/* Actual compat calls must reload arguments after a SysV helper clobbers them. */
#include <linux/bpf.h>
#include <stdint.h>
#define MICRO_NATIVE_HELPER_MACROS
#define MICRO_NATIVE_TETRAGON
#include "../../vendor/bpf/core-compat.h"

__attribute__((visibility("hidden"))) volatile unsigned long last_value;
extern unsigned long host0(void), host1(void), host2(void), host3(void),
    host4(void), host5(void), host3v(void);
#define CLOBBER "xor %edi,%edi\nxor %esi,%esi\nxor %edx,%edx\nxor %ecx,%ecx\n" \
    "xor %r8d,%r8d\nxor %r9d,%r9d\nxor %r10d,%r10d\nxor %r11d,%r11d\nret\n"
#define HOST(name, sum) ".text\n.globl " #name "\n.type " #name ",@function\n" \
    #name ":\nmov $11,%eax\n" sum "mov %rax,last_value(%rip)\n" CLOBBER
__asm__(HOST(host0, "")
        HOST(host1, "add %rdi,%rax\n")
        HOST(host2, "add %rdi,%rax\nadd %rsi,%rax\n")
        HOST(host3, "add %rdi,%rax\nadd %rsi,%rax\nadd %rdx,%rax\n")
        HOST(host4, "add %rdi,%rax\nadd %rsi,%rax\nadd %rdx,%rax\nadd %rcx,%rax\n")
        HOST(host5, "add %rdi,%rax\nadd %rsi,%rax\nadd %rdx,%rax\nadd %rcx,%rax\nadd %r8,%rax\n")
        HOST(host3v, "add %rdi,%rax\nadd %rsi,%rax\nadd %rdx,%rax\n"));

#undef NATIVE_BPF_FUNC_get_current_pid_tgid
#define NATIVE_BPF_FUNC_get_current_pid_tgid ((unsigned long)host0)
#undef NATIVE_BPF_FUNC_send_signal
#define NATIVE_BPF_FUNC_send_signal ((unsigned long)host1)
#undef NATIVE_BPF_FUNC_map_lookup_elem
#define NATIVE_BPF_FUNC_map_lookup_elem ((unsigned long)host2)
#undef NATIVE_BPF_FUNC_probe_read
#define NATIVE_BPF_FUNC_probe_read ((unsigned long)host3)
#undef NATIVE_BPF_FUNC_map_update_elem
#define NATIVE_BPF_FUNC_map_update_elem ((unsigned long)host4)
#undef NATIVE_BPF_FUNC_perf_event_output
#define NATIVE_BPF_FUNC_perf_event_output ((unsigned long)host5)
#undef NATIVE_BPF_FUNC_tail_call
#define NATIVE_BPF_FUNC_tail_call ((unsigned long)host3v)

#define PAIR(name, expr) \
    __attribute__((noinline)) unsigned long name(unsigned long x) { \
        unsigned long first=(unsigned long)(expr); \
        return first+(unsigned long)(expr); \
    }
PAIR(check0, get_current_pid_tgid())
PAIR(check1, send_signal(x))
PAIR(check2, map_lookup_elem((void*)x,(void*)(x+1)))
PAIR(check3, probe_read((void*)x,x+1,(void*)(x+2)))
PAIR(check4, map_update_elem((void*)x,(void*)(x+1),(void*)(x+2),x+3))
PAIR(check5, perf_event_output((void*)x,(void*)(x+1),x+2,(void*)(x+3),x+4))
__attribute__((noinline)) unsigned long check_void(unsigned long x)
{
    tail_call((void*)x,(void*)(x+1),x+2);
    tail_call((void*)x,(void*)(x+1),x+2);
    return last_value;
}
