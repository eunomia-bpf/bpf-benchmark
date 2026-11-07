# AArch64 trusted extern contract

The ARM worker now validates the kernel-derived typed generation view, then emits bare extern references for the reachable native symbols. It creates no replacement maps and includes no producer C, proof, source-instruction metadata or compiler flags. The loader binds each extern to the exact native symbol address. A null value_offset means a map handle; numeric zero and nonzero offsets both mean a direct map-value pointer. The capsule base is added once by the loader, while native instruction/ELF addends remain relative.

The generator uses the common c_symbol_aliases helper for C spelling and __asm__(raw ELF name) to retain ELF identity. This handles actual static names such as sys_exit.zero and avoids collision with an existing legal C identifier. The old original_source/source_map_bindings APIs remain available for historical reproducers.

The compiler checks cover:

- Dotted symbol plus a colliding legal C name, with direct bases 0 and 8. Both produce identical generated C, BPF instruction bytes and relocations, proving that the capsule base is not added by the generator.
- Actual Katran native bytes and all 14 reachable map references: each ELF symbol is undefined for trusted binding; no .maps, .native_lab.source_maps or copied map rodata is emitted. This is compiler ABI preparation, not a kernel load or application acceptance claim. Its typed metadata comes from the stored host preparation, not current kernel facts.
- Boolean, negative and oversized direct bases rejected before output creation.
- The old declaration-based rendering of the actual Katran body compared byte-for-byte with the pinned prior generator blob. This checks compatibility without changing ISA handlers or dropping native instructions.

summary.json pins the inputs and records each relocation. compiler-inputs.tar.gz retains the exact C/native/proof/BPF inputs and compiler logs. Temporary raw files are removed automatically. The exact checked generator, worker, checker and shared helper are retained under producer-source/ in the archive. The ARM source integration now uses the byte-identical committed shared helper. Reproduce with make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-arm64-extern-check. Compiler acceptance here is not kernel or application acceptance.
