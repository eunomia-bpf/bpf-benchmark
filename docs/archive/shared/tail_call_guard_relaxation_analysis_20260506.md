# Tail-call kop guard relaxation analysis - 2026-05-06

+ NUKED: tail-call program-wide guard deleted. `kop_replacement_subprog_skip_reason()` now returns after only bpfopt subprogram/range checks (`bpfopt/crates/bpfopt/src/passes/utils.rs:725-776`); `const_prop` no longer filters replacements through a tail-call protected prefix (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:190-207`); `dce` runs unreachable/dead-def/nop cleanup without tail-call gating (`bpfopt/crates/bpfopt/src/passes/dce.rs:43-60`).

All parent-repo source citations were read with `git show HEAD:<path>`. The user prompt named `HEAD=e3c3388b`, but the checked-out parent `HEAD` during this investigation was `88e43e83b87bc5cc406110de50de77e3450021de`. The relevant guard file is identical between `e3c3388b` and this checked-out `HEAD`; `vendor/linux-framework` is the same submodule commit in both (`81cb8848bacea3595befa0d5bdea842f976dee41`). Kernel citations below were read with `git -C vendor/linux-framework show HEAD:<path>`.

## 1. What the guard does today

The generic kop replacement guard is `kop_replacement_subprog_skip_reason()` in `bpfopt/crates/bpfopt/src/passes/utils.rs:728-785`. It first enforces nonzero lengths, site bounds, subprogram containment, replacement containment, and no subprogram entry inside the old replacement range. Then it calls `kop_replacement_tail_call_skip_reason()` at `utils.rs:787-803`.

Tail-call behavior today:

- `tail_call_protected_prefix_end()` returns the exclusive end of the last tail-call instruction: `last_tail_call_pc + insn_width()` (`utils.rs:823-827`).
- `is_tail_call_insn()` recognizes both verifier-rewritten `BPF_JMP | BPF_TAIL_CALL` and source helper calls with `imm == BPF_FUNC_tail_call` (`utils.rs:841-844`).
- If there is no tail call, the guard permits the site.
- If `replacement_len == old_len` and `start_pc >= last_tail_end`, the guard permits the site (`utils.rs:793-796`).
- Otherwise it rejects with `kop site in program with tail-call helper (tail call pc {pc}, site pc {start_pc})` (`utils.rs:798-802`).
- The diagnostic tail-call pc is not necessarily nearest. `tail_call_skip_report_pc()` reports a tail call inside the old site if the site covers one; otherwise it reports the first tail call in the program (`utils.rs:805-820`).

So this is not quite a program-wide ban. It allows fixed-length replacements after the last tail-call instruction. But it is still effectively a broad ban for most packed-kop optimizations:

- Any replacement before or through the last tail call is rejected, even if length-preserving.
- Any length-changing replacement anywhere in a program containing a tail-call helper is rejected, even after the last tail call.
- The unit tests encode this policy directly: fixed-length before-tail-call is rejected, size-changing before-tail-call is rejected, fixed-length after-tail-call is allowed, and size-changing after-tail-call is rejected (`utils.rs:1403-1461`).

Guard callers in `HEAD`:

| pass | caller | replacement length supplied to guard | affected by guard |
|---|---:|---|---|
| `bulk_memory` | `bulk_memory.rs:176-181` | `site.replacement_len()` | yes |
| `ccmp` | `ccmp.rs:197-202` | constant `CCMP_REPLACEMENT_LEN = 3` | yes |
| `cond_select` | `cond_select.rs:189-194` | `lowering.prefix.len() + 2` | yes |
| `endian_fusion` | `endian.rs:452-464` | architecture-dependent packed-kop lowering plus retained suffix | yes |
| `extract` | `extract.rs:145-150` | `2` | yes |
| `rotate` | `rotate.rs:65-70` | `2` | yes |

Other related passes:

- `prefetch` is a packed-kop pass and inserts two instructions per candidate (`prefetch.rs:196-228`), but it does not call this guard.
- `wide_mem` and `map_inline` are length-changing transforms but do not use packed kop calls and do not call this guard.
- `const_prop` and `dce` use `tail_call_protected_prefix_end()` separately (`const_prop.rs:193-210`, `dce.rs:38-55`), so they have related tail-call conservatism but are not blocked by this exact skip reason.

## 2. What invariants it protects

There are three plausible invariants behind the guard.

1. Tail-call poke descriptors.

Direct tail calls have a kernel-side `struct bpf_jit_poke_descriptor` with JIT patch addresses plus descriptor identity fields: `tail_call.map`, `tail_call.key`, `reason`, and `insn_idx` (`vendor/linux-framework/include/linux/bpf.h:1641-1657`). The verifier creates a descriptor when it sees a `BPF_FUNC_tail_call`, records the current instruction index, appends it through `bpf_jit_add_poke_descriptor()`, and rewrites the instruction to `BPF_JMP | BPF_TAIL_CALL` with `imm = ret + 1` (`kernel/bpf/verifier.c:24140-24178`). The x86 JIT uses that `imm` as the poke-table index (`arch/x86/net/bpf_jit_comp.c:2555-2559`).

The original reason for a PC-preservation guard was reasonable for an older design: if an old poke descriptor array were reused by instruction index, instruction-count changes before a tail-call site would make descriptor PCs stale.

2. BTF func_info / line_info offsets.

`struct bpf_func_info` and `struct bpf_line_info` both store `insn_off` (`include/uapi/linux/bpf.h:7475-7488`). bpfopt has metadata remapping helpers for ordinary rewrites and special kop proof-subprogram layout (`utils.rs:85-108`, `utils.rs:635-677`). The CLI can read/write raw metadata when supplied (`bpfopt/src/main.rs:585-644`).

In the daemon path, however, `BPF_PROG_REJIT` is invoked with only bytecode and an fd array (`daemon/src/commands.rs:182-204`, `daemon/src/commands.rs:670-677`). The ReJIT attr itself has `prog_fd`, `insn_cnt`, `insns`, log fields, `fd_array`, and flags; it has no func_info or line_info fields (`include/uapi/linux/bpf.h:1935-1945`). BTF metadata preservation is therefore a general transform invariant when metadata is present, not a reason to ban kop replacements in tail-call programs.

3. Branch target reachability and subprogram layout.

The kop passes already check interior branch targets before calling the tail-call guard, and `fixup_all_branches()` remaps surviving branches and pseudo calls through an address map (`utils.rs:13-67`). `kop_replacement_subprog_skip_reason()` separately ensures the old and replacement ranges stay within the same subprogram (`utils.rs:753-777`). This invariant should remain, but it does not require a tail-call-program-wide instruction-count ban.

## 3. Kernel preservation requirements vs defensive bpfopt policy

The current kernel ReJIT path does not require tail-call instruction indices to be preserved.

ReJIT constructs a temporary `bpf_prog` from the new bytecode, copies the new instructions, runs `bpf_check()`, selects runtime/JIT, and only then updates the original program in place (`kernel/bpf/syscall.c:3610-3786`). That means the verifier re-walks the new bytecode and builds a new `tmp->aux->poke_tab`.

The decisive code is `bpf_prog_rejit_update_poke_tab()`:

- `bpf_prog_rejit_supported()` says tail-call `poke_tab` is supported and the tail-call pattern `(count, map, key)` must be identical between old and new bytecode (`kernel/bpf/syscall.c:3167-3199`).
- `bpf_prog_rejit_update_poke_tab()` first requires the same `size_poke_tab` (`syscall.c:3224-3228`).
- It validates each descriptor by sequence using `reason`, `tail_call.map`, and `tail_call.key` (`syscall.c:3241-3249`).
- It explicitly does not reject moved instruction indices. The comment says the new JIT image can place the helper call at a different eBPF instruction index while emitting the same descriptors in the same discovery order (`syscall.c:3230-3240`).
- It copies the new JIT address fields from `tmp` into the old descriptor table (`syscall.c:3251-3288`), then swaps the program image (`syscall.c:3810-3837`).

So the kernel-side preservation contract is semantic descriptor preservation, not PC-layout preservation:

- Required: same number of direct-tail-call poke descriptors.
- Required: same descriptor order.
- Required: same descriptor identity: reason, map, key.
- Not required: same `insn_idx`.
- Not required: unchanged bytecode length before tail-call sites.

That makes the current bpfopt guard defensive beyond the kernel contract. The minimum kernel-driven safety check is not "no instruction-count changes in a program with a tail-call helper"; it is "do not change the ordered direct-tail-call descriptor pattern." A pass that does not rewrite a tail-call instruction or its descriptor-defining map/key semantics should be allowed to move tail-call PCs. The kernel will reject actual descriptor-pattern mismatches with `-EINVAL`.

## 4. Concrete false-positive evidence from otel ARM64

Input artifact: `corpus/results/aws_arm64_corpus_20260506_193211_995298/details/result.json`. This is the same otel ARM64 run summarized by `docs/tmp/cond_select_arm64_emit_diagnosis_20260506.md`.

`cond_select` matched 31 sites and applied 0. Of those, 30 were rejected by the tail-call guard and 1 by register pressure.

The saved result does not include the original bytecode snapshot, so exact nearest-tail-call distances cannot be reconstructed solely from `result.json`. The skip reason preserves one reported tail-call pc, which is the first tail-call pc unless the old replacement range itself contains a tail call. Using that reported pc, all 30 rejected sites are far away:

- min distance: 444 instructions
- median distance: 3091.5 instructions
- max distance: 6968 instructions
- count with distance greater than 256: 30/30
- count with distance greater than 512: 25/30
- count with distance greater than 1024: 21/30

Per-program detail:

| prog_id | prog_name | reported tail pc | rejected site pcs | distance range |
|---:|---|---:|---|---:|
| 82 | `perf_unwind_sto` | 1324 | 545, 692, 695 | 629-779 |
| 83 | `perf_unwind_nat` | 6941 | 2086, 2472, 3644, 4055, 5271, 5445, 5864, 6488 | 453-4855 |
| 84 | `perf_unwind_hot` | 6292 | 1332, 1513, 1524, 2742, 4155, 5848 | 444-4960 |
| 86 | `perf_unwind_php` | 6835 | 46, 162 | 6673-6789 |
| 87 | `perf_unwind_pyt` | 5836 | 882 | 4954 |
| 89 | `perf_unwind_v8` | 7782 | 814, 1701, 2588, 3472, 4415, 5305, 7135, 7334 | 448-6968 |
| 93 | `native_tracer_e` | 232 | 728, 731 | 496-499 |

Two observations matter:

- Even under the weaker "reported tail pc" evidence, the otel rejections are not adjacent to tail-call instructions. An `N=256` window around the reported tail call would have admitted all 30 rejected candidates.
- `native_tracer_e` is a clear post-tail-call example from the diagnostic itself: sites at 728 and 731 are after the reported tail call at 232, but they are still rejected because `cond_select` is length-changing and the current guard rejects any length-changing site in a tail-call program.

## 5. Per-pass impact across recent corpus runs

I parsed `corpus/results/x86_kvm_corpus_20260506_073134_900272/details/result.json` and all present `corpus/results/aws_arm64_corpus_20260506_*/details/result.json` artifacts. Only rows with a nonzero `kop site in program with tail-call helper` count are shown.

| run | app | pass | programs hit | matched | applied | matched-applied | guard skips | other skips in same rows |
|---|---|---|---:|---:|---:|---:|---:|---:|
| `aws_arm64_corpus_20260506_193211_995298` | `otelcol-ebpf-profiler/profiling` | `cond_select` | 7 | 31 | 0 | 31 | 30 | 1 |
| `x86_kvm_corpus_20260506_073134_900272` | `cilium/agent` | `cond_select` | 20 | 70 | 0 | 70 | 70 | 0 |
| `x86_kvm_corpus_20260506_073134_900272` | `cilium/agent` | `endian_fusion` | 10 | 30 | 10 | 20 | 20 | 0 |
| `x86_kvm_corpus_20260506_073134_900272` | `tetragon/observer` | `bulk_memory` | 78 | 164 | 0 | 164 | 164 | 0 |
| `x86_kvm_corpus_20260506_073134_900272` | `tetragon/observer` | `cond_select` | 166 | 1701 | 79 | 1622 | 1218 | 404 |
| `x86_kvm_corpus_20260506_073134_900272` | `tetragon/observer` | `endian_fusion` | 9 | 45 | 18 | 27 | 27 | 0 |
| `x86_kvm_corpus_20260506_073134_900272` | `tetragon/observer` | `extract` | 9 | 9 | 0 | 9 | 9 | 0 |
| `x86_kvm_corpus_20260506_073134_900272` | `tracee/monitor` | `bulk_memory` | 22 | 41 | 0 | 41 | 24 | 17 |
| `x86_kvm_corpus_20260506_073134_900272` | `tracee/monitor` | `cond_select` | 25 | 89 | 0 | 89 | 87 | 2 |
| `x86_kvm_corpus_20260506_073134_900272` | `tracee/monitor` | `extract` | 7 | 35 | 0 | 35 | 35 | 0 |

App totals in those artifacts:

| run | app | programs hit | matched-applied in rows with guard | guard skips |
|---|---|---:|---:|---:|
| `aws_arm64_corpus_20260506_193211_995298` | `otelcol-ebpf-profiler/profiling` | 7 | 31 | 30 |
| `x86_kvm_corpus_20260506_073134_900272` | `cilium/agent` | 20 | 90 | 90 |
| `x86_kvm_corpus_20260506_073134_900272` | `tetragon/observer` | 166 | 1822 | 1418 |
| `x86_kvm_corpus_20260506_073134_900272` | `tracee/monitor` | 25 | 165 | 146 |

Pass totals across these artifacts:

| pass | guard skips |
|---|---:|
| `cond_select` | 1405 |
| `bulk_memory` | 188 |
| `endian_fusion` | 47 |
| `extract` | 44 |
| total | 1684 |

The biggest paper-perf bottleneck in these artifacts is `cond_select`, especially tetragon and cilium on x86 plus otel on ARM64. `bulk_memory` is also materially blocked in tetragon. `rotate` and `ccmp` did not have nonzero guard skips in this artifact set.

## 6. Verdict

Yes, the guard is too conservative for the current vendor kernel. Confidence: high.

The guard is stricter than the kernel's ReJIT tail-call contract. The kernel rebuilds poke descriptors from the new bytecode and explicitly accepts moved eBPF instruction indices as long as the descriptor sequence and `(reason, map, key)` identity are unchanged. bpfopt currently rejects many sites solely because their program contains a tail-call helper and the replacement changes instruction count or occurs before the last tail call.

There is also a lower-confidence but still decisive old-model point: even if the kernel still required PC preservation, the current guard would be too conservative because it rejects length-changing sites after the last tail-call instruction and fixed-length sites before the last tail-call instruction. Those cases do not shift tail-call PCs under the old PC-indexing model.

Residual risk is not zero. A transform that rewrites a tail-call instruction or changes the verifier's direct-tail-call descriptor discovery order/map/key would still break ReJIT and should be rejected or allowed to surface as a kernel `-EINVAL`. But the current prefix/program-level length ban is not the minimum precision needed to avoid that.

Minimum-precision safety rule, stated semantically rather than as code:

- Keep existing subprogram-boundary and interior-branch-target checks.
- Reject a kop replacement whose old range contains a tail-call instruction.
- Reject, or rely on ReJIT to reject, a replacement that changes the ordered direct-tail-call descriptor pattern `(count, reason, map, key)`.
- Do not reject solely because instruction count changes before or after a tail-call pc.

## 7. Relaxation dimensions

Relaxation axes to consider, without proposing a concrete patch:

1. PC-layout relaxation.

Remove the assumption that tail-call instruction indices must be preserved. The kernel ReJIT path already remaps by rebuilding descriptors from the new bytecode and copying new JIT address fields.

2. Range narrowing.

Narrow the bpfopt guard from "program has tail-call helper and this replacement is not fixed-length after the last tail call" to "replacement touches tail-call semantics." The most direct range rule is to reject only ranges that include a tail-call instruction. A more conservative proof-oriented version could also protect local descriptor setup when bpfopt cannot prove map/key preservation, but that should be a semantic/dataflow rule, not a whole-prefix rule.

3. Length-preservation allow.

Allow fixed-length replacements regardless of whether they occur before or after a tail call, provided they do not touch the tail-call instruction or descriptor-defining semantics. Current tests reject fixed-length before-tail-call sites despite no PC shift.

4. Post-tail-call allow.

Even under the older PC-index preservation model, length-changing replacements after the last tail-call instruction are safe with respect to tail-call PC indexing. The current guard rejects them; the `native_tracer_e` otel sites demonstrate the lost opportunity.

5. No arbitrary N unless it is only an implementation stopgap.

The kernel evidence does not require an `N`-instruction exclusion window around tail calls. If the team wants a temporary implementation guard, a small window can reduce risk, but it should be treated as proof debt. From the otel ARM64 artifact, an `N=256` window around the reported tail-call pc would have admitted all 30 guard-rejected `cond_select` sites.

6. Consistent packed-kop policy.

`prefetch` already inserts packed kop calls without this generic guard. Whatever tail-call safety contract is chosen should be applied consistently across packed-kop transforms, rather than blocking only the replacement-style passes.

7. Diagnostics.

Keep per-site skip reasons, but improve the tail-call diagnostic if the guard remains: report whether the site contains a tail call, is before the last tail call, or is after the last tail call but length-changing. The current message reports the first tail-call pc in most cases, which is not enough to analyze nearest-tail-call distance from result artifacts alone.
