# x86 PLT32 tail-jump linkage

The generic linker follows both E8 CALL and E9 tail-JMP relocations, retains each four-byte displacement through block encoding, and resolves it in the final native layout. ELF targets determine reachability and target identity. This changes25 production lines and64 regression-test lines, with10 replaced lines; runtime admission additions0. The simulator and native input bytes retain their existing semantics.

The regression fails on the entry/middle/leaf closure before the repair and passes all8 symbol/section, forward/backward and CALL/JMP variants afterwards. Complete existing Rust suite:90/90. The documented micro-proofs-build target compiles29positive and1negative native artifacts, Makeexit0. The existing incremental release cache supplies the updated shared linker.

The current x86 kernel C catalog has239 compiled entries. The complete before/after ELF-link scan records161generated and78generation failures in each version, preserving every original command and error. Six previously truncated outputs gain their actual reachable functions:

| Entry | Prior proof text bytes | Current proof text bytes | Current functions |
| --- | ---: | ---: | ---: |
| global_func11 | 2 | 35 | 2 |
| global_func13 | 7 | 40 | 2 |
| global_func14 | 4 | 37 | 2 |
| global_func17 | 9 | 32 | 2 |
| global_func3 | 2 | 75 | 9 |
| global_func4 | 2 | 70 | 8 |

These are linker/component observations. Fresh full-application startup and annotation outcomes retain their separate evidence domains. Original global_func4 now compiles45 BPF instructions and roundtrips its complete70-byte/eight-function chain through serialized proof ELF to the kernel native image. Original global_func16 retains44 BPF instructions and a42-byte kernel image. The original global_func2 component compiles1174instructions and reaches its existing memset helper-address input requirement during the standalone kernel-link control. The initial direct-native kernel CLI attempts retain their explicit proof-input diagnostic, followed by the serialized-proof controls.

The actual registered-service replay submits original global_func4 and global_func8 through source0 native context, preserving both native object hashes. global_func8 installs program5, service status0. global_func4 reaches stock verification and its next __sk_buff/kernel-skb layout frontier: its original native u32 read at offset0 addresses kernel member next. Its full verifier log is retained. Both producers request load-only; annotation interpretation and generic native-context ABI work remain with R/C.

Commands, all run in the owning Workspace:

```sh
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps focused
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps test build
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps component
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps micro
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps catalog
make -C /workspaces/.agent-state/kprog-lanes/C/design-only/plt32-tail-jumps probe replay
```

[summary.json](summary.json) holds actual hashes/counts/stages. [raw.tar.gz](raw.tar.gz) holds original239 native inputs, before/after linked outputs, exact source snapshots, regression/full/micro compiler logs and objects, original kernel controls, service/native/BPF/verifier archives, and the Make/Python/C++ reproduction sources. Repeated controls use fresh output directories, retaining their initial setup diagnostics. Universal O4 link-preservation laws apply to this generic relocation operation.
