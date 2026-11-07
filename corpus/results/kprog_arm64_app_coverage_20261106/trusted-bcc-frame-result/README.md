# tcplife trusted-extern compiler frame

The current trusted ARM worker compiles the real tcplife native entry, but the generated BPF still accesses `r10 - 584`. This confirms that changing to the trusted extern interface does not remove the prior frame-size blocker. This check does not submit a program to the kernel or establish verifier acceptance.

Reproduce through the repository result Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-bcc-frame-check
```

The checker opens the original arm64 tcplife BPF ELF with libbpf and uses its actual pre-load map shapes. All nine map/readonly symbols have matching names, section, offset, size and bytes in the native ELF. Readonly variables retain their exact direct-value offsets, including zero. These are preparation facts, not kernel-pinned runtime facts; the perf-event map's pre-load max_entries remains zero as reported by libbpf. Real admission must obtain the live facts from the common service.

`summary.json` records the inputs, symbol checks and largest disassembled frame offset. `compiler-inputs.tar.gz` contains both original ELF inputs, fresh native-link output, generated C/BPF, disassembly and compiler command logs. `compiler-check.log.gz` retains the complete successful check. `setup-failure.log` retains an initial harness output-directory collision, fixed before the successful run. The temporary build directory was removed after archival. No simulator/header, native input, kernel or active QEMU input was modified.

An isolated candidate limited ghost-payload writes to STACK/RETURN tags, the only tags read by `MEM_PAYLOAD` and the stack-transfer path. It left tcplife at `fp-584` and the existing actual Katran source at `fp-672`, so it was **not promoted**. Five existing stack route hosts passed against the copied candidate header; these are focused host checks, not verifier or whole-formal acceptance. `ghost-candidate.json` records each result, and `ghost-candidate-inputs.tar.gz` retains the exact copied header, generated compiler inputs/objects/disassemblies, existing host sources/logs and experiment scripts. The production header stayed byte-identical throughout.

A later isolated sparse-payload candidate compiles the same archived Katran proof with a 440-byte maximum frame offset; tcplife stays at 584 bytes. Raw stack bytes and tags retain their complete extent. Only STACK/RETURN ghost payload words are compressed, with total rank indexing rather than an unknown-slot default return. Unresolved aliases/copy lengths retain the dense layout. In tcplife, the helper call at native PC `0x3d4` joins actual lengths 4 and 16, which this single-constant analysis cannot retain.

A new post-indexed pointer-spill fixture first exposed an undercount in the draft analysis (only `-24` instead of both `-24` and `-16`). Preserving base-register provenance across memory writeback fixes it. All 12 targeted fixtures now pass, including joined pointers, partial stores, helper copies, external probe sources and unresolved stack-derived probe sources. `sparse-ghost-candidate.json` and `sparse-ghost-candidate-inputs.tar.gz` retain the exact prototype, failing and passing logs, native fixtures, generated C/BPF/disassembly, commands and baseline source. This candidate is **not promoted**: there is no kernel verifier, bound execution or whole-refinement result for it. The production header remains byte-identical while the separate 8 GiB actual Katran replay runs.
