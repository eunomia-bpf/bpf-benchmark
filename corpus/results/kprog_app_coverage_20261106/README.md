# Lane C: application proof-artifact coverage, 2026-11-06

Generation checkpoint: **1,136/1,136 native proof objects generated C**:
1,054 staged objects from five applications plus 82 archived Cilium objects.
No encoding/specialization error was reported. Compilation and KVM load scans
are in progress; [tables.md](tables.md) and [coverage.csv](coverage.csv) record
the checkpoint, including pending cases. No timing claim is made.

These are **artifact counts, not counts of programs loaded by the six apps**.
The staged manifests contain BCC 29, Katran 3, OTel 26, Tetragon 235 and
Tracee 114 program-name entries; the archived Cilium manifest contains 89.
Objects additionally include helper functions and configuration variants;
some manifest entries have ambiguous truncated names. A current six-app
startup inventory and native-object pairing remain unfinished. No app,
program, failed artifact, or helper function was excluded from the scan.

The original app smoke generator assigns every artifact XDP entry ABI.
Consequently its stock-verifier acceptances are recorded as artifact
acceptances, not established coverage of tracing or other app program types.
The June Tracee records named by the lane prompt are workload-derived micro
kernels, not the complete Tracee program population.

Inputs: checkout `075c64b6ed5abb78ea33f10dbd8bae8e81963ec5`, with unrelated
formal/vendor work preserved; `vendor/build/native-bpf/x86/stage/` and
the `native-cilium/` member of
`corpus/results/cilium_native_lab_20261009/current-native-artifacts.tar.gz`.
The Cilium archive is historical evidence, not a current runtime-config pair.
Copied manifests are in [inventory/](inventory/). Generated sources and native
proof inputs are retained in each phase's `generated-sources.tar.gz`.

Commands, from the repository root:

```sh
taskset -c 8-15 make -C kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --report-dir /workspaces/repository/corpus/results/kprog_app_coverage_20261106/baseline --output-dir /workspaces/repository/kprog/x86/app-coverage-baseline'
# Extract archived native-cilium objects into a separate proof root, then:
taskset -c 8-15 make -C kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root /workspaces/repository/kprog/x86/app-coverage-cilium-input --report-dir /workspaces/repository/corpus/results/kprog_app_coverage_20261106/cilium-baseline --output-dir /workspaces/repository/kprog/x86/app-coverage-cilium-baseline'
make -f corpus/results/kprog_app_coverage_20261106/Makefile compile
make -f corpus/results/kprog_app_coverage_20261106/Makefile compile PHASE=cilium-baseline
make -f corpus/results/kprog_app_coverage_20261106/Makefile verify
make -f corpus/results/kprog_app_coverage_20261106/Makefile verify PHASE=cilium-baseline
make -f corpus/results/kprog_app_coverage_20261106/Makefile summarize
```

The compiler uses six workers per invocation and a 120-second per-object
timeout, retaining full stderr and stdout. Completion records allow rerunning
the compile/verify commands without repeating finished cases. The first
baseline compile invocation saw 779 generated files while generation was
running; rerun it to cover the remaining 275. The guest uses the framework
`vendor/build/x86/linux/arch/x86/boot/bzImage`, ordinary BPF verifier loads,
four vCPUs, 8 GiB memory, and host affinity 8-15. It does not load a native
execution module. These are diagnostic load checks, not benchmark timings.

Generation commands and full output are in each phase's `commands.jsonl`;
`programs.jsonl` maps each name to its input and generated source. Compiler
and loader invocations/output are under `compile/` and `verify/`; nonempty
`.verifier.log` files distinguish verifier rejection from libbpf object-open
or relocation errors. A missing extern BTF definition is a load preparation
failure, not a verifier rejection. Every completed failure remains recorded.

Changes at this checkpoint: the app smoke tool can retain raw commands and
per-program outcomes and generate without compiling. Its compiler can find
the simulator header when the output directory is outside `kprog/x86`.
The result-local Makefile and scripts compile and verify independently and
derive the coverage table from raw records. No workload or app runner changed.

Semantic findings that prevent interpreting baseline acceptance as a native
safety proof:

- Large programs (217 of the 1,054 staged artifacts) take the chunked path,
  which inserts a dispatch fuel limit, an unknown-PC exit, and zero-return
  fallback. These violate `kprog/x86/README.md` and need removal.
- The simulator inserts stack-window and pointer checks ending in
  `__builtin_trap`; BPF compilation reports an unsupported `abort` call.
- Helper PID/UID/CPU bodies return zero, unhandled helper IDs default to zero,
  and the simulator's custom helper numbers differ from Linux helper IDs
  used by register-indirect calls. OTel `custom__generic` becomes a trivial
  early exit after its PID call is modeled as zero. Accepted artifacts and
  raw logs are retained; none has been called generation-bound execution.

Before changing the simulator, its headers and generated contracts were
copied under `baseline/simulator/`. Generated working sources were pointed
at that snapshot so in-flight baseline compiles retain their original
semantics. The source archives preserve the original relative includes.

Next: finish compile/load enumeration, fix the frequent missing semantics,
rerun the table with correct program ABI/map relocations, inventory real app
startup, then execute passing native programs with generation-bound proofs
and add exact commands to the shared coordination file for lane R timing.
