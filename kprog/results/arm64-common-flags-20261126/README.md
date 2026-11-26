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

2026-11-26T21:24:25Z: the current ARM flags select baseline Armv8 and inline LL/SC
atomics. atomic-probe.json captures one fixed +lse comparison: add/or/and
lower to LSE instructions accepted by the existing decoder; XOR, exchange
and CAS have no existing model. The complete 112-object embedded-IR census
(atomic-ir-audit.json) contains only add/or/and: BCC6 adds, Cilium13 adds,
Tetragon667 adds/13 ORs/1 AND; the other three apps have none. These are
static IR sites, distinct from emitted instruction counts. For example,
runqlat handle_switch and Cilium __ct_lookup/__policy_account use seq_cst
adds. The kernel JIT selects LSE on capable hardware. This is a concrete
codegen asymmetry, not measured hot-path weight or a slowdown attribution.

The common +lse flag is NOT adopted: the frozen ARM functional entry runs
QEMU cortex-a57, which does not support LSE. Changing that CPU would change
the frozen framework. No helper dispatch, weakened atomic memory ordering,
per-app flag selection or CPU override was added. Unsupported hypothetical
XOR/exchange/CAS is a capability observation, not an actual current-catalog
regression. atomic-conclusion.json records the exact frozen CPU/JIT source
references. The initial mnemonic parser also included ordinary loads;
its complete output is retained compressed as atomic-probe-initial.json.gz,
and the corrected atomic-only output is atomic-probe.json. No production
P/I/flags, module, linker, image or timing changed; full timing stays frozen.
