# Tracee current CORE input, November8 UTC

The complete original Tracee startup submits six native requests: all six generate and compile, and five install through the five-step path. `sys_exit_submit` reaches native chunk creation and returns `ENOENT` from the loader. Its stock-verifier outcome remains pending native relocation resolution. The corpus records startup error and retains its original application stderr and counters. Baseline resident census is151.

| Native entry | Generated | Compiled | Installed | Terminal result |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 1 | installed |
| sys_enter_init | 1 | 1 | 1 | installed |
| sys_enter_submit | 1 | 1 | 1 | installed |
| tracepoint__raw_syscalls__sys_exit | 1 | 1 | 1 | installed |
| sys_exit_init | 1 | 1 | 1 | installed |
| sys_exit_submit | 1 | 1 | 0 | native chunk creation ENOENT |

The runtime layer consumes the existing [CORE-preserving native build](../../kprog_app_coverage_20261107/native-core-helper/README.md), native object SHA256 `7479850e23454e957f4c5880a18d92a91c27dd282af52f768e4422fe9366a722`. The current `vendor/bpf/native_compat.h` and that build share SHA256 `d8f3497c11a5ceebb14ea389c9a4018caf22f065c53ba407e856a23cee717a3a`. The prior runtime carried object `025fe5e116ed994767c7142510c7b744883b0911eafe584cd06add56f16c7cd1`; its direct pt_regs read supplies the historical scalar-access frontier. Preserved CORE helper reads in the current object advance startup to five installed entries. R receives this native-input epoch for timing ownership. The published object keeps173functions and87maps; the standard writer emits114program rows from all three current objects with `--dedupe-program last`.

Commands, run in the Workspace through bws.sh:

```sh
Q=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-core-assets
python3 vendor/bpf/write_native_manifest.py --app tracee --llvm-nm llvm-nm-18 --dedupe-program last --output "$Q/manifest.json" --object "$Q/tracee.native.o" --object "$Q/kprobe_check.native.o" --object "$Q/lsm_check.native.o"
make -f "$Q/Makefile" image
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-current-core/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-current-core CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2
```

`runtime.tar.gz` carries the actual image build/manifest/source receipts and launch commands. `service.tar.gz` carries all six terminal native requests with generated C/BPF and loader logs. `result.tar.gz` preserves the entire corpus result. `coverage.json` joins all six request hashes to the native object. The image is `sha256:c10e55947ac3c724b3297b6ed238b0548be492f6d0676f3af87e57c8b22e3da5`. Worker exit0 and corpus startup error retain their separate meanings.
