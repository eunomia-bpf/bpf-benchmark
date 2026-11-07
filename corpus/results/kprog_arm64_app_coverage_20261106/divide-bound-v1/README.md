# Priority2 ARM division and entry-state audit

All16 boundary controls pass source/simulator/generation-bound native execution
in full-system QEMU: eight cases in both stripped and preserved entry modes.
Every native object contains an actual UDIV word (native-udiv.asm), and every
bound load has one nonzero generation. The post-division equality branch also
checks preservation of the Z flag. Exact results are in cases.json/verify.

| Case | Width | Numerator | Divisor | Result |
| --- | ---: | --- | --- | --- |
| xz |64|37|0|0|
| wz |32|37|0|0|
| wtrunc |32|2^32+37|2^32|0|
| wupper |32|2^32+37|2^32+3|12|
| xfull |64|2^64-1|3|6148914691236517205|
| xalias |64|2^64-1|3|6148914691236517205|
| walias |32|2^32-1|3|1431655765|
| same |64|2^64-1|2^64-1|1|

The alias cases overwrite the divisor register. The32-bit cases require
operand truncation before division and zero extension on destination write.
Unlike x86 DIV, the exercised ARM UDIV zero divisor returns zero without a
native divide fault. No simulator semantic change or synthetic safety guard
was needed: the existing generated arm64_mul contract already has this rule.
The original unsafe x86 cases remain C/V/F work, not ARM rejection cases.

Priority2 entry flags are separately wired in F1998ee4fc: scalar SP and outer
LR observations read NATIVE_LAB_ENTRY_INPUT(SP/RETURN); address/control payloads
stay relative. The ARM JIT handles those private input instructions in
vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c. Published supporting
records are differential/arm64-numeric and negative/arm64-numeric under
kprog/results/kprog_fidelity_20261106:567forms/580608CPU cases,97control
sequences,30/30 unsafe load-only rejections and five valid bound admissions.
This audit reads those records and production hooks; it does not count them
as newly executed tests or a complete whole-program certificate.

Rebuild from root with the dated Makefile's entry-abi-build and
fmov-bank-check PHASE=NEW_NAME ENTRY_ABI_ARGS=divide. The replay archive holds
exact native/source/simulator inputs, compiled artifacts, frozen dependencies
and matched built kernel/initrd. Extract then make -C runtime run; on Spark,
make -C runtime run ACCEL=kvm CPU=host. QEMU timings are functional only.
