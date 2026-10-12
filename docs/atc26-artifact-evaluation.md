# BPF-Ext / Kinsn: ATC '26 artifact

This is the artifact guide for *BPF-Ext: Safely Extending the eBPF Compilation
Pipeline with Native Operations* (ACM ATC '26, November 16–18, 2026, Hong Kong;
Yusheng Zheng, Zhengjie Ji, Weichen Tao, Hao Sun, Wei Zhang, Dan Williams, Andi
Quinn).

The detailed record of the artifact-evaluation round (claim-by-claim evidence,
reruns, packaging) is kept in
[`archive/atc26-artifact-evaluation-ae-round.md`](archive/atc26-artifact-evaluation-ae-round.md).

## 1. What is where

| Paper part | Location |
| --- | --- |
| BPF-Ext kernel support: proof-sequence lowering and restore in the verifier, x86-64 and arm64 JIT emission | `vendor/linux-framework`: [`eunomia-bpf/linux`](https://github.com/eunomia-bpf/linux), branch `kinsn-only` |
| Kinsn operations | [`kinsn/module/x86/`](../kinsn/module/x86/), [`kinsn/module/arm64/`](../kinsn/module/arm64/) |
| Lean 4 proofs that each operation's native code computes the same result as its proof sequence | [`kinsn/lean/`](../kinsn/lean/README.md) |
| Compile-time recognizer and load-time optimizer | `llvm-backend/llvm` ([`eunomia-bpf/bpf-kinsn-llvm`](https://github.com/eunomia-bpf/bpf-kinsn-llvm)), [`bpfopt/`](../bpfopt/) |
| Microbenchmarks: 27 programs, 12 modeled on production programs and 15 synthetic, plus the `simple` and `simple_packet` baselines | [`micro/programs/`](../micro/programs/) |
| Benchmark harness for microbenchmarks and applications | [`Makefile`](../Makefile), [`runner/`](../runner/), [`micro/`](../micro/), [`corpus/`](../corpus/) |
| The paper's data, numbers and figures, regenerated without a VM | [`kinsn/paper/atc26/`](../kinsn/paper/atc26/README.md) |

`kprog/` is a separate project (whole-program native execution) with its own
Lean proofs in `kprog/formal/`; it is not needed for this paper.

## 2. Environment

The paper's x86-64 experiments run in a KVM guest with 8 vCPUs and 64 GB RAM on
an Intel Core Ultra 9 285K host, using the in-repo Linux `7.0.0-rc2+` kernel
(`vendor/linux-framework`) under `virtme-ng`. The ARM64 experiments run on an
AWS `t4g.small` instance (2 vCPUs, 2 GiB, Graviton2) with the same kernel.

| Tool | Version used |
| --- | --- |
| OS | Ubuntu 24.04, x86-64 |
| clang / llc | 18.1.3 |
| gcc, aarch64-linux-gnu-gcc | 13.3.0 |
| cmake | 3.28.3 |
| Python | 3.12 with PyYAML |
| Rust / Cargo | 1.98.1 |
| Go | 1.26.8 |
| virtme-ng (`vng`), QEMU | 1.41, 8.2.2 |
| Docker | 29.8.0 |
| Lean | `leanprover/lean4:v4.28.0` with Mathlib (pinned in `kinsn/lean/lean-toolchain`) |

The tracked `.devcontainer/Dockerfile` provides this build environment.

| Step | Time | Disk |
| --- | --- | --- |
| Checks without a VM (§4) | minutes; the first Lean build with the Mathlib cache takes tens of minutes | a few GB |
| First kernel and runtime-image build | 1.5–3 hours | 25–40 GB |
| One application run after the build | a few minutes | — |
| Full microbenchmark and application suites, both architectures | more than a day; ARM64 needs AWS | ~60 GB |

## 3. Get the artifact

```bash
git clone https://github.com/eunomia-bpf/bpf-benchmark.git
cd bpf-benchmark
git submodule update --init --recursive -- \
    vendor/linux-framework llvm-backend/llvm vendor/libbpf vendor/llvmbpf \
    vendor/repos/bcc vendor/repos/bpftrace vendor/repos/cilium \
    vendor/repos/cilium-ebpf vendor/repos/katran \
    vendor/repos/opentelemetry-ebpf-profiler vendor/repos/tetragon \
    vendor/repos/tracee
pip install pyyaml
```

Initialize only these submodules. Do not run a bare
`git submodule update --init --recursive`: four submodules (`docs/paper`,
`docs/kprog-simulator-in-ebpf`, `docs/speculative-optimization`,
`vendor/academic-writing-skills`) are private author repositories that fail to
fetch without access, and nothing in this guide needs them.

Archived versions are on Zenodo
([concept DOI 10.5281/zenodo.22907396](https://doi.org/10.5281/zenodo.22907396)).

## 4. Checks without a VM

```bash
# The Lean proofs (needs elan, which installs the pinned toolchain).
(cd kinsn/lean && lake exe cache get && lake build)

# The paper's numbers, tables and figures from the shipped raw data
# (Python 3.11+, the packages in kinsn/paper/atc26/requirements.txt, pdflatex).
make -C kinsn/paper/atc26

# Syntax checks of the harness.
make lint
```

The Lean build fails if any proof uses `sorry` or an axiom beyond `propext`,
`Classical.choice` and `Quot.sound`; [`kinsn/lean/README.md`](../kinsn/lean/README.md)
lists what is proved. [`kinsn/paper/atc26/README.md`](../kinsn/paper/atc26/README.md)
describes the bundle and its outputs.

## 5. Runs on a KVM host

The runs build an in-repo kernel, load real eBPF programs and use KVM, Docker
and `sudo -n`. Use a disposable machine or VM; the build does not modify the
running kernel but writes tens of GB under `vendor/build/` and `.cache/`. The
root `Makefile` is the only supported entry point.

```bash
make check                                   # builds the runtime image and runs the tests

# Smallest end-to-end run: one application, one sample.
BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3000 make corpus

# All six applications.
SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=7200 make corpus
```

A corpus run starts the real application, intercepts its `BPF_PROG_LOAD` calls,
applies the configured passes (including `kinsn`), loads the result through the
application's normal path, and measures the workload before and after. Results
are written to `corpus/results/<arch>_<platform>_corpus_<timestamp>/` and
`micro/results/`; the per-program fields `run_cnt_delta` and
`run_time_ns_delta` give the BPF cost, and `details/loadtime-reports/` lists the
rewritten sites. The harness records raw counters only; ratios are computed by
analysis scripts.

Expected messages: `verifier probe rejected candidate after step <pass>` means
a rewritten candidate was rejected and the original program was loaded instead.
`loadtime optimization failed` means an optimizer step failed; the load then
fails on purpose rather than silently falling back.

## 6. The paper's results, their data and commands

The data directories below are under `micro/results/` and `corpus/results/`;
copies of all except RQ4 are in `kinsn/paper/atc26/data/`. Run with statistics
off for throughput and with `BPFREJIT_CORPUS_BPF_STATS=1` for BPF cost.

| Result | Paper | Command | Data |
| --- | --- | --- | --- |
| RQ1 x86-64 microbenchmarks | 1.242× speedup (27 programs), code size 0.772× | `make micro SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000` | `x86_kvm_micro_20260519_114214_364050` (Kinsn), `x86_kvm_micro_20260526_210351_224315` (eBPF JIT) |
| RQ1 ARM64 microbenchmarks | 1.222× speedup, 308 sites, code size 0.879× | `PLATFORM=aws ARCH=arm64 make micro` | `aws_arm64_micro_20260606_001225_821028` |
| Load time | 0.99× over 62 microbenchmarks | — | `x86_kvm_micro_20260514_031744_210343`, `x86_kvm_micro_20260514_181806_133778` |
| RQ2 Cilium, x86-64, every Kinsn operation | 1.074× throughput, 4086 sites | `BPFREJIT_BENCH_PASSES=kinsn_all_prefetch BPFREJIT_CORPUS_APPS=cilium/agent SAMPLES=3 WORKLOAD_DURATION=180 make corpus` | `x86_kvm_corpus_20260604_100557_313063` (throughput), `x86_kvm_corpus_20260604_070210_639497` (BPF cost 1.010×) |
| RQ2 Katran, ARM64, rotate, bit extract and conditional select | 1.065× throughput, 21 sites | `PLATFORM=aws ARCH=arm64 BPFREJIT_BENCH_PASSES=kinsn BPFREJIT_CORPUS_APPS=katran SAMPLES=3 WORKLOAD_DURATION=30 make corpus` | `aws_arm64_corpus_20260605_080836_924256` (BPF cost 0.941×) |
| RQ3 Cilium without bulk copy | 1.119× throughput, 3512 sites, BPF cost 1.062× | `BPFREJIT_BENCH_PASSES=kinsn_all_no_bulk_prefetch BPFREJIT_CORPUS_APPS=cilium/agent SAMPLES=3 WORKLOAD_DURATION=180 make corpus` | `x86_kvm_corpus_20260605_004607_636479`, `x86_kvm_corpus_20260604_232313_992341` |
| RQ3 Katran, every ARM64 operation | 0.984× throughput, 62 sites, BPF cost 1.006× | `PLATFORM=aws ARCH=arm64 BPFREJIT_BENCH_PASSES=rotate,extract,endian_fusion,bulk_memory,prefetch,cond_select,ccmp BPFREJIT_CORPUS_APPS=katran SAMPLES=3 WORKLOAD_DURATION=30 make corpus` | `aws_arm64_corpus_20260605_094729_221231` |
| RQ4 Cilium whole-program native | 1.194× throughput (median of six fresh guests); 659.2 → 463.9 ns per BPF run | per guest: `BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_SHIM_NATIVE_LOADER=post VM_CPUS=8 VM_MEM=64G VM_CPU_PIN=0-7 SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=60 make corpus` | [`cilium_x86_config_parity_counterbalanced_20261010/`](../corpus/results/cilium_x86_config_parity_counterbalanced_20261010/SUMMARY.md) (`guests.csv`, `analysis.json`); profile in `cilium_profile_jit_kprog_counterbalanced_20261010/` |
| Proofs | native code = proof sequence for every operation | `(cd kinsn/lean && lake exe cache get && lake build)` | `kinsn/lean/` |

RQ4 places native in the second start of each guest with
`BPFREJIT_SHIM_NATIVE_LOADER=post` and in the first with
`BPFREJIT_SHIM_NATIVE_LOADER=baseline`; its `SUMMARY.md` gives the full method.

Application throughput varies between runs on the same host: the paper reports
medians and, for RQ4, a JIT-to-JIT control in each guest.
