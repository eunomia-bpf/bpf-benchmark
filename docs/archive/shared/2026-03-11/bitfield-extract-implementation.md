# Bitfield Extract Implementation

Date: 2026-03-11

## Summary

TASK #79 is implemented across the scanner, kernel directive framework, x86 JIT, and micro-benchmark stack.

- Added a new directive family: `BITFIELD_EXTRACT`
- Added legacy scanner recognition and v5 declarative descriptors
- Added kernel-side canonical validation for bitfield extract rules
- Added x86 emission for canonical and legacy sites
- Added a new `bitfield_extract` micro benchmark, input generator, config entry, and runner plumbing

The new family targets BPF idioms of the form:

- `(src >> shift) & mask`
- `(src & mask) >> shift`

## Scanner Changes

Userspace scanner support was added in both paths:

- Legacy scanner (`scanner/src/scanner.cpp`)
  - matches `RSH64_IMM + AND64_IMM`
  - matches `RSH32_IMM + AND32_IMM`
  - matches `AND + RSH`
  - matches 2-insn and 3-insn forms (with an initial copy)
- v5 scanner (`scanner/src/pattern_v5.cpp`)
  - added `V5Family::BitfieldExtract`
  - added canonical form `BPF_JIT_CF_BITFIELD_EXTRACT`
  - added 8 descriptors covering:
    - 32-bit and 64-bit
    - with-copy and in-place forms
    - `shift->mask` and `mask->shift` orderings

Canonical parameters captured:

- destination register
- source register
- shift amount
- mask immediate
- bit width (`32` or `64`)
- operation order (`SHIFT_MASK` or `MASK_SHIFT`)

## Kernel Changes

Shared validation and x86 lowering were added for the new canonical form.

- UAPI additions in `vendor/linux-framework/include/uapi/linux/bpf.h`
  - new rule kind: `BPF_JIT_RK_BITFIELD_EXTRACT`
  - new canonical form: `BPF_JIT_CF_BITFIELD_EXTRACT`
  - new native choice: `BPF_JIT_BFX_EXTRACT`
- Generic validator updates in `vendor/linux-framework/kernel/bpf/jit_directives.c`
  - rule kind to canonical form mapping
  - canonical parameter validation
  - site parsing for legacy 2-insn and 3-insn forms
  - rule validation dispatch for the new family
- x86 JIT updates in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
  - legacy site parser for bitfield extract patterns
  - canonical emitter
  - legacy emitter
  - rule-form dispatch wiring in `bpf_jit_try_emit_rule()`

x86 emission behavior:

- use BMI1 `bextr` when `boot_cpu_has(X86_FEATURE_BMI1)` and the effective extracted mask is contiguous
- otherwise emit an exact compact fallback
  - prefer `shr reg, imm; and reg, imm`
  - preserve `and; shr` when needed for exact semantics or immediate-encoding limits

## Benchmark Changes

Added a new staged-input XDP benchmark:

- program: `micro/programs/bitfield_extract.bpf.c`
- generator: `micro/input_generators.py`
- config entry: `config/micro_pure_jit.yaml`

Benchmark characteristics:

- fixed 32-record staged input
- each record contains two packed `u64` words
- 12 source-level field extracts per record body
- final generated BPF preserves 9 static extract sites after clang optimization

Configured benchmark result:

- `kernel_input_size: 520`
- `expected_result: 12211926182125163441`

Runner plumbing was also updated so `--recompile-all` and v5 autoscan paths can include the new family:

- `--recompile-extract`
- `--recompile-bitfield-extract`
- `--skip-families ... extract`

## Build And Verification

Completed on March 11, 2026.

Successful checks:

- `cmake --build scanner/build -j`
- `./scanner/build/test_scanner`
  - result: `OK: 83 passed, 0 failed`
- `python3 -m py_compile micro/input_generators.py`
- `make -C micro`

One build command from the task text does not currently work in this repo:

- `make -C scanner`
  - fails because `scanner/` has no top-level `Makefile`
  - the working build path is `scanner/build/`

## Scan Results

### New benchmark

The current scanner CLI accepts `--xlated`, not raw ELF objects, so the benchmark object was scanned by dumping its `xdp` section with `llvm-objcopy`.

Legacy scanner result:

- `9` accepted `bitfield-extract` sites

v5 scanner result:

- `9` accepted v5 `extract` sites

### Corpus census

For the same reason, the corpus census was run by dumping each non-dot ELF text section from `corpus/build/**/*.bpf.o` and scanning those section blobs with `--v5 --extract`.

Corpus totals:

- total extract sites: `544`
- sections with hits: `71`
- objects with hits: `41`

Top sections by extract count:

- `138` - `corpus/build/cilium/bpf_lxc.bpf.o` section `tc/tail`
- `32` - `corpus/build/cilium/bpf_overlay.bpf.o` section `tc/tail`
- `28` - `corpus/build/cilium/bpf_xdp.bpf.o` section `xdp/tail`
- `22` - `corpus/build/tetragon/bpf_generic_usdt.bpf.o` section `uprobe`
- `22` - `corpus/build/tetragon/bpf_generic_uprobe.bpf.o` section `uprobe`
- `22` - `corpus/build/tetragon/bpf_generic_tracepoint.bpf.o` section `tracepoint`
- `22` - `corpus/build/tetragon/bpf_generic_rawtp.bpf.o` section `raw_tp`
- `22` - `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` section `kprobe`

## Notes

- The benchmark object path produced by this repo is `micro/programs/bitfield_extract.bpf.o`, not `micro/build/programs/bitfield_extract.bpf.o`.
- The benchmark intentionally keeps the source-level extract idiom explicit, but clang still folds some extracts together; that is why the final object shows `9` static sites instead of all `12` source-level extracts.
- I did not run a full kernel tree build for `vendor/linux-framework`; validation here is userspace build/test coverage plus scanner output inspection and source integration.
