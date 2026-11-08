AArch64 exact-width byte atomic simulation

The shared LDADD/LDSET/LDCLR simulator body lowers its byte access through bpf_arm64_native_lab_atomic8. The typed u8 pointer gives the stock verifier the one-byte read/write extent; the kernel primitive performs the matching native fetch-add/or/and with the encoded memory order. The 32/64-bit paths keep their existing operations. The ARM module Makefile selects inline atomics for this translation unit.

The single kfunc set carries the native emitter descriptor and the ordinary byte primitive. The BTF registration path allows an ordinary kfunc alongside the native descriptor. An aligned .BTF_ids section supplies the typed u32 access required by the ARM relocation; the archived earlier epoch records the emitter lookup diagnostic and the final paired Image/module control succeeds.

Actual full-system QEMU observations:

| Operation | Context index | Source | Old byte | New byte | Load / run exit |
| --- | ---: | ---: | ---: | ---: | --- |
| LDADD | 1 | 4 | 7 | 11 | 0 / 0 |
| LDSET | 1 | 4 | 7 | 7 | 0 / 0 |
| LDCLR | 1 | 4 | 7 | 3 | 0 / 0 |

The complete native service control generates and compiles B, obtains stock verifier acceptance, installs P and returns2. Guest, QEMU and compiler exit0. Existing29 microprograms plus the negative artifact compile; existing9 service tests and kernel-patch idempotence/conflict checks pass. The earlier11,520 host C-model scenes remain in ../bitwise-lse. These domains provide component evidence; V owns universal token/reference preservation. The complete Tetragon replay supplies subsequent application coverage.

summary.json records actual outcomes and source/runtime hashes. Each control directory retains its original summary and raw archive, including the earlier diagnostics. inputs.tar.gz contains exact source, build commands/logs and the built byte objects/module. The retained warm build command is make -f /workspaces/.agent-state/kprog-lanes/A/byte-atomic/Makefile existing-components; make targets control and observe run the matching2GiB QEMU controls. Source/build paths and Image/module hashes accompany the reproduction record. The halfword alignment predicate case remains with the operator. Runtime admission additions:0.
