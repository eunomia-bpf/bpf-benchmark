# Early native-number reproduction, 2026-11-06

Reproduces the 2026-05-29 x86 KVM results on current `master`, using the
same `make` entrypoints and the recorded knobs. Lane R (host CPUs 0-7).

Reference numbers, taken from the archived runs rather than restated:

| Quantity | Reference | Source |
| --- | ---: | --- |
| Pure-bytecode geomean, 29 programs | `1.478x` | `micro/results/x86_kvm_micro_20260529_003919_048557` |
| Helper/map geomean, 13 programs | `1.429x` | `micro/results/x86_kvm_micro_20260529_004658_667642` |
| Six-app corpus workload geomean | `1.349x` | `kprog/docs/evaluation.md`, six per-app ratios |

Ratio definition, used identically for reference and current runs: for each
benchmark, `median(exec_ns)` per runtime over that runtime's samples, then
`median(kernel) / median(native_kernel)`; the suite figure is the
unweighted geometric mean of the per-program ratios. `exec_ns` is the
in-guest `ktime`-sourced execution time, the same field the archived runs
used.

# Summary

| arm | current | reference | verdict |
| --- | ---: | ---: | --- |
| Pure bytecode (29) | **1.446x** | 1.478x | reproduces, -2.2% |
| Helper/map (13) | **1.403x** | 1.429x | reproduces, -1.8% |
| Corpus, bcc/set native | **1.002x** / 1.000x | 1.005x | reproduces |
| Corpus, other five apps | — | — | blocked on app artifacts, see below |

Both micro arms ran with recipe parity verified from the result files, and
every arm's correctness was checked by comparing return values and results
across runtimes, not by trusting the timings.

# Micro: pure bytecode (29 programs)

| Run | Suite | Programs | Geomean |
| --- | --- | ---: | ---: |
| Reference 2026-05-29 | `micro_staged_codegen` | 29 | **1.478x** |
| Current | `micro_staged_codegen` | 29 | **1.446x** |

Recipe parity, read back from both `details/result.json`: runtimes
`kernel native_kernel llvmbpf native`, `inner_repeat` 100000, 3 samples
per run — identical in both.

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 \
  SUITE=micro/config/micro_pure_jit.yaml \
  RUNTIMES='kernel native_kernel llvmbpf native' \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Artifact: `micro/results/x86_kvm_micro_20261106_090507_158145`.

Program split unchanged: 26 faster, 2 ties, 1 slower in both runs.
Correctness: 116 runtime comparisons (4 runtimes x 29 programs) agree
exactly on `(retval, result)`; zero disagreements.

Two programs sit more than 10% below their reference ratio —
`cilium_policy_guard_tree_filter` (0.61 of the reference ratio) and
`simple_packet` (0.86) — and both stay above 1.0. The direction is
preserved; no claim is made about which side moved without a paired re-run
of the 05-29 binary.

**Kernel provenance.** The 09:05 run loaded `bpf_x86_alu.ko` and printed no
kernel banner, so it ran the image already built at that time. Lane T then
rebuilt the host kernel with the native proof-region patch, so this is a
pre-patch-kernel measurement. Every later arm is labelled with its own
kernel in the artifact.

# Micro: helper/map (13 programs)

| Run | Programs | Geomean |
| --- | ---: | ---: |
| Reference 2026-05-29 | 13 | **1.429x** |
| Current | 13 | **1.403x** |

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 \
  SUITE=micro/config/micro_stage2.yaml \
  RUNTIMES='kernel native_kernel' \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Artifact: `micro/results/x86_kvm_micro_20261106_102025_639020`.

Recipe parity verified from both files: `inner_repeat` 100000, 3 samples,
runtimes `kernel native_kernel`, program name sets equal (13 names).
Correctness: 26 runtime comparisons agree exactly; zero disagreements.

# Corpus: native arm

The native arm is the **native loader**, not a pass list:

```sh
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_SHIM_NATIVE_MANIFEST=<app manifest> \
  make corpus PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=<app> \
  SAMPLES=3 WORKLOAD_DURATION=180
```

with `BPFREJIT_CORPUS_BPF_STATS=0` for the stats-off arm. Runs with
`BPFREJIT_BENCH_PASSES=noop`, `dce` or `kinsn` reload eBPF bytecode
through `bpfopt` and are **not** native; none of the numbers below come
from a pass-list run. The verified arm
(`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`) is a separate, later
measurement.

## A ratio only counts with replacements verified

The shim log is the evidence that a run was native. It records
`native-loader replaced prog=<name>` for every program actually executed
natively, and `native-loader failed prog=<name> ... error=...` for one
that passed through as eBPF. Every ratio below carries that count.

This matters: katran's first run returned `status ok` with both arms and
1.128x, but its log had **zero** replaced lines — the only program,
`balancer_ingress`, failed and passed through, so both arms ran eBPF and
1.128x was run-to-run variance.

## Manifest paths must be image paths

The corpus run executes **inside** the runtime image. Its
`/workspaces/repository/corpus` is a copy taken at image build time and
contains **no** `results/` directory, so any manifest path under
`corpus/results/...` is unreadable at run time — the loader reports
`manifest native object is unreadable`. The one staged location the image
carries is `/artifacts/user/native-bpf/x86_64/<app>/` (note `x86_64`).

Each app therefore gets a `manifest.image.json` beside its original, with
the same entries and only that prefix rewritten. `bcc-real-4` was the
first to work this way.

## bcc/set: reproduces

`bcc-real-4/manifest.image.json`, 18 programs replaced natively, 7
failed (below). Reference 1.005x.

| arm | baseline eBPF | native | native/eBPF |
| --- | ---: | ---: | ---: |
| stats on | 278,893,541 | 279,417,520 | **1.002x** |
| stats on (2nd run) | 281,747,730 | 282,144,110 | **1.001x** |
| stats off | 359,778,402 | 359,881,404 | **1.000x** |

Figures are stress-ng bogo-ops, 3 samples of 180 s per arm, same four
stressors in both arms. Artifacts:
`corpus/results/x86_kvm_corpus_20261106_190628_159160` (stats on),
`..._201524_310676` (stats on, second run), `..._204653_590159` (stats
off, `bpf_stats: false` confirmed in metadata).

bcc sits at unity in the reference too, and for the same reason: its
workload is `set`/`cap` syscalls rather than the traced path, so the BPF
program's cost is a small share of the workload. That is why the
reference's 1.005x and these 1.000-1.002x agree.

Per-stressor, both arms did the same work (one stats-on run): syscall
514/514, cap 17,126,810/17,184,093, set 1,292,235/1,309,932, sockfd
12,374,606/12,432,355.

### Programs that ran native (17)

`blk_account_io_*`, `block_rq_insert`, `block_rq_issue`,
`fentry_vfs_{creat,fsyn,open,read,writ}`, `inet_sock_set_*`,
`kprobe__cap_cap`, `sched_wakeup`, `sched_wakeup_new`, `sys_enter`,
`tcp_v4_connect`, `tcp_v6_connect`, `tracepoint__sys*`.

### Programs that stayed eBPF (8), with the log's reason

- `BPF_PROG_LOAD native_lab stub: Invalid argument` — `tracepoint__sys`,
  `kprobe__cap_cap`, `block_rq_complete` and one more.
- `proof readonly map lacks explicit symbol metadata: .rodata.n...` —
  `tcp_v4_connect`, `tcp_v6_connect`, `sys_exit`, `sched_switch`.

These pass through and do not stop the run, so the measurement is complete
with 17 of 25 programs native.

## katran: linked, now rejected by the kernel

`balancer_ingress` is katran's only program, and it has not replaced yet,
so **katran has no native number**. Its defect moved during this work,
which is progress worth recording:

| manifest | failure |
| --- | --- |
| `katran-real-10` | `simulator proof contains an unresolved map/kfunc relocation` |
| `katran-real-14` | `BPF_PROG_LOAD native_lab stub: Permission denied` |

So the proof now links and reaches the kernel; the kernel refuses it with
EPERM rather than EINVAL. The blob is `prog_type=6 blob_bytes=10243
reloc_records=90 chunks=81`, well under the 512-chunk bound, so the
refusal is not a chunk-count limit. Reported to the kernel/module owner.

## otelcol: manifest names a consolidated object that is not staged

`otel-real-2/manifest.json` names a single `otel.native.o` for all 14
objects, but the staged artifacts are per-tracer
(`custom_trace.native.o`, `dotnet_tracer.native.o`,
`go_labels.native.o`, `hotspot_tracer.native.o`, ...), so every entry
reads as unreadable. Needs one row per staged object, or a consolidated
object built. Reported to lane C, which owns app artifact packaging.

## tetragon, cilium, tracee

No complete app manifest existed at the time of writing; tetragon (62
staged native objects), cilium (0) and tracee (3) are lane C's to package.

# Blockers cleared to reach the native arm

Each was reproducible, and each is named with the evidence that cleared it.

1. **Module/kernel BTF mismatch** — `bpf_x86_alu.ko: Invalid parameters`
   with `distilled base BTF type 'bpf_prog' [4], size 96 has multiple
   candidates of the same size`. Not staleness: verified with a clean
   module rebuild (`rm -f *.ko`, `touch` sources, matching `vermagic`) and
   a fresh image. Cleared by rebuilding the module against the current
   kernel and repackaging.
2. **`vmlinux` relinked with the host `cc`** — `micro/programs/Makefile`
   uses the image only as a prerequisite of a generated header, but
   `vmlinux.o` sits beside it, so make's builtin `%: %.o` rule applies
   and the link fails on a PIE relocation.
3. **`native-link` failed to compile** — `missing field readonly_objects`
   in two `RewriteResult` constructors, twice.
4. **`siphash_rotate64_mixer`** — `error in backend: IO failure on output
   stream: Bad address` under concurrent load.
5. **Stale shim/loader in the image** — `host-shim-x86` has no
   prerequisites and misses its header dependency, so a header-only change
   never reaches the `.so` (and `runner/build-*/native_loader` had the same
   problem). Remove those before packaging; the image then reports the
   string that proves which shim it carries.
6. **libbpf's probe was fatal on the verified arm** — the exemption was
   gated on the bound requirement being off. Fixed upstream in `20aae50eb`
   after `dd3707caf` had made the gating deliberate.

# Timing requests served

## Lane F: stage2 helper/map, three runtimes

`RUNTIMES="native_kernel kernel native_proof" SAMPLES=3 WARMUPS=1
INNER_REPEAT=100000` -> RC=0,
`micro/results/x86_kvm_micro_20261106_181845_426714`. All 13 cases ran on
all three runtimes, and **return values and results agree in all 26
runtime comparisons**, so the arms did equal work.

Geomeans as computed (not as claims): `kernel/native_kernel` 1.380x,
`kernel/native_proof` 0.871x, `native_kernel/native_proof` 0.631x.
`native_proof` is the proof-verifier arm, expected to be slower than plain
native, and per-program medians sit in the single-digit-to-hundreds of
nanoseconds where `exec_ns` granularity dominates.

## Lane F: load-time

`BENCH=simple RUNTIMES='native_kernel kernel native_proof' SAMPLES=15
WARMUPS=1 INNER_REPEAT=1` -> `micro/results/
x86_kvm_micro_20261106_101146_092448`. The pure suite, so the stage2
defects do not affect it.

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
neither the ~107 ms that was patched out nor the sub-millisecond a hash
lookup implies. Recorded as measured, not as evidence the patch works.

# Not claimed

- These are the micro and corpus workload numbers as the reference runs
  defined them; the verified (generation-bound) arm is a separate later
  measurement.
- arm64 AWS (`1.056x`) is not rerun — it costs money and waits for the
  operator.
- katran, otelcol, tetragon, cilium and tracee have no native number yet,
  for the artifact reasons stated per app.