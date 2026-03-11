# CMOV Broadening Report

## Summary

Task #78 broadened userspace-only `cmov_select` recognition in both the classic scanner path and the v5 declarative pattern library.

The scanner now recognizes:

- `JSET` / `JSET32` conditional jumps by accepting the full `0x40` jump-op family (`0x45`, `0x4d`, `0x46`, `0x4e`).
- Wider diamonds where the false arm contains a short pure value-prep sequence before the final `mov`, including `jcc +3` and `jcc +4`.
- Guarded-update shapes where a conditional branch skips or joins around a short value-prep sequence ending in `mov dst, value`.
- Switch-style local select chains of the form `mov false; guard-jcc; select-jcc; ja else; mov true; ja join`.

On the three previously-missed benchmarks, the scanner now finds nonzero cmov sites.

## Code Changes

- `[scanner.cpp](/home/yunwei37/workspace/bpf-benchmark/scanner/src/scanner.cpp)`:
  - added `JSET` acceptance to `is_cond_jump_raw()`;
  - added helpers for pure ALU value-prep recognition and shared-join checks;
  - generalized CMOV detection beyond the old 4-insn diamond and 3-insn compact forms.
- `[pattern_v5.cpp](/home/yunwei37/workspace/bpf-benchmark/scanner/src/pattern_v5.cpp)`:
  - added `JSET`/`JSET32` opcodes to the cmov descriptor opcode set;
  - added new descriptor families for switch-chain, guarded-update, and wider-diamond cmov-like regions.
- `[engine.cpp](/home/yunwei37/workspace/bpf-benchmark/scanner/src/engine.cpp)`:
  - updated branch-density classification to count `JSET` as a conditional jump.
- `[test_scanner.cpp](/home/yunwei37/workspace/bpf-benchmark/scanner/tests/test_scanner.cpp)`:
  - added coverage for widened diamonds, guarded-update patterns, switch-chain recognition, and `JSET`.

## Build Status

Build commands:

```bash
cmake -S scanner -B scanner/build
cmake --build scanner/build -j$(nproc)
./scanner/build/test_scanner
```

Result:

- scanner build: success
- unit tests: `OK: 69 passed, 0 failed`

## Scan Method

The task text says to run `bpf-jit-scanner scan <object>`, but the current CLI in this repo still accepts only `--prog-fd` or `--xlated`.

For offline scanning, I extracted the raw `xdp` section bytes from each BPF object:

```bash
llvm-objcopy --dump-section xdp=/tmp/cmov-broadening/<name>.xlated micro/programs/<name>.bpf.o
```

Then scanned those raw bytes with:

```bash
./scanner/build/bpf-jit-scanner scan --xlated /tmp/cmov-broadening/<name>.xlated --cmov
./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/cmov-broadening/<name>.xlated --cmov
```

## Scan Results

Previous baseline from the gap analysis / CMOV experiment docs: all three were `cmov_sites = 0`.

Current results:

| Program | Classic scanner (`scanner.cpp`) | v5 scanner (`pattern_v5.cpp`) |
| --- | ---: | ---: |
| `switch_dispatch` | 1 | 1 |
| `binary_search` | 2 | 1 |
| `bounds_ladder` | 2 | 2 |

Notes:

- `switch_dispatch` now gets a switch-style local-select hit instead of `0`.
- `binary_search` now gets guarded-update/select hits instead of `0`.
- `bounds_ladder` now gets both ladder-style guarded updates instead of `0`.

Net new recognized sites versus the documented old baseline:

- classic scanner: `+5` across the three targets
- v5 scanner: `+4` across the three targets

## Commands Run

```bash
./scanner/build/bpf-jit-scanner scan --xlated /tmp/cmov-broadening/switch_dispatch.xlated --cmov
./scanner/build/bpf-jit-scanner scan --xlated /tmp/cmov-broadening/binary_search.xlated --cmov
./scanner/build/bpf-jit-scanner scan --xlated /tmp/cmov-broadening/bounds_ladder.xlated --cmov

./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/cmov-broadening/switch_dispatch.xlated --cmov
./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/cmov-broadening/binary_search.xlated --cmov
./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/cmov-broadening/bounds_ladder.xlated --cmov
```
