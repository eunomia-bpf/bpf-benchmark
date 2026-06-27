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
