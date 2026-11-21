# ARM verification configuration handoff, 2026-11-21

This record traces the committed source at 0df4fb8e7d8fda47d568fe951c72d6135269d861. It adds a static implementation-scope observation to the historical ARM coverage records. The coordinator owns the running six-application QEMU functional check (`/workspaces/kprog-raw/coordinator/restore-529/chain3.sh`) and the x86 timing rotation. Application runs started by this observation: 0; tests started: 0; source edits: 0.

| Configuration or interface | Current ARM implementation | Source evidence |
| --- | --- | --- |
| `submitted-native` verification | The ARM worker links P in proof mode with `--preserve-entry-abi`, emits sim C, compiles B, and returns the original P plus B to the shared loader. | `kprog/arm64/trusted_specializer.py`, `specialize`; `kprog/trusted_service.py`, `load_service_artifacts` |
| ARM proof entry ABI | The flag reaches `rewrite_arm64`; proof mode with entry preservation retains the entry save/restore instructions and RET. | `native_link/src/main.rs`, `rewrite_arm64`, `entry_abi_strip` and final RET selection |
| `checked-sim-c` execution | The shared CLI currently accepts this configuration for architecture 1 (x86). The ARM worker implements `specialize`; its checked-simulator native-compilation method remains an implementation item. | `kprog/trusted_service.py`, `main`; `kprog/arm64/trusted_specializer.py` |
| Current ARM six-app functional entry | The frozen ARM Makefile explicitly unsets `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF` and selects the ordinary post-load native loader. Its functional results belong to the direct native configuration. | `kprog/perf/one-image-arm64/Makefile`, guest environment |

The design describes both configurations in `kprog/docs/design.md`, compilation pipeline: the checked configuration compiles the same verified sim C through LTO; the direct configuration executes P with machine-code linking. The existing ARM submitted-native verifier route and the direct six-app functional route have distinct evidence. Current ARM direct functionality and historical ISA48 outcomes retain their own source epochs.

The ARM checked-sim-C execution port is the remaining configuration item for the coordinator and verification owner to assign. It includes the ARM checked native-compilation adapter and its integration with the shared service. This record preserves the current design and implementation boundary; the current x86 timing, ARM check, kernel, loader, benchmark settings and peer working files retain their existing owners and contents.

`configuration-source.json` records the exact revision and SHA256 of each inspected file. Every inspected file matches that committed revision. Historical requested rollback and comparison receipts remain in `kprog_arm64_app_coverage_20261109/entry-frame/` and `kprog_app_coverage_20261109/resident-census/aee6-comparison/`.
