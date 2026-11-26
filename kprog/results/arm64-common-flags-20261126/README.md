# ARM64 common compiler investigation

2026-11-26T20:46:23Z: todo0 coordinator18:09/18:28 asks for BCC/Katran/Cilium differences
after Tetragon generation. Run8 used Cortex-X925 timing CPUs15-19; the
common production flags select neoverse-n1. The installed Ubuntu Clang18.1.3
accepts the current tune but rejects cortex-x925. compiler-probe.json/log
retain exact stdin source, flags, return codes and diagnostic. This is
capability evidence only, not a performance cause or gain; no alternate
tune sweep, compiler upgrade, nativeP build, image or runtime setting change.
Full x86 timing stays frozen.

2026-11-26T21:16:35Z: source/binary follow-up retains the actual built key4C helper
(200bytes, hash-k4.bin/dis) and existing ARM lookup postprocess source in
hash-code-audit.json. Key hashing/comparison use ordinary wordLDRs, not
byte-by-byte assembly or acquire loads. PerCpuHash postprocess already
emits MRS TPIDR_EL1 +ADD directly; it does not call another CPU helper.
These observations do not support an alignment/order-strength or redundant
CPU-helper-call fix on these paths. This is source/code evidence, not a
live profile or performance result. No codegen flag, helper/module/linker,
image or workload changed. Remaining ARM diagnosis needs the actual costly
program path, with the common one-flag-set/all-LTO policy and frozen settings.
