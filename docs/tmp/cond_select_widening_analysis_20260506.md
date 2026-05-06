# cond_select matcher widening analysis - 2026-05-06

All source citations below were read with `git show HEAD:<path>` unless noted.
Local `HEAD` during this investigation was `88e43e83`, while the prompt named
`e3c3388b` as HEAD. The named commit exists locally, and
`bpfopt/crates/bpfopt/src/passes/cond_select.rs` is identical for this analysis
scope. No code, build, smoke, make, docker, or cargo command was run. The only
file written is this report.

## 1. Current matcher coverage

### Implementation shape

`bpfopt/crates/bpfopt/src/passes/cond_select.rs:33-50` defines a scalar
`CondSelectSite`: one `dst_reg`, one `true_val`, one `false_val`, and the JCC
metadata. `CondSelectValue` is already a four-way enum with `Reg`, `Reg32`,
`Imm`, and `Imm32` at `cond_select.rs:66-72`.

The matcher is not const-vs-const only at this HEAD:

- Pattern A is the 4-instruction diamond at `cond_select.rs:293-322`:
  `Jcc +2; MOV dst,false; JA +1; MOV dst,true`.
- Pattern C is the 3-instruction short conditional MOV at
  `cond_select.rs:324-377`:
  `MOV dst,true; Jcc +1; MOV dst,false`.
- `is_select_mov()` accepts both ALU64 MOV and ALU32 MOV at
  `cond_select.rs:380-386`.
- `extract_mov_value()` records register and immediate operands, including
  32-bit MOV register values, at `cond_select.rs:388-400`.

Lowering is also register-capable:

- `build_lowering()` protects source registers, selects/inverts true and false
  values, and materializes only values that are not already usable as a 64-bit
  source register at `cond_select.rs:402-447`.
- `condition_prefix()` can reuse a zero-compare condition register directly,
  or create a predicate register for JMP32, non-zero immediates, and non-NE/EQ
  comparisons at `cond_select.rs:449-545`.
- `materialize_value()` returns `Reg` directly, copies `Reg32` with `mov32`,
  and materializes immediates into temporary registers at
  `cond_select.rs:563-589`.
- Temp selection avoids live-out and protected registers at
  `cond_select.rs:600-623`.

The replacement is the packed kinsn ABI, not ordinary call-argument setup:
`cond_select.rs:226-237` encodes `dst`, `a_reg`, `b_reg`, and `cond_reg` into a
sidecar payload, then emits `emit_packed_kinsn_call_with_off(...)`.
`bpfopt/crates/bpfopt/src/passes/utils.rs:1177-1191` shows the packed
replacement is exactly two BPF instructions: sidecar plus kinsn call.

The Rust comment at `cond_select.rs:21-29` describes an older-looking logical
`bpf_select64(a,b,cond)` call shape. The kernel modules expose the actual kinsn
stub as `__bpf_kfunc void bpf_select64(void) {}` at
`module/x86/bpf_select.c:8-10` and `module/arm64/bpf_select.c:8-10`, and decode
all operands from the packed sidecar payload at `module/x86/bpf_select.c:18-36`
and `module/arm64/bpf_select.c:18-36`.

### Existing tests

Reg and mixed values are already tested and applied:

- Pattern C with register values is detected at
  `cond_select_tests.rs:126-139`.
- Pattern A with register values is detected at
  `cond_select_tests.rs:195-210`.
- Pattern C with register values emits a packed select call at
  `cond_select_tests.rs:160-180`.
- Mixed immediate/register cases apply at `cond_select_tests.rs:294-352`.
- Pattern A with register values applies at `cond_select_tests.rs:481-507`.
- Alias coverage across `cond_reg`, `true_src`, and `false_src` is tested at
  `cond_select_tests.rs:613-665`.

### Safety and tail-call gates

After matching, `cond_select` requires branch-target and liveness analyses at
`cond_select.rs:89-91`, gets them at `cond_select.rs:140-143`, then checks:

- missing liveness, `cond_select.rs:150-157`;
- lowering failures, `cond_select.rs:159-168`;
- interior branch targets, excluding the site's own JCC target,
  `cond_select.rs:170-187`;
- generic kinsn subprogram/tail-call safety,
  `cond_select.rs:189-200`.

The generic guard is in `bpfopt/crates/bpfopt/src/passes/utils.rs:728-785`.
For tail-call programs, the key rule is `utils.rs:787-803`: a kinsn replacement
is allowed only when `replacement_len == old_len` and `start_pc` is after the
exclusive end of the last tail-call instruction. `utils.rs:823-844` defines the
protected prefix as the region through the last tail-call helper or tail-call
instruction.

### ARM64 OTel result evidence

Artifact:
`corpus/results/aws_arm64_corpus_20260506_193211_995298/details/result.json`.

The result records only per-pass summaries and skip reasons. It does not retain
the original bytecode or matched operand kinds, so the 31 OTel sites cannot be
classified as const-vs-const, reg-vs-reg, or mixed from this artifact alone.
The first 10 recorded candidate PCs are:

| prog_id | program | site_pc | tail_call_pc | result evidence |
|---:|---|---:|---:|---|
| 82 | `perf_unwind_sto` | 545 | 1324 | tail-call guard |
| 82 | `perf_unwind_sto` | 692 | 1324 | tail-call guard |
| 82 | `perf_unwind_sto` | 695 | 1324 | tail-call guard |
| 83 | `perf_unwind_nat` | 2086 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 2472 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 3644 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 4055 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 5271 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 5445 | 6941 | tail-call guard |
| 83 | `perf_unwind_nat` | 5864 | 6941 | tail-call guard |

Across all 31 sites, 30 are tail-call guard skips and 1 is
`no dead register available to materialize immediate operand`. The latter proves
at least one matched site had an operand that needed materialization
(`Imm`, `Imm32`, or `Reg32`), but it does not classify the other 30 sites.

### Static object scan

To estimate pattern distribution, I ran read-only `llvm-objdump -d
--no-show-raw-insn` scans on recent built BPF objects. This is a rough upper
bound: it scans object bytecode, not the exact live kernel bytecode from the
result artifact, and it does not apply bpfopt safety gates.

| object | insns scanned | current matches | imm/imm | reg/reg | mixed | Pattern A | Pattern C |
|---|---:|---:|---:|---:|---:|---:|---:|
| `opentelemetry-ebpf-profiler/native_stack_trace.bpf.o` | 3693 | 7 | 7 | 0 | 0 | 0 | 7 |
| `opentelemetry-ebpf-profiler/generic_probe.bpf.o` | 996 | 1 | 1 | 0 | 0 | 0 | 1 |
| `cilium/bpf_lxc.bpf.o` | 50750 | 151 | 129 | 4 | 18 | 1 | 150 |
| `cilium/bpf_xdp.bpf.o` | 28974 | 447 | 412 | 0 | 35 | 254 | 193 |

Sample current matches from the static scan:

- OTel `native_stack_trace`, Pattern C imm/imm:
  `r2 = 0x8; if r7 == 0x0 goto +0x1; r2 = 0x4`.
- OTel `native_stack_trace`, Pattern C imm/imm:
  `r1 = 0x1; if r0 != 0x0 goto +0x1; r1 = 0x0`.
- Cilium `bpf_lxc`, Pattern C imm/imm:
  `w6 = -0x9a; if w0 s< 0x0 goto +0x1; w6 = 0x0`.
- Cilium `bpf_lxc`, Pattern C imm/imm:
  `w3 = 0x1; if w1 == 0x200 goto +0x1; w3 = 0x0`.

Reg/reg is present but rare in this sample. Mixed register/immediate is more
common than pure reg/reg in Cilium. Since HEAD already supports both, Axis 1
has no remaining matcher uplift at this commit.

## 2. Per-axis analysis

### Axis 1: Reg-vs-reg select

Pattern:
`mov rdst, rA; if cond goto +1; mov rdst, rB`, or the equivalent 4-insn
diamond with register MOVs.

1. Matcher complexity

No implementation work is needed at this HEAD. The exact axis is already
recognized by `try_match_cond_select()` through `is_select_mov()` and
`extract_mov_value()` at `cond_select.rs:290-400`. The existing `CondSelectValue`
enum and `materialize_value()` are already able to carry `Reg` and `Reg32`.

If this were being added to an older const-only baseline, the invasive points
would have been:

- add register variants to `CondSelectValue`, now at `cond_select.rs:66-72`;
- teach `extract_mov_value()` to distinguish `BPF_X` MOVs, now at
  `cond_select.rs:388-400`;
- protect source registers in temp allocation, now at `cond_select.rs:413-419`
  and `cond_select.rs:615-623`;
- handle 32-bit MOV register values with zero-extension, now at
  `cond_select.rs:580-583` and `cond_select.rs:591-598`.

2. Emit feasibility

Existing `bpf_select64` is sufficient. The packed payload already has register
slots for destination, true value, false value, and condition:

- payload encoding in bpfopt: `cond_select.rs:230-234`;
- payload decoding in x86 module: `module/x86/bpf_select.c:18-36`;
- payload decoding in ARM64 module: `module/arm64/bpf_select.c:18-36`;
- formal payload fields in `docs/kinsn-formal-semantics.md:333-364`.

No new kfunc is required. The current packed ABI naturally handles source
register values. Immediate values are the special case, because they need prefix
materialization into a register before the packed select.

3. Verifier safety

This is the safest axis. The kinsn proof sequence is just a conditional branch
plus MOVs:

- x86 proof instantiation: `module/x86/bpf_select.c:38-53`;
- ARM64 proof instantiation: `module/arm64/bpf_select.c:38-53`;
- formal proof semantics: `docs/kinsn-formal-semantics.md:356-368`.

There is no speculative computation of an untaken branch. If the original code
could move either register into `dst`, the proof code does the same. The main
pitfalls are aliasing and preserving the condition source before any `dst`
write. The x86 emitter explicitly handles ordering around aliasing; the formal
semantics document calls out this condition at
`docs/kinsn-formal-semantics.md:647-650`, and the Rust tests cover source
aliasing at `cond_select_tests.rs:613-665`.

4. Estimated site uplift

Remaining uplift at this HEAD: zero, because the feature is already present.

If comparing against the stale "const-only" premise, the read-only object scan
suggests reg/reg is usually a small minority:

- OTel sample: 0 reg/reg or mixed out of 8 current matches.
- Cilium `bpf_lxc`: 4 reg/reg and 18 mixed out of 151 current matches.
- Cilium `bpf_xdp`: 0 reg/reg and 35 mixed out of 447 current matches.

Order of magnitude: adding register operands to a truly const-only matcher
would likely add 0-15 percent to current cond_select site counts in these
samples, but still a very small fraction of total BPF instructions. Since HEAD
already includes it, this is not an actionable uplift source.

5. Tail-call guard interaction

Reg-vs-reg does not dodge the current tail-call guard. For common zero
comparisons, the prefix length is 0 and the packed replacement length is 2.
That changes instruction count relative to both Pattern C old length 3 and
Pattern A old length 4. In any program containing a tail-call helper,
`utils.rs:787-803` rejects length-changing replacements regardless of whether
the site is before or after the last tail call.

Reg-vs-reg can avoid immediate temp materialization failures, but it does not
avoid the dominant OTel guard failure. It only helps the 1/31 OTel failure if
that specific site can be represented without materializing any immediate or
Reg32 value.

6. False-positive risk

The current false-positive risk is low because both supported shapes are tiny
and require same `dst`. Existing protections include:

- Pattern C rejects cases where the pre-JCC MOV clobbers the JCC condition reg
  or source reg at `cond_select.rs:344-356`.
- Interior branch targets are rejected at `cond_select.rs:170-187`.
- Source regs are protected from temp allocation at `cond_select.rs:413-419`.

The remaining risks are mostly around verifier type joins and aliasing, already
covered by the proof semantics and alias tests. There is no memory side effect
or helper-call side effect in the matched body.

### Axis 2: Multi-insn body select

Pattern:
short `if cond { rdst = X; rother = Y } else { rdst = X'; rother = Y' }`, with
1-2 MOVs per branch.

1. Matcher complexity

Medium to high. This is not a scalar `CondSelectSite`; it is a small parallel
assignment. The current site struct at `cond_select.rs:33-50` would need to
become either a vector of lanes or a new site kind. The matcher at
`cond_select.rs:290-377` would need to parse variable branch lengths:

```text
Jcc +(false_len + 1)
false MOV lane 0
false MOV lane 1
JA +true_len
true MOV lane 0
true MOV lane 1
```

It would also need to verify that both branches write the same live-out
destinations. Existing broad-match examples worth copying in style are:

- `ccmp` scans variable-length same-target branch chains at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:314-356`;
- `wide_mem` scans multiple byte-ladder variants with descending width priority
  at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:90-148`;
- `bulk_memory` carries richer match outcomes and local state through the scan
  at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:267-305`.

New recognition needed:

- branch-body length derivation from JCC and JA offsets;
- same destination set across branches, ideally in lane order or with an
  explicit lane matching rule;
- liveness filtering so dead lane writes do not create pointless selects;
- branch-target rejection for every interior instruction, not just the current
  single-MOV body;
- alias analysis for cases where one lane writes a register read by another
  lane.

No existing `cond_select` test covers multi-output branch bodies. Existing
tests stop at one destination.

2. Emit feasibility

For simple non-aliasing bodies, existing `bpf_select64` is sufficient: emit one
packed select per destination lane. For two destinations, the minimal
replacement is two sidecar/call pairs, so four BPF instructions, plus any
predicate or value materialization prefix.

The hard part is preserving parallel assignment semantics. For example, if
either branch contains `r1 = r2; r2 = r1`, sequentially emitting `select(r1,...)`
then `select(r2,...)` can read a value after it has already been overwritten.
Conservative implementation can skip all cases where any lane destination is
used as any later lane source, but that cuts into the already-small candidate
set. A more complete implementation needs source snapshots in temporary
registers, and temp pressure can become the dominant skip reason.

A new multi-output kfunc is not required for the narrow non-aliasing subset, but
it may be required for a robust and compact "two-lane select" if the goal is to
preserve simultaneous semantics without many bpfopt-emitted temp MOVs. Such a
kfunc would be kernel work and would need a new payload format, proof length
calculation, native emitters, and verifier proof instantiation.

3. Verifier safety

Verifier safety is acceptable only for a conservative subset:

- each body instruction must be MOV32 or MOV64 only;
- no stack writes, map operations, memory loads, calls, atomics, or pointer
  arithmetic;
- all source registers must hold the same values they held at the original
  branch point when each select executes;
- output register state after the lane sequence must match the verifier merge
  the original branch would have produced.

The existing `bpf_select64` proof writes one destination per call. Multiple
calls are individually valid, but inter-call register clobbering from earlier
lane writes can break later lanes unless source snapshots are used.

4. Estimated site uplift

Low. The static scan found zero two-MOV-per-branch diamonds in the OTel/Cilium
sample under a deliberately simple matcher:

- OTel `native_stack_trace.bpf.o`: 0.
- OTel `generic_probe.bpf.o`: 0.
- Cilium `bpf_lxc.bpf.o`: 0.

Typical clang-generated BPF appears to create many single-scalar conditional
MOVs, while multi-output if/else blocks often include stores, helper calls,
loads, or other side effects that this axis must reject. Expected uplift is
order 0-5 percent over current cond_select site counts, with a realistic chance
of zero in OTel.

5. Tail-call guard interaction

This axis usually still hits the same guard. A two-lane MOV diamond has old
length around 6 (`Jcc`, 2 false MOVs, `JA`, 2 true MOVs). Two existing
`bpf_select64` calls have replacement length 4 before prefix materialization,
so the replacement is length-changing and is rejected in any program with a
tail-call helper by `utils.rs:787-803`.

Using a new two-lane kfunc would make the replacement even shorter, not safer
for this guard. The only natural way to pass the current guard in tail-call
programs is to be length-preserving and after the last tail call, or to add an
explicit padding policy. Neither exists in the current pass.

6. False-positive risk

Main false positives:

- branch bodies assign the same destinations but in different orders with
  source/destination aliasing;
- one lane's destination is dead on one path but live on the other;
- a MOV is actually a `LD_IMM64` pseudo-map/pseudo-function load in objdump-like
  text, not a simple ALU MOV;
- a branch target enters the middle of one branch body;
- 32-bit MOV zero-extension is accidentally widened to 64-bit semantics;
- source register state differs across paths before the apparent MOV body.

This axis is implementable, but the safe subset is narrow.

### Axis 3: Side-effect-free arithmetic

Pattern:
one branch computes a short pure expression on `rdst`, or both branches compute
short pure arithmetic expressions, with no helper calls or map/memory
operations.

1. Matcher complexity

High. This requires a local expression/dataflow matcher, not just branch-shape
recognition. Extension points would be:

- replace or extend `CondSelectSite` at `cond_select.rs:33-50` to carry
  expression trees or emitted candidate-computation prefixes;
- extend `try_match_cond_select()` at `cond_select.rs:290-377` to parse
  variable-length branch bodies;
- extend `build_lowering()` at `cond_select.rs:402-447` to allocate temporaries
  for both candidate expressions;
- likely add verifier-state requirements, because syntactic "pure arithmetic"
  is not enough to prove scalar-only safety.

The matcher would need a whitelist for side-effect-free operations. It should
probably exclude at least:

- helper/kfunc calls;
- loads, stores, atomics, stack writes, map operations, packet accesses;
- `LD_IMM64` pseudo-map/pseudo-function values;
- division and modulo unless divisor safety is proven;
- pointer arithmetic unless verifier state proves scalar semantics are being
  preserved;
- any operation that writes the condition register or a still-needed source.

No existing `cond_select` test covers arithmetic branch bodies.

2. Emit feasibility

Existing `bpf_select64` can be reused only after both candidate values have been
computed into registers. For example, a safe scalar diamond like:

```text
if w5 == 0x33 goto true
w0 = w3
w0 &= 0xff
w0 <<= 3
goto join
true:
w0 = w3
w0 &= 0xff
w0 <<= 2
```

could be lowered by computing both expressions into temporaries and then using
one select. That does not need a new kfunc, but it usually increases bpfopt
prefix length and temp pressure.

A new kfunc is not attractive unless it encodes a very specific expression
family. A general "select arithmetic expression" kfunc would need an expression
bytecode or many payload modes, which is disproportionate to the observed site
count and risky for verifier proof semantics.

3. Verifier safety

This is the riskiest axis. The original program executes only one branch body.
A branchless replacement that computes both candidate expressions speculatively
can make previously untaken operations execute. That is safe only when the
extra operations are total, scalar-only, and verifier-legal without the original
branch predicate.

Important cases to reject:

- arithmetic on pointer-typed registers, including packet, map-value, stack, or
  context pointers;
- arithmetic whose verifier legality depends on the branch condition;
- division/modulo with a divisor that may be zero;
- ALU32/ALU64 width mismatches where zero-extension or sign behavior changes;
- any body that changes a register used by the other candidate computation;
- any candidate that would require reading a value after it is overwritten.

The current pass does not consume verifier states. Adding this axis safely
probably requires verifier-state awareness or an extremely narrow scalar
syntactic subset.

4. Estimated site uplift

The static scan found a small number of pure-arithmetic short branches, again as
an upper bound:

| object | broad pure-arithmetic short branches | notes |
|---|---:|---|
| `opentelemetry-ebpf-profiler/native_stack_trace.bpf.o` | 2 | one-sided pure length 2 |
| `opentelemetry-ebpf-profiler/generic_probe.bpf.o` | 1 | one-sided pure length 2 |
| `cilium/bpf_lxc.bpf.o` | 9 | mostly one-sided, often multiple destination writes |
| `cilium/bpf_xdp.bpf.o` | 17 | includes 4 same-dst pure diamonds in the scanned subset |

Representative Cilium `bpf_xdp` same-dst arithmetic diamond:

```text
if w5 == 0x33 goto +0x4
w0 = w3
w0 &= 0xff
w0 <<= 0x3
goto +0x3
w0 = w3
w0 &= 0xff
w0 <<= 0x2
```

Representative OTel one-sided pure branch:

```text
if r4 > r2 goto +0x2
r7 = r3
r7 += 0x1
```

Order of magnitude: a safe implementation might add a few sites in Cilium and
near-zero in OTel. After rejecting pointer-dependent arithmetic, aliasing, and
multi-destination one-sided bodies, expected net uplift is likely below 5-10
percent of current static cond_select matches and far below 0.1 percent of total
instructions. It is not likely to move paper-performance numbers unless those
few sites are extremely hot.

5. Tail-call guard interaction

This axis does not naturally dodge the OTel tail-call guard. It often changes
instruction count in either direction:

- computing both expressions plus one select is often longer than the original;
- using a compact new expression kfunc would be shorter than the original;
- neither case is admitted by `utils.rs:787-803` in a tail-call-helper program
  unless the final replacement length exactly equals old length and the site is
  after the last tail call.

For OTel, broadening the matcher before solving the tail-call policy likely
turns into more matched-but-skipped sites, not more applied sites.

6. False-positive risk

Main false positives:

- "pure" arithmetic is actually pointer arithmetic whose safety depends on the
  branch predicate;
- the untaken branch contains an operation that would be verifier-illegal if
  executed unconditionally;
- ALU32 and ALU64 results are mixed incorrectly;
- a register source is overwritten while still needed for the other candidate;
- the branch body writes stack or map state despite looking like arithmetic in a
  text dump;
- an interior label or subprogram entry enters the branch body;
- dead writes are selected even though only a subset of destinations is live at
  the join.

Axis 3 needs the strictest admission policy.

## 3. Cross-axis ranking

| Rank | Axis | ROI verdict | Why |
|---:|---|---|---|
| 1 | Axis 1, reg-vs-reg | Already done | HEAD already detects and emits reg/reg and mixed values. There is no remaining implementation ROI, but any stale branch should be updated to this code. |
| 2 | Axis 3, pure arithmetic | Best remaining research axis, but risky | It has some real static candidates in Cilium, and existing `bpf_select64` can be reused for a narrow scalar subset. Safety and temp pressure are significant. |
| 3 | Axis 2, multi-MOV body | Lowest ROI | The scan found zero simple two-MOV diamonds in the sampled objects. Correct parallel-copy semantics add complexity and may need many temps or a new multi-output kfunc. |

Paper-performance priority changes the ranking in one important way: none of
the remaining axes should come before the tail-call guard decision if the target
workload is OTel ARM64. The current OTel artifact has 30/31 candidates rejected
by that generic guard. Matcher broadening alone is likely to increase
`sites_matched`, not `sites_applied`.

## 4. New-kfunc-required vs existing-kfunc-sufficient

Existing `bpf_select64` is sufficient for:

- Axis 1 completely. It already takes register operands through the sidecar
  payload.
- Axis 2 only for a conservative, non-aliasing subset where each destination
  lane can be emitted as an independent scalar select.
- Axis 3 only when bpfopt can compute both candidate scalar values into
  registers safely before calling `bpf_select64`.

New kfunc or kernel-side extension would be needed for:

- an efficient and robust multi-output select that preserves parallel lane
  semantics without source snapshot prefixes;
- any attempt to encode arithmetic expressions directly in a kfunc payload
  instead of materializing both candidate values in ordinary BPF first;
- any attempt to make these widened replacements length-preserving by changing
  kernel-side proof length rather than padding in bpfopt.

Recommendation: do not add a new kfunc for Axis 2 or Axis 3 yet. The site
uplift is too uncertain, and the tail-call guard would still reject
length-changing replacements in tail-call-heavy programs. Use existing
`bpf_select64` for any exploratory implementation, with conservative skips.

## 5. Recommended axis order

1. Treat Axis 1 as complete at this HEAD. If any branch still reports
   const-only behavior, first verify it is actually running this cond_select
   implementation and these tests.

2. Fix or explicitly decide the tail-call replacement policy before spending
   paper-performance effort on matcher widening. The OTel ARM64 artifact is
   dominated by this guard, not by missing reg/reg recognition.

3. If matcher widening is still desired, prototype Axis 3 first with a very
   narrow subset:
   scalar-only same-destination diamonds, ALU32/ALU64 exact width preservation,
   no div/mod, no memory, no calls, no pointer arithmetic, no branch interior
   targets, and skip on any temp-pressure or alias uncertainty. Reuse existing
   `bpf_select64`.

4. Attempt Axis 2 only after a corpus scan shows real multi-MOV diamonds in hot
   programs. Start with non-aliasing independent lanes and emit multiple
   existing selects. Do not design a new multi-output kfunc without stronger
   corpus evidence.

## 6. Open questions / unknowns

Axis 1:

- Why did the prompt context describe current HEAD as const-vs-const only when
  both `HEAD` and `e3c3388b` contain register support?
- Are the benchmark machines definitely running this exact bpfopt binary, or a
  stale build?
- For the single OTel non-tail-call skip, what exact operand kind caused
  immediate materialization pressure? The result artifact lacks bytecode.

Axis 2:

- Do production loaded programs contain hot two-MOV branch diamonds after the
  kernel/verifier transformations, not just object-file bytecode?
- How much of the apparent multi-output branch population has source/dest
  aliasing that would require snapshots?
- Should dead lane writes be ignored, or should a multi-lane site require all
  lane destinations to be live at the join?

Axis 3:

- Can bpfopt access sufficient verifier state at the site to prove scalar-only
  candidate computations?
- Which ALU operations are allowed in the speculative computation subset?
  `ADD/SUB/AND/OR/XOR/LSH/RSH/ARSH/MUL` look plausible; `DIV/MOD` should
  probably be excluded initially.
- Is there a measurable hot-path benefit after the extra prefix instructions
  needed to compute both candidate expressions?
- Should bpfopt ever pad replacements to satisfy the tail-call guard, or should
  the guard be relaxed with a more precise tail-call poke-index model?

Overall unknown:

- The exact 31 OTel ARM64 matched sites cannot be operand-classified from the
  saved `result.json`. Future reports should retain a compact per-site
  diagnostic like `pc`, `old_len`, `pattern`, `true_kind`, `false_kind`,
  `replacement_len`, and `skip_reason` if matcher-coverage investigations will
  continue.
