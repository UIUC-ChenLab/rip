sub partition_back_annotation{
my ($current_directory, $benchmark, $source_file, $simulation_suffix) = @_;
my $current_read_line = 0;
my $current_ROI_marker = 0;
my $ROI_start_found = 0;
my $ROI_end_found_flag = 0;
my $target_file_buffer = "#include \"back_annotation_" . $simulation_suffix . ".h\"\n";
my $loop_found = 0;
my $RIO_section_number = 0;
my $command;
my $warm_up = 1;
my $ROI_label_number = 0;
my $ROI_loop_count = 0;

open(my $source_filehandle, '<', $current_directory . "/source_files/" . $source_file) or die "Failed to open stats 1 file $source_file\n";
while(my $line = <$source_filehandle>){
	chomp($line);
	#for non loop based ROI
	if($line =~ m/Start_ROI\(.*\);.*/){
		#Replace function with ROI function call
		$line =~ s/Start_ROI\(.*\);//g;
		$ROI_label_number += 1;
		$ROI_start_found = 1;
	}
	if($line =~ m/Stop_ROI\(.*\);.*/){
		if($ROI_start_found == 1){
			#Replace function with ROI function call
			$line =~ s/Stop_ROI\(.*\);/update_performance($RIO_section_number);\n\/\/CALL_WRITEBACK\(...\)\n/g;
			$ROI_label_number += 1;
			$ROI_end_found_flag = 1;
			$current_ROI_marker = $current_read_line;
			$ROI_start_found = 0;
		}
		else{
			$line =~ s/Stop_ROI\(.*\);//g;
		}
	}

	#for loop based ROI
	if($line =~ m/Start_ROI_loop\(.*\);.*/){
		my $function_param_str = $line;
		$function_param_str =~ s/.*Start_ROI_loop\(//g;
		$function_param_str =~ s/\).*//g;
		my @function_param_array = split(',',$function_param_str);
		my $param_length = scalar(@function_param_array);
		if (scalar(@function_param_array) == 1){
			$line =~ s/Start_ROI_loop\(.*\);//g;
			$ROI_label_number += 1;
			$loop_found = 1;
			$ROI_start_found = 1;
		}
	}
	if($line =~ m/Stop_ROI_loop\(.*\);.*/){
		if($ROI_start_found == 1){
			$line =~ s/Stop_ROI_loop\(.*\);//g;
			$target_file_buffer =~ s/\}(?=[^\}]*$)/update_performance($RIO_section_number);\n\/\/CALL_WRITEBACK\(...\)\n\}/;
			$ROI_label_number += 1;
			$ROI_end_found_flag = 1;
			$current_ROI_marker = $current_read_line;
			$ROI_start_found = 0;
			$ROI_loop_count += 1;
		}
	}
	$target_file_buffer .= $line . "\n";
	$current_read_line = $current_read_line + 1;

	if($ROI_end_found_flag == 1){
		$RIO_section_number = $RIO_section_number + 1;
		$ROI_end_found_flag = 0;
	}
}

my $dest_file = $current_directory . "/target_files/" . $source_file;
open(my $target_filehandle, '>', $dest_file) or die "Failed to open target file: $dest_file\n";
print $target_filehandle "$target_file_buffer";
close($target_filehandle);
}

1;
