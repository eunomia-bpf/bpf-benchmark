# wide_mem tetragon ReJIT failure investigation, 2026-05-13

Read-only investigation. I did not run benchmarks. The only executed transforms were host-side
`bpfopt --pass wide_mem` over existing `bpfopt/testbin/tetragon_observer/*/canonicalize_output.bin`
inputs with outputs/reports in `/tmp`.

## 1. Specific wide_mem rewrite

### Implemented patterns in `wide_mem.rs`

`bpfopt/crates/bpfopt/src/passes/wide_mem.rs` implements only byte-load ladders that start at an
`LDX_MEM B` instruction:

- Width search order: `8, 4, 2` via `WIDE_MEM_WIDTHS` at lines 7-8.
- Low-first pattern at lines 27-31 and 60-81:

```text
rD = *(u8 *)(rB + off + 0)
rT = *(u8 *)(rB + off + i)
rT <<= 8*i
rD |= rT
...
=> rD = *(u{16,32,64} *)(rB + off)
```

- High-first pattern at lines 32-38 and 82-115:

```text
rD = *(u8 *)(rB + off + 1)
rD <<= 8
rT = *(u8 *)(rB + off + 0)
rD |= rT
...
=> rD = *(u{16,32,64} *)(rB + off)
```

- Scratch register rule: each byte-load temp must not be the destination register
  (`byte_load_tmp`, lines 117-123).
- Lane combine rule: shifts must be ALU64 left shifts by the exact byte lane, and the OR must
  consume the temp into the destination (`shifted_or_lane` / `or_uses_tmp`, lines 125-134).
- Emission is a single `LDX_MEM` of size `BPF_H`, `BPF_W`, or `BPF_DW` into the original
  destination from the original base and canonical base offset (`emit_wide_mem`, lines 135-151).

Admission/skips before emission:

- Rejects any ladder with an interior branch target (lines 202-208).
- Rejects if a scratch register is live after the matched site (lines 209-221).
- Rejects non-natural offsets for the chosen width (lines 222-231).
- Rejects likely packet-pointer fusions for packet programs (`SCHED_CLS`, `SCHED_ACT`, `XDP`,
  `LWT_*`, `SK_SKB`) unless base is stack or verifier state says otherwise (lines 153-164 and
  232-246).
- Rejects BTF struct or other-pointer bases because a wide load may cross a field boundary
  (lines 247-259).
- Adds a separate skip when a candidate would cross a block boundary through a branch-target entry
  site (lines 271-333).

### Host-side transforms inspected

Commands used:

```bash
bpfopt/target/release/bpfopt --pass wide_mem \
  --input bpfopt/testbin/tetragon_observer/247_generic_kprobe_actions/canonicalize_output.bin \
  --output /tmp/wide_247_actions.bin \
  --report /tmp/wide_247_actions.json \
  --prog-type kprobe

bpfopt/target/release/bpfopt --pass wide_mem \
  --input bpfopt/testbin/tetragon_observer/245_generic_kprobe_filter_arg/canonicalize_output.bin \
  --output /tmp/wide_245_filter_arg.bin \
  --report /tmp/wide_245_filter_arg.json \
  --prog-type kprobe

bpfopt/target/release/bpfopt --pass wide_mem \
  --input bpfopt/testbin/tetragon_observer/251_generic_kprobe_process_filter/canonicalize_output.bin \
  --output /tmp/wide_251_process_filter.bin \
  --report /tmp/wide_251_process_filter.json \
  --prog-type kprobe
```

Reports:

```json
247_generic_kprobe_actions:        {"sites_applied":8,  "sites_matched":8,  "sites_skipped":0, "insn_count_before":1021, "insn_count_after":997}
245_generic_kprobe_filter_arg:    {"sites_applied":47, "sites_matched":47, "sites_skipped":0, "insn_count_before":2109, "insn_count_after":1968}
251_generic_kprobe_process_filter:{"sites_applied":6,  "sites_matched":6,  "sites_skipped":0, "insn_count_before":2174, "insn_count_after":2156}
```

All representative tetragon rewrites were high-first, width-2 halfword fusions. I did not find a
representative width-4 or width-8 tetragon fusion in these failing shapes.

Representative 1021-insn `generic_kprobe_actions` sites:

```text
pc 26: high-first width=2 base=r2 off=0 dst=r1
  26: (71) r1 = *(u8 *)(r2 +1)
  27: (67) r1 <<= 8
  28: (71) r3 = *(u8 *)(r2 +0)
  29: (4f) r1 |= r3
  => (69) r1 = *(u16 *)(r2 +0)

pc 573: high-first width=2 base=r6 off=4 dst=r2
  573: (71) r2 = *(u8 *)(r6 +5)
  574: (67) r2 <<= 8
  575: (71) r1 = *(u8 *)(r6 +4)
  576: (4f) r2 |= r1
  => (69) r2 = *(u16 *)(r6 +4)

pc 583: high-first width=2 base=r6 off=8 dst=r2
  583: (71) r2 = *(u8 *)(r6 +9)
  584: (67) r2 <<= 8
  585: (71) r3 = *(u8 *)(r6 +8)
  586: (4f) r2 |= r3
  => (69) r2 = *(u16 *)(r6 +8)
```

Representative 2109-insn `generic_kprobe_filter_arg` sites:

```text
pc 64: high-first width=2 base=r3 off=0 dst=r1
  64: (71) r1 = *(u8 *)(r3 +1)
  65: (67) r1 <<= 8
  66: (71) r2 = *(u8 *)(r3 +0)
  67: (4f) r1 |= r2
  => (69) r1 = *(u16 *)(r3 +0)

pc 119: high-first width=2 base=r1 off=12 dst=r2
  119: (71) r2 = *(u8 *)(r1 +13)
  120: (67) r2 <<= 8
  121: (71) r3 = *(u8 *)(r1 +12)
  122: (4f) r2 |= r3
  => (69) r2 = *(u16 *)(r1 +12)

pc 189: high-first width=2 base=r1 off=16 dst=r3
  189: (71) r3 = *(u8 *)(r1 +17)
  190: (67) r3 <<= 8
  191: (71) r4 = *(u8 *)(r1 +16)
  192: (4f) r3 |= r4
  => (69) r3 = *(u16 *)(r1 +16)
```

Representative 2174-insn `generic_kprobe_process_filter` sites:

```text
pc 1017: high-first width=2 base=r7 off=0 dst=r5
  1017: (71) r5 = *(u8 *)(r7 +1)
  1018: (67) r5 <<= 8
  1019: (71) r2 = *(u8 *)(r7 +0)
  1020: (4f) r5 |= r2
  => (69) r5 = *(u16 *)(r7 +0)

pc 1395: high-first width=2 base=r9 off=8 dst=r0
  1395: (71) r0 = *(u8 *)(r9 +9)
  1396: (67) r0 <<= 8
  1397: (71) r5 = *(u8 *)(r9 +8)
  1398: (4f) r0 |= r5
  => (69) r0 = *(u16 *)(r9 +8)
```

The visible stack halfword loads in the current prog 192 verifier tail are not necessarily
wide_mem-generated. In the matching 1021-insn testbin, this stack `LDXH` is already present before
wide_mem:

```text
original 247_generic_kprobe_actions:
  606: (79) r8 = *(u64 *)(r10 -80)
  607: (69) r1 = *(u16 *)(r10 -22)
  611: (69) r1 = *(u16 *)(r10 -24)
  615: (69) r1 = *(u16 *)(r10 -26)

after wide_mem:
  582: (79) r8 = *(u64 *)(r10 -80)
  583: (69) r1 = *(u16 *)(r10 -22)
  587: (69) r1 = *(u16 *)(r10 -24)
  591: (69) r1 = *(u16 *)(r10 -26)
```

So the current log tail's `fp[0]-1` stack state is not evidence that wide_mem fused a mixed stack
slot.

## 2. Kernel verifier rejection reason

The current result path is:

`corpus/results/x86_kvm_corpus_20260513_004301_156506/details/apps/tetragon__observer.json`

Counts from that file:

```text
programs: 287
program status=error: 130
wide_mem failed_rejit: 125
wide_mem failed_rejit with sites_applied > 0: 122
wide_mem total sites_applied: 2899
```

For the named example, prog 192:

```text
prog_id=192 name=generic_kprobe_ orig_insn_count=1021
wide_mem step.log_level=2 sites_applied=8 error length=65600 bytes
```

The current JSON preserves only the last 64 KiB of the error string:

```text
... [truncated 33489002 leading bytes; full log in workdir tar]
89: (bf) r3 = r10                    ; frame1: R3=fp0 R10=fp0
790: (07) r3 += -8                    ; frame1: R3=fp-8
```

The visible tail does not contain a final verifier rejection such as `invalid mem access` or
`unbounded`. It ends with normal verifier traversal summaries:

```text
prog 192:
processed 111338 insns (limit 1000000) max_states_per_insn 24 total_states 5227 peak_states 961 mark_read 0

prog 194:
processed 168964 insns (limit 1000000) max_states_per_insn 34 total_states 6220 peak_states 1374 mark_read 0

prog 197:
processed 202943 insns (limit 1000000) max_states_per_insn 29 total_states 8662 peak_states 2804 mark_read 0
```

I searched the current preserved tails and the full May 8 failure tar verifier log for
`invalid mem access`, `unbounded`, and similar verifier-failure strings. They are absent in the
inspected artifacts.

The exact failure sentence preserved in older tetragon result markdown for the same failure class
is ENOSPC, not EINVAL:

```text
prog 30 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)
prog 40 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)
prog 47 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)
```

Source: `corpus/results/x86_kvm_corpus_20260504_042922_581042/details/result.md`, line 6375
contains the first group of these inlined tetragon wide_mem errors.

The May 8 failure tarballs confirm the same log-buffer pattern. For
`corpus/results/x86_kvm_corpus_20260508_202653_157003/details/failure-artifacts/246.tar.gz`:

```text
./verifier_log_step1.log size: 33554431 bytes
./report_step1.json: {"pass":"wide_mem","sites_applied":47,"sites_matched":47,"sites_skipped":0,"insn_count_before":2109,"insn_count_after":1968}
```

The full log starts mid-line and ends with:

```text
from 17 to 291: safe
processed 202943 insns (limit 1000000) max_states_per_insn 29 total_states 8662 peak_states 2804 mark_read 0
```

The size `33554431` is exactly `32 MiB - 1`, matching a verifier log buffer filled to the daemon's
current maximum. That makes the most supported interpretation: the syscall failed because verbose
log capture exhausted the log buffer (`ENOSPC`), not because the transformed bytecode reached a
verifier-invalid state.

## 3. Hypotheses evaluated

### (a) Stack-slot byte ladder fused across mixed/spilled-pointer state

Not supported by the inspected transforms. The representative wide_mem-generated sites are
halfword loads from map-value/filter structures, not stack ladders. The stack `LDXH` visible near
the current prog 192 tail is pre-existing in the canonical input, so it cannot identify an
offending wide_mem site.

A real mixed-stack-slot failure should have a verifier line such as an invalid stack/memory access.
The current preserved tails and the inspected full May 8 tar log do not contain such a line.

### (b) Packet-pointer ladder lost a verifier-required bounds check

Not supported. Tetragon programs here are kprobes (`prog_type=2`), not XDP/TC/packet programs. The
packet-unsafe skip in `wide_mem.rs` applies only to the packet program types listed at lines
153-164. The inspected sites use map-value or scalar-derived bases, and there is no packet bounds
complaint in the logs.

### (c) Fusion across a tail-call site or kfunc call breaks verifier flow

Not supported. The matched tetragon sites are straight-line four-instruction ladders inside one
block. Existing admission checks reject interior branch targets and cross-block branch-target
entries. The representative sites do not span calls, tail calls, or kfunc calls.

### (d) Stale per-site verifier-state assumption

Not supported for wide_mem itself. The host-side commands above passed no `--verifier-states`, and
wide_mem still matched the same sites. wide_mem uses verifier state only to skip some pointer bases
when state is available; it does not require cached per-site state to emit these halfword loads.

The observed failure does correlate with `log_level=2`, but that is a daemon verifier-log capture
requirement for downstream `const_prop`, not a stale-state condition inside wide_mem.

### (e) ARM64-style alignment problem on x86

Not supported. All inspected sites are width-2 with naturally aligned offsets (`0`, `4`, `8`,
`12`, `16`, `144`). `wide_mem.rs` already checks natural alignment at lines 222-231. The run is
x86 KVM, and the visible failure class is `ENOSPC`, not an alignment verifier rejection.

## 4. Pattern-detector audit

For the inspected tetragon sites, the detector did what it was written to do:

- Pattern shape: high-first two-byte ladders match lines 82-115 exactly.
- Scratch register: temps differ from destination, satisfying lines 117-123.
- Branch safety: no interior target inside the four-instruction ladder, satisfying lines 202-208.
- Scratch liveness: no live-out scratch conflict was reported; `sites_skipped=0`.
- Alignment: all offsets are even for width 2, satisfying lines 222-231.
- Packet rule: not applicable because the programs are kprobes.
- BTF/Other pointer rule: no available verifier state classified these bases as BTF struct or
  other-pointer bases; in the host-side command no verifier-state input was used.

The actual transformed instruction is the intended emission at `emit_wide_mem` lines 146-151:

```text
Ok(vec![BpfInsn::ldx_mem(size, site.dst_reg, site.base_reg, off)])
```

No current evidence identifies a structural condition that should have made wide_mem skip these
specific sites. A skip such as "skip tetragon generic_kprobe", "skip large programs", or "skip
log-heavy programs" would be a policy guard without a bytecode root cause and would violate the
project's no-filtering/fail-fast intent.

## 5. Cross-reference cilium and historical tetragon runs

Cilium BR has no direct wide_mem comparison here because wide_mem had no cilium candidates in the
referenced run. The broader ReJIT path is not generally broken: other passes, including large
`const_prop` application counts in cilium, made it through ReJIT.

Historical tetragon result files show that tetragon wide_mem was exercised before, and the outcome
tracks daemon log verbosity:

```text
corpus/results/x86_kvm_corpus_20260508_062557_454122/details/apps/tetragon__observer.json
  wide_mem steps=164 ok=163 failed_rejit=1 sites_applied=351 log_level=1

corpus/results/x86_kvm_corpus_20260508_071049_947460/details/apps/tetragon__observer.json
  wide_mem steps=283 ok=161 failed_rejit=122 sites_applied=2887 log_level=2

corpus/results/x86_kvm_corpus_20260508_193421_787859/details/apps/tetragon__observer.json
  wide_mem steps=282 ok=280 failed_rejit=2 sites_applied=2890 log_level=1

corpus/results/x86_kvm_corpus_20260508_202653_157003/details/apps/tetragon__observer.json
  wide_mem steps=286 ok=161 failed_rejit=125 sites_applied=2904 log_level=2

corpus/results/x86_kvm_corpus_20260513_004301_156506/details/apps/tetragon__observer.json
  wide_mem failed_rejit=125, 122 with sites_applied>0, total sites_applied=2899, log_level=2
```

The same 1021-insn generic-kprobe shape is especially useful:

```text
May 8 193421, prog 250:
  noop log_level=1 ok
  wide_mem log_level=1 ok sites_applied=8
  dce/bounds_check_merge/skb_load_bytes_spec ok

May 8 202653, prog 250:
  noop log_level=1 ok
  wide_mem log_level=2 failed_rejit sites_applied=8
  error begins with the current-style 64 KiB tail truncation marker

May 13 004301, prog 192:
  noop ok
  wide_mem log_level=2 failed_rejit sites_applied=8
```

This is the key control: the same wide_mem halfword transformation is accepted under
`log_level=1` and fails under `log_level=2`. That points away from invalid transformed bytecode and
toward verbose verifier-log buffer exhaustion.

The "wide_mem tetragon=2826/2826" baseline should not be interpreted as proof that all verbose
daemon ReJITs succeeded. Available May 8 artifacts show failures were surfaced as `failed_rejit`
when they occurred; the 2826/2826-style number appears to be a matched/applied-site count or a
different run configuration, not evidence of silent rejected-bytecode acceptance.

## 6. Root cause and minimal fix

I do not find an offending wide_mem fusion in `wide_mem.rs`. The file/line where these fusions are
emitted is `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:146`, but the emitted instruction is the
expected `LDXH` replacement for a high-first two-byte ladder.

The root cause supported by the artifacts is daemon-side verbose verifier log exhaustion plus
response truncation that hides the errno prefix:

- `runner/config/passes/wide_mem/default.yaml:4` declares wide_mem's own input need as
  `log_level: 1`.
- `runner/config/passes/const_prop/default.yaml:4-6` declares `log_level: 2` and consumes
  `${VERIFIER_STATES}`.
- `runner/libs/rejit_plan.py:13-15` and `runner/libs/rejit_plan.py:121-126` make each step's
  outgoing daemon `log_level` equal to the next step's input requirement. Therefore in the BR pass
  sequence `noop,wide_mem,const_prop,...`, the wide_mem ReJIT runs at `log_level=2`.
- `daemon/src/commands.rs:763-780` selects the verbose verifier log buffer when
  `step.log_level == 2`.
- `daemon/src/syscall.rs:18-20` caps retry growth at `32 MiB`.
- `daemon/src/syscall.rs:393-414` retries `ENOSPC` by growing the buffer until the cap, then
  returns the formatted syscall failure.
- `daemon/src/syscall.rs:186-197` formats the important prefix as
  `BPF_PROG_REJIT errno 28: No space left on device (os error 28)`.
- `daemon/src/commands.rs:33-45` then keeps only the last 64 KiB for JSON response fields. For
  current tetragon failures, this drops the formatted errno prefix and leaves only the verifier-log
  tail, so the JSON looks like a verifier bytecode rejection even when the syscall error is
  `ENOSPC`.

Minimal text-only fix proposal:

```diff
diff --git a/daemon/src/commands.rs b/daemon/src/commands.rs
@@
 fn truncate_response_log(text: String) -> String {
     if text.len() <= RESPONSE_LOG_TAIL_BYTES {
         return text;
     }
+    let prefix = text.lines().next().unwrap_or("");
     let dropped = text.len() - RESPONSE_LOG_TAIL_BYTES;
     let mut start = text.len() - RESPONSE_LOG_TAIL_BYTES;
     while start < text.len() && !text.is_char_boundary(start) {
         start += 1;
     }
     format!(
-        "... [truncated {dropped} leading bytes; full log in workdir tar]\n{}",
+        "{prefix}\n... [truncated {dropped} leading bytes; full log in workdir tar]\n{}",
         &text[start..]
     )
 }
```

That fixes the misleading artifact by preserving the syscall errno sentence. A second, related
improvement would be to make `format_prog_rejit_failure()` or the caller append an explicit
sentence for final-cap ENOSPC, for example:

```text
BPF_PROG_REJIT verifier log exceeded daemon max log buffer; bytecode acceptance is unknown from this run.
```

I do not recommend a wide_mem detector skip based on the inspected data. The transformed halfword
loads are accepted under `log_level=1`, the current tails lack an invalid-bytecode verifier line,
and older preserved failure sentences identify `ENOSPC`.

Algorithm fix: daemon-side ENOSPC/error-preservation fix, not a wide_mem bytecode change; keep the BPF_PROG_REJIT errno prefix in truncated errors and report max-log-buffer ENOSPC explicitly because the transformed tetragon LDXH bytecode is accepted under log_level=1.
