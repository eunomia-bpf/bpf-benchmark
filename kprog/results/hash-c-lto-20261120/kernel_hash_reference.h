/* Use the actual sole-kernel hash implementation without building kernel tools. */
#include <stdint.h>
#include <string.h>
#define _LINUX_BITOPS_H
#define __LINUX_UNALIGNED_H
typedef uint32_t u32;
typedef unsigned char u8;
#define rol32(v,n) (((u32)(v)<<(n))|((u32)(v)>>(32-(n))))
#define get_unaligned(p) ({ __typeof__(*(p)) v; memcpy(&v,(p),sizeof(v)); v; })
#define fallthrough __attribute__((fallthrough))
#include "../../../vendor/linux-framework/include/linux/jhash.h"
