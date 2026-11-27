# Link-time frozen scalar optimization

The x86 linker preserves embedded frontend IR as non-allocated proof metadata. At kernel linking, the existing bound frozen scalar values reach the existing common LLVM optimizer before machine-code generation. The linker extracts a fresh proof from that output and uses its saved-register ABI. The exact optimized proof remains beside the original input for attribution. No application or program name selects this policy; machine-only inputs retain the existing instruction-level folding. ARM proof output is unchanged.

The compiler uses the existing common x86 O3/backend policy, a shared single compiler slot and a 48 GiB address-space limit. Compilation errors propagate with retained inputs and stderr. Mutable globals do not become constants. No new runtime option, producer, loader-core, kernel, benchmark or timing-setting change.

Release build and all 12 linker tests passed. The regression test follows actual clang → proof → LLVM → proof execution, checks both frozen flag values against a conditional external call, verifies that mutable data remains live, checks bit-for-bit preservation of embedded IR, and requires ABI metadata on the fresh proof.

The actual native-link CLI also passed on the exact staged OTel P and captured boot plan using the current runtime container's compiler. The resulting blob is 14,327 bytes with zero relocations to bpf_trace_printk, versus the previously observed installed 29,964 bytes and 106 static calls. This is an offline linked result; installed native code, functional behavior and the diagnostic per-call ratio await the sole-image refresh and frozen 10-second check. Original and failed-launch evidence is retained.

Self-review: production growth implements IR transport, the existing compiler invocation and fresh ABI extraction; the regression covers the actual lost-IR/late-fact defect and mutable-data boundary. No public option or app selection was added. The pending refresh reuses every existing P and kernel byte and the frozen image recipe. Full x86 timing stays frozen.
