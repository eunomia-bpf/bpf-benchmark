#include <stdio.h>
#include <string.h>
struct xdp_md;
unsigned ENTRY(const struct xdp_md *);
#ifndef EXPECTED_VALUE
#define EXPECTED_VALUE 34
#endif
int main(void) {
 unsigned long long xdp[8]={},rxq[8]={},device[320]={}; unsigned expected=34;
 xdp[1]=0x0000001100000000ULL;xdp[4]=(unsigned long long)rxq;rxq[0]=(unsigned long long)device;
 memcpy((char*)device+224,&expected,4);
 unsigned value=ENTRY((void*)xdp);printf("{\"value\":%u,\"expected\":%u}\n",value,(unsigned)EXPECTED_VALUE);
 return value==EXPECTED_VALUE?0:1;
}
