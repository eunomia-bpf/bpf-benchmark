/* The scalar fields use the canonical declaration; arena/fact references can
 * bind array storage or separately scalarized producer cells. The active b/q/w/d views
 * name the same live arena; facts cover ceil(capacity/8) distinct live cells.
 * Registers, descriptors and fact cells are separate from arena storage.
 * The producer supplies its capacity unchanged; M5 proves that relation. */
#ifndef KPROG_X86_POINTER_BINDING_H
#define KPROG_X86_POINTER_BINDING_H
#include "../../x86/x86_sim_local_bpf.h"

struct kprog_x86_arena {
	volatile __u8 *b;
	volatile __u64 *q;
	volatile __u16 *w;
	volatile __u32 *d;
};
struct kprog_x86_stack_fact {
	__u8 *tag;
	void **pointer;
};
void kprog_x86_ptr_load(struct x86_sim_register_state *, struct kprog_x86_arena *,
                       struct kprog_x86_stack_fact *, __u32, __u8, __u8, __u32, __u64);
__u64 kprog_x86_read_reg(struct x86_sim_register_state *, struct kprog_x86_arena *,
                        __u32, __u8, __u8, __u8);
void kprog_x86_write_reg(struct x86_sim_register_state *, struct kprog_x86_arena *,
                        struct kprog_x86_stack_fact *, __u32, __u8, __u64, __u8, __u8);
void kprog_x86_mov_imm(struct x86_sim_register_state *, struct kprog_x86_arena *,
                      struct kprog_x86_stack_fact *, __u32, __u8, __u8, __u32, __u64);
void kprog_x86_mov_reg(struct x86_sim_register_state *, struct kprog_x86_arena *,
                      struct kprog_x86_stack_fact *, __u32, __u8, __u8, __u8, __u32);
void kprog_x86_movx_reg(struct x86_sim_register_state *, struct kprog_x86_arena *,
                       struct kprog_x86_stack_fact *, __u32, __u8, __u8, __u8, __u8, __u32);
__s64 kprog_x86_stack_alias(struct kprog_x86_arena *, __u32, const void *);
__u64 kprog_x86_load_tagged(struct x86_sim_register_state *, struct kprog_x86_arena *,
                           __u32, const void *, __u64, __u64);
__u64 kprog_x86_native_load_tagged(struct x86_sim_register_state *, struct kprog_x86_arena *,
                                  __u32, const void *, __s64, __u64, __u64);
__s64 kprog_x86_mem_offset_indexed(__u64, __s64, __u64, int);
__s64 kprog_x86_mem_offset(struct x86_sim_register_state *, struct kprog_x86_arena *,
                           __u32, __u64, __s64);
int kprog_x86_read_recovery_at(struct x86_sim_register_state *, struct kprog_x86_arena *,
                               struct kprog_x86_stack_fact *, __u32, __u64, __u64, __u64);
int kprog_x86_read_recovery(struct x86_sim_register_state *, struct kprog_x86_arena *,
                            struct kprog_x86_stack_fact *, __u32, __u64, __u64);
int kprog_x86_read_recovery_mem(struct x86_sim_register_state *, struct kprog_x86_arena *,
                                struct kprog_x86_stack_fact *, __u32, __u64, __u64, __u64, __s64);
__u8 kprog_x86_mov_load_write_width(__u64);
__u8 kprog_x86_mov_load_mem_width(__u64, __u64);
__u8 kprog_x86_mov_load_arm(__u64, __u64, __u64, __u64, __u64);
__u8 kprog_x86_mem_read_src(__u64, __u64, __u64);
__u64 kprog_x86_stack_read_owned(struct kprog_x86_arena *, __u32, __s64, __u64);
__u64 kprog_x86_stack_read(struct x86_sim_register_state *, struct kprog_x86_arena *,
                           __u32, __s64, __u64);
void kprog_x86_stack_values_read(struct x86_sim_register_state *,
                                  struct kprog_x86_stack_fact *, __u32,
                                  __u64, __u64, struct x86_sim_stack_value *);
#endif
