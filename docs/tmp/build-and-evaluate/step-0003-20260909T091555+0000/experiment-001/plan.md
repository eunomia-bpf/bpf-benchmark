# Experiment Plan: proof-bound native execution

## Research question

- Claim-ledger target: **C2: an accepted proof and the native payload that
  executes are one immutable load snapshot.**
- This step asks whether the existing 29-program x86-64 micro population can
  load and execute after replacing the native-lab module's unrelated trivial
  proof with the generated simulator proof, while binding proof and native
  chunks to one module-slot generation.
- It also measures the execution opportunity and loading cost after that
  binding. It does not prove that the generator's native output refines the
  generated eBPF simulator, nor does it establish production-application or
  ARM-hardware performance.

## Implementation under test

- The runner first loads each simulator proof object through the stock kernel
  verifier, then supplies its instructions to `libnativeloader`.
- Each native chunk and its proof are uploaded into one native-lab slot. Every
  slot mutation advances a nonzero generation. The KOP sidecar carries the
  slot id, ABI mask, and generation; both proof instantiation and native
  emission reject a stale generation.
- For a multi-chunk native blob, leading chunks carry the verifier-safe
  continuation `r0 = 0` and the final chunk carries the verifier-visible
  simulator body. Placing the CFG last lets redirected proof exits reach the
  stub's real exit without traversing another KOP. The kernel verifier now
  allocates KOP proof scratch space from the operation's declared maximum
  instead of the former 256-instruction fixed buffer.
- Native program exits are represented inside a KOP proof region as direct
  jumps to the instruction immediately after that region. This preserves
  multi-exit and loop-shaped CFGs without allowing an actual `BPF_EXIT` inside
  a proof sequence; no-call and no-nested-KOP restrictions remain explicit.
- Generations fail closed at counter exhaustion instead of wrapping to an old
  value, preventing an ABA match after repeated slot mutations.

## Comparison and metrics

- Baseline: `kernel`, the stock kernel eBPF JIT under `BPF_PROG_TEST_RUN`.
- Treatment: `native_kernel`, using the proof-bound native-lab path described
  above on the same source, input, program type, guest, and test-run API.
- Workloads: the unchanged 29 entries in
  `micro/config/micro_pure_jit.yaml`.
- Correctness: preserve every raw result and return value and compare them to
  the checked-in expectations.
- Primary performance metric: the unweighted geometric mean across programs
  of each program's median `native_kernel.exec_ns / kernel.exec_ns`; below one
  is faster and the reported speedup is its reciprocal.
- Secondary measurements: per-program ratios, code-size ratio, and raw load
  phases including proof verifier load. Loading is reported separately from
  steady-state execution.

## Public-Make protocol

- Entry revision before the implementation: `d43a4d631c56ef43998824c879f799abee6c5e74`.
- Functional smoke:
  `RUNTIMES=native_kernel BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 TIMEOUT=7200 make micro`.
- Repeated comparison:
  `RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 TIMEOUT=7200 make micro`.
- The repeated parameters match the immediately preceding trusted-native
  opportunity run so the effect of adding binding can be compared without
  changing the workload or sample protocol. Analysis remains post-hoc and
  outside framework code.

## Preflight record

- Attempt 1 stopped before VM launch when the retained Workspace's Go 1.27.1
  activated an upstream Cilium build constraint incompatible with its vendored
  gRPC. The project devcontainer already pins Go 1.26.8.
- Attempt 2 stopped before VM launch because the retained Workspace PATH did
  not expose the installed `clang-18` as `clang`.
- Attempt 3 passed the host micro build but stopped before VM launch because
  `llvm-readelf` was likewise absent from PATH during proof generation.
- The checked-in devcontainer already prepends `/usr/lib/llvm-18/bin`, which
  supplies these unversioned tool names. Re-entering with the equivalent PATH
  and pinned Go completed the public functional smoke at
  `micro/results/x86_kvm_micro_20260909_091436_290449/metadata.json`: status
  `completed`, one matching result/return-value pair, and a nonzero
  `proof_verifier_load_ns` phase.
- The first 29-program repeated attempt is retained at
  `micro/results/x86_kvm_micro_20260909_094215_341511/metadata.json`. It
  attempted every benchmark but exited with errors in eleven `native_kernel`
  runs: ten otherwise accepted large proofs exhausted the loader's 16-MiB
  level-2 verifier log, while Katran exposed the invalid assumption that a
  loop-shaped proof object must end in `BPF_EXIT`. A one-program reproducer at
  `micro/results/x86_kvm_micro_20260909_101556_226850/metadata.json` preserves
  the decisive `BPF_PROG_LOAD ... No space left on device` errno. These are
  failed implementation runs, not performance samples. The repair rewrites
  every proof exit to the region boundary before upload and performs the
  ordinary load without verifier tracing; only a failed load is retried with
  a bounded diagnostic log. This avoids turning an otherwise acceptable
  loop-heavy proof into `ENOSPC` merely by requesting its full verifier trace.
- A corrected repeated attempt was deliberately interrupted after its second
  multi-chunk failure; its partial raw directory is
  `micro/results/x86_kvm_micro_20260909_104608_695915/`. It showed that putting
  the full loop-shaped proof on the first native chunk made all proof exits
  continue into another KOP and caused verifier-state/log expansion. Moving
  the full proof to the final chunk removed that expansion. The next focused
  Make reproducer,
  `micro/results/x86_kvm_micro_20260909_111713_283313/metadata.json`, then
  exposed a separate 146-byte verifier error: the leading continuation used
  `r0 = r0` before `r0` was initialized (`R0 !read_ok`). It is also retained
  as a failed implementation run. The continuation is now `r0 = 0`.
- A second focused reproducer at
  `micro/results/x86_kvm_micro_20260909_114315_763230/metadata.json` confirmed
  that the initialized continuation removed `R0 !read_ok`, but the successful
  proof path still filled the requested verifier log. The loader now makes a
  silent primary `BPF_PROG_LOAD` and requests a bounded log only after a real
  primary failure, preserving the primary errno even if diagnostic logging
  itself reaches `ENOSPC`.

## Interpretation boundary

A successful run establishes verifier acceptance and execution with a
generation-consistent proof/native snapshot in this test module. The trusted
generator, native-link transformation, and architecture simulator remain in
the trusted computing base until a refinement proof connects their emitted
native payload to the verifier-visible proof. The result therefore advances
artifact binding but is not a complete verified compiler theorem.

## Completed result

The final public repeated command exited zero and wrote
`micro/results/x86_kvm_micro_20260909_121208_577260/metadata.json`. Strict
post-hoc validation accepted all 29 programs, all 870 result/return-value
pairs, and proof/load phases for all 435 native samples. The geometric mean of
per-program median native/kernel execution-time ratios is `0.6824347261`
(`1.4653416096x` reciprocal), with 26 wins, two ties, one loss, and a
program-population bootstrap interval of `[0.6135276985, 0.7592106567]`.

The load-ratio geometric mean is `54.5205457812x`. Separately, the medians of
the 29 per-program median load times are 116.192 ms native and 1.869 ms kernel;
the proof verifier phase median is 2.529 ms. `analysis.json` and
`result-review.md` contain the complete post-hoc output, failure history, and
claim boundary.

## ARM64 cross-ISA functional result

The same generation-bound path was then exercised through the unchanged
public Make entrypoint with
`PLATFORM=qemu ARCH=arm64 RUNTIMES=native_kernel SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 TIMEOUT=7200 make micro`.
Two failed attempts are retained rather than promoted to results. The first,
`micro/results/arm64_qemu_micro_19700101_000021_338346/`, used a stale
incremental Image and exposed the former fixed 256-instruction verifier proof
buffer. The second,
`micro/results/arm64_qemu_micro_19700101_000022_284039/`, used the rebuilt
proof buffer but exposed a separate ARM JIT defect: a fixed 64-instruction
emit scratch rejected the native-lab descriptor's 16-KiB bound and surfaced
as errno 524. Both runs were stopped after repeated same-cause failures.

The ARM JIT now allocates its emit scratch from the descriptor's bounded
`max_emit_bytes` value and frees it on every return path. After rebuilding the
kernel, the final public command exited zero and wrote
`micro/results/arm64_qemu_micro_19700101_000024_077043/metadata.json`.
Independent JSON validation found status `completed`, exactly 29 programs and
29 native samples, 29 matching results, 29 matching return values, and proof
open/verifier-load phases in all 29 samples. The guest powered down normally.
This closes functional generation-bound execution for the implemented ARM64
subset under full-system QEMU. The guest clock remains at 1970 and QEMU TCG is
not ARM hardware, so none of its compile or execution timings are performance
evidence.
