# K2 / Merlin on BPF Benchmark: Feasibility and Run Plan

Date: 2026-06-26

This is an exploration note, not a canonical architecture document. The
benchmark contract remains the root `Makefile`, `docs/tmp/bpfopt_design_v3.md`,
and the repository-level benchmark rules.

## Short Answer

K2 and Merlin can be evaluated with this benchmark harness, but they should not
be treated as new benchmark apps. They are optimizer treatments over the same
apps and workloads.

The practical path is:

1. Qualify each optimizer outside the benchmark path on saved objects or raw
   bytecode fixtures.
2. Add one explicit third-party optimizer mode at a time.
3. Run selected corpus apps through `make corpus`, with baseline using the
   unmodified real app startup and post phase using the optimizer treatment.
4. Keep `result.json` raw. Do all ratios, geomeans, win/loss counts, and
   summaries in external analysis scripts only.

Merlin is the more plausible all-corpus candidate because it was designed for
multi-tier eBPF optimization and was evaluated on Tracee and Tetragon-scale
systems. K2 is useful as a strong prior-work point, but its prototype is older,
stochastic, and the paper itself flags scaling limits on larger programs.

## External Tool Facts

K2:

- Upstream compiler source is `smartnic/superopt`; the artifact notes point to
  public source and a Docker artifact.
- It accepts BPF C macros, K2's own instruction format, and pre-compiled BPF
  object files, producing optimized output in the same format.
- The K2 paper describes it as BPF bytecode-to-bytecode synthesis with formal
  equivalence and safety checks, followed by kernel checker validation.
- Main risk: compile time and scale. The paper says 200+ instruction programs
  are not optimized quickly by the prototype, and the artifact uses selected
  programs that can finish within bounded time.

Merlin:

- Upstream source is `4ar0nma0/Merlin`.
- It has LLVM IR passes (`alignbpf`, `atomicbpf`) invoked via `opt`, plus Python
  bytecode optimization scripts that operate on `.o` files.
- The paper positions Merlin as pre-verification optimization using LLVM IR
  transformation plus bytecode refinement.
- It was evaluated on XDP programs and complex systems including Tracee and
  Tetragon, which makes it a better fit for this corpus than K2.

Useful references:

- K2 project page: <https://k2.cs.rutgers.edu/>
- K2 source: <https://github.com/smartnic/superopt>
- K2 artifact: <https://github.com/smartnic/sigcomm21_artifact>
- Merlin source: <https://github.com/4ar0nma0/Merlin>
- Merlin paper: <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>

## Current Benchmark Hooks

The supported run surface is still:

```sh
make corpus
BPFREJIT_CORPUS_APPS="katran" SAMPLES=1 WORKLOAD_DURATION=10 make corpus
BPFREJIT_CORPUS_APPS="tracee/monitor,tetragon/observer" SAMPLES=1 WORKLOAD_DURATION=10 make corpus
```

The current corpus lifecycle is important:

- Baseline phase starts the real app, lets it load its own BPF programs, runs
  the workload, collects raw BPF counters, then stops the app.
- Post phase starts the real app again. If `BPFREJIT_SHIM_LOADTIME_PLAN` is set,
  the shim intercepts each `BPF_PROG_LOAD`, writes raw bytecode to a workdir,
  runs each configured pass command, verifier-probes each candidate, then lets
  the optimized bytecode become the app-loaded program.
- Pass commands come from `runner/config/passes/<pass>/default.yaml` and receive
  `${INPUT}`, `${OUTPUT}`, `${REPORT}`, `${PROG_TYPE}`, `${TARGET}`,
  `${MAP_IDS}`, and `${MAP_VALUES}`.

This means the easiest benchmark-compatible insertion point is a load-time pass
whose command reads raw `struct bpf_insn[]` from `${INPUT}` and writes raw
`struct bpf_insn[]` to `${OUTPUT}`.

The catch: K2 and Merlin are not natively raw-bytecode CLIs in that exact shape.
They mostly expect `.bpf.o`, LLVM IR, BPF macro text, or tool-specific text.
That is the central integration task.

## Integration Options

### Option A: Raw-Bytecode Load-Time Adapter

Add pass configs such as:

```text
runner/config/passes/k2/default.yaml
runner/config/passes/merlin_bytecode/default.yaml
```

Each command should call a small wrapper:

```sh
third-party-bpfopt --tool k2 \
  --input ${INPUT} --output ${OUTPUT} --report ${REPORT} \
  --prog-type ${PROG_TYPE} --target ${TARGET} \
  --map-ids ${MAP_IDS} --map-values ${MAP_VALUES}
```

The wrapper must:

- consume canonical raw bytecode and emit canonical raw bytecode;
- preserve map references, subprogram calls, helper calls, and program type
  assumptions;
- exit nonzero on unsupported opcodes, maps, helpers, subprogram metadata, or
  tool failure;
- never silently return the input as a fallback;
- write only diagnostic tool metadata, not performance summaries.

This is the best benchmark shape because baseline and treatment happen inside
one `make corpus` invocation and all app startup remains real.

Feasibility:

- K2 may be adaptable by converting raw bytecode to K2's instruction language or
  BPF macro form, then converting the output back.
- Merlin's Python bytecode stage appears object-oriented, so it likely needs
  either a minimal ELF rehydration adapter or direct extraction of the
  bytecode-rewrite logic.
- Merlin's LLVM IR passes cannot use this path because load-time interception
  no longer has LLVM IR.

### Option B: App Artifact Replacement

Build an optimizer-specific app artifact before the runtime image is assembled:

```text
original upstream source/object -> K2 or Merlin -> optimized .bpf.o / embedded asset
```

Then run the same real app binary/launcher and workload through `make corpus`.
This is the right path for Merlin's LLVM IR passes and for K2 object-file mode.

Rules for this path:

- The real upstream app binary must still load its own BPF programs.
- Do not add a bpftool/libbpf custom loader to replace the app.
- Transform every BPF object needed by the selected app, or fail the build.
  Partial optimizer coverage would hide unsupported programs.
- Keep transformed artifacts in image layers, not host bind mounts.
- Makefile edits must be local to the owning build rule. Do not add root alias
  targets just for convenience.

Feasibility by app:

- `katran`: good K2 first target because it is XDP-heavy and has stable BPF
  objects. It also has a host fixture in `bpfopt-loader` for functional smoke,
  but the benchmark run must still be `make corpus`.
- `cilium/agent`: possible but large and tail-call heavy; transformed artifact
  inventory must be exact.
- `tracee/monitor` and `tetragon/observer`: better Merlin targets because
  Merlin evaluated similar systems. They may require source/build integration
  instead of only load-time bytecode.
- `bcc/set`: useful smoke target because the app runner is simpler, but it may
  not exercise the same optimizer strengths as XDP/security-agent programs.
- `otelcol-ebpf-profiler`: later target; tail-call accounting makes coverage
  interpretation subtle.

### Option C: Direct Offline Micro/Loader Smoke

Use `bpfopt-loader` or saved corpus objects only to prove the external tool can
produce verifier-accepted bytecode. This is not a benchmark result.

This phase is still valuable because it catches:

- toolchain build problems;
- object format assumptions;
- map relocation and pseudo-map handling;
- verifier rejection before running a multi-hour corpus job.

Do not cite this as app-level performance evidence.

## Recommended Phase Plan

### Phase 0: Tool Reproduction

Goal: pin the external tools and prove we can build them reproducibly.

Tasks:

- Build K2 from `smartnic/superopt` at a pinned commit or release tag.
- Build Merlin from `4ar0nma0/Merlin`, including its LLVM pass dependencies and
  Python dependencies (`lief`, `numpy`).
- Record tool commit, build image/base OS, LLVM version, Z3 version for K2, and
  command-line seed or timeout knobs if available.
- Keep this outside the runtime benchmark until a smoke artifact passes.

Exit criteria:

- Each tool optimizes its own upstream sample.
- Each tool can be invoked by a noninteractive wrapper that exits nonzero on
  failure.

### Phase 1: Bytecode/Object Smoke

Goal: verify kernel acceptance on repo-controlled BPF artifacts.

Candidate artifacts:

- K2: `bpfopt/testobject/katran_balancer.bpf.o`, then a smaller XDP object if
  K2 compile time is too high.
- Merlin: Tracee/Tetragon sample objects if the Python bytecode optimizer can
  run directly; otherwise start with a small object and then a Tracee object.

Checks:

- optimized output is verifier-accepted;
- no unsupported program is quietly passed through;
- output can be converted to raw `struct bpf_insn[]` if Option A is used;
- for Katran, `bpfopt-loader --bpftestrun --katran-maps --repeat 1` remains a
  functional smoke only.

### Phase 2: One-App Corpus Smoke

Goal: run one full benchmark lifecycle through `make corpus`.

If Option A exists:

```sh
BPFREJIT_CORPUS_APPS="katran" \
BPFREJIT_BENCH_PASSES="k2" \
SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

```sh
BPFREJIT_CORPUS_APPS="tracee/monitor" \
BPFREJIT_BENCH_PASSES="merlin_bytecode" \
SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

If only Option B exists, add one explicit post-only artifact-selection env first
and keep the public invocation as `make corpus`, for example:

```sh
BPFREJIT_CORPUS_APPS="tracee/monitor" \
BPFREJIT_THIRD_PARTY_ARTIFACT_POST_ONLY="merlin" \
SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

That env does not exist today; it is the proposed runner surface if artifact
replacement is chosen.

Exit criteria:

- baseline and post phases both start the real app;
- every loaded BPF program in the selected app is either optimized or the run
  fails with an explicit error;
- result path is under `corpus/results/`;
- raw counters and workload stdout/stderr are preserved.

### Phase 3: Scoped Corpus Expansion

K2 expansion order:

1. `katran`
2. selected Cilium network programs only if the whole `cilium/agent` app can be
   transformed without per-program exclusions
3. stop if K2 cannot handle non-XDP/tracing programs without fallback

Merlin expansion order:

1. `tracee/monitor`
2. `tetragon/observer`
3. `katran`
4. `bcc/set`
5. `cilium/agent`
6. `otelcol-ebpf-profiler/profiling`

Use smoke settings first:

```sh
SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_APPS="<app>" make corpus
```

Then authoritative settings:

```sh
SAMPLES=3 WORKLOAD_DURATION=30 BPFREJIT_CORPUS_APPS="<app>" make corpus
```

Do not increase AWS instance class beyond the project cap to compensate for
tool runtime. Optimize build caching and choose scoped apps instead.

## Required Implementation Boundaries

Do:

- Keep all benchmark execution behind `make <target>`.
- Keep real app startup and app-owned BPF loading.
- Let optimizer failures surface as run errors.
- Preserve raw per-program counters only.
- Put any derived analysis in external scripts outside the framework.
- Pin external tool revisions and record the exact command used.

Do not:

- add `live_rejit_programs()` filters;
- add per-program or per-prog-type exclusions to benchmark config;
- use `LifecycleAbort` to skip unsupported programs;
- direct-load `.bpf.o` with bpftool or a custom replacement loader for corpus
  measurements;
- add summary, ratio, geomean, win/loss, or markdown rollup generation to the
  framework;
- silently pass original bytecode through when K2/Merlin cannot transform it.

## Feasibility Verdict

Merlin: feasible, with meaningful corpus value, but likely needs an artifact
replacement path for the full LLVM IR stage. A raw-bytecode adapter may be
possible only for its Python bytecode stage.

K2: feasible as a scoped prior-work comparison on XDP-style objects, especially
Katran. It is not a realistic all-6-app treatment unless its supported opcode,
helper, map, and program-type coverage is first proven against the corpus.

The next concrete action is Phase 0 plus one Phase 1 smoke for each tool. Only
after those pass should we add `runner/config/passes/k2` or
`runner/config/passes/merlin_bytecode`, or an artifact post-only runner surface.
