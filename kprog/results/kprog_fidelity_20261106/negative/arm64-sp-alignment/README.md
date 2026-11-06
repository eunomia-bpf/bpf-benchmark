# Arm SP alignment safety repair

The unchanged native fixture below was accepted by the generation-bound
full-system QEMU path before the repair: program ID8, one chunk, generation1.
It is load-only evidence; the unsafe native program was never executed.

```asm
sub sp, sp, #16
mov w1, #0x2222
str x1, [sp]
add sp, sp, #1
ldrb w0, [sp]
sub sp, sp, #1
add sp, sp, #16
ret
```

The kernel enables SCTLR_EL1.SA in
`vendor/linux-framework/arch/arm64/include/asm/sysreg.h`,
`INIT_SCTLR_EL1_MMU_ON`. Its native entry stack is16-byte aligned. An SP-based
memory instruction checks the **old SP**, before effective-address calculation
or writeback. Ordinary unaligned byte addresses through a general register
do not invoke this check.

The production ABI analysis now checks that property before handling each
SP-based memory instruction. The fixture rejects during specialization with
the exact message:

```text
native SP alignment fault at 0x10: ldrb w0, [sp]
```

No runtime simulator guard, guessed absolute address, or alternate instruction
semantics was introduced. The five alignment regressions include both the
misaligned-SP/aligned-effective-address case and legitimate pre/postindex
writeback. All40 real-encoding ABI regressions pass. The broader cases also
exercise the concurrent Arm owner's definedness/vector changes; this increment
publishes only the SP-alignment hunk of the shared ABI file.

Three positive controls still load with one bound chunk and generation1:

| Control | Bound program ID | Result |
| --- | ---: | --- |
| Aligned SP, unaligned effective address through X2 | 8 | accepted |
| `str x1,[sp,#-8]!`, testing aligned old SP | 16 | accepted |
| `ldrb w0,[sp],#1`, testing aligned old SP | 24 | accepted |

These are load-only positive controls, not native return-value or timing tests.
The full18-case Arm suite reports9 verifier rejections,6 specialization
rejections,1 loader rejection and2 accepted findings. All11 original negatives
reject. The two remaining accepts are the earlier numeric stack-base and
outer-return-address flag observations; this repair does not close them.
Every exact diagnostic remains in `full-after/outcomes.json` and individual
logs. The suite exits1 for those findings, with zero infrastructure errors.
The negative proof artifact and all29 workload-derived positive proofs compile
with the repaired checker (`micro-build.log`).

Commands, all on host CPUs16–23:

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment check full-build full-package full-run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment positive-build positive-run
taskset -c 16-23 make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build/fidelity-sp-alignment/micro-proofs NEGATIVE_NATIVE_BUILD_DIR=build/fidelity-sp-alignment/negative-native MICRO_SIM_PROOF_ARGS='--jobs 1'
```

The first command is the preserved before-repair run and intentionally exits1.
The full suite likewise exits1 for the two separate accepted findings. The
QEMU guests use cortex-a57,2vCPUs and2GiB with the matched kernel/module and
loader copied into the owning build directory; no shared image is replaced.
`artifacts.tar.gz` restores `sp-alignment-bound/` under
`kprog/fidelity/build-arm64/`: native sources/objects, generated proofs, frozen
production import/include closure, regression outcomes, exact kernel/module,
static probe, loader library, linker and initramfs specifications. Initramfs
archives are rebuildable with the included `package.py` target. The before
snapshot's fixtures remain distinct from the repaired full-suite snapshot.
