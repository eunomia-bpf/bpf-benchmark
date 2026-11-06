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

The corpus target builds and boots across the six applications. Two
defects seen on the way were fixed by their owning lanes, not accepted as
boundaries:

1. **`shl esi` generator failure.** `check_definedness` raised
   `undefined native ABI register esi`, which I first read as an entry-ABI
   coverage boundary. It was a **checker bug**, fixed by lane C
   (`3c4a64711`); the corpus programs generate now.
2. **Native-arm load failure under a `kinsn` plan.** Bisected on katran
   with everything else fixed: `noop` and `dce` both measure both arms,
   `kinsn` does not, failing in libbpf's
   `bpf_object__probe_loading(): -EINVAL`. That is a pass-path defect, not
   the native loader.

### Boot blocker since ~11:00 (all corpus arms)

Every corpus arm — native and baseline — is blocked by a deterministic
module-insert failure introduced with a host-kernel rebuild:

```
insmod: ERROR: could not insert module .../bpf_x86_alu.ko: Invalid parameters
distilled base BTF type 'bpf_prog' [4], size 96 has multiple candidates
of the same size (ids [73772, 73771]) in base BTF
```

Verified as not staleness: kernel timestamp stable for 10 minutes, module
built clean (`rm -f *.ko`, `touch` sources, 15 `.ko`, `vermagic
7.0.0-rc2+ ... modversions` matching `kernel.release`), image rebuilt from
those artifacts, same failure. Two *adjacent* base-BTF `bpf_prog` records
of identical name and size means one type emitted twice, so
`pahole --btf_gen_distilled` cannot choose and module BTF validation
returns -22. `pahole -F btf -C bpf_prog` on the vmlinux shows a single
definition, so the duplication is in the distilled base rather than the
source. Fifteen modules loaded at 10:47; none since. Reported to lane T.

This is why the corpus arms below are recorded at `SAMPLES=1`
`WORKLOAD_DURATION=60` from before the regression, rather than at the
operator's recipe.

### Second build blocker: vmlinux relinked with the host compiler

`micro/programs/Makefile` uses the kernel image only as a *prerequisite*
of a generated offsets header, but because `vmlinux.o` sits beside it,
GNU make's builtin `%: %.o` rule relinks `vmlinux` with plain `cc`:

```
cc .../vendor/build/x86/linux/vmlinux.o -o .../vendor/build/x86/linux/vmlinux
/usr/bin/ld: ...vmlinux.o: relocation R_X86_64_32S against
`.rodata.str1.8' can not be used when making a PIE object
```

That fails `host-micro-programs-x86` and blocks both `make micro` and
`make corpus`. Reported; not worked around here.

### Native arm state, latest

Blockers cleared in order (each reproducible, each named with evidence):

1. module/kernel BTF mismatch — rebuilt the module against the current
   kernel and repackaged the image;
2. `vmlinux` relinked with the host `cc` because `vmlinux.o` sits beside it
   and make's builtin `%: %.o` rule applied;
3. `native-link` did not compile (`missing field readonly_objects`, twice);
4. `siphash_rotate64_mixer`: `error in backend: IO failure on output
   stream: Bad address` under concurrent load;
5. a **stale prebuilt shim/loader** shipped in the image — `host-shim-x86`
   has no prerequisites and misses the header dependency, so a header-only
   change never reaches the `.so`. Removing
   `bpfopt/shim/build-x86/libbpfrejit_shim.so` (and the two
   `runner/build-*/native_loader` dirs) before packaging fixes it, and the
   image then reports the string that proves which shim it carries.

**Current stopping point** (`corpus/results/
x86_kvm_corpus_20261106_180719_356323`): the verified arm dies at startup
with `rc=97`, and the shim log pins it to libbpf's own probe —

```
BPF_PROG_LOAD type=1 (socket_filter) name= insn_cnt=2
  hash=39f82ae52884c235
source=/tmp/bpfrejit_<pid>_39f82ae52884c235.bpf
verified native runtime has no manifest entry for prog= ...
```

`shim_native_loader.h` exempts probe programs only when the bound
requirement is **off**; commit `dd3707caf` made that deliberate ("The
verified arm binds startup probes as well as resident programs"). Under
that design the application manifest must therefore carry a probe entry,
or no application can start on the verified arm. Reported to the shim
owner with both options; the measurement is one manifest field or one
guard away.

### Work done per arm

The native arm itself is selected with

```sh
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_SHIM_NATIVE_MANIFEST=<complete-app-manifest> make corpus
```

and the verified arm adds `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`
(lane C, `bb0b9c146`). A bcc application manifest with 25 programs exists
at `corpus/results/kprog_app_coverage_20261106/bcc-real-4/manifest.json`;
the remaining apps' complete manifests are lane C's.

### Pass-list runs are bytecode reload, not native

**Correction.** Runs with `BPFREJIT_BENCH_PASSES=noop`, `dce` or `kinsn`
reload eBPF bytecode through `bpfopt` and are **not** the native arm. The
native arm is the native loader, selected with

```sh
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_SHIM_NATIVE_MANIFEST=<complete-app-manifest> make corpus
```

and the verified arm adds `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`
(lane C, `bb0b9c146`; see
`corpus/results/kprog_app_coverage_20261106/README.md`). So no
`native/eBPF` figure may be quoted from a pass-list run.

`BPFREJIT_BENCH_PASSES=noop`, `SAMPLES=1 WORKLOAD_DURATION=60`
(`corpus/results/x86_kvm_corpus_20261106_114826_062263`) does give `ok`
with both arms measured for bcc/set, cilium/agent, otelcol-ebpf-profiler
and tetragon/observer — but that is a bytecode arm, useful only as the
work-counter evidence below.

### Work done per arm (the operator's requirement)

Each application's own counters are recorded for both arms in the run
artifacts. Sampled at `noop`, 60 s:

- **bcc/set** — stress-ng bogo-ops in both arms, same four stressors
  (syscall, cap, set, sockfd): cap 16,871,329 vs 16,974,156; set
  1,286,541 vs 1,296,699; sockfd 12,788,194 vs 12,762,634.
- **cilium/agent** — forwarded vs dropped verdicts with drop reasons in
  both arms: 155,090,107 forwarded / 2 dropped (baseline) and
  177,249,149 forwarded / 4 dropped (post). Drops are
  `reason=139,direction=2` in both, so the drop class is the same and only
  the volume differs.
- **tetragon/observer** — stress-ng bogo-ops in both arms, same four
  stressors (eventfd, mmap, udp, sock): udp 6,128,968 vs 6,149,140;
  eventfd 3,776,936 vs 3,710,052; sock 20,270 vs 21,698.
- **otelcol-ebpf-profiler** — both arms measured; its workload config
  carries no counters block, so its work figures come from the profiler's
  own output rather than a `config.outcomes` map.

Cilium's volume differs by 14% between arms at `SAMPLES=1`, which is why a
rate must come from throughput over equal durations rather than from raw
counters — the counters are evidence of *which work* was done, not of the
rate.

### bcc at the operator recipe (bytecode arm)

`SAMPLES=3 WORKLOAD_DURATION=180`, `noop`
(`corpus/results/x86_kvm_corpus_20261106_125737_127074`): status `ok`,
3 workloads per arm, stress-ng totals 275,414,345 bogo-ops baseline vs
280,803,536 post, **1.020x**. This is a bytecode-arm figure.

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