# K2 and Merlin Smoke Results (2026-06-26)

This note records the minimal local smoke runs for K2 and Merlin before wiring
either optimizer into the benchmark runner. These are diagnostic/toolchain
smokes, not benchmark-grade measurements. No runner, Makefile, corpus config, or
framework code was changed.

## Environment

- Workspace: `/home/yunwei37/workspace/bpf-benchmark`
- Host toolchain:
  - `clang`: Ubuntu clang 18.1.3
  - `opt`: Ubuntu LLVM 18.1.3
  - `llc`: Ubuntu LLVM 18.1.3
  - `cmake`: 3.28.3
  - `g++`: Ubuntu 13.3.0
- Work area: `/home/yunwei37/workspace/bpf-benchmark/.cache/third-party-smoke`

## Source Revisions

- Merlin:
  - GitHub tag: `v0.01`
  - tag object: `0b53dcac7145dbbccd8bfa28613f12f243e8a7fa`
  - extracted at: `.cache/third-party-smoke/src/Merlin-0.01`
- K2:
  - GitHub repo: `smartnic/superopt`
  - tag: `sigcomm2021_sub`
  - tag object: `1fd3ae58ea6b2b3d51716aee650a65f8df63a342`
  - extracted at: `.cache/third-party-smoke/src/superopt-sigcomm2021_sub`
- K2 Z3 dependency:
  - commit: `1c7d27bdf31ca038f7beee28c41aa7dbba1407dd`
  - extracted at: `.cache/third-party-smoke/src/z3`
  - built library: `.cache/third-party-smoke/src/z3/build/libz3.so`

## Merlin Smoke

Build:

```sh
cmake -S .cache/third-party-smoke/src/Merlin-0.01 \
  -B .cache/third-party-smoke/build/merlin-v0.01-llvm18 \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_DIR=/usr/lib/llvm-18/lib/cmake/llvm
cmake --build .cache/third-party-smoke/build/merlin-v0.01-llvm18 -j4
```

Built outputs:

- `.cache/third-party-smoke/build/merlin-v0.01-llvm18/lib/libAtomicBPF.so`
- `.cache/third-party-smoke/build/merlin-v0.01-llvm18/lib/libAlignBPF.so`

Functional rewrite smoke:

```sh
opt -load-pass-plugin .cache/third-party-smoke/build/merlin-v0.01-llvm18/lib/libAtomicBPF.so \
  -passes=atomicbpf -S \
  .cache/third-party-smoke/results/merlin-xdp-atomic-g-input.ll \
  -o .cache/third-party-smoke/results/merlin-xdp-atomic-g-output.ll
llc -march=bpfel -filetype=obj \
  .cache/third-party-smoke/results/merlin-xdp-atomic-g-output.ll \
  -o .cache/third-party-smoke/results/merlin-xdp-atomic-g-output.bpf.o
```

Evidence:

- Output object: `.cache/third-party-smoke/results/merlin-xdp-atomic-g-output.bpf.o`
- `llvm-objdump -d` shows the expected atomic BPF instruction:

```text
3: db 12 00 00 00 00 00 00 lock *(u64 *)(r2 + 0x0) += r1
```

Kernel/verifier smoke with the existing developer loader:

```sh
sudo -n bpfopt/target/debug/bpfopt-loader \
  --obj .cache/third-party-smoke/results/merlin-xdp-atomic-g-output.bpf.o \
  --pass noop \
  --workdir .cache/third-party-smoke/results/merlin-xdp-loader-work-g
```

Result:

- Exit status: 0
- Loader report:
  - `.cache/third-party-smoke/results/merlin-xdp-loader-work-g/xdp_prog/report.json`
  - `insn_count_before = 6`
  - `insn_count_after = 6`
  - `pass = noop`
- Program metadata:
  - `.cache/third-party-smoke/results/merlin-xdp-loader-work-g/xdp_prog/metadata.json`
  - `name = xdp_prog`
  - `prog_type = 6`

Verdict: Merlin can be built on the current host LLVM 18 toolchain, can rewrite
LLVM IR into BPF atomic bytecode, and the resulting XDP ELF object can pass the
existing loader/verifier smoke.

## K2 Smoke

Z3 build:

```sh
python3 scripts/mk_make.py
make -C build -j4
```

K2 build:

```sh
make main_ebpf.out -j4
make z3server.out -j4
```

Built outputs:

- `.cache/third-party-smoke/src/superopt-sigcomm2021_sub/main_ebpf.out`
- `.cache/third-party-smoke/src/superopt-sigcomm2021_sub/z3server.out`
- `.cache/third-party-smoke/src/z3/build/libz3.so`

Minimal built-in eBPF smoke:

```sh
timeout 120s env LD_LIBRARY_PATH=../z3/build ./main_ebpf.out \
  --bm 0 -n 1 -k 1 \
  --path_res /home/yunwei37/workspace/bpf-benchmark/.cache/third-party-smoke/results/k2-bm0/ \
  --port 18003 --logger_level 0
```

Result:

- Exit status recorded by wrapper: 0
- Log: `.cache/third-party-smoke/results/k2-bm0.log`
- Outputs:
  - `.cache/third-party-smoke/results/k2-bm0/output0.insns`
  - `.cache/third-party-smoke/results/k2-bm0/output0.bpf_insns`
  - `.cache/third-party-smoke/results/k2-bm0/output0.desc`
- Key log evidence:
  - `Port is  18003`
  - `Best program(s):`
  - `program 0 cost: 0 3`
  - `kill the z3 solver server successfully`

Katran-like built-in eBPF/map smoke:

```sh
timeout 120s env LD_LIBRARY_PATH=../z3/build ./main_ebpf.out \
  --bm 24 -n 1 -k 1 \
  --path_res /home/yunwei37/workspace/bpf-benchmark/.cache/third-party-smoke/results/k2-bm24-katran-xdp-pktcntr/ \
  --port 18004 --logger_level 0
```

Result:

- Exit status recorded by wrapper: 0
- Log: `.cache/third-party-smoke/results/k2-bm24-katran-xdp-pktcntr.log`
- Outputs:
  - `.cache/third-party-smoke/results/k2-bm24-katran-xdp-pktcntr/output0.insns`
  - `.cache/third-party-smoke/results/k2-bm24-katran-xdp-pktcntr/output0.bpf_insns`
  - `.cache/third-party-smoke/results/k2-bm24-katran-xdp-pktcntr/output0.desc`
- Key log evidence:
  - `Port is  18004`
  - `original program's perf cost: 22`
  - `validator counters: is_equal_to: 1, throw_err: 0, prog_eq_cache: 0, solve_safety: 0, solve_eq: 1`
  - `program 0 cost: 0 22`
  - `kill the z3 solver server successfully`

Tried but not accepted by K2:

```sh
timeout 120s env LD_LIBRARY_PATH=../z3/build ./main_ebpf.out \
  --bm_from_file \
  --bytecode inputs/xdp1_kern.ins \
  --map inputs/xdp1_kern.maps \
  --desc inputs/xdp1_kern.desc \
  -n 1 -k 1 \
  --path_res /home/yunwei37/workspace/bpf-benchmark/.cache/third-party-smoke/results/k2-xdp1/ \
  --port 18002 --logger_level 0
```

Result:

- Exit status recorded by wrapper: 134
- Log: `.cache/third-party-smoke/results/k2-xdp1.log`
- K2 printed the input program, then aborted with:

```text
ERROR: the original program is illegal. error!!!
terminate called after throwing an instance of 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >'
```

Interpretation: K2 itself builds and runs. Its checked-in file-input example is
not a reliable smoke on this host/toolchain, but the built-in eBPF and Katran-like
eBPF/map paths both complete and produce candidate bytecode outputs.

## Simplest Benchmark Integration Path

The simplest path remains artifact replacement, not runner rewiring:

1. Keep the benchmark runner unchanged and continue invoking suites only through
   `make <target>`.
2. Add an external pre-benchmark artifact preparation step that builds a
   candidate application/BPF object using K2 or Merlin.
3. Feed the candidate object into the real upstream app image/artifact path, then
   run the normal app-level benchmark startup.
4. Keep all performance interpretation outside the framework; `result.json`
   should stay raw-counter-only.

For Merlin, the smoke shows the natural adapter boundary: source/IR-level pass
before producing the final `.bpf.o`.

For K2, the smoke shows a larger adapter gap: K2 emits raw eBPF instruction
streams (`.insns` / `.bpf_insns`), not a complete ELF object with BTF, maps,
sections, relocations, and app loader metadata. A benchmark-grade K2 path needs
an offline object reconstruction or source-level artifact flow before the real
app starts. Do not put this reconstruction in the benchmark framework runner.

## Verdict

- Merlin smoke: pass.
- K2 build smoke: pass.
- K2 built-in eBPF smoke: pass.
- K2 Katran-like built-in eBPF/map smoke: pass.
- K2 checked-in file-input `xdp1_kern` smoke: blocked by K2's own legality
  check, recorded as diagnostic evidence.
- Benchmark-grade status: not yet. The next step is to prepare one real app
  artifact outside the runner, then run a tiny `make corpus` subset with normal
  app startup.

## 2026-06-27 Follow-up: Load-Time Compatibility Runs

After the tool smokes above, load-time compatibility adapters were exercised
through the normal KVM corpus entrypoint. These runs are useful raw datasets for
checking benchmark plumbing and workload parity. They are not evidence of K2 or
Merlin optimization speedup because neither run changed bytecode.

K2 full 6-app run:

- Command: `BPFREJIT_BENCH_PASSES="k2" SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 BPFREJIT_K2_NITER=1 BPFREJIT_K2_TIMEOUT=1 KEEP_WORKDIRS=1 make corpus`
- Artifact: `corpus/results/x86_kvm_corpus_20260627_055138_934572`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Changed bytecode outputs: 0

Merlin full 6-app run:

- Command: `BPFREJIT_BENCH_PASSES="merlin" SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Artifact: `corpus/results/x86_kvm_corpus_20260627_061142_094340`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Changed bytecode outputs: 0

Interpretation: the benchmark harness can now drive K2 and Merlin through
baseline/post app lifecycles without app-level failures. Real optimizer
performance still requires a non-load-time integration path that produces
changed app BPF artifacts before the app starts.

Path-fix validation after switching pass configs to
`${BPFREJIT_REPO_ROOT}/runner/config/passes/...`:

- K2 `bcc/set`: `corpus/results/x86_kvm_corpus_20260627_063123_950147`,
  metadata `completed`, app `ok`, 77 load-time reports.
- Merlin `bcc/set`: `corpus/results/x86_kvm_corpus_20260627_063958_892569`,
  metadata `completed`, app `ok`, 77 load-time reports.

## 2026-06-27 Follow-up: K2 Safety Fix and Full Dataset

A later Cilium-focused K2 run failed because K2 rewrote a large-program feature
probe made of repeated return-value filler instructions into verifier-invalid
context access:

- Failed artifact: `corpus/results/x86_kvm_corpus_20260627_071606_708070`
- Verifier symptom: `invalid bpf_context access off=2 size=8`
- App symptom: Cilium post phase failed `requirements failed: Require support
  for large programs`

The adapter was tightened to leave return-filler probes unchanged and to reject
non-ALU/MOV memory or control-flow changes outside the selected K2 windows. A
focused Cilium smoke then passed:

- Artifact: `corpus/results/x86_kvm_corpus_20260627_072933_922059`
- Metadata status: `completed`
- App status: `ok`
- Load-time reports: 169
- Applied/changed outputs: 0/0

The current K2 full 6-app compatibility dataset is:

- Command: `BPFREJIT_BENCH_PASSES="k2" SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 BPFREJIT_K2_NITER=200 BPFREJIT_K2_TIMEOUT=45 KEEP_WORKDIRS=1 make corpus`
- Artifact: `corpus/results/x86_kvm_corpus_20260627_073705_300047`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Applied/changed outputs: 0/0
- External post-hoc retained-program geomean ratio: 0.983758 over 43 matched
  programs.

Interpretation: K2 now works as a benchmark-compatible load-time compatibility
adapter across the full corpus, but it still produces no safe changed bytecode
on this corpus. The performance number above is therefore no-op/plumbing data,
not K2 optimizer speedup.

## 2026-06-27 Follow-up: Merlin Katran Artifact and 6-App Dataset

Merlin v0.01 is an LLVM IR optimizer, so the load-time adapter cannot generally
transform arbitrary raw `struct bpf_insn[]` input. For one real app path, a
host-prepared artifact was built from Katran's real `balancer.c` BPF source by
running Merlin before BPF code generation, then converting the resulting object
section layout back to the runtime raw instruction order used by the app loader.

Prepared artifacts:

- `atomic`: `runner/config/passes/merlin/artifacts/katran_balancer_ingress_atomic.bin`,
  SHA-256 `fbc0a4b9062aa37cd00a74b02805b5d4c2c6fe4ab6ccd68e20db959de532f008`
- `align`: `runner/config/passes/merlin/artifacts/katran_balancer_ingress_align.bin`,
  SHA-256 `d2eb1c90f985a51a9b5ecf875ba02c2d380361f05feb0b91cfe35cd4301e95a4`
- `both`: `runner/config/passes/merlin/artifacts/katran_balancer_ingress_both.bin`,
  SHA-256 `2d50cac4c0c8f6cc7daf9be03cb0405664b2c97a843ac33df8c8a36313004e3a`

Katran-only mode smokes:

- `MERLIN_ARTIFACT_MODE=atomic`: `corpus/results/x86_kvm_corpus_20260627_081509_080144`,
  app `ok`, `balancer_ingres` changed 2542 -> 2496 insns, post/base ratio
  1.04244.
- `MERLIN_ARTIFACT_MODE=align`: `corpus/results/x86_kvm_corpus_20260627_082447_495747`,
  app `ok`, `balancer_ingres` changed 2542 -> 2543 insns, post/base ratio
  1.000106.
- `MERLIN_ARTIFACT_MODE=both`: `corpus/results/x86_kvm_corpus_20260627_083226_669233`,
  app `ok`, `balancer_ingres` changed 2542 -> 2497 insns, post/base ratio
  1.015827.

The full 6-app Merlin changed-bytecode dataset uses the least harmful artifact
mode, `align`:

- Command: `BPFREJIT_BENCH_PASSES="merlin" MERLIN_ARTIFACT_MODE=align SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Artifact: `corpus/results/x86_kvm_corpus_20260627_083921_948067`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Applied/changed outputs: 1/1
- Applied program: Katran `balancer_ingres` (`xdp`), input SHA-256
  `1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e`,
  output SHA-256
  `d2eb1c90f985a51a9b5ecf875ba02c2d380361f05feb0b91cfe35cd4301e95a4`,
  2542 -> 2543 insns.

External post-hoc performance calculation matched unambiguous `(app, name,
type)` program groups and retained programs with
`min(baseline_runs, post_runs) >= 100`. It retained 48 programs. The post/base
per-program geomean ratio was 1.037160, with 25 ratios below 1.0 and 23 above
1.0. The single changed program, Katran `balancer_ingres`, had:

- baseline: 12,324,851 runs, 2,103,854,301 ns, 170.700181 ns/run
- post: 12,198,320 runs, 2,065,691,926 ns, 169.342330 ns/run
- post/base ratio: 0.992045, about 0.8% faster

Interpretation: Merlin now has a real changed-bytecode 6-app corpus dataset
through the standard benchmark entrypoint. Its measured benefit is currently
limited to one Katran XDP program; the full-suite geomean is dominated by
unchanged programs and workload noise, so report the changed-program result and
the 6-app provenance separately.

## 2026-06-27 Follow-up: Merlin Compile-Time Source/IR Path

The cleaner Merlin boundary is source/LLVM IR compilation, not load-time raw
bytecode replacement. A Katran compile-time path was added to the vendor build:

```sh
clang-18 -emit-llvm -c -g ... -o input.bc
opt-18 -load-pass-plugin libAlignBPF.so -passes=alignbpf input.bc -o align.bc
llc-18 -march=bpf -filetype=obj align.bc -o balancer.bpf.o
```

The real Katran app binary and app-owned loader remain unchanged. The public
benchmark entrypoint remains `make corpus`.

Commands:

```sh
MERLIN_COMPILETIME_MODE=none \
BPFREJIT_CORPUS_APPS="katran" \
BPFREJIT_BENCH_PASSES="noop" \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

```sh
MERLIN_COMPILETIME_MODE=align \
BPFREJIT_CORPUS_APPS="katran" \
BPFREJIT_BENCH_PASSES="noop" \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

Results:

- Baseline artifact:
  `corpus/results/x86_kvm_corpus_20260627_092713_638052`
- Align artifact:
  `corpus/results/x86_kvm_corpus_20260627_093432_232197`
- Metadata/app status: both `completed`, Katran app `ok`
- Compile evidence: Docker runtime image copied
  `vendor/build/x86/katran/bpf/*.bpf.o`; align build invoked
  `opt-18 -load-pass-plugin ... libAlignBPF.so -passes=alignbpf`.
- Object evidence: `balancer.bpf.o` `xdp` section changed from 18,544 bytes
  to 18,552 bytes.

External post-hoc counter comparison:

- `baseline` phase: 176.195296 ns/run (`none`) vs 169.499633 ns/run (`align`),
  ratio 0.961999, about 3.95% faster.
- `post_rejit`/`noop` phase: 175.024515 ns/run (`none`) vs 167.939250 ns/run
  (`align`), ratio 0.959518, about 4.22% faster.
- Workload pktgen total pps moved in the same direction: +3.65% in baseline
  phase and +4.31% in post/noop phase.

Interpretation: this is the current fair Merlin result for Katran because the
only intended treatment difference is the compile-time LLVM IR pass. It should
supersede the load-time artifact result for Merlin performance discussion on
Katran, while the older artifact run remains useful provenance.
