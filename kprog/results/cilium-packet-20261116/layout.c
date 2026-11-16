#include <linux/bpf.h>
#include <stddef.h>
#include <stdio.h>
int main(void)
{
    printf("{\"size\":%zu,\"ifindex\":%zu,\"ingress_ifindex\":%zu,\"wire_len\":%zu}\n",
           sizeof(struct __sk_buff), offsetof(struct __sk_buff, ifindex),
           offsetof(struct __sk_buff, ingress_ifindex), offsetof(struct __sk_buff, wire_len));
}
