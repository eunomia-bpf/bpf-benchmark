# native-loader lib design

## Goal

Move native-lab linking/loading mechanics into `native-sim/libnativeloader` so
both frontends can use the same mechanism:

- micro runner frontend: companion `.bpf.o` + `.native.o` -> native prog fd for
  `BPF_PROG_TEST_RUN`.
- corpus shim frontend: real app `BPF_PROG_LOAD` fd + prebuilt `.native.o` ->
  native prog fd returned to the app.

The lib is a mechanism layer. It must not start apps, decide benchmark policy,
load corpus `.bpf.o` files directly, run workloads, compute summaries, or
fallback silently to original BPF.

## Public API shape

Current external contract:

```c
int native_loader_load_from_fd_with_source_path_and_attach(
    int original_prog_fd,
    const char *native_object_path,
    const char *symbol_name,
    const char *source_bpf_path,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t prog_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out);
```

`original_prog_fd` is the already-loaded oracle program:

- in micro, the runner loads a native-lab companion object and passes that fd;
- in corpus, the shim first lets the real app's `BPF_PROG_LOAD` succeed,
  resolves the prebuilt native object from
  `BPFREJIT_SHIM_NATIVE_MANIFEST`, and passes the resulting fd plus attach
  metadata.

The lib owns:

- reading `bpf_prog_info`, xlated bytecode, JIT image, and JIT base;
- deriving helper/map/update/lookup site metadata from the oracle;
- invoking `native-link`;
- reading native blob, reloc, map patch, and ABI outputs;
- patching real map kernel pointers into the linked template;
- loading the native-lab kfunc stub and returning its fd.

If one `.native.o` can contain multiple entry functions, the shim manifest may
carry `symbol`. When the manifest omits `symbol`, libnativeloader infers the
exact BTF `func_info` name from the loaded oracle fd; this is required for
15-byte BPF program-name collisions such as BCC kprobe entry/exit pairs.
Object selection itself stays manifest-driven and must fail on ambiguous
matches.

## Internal request model

The minimal fd API lowers into a typed request:

```text
NativeLoaderRequest {
  original_prog_fd,
  native_object_path,
  optional_symbol,
  arch,
  prog_type,
  expected_attach_type,
  oracle_jit_base,
  oracle_jited,
  oracle_xlated,
  maps[],
  lookup_sites[],
  update_sites[],
}
```

The typed model is serialized to `native-link` inputs. Positional
comma-separated site strings are an implementation detail to be removed after
the lib exists; the stable contract should be a versioned manifest with named
fields.

## Frontend Boundaries

### micro runner

Allowed:

- load the experiment companion `.bpf.o`;
- keep that companion object alive while `test_run` executes;
- pass companion prog fd and `.native.o` to native-loader;
- run `BPF_PROG_TEST_RUN` on the native fd.

Not allowed:

- reuse this companion loader path for corpus apps.

### corpus shim

Allowed:

- intercept the real app's `BPF_PROG_LOAD`;
- call the real syscall first so the app loader, maps, CO-RE, BTF, and attach
  metadata stay authoritative;
- resolve a prebuilt native object from a JSON manifest, pass the original prog
  fd plus attach metadata to native-loader;
- return native fd to the app if native load succeeds.

Not allowed:

- `bpf_object__open_file` corpus app `.bpf.o` from runner/framework code;
- duplicate app maps through a synthetic companion object;
- fallback silently to original BPF when native mode was requested.

## Build-Time Native Artifacts

`vendor/bpf` is the source of corpus BPF C. The build should add a native
artifact phase under `vendor/build`:

```text
vendor/bpf/<app sources>
  -> existing .bpf.o objects
  -> native .o objects compiled with native-lab constraints
  -> artifact manifest mapping real program identity to native object/symbol
```

Native compile flags should start from `native-sim/test/Makefile`:

- `-O3 -g -fPIC -c -fno-plt`
- `-fomit-frame-pointer -fno-stack-protector`
- `-fno-asynchronous-unwind-tables -fno-unwind-tables`
- `-fno-jump-tables -mllvm -switch-to-lookup=false`
- no red zone and general regs only on x86/arm64

App-specific native compatibility headers are expected. Many corpus sources
use BPF-only macros, CO-RE helpers, section wrappers, tail calls, and context
helpers that will not compile as native C without controlled shims.

## Rollout Todo

### Core library

- [x] Create `native-sim/libnativeloader` with C ABI header, C++ implementation,
      and Makefile/CMake integration.
- [x] Move native-lab target constants, native-link invocation, output parsing,
      map pointer patching, and native stub loading out of runner-local code.
- [x] Add the shared fd load path and a micro-only companion-object helper.
- [ ] Add a typed native-link manifest path and parser tests.
- [ ] Keep current positional CLI support only as a compatibility backend until
      the manifest path is used by both runner and shim.

### micro runner

- [x] Replace runner-local native-link/load logic with libnativeloader calls.
- [x] Keep packet preparation, measurement, and result extraction in runner.
- [x] Test native_kernel micro path through the repo Makefile entrypoint.

### shim smoke

- [x] Add `native-sim/test/multi_prog_tool.c` plus a `.bpf.c` source with
      multiple BPF programs in one C/object, loaded through libbpf.
- [x] Run it under the shim and verify every `BPF_PROG_LOAD` is observed.
- [x] Add native-loader invocation for an opt-in env flag, returning native fd
      only when native load succeeds.
- [x] Test with the multi-program tool under shim.

### vendor/bpf native build

- [x] Add native artifact output under `vendor/build/native-bpf/<arch>/<kernel>`.
- [x] Generate per-app native object(s) and a manifest.
- [x] Pre-run native-link proof stage for generated native artifacts. Native
      objects are not considered corpus-ready unless the selected entry symbols
      also pass the proof-link stage.

### corpus app enablement

- [x] `bcc`: compile native objects for selected libbpf-tools, shim-load them,
      and compare raw workload counters.
- [x] `katran`: compile `balancer`, `healthchecking*`, `xdp_root`; validate
      XDP attach and tail-call behavior.
      Current status: native compile/proof passes for `balancer`,
      `healthchecking_ipip`, `healthchecking`, and `xdp_root`; single-app
      runtime smoke passes after truncated-name aliasing, x86 proof reloc
      normalization, and native `xdp_buff`/`sk_buff` context layout fixes.
- [x] `cilium`: compile selected datapath objects; validate tail-call map
      updates and NodePort/CT policy chains.
      Current status: native compile/proof passes for selected datapath
      objects, including Cilium LXC/host/XDP/socket entries and tail programs.
      A single-app native-loader smoke now passes after the retained-map-fd
      close/close_range lifetime fix. The full native-loader corpus runs also
      pass with Cilium enabled in the six-app suite; app-level pktgen workload
      throughput improves by about 2.6x with zero pktgen errors in the final
      stats-off run.
- [x] `tracee`: compile `tracee.bpf.c` and LSM support probes; validate
      kprobe/tracepoint/LSM attach coverage.
      Current status: native compile/proof passes for the main
      `tracee.bpf.c` object and the two LSM support probes. Single-app
      native-loader smoke now passes after map-name truncation, duplicate
      inner-map aliasing, and `bpf_*` map-vs-helper fixes. Artifact:
      `corpus/results/x86_kvm_corpus_20260524_133325_153376`.
- [x] `tetragon`: compile process/cgroup/alignment objects; validate static Go
      shim path before native fd replacement.
      Current status: native compile/proof passes for the selected Tetragon
      process/cgroup objects. Single-app native-loader smoke now passes after
      object-scoped map schema fixes and the retained-map fd keeper process
      fix. Artifact:
      `corpus/results/x86_kvm_corpus_20260524_220355_937610`.
- [x] `otelcol-ebpf-profiler`: compile profiler objects; validate tail-called
      unwind programs and caller-side accounting.
      Current status: native compile/proof passes for selected profiler
      entries. Single-app native-loader smoke now passes with no native-loader
      failures after exact feature-probe handling for the tiny
      `probe_bpf_perf_` capability probe. Artifact:
      `corpus/results/x86_kvm_corpus_20260524_223229_404846`.

Do not run all corpus apps at once and hope the stack passes. Enable and test
one app at a time, starting with `bcc`; inspect the first failure, fix it, rerun
that app, and only then move to the next app.

Each app is complete only when the corpus target runs through the real app
startup path, native fd loading is exercised, no ReJIT/app-loader rule is
violated, and raw workload metrics show the expected direction of improvement.

## Current Validation Results

This section is a living implementation log. It records raw run status and
artifact locations only; framework code must not compute performance rollups.

- `native-sim/libnativeloader`: `make -C native-sim/libnativeloader` passes.
- shim multi-program smoke: `TEST_MODE=native-loader-smoke make test` passed
  with run token `26875a68`; both programs from one libbpf object were loaded
  through the shim and replaced with native fds.
- shim multi-program smoke after fd-array source canonicalization and x86
  tail-call frame fixes: `TEST_MODE=native-loader-smoke make test` passed with
  run token `574e44e8`.
- micro native kernel smoke:
  `SUITE=micro/config/micro_stage2.yaml RUNTIMES=native_kernel BENCH=helper_only_uid_gid SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 make micro`
  passed with run token `2a298b03`.
- full micro regression after the post-keeper corpus app sweep:
  `make micro` passed. Artifact:
  `micro/results/x86_kvm_micro_20260524_232117_957138`. The suite is
  `micro_staged_codegen` with 29 benchmarks, 29 runs each for `native`,
  `kernel`, and `llvmbpf`, 261 total samples, and no result/retval mismatches.
  The boot log scan found no kernel oops/panic; the only `ERROR` string was the
  expected ACPI `_OSC` boot message.
- final full micro regression after the all-app native-loader corpus reruns:
  `make micro` passed. Artifact:
  `micro/results/x86_kvm_micro_20260525_050929_891422`. The suite is
  `micro_staged_codegen`, with 29 benchmarks, `SAMPLES=3`, `INNER_REPEAT=100000`,
  29 runs each for `native`, `kernel`, and `llvmbpf`, and no run errors or
  result/retval mismatches.
- `bcc/set` native-loader corpus smoke:
  `BPFREJIT_CORPUS_APPS=bcc/set BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`
  passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_011434_535391`.
- `bcc/set` native-loader corpus smoke after the retained-map-fd protection:
  the same single-app command passed again. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_114723_064032`.
- `bcc/set` post-keeper rerun:
  the same single-app command passed after the retained-map fd keeper change.
  Artifact: `corpus/results/x86_kvm_corpus_20260524_222037_811414`. The suite
  and app status are both `ok`, selected workload is
  `stress_ng_bcc_hook_hot`, and the shim log records 25 native replacements
  with no native-loader failures or kernel oops/panic.
- `katran` native artifact build/proof:
  `make -B -C vendor/bpf native-katran` passed. The stage directory now
  contains program-name aliases for `balancer_ingress`, `healthcheck_encap`,
  and `xdp_root` under `vendor/build/native-bpf/x86/stage/katran`.
  The first runtime attempt,
  `corpus/results/x86_kvm_corpus_20260524_115537_677458`, failed before
  workload start because the kernel/libbpf program name was truncated to
  `balancer_ingres`, while the stage directory only had the full
  `balancer_ingress.native.o` alias. Katran staging now emits 15-byte
  truncated aliases for native objects, including `healthcheck_enca`.
- `katran` native-loader corpus smoke:
  `BPFREJIT_CORPUS_APPS=katran BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`
  passed after the proof-relocation and native context-layout fixes. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_122003_634530`.
- `katran` post-keeper rerun:
  the same single-app command passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_225627_645623`. The suite and app
  status are both `ok`, selected workload is `xdp_pktgen`, baseline and post
  phases each ran 4 workload components, and the shim log records 1 native
  replacement for `balancer_ingres` with no native-loader failures or kernel
  oops/panic.
- `otelcol-ebpf-profiler/profiling` is being enabled next as a single-app
  functional native-loader smoke passed with:
  `BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`.
  Artifact:
  `corpus/results/x86_kvm_corpus_20260524_044050_792890`.
  This validates real app startup, native fd replacement, prog-array tail-call
  target updates, and workload execution. Performance comparison and full
  proof/regression are still pending. Earlier failing artifacts are kept for
  debugging:
  `corpus/results/x86_kvm_corpus_20260524_021248_399823`,
  `corpus/results/x86_kvm_corpus_20260524_021849_219691`,
  `corpus/results/x86_kvm_corpus_20260524_022538_934769`,
  `corpus/results/x86_kvm_corpus_20260524_023927_400132`,
  `corpus/results/x86_kvm_corpus_20260524_025357_924766`,
  `corpus/results/x86_kvm_corpus_20260524_030419_873922`.
- `otelcol-ebpf-profiler/profiling` post-keeper rerun:
  the same single-app command passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_223229_404846`. The suite and app
  status are both `ok`, selected workload is `otel_mixed_workload`, baseline
  and post phases each ran 11 workload components, and the shim log records 14
  native replacements with no native-loader failures or kernel oops/panic. The
  earlier `probe_bpf_perf_` proof failures are gone; the 2-insn
  `probe_bpf_perf_` capability probe is now logged as an exact feature-probe
  skip instead of being proof-linked as a benchmark program.
- `cilium/agent` native artifact build/proof:
  `make -B -C vendor/bpf native-cilium` passed. The build emits selected Cilium
  native objects under `vendor/build/native-bpf/x86/stage/cilium`, including
  per-entry copies such as `cil_from_container.native.o`,
  `cil_xdp_entry.native.o`, `cil_sock4_connect.native.o`, and tail-call
  handlers. The latest forced rebuild after helper-call fail-fast work also
  passed proof-link for LXC, overlay, socket, host, wireguard, XDP, and
  alignchecker native objects.
- `cilium/agent` native-loader corpus smoke after retained-map-fd protection:
  `BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`
  passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_114137_174517`.
- `cilium/agent` post-keeper rerun:
  the same single-app command passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_224335_973426`. The suite and app
  status are both `ok`, selected workload is `cilium_endpoint_pktgen`,
  baseline and post phases each ran 2 workload components, and the shim log
  records 113 native replacements plus 70 prog-array updates with no
  native-loader failures or kernel oops/panic.
- `otelcol-ebpf-profiler` native artifact build/proof after the x86 helper
  fail-fast work:
  `make -B -C vendor/bpf native-otel` passed. The proof-link stage covered all
  selected kprobe/perf/uprobe/tracepoint entry symbols in
  `otelcol-ebpf-profiler.native.o`, including `custom__generic`,
  `finish_task_switch`, `kprobe_go_labels`, every `kprobe_unwind_*` and
  `perf_unwind_*` entry, `native_tracer_entry`, and the sched/process helpers.
- `tracee/monitor` native artifact build/proof:
  `make -B -C vendor/bpf native-tracee` passed for the main Tracee native
  object and the LSM support probe objects. The main `tracee.bpf.c` native
  object proof-linked 172 text symbols, and the support-probe proof stage
  covered `security_bpf_kprobe` and `lsm_bpf_check`.
- `tracee/monitor` first native-loader corpus smoke:
  `BPFREJIT_CORPUS_APPS=tracee/monitor BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`
  reached real Tracee startup and replaced both LSM support probes with native
  fds, then failed on the first main Tracee object map collision. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_125058_326958`.
- `tracee/monitor` second native-loader corpus smoke:
  the same single-app command moved past the `cgroup_id_filter_version`
  map-of-maps collision and failed later on an eager `.maps` alias for
  `policies_config_map`, which has multiple open process inner-map instances.
  Artifact: `corpus/results/x86_kvm_corpus_20260524_130230_205598`.
- `tracee/monitor` third native-loader corpus smoke:
  the same single-app command reached workload startup but panicked in
  `bpf_map_lookup_elem` from `trace_security_bpf_prog` because x86 native-link
  misclassified real maps named `bpf_attach_tmp_map` and `bpf_attach_map` as
  helper GOT symbols. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_131518_330347`.
- `tracee/monitor` native-loader corpus smoke after the x86 map-priority fix:
  the same single-app command passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_133325_153376`. The shim log records
  169 native replacements, including `trace_security_` and LSM programs, 13
  exact feature-probe skips, and no native-loader/link/kernel errors.
- `tracee/monitor` post-keeper rerun:
  the same single-app command passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_230826_179625`. The suite and app
  status are both `ok`, selected workload is `stress_ng_tracee_syscall_hot`,
  baseline and post phases each ran 1 workload component, and the shim log
  records 169 native replacements with no native-loader failures or kernel
  oops/panic.
- `tetragon/observer` native-loader corpus smoke after the retained-map fd
  keeper process:
  `BPFREJIT_CORPUS_APPS=tetragon/observer BPFREJIT_SHIM_NATIVE_LOADER=1 SKIP_REJIT=norejit SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 make corpus`
  passed. Artifact:
  `corpus/results/x86_kvm_corpus_20260524_220355_937610`. The suite result is
  `status=ok`, app result is `status=ok`, selected workload is
  `stress_ng_tetragon_policy_hot`, and the shim log records 288 native
  replacements, 577 native-loader jit-info lines, no native-loader failures,
  and no kernel oops/panic in `/tmp/tetragon-corpus-smoke-21.log`.
- Current single-app functional smoke status before the post-fix rerun sweep:
  `bcc/set`, `otelcol-ebpf-profiler/profiling`, `katran`, `cilium/agent`,
  `tracee/monitor`, and `tetragon/observer` all have at least one single-app
  functional smoke with no native-loader failures recorded in their shim logs.
  The post-keeper rerun sweep has completed all six apps individually:
  `bcc/set`, `otelcol-ebpf-profiler/profiling`, `cilium/agent`,
  `tetragon/observer`, `katran`, and `tracee/monitor`.

After every app passes individually, run:

- full micro regression through `make micro`;
- full native-loader corpus performance regression through
  `BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit make corpus`; this
  keeps baseline as the real app's original eBPF/JIT load path and enables
  native fd replacement only for the post phase;
- full workload-number regression with BPF stats disabled through
  `BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit BPFREJIT_CORPUS_BPF_STATS=0 make corpus`;
- per-app raw metric inspection from the generated `result.json` files.

## Issues Found While Enabling Corpus Native Loading

### Corpus boundary

The micro runner may still load a synthetic companion `.bpf.o`, because that is
the micro experiment frontend. The corpus path must not do that. The corpus
implementation therefore hooks the real app `BPF_PROG_LOAD`, lets the app load
its own BPF program first, and passes that already-loaded fd plus a native
object path to `libnativeloader`.

### Performance-mode boundary

`BPFREJIT_SHIM_NATIVE_LOADER=1` is a functional smoke mode: because the env var
is visible to both app starts, baseline and post both run with native fd
replacement. It does not answer whether native loading improves over the real
app's original eBPF/JIT path. Corpus performance runs now use
`BPFREJIT_SHIM_NATIVE_LOADER=post` with `SKIP_REJIT=norejit`, so the baseline
phase loads original eBPF through the real app loader and the post phase starts
the same app with native-loader enabled. This isolates native loading from the
default loadtime bpfopt pass policy.

The workload-number configuration must disable kernel BPF stats while keeping
the real app lifecycle. The old `BPFREJIT_CORPUS_BPF_STATS=0` guard forced
callers into `BPFREJIT_CORPUS_WORKLOAD_ONLY=1` or `SKIP_REJIT=all`; the
workload-only path deliberately runs the workload without the eBPF app and is
not a valid native-vs-original app comparison. The guard was removed so
`BPFREJIT_CORPUS_BPF_STATS=0` can be combined with the normal baseline/post app
lifecycle.

### Positional metadata coupling

`runner/src/native_lab_runner.cpp` and `native-link` previously duplicated map,
helper, site, enum, and kernel-offset semantics through positional CLI strings.
The library now centralizes that lowering, but the stable long-term fix remains
a typed native-link manifest. Until that exists, runner and shim must call only
the library API so the duplicated positional contract has one userspace owner.

OTEL also exposed a concrete bug in the positional lookup-site contract:
`perf_unwind_hotspot` has 39 source `bpf_map_lookup_elem` helper calls, but the
x86 native object can present helper calls in an order that does not match the
BPF bytecode's global source order. The old x86 linker assumed "native call
ordinal N == BPF helper ordinal N", so a later native call failed with missing
lookup-site metadata or, worse, could have used the wrong map inline metadata.
The x86 path is being changed to carry an optional source map name in each
lookup-site record and to match native helper sites by the map symbol traced in
the native call's first argument. The linker still fails fast if it cannot find
an unused matching site.

The next OTEL run showed that order was not the only problem:
`perf_unwind_hotspot` has native lookup calls against
`pid_page_to_mapping_info` that do not have a one-for-one source BPF helper
site. This can happen when the native compiler keeps branches or helper calls
that the BPF compilation path does not materialize in the same way. The fix is
to make per-map lookup metadata explicit: the loader now passes `--lookup-map`
records keyed by native map symbol name, derived from the live map fd metadata
and kernel struct offsets. x86 native-link first consumes source call-site
metadata when it matches, then falls back to the per-map record for
native-only lookup callsites whose map argument can be traced. If the map
argument cannot be traced, the linker still exits 1.

OTEL then exposed a helper-argument schema bug in the loader itself:
`custom__generic` failed native-link with an unknown `perf_progs` GOT
relocation in
`corpus/results/x86_kvm_corpus_20260524_030419_873922`. The source scanner
was recording only the map fd in BPF register `r1` for every helper. That is
valid for `bpf_map_lookup_elem`/`update`/`delete`, but wrong for
`bpf_tail_call(ctx, map, index)` and
`bpf_perf_event_output(ctx, map, flags, data, size)`, whose map argument is
`r2`. The fix is to make the scanner choose the helper-specific map argument
register before it builds map metadata, so PROG_ARRAY and PERF_EVENT_ARRAY
maps such as `perf_progs` and `trace_events` are passed to native-link by the
same typed map path as other app maps.

The next OTEL run showed the same `perf_progs` symbol can still be absent even
after using the helper-specific map argument register. The failing artifact is
`corpus/results/x86_kvm_corpus_20260524_031700_105083`; its shim log shows
`BPF_MAP_CREATE` for `perf_progs`, but the native-link command for
`custom__generic` did not contain `--map perf_progs=...`. The likely cause is
the source bytecode encoding: libbpf can load programs with
`BPF_PSEUDO_MAP_IDX` plus `BPF_PROG_LOAD.fd_array`, while the native-loader
source scanner only understands `BPF_PSEUDO_MAP_FD`. The corpus shim sees the
original `fd_array` pointer at the interception boundary, so the fix is to
snapshot the referenced fd-array slots during `BPF_PROG_LOAD` capture and write
a native-loader-only canonical bytecode copy where `PSEUDO_MAP_IDX` and
`PSEUDO_MAP_IDX_VALUE` are rewritten to `PSEUDO_MAP_FD` and
`PSEUDO_MAP_VALUE`. The original bytecode dump remains unchanged for the
normal shim/ReJIT pipeline.

### native-link implementation size

The x86 rewrite path was split from the native-link `main.rs` into an x86 module
to reduce the monolithic file size. The arm64 path still needs a similar split
before more ABI cases are added.

### Cilium helper feature probes

`cilium/agent` native-loader smoke first failed in
`corpus/results/x86_kvm_corpus_20260524_044600_782701` before any tracked
datapath programs were loaded. The shim log shows an anonymous
`BPF_PROG_TYPE_CGROUP_SOCK` program with three instructions, then
`native-loader enabled but no native object for prog=`. This is Cilium's
cilium/ebpf helper probe for `FnSetRetval`, generated as
`helper.Call(); r0 = 0; return`. It is not a persistent app datapath program
and has no stable native object identity. The shim's existing feature-probe
skip was extended from libbpf nametest/tiny probes to include anonymous helper
probes for CGroupSock/CGroupSockAddr/CGroupSockopt, XDP, SchedCLS, and
SchedACT. The first retry in
`corpus/results/x86_kvm_corpus_20260524_050152_491706` showed Cilium also uses
an anonymous four-instruction CGroupSock probe for the same startup capability
path, so the anonymous feature-probe limit for these program types is four
instructions. Named Cilium datapath programs still fail fast if native-loader
mode is enabled and no native object exists; this change is not a fallback for
real benchmark programs.

The next retry in
`corpus/results/x86_kvm_corpus_20260524_050652_993694` reached Cilium map
creation and later failed Cilium's dead-code-elimination requirement. The cause
was another startup probe: `HaveDeadCodeElim()` loads a temporary XDP program
named `test` with six instructions and then reads the final kernel
instructions to verify that verifier DCE removed the dead jump. Native-loader
incorrectly treated that named probe as a datapath program and failed looking
for `test.native.o`, making Cilium report that the kernel lacked DCE support.
The shim now skips only this exact feature-probe shape, including the normalized
program hash, so ordinary named Cilium programs still require a native object.

The following retry in
`corpus/results/x86_kvm_corpus_20260524_051203_373909` got past the DCE probe
and then failed Cilium's large-instruction-limit requirement. This was another
startup capability probe from cilium/ebpf: an anonymous socket-filter program
with 4097 instructions and no native object identity. The shim now skips only
that exact anonymous socket-filter probe shape, including the normalized
program hash. The same log also showed Cilium's FIB feature probes
(`probe_fib_lookup_skip_neigh`, `probe_fib_lookup_tbid`, and
`probe_fib_lookup_src`) arriving at the kernel as the truncated name
`probe_fib_looku`. Those are temporary SchedCLS probes for `bpf_fib_lookup`
flag support, not loaded datapath programs, so the shim also skips only their
exact truncated-name, type, instruction-count, and hash shape. Real Cilium
datapath loads such as `cil_xdp_entry` still fail fast when native loading
cannot produce a replacement fd.

`corpus/results/x86_kvm_corpus_20260524_051835_192997` found the next Cilium
startup capability probe: `adjust_mac_room`, a five-instruction SchedCLS probe
for `bpf_skb_adjust_room(..., BPF_ADJ_ROOM_MAC, ...)`. Native-link does not
lower helper id 50 yet, but this probe is executed only to decide kernel
support, so the shim keeps the original fd for this exact program shape.

The same run reached the real XDP datapath entry and exposed a loader metadata
bug: kernel map object names are limited to 15 bytes, so both
`cilium_cidr_v4_fix` and `cilium_cidr_v4_dyn` report as `cilium_cidr_v4_`
and the v6 pair reports similarly. The loader used to fail as soon as the
original program's `used_maps` list contained two different kernel pointers
with the same truncated name. It now retains duplicate loaded-map metadata and
only resolves a full native `.maps` symbol when that symbol is actually used.
For Cilium's `_fix`/`_dyn` collision, the full symbol suffix plus map type
(`HASH` for `_fix`, `LPM_TRIE` for `_dyn`) uniquely selects the loaded map.
Ambiguous map symbols without a unique match still fail the native load.

`corpus/results/x86_kvm_corpus_20260524_052704_340744` showed that the FIB
probe set has three concrete hashes, not two; the third hash corresponds to
the remaining `probe_fib_lookup_*` variant and is now part of the exact
feature-probe skip list. Returning the original fd for these probes is
required because Cilium runs each loaded probe with `BPF_PROG_TEST_RUN` and
uses the return value to decide whether a kernel feature is supported.

### Cilium native C compatibility and proof

Cilium's datapath sources rely on BPF-only inline assembly wrappers for context
access, packet load/store helpers, static config reads, and tail-call macros.
Those forms are correct for BPF C but cannot be compiled into native-lab host
objects. The native artifact build now uses `MICRO_NATIVE` branches in the
Cilium compatibility headers for the selected corpus datapath objects:

- XDP/SKB context access is lowered to normal C pointer reads where the kernel
  context layout is already known.
- `xdp_load_bytes`, `xdp_store_bytes`, checksum helpers, and `map_array_get_32`
  use native-callable helper wrappers instead of BPF inline assembly.
- `CONFIG(name)` resolves to the generated native config symbol instead of a
  BPF `ld_imm64` inline-assembly sequence.
- `tail_call_static`/`tail_call_dynamic` lower to the same `tail_call()` helper
  shape that native-link already recognizes and proof-links.

The first max-option `bpf_overlay` proof failed on the multicast entry
`tail_mcast_ep_delivery` because the native object passed a text-section
callback symbol into the generated proof input; native-link deliberately rejects
that PC32 text relocation shape. The current Cilium runner setup does not enable
multicast, so the native build aligns with the runner feature set and removes
`-DENABLE_MULTICAST=1` from the Cilium native overlay option set. This is not a
runtime skip or ReJIT filter: it avoids building a native artifact for a Cilium
feature the corpus app is not configured to load.

### Tail calls in OTEL

OTEL uses `bpf_tail_call` in unwind programs. Native-link initially failed on
helper id 12. The x86 path now lowers `bpf_tail_call` inline for entry symbols,
using generated kernel offsets for `struct bpf_array`, `struct bpf_map`, and
`struct bpf_prog`. The native-lab stub loader also emits a verifier-visible,
runtime-false tail-call probe so the kernel JIT allocates the tail-call stack
slot expected by the native success path.

A later OTEL run also hit a dangerous x86 tail-call lowering bug: the kernel
oopsed at `native_lab_stub+0x791` while executing the generated tail-call
inline sequence for `perf_unwind_hotspot`; the faulting instruction was the
generated load from `[rbp - 16]` and the oops showed `RBP=0`. The native
function body had already used `%rbp` as a normal callee-saved register, so
the generated sequence was reading the tail-call counter pointer through the
wrong frame pointer. The kernel x86 JIT computes the slot as
`-16 - round_up(stack_depth, 8)` from the BPF frame pointer and preserves that
frame pointer across tail calls. Native-link must either preserve/remap native
`%rbp` before emitting tail-call lowering or fail the link; emitting code that
can dereference a clobbered `%rbp` is not acceptable. The implemented fix keeps
the normal native `%rbp` save/restore path, records the saved BPF frame
pointer's offset from the native `%rsp` after ABI stripping, and makes the
tail-call inline sequence recover the BPF frame pointer from that stack slot
before reading the tail-call counter pointer.

The follow-up OTEL run still emitted the old `[rbp - 16]` sequence in
`perf_unwind_hotspot`, which means the x86 ABI-strip planner can decline the
strip plan and leave the tail-call lowering without a recorded frame location.
That is a correctness bug in the linker, not a workload problem. The linker
must now build a conservative no-strip tail-call frame plan when ABI stripping
is not available, and it must fail the link instead of emitting tail-call code
without either a live BPF `%rbp` or a stack slot containing the saved BPF
`%rbp`.

The next OTEL run no longer oopsed, but `perf_unwind_stop` failed during the
runtime `native-link --mode kernel` pass with `x86 entry with bpf_tail_call has
no return epilogue`. The input at this point is the already-proved
`*.proof.o`, whose entry return has been normalized from `retq` into a
`jmp <entry_end>` marker so the final linker can patch it as `JmpEnd`. The
tail-call frame planner was still looking only for real `ret` instructions,
so it could not extract the epilogue cleanup bytes from proof input. Kernel
mode now treats proof-input `jmp <entry_end>` as the entry return terminator,
and it preserves the proof object's existing ABI stripping instead of trying
to strip the entry ABI a second time.

The following OTEL run progressed past `perf_unwind_stop` link-time failure
and loaded the unwind native stubs plus `native_tracer_entry`, then oopsed at
runtime in the native-lab stub for the perf-event entry. The fault was a
supervisor instruction fetch at a non-kernel address (`0x104f...`), with the
call trace pointing at the generated `native_lab_stub`. This is no longer a
proof/linker acceptance problem; it is a runtime code-generation bug in the
tail-call path or a still-unresolved indirect helper target inside the native
blob. The same run also showed `custom__generic` still missing the `perf_progs`
map alias during kernel-mode link, and the application attempted to continue
loading after the native-loader failure. Both are tracked as defects: native
loader failures in enabled corpus mode should abort the app load path rather
than silently leave a mixed native/original state, and fd-array/map-alias
canonicalization still needs to cover the OTEL `custom__generic` source shape.

The likely root cause for the runtime tail-call oops was an ABI-mask mismatch
introduced by proof-input handling. Kernel-mode linking preserved the proof
object's entry ABI, but the x86 rewrite result still carried
`callee_saved_mask=0`, so generated tail-call inline code did not pop the
callee-saved host registers that the BPF JIT had saved for the proof ABI
before jumping to the target program. Kernel-mode x86 rewriting now reads the
proof object's `.native_link_abi` and uses that mask for tail-call cleanup.

`custom__generic` exposed another map-metadata shape: the selected BPF entry
does not directly call `bpf_tail_call`, but the native object still has GOT
relocations against the shared `perf_progs` map through common code. That map
therefore is not in the original program's `used_maps` list and cannot be
derived from helper-call source scanning. The loader now treats `.maps` symbols
as native-object requirements and, when a symbol is absent from the program
metadata, scans only the current process's open BPF map fds for a unique
kernel object name match. Ambiguous names are not aliased at scan time because
native objects can contain `.maps` symbols for other entry sections; if the
selected entry really references an ambiguous symbol, native-link will still
fail the load when it sees the unresolved relocation. There is no fallback to
the original program. The shim also logs successful `BPF_MAP_UPDATE_ELEM`
operations for PROG_ARRAY maps so tail-call chains can be verified against the
fds returned to the real app.

The first OTEL retry after adding process-fd map discovery failed before app
startup with `native map symbol system_analysis matches multiple open process
maps named system_analysis`. That exposed the distinction above: an eager
`.maps` scan was treating unrelated entry-section symbols as required. The
fix is to skip ambiguous process-fd aliases until native-link proves the
selected entry actually needs that symbol.

The OTEL retry after the ambiguity fix loaded all `perf_unwind_*` native fds
into the real `perf_progs` prog array and then oopsed from the native-lab stub
for `native_tracer_entry`. Added shim diagnostics confirmed that the prog array
contained the native fds returned to the app (`perf_unwind_stop` through
`perf_unwind_v8`, plus `perf_go_labels`), and that every prog-array target's
JIT ksym was in the expected BPF JIT/module range (`0xffffffffc00...`). The
faulting RIP was instead a vmalloc/stack-looking NX address
(`0xffffd30080502000` in the latest run), while the call trace pointed at
`native_lab_stub+0x8d`. This makes the current leading hypothesis a native blob
code-generation/relocation bug inside the entry stub, not a wrong fd in the
prog-array map. The next diagnostic step is to dump the native stub JIT bytes
from the shim immediately after load so `native_lab_stub+0x8d` can be mapped to
the exact emitted instruction.

The full JIT dump narrowed that oops to `perf_unwind_stop`, not the caller's
prog-array update. The first tail-called target contained an unpatched
`call *%r15` at the second `bpf_map_lookup_elem` site. The native C compiler
loaded helper id 1 into callee-saved `%r15d` once and reused it for multiple
helper calls. Native-link removed the first immediate load when it inlined the
first lookup, then incorrectly discarded the `%r15 -> bpf_map_lookup_elem`
metadata after that call. The second call was no longer recognized as a helper
site, so it remained as `call *%r15` and jumped to whatever `%r15` held across
the tail call. The x86 linker now clears helper-id/GOT metadata only for
caller-clobbered registers across calls; callee-saved helper registers such as
`%r15` remain valid until an explicit write kills them. This keeps the existing
fail-fast model: unrecognized helper indirections should fail or be patched,
not survive into the native blob as arbitrary indirect calls.

The OTEL retry after preserving callee-saved helper-id metadata passed the
single-app functional smoke. The key validation point is that the real app
updated `perf_progs` with the native fds returned by the shim and the mixed
Python/Ruby/Node workload completed both baseline and post-rejit phases without
kernel oops or app loader fallback.

### Native map symbol names vs kernel object names

OTEL has map symbols longer than `BPF_OBJ_NAME_LEN - 1`; the kernel truncates
loaded map names while the native object keeps the full ELF symbol name. Native
linking failed on `stack_delta_page_to_info` because userspace only exported
the truncated kernel name. The loader now aliases full `.maps` symbol names to
the loaded truncated map pointer when the truncation is unique.

### native_lab chunk capacity

`perf_unwind_native` produced 249 x86 chunks, exceeding the old 64-slot
native-lab upload limit. The module and userspace checks were raised to 512
slots in the x86 module, arm64 module, libnativeloader, the legacy runner check,
and the native-lab PoC.

### Verifier log truncation changed load behavior

After raising the chunk limit, `perf_unwind_native` built a 506-insn native-lab
stub. The stub `BPF_PROG_LOAD` returned `ENOSPC`, but the verifier output only
showed successful processing statistics. The errno came from verifier log
finalization: `log_level=1` plus a 32KB log buffer truncated the verbose log,
and the kernel reports log truncation as `ENOSPC`. Normal native stub loading no
longer requests verifier logs so diagnostics cannot change the success path.

### Cilium XDP helper coverage

`cilium/agent` reached real datapath loading after the feature-probe skips and
map truncation fixes, then failed on `cil_xdp_entry` with `native_kernel:
unsupported helper id 189` in
`corpus/results/x86_kvm_corpus_20260524_053222_865520`. Helper 189 is
`bpf_xdp_load_bytes`. This is not a Cilium feature probe: it is in the loaded
XDP entry path, so native-loader must either support the helper or fail the app
load. The loader and x86 linker now recognize the XDP helper family with stable
one-to-one kernel symbols: `bpf_xdp_adjust_meta`, `bpf_xdp_adjust_head`,
`bpf_xdp_adjust_tail`, `bpf_xdp_get_buff_len`, `bpf_xdp_load_bytes`, and
`bpf_xdp_store_bytes`.

Helpers whose implementation symbol depends on BPF program type, such as
`redirect`, `redirect_map`, and `fib_lookup`, remain intentionally out of this
fix until the loader carries a typed helper-site schema. Accepting those helper
IDs through a single global name would risk linking an XDP program to a TC
helper implementation or the reverse.

The next Cilium retry in
`corpus/results/x86_kvm_corpus_20260524_054137_090668` confirmed that helper
189 was no longer the blocker. It failed later in kernel-mode native-link with
`x86 tail_call lowering missing --helper __native_x86_bpf_map_max_entries_offset`.
The native object contains a `bpf_tail_call` site even though the loaded source
BPF helper scan did not set `has_tail_call` for this path, so gating x86
tail-call lowering constants on source-bytecode discovery is too weak. The
loader now passes the x86 tail-call lowering constants unconditionally; the
linker still only consumes them when it proves a native tail-call site exists.

After that fix, `corpus/results/x86_kvm_corpus_20260524_054631_588412` failed
with `x86 bpf_map_lookup_elem native call 11 in cil_xdp_entry is missing
--lookup-site metadata`. The missing site came from native-only map symbols
whose loaded kernel names collide after `BPF_OBJ_NAME_LEN` truncation:
`cilium_cidr_v{4,6}_dyn` and `cilium_cidr_v{4,6}_fix` both load as
`cilium_cidr_v*_`. The in-memory metadata path already used `_dyn` as
`BPF_MAP_TYPE_LPM_TRIE` and `_fix` as `BPF_MAP_TYPE_HASH`; the process-fd
fallback path did not. Process map discovery now applies the same suffix/type
disambiguation so these native map symbols can produce both `--map` and
`--lookup-map` records.

The following Cilium retry in
`corpus/results/x86_kvm_corpus_20260524_055334_429942` got past the CIDR maps
and failed on another truncation collision: `cilium_ratelimit` and
`cilium_ratelimit_metrics` both load as `cilium_ratelimi`. These symbols do not
carry the `_dyn`/`_fix` suffix convention, so the loader now has a small native
map shape table for the exact Cilium ratelimit symbols:
`cilium_ratelimit_metrics` is `HASH key=4 value=8 max_entries=64`, while
`cilium_ratelimit` is `LRU_HASH key=8 value=16 max_entries=1024`. The
disambiguation is applied both to maps already referenced by the loaded program
and to open process maps discovered from `/proc/self/fd`.

The next Cilium retry in
`corpus/results/x86_kvm_corpus_20260524_060015_510800` confirmed that ratelimit
was resolved and exposed the same class of collision for
`cilium_lb4_reverse_nat`, which shares loaded name `cilium_lb4_reve` with the
socket reverse-NAT map. The shape table now also covers
`cilium_lb4_reverse_nat`, `cilium_lb6_reverse_nat`,
`cilium_snat_v4_external`, `cilium_snat_v4_alloc_retries`, and the two
`cilium_l2_responder_*` maps that appear in the same Cilium startup set. These
are exact Cilium native symbols with full type/key/value/max-entries checks;
unknown collisions still fail fast instead of falling back to an arbitrary map.

`corpus/results/x86_kvm_corpus_20260524_060704_046875` then moved past map
shape disambiguation and failed in native-link with an unknown `cilium_calls`
GOT symbol. This was a native build configuration mismatch, not a missing
loader alias: the corpus runner starts Cilium with IPv4 and XDP prefiltering but
without node-port service enablement, so Cilium's real loader DCEs
`cil_xdp_entry` down to 280 BPF instructions and does not create the private
`cilium_calls` prog-array. The native Cilium XDP object was still compiled with
`ENABLE_NODEPORT_ACCELERATION`, which retained `tail_call_internal()` and the
`cilium_calls` relocation. The XDP native build now removes
`-DENABLE_NODEPORT_ACCELERATION=1` from its option set so the native object is
not broader than the app-level loaded program for this corpus configuration.

The next Cilium retry,
`corpus/results/x86_kvm_corpus_20260524_061810_988986`, got past that native
linking mismatch and successfully replaced `cil_xdp_entry` with a native
`native_lab_stub`, but the first real XDP packet path oopsed at
`native_lab_stub+0x1c3`. The faulting address had only the low 32 bits of the
packet pointer (`0x8a0010c`), which pointed at the Cilium `MICRO_NATIVE` XDP
compat layer still reading `struct xdp_md`'s 32-bit `data` / `data_end`
members. In the real kernel entry ABI the native stub receives
`struct xdp_buff *`; the verifier normally rewrites BPF `xdp_md` field loads
to 64-bit `xdp_buff` pointer loads before JIT. Native C bypasses that rewrite,
so the compatibility layer must do it explicitly. Cilium native XDP now reads
`data`, `data_end`, and `data_meta` as 64-bit fields at `xdp_buff` offsets
0/8/16 for `ctx_data()`, `ctx_data_end()`, `ctx_load_bytes()`,
`ctx_store_bytes()`, checksum helpers, and `ctx_full_len()`. A forced
`make -B -C vendor/bpf native-cilium` after this fix passed and regenerated the
proof-linked Cilium native artifacts.

The following Cilium retry,
`corpus/results/x86_kvm_corpus_20260524_062559_315571`, moved the crash from
packet-pointer access to an early `.rodata.config` access. The native JIT dump
showed `movabs rax, ffffcb6e00386076; cmpb $0,(rax)` for
`__config_tracing_ip_option_type` at offset `0x76` in `.rodata.config`. The
address shape matched `array->value + symbol_offset`, so the mmapable-array
offset formula was not the immediate bug. The real bug was lifetime: the shim
loaded the original BPF program only to obtain the JIT oracle/map metadata,
loaded a native stub, then immediately closed the original fd before returning
the native fd to the app. The native stub verifier does not see the raw
map/global-data pointers embedded in the native blob, so it holds no references
to those maps. Once the app/libbpf object tears down the original program or
maps, those raw pointers can become use-after-free addresses in the attached
native program.

The shim now treats a successful native-loader replacement as an ownership
pair: the app receives only the native fd, while the shim keeps the original
prog fd and dup'd current BPF map fds hidden on the `prog_entry`. Those hidden
fds are not passed to native-link and do not change app-visible loader
semantics; they only preserve kernel object lifetime for raw pointers already
embedded into the native blob. The retained fd count is logged on every
replacement so later corpus failures can distinguish link correctness from
lifetime-retention bugs.

`corpus/results/x86_kvm_corpus_20260524_070021_118713` proved the lifetime
fix: `cil_xdp_entry` was replaced twice and survived into the next Cilium load
phase. The next blocking items are loader/linker metadata gaps:

- Cilium host/LXC paths call helper id 118 (`bpf_jiffies64`). The loader and
  x86 native-link helper name table now include this exact helper symbol.
- Endpoint tail-call maps are named `cilium_calls_02` in this corpus run, not
  only `cilium_calls_00`. The shim now maps every `cilium_calls_0*` source map
  prefix to the `bpf_lxc.*.native.o` object namespace.
- Cilium creates a fresh `cilium_devices` map for several per-endpoint object
  loads with identical BPF object names and shapes. The native object can still
  reference `cilium_devices` even when the verifier removed the direct map
  reference from the loaded BPF program, so the prog-info map-id list is not
  sufficient. The loader now records process fds in `MapMeta`, requires the
  exact `HASH key=4 value=16 max_entries=512` shape for this symbol, and for
  this Cilium object-scoped map chooses the newest open process fd. Other
  ambiguous open process map names still fail fast.

The next Cilium retry,
`corpus/results/x86_kvm_corpus_20260524_070922_976848`, successfully replaced
`cil_xdp_entry` and `tail_drop_notif`. It then exposed:

- helper id 99 (`bpf_skc_lookup_tcp`), which is context-typed in the kernel.
  native-loader now resolves it to `bpf_tc_skc_lookup_tcp` for TC programs,
  `bpf_xdp_skc_lookup_tcp` for XDP programs, and generic
  `bpf_skc_lookup_tcp` otherwise, while keeping the native-link symbol name as
  `bpf_skc_lookup_tcp`.
- `bpf_get_prandom_u32` has no exported body with that name in this kernel;
  the helper proto points at `bpf_user_rnd_u32`. native-loader now passes
  `bpf_get_prandom_u32=<bpf_user_rnd_u32 address>` to native-link.
- additional Cilium truncated-name map collisions:
  `cilium_policy_v2` is exactly `LPM_TRIE key=12 value=12 max_entries=16384`,
  and `cilium_nodeport_nat_buffer` is exactly
  `PERCPU_ARRAY key=4 value=18 max_entries=1`. These are also treated as
  newest-open Cilium object-scoped maps after shape validation.
- retaining all process map fds is racy in Cilium's multi-threaded loader
  because another thread can close a map fd after `/proc/self/fd` enumeration.
  The shim now skips stale `EBADF`/`ENOENT` candidates and revalidates each dup
  as `anon_inode:bpf-map`; other retention errors still fail the native
  replacement.

`corpus/results/x86_kvm_corpus_20260524_071652_551718` showed that the
remaining Cilium failures were mostly configuration-width mismatches:

- The corpus runner starts Cilium with `--enable-ipv6=false` and
  `--enable-l7-proxy=false`, while the native Cilium build still used a
  max-feature overlay with `ENABLE_IPV6` and `ENABLE_L7_LB`. This made native
  symbols reference maps and branches the real app-level BPF loader had
  compiled or verifier-DCE'd away, for example `cilium_nodeport_neigh6` and
  full `cil_lxc_policy_egress` logic when the loaded BPF program was just a
  2-insn `CTX_ACT_OK` path. The Cilium native build options are now aligned to
  the current corpus runner's IPv4-only, L7-disabled configuration instead of
  the previous max-feature build.
- Cilium's native sources use a generic `cilium_calls` symbol, but the real
  loader creates object-specific prog arrays like `cilium_calls_ho` and
  `cilium_calls_02`. The loader now aliases `cilium_calls` to the single
  loaded Cilium prog-array for the program when available, otherwise to the
  newest matching open process prog-array.
- When the loaded BPF program no longer references `.rodata.config` directly,
  prog-info map IDs cannot seed native data symbol addresses. The loader now
  resolves ARRAY data sections (`.rodata*`, `.data`, `.bss`) from the newest
  open process data map with matching BPF object name, key size, max entries,
  and sufficient value size. This is used for config symbols such as
  `__config_security_label` before native-link kernel mode validates
  RIP-relative data references.

`corpus/results/x86_kvm_corpus_20260524_072820_934011` found the next Cilium
object-scope gaps:

- The first native Cilium option alignment still left
  `ENABLE_CLUSTER_AWARE_ADDRESSING` and `ENABLE_INTER_CLUSTER_SNAT` enabled.
  That made native CT/NAT paths reference per-cluster maps such as
  `cilium_per_cluster_ct_tcp4` even though the corpus Cilium runner uses
  `--cluster-id=0`. The Cilium native build now removes these clustermesh
  options as well.
- Data-map selection used each symbol's end offset as the minimum map size.
  For `.rodata.config`, that was too broad: a small early config symbol could
  match XDP, host, and LXC `.rodata.config` maps with different value sizes.
  The loader now requires the full ELF data section size when resolving native
  data-section symbols.
- `cil_to_host` uses helper id 124 (`bpf_sk_assign`). The loader and x86
  native-link helper-name table now include `bpf_sk_assign`.

The same run still showed a `cil_to_netdev` lookup-site count mismatch before
the clustermesh option fix. The next retry must confirm whether option
alignment removes that mismatch; if not, the remaining work is to make
native-link handle native helper-call sites that can only be safely lowered to
the generic helper call because no source-ordinal map metadata exists.

`corpus/results/x86_kvm_corpus_20260524_073757_942006` moved past the earlier
lookup-site and per-cluster map failures: `cil_xdp_entry`, a host nodeport
tail program, and an LXC ARP tail program were replaced. The next Cilium
truncated-name collision was `cilium_nodeport_neigh4`: libbpf truncates both
`cilium_nodeport_neigh4` and `cilium_nodeport_nat_buffer` to
`cilium_nodeport`. The loader now distinguishes the neighbor map as
`LRU_HASH key=4 value=8` and the NAT buffer as `PERCPU_ARRAY key=4 value=18`,
then treats the neighbor maps as Cilium object-scoped newest-open maps after
shape validation.

`corpus/results/x86_kvm_corpus_20260524_074321_625214` exposed a separate
retention scalability bug. `cil_to_host` reached fd numbers above 3600, and the
shim's previous "retain all current process BPF map fds" policy tried to dup
every open map before invoking native-loader. Cilium's app-level loader can have
thousands of map fds open during endpoint regeneration, so this hit `EMFILE`
before native-link even ran.

The shim now retains only the maps actually referenced by the loaded program:
it reads the original program's kernel `prog_info.map_ids`, reopens those maps
with `BPF_MAP_GET_FD_BY_ID`, and supplements that set with any explicit
`BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` references from the source
bytecode passed to native-loader. Retention is deduplicated by kernel map id.
This keeps the raw native map-pointer lifetime guarantee without coupling the
native replacement to every unrelated map fd owned by a large app loader.

The same retry confirmed that this removed the `EMFILE` blocker: native-loader
advanced into later Cilium endpoint programs and replacements logged small
retained sets such as 7 or 11 map fds. The next failures were ordinary
metadata gaps:

- `cilium_tail_call_buffer4` collides with other maps under libbpf's
  `cilium_tail_cal` truncation. It has the same exact
  `PERCPU_ARRAY key=4 value=60 max_entries=1` shape as the previously handled
  buffer6 variant and is now treated as a newest-open Cilium object-scoped map.
- Cilium TC paths call helper id 85 (`bpf_sk_lookup_udp`) and helper id 86
  (`bpf_sk_release`). The loader now resolves UDP socket lookup through the
  same context-typed alias pattern as TCP lookup: TC uses
  `bpf_tc_sk_lookup_udp`, XDP uses `bpf_xdp_sk_lookup_udp`, cgroup sock-addr
  uses `bpf_sock_addr_sk_lookup_udp`, and the native-link helper-id table maps
  ids 85/86 back to `bpf_sk_lookup_udp` / `bpf_sk_release`.

`corpus/results/x86_kvm_corpus_20260524_080158_511240` got past the fd
retention and UDP socket helper gaps, then failed several Cilium host/tail
programs with `x86 bpf_map_lookup_elem native call ... is missing
--lookup-site metadata`. The concrete examples were `cil_host_policy`,
`tail_handle_snat_fwd_ipv4`, and `tail_handle_ipv4_from_netdev`. In these
paths the loaded app-level BPF program can be much smaller than the selected
native C object after verifier DCE/config specialization, and some optimized
native call sites cannot be traced back to a single source lookup ordinal or a
single statically-known map symbol. The correct behavior is still to call the
real kernel `bpf_map_lookup_elem` helper with the runtime map pointer already
in `rdi`; only the optional array/hash lookup inline requires exact map-shape
metadata. x86 native-link now emits a generic `bpf_map_lookup_elem` helper call
when no source/site/map metadata can be matched, while still using exact
`--lookup-site` or `--lookup-map` records whenever they are available. This is
not an app-loader fallback: the native fd is still loaded, and unknown map
shape simply disables that one call-site inline optimization.

`corpus/results/x86_kvm_corpus_20260524_081253_448783` confirmed that the
generic lookup path fixed those missing-site failures: `cil_host_policy` and
`tail_handle_ipv4_from_netdev` were replaced successfully. The next failure was
`tail_handle_snat_fwd_ipv4` in kernel-mode relink:
`instruction at IP 0x122f reads RIP-relative 0x82cd outside the included
symbols`. Reproducing proof mode locally showed the same native object still
contained an unresolved `cilium_egress_gw_policy_v4` relocation. The corpus
Cilium runner does not enable egress gateway, so the app-level loader never
creates the matching map for this run. This was another native build/app
configuration mismatch rather than a loader lifetime issue. The Cilium native
build now removes `-DENABLE_EGRESS_GATEWAY=1` so host SNAT/native objects match
the corpus runner's enabled feature set.

`corpus/results/x86_kvm_corpus_20260524_082241_966541` got further after the
egress-gateway fix, but still showed three Cilium map references from native
paths wider than the actual runner configuration:

- `cil_to_netdev` referenced `cilium_throttle`, which belongs to bandwidth
  manager. The runner does not pass `--enable-bandwidth-manager=true`.
- `tail_handle_ipv4_cont` referenced `cilium_subnet_map`, which belongs to
  VTEP/hybrid routing paths. The runner does not enable VTEP.
- `tail_handle_snat_fwd_ipv4` referenced `cilium_ipmasq_v4`, which belongs to
  the ip-masq-agent map, not the plain `--enable-bpf-masquerade=true` path.

The native Cilium build now removes `-DENABLE_BANDWIDTH_MANAGER=1`,
`-DENABLE_VTEP=1`, and `-DENABLE_IP_MASQ_AGENT_IPV4=1` for the same reason as
the earlier IPv6/L7/clustermesh/egress-gateway removals: app-level Cilium did
not create those maps, so the native object must not encode map relocations to
them.

The same artifact also showed the shim log growing past 100 MB with repeated
`bpf cmd=15 size=16` lines (`BPF_OBJ_GET_INFO_BY_FD`). That logging was useful
during shim bring-up but is too noisy for Cilium and changes benchmark
behavior. The shim now stops logging unknown/default BPF commands and keeps the
structured program/map/link/native-loader events.

### Tetragon native-loader bring-up

Tetragon first exposed native-link reachability that proof did not cover:
`execve_send` references the `bpf_loop` callback `cwd_read_v61` through an
`R_X86_64_PC32` text relocation rather than a PLT32 call. The x86 linker's
reachable-symbol walk now includes defined-text PC32 relocation targets, so
proof and kernel-mode relink include these callback bodies.

Several Tetragon startup programs are feature probes rather than benchmark
programs. The shim skip list was extended for exact Tetragon probe-name shapes
such as `probe_bpf_perf_`, `probe_kpm_link`, and related probe programs. This
keeps corpus app startup on the real app loader path while avoiding native
objects for temporary capability probes.

Tetragon also has many object-scoped maps with names that collide after
libbpf's 15-byte kernel object-name truncation. `libnativeloader` now carries
shape checks for the Tetragon maps encountered so far, including execve maps,
ring buffers, string maps, cgroup maps, policy/config maps, and heap maps. For
object-scoped Tetragon maps with duplicate names, the loader chooses the newest
open process map only after exact type/key/value/max-entry validation.

The first generic-kprobe runtime pass found an app-side loader assumption in
Tetragon: after native-loader replaces a program fd, `Program.Info().MapIDs()`
can include maps that are not present in cilium/ebpf's `coll.Maps` for the
currently opened collection. Tetragon's loader now falls back to
`ExtendedInfoFromMapID()` when `collMaps[id]` is nil. This is an app
compatibility fix, not a framework-side `.bpf.o` loader.

The native Tetragon build needed its host-object call shape aligned with what
native-link can prove and relink. `-fno-optimize-sibling-calls` prevents
tail-call optimized `jmp *GOT` lowering, and removing `-fno-plt` lets local
calls become direct PLT32/rel32 calls instead of GOTPCRELX indirect calls.
Tetragon's dynamically generated CEL expression functions are not present in
the prebuilt native object set, so the `MICRO_NATIVE` build uses the existing
stub CEL path. The current corpus policy does not use CEL expressions; adding
CEL native support later needs a manifest for generated CEL symbols.

Tetragon weak kfunc string helpers (`bpf_strnstr` and `bpf_strncasestr`) do
not have stable helper/kallsyms targets for native-link. The native build now
uses bounded local implementations for these helpers so substring filters keep
their semantics in native code.

`corpus/results/x86_kvm_corpus_20260524_171157_741655` reached the generic
kprobe sensor and replaced several `generic_kprobe_` instances, then failed on
`generic_kprobe_process_event` because the selected entry referenced
`heap_ro_zero` and the loader did not yet recognize that map symbol. The map
shape table now includes `heap_ro_zero` (`ARRAY key=4 value=16384 entries=1`)
and Tetragon's `heap` (`PERCPU_ARRAY key=4 value=4104 entries=1`, distinct
from bcc's same-named heap). The follow-up Tetragon smoke is in progress.

`corpus/results/x86_kvm_corpus_20260524_172528_643521` confirmed the
`heap_ro_zero` fix and replaced additional `generic_kprobe_` instances. The
next unresolved symbol was `override_tasks`, another Tetragon generic map. The
loader's exact-shape table now covers the generic maps observed in that run:
`process_call_heap`, `override_tasks`, `filter_map`, `config_map`,
`write_offload`, `argfilter_maps`, `policy_filter_maps`,
`policy_filter_cgroup_maps`, and `exit_heap_map`. These are still resolved
through type/key/value/max-entry validation, not by trusting the name alone.

`corpus/results/x86_kvm_corpus_20260524_173938_218000` moved past
`override_tasks` and then failed on `enforcer_data`, which is defined in
Tetragon's enforcer header and can be pulled into the same
`generic_kprobe_process_event` native object through policy action code. The
loader now covers `enforcer_data` (`HASH key=8 value=12 entries=1`) and the
adjacent `enforcer_missed_notifications` map (`HASH key=12 value=4
entries=128`, truncated in-kernel as `enforcer_missed`).

`corpus/results/x86_kvm_corpus_20260524_193347_242004` confirmed that the
enforcer maps were resolved and the next unresolved symbol was
`ratelimit_heap`. The loader now also covers Tetragon's rate-limit maps:
`ratelimit_heap` (`PERCPU_ARRAY key=4 value=352 entries=1`) and
`ratelimit_map` (`LRU_HASH key=224 value=8`, with dynamic max_entries allowed
because the Tetragon agent may resize it when rate limiting is configured).

`corpus/results/x86_kvm_corpus_20260524_194916_208340` confirmed the
rate-limit maps were resolved and failed later in the same
`generic_kprobe_process_event` entry on `stack_trace_map`. The loader now
covers the remaining generic-kprobe support maps that are both present in the
shim's map-create trace and defined in Tetragon source:
`stack_trace_map` (`STACK_TRACE key=4 value=1016`, dynamic entries allowed),
`retprobe_map` (`HASH key=16 value=24 entries=1024`), `fdinstall_map`
(`LRU_HASH key=16 value=4104`, dynamic entries allowed),
`sleepable_preload` (`HASH key=8 value=4100`, dynamic entries allowed),
`tg_ipv6_ext_heap` (`PERCPU_ARRAY key=4 value=8 entries=1`),
`tg_mb_sel_opts` (`ARRAY key=4 value=12 entries=10`), `tg_mb_paths`
(`ARRAY_OF_MAPS key=4 value=4 entries=10`), and the IPv4/IPv6 LPM
map-of-maps (`addr4lpm_maps` / `addr6lpm_maps`, `ARRAY_OF_MAPS key=4
value=4 entries=8`). These are still object-scoped exact-shape matches.

`corpus/results/x86_kvm_corpus_20260524_200649_820430` then loaded the first
Tetragon tracing policy's generic-kprobe programs natively and failed on the
second policy (`datagram`) when `generic_kprobe_process_event` referenced
`policy_stats`. The loader now covers `policy_stats` as an object-scoped
`ARRAY key=4 value=80 entries=1`, matching both Tetragon source and the shim's
map-create trace.

`corpus/results/x86_kvm_corpus_20260524_213823_386885` confirmed that
`policy_stats` was no longer a link/schema blocker: Tetragon reached 248 native
fd replacements with no native-loader failures before the VM panicked while
running the `datagram` policy path under `__sk_free`. The panic signatures were
native `generic_kprobe_` stubs reading or writing vmalloc/percpu-looking
addresses that had been patched into the native blob as direct ARRAY or
PERCPU_ARRAY value pointers. The leading diagnosis is lifetime rather than
symbol resolution: Tetragon is a Go binary, and Go/x/sys can issue raw syscalls
such as `close_range` without going through LD_PRELOAD's libc `syscall` or
`close_range` interceptors. A hidden fd retained only in the app process fd
table is therefore not a sufficient owner for verifier-invisible native map
pointers. The shim is being changed to transfer retained map fds to a minimal
keeper child process via `SCM_RIGHTS`; the child holds the map references
outside the app's fd table so raw `close_range` cannot free maps still
referenced by attached native programs. The shim now also logs BPF program tags
in `native-loader jit-info` so future kernel oops tags can be matched back to
the exact replacement line.

`corpus/results/x86_kvm_corpus_20260524_220355_937610` validated that diagnosis:
with retained map fds moved out of the app fd table into the keeper child, the
same single-app Tetragon smoke completed with `status=ok`. The run crossed the
previous 248-replacement crash point, reached 288 native fd replacements, and
finished the `stress_ng_tetragon_policy_hot` workload without native-loader
failures or kernel oops/panic. The keeper intentionally retains native-loader
map references until app exit rather than trying to mirror per-program close
lifetime; that is the conservative app-level loader behavior while native blobs
hold verifier-invisible direct map/value pointers.

`corpus/results/x86_kvm_corpus_20260524_083558_419282` moved past the remaining
Cilium feature-map mismatches and loaded many native host/LXC programs, but the
VM later crashed in a native replacement for `cil_from_host`:
`native_lab_stub+0x931/0xdaa` faulted while dereferencing a pointer derived from
the `cilium_metrics` map lookup path. Local proof disassembly matched the
faulting range to the hash/percpu-hash lookup post-call inline sequence. That
sequence assumed the helper target returned an internal `struct htab_elem *`
and then adjusted it to the map value, but the app-level native loader is
calling the real kernel helper ABI and must trust the helper return value
directly.

The linker policy is now narrower: only ARRAY and PERCPU_ARRAY lookups are
lowered to direct value-pointer inline code. HASH, LRU_HASH, and PERCPU_HASH
sites still consume their typed metadata, but x86 and arm64 both lower them to a
plain `bpf_map_lookup_elem` helper call with no post-call pointer arithmetic.
That trades away one unsafe optimization for correctness across real corpus app
loaders and avoids coupling native-link to kernel-internal hash map layouts.

The follow-up Cilium retry
`corpus/results/x86_kvm_corpus_20260524_084750_142667` showed the same visible
fault address, but after disassembling the panic bytes the failing sequence was
not hash lookup. It was the x86 `bpf_tail_call` inline sequence generated for
`cil_from_host`: compare `prog_array->max_entries`, load the BPF JIT
tail-call-counter pointer, read the prog-array slot, then jump to the target
program. The native linker had decoded `sub rsp, 0x48` and `add rsp, 0x48` as
plain unsupported immediates because iced-x86 reports these encodings as
`Immediate8to64`. As a result, the tail-call lowering believed the saved BPF
`rbp` was at `[rsp+8]` instead of `[rsp+0x50]`, and it also omitted the
`add rsp, 0x48` native-frame cleanup on successful tail calls.

The x86 stack-adjust recognizer now accepts iced-x86 sign-extended immediate
forms (`Immediate8to16`, `Immediate8to32`, and `Immediate8to64`) for both
`sub rsp, imm` prologue detection and `add rsp, imm` epilogue cleanup. A unit
test covers the concrete `push rbp; push r12; sub rsp, 0x48; ...; add rsp,
0x48; pop r12; pop rbp; ret` shape and asserts that tail-call lowering uses
saved BPF `rbp` offset `0x50` and preserves the stack cleanup bytes.

`corpus/results/x86_kvm_corpus_20260524_090008_268384` confirmed the x86
tail-call stack fix eliminated the kernel oops, but Cilium still timed out
waiting for initial endpoint generation. The shim log showed two native
artifact/configuration problems:

- runtime Cilium loaded `tail_no_service*`, but the native Cilium objects did
  not build those symbols because `SERVICE_NO_BACKEND_RESPONSE` was missing;
- selected LXC/host native tail programs still referenced
  `cilium_subnet_map` / `__config_hybrid_routing_enabled`, while the corpus
  runner does not create the subnet map.

The Cilium native build now defines `SERVICE_NO_BACKEND_RESPONSE=1` so the
native stage contains both full and libbpf-truncated `tail_no_service` aliases.
Host native flags were narrowed to avoid tunnel-only subnet references. For
LXC, the `MICRO_NATIVE` build compiles the hybrid subnet-id checks out of both
IPv4 and IPv6 destination-classification paths, matching the corpus app's
current no-subnet-map configuration. The `native-cilium` stage rule now also
deletes stale staged `.native.o` aliases before installing the current symbol
set; otherwise an earlier wider build can leave obsolete IPv6 tail aliases that
the shim would still discover.

`corpus/results/x86_kvm_corpus_20260524_091700_298133` then failed in a new
place: `cil_xdp_entry` faulted at native stub offset `0x22` while reading the
absolute address patched for `__config_tracing_ip_option_type`. This matched
the native JIT dump for the second XDP replacement. The root cause was native
map/data relocation lifetime, not XDP packet bounds: `load_from_fd()` discovers
extra maps through the native object's `.maps` and `.rodata*` symbols, but the
C API only returned the native prog fd. The shim retained only maps visible in
the original loaded program/source BPF. When native C is wider than verifier-DCE
source BPF, a patched data-map value pointer can outlive the app's libbpf map
fd and become dangling.

`libnativeloader` now records kernel map ids for every `MapMeta`, reopens every
map that participated in native map/data relocation, and returns those owned fds
through the C API. The shim merges that fd list into the native prog entry so
the original prog fd and every raw map/value pointer owner stay alive until the
app closes the returned native fd (or the shim drops the prog entry).

`corpus/results/x86_kvm_corpus_20260524_092723_879300` confirmed that the data
relocation lifetime fix moved Cilium past the `cil_xdp_entry` crash, but the
app still timed out while generating the first endpoint. This time the failure
mode was fd pressure rather than a native-code fault: each Cilium reload
retained 30-45 map fds per native program, and many of those fds were duplicate
references to the same kernel map ids. Once the process approached the fd
limit, native-loader calls failed with `bpf_map_get_fd_by_id(...): Too many
open files`, the real Cilium fallback loads started returning `ENOSPC`, and
endpoint generation never completed.

The shim now owns a process-wide native map-ref table keyed by kernel map id.
The native-loader C API still returns owned fds, but the shim consumes them into
that shared table and stores only the per-program map ids. Multiple native
programs that reference the same map increment a refcount and close the
duplicate fd, so one kernel map costs one process fd instead of one fd per
native replacement. Successful replacement also closes the original BPF program
fd immediately after the native fd is loaded and the map refs are retained; the
original fd is not returned to the app and is not needed for native execution.

The same artifact exposed one missing helper declaration: Cilium
`tail_no_service` uses helper id 50 (`bpf_skb_adjust_room`). That helper is now
included in both libnativeloader's supported-helper table and native-link's x86
immediate-helper-id mapping.

`corpus/results/x86_kvm_corpus_20260524_094241_164017` verified that the shared
map-ref table fixed the fd-pressure class: native replacements stayed in the
low hundreds of fd numbers and no `Too many open files` failures appeared. The
remaining endpoint timeout had two distinct causes:

- `tail_no_service` variants loaded through `cilium_calls_ne` could not be
  mapped to a native object prefix. The shim now treats `cilium_calls_ne` as a
  host/netdev Cilium call map and selects `bpf_host.*.native.o`.
- `tail_handle_ipv4_cont` can contain a `bpf_fib_lookup` native call even when
  the source companion JIT oracle does not expose a matching helper call-site.
  This is another Cilium native-source width mismatch: native C includes a
  broader helper path than the specific loaded BPF variant. `libnativeloader`
  now passes known prog-type contextual helper aliases (`bpf_fib_lookup`,
  `bpf_redirect_map`, `bpf_skc_lookup_tcp`, `bpf_sk_lookup_udp`, and
  `bpf_get_prandom_u32`) whenever their kernel symbols are available, so
  native-link does not depend on the companion oracle to discover those
  addresses.

`corpus/results/x86_kvm_corpus_20260524_100441_908658` got past native-link
and native-loader failures, then crashed at runtime in a native
`tail_nodeport_rev_dnat_ipv4` replacement. The panic bytes showed the native
program reading a packet pointer from `ctx->data` at fake `struct __sk_buff`
offset `0x4c`, receiving zero, passing a bogus `data + 4 <= data_end` check,
and dereferencing address 0. This is the TC/SchedCLS counterpart to the earlier
XDP ctx issue: native-lab receives the kernel's real `struct sk_buff *`, while
BPF C is written against the verifier's UAPI `struct __sk_buff` mirror. The
kernel verifier normally rewrites those ctx accesses before JIT; native C must
model that rewrite explicitly.

The Cilium `MICRO_NATIVE` build now overlays the subset of real `sk_buff`
layout that Cilium reads directly (`cb`, `len`, `data_len`, `queue_mapping`,
`tc_index`, `priority`, `skb_iif`, `hash`, VLAN fields, `mark`, `protocol`,
`head`, and `data`) and has compile-time offset assertions for those ABI
fields. `ctx_data()` returns `skb->data`, `ctx_data_end()` returns
`skb->data + (skb->len - skb->data_len)`, `ctx_data_meta()` uses the
`skb_shared_info.meta_len` byte, and `ctx_get_ifindex()` reads
`skb->dev->ifindex` through a small native-only `net_device` overlay. The few
source sites that cannot be represented as direct fields (`ctx->ifindex`,
`ctx->vlan_present`, `ctx->data_end`, and `ctx->tc_classid`) now go through
native-safe accessors or are skipped under `MICRO_NATIVE`. A forced
`make -B -C vendor/bpf native-cilium` after this change passed, including the
proof-link stage.

`corpus/results/x86_kvm_corpus_20260524_101850_953210` still crashed the VM,
but the crash signature changed: the faulting RIP was an NX vmalloc/data page
entered from Cilium `tail_handle_ipv4_cont`, and the local reproduction of the
linked blob showed a literal `call *%r12` at the matching offset. The source
disassembly mapped it to `policy.h:302` (`map_lookup_elem(map, &key)`). LLVM
had hoisted Cilium's static helper function pointer into a callee-saved
register, while native-link's helper recognizer only handled immediate helper
ids that stayed locally visible. The generated native blob therefore kept an
unresolved register-indirect call and could jump to a map/data pointer in
kernel space.

The fix has two parts. First, native-link now fails fast on any register-
indirect x86 call that cannot be resolved as a BPF helper before kernel load.
This turns the previous kernel panic class into a proof/link-time error.
Second, the Cilium `MICRO_NATIVE` helper declarations now wrap non-colliding
helper calls with a small inline-asm identity on the helper id, so each callsite
materializes an immediate helper id near the call. Helper names that Cilium
redefines as local XDP wrappers are intentionally not macro-wrapped to avoid
polluting local function definitions.

Enabling the fail-fast check exposed two correctness gaps in proof mode rather
than at runtime: proof mode was not tracking immediate helper-id loads, and
then cleared the tracked register when it preserved the `mov imm, %reg`
instruction. Proof mode now records those helper-id loads while preserving the
original instruction stream. Cilium socket programs then exposed missing helper
ids in native-link's immediate-helper table (`bpf_setsockopt`,
`bpf_getsockopt`, `bpf_get_netns_cookie`, `bpf_sk_lookup_tcp`, `bpf_seq_write`,
`bpf_ringbuf_*`, `bpf_for_each_map_elem`, `bpf_loop`, `bpf_set_retval`, and
`bpf_map_lookup_percpu_elem`). After these additions, a forced
`make -B -C vendor/bpf native-cilium` passed again across the selected Cilium
native objects and their proof-link outputs.

The same fail-fast change initially blocked later `make corpus` dependency
preparation before the Cilium VM even started: `vendor/bpf native-artifacts`
rebuilds all native artifacts, and BCC `biosnoop.block_rq_complete` had a
callee-saved `call *%r13` to a hoisted `bpf_probe_read_kernel` GOT helper from
`BPF_CORE_READ`. That path is legitimate and should not be rejected. The x86
linker now tracks `bpf_*` GOT helper loads in proof mode as well as kernel-link
mode and routes the later register call through the same helper-call lowering.
The old direct `mov helper_addr, %reg` builder became unused and was removed to
avoid dead code. A forced `make -B -C vendor/bpf native-bcc` now passes proof
for the selected BCC objects.

The next all-artifact dependency blocker was OTEL proof linking. First,
`custom__generic` left a `call *%r14` after `bpf_map_update_elem`: LLVM loaded
helper id 1 into `%r14d`, used `%rax` for the update helper, and then reused
`%r14` for the following `bpf_map_lookup_elem`. Native-link now tracks known
helper-id immediates even when another helper call appears before the later
register-indirect call. Direct adjacent helper-id loads are still dropped in
kernel-link mode as before; non-adjacent known ids are metadata only.

OTEL then exposed a harder branch case in `finish_task_switch` and
`kprobe_go_labels`: a helper id can be materialized before a conditional branch,
while one branch path writes the same register for debug strings and the other
branch path later uses it as the helper call register. Rather than making
native-link's helper recognizer a full path-sensitive dataflow engine, OTEL's
`MICRO_NATIVE` helper definitions now use per-call helper macros. The helper id
passes through a volatile inline-asm identity that depends on the actual call
arguments, which keeps helper-id materialization after the branch-specific
arguments are available and prevents the problematic cross-branch hoist. A
forced `make -B -C vendor/bpf native-otel` now passes proof for all selected
OTEL native entries.

`corpus/results/x86_kvm_corpus_20260524_105729_546094` exposed an x86
BlockEncoder boundary failure in Cilium `tail_ipv4_policy`: helper/map
rewrites expanded a short branch to exactly the i8 edge and iced failed with
`Branch distance is too far away`. Native-link now has a near-branch
re-encoding fallback for local x86 blocks.

The follow-up Cilium run (`corpus/results/x86_kvm_corpus_20260524_111329_901522`)
then loaded farther and crashed in native `tail_ipv4_ct_eg` during pktgen. The
panic RIP landed inside a `movabs` immediate, not at an instruction boundary.
Local reproduction with `tail_ipv4_ct_egress` showed why: kernel-link mode
deletes immediate helper-id loads such as `mov ecx, 5`, but proof-mode
branches can legally target that deleted instruction. The old fast path let
iced keep such a target in the old local-IP coordinate space, so the final
branch could jump into the middle of a later expanded instruction.

Native-link now detects local branch targets that no longer have a surviving
instruction, widens local branches to near form, dry-runs the widened layout,
retargets each local branch to the first surviving instruction at or after the
original target, and final-encodes with instruction IPs reset to the dry-run
new offsets. A manual `tail_ipv4_ct_egress` link/disasm check found 195 local
branches and zero targets outside instruction starts after this fix.

`corpus/results/x86_kvm_corpus_20260524_112704_659739` then completed Cilium
baseline measurement but crashed during the post-rejit phase in native
`cil_xdp_entry` at the first `.rodata.config` byte load. The native stub's
first `movabs` immediate was the expected Cilium config value address:
`map_ptr + K_BPF_ARRAY_VALUE_OFFSET + 0x6e` for
`__config_tracing_ip_option_type`. The fault was therefore not a relocation
name mismatch; it was a stale vmalloc data page, consistent with the map being
released after native-link patched the direct array-value pointer into the
blob.

The native-loader shim already kept referenced maps alive through hidden
`bpf_map_get_fd_by_id()` fds, but those fds lived in the same app process fd
table. Any app-side `close_range()` or raw `syscall(SYS_close, fd)` sweep could
close them without going through the shim's `close()` bookkeeping, leaving the
native program attached while its verifier-invisible maps were freed. The shim
now treats native-loader retained map fds as protected: intercepted `close()`,
raw `SYS_close`, and `close_range()` skip those hidden fds; `close_range` only
falls back to per-fd closing when the requested range would otherwise include a
native-loader retained fd. This preserves the direct native map/value pointer
lifetime independently of app fd cleanup patterns.

`corpus/results/x86_kvm_corpus_20260524_120125_269563` confirmed that the
Katran truncated-name alias fix was sufficient for shim object selection, but
then failed in native-link kernel mode for `balancer_ingres` with
`x86 helper call jhash has no helper address`. The object-level proof pass had
correctly discovered `balancer_ingress`, `jhash`, and `jhash_2words`; the
failure appeared only when native-loader fed the proof object back into
native-link for the kernel blob.

The root cause was proof relocation normalization. Katran's original object
used a section-symbol PLT32 relocation such as `.text + 0x5c`, whose effective
call target is the `jhash` entry after applying x86's `+4` PC-relative rule.
Proof-mode rewrote that relocation to symbol `jhash` but preserved the old
section-relative addend, producing `jhash + 0x5c`. A second native-link pass
then treated the local function as unreachable and left an undefined `jhash`
call that later looked like a helper. The x86 proof reloc writer now
renormalizes PLT32 addends when retargeting a section-relative relocation to a
real function symbol. Local verification with `balancer_ingres.native.o`
shows the first proof object now emits `jhash - 4`, and a second proof pass
keeps all three reachable symbols.

`corpus/results/x86_kvm_corpus_20260524_121101_645894` then got past
native-link and loaded Katran's native XDP program, but the VM panicked in
`native_lab_stub+0x8b` while `balancer_ingres` was processing an XDP packet.
The faulting register held `0x0000000093977100`; the linked disassembly showed
the program was reading `ctx->data` as a 32-bit UAPI `xdp_md.data` field and
then dereferencing the truncated low bits as a packet pointer. That is wrong
for app-level native XDP because the real kernel entry context is
`struct xdp_buff *`.

Katran's `MICRO_NATIVE` build now overlays `struct xdp_md` with the real
`xdp_buff` pointer layout (`data`, `data_end`, `data_meta`, `data_hard_start`,
`rxq`, `txq`, `frame_sz`, `flags`) and compile-time offset assertions. The
native `balancer_ingress` entry now loads `data` and `data_end` with 64-bit
loads from offsets 0 and 8 before touching packet headers. The same native
header also overlays `struct __sk_buff` for TC healthcheck programs and adds
`katran_skb_data()` / `katran_skb_data_end()` accessors, because real
`sk_buff` has no UAPI `data_end` field. `healthchecking.c` and
`healthchecking_helpers.h` now use those accessors at direct packet-boundary
sites. A forced `make -B -C vendor/bpf native-katran` passed after this fix.

### Tracee native C compatibility and proof

Tracee's BPF sources use sparse helper-id enum initializers, CO-RE register
helpers, inline BPF bounds-check assembly, and BPF-only convenience macros that
do not compile as normal native C. The native artifact build now compiles the
main `tracee.bpf.c` object with `MICRO_NATIVE_HELPER_MACROS`,
`__BPF_TRACING__`, `CORE`, and `COMMON_BUILD`, plus native compatibility
definitions for target-arch macros, `PT_REGS_*_CORE`, CO-RE stubs, and helper
declarations. The main object proof-linked all 172 selected text symbols.

The first attempt to rebuild all native artifacts for a Tracee corpus run failed
before the VM because `vendor/bpf/native_compat.h` included `<stddef.h>`, while
BCC's generated `vmlinux.h` already defines `wchar_t`. The fix is to avoid the
system header in the native compatibility shim and define `offsetof` with
`__builtin_offsetof` when the macro is absent. A follow-up
`make -C vendor/bpf native-bcc` passed, so the global compatibility header no
longer breaks already-enabled BCC native artifacts.

Tracee's two LSM support probes are loaded from separate tiny objects before
the main Tracee object. The first runtime smoke confirmed the shim can resolve
and replace both `security_bpf_kp` and `lsm_bpf_check` through native-loader,
using the staged support-probe native objects. That validates the object-path
aliasing for libbpf-truncated program names in this app.

The same run then failed on the first main Tracee program with
`native map symbol cgroup_id_filter_version matches multiple open process maps
named cgroup_id_filte`. This is the same kernel object-name truncation class as
Cilium, but for Tracee map-of-maps version maps: the outer
`*_version` map and inner/template maps can share the same 15-byte kernel name.
The loader now recognizes `*_version` native symbols as
`BPF_MAP_TYPE_HASH_OF_MAPS` with key size 0, value size 4, and max entries 64,
so map-of-maps version symbols can be disambiguated by shape instead of choosing
an arbitrary open process map. Unknown or still-ambiguous Tracee map symbols
continue to fail the native load.

The next Tracee retry then failed on `policies_config_map`. That symbol is an
inner/template hash map, and Tracee can keep multiple same-name same-shape inner
maps open while loading the map-of-maps version tables. Native objects also
carry `.maps` symbols for sections that the selected entry does not necessarily
reference. The loader therefore no longer fails during eager open-process map
aliasing when a `.maps` symbol has multiple different kernel map candidates; it
skips that eager alias and lets native-link decide. If the selected entry really
contains a relocation to the ambiguous symbol, the link still fails because no
`--map` record exists. This keeps unused `.maps` definitions from blocking
Tracee startup without falling back to the original BPF program.

The following Tracee retry reached workload startup but panicked the VM in
`bpf_map_lookup_elem` from native `trace_security_bpf_prog`. The panic register
state showed `rdi` pointing at the BPF stack instead of a `struct bpf_map *`.
Offline kernel-link/disassembly of the same symbol exposed the cause:
`native-link` treated any x86 GOT load whose target name started with `bpf_` as
a helper pointer. Tracee has real maps named `bpf_attach_tmp_map` and
`bpf_attach_map`; their map-load instructions were dropped, so later
`bpf_map_lookup_elem` / update / delete helpers inherited stale argument
registers. The x86 rewriter now gives known map symbols priority over the
`bpf_` helper-name heuristic. A repeat offline link of
`trace_security_bpf_prog` shows the `bpf_attach_*` sites now emit
`movabs map,%rdi` before the helper calls, and map patch sites increased from
23 to 28, matching the recovered map loads.

The retry after that linker fix passed the real Tracee app path:
`corpus/results/x86_kvm_corpus_20260524_133325_153376`. The workload completed
both baseline and post-rejit measurement phases, and the shim log shows native
replacement for the main Tracee kprobe/raw-tracepoint/LSM/cgroup programs
rather than a silent fallback to original BPF.

### 2026-05-25 native corpus measurement status

The formal native-vs-original BPF-counter runs use app-level startup with the
real corpus app and only switch post-rejit loads to native-loader:

```
BPFREJIT_CORPUS_APPS=<app> BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit make corpus
```

This keeps baseline as upstream eBPF and post-rejit as native-loaded programs.
The `post` mode is required for performance measurement; `1` is only a
correctness smoke because it native-loads both phases.

Completed BPF-counter runs:

- BCC set:
  `corpus/results/x86_kvm_corpus_20260525_001244_895347`. Status ok,
  25 baseline/post programs, 25 native replacements, no native-loader failures.
  Exact hash-based mapping produced 15 paper-qualified programs
  (`min(run_cnt_delta) >= 100`), geomean native/original avg-run-ns ratio
  0.9398 (1.064x speedup), wins/losses 9/6.
- OTEL profiler:
  `corpus/results/x86_kvm_corpus_20260525_003104_503151`. Status ok,
  14 native replacements, no native-loader failures. Only
  `native_tracer_entry` is paper-qualified; its native/original avg-run-ns
  ratio is 0.0648 (15.4x speedup). The `perf_unwind_*` tail-call targets have
  zero run counters as expected; savings are charged to the directly attached
  caller.
- Cilium agent:
  `corpus/results/x86_kvm_corpus_20260525_004700_768372`. Status ok,
  135 native replacements, no native-loader failures. Two directly attached
  `cil_from_container` programs qualify, with geomean native/original
  avg-run-ns ratio 0.4588 (2.18x speedup). The BPF-stats-on workload samples
  also show pktgen throughput increasing from about 0.64 Mpps to about
  1.58 Mpps in each direction, but final workload numbers still need the
  stats-off configuration.
- Katran:
  `corpus/results/x86_kvm_corpus_20260525_015347_680652`. Status ok,
  1 native replacement, no native-loader failures. The standalone
  `balancer_ingres` XDP program is the only paper-qualified program; its
  avg-run-ns ratio is 0.8288 (1.21x speedup). The BPF-stats-on workload data is
  not yet conclusive because one post-rejit pktgen sample dropped well below
  the other two despite the run-counter speedup. This requires stats-off
  workload validation before claiming an app-level Katran benefit.
- Tracee:
  `corpus/results/x86_kvm_corpus_20260525_020803_759245`. Status ok,
  169 native replacements, no native-loader failures. Attach-symbol matching
  plus unique shape matching produced 39 paper-qualified programs with geomean
  avg-run-ns ratio 0.9091 (1.10x speedup), wins/losses 20/19. The distribution
  is mixed: `fd_install`, `security_file_permission`, raw syscall tracepoints,
  and several file-update sites improve, while `security_task_prctl`,
  `commit_creds`, `trace_ret_vfs_read`, and some sched/raw-tracepoint paths
  regress. The stress-ng workload output in this stats-on run is close enough
  that the final direction must come from the stats-off workload run.

Tetragon initially looked like a severe native slowdown, but the first matching
attempt was not trustworthy because many probes are named `generic_kprobe_` or
`generic_retkpro` after kernel/libbpf truncation. A log-only shim update now
records `BPF_TASK_FD_QUERY` after successful perf-event `BPF_LINK_CREATE`, so
the analysis can key directly attached programs by attach symbol instead of
only by name/type/size. The later run
`corpus/results/x86_kvm_corpus_20260525_013654_901087` produced 48 successful
task-fd-query records in both baseline and post-rejit logs, so the duplicate
name ambiguity is now observable.

The attach-symbol matched Tetragon data still shows a real problem rather than
just a matching artifact: 8 directly attached programs qualify, with geomean
native/original avg-run-ns ratio 3.28 (0.305x, a slowdown). The largest losses
are high-frequency small hooks such as `fd_install`, `ip_output`,
`tcp_sendmsg`, and `sys_enter`, where the generated native-lab program is about
5 us/run while the original JITed BPF is hundreds of ns/run. The same run's
stress-ng workload output drops by roughly 3-6x for
eventfd/udp/sockfd/sockpair. This must be validated again with BPF stats
disabled, but it is currently treated as a generated native wrapper/blob fixed
cost issue on tiny high-frequency probes, not as an analysis matching bug.

Stats-off workload runs use:

```
BPFREJIT_CORPUS_APPS=<app> BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit BPFREJIT_CORPUS_BPF_STATS=0 make corpus
```

These runs are executed one app at a time and are the source for app-level
workload numbers, because they remove the BPF stats accounting overhead from
the workload path.

Stats-off workload results so far:

- BCC set:
  `corpus/results/x86_kvm_corpus_20260525_022330_721266`. Status ok,
  `bpf_stats=false`, 25 post native replacements, no native-loader failures.
  Baseline/post each ran 3 stress-ng workload samples successfully. The stable
  stressors are essentially flat at app level: `cap` and `set` are slightly
  higher with native loading, while `sockfd` is slightly lower. The `syscall`
  stressor produced one post sample with much larger bogo-ops than the other
  five samples; that is treated as a stress-ng workload metric instability, not
  as evidence of a real native speedup. Cross-check: this is consistent with
  the BPF-counter result, which showed only a modest BCC per-program speedup
  and several small regressions.
- OTEL profiler:
  `corpus/results/x86_kvm_corpus_20260525_023816_629087`. Status ok,
  `bpf_stats=false`, 14 post native replacements, no native-loader failures.
  All mixed-language workload components returned 0. Workload ops/s improves
  strongly and consistently with native loading: Node workers are about
  5.9-7.0x faster, Python about 1.4-1.6x, Ruby about 1.3-1.7x, PHP about
  1.3-1.6x, Perl about 1.3-1.6x, and stress-ng CPU about 1.34x. Cross-check:
  this agrees with the BPF-counter run where the directly attached
  `native_tracer_entry` became about 15.4x faster; the workload improvement is
  smaller because the profiler is only part of total process runtime, but the
  direction is consistent and all workload processes completed successfully.
- Cilium agent:
  `corpus/results/x86_kvm_corpus_20260525_025332_109685`. Status ok,
  `bpf_stats=false`, 135 post native replacements, no native-loader failures.
  Baseline and post each ran three forward and three reverse endpoint pktgen
  components successfully, with zero reported pktgen errors. Baseline forward
  samples were 704994, 702202, and 708863 pps; post forward samples were
  1847506, 1825849, and 1813845 pps. Baseline reverse samples were 704968,
  700010, and 707154 pps; post reverse samples were 1861620, 1823601, and
  1865035 pps. Cross-check: this app-level 2.6x-ish throughput increase is in
  the same direction as the BPF-counter run's 2.18x per-program speedup for
  the directly attached `cil_from_container` programs, and the zero-error
  pktgen output argues against a fake speedup from packets being dropped or the
  datapath being skipped.
- Tetragon observer:
  `corpus/results/x86_kvm_corpus_20260525_030809_301462`. Status ok,
  `bpf_stats=false`, 288 post native replacements, no native-loader failures,
  and 48 successful `BPF_TASK_FD_QUERY` records in both baseline and post logs.
  All three baseline and post stress-ng workload samples returned 0, but the
  app-level throughput regression is large and repeatable. Mean post/baseline
  `ops/s_real` ratios are about 0.163 for `eventfd`, 0.168 for `sockfd`,
  0.236 for `sockpair`, 0.323 for `udp`, 0.574 for `sock`, and 0.769 for
  `mmap`. Cross-check: this agrees with the attach-symbol matched BPF-counter
  run where the high-frequency small hooks (`fd_install`, `ip_output`,
  `tcp_sendmsg`, `sys_enter`) slowed down heavily under native loading. The
  current interpretation is a real native-stub overhead problem on tiny
  Tetragon probes, not a workload failure or program-matching artifact.
- Katran:
  `corpus/results/x86_kvm_corpus_20260525_032310_956001`. Status ok,
  `bpf_stats=false`, 1 post native replacement, no native-loader failures.
  Each sample runs four pktgen threads. The per-thread output includes large
  `errors:` counts in both baseline and post, but every thread reports
  `Result: OK` and returns 0, so this is not a native-only correctness failure
  in this workload. The safer app-level metric is the per-sample total pps over
  the four threads: baseline totals are 2934983, 2881127, and 2907982 pps; post
  totals are 3216017, 3183728, and 3255834 pps. Mean total pps improves by
  about 1.11x. Cross-check: this is consistent with the BPF-counter run's
  1.21x avg-run-ns speedup for standalone `balancer_ingres`; the earlier
  stats-on low post sample did not reproduce as a post-only problem when BPF
  stats were disabled.
- Tracee monitor:
  `corpus/results/x86_kvm_corpus_20260525_033753_511202`. Status ok,
  `bpf_stats=false`, 169 post native replacements, no native-loader failures,
  and 133 successful `BPF_TASK_FD_QUERY` records in both baseline and post
  logs. All baseline and post stress-ng samples returned 0. Workload throughput
  is consistently lower with native loading: mean post/baseline `ops/s_real`
  ratios are about 0.905 for `sigfd`, 0.923 for `cap`, 0.937 for `set`, 0.944
  for `kill`, 0.952 for `eventfd`, 0.978 for `prctl`, and 0.984 for `futex`.
  Cross-check: this does not match the BPF-counter geomean's slight 1.10x
  per-program win, but the counter distribution was mixed with several
  high-frequency regressions. The current interpretation is that Tracee native
  loading is functionally correct but app-level stress throughput is dominated
  by the regressing hooks and/or event-processing overhead, so this app should
  be reported as a workload slowdown despite a small per-program counter win.

### 2026-05-25 full-suite reruns and final app interpretation

Full BPF-counter corpus rerun:

```
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit make corpus
```

Artifact: `corpus/results/x86_kvm_corpus_20260525_035337_555709`.
The suite status is `ok`, `bpf_stats=true`, `samples=3`,
`workload_seconds=30`, and all six app result files are `ok`. Post-phase shim
logs record the same native replacement coverage as the one-app runs and no
native-loader failures: BCC 25, OTEL 14, Cilium 135, Tetragon 288, Katran 1,
Tracee 169.

Paper-grade counter interpretation, using post-hoc analysis with
`min(run_cnt_delta) >= 100` and native/original avg-run-ns ratios:

| App | Qualified direct programs | Native/original avg-run-ns geomean | Counter interpretation |
| --- | ---: | ---: | --- |
| BCC set | 15 | 0.9299, 1.075x faster | Small per-program win, mixed sites. |
| OTEL profiler | 1 | 0.0674, 14.83x faster | Strong win on `native_tracer_entry`; tail targets are charged to the caller. |
| Cilium agent | 2 | 0.4291, 2.33x faster | Strong win on the two active `cil_from_container` paths. |
| Tetragon observer | 8 | 4.4405, 0.225x | Severe slowdown on high-frequency tiny hooks. |
| Katran | 1 | 0.7952, 1.26x faster | Modest XDP win on `balancer_ingres`. |
| Tracee monitor | 40 | 0.8952, 1.12x faster | Mixed; wins and losses are almost balanced. |

The Cilium full-suite counter match uses the two active `cil_from_container`
programs by program shape because per-phase map identities change the raw load
hashes. The two pairings are stable because both entries have the same program
shape and nearly identical run counts/ratios; either ordering gives the same
geomean to the reported precision.

Full workload-number corpus rerun with kernel BPF stats disabled:

```
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_BPF_STATS=0 make corpus
```

Artifact: `corpus/results/x86_kvm_corpus_20260525_043133_695517`.
The suite status is `ok`, `bpf_stats=false`, `samples=3`,
`workload_seconds=30`, and all six app result files are `ok`. Post-phase native
replacement counts are again BCC 25, OTEL 14, Cilium 135, Tetragon 288,
Katran 1, Tracee 169, with zero native-loader failures.

Stats-off workload numbers:

| App | Workload metric | Baseline mean | Native mean | Native/baseline | Final workload interpretation |
| --- | --- | ---: | ---: | ---: | --- |
| BCC set | `cap` ops/s real | 422694.55 | 423642.64 | 1.002 | Flat. |
| BCC set | `set` ops/s real | 30888.38 | 31010.32 | 1.004 | Flat. |
| BCC set | `sockfd` ops/s real | 262616.37 | 262412.57 | 0.999 | Flat. |
| BCC set | `syscall` ops/s real | 105.13 | 16.58 | 0.158 | Unstable stress-ng signal; one baseline outlier, not used as a real native effect. |
| OTEL profiler | Node.js ops/s | 986051.6 | 8765656.6 | 8.890 | Strong app-level speedup. |
| OTEL profiler | Python ops/s | 2294704.3 | 3737779.9 | 1.629 | Strong app-level speedup. |
| OTEL profiler | Ruby ops/s | 5962359.1 | 8732203.5 | 1.465 | Strong app-level speedup. |
| OTEL profiler | PHP ops/s | 9811407.1 | 14402807.9 | 1.468 | Strong app-level speedup. |
| OTEL profiler | Perl ops/s | 2876300.8 | 3973204.0 | 1.381 | Strong app-level speedup. |
| OTEL profiler | stress-ng CPU ops/s real | 831.9 | 989.4 | 1.189 | Modest supporting speedup. |
| Cilium agent | forward pktgen pps | 709203 | 1862566 | 2.626 | Strong datapath speedup, zero pktgen errors. |
| Cilium agent | reverse pktgen pps | 709441 | 1886538 | 2.659 | Strong datapath speedup, zero pktgen errors. |
| Tetragon observer | `eventfd` ops/s real | 70249.03 | 12262.22 | 0.175 | Severe slowdown. |
| Tetragon observer | `sockfd` ops/s real | 127668.33 | 22290.82 | 0.175 | Severe slowdown. |
| Tetragon observer | `sockpair` ops/s real | 45123.69 | 10682.77 | 0.237 | Severe slowdown. |
| Tetragon observer | `udp` ops/s real | 118695.17 | 35828.71 | 0.302 | Severe slowdown. |
| Tetragon observer | `sock` ops/s real | 361.23 | 210.16 | 0.582 | Slowdown. |
| Tetragon observer | `mmap` ops/s real | 25.92 | 21.92 | 0.845 | Small slowdown. |
| Katran | four-thread total pktgen pps | 2905920 | 3141304 | 1.081 | Modest speedup; high pktgen errors exist in both phases and every component reports `Result: OK`. |
| Tracee monitor | `cap` ops/s real | 79192.08 | 75231.28 | 0.950 | Slowdown. |
| Tracee monitor | `eventfd` ops/s real | 43716.25 | 40570.35 | 0.928 | Slowdown. |
| Tracee monitor | `futex` ops/s real | 85069.30 | 86260.28 | 1.014 | Flat/slightly up. |
| Tracee monitor | `kill` ops/s real | 32490.32 | 31665.60 | 0.975 | Flat/slightly down. |
| Tracee monitor | `prctl` ops/s real | 405.26 | 301.72 | 0.745 | Slowdown. |
| Tracee monitor | `set` ops/s real | 6562.33 | 6136.21 | 0.935 | Slowdown. |
| Tracee monitor | `sigfd` ops/s real | 199164.02 | 193618.19 | 0.972 | Flat/slightly down. |

Final per-app conclusion:

- BCC is functionally correct but has no meaningful app-level workload benefit;
  the counter win is too small and mixed to survive at workload level.
- OTEL has a real benefit. Counter data and stats-off workload numbers agree,
  and the tail-call accounting is correctly measured at `native_tracer_entry`.
- Cilium has a real benefit. Both counter data and endpoint pktgen throughput
  show a large speedup, with zero pktgen errors.
- Tetragon is functionally correct but not beneficial. The slowdown is
  repeatable in counters and workload numbers and is consistent with generated
  native wrapper/blob fixed cost dominating tiny high-frequency hooks.
- Katran has a modest real benefit. The counter and workload directions agree;
  pktgen error counts are high in both phases, so they are a workload/topology
  caveat rather than a native-only correctness failure.
- Tracee is functionally correct but should be reported as a workload slowdown.
  The per-program counter geomean is slightly positive, but the distribution is
  mixed and stats-off workload metrics are mostly lower with native loading.

Proof status: the staged native artifact manifests under
`vendor/build/native-bpf/x86/stage/*/manifest.json` all report
`native-objects-proof-linked`, and the tree contains 111 `.proof.ok` markers
under `vendor/build/native-bpf/x86`. The final corpus runs loaded those staged
native artifacts through the real app startup paths.

### 2026-05-25 runner fallback cleanup

Follow-up cleanup removed the old `run-native-kernel --program <prelinked.blob>`
path from the C++ runner. `run-native-kernel` now requires the same Stage 2
shape used by normal micro native runs: `--program <companion.bpf.o>` plus
`--native-program <native.o>`, and the runner delegates companion loading,
native-link invocation, blob upload, and `native_lab_stub` `BPF_PROG_LOAD` to
`native-sim/libnativeloader`.

This also removes the arm64-only prelinked-blob smoke artifact under
`native-sim/arm64/native_lab_smoke`; that test was the only remaining caller of
the old blob path and could not exercise the shared loader library.

Terminology correction: `native_lab_stub` is the kernel-visible BPF program name
for the tiny `(sidecar; kinsn-call)*N; exit` wrapper that the native-lab kinsn
JIT expands with uploaded native bytes. It is not a separate user-space loader
stub, and the hot path should not be described as a normal kfunc call per event.
BPF entry/stats accounting is also not native-only overhead; ordinary JITed BPF
programs pay it too.

### 2026-05-25 shim manifest cleanup

Follow-up cleanup removed the old shim native-object environment contract:
`BPFREJIT_SHIM_NATIVE_OBJECT`, `BPFREJIT_SHIM_NATIVE_OBJECT_DIR`, and the
Cilium-specific object-name resolver. The shim now requires
`BPFREJIT_SHIM_NATIVE_MANIFEST` when native-loader mode is enabled. Corpus app
runners only provide that manifest path; they no longer compute per-program
native object paths in Python.

The manifest schema is intentionally small:

```json
{
  "version": 1,
  "app": "bcc",
  "status": "native-objects-proof-linked",
  "objects": [
    {
      "program": "kprobe__cap_cap",
      "native_object": "capable.native.o",
      "symbol": "kprobe__cap_capable_entry",
      "prog_type": 2,
      "source_map_prefix": "cilium_calls_0"
    }
  ]
}
```

`program` and `native_object` are required. `program` matches the kernel/libbpf
15-byte BPF program name. `symbol`, `prog_type`, and `source_map_prefix` are
optional selectors. `native_object` is resolved relative to the manifest
directory unless it is absolute. Multiple matching manifest entries are allowed
only when they resolve to the same object/symbol; otherwise the shim fails the
load as ambiguous.

`vendor/bpf/write_native_manifest.py` generates these manifests from native
object text symbols with optional per-object selectors. BCC truncated-name
collisions intentionally omit `symbol` so libnativeloader can recover the exact
BTF function name from the already-loaded oracle fd. Cilium disambiguation now
lives in manifest `source_map_prefix` / `prog_type` selectors rather than
hardcoded shim string logic.

The C ABI exported for the shim has also been reduced to the attach-aware fd
loader:
`native_loader_load_from_fd_with_source_path_and_attach(...)`. The older weak
C wrappers that accepted only fd/object or fd/object/source-path were removed;
micro runner uses the C++ companion-object entry point directly.

A later cleanup removed the shim's hardcoded native JIT hex dump path. The
remaining post-load logging records BPF/JIT metadata for the original and
native fds, but no longer carries a fixed per-program dump list or exported
`BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT` environment knob.

Validation after this cleanup:

- `python3 -m py_compile` passed for the changed Python app-runner and manifest
  generator files.
- `make -C bpfopt/shim` passed; the remaining `shim_reload.h` `snprintf`
  warning is pre-existing and unrelated to native-object resolution.
- `make -C native-sim/libnativeloader` passed.
- `make host-runner-x86` passed.
- `make -C vendor/bpf native-bcc native-katran native-otel native-tracee native-cilium`
  passed and regenerated per-app staged manifests.
- `TEST_MODE=native-loader-smoke TIMEOUT=1200 make test` passed with run token
  `209e2c80`; the containerized shim loaded the manifest and replaced both
  programs from `multi_prog_tool`.
- After deleting the fixed native JIT dump path, `TEST_MODE=native-loader-smoke
  TIMEOUT=1200 make test` passed again with run token `95a792f5`.
- After removing the stale JIT dump env forwarding, `TEST_MODE=native-loader-smoke
  TIMEOUT=1200 make test` passed again with run token `4cac2d0a`.
- After the final removal of the shim JIT dump helper/call and suite env
  forwarding, `TEST_MODE=native-loader-smoke TIMEOUT=1200 make test` passed
  again with run token `65fd2068`.
