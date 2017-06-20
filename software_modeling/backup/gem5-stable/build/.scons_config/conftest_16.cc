
#include <linux/perf_event.h>
int main(){
  struct perf_event_attr test;
  (void)test.exclude_host;
  return 0;
};
