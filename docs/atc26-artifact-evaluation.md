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
  in [Experiment → paper claim mapping](#9-reproducing-the-papers-experiments) says so
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

Install the Python dependency used by the harness. The two raw-data plotting
scripts additionally need Matplotlib and NumPy:

```bash
pip install pyyaml
pip install matplotlib numpy  # only for regenerating the paper's micro figures
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
modules or binaries directly. The RQ3 policy comparison needs two runs, and a
validated one-command RQ4 native-replacement recipe is not yet documented.
Those gaps remain Reproduced work, regardless of historical metric rows.

| # | Paper claim | Command | Where the output lands | Reproduced by a single command here? |
|---|---|---|---|---|
| RQ1 x86 | micro speedup/geomean, code-size shrink | `make micro SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000` | `micro/results/` | Yes (x86, on a KVM host) |
| RQ1 arm64 | ARM64 micro speedup | `PLATFORM=aws ARCH=arm64 make micro` | `micro/results/` | Yes (needs AWS) |
| RQ1 overhead | `object_load_ns` ratio | included in `make micro` | `micro/results/` | Command path yes; retained 62-case claim `PARTIAL` |
| RQ2 Cilium x86 | 1.074× datapath throughput, 4086 sites | `BPFREJIT_CORPUS_APPS=cilium/agent make corpus` | `corpus/results/` | Path yes; exact number is a full-scale run |
| RQ2 Katran arm64 | 1.073× throughput, 21 sites | `PLATFORM=aws ARCH=arm64 BPFREJIT_CORPUS_APPS=katran make corpus` | `corpus/results/` | Yes (needs AWS) |
| RQ3 policy | site-count vs profitability | two policy-arm commands below | `corpus/results/` | `PARTIAL`: throughput raw retained, per-pass site reports missing and accepted prose pairs distinct policies |
| RQ4 native bound | 2.358×, 488.7→262.3 ns/run | no validated single-command recipe retained | `corpus/results/` | `PARTIAL`: selected metrics derive from retained Cilium JSON; 113/22/89 loader counts unavailable |
| Correctness | "zero correctness mismatches" | printed by `make micro` / `make test` | suite output | Yes |
| Proofs | "emit computes the same result as its proof sequence" | `make -C native-sim/formal check` | stdout | **Yes** |

The two RQ3 policy-arm commands below select the same pass names and 3-sample,
30-second workload settings recorded in the retained Cilium run metadata. The
original shell commands and per-pass site reports were not retained, and these
re-run recipes have not been validated against a fresh completed run:

```bash
BPFREJIT_BENCH_PASSES=kop_all_prefetch BPFREJIT_CORPUS_APPS=cilium/agent \
  SAMPLES=3 WORKLOAD_DURATION=30 make corpus
BPFREJIT_BENCH_PASSES=kop_all_no_bulk_no_prefetch BPFREJIT_CORPUS_APPS=cilium/agent \
  SAMPLES=3 WORKLOAD_DURATION=30 make corpus
```

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
- `docs/paper/scripts/plot_app_case_studies.py` -- a declarative camera-ready
  visualization of the four published summary points; its values are embedded
  in `CONFIGS`, so this script is **not** reproduction evidence

The two raw-data scripts emit the PDFs referenced from
`docs/paper/figures/sec-6-koperation-micro-rq1.tex` and
`docs/paper/figures/sec-6-koperation-micro-rq3.tex`. They are **analysis-side**;
per the repository rule, no aggregation lives in the measurement framework.
For RQ1, `docs/artifacts/render_claim_table.py` calculates the accepted
paper's x86 27-case execution geomean from the retained x86 pair, excluding
the baseline-only `simple` and `simple_packet` cases (1.241736×, displayed
as 1.242×). It derives ARM64's 27 KOperation-bearing execution cases as
1.222042× (displayed as 1.222×). Generated native-code size uses **all 29**
cases: 0.771807× x86 and 0.879116× ARM64, displayed as 0.772× and
0.879×. The older plotting script includes all 29 x86 cases for execution
time (1.215665×); that is a different population from the paper's 27 cases.

The selected Cilium corpus JSON yields RQ2 throughput 1.074262× and RQ4
native/eBPF throughput 2.357974× and BPF cost 488.676→262.298 ns/run.
Their historical per-pass site and native-loader logs are missing, so the
4086-site and 113/22/89-loader counts are **not** independently reproduced.
The RQ3 full-policy Cilium app yields 1.114172×, while the
no-bulk/no-prefetch app yields 0.999373×. The paper's table pairs the full
policy with 4697 sites and 1.114×, matching the historical summary; its
prose pairs 3512 sites with 1.114×, splicing in the no-bulk/no-prefetch
policy's historical site count. The original per-pass reports are missing,
so the site counts cannot be regenerated from the selected app JSON.

For the paper's 62-case x86 object-load claim, the two retained completed
May 14 ReJIT runs each contain 63 cases. Restricting each to the exact 62
benchmark names in the earlier April 29 run (the only extra name is
`katran_like`) gives 0.995157× and 0.997839×, respectively. Both round to
1.00× at two decimal places. The paper does not enumerate its 62 names and
states 0.99×; no completed paired 62-case ReJIT run was found among the
retained May/June x86 micro results. The renderer therefore marks this claim
`PARTIAL`. This historical-name mapping is plausible, not proven to be the
paper's exact population. A search across all current Git refs found no
May/June `details/loadtime-reports`, `loadtime-plans`, or `shim-logs`
files for the historical corpus runs; the original June 4 Cilium result
commit contains only app, result, progress, and metadata JSON. The 4086
site count remains a historical summary until the original per-pass raw log
is recovered or the experiment is rerun with matched configuration.
These are analysis-side computations. No aggregation lives in the
measurement framework, and the declarative application plot is not evidence.

---

## 10. Known limitations and expected failures

These are real limitations and failures. Some currently block a complete
Functional or Reproduced evaluation, so check each run's status rather than
assuming a command or retained directory succeeded.

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
   fatal. This is an application-survival failure and a full-corpus measurement
   blocker; the per-program reports alone do not establish a successful run.
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
docs/paper/                   # current paper source and plots; see metadata caveat above
docs/implementation.md        # current proof/coverage boundary (read this)
docs/tmp/20260906-*.md        # chronological engineering log with measurements
```

---

## 12. Artifact status and remaining action

**Target: all three badges — Available, Functional, and Reproduced. A requested
badge is not an awarded badge.** The following is the artifact author's
evidence status, not an AEC decision.

| Badge | Current evidence | Remaining acceptance work |
|---|---|---|
| Available | The public, immutable `atc26-ae-1` ZIP is deposited at [version DOI 10.5281/zenodo.22907397](https://doi.org/10.5281/zenodo.22907397); [concept DOI 10.5281/zenodo.22907396](https://doi.org/10.5281/zenodo.22907396) is the stable all-versions homepage. Repository-original material is MIT-licensed; third-party licenses and pins are in `THIRD_PARTY_NOTICES.md`. | The corrected `atc26-ae-2` draft must be packaged, independently checked and **published** before it can count as an available newer archive. Publishing a draft DOI alone does not publish its files. |
| Functional | Component map, environment, dependencies, safety notes, no-VM formal path and a completed Katran KVM smoke are documented above. | Verify the new ZIP **after clean extraction** through the documented proof/build/smoke path; an archive self-test or a successful run in the authors' checkout alone is weaker evidence. |
| Reproduced | The retained RQ1 data derive 1.242×/1.222× speedup on the respective 27-case subsets and 0.772×/0.879× code size on all 29 cases. Selected raw Cilium app JSON derives RQ2 throughput 1.074× and RQ4 throughput 2.358× and 488.7→262.3 ns/run. The formal and Katran receipts are hash-bound. | RQ1's 62-case 0.99× object-load claim is `PARTIAL`; RQ2's 4086 sites, RQ3's accepted-prose 3512-sites/1.114× pairing, and RQ4's 113/22/89 counts lack independent raw derivations. The six-app run is `error` with only 5/6 successful workloads. Row-level PASS is not a full badge verdict. |

`docs/artifacts/render_claim_table.py` separates raw-file integrity, selected
numeric claims, ReJIT coverage and full workload success. Its `PASS` is local to
the named row; it is **not** a badge verdict. In particular, the current
six-application full workload row is `PARTIAL`. The x86 micro dataset's 29
available cases are not the paper's 27-case analysis population.

At least one author must be reachable during kick-the-tires (through
2026-09-29). The `\acmDOI`/`\acmISBN` fields in `docs/paper/main.tex` are
template placeholders and require the actual camera-ready identifiers.

**Measurement boundary.** The paper-scale x86 Xeon and ARM64 AWS figures were
not re-measured while preparing this package. The retained six-app preparation
run `x86_kvm_corpus_20260921_211712_637406` has top-level status `error`; its
hash-bound compact evidence supports ReJIT/KOperation *coverage* only. The
separate Katran smoke `x86_kvm_corpus_20260922_213414_889964` completed and
supports one successful workload. Neither substitutes for all six successful
workloads or a matched paper-scale rerun.

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
