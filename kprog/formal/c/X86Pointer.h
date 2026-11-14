/* The scalar fields use the canonical declaration; arena/fact references can
 * bind array storage or separately scalarized producer cells. The b/q views
 * name the same live arena; facts cover ceil(capacity/8) distinct live cells.
 * Registers, descriptors and fact cells are separate from arena storage.
 * The producer supplies its capacity unchanged; M5 proves that relation. */
#ifndef KPROG_X86_POINTER_BINDING_H
#define KPROG_X86_POINTER_BINDING_H
#include "../../x86/x86_sim_local_bpf.h"

struct kprog_x86_arena {
	volatile __u8 *b;
	volatile __u64 *q;
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
#endif
