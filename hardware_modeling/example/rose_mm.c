#include "mm.h"
#include "systemc.h"
#include <sstream>
#include "latencies.h"
#include "power.h"
#include "help_function.h"
double energy = 0.0;

class kernel_mm_loop0_module : public sc_module
{
public:
   sc_in<bool> scgen__start;
   sc_signal<bool> scgen__running;
   sc_out<bool> scgen__done;
   sc_in<int> scgen__c1;
   sc_in<int> scgen__c0;
   sc_in<int> scgen__c2;
   sc_in<int> scgen__c3;
   sc_in<int> scgen__c4;
   sc_in<int> scgen__c5;
  

  public: void kernel_mm_loop0()
{
    while(1){
   while(!scgen__start) wait();
   scgen__done = false;
   int c1=scgen__c1;
   int c0=scgen__c0;
   int C_l[32][32];
   int C_l_cycle = 0;
   int c2=scgen__c2;
   int A_l[32][32];
   int A_l_cycle = 0;
   int B_l[32][32];
   int B_l_cycle = 0;
   int c3=scgen__c3;
   int c4=scgen__c4;
   int c5=scgen__c5;
{{
          for (c1 = 0; c1 <= 31; c1++) {
/* per-iteration communication (blocking) */
{
              int __it1;
              int __it0;
              if (c0 >= 0 && c0 <= 31 && c1 >= 0 && c1 <= 31) {{{
                    for (__it0 = 32 * c0; __it0 <= 32 * c0 + 31; __it0++) {{{
                          for (__it1 = 32 * c1; __it1 <= 32 * c1 + 31; __it1++) {
                            C_l[__it0 % 32][__it1 % 32] = C[__it0][__it1];
#pragma AP loop tripcount min 32 avg 32 max 32
                          }
                        }
                      }
#pragma AP loop tripcount min 32 avg 32 max 32
                    }
                  }
                }
              }
            }
{
              for (c2 = 0; c2 <= 31; c2++) {
/* per-iteration communication (blocking) */
{
                  int __it1;
                  int __it0;
                  if (c0 >= 0 && c0 <= 31 && c1 >= 0 && c1 <= 31 && c2 >= 0 && c2 <= 31) {{{
                        for (__it0 = 32 * c0; __it0 <= 32 * c0 + 31; __it0++) {{{
                              for (__it1 = 32 * c2; __it1 <= 32 * c2 + 31; __it1++) {
                                A_l[__it0 % 32][__it1 % 32] = A[__it0][__it1];
#pragma AP loop tripcount min 32 avg 32 max 32
                              }
                            }
                          }
#pragma AP loop tripcount min 32 avg 32 max 32
                        }
                      }
                    }
                  }
                }
{
/* loop data preload (blocking) */
{
                    int c3__local__;
{
                      c3__local__ = 32 * c0;
                    }
                    int __it1;
                    int __it0;
                    if (c0 >= 0 && c0 <= 31 && 32 * c0 <= c3__local__ && 32 * c0 >= c3__local__ + -31 && c1 >= 0 && c1 <= 31 && c2 >= 0 && c2 <= 31) {{{
                          for (__it0 = 32 * c2; __it0 <= 32 * c2 + 31; __it0++) {{{
                                for (__it1 = 32 * c1; __it1 <= 32 * c1 + 31; __it1++) {
                                  B_l[__it0 % 32][__it1 % 32] = B[__it0][__it1];
#pragma AP loop tripcount min 32 avg 32 max 32
                                }
                              }
                            }
#pragma AP loop tripcount min 32 avg 32 max 32
                          }
                        }
                      }
                    }
                  }
                  for (c3 = 32 * c0; c3 <= 32 * c0 + 31; c3++) {{
                      for (c4 = 32 * c2; c4 <= 32 * c2 + 31; c4++) {{
                          for (c5 = 32 * c1; c5 <= 32 * c1 + 31; c5++) 
#pragma AP pipeline II=1
{{
                              C_l[c3 % 32][c5 % 32] += (A_l[c3 % 32][c4 % 32] * B_l[c4 % 32][c5 % 32]);
                            }
#pragma AP loop tripcount min 32 avg 32 max 32
                          }
                        }
#pragma AP loop tripcount min 32 avg 32 max 32
                      }
                    }
#pragma AP loop tripcount min 32 avg 32 max 32
                  }
                }
#pragma AP loop tripcount min 32 avg 32 max 32
              }
            }
/* per-iteration copy-out */
{
              int __it1;
              int __it0;
              if (c0 >= 0 && c0 <= 31 && c1 >= 0 && c1 <= 31) {{{
                    for (__it0 = 32 * c0; __it0 <= 32 * c0 + 31; __it0++) {{{
                          for (__it1 = 32 * c1; __it1 <= 32 * c1 + 31; __it1++) {
                            C[__it0][__it1] = C_l[__it0 % 32][__it1 % 32];
#pragma AP loop tripcount min 32 avg 32 max 32
                          }
                        }
                      }
#pragma AP loop tripcount min 32 avg 32 max 32
                    }
                  }
                }
              }
            }
#pragma AP loop tripcount min 32 avg 32 max 32
          }
        }
#pragma AP loop tripcount min 32 avg 32 max 32
      }
   scgen__running = false;
   scgen__done = true;
    }
  }
   SC_HAS_PROCESS(kernel_mm_loop0_module);
   kernel_mm_loop0_module(const sc_module_name& p_name) :
     sc_module(p_name)
   {
      SC_THREAD(kernel_mm_loop0);
      sensitive << scgen__start;
   }
}
;

class kernel_mm_module : public sc_module
{
public:
   sc_in<bool> scgen__start;
   sc_signal<bool> scgen__running;
   kernel_mm_loop0_module* scgen__tiles0[2];
   sc_signal<bool> scgen__tiles0_start[2];
   sc_signal<bool> scgen__tiles0_done[2];
   sc_signal<int> scgen__tiles0_c1[2];
   sc_signal<int> scgen__tiles0_c0[2];
   sc_signal<int> scgen__tiles0_c2[2];
   sc_signal<int> scgen__tiles0_c3[2];
   sc_signal<int> scgen__tiles0_c4[2];
   sc_signal<int> scgen__tiles0_c5[2];
  

  public: void kernel_mm()
{
    while(1){
   while(!scgen__start) wait();
      int c3;
      int c4;
      int c5;
      int c2;
      int c0;
      int c1;
{
        int B_l[32][32];
        int A_l[32][32];
        int C_l[32][32];
        for (c0 = 0; c0 <= 31; c0 += 2) {
// send signal for loop0modules to start
for(int loopi=0; loopi<(2<(31+1-c0)?2:(31+1-c0)) ; ++loopi)
{
   scgen__tiles0_c1[loopi]=c1;
   scgen__tiles0_c0[loopi]=(0+c0+(loopi*1));
   scgen__tiles0_c2[loopi]=c2;
   scgen__tiles0_c3[loopi]=c3;
   scgen__tiles0_c4[loopi]=c4;
   scgen__tiles0_c5[loopi]=c5;
   scgen__tiles0_start[loopi]=true;//start the tile's thread
}
wait(1, SC_NS);
for(int loopi=0; loopi<(2<(31+1-c0)?2:(31+1-c0)); loopi++)
{
   scgen__tiles0_start[loopi]=false;
}
bool all_done = false;
while(!all_done){
   wait();
   bool tmp = true;
   for(int loopi=0; loopi<(2<(31+1-c0)?2:(31+1-c0)); loopi++){
      tmp &= scgen__tiles0_done[loopi];
   }
   all_done = tmp;
}{
          }
        }
      }
   scgen__running = false;
   sc_stop();
    }
  }
   SC_HAS_PROCESS(kernel_mm_module);
   kernel_mm_module(const sc_module_name& p_name) :
     sc_module(p_name)
   {
      SC_THREAD(kernel_mm);
      sensitive << scgen__start;
   for(int loopi=0; loopi<2; loopi++)
   {
      sensitive << scgen__tiles0_done[loopi];
   }
   for(int loopi=0; loopi<2; loopi++)
   {
      //creat tile module
      std::stringstream ss;
      ss << "tile0_" << loopi;
      scgen__tiles0[loopi] = new kernel_mm_loop0_module((ss.str().c_str()));
      //bind ports
      scgen__tiles0[loopi]->scgen__start(scgen__tiles0_start[loopi]);
      scgen__tiles0[loopi]->scgen__done(scgen__tiles0_done[loopi]);
      scgen__tiles0[loopi]->scgen__c1(scgen__tiles0_c1[loopi]);
      scgen__tiles0[loopi]->scgen__c0(scgen__tiles0_c0[loopi]);
      scgen__tiles0[loopi]->scgen__c2(scgen__tiles0_c2[loopi]);
      scgen__tiles0[loopi]->scgen__c3(scgen__tiles0_c3[loopi]);
      scgen__tiles0[loopi]->scgen__c4(scgen__tiles0_c4[loopi]);
      scgen__tiles0[loopi]->scgen__c5(scgen__tiles0_c5[loopi]);
   }
   }
}
;

int sc_main(int argc,char **argv)
{
  initialize();kernel_mm_module* top_module = new kernel_mm_module("top_module");
   sc_signal<bool> start;
   top_module->scgen__start(start);
   // Start simulation
   sc_set_time_resolution(1,SC_NS);
   start=true;
   sc_start(1, SC_NS);
   start = false;
   cout << "start @" << sc_time_stamp() << endl;
   sc_start(); // start the simulation
   cout << "Energy: " << energy << endl;
   cout << "Latency: " << sc_time_stamp() << endl;
{
  }
  check_correctness();
  return 0;
}
