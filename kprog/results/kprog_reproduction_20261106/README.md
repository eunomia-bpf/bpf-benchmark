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

### Kernel provenance of this arm

The 09:05 run loaded `bpf_x86_alu.ko` successfully and did not print a
kernel banner, so it ran the image the runner had already built at that
time. Lane T then rebuilt the host kernel (kernel #48, 09:23) with the
native proof-region patch, and from 09:23 the same `insmod` fails BTF
validation (`distilled base BTF type 'bpf_map' [4], size 288 has multiple
candidates of the same size (ids [72830, 72829])`; `failed to validate
module [bpf_x86_alu] BTF: -22`). The 1.446x figure is therefore a
pre-patch-kernel measurement. The kernel is a shared build owned by lane T;
the failure is reported there and no re-run is claimed until it boots with
the module.

## Helper/map (13 programs)

**Partially measured.** Two external blockers were hit and cleared — a
non-idempotent kernel patch (lane T) and a generator failure on an
unresolved finite indirect call (lane C) — plus a third that needed an
image rebuild: `bpf_x86_alu.ko` copied from the runtime image failed BTF
validation against T's kernel #48 (`bpf_map` size 288, duplicate candidate
ids). `make x86-runner-runtime-image-tar` was rebuilt (digest
`652e8b2eacf6` -> `fd4820b0ff6b`) and the module now inserts.

The suite then ran and aborted after 2 of 13 programs on a **chunk
alignment** defect in the native proof blob, reported to lane T:

```
native_blob_diag: ... chunk_bytes=0:128,128:19
  chunk_alignment_bad=1 first_unaligned_chunk=1
  final_chunk_end=147 final_size_matches=1
stub_load_error_summary=BPF_PROG_LOAD native_lab stub: Invalid argument
```

The second chunk is 19 bytes, not a multiple of 8, so the kernel rejects
the proof region. The two programs that did complete give `1.143x` on a
single pair — far too small a sample to report as the suite figure, and
recorded here only as the partial state.

The program set is confirmed identical to the reference run (13 names,
equal sets), so the suite is comparable once the chunker pads the tail.

Reference `1.429x` is confirmed from its own artifact under the same ratio
definition; only the current-code arm is outstanding.

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