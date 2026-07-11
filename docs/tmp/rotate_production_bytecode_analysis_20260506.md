# Rotate Production Bytecode Analysis - 2026-05-06

## Section 1: Reproducibility on Captured Bytecode

Captured artifact root:

```text
corpus/results/x86_kvm_corpus_20260506_205924_738444/details/failure-artifacts
```

The directory contains 56 Cilium program tarballs. I extracted representative programs to `/tmp/rotate-cilium-prod/` and reran the same pass command shape against the captured `input_step0.bin` and per-program `target.json`.

Commands:

```text
bpfopt/target/release/bpfopt --pass rotate --input /tmp/rotate-cilium-prod/95/input_step0.bin --output /tmp/rotate-cilium-prod/95/rerun_output.bin --report /tmp/rotate-cilium-prod/95/rerun_report.json --prog-type sched_cls --target /tmp/rotate-cilium-prod/95/target.json
bpfopt/target/release/bpfopt --pass rotate --input /tmp/rotate-cilium-prod/99/input_step0.bin --output /tmp/rotate-cilium-prod/99/rerun_output.bin --report /tmp/rotate-cilium-prod/99/rerun_report.json --prog-type sched_cls --target /tmp/rotate-cilium-prod/99/target.json
bpfopt/target/release/bpfopt --pass rotate --input /tmp/rotate-cilium-prod/10/input_step0.bin --output /tmp/rotate-cilium-prod/10/rerun_output.bin --report /tmp/rotate-cilium-prod/10/rerun_report.json --prog-type sched_cls --target /tmp/rotate-cilium-prod/10/target.json
```

Results:

```json
{"prog_id":95,"prog_name":"cil_from_netdev","prog_type":3,"insn_count_before":1110,"sites_matched":0,"sites_skipped":0,"sites_applied":0}
{"prog_id":99,"prog_name":"cil_from_host","prog_type":3,"insn_count_before":1194,"sites_matched":0,"sites_skipped":0,"sites_applied":0}
{"prog_id":10,"prog_name":"dump_bpf_map","prog_type":26,"insn_count_before":35,"sites_matched":0,"sites_skipped":0,"sites_applied":0}
```

`cmp` confirmed rerun outputs for these three programs are byte-for-byte identical to their captured inputs.

The captured target contains both rotate koperation, so this is not a target probing problem:

```json
{
  "arch": "x86_64",
  "features": ["cmov", "bmi1", "bmi2", "rorx", "movbe"],
  "koperation": {
    "bpf_rotate32": {"btf_func_id": 128702, "btf_id": 6, "call_offset": 5},
    "bpf_rotate64": {"btf_func_id": 128703, "btf_id": 6, "call_offset": 5}
  }
}
```

Independent scan of all 56 captured `input_step0.bin` streams:

```text
programs: 56
total insns: 22476
exact rotate matcher candidates: 0
loose complementary immediate shift+or candidates within 8-insn windows: 0
BPF_END byte-swap instructions: 69
BPF_STX atomic instructions: 13
```

## Section 2: Rotate Matcher Pattern Expectation

Implementation inspected from `HEAD:bpfopt/crates/bpfopt/src/passes/rotate.rs`.

The scanner walks instruction windows and calls `try_match_rotate()`:

- `rotate.rs:226-246`: scans linearly and advances past a matched site.
- `rotate.rs:278-288`: tries the split-copy matcher first, then adjacent W64/W32 matchers.

The Cilium split-copy matcher expects this exact five-instruction form:

```text
MOV tmp0, val
RSH/LSH tmp0, A
MOV tmp1, val
LSH/RSH tmp1, B
OR one_shifted_reg, other_shifted_reg
```

Matcher checks:

- `rotate.rs:301-318`: both copy instructions must be register MOVs of the selected width.
- `rotate.rs:320-323`: both copies must read the same source register.
- `rotate.rs:325-329`: the two shifted registers must be distinct and shifted immediately after their copy.
- `rotate.rs:331-347`: one shift must be LSH, one RSH, and immediates must sum to 32 or 64.
- `rotate.rs:349-358`: OR must combine exactly those two shifted registers.
- `rotate.rs:360` and `rotate.rs:484-503`: encoded scratch must not alias the result or source register.

The older adjacent matcher expects:

```text
MOV tmp, orig
RSH/LSH regA, A
LSH/RSH regB, B
OR one_shifted_reg, other_shifted_reg
```

with the provenance MOV immediately before the shift pair:

- `rotate.rs:248-270`: provenance MOV must be at `shift_pc - 1`.
- `rotate.rs:363-482`: adjacent shift-pair matcher for W64 and W32.

The in-file tests document the canonical shapes:

- `rotate.rs:548-563`: W64 adjacent pattern A.
- `rotate.rs:567-578`: W64 adjacent pattern B.
- `rotate.rs:581-610`: W32 adjacent patterns.
- `rotate.rs:613-633`: Cilium split-copy shape from offline `bpf_xdp.bpf.o`.
- `rotate.rs:649-658` and `rotate.rs:948-961`: intervening instructions intentionally do not match.

There is no separate `bpfopt/crates/bpfopt/src/passes/rotate_tests.rs` file at this HEAD; the rotate tests are embedded in `rotate.rs`.

## Section 3: Captured Cilium Disassembly Shape

The captured production programs do contain shifts and ORs, but not rotate idioms. They are byte assembly, bitfield insertion/extraction, masks, endian conversions, and atomics. No captured program has the Jenkins `rol32` split-copy sequence.

### Prog 95: `cil_from_netdev`, packet byte assembly

```text
0031: r2 = *(u8 *)(r1 +12)
0032: r1 = *(u8 *)(r1 +13)
0033: w1 <<= 8
0034: w1 |= w2
0035: if w1 < 6 goto ...
0037: w1 &= 65535
```

This is a 16-bit big-endian value assembled from two byte loads. It has one LSH and one OR, no RSH, and no copy provenance.

### Prog 95: `cil_from_netdev`, byte swaps are BPF_END

```text
1015: r4 = *(u16 *)(r10 -88)
1016: w4 = be16 w4
...
1026: r1 = *(u32 *)(r10 -88)
1027: w1 = be32 w1
...
1039: r4 = *(u64 *)(r10 -88)
1040: w4 = be64 w4
1041: w0 s>>= 31
```

The production endian shape is a single `BPF_END` instruction, not a shift/or rotate. A rotate matcher should not catch this; the separate endian pass is the relevant family.

### Prog 99: `cil_from_host`, bitfield merge with variable shifts

```text
0304: w3 >>= 16
0305: w3 &= w0
0306: w6 &= w2
0307: w4 += 8
0308: w6 >>= w4
0309: w2 &= 255
0310: w6 |= w2
0313: r2 = *(u32 *)(r2 +0)
0314: w6 <<= w2
0315: w6 |= w3
```

This region is close only in the broad sense that it has shifts and ORs. It uses variable shift counts and masks. It is not an immediate `LSH/RSH` pair whose shift amounts sum to 32 or 64.

### Prog 120: `cil_to_host`, packet byte assembly and sign/mask construction

```text
0025: r2 = *(u8 *)(r1 +12)
0026: r1 = *(u8 *)(r1 +13)
0027: w1 <<= 8
0028: w1 |= w2
0029: if w1 < 6 goto ...
```

```text
0297: *(u16 *)(r10 -84) = r3
0298: r3 <<= 32
0299: r1 = 0xffffffff ll
0301: r3 |= r1
0302: r4 = r10
```

Again, these are byte assembly or mask/sign construction, not rotate.

### Offline contrast: `bpf_xdp.bpf.o:xdp/tail`

Dumping the offline section and running the current rotate pass reproduces the earlier 111-site number:

```text
llvm-objcopy --dump-section xdp/tail=/tmp/rotate-cilium-prod/offline_xdp_tail.bin corpus/build/cilium/bpf_xdp.bpf.o
bpfopt/target/release/bpfopt --pass rotate --input /tmp/rotate-cilium-prod/offline_xdp_tail.bin --output /tmp/rotate-cilium-prod/offline_xdp_tail_rotate.bin --report /tmp/rotate-cilium-prod/offline_xdp_tail_report.json --prog-type xdp --target /tmp/rotate-cilium-prod/95/target.json
```

Report:

```json
{"insn_count_before":25825,"insn_count_after":25492,"sites_matched":111,"sites_skipped":0,"sites_applied":111}
```

A representative offline XDP tail site:

```text
2462: w1 = w6
2463: w1 >>= 0x1c
2464: w2 = w6
2465: w2 <<= 0x4
2466: w2 |= w1
```

This is exactly the split-copy shape tested in `rotate.rs:613-633`. It comes from Cilium's Jenkins hash helper:

- `runner/repos/cilium/bpf/lib/jhash.h:13-16`: `rol32(word, shift) = (word << shift) | (word >> ((-shift) & 31))`.
- `runner/repos/cilium/bpf/lib/jhash.h:18-36`: Jenkins mix/final macros repeatedly call `rol32`.

The captured live program list for this run is different. It contains TC/tracing programs such as:

```text
95  cil_from_netdev  prog_type=3  insns=1110
99  cil_from_host    prog_type=3  insns=1194
120 cil_to_host      prog_type=3  insns=351
10  dump_bpf_map     prog_type=26 insns=35
```

Across all 56 captures, the names are `cil_from_netdev`, `cil_from_host`, `cil_to_host`, `cil_to_netdev`, `tail_handle_ipv`, `tail_drop_notif`, `cil_host_policy`, and two tracing dump programs. The captured set does not include an XDP tail body with the offline Jenkins hash rotate sequence.

## Section 4: Kernel Verifier Rewrites Relevant to Shape

The verifier has several rewrites that explain why production xlated bytecode differs from raw object sections in general, but I did not find evidence that it rewrites a Jenkins rotate into a different rotate-like form in these captures.

Relevant verifier mechanisms:

- `vendor/linux-framework/kernel/bpf/verifier.c:16214-16254`: `scalar_byte_swap()` handles `BPF_END` as a byte-swap operation for verifier scalar state. It treats `be16`, `be32`, and `be64` as byte-swap/truncation semantics.
- `vendor/linux-framework/kernel/bpf/verifier.c:16472-16474`: `BPF_END` is handled as its own ALU operation.
- `vendor/linux-framework/kernel/bpf/verifier.c:16480-16489`: ALU32 zero-extension is skipped for `BPF_END` because the byte-swap helper already handles truncation. This preserves the single-instruction endian shape seen in captured programs.
- `vendor/linux-framework/kernel/bpf/verifier.c:23088-23109`: `convert_ctx_accesses()` can insert `RSH` plus `AND` for narrower context loads. This can create shift-looking xlated code, but it is extraction, not rotate, and it has no complementary `LSH/RSH/OR` form.
- `vendor/linux-framework/kernel/bpf/verifier.c:23814-23816`: `do_misc_fixups()` can convert ALU64 operations to ALU32 when `needs_zext` is set.
- `vendor/linux-framework/kernel/bpf/verifier.c:23939-23958`: probe-memory loads can be patched with guard code including an `RSH`, but again not a rotate OR pair.
- `vendor/linux-framework/kernel/bpf/verifier.c:24409-24427`: `bpf_get_smp_processor_id()` can be inlined to a percpu load on x86_64. This is unrelated to the missing rotate sites.
- `vendor/linux-framework/kernel/bpf/verifier.c:22946-22951`: some arena atomics can be rewritten to probe atomics. The captured streams have 13 atomic instructions, but they are not rotate candidates.

The rotate kop implementation itself expects the same proof shape the matcher emits:

- `module/x86/bpf_rotate.c:56-77`: `bpf_rotate64` proof expansion is MOV, optional MOV, LSH, RSH, OR.
- `module/x86/bpf_rotate.c:80-100`: `bpf_rotate32` proof expansion is MOV32, optional MOV32, LSH, RSH, OR.
- `module/x86/bpf_rotate.c:140-169`: native x86 emission becomes a MOV plus `ROL` immediate.

So the kernel side has no alternate xlated rotate form that the current matcher should have recognized here. The production captures simply do not contain the offline Jenkins rotate body.

## Section 5: Verdict

The rotate matcher returns zero on captured production bytecode because there are no rotate candidates in the captured production bytecode.

This is not a missed variant of the existing Cilium split-copy rotate shape. The exact split-copy shape is present in the offline `bpf_xdp.bpf.o:xdp/tail` section and the current matcher finds 111 sites there. The daemon-fed captured programs from this run are smaller live TC/tracing programs whose shift/or regions are packet byte assembly, bitfield/mask operations, endian `BPF_END`, and atomics. An independent scan found zero exact matcher candidates and zero loose complementary immediate `LSH/RSH/OR` candidates across all 56 captured programs.

The earlier "111 on Cilium .bpf.o" number is real for the offline XDP tail section, but it is not evidence that the captured `cil_from_*` production xlated bytecode should contain 111 rotate sites. It was a different bytecode body and likely a different loaded-program set/configuration than this daemon capture.

Confidence: high.

Basis:

- Reproduced `sites_matched=0` with `bpfopt --pass rotate` on captured progs 95, 99, and 10.
- Decoded all 56 captured raw streams and found no complementary immediate rotate clusters.
- Reproduced `sites_matched=111` on offline `bpf_xdp.bpf.o:xdp/tail`.
- Verified the offline 111-site shape is the exact split-copy shape now implemented and tested by the matcher.
- Verifier source review found rewrites that can insert extraction shifts, preserve `BPF_END`, inline helpers, and rewrite atomics, but no rewrite that would hide an existing Jenkins rotate as a different rotate-like production form in these artifacts.

## Section 6: Fix Dimensions

For this captured production set, expanding the rotate matcher will not help. There is no additional production rotate shape to recognize in the 56 captured programs.

Practical next steps:

1. If the goal is to evaluate rotate on Cilium production code, drive/load the Cilium XDP tail body or whichever live Cilium configuration actually contains `jhash`/`rol32` code. The current captured set is TC/tracing and does not include the offline XDP rotate body.
2. Keep the current split-copy matcher. It correctly catches the offline Jenkins shape:

```text
MOV tmp0, val; RSH tmp0, 32-k; MOV tmp1, val; LSH tmp1, k; OR tmp1, tmp0
```

3. Do not make rotate match byte assembly, `BPF_END`, variable-shift bitfield operations, or mask construction. Those are different semantics.
4. If future production captures show true rotates after verifier rewrites but in a noncanonical form, the right fix is a semantic rotate matcher over a bounded dataflow slice: prove both OR operands derive from the same value, one through LSH(k), one through RSH(width-k), with no intervening side effects or clobbers. That is not needed for the current captured bytecode.
5. If the observed production opportunity is really byte swapping, use or improve the endian pass, not rotate.

