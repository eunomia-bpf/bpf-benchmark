# Narrow memory loads preserve their actual zero extension

Socket LB's original native code loads a 16-bit divisor with MOVZX, tests that value for zero and divides only on the nonzero path. The old BPF C memory primitive emitted a single correct LDX8/16/32 instruction but exposed its inline-assembly output to Clang as an unconstrained u64. Clang therefore inserted redundant masks after the value was spilled, and the verifier lost the divisor's nonzero scalar identity. The modeled native division fault then remained reachable and rejected.

The sole memory-access C generator now returns `(__u8)value`, `(__u16)value` or `(__u32)value` for both address and fixed-displacement loads. These six casts express the same architectural zero extension already performed by the load instruction. 64-bit loads, all stores, load count/width, metadata/tags, native branches, flags and division fault behavior are unchanged. No new check, branch assertion, fuel, native input, compiler flag or verifier-limit change. The existing JSON and Lean byte-memory contract already specifies narrowing and is unchanged.

| Original program | Fresh generation | Compile | Verifier accepted/bound | Native result/action |
| --- | ---: | ---: | ---: | --- |
| cilium_socket_lb_service_select_xdp | 1 | 1 | 1 | 2868565165525030065 / 2 |

The private candidate loads at the canonical generated-header path in a mount namespace and uses the production native-only registered service. Exact original kernel-owned P SHA `b5d74a6bce6b658ae085b79e331eb3b94c72e1d4c5c234bb8a8e55b94f899d0f` matches the earlier rejected input. Request1/source6 binds native11 and executes correctly; the complete terminal archive is retained. Native TEST now dominates the spilled divisor, so Clang eliminates the unreachable division-fault branch without any removal of that branch in the simulator source. Only after the successful capture is the byte-exact candidate header promoted with its generator.

Existing independent byte-memory oracle passes 40,260 cases under UBSan. All eight existing x86 division-by-zero/quotient-overflow fixtures at 8/16/32/64 bits freshly generate and compile against the exact candidate include closure; the real verifier rejects all eight, zero accepted. These controls are **load only** through the ordinary proof loader, not native executions or a full generation-bound negative-suite claim. The positive original Socket case separately exercises native-only generation/binding/execution. Generator freshness passes and its Lean output is byte-identical. No full formal/ISA/whole-program proof claim.

## Commands and evidence

C CPUs20-23, private guest 4 GiB/two vCPUs, started only after the preceding 12 GiB OTel driver closed; cached kernel/module/image inputs are reused. `experiment/run.sh` and `guest.sh` inside `raw.tar.gz` give the exact private mount and registered-service commands. The service runs original `micro_exec run-native-kernel` on the cached original native/companion ELF and input, then the existing `make -C kprog/fidelity negative-guest` target in load-only mode. `build.sh` uses unchanged production Clang O3 flags; existing negative controls retain their O2 flags. No image/kernel/module rebuild and no image disk/export tar for this private component guest.

`raw.tar.gz` contains before/candidate headers and generator, actual original native/companion/input bytes, generated C/objects/disassembly, production service terminal archive, full kernel/meminfo, host oracle, all eight native negative fixtures plus their exact include snapshots/load logs, and initial harness keyword error before its correction. All launch pins stay unchanged through capture; the sole later physical change is this explicit promotion. `checks.json` pins source and result identities.

The complete 29-case standard Make suite is running separately in `../micro-load-width` with the promoted canonical source; no all-29 or six-application pass is claimed by this one-case result. Earlier rejected Socket evidence remains in `../micro-cmp-12g`.
