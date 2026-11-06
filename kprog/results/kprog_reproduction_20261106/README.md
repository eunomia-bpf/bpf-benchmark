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

| Run | Programs | Geomean |
| --- | ---: | ---: |
| Reference 2026-05-29 | 13 | **1.429x** |
| Current 2026-11-06 | 13 | **1.403x** |

Command (current):

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 \
  SUITE=micro/config/micro_stage2.yaml \
  RUNTIMES='kernel native_kernel' \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Artifact: `micro/results/x86_kvm_micro_20261106_102025_639020`.

Recipe parity verified from both result files: `inner_repeat` 100000,
3 samples per run, runtimes `kernel native_kernel`, and the program name
sets are equal (13 names, set-identical).

**Outcome: reproduces within 1.8%** (`1.403x` against `1.429x`).
Correctness: 26 runtime comparisons (2 x 13) agree exactly on
`(retval, result)`; zero disagreements.

### Blockers cleared to get here

1. `kprog/tv/apply_kernel_patch.py` was not idempotent for
   `include/linux/bpf.h` (hunks 1 and 3 FAILED), breaking
   `host-kernel-x86`. Fixed by lane T.
2. The stage2 generator raised `unresolved finite indirect target at 0xf:
   call QWORD PTR [rip+0x0]`. Fixed by lane C.
3. `bpf_x86_alu.ko`, copied from the runtime image, failed BTF validation
   against lane T's kernel #48 (`bpf_map` size 288, duplicate candidate
   ids, `-22`). The image was rebuilt (digest `652e8b2eacf6` ->
   `fd4820b0ff6b`) and the module now inserts.
4. The native proof blob's tail chunk was rejected
   (`BPF_PROG_LOAD native_lab stub: Invalid argument`) after lane T's
   external-identity commit; fixed by lane C's follow-up
   `Resolve finite x86 control flow and call real Linux helpers`.

Note: a `chunk_alignment_bad=1` line in the loader diagnostic is a red
herring for x86 — `native_lab_binding_validate` applies the 4-byte chunk
rule only for `NATIVE_LAB_ARCH_ARM64`.

## Corpus (six applications)

**Not yet measured.** The corpus target builds the simulator proofs for the
application programs, and that build currently stops on an entry-ABI
question rather than a performance one:

```
ValueError: undefined native ABI register esi at 0x256: shl esi,0x10
```

raised from `kprog/x86/micro-prog/x86_abi.py:88` via `check_definedness`.

Diagnosis, settled against the production header rather than inferred:
`X86_SIM_ENTRY_XDP` and `X86_SIM_ENTRY_SKB` (`x86_sim_local_bpf.h:353-375`)
initialize exactly `__x86_rdi = &__x86_sim_abi` plus the stack in `rsp`.
The analyzer's seed is the same two registers, so it is an exact model of
the entry ABI and the error is correct: the program reads `esi` before
anything defines it. This is a **coverage boundary** of the modeled entry
ABI, not an analyzer bug and not something to widen silently — widening
the seed would accept a premise the simulator never establishes.

What remains is a named decision for lane C: whether that program takes a
second entry argument outside the modeled ABI, or whether its preamble is
meant to materialize `esi` from the ABI struct and does not. Either way the
corpus arm is reported with that boundary stated, not hidden.

### State reached, 2026-11-06 10:47

The corpus target builds and boots end to end
(`corpus/results/x86_kvm_corpus_20261106_104647_576649`), and the **baseline
(eBPF JIT) arm measures**: `phase_done status ok` with one workload record
for `bcc/set`. The **native arm produces nothing**:

```
BCC tool capable exited before BPF programs were tracked by shim
failed to load BPF skeleton 'capable_bpf': -22
failed to load BPF object: -22
```

`-22` is EINVAL on the app's own `BPF_PROG_LOAD` after the shim handed it
on, and `post_rejit.workloads` is empty — so this is the native-loader arm
only, not app startup and not a general corpus regression. The
`native/eBPF` ratio the reference quotes needs that arm; the baseline arm
is available today. Reported to lanes T/F.

Reference `1.349x` is confirmed as the geometric mean of the six per-app
`native/eBPF` ratios recorded in `kprog/docs/evaluation.md`
(`1.005, 1.824, 2.358, 1.323, 1.102, 0.958`).

Planned measurements once the corpus programs generate, following the
2026-05-29 recipe and `corpus/results/cilium_native_lab_20261009/
artifacts.mk`: both arms (`9f3855f6fa1c` as that file builds it, and
current), `SAMPLES=3 WORKLOAD_DURATION=180`, BPF stats on and off, plus
the no-eBPF baseline; per app the work counters observed the way
`cilium_native_lab_20261009` did — Cilium forwarded/dropped/received
packets with drop reasons, OTel delivered samples and stack-delta maps,
Tetragon and Tracee events, Katran XDP actions and received packets, BCC
events.

arm64 AWS (`1.056x`) is deferred: it costs money and waits for the
operator.

## Timing requests served

Lane F's load-time request (2026-11-06) ran to completion on the current
tree — `BENCH=simple RUNTIMES='native_kernel kernel native_proof'
SAMPLES=15 WARMUPS=1 INNER_REPEAT=1` -> `micro/results/
x86_kvm_micro_20261106_101146_092448`. It uses the pure suite, so the
stage2 chunk defect does not affect it.

`native_kernel`, median over 15 samples (min-max):

| Phase | Median (ms) | Range (ms) |
| --- | ---: | ---: |
| `native_load_ns` | 46.076 | 45.656-49.000 |
| `companion_lookup_spec_ns` | 45.240 | 44.798-48.094 |
| `companion_load_ns` | 0.326 | — |
| `companion_object_load_ns` | 0.222 | — |
| `proof_verifier_load_ns` | 0.058 | 0.053-0.065 |
| `prog_load_ns` | 0.111 | — |
| `blob_upload_ns` | 0.052 | — |
| `proof_open_ns` | 0.030 | — |

`kernel`: `object_load_ns` 0.216 ms. `native_proof`: `proof_compile_ns`
121.598 ms.

`companion_lookup_spec_ns` is 45.24 ms — 98% of the whole load — which is
neither the ~107 ms F reported patching out nor the sub-millisecond a hash
lookup implies. Reported to F; the figure is recorded as measured, not as
evidence that the patch works.

## Not claimed

- Nothing here is generation-bound path evidence; these are the micro and
  corpus workload numbers as the reference runs defined them.
- The arm64 numbers are not rerun.