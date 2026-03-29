# llvmbpf Bulk Round-Trip Report (2026-03-29)

## Scope

- Objects tested: `10`
- Programs discovered from symbol tables: `44`
- Program lift success: `35/44` (79.5%)
- Program LLVM lower success: `23/35` (65.7%)
- Program verifier pass success: `0/23` (0.0%)
- End-to-end program coverage over the tested corpus slice: `0/44` (0.0%)
- Total `map_lookup_elem` candidate sites in lifted LLVM IR: `29`
- Programs that lowered but were not pinned by `bpftool prog loadall` in the VM: `12`

## Families

- `bcc`: 10 object(s)

## Failure Breakdown

### Lift failures: top 5

- `program not reported by llvmbpf build output`: 6
- `Unable to generate llvm module`: 3

### Verifier / VM failures: top 5

- `program not pinned by bpftool prog loadall`: 12
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 3
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
Invalid line_info[8].insn_off:18 (prev_offset:11 prog->len:18)
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 2
- `BPF_PROG_LOAD: Permission denied (os error 13)
verifier log:
func#0 @0
Live regs before insn:
      0: .1........ (bf) r6 = r1
      1: ......6... (61) r1 = *(u32 *)(r6 +80)
      2: .1....6... (61) r8 = *(u32 *)(r6 +84)
      3: .1....6.8. (67) r8 <<= 32
      4: .1....6.8. (4f) r8 |= r1
      5: ......6.8. (15) if r8 == 0x0 goto pc+37
      6: ......6.8. (bf) r7 = r10
      7: ......678. (07) r7 += -80
      8: ......678. (bf) r1 = r7
      9: .1....678. (07) r1 += -100
     10: .1....678. (b7) r2 = 16
     11: .12...678. (b7) r5 = 84
     12: .12...678. (85) call bpf_get_current_comm#16
     13: ......678. (71) r1 = *(u8 *)(r10 -180)
     14: .1....678. (56) if w1 != 0x62 goto pc+28
     15: ......678. (71) r1 = *(u8 *)(r10 -179)
     16: .1....678. (56) if w1 != 0x61 goto pc+26
     17: ......678. (71) r1 = *(u8 *)(r10 -178)
     18: .1....678. (56) if w1 != 0x73 goto pc+24
     19: ......678. (71) r1 = *(u8 *)(r10 -177)
     20: .1....678. (56) if w1 != 0x68 goto pc+22
     21: ......678. (71) r1 = *(u8 *)(r10 -176)
     22: .1....678. (56) if w1 != 0x0 goto pc+20
     23: ......678. (b7) r1 = 0
     24: ......678. (b7) r2 = 16
     25: ......678. (b7) r5 = 84
     26: ......678. (85) call bpf_get_current_pid_tgid#14
     27: 0.....678. (77) r0 >>= 32
     28: 0.....678. (63) *(u32 *)(r10 -164) = r0
     29: ......678. (bf) r1 = r7
     30: .1....678. (07) r1 += -80
     31: .1....678. (b7) r2 = 80
     32: .12...678. (bf) r3 = r8
     33: .123..67.. (b7) r5 = 84
     34: .123..67.. (85) call bpf_probe_read_user_str#114
     35: ......67.. (07) r7 += -84
     36: ......67.. (bf) r1 = r6
     37: .1.....7.. (b7) r2 = 0
     38: .12....7.. (18) r3 = 0xffffffff
     40: .123...7.. (bf) r4 = r7
     41: .1234..... (b7) r5 = 84
     42: .12345.... (85) call bpf_perf_event_output#25
     43: .......... (b7) r0 = 0
     44: 0......... (95) exit
0: R1=ctx() R10=fp0
; int BPF_URETPROBE(printret, const void *ret) { @ bashreadline.bpf.c:17
0: (bf) r6 = r1                       ; R1=ctx() R6=ctx()
1: (61) r1 = *(u32 *)(r6 +80)         ; R1=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R6=ctx()
; if (!ret) @ bashreadline.bpf.c:22
2: (61) r8 = *(u32 *)(r6 +84)         ; R6=ctx() R8=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))
3: (67) r8 <<= 32                     ; R8=scalar(smax=0x7fffffff00000000,umax=0xffffffff00000000,smin32=0,smax32=umax32=0,var_off=(0x0; 0xffffffff00000000))
; bpf_get_current_comm(&comm, sizeof(comm)); @ bashreadline.bpf.c:25
4: (4f) r8 |= r1                      ; R1=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R8=scalar()
5: (15) if r8 == 0x0 goto pc+37       ; R8=scalar(umin=1)
6: (bf) r7 = r10                      ; R7=fp0 R10=fp0
; if (comm[0] != 'b' || comm[1] != 'a' || comm[2] != 's' || comm[3] != 'h' || comm[4] != 0 ) @ bashreadline.bpf.c:26
7: (07) r7 += -80                     ; R7=fp-80
8: (bf) r1 = r7                       ; R1=fp-80 R7=fp-80
9: (07) r1 += -100                    ; R1=fp-180
10: (b7) r2 = 16                      ; R2=16
11: (b7) r5 = 84                      ; R5=84
12: (85) call bpf_get_current_comm#16
mark_precise: frame0: last_idx 12 first_idx 0 subseq_idx -1 
mark_precise: frame0: regs=r2 stack= before 11: (b7) r5 = 84
mark_precise: frame0: regs=r2 stack= before 10: (b7) r2 = 16
13: R0=scalar() fp-168=????mmmm fp-176=mmmmmmmm fp-184=mmmm????
13: (71) r1 = *(u8 *)(r10 -180)       ; R1=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R10=fp0 fp-184=mmmm????
14: (56) if w1 != 0x62 goto pc+28     ; R1=98
15: (71) r1 = *(u8 *)(r10 -179)       ; R1=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R10=fp0 fp-184=mmmm????
16: (56) if w1 != 0x61 goto pc+26     ; R1=97
; pid = bpf_get_current_pid_tgid() >> 32; @ bashreadline.bpf.c:29
17: (71) r1 = *(u8 *)(r10 -178)       ; R1=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R10=fp0 fp-184=mmmm????
18: (56) if w1 != 0x73 goto pc+24     ; R1=115
; data.pid = pid; @ bashreadline.bpf.c:30
19: (71) r1 = *(u8 *)(r10 -177)       ; R1=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R10=fp0 fp-184=mmmm????
; bpf_probe_read_user_str(&data.str, sizeof(data.str), ret); @ bashreadline.bpf.c:31
20: (56) if w1 != 0x68 goto pc+22     ; R1=104
21: (71) r1 = *(u8 *)(r10 -176)       ; R1=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R10=fp0 fp-176=mmmmmmmm
22: (56) if w1 != 0x0 goto pc+20      ; R1=0
23: (b7) r1 = 0                       ; R1=0
24: (b7) r2 = 16                      ; R2=16
25: (b7) r5 = 84                      ; R5=84
; pid = bpf_get_current_pid_tgid() >> 32; @ bashreadline.bpf.c:29
26: (85) call bpf_get_current_pid_tgid#14     ; R0=scalar()
; bpf_perf_event_output(ctx, &events, BPF_F_CURRENT_CPU, &data, sizeof(data)); @ bashreadline.bpf.c:33
27: (77) r0 >>= 32                    ; R0=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))
28: (63) *(u32 *)(r10 -164) = r0      ; R0=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=fp0 fp-168=mmmmmmmm
29: (bf) r1 = r7                      ; R1=fp-80 R7=fp-80
30: (07) r1 += -80                    ; R1=fp-160
31: (b7) r2 = 80                      ; R2=80
32: (bf) r3 = r8                      ; R3=scalar(id=1,umin=1) R8=scalar(id=1,umin=1)
33: (b7) r5 = 84                      ; R5=84
; int BPF_URETPROBE(printret, const void *ret) { @ bashreadline.bpf.c:17
34: (85) call bpf_probe_read_user_str#114
mark_precise: frame0: last_idx 34 first_idx 22 subseq_idx -1 
mark_precise: frame0: regs=r2 stack= before 33: (b7) r5 = 84
mark_precise: frame0: regs=r2 stack= before 32: (bf) r3 = r8
mark_precise: frame0: regs=r2 stack= before 31: (b7) r2 = 80
35: R0=scalar(smin=smin32=-4095,smax=smax32=80) fp-88=mmmmmmmm fp-96=mmmmmmmm fp-104=mmmmmmmm fp-112=mmmmmmmm fp-120=mmmmmmmm fp-128=mmmmmmmm fp-136=mmmmmmmm fp-144=mmmmmmmm fp-152=mmmmmmmm fp-160=mmmmmmmm
35: (07) r7 += -84                    ; R7=fp-164
36: (bf) r1 = r6                      ; R1=ctx() R6=ctx()
37: (b7) r2 = 0                       ; R2=0
38: (18) r3 = 0xffffffff              ; R3=0xffffffff
40: (bf) r4 = r7                      ; R4=fp-164 R7=fp-164
41: (b7) r5 = 84                      ; R5=84
42: (85) call bpf_perf_event_output#25
R2 type=scalar expected=map_ptr
processed 42 insns (limit 1000000) max_states_per_insn 0 total_states 3 peak_states 3 mark_read 0
`: 1
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
Invalid line_info[22].insn_off:69 (prev_offset:67 prog->len:68)
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 1

## Conclusion

The LLVM IR round-trip path is viable on a meaningful slice of real-world BPF programs: 0 programs from 10 real-world objects completed host lift/O2/lower and then passed a fresh VM-side `BPF_PROG_LOAD` verifier check. The main blockers remain llvmbpf lift failures on specific control-flow patterns and VM-side loadability gaps where `bpftool prog loadall` could not materialize the original program context.

## Artifacts

- Manifest: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/smoke_manifest_fix.json`
- Guest verify results: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/smoke_guest_results_fix.json`
- Guest helper binary: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/target/release/llvmbpf-bulk-guest-verify`
