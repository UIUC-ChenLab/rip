sub get_max_ROI_divisions{
        (my $assigned_block, my $num_ROI_divisions) = @_;
	my $total_ROI_iterations = $roi_block_stops[2*$assigned_block + 1] - $roi_block_starts[2*$assigned_block];
	if($num_ROI_divisions < $total_ROI_iterations){
		return $num_ROI_divisions;
	}
	return $total_ROI_iterations;
}

sub output_ROI_divisions_file{
    (my $current_directory, my $assigned_block, my $num_ROI_divisions, $simulation_suffix) = @_;

	my $total_ROI_iterations = $roi_block_stops[2*$assigned_block + 1] - $roi_block_starts[2*$assigned_block];
	if($num_ROI_divisions > $total_ROI_iterations){
		$num_ROI_divisions = $total_ROI_iterations;
	}

	my $dest_folder_parent = $current_directory . "/ROI_" . $assigned_block;
	my $command = "mkdir " . $dest_folder_parent;
	system($command);
	my @upper_rank_array;
	
	my $target_file = $current_directory . "/Roi_divisions.csv";
	open(my $target_filehandle, '>>', $target_file) or die "Failed to open results file: $target_file\n";
	my $rank = 0;
	my $roi_block_begin = $roi_block_starts[2*$assigned_block];
	my $output_string = "";
	
	while($rank < $num_ROI_divisions){
		my $lower_bound = $roi_block_begin + int($rank*($total_ROI_iterations)/$num_ROI_divisions);
		my $upper_bound = $roi_block_begin + int(($rank+1)*($total_ROI_iterations)/$num_ROI_divisions);
		if($upper_bound > $lower_bound){
			my $instr_start = $profiled_instruction_counts[$lower_bound];
			my $instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
			$output_string .= $assigned_block . "," . $rank . "," . $instr_start . "," . $instr_length . "\n";
			push @upper_rank_array, $rank;
		}
		$rank += 1;
	}
	print $target_filehandle $output_string;
	close($target_filehandle);

	#output array into header file allowing back annotated code to recognize which indexes correspond with intervals in latency and energy
	my $index_header_file = $current_directory . "/target_files/ROI_INDEX_VALUES_" . $simulation_suffix . ".h";
	$output_string = "static int ROI_" . $assigned_block . "_size = " . scalar(@upper_rank_array) . ";\n";
	$output_string .= "static int ROI_" . $assigned_block . "_INDEXES[" . scalar(@upper_rank_array) . "] = {";
	open(my $index_filehandle, '>>', $index_header_file) or die "Failed to open results file: $index_header_file\n";
	if($new_num_ROI_divisions > 0){
		$output_string .= $upper_rank_array[0];
	}
	for(my $new_rank = 1; $new_rank < $new_num_ROI_divisions; $new_rank++){
		$output_string .= ", " . $upper_rank_array[$new_rank];
	}
	$output_string .= "};\n";
	print $index_filehandle $output_string;
	close($index_filehandle);
	
    return;
}

sub output_ROI_divisions_average_file{
        (my $current_directory, my $assigned_block, my $num_ROI_divisions, $simulation_suffix) = @_;

	my $total_ROI_iterations = $roi_block_stops[2*$assigned_block + 1] - $roi_block_starts[2*$assigned_block];
	if($num_ROI_divisions > $total_ROI_iterations){
		$num_ROI_divisions = $total_ROI_iterations;
	}
	my $average_instructions = ($profiled_instruction_counts[$roi_block_stops[2*$assigned_block + 1]] - $profiled_instruction_counts[$roi_block_starts[2*$assigned_block]])/$num_ROI_divisions;

	my $target_file = $current_directory . "/Roi_divisions.csv";
	open(my $target_filehandle, '>>', $target_file) or die "Failed to open results file: $target_file\n";
	my $rank = 0;
	my $roi_block_begin = $roi_block_starts[2*$assigned_block];
	my $output_string = "";
	my @divisions_array;
	my @upper_rank_array;
	
	while($rank < $num_ROI_divisions){
		my $lower_bound = $roi_block_begin + int($rank*($total_ROI_iterations)/$num_ROI_divisions);
		my $upper_bound = $roi_block_begin + int(($rank+1)*($total_ROI_iterations)/$num_ROI_divisions);
		my $instr_start = $profiled_instruction_counts[$lower_bound];
		my $instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
		while ($instr_length<$average_instructions and $rank < $num_ROI_divisions){
			$rank += 1;
			$upper_bound = $roi_block_begin + int(($rank+1)*($total_ROI_iterations)/$num_ROI_divisions);
			$instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
		}
		if($upper_bound > $lower_bound){
			push @divisions_array, [$instr_start, $instr_length];
			push @upper_rank_array, $rank;
		}
		$rank += 1;
	}
	my $new_num_ROI_divisions = scalar (@divisions_array);
	if($new_num_ROI_divisions > 1){
		if($divisions_array[$new_num_ROI_divisions-1][1] < $average_instructions){
			$divisions_array[$new_num_ROI_divisions-2][1] += $divisions_array[$new_num_ROI_divisions-1][1];
			pop @divisions_array;
			$upper_rank_array[$new_num_ROI_divisions-2] = $upper_rank_array[$new_num_ROI_divisions-1];
			pop @upper_rank_array;
			$new_num_ROI_divisions -= 1;
		}
	}

	my $dest_folder_parent = $current_directory . "/ROI_" . $assigned_block;
	my $command = "mkdir " . $dest_folder_parent;
	system($command);

	for(my $new_rank = 0; $new_rank < $new_num_ROI_divisions; $new_rank++){
		$output_string .= $assigned_block . "," . $new_rank . "," . $divisions_array[$new_rank][0] . "," . $divisions_array[$new_rank][1] . "\n";
		my $dest_folder = $dest_folder_parent . "/Division_" . $new_rank;
		$command = "mkdir " . $dest_folder;
		system($command);
	}

	print $target_filehandle $output_string;
	close($target_filehandle);
	
	#output array into header file allowing back annotated code to recognize which indexes correspond with intervals in latency and energy
	my $index_header_file = $current_directory . "/target_files/ROI_INDEX_VALUES_" . $simulation_suffix . ".h";
	$output_string = "static int ROI_" . $assigned_block . "_size = " . scalar(@upper_rank_array) . ";\n";
	$output_string .= "static int ROI_" . $assigned_block . "_INDEXES[" . scalar(@upper_rank_array) . "] = {";
	open(my $index_filehandle, '>>', $index_header_file) or die "Failed to open results file: $index_header_file\n";
	if($new_num_ROI_divisions > 0){
		$output_string .= $upper_rank_array[0];
	}
	for(my $new_rank = 1; $new_rank < $new_num_ROI_divisions; $new_rank++){
		$output_string .= ", " . $upper_rank_array[$new_rank];
	}
	$output_string .= "};\n";
	print $index_filehandle $output_string;
	close($index_filehandle);
	
	return;
}

sub output_ROI_divisions_min_file{
        (my $current_directory, my $assigned_block, $simulation_suffix) = @_;

	my $total_ROI_iterations = $roi_block_stops[2*$assigned_block + 1] - $roi_block_starts[2*$assigned_block];
	my $num_ROI_divisions = $total_ROI_iterations;
	my $minimum_instructions = 4000000;

	my $target_file = $current_directory . "/Roi_divisions.csv";
	open(my $target_filehandle, '>>', $target_file) or die "Failed to open results file: $target_file\n";
	my $rank = 0;
	my $roi_block_begin = $roi_block_starts[2*$assigned_block];
	my $output_string = "";
	my @divisions_array;
	my @upper_rank_array;
	
	while($rank < $num_ROI_divisions){
		my $lower_bound = $roi_block_begin + int($rank*($total_ROI_iterations)/$num_ROI_divisions);
		my $upper_bound = $roi_block_begin + int(($rank+1)*($total_ROI_iterations)/$num_ROI_divisions);
		my $instr_start = $profiled_instruction_counts[$lower_bound];
		my $instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
		while ($instr_length<$minimum_instructions and $rank < $num_ROI_divisions){
			$upper_bound = $roi_block_begin + int(($rank+1)*($total_ROI_iterations)/$num_ROI_divisions);
			$instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
			$rank += 1;
		}
		if($upper_bound > $lower_bound){
			$instr_length = $profiled_instruction_counts[$upper_bound] - $instr_start;
			push @divisions_array, [$instr_start, $instr_length];
			push @upper_rank_array, $rank;
		}
		$rank += 1;
	}
	my $new_num_ROI_divisions = scalar (@divisions_array);
	if($new_num_ROI_divisions > 1){
		if($divisions_array[$new_num_ROI_divisions-1][1] < $minimum_instructions){
			$divisions_array[$new_num_ROI_divisions-2][1] += $divisions_array[$new_num_ROI_divisions-1][1];
			pop @divisions_array;
			$upper_rank_array[$new_num_ROI_divisions-2] = $upper_rank_array[$new_num_ROI_divisions-1];
			pop @upper_rank_array;
			$new_num_ROI_divisions -= 1;
		}
	}

	my $dest_folder_parent = $current_directory . "/ROI_" . $assigned_block;
	my $command = "mkdir " . $dest_folder_parent;
	system($command);

	for(my $new_rank = 0; $new_rank < $new_num_ROI_divisions; $new_rank++){
		$output_string .= $assigned_block . "," . $new_rank . "," . $divisions_array[$new_rank][0] . "," . $divisions_array[$new_rank][1] . "\n";
		my $dest_folder = $dest_folder_parent . "/Division_" . $new_rank;
		$command = "mkdir " . $dest_folder;
		system($command);
	}

	print $target_filehandle $output_string;
	close($target_filehandle);

	#output array into header file allowing back annotated code to recognize which indexes correspond with intervals in latency and energy
	my $index_header_file = $current_directory . "/target_files/ROI_INDEX_VALUES_" . $simulation_suffix . ".h";
	$output_string = "static int ROI_" . $assigned_block . "_size = " . scalar(@upper_rank_array) . ";\n";
	$output_string .= "static int ROI_" . $assigned_block . "_INDEXES[" . scalar(@upper_rank_array) . "] = {";
	open(my $index_filehandle, '>>', $index_header_file) or die "Failed to open results file: $index_header_file\n";
	if($new_num_ROI_divisions > 0){
		$output_string .= $upper_rank_array[0];
	}
	for(my $new_rank = 1; $new_rank < $new_num_ROI_divisions; $new_rank++){
		$output_string .= ", " . $upper_rank_array[$new_rank];
	}
	$output_string .= "};\n";
	print $index_filehandle $output_string;
	close($index_filehandle);
	
    return;
}

1;
