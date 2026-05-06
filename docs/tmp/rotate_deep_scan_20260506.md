# Rotate Deep Scan on Captured Cilium Production Bytecode - 2026-05-06

## Scope and Reproducibility

Inputs scanned:

- Captured programs: `corpus/results/x86_kvm_corpus_20260506_205924_738444/details/failure-artifacts/*.tar.gz` (56 tarballs).
- Captured byte stream per tarball: `captured-input-rotate.bin` when present, otherwise `input_step0.bin`.
- Result metadata for names/types: `corpus/results/x86_kvm_corpus_20260506_205924_738444/details/result.json`.
- Offline object: `corpus/build/cilium/bpf_xdp.bpf.o`.
- Rotate matcher inspected via `git show HEAD:bpfopt/crates/bpfopt/src/passes/rotate.rs`.

Checkout note: prompt said `HEAD = 88e43e83`; this checkout is `f67b5ce43164d75606fcb948cb46443fc1c41247` (`f67b5ce4 Add major BPF program trigger analysis and tail-call guard relaxation analysis reports`). Commit `88e43e83` exists as `88e43e83 fix: enhance timeout settings and add rotate capture functionality`, and `rotate.rs` has `none` diff between `88e43e83` and current `HEAD`.

Helper outputs generated outside the repo:

- `/tmp/rotate_deep_scan.py` - raw BPF decoder, loose scanner, and Python mirror of the rotate matcher.
- `/tmp/rotate_deep_scan.json` - structured scan results.
- `/tmp/rotate_captured_56_disasm.txt` - comprehensive disassembly for all 56 captured programs.
- `/tmp/rotate_offline_bpf_xdp_disasm.txt` - comprehensive disassembly for executable sections in the offline object.
- `/tmp/rotate_bpfopt_confirm/xdp_tail.report.json` - `bpfopt --pass rotate` confirmation on offline `xdp/tail`.

The raw decoder treats each instruction as Linux `struct bpf_insn`: `u8 code`, `u4 dst`, `u4 src`, `s16 off`, `s32 imm`, little-endian. LSH/RSH/OR counts include both ALU32 and ALU64, immediate and register-source variants.

## Section 1: Per-Program LSH/RSH/OR Histogram Across 56 Captured Programs

Totals across 56 captured programs: `22476` instructions, `441` LSH, `79` RSH, `422` ALU OR, `69` BPF_END. Captured rotate pass reports sum to `0` matched sites.

Operation-kind breakdown:

| kind | count |
| --- | --- |
| ALU32:LSH/K | 251 |
| ALU32:LSH/X | 67 |
| ALU32:OR/K | 14 |
| ALU32:OR/X | 286 |
| ALU32:RSH/K | 55 |
| ALU32:RSH/X | 24 |
| ALU64:LSH/K | 123 |
| ALU64:OR/X | 122 |

Histogram by `(LSH, RSH, OR)` tuple:

| LSH | RSH | OR | program_count |
| --- | --- | --- | --- |
| 0 | 0 | 0 | 16 |
| 0 | 0 | 1 | 8 |
| 1 | 0 | 0 | 1 |
| 2 | 3 | 2 | 8 |
| 4 | 0 | 3 | 5 |
| 10 | 4 | 7 | 5 |
| 24 | 0 | 23 | 6 |
| 30 | 5 | 30 | 7 |

Per-program histogram:

| prog_id | name | type | insns | LSH | RSH | OR | BPF_END | rotate_sites_matched |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 10 | dump_bpf_map | tracing | 35 | 0 | 0 | 0 | 0 | 0 |
| 11 | dump_bpf_prog | tracing | 65 | 1 | 0 | 0 | 0 | 0 |
| 67 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 68 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 69 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 70 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 71 | cil_to_netdev | sched_cls | 489 | 10 | 4 | 7 | 3 | 0 |
| 73 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 74 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 76 | cil_to_host | sched_cls | 351 | 4 | 0 | 3 | 3 | 0 |
| 77 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 78 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 80 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 81 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 82 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 84 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 85 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 86 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 87 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 90 | cil_to_netdev | sched_cls | 489 | 10 | 4 | 7 | 3 | 0 |
| 92 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 93 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 94 | cil_to_netdev | sched_cls | 489 | 10 | 4 | 7 | 3 | 0 |
| 95 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 96 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 97 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 98 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 99 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 100 | cil_to_host | sched_cls | 351 | 4 | 0 | 3 | 3 | 0 |
| 101 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 104 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 105 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 106 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 107 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 108 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 109 | cil_to_host | sched_cls | 351 | 4 | 0 | 3 | 3 | 0 |
| 110 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 111 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 112 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 113 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 114 | cil_to_netdev | sched_cls | 489 | 10 | 4 | 7 | 3 | 0 |
| 115 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 116 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 117 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 118 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 119 | cil_to_netdev | sched_cls | 489 | 10 | 4 | 7 | 3 | 0 |
| 120 | cil_to_host | sched_cls | 351 | 4 | 0 | 3 | 3 | 0 |
| 121 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 122 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |
| 124 | cil_from_netdev | sched_cls | 1110 | 24 | 0 | 23 | 3 | 0 |
| 125 | cil_host_policy | sched_cls | 2 | 0 | 0 | 0 | 0 | 0 |
| 126 | cil_from_host | sched_cls | 1194 | 30 | 5 | 30 | 3 | 0 |
| 127 | tail_handle_ipv4_from_netdev | sched_cls | 70 | 0 | 0 | 0 | 0 | 0 |
| 128 | cil_to_host | sched_cls | 351 | 4 | 0 | 3 | 3 | 0 |
| 129 | tail_handle_ipv4_from_host | sched_cls | 227 | 0 | 0 | 1 | 0 | 0 |
| 130 | tail_drop_notify | sched_cls | 96 | 2 | 3 | 2 | 0 | 0 |

## Section 2: Near-Match Findings in Captured Programs

Loose scan definition: any opposite-direction LSH/RSH pair with the same ALU width within 10 instructions, plus any ALU OR within 10 instructions of both shifts that touches at least one shifted register. This is intentionally broader than the matcher and includes variable-shift bitfield code.

Captured loose shift/OR triples found: `95`. Opposite-direction LSH/RSH pairs within 10 instructions regardless of OR: `93`. Immediate-source opposite-direction pairs within 10 instructions: `0`. Complementary immediate pairs: `0`. Non-complementary immediate pairs: `0`.

Judgement summary:

| judgement | count |
| --- | --- |
| bitfield/variable-shift, not rotate matcher input | 95 |

Near-match count by program:

| prog_id | name | loose_triples |
| --- | --- | --- |
| 68 | cil_from_host | 10 |
| 71 | cil_to_netdev | 5 |
| 80 | cil_from_host | 10 |
| 90 | cil_to_netdev | 5 |
| 94 | cil_to_netdev | 5 |
| 98 | cil_from_host | 10 |
| 99 | cil_from_host | 10 |
| 107 | cil_from_host | 10 |
| 114 | cil_to_netdev | 5 |
| 118 | cil_from_host | 10 |
| 119 | cil_to_netdev | 5 |
| 126 | cil_from_host | 10 |

Every captured loose triple below was judged as bitfield or variable-shift packing/extraction, not rotate. Common disqualifiers: at least one shift uses a register count (`/X`), no immediate pair exists to pass or fail the complementary-constant check, and the OR does not combine two shifted copies of the same source value.

### Captured Near-Match 1: prog 68 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   68:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   68:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   68:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   68:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   68:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   68:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   68:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   68:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 68:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   68:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   68:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   68:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 68:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   68:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   68:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   68:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00317: bf 76 00 00 00 00 00 00 r6 = r7
   68:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   68:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   68:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 2: prog 68 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   68:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   68:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   68:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   68:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   68:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   68:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   68:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   68:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 68:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   68:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   68:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   68:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   68:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 68:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00317: bf 76 00 00 00 00 00 00 r6 = r7
   68:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   68:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   68:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   68:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   68:00322: bf a2 00 00 00 00 00 00 r2 = r10
   68:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   68:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 3: prog 68 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   68:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   68:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   68:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   68:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   68:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   68:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   68:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 68:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   68:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   68:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 68:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00317: bf 76 00 00 00 00 00 00 r6 = r7
   68:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   68:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   68:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   68:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   68:00322: bf a2 00 00 00 00 00 00 r2 = r10
   68:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   68:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 4: prog 68 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   68:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   68:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   68:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   68:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   68:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   68:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   68:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 68:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   68:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   68:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   68:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 68:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 68:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00317: bf 76 00 00 00 00 00 00 r6 = r7
   68:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   68:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   68:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   68:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   68:00322: bf a2 00 00 00 00 00 00 r2 = r10
   68:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   68:00324: bf a3 00 00 00 00 00 00 r3 = r10
   68:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 5: prog 68 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   68:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   68:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   68:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   68:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   68:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   68:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   68:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   68:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 68:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   68:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   68:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 6: prog 68 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   68:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   68:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   68:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   68:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   68:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   68:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   68:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   68:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00425: bf 56 00 00 00 00 00 00 r6 = r5
   68:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   68:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   68:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   68:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 7: prog 68 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   68:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   68:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   68:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   68:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00425: bf 56 00 00 00 00 00 00 r6 = r5
   68:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   68:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   68:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   68:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 8: prog 68 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   68:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   68:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   68:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   68:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 68:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00425: bf 56 00 00 00 00 00 00 r6 = r5
   68:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   68:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   68:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   68:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   68:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   68:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 9: prog 68 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 68:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   68:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00425: bf 56 00 00 00 00 00 00 r6 = r5
   68:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   68:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   68:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   68:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   68:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 10: prog 68 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   68:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   68:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   68:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   68:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   68:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   68:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   68:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   68:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   68:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   68:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 68:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   68:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   68:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   68:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 68:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 68:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   68:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   68:00425: bf 56 00 00 00 00 00 00 r6 = r5
   68:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   68:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   68:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   68:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   68:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   68:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   68:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 11: prog 71 `cil_to_netdev` PCs [223, 229, 231]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   71:00213: 04 02 00 00 08 00 00 00 w2 += 0x8
   71:00214: 6c 28 00 00 00 00 00 00 w8 <<= w2
   71:00215: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   71:00216: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00217: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   71:00218: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   71:00219: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   71:00220: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00221: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   71:00222: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 71:00223: 6c 45 00 00 00 00 00 00 w5 <<= w4
   71:00224: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   71:00225: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   71:00226: 5c 52 00 00 00 00 00 00 w2 &= w5
   71:00227: 5c 18 00 00 00 00 00 00 w8 &= w1
   71:00228: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 71:00229: 7c 38 00 00 00 00 00 00 w8 >>= w3
   71:00230: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 71:00231: 4c 18 00 00 00 00 00 00 w8 |= w1
   71:00232: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   71:00233: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00234: 05 00 20 00 00 00 00 00 goto +32 <pc 267>
   71:00235: 16 09 24 00 00 0e 00 00 if w9 == 0xe00 goto +36 <pc 272>
   71:00236: 16 09 01 00 00 0f 00 00 if w9 == 0xf00 goto +1 <pc 238>
   71:00237: 05 00 21 00 00 00 00 00 goto +33 <pc 271>
   71:00238: 61 61 08 00 00 00 00 00 r1 = *(w) (r6 +0x8)
   71:00239: 18 62 00 00 00 00 00 00 r2 = 0x800000000 ll
   71:00240: 00 00 00 00 08 00 00 00 <ldimm64 high half>
   71:00241: 61 28 00 00 00 00 00 00 r8 = *(w) (r2 +0x0)
```

### Captured Near-Match 12: prog 71 `cil_to_netdev` PCs [256, 262, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   71:00246: 04 02 00 00 08 00 00 00 w2 += 0x8
   71:00247: 6c 28 00 00 00 00 00 00 w8 <<= w2
   71:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   71:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   71:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   71:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   71:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   71:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 71:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   71:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   71:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   71:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   71:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   71:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 71:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   71:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 71:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   71:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   71:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
   71:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   71:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   71:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   71:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   71:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   71:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   71:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
```

### Captured Near-Match 13: prog 71 `cil_to_netdev` PCs [258, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w2 >>= 0x10`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   71:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   71:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   71:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   71:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   71:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   71:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   71:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   71:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
=> 71:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   71:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   71:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   71:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
   71:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   71:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 71:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   71:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   71:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 71:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   71:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   71:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   71:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   71:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   71:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   71:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   71:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   71:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   71:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   71:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 14: prog 71 `cil_to_netdev` PCs [262, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   71:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   71:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   71:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   71:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   71:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   71:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   71:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   71:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   71:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 71:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   71:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 71:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   71:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   71:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 71:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   71:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   71:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   71:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   71:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   71:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   71:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   71:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   71:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   71:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   71:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 15: prog 71 `cil_to_netdev` PCs [262, 268, 269]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   71:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   71:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   71:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   71:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   71:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   71:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   71:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   71:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   71:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 71:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   71:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
   71:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   71:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   71:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   71:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 71:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
=> 71:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   71:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   71:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   71:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   71:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   71:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   71:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   71:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   71:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   71:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   71:00279: 71 44 00 00 00 00 00 00 r4 = *(b) (r4 +0x0)
```

### Captured Near-Match 16: prog 80 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   80:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   80:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   80:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   80:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   80:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   80:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   80:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   80:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 80:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   80:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   80:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   80:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 80:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   80:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   80:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   80:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00317: bf 76 00 00 00 00 00 00 r6 = r7
   80:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   80:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   80:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 17: prog 80 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   80:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   80:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   80:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   80:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   80:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   80:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   80:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   80:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 80:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   80:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   80:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   80:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   80:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 80:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00317: bf 76 00 00 00 00 00 00 r6 = r7
   80:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   80:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   80:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   80:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   80:00322: bf a2 00 00 00 00 00 00 r2 = r10
   80:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   80:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 18: prog 80 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   80:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   80:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   80:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   80:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   80:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   80:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   80:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 80:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   80:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   80:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 80:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00317: bf 76 00 00 00 00 00 00 r6 = r7
   80:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   80:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   80:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   80:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   80:00322: bf a2 00 00 00 00 00 00 r2 = r10
   80:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   80:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 19: prog 80 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   80:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   80:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   80:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   80:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   80:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   80:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   80:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 80:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   80:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   80:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   80:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 80:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 80:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00317: bf 76 00 00 00 00 00 00 r6 = r7
   80:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   80:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   80:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   80:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   80:00322: bf a2 00 00 00 00 00 00 r2 = r10
   80:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   80:00324: bf a3 00 00 00 00 00 00 r3 = r10
   80:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 20: prog 80 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   80:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   80:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   80:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   80:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   80:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   80:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   80:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   80:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 80:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   80:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   80:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 21: prog 80 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   80:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   80:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   80:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   80:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   80:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   80:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   80:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   80:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00425: bf 56 00 00 00 00 00 00 r6 = r5
   80:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   80:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   80:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   80:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 22: prog 80 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   80:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   80:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   80:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   80:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00425: bf 56 00 00 00 00 00 00 r6 = r5
   80:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   80:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   80:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   80:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 23: prog 80 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   80:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   80:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   80:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   80:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 80:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00425: bf 56 00 00 00 00 00 00 r6 = r5
   80:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   80:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   80:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   80:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   80:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   80:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 24: prog 80 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 80:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   80:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00425: bf 56 00 00 00 00 00 00 r6 = r5
   80:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   80:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   80:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   80:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   80:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 25: prog 80 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   80:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   80:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   80:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   80:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   80:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   80:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   80:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   80:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   80:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   80:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 80:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   80:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   80:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   80:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 80:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 80:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   80:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   80:00425: bf 56 00 00 00 00 00 00 r6 = r5
   80:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   80:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   80:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   80:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   80:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   80:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   80:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 26: prog 90 `cil_to_netdev` PCs [223, 229, 231]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   90:00213: 04 02 00 00 08 00 00 00 w2 += 0x8
   90:00214: 6c 28 00 00 00 00 00 00 w8 <<= w2
   90:00215: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   90:00216: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00217: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   90:00218: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   90:00219: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   90:00220: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00221: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   90:00222: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 90:00223: 6c 45 00 00 00 00 00 00 w5 <<= w4
   90:00224: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   90:00225: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   90:00226: 5c 52 00 00 00 00 00 00 w2 &= w5
   90:00227: 5c 18 00 00 00 00 00 00 w8 &= w1
   90:00228: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 90:00229: 7c 38 00 00 00 00 00 00 w8 >>= w3
   90:00230: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 90:00231: 4c 18 00 00 00 00 00 00 w8 |= w1
   90:00232: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   90:00233: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00234: 05 00 20 00 00 00 00 00 goto +32 <pc 267>
   90:00235: 16 09 24 00 00 0e 00 00 if w9 == 0xe00 goto +36 <pc 272>
   90:00236: 16 09 01 00 00 0f 00 00 if w9 == 0xf00 goto +1 <pc 238>
   90:00237: 05 00 21 00 00 00 00 00 goto +33 <pc 271>
   90:00238: 61 61 08 00 00 00 00 00 r1 = *(w) (r6 +0x8)
   90:00239: 18 62 00 00 00 00 00 00 r2 = 0x800000000 ll
   90:00240: 00 00 00 00 08 00 00 00 <ldimm64 high half>
   90:00241: 61 28 00 00 00 00 00 00 r8 = *(w) (r2 +0x0)
```

### Captured Near-Match 27: prog 90 `cil_to_netdev` PCs [256, 262, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   90:00246: 04 02 00 00 08 00 00 00 w2 += 0x8
   90:00247: 6c 28 00 00 00 00 00 00 w8 <<= w2
   90:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   90:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   90:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   90:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   90:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   90:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 90:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   90:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   90:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   90:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   90:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   90:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 90:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   90:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 90:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   90:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   90:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
   90:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   90:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   90:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   90:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   90:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   90:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   90:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
```

### Captured Near-Match 28: prog 90 `cil_to_netdev` PCs [258, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w2 >>= 0x10`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   90:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   90:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   90:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   90:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   90:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   90:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   90:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   90:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
=> 90:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   90:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   90:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   90:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
   90:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   90:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 90:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   90:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   90:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 90:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   90:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   90:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   90:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   90:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   90:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   90:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   90:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   90:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   90:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   90:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 29: prog 90 `cil_to_netdev` PCs [262, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   90:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   90:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   90:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   90:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   90:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   90:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   90:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   90:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   90:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 90:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   90:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 90:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   90:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   90:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 90:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   90:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   90:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   90:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   90:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   90:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   90:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   90:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   90:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   90:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   90:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 30: prog 90 `cil_to_netdev` PCs [262, 268, 269]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   90:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   90:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   90:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   90:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   90:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   90:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   90:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   90:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   90:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 90:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   90:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
   90:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   90:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   90:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   90:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 90:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
=> 90:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   90:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   90:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   90:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   90:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   90:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   90:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   90:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   90:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   90:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   90:00279: 71 44 00 00 00 00 00 00 r4 = *(b) (r4 +0x0)
```

### Captured Near-Match 31: prog 94 `cil_to_netdev` PCs [223, 229, 231]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   94:00213: 04 02 00 00 08 00 00 00 w2 += 0x8
   94:00214: 6c 28 00 00 00 00 00 00 w8 <<= w2
   94:00215: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   94:00216: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00217: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   94:00218: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   94:00219: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   94:00220: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00221: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   94:00222: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 94:00223: 6c 45 00 00 00 00 00 00 w5 <<= w4
   94:00224: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   94:00225: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   94:00226: 5c 52 00 00 00 00 00 00 w2 &= w5
   94:00227: 5c 18 00 00 00 00 00 00 w8 &= w1
   94:00228: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 94:00229: 7c 38 00 00 00 00 00 00 w8 >>= w3
   94:00230: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 94:00231: 4c 18 00 00 00 00 00 00 w8 |= w1
   94:00232: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   94:00233: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00234: 05 00 20 00 00 00 00 00 goto +32 <pc 267>
   94:00235: 16 09 24 00 00 0e 00 00 if w9 == 0xe00 goto +36 <pc 272>
   94:00236: 16 09 01 00 00 0f 00 00 if w9 == 0xf00 goto +1 <pc 238>
   94:00237: 05 00 21 00 00 00 00 00 goto +33 <pc 271>
   94:00238: 61 61 08 00 00 00 00 00 r1 = *(w) (r6 +0x8)
   94:00239: 18 62 00 00 00 00 00 00 r2 = 0x800000000 ll
   94:00240: 00 00 00 00 08 00 00 00 <ldimm64 high half>
   94:00241: 61 28 00 00 00 00 00 00 r8 = *(w) (r2 +0x0)
```

### Captured Near-Match 32: prog 94 `cil_to_netdev` PCs [256, 262, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   94:00246: 04 02 00 00 08 00 00 00 w2 += 0x8
   94:00247: 6c 28 00 00 00 00 00 00 w8 <<= w2
   94:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   94:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   94:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   94:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   94:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   94:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 94:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   94:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   94:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   94:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   94:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   94:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 94:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   94:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 94:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   94:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   94:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
   94:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   94:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   94:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   94:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   94:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   94:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   94:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
```

### Captured Near-Match 33: prog 94 `cil_to_netdev` PCs [258, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w2 >>= 0x10`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   94:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   94:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   94:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   94:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   94:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   94:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   94:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   94:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
=> 94:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   94:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   94:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   94:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
   94:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   94:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 94:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   94:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   94:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 94:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   94:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   94:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   94:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   94:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   94:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   94:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   94:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   94:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   94:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   94:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 34: prog 94 `cil_to_netdev` PCs [262, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   94:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   94:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   94:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   94:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   94:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   94:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   94:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   94:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   94:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 94:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   94:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 94:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   94:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   94:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 94:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   94:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   94:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   94:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   94:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   94:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   94:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   94:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   94:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   94:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   94:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 35: prog 94 `cil_to_netdev` PCs [262, 268, 269]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   94:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   94:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   94:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   94:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   94:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   94:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   94:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   94:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   94:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 94:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   94:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
   94:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   94:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   94:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   94:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 94:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
=> 94:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   94:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   94:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   94:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   94:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   94:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   94:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   94:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   94:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   94:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   94:00279: 71 44 00 00 00 00 00 00 r4 = *(b) (r4 +0x0)
```

### Captured Near-Match 36: prog 98 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   98:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   98:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   98:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   98:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   98:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   98:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   98:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   98:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 98:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   98:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   98:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   98:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 98:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   98:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   98:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   98:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00317: bf 76 00 00 00 00 00 00 r6 = r7
   98:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   98:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   98:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 37: prog 98 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   98:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   98:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   98:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   98:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   98:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   98:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   98:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   98:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 98:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   98:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   98:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   98:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   98:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 98:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00317: bf 76 00 00 00 00 00 00 r6 = r7
   98:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   98:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   98:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   98:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   98:00322: bf a2 00 00 00 00 00 00 r2 = r10
   98:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   98:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 38: prog 98 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   98:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   98:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   98:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   98:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   98:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   98:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   98:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 98:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   98:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   98:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 98:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00317: bf 76 00 00 00 00 00 00 r6 = r7
   98:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   98:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   98:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   98:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   98:00322: bf a2 00 00 00 00 00 00 r2 = r10
   98:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   98:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 39: prog 98 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   98:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   98:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   98:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   98:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   98:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   98:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   98:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 98:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   98:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   98:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   98:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 98:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 98:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00317: bf 76 00 00 00 00 00 00 r6 = r7
   98:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   98:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   98:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   98:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   98:00322: bf a2 00 00 00 00 00 00 r2 = r10
   98:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   98:00324: bf a3 00 00 00 00 00 00 r3 = r10
   98:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 40: prog 98 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   98:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   98:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   98:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   98:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   98:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   98:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   98:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   98:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 98:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   98:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   98:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 41: prog 98 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   98:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   98:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   98:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   98:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   98:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   98:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   98:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   98:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00425: bf 56 00 00 00 00 00 00 r6 = r5
   98:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   98:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   98:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   98:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 42: prog 98 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   98:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   98:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   98:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   98:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00425: bf 56 00 00 00 00 00 00 r6 = r5
   98:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   98:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   98:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   98:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 43: prog 98 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   98:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   98:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   98:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   98:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 98:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00425: bf 56 00 00 00 00 00 00 r6 = r5
   98:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   98:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   98:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   98:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   98:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   98:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 44: prog 98 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 98:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   98:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00425: bf 56 00 00 00 00 00 00 r6 = r5
   98:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   98:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   98:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   98:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   98:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 45: prog 98 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   98:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   98:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   98:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   98:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   98:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   98:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   98:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   98:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   98:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   98:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 98:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   98:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   98:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   98:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 98:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 98:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   98:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   98:00425: bf 56 00 00 00 00 00 00 r6 = r5
   98:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   98:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   98:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   98:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   98:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   98:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   98:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 46: prog 99 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   99:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   99:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   99:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   99:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   99:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   99:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   99:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   99:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 99:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   99:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   99:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   99:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 99:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   99:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   99:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   99:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00317: bf 76 00 00 00 00 00 00 r6 = r7
   99:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   99:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   99:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 47: prog 99 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   99:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   99:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   99:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   99:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   99:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   99:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   99:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   99:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 99:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   99:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   99:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   99:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   99:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 99:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00317: bf 76 00 00 00 00 00 00 r6 = r7
   99:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   99:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   99:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   99:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   99:00322: bf a2 00 00 00 00 00 00 r2 = r10
   99:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   99:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 48: prog 99 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   99:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   99:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   99:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   99:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   99:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   99:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   99:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 99:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   99:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   99:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 99:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00317: bf 76 00 00 00 00 00 00 r6 = r7
   99:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   99:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   99:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   99:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   99:00322: bf a2 00 00 00 00 00 00 r2 = r10
   99:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   99:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 49: prog 99 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   99:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   99:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   99:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   99:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   99:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   99:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   99:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 99:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   99:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   99:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   99:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 99:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 99:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00317: bf 76 00 00 00 00 00 00 r6 = r7
   99:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   99:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   99:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   99:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   99:00322: bf a2 00 00 00 00 00 00 r2 = r10
   99:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   99:00324: bf a3 00 00 00 00 00 00 r3 = r10
   99:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 50: prog 99 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   99:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   99:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   99:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   99:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   99:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   99:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   99:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   99:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 99:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   99:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   99:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 51: prog 99 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   99:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   99:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   99:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   99:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   99:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   99:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   99:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   99:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00425: bf 56 00 00 00 00 00 00 r6 = r5
   99:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   99:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   99:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   99:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 52: prog 99 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   99:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   99:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   99:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   99:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00425: bf 56 00 00 00 00 00 00 r6 = r5
   99:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   99:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   99:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   99:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 53: prog 99 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   99:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   99:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   99:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   99:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 99:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00425: bf 56 00 00 00 00 00 00 r6 = r5
   99:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   99:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   99:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   99:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   99:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   99:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 54: prog 99 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 99:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   99:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00425: bf 56 00 00 00 00 00 00 r6 = r5
   99:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   99:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   99:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   99:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   99:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 55: prog 99 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   99:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   99:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   99:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   99:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   99:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   99:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   99:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   99:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   99:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   99:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 99:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   99:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   99:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   99:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 99:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 99:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   99:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   99:00425: bf 56 00 00 00 00 00 00 r6 = r5
   99:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   99:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   99:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   99:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   99:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   99:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   99:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 56: prog 107 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   107:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   107:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   107:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   107:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   107:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   107:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   107:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   107:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 107:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   107:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   107:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   107:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 107:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   107:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   107:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   107:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00317: bf 76 00 00 00 00 00 00 r6 = r7
   107:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   107:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   107:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 57: prog 107 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   107:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   107:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   107:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   107:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   107:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   107:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   107:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   107:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 107:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   107:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   107:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   107:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   107:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 107:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00317: bf 76 00 00 00 00 00 00 r6 = r7
   107:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   107:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   107:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   107:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   107:00322: bf a2 00 00 00 00 00 00 r2 = r10
   107:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   107:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 58: prog 107 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   107:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   107:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   107:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   107:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   107:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   107:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   107:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 107:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   107:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   107:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 107:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00317: bf 76 00 00 00 00 00 00 r6 = r7
   107:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   107:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   107:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   107:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   107:00322: bf a2 00 00 00 00 00 00 r2 = r10
   107:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   107:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 59: prog 107 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   107:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   107:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   107:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   107:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   107:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   107:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   107:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 107:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   107:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   107:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   107:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 107:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 107:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00317: bf 76 00 00 00 00 00 00 r6 = r7
   107:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   107:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   107:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   107:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   107:00322: bf a2 00 00 00 00 00 00 r2 = r10
   107:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   107:00324: bf a3 00 00 00 00 00 00 r3 = r10
   107:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 60: prog 107 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   107:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   107:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   107:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   107:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   107:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   107:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   107:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   107:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 107:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   107:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   107:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 61: prog 107 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   107:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   107:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   107:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   107:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   107:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   107:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   107:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   107:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00425: bf 56 00 00 00 00 00 00 r6 = r5
   107:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   107:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   107:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   107:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 62: prog 107 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   107:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   107:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   107:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   107:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00425: bf 56 00 00 00 00 00 00 r6 = r5
   107:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   107:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   107:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   107:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 63: prog 107 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   107:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   107:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   107:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   107:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 107:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00425: bf 56 00 00 00 00 00 00 r6 = r5
   107:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   107:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   107:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   107:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   107:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   107:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 64: prog 107 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 107:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   107:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00425: bf 56 00 00 00 00 00 00 r6 = r5
   107:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   107:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   107:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   107:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   107:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 65: prog 107 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   107:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   107:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   107:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   107:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   107:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   107:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   107:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   107:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   107:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   107:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 107:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   107:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   107:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   107:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 107:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 107:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   107:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   107:00425: bf 56 00 00 00 00 00 00 r6 = r5
   107:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   107:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   107:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   107:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   107:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   107:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   107:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 66: prog 114 `cil_to_netdev` PCs [223, 229, 231]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   114:00213: 04 02 00 00 08 00 00 00 w2 += 0x8
   114:00214: 6c 28 00 00 00 00 00 00 w8 <<= w2
   114:00215: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   114:00216: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00217: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   114:00218: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   114:00219: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   114:00220: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00221: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   114:00222: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 114:00223: 6c 45 00 00 00 00 00 00 w5 <<= w4
   114:00224: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   114:00225: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   114:00226: 5c 52 00 00 00 00 00 00 w2 &= w5
   114:00227: 5c 18 00 00 00 00 00 00 w8 &= w1
   114:00228: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 114:00229: 7c 38 00 00 00 00 00 00 w8 >>= w3
   114:00230: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 114:00231: 4c 18 00 00 00 00 00 00 w8 |= w1
   114:00232: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   114:00233: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00234: 05 00 20 00 00 00 00 00 goto +32 <pc 267>
   114:00235: 16 09 24 00 00 0e 00 00 if w9 == 0xe00 goto +36 <pc 272>
   114:00236: 16 09 01 00 00 0f 00 00 if w9 == 0xf00 goto +1 <pc 238>
   114:00237: 05 00 21 00 00 00 00 00 goto +33 <pc 271>
   114:00238: 61 61 08 00 00 00 00 00 r1 = *(w) (r6 +0x8)
   114:00239: 18 62 00 00 00 00 00 00 r2 = 0x800000000 ll
   114:00240: 00 00 00 00 08 00 00 00 <ldimm64 high half>
   114:00241: 61 28 00 00 00 00 00 00 r8 = *(w) (r2 +0x0)
```

### Captured Near-Match 67: prog 114 `cil_to_netdev` PCs [256, 262, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   114:00246: 04 02 00 00 08 00 00 00 w2 += 0x8
   114:00247: 6c 28 00 00 00 00 00 00 w8 <<= w2
   114:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   114:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   114:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   114:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   114:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   114:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 114:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   114:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   114:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   114:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   114:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   114:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 114:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   114:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 114:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   114:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   114:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
   114:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   114:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   114:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   114:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   114:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   114:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   114:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
```

### Captured Near-Match 68: prog 114 `cil_to_netdev` PCs [258, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w2 >>= 0x10`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   114:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   114:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   114:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   114:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   114:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   114:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   114:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   114:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
=> 114:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   114:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   114:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   114:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
   114:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   114:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 114:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   114:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   114:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 114:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   114:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   114:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   114:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   114:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   114:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   114:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   114:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   114:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   114:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   114:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 69: prog 114 `cil_to_netdev` PCs [262, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   114:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   114:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   114:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   114:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   114:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   114:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   114:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   114:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   114:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 114:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   114:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 114:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   114:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   114:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 114:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   114:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   114:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   114:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   114:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   114:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   114:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   114:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   114:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   114:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   114:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 70: prog 114 `cil_to_netdev` PCs [262, 268, 269]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   114:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   114:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   114:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   114:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   114:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   114:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   114:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   114:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   114:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 114:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   114:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
   114:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   114:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   114:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   114:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 114:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
=> 114:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   114:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   114:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   114:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   114:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   114:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   114:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   114:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   114:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   114:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   114:00279: 71 44 00 00 00 00 00 00 r4 = *(b) (r4 +0x0)
```

### Captured Near-Match 71: prog 118 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   118:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   118:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   118:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   118:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   118:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   118:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   118:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   118:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 118:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   118:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   118:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   118:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 118:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   118:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   118:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   118:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00317: bf 76 00 00 00 00 00 00 r6 = r7
   118:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   118:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   118:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 72: prog 118 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   118:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   118:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   118:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   118:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   118:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   118:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   118:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   118:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 118:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   118:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   118:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   118:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   118:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 118:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00317: bf 76 00 00 00 00 00 00 r6 = r7
   118:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   118:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   118:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   118:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   118:00322: bf a2 00 00 00 00 00 00 r2 = r10
   118:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   118:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 73: prog 118 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   118:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   118:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   118:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   118:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   118:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   118:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   118:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 118:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   118:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   118:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 118:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00317: bf 76 00 00 00 00 00 00 r6 = r7
   118:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   118:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   118:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   118:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   118:00322: bf a2 00 00 00 00 00 00 r2 = r10
   118:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   118:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 74: prog 118 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   118:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   118:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   118:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   118:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   118:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   118:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   118:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 118:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   118:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   118:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   118:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 118:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 118:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00317: bf 76 00 00 00 00 00 00 r6 = r7
   118:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   118:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   118:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   118:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   118:00322: bf a2 00 00 00 00 00 00 r2 = r10
   118:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   118:00324: bf a3 00 00 00 00 00 00 r3 = r10
   118:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 75: prog 118 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   118:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   118:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   118:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   118:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   118:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   118:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   118:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   118:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 118:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   118:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   118:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 76: prog 118 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   118:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   118:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   118:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   118:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   118:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   118:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   118:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   118:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00425: bf 56 00 00 00 00 00 00 r6 = r5
   118:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   118:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   118:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   118:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 77: prog 118 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   118:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   118:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   118:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   118:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00425: bf 56 00 00 00 00 00 00 r6 = r5
   118:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   118:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   118:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   118:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 78: prog 118 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   118:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   118:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   118:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   118:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 118:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00425: bf 56 00 00 00 00 00 00 r6 = r5
   118:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   118:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   118:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   118:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   118:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   118:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 79: prog 118 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 118:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   118:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00425: bf 56 00 00 00 00 00 00 r6 = r5
   118:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   118:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   118:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   118:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   118:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 80: prog 118 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   118:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   118:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   118:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   118:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   118:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   118:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   118:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   118:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   118:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   118:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 118:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   118:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   118:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   118:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 118:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 118:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   118:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   118:00425: bf 56 00 00 00 00 00 00 r6 = r5
   118:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   118:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   118:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   118:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   118:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   118:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   118:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 81: prog 119 `cil_to_netdev` PCs [223, 229, 231]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   119:00213: 04 02 00 00 08 00 00 00 w2 += 0x8
   119:00214: 6c 28 00 00 00 00 00 00 w8 <<= w2
   119:00215: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   119:00216: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00217: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   119:00218: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   119:00219: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   119:00220: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00221: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   119:00222: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 119:00223: 6c 45 00 00 00 00 00 00 w5 <<= w4
   119:00224: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   119:00225: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   119:00226: 5c 52 00 00 00 00 00 00 w2 &= w5
   119:00227: 5c 18 00 00 00 00 00 00 w8 &= w1
   119:00228: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 119:00229: 7c 38 00 00 00 00 00 00 w8 >>= w3
   119:00230: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 119:00231: 4c 18 00 00 00 00 00 00 w8 |= w1
   119:00232: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   119:00233: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00234: 05 00 20 00 00 00 00 00 goto +32 <pc 267>
   119:00235: 16 09 24 00 00 0e 00 00 if w9 == 0xe00 goto +36 <pc 272>
   119:00236: 16 09 01 00 00 0f 00 00 if w9 == 0xf00 goto +1 <pc 238>
   119:00237: 05 00 21 00 00 00 00 00 goto +33 <pc 271>
   119:00238: 61 61 08 00 00 00 00 00 r1 = *(w) (r6 +0x8)
   119:00239: 18 62 00 00 00 00 00 00 r2 = 0x800000000 ll
   119:00240: 00 00 00 00 08 00 00 00 <ldimm64 high half>
   119:00241: 61 28 00 00 00 00 00 00 r8 = *(w) (r2 +0x0)
```

### Captured Near-Match 82: prog 119 `cil_to_netdev` PCs [256, 262, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w5 <<= w4`; `ALU32:RSH/X` `w8 >>= w3`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   119:00246: 04 02 00 00 08 00 00 00 w2 += 0x8
   119:00247: 6c 28 00 00 00 00 00 00 w8 <<= w2
   119:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   119:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   119:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   119:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   119:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   119:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
=> 119:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   119:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   119:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   119:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   119:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   119:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 119:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   119:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 119:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   119:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   119:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
   119:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   119:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   119:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   119:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   119:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   119:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   119:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
```

### Captured Near-Match 83: prog 119 `cil_to_netdev` PCs [258, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w2 >>= 0x10`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   119:00248: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   119:00249: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00250: 61 23 00 00 00 00 00 00 r3 = *(w) (r2 +0x0)
   119:00251: 61 62 08 00 00 00 00 00 r2 = *(w) (r6 +0x8)
   119:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   119:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   119:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   119:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   119:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
=> 119:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   119:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   119:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   119:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
   119:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   119:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 119:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   119:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   119:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 119:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   119:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   119:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   119:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   119:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   119:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   119:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   119:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   119:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   119:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   119:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 84: prog 119 `cil_to_netdev` PCs [262, 268, 264]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   119:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   119:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   119:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   119:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   119:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   119:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   119:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   119:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   119:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 119:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   119:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
=> 119:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   119:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   119:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 119:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
   119:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   119:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   119:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   119:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   119:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   119:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   119:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   119:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   119:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   119:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
```

### Captured Near-Match 85: prog 119 `cil_to_netdev` PCs [262, 268, 269]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w8 >>= w3`; `ALU32:LSH/X` `w8 <<= w1`; `ALU32:OR/X` `w8 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   119:00252: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   119:00253: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00254: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   119:00255: b4 05 00 00 ff ff ff ff w5 = -0x1
   119:00256: 6c 45 00 00 00 00 00 00 w5 <<= w4
   119:00257: a4 05 00 00 ff ff ff ff w5 ^= -0x1
   119:00258: 74 02 00 00 10 00 00 00 w2 >>= 0x10
   119:00259: 5c 52 00 00 00 00 00 00 w2 &= w5
   119:00260: 5c 18 00 00 00 00 00 00 w8 &= w1
   119:00261: 04 03 00 00 08 00 00 00 w3 += 0x8
=> 119:00262: 7c 38 00 00 00 00 00 00 w8 >>= w3
   119:00263: 54 01 00 00 ff 00 00 00 w1 &= 0xff
   119:00264: 4c 18 00 00 00 00 00 00 w8 |= w1
   119:00265: 18 61 00 00 00 00 00 00 r1 = 0x0 ll
   119:00266: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   119:00267: 61 11 00 00 00 00 00 00 r1 = *(w) (r1 +0x0)
=> 119:00268: 6c 18 00 00 00 00 00 00 w8 <<= w1
=> 119:00269: 4c 28 00 00 00 00 00 00 w8 |= w2
   119:00270: 05 00 01 00 00 00 00 00 goto +1 <pc 272>
   119:00271: b4 08 00 00 00 00 00 00 w8 = 0x0
   119:00272: 18 61 00 00 00 00 00 00 r1 = 0x400000000 ll
   119:00273: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   119:00274: 71 13 00 00 00 00 00 00 r3 = *(b) (r1 +0x0)
   119:00275: 61 62 50 00 00 00 00 00 r2 = *(w) (r6 +0x50)
   119:00276: 61 61 4c 00 00 00 00 00 r1 = *(w) (r6 +0x4c)
   119:00277: 18 64 00 00 00 00 00 00 r4 = 0x400000000 ll
   119:00278: 00 00 00 00 04 00 00 00 <ldimm64 high half>
   119:00279: 71 44 00 00 00 00 00 00 r4 = *(b) (r4 +0x0)
```

### Captured Near-Match 86: prog 126 `cil_from_host` PCs [302, 308, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w0 <<= w5`; `ALU32:RSH/X` `w6 >>= w4`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   126:00292: 04 03 00 00 08 00 00 00 w3 += 0x8
   126:00293: 6c 36 00 00 00 00 00 00 w6 <<= w3
   126:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   126:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   126:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   126:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   126:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   126:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
=> 126:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   126:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   126:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   126:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 126:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   126:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   126:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
   126:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00317: bf 76 00 00 00 00 00 00 r6 = r7
   126:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   126:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   126:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
```

### Captured Near-Match 87: prog 126 `cil_from_host` PCs [304, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   126:00294: 18 63 00 00 00 00 00 00 r3 = 0x0 ll
   126:00295: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00296: 61 34 00 00 00 00 00 00 r4 = *(w) (r3 +0x0)
   126:00297: 61 73 08 00 00 00 00 00 r3 = *(w) (r7 +0x8)
   126:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   126:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   126:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   126:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   126:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
=> 126:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   126:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
   126:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   126:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   126:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 126:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00317: bf 76 00 00 00 00 00 00 r6 = r7
   126:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   126:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   126:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   126:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   126:00322: bf a2 00 00 00 00 00 00 r2 = r10
   126:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   126:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 88: prog 126 `cil_from_host` PCs [308, 314, 310]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   126:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   126:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   126:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   126:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   126:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   126:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   126:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 126:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   126:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   126:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 126:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00317: bf 76 00 00 00 00 00 00 r6 = r7
   126:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   126:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   126:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   126:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   126:00322: bf a2 00 00 00 00 00 00 r2 = r10
   126:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   126:00324: bf a3 00 00 00 00 00 00 r3 = r10
```

### Captured Near-Match 89: prog 126 `cil_from_host` PCs [308, 314, 315]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w4`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r7 into r6/r6', 'same destination register'].

```text
   126:00298: 18 65 00 00 00 00 00 00 r5 = 0x0 ll
   126:00299: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00300: 61 55 00 00 00 00 00 00 r5 = *(w) (r5 +0x0)
   126:00301: b4 00 00 00 ff ff ff ff w0 = -0x1
   126:00302: 6c 50 00 00 00 00 00 00 w0 <<= w5
   126:00303: a4 00 00 00 ff ff ff ff w0 ^= -0x1
   126:00304: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00305: 5c 03 00 00 00 00 00 00 w3 &= w0
   126:00306: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00307: 04 04 00 00 08 00 00 00 w4 += 0x8
=> 126:00308: 7c 46 00 00 00 00 00 00 w6 >>= w4
   126:00309: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   126:00310: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00311: 18 62 00 00 00 00 00 00 r2 = 0x0 ll
   126:00312: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00313: 61 22 00 00 00 00 00 00 r2 = *(w) (r2 +0x0)
=> 126:00314: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 126:00315: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00316: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00317: bf 76 00 00 00 00 00 00 r6 = r7
   126:00318: 05 00 6b 00 00 00 00 00 goto +107 <pc 426>
   126:00319: 7b 7a b0 ff 00 00 00 00 *(dw) (r10 -0x50) = r7
   126:00320: b7 01 00 00 01 00 00 00 r1 = 0x1
   126:00321: 7b 1a a8 ff 00 00 00 00 *(dw) (r10 -0x58) = r1
   126:00322: bf a2 00 00 00 00 00 00 r2 = r10
   126:00323: 07 02 00 00 e8 ff ff ff r2 += -0x18
   126:00324: bf a3 00 00 00 00 00 00 r3 = r10
   126:00325: 07 03 00 00 a8 ff ff ff r3 += -0x58
```

### Captured Near-Match 90: prog 126 `cil_from_host` PCs [409, 411, 405]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w8 <<= w4`; `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:OR/K` `w8 |= 0x1`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   126:00395: 61 53 08 00 00 00 00 00 r3 = *(w) (r5 +0x8)
   126:00396: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   126:00397: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00398: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   126:00399: 63 4a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r4
   126:00400: 18 64 00 00 00 00 00 00 r4 = 0x0 ll
   126:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   126:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   126:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
=> 126:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   126:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   126:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
=> 126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
```

### Captured Near-Match 91: prog 126 `cil_from_host` PCs [411, 415, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/K` `w3 >>= 0x10`; `ALU32:LSH/X` `w6 <<= w0`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: none.

```text
   126:00401: 00 00 00 00 00 00 00 00 <ldimm64 high half>
   126:00402: 61 44 00 00 00 00 00 00 r4 = *(w) (r4 +0x0)
   126:00403: 63 4a 98 ff 00 00 00 00 *(w) (r10 -0x68) = r4
   126:00404: 61 58 2c 00 00 00 00 00 r8 = *(w) (r5 +0x2c)
   126:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   126:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   126:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
=> 126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
   126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   126:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00425: bf 56 00 00 00 00 00 00 r6 = r5
   126:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   126:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   126:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   126:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 92: prog 126 `cil_from_host` PCs [415, 418, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   126:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   126:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   126:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   126:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00425: bf 56 00 00 00 00 00 00 r6 = r5
   126:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   126:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   126:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   126:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
```

### Captured Near-Match 93: prog 126 `cil_from_host` PCs [415, 418, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:LSH/X` `w6 <<= w0`; `ALU32:RSH/X` `w6 >>= w7`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['same destination register'].

```text
   126:00405: 44 08 00 00 01 00 00 00 w8 |= 0x1
   126:00406: 63 85 2c 00 00 00 00 00 *(w) (r5 +0x2c) = r8
   126:00407: b4 08 00 00 ff ff ff ff w8 = -0x1
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
=> 126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
   126:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 126:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00425: bf 56 00 00 00 00 00 00 r6 = r5
   126:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   126:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   126:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   126:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   126:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   126:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

### Captured Near-Match 94: prog 126 `cil_from_host` PCs [418, 422, 420]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w2`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
=> 126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 126:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
   126:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00425: bf 56 00 00 00 00 00 00 r6 = r5
   126:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   126:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   126:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   126:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   126:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
```

### Captured Near-Match 95: prog 126 `cil_from_host` PCs [418, 422, 423]

- Judgement: bitfield/variable-shift, not rotate matcher input.
- Shift/OR summary: `ALU32:RSH/X` `w6 >>= w7`; `ALU32:LSH/X` `w6 <<= w2`; `ALU32:OR/X` `w6 |= w3`.
- Width: 32; immediate pair `(RSH, LSH)`: None; complementary: False; OR combines both shifted regs: False; register relation notes: ['split-copy MOVs from r5 into r6/r6', 'same destination register'].

```text
   126:00408: 61 a4 a0 ff 00 00 00 00 r4 = *(w) (r10 -0x60)
   126:00409: 6c 48 00 00 00 00 00 00 w8 <<= w4
   126:00410: a4 08 00 00 ff ff ff ff w8 ^= -0x1
   126:00411: 74 03 00 00 10 00 00 00 w3 >>= 0x10
   126:00412: 5c 83 00 00 00 00 00 00 w3 &= w8
   126:00413: 54 06 00 00 00 ff ff ff w6 &= -0x100
   126:00414: 04 00 00 00 08 00 00 00 w0 += 0x8
   126:00415: 6c 06 00 00 00 00 00 00 w6 <<= w0
   126:00416: 5c 26 00 00 00 00 00 00 w6 &= w2
   126:00417: 04 07 00 00 08 00 00 00 w7 += 0x8
=> 126:00418: 7c 76 00 00 00 00 00 00 w6 >>= w7
   126:00419: 54 02 00 00 ff 00 00 00 w2 &= 0xff
   126:00420: 4c 26 00 00 00 00 00 00 w6 |= w2
   126:00421: 61 a2 98 ff 00 00 00 00 r2 = *(w) (r10 -0x68)
=> 126:00422: 6c 26 00 00 00 00 00 00 w6 <<= w2
=> 126:00423: 4c 36 00 00 00 00 00 00 w6 |= w3
   126:00424: 63 6a a0 ff 00 00 00 00 *(w) (r10 -0x60) = r6
   126:00425: bf 56 00 00 00 00 00 00 r6 = r5
   126:00426: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00427: 63 26 08 00 00 00 00 00 *(w) (r6 +0x8) = r2
   126:00428: b4 07 00 00 01 00 00 00 w7 = 0x1
   126:00429: b4 02 00 00 01 00 00 00 w2 = 0x1
   126:00430: 16 01 01 00 00 0a 00 00 if w1 == 0xa00 goto +1 <pc 432>
   126:00431: b4 02 00 00 00 00 00 00 w2 = 0x0
   126:00432: 16 01 01 00 00 0b 00 00 if w1 == 0xb00 goto +1 <pc 434>
   126:00433: b4 07 00 00 00 00 00 00 w7 = 0x0
```

## Section 3: Offline `corpus/build/cilium/bpf_xdp.bpf.o` Scan

Executable ELF sections scanned with the same raw decoder and matcher mirror:

| section | insns | LSH | RSH | OR | BPF_END | exact_rotate_sites | loose_triples |
| --- | --- | --- | --- | --- | --- | --- | --- |
| .text | 3947 | 254 | 74 | 236 | 34 | 0 | 6 |
| xdp/tail | 25825 | 608 | 760 | 662 | 93 | 111 | 585 |
| xdp/entry | 626 | 15 | 0 | 14 | 3 | 0 | 0 |

`bpfopt --pass rotate` confirmation on `xdp/tail`:

```json
{
  "pass": "rotate",
  "sites_applied": 111,
  "sites_matched": 111,
  "sites_skipped": 0,
  "skip_reasons": {},
  "diagnostics": [],
  "insn_count_before": 25825,
  "insn_count_after": 25492,
  "insn_delta": -333
}
```

Exact offline site shape summary:

| shape | width | count |
| --- | --- | --- |
| split-copy | 32 | 111 |

Offline constant pairs `(S_rsh, S_lsh)` among the 111 exact sites:

| S_rsh | S_lsh | count |
| --- | --- | --- |
| 28 | 4 | 24 |
| 26 | 6 | 10 |
| 24 | 8 | 10 |
| 21 | 11 | 7 |
| 18 | 14 | 13 |
| 16 | 16 | 19 |
| 13 | 19 | 10 |
| 8 | 24 | 9 |
| 7 | 25 | 9 |

All 111 exact sites are 32-bit split-copy rotates. The shape is:

```text
MOV tmp0, val
RSH tmp0, 32-k
MOV tmp1, val
LSH tmp1, k
OR  tmp1, tmp0
```

Representative examples, one for each observed constant pair:

### Offline Pair (28, 4): section `xdp/tail`, pc 2462

```text
   xdp/tail:02459: bf 02 00 00 00 00 00 00 r2 = r0
   xdp/tail:02460: 07 02 00 00 32 00 00 00 r2 += 0x32
   xdp/tail:02461: 2d 12 68 ff 00 00 00 00 if r2 > r1 goto -152 <pc 2310>
=> xdp/tail:02462: bc 61 00 00 00 00 00 00 w1 = w6
=> xdp/tail:02463: 74 01 00 00 1c 00 00 00 w1 >>= 0x1c
=> xdp/tail:02464: bc 62 00 00 00 00 00 00 w2 = w6
=> xdp/tail:02465: 64 02 00 00 04 00 00 00 w2 <<= 0x4
=> xdp/tail:02466: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02467: 61 a5 f0 fe 00 00 00 00 r5 = *(w) (r10 -0x110)
   xdp/tail:02468: 1c 65 00 00 00 00 00 00 w5 -= w6
   xdp/tail:02469: ac 25 00 00 00 00 00 00 w5 ^= w2
```

### Offline Pair (26, 6): section `xdp/tail`, pc 2470

```text
   xdp/tail:02467: 61 a5 f0 fe 00 00 00 00 r5 = *(w) (r10 -0x110)
   xdp/tail:02468: 1c 65 00 00 00 00 00 00 w5 -= w6
   xdp/tail:02469: ac 25 00 00 00 00 00 00 w5 ^= w2
=> xdp/tail:02470: bc 51 00 00 00 00 00 00 w1 = w5
=> xdp/tail:02471: 74 01 00 00 1a 00 00 00 w1 >>= 0x1a
=> xdp/tail:02472: bc 52 00 00 00 00 00 00 w2 = w5
=> xdp/tail:02473: 64 02 00 00 06 00 00 00 w2 <<= 0x6
=> xdp/tail:02474: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02475: 61 a4 28 ff 00 00 00 00 r4 = *(w) (r10 -0xd8)
   xdp/tail:02476: 0c 46 00 00 00 00 00 00 w6 += w4
   xdp/tail:02477: 1c 54 00 00 00 00 00 00 w4 -= w5
```

### Offline Pair (24, 8): section `xdp/tail`, pc 2479

```text
   xdp/tail:02476: 0c 46 00 00 00 00 00 00 w6 += w4
   xdp/tail:02477: 1c 54 00 00 00 00 00 00 w4 -= w5
   xdp/tail:02478: ac 24 00 00 00 00 00 00 w4 ^= w2
=> xdp/tail:02479: bc 41 00 00 00 00 00 00 w1 = w4
=> xdp/tail:02480: 74 01 00 00 18 00 00 00 w1 >>= 0x18
=> xdp/tail:02481: bc 42 00 00 00 00 00 00 w2 = w4
=> xdp/tail:02482: 64 02 00 00 08 00 00 00 w2 <<= 0x8
=> xdp/tail:02483: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02484: 0c 65 00 00 00 00 00 00 w5 += w6
   xdp/tail:02485: 1c 46 00 00 00 00 00 00 w6 -= w4
   xdp/tail:02486: ac 26 00 00 00 00 00 00 w6 ^= w2
```

### Offline Pair (21, 11): section `xdp/tail`, pc 2579

```text
   xdp/tail:02576: 1c 46 00 00 00 00 00 00 w6 -= w4
   xdp/tail:02577: 61 a2 30 ff 00 00 00 00 r2 = *(w) (r10 -0xd0)
   xdp/tail:02578: 0c 21 00 00 00 00 00 00 w1 += w2
=> xdp/tail:02579: bc 62 00 00 00 00 00 00 w2 = w6
=> xdp/tail:02580: 74 02 00 00 15 00 00 00 w2 >>= 0x15
=> xdp/tail:02581: bc 63 00 00 00 00 00 00 w3 = w6
=> xdp/tail:02582: 64 03 00 00 0b 00 00 00 w3 <<= 0xb
=> xdp/tail:02583: 4c 23 00 00 00 00 00 00 w3 |= w2
   xdp/tail:02584: bc 62 00 00 00 00 00 00 w2 = w6
   xdp/tail:02585: ac 12 00 00 00 00 00 00 w2 ^= w1
   xdp/tail:02586: 1c 32 00 00 00 00 00 00 w2 -= w3
```

### Offline Pair (18, 14): section `xdp/tail`, pc 2611

```text
   xdp/tail:02608: bc 34 00 00 00 00 00 00 w4 = w3
   xdp/tail:02609: ac 24 00 00 00 00 00 00 w4 ^= w2
   xdp/tail:02610: 1c 54 00 00 00 00 00 00 w4 -= w5
=> xdp/tail:02611: bc 42 00 00 00 00 00 00 w2 = w4
=> xdp/tail:02612: 74 02 00 00 12 00 00 00 w2 >>= 0x12
=> xdp/tail:02613: bc 45 00 00 00 00 00 00 w5 = w4
=> xdp/tail:02614: 64 05 00 00 0e 00 00 00 w5 <<= 0xe
=> xdp/tail:02615: 4c 25 00 00 00 00 00 00 w5 |= w2
   xdp/tail:02616: ac 14 00 00 00 00 00 00 w4 ^= w1
   xdp/tail:02617: 1c 54 00 00 00 00 00 00 w4 -= w5
   xdp/tail:02618: bc 41 00 00 00 00 00 00 w1 = w4
```

### Offline Pair (16, 16): section `xdp/tail`, pc 2487

```text
   xdp/tail:02484: 0c 65 00 00 00 00 00 00 w5 += w6
   xdp/tail:02485: 1c 46 00 00 00 00 00 00 w6 -= w4
   xdp/tail:02486: ac 26 00 00 00 00 00 00 w6 ^= w2
=> xdp/tail:02487: bc 61 00 00 00 00 00 00 w1 = w6
=> xdp/tail:02488: 74 01 00 00 10 00 00 00 w1 >>= 0x10
=> xdp/tail:02489: bc 62 00 00 00 00 00 00 w2 = w6
=> xdp/tail:02490: 64 02 00 00 10 00 00 00 w2 <<= 0x10
=> xdp/tail:02491: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02492: 0c 54 00 00 00 00 00 00 w4 += w5
   xdp/tail:02493: 1c 65 00 00 00 00 00 00 w5 -= w6
   xdp/tail:02494: ac 25 00 00 00 00 00 00 w5 ^= w2
```

### Offline Pair (13, 19): section `xdp/tail`, pc 2495

```text
   xdp/tail:02492: 0c 54 00 00 00 00 00 00 w4 += w5
   xdp/tail:02493: 1c 65 00 00 00 00 00 00 w5 -= w6
   xdp/tail:02494: ac 25 00 00 00 00 00 00 w5 ^= w2
=> xdp/tail:02495: bc 51 00 00 00 00 00 00 w1 = w5
=> xdp/tail:02496: 74 01 00 00 0d 00 00 00 w1 >>= 0xd
=> xdp/tail:02497: bc 52 00 00 00 00 00 00 w2 = w5
=> xdp/tail:02498: 64 02 00 00 13 00 00 00 w2 <<= 0x13
=> xdp/tail:02499: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02500: 0c 46 00 00 00 00 00 00 w6 += w4
   xdp/tail:02501: 1c 54 00 00 00 00 00 00 w4 -= w5
   xdp/tail:02502: ac 24 00 00 00 00 00 00 w4 ^= w2
```

### Offline Pair (8, 24): section `xdp/tail`, pc 2618

```text
   xdp/tail:02615: 4c 25 00 00 00 00 00 00 w5 |= w2
   xdp/tail:02616: ac 14 00 00 00 00 00 00 w4 ^= w1
   xdp/tail:02617: 1c 54 00 00 00 00 00 00 w4 -= w5
=> xdp/tail:02618: bc 41 00 00 00 00 00 00 w1 = w4
=> xdp/tail:02619: 74 01 00 00 08 00 00 00 w1 >>= 0x8
=> xdp/tail:02620: bc 42 00 00 00 00 00 00 w2 = w4
=> xdp/tail:02621: 64 02 00 00 18 00 00 00 w2 <<= 0x18
=> xdp/tail:02622: 4c 12 00 00 00 00 00 00 w2 |= w1
   xdp/tail:02623: ac 34 00 00 00 00 00 00 w4 ^= w3
   xdp/tail:02624: 1c 24 00 00 00 00 00 00 w4 -= w2
   xdp/tail:02625: bc 41 00 00 00 00 00 00 w1 = w4
```

### Offline Pair (7, 25): section `xdp/tail`, pc 2587

```text
   xdp/tail:02584: bc 62 00 00 00 00 00 00 w2 = w6
   xdp/tail:02585: ac 12 00 00 00 00 00 00 w2 ^= w1
   xdp/tail:02586: 1c 32 00 00 00 00 00 00 w2 -= w3
=> xdp/tail:02587: bc 21 00 00 00 00 00 00 w1 = w2
=> xdp/tail:02588: 74 01 00 00 07 00 00 00 w1 >>= 0x7
=> xdp/tail:02589: bc 23 00 00 00 00 00 00 w3 = w2
=> xdp/tail:02590: 64 03 00 00 19 00 00 00 w3 <<= 0x19
=> xdp/tail:02591: 4c 13 00 00 00 00 00 00 w3 |= w1
   xdp/tail:02592: bc 21 00 00 00 00 00 00 w1 = w2
   xdp/tail:02593: ac 51 00 00 00 00 00 00 w1 ^= w5
   xdp/tail:02594: 1c 31 00 00 00 00 00 00 w1 -= w3
```

Source context: Cilium `runner/repos/cilium/bpf/lib/jhash.h` defines `rol32(word, shift)` as `(word << shift) | (word >> ((-shift) & 31))`, and the Jenkins mix/final macros call `rol32` with shifts 4, 6, 8, 16, 19, 14, 11, 25, and 24. Those are exactly the offline `S_lsh` values above.

## Section 4: Structural Comparison

Captured production bytecode and offline `bpf_xdp.bpf.o` differ structurally in program coverage and instruction shape:

- Captured set: only `sched_cls` Cilium programs plus two tracing dump programs. Unique captured program names are `cil_from_host`, `cil_from_netdev`, `cil_to_host`, `cil_to_netdev`, `cil_host_policy`, `tail_drop_notify`, `tail_handle_ipv4_from_host`, `tail_handle_ipv4_from_netdev`, `dump_bpf_map`, and `dump_bpf_prog`. No captured program is an XDP program and no captured body corresponds to offline section `xdp/tail`, where all 111 rotate sites live.
- Captured shift activity is dominated by byte assembly, masks, and variable bitfield insertion/extraction. The loose neighborhoods use register shift counts such as `w6 >>= w4`, `w6 <<= w2`, or `w8 >>= w3`, often bracketed by masks and map/config loads. This is not the Jenkins immediate rotate lowering.
- Offline `xdp/tail`: all exact rotate sites are immediate 32-bit split-copy sequences with two MOV copies from one source, complementary constants summing to 32, and an OR combining the two shifted copies.
- The captured programs do contain `BPF_END` (`69` total), but endian operations remain single BPF_END instructions and do not create rotate-like shift/or windows.

I did not find evidence that the kernel verifier rewrote Jenkins rotates into a noncanonical rotate form that defeats the 3-5 instruction matcher. If such a rewrite had merely inserted MOVs or reordered within a small window, the scan should still have found immediate LSH/RSH pairs with constants summing to 32 or at least non-complementary immediate pairs. Captured bytecode has zero immediate opposite-direction LSH/RSH pairs within 10 instructions.

## Section 5: Verdict on Previous `0 Candidates` Claim

The previous `0 rotate candidates in captured production bytecode` claim is correct for rotate candidates. It was incomplete only if read as “there are no shifts”: the 56 captures contain substantial shift and OR activity (`441` LSH, `79` RSH, `422` OR), but none is rotate-shaped.

Specific answers:

1. Yes, there are LSH/RSH instructions across the 56 captured programs.
2. Yes, the loose scan found 95 shift/OR neighborhoods, all in `cil_from_host` or `cil_to_netdev` clones; all are variable-shift bitfield/packing code, not rotate.
3. No evidence that the complementary-constant check is too strict: there are zero immediate opposite-direction LSH/RSH pairs within 10 instructions in captured bytecode, so no complementary constants were available for the matcher to misparse.
4. No evidence that the verifier produced a noncanonical rotate form in captured bytecode. The structural difference is that the captured live program set lacks the offline XDP tail body that contains Jenkins rotates.
5. The strict matcher did not miss a loose pattern that should be added based on this dataset.

## Section 6: Matcher Broadening Recommendation

Do not broaden the rotate matcher based on this captured production scan.

No specific new safe rotate pattern appears in the 56 captured programs. The only loose neighborhoods are variable-shift bitfield operations with masks and configuration-derived shift counts; mapping those to the current immediate `bpf_rotate32`/`bpf_rotate64` kfunc encoding would be semantically wrong. The existing split-copy matcher already catches all 111 offline Cilium Jenkins sites.

If future data shows real delayed-copy rotates, the safe broadening would need to be a dataflow-proven variant of the existing split-copy pattern, not a blind 10-instruction window: prove two shifted registers are copies of the same source, prove neither source is modified between copy and shift, require immediate complementary constants, require OR to combine exactly those two shifted values, and preserve all intervening side effects. This scan does not provide such a case.
