use File::chdir;
my ($current_directory, $launch_number, $max_launch_number) = @ARGV;
my @ROI_folders = <$current_directory/ROI_*>;
my $command;

my $target_file = "my_directories.csv";
open(my $target_filehandle, '>', $target_file) or die "Failed to open stats 1 file $target_file\n";
my $ROI_length = scalar @ROI_folders;
my $ROI_index = 0;
while ($ROI_index < $ROI_length){
  my $ROI_folder = $ROI_folders[$ROI_index];
  my @unsorted_folders =<$ROI_folder/Division_*>;
  my @Division_numbers;
  my $index = 0;
  foreach $unsort_folder (@unsorted_folders){
	(my $prefix, my $suffix) = split($ROI_folder . "/Division_",$unsort_folder);
	$Division_numbers[$index] = $suffix;
	$index += 1;
  }
  
  my @sorted_division_numbers = sort {$a <=> $b} @Division_numbers;

  $index = 0;
  my @Division_folders;
  foreach $sorted_division (@sorted_division_numbers){
	@Division_folders[$index] = $ROI_folder . "/Division_" . $sorted_division;
	$index += 1;
  }

  my $division_num = 0;
  my $num_divisions = scalar @Division_folders;
  while ($division_num < $num_divisions){
	my $Division_folder = $Division_folders[$division_num];
	if($division_num < $num_divisions- 1){
		print $target_filehandle "$Division_folder,";
	}
	else{
		print $target_filehandle "$Division_folder";
	}
	$division_num += 1;
  }
  print $target_filehandle "\n";
  $ROI_index += 1;
}
close($target_filehandle);
