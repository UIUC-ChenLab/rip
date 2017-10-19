###Publication
"Parallel Code-specific CPU Simulation with Dynamic Phase Convergence Modeling for HW/SW Co-design", 
Warren Kemmerer, Wei Zuo, and Deming Chen. (ICCAD '16) [link](http://delivery.acm.org/10.1145/2970000/2967063/a79-kemmerer.pdf)

###Introduction
Our tool is an automated framework that: 1. Enables high speed code-specific CPU profiling support
for gem5, providing automatic annotation of energy and latency within source code. Maximum speedups obtained using gem5 is 562x while average results obtained speedups of 323.1x. Our tool achieves average accuracies of 4.16% and 2.87% for latency and energy respectively.

###Installation

This framework includes several exisiting tools. Following is detailed reference.

1. McPAT, version 1.0

    Tool used for power estimation. Flow natively supports McPAT version 1.0, although later releases should be compatible.

    McPAT relies on an input .xml file describing both the processor architecture and aggregate runtime statistics. Example .xml files relating to various processor architectures can be found in the native McPAT software, with additional processor architects available through open source. Any customized architecture will require, at present, the hand modification of these description files.
However, updating these .xml files with runtime statistics generated from GEM5 simulation is not natively supported by either GEM5 or McPAT. We therefore rely the following script (./benchmark/generic_benchmark/GEM5ToMcPAT.py) to achieve the transfer of this information.

2. GEM5ToMcPAT 

    Open source conversion tool that enables data transfer between GEM5 simulation run and McPAT. Tool version supported natively is included in packaged code, and was originally downloaded here: https://bitbucket.org/dskhudia/gem5tomcpat.
    
    This tool relies on the output of GEM5 when run in profiling mode, specifically the stats.txt and the config.json files. The former defines the aggregate runtime statistics while the later describes hierarchical components relating to the processor architecture. 
    
    Script also requires a McPAT .xml template. Our tool provides an example .xml template, ./benchmark/generic_benchmark/my_xeon_template.xml. Effectively, this .xml template is identical to the processor description .xml used by McPAT, except that numerical values representing runtime data have been replaced with parameters describing the GEM5 statistical output identifier. At present, this template must be manually generated, once per architecture. Generating this .xml template and updating the corresponding pointer within our flow’s configuration file should be the only manual work required by the user to enable power extraction within our flow.

3. PIN 3.0

    PIN is a massive code profiling suite provided by Intel. For the purposes of our flow, we have generated a custom PIN tool used in dynamically extracting the instruction counts associated with specified locations within compiled code. These extracted instruction values are used to dynamically control the targeted subsection of code simulated using the KVM processor model in GEM5.
To enable our custom PIN tool after installing PIN, copy the file pin/ManualExamples/roi_sampling.* to the directory $PIN_ROOT_DIR/source/tools/ManualExamples/. 

4. GEM5

    We assume the user has a knowledge of how to install GEM5 and generate a processor simulation model with performance monitoring (gem5.perf). In addition to the standard GEM5 simulation procedure, our flow requires custom simulation control files for dynamic handling of the KVM process. User will need to copy these updated control file .gem5/common/Simulation.py, into the following directory: $GEM5_ROOT_DIR/configs/common/.(Or replace the common folder with provided common folder).
    
5. Kernel-based Virtual Machine (KVM) Processor Simulation

    Speedup within the fast forward subsection of the GEM5 simulation flow requires processor virtualization, which is achieved through a Kernel-based Virtual Machine (KVM). Getting the KVM processor model to work within GEM5 can be an admittedly finicky procedure involving both software and hardware complications, and we highly recommend attempting an independent KVM processor run in GEM5 before using our flow. 
    
    In general, before the KVM processor mode can be used in GEM5, processor virtualization must be enabled in hardware on the host machine. This is typically achieved through a processor setting within the BIOS. Not all processors and motherboards will support hardware virtualization, and it is more common in newer models. After configuring hardware, kernel virtualization must be enabled within the host operating system. This can be achieved though software such as qemu-kvm within many linux based environments. After enabling virtualization in both hardware and software, it is necessary that the hardware performance counters associated with the host machine processor are compatible with GEM5’s virtualized processor model. Attempting a GEM5 kvm processor run remains the best way of testing compatibility. At the time of our experiments, support was generally available with most AMD processors, while Intel CPU support was still under development.
    
6. Perl File::chdir

    Chdir is a perl module that enables perl to dynamically change the current working directory. Within the context of our flow, it is used for launching sub modules that need to compile and execute code non-perl code within dynamically generated subdirectories. The source code, along within installation instructions can be obtained here: https://perldoc.perl.org/functions/chdir.html. We provided the installed files in ./perl_lib.
    
###Other prerequisite and configuration

1.gcc and g++ version 7.0.0 20160523 (experimental) (GCC)
2.Put the following variable in your .bashrc.

``` 
export PERL5LIB=<Chdir install dir>/perl_lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<gcc-7.0.0 install dir>/lib64
export CXX=<gcc-7.0.0 install dir>/bin/g++
export CC=<gcc-7.0.0 install dir>/bin/gcc
```

###Run the tool
1. Script
We provided a general running script in ./benchmarks/generic_benchmark/run_gem5.pl
The configuration is written in detail in the script. 

2. place target c files into ./benchmarks/generic_benchmark/source_files.

3. Annotate the loops the uers is interested in with Start_ROI_loop(Iteration Number) and Stop_ROI_loop(Iteration Number), please refer to the example in the source_files folder.
4. go back to ./benchmark/generic_benchmark, run perl run_gem5.pl. The annotated files will be generated in target_files.

###Generate SystemC code
1. We use the same framework as the hardare modeling (PolyOpt), please refer to README in hardware_modeling folder for installation. 

2. To generate SystemC, please run the following command:

```
PolyRose --systemc-no-pretile   --systemc-target-func=kernel_function  filename.c
The brief explanation is as following:

 * --systemc-no-pretile: directly generate SystemC from the input C code without transformation.
  
 * --systemc-target-func=kernel_function: where "kerenel_function" is the name of your design function.
 
 * filename.c: The input file name. 
```

### Back up:
To help installation, I put the installed files on our machine for different tools in ./backup folder. In there is any error or file missing when installing the tool chain, user can refer to this folder for more files.

### Bug Report and Contact
weizuo (at) illinois (dot) edu




