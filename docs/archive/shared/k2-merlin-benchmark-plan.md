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

## 2026-06-27 Execution Update

Load-time compatibility adapters were added for the existing corpus shim so K2
and Merlin can be invoked through the normal `make corpus` surface. These runs
produce complete raw baseline/post counter datasets, but they are not
paper-grade optimizer performance results:

- K2 is invoked on raw `struct bpf_insn[]` input. If the current prototype cannot
  consume the program or metadata within the configured budget, the adapter
  records a per-program diagnostic and leaves the bytecode unchanged.
- Merlin v0.01 is an LLVM IR optimizer plugin, not a raw load-time bytecode
  optimizer. The load-time adapter records that boundary mismatch and leaves the
  bytecode unchanged.

Full 6-app KVM smoke datasets were collected with `SAMPLES=1` and
`WORKLOAD_DURATION=5`:

```sh
BPFREJIT_BENCH_PASSES="k2" \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 \
BPFREJIT_K2_NITER=1 BPFREJIT_K2_TIMEOUT=1 KEEP_WORKDIRS=1 \
  make corpus
```

Result:

- Artifact: `corpus/results/x86_kvm_corpus_20260627_055138_934572`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Changed bytecode outputs: 0
- Diagnostic distribution: 536 `k2_failed`, 119 unchanged with no failure
  reason, 85 `unsupported_map_metadata`

```sh
BPFREJIT_BENCH_PASSES="merlin" \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

Result:

- Artifact: `corpus/results/x86_kvm_corpus_20260627_061142_094340`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Changed bytecode outputs: 0
- Diagnostic distribution: 740 `not_applicable_loadtime`

The next step for real optimizer performance is still artifact-level
integration: Merlin must run before BPF code generation on LLVM IR, and K2 needs
an object/source-level path that preserves the real app loader contract.

After replacing cwd-dependent pass script paths with
`${BPFREJIT_REPO_ROOT}/runner/config/passes/...`, the path fix was validated
with focused `bcc/set` KVM smokes:

- K2: `corpus/results/x86_kvm_corpus_20260627_063123_950147`, metadata
  `completed`, app `ok`, 77 load-time reports.
- Merlin: `corpus/results/x86_kvm_corpus_20260627_063958_892569`, metadata
  `completed`, app `ok`, 77 load-time reports.

Later K2 testing exposed one unsafe transformed output on Cilium's large-program
feature probe. K2 replaced part of a long `r0 = 1; ...; exit` return-filler
program with a context load, and the kernel verifier rejected it with
`invalid bpf_context access off=2 size=8`. The load-time adapter now treats this
return-filler shape as unsupported and leaves it unchanged; it also rejects K2
outputs that introduce non-ALU/MOV memory or control-flow instructions outside
the selected K2 windows. A focused Cilium rerun then completed:

- Failed pre-fix artifact:
  `corpus/results/x86_kvm_corpus_20260627_071606_708070`
- Fixed Cilium smoke:
  `corpus/results/x86_kvm_corpus_20260627_072933_922059`
- Fixed Cilium status: metadata `completed`, app `ok`, 169 K2 reports,
  0 applied, 0 changed.

The current K2 full 6-app dataset after that safety fix is:

```sh
BPFREJIT_BENCH_PASSES="k2" \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 \
BPFREJIT_K2_NITER=200 BPFREJIT_K2_TIMEOUT=45 KEEP_WORKDIRS=1 \
  make corpus
```

Result:

- Artifact: `corpus/results/x86_kvm_corpus_20260627_073705_300047`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Load-time reports: 740
- Applied K2 sites: 0
- Changed bytecode outputs: 0
- Unsafe K2 outputs accepted by the adapter: 0
- Diagnostic distribution: 287 `k2_failed`, 198 unchanged with no failure
  reason, 170 `no_candidate_windows`, 85 `unsupported_map_metadata`.

External post-hoc performance calculation, using only raw per-program counters
and matching unique `(app, name, type, bytes_xlated)` programs with
`min(baseline_runs, post_runs) >= 100`, retained 43 programs. The post/base
per-program geomean ratio was 0.983758, with 26 ratios below 1.0 and 17 above
1.0. Because the load-time reports show 0 applied and 0 changed programs, this
number is a no-op/plumbing measurement and must not be cited as K2 optimizer
speedup.

The corresponding Merlin no-op adapter dataset remains
`corpus/results/x86_kvm_corpus_20260627_061142_094340`. The same external
calculation retained 43 programs and produced a post/base geomean ratio of
0.984995, with 29 ratios below 1.0 and 14 above 1.0. Since Merlin's adapter
records `not_applicable_loadtime` for all 740 programs, this is also not Merlin
optimization performance.

Merlin changed-bytecode follow-up:

- Integration: host-prepared Katran `balancer_ingres` raw artifacts generated
  from real Katran BPF source after Merlin v0.01 LLVM IR passes, then selected
  by exact input SHA at load time.
- Added make/env surface: `MERLIN_ARTIFACT_MODE=atomic|align|both`.
- Katran-only smokes:
  - `atomic`: `corpus/results/x86_kvm_corpus_20260627_081509_080144`,
    2542 -> 2496 insns, ratio 1.04244.
  - `align`: `corpus/results/x86_kvm_corpus_20260627_082447_495747`,
    2542 -> 2543 insns, ratio 1.000106.
  - `both`: `corpus/results/x86_kvm_corpus_20260627_083226_669233`,
    2542 -> 2497 insns, ratio 1.015827.
- Full 6-app dataset:
  `corpus/results/x86_kvm_corpus_20260627_083921_948067`
- Command:
  `BPFREJIT_BENCH_PASSES="merlin" MERLIN_ARTIFACT_MODE=align SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Metadata/app status: `completed`, all six supported apps `ok`
- Load-time reports: 740
- Applied/changed outputs: 1/1
- Applied program: Katran `balancer_ingres` (`xdp`), input SHA-256
  `1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e`,
  output SHA-256
  `d2eb1c90f985a51a9b5ecf875ba02c2d380361f05feb0b91cfe35cd4301e95a4`,
  2542 -> 2543 insns.
- External post-hoc retained-program result, using unambiguous `(app, name,
  type)` matches and `min_runs >= 100`: retained 48, geomean ratio 1.037160,
  wins/losses 25/23.
- Changed-program result: Katran `balancer_ingres` baseline 170.700181 ns/run,
  post 169.342330 ns/run, ratio 0.992045.

Interpretation: this is the first Merlin run in this investigation with real
changed bytecode through the standard 6-app `make corpus` path. It should be
reported as a scoped Katran artifact result, not as a broad Merlin improvement
over all six apps.

Merlin compile-time source/IR follow-up:

- Rationale: Merlin v0.01's natural boundary is LLVM IR, so the fairer path is
  to run Merlin while building the app BPF object, before app startup. The
  earlier load-time artifact replacement was a diagnostic bridge, not the final
  methodology.
- Integration: Katran BPF objects now build as `clang -emit-llvm`, optional
  `opt-18 -load-pass-plugin ... -passes=<merlin-pass>`, then `llc-18 -march=bpf
  -filetype=obj`. The real Katran binary and its app loader still load the
  resulting `.bpf.o`.
- Added make/env surface: `MERLIN_COMPILETIME_MODE=none|roundtrip|atomic|align|both`.
  `MERLIN_BUILD_DIR` points at the Merlin v0.01 LLVM 18 build.
- Baseline command:
  `MERLIN_COMPILETIME_MODE=none BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop" SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Baseline artifact:
  `corpus/results/x86_kvm_corpus_20260627_092713_638052`
- Treatment command:
  `MERLIN_COMPILETIME_MODE=align BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop" SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Treatment artifact:
  `corpus/results/x86_kvm_corpus_20260627_093432_232197`
- Metadata/app status: both `completed`, Katran app `ok`.
- Object evidence: `balancer.bpf.o` `xdp` section changed from 18,544 bytes
  to 18,552 bytes in the compile-time align build.
- External post-hoc comparison of the same `baseline` phase, matching by
  program name:
  - `none`: 11,992,256 runs, 2,112,979,091 ns, 176.195296 ns/run
  - `align`: 12,486,876 runs, 2,116,520,895 ns, 169.499633 ns/run
  - ratio `align/none`: 0.961999, about 3.95% faster
  - workload-side pktgen total pps: 2,449,641 -> 2,539,142, about 3.65% higher
- External post-hoc comparison of the same `post_rejit`/`noop` phase:
  - `none`: 12,313,162 runs, 2,155,105,202 ns, 175.024515 ns/run
  - `align`: 12,812,124 runs, 2,151,658,495 ns, 167.939250 ns/run
  - ratio `align/none`: 0.959518, about 4.22% faster
  - workload-side pktgen total pps: 2,507,442 -> 2,615,561, about 4.31% higher

Interpretation: this is the cleanest Merlin comparison so far because both
datasets use the same app, workload, Makefile path, runtime image flow, and
noop ReJIT policy, while changing only the BPF object build mode. It should be
reported as a Katran compile-time Merlin result, not as full-corpus coverage.
The next paper-grade step at that point was
`SAMPLES=3 WORKLOAD_DURATION=30` for Katran; the late update below records that
run and leaves Tracee/Tetragon source/IR expansion as the next coverage step.

2026-06-27 late update: the source/IR path is now the active Merlin path, not a
future-only plan.

Implemented compile-time integration:

- Added a BPF clang wrapper that supports
  `MERLIN_COMPILETIME_MODE=none|roundtrip|atomic|align|both`.
- For BPF compilation, the wrapper emits LLVM bitcode, runs Merlin LLVM passes
  with `opt-18`, then lowers with `llc-18 -march=bpf* -filetype=obj`.
- Wired host source-app builds so Katran, Tracee, Tetragon, BCC, and
  OTel profiler BPF builds can use the wrapper without replacing the real app
  loader.
- The runtime image carries the Merlin wrapper and plugin libraries so app-side
  rebuilds use the same mode inside the benchmark runtime.
- Katran has a dedicated source-to-IR-to-object helper because its BPF build is
  not a simple one-command clang invocation.

Compatibility fixes made during the source/IR work:

- `AtomicBPF` was made verifier-safer by avoiding unsafe atomic rewrites on
  dynamically indexed or unsupported pointer shapes. A focused Tracee atomic
  smoke completed with status `ok`:
  `corpus/results/x86_kvm_corpus_20260627_111656_888037`.
- `AlignBPF` stopped promoting exotic pointer-derived alignment and stopped
  increasing alloca alignment after Tracee exceeded the BPF stack limit. After
  the fix, `MERLIN_COMPILETIME_MODE=align make -C vendor tracee-x86 ...`
  completed.
- Cilium atomic source/IR smokes completed with status `ok`:
  `corpus/results/x86_kvm_corpus_20260627_102232_231939` and
  `corpus/results/x86_kvm_corpus_20260627_104055_859181`.

Katran `SAMPLES=3 WORKLOAD_DURATION=30` source/IR A/B:

```sh
MERLIN_COMPILETIME_MODE=none \
BPFREJIT_CORPUS_APPS="katran" \
BPFREJIT_BENCH_PASSES="noop" \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_112807_015471`
- Status: Katran app `ok`

```sh
MERLIN_COMPILETIME_MODE=align \
BPFREJIT_CORPUS_APPS="katran" \
BPFREJIT_BENCH_PASSES="noop" \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_114256_479291`
- Status: Katran app `ok`

External post-hoc comparison, matching the directly counted Katran XDP program
`balancer_ingres` and retaining it under the `min_runs >= 100` rule:

- Baseline phase:
  - `none`: 219,677,616 runs, 40,607,325,708 ns,
    184.849629 ns/run
  - `align`: 230,417,263 runs, 39,486,220,703 ns,
    171.368326 ns/run
  - ratio `align/none`: 0.927069, about 7.87% faster
  - raw pktgen total pps samples:
    `none` [2,478,958, 2,440,525, 2,407,433],
    `align` [2,563,646, 2,548,540, 2,573,866]
  - average pktgen throughput delta: +4.90%
- Post/noop phase:
  - `none`: 226,101,209 runs, 39,744,564,089 ns,
    175.782183 ns/run
  - `align`: 230,450,501 runs, 38,886,169,133 ns,
    168.739790 ns/run
  - ratio `align/none`: 0.959937, about 4.17% faster
  - raw pktgen total pps samples:
    `none` [2,494,325, 2,507,874, 2,538,924],
    `align` [2,524,074, 2,565,663, 2,596,871]
  - average pktgen throughput delta: +1.93%

Interpretation:

- The earlier "no speedup" result was expected for load-time K2/Merlin because
  K2 changed 0/740 programs and load-time Merlin changed only 1/740 programs in
  the full corpus. A no-op treatment can only measure benchmark variance and
  plumbing, not optimizer speedup.
- The fair Merlin comparison is source/IR `none` vs source/IR `align` or
  `atomic`, with the same app, same Makefile entrypoint, same workload, same
  runtime image flow, and `BPFREJIT_BENCH_PASSES=noop` to isolate compile-time
  object differences.
- The current Katran `SAMPLES=3/30s` data shows a real compile-time Merlin
  effect, but it is still a scoped one-app result. It is not yet a full-corpus
  Merlin claim.
- K2 should not be forced into this LLVM IR path: K2 is a bytecode/window
  superoptimizer, not an LLVM IR pass. A fair K2 path needs an object-level
  rewrite that preserves ELF sections, BTF, maps, relocations, and real app
  loader metadata, or a source-level frontend that K2 does not currently expose.

2026-06-27 full 6-app source/IR no-ReJIT update:

The full-corpus source/IR path was switched away from `BPFREJIT_BENCH_PASSES=noop`
for the fairness run. `noop` is still a load-time ReJIT pass, and layering it on
top of Merlin-produced BPF objects exposed verifier failures in OTel/Tetragon.
For a pure compile-time comparison, both arms should use real app startup and
skip load-time ReJIT:

```sh
MERLIN_COMPILETIME_MODE=none \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_122922_140023`
- Status: all six apps `ok`
- Program counts by app, baseline/post repeat:
  `bcc` 25/25, `cilium` 62/53, `katran` 1/1, `otel` 13/13,
  `tetragon` 287/287, `tracee` 151/151

```sh
MERLIN_COMPILETIME_MODE=align \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_130407_306689`
- Status: all six apps `ok`
- Program counts by app, baseline/post repeat:
  `bcc` 25/25, `cilium` 62/62, `katran` 1/1, `otel` 13/13,
  `tetragon` 287/287, `tracee` 151/151

Preceding full-corpus smoke:

```sh
MERLIN_COMPILETIME_MODE=align \
SKIP_REJIT=norejit \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_121639_807616`
- Status: all six apps `ok`

External post-hoc comparison, matching by app result file and `(name, type)`;
duplicate logical program names are paired by descending `run_cnt_delta`.
Programs are retained only when `min(none_runs, align_runs) >= 100`.

- Baseline phase:
  - retained programs: 72
  - geomean ratio `align/none`: 1.013690
  - speedup: 0.986495x, so `align` is about 1.35% slower in this window
  - wins/losses: 34/38
  - by app: BCC 1.021684x, Cilium 0.776589x, Katran 1.006693x,
    OTel 1.053048x, Tetragon 0.986069x, Tracee 0.982790x
- Post/no-ReJIT repeat phase:
  - retained programs: 72
  - geomean ratio `align/none`: 0.985603
  - speedup: 1.014607x, so `align` is about 1.46% faster in this window
  - wins/losses: 46/26
  - by app: BCC 1.037553x, Cilium 0.998015x, Katran 1.010903x,
    OTel 1.037658x, Tetragon 1.001006x, Tracee 1.013029x

Interpretation:

- Source/IR Merlin `align` now works across the six supported corpus apps under
  the normal `make corpus` entrypoint and real app-owned loaders.
- The full-corpus performance result is neutral, not a robust speedup. The two
  workload windows disagree in sign, and the strongest positive single-app
  result remains the scoped Katran source/IR A/B above.
- The main offsets are Cilium's baseline slowdown on the two retained programs
  and mixed Tracee/Tetragon effects. BCC, Katran, and OTel are positive but not
  enough to dominate the full suite.
- The next fairness fix was to use `MERLIN_COMPILETIME_MODE=roundtrip` as the
  no-pass arm. `roundtrip` uses the same clang bitcode to `llc` path as the
  `align` arm, minus the Merlin pass, while `none` remains the normal direct
  clang path for default wrapper builds. Katran's dedicated helper already uses
  the bitcode-to-`llc` lowering shape for its source/IR build, but the explicit
  `roundtrip` label keeps the full-corpus baseline unambiguous.
- K2 still needs a separate object/bytecode-level source build path. It should
  not be compared through Merlin's LLVM IR wrapper.

2026-06-27 full 6-app `roundtrip` fairness update:

The no-pass source/IR arm was added and validated across the full corpus:

```sh
MERLIN_COMPILETIME_MODE=roundtrip \
SKIP_REJIT=norejit \
SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

- Smoke artifact: `corpus/results/x86_kvm_corpus_20260627_134500_117852`
- Status: all six apps `ok`
- Program counts by app, baseline/post repeat:
  `bcc` 25/25, `cilium` 62/60, `katran` 1/1, `otel` 13/13,
  `tetragon` 237/234, `tracee` 151/151

```sh
MERLIN_COMPILETIME_MODE=roundtrip \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_135722_307540`
- Metadata status: `completed`
- App status: all six supported apps `ok`
- Program counts by app, baseline/post repeat:
  `bcc` 25/25, `cilium` 56/53, `katran` 1/1, `otel` 13/13,
  `tetragon` 287/287, `tracee` 151/151

External post-hoc comparison against the existing `align` full-corpus dataset
`corpus/results/x86_kvm_corpus_20260627_130407_306689`, matching by app result
file and `(name, type)` and pairing duplicate logical names by descending
`run_cnt_delta`:

- Baseline phase:
  - retained programs: 72
  - geomean ratio `align/roundtrip`: 1.007935
  - speedup: 0.992127x, so `align` is about 0.79% slower in this window
  - wins/losses: 31/41
  - by app: BCC 1.037937x, Cilium 0.755926x, Katran 0.983208x,
    OTel 0.989944x, Tetragon 1.002127x, Tracee 0.982476x
- Post/no-ReJIT repeat phase:
  - retained programs: 72
  - geomean ratio `align/roundtrip`: 1.001105
  - speedup: 0.998896x, effectively neutral
  - wins/losses: 35/37
  - by app: BCC 1.012167x, Cilium 0.797539x, Katran 0.977668x,
    OTel 1.000577x, Tetragon 0.998242x, Tracee 1.007566x

Interpretation: `roundtrip` confirms the source/IR integration itself works
under real app-owned loaders, but Merlin `align` does not produce a robust
full-corpus speedup. The pass is locally helpful for some programs/apps,
especially BCC in this full-corpus run and Katran in the scoped A/B above, but
the aggregate is neutral once the no-pass arm uses the same IR lowering path.

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

## 2026-06-27 Final Full-Corpus Update

This late update resolves the "why not source/IR compile integration" question:
that is now exactly how Merlin is evaluated. K2 is different. Upstream K2 is an
eBPF bytecode/window superoptimizer, not an LLVM IR compiler pass. Forcing K2
through Merlin's LLVM IR wrapper would evaluate a new reimplementation or a
different optimizer boundary, not upstream K2. The fair K2 comparison is to
build upstream K2 from source, invoke it at the BPF bytecode/object boundary,
and preserve real app-owned loading.

Implemented fairness split:

- Merlin source/IR path: `clang -emit-llvm`, optional Merlin `opt-18` pass,
  `llc-18 -march=bpf* -filetype=obj`, then the real app loader loads the
  resulting BPF object.
- Merlin no-pass control: `MERLIN_COMPILETIME_MODE=roundtrip`, which uses the
  same IR-to-object lowering path without a Merlin optimization pass.
- Merlin treatments: `MERLIN_COMPILETIME_MODE=align|atomic|both`.
- K2 path: upstream K2 source build from `.cache/third-party-smoke/src`, wired
  through `runner/config/passes/k2/k2_loadtime.py` as a load-time raw-bytecode
  treatment.
- Source provenance: repository `HEAD`
  `8c5b9d5a76dd54a582ec1a9ceefcd7145a55112d` with a dirty working tree
  containing the K2/Merlin integration, analysis scripts, and result artifacts.
  These runs should be archived with the worktree diff or after committing the
  integration; they are not clean-commit artifacts.

K2 fixes required before the full corpus would run:

- Patched upstream K2 `canonicalize.cc` so helper metadata without
  `CONST_PTR_TO_MAP` no longer aborts the process.
- Added branch-offset normalization and target remapping validation around K2
  windows so shorter K2 outputs can be accepted only when branch targets remain
  structurally valid.
- Added an input-model guard. K2's current adapter only treats constant-input
  programs as supported; packet/SKB/XDP/sched/cgroup/socket-filter programs are
  recorded as unsupported rather than rewritten unsafely.
- Changed the load-time shim so verifier-probe rejection of a candidate is
  logged and the original app `BPF_PROG_LOAD` continues. This prevents a rejected
  third-party candidate from breaking real app startup.
- Added a default K2 input-size guard of 1600 BPF instructions. The previous
  2000-instruction setting still let Tracee get killed during post startup.

Full K2 corpus command:

```sh
BPFREJIT_BENCH_PASSES="k2" \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
BPFREJIT_K2_NITER=200 KEEP_WORKDIRS=1 \
  make corpus
```

Result:

- Artifact: `corpus/results/x86_kvm_corpus_20260627_175450_331927`
- Metadata status: `completed`; `details/result.json` suite status: `ok`
- App status: all six supported apps `ok`
- Program counts by app, baseline/post:
  `bcc` 25/25, `cilium` 53/53, `katran` 1/1, `otel` 13/13,
  `tetragon` 287/151, `tracee` 151/151
- Load-time coverage command:
  `python3 analysis/loadtime_report_summary.py corpus/results/x86_kvm_corpus_20260627_175450_331927 --per-app`
- Load-time reports: 666
- Matched K2 sites: 1304
- Applied K2 sites: 3
- Changed reports: 3
- Applied reports: BCC tracepoint 116 -> 115 insns, BCC kprobe 142 -> 141
  insns, OTel kprobe 1253 -> 1248 insns.
- Skip reasons: `unchanged` 598, `unsupported_input_model` 684,
  `k2_timeout` 9.
- No-apply reasons: `input_too_large` 264, `no_candidate_windows` 168,
  `unsupported_input_model` 91, `unsupported_map_metadata` 43,
  `k2_timeout` 2.

External post-hoc K2 counter comparison, using `(name, type)` pairing with
duplicate names sorted by descending `run_cnt_delta`, retained 67 rows at
`min_runs >= 100`:

- Analysis command:
  `python3 analysis/corpus_analyze.py corpus/results/x86_kvm_corpus_20260627_175450_331927 --pair-by name-type --per-app`
- Geomean post/baseline ratio: 0.983654
- Apparent speedup: 1.016617x
- Wins/losses/ties: 40/27/0

Using the stricter stable key `(name, type, bytes_xlated, bytes_jited)`,
retained rows drop to 65 and the ratio is similar:

- Analysis command:
  `python3 analysis/corpus_analyze.py corpus/results/x86_kvm_corpus_20260627_175450_331927 --pair-by stable --per-app`
- Geomean post/baseline ratio: 0.982925
- Apparent speedup: 1.017371x
- Wins/losses/ties: 41/24/0

Interpretation: the K2 corpus now works end to end, but this is not credible
evidence of a K2 fleet speedup. Only 3 reports changed bytecode, while
Cilium, Katran, Tetragon, and Tracee had 0 applied sites. Tetragon also has a
large baseline/post program-count mismatch, so the retained counter geomean is
best treated as a plumbing/noise observation plus a tiny BCC/OTel applied
sample, not as an optimizer headline.

Full Merlin source/IR no-ReJIT datasets:

```sh
MERLIN_COMPILETIME_MODE=roundtrip \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_135722_307540`
- App status: all six supported apps `ok`

```sh
MERLIN_COMPILETIME_MODE=align \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_130407_306689`
- App status: all six supported apps `ok`

```sh
MERLIN_COMPILETIME_MODE=atomic \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_143445_964518`
- App status: all six supported apps `ok`

```sh
MERLIN_COMPILETIME_MODE=both \
SKIP_REJIT=norejit \
SAMPLES=3 WORKLOAD_DURATION=30 TIMEOUT=7200 KEEP_WORKDIRS=1 \
  make corpus
```

- Artifact: `corpus/results/x86_kvm_corpus_20260627_151129_643205`
- App status: all six supported apps `ok`

External post-hoc Merlin comparisons against the `roundtrip` no-pass arm,
matching by app result file and `(name, type)` and retaining
`min_runs >= 100`:

- Analysis command shape:
  `python3 analysis/corpus_compare.py <roundtrip-artifact> <treatment-artifact> --left-label roundtrip --right-label <mode> --left-phase <phase> --right-phase <phase> --pair-by name-type --per-app`

| Mode | Phase | Retained | Geomean treatment/roundtrip | Speedup | Wins/losses |
| --- | --- | ---: | ---: | ---: | ---: |
| `align` | baseline | 72 | 1.007935 | 0.992127x | 30/42 |
| `align` | post/no-ReJIT | 72 | 1.001105 | 0.998896x | 36/36 |
| `atomic` | baseline | 72 | 0.992141 | 1.007921x | 40/32 |
| `atomic` | post/no-ReJIT | 72 | 1.009330 | 0.990756x | 36/36 |
| `both` | baseline | 72 | 1.008544 | 0.991528x | 32/40 |
| `both` | post/no-ReJIT | 72 | 1.014216 | 0.985983x | 25/47 |

Interpretation: Merlin's source/IR integration is the fair one and it works
across all six corpus apps, but the performance result is neutral to negative
at full-corpus scope. The earlier Katran-only `align` A/B showed a real local
positive result, but the six-app run is dominated by mixed effects: Cilium and
Katran are often slower in the full-corpus source/IR arms, BCC is often faster,
and Tracee/Tetragon are close to neutral or mixed. `atomic` has one positive
baseline window but loses in the post/no-ReJIT repeat; `both` is slower in both
windows.

Bottom line:

- The source/IR compile integration exists and is now the Merlin methodology.
- K2 was also built from source, but its fair boundary is bytecode/object-level,
  not LLVM IR.
- The absence of a robust speedup is an optimizer-coverage/result issue, not a
  missing benchmark hook: Merlin has mixed full-corpus pass effects, and K2
  safely applies to only 3 changed reports in the full six-app corpus.
