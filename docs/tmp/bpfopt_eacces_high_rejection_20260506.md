# bpfopt EACCES high rejection 调研, 2026-05-06

Scope: KVM x86 corpus per-app smoke, `SAMPLES=1`, `noop+12-pass`. This is analysis of existing `result.json` data only; no framework or pass code was changed.

Primary input files:

- `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json`
- `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json`
- `corpus/results/x86_kvm_corpus_20260506_233740_843089/details/apps/tetragon__observer.json`
- `corpus/results/x86_kvm_corpus_20260506_223040_471337/details/apps/otelcol-ebpf-profiler__profiling.json`
- `corpus/results/x86_kvm_corpus_20260506_231413_833842/details/apps/katran.json`
- `corpus/results/x86_kvm_corpus_20260506_223334_701834/details/apps/bcc__set.json`
- `corpus/results/x86_kvm_corpus_20260506_223639_781587/details/apps/bpftrace__set.json`

## 1. 量化分布

For each EACCES program, the culprit pass below is the first non-`ok` pass after the last successful pass in that program's `passes` array.

| app | progs | EACCES | EACCES / progs | culprit `const_prop` | culprit `dce` | culprit `wide_mem` | notable non-EACCES |
|---|---:|---:|---:|---:|---:|---:|---|
| tracee | 158 | 114 | 72.2% | 112 | 2 | 0 | 2 other errors |
| cilium | 53 | 31 | 58.5% | 28 | 2 | 1 | 13 other errors |
| tetragon | 287 | 35 | 12.2% | 35 | 0 | 0 | 142 `ENOSPC` log-buffer failures before later passes |
| otelcol-ebpf-profiler | 13 | 6 | 46.2% | 5 | 1 | 0 | 2 other errors |
| katran | 3 | 1 | 33.3% | 1 | 0 | 0 | 0 |
| bcc/set | 21 | 1 | 4.8% | 0 | 1 | 0 | 1 other error |
| bpftrace/set | 9 | 1 | 11.1% | 1 | 0 | 0 | 0 |
| selected total | 544 | 189 | 34.7% | 182 | 6 | 1 | 193 non-EACCES errors, including 142 tetragon `ENOSPC` |

Tracee + cilium, the two high-rate apps requested for detailed attribution:

| culprit pass | EACCES count | share of tracee+cilium EACCES | affected app split |
|---|---:|---:|---|
| `const_prop` | 140 | 96.6% | tracee 112, cilium 28 |
| `dce` | 4 | 2.8% | tracee 2, cilium 2 |
| `wide_mem` | 1 | 0.7% | cilium 1 |
| `noop` | 0 | 0.0% | none |
| `map_inline` | 0 | 0.0% | none |

Interpretation: the high rejection rate is systematic and dominated by `const_prop`. `map_inline` and `noop` do not directly fail ReJIT in these results.

## 2. 元凶 pass

### `const_prop`

`const_prop` accounts for 182/189 selected-app EACCES and 140/145 tracee+cilium EACCES.

Representative examples:

- tracee prog 20, `sys_enter_submit`: previous passes through `map_inline` succeed; `const_prop` fails with `R1 type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_` at a `bpf_probe_read_kernel#113` helper argument. The combined top-level error log starts at `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json:2875`; the program name appears in the per-program section at the same file's line 27.
- tracee prog 38, `syscall__execve_enter`: `const_prop` fails with `R1 type=scalar expected=map_ptr` at `bpf_map_lookup_elem#1`, also in `tracee__monitor.json:2875`; the program name appears at `tracee__monitor.json:189`.
- cilium prog 110, `tail_handle_ipv4_from_host`: `const_prop` fails around `bpf_tail_call#12` with a helper argument that should still be context/map state, in `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json:985`; the program name appears at `cilium__agent.json:54`.

The source shape matches the failure mode:

- `const_prop` builds verifier exact-constant facts from `InsnDeltaState` keyed by `(pc, reg)` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:120-147`.
- It applies those verifier-derived facts while simulating each instruction at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:190-204` and `bpfopt/crates/bpfopt/src/passes/const_prop.rs:324-399`.
- ALU/MOV replacement uses `oracle.exact_for_instruction(pc, dst_reg, ...)` before local evaluation at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:402-419`.
- Replacement emission is a plain scalar `mov32`, `mov64`, or plain `ldimm64` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:661-670`.
- The unit test at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1008-1033` explicitly verifies using verifier exact constants after helper calls, so this is intentional behavior rather than an accidental unused path.

The verifier log parser also makes this plausible:

- The parser is designed to feed optimization analyses from verifier logs at `bpfopt/crates/kernel-sys/src/verifier_log.rs:1-10`.
- It parses `<pc>: (insn) ; R...` lines as `InsnDeltaState` at `bpfopt/crates/kernel-sys/src/verifier_log.rs:171-191`.
- Exact values are only treated as scalar facts in `bpfopt/crates/kernel-sys/src/verifier_log.rs:285-321` and `bpfopt/crates/kernel-sys/src/lib.rs:168-185`.

### `dce`

`dce` accounts for 6/189 selected-app EACCES and 4/145 tracee+cilium EACCES. The pattern is not type substitution; it is unreadable/uninitialized registers:

- tracee prog 52, `sched_process_exec_event_submit_tail`: `dce` fails with `R1 !read_ok` after a `bpf_probe_read_kernel#113` sequence, at `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json:34225`; the program name appears at `tracee__monitor.json:315`.
- cilium prog 115 and prog 123, both `cil_to_host`: `dce` fails with `R3 !read_ok`, with pass-specific errors at `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json:4189` and `cilium__agent.json:5857`; program ids/names are at `cilium__agent.json:4414-4419` and `cilium__agent.json:6083-6088`.

Relevant code:

- `dce` removes unreachable blocks, dead register definitions, and NOPs at `bpfopt/crates/bpfopt/src/passes/dce.rs:43-67`.
- It then remaps BTF metadata and annotations at `bpfopt/crates/bpfopt/src/passes/dce.rs:85-88`.

### `wide_mem`

There is one cilium EACCES with first failed pass `wide_mem`:

- cilium prog 11, `dump_bpf_prog`: diagnostic is `access beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8`, in `cilium__agent.json:985`; the program name appears at `cilium__agent.json:18`.

This does not explain the high rejection rate. In this case the `wide_mem` pass report showed no applied rewrite and no instruction delta, so it looks like a ReJIT/verifier/BTF acceptance problem for that program shape, not a broad `wide_mem` rewrite bug.

## 3. 错误类型分类

Normalized top diagnostics:

| normalized diagnostic | tracee+cilium count | selected-app count | dominant pass | common context |
|---|---:|---:|---|---|
| `R# type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_` | 126 | 165 | `const_prop` | helper arg should be stack/map/packet memory pointer |
| `R# type=scalar expected=ctx` | 9 | 10 | `const_prop` | helper arg should be program context |
| `R# type=scalar expected=map_ptr` | 5 | 5 | `const_prop` | `bpf_map_lookup_elem#1` first arg |
| `R# !read_ok` | 4 | 5 | `dce` | register definition removed or path no longer initializes it |
| `access beyond the end of member pages ... struct bpf_prog ...` | 1 | 1 | `wide_mem` | cilium iterator/BTF program |
| `R1 bitwise operator &= on pointer prohibited` | 0 | 1 | `const_prop` | pointer/scalar type confusion |
| `R4 invalid mem access 'scalar'` | 0 | 1 | `const_prop` | pointer use degraded to scalar |
| `R0 min value is outside of the allowed memory range` | 0 | 1 | `dce` or downstream pass | range/provenance invalidation |

Exact top selected-app diagnostic strings:

| exact final verifier string | count |
|---|---:|
| `R1 type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_` | 145 |
| `R2 type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_` | 20 |
| `R1 type=scalar expected=ctx` | 10 |
| `R1 type=scalar expected=map_ptr` | 5 |
| `R1 !read_ok` | 3 |
| `R3 !read_ok` | 2 |

Helper concentration in tracee+cilium:

| helper / site type near final rejection | count | main diagnostic |
|---|---:|---|
| `call bpf_probe_read_kernel#113` | 108 | memory pointer arg became scalar |
| `call bpf_map_lookup_elem#1` | 21 | map pointer or key pointer became scalar |
| `call bpf_skb_change_tail#38` | 4 | context arg became scalar |
| `call bpf_tail_call#12` | 3 | context/map argument became scalar |
| `call bpf_perf_event_output#25` | 1 | context arg became scalar |
| `call bpf_skb_store_bytes#9` | 1 | context/memory arg became scalar |
| no helper at final line | 1 | cilium BTF struct bounds |

Program type concentration:

| app | type | EACCES count |
|---|---|---:|
| tracee | `kprobe` | 92 |
| tracee | `raw_tracepoint` | 21 |
| tracee | `lsm` | 1 |
| cilium | `sched_cls` | 30 |
| cilium | `tracing` | 1 |
| tetragon | `kprobe` | 33 |
| tetragon | `tracepoint` | 1 |
| tetragon | `raw_tracepoint` | 1 |
| otelcol-ebpf-profiler | `perf_event` | 6 |
| katran | `xdp` | 1 |
| bcc/set | `kprobe` | 1 |
| bpftrace/set | `tracepoint` | 1 |

This is not a single prog type issue. Tracee is dominated by `kprobe`/`raw_tracepoint`, while cilium is dominated by `sched_cls`. The common feature is helper argument type/provenance, not attach type.

Stack / size correlation:

- tracee+cilium EACCES logs have max stack offset median about 208 bytes, p90 about 296 bytes, max about 440 bytes.
- tracee EACCES programs are all large in original instruction count, but cilium includes both large and sub-500-instruction failures.
- Stack size and large program size increase exposure, but they are not a sufficient root cause. Small/medium cilium programs still fail when `const_prop` replaces verifier-sensitive setup code.

## 4. bytecode bug 还是 verifier 兼容性问题?

The data points to wrong rewrite semantics, primarily in `const_prop`, not to valid bytecode that the verifier refuses because of an intentional fast path.

Evidence against `map_inline` as the main issue:

- `map_inline` has 0 direct EACCES in selected apps and 0 direct EACCES in tracee+cilium.
- Among all 182 `const_prop` EACCES programs, 149 had `map_inline.sites_applied == 0`. For tracee+cilium, 112/140 `const_prop` EACCES had no `map_inline` rewrite.
- `map_inline` instruction delta was 0 for 180/182 `const_prop` EACCES programs.
- Source-wise, `map_inline` returns unchanged when no rewrites are prepared at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1114-1120`, and its rewrite/remap logic is localized at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1176-1225`.

Evidence for `const_prop` bytecode bug:

- The dominant final errors are verifier type errors on helper arguments: pointer or context values became plain scalars.
- `const_prop` can emit plain scalar immediate instructions from verifier exact facts at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:409-416` and `bpfopt/crates/bpfopt/src/passes/const_prop.rs:661-670`.
- The emitted scalar immediate cannot preserve verifier-only provenance such as `fp`, `ctx`, `map_ptr`, `map_value`, or packet pointer type.
- The affected helper calls are exactly helper interfaces that require typed/provenance-carrying registers, especially `bpf_probe_read_kernel#113` and `bpf_map_lookup_elem#1`.

`dce` looks like a smaller independent bytecode bug:

- Its failures are `R1 !read_ok` / `R3 !read_ok`, not pointer-vs-scalar mismatches.
- The code removes dead register definitions and NOPs at `bpfopt/crates/bpfopt/src/passes/dce.rs:51-67`; the verifier symptoms match a removed definition or a broken path-sensitive initialization.

`wide_mem` looks like a one-off verifier/BTF acceptance issue:

- The sole cilium failure is a BTF struct member bounds diagnostic, not a helper-argument scalar replacement.
- It is not a high-rate pattern.

## 5. verifier states / PC offset

Configured pass order is:

`wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> noop -> map_inline -> const_prop -> dce -> bounds_check_merge -> skb_load_bytes_spec -> bulk_memory -> prefetch`

The x86 pass order is in `corpus/config/benchmark_config.yaml:4-17`.

State handoff mechanics:

- Step construction gives `log_level=2` to passes that produce verifier states at `runner/libs/rejit_plan.py:61-63` and `runner/libs/rejit_plan.py:81`.
- `noop`, `map_inline`, and `const_prop` metadata are state-producing or state-consuming at `bpfopt/crates/bpfopt/src/passes/mod.rs:86-89` and `bpfopt/crates/bpfopt/src/passes/mod.rs:103-106`.
- The daemon starts with a deliberately nonexistent verifier-state path so state-needing passes cannot silently proceed without a producer at `daemon/src/commands.rs:468-474`.
- For each pass, the daemon writes `output_stepN.bin`, `report_stepN.json`, and `verifier_log_stepN.log` at `daemon/src/commands.rs:477-480`.
- Each produced bytecode is immediately ReJITed at `daemon/src/commands.rs:642-659`.
- After each successful ReJIT, the daemon updates `verifier_states_path = verifier_log_path`, `input_path = output_path`, and `current_bytes = pass_bytes` at `daemon/src/commands.rs:662-664`.

Conclusion:

- `noop` after the first five kop passes is correctly positioned to regenerate verifier states after any earlier instruction-count changes.
- `map_inline` also produces fresh verifier states; therefore `const_prop` consumes the verifier log for the post-`map_inline` bytecode, not stale `noop` states.
- If a PC mismatch exists, the likely bug is inside `const_prop`'s interpretation of verifier log PC/state semantics, not an old `noop` state being fed across `endian_fusion` or `map_inline`.

First-five-pass instruction-count changes do occur before `noop`:

- tracee+cilium EACCES often have nonzero `cond_select` rewrites; some tracee cases also have `wide_mem`.
- But because `noop` comes after those passes and produces the next verifier-state log, those earlier PC shifts should be realigned before `map_inline`.
- `endian_fusion` had applied sites in some outputs but did not show a broad nonzero instruction-delta pattern in the selected tracee+cilium EACCES set.

## 6. 猜测根因

### H1, highest confidence: `const_prop` folds verifier-sensitive pointer setup into scalar immediates

Support:

- 140/145 tracee+cilium EACCES and 182/189 selected-app EACCES are first failed at `const_prop`.
- The top diagnostics are helper argument type mismatches, not arbitrary verifier failures.
- `const_prop` uses verifier exact constants keyed by `(pc, reg)` and emits scalar immediate bytecode.
- Examples hit `bpf_probe_read_kernel#113`, `bpf_map_lookup_elem#1`, `bpf_tail_call#12`, and skb helpers, all of which require typed/provenance registers.

Counter-evidence:

- The oracle ignores non-scalar states at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:81-85`, so the bug may not be "it directly folds a pointer state." A more precise version is likely PC/state-kind misuse: a scalar exact fact at the same PC or post-state is being applied to an instruction whose result must still reconstruct pointer provenance for the next helper.

### H2, medium confidence: `const_prop` uses post-instruction verifier states at the wrong semantic point

Support:

- The parser classifies instruction delta states from `<pc>: (insn) ; R...` at `bpfopt/crates/kernel-sys/src/verifier_log.rs:171-191`.
- `const_prop` applies oracle post-state after analyzing an instruction at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:398`, but also uses `exact_for_instruction(pc, dst_reg, ...)` while deciding how to replace that instruction at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:409-416`.
- If that state represents the verifier's state after the instruction, replacing the instruction with a scalar immediate can destroy the operation that produced a pointer or initialized memory for the next helper.

Counter-evidence:

- This needs a one-program bytecode diff to prove. The result artifacts do not preserve pass output binaries by default.

### H3, medium confidence: `dce` deletes verifier-needed definitions or path initializers

Support:

- All observed tracee+cilium `dce` failures are `R1 !read_ok` or `R3 !read_ok`.
- `dce` removes dead register definitions and NOPs after CFG cleanup at `bpfopt/crates/bpfopt/src/passes/dce.rs:43-67`.

Counter-evidence:

- Only 4 tracee+cilium failures and 6 selected-app failures are attributed to `dce`; it cannot explain the high rejection rate.

### H4, low confidence as primary cause: `map_inline` fast path is verifier-incompatible

Support:

- Some cilium `const_prop` failures occur after `map_inline` applied rewrites, so `map_inline` can feed a more constant-heavy program into `const_prop`.
- `map_inline` has direct pseudo-map-value constantization logic at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1918-2020`.

Counter-evidence:

- 0 direct `map_inline` EACCES.
- Most `const_prop` EACCES have no `map_inline` rewrite.
- This is not the primary systematic failure.

### H5, low confidence as primary cause: stale verifier states from `noop`

Support:

- The pipeline relies on verifier-log side inputs for `map_inline` and `const_prop`.

Counter-evidence:

- Daemon state handoff updates verifier-state path after every successful ReJIT at `daemon/src/commands.rs:662-664`.
- `noop` is after the first five kop passes in `corpus/config/benchmark_config.yaml:4-17`.
- `map_inline` and `const_prop` are declared state producers/consumers at `bpfopt/crates/bpfopt/src/passes/mod.rs:103-106`.
- Therefore stale `noop` state does not explain the observed dominant `const_prop` helper-argument failures.

## 7. 复现和 bytecode artifact 状态

Best reproduction target:

- tracee prog 20 `sys_enter_submit`: high-signal `const_prop` failure, many helper-argument scalar mismatches, and full top-level verifier log in `tracee__monitor.json:2875`.

What is missing:

- The result directories inspected did not contain `output_step*.bin`, `verifier_log_step*.log`, failure tarballs, or kept workdirs under the tracee result directory.
- The per-program result payload carries pass summaries and verifier log tails, not the actual per-pass bytecode binaries.

Existing debug path for a rerun:

- `runner/libs/rejit_plan.py:83-94` supports `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS`: it copies each daemon-fed `${INPUT}` into the workdir and deliberately forces a failure so the daemon's failure-artifact mechanism can return a tarball.
- That is sufficient for a targeted rerun of tracee prog 20 or a narrowed app smoke, without changing pass logic.

## 8. 修复方向

Priority 0: make `const_prop` verifier-type safe before using it for corpus results.

- Direction: disable oracle-driven ALU/MOV-to-immediate replacement unless the original instruction's relevant verifier state is scalar both before and after the instruction and the replacement cannot be part of helper argument setup.
- Direction: conservatively refuse replacements touching `R1`-`R5` in a short window before helper calls unless the helper ABI expects a scalar for that argument.
- Direction: never replace instructions that materialize or preserve `fp`, `ctx`, `map_ptr`, `map_value`, packet pointer, ringbuf memory, or trusted pointer provenance.
- Risk: low correctness risk, medium to high performance impact. It may remove many currently invalid const-prop wins, but should restore retained-program coverage and make paper-grade measurements meaningful.

Priority 0: isolate the exact `const_prop` replacement class with one saved-bytecode repro.

- Direction: rerun tracee prog 20 with kept workdir artifacts and compare bytecode before/after `const_prop`.
- Direction: inspect the few instructions immediately before the final rejected helper call and map them back to `const_prop` replacements.
- Risk: none for framework behavior if done as a debug rerun. High diagnostic value.

Priority 1: split `const_prop` into safer modes.

- Direction: keep branch folding separately from ALU/MOV scalar materialization; enable branch folding first.
- Direction: re-enable ALU folding only for local scalar chains proven without verifier oracle facts.
- Risk: low correctness risk, medium performance impact. This gives an incremental path instead of disabling all `const_prop`.

Priority 1: gate `dce` dead-definition removal.

- Direction: temporarily disable or narrow `eliminate_dead_register_defs` while keeping unreachable-block cleanup, or require stronger liveness proof around helper arguments.
- Risk: low performance impact compared with `const_prop`; only 6 selected-app EACCES are currently `dce`.

Priority 2: improve tetragon observability.

- Direction: increase the verbose verifier log buffer for state-producing passes or rerun tetragon with a larger debug buffer to get past the 142 `ENOSPC` failures.
- Risk: no expected paper performance impact, but it may reveal more downstream `const_prop` failures hidden behind current log-buffer exhaustion.

Priority 2: deprioritize `map_inline` as the primary fix.

- Direction: do not disable `map_inline` globally based on this dataset. It has no direct EACCES in the selected apps and most `const_prop` failures occur with no `map_inline` rewrite.
- Risk: disabling `map_inline` would likely lose optimization opportunity without addressing the dominant rejection mode.

## 结论

The high EACCES rate is systematic. The dominant failure is `const_prop` converting verifier-sensitive helper argument setup into scalar-immediate bytecode, or equivalently using verifier exact-state information at the wrong semantic point. `dce` has a smaller independent `!read_ok` problem. `noop` placement and stale verifier states are unlikely to be the cause because verifier states are regenerated after each successful state-producing pass and chained by the daemon.
