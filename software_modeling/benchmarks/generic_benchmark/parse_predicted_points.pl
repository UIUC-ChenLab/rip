my $current_directory = "/home/warren/gem5/benchmarks/lu";

sub parse_predicted_points{
my ($current_directory) = @_;
my @predicted_points_files = <$current_directory/predicted_points*>;
my $target_file = "accumulated_results.csv";
open(my $target_filehandle, '>', $target_file) or die "Failed to open results file: $target_file\n";

foreach $source_file (@predicted_points_files){
my $current_file_name = $source_file;
$current_file_name =~ s/$current_directory\///g;
print $target_filehandle $current_file_name . "\n";
my $command;
my $prev_roi_number = 0;
my $accum_energy = 0;
my $accum_latency = 0;
my $total_latency = 0;
my $total_energy = 0;

open(my $source_filehandle, '<', $source_file);
while(my $line = <$source_filehandle>){
	chomp($line);
	my @fields = split "," , $line;
	my $roi_number = $fields[0];
	my $latency = $fields[2];
	my $power = $fields[3];
	if($prev_roi_number != $roi_number and $accum_energy != 0){
		my $accum_power = $accum_energy/$accum_latency;
		print $target_filehandle ($prev_roi_number . "," . $accum_latency . "," . $accum_power . "," . $accum_energy ."\n");
		$prev_roi_number = $roi_number;
		$total_latency += $accum_latency;
		$total_energy += $accum_energy;
		$accum_latency = $latency;
		$accum_energy = $latency*$power;
	}
	else{
		$accum_latency += $latency;
		$accum_energy += $latency*$power;
	}
}
close($source_filehandle);
if($accum_energy != 0){
	my $accum_power = $accum_energy/$accum_latency;
	print $target_filehandle ($prev_roi_number . "," . $accum_latency . "," . $accum_power . "," . $accum_energy ."\n");
	$total_latency += $accum_latency;
	$total_energy += $accum_energy;
}
if($total_energy !=0){
	my $total_power = $total_energy/$total_latency;
	print $target_filehandle ("," . $total_latency . "," . $total_power . "," . $total_energy ."\n");
}

}
close($target_filehandle);
}
1;
