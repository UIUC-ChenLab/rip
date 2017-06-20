sub partition_standard {
my ($current_directory, $benchmark, $source_file, $ROI_numbers_ref, $array_index, $simulation_suffix) = @_;

delete $INC{'generate_roi_structure.pl'};
require 'generate_roi_structure.pl';

my @ROI_numbers = @{$ROI_numbers_ref};
my $ROI_start_found = 0;
my $ROI_end_found_flag = 0;
my $loop_found = 0;
my $RIO_section_number = 0;
my $command;
my $warm_up = 1;
my $ROI_label_number = 0;
my $ROI_loop_count = 0;

$command = "rm -R ROI_*";
system($command);
$command = "rm " . $current_directory . "/Roi_divisions.csv";
system($command);

#generate index array header file
my $index_header_file = $current_directory . "/target_files/ROI_INDEX_VALUES_" . $simulation_suffix . ".h";
open(my $index_filehandle, '>', $index_header_file) or die "Failed to open results file: " . $index_header_file . "\n";
print $index_filehandle "#ifndef ROI_INDEX_VALUES_H\n#define ROI_INDEX_VALUES\n\n";
close($index_filehandle);

my $ROI_divisions;

open(my $source_filehandle, '<', $current_directory . "/source_files/" . $source_file) or die "Failed to open stats 1 file $source_file\n";
while(my $line = <$source_filehandle>){
	chomp($line);
	#for non loop based ROI
	if($line =~ m/Start_ROI\(.*\);.*/){
		$ROI_label_number += 1;
		$ROI_start_found = 1;
		$ROI_divisions = 1;
	}
	if($line =~ m/Stop_ROI\(.*\);.*/){
		if($ROI_start_found == 1){
			$ROI_label_number += 1;
			$ROI_end_found_flag = 1;
			$ROI_start_found = 0;
		}
	}

	#for loop based ROI
	if($line =~ m/Start_ROI_loop\(.*\);.*/){
		print("I have found loop " . $ROI_numbers[$array_index][$ROI_loop_count] . "\n");
		my $function_param_str = $line;
		$function_param_str =~ s/.*Start_ROI_loop\(//g;
		$function_param_str =~ s/\).*//g;
		my @function_param_array = split(',',$function_param_str);
		my $param_length = scalar(@function_param_array);
		if (scalar(@function_param_array) == 1){
			$ROI_divisions = $ROI_numbers[$array_index][$ROI_loop_count];	
			$ROI_label_number += 1;
			$loop_found = 1;
			$ROI_start_found = 1;
		}
	}
	if($line =~ m/Stop_ROI_loop\(.*\);.*/){
		if($ROI_start_found == 1){
			$ROI_label_number += 1;
			$ROI_end_found_flag = 1;
			$ROI_start_found = 0;
			$ROI_loop_count += 1;
		}
	}

	if($ROI_end_found_flag == 1){
		generate_roi_structure::output_ROI_divisions_file($current_directory, $RIO_section_number, $ROI_divisions, $simulation_suffix);
		$RIO_section_number = $RIO_section_number + 1;
		$ROI_end_found_flag = 0;
	}
}
close($source_filehandle);

open(my $index_filehandle, '>>', $index_header_file) or die "Failed to open results file: " . $index_header_file . "\n";
my $output_string = "static int * my_index_arrays[$RIO_section_number] = {";
if($RIO_section_number > 0){
	$output_string .= "&ROI_" . 0 . "_INDEXES[0]";
}
for(my $new_rank = 1; $new_rank < $RIO_section_number; $new_rank++){
	$output_string .= ", " + "&ROI_" . $new_rank . "_INDEXES[0]";
}
$output_string .= "};\n";
$output_string .= "static int my_index_array_sizes[$RIO_section_number] = {";
if($RIO_section_number > 0){
	$output_string .= "ROI_" . 0 . "_size";
}
for(my $new_rank = 1; $new_rank < $RIO_section_number; $new_rank++){
	$output_string .= ", " + "&ROI_" . $new_rank . "size";
}
$output_string .= "};\n#endif\n";
print $index_filehandle $output_string;
close($index_filehandle);
}

1;
