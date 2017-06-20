use File::chdir;

sub run_pin_profile{
my ($benchmark, $main_source_file, $additional_depend, $benchmark_arguments, $current_directory, $pintool_directory) = @_;
my $command;

#compile source code
$command = "g++ " . $main_source_file . " " . $additional_depend . " -o " . $benchmark . ".out -static";
system($command);

#disassemble source code
$command = "objdump -d " . $benchmark . ".out > " . $benchmark . "_objdump.txt";
system($command);

#isolate addresses
$command = "grep -r \"ROILabel\" " . $benchmark . "_objdump.txt > addresses.txt";
system($command);

my $target_file = "roi_addresses.h";
open(my $target_filehandle, '>', $target_file) or die "Failed to open target file: $target_file\n";
print $target_filehandle "#ifndef ROI_ADDRESSES_H\n";
print $target_filehandle "#define ROI_ADDRESSES_H\n\n";

my $source_file = "addresses.txt";
my @addresses;

my $result = "";
my $line_copy = "";
open(my $source_filehandle, '<', $source_file) or die "Failed to open stats file $stats_file\n";
while(my $line = <$source_filehandle>) {
	chomp($line);
	$line_copy = $line;
	if ($line_copy =~ m/.*<ROILabel.*>:/) {
		$line_copy =~ s/\s+<ROILabel.*//;
		my $hex_string = hex($line_copy);
		push @addresses, $hex_string;
	}
}
close($source_filehandle);

my $num_addresses = scalar @addresses;
print $target_filehandle "#define INSTRUCTION_ARRAY_SIZE " . $num_addresses . "\n";
print $target_filehandle "void* my_instruction_array[INSTRUCTION_ARRAY_SIZE]  = {";
my $address_index = 0;
while($address_index < $num_addresses){
	if($address_index > 0){
		print $target_filehandle ", "
	}
	printf $target_filehandle "(void*)0x%x",$addresses[$address_index];
	$address_index += 1;
}

print $target_filehandle "};\n\n#endif\n";
close($target_filehandle);

$command = "cp roi_addresses.h " . $pintool_directory . "/ManualExamples/roi_addresses.h";
system($command);

$command = "rm " . $pintool_directory . "/ManualExamples/obj-intel64/roi_sampling.*";
system($command);

$command = "make -C " . $pintool_directory;
system($command);

$CWD = $pintool_directory . "/ManualExamples";
$command = "../../../pin -t obj-intel64/roi_sampling.so -- " . $current_directory . "/" . $benchmark . ".out " . $benchmark_arguments;
system($command);

$CWD = $current_directory;
$command = "cp " . $pintool_directory . "/ManualExamples/roi_sampling.pm " . $current_directory . "/roi_sampling.pm";
system($command);

$command = "cat roi_sampling.pm roi_functions.pl > generate_roi_structure.pm";
system($command);

$command = "sed '1d' generate_roi_structure.pm > generate_roi_structure.pl";
system($command);

$command = "cp generate_roi_structure.pl ../generate_roi_structure.pl";
system($command);
}

1;
