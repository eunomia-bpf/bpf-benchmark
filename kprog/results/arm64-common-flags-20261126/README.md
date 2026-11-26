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

2026-11-26T22:29:53Z: phase1 ARM compiler-policy audit found the checked-native helper/
final flags omit -ffixed-x26 and -mno-outline-atomics already used by P.
abi-probe.json compares actual flags on one pressure/atomic fixture.
Without them, x26 is loaded from input before bpf_tail_call and restored
only on return. The existing linker tail-call template reads [x26] as the
native frame counter (main.rs1432), so ordinary C callee-save preservation
is insufficient at that call site. The same object has an undefined
__aarch64_ldadd8_acq_rel compiler-runtime call. Producer-policy flags avoid
both. Proof emission succeeds for both, retaining the former relocation;
this is not kernel-link acceptance. Actual checked-worker/compiler and
kernel-link reproduction follows before a production repair. No app P,
image or performance setting changed; this concerns the main checked path,
not the existing direct ARM run8 timing. OMP simulation/micro WIP untouched.

2026-11-26T22:40:41Z: ARM checked-native phase1 ABI repair propagates P's existing -mtune=neoverse-n1/-mno-outline-atomics/-ffixed-x26 through AARCH64_HELPER_FLAGS, used by helper and final native emission. Actual compile_checked_simulator before/after controls preserve identical frontend IR. Before: kernel-link1 on undefined __aarch64_ldadd8_acq_rel; Cortex-A57 userspace observer atomic64/values pass but physical x26 frame pointer fails. After: kernel-link0 (28bytes,0relocs), atomic64/values/frame pointer all pass. This is common architecture policy, not app selection, B flag change, direct ARM run8 timing attribution or real kernel tail-call/stock/app acceptance. Initial installed x86 compile-sim-ir rejected ARM arguments; setup failure is retained separately; successful controls use the existing ARM coverage /tmp/cc_compile-sim-ir tool. Before/after complete native artifacts, commands and failures retained in arm64-common-flags-20261126. All LTO together; no image/kernel/framework/workload/settings change, full timing frozen.

2026-11-26T22:44:18Z: ARM3b select audit completed on all112current staged modules. LLVM18.1.3 N1 tune already enables both select optimization and predictable-select-expensive (AArch64.td1237-1245); O3 schedules SelectOptimize before machine early-if-conversion. Existing binary-search fixture emits12conditional selects with either default or disabled early-if-conversion, so that switch alone is not an x86 force-all counterpart. Static native conditional-select family counts BCC12/Cilium502/Katran19/OTel546/Tetra13847/Tracee293; these include cset aliases, all code/functions and cold sites, not hot-path weights or numbers executed. IR selects BCC0/Cilium39/Katran0/OTel14/Tetra344/Tracee3. No production flag or performance gain inferred; actual BCC/Katran/Cilium machine-lowering control follows. select-audit.json retains commands, attributes, selected IR and disassembly sites. AllLTO together/fulltimingfrozen.

2026-11-26T22:46:04Z: ARM3b fixed machine-only early-if-conversion control finishes0. Existing embedded IR from BCC vfsstat, Katran balancer and Cilium bpf_lxc regenerated with llc18 O3/PIC default versus -aarch64-enable-early-ifcvt=false, retaining original IR target attributes. Entire executable code sections are byte-identical in all3pairs:544/9732/73076bytes; conditional-select counts0/6/54 unchanged. No claim regenerated defaults equal original P objects. Together with fixture12/12 and existing N1 select features, this switch is not an evidenced candidate; no production adoption or Spark run. Complete6objects/disassemblies compressed before canonical output replacement, commands/status/result retained under arm64-common-flags-20261126/select-backend-*. Phase1 ABI repair31c044ac5 is pushed, B-frame coverage and ARM performance attribution remain open; allLTO together/fulltimingfrozen.

2026-11-26T22:52:37Z: reproduced ARM phase1 missing common C helper linkage on actual compile_checked_simulator/sole ARM BTF. ARRAY and user/kernel probe-read native entries fail kernel linking on unresolved __kprog_array_lookup/__kprog_probe_read_user/__kprog_probe_read_kernel. Hash/LPM/percpu/dynamic four entries link only through generic helper; ARM worker never links the shared lookup/probe bodies already used by x86. helpers-before-result.json/commands/archive preserve actual outcome (3fail/4link); this is synthetic native compilation/linkage, not stock/app/kernel execution. Scoped next repair reuses inline_array.py/inline_probe.c for all apps together in ARM checked native emission, leaving B flags/shared simulator/P/image unchanged. AllLTO together/fulltimingfrozen.

2026-11-26T22:56:58Z: phase1 ARM common C helper linkage repaired: worker now links the SAME lookup_source/dynamic_lookup_source/inline_probe.c bodies as x86, including typed ARRAY/PERCPU_ARRAY/LPM/plain HASH, unknown-map kernel method and nofault probes, plus existing PID. No app selector/new policy/flags or shared-I change. ARM nativeLink now retains ordinary BLR kernel-method calls and clears caller-saved x0-x18 map facts; named helper handling unchanged. Before3of7kernel links failed on missing internal C symbols; shared-C first6/7exposed BLR refusal (4149eb8f4), complete repair7/7link0 with sole ARM BTF and identical B frontend IR. Actual emitted code passes23Cortex-A57 userspace model cases (ARRAY/PERCPU/dynamic and nofault success/error/zeroing; HASH/LPM empty only), Rust release9tests pass. One runtime-harness import setup failure retained/fixed; final execution0. No actual stock/kernel/app/timing acceptance claimed. Existing ARM coverage products predate this native emission repair; regenerate through worker for future checked runs, not relabel old280counts. NativeLink sole release build updated in place; base/image/P unchanged, allLTO together/fulltimingfrozen. All raw commands/products/failures retained in arm64-common-flags-20261126/helpers-*; source checks and cleanup recorded.
