# Kernel-Side BPF JIT Directive POC Summary

This POC adds a minimal kernel-side directive path in `vendor/linux/` for a first `wide_load` directive.

Implemented:

- `BPF_PROG_LOAD` UAPI extension in `include/uapi/linux/bpf.h`
  - new `BPF_F_JIT_DIRECTIVES_FD` prog flag
  - new `jit_directives_fd` / `jit_directives_flags` fields
  - minimal blob format:
    - `struct bpf_jit_directive_hdr`
    - `struct bpf_jit_directive_rec`
    - `struct bpf_jit_directive_wide_load`
- kernel-owned directive state in `struct bpf_prog_aux`
- load-time parsing in `kernel/bpf/jit_directives.c`
  - consumes a sealed memfd blob
  - validates blob magic/version/record size/instruction count
  - keeps only supported records
  - fail-closed behavior is best-effort: malformed or unsupported blobs are ignored and the program loads normally
- verifier-side rewrite in `kernel/bpf/verifier.c`
  - runs in the post-proof rewrite block, before `convert_ctx_accesses()`
  - matches an exact 4-byte little-endian byte-recompose ladder:
    - 4 adjacent `LDX B`
    - `LSH` by `8/16/24`
    - `OR` into one destination register
  - only accepts stack/map-value loads
  - requires 4-byte alignment
  - rejects interior jump targets and temp-liveout cases
  - rewrites the ladder to one `BPF_LDX_MEM(BPF_W, ...)`
  - removes the remaining 9 instructions with existing verifier remove/adjust helpers
- x86 hook in `arch/x86/net/bpf_jit_comp.c`
  - verifier-rewritten `wide_load` sites intentionally reuse the normal `LDX W` emitter path
  - no separate x86-native directive encoding was added in this POC

Not implemented in this POC:

- digest binding
- strict CPU contracts
- logging/telemetry
- multi-width support beyond the 4-byte case
- broader verifier legality reconstruction beyond the conservative checks above

Build checks performed:

- `make -C vendor/linux headers_install`
- targeted object builds under `vendor/linux/`:
  - `make kernel/bpf/jit_directives.o kernel/bpf/core.o`
  - `make kernel/bpf/verifier.o kernel/bpf/syscall.o arch/x86/net/bpf_jit_comp.o`

Notes:

- `make -C vendor/linux M=kernel/bpf -j4` completes, but it only builds the module content under `kernel/bpf/preload/`, so targeted object builds were used to check the modified built-in objects.
