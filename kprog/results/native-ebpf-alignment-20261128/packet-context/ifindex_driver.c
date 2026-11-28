#include <stdio.h>
#include <string.h>
struct xdp_md;
unsigned native_ifindex(const struct xdp_md *);
unsigned native_ingress(const struct xdp_md *);
int main(void)
{
    unsigned long long xdp[8] = {}, rxq[8] = {}, device[320] = {};
    const unsigned expected = 34;
    // Current canonical BTF on both ISAs: rxq32, dev0, ifindex224.
    xdp[1] = 0x0000001100000000ULL; // unrelated data_end upper word17
    xdp[4] = (unsigned long long)rxq;
    rxq[0] = (unsigned long long)device;
    memcpy((char *)device + 224, &expected, sizeof(expected));
    unsigned a = native_ifindex((void *)xdp), b = native_ingress((void *)xdp);
    printf("{\"ifindex\":%u,\"ingress_ifindex\":%u,\"expected\":%u}\n", a, b, expected);
    return a == expected && b == expected ? 0 : 1;
}
