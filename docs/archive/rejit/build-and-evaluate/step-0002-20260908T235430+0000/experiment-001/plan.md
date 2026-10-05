# Experiment Plan: current-revision native performance opportunity

## Research question

- Claim ledger target: **C2: accepted programs run at native speed because the
  eBPF artifact is not executed.**
- This experiment tests a deliberately narrower uncertainty needed before the
  final C2 experiment: for the exact 29-program source population whose proof
  artifacts passed the current x86-64 verifier smoke, how large is the
  steady-state execution opportunity between the kernel eBPF JIT and the
  repository's direct-native preview path?
- The result does not establish C2 because the current native-lab module does
  not bind verifier acceptance of a proof artifact to the native bytes it
  emits. It is an upper-bound/component experiment for the binding work, not a
  substitute for the accepted-and-bound comparison.

## Paper-value admission

- Planned role: supporting.
- Largest credible result: replace the May 2026 micro preview number with a
  current-revision, source-population-matched x86-64 KVM measurement for all 29
  proof-qualified pure-bytecode programs.
- Load-bearing uncertainty: the historical 1.478x micro speedup predates the
  current generator, ABI policy, runner, kernel, and proof corpus. It may not
  describe today's implementation or exact accepted population.
- Positive result: direct native remains faster on the aggregate and defines a
  concrete performance opportunity for artifact binding to preserve.
- Contradictory result: direct native matches or loses to kernel eBPF, removing
  the claimed current micro opportunity even though functional proof smokes
  remain valid.
- Mixed result: report the aggregate and per-program distribution without
  generalizing to production applications.
- Best alternative: implement kernel-enforced artifact binding first. That is
  the decisive C2 work, but it is not a small experiment and its performance
  target should be based on the current implementation rather than a May 2026
  preview. This bounded measurement supplies that current target without
  making binding a prerequisite for all performance investigation.

## Comparison and metrics

- Baseline: `kernel`, the stock kernel eBPF JIT under `BPF_PROG_TEST_RUN`.
- Treatment/control: `native_kernel`, the trusted native-lab upper bound using
  the same benchmark source, input, program type, KVM guest, and test-run API.
- Workloads: all 29 entries in `micro/config/micro_pure_jit.yaml`, unchanged.
- Correctness: every measured sample must match its checked-in result and
  return value.
- Primary metric: per-benchmark median `native_kernel.exec_ns /
  kernel.exec_ns`; the population aggregate is its unweighted geometric mean.
  Values below 1 mean direct native is faster; speedup is the reciprocal.
- Uncertainty: report the 15 paired-by-index ratios for each benchmark and a
  bootstrap 95% confidence interval over the 29 per-benchmark median ratios.
  This post-hoc analysis is outside the benchmark framework.
- Secondary observations: win/loss count and code-size ratio. They do not veto
  a correct throughput result.

## Protocol

- Public entrypoint only: root `make micro`.
- KVM preflight:
  `BENCH=simple RUNTIMES="kernel native_kernel" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 make micro`.
- Full run:
  `RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 make micro`.
- The driver alternates the two runtime orders by sample index. Kernel CPU
  governor and VM construction remain owned by the existing Make target.
- Raw results remain under `micro/results/`; console logs are retained under
  `/workspaces/.agent-state/bpf-development/`.
- Source revision at entry:
  `e0b7d35e0ecb1127105410b2b5b637f65f9d8d1f`.

## Interpretation boundary

This experiment may update only the paper's explicitly labeled native-preview
evidence. It cannot be called verified native execution, cannot support ARM64
performance, cannot establish production-application throughput, and cannot
replace a fresh performance run after semantic or cryptographic artifact
binding is implemented.
