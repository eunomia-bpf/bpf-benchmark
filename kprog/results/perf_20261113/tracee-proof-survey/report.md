# Actual Tracee service-route proof inventory

2026-11-15. Native ELF SHA256
`b0aafb3f523ad649c630f96e5bc12a1e45342dfb8c4d7950e09f4a7519e724ef`
was unchanged before/after this offline measurement. The current canonical
linker45c33e7e processes every172 defined function with the service's
`--preserve-entry-abi` proof route:165 succeed, seven fail. All commands,
resources, exact errors and proof output hashes are retained; the overall
Make exits2 rather than reporting partial success. Total survey2.647s.
Only one canonical proof output is reused; no native source or compiled
artifact is copied here. No B, stock kernel or app acceptance is claimed;
the exact native bytes do not by themselves certify source/build fidelity.

Failures: `trace_ret_arch_prctl`, `trace_ret_dup`, `trace_ret_dup2`,
`trace_ret_dup3`, `trace_ret_process_vm_writev`, `trace_ret_ptrace`,
`sys_exit_submit`. All report a nested PC32 code relocation in shared
`.rodata` without a relative jump-table base.

Actual disassembly establishes that the referenced object is **scalar data**:
`trace_ret_dup` has six LEAs to `.rodata+0x750`, followed later by indexed
32-bit loads for argument type sizes. ELF `type_size_table` occupies exactly
64bytes at0x750. The same1,936-byte section also holds463 unrelated relative
code entries before that data. The linker recognizes spans for anonymous
code-table references, but this section-symbol reference to an ordinary
defined data object copies the entire section and then attempts to resolve
other roots' code entries. This is the same shared-container class as the
earlier code-table-only fix, now exposed by a scalar object.

`rodata-layout.json` and `trace_ret_dup.disassembly.log` hold the direct ELF/
instruction evidence. A source-level regression for section-symbol references
to the start/interior of a typed scalar object beside unrelated code tables
is added in the next step. Existing failure evidence remains unchanged.

Raw `/workspaces/kprog-raw/perf/20261115-tracee-proof-survey`; launcher930096.
Reproduction: `make -r -f kprog/test/native-relocations.mk tracee-proof-survey`
with `OUTPUT` for logs; host16–19/4GiBAS/imageSH, no guest/timing lock or
kernel/base/image changes. The survey script is2a397b4f4.
