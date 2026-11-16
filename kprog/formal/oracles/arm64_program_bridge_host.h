/* Execute the existing whole-frame oracle through the borrowed entry ABI.
 * Compound literals live through each call. Only the oracle's fixed arguments
 * are repeated; production program operands are not transformed by this file.
 */
#include "../c/Arm64Program.h"
#define PROGRAM_VIEW(A, VECS, N, Z, C, V) \
 (&(struct kprog_arm64_entry){ \
 .cells = (union arm64_sim_gpr *const[]){&(A)->registers[0], &(A)->registers[1], &(A)->registers[2], &(A)->registers[3], &(A)->registers[4], &(A)->registers[5], &(A)->registers[6], &(A)->registers[7], &(A)->registers[8], &(A)->registers[9], &(A)->registers[10], &(A)->registers[11], &(A)->registers[12], &(A)->registers[13], &(A)->registers[14], &(A)->registers[15], &(A)->registers[16], &(A)->registers[17], &(A)->registers[18], &(A)->registers[19], &(A)->registers[20], &(A)->registers[21], &(A)->registers[22], &(A)->registers[23], &(A)->registers[24], &(A)->registers[25], &(A)->registers[26], &(A)->registers[27], &(A)->registers[28], &(A)->registers[29], &(A)->registers[30]}, \
 .tag_cells = (__u8 *const[]){&(A)->tags[0], &(A)->tags[1], &(A)->tags[2], &(A)->tags[3], &(A)->tags[4], &(A)->tags[5], &(A)->tags[6], &(A)->tags[7], &(A)->tags[8], &(A)->tags[9], &(A)->tags[10], &(A)->tags[11], &(A)->tags[12], &(A)->tags[13], &(A)->tags[14], &(A)->tags[15], &(A)->tags[16], &(A)->tags[17], &(A)->tags[18], &(A)->tags[19], &(A)->tags[20], &(A)->tags[21], &(A)->tags[22], &(A)->tags[23], &(A)->tags[24], &(A)->tags[25], &(A)->tags[26], &(A)->tags[27], &(A)->tags[28], &(A)->tags[29], &(A)->tags[30]}, \
 .sp_base = &(A)->coordinates->sp_base, .return_base = &(A)->coordinates->return_base, \
 .sp = &(A)->coordinates->stack_offset, .sp_valid = &(A)->coordinates->sp_valid, \
 .return_valid = &(A)->coordinates->return_valid, .lr = &(__u64){0}, \
 .n = (N), .z = (Z), .c = (C), .v = (V), \
 .b = (A)->b, .q = (A)->q, .payload = (A)->payload, .stack_tags = (A)->stack_tags, \
 .payload_load = kprog_arm64_payload_load, .payload_store = kprog_arm64_payload_store, \
 .capacity = (A)->capacity, .bias = (A)->bias, \
 .helper_context = &(A)->helper_context, .helper_abi_base = &(A)->helper_abi_base, \
 .is_xdp = &(A)->is_xdp, .abi_kind = &(A)->abi_kind, \
 .skb_context = &(struct __sk_buff *){0}, .abi = (A)->helper_abi_base, \
 .vector_lo = {&(VECS)[0].lo, &(VECS)[1].lo, &(VECS)[2].lo, &(VECS)[3].lo, &(VECS)[4].lo, &(VECS)[5].lo, &(VECS)[6].lo, &(VECS)[7].lo, &(VECS)[8].lo, &(VECS)[9].lo, &(VECS)[10].lo, &(VECS)[11].lo, &(VECS)[12].lo, &(VECS)[13].lo, &(VECS)[14].lo, &(VECS)[15].lo, &(VECS)[16].lo, &(VECS)[17].lo, &(VECS)[18].lo, &(VECS)[19].lo, &(VECS)[20].lo, &(VECS)[21].lo, &(VECS)[22].lo, &(VECS)[23].lo, &(VECS)[24].lo, &(VECS)[25].lo, &(VECS)[26].lo, &(VECS)[27].lo, &(VECS)[28].lo, &(VECS)[29].lo, &(VECS)[30].lo, &(VECS)[31].lo}, \
 .vector_hi = {&(VECS)[0].hi, &(VECS)[1].hi, &(VECS)[2].hi, &(VECS)[3].hi, &(VECS)[4].hi, &(VECS)[5].hi, &(VECS)[6].hi, &(VECS)[7].hi, &(VECS)[8].hi, &(VECS)[9].hi, &(VECS)[10].hi, &(VECS)[11].hi, &(VECS)[12].hi, &(VECS)[13].hi, &(VECS)[14].hi, &(VECS)[15].hi, &(VECS)[16].hi, &(VECS)[17].hi, &(VECS)[18].hi, &(VECS)[19].hi, &(VECS)[20].hi, &(VECS)[21].hi, &(VECS)[22].hi, &(VECS)[23].hi, &(VECS)[24].hi, &(VECS)[25].hi, &(VECS)[26].hi, &(VECS)[27].hi, &(VECS)[28].hi, &(VECS)[29].hi, &(VECS)[30].hi, &(VECS)[31].hi} })
#define kprog_arm64_execute(A, VECS, N, Z, C, V, OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM) \
 kprog_arm64_program_execute(PROGRAM_VIEW(A, VECS, N, Z, C, V), (OP), (DST), (SRC), (SRC2), (SRC3), (FLAGS), (AUX), (IMM))
#define kprog_arm64_libc_memset(A, VECS, N, Z, C, V) kprog_arm64_program_memset(PROGRAM_VIEW(A, VECS, N, Z, C, V))
#define kprog_arm64_libc_memcpy(A, VECS, N, Z, C, V) kprog_arm64_program_memcpy(PROGRAM_VIEW(A, VECS, N, Z, C, V))
#define kprog_arm64_helper_bpf_map_lookup_elem(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_map_lookup_elem(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_map_update_elem(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_map_update_elem(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_probe_read(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_probe_read(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_ktime_get_ns(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_ktime_get_ns(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_trace_printk(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_trace_printk(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_get_prandom_u32(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_get_prandom_u32(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_xdp_adjust_head(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_xdp_adjust_head(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_xdp_adjust_meta(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_xdp_adjust_meta(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_xdp_adjust_tail(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_xdp_adjust_tail(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_ringbuf_submit(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_ringbuf_submit(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_ringbuf_discard(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_ringbuf_discard(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_dynptr_read(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_dynptr_read(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_dynptr_write(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_dynptr_write(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_ringbuf_submit_dynptr(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_ringbuf_submit_dynptr(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
#define kprog_arm64_helper_bpf_ringbuf_discard_dynptr(A, VECS, N, Z, C, V, FN) kprog_arm64_program_helper_bpf_ringbuf_discard_dynptr(PROGRAM_VIEW(A, VECS, N, Z, C, V), (FN))
