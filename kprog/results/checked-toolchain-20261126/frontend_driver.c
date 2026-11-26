#include <stdio.h>
extern int trusted_arm64_arm64_sim_xdp(void *);
int main(void) { printf("native_return=%d\n",trusted_arm64_arm64_sim_xdp(0)); return 0; }
