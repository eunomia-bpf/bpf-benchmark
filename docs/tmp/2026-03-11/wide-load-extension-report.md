# Wide-Load Extension Report

## Summary

TASK #80 is implemented across the scanner, v5 pattern library, kernel rule validator, and x86 JIT wide-load emitter.

The main functional changes are:

- userspace wide-load recognition now handles byte-recompose ladders for widths `2..8`, including odd widths `3/5/6/7`
- the scanner now recognizes both little-endian low-first ladders and big-endian high-first ladders, which covers packet/ctx field extraction patterns assembled from consecutive byte loads plus shift/OR steps
- v5 pattern descriptors now exist for the wider low-first and high-first shapes, with an endian flag encoded in the width binding
- the x86 emitter now recovers odd-width wide loads by decomposing them into `4/2/1`-byte chunks, then shifting and ORing the partial loads back together

## Userspace Scanner Changes

Updated areas:

- `scanner/src/scanner.cpp`
- `scanner/src/pattern_v5.cpp`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
- `scanner/tests/test_scanner.cpp`

Scanner-side changes:

- replaced the old width-specific recognizer with a generic byte-recompose parser that accepts widths `2..8`
- added support for odd-width ladders, including width `3` for common 24-bit protocol fields
- added support for big-endian ascending byte ladders of the form `ldxb; shl; ldxb; shl; or; ...`, which is the packet/ctx extraction shape called out in the gap analysis
- kept compatibility with the old two-byte reverse-offset special case
- added v5 descriptors for both little-endian low-first and big-endian high-first wide-load shapes for widths `2..8`
- added `BPF_JIT_WMEM_F_BIG_ENDIAN` and a width mask so canonical width parameters can carry endian metadata without changing the rule layout

Added scanner tests:

- 3-byte little-endian ladder detection
- 4-byte big-endian byte-recompose detection
- matching v5 binding generation for both cases

## Kernel Changes

Updated areas:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Kernel-side changes:

- widened rule validation from only `2/4/8` to widths `2..8`
- widened accepted wide-load site lengths from `4/10/22` to `4/7/10/13/16/19/22`
- taught rule validation to parse the same little-endian and big-endian byte-recompose shapes the scanner now emits
- taught the canonical path to decode width plus endian flags from the `BPF_JIT_WMEM_PARAM_WIDTH` binding
- reworked the x86 wide-load emitter so both direct-site and canonical wide-load emission share the same chunked implementation
- for widths `3/5/6/7`, the emitter now rebuilds the value from `4/2/1` loads using shifts and ORs; big-endian chunk loads are byteswapped before recomposition

Build note:

- the kernel tree initially failed with `-Werror` because two staged `bitfield_extract` helpers in `arch/x86/net/bpf_jit_comp.c` were unused
- I marked those helpers `__maybe_unused` so `bzImage` can build cleanly; this does not change wide-load behavior

## Build And Test

Scanner:

```bash
cd scanner
cmake -S . -B build
cmake --build build -j"$(nproc)"
./build/test_scanner
```

Result:

- build succeeded
- unit tests succeeded: `59 passed, 0 failed`

Kernel:

```bash
cd vendor/linux-framework
make -j"$(nproc)" bzImage
```

Result:

- build succeeded
- output image: `vendor/linux-framework/arch/x86/boot/bzImage`

## Corpus Scan

Requested shorthand:

```bash
./build/bpf-jit-scanner scan corpus/build/**/*.bpf.o
```

Current scanner CLI does not accept a raw `.bpf.o` path in that form; it reports `unknown option: ...`.

Measured method:

- enumerate `corpus/build/**/*.bpf.o`
- extract executable `SHT_PROGBITS` sections from each ELF object
- scan each section with `scan --xlated <section.bin> --wide-mem`
- compare the baseline scanner in `.tmp-wide-head/scanner/build/bpf-jit-scanner` against the updated scanner in `scanner/build/bpf-jit-scanner`

Results:

- object files scanned: `560`
- executable sections scanned: `1657`
- before total wide sites: `2835`
- after total wide sites: `2835`
- delta: `0`
- before hit files: `33`
- after hit files: `33`
- files with changed counts: `0`
- scan errors: `0` before, `0` after

Interpretation:

- the new odd-width and big-endian byte-recompose support is covered by unit tests and builds cleanly
- the current `corpus/build` snapshot did not produce additional wide-load detections beyond the existing total
- this likely means the built corpus currently lacks extra odd-width or packet-style byte-recompose sites that were previously missed, or they are not present in executable sections that reach the scanner in this corpus build

## Caveats

- the wide-load extension targets byte-recompose recovery. Programs that already compile to direct `LDXH/LDXW/LDXDW` packet or ctx loads are not a wide-load optimization target.
- corpus counting was done by extracting executable ELF sections because the CLI does not currently accept `.bpf.o` inputs directly.
- the endian flag is encoded inside the canonical width binding, so userspace and kernel must stay aligned on `BPF_JIT_WMEM_WIDTH_MASK` and `BPF_JIT_WMEM_F_BIG_ENDIAN`.
