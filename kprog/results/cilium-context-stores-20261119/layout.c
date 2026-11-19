#include "vmlinux.h"
#define OFFSET(T,F) __builtin_offsetof(struct T,F)
_Static_assert(OFFSET(sk_buff, cb) == 40, "kernel skb control buffer");
_Static_assert(OFFSET(qdisc_skb_cb, tc_classid) == 6, "qdisc class overlay");
_Static_assert(sizeof(((struct qdisc_skb_cb *)0)->tc_classid) == 2, "physical class width");
_Static_assert(OFFSET(__sk_buff, tc_classid) == 72, "public class offset");
_Static_assert(sizeof(((struct __sk_buff *)0)->tc_classid) == 4, "public class width");
_Static_assert(OFFSET(sk_buff, ll_node) == 0, "opening union member");
