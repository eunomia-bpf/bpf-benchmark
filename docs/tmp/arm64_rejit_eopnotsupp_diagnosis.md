# ARM64 `BPF_PROG_REJIT` `EOPNOTSUPP` diagnosis for Katran `balancer_ingres`

Date: 2026-05-06

Scope: read-only diagnosis of why ARM64 Katran `balancer_ingres` fails the bootstrap
`noop` `BPF_PROG_REJIT` step with `EOPNOTSUPP`.

Primary evidence:

- Kernel source was inspected from the pinned `vendor/linux-framework` submodule revision.
- Superproject source paths were read from the requested HEAD where relevant.
- Katran ARM64 evidence came from
  `corpus/results/aws_arm64_corpus_20260506_194818_115918/details/result.json`.
- Katran x86 comparison came from
  `corpus/results/x86_kvm_corpus_20260506_073134_900272/details/result.json`.
- ARM64 successful-program comparison came from
  `corpus/results/aws_arm64_corpus_20260506_193211_995298/details/result.json`.

## 1. Inventory of `EOPNOTSUPP` returns in ARM64 BPF JIT, verifier, and REJIT paths

### REJIT command path

- `vendor/linux-framework/kernel/bpf/syscall.c:3642`

  `bpf_prog_rejit()` initializes `err = -EOPNOTSUPP` before checking
  `bpf_prog_rejit_supported(prog)`. This pre-verifier gate rejects programs that
  are not eligible for REJIT before the replacement bytecode is checked.

- `vendor/linux-framework/kernel/bpf/syscall.c:3167-3200`

  `bpf_prog_rejit_supported()` rejects:

  - programs that are not currently JITed;
  - subprogram function objects (`prog->is_func`);
  - offloaded or device-bound programs;
  - attached `BPF_PROG_TYPE_EXT` programs without `aux->dst_prog`.

  It does not reject XDP, tail-call targets, direct-call programs, or programs
  with a tail-call poke table. The nearby comment explicitly says tail-call
  targets are covered by poke descriptor updates.

- `vendor/linux-framework/kernel/bpf/syscall.c:3784`

  `bpf_prog_rejit()` initializes `err = -EOPNOTSUPP` again after verifier
  acceptance and after `bpf_prog_select_runtime(tmp, &err)`. It then rejects if
  `!bpf_prog_rejit_supported(tmp) || !tmp->jited`.

  This is the most important source location for the Katran failure. If the
  verifier accepts the temporary program but the architecture JIT returns a
  non-JITed program, this gate converts the condition into the user-visible
  `EOPNOTSUPP`.

- `vendor/linux-framework/kernel/bpf/core.c:2521-2574`

  `bpf_prog_select_runtime()` runs the architecture JIT. If the JIT returns a
  non-JITed program and `jit_needed` is true, this function can report
  `-ENOTSUPP`; otherwise the caller can still observe `tmp->jited == false`.
  The REJIT syscall has its own post-JIT `EOPNOTSUPP` gate, so a silent or
  collapsed architecture JIT failure can surface as `EOPNOTSUPP` rather than the
  architecture-internal error.

### ARM64 JIT path

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1201-1235`

  `emit_kop_desc_call_arm64()` is the only direct `-EOPNOTSUPP` return in the
  ARM64 BPF JIT implementation. It handles `BPF_PSEUDO_KOP_CALL` and returns
  `-EOPNOTSUPP` if `bpf_jit_get_kop_payload()` returns no payload or the
  payload lacks an ARM64 emitter:

  - `!kop`
  - `!kop->emit_arm64`

  This is a real REJIT-related ARM64 limitation, but it is not a good match for
  Katran `noop`: the failing bootstrap pass feeds the original/non-kop
  bytecode, and the verifier log does not show kop calls.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1643-1648`

  `build_insn()` reaches `emit_kop_desc_call_arm64()` only for
  `BPF_JMP | BPF_CALL` with `src_reg == BPF_PSEUDO_KOP_CALL`.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2063-2306`

  `bpf_int_jit_compile()` returns the original non-JITed program on several JIT
  failures, including body build failures, image allocation failures, validation
  failures, and finalization failures. The function does not propagate a rich
  architecture error back to `BPF_PROG_REJIT`; the REJIT syscall later sees
  `tmp->jited == false` and reports `EOPNOTSUPP` at `syscall.c:3784`.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1335-1349`,
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1464-1479`

  ARM64 emits `UDIV`/`SDIV` for BPF division/modulo. There is no
  `EOPNOTSUPP` return for these ALU operations in the inspected code.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1665-1669`

  Tail calls use `emit_bpf_tail_call()`. Failure here returns `-EFAULT`, not
  `-EOPNOTSUPP`.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1924-1946`

  Atomic operations dispatch through ARM64 atomic emitters. This path does not
  directly return `-EOPNOTSUPP` in the inspected code.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1948-1950`

  Unknown or unsupported instructions return `-EINVAL`, not `-EOPNOTSUPP`.

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2317-2343`

  ARM64 advertises support for private stacks, kfunc calls, and subprogram
  tail-calls:

  - `bpf_jit_supports_private_stack() == true`
  - `bpf_jit_supports_kfunc_call() == true`
  - `bpf_jit_supports_subprog_tailcalls() == true`

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2851-2854`,
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3173-3189`

  ARM64 advertises fsession and arena support. `bpf_jit_supports_insn()` only
  rejects arena atomics when LSE atomics are unavailable. Katran
  `balancer_ingres` is not an arena program.

### Verifier paths that can return `EOPNOTSUPP`

- `vendor/linux-framework/kernel/bpf/verifier.c:3482-3492`

  Kfunc calls return `-EOPNOTSUPP` if vmlinux BTF is missing, JIT is not
  requested, or the architecture does not support kfunc calls. ARM64 advertises
  kfunc-call support, and Katran `balancer_ingres` does not show kfunc calls in
  the failing verifier log.

- `vendor/linux-framework/kernel/bpf/verifier.c:8482-8489`

  64-bit load-acquire/store-release operations require a 64-bit JIT target.
  ARM64 is 64-bit, so this is not a match.

- `vendor/linux-framework/kernel/bpf/verifier.c:9061`

  `bpf_timer` use is disabled on PREEMPT_RT. Katran `balancer_ingres` does not
  use `bpf_timer`.

- `vendor/linux-framework/kernel/bpf/verifier.c:10117-10148`,
  `vendor/linux-framework/kernel/bpf/verifier.c:10313-10317`

  `get_constant_map_key()` returns `-EOPNOTSUPP` for internal map-key analysis
  cases where the verifier cannot elide nullness. The caller treats
  `-EOPNOTSUPP` as non-fatal and returns success, so this is not the user-visible
  REJIT failure.

- `vendor/linux-framework/kernel/bpf/verifier.c:15155`

  Unprivileged pointer arithmetic sanitization can return `-EOPNOTSUPP` for an
  unsupported pointer type. REJIT runs under privileged daemon capabilities; the
  failing log is not this path.

- `vendor/linux-framework/kernel/bpf/verifier.c:22025-22029`,
  `vendor/linux-framework/kernel/bpf/verifier.c:23037`

  Arena programs require JIT and architecture support. ARM64 advertises arena
  support, with the LSE-atomic caveat above. Katran is not an arena program.

- `vendor/linux-framework/kernel/bpf/verifier.c:24308`

  `map_gen_lookup()` returning `-EOPNOTSUPP` falls back to generic map-ops
  patching. It is not propagated as the REJIT syscall errno.

- `vendor/linux-framework/kernel/bpf/verifier.c:24505`

  Unsupported `bpf_get_func_ret` attach contexts patch a helper return value to
  `-EOPNOTSUPP`; this is generated program behavior, not verifier rejection.

- `vendor/linux-framework/kernel/bpf/verifier.c:25554`

  Fsession requires JIT support. ARM64 advertises support, and Katran XDP is not
  an fsession program.

### Header stubs

- `vendor/linux-framework/include/linux/filter.h:1799-1839`

  Several skb/xdp helper stubs return `-EOPNOTSUPP` when `CONFIG_NET` support is
  absent. These are not the Katran path: the benchmark kernel has networking and
  XDP enabled, and these are not REJIT verifier/JIT returns.

## 2. `balancer_ingres` feature inventory

Source artifact:
`corpus/results/aws_arm64_corpus_20260506_194818_115918/details/result.json`.

Program identity:

- app: `katran`
- program: `balancer_ingres`
- program id: `92`
- program type: `6` (`BPF_PROG_TYPE_XDP`)
- original instruction count in pass record: `2544`
- baseline `bytes_xlated`: `23824`
- baseline `bytes_jited`: `14464`
- bootstrap pass: `noop`
- bootstrap result: `failed_rejit`
- syscall error: `BPF_PROG_REJIT errno 95: Operation not supported`

Verifier/JIT phase observation:

- The REJIT verifier log begins with:
  - `func#0 @0`
  - `func#1 @2320`
  - `func#2 @2468`
- The log ends after a full verifier traversal:
  `processed 67941 insns (limit 1000000) max_states_per_insn 20 total_states 3993 peak_states 1206 mark_read 0`.
- This strongly indicates that the verifier accepted the identity/noop program
  and the failure happened after verification, during or immediately after JIT
  selection.

Subprograms:

- Present.
- The verifier log contains three function entry points: `0`, `2320`, and
  `2468`.
- The trace includes BPF-to-BPF calls such as `call pc+1041`, `call pc+1186`,
  and `call pc+483`.
- This is a multi-subprogram XDP program.

Tail calls:

- No `bpf_tail_call` helper call appears in the failing `balancer_ingres`
  verifier log.
- `balancer_ingres` is a Katran tail-call target in the deployed chain, but the
  bytecode under REJIT is not a tail-call origin program.
- Tail-call origin protection is therefore not a direct explanation for this
  program's bootstrap `noop` failure.

Helpers used:

- `bpf_map_lookup_elem#1`
- `bpf_map_update_elem#2`
- `bpf_ktime_get_ns#5`
- `bpf_get_smp_processor_id#8`
- `bpf_xdp_adjust_head#44`

Kfuncs / kop calls:

- No kfunc calls were identified in the failing verifier log.
- No `BPF_PSEUDO_KOP_CALL` evidence was identified in the failing verifier
  log.
- This makes the ARM64 `emit_kop_desc_call_arm64()` `-EOPNOTSUPP` path an
  unlikely direct cause for the bootstrap `noop` failure.

Atomics:

- No atomic op evidence was found in the failing verifier log.
- Searches for atomic markers, `xadd`, `cmpxchg`, and atomic opcodes did not
  identify an atomic-use signature.

Maps:

Named maps observed in the verifier log include:

- `stats`
- `vip_map`
- `quic_stats_map`
- `fallback_cache`
- `reals`
- `ctl_array`
- `ch_rings`
- `vip_miss_stats`
- `server_id_map`
- `reals_stats`
- `server_id_stats`
- `lru_mapping`
- `vip_to_down_rea`
- `lru_miss_stats`

The program uses many maps, as expected for Katran, but the observed named set
is well below the REJIT fd-array limit. The daemon's fd-array layout is maps
first, followed by BTF module fds. Nothing in the failure points to fd-array
overflow.

Attach type:

- The result payload records program type but not a concrete attach type.
- The kernel REJIT path copies `expected_attach_type` from the original program
  before verification.
- For this Katran XDP program, the effective attach type is expected to be the
  normal XDP attach context rather than a tracing/kfunc attach context.

Noop transform:

- `bpfopt/crates/bpfopt/src/passes/noop.rs` returns
  `PassResult::unchanged("noop")`.
- The pass record confirms `insn_count_before = 2544` and
  `insn_count_after = 2544`.
- The failing bootstrap input is therefore an identity REJIT of the original
  bytecode, not a kop-bearing rewrite.

## 3. Comparison: `balancer_ingres` vs successful ARM64 `otel` programs

Successful ARM64 comparison artifact:
`corpus/results/aws_arm64_corpus_20260506_193211_995298/details/result.json`.

The `otelcol-ebpf-profiler` `perf_unwind_*` programs all pass bootstrap
`noop` REJIT on ARM64 and continue into later passes:

- `perf_unwind_sto`: type `perf_event`, `1616` original insns, `noop` ok.
- `perf_unwind_nat`: type `perf_event`, `7152` original insns, `noop` ok.
- `perf_unwind_hot`: type `perf_event`, `6448` original insns, `noop` ok.
- `perf_unwind_per`: type `perf_event`, `7396` original insns, `noop` ok.
- `perf_unwind_php`: type `perf_event`, `6939` original insns, `noop` ok.
- `perf_unwind_pyt`: type `perf_event`, `5869` original insns, `noop` ok.
- `perf_unwind_rub`: type `perf_event`, `5178` original insns, `noop` ok.
- `perf_unwind_v8`: type `perf_event`, `7940` original insns, `noop` ok.
- `perf_unwind_bea`: type `perf_event`, `242` original insns, `noop` ok.

Important negative evidence from `otel`:

- Program size alone is not the cause. Several successful ARM64 `otel` programs
  are much larger than Katran `balancer_ingres`.
- Tail-call-helper presence alone is not the cause. Later `otel` pass records
  contain skip reasons for programs with tail-call helpers, which means those
  programs still passed bootstrap `noop` REJIT.
- ARM64 target registration and generic ARM64 REJIT plumbing are not globally
  broken. `otel` reaches `cond_select` and `prefetch` on ARM64.

Features that differ from Katran `balancer_ingres`:

- Katran `balancer_ingres` is XDP; the successful `otel` programs are
  `perf_event`.
- Katran uses XDP packet context access and `bpf_xdp_adjust_head#44`; the
  successful `otel` programs do not exercise XDP packet mutation.
- Katran `balancer_ingres` is a multi-subprogram XDP program with function
  entries at `0`, `2320`, and `2468`.
- Katran uses many load-balancer maps and packet/map update paths; the `otel`
  programs are profiler unwind programs with a different helper and context
  profile.

Katran x86 comparison:

- On x86, the same logical `balancer_ingres` program reaches pass matching:
  - `cond_select`: `7` matched and applied sites.
  - `endian_fusion`: `6` matched and applied sites.
  - `prefetch`: `42` matched and applied sites, then later REJIT fails with a
    different errno.
- This proves the Katran program is not a genuine zero-opportunity program. On
  x86 it reaches the matchers and exposes many candidate sites.

## 4. Hypothesis ranking

### 1. Multi-subprogram ARM64 REJIT/JIT failure for large XDP programs

Rank: strongest.

Evidence:

- `balancer_ingres` has three verifier functions: `func#0 @0`,
  `func#1 @2320`, and `func#2 @2468`.
- The verifier accepts the identity program, then the syscall returns
  `EOPNOTSUPP`.
- The most plausible direct return point is the post-JIT support gate at
  `kernel/bpf/syscall.c:3784`, where `tmp->jited == false` becomes
  `EOPNOTSUPP`.
- ARM64 `bpf_int_jit_compile()` can return the original non-JITed program after
  internal JIT failure without preserving a detailed errno for REJIT.
- x86 REJIT of the same program shape reaches later passes, so the bytecode and
  fd-array are not generically invalid.
- ARM64 `otel` proves that large programs and tail-call-helper programs can pass
  bootstrap `noop`, narrowing the likely trigger to Katran's XDP/multi-subprog
  shape rather than size alone.

What remains uncertain:

- The current result artifact does not capture the internal ARM64 JIT failure
  site because the JIT collapses failures into a non-JITed return. Kernel-side
  instrumentation would be needed to distinguish an exact `build_body` failure,
  image/finalization failure, or multi-function metadata failure.

### 2. XDP-specific ARM64 REJIT/JIT shape

Rank: plausible secondary cause.

Evidence:

- The failing program is XDP and uses `bpf_xdp_adjust_head#44`.
- The successful ARM64 comparison set is `perf_event`, not XDP.
- XDP programs have packet-pointer, context, and post-attach details that are
  absent from `otel`.

Counter-evidence:

- The REJIT failure occurs before the swap/refresh phase, so later
  `bpf_prog_refresh_xdp()` behavior is not the immediate cause.
- The small Katran `xdp_root` XDP program exists and does not show the same
  bootstrap failure shape, so XDP alone is not sufficient.

Most likely interpretation:

- XDP is probably part of the trigger only in combination with large
  multi-subprogram JIT state, packet access, or `xdp_adjust_head`.

### 3. Tail-call origin protection

Rank: weak for this failure.

Evidence against:

- No `bpf_tail_call#12` helper appears in the `balancer_ingres` failing verifier
  log.
- `balancer_ingres` is a tail-call target, not the origin dispatcher.
- The REJIT support check does not reject tail-call targets; syscall comments
  explicitly handle tail-call poke descriptors.
- ARM64 declares `bpf_jit_supports_subprog_tailcalls() == true`.
- Successful ARM64 `otel` programs pass bootstrap `noop` despite later pass skip
  reasons related to tail-call helpers.

Tail-call handling remains important for later optimization passes, but it does
not explain this bootstrap `noop` `EOPNOTSUPP`.

### 4. Specific helper, kfunc, kop, or atomic unsupported on ARM64

Rank: weak.

Evidence against:

- Helpers are common and expected on ARM64:
  `map_lookup_elem`, `map_update_elem`, `ktime_get_ns`,
  `get_smp_processor_id`, and `xdp_adjust_head`.
- No kfunc calls were identified.
- No kop calls exist in the bootstrap/noop input, so the ARM64
  `emit_kop_desc_call_arm64()` `-EOPNOTSUPP` path does not fit.
- No atomics were identified in the failing log.

### 5. fd-array consistency or map-layout failure

Rank: weak.

Evidence against:

- The verifier traverses the whole program and reports full processed-state
  statistics; an fd-array/map-index failure would normally surface during
  verification with a more direct verifier error.
- The observed named map set is below the REJIT fd-array cap.
- x86 can identity-REJIT the same logical program far enough to run multiple
  optimization passes.
- The daemon's REJIT wrapper passes map fds in the expected fd-array structure
  and `noop` does not introduce new map references.

## 5. Verdict

The user-visible `EOPNOTSUPP` is most likely returned by the REJIT syscall's
post-JIT support gate at:

- `vendor/linux-framework/kernel/bpf/syscall.c:3784-3786`

The important sequence is:

1. Daemon invokes `BPF_PROG_REJIT` with the original Katran `balancer_ingres`
   bytecode because `noop` is an unchanged transform.
2. REJIT verifier accepts the program. The log shows three functions and ends
   with full processed-state statistics rather than a rejection.
3. The ARM64 JIT path fails to leave the temporary program JITed.
4. `bpf_prog_rejit()` observes `!tmp->jited` and reports `-EOPNOTSUPP`.

Dominant cause:

The strongest diagnosis is an ARM64 REJIT/JIT limitation for this large
multi-subprogram XDP shape, likely in the temporary-program JIT reconstruction
path rather than in verifier feature validation. The exact internal ARM64 JIT
failure is hidden by `bpf_int_jit_compile()` returning a non-JITed program and
the syscall collapsing that condition into `EOPNOTSUPP`.

Confidence:

- High confidence on the syscall-level return point: post-verifier, post-JIT
  `syscall.c:3784`.
- Medium confidence on the precise feature trigger: large multi-subprogram XDP,
  possibly with XDP packet mutation/`xdp_adjust_head`.
- Low confidence for tail-call origin, kfunc, atomic, kop, and fd-array
  hypotheses.

## 6. Fix dimensions

No concrete patches are proposed here.

Kernel dimensions:

- Preserve or expose ARM64 JIT failure causes through the REJIT path instead of
  collapsing all non-JITed temporary programs into generic `EOPNOTSUPP`.
- Add diagnostic coverage around ARM64 `bpf_int_jit_compile()` for REJIT
  temporary programs, especially failures in `build_body`, multi-function final
  offsets, image allocation/finalization, and validation.
- Audit ARM64 identity REJIT for multi-subprogram XDP programs. The minimum
  useful reproducer should include BPF-to-BPF calls plus XDP context/packet
  access, not just a small single-function XDP program.
- Validate whether REJIT temporary programs reconstruct the same subprogram,
  `aux`, line-info, jited-function, and exception-table metadata that ARM64's
  multi-function JIT expects.
- Validate whether XDP packet mutation helpers such as `bpf_xdp_adjust_head`
  interact with ARM64 REJIT temporary JIT state.

Daemon / framework dimensions:

- Do not filter or skip these programs. A failing bootstrap `noop` is a kernel
  REJIT unsupported/error result, not zero optimization opportunity.
- Preserve raw verifier/JIT logs and syscall errno in result artifacts.
- Consider recording a diagnostic classification outside the raw counter result
  path for development runs: verifier rejected, verifier accepted but tmp not
  JITed, or swap/poke/update failed. This should not become a performance
  summary or filtering mechanism.
- Keep fd-array reconstruction fail-fast. Nothing here justifies a userspace
  fallback loader or app-level exclusion.

Paper/reporting dimensions:

- ARM64 Katran `balancer_ingres` must not be counted as "no matched sites" or
  "no optimization opportunity." Its matchers never ran.
- The paper should separate true zero-opportunity programs from programs where
  bootstrap `BPF_PROG_REJIT` is unsupported by the kernel/JIT.
- x86 evidence shows `balancer_ingres` contains optimization sites
  (`cond_select`, `endian_fusion`, and `prefetch`), so the ARM64 zero-match
  appearance is a hidden kernel-path failure.

## 7. Affected app inventory

This inventory is heuristic. It flags programs likely to be affected by the same
"bootstrap `noop` REJIT unsupported before matchers run" failure mode, not
programs proven to have no optimization opportunities.

### Katran

Status: definite for `balancer_ingres`.

- `balancer_ingres`: definite affected program on ARM64. It is a large
  multi-subprogram XDP tail-call target and fails bootstrap `noop` with
  `EOPNOTSUPP`.
- `xdp_root`: lower risk for this specific failure. It is the XDP dispatcher and
  tail-call origin, but it is small and does not show the same failure in the
  inspected Katran ARM64 run.
- `healthcheck_encap`: lower risk for this specific failure. It is `sched_cls`
  and small in the inspected run.

Paper impact:

- Katran ARM64 must be treated as partially blocked by kernel REJIT/JIT support.
  `balancer_ingres` is the main forwarder, so losing it is not a minor coverage
  issue.

### Cilium

Status: likely at risk; needs ARM64 bootstrap-noop audit.

Likely risky shapes:

- large `sched_cls` datapath programs such as host/from-netdev/to-netdev paths;
- programs with BPF-to-BPF subprograms;
- programs with tail-call dispatch or tail-call targets;
- programs with many map lookups and packet context accesses.

Reasoning:

- Cilium's datapath resembles Katran more than `otel`: large networking
  `sched_cls`/XDP-style programs, packet parsing, map-heavy policy and
  forwarding logic, and tail-call structure.
- If ARM64 REJIT's hidden failure trigger is "large multi-subprogram networking
  program," Cilium is one of the highest-risk apps after Katran.

Paper impact:

- Treat ARM64 Cilium zero-match or missing-match results with caution until
  bootstrap `noop` status is audited per program.

### Tracee

Status: moderate risk; needs ARM64 bootstrap-noop audit.

Likely risky shapes:

- large kprobe/tracing programs with BPF-to-BPF subprograms;
- programs using tail-call dispatch tables;
- cgroup/socket programs with multiple helper and map paths.

Reasoning:

- Tracee is not XDP, which weakens the exact Katran-match hypothesis.
- It can still contain large multi-subprogram probe programs and tail-call
  structures. If the true trigger is ARM64 multi-subprogram REJIT metadata rather
  than XDP-specific codegen, Tracee could be affected.

Paper impact:

- Tracee should be classified by observed bootstrap `noop` status, not inferred
  from matched-site counts alone.

### Tetragon

Status: moderate risk; needs ARM64 bootstrap-noop audit.

Likely risky shapes:

- kprobe/tracing programs with subprograms;
- tail-call based policy/event dispatch programs;
- map-heavy probe programs.

Reasoning:

- Tetragon's program type mix differs from Katran XDP, but it can share the
  "large program with subprograms/tail-call structure" risk dimension.
- If failures occur before matchers run, they could masquerade as missing
  optimization opportunities in the same way.

Paper impact:

- Any ARM64 Tetragon program with bootstrap `noop` failure should be reported as
  REJIT unsupported/error, not as zero matched sites.

### Otelcol eBPF profiler

Status: negative/control for this specific failure.

Observed successful programs:

- `perf_unwind_sto`
- `perf_unwind_nat`
- `perf_unwind_hot`
- `perf_unwind_per`
- `perf_unwind_php`
- `perf_unwind_pyt`
- `perf_unwind_rub`
- `perf_unwind_v8`
- `perf_unwind_bea`

Reasoning:

- These ARM64 `perf_event` programs pass bootstrap `noop`.
- Some are substantially larger than Katran `balancer_ingres`.
- Later pass records show tail-call-helper-related skip reasons, so tail-call
  helper presence alone does not produce the Katran `EOPNOTSUPP`.

Paper impact:

- Otel is useful as a control: ARM64 REJIT, target registration, and large
  program handling are not globally broken.
- Otel's later skipped kop sites are a separate bpfopt policy/guard issue, not
  this bootstrap `noop` kernel failure.
