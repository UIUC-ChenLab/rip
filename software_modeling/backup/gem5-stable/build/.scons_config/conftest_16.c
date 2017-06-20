#include <linux/kvm.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
    printf("%d", (int)sizeof(struct kvm_xsave));
    return 0;
}
    