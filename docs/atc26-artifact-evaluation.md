# BPF-Ext / KOperation — ATC 2026 Artifact Evaluation Guide

This document is the **artifact "read me"** for the accepted ATC 2026 paper
*"BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native
Operations"*. The current supporting LaTeX source is `docs/paper/main.tex`;
see the metadata caveat below. Follow this evaluator-facing guide in order.

- Current supporting paper source: [`docs/paper/main.tex`](../docs/paper/main.tex)
- Repository root: [`README.md`](../README.md)
- Paper metadata authority: **accepted paper #1160** (see
  [Paper metadata](#1-paper-metadata)). No metadata is invented here.

> **Status / honesty note.** This repository contains the framework, optimizer,
  KOperation modules, Lean 4 proofs, and measurement harness. The formal check,
  a single-app Katran KVM smoke, and a fresh full six-application corpus run
  have completed: the six-app run `x86_kvm_corpus_20260923_114624_121697`
  finished with suite status `completed` and all six workloads `ok`. An earlier
  retained six-app preparation run ended with one workload failure and is kept
  as the honest negative record. Full paper-scale measurements require
  multi-hour KVM builds and AWS instances for the ARM64 column. This guide gives
  the no-VM proof path, the Katran smoke command, the six-application command,
  and available Make-backed experiment commands. RQ3's family-ablation ladder
  and Katran policy pair have not been validated in a fresh complete run, and
  RQ4 lacks a validated single-command recipe. The
  [claim mapping](#9-reproducing-the-papers-experiments) marks the remaining
  gaps explicitly.

---

## 1. Paper metadata

**Authority for this AE submission: accepted paper #1160.**

- **Title:** *BPF-Ext: Safely Extending the eBPF Compilation Pipeline with
  Native Operations*
- **Authors:** Yusheng Zheng, Zhengjie Ji, Weichen Tao, Hao Sun, Wei Zhang,
  Dan Williams, Andi Quinn
- **Venue:** ACM ATC '26 (2026 ACM SIGOPS Annual Technical Conference),
  November 16–18, 2026, Shatin, Hong Kong.

> **Note on the LaTeX source.** The in-repo source under `docs/paper/` (**supporting
> material only**) has since diverged from the accepted version: it currently
> carries a different title (`\tool: ...`, where `\tool` expands to *KOperation*)
> and a different author block. The accepted-paper metadata above is
> authoritative for the AE submission; do not read the current `main.tex` as a
> verbatim record of the accepted paper.

The `\acmDOI`/`\acmISBN` fields in the current source are ACM template
placeholders and are not real identifiers — see
[Author/legal action required](#12-artifact-status-and-remaining-action).

---

## 2. What this artifact is

The artifact contains four components. Each maps to a part of the paper.

| Component | Path | Paper relation |
|---|---|---|
| `bpfopt` bytecode optimizer + stock-kernel userspace shim | `bpfopt/` (`shim/`, `llvm/`, `kopprober/`) | \S\ref{sec:implementation}; the load-time lowering/restore stage |
| KOperation native-operation kernel modules | `module/x86/`, `module/arm64/` | \S\ref{sec:koperation}; the seven hardware-idiom descriptor families |
| Lean 4 semantic proofs + host cross-checks | `native-sim/formal/`, `native-sim/x86/`, `native-sim/arm64/` | abstract + \S\ref{sec:implementation}; "each native emit computes the same result as its proof sequence" |
| Make-backed benchmark harness (micro + production corpus) | `Makefile`, `runner/`, `micro/`, `corpus/` | \S\ref{sec:evaluation} (RQ1–RQ4) |

Supporting material: `docs/implementation.md` (current proof/coverage boundary),
`docs/tmp/20260906-bpf-development-todo.md` (chronological engineering log with
measured results and known defects), `docs/paper/` (LaTeX, figures, tables,
plotting scripts).

---

## 3. Tested environment

The artifact was developed and validated on:

- **OS:** Ubuntu 24.04 (Linux) container/host, x86-64
- **CPU:** Intel Core Ultra 9 285K (x86-64); the paper's *reported* x86 platform is
  an Intel Xeon Silver 4210R @ 2.40 GHz host running an 8-vCPU / 64 GB KVM guest
  on Linux `7.0.0-rc2+`
- **Kernel for benchmarks:** the in-repo `vendor/linux-framework` build
  (release string `7.0.0-rc2+`), run inside KVM via `virtme-ng`
- **ARM64 column in the paper:** AWS `t4g.small` (2 vCPU, 2 GiB, Graviton2),
  also on a \tool-enabled `7.0.0-rc2+` build

**Verified toolchain versions on the tested machine** (recorded from
`--version`):

| Tool | Version |
|---|---|
| clang / llc | Ubuntu clang 18.1.3 / LLVM 18.1.3 |
| gcc, aarch64-linux-gnu-gcc | 13.3.0 |
| cmake | 3.28.3 |
| Python | 3.12.3 (PyYAML 6.0.1) |
| Rust / Cargo | rustc 1.98.1 / cargo 1.98.1 |
| Go | 1.26.8 |
| qemu-system-aarch64 | 8.2.2 |
| virtme-ng (`vng`) | 1.41 |
| docker | 29.8.0 |
| Lean (`lean-toolchain`) | `leanprover/lean4:v4.19.0` (pinned in `native-sim/formal/lean-toolchain`) |

Rust and Go are required by the full build and are pinned by the tracked
`.devcontainer/Dockerfile`; the versions above were verified in the preparation
Workspace.


### Minimum resources

| Path | Time (measured/estimated) | Disk | RAM | Network |
|---|---|---|---|---|
| Static + Lean proof check | tens of minutes (proof build dominates) | ~2–4 GB | ~4 GB | none after deps |
| KVM single-app corpus smoke | ~1.5–3 h (kernel + app build, then a ~2 min guest run) | ~25–40 GB | ~8 GB | none after deps |
| Full micro suite (both arches) | hours to >1 day | ~40 GB | ~16 GB | AWS for ARM64 |
| Full 6-app corpus (both arches) | >1 day | ~60 GB | ~16 GB | AWS for ARM64 |

All measured paths are dominated by **one-time kernel and application image
builds**, not by the measurement itself.

---

## 4. Safety and warnings

- **Privilege.** Benchmarks load real eBPF programs into a kernel and use KVM.
  Docker and `sudo -n` are used for image builds and runtime setup. Run in a
  disposable VM/container, not on a production host.
- **Kernel build.** `make` targets build an in-repo Linux kernel
  (`vendor/linux-framework`). This is slow and disk-hungry; it does **not**
  modify your running system kernel, but it does write tens of GB under
  `vendor/build/` and `.cache/`.
- **Network.** Benchmark runs use packet generation inside the guest. They should
  not be run on a machine whose network must stay pristine.
- **No destructive host operations by design.** No script here deletes unrelated
  files. The only large deletions are of this repository's own build/result
  directories.
- **The `Makefile` is the only supported entrypoint.** Invoking suite modules,
  `cargo run`, or `docker run` directly changes the contract and is unsupported.
- **Expected messages, and one important distinction.**
  - Benign build noise, e.g. `libbpf: elf: skipping unrecognized data section
    .eh_frame`.
  - `verifier probe rejected candidate after step <pass> ...; passing original
    BPF_PROG_LOAD through` — a verifier rejection of an *optimized candidate*
    degrades to the original bytecode; the application still loads.
  - `loadtime optimization failed: loadtime bpfopt step <pass> failed; ...` — an
    **optimizer step failure is fail-fast**: the shim records the error and can
    return `errno=EINVAL` for the application's own `BPF_PROG_LOAD`, which some
    applications treat as fatal. This is deliberate repository policy, not a
    silent pass-through. See
    [Known limitations](#10-known-limitations-and-expected-failures).

---

## 5. Step 0 — obtain and verify the artifact

The primary evaluator entrypoint is the
[GitHub repository](https://github.com/eunomia-bpf/bpf-benchmark) and this guide.
For the current source, clone the repository and initialize its pinned
submodules:

```bash
git clone https://github.com/eunomia-bpf/bpf-benchmark.git
cd bpf-benchmark
git submodule update --init --recursive
```

For a frozen version, use an
[immutable GitHub release tag](https://github.com/eunomia-bpf/bpf-benchmark/releases)
and run `git submodule update --init --recursive` after selecting that tag.
The release notes identify the corresponding archive and source revision. The
repository tracks submodules under `vendor/` (notably `vendor/linux-framework`
for the kernel, `vendor/libbpf`, `vendor/llvmbpf`, and `llvm-backend/llvm`).

[Zenodo concept DOI 10.5281/zenodo.22907396](https://doi.org/10.5281/zenodo.22907396)
is the immutable archival backup. It currently has a published `atc26-ae-1`
version ([version DOI 10.5281/zenodo.22907397](https://doi.org/10.5281/zenodo.22907397)).
An `atc26-ae-2` version is being prepared; do not treat a draft as published
evidence. To use an archived ZIP instead of GitHub, download it from a
**published** Zenodo record. For ae-1, compare its MD5 with the checksum shown
on that record; there is no public ae-1 `.sha256` companion. Once ae-2 is
published, download both its ZIP and `.sha256` companion and run `sha256sum -c`
in their directory. Do not use a draft's checksum as public verification.

An `atc26-ae-2` candidate was built from this repository and passed the
packager's clean-extraction verification (`make lint`, `py_compile`, renderer
`--self-test`, table generation, manifest JSON parse, and the
`required=(...)` file list). Its exact source revision is the
`superprojectCommit` field of `ARTIFACT_MANIFEST.json` inside the archive, and
its authoritative SHA256 is the `.sha256` companion next to the ZIP. It is a
local build, not a published record: the authors must upload the ZIP and its
`.sha256` companion to Zenodo and publish the version before it counts as
available evidence.

```bash
ZIP=atc26-ae-1.zip  # select the ZIP from a published Zenodo record
md5sum "$ZIP"       # ae-1: compare with the MD5 shown on its Zenodo Files page
# Once ae-2 is published with both files: sha256sum -c "$ZIP.sha256"
mkdir bpf-ext-artifact
unzip "$ZIP" -d bpf-ext-artifact
cd bpf-ext-artifact
python3 -m json.tool ARTIFACT_MANIFEST.json >/dev/null
python3 docs/artifacts/render_claim_table.py .
```

The ZIP embeds the pinned source of every submodule required by the documented
proof and benchmark paths. It deliberately has **no `.git` directory**; do not
run `git checkout` or `git submodule update` inside it. The manifest records
the superproject commit and direct/nested submodule pins. Match the package
version and checksum to the chosen GitHub release before interpreting its
evidence.

Install the Python dependency used by the harness. The raw-data plotting
scripts additionally need Matplotlib and NumPy:

```bash
pip install pyyaml
pip install matplotlib numpy  # only for regenerating the paper's figures
```

---

## 6. Step 1 — FAST PATH: static validation and the Lean 4 proofs (no VM)

This path needs **no KVM, no Docker, and no AWS**, and it is the first thing an
evaluator should run. It validates the artifact's *soundness* content: the
generated contracts, the Lean 4 refinement theorems, and the independent C host
cross-checks. These proofs cover the listed native-simulator emitter contracts;
they do not prove equivalence of the optimizer's generic stack-offset remapper
or branch-sensitive stack-slot reuse. Those transformations need separate
semantic checks, beyond a passing fixture or kernel verifier result.

```bash

# 1. Pure-Python syntax validation, no runtime dependencies.
make lint

# 2. Lean 4 semantic proofs + generated-contract drift checks + C host cross-checks.
make -C native-sim/formal check

# 3. x86 simulator proof artifacts (negative artifact + workload-derived artifacts).
make -C native-sim/x86 micro-proofs-build
```

### Why `make check` is not in the fast path

`make check` expands to `make validate` → `make test` (see `Makefile`), which is
the Make-backed **KVM test suite** target. It requires the runtime image and a
KVM-capable host, so it belongs to the full-validation stage in
[Step 2](#7-step-2--kvm--full-validation-then-the-single-app-smoke-path) and later, not here.

### What `make -C native-sim/formal check` does

It is the paper's **soundness check for the "native emit == proof sequence"
claim**. In order it:

1. Runs `--check` on the 52 generator scripts (e.g.
   `generate_arm64_alu_result_spec.py --check`,
   `generate_x86_add_flags_spec.py --check`) that regenerate the shared
   Lean + C contracts from the JSON specs and **fail if any generated artifact
   drifted** from its spec. This is how the paper's "generated contract" design
   is enforced.
2. Runs `lake build` for the `KProgFormal` library (Lean 4, pinned
   `v4.19.0`, **Mathlib-free**).
3. Type-checks each refinement module
   (`lake env lean KProgFormal/<Module>.lean`) — these contain the refinement
   theorems that relate each generated native emit to an independently stated
   specification.
4. Compiles and runs **host cross-check programs** (`test_*_host.c`) that
   independently re-derive the same results in C and compare, e.g.
   `arm64 flags host cross-check: OK (... cases)`,
   `x86 bswap host cross-check: OK (... cases)`.

**Expected output.** Long compile output, then a series of lines ending in
`host cross-check: OK (<N> cases)`. Exit status **0**. Any `error:` line or a
non-zero exit is a real failure — see
[Troubleshooting](#8-idempotence-and-failure-recovery).

**No `sorry`/`admit`.** The proof suite is required to be complete; a `sorry`
would be a defect, not a warning. (Check: `grep -rn "sorry" native-sim/formal/KProgFormal/`.)

**Resource note.** The Lean step is the slowest part of the fast path; budget
tens of minutes on a first run and much less on re-runs (the `.lake` build
directory is cached).

**Validation evidence (2026-09-25).** A full `make -C native-sim/formal check`
completed with **exit status 0** at commit `735539c2c`: 52
`generate_*_spec.py --check` generators, 84 `lake env lean` refinement-module
checks, and 34 compiled-and-run C host cross-checks reporting 1,605,212 oracle
cases in total. (The previous receipt, at commit `68a77fe0e`, recorded
52/80/30 checks and 1,517,532 oracle cases; the proof line has since grown the
x86 memory source/store/unary handler cross-checks.) The retained receipt is
`docs/artifacts/evidence/formal-check.json`, its console log is
`docs/artifacts/evidence/formal-check.log`, and the claim table's
`Semantic proofs` row derives those four counts from the log and cross-checks
them against both the receipt and the `native-sim/formal/Makefile` at the
current commit, so a receipt left behind by an older proof tree reports
PARTIAL rather than passing. Performance experiments were **not** rerun as part
of this documentation validation; the paper's performance numbers are not
claimed to have been re-measured here.

---

## 7. Step 2 — KVM / full validation, then the single-app smoke path

Full validation requires the runtime image and a KVM-capable host. The tracked
`.devcontainer/devcontainer.json` and `.devcontainer/Dockerfile` provide the
pinned build environment and start Docker; the host must separately expose
`/dev/kvm` and permit Docker-in-Docker. Check the Rust and Go toolchains before
the first image build. The supplied
`.devcontainer/Dockerfile` installs both under `/usr/local` and sets these
variables and paths; some existing Coder login shells omit them even though
the toolchains are installed. In such a shell, use the installed paths shown
below rather than downloading a second toolchain. On a different host, use
that host's working Rust and Go installations instead.

```bash
# Existing Coder shell using the supplied image:
export RUSTUP_HOME=/usr/local/rustup CARGO_HOME=/usr/local/cargo
export PATH="/usr/lib/llvm-18/bin:/usr/local/go/bin:/usr/local/cargo/bin:$PATH"
clang --version
cargo --version
go version
# Full Make-backed test validation (builds the runtime image; requires KVM).
make check
```

Once the image and kernel are built, the cheapest **end-to-end** measurement is
a single corpus application:

```bash
BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 \
  TIMEOUT=3000 make corpus
```

This is a genuine two-start load-time experiment: the framework starts the real
upstream application (never a synthetic loader), captures its `BPF_PROG_LOAD`
calls through the injected shim, runs the configured `bpfopt` pass chain
(including the KOperation-backed `kop` pass), submits optimized bytecode
through the application's normal stock-kernel `BPF_PROG_LOAD` path, and measures
the workload in both phases.

To measure **all six** applications to a terminal success, drop the
`BPFREJIT_CORPUS_APPS` subset and keep the same single-sample, 10-second
configuration:

```bash
SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=7200 make corpus
```

A fresh run of this exact command completed on 2026-09-23 in 1,162 seconds with
suite status `completed` and all six applications `ok`; its retained,
hash-bound evidence is `docs/artifacts/evidence/kvm-six-app-success/`.


### Where results land

```
corpus/results/<arch>_<platform>_corpus_<timestamp>/
├── metadata.json                      # suite-level record
├── result.json
└── details/
    ├── apps/<app>.json                # per-app: status, error, baseline/post_rejit
    ├── loadtime-reports/<app>.jsonl   # per-program, per-step optimizer reports
    ├── loadtime-plans/<app>.json      # the exact ordered pass plan used
    └── shim-logs/<app>.*.log          # raw shim/verifier/lifecycle log
```

**Raw fields to read** (per BPF program, per phase `baseline` / `post_rejit`):
`run_cnt_delta`, `run_time_ns_delta`, `id`, `name`, `type`, `bytes_jited`,
`bytes_xlated`. The per-program average cost is
`run_time_ns_delta / run_cnt_delta`; programs with `run_cnt_delta == 0` in either
phase must be skipped. `details/loadtime-reports/*.jsonl` contains
`sites_matched` / `sites_applied` per pass and the `kop_calls_by_name` histogram.

**The framework writes raw counters only.** No ratios, geomeans, or summaries are
computed in framework code (this is a documented repository invariant); all
aggregation belongs in `docs/paper/scripts/`.

### Result data shipped in the repository, and its exact status

**Read this before citing any shipped result.** The repository tracks a large
amount of historical development result data (thousands of directories under
`corpus/results/`). Most of it is *development* data, not the paper's dataset.
The specific runs relevant to this guide, with their **verified top-level
status**:

| Run directory | Top-level status | Per-app | What it does and does not support |
|---|---|---|---|
| `docs/artifacts/evidence/kvm-six-app-coverage/` (source run `x86_kvm_corpus_20260921_211712_637406`) | `error` | 5/6 apps `ok`; `tracee/monitor` `error` | **Tracked compact evidence.** Supports *rejit/KOperation coverage*: all six retained app records report `rejit_result.status: ok`. Does **not** support a claim of full workload success, because the Tracee workload launch failed. `receipt.json` binds every retained JSON by SHA256 and states that the original shell command was not retained. |
| `docs/artifacts/evidence/kvm-katran-smoke/` (source run `x86_kvm_corpus_20260922_213414_889964`) | `completed` | Katran `status: ok`; `rejit_result.status: ok` | **Fresh tracked KVM smoke.** The exact command exited 0 after 5,946 seconds. `receipt.json` binds the command, source commit, log, and retained JSON files by SHA256. Supports both Katran rejit/KOperation coverage and a complete successful single-app workload run. |
| `docs/artifacts/evidence/kvm-six-app-success/` (source run `x86_kvm_corpus_20260923_114624_121697`) | `completed` | all six apps `ok`; all six `rejit_result.status: ok` | **Fresh tracked full six-application corpus run.** The exact command `SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=7200 make corpus` exited 0 after 1,162 seconds. `receipt.json` binds the command, source commit, normalized log, and every retained JSON by SHA256. Supports six successful workloads and full ReJIT/KOperation coverage under the default `full-x86` policy. It is a single-sample 10 s run, not a paper-scale Xeon/AWS rerun. |
| `docs/artifacts/evidence/rq4-cilium-native-loader/` (source run `x86_kvm_corpus_20260924_164153_955835`) | `completed` | Cilium `status: ok` | **Fresh tracked native-loader run.** The exact command `BPFREJIT_CORPUS_APPS="cilium/agent" BPFREJIT_SHIM_NATIVE_LOADER=post SAMPLES=3 WORKLOAD_DURATION=30 JOBS=8 IMAGE_BUILD_JOBS=8 TIMEOUT=3600 make corpus` exited 0 after 2,846 seconds. `receipt.json` binds the command, source commit, normalized log, post-phase shim log, staged manifest and retained JSON files by SHA256. Supports the derived RQ4 loader counts (179 loads / 135 replacements / 0 pass-throughs / 33 feature-probe skips / 11 pre-init loads) and the 89-object staged manifest; it does not reproduce the paper's declared 113/22 loader split. |
| `docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/` (source run `x86_kvm_corpus_20260925_081752_606800`) | `completed` | Cilium `status: ok` | **Fresh tracked retained-bytecode run.** The exact command `BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` exited 0 after ~290 s inside the guest. `receipt.json` binds the command, source commit, normalized log, report stream, and the retained per-step bytecode for the 122 changed load instances by SHA256. Supports the derived rewrite evidence (122/122 changed workdirs whose retained before/after bytecode lengths match the reported instruction counts and whose images differ; 3,787 applied sites; 159,896 → 111,826 instructions); it is a single startup and does not reproduce the paper's declared 4,086-site full-scale run. |
| `docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/` (source run `x86_kvm_corpus_20260925_101028_808501`) | `completed` | Katran `status: ok` | **Fresh tracked retained-bytecode run.** The exact command `BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` exited 0 after 3m29s. `receipt.json` binds the command, source commit, normalized log, report stream, and the retained per-step bytecode for the one changed load instance by SHA256. Supports the derived rewrite evidence for the overlay/hint policy path (`--inline-hint` anchors plus `overlays/katran/*.json`): 1/1 changed workdir whose retained before/after bytecode lengths match the reported instruction counts and whose images differ, 16 applied sites, 2,554 → 2,284 instructions (−270). Does **not** support a population-scale claim; the fresh 16-site figure is not merged with the paper's declared Katran site figures. |
| `docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/` (source run `x86_kvm_corpus_20260925_111811_456569`) | `completed` | Tracee `status: ok` | **Fresh tracked retained-bytecode run.** The exact command `BPFREJIT_CORPUS_APPS=tracee/monitor BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` exited 0 after ~362 s. `receipt.json` binds the command, source commit, normalized log, report stream, and the retained per-step bytecode for the 12 changed load instances by SHA256. Supports the derived rewrite evidence for the default `--map-values`/`--map-ids` policy path (no inline hints) over the two global config arrays, across kprobe, raw_tracepoint and cgroup_skb program types: 12/12 changed workdirs whose retained before/after bytecode lengths match the reported instruction counts and whose images differ, 12 applied sites, 400,640 → 398,817 instructions (−1,823). Does **not** support a population-scale claim; the fresh 12-site figure is not merged with the paper's declared RQ2 4086 figure or any declared Tracee site count. |
| `docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/` (source run `x86_kvm_corpus_20260925_133216_342697`) | `completed` | Tetragon `status: ok` | **Fresh tracked retained-bytecode run.** The exact command `BPFREJIT_CORPUS_APPS=tetragon/observer BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` exited 0 after ~400 s. `receipt.json` binds the command, source commit, normalized log, report stream, and the retained per-step bytecode for the 118 changed load instances by SHA256. Supports the derived rewrite evidence for the default `--map-values`/`--map-ids` policy path (no inline hints) over six array maps (`tg_conf_map`, `policy_conf`, `policy_stats`, `cgroup_rate_opt`, `.rodata`, `config_map`), across kprobe, tracepoint, raw_tracepoint and socket_filter program types, and covering single-site as well as two- and three-site programs: 118/118 changed workdirs whose retained before/after bytecode lengths match the reported instruction counts and whose images differ; 140 applied sites; 234,754 → 220,562 instructions. It is a single startup with `SAMPLES=1` and does not re-measure the paper's declared Tetragon site figures. |
| `docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/` (source run `arm64_qemu_corpus_19700101_000012_467359`) | `completed` | Katran `status: ok` | **Fresh tracked retained-bytecode run on AArch64.** The exact command `env PLATFORM=qemu ARCH=arm64 BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` exited 0 after 326 s of guest-reported wall time under the local `qemu-system-aarch64` executor. `receipt.json` binds the command, source commit, normalized log, report stream, and the retained per-step bytecode for the one changed load instance by SHA256. Supports the derived rewrite evidence for the same overlay/hint policy path used by the x86 Katran row, now on arm64: 1/1 changed workdir whose retained before/after bytecode lengths match the reported instruction counts and whose images differ; 16 applied sites; instruction counts 2,554 → 2,284 (−270). The arm64 set has the same single changed instance and the same 16 applied sites as the x86 Katran set, so the rewrite is architecture-symmetric; it does not re-measure the paper's declared Katran figures or any workload throughput, and the two architectures are never merged. |
| `corpus/results/x86_kvm_corpus_20260522_*` (18 runs: six apps × one `map_inline`-only + two no-pass `loadtime`) | `completed` | all six apps `status: ok` | **Tracked historical matched batch.** The only tracked set that holds, for all six applications, a `map_inline`-only run *and* same-batch no-pass `loadtime` nulls at the identical 60 s `WORKLOAD_DURATION` with 3+3 workload samples. Supports the renderer's controlled per-pass throughput-causality rows (raw `map_inline` vs restart-drift-corrected ratios) and the pooled 0.9751 control-corrected geomean. Retains no per-step bytecode, so no site counts are claimed; single-app runs, no `metadata.command`/`source_revision` (old format), so no `receipt.json`. Not merged with the paper's separate June ratios. |
| `docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_005057_618064` plus no-pass controls `x86_kvm_corpus_20260926_010023_572333`, `x86_kvm_corpus_20260926_010936_702976`) | `completed` | Katran `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the one changed load instance, and both controls' logs, metadata and app records by SHA256. Unlike the May matched batch, each run retains its own make-console log and the MI run retains per-step bytecode, so one row binds the derived 16-site rewrite (1 changed load instance, insn 2554 → 2284) to the measured control-corrected throughput ratio (median summed-pktgen raw 1.0751x, control median 0.9997x, corrected 1.0754x; controls 1.0029/0.9966). Single-app, `SAMPLES=3` at 60 s; the fresh pktgen workload sums four components per phase. Not merged with the May ratios or the paper's June ratios. |
| `docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_034321_368659` plus no-pass controls `x86_kvm_corpus_20260926_035326_009026`, `x86_kvm_corpus_20260926_040241_545335`) | `completed` | Cilium `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the 122 changed load instances, and both controls' logs, metadata and app records by SHA256. Unlike the May matched batch, each run retains its own make-console log and the MI run retains per-step bytecode, so one row binds the derived 3,787-site rewrite (122 changed load instances, insn 159,896 → 111,826) to the measured control-corrected throughput ratio (median summed-pktgen raw 1.0325x, control median 1.0734x, corrected 0.9619x; controls 1.0727/1.0740). The corrected sign agrees with the May Cilium batch's independent 0.9585, so Cilium's `map_inline` effect is within restart drift of neutral. A separate generation; never merged with the paper's declared 4086 or the May numbers. |
| `docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_050153_382346` plus no-pass controls `x86_kvm_corpus_20260926_051151_192774`, `x86_kvm_corpus_20260926_052116_597549`) | `completed` | Tetragon `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=tetragon/observer BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the 126 changed load instances, and both controls' logs, metadata and app records by SHA256. The single controlled row binds the derived 148-site rewrite (126 changed load instances, insn 251,439 → 236,490) to the measured control-corrected throughput ratio (median stress-ng `metrc` bogo-ops raw 1.0423x, control median 1.0063x, corrected 1.0357x; controls 0.9977/1.0150). This app's fresh workload is a single component-less stress-ng run, so the derived scalar is the workload-level `stress-ng: metrc:` bogo-ops column rather than a pktgen pps sum. The corrected sign agrees with the May Tetragon batch's independent 1.0840. A separate generation; never merged with the paper's declared site counts or the May numbers. |
| `docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_055043_248321` plus no-pass controls `x86_kvm_corpus_20260926_060155_936788`, `x86_kvm_corpus_20260926_061150_119248`) | `completed` | Tracee `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=tracee/monitor BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the 12 changed load instances, and both controls' logs, metadata and app records by SHA256. The single controlled row binds the derived 12-site rewrite (12 changed load instances, insn 400,640 → 398,817) to the measured control-corrected throughput ratio (median stress-ng `metrc` bogo-ops raw 1.0110x, control median 0.9959x, corrected 1.0152x; controls 0.9948/0.9969). This app's fresh workload is a single component-less stress-ng run, so the derived scalar is the workload-level `stress-ng: metrc:` bogo-ops column. The corrected sign agrees with the May Tracee batch's independent 1.0114 (both above 1.0). A separate generation; never merged with the paper's declared site counts or the May numbers. |
| `docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_070636_267511` plus no-pass controls `x86_kvm_corpus_20260926_071903_072417`, `x86_kvm_corpus_20260926_073026_776920`) | `completed` | BCC `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=bcc/set BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the 19 changed load instances, and both control records by SHA256. Supports the derived 83-site rewrite (19 changed load instances, insn 2,263 → 1,530, all 19 retained before/after images matching the reported counts and differing) bound to the measured control-corrected throughput ratio (median stress-ng `metrc` bogo-ops raw 1.0107x, control median 1.0032x, corrected 1.0075x; controls 0.9995/1.0068). This app's fresh workload is a single component-less stress-ng run, so the derived scalar is the workload-level `stress-ng: metrc:` bogo-ops column. The fresh corrected ratio is within restart drift of neutral, whereas the May BCC batch's independent generation reports 0.7921 (below 1.0); the two are separate generations, so the row claims the controlled measurement rather than a speedup, and it is never merged with the paper's declared site counts or the May numbers. |
| `docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/` (source run `x86_kvm_corpus_20260926_082957_279287` plus no-pass controls `x86_kvm_corpus_20260926_084138_823558`, `x86_kvm_corpus_20260926_085249_602113`) | `completed` | otelcol-ebpf-profiler `status: ok`; both controls `passes: []`, `rejit_result.status: skipped` | **Fresh provenance-complete causality triplet.** The exact commands `env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling BPFREJIT_BENCH_PASSES=map_inline SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` and the two controls with `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,`. `receipt.json` binds the command, source commit, normalized console log, report stream, the retained per-step bytecode for the 13 changed load instances, and both control records by SHA256. Supports the derived 1,078-site rewrite (13 changed load instances, insn 53,346 → 24,566, all 13 retained before/after images matching the reported counts and differing) bound to the measured control-corrected throughput ratio (median stress-ng `metrc` bogo-ops raw 1.0188x, control median 0.9435x, corrected 1.0798x; controls 1.0228/0.8643). This app's fresh workload is composite — five interpreter sha256 workers plus one stress-ng `--cpu` component — but only the stress-ng component carries a rate the extractor recognizes (its `stress-ng: metrc:` bogo-ops column), so the derived scalar is that metrc column summed over the workload's rate-bearing components. The fresh corrected ratio is above 1.0, whereas the May otelcol batch's independent generation reports 0.9983 (below 1.0); the two are separate generations, so the row claims the controlled measurement rather than a speedup, and it is never merged with the paper's declared site counts or the May numbers. |
| `corpus/results/x86_kvm_corpus_20260920_045430_754822/`, `corpus/results/x86_kvm_corpus_20260919_225748_512435/` | development | mixed | Earlier before/after comparisons used while fixing optimizer defects; not paper evidence. |
| `corpus/results/aws_arm64_corpus_*`, `corpus/results/aws_x86_corpus_*` | see each `details/progress.json` | — | Historical AWS runs tracked in the repository. Some have a top-level `status` of `error`; **do not present any run as an all-success result without checking its own `details/progress.json`.** |

**Ground rule.** A result directory is evidence only for what its own
`details/progress.json` (`status`) and `details/apps/<app>.json` (`status`,
`rejit_result.status`, `error`) actually say. A running process is not evidence,
and neither is a directory that merely exists.

These are **development runs on the tested machine**, not the paper's reported
Xeon/AWS numbers. See the honesty note at the top of this guide.

---

## 8. Idempotence and failure recovery

- **Idempotence.** Every `make` target writes to a timestamped directory under
  `corpus/results/`, `micro/results/`, or `tests/results/`; re-running never
  overwrites a previous result. Generated contracts are regenerated by
  `--check` scripts and compared, so re-running the proof check is a no-op when
  nothing changed.
- **Build caching.** Kernel, app, and image builds are cached under
  `vendor/build/` and `.cache/`. A second run is much faster than the first.
- **Interrupted build.** Re-run the same `make` target; builds resume.
- **Network/FUSE-backed workspaces.** The supported Make targets install kernel
  modules serially into a temporary local directory, then copy the completed
  tree into the build cache. This avoids the directory-creation race that raw
  parallel `modules_install` can hit on FUSE. Use the repository Make targets
  rather than invoking Kbuild's `modules_install` directly.
- **`KEEP_WORKDIRS=1`** retains per-program workdir tarballs (including raw
  verifier logs and intermediate bytecode) for programs that hit real
  optimization failures:
  ```bash
  KEEP_WORKDIRS=1 make corpus
  ```
  Tarballs appear under
  `corpus/results/<run>/details/failure-artifacts/<prog_id>.tar.gz`
  (`KEEP_WORKDIRS=all` keeps all of them).
- **A failed optimizer step is recorded, not hidden.** The shim logs
  `loadtime optimization failed: loadtime bpfopt step <pass> failed; log=...`
  and leaves the original bytecode in place where the path allows. Error strings
  and app `status` are preserved in `details/apps/<app>.json`.

---

## 9. Reproducing the paper's experiments

Rows with runnable commands use the Make-backed entrypoints; do not call suite
modules or binaries directly. The RQ3 policy comparison needs a family-ablation
matrix of runs, and a validated one-command RQ4 native-replacement recipe is not
yet documented. Those gaps remain Reproduced work, regardless of historical
metric rows.

| # | Paper claim | Command | Where the output lands | Reproduced by a single command here? |
|---|---|---|---|---|
| RQ1 x86 | micro speedup/geomean, code-size shrink | `make micro SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000` | `micro/results/` | Yes (x86, on a KVM host) |
| RQ1 arm64 | ARM64 micro speedup | `PLATFORM=aws ARCH=arm64 make micro` | `micro/results/` | Yes (needs AWS) |
| RQ1 overhead | `object_load_ns` ratio | included in `make micro` | `micro/results/` | Command path yes; retained 62-case claim `PARTIAL` |
| RQ2 Cilium x86 | 1.074× datapath throughput, 4086 sites | `BPFREJIT_CORPUS_APPS=cilium/agent make corpus` | `corpus/results/` | Path yes; throughput derives from retained JSON; the 4086 count is a full-scale run, with the same-policy `kop` rerun deriving 2988 fresh |
| RQ3 policy | site-count vs profitability | four-arm Cilium ladder + two-arm Katran pair below | `corpus/results/` | `PARTIAL`: all six throughput/cost points and all six fresh site counts (Cilium 4017/3512/3517/2988; Katran 21/64) derive from retained raw JSON; the June per-pass site reports are missing, so the June site counts are declared and the fresh ladder's ordering diverges from June's |
| RQ4 native bound | 2.358×, 488.7→262.3 ns/run | no validated single-command recipe retained | `corpus/results/` | `PARTIAL`: selected metrics derive from retained Cilium JSON; the paper's 113/22/89 loader counts stay declared, and a fresh native-post run derives 179 loads / 135 replacements / 0 pass-through / 33 feature-probe skips / 11 pre-init loads plus 89 manifest objects across 6 native objects |
| Correctness | "zero correctness mismatches" | printed by `make micro` / `make test` | suite output | Yes |
| Proofs | "emit computes the same result as its proof sequence" | `make -C native-sim/formal check` | stdout | **Yes** |
The RQ3 policy-arm commands below select the pass names and 3-sample,
30-second workload settings recorded in the retained Cilium/Katran run
metadata. The Cilium ladder starts from the coverage-max arm and disables
`prefetch`, then `bulk_memory`, then both; the Katran pair compares the
conservative ARM64 pass with the all-selector pass list. The Cilium arm
commands have since been re-run to completion on the current host/toolchain
generation (the four `corpus/results/x86_kvm_corpus_20260924_*` directories),
and those runs retain `details/loadtime-reports/cilium__agent.jsonl`, from which
the renderer derives 4017/3512/3517/2988 applied sites. The two Katran ARM64
policies have likewise been re-run to completion locally under
`PLATFORM=qemu ARCH=arm64` (the two
`corpus/results/arm64_qemu_corpus_19700101_*` directories; `qemu` substitutes
for the unavailable `aws` platform here), retaining
`details/loadtime-reports/katran.jsonl` from which the renderer derives
21 (conservative) and 64 (coverage-max) applied sites. The June and historical
RQ2 site counts remain declared from
`docs/tmp/kop_ablation_20260605_summary.md` because their runs retained no
per-pass report:

```bash
for arm in kop_all_prefetch kop_all_no_prefetch \
           kop_all_no_bulk_prefetch kop_all_no_bulk_no_prefetch; do
  BPFREJIT_BENCH_PASSES=$arm BPFREJIT_CORPUS_APPS=cilium/agent \
    SAMPLES=3 WORKLOAD_DURATION=30 make corpus
done
PLATFORM=qemu ARCH=arm64 BPFREJIT_BENCH_PASSES=kop \
  BPFREJIT_CORPUS_APPS=katran SAMPLES=3 WORKLOAD_DURATION=30 make corpus
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_BENCH_PASSES=rotate,extract,endian_fusion,bulk_memory,prefetch,cond_select,ccmp \
  BPFREJIT_CORPUS_APPS=katran SAMPLES=3 WORKLOAD_DURATION=30 make corpus
```
(`PLATFORM=aws ARCH=arm64` is the equivalent remote arm64 executor when AWS
credentials are configured; the retained reruns above used local QEMU.)

To render the tracked raw JSON into a human-readable claim table, run:

```bash
python3 docs/artifacts/render_claim_table.py .
```

At this revision the expected final line is `OVERALL AE EVIDENCE: INCOMPLETE`:
claim-level `PASS` rows coexist with missing site/loader evidence and a
`PARTIAL` six-application workload row. Treat a process exit of 0 from this
renderer as successful table generation, not successful reproduction.

Composite helper targets exist for convenience: `make all` = test + micro +
corpus; `make terminate` stops managed remote instances.

### Turning raw results into the paper's figures

The paper's plots are produced by scripts in `docs/paper/scripts/`:

- `docs/paper/scripts/plot_evaluation_koperation.py` -- derives the RQ1 micro
  figures from the three retained RQ1 JSON datasets
- `docs/paper/scripts/plot_characterization_pure_percase.py` -- derives the
  Section 3 characterization from the two retained pure-bytecode JSON datasets
- `docs/paper/scripts/plot_rq3_policy_probes.py` -- derives the RQ3
  application policy-probe figure from the six retained corpus run directories
- `docs/paper/scripts/plot_app_case_studies.py` -- the extended-abstract
  rendering of the same six raw points; it reuses the RQ3 derivation above

The RQ1, RQ3, and application scripts emit the PDFs referenced from
`docs/paper/figures/sec-6-koperation-micro-rq1.tex`,
`docs/paper/figures/sec-6-koperation-micro-rq3.tex`, and
`extended-abstract.tex`, respectively. They are **analysis-side**;
per the repository rule, no aggregation lives in the measurement framework.
For RQ1, `docs/artifacts/render_claim_table.py` calculates the accepted
paper's x86 27-case execution geomean from the retained x86 pair, excluding
the baseline-only `simple` and `simple_packet` cases (1.241736×, displayed
as 1.242×). It derives ARM64's 27 KOperation-bearing execution cases as
1.222042× (displayed as 1.222×). Generated native-code size uses **all 29**
cases: 0.771807× x86 and 0.879116× ARM64, displayed as 0.772× and
0.879×. The older plotting script includes all 29 x86 cases for execution
time (1.215665×); that is a different population from the paper's 27 cases.

The selected Cilium corpus JSON yields RQ2 throughput 1.074262× (median) and
RQ4 native/eBPF throughput 2.357974× and BPF cost 488.676→262.298 ns/run.
The RQ2 run's historical per-pass site and native-loader logs are missing, so
its 4086-site and 113/22/89-loader counts are **not** independently reproduced.
The RQ4 native-loader split was instead re-measured on a fresh native-post run
(`corpus/results/x86_kvm_corpus_20260924_164153_955835`, `BPFREJIT_SHIM_NATIVE_LOADER=post`),
whose retained post-phase shim log records 179 intercepted `BPF_PROG_LOAD`s,
135 native replacements, 0 manifest pass-throughs, 33 feature-probe skips, and
11 loads issued before the loader finished initializing (the log emits exactly
one decision line per classified load). Its retained staged manifest holds
89 object entries across 6 distinct native objects. These are a fresh
host/toolchain generation; they are reported beside, and never merged with,
the paper's declared 113/22/89.
The RQ2 run's own pass policy (`kop`) was rerun with its report stream retained
(`corpus/results/x86_kvm_corpus_20260924_114427_040291`), deriving 2988 sites;
the fresh `kop` policy no longer enables `bulk_memory`, so 2988 is a
same-policy fresh-generation count rather than a reproduction of 4086.
The RQ3 family ladder reads the six retained corpus run directories and
derives workload ratios as `mean(post pps)/mean(baseline pps)` and BPF cost
ratios as `sum(run_time_ns_delta)/sum(run_cnt_delta)` over records with
`run_cnt_delta >= 100`. On Cilium the ladder is monotone in the number of
enabled families (coverage-max 1.114172×/0.776324, no-prefetch
1.054652×/0.870897, no-bulk 1.036560×/0.918381, no-bulk+no-prefetch
0.999373×/0.991438); on Katran the coverage-max policy is worse than the
conservative one (1.072760×/0.940924 versus 0.994743×/1.005560).

The **Cilium** applied-site counts are additionally derived from raw shim
report streams. The June ladder retained no per-pass reports, so the same four
single-pass policies were rerun on the same host/toolchain generation as four
fresh isolated `make corpus` invocations (the four
`corpus/results/x86_kvm_corpus_20260924_*` directories) that do retain
`details/loadtime-reports/cilium__agent.jsonl`. The renderer sums
`report.sites_applied` over each stream, keyed by the policy name in
`record.step`, giving 4017 (coverage-max), 3512 (no-prefetch), 3517 (no-bulk),
and 2988 (no-bulk+no-prefetch) — a deterministic count that is independent of
`SAMPLES` and `WORKLOAD_DURATION` (a `SAMPLES=1 WORKLOAD_DURATION=10` rerun of
the coverage-max policy derives the same 4017). These fresh runs are a
**different host/toolchain generation** from the June ladder, so both their
absolute site counts and their throughput ordering differ: the June ladder is
monotone (coverage-max fastest), while the fresh ladder's throughput order is
the reverse (no-bulk+no-prefetch fastest at 1.138190×, coverage-max slowest at
1.011866×). The renderer's `RQ3 Cilium June-vs-fresh ladder ordering (diverges)`
row derives both orderings from retained raw JSON and reports the divergence;
the fresh ladder is shipped as separate evidence and does not replace the June
values. The Katran and the historical RQ2 counts (21/62, 4086) remain
**declared** from `docs/tmp/kop_ablation_20260605_summary.md`, since no
`details/loadtime-reports/` tree survives for those runs and the figures
annotate them as declared.

The **Katran** applied-site counts are derived the same way from two fresh
local-QEMU ARM64 reruns of the paper's two policies
(`corpus/results/arm64_qemu_corpus_19700101_000011_781867`,
`..._000011_741370`). The conservative `kop` arm derives 21 sites
(`{'kop': 21}`; families `rotate 20, extract 1`), exactly matching the declared
per-app 21. The coverage-max seven-family arm derives 64 sites across its
seven steps (`rotate 20, extract 1, endian_fusion 9, bulk_memory 28, prefetch 6`,
`cond_select 0, ccmp 0`), against the declared 62 — a same-policy
different-generation count, not a reproduction. Both rows carry their fresh
throughput and cost ratios. As with the Cilium arms, the June/July counts remain
**declared**; these fresh arm64 runs are shipped as separate evidence.

For the paper's 62-case x86 object-load claim, the two retained completed
May 14 ReJIT runs each contain 63 cases. Restricting each to the exact 62
benchmark names in the earlier April 29 run (the only extra name is
`katran_like`) gives 0.995157× and 0.997839×, respectively. Both round to
1.00× at two decimal places. The paper does not enumerate its 62 names and
states 0.99×; no completed paired 62-case ReJIT run was found among the
retained May/June x86 micro results. The renderer derives this claim's status
from those two ratios — `PASS` only if both round to 0.99× and both runs pass
their live metadata/progress provenance check, otherwise `PARTIAL` — so it
marks the claim `PARTIAL`. This historical-name mapping is plausible, not
proven to be the paper's exact population. A search across all current Git
May/June `details/loadtime-reports`, `loadtime-plans`, or `shim-logs`
files for the historical corpus runs; the original June 4 Cilium result
commit contains only app, result, progress, and metadata JSON. The 4086
site count remains a historical summary until its original per-pass raw log is
recovered. Two fresh reruns of the RQ2 run's own `kop` policy and of the
no-prefetch family set retain their report streams and derive 2988 and 3512
sites respectively; the fresh `kop` policy no longer enables `bulk_memory`, so
both are same-policy different-generation counts, not reproductions of 4086.

Two further fresh x86 paired load-time runs were taken on the current micro
generation (`SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 RUNTIMES="kernel
kernel_rejit" make micro`): `x86_kvm_micro_20260924_231824_136293` under the
default `full-x86` policy and `x86_kvm_micro_20260925_002201_525373` under
`kop`. Neither reproduces the paper's 62-name population — the current config
retains only 2 names in common with either May 14 run — so the renderer
derives six separate rows from these runs' own paired series. Two are
object-load overhead rows from the paired `object_load_ns` geomeans
(1.161575× and 1.223405×, both `PARTIAL` against the paper's 0.99×). Two apply
the paper's RQ1 exec-speedup definition (geomean kernel/kernel_rejit median
`exec_ns` over the 27 non-simple cases whose median applied kop sites exceed
zero) and yield 1.081422× (`full-x86`, 532 applied kop sites plus the
pure-bytecode passes) and 1.213995× (`kop`, 525 applied kop sites). Two apply
the paper's RQ1 code-size definition (geomean kernel_rejit/kernel median
`native_code_bytes` over all 29 cases) and yield 0.893127× (`full-x86`) and
0.896642× (`kop`). All four speedup/size rows are `PASS` on provenance, but
they are same-policy different-generation values, not reproductions of the
paper's 1.242× speedup or 0.772× code size. The paper's 62-case row is never
merged with them.

These are analysis-side computations. No aggregation lives in the
measurement framework; the plot scripts derive every plotted value except the
declared site annotations.

---

## 10. Known limitations and expected failures

These are real limitations and failures. Some currently block a complete
Functional or Reproduced evaluation, so check each run's status rather than
assuming a command or retained directory succeeded.

1. **Some programs cannot be lifted within the 512-byte BPF frame.** The LLVM
   roundtrip that the optimizer uses re-lays out the stack and inflates the frame
   by ~45 bytes on average (measured over all 542 checked-in program fixtures;
   405 grew, 137 unchanged, none shrank). `kop` runs last in the pipeline, so a
   program starting near the limit can lose all optimization. Two bpfopt fixes
   committed on 2026-09-23 addressed this: an out-of-range stack-slot remap at
   the widest width (`1df5b1369`) and giving the generic (non-`kop`) roundtrip
   passes the same 4096-byte LLVM stack budget that `kop` already used
   (`42cceb67e`), so the remapper can squeeze the layout back into the 512-byte
   BPF frame. Quantified in `docs/tmp/20260906-bpf-development-todo.md`.
2. **`tracee/monitor` app-level errors are fixed for the default policy.** The
   shim returns `errno=EINVAL` for an application's own `BPF_PROG_LOAD` when an
   optimizer step fails (deliberate fail-fast policy), and some applications
   treat that as fatal. Before the two fixes above, `const_prop` failed on
   `trace_security_` and the workload launch errored (run
   `x86_kvm_corpus_20260921_211712_637406`). In the fresh run
   `x86_kvm_corpus_20260923_114624_121697` the same program completes all 11
   plan steps (`kop` applies 57/57 sites at step 10) and every app reports
   `status: ok`. A single-sample run is not a paper-scale measurement; treat the
   per-program reports as optimization evidence, not throughput evidence.
3. **`branch_flip`** is production code but is intentionally **not** in the
   default benchmark policy; it requires real per-site PMU profile input from the
   external profiling toolchain.
4. **ARM64 numbers require AWS.** There is no local ARM64 KVM path for the
   reported configuration; QEMU is available but is not the measured platform.
5. **The paper's "62 microbenchmarks" population is not the shipped RQ1
   population.** Section 7.1's load-overhead sentence cites all 62
   microbenchmarks; the 62-name dataset is
   `micro/results/x86_kvm_micro_20260429_035938_203074`. The shipped RQ1
   datasets hold 29 cases each, and the renderer's RQ1 execution claim uses 27
   after excluding the baseline-only `simple` and `simple_packet`. The
   load-overhead claim therefore cannot be re-derived from the RQ1 datasets.
6. **Katran's per-app applied-site count differs from the corpus-wide family
   sum.** `docs/tmp/kop_ablation_20260605_summary.md` records 21 Katran sites in
   its per-app table (line 55) but 24 in its corpus-wide family tally (rotate 20
   + extract 4). The paper quotes the per-app 21; the two are different
   aggregations of the same run and the discrepancy is unresolved because the
   per-pass report is not retained.
7. **The June RQ3/RQ2 site counts are declared; the fresh Cilium and Katran
   counts are derived.** No `details/loadtime-reports/` tree survives for the
   June ladder, so its annotated counts (4697/4086/4136/3512), the June Katran
   counts (21/62) and the RQ2 4086 count are **declared** from
   `docs/tmp/kop_ablation_20260605_summary.md`. Five fresh Cilium reruns retain
   their report streams: the four RQ3 policy arms
   (`corpus/results/x86_kvm_corpus_20260924_{064817_392000,074900_275227,085901_647044,095500_223221}`)
   derive 4017/3512/3517/2988, and a rerun of the RQ2 run's own `kop` policy
   (`corpus/results/x86_kvm_corpus_20260924_114427_040291`) derives 2988. Two
   fresh local-QEMU ARM64 reruns retain `details/loadtime-reports/katran.jsonl`:
   the conservative `kop` arm (`corpus/results/arm64_qemu_corpus_19700101_000011_781867`)
   derives 21, and the seven-family coverage-max arm
   (`corpus/results/arm64_qemu_corpus_19700101_000011_741370`) derives 64. The
   fresh `kop` policy no longer enables `bulk_memory`. These are a different
   host/toolchain generation (the ARM64 arms also ran under local QEMU rather
   than AWS), so do not treat the derived counts as reproducing the June
   numbers.
8. **The fresh Cilium ladder does not reproduce the June ladder's ordering.**
   On the same fresh generation the post/baseline throughput ordering is the
   reverse of the June ladder (no-bulk+no-prefetch 1.138190× fastest,
   coverage-max 1.011866× slowest), and baseline pps varies ~10% across arms.
   The renderer derives both orderings and marks the comparison `PARTIAL`
   (`RQ3 Cilium June-vs-fresh ladder ordering (diverges)`); the June rows are
   kept and the fresh runs are shipped as a separate evidence set.
9. **RQ4's producers are retained analysis scripts, not Make targets.**
   `docs/tmp/native_eval_20260529.py` and `docs/tmp/native_eval_20260614.py`
   derive the native-in-kernel metrics; they are shipped as cited files and are
   not reachable from a single `make` command.

---

## 11. Repository layout (artifact-relevant paths)

```text
Makefile                      # the ONLY supported benchmark entrypoint
bpfopt/
  shim/                       # LD_PRELOAD shim; intercepts BPF syscalls in-process
  llvm/                       # the optimizer CLI (one named pass per invocation)
  kopprober/                  # probes loaded KOperation BTF and writes target.json
module/{x86,arm64}/           # KOperation native-operation kernel modules
native-sim/
  formal/                     # Lean 4 proofs, JSON specs, generators, host checks
  x86/, arm64/                # architecture simulators with proven contracts
micro/                        # microbenchmark programs + configs + results
corpus/                       # production app corpus, workloads, results
runner/                       # Make-backed suites, executors, images, libs
docs/paper/                   # current paper source and plots; see metadata caveat above
docs/implementation.md        # current proof/coverage boundary (read this)
docs/tmp/20260906-*.md        # chronological engineering log with measurements
docs/artifacts/               # AEC renderer, packager, and compact receipts
docs/paper/scripts/           # raw-deriving plot scripts (RQ1, RQ3, Section 3)
```

---

## 12. Artifact status and remaining action

**Target: all three badges — Available, Functional, and Reproduced. A requested
badge is not an awarded badge.** The following is the artifact author's
evidence status, not an AEC decision.

| Badge | Current evidence | Remaining acceptance work |
|---|---|---|
| Available | The public, immutable `atc26-ae-1` ZIP is deposited at [version DOI 10.5281/zenodo.22907397](https://doi.org/10.5281/zenodo.22907397); [concept DOI 10.5281/zenodo.22907396](https://doi.org/10.5281/zenodo.22907396) is the stable all-versions homepage. Repository-original material is MIT-licensed; third-party licenses and pins are in `THIRD_PARTY_NOTICES.md`. An `atc26-ae-2` candidate ZIP was built by `docs/artifacts/package-atc26.sh` and replay-verified from clean extraction. | The `atc26-ae-2` candidate must be **published** on Zenodo, and an independent evaluator must verify that published ZIP from clean extraction, before it can count as an available newer archive. Publishing a draft DOI alone does not publish its files. |
| Functional | Component map, environment, dependencies, safety notes, no-VM formal path, a completed six-application KVM corpus run and a completed fresh Cilium native-loader run are documented above. The `atc26-ae-2` candidate passed the packager's clean-extraction replay (`make lint`, `py_compile`, renderer `--self-test`, table generation and manifest parse). | An independent evaluation must confirm the **published** ZIP through the documented proof/build/smoke path; a build-time self-test in the authors' checkout alone is weaker evidence. |
| Reproduced | The retained RQ1 data derive 1.242×/1.222× speedup on the respective 27-case subsets and 0.772×/0.879× code size on all 29 cases. The two fresh x86 paired runs additionally derive same-policy different-generation RQ1 rows: exec speedup 1.081× (`full-x86`) and 1.214× (`kop`) over their 27 kop-bearing non-simple cases, and code size 0.893× (`full-x86`) and 0.897× (`kop`) over all 29 cases -- self-contained paired runs, but not reproductions of the paper's 1.242× speedup or 0.772× code size. Selected raw Cilium app JSON derives RQ2 throughput 1.074× and RQ4 throughput 2.358× and 488.7→262.3 ns/run. All six RQ3 policy-probe throughput/cost points derive from retained raw JSON (Cilium ladder 1.114/1.055/1.037/0.999 with costs 0.776/0.871/0.918/0.991; Katran 1.073/0.995 with costs 0.941/1.006). Five fresh Cilium reruns retain their shim report streams: the four RQ3 arms derive applied-site counts 4017/3512/3517/2988 and a rerun of the RQ2 run's own `kop` policy derives 2988; two fresh local-QEMU ARM64 Katran reruns derive 21 (conservative) and 64 (coverage-max); the renderer derives a `PARTIAL` June-vs-fresh ordering divergence row and, for each of the five retained report streams, a caller-vs-tail-descendant attribution row splitting applied sites into directly attached callers (1019/876/869/717) versus zero-self tail targets (2929/2571/2583/2212) plus the 15-char name-join residual. A fresh native-post Cilium run retains its post-phase shim log, from which the renderer derives 179 intercepted loads, 135 native replacements, 0 pass-throughs, 33 feature-probe skips, 11 pre-init loads and 89 manifest objects across 6 native objects. The formal, Katran-smoke, six-app-success and native-loader receipts are hashed in `docs/artifacts/evidence/`. | The fresh site counts are a different host/toolchain generation (the ARM64 arms under local QEMU, not AWS), so they do not reproduce the June 4697/4086/4136/3512 and 21/62 counts, which remain **declared**. The fresh native-loader counts likewise do not reproduce the paper's declared 113/22/89 loader split. |

`docs/artifacts/render_claim_table.py` separates raw-file integrity, selected
numeric claims, ReJIT coverage and full workload success. Its `PASS` is local to
the named row; it is **not** a badge verdict. The fresh six-app-success workload
row is `PASS`; the earlier errored six-app preparation run is retained as an
explicit `PARTIAL` workload row (ReJIT coverage `PASS`, 5/6 workloads). The x86
micro dataset's 29 available cases are not the paper's 27-case analysis
population.

The renderer additionally attributes each retained Cilium report stream's
applied sites to directly attached callers versus tail-call descendants, by
joining report `prog_name` against the application's own `baseline.bpf[*]`
runtime counters on the shim's 15-character truncated name. Across the four
RQ3 arms (the fifth, the RQ2 `kop` rerun, matches the no-bulk/no-prefetch arm
exactly at 2988/717/2212/59) the result is identical in structure: 4 directly
attached caller programs (`cil_from_contai`, `cil_from_netdev`, `cil_to_netdev`,
`cil_xdp_entry`, each with nonzero `run_cnt_delta`; 1019/876/869/717 sites) and
12 zero-self tail targets (2929/2571/2583/2212 sites), with a name-join
residual of 69/65/65/59 sites over 3 names (`''`, `cil_to_containe`,
`probe_fib_looku`) that the application never reported a counter for. This is
the tail-call accounting caveat made concrete: the callers' `run_time_ns_delta`
already includes every tail descendant's cost, so the applied-site total
reconciles as directly attached + zero-self + residual and the join is reported
as lossy rather than presented as total.

The renderer also derives a fresh RQ2 Cilium rewrite row from retained per-step
bytecode. The older RQ2 artifacts kept neither retained outputs nor before
images, so a `map_inline` rewrite could not be shown to have changed any
bytecode. A fresh single-pass run `BPFREJIT_CORPUS_APPS=cilium/agent
BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30
KEEP_WORKDIRS=1 make corpus` (source commit `680a9e9b88`) retains, for every
changed load instance, the per-step `input.step.0.bin` / `output.next.0.bin`
pair and its `report.0.json` under
`docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/`. Its
retained `details/loadtime-reports/cilium__agent.jsonl` holds 169 report rows
(122 changed load instances, 47 unchanged), 3,787 applied sites, and instruction
counts 159,896 → 111,826 (−48,070). For all 122 changed workdirs the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts, and all 122 before/after images differ; the
run's `provenance/start.json` (hand-authored, not Makefile-generated) records
the command and source revision. The renderer computes these counts at render
time and asserts both reconciliations. This is a single startup, so it proves
the rewrite on retained bytecode rather than per-pass throughput causality, and
the paper's declared 4,086 site count is not merged with the fresh 3,787.

The same derivation is applied to Katran, which exercises the overlay/hint
policy path rather than Cilium's `.rodata.config` path. A fresh single-pass run
`BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1
WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` (source commit `b04df85dc1`)
retains, for the one changed load instance, the per-step `input.step.0.bin` /
`output.next.0.bin` pair and its `report.0.json` under
`docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/`. Its retained
`details/loadtime-reports/katran.jsonl` holds 6 report rows (1 changed load
instance, 5 unchanged), 16 applied sites, and instruction counts 2,554 → 2,284
(−270). The retained bytecode's raw `struct bpf_insn` length (8 bytes each)
matches the reported before/after instruction counts for that workdir and the
two images differ. The inlined map classes are exactly the hinted set
(`ch_rings` 2, `ctl_array` 2, `reals` 6, `server_id_map` 2, `vip_map` 4);
the shim's post-phase log records `loadtime optimized prog=balancer_ingres
insns=2542->2272 maps=14` with zero failure lines. The renderer computes these
counts at render time and asserts both reconciliations. The Katran set is thin
(1 changed load instance), so it establishes the policy path and its retained
rewrite, not a population-scale effect; the fresh 16-site figure is not merged
with the paper's declared Katran site figures or with Cilium's fresh 3,787.

A third retained-bytecode run applies the same derivation to Tracee, which uses
the default `--map-values`/`--map-ids` policy path with no inline hints and
whose workload is stress-ng rather than a packet generator. A fresh single-pass
run `BPFREJIT_CORPUS_APPS=tracee/monitor BPFREJIT_BENCH_PASSES=map_inline
SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` (source commit
`14ab524f32`) retains, for each of the 12 changed load instances, the per-step
`input.step.0.bin` / `output.next.0.bin` pair and its `report.0.json` under
`docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/`. Its retained
`details/loadtime-reports/tracee__monitor.jsonl` holds 162 report rows (12
changed load instances, 150 unchanged), 12 applied sites, and instruction
counts 400,640 → 398,817 (−1,823); the per-program deltas are large for single
sites because each inlined array load replaces a map-value lookup sequence, and
the changed set spans `kprobe`, `raw_tracepoint` and `cgroup_skb` program types
(`sys_enter_init` 579 → 416, `lkm_seeker_mod_` 218 → 90, `cgroup_skb_ingr`
3,602 → 3,420, and nine more). For all 12 changed workdirs the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts and the two images differ. The renderer computes
these counts at render time and asserts both reconciliations. The Tracee set is
small (12 changed load instances, 12 sites), so it establishes the hint-free
policy path and its retained rewrite, not a population-scale effect; the fresh
12-site figure is not merged with the paper's declared RQ2 4086 figure or any
declared Tracee site count.

A fourth retained-bytecode run applies the same derivation to Tetragon, which
also uses the default `--map-values`/`--map-ids` policy path with no inline
hints and whose workload is stress-ng. A fresh single-pass run
`BPFREJIT_CORPUS_APPS=tetragon/observer BPFREJIT_BENCH_PASSES=map_inline
SAMPLES=1 WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` (source commit
`ac3432e60`) retains, for each of the 118 changed load instances, the per-step
`input.step.0.bin` / `output.next.0.bin` pair and its `report.0.json` under
`docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/`. Its
retained `details/loadtime-reports/tetragon__observer.jsonl` holds 215 report
rows (118 changed load instances, 97 unchanged), 140 applied sites, and
instruction counts 234,754 → 220,562 (−14,192); this is the largest retained
changed-instance set in the package and it spans `kprobe`, `tracepoint`,
`raw_tracepoint` and `socket_filter` program types, including programs with two
and three applied sites as well as single-site ones. Six distinct array maps are
inlined — `tg_conf_map` (77 sites), `policy_conf` (41), `policy_stats` (18),
`cgroup_rate_opt` (2), `.rodata` (1, frozen) and `config_map` (1) — verified
against each workdir's `map-values/map-<id>.show.json`. For all 118 changed
workdirs the retained bytecode's raw `struct bpf_insn` length (8 bytes each)
matches the reported before/after instruction counts and the two images differ.
The renderer computes these counts at render time and asserts both
reconciliations. The fresh 140-site figure is not merged with the paper's
declared Tetragon site figures.

A fifth retained-bytecode run extends the same derivation to AArch64: the
overlay/hint `map_inline` policy applied to Katran under the local
`qemu-system-aarch64` executor. The exact command `env PLATFORM=qemu ARCH=arm64
BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1
WORKLOAD_DURATION=30 KEEP_WORKDIRS=1 make corpus` (source commit `8f90c5a12`)
retains, for its single changed load instance (`balancer_ingress`, `xdp`), the
per-step `input.step.0.bin` / `output.next.0.bin` pair and its `report.0.json`
under `docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/`.
Its retained `details/loadtime-reports/katran.jsonl` holds 6 report rows (1
changed load instance, 5 unchanged), 16 applied sites, and instruction counts
2,554 → 2,284 (−270). For the changed workdir the retained bytecode's raw
`struct bpf_insn` length (8 bytes each) matches the reported before/after
instruction counts and the two images differ; the renderer computes these counts
at render time and asserts both reconciliations. Because both rows derive from the
same overlay/hint policy, the arm64 Katran set reproduces the x86 Katran set's
single changed instance and 16 applied sites exactly, so the retained evidence
shows the rewrite is architecture-symmetric. It is a single startup with
`SAMPLES=1`, re-measures no workload throughput, and its fresh 16-site figure is
not merged with the paper's declared Katran site figures or with the x86 set.

A sixth derivation answers per-pass throughput causality from a *tracked
historical* batch rather than fresh retained bytecode. The `x86_kvm_corpus_20260522_*`
set holds, for each of the six applications, one `map_inline`-only run and two
same-batch no-pass runs (`enabled_passes==[]`, `mode=loadtime`,
`status=skipped`) — all single-app `x86_kvm_corpus` with three baseline and
three post-restart workload samples at the identical 60 s
`WORKLOAD_DURATION`. The two no-pass runs are the restart-drift null: they pair
an optimized and a plain restart of the same application at the same duration,
so their median ratio measures how much of the raw post/baseline throughput
ratio is restart drift rather than pass effect. The renderer derives each
application's raw `map_inline` median throughput ratio and its
control-drift-corrected ratio (raw ÷ median of the two controls) directly from
the tracked `corpus/results/**` JSON: bcc/set 0.8318 → 0.7921, otelcol 0.9984 →
0.9983, cilium 0.8885 → 0.9585, tetragon 1.0408 → 1.0840, katran 1.0191 →
1.0345, tracee 0.9243 → 1.0114, with a pooled control-corrected geomean of
0.9751 over the six applications. Because controls differ by app, this
controlled figure is not the sum of an independent measured effect. These runs
retain no per-step bytecode, so the causality rows claim no site counts, and
the May-batch ratios are never merged with the paper's separate June
generation. The renderer's `map_inline` causality rows are `PASS` only when the
derived values reproduce frozen declared constants at the printed precision;
any drift degrades the row to `PARTIAL` rather than silently re-baselining.

A seventh derivation answers the same causality question from a **fresh,
provenance-complete** triplet rather than the tracked historical batch:
`docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/` carries one
`map_inline` run (`x86_kvm_corpus_20260926_005057_618064`) plus two matched
no-pass controls (`x86_kvm_corpus_20260926_010023_572333`,
`x86_kvm_corpus_20260926_010936_702976`), each with its own make-console log and
the MI run retaining per-step bytecode. Unlike the May batch, a single row
therefore binds the measured pass effect to the bytecode change that produced
it: the retained report stream gives one changed load instance
(`balancer_ingress`, 16 applied sites, instruction counts 2,554 → 2,284) whose
retained before/after images match the reported counts and differ, and the
throughput derivation gives median summed-pktgen raw 1.0751x, no-pass control
median 0.9997x (controls 1.0029/0.9966), control-corrected 1.0754x over 3+3
samples at 60 s. The fresh kernel-pktgen workload splits each phase into four
nondeterministically ordered components, so the derived throughput is the sum
over all components' pktgen pps rather than the first rate-bearing component;
the row is `PASS` only when both derived ratios reproduce the frozen declared
constants at four decimal places. The three runs are single-app `x86_kvm_corpus`
with `SAMPLES=3` and 60 s `WORKLOAD_DURATION`; their ratios are never merged
with the May-batch ratios or the paper's June generation.

An eighth derivation repeats the **fresh provenance-complete** treatment for
the second application: `docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/`
carries one `map_inline` run (`x86_kvm_corpus_20260926_034321_368659`) plus two
matched no-pass controls (`x86_kvm_corpus_20260926_035326_009026`,
`x86_kvm_corpus_20260926_040241_545335`), each with its own make-console log
and the MI run retaining per-step bytecode. The retained report stream gives
122 changed load instances totalling 3,787 applied sites (instruction counts
159,896 → 111,826), all 122 of whose retained before/after images match the
reported counts and differ; the throughput derivation gives median
summed-pktgen raw 1.0325x, no-pass control median 1.0734x (controls
1.0727/1.0740), control-corrected 0.9619x over 3+3 samples at 60 s. The fresh
Cilium workload splits each phase into two kernel-pktgen components, so the
derived throughput is again the sum over all components' pktgen pps. The sign
of the control-corrected ratio agrees with the May Cilium batch's independent
`0.9585`: under this host/toolchain generation Cilium's `map_inline` effect is
within restart drift of neutral, so the row claims the controlled measurement
rather than a throughput speedup. The renderer reuses one generic builder for
both fresh triplets and gates each row on that application's own app record and
report path, so a Cilium triplet cannot be satisfied by Katran files. As with
the Katran triplets, these ratios are never merged with the May batch or the
paper's June generation.

A ninth derivation repeats the **fresh provenance-complete** treatment for the
third application: `docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/`
carries one `map_inline` run (`x86_kvm_corpus_20260926_050153_382346`) plus two
matched no-pass controls (`x86_kvm_corpus_20260926_051151_192774`,
`x86_kvm_corpus_20260926_052116_597549`), each with its own make-console log
and the MI run retaining per-step bytecode. The retained report stream gives
126 changed load instances totalling 148 applied sites (instruction counts
251,439 → 236,490), all 126 of whose retained before/after images match the
reported counts and differ; the throughput derivation gives median raw 1.0423x,
no-pass control median 1.0063x (controls 0.9977/1.0150), control-corrected
1.0357x over 3+3 samples at 60 s. Tetragon's fresh workload is a single
component-less stress-ng run, so its rate scalar is the workload-level
`stress-ng: metrc:` bogo-ops column rather than a pktgen pps sum; the shared
extractor's `_rate_scalar` fallback already covers that shape, and the row's
wording names the metric it actually derived. The sign of the control-corrected
ratio agrees with the May Tetragon batch's independent `1.0840` (both above
1.0), but the two are separate generations and are never merged. The renderer's
single generic builder now serves all three fresh triplets, each gated on its
own app record and report path and each carrying its own frozen declared
constants, so a Tetragon triplet cannot be satisfied by Katran or Cilium files.

A tenth derivation repeats the **fresh provenance-complete** treatment for the
fourth application, and the second on the component-less stress-ng shape:
`docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/` carries one
`map_inline` run (`x86_kvm_corpus_20260926_055043_248321`) plus two matched
no-pass controls (`x86_kvm_corpus_20260926_060155_936788`,
`x86_kvm_corpus_20260926_061150_119248`), each with its own make-console log
and the MI run retaining per-step bytecode. The retained report stream gives 12
changed load instances totalling 12 applied sites (instruction counts
400,640 → 398,817), all 12 of whose retained before/after images match the
reported counts and differ; the throughput derivation gives median raw 1.0110x,
no-pass control median 0.9959x (controls 0.9948/0.9969), control-corrected
1.0152x over 3+3 samples at 60 s. Tracee's fresh workload is a single
component-less stress-ng run, so its rate scalar is the same workload-level
`stress-ng: metrc:` bogo-ops column that the ninth derivation introduced. The
sign of the control-corrected ratio agrees with the May Tracee batch's
independent `1.0114` (both above 1.0), but the two are separate generations and
are never merged. The renderer's single generic builder serves every fresh
triplet, each gated on its own app record and report path and each carrying its
own frozen declared constants, so a Tracee triplet cannot be satisfied by
Katran, Cilium, Tetragon, or BCC files.

An eleventh derivation repeats the **fresh provenance-complete** treatment for
the fifth application: `docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/`
carries one `map_inline` run (`x86_kvm_corpus_20260926_070636_267511`) plus two
matched no-pass controls (`x86_kvm_corpus_20260926_071903_072417`,
`x86_kvm_corpus_20260926_073026_776920`), each with its own make-console log
and the MI run retaining per-step bytecode. The retained report stream gives 19
changed load instances totalling 83 applied sites (instruction counts
2,263 → 1,530), all 19 of whose retained before/after images match the reported
counts and differ; the throughput derivation gives median raw 1.0107x, no-pass
control median 1.0032x (controls 0.9995/1.0068), control-corrected 1.0075x over
3+3 samples at 60 s. BCC's fresh workload is a single component-less stress-ng
run, so its rate scalar is the same workload-level `stress-ng: metrc:` bogo-ops
column as the ninth and tenth derivations. The May BCC batch's independent
generation reports `0.7921`; the fresh corrected ratio sits within restart drift
of neutral on the other side of 1.0, so the row claims the controlled
measurement rather than a speedup, and the two generations are never merged.
The renderer's single generic builder now serves five fresh triplets, each gated
on its own app record and report path and each carrying its own frozen declared
constants, so a BCC triplet cannot be satisfied by Katran, Cilium, Tetragon, or
Tracee files.

A twelfth derivation repeats the **fresh provenance-complete** treatment for
the sixth and last application:
`docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/` carries one
`map_inline` run (`x86_kvm_corpus_20260926_082957_279287`) plus two matched
no-pass controls (`x86_kvm_corpus_20260926_084138_823558`,
`x86_kvm_corpus_20260926_085249_602113`), each with its own make-console log
and the MI run retaining per-step bytecode. The retained report stream gives 13
changed load instances totalling 1,078 applied sites (instruction counts
53,346 → 24,566), all 13 of whose retained before/after images match the
reported counts and differ; the throughput derivation gives median raw 1.0188x,
no-pass control median 0.9435x (controls 1.0228/0.8643), control-corrected
1.0798x over 3+3 samples at 60 s. Unlike BCC/Tetragon/Tracee, otelcol's fresh
workload is composite — five interpreter sha256 workers plus one `stress-ng
--cpu` component — but the interpreters' own stdout matches no recognized rate
shape, so the derived scalar is the stress-ng component's `stress-ng: metrc:`
bogo-ops column, which the shared summed extractor already sums over the
workload's rate-bearing components. The May otelcol batch's independent
generation reports `0.9983`; the fresh corrected ratio is above 1.0 on the
other side, so the row claims the controlled measurement rather than a speedup,
and the two generations are never merged. The renderer's single generic builder
now serves six fresh triplets (one per supported application), each gated on
its own app record and report path and each carrying its own frozen declared
constants, so an otelcol triplet cannot be satisfied by any other app's files.

At least one author must be reachable during kick-the-tires (through
2026-09-29). The `\acmDOI`/`\acmISBN` fields in `docs/paper/main.tex` are
template placeholders and require the actual camera-ready identifiers.

**Measurement boundary.** The paper-scale x86 Xeon and ARM64 AWS figures were
not re-measured while preparing this package. A fresh local KVM six-application
corpus run `x86_kvm_corpus_20260923_114624_121697` reached terminal success
(suite `completed`, all six apps `ok`, all six ReJIT `ok`) under the default
`full-x86` policy and is retained, hash-bound, at
`docs/artifacts/evidence/kvm-six-app-success/`. Its `make corpus` log shows every
step of the 11-step load-time plan completing for the previously failing heavy
Tracee program `trace_security_`. This establishes six successful workloads, but
it is a single-sample 10-second configuration, not a paper-scale Xeon/AWS rerun.
The earlier six-app preparation run `x86_kvm_corpus_20260921_211712_637406` has
top-level status `error`; its hash-bound compact evidence
(`docs/artifacts/evidence/kvm-six-app-coverage/`) supports ReJIT/KOperation
*coverage* only and is retained as the honest negative record. The separate
Katran smoke `x86_kvm_corpus_20260922_213414_889964` supports one successful
workload.

---

## 13. Reproducibility platform (short text for the submission form)

> BPF-Ext reproduces on Ubuntu 24.04 x86-64. A fast path requiring no VM runs the
> Lean 4 proof suite, the generated-contract drift checks, and the independent C
> host cross-checks (`make -C native-sim/formal check`; `make -C native-sim/x86
> micro-proofs-build`). End-to-end measurement uses an in-repo Linux
> `7.0.0-rc2+` kernel inside KVM via virtme-ng, driven only through `make`
> targets; the smallest end-to-end experiment is
> `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 make corpus`.
> Dependencies are clang/LLVM 18, gcc 13, cmake, Python 3 + PyYAML, Rust
> (rustup), Go, Docker, virtme-ng, and the Lean 4 toolchain pinned by
> `native-sim/formal/lean-toolchain` (`leanprover/lean4:v4.19.0`). One-time kernel
> and image builds dominate runtime (hours) and disk (~25–40 GB); the guest
> measurement itself is ~2 minutes. Full paper-scale runs (both architectures)
> additionally require AWS `t4g.small` for the ARM64 column.
