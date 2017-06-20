use File::chdir;

my $current_directory = $ARGV[0];
#"/home/warren/sniper-6.1/test/correlation_parallel";

my $command;
my $source_file = "";
my $access_count = 0;

  $target_file = $current_directory . "/performance_results.csv";
  open(my $target_filehandle, '>', $target_file) or die "Failed to open results file: $target_file\n";

	$access_count = 0;
	$source_file = $current_directory . "/stats.txt";
	open(my $source_filehandle, '<', $source_file) or print "Failed to open simulation file $source_file\n";
	while(my $line = <$source_filehandle>){
		chomp($line);
		if($line =~ m/sim_ticks.*# Number of ticks simulated.*/){
			$line =~ s/sim_ticks//g;
			$line =~ s/# Number of ticks simulated.*//g;
			$line =~ s/^\s+|\s+$//g;
			if($access_count == 0){
				print $target_filehandle $line*(10.0**-12);
			}
			$access_count = $access_count + 1;
		}
	}
	close($source_filehandle);

	$access_count = 0;
	my $core_found = 0;
	$source_file = $current_directory . "/power.txt";
	open(my $source_filehandle, '<', $source_file) or print "Failed to open power file $source_file\n";
	while(my $line = <$source_filehandle>){
		chomp($line);
		if($line =~ m/^Core:.*/){
			$core_found = 1;
		}
		if($core_found == 1 and $line =~ m/.*Runtime Dynamic = .*/){
			$line =~ s/.*= //g;
			$line =~ s/ W.*//g;
			if($access_count == 0){
				print $target_filehandle ("," . $line);
			}
			$access_count = $access_count + 1;
		}
	}
	close($source_filehandle);
	print $target_filehandle ("\n");
  close($target_filehandle);

