

#include "time.h"
#include "signal.h"

int
main() {
  timer_create(CLOCK_MONOTONIC, NULL, NULL);
return 0;
}
