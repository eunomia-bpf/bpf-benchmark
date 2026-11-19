#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
_Static_assert(__builtin_offsetof(struct sk_buff,len)==112, "headlen len offset");
_Static_assert(__builtin_offsetof(struct sk_buff,data_len)==116, "headlen data_len offset");
_Static_assert(sizeof(((struct sk_buff *)0)->len)==4, "headlen len width");
_Static_assert(sizeof(((struct sk_buff *)0)->data_len)==4, "headlen data_len width");
