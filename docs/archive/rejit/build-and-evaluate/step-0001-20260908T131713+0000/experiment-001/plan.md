# Experiment Plan: C3 cross-architecture falsifiability

## Research Question

- RQ exactly as written in the paper: **C3: Safety transfer is falsifiable.**
- Specific uncertainty tested here: whether the current AArch64 simulator
  artifacts both execute the 29 accepted workload-derived cases correctly in
  an AArch64 guest and preserve the shared unchecked packet access strongly
  enough for that guest's stock verifier to reject it.
- Why the answer matters: the current tree has fresh AArch64 cross-build
  evidence but only historical guest execution, leaving the paper unable to
  state current cross-architecture verifier behavior.

## Paper-Value Admission

- Planned role: supporting.
- Largest credible paper story this experiment could unlock: the current
  x86-64 functional milestone extends to a second verifier/JIT architecture
  for the implemented 29-program subset.
- Strongest uncertainty addressed: AArch64 build success may hide load-time or
  verifier failures, and the negative proof may fail for a reason other than
  the intended unsafe packet access.
- Independent evidence added: a fresh AArch64 kernel boot, verifier load, and
  test-run on the exact current artifacts; prior fresh evidence stopped at
  cross-compilation.
- The result is not tautological because both target-specific generated BPF
  and the target verifier differ from x86-64.
- Paper decision if positive: report current functional cross-architecture
  coverage for this subset, without making a performance or full-fidelity
  claim.
- Paper decision if contradictory, mixed, or inconclusive: retain the raw
  failure and repair the isolated AArch64 generator/runtime defect before the
  paper can claim current two-architecture coverage.
- Best alternative: implement the artifact-binding chain. That is the next
  stronger O4 step, but it does not answer whether today's AArch64 artifacts
  actually survive their target verifier; this run is bounded and directly
  closes the already identified cross-architecture evidence gap.

## Expected And Alternative Outcomes

- Expected: all 29 positive cases match result and return value, while
  `unchecked_packet_read` fails with `invalid access to packet`.
- Competing explanation: AArch64 code generation succeeds but target load or
  execution fails, or the unsafe access disappears during translation.
- Contradiction: any positive case mismatch/load failure, unexpected negative
  acceptance, or rejection without the intended verifier diagnostic.

## Published Precedent And Real Assets

- Official system/tool: the repository's current Linux kernel, stock eBPF
  verifier, QEMU AArch64 machine, runtime image, and public Make targets.
- Reused assets: current 29-case micro corpus, generated AArch64 proof objects,
  shared negative native source, and runner correctness oracle.
- Necessary deviation: local cross-architecture QEMU is used because the
  configured `codex-ec2` AWS profile is absent. This is suitable for functional
  verifier evidence, not ARM hardware performance.

## Comparison

- Method: AArch64 generated simulator artifacts in `native_proof` mode.
- Control: the same source-level unsafe packet program used in the accepted
  x86-64 milestone; it is a rejection control, not a performance baseline.
- Correctness fairness: expected outputs and return values are unchanged from
  the checked-in corpus configuration.

## Workloads And Metrics

- Workloads: 29 checked-in workload-derived micro kernels plus the shared
  unchecked packet read.
- Primary metrics: per-case result/retval equality and the exact verifier
  rejection class for the unsafe artifact.
- Repetitions: one functional smoke execution per case; no statistical or
  performance conclusion is drawn.

## Planned Runs

| Run group | Role | Workload | System/method | Repetitions | Decision consequence |
|---|---|---|---|---:|---|
| preflight | real-path smoke | `simple` | AArch64 QEMU `native_proof` | 1 | establish guest path only |
| full | supporting | 29 positive + 1 unsafe | AArch64 QEMU selftest | 1 | current cross-architecture functional evidence |

## Execution

- Preflight: `PLATFORM=qemu ARCH=arm64 BENCH=simple RUNTIMES=native_proof SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 make micro`.
- Full run: `PLATFORM=qemu ARCH=arm64 make selftest`.
- Completion: Make exits zero, all 29 positive cases match, the unsafe case is
  rejected with `invalid access to packet`, and the guest terminates normally.
- Raw results: the normal `micro/results` and `tests/results` paths emitted by
  the public Make targets, plus captured Make console logs.
- Recovery: retain the incremental build tree and rerun only the affected Make
  target after a concrete failure repair.

## Interpretation

- Positive: current functional support for the implemented AArch64 subset.
- Negative: an implementation defect to repair; not evidence against the
  paper's overall thesis and not reader-facing paper material.
- Mixed/inconclusive: do not claim current two-architecture support.
- Target paper location: Prototype Status and Existing Evidence, without a new
  performance figure.

## Reproducibility Notes

- Source revision at entry: `17911970875578432b712f3981dc5f1ca07fdd19`.
- The Makefile owns kernel, image, QEMU, runtime, and result-path parameters.
- This plan changes no benchmark workload, launcher, metric, or acceptance
  threshold.
