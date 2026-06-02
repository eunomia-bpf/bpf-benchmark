# kinsn all-force TODO, 2026-06-02

Goal: make both LLVM backend and `bpfopt` default to force/apply-all kinsn
selection, then validate the full x86 kinsn corpus path app by app. YAML is only
for explicit per-app/per-prog/per-hash override after the root cause is
understood; verifier/load failures must first be treated as implementation bugs.

Methodology constraints:

- Use only `make <target>` for benchmark runs.
- Do not change corpus workloads after the 2026-05-25 methodology freeze.
- Use the full kinsn pass set for x86 smoke:
  `rotate,cond_select,ccmp,extract,endian_fusion,bulk_memory,prefetch,lea`.
- Use `SAMPLES=1 WORKLOAD_DURATION=30` for smoke/app-search runs.
- Do not add code-level profitability gates.
- Do not add YAML disable just because verifier/load fails.

Current implementation state:

- [x] LLVM backend default policy changed from `Cost` to `Force`.
- [x] `bpfopt --pass <kinsn>` injects `-bpf-kinsn-mode=all=force` unless an
  explicit `--kinsn-mode`/`-bpf-kinsn-mode=` override is present.
- [x] LEA app-level disable YAML files removed so verifier/load failures are not
  hidden by policy.
- [x] x86 `bpf_x86_lea` verifier-side instantiate changed to avoid `MUL` and
  reordered pointer arithmetic when `dst == index`.
- [x] `make host-kinsn-x86` passed after the LEA module change.
- [x] `cmake --build bpfopt/llvm/build-kinsn -j2` passed.
- [x] `make -C bpfopt/shim` passed.
- [ ] Finish LLVM backend `llc` rebuild when needed for micro/backend-only
  verification. The previous rebuild was stopped after user interruption.

Validation plan:

- [ ] Run x86 KVM `tracee/monitor` with the full kinsn pass set.
- [ ] Run x86 KVM `tetragon/observer` with the full kinsn pass set.
- [ ] Run x86 KVM `otelcol-ebpf-profiler/profiling` with the full kinsn pass set.
- [ ] Run x86 KVM `bcc/set` with the full kinsn pass set.
- [ ] Run x86 KVM `katran` with the full kinsn pass set.
- [ ] Run x86 KVM `cilium/agent` with the full kinsn pass set.
- [ ] Run combined x86 KVM corpus with the full kinsn pass set after all apps
  pass individually.
- [ ] Record per-app policy table from raw loadtime reports.
- [ ] Generate `docs/eval_kinsn.md` and figures from raw results.

Obsolete artifacts:

- Earlier `lea`-only smoke/eval artifacts from 2026-06-02 are no longer
  authoritative because they used disable-based workarounds while investigating
  verifier failures. Keep them only as debug history.
