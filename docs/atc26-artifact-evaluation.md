# BPF-Ext / KOperation — ATC 2026 Artifact Evaluation Guide

This document is the **artifact "read me"** for the accepted ATC 2026 paper
*"BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native
Operations"* (`docs/paper/main.tex`). It is the chronological, evaluator-facing
guide: follow the sections in order.

- Paper source: [`docs/paper/main.tex`](../docs/paper/main.tex)
- Repository root: [`README.md`](../README.md)
- Paper metadata authority: **accepted paper #1160** (see
  [Paper metadata](#1-paper-metadata)). No metadata is invented here.

> **Status / honesty note.** The framework, optimizer, KOperation modules, the
  Lean 4 proof suite, and the measurement harness are all in this repository and
  are runnable. The **full paper-scale measurements require multi-hour KVM
  builds and, for the ARM64 column, AWS instances**; the artifact therefore ships
  (a) a fast **static + proof** path that needs no VM, (b) a **single-app KVM
  smoke path**, and (c) the exact commands for the full experiments. Where a
  number in the paper is not reproduced by a one-command path, the mapping table
  in [Experiment → paper claim mapping](#experiment--paper-claim-mapping) says so
  explicitly.

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
[Author/legal action required](#author--legal-action-required).

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
| qemu-system-aarch64 | 8.2.2 |
| virtme-ng (`vng`) | 1.41 |
| docker | 29.8.0 |
| Lean (`lean-toolchain`) | `leanprover/lean4:v4.19.0` (pinned in `native-sim/formal/lean-toolchain`) |

Rust (`cargo`) and Go are also required by the full build; they are installed
through `rustup` and a Go toolchain respectively. Exact minimums are not pinned
by this guide — see [Blockers](#remaining-blockers-and-author-action-items).

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
    [Known limitations](#known-limitations-and-expected-failures).

---

## 5. Step 0 — checkout and submodules

```bash
git clone https://github.com/eunomia-bpf/bpf-benchmark.git
cd bpf-benchmark
git checkout master
git submodule update --init --recursive
```

The repository tracks submodules under `vendor/` (notably `vendor/linux-framework`
for the kernel, `vendor/libbpf`, `vendor/llvmbpf`, and `llvm-backend/llvm`). The
submodule commit pins are recorded in git, so `git submodule update` reproduces
the tested revisions exactly.

Install the Python dependency used by the harness:

```bash
pip install pyyaml
```

---

## 6. Step 1 — FAST PATH: static validation and the Lean 4 proofs (no VM)

This path needs **no KVM, no Docker, and no AWS**, and it is the first thing an
evaluator should run. It validates the artifact's *soundness* content: the
generated contracts, the Lean 4 refinement theorems, and the independent C host
cross-checks.

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
[Step 2](#7-step-2--the-kvm-single-app-smoke-path) and later, not here.

### What `make -C native-sim/formal check` does

It is the paper's **soundness check for the "native emit == proof sequence"
claim**. In order it:

1. Runs `--check` on ~50 generator scripts (e.g.
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

**Validation evidence (2026-09-22).** A full `make -C native-sim/formal check`
completed with **exit status 0**, including the generated-artifact drift checks,
the Lean module checks, and the C host cross-checks. Performance experiments were
**not** rerun as part of this documentation validation; the paper's performance
numbers are not claimed to have been re-measured here.

---

## 7. Step 2 — KVM / full validation, then the single-app smoke path

Full validation requires the runtime image and a KVM-capable host:

```bash
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
(including the KOperation-backed `kop` pass), reloads and re-attaches the
optimized bytecode through stock kernel APIs, and measures the workload in both
phases.

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
| `corpus/results/x86_kvm_corpus_20260921_211712_637406/` | `error` | 5/6 apps `ok`; `tracee/monitor` `error` | **Untracked** (regenerate with the Step 2 command). Supports *rejit/KOperation coverage*: all six apps report `rejit_result.status: ok`, and `kop` applied sites in all six with zero kop step failures. Does **not** support a claim of full workload success, because the Tracee workload launch failed. |
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
- **`modules_install: cp: cannot create ...: No such file or directory`.** A known
  environment flake on network/FUSE-backed workspaces (a dropped directory
  create). Re-run the target; it succeeds on retry. This is documented in
  `docs/tmp/20260906-bpf-development-todo.md`.
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

Each row is one command plus the paper artifact it feeds. **All of these are
Make-backed; do not call suite modules or binaries directly.**

| # | Paper claim | Command | Where the output lands | Reproduced by a single command here? |
|---|---|---|---|---|
| RQ1 x86 | micro speedup/geomean, code-size shrink | `make micro SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000` | `micro/results/` | Yes (x86, on a KVM host) |
| RQ1 arm64 | ARM64 micro speedup | `PLATFORM=aws ARCH=arm64 make micro` | `micro/results/` | Yes (needs AWS) |
| RQ1 overhead | `object_load_ns` ratio | included in `make micro` | `micro/results/` | Yes |
| RQ2 Cilium x86 | 1.074× datapath throughput, 4086 sites | `BPFREJIT_CORPUS_APPS=cilium/agent make corpus` | `corpus/results/` | Path yes; exact number is a full-scale run |
| RQ2 Katran arm64 | 1.073× throughput, 21 sites | `PLATFORM=aws ARCH=arm64 BPFREJIT_CORPUS_APPS=katran make corpus` | `corpus/results/` | Yes (needs AWS) |
| RQ3 policy | site-count vs profitability | per-app pass policy via `BPFREJIT_BENCH_PASSES` + `runner/config/passes/` | `corpus/results/` | Path yes; the two policy points are configured runs |
| RQ4 native bound | 2.358×, 488.7→262.3 ns/run | native-replacement configuration | `corpus/results/` | Configuration-dependent; see the paper's setup text |
| Correctness | "zero correctness mismatches" | printed by `make micro` / `make test` | suite output | Yes |
| Proofs | "emit computes the same result as its proof sequence" | `make -C native-sim/formal check` | stdout | **Yes** |

Composite helper targets exist for convenience: `make all` = test + micro +
corpus; `make terminate` stops managed remote instances.

### Turning raw results into the paper's figures

The paper's plots are produced by scripts in `docs/paper/scripts/`:

- `docs/paper/scripts/plot_evaluation_koperation.py` — the RQ1 micro figures
- `docs/paper/scripts/plot_app_case_studies.py` — the application case studies
- `docs/paper/scripts/plot_characterization_pure_percase.py` — the \S3 characterization

They read the raw result files described above and emit the PDFs referenced from
`docs/paper/figures/sec-6-koperation-micro-rq1.tex` and
`docs/paper/figures/sec-6-koperation-micro-rq3.tex`. They are **analysis-side**;
per the repository rule, no such computation lives in the framework.

---

## 10. Known limitations and expected failures

These are real and are documented here rather than hidden; none of them is an
artifact defect you need to work around.

1. **Some programs cannot be lifted within the 512-byte BPF frame.** The LLVM
   roundtrip that the optimizer uses re-lays out the stack and inflates the frame
   by ~45 bytes on average (measured over all 542 checked-in program fixtures;
   405 grew, 137 unchanged, none shrank). `kop` runs last in the pipeline, so a
   program starting near the limit can lose all optimization. In the shipped
   full run this affects 2 `tracee` programs (`map_inline`/`const_prop` step
   failures). Quantified in `docs/tmp/20260906-bpf-development-todo.md`.
2. **`tracee/monitor` may report an app-level error.** The shim returns
   `errno=EINVAL` for an application's own `BPF_PROG_LOAD` when an optimizer step
   fails (deliberate fail-fast policy), and some applications treat that as
   fatal. This is an application-survival effect, not a measurement gate; the
   per-program reports are still recorded.
3. **`branch_flip`** is production code but is intentionally **not** in the
   default benchmark policy; it requires real per-site PMU profile input from the
   external profiling toolchain.
4. **ARM64 numbers require AWS.** There is no local ARM64 KVM path for the
   reported configuration; QEMU is available but is not the measured platform.

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
docs/paper/                   # the accepted paper, figures, tables, plot scripts
docs/implementation.md        # current proof/coverage boundary (read this)
docs/tmp/20260906-*.md        # chronological engineering log with measurements
```

---

## 12. Artifact status and remaining external action

**Target: all three badges — Available, Functional, and Reproduced.**

Satisfied by this repository:

1. **License (Available).** ✅ `LICENSE` (MIT) is at the repository root, with the
   third-party scope stated explicitly, and `THIRD_PARTY_NOTICES.md` lists the
   exact pinned revision and license of every submodule and vendored
   application. MIT permits comparison and extension, as the checklist requires.
2. **Repository "read me" referencing the paper (Available).** ✅ This document,
   linked from `README.md`.
3. **Functional.** ✅ Components and their paper relation (§2), exact environment
   (§3), dependencies (§3), resources per experiment type (§3), safety warnings
   (§4), a no-VM minimal path (§6) and a KVM path (§7), expected outputs (§6),
   idempotence and recovery (§8), and per-claim commands (§9).
4. **Reproduced.** ✅ One command per experiment and a documented
   results→claim renderer (§9 and `docs/artifacts/render_claim_table.py`), plus
   honest status reporting for shipped data (§7).

Remaining **external** action (cannot be done from this repository):

1. **Zenodo deposit and DOI (Available).** The "Available" badge requires a
   public archive with irrevocable versioning and long-term storage. A GitHub
   repository alone does **not** satisfy it. Build the archive with
   `docs/artifacts/package-atc26.sh`, upload the resulting single ZIP to Zenodo,
   and submit the DOI. The manifest and checksum are produced by that script.
2. **HotCRP registration/submission** — intentionally not performed here.
3. **Evaluator contact** — at least one author must be reachable during
   kick-the-tires (through 2026-09-29).
4. **ACM DOI/ISBN fields** in `docs/paper/main.tex` are template placeholders and
   must be replaced with the real values at camera-ready.

**Honest boundaries (do not overstate).** The paper-scale x86 Xeon and ARM64 AWS
figures were **not** re-measured while preparing this artifact; the guide gives
the exact commands and the raw-result mapping instead. The local preparation corpus
run cited by this guide is
`x86_kvm_corpus_20260921_211712_637406`, which is **untracked** and whose
top-level status is `error` (Tracee workload launch failed) — it supports
rejit/KOperation *coverage* only, not full workload success.

If the Zenodo deposit cannot be completed before the deadline, the defensible
fallback per the AEC table is **Functional + Reproduced**.

---

## 14. Reproducibility platform (short text for the submission form)

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
