my $current_directory = $ARGV[0];
my @ROI_folders = <$current_directory/ROI_*>;
my @Division_folders;
my $command;
my $target_file = "global_performance_results.csv";
my $source_file = "";

open(my $target_filehandle, '>', $target_file) or die "Failed to open results file: $target_file\n";
foreach $ROI_folder (@ROI_folders) {
  @Division_folders =<$ROI_folder/Division_*>;
  my $division_num = 0;
  my $num_divisions = scalar @Division_folders;
  while ($division_num < $num_divisions){
	my $Division_folder = $Division_folders[$division_num];
	$source_file = $Division_folder . "/performance_results.csv";
	open(my $source_filehandle, '<', $source_file);
	while(my $line = <$source_filehandle>){
		chomp($line);
		my @fields = split "," , $line;
		my $power = $fields[1];
		my $latency = $fields[0];
		print $target_filehandle ($Division_folder . "," . $latency . "," . $power . "\n");
	}
	close($source_filehandle);
	$division_num += 1;
  }
}
close($target_filehandle);
