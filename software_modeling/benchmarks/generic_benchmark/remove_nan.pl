my ($stats_file) = @ARGV;
my $result = "";
my $line_copy = "";
open(WORKING,"<$stats_file") or die "Failed to open stats file $stats_file\n";
my $valid_flag = 0;
while(my $line = <WORKING>) {
	$line_copy = $line;
	if ($line_copy =~ m/ nan /) {
		$line_copy =~ s/ nan / 0 /;
	}
	if ($line_copy =~ m/system.cpu.itb_walker_cache/){
		$valid_flag = 1;
	}
	
	if ($line_copy =~ m/system.switch_cpus_1/) {
		$line_copy =~ s/system.switch_cpus_1/system.cpu/;
	}
	elsif ($line_copy =~ m/system.cpu/ and $valid_flag == 0) {
		$line_copy =~ s/system.cpu/system.switch_cpus_1/;
	}

	$result .= $line_copy;
}
close(WORKING);
open(my $target_filehandle,'>', $stats_file) or die "Failed to create target file $stats_file\n";
print $target_filehandle "$result";
close($target_filehandle);
