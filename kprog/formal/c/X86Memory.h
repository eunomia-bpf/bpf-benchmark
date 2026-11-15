#ifndef KPROG_X86_MEMORY_BINDING_H
#define KPROG_X86_MEMORY_BINDING_H
#include "X86Pointer.h"
__u8 kprog_x86_cmov_writeback(__u64);
__u8 kprog_x86_setcc_lane(__u64);
__u8 kprog_x86_setcc_mem_base(__u64);
__u8 kprog_x86_setcc_mem_arm(__u64);
__u8 kprog_x86_movbe_width(__u64);
__u8 kprog_x86_movbe_arm(__u64);
__u64 kprog_x86_read_mem_value(struct x86_sim_register_state *,struct kprog_x86_arena *,
                              __u32,__u64,__u64,__u64,__u64,__u64);
void kprog_x86_movbe_load(struct x86_sim_register_state *,struct kprog_x86_arena *,
                         struct kprog_x86_stack_fact *,__u32,__u64,__u64,__u64,__u64,__u64);
void kprog_x86_store_memory(void *,__u64,__u64);
void kprog_x86_load_xmm0(struct x86_sim_register_state *,struct kprog_x86_arena *,
                         struct kprog_x86_stack_fact *,__u32,__u64,__u64,__u64);
void kprog_x86_store_xmm0(struct x86_sim_register_state *,struct kprog_x86_arena *,
                          struct kprog_x86_stack_fact *,__u32,__u64,__u64,__u64);
void kprog_x86_cmov(struct x86_sim_register_state *,struct kprog_x86_arena *,
                    struct kprog_x86_stack_fact *,__u32,__u8,__u8,__u8,__u32);
void kprog_x86_cmov_mem(struct x86_sim_register_state *,struct kprog_x86_arena *,
                        struct kprog_x86_stack_fact *,__u32,__u8,__u8,__u8,__u32,__u64);
void kprog_x86_setcc(struct x86_sim_register_state *,struct kprog_x86_arena *,
                     struct kprog_x86_stack_fact *,__u32,__u8,__u32);
void kprog_x86_setcc_mem(struct x86_sim_register_state *,struct kprog_x86_arena *,
                         struct kprog_x86_stack_fact *,__u32,__u8,__u32,__u64);
#endif
