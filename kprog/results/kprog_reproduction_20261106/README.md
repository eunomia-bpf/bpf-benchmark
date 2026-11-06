# Early native-number reproduction, 2026-11-06

Reproduces the 2026-05-29 x86 KVM results on current `master`, using the
same `make` entrypoints and the recorded knobs. Lane R (0-7, P-cores).

Reference numbers being reproduced:

| Quantity | Reference | Source |
| --- | ---: | --- |
| Pure-bytecode geomean, 29 programs | `1.478x` | `micro/results/x86_kvm_micro_20260529_003919_048557` |
| Helper/map geomean, 13 programs | `1.429x` | `micro/results/x86_kvm_micro_20260529_004658_667642` |
| Six-app corpus workload geomean | `1.349x` | `kprog/docs/evaluation.md`, six per-app ratios |

Ratio definition, used identically for reference and current runs: for each
benchmark, `median(exec_ns)` per runtime over that runtime's samples, then
`median(kernel) / median(native_kernel)`; the suite figure is the unweighted
geometric mean of the per-program ratios. `exec_ns` is the in-guest
`ktime`-sourced execution time, the same field the archived runs used.

## Pure bytecode (29 programs)

| Run | Suite | Programs | Geomean |
| --- | --- | ---: | ---: |
| Reference 2026-05-29 | `micro_staged_codegen` | 29 | **1.478x** |
| Current 2026-11-06 | `micro_staged_codegen` | 29 | **1.446x** |

Recipe parity, read back from both `details/result.json`:

- runtimes `kernel native_kernel llvmbpf native` — identical in both;
- `inner_repeat` 100000 — identical in both;
- samples per run 3 — identical in both.

Command (current):

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 \
  SUITE=micro/config/micro_pure_jit.yaml \
  RUNTIMES='kernel native_kernel llvmbpf native' \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Artifact: `micro/results/x86_kvm_micro_20261106_090507_158145`.

**Outcome: reproduces within 2.2%.** `1.446x` against `1.478x`. The split of
programs is unchanged: 26 faster, 2 ties, 1 slower in both runs.

Correctness: 116 runtime comparisons (4 runtimes x 29 programs) agree
exactly on `(retval, result)`; zero disagreements. A native arm that were
faster but wrong would not be a reproduction.

Two programs sit more than 10% below their reference ratio —
`cilium_policy_guard_tree_filter` (0.61 of the reference ratio) and
`simple_packet` (0.86). Both remain above 1.0 in the current run, so the
direction is preserved; the shortfall is a ratio-size difference, not a
reversal. No claim is made here about which side moved without a paired
re-run of the 05-29 binary.

## Helper/map (13 programs)

**Not yet measured.** Two blockers, both external to lane R:

1. `runner/mk/build.mk:123 host-kernel-x86` failed because
   `kprog/tv/apply_kernel_patch.py` was not idempotent for
   `include/linux/bpf.h` (hunks 1 and 3 FAILED); reported to lane T, which
   fixed it (`native proof-region kernel patch already applied`, rc=0).
2. After that fix, `host-x86-sim-proofs` fails in lane C's in-flight
   generator worktree:
   `ValueError: unresolved finite indirect target at 0xf: call QWORD PTR
   [rip+0x0]`, raised from
   `kprog/x86/micro-prog/generate_micro_sim_proofs.py`. Reported to lane C.

The reference `1.429x` is confirmed from its own artifact under the same
ratio definition, so only the current-code arm is outstanding.

## Corpus (six applications)

**Not yet measured.** Same two blockers: the corpus target needs both the
host kernel and the generator. The reference `1.349x` is confirmed as the
geometric mean of the six per-app `native/eBPF` ratios recorded in
`kprog/docs/evaluation.md` (`1.005, 1.824, 2.358, 1.323, 1.102, 0.958`).

Planned measurements, following the 2026-05-29 recipe and
`corpus/results/cilium_native_lab_20261009/artifacts.mk`:

- both arms (`9f3855f6fa1c` as that file builds it, and current), once each;
- `SAMPLES=3 WORKLOAD_DURATION=180`, BPF stats on and off, plus the
  no-eBPF baseline;
- per app, the work counters, observed the way
  `cilium_native_lab_20261009` did: Cilium forwarded/dropped/received
  packets with drop reasons, OTel delivered samples and stack-delta maps,
  Tetragon and Tracee events, Katran XDP actions and received packets, BCC
  events.

arm64 AWS (`1.056x`) is deferred: it costs money and waits for the operator.

## Not claimed

- Nothing here is generation-bound path evidence; these are the micro and
  corpus workload numbers as the reference runs defined them.
- The arm64 numbers are not rerun.