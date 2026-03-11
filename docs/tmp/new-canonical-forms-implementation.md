# new canonical forms implementation

Date: 2026-03-11

## 1. Scope

This change set implements three new v6-target canonical forms across both the scanner and the framework kernel:

- `ZERO_EXT_ELIDE`
- `ENDIAN_FUSION`
- `BRANCH_FLIP`

It also updates the scanner CLI so `scan <prog.bpf.o> --v5` can consume ELF objects directly. The CLI now prefers loading the object and fetching kernel xlated bytecode; if loading is unavailable, it falls back to the ELF program instructions.

## 2. Scanner changes

### 2.1 `ZERO_EXT_ELIDE`

- added `BPF_JIT_CF_ZERO_EXT_ELIDE`
- added v5 descriptors for:
  - `{ ALU32_* dst, ... ; MOV64_REG dst, dst }`
  - `{ ALU32_* dst, ... ; AND64_IMM dst, 0xffffffff }`
- added `zero_ext` family counters and CLI flag plumbing
- added unit coverage in `scanner/tests/test_scanner.cpp`

### 2.2 `ENDIAN_FUSION`

- added `BPF_JIT_CF_ENDIAN_FUSION`
- added v5 descriptors for:
  - `{ LDX_MEM_* dst, [src+off] ; ENDIAN_* dst, width }`
  - `{ ENDIAN_* src, width ; STX_MEM_* [dst+off], src }`
- canonical params:
  - data reg
  - base reg
  - offset
  - width
  - direction (`load_swap` / `swap_store`)
- native choice requires `MOVBE`
- added unit coverage in `scanner/tests/test_scanner.cpp`

### 2.3 `BRANCH_FLIP`

- added `BPF_JIT_CF_BRANCH_FLIP`
- scanner now detects a bounded local if/else diamond:
  - `jcc +N`
  - body A
  - `ja +M`
  - body B
  - join
- matcher enforces:
  - body length `1..16`
  - no outside edge into body interior
  - only supported linear body instructions
- canonical params record:
  - condition op
  - body A start/len
  - body B start/len
  - join target
- native choice supports `ORIGINAL` and `FLIPPED`
- added unit coverage in `scanner/tests/test_scanner.cpp`

### 2.4 CLI compatibility

- `scanner/src/cli.cpp` now accepts positional ELF object input for `scan`
- `--program-name` now selects a program when scanning a multi-program object
- scanner README updated to document the new path and the new family flags

## 3. Kernel changes

### 3.1 UAPI / common validation

`vendor/linux-framework/include/uapi/linux/bpf.h` now includes:

- `BPF_JIT_CF_ZERO_EXT_ELIDE`
- `BPF_JIT_CF_ENDIAN_FUSION`
- `BPF_JIT_CF_BRANCH_FLIP`
- per-form native-choice enums
- per-form canonical-param enums
- `BPF_JIT_X86_MOVBE`

`vendor/linux-framework/kernel/bpf/jit_directives.c` now includes:

- canonical-form dispatch and native-choice validation for all three forms
- canonical-param validation for all three forms
- dedicated site validators for:
  - zero-ext elision pairs
  - endian fusion load/swap and swap/store pairs
  - branch-flip local diamonds with no interior outside edges
- CPU feature validation for `MOVBE`

### 3.2 x86 emitters

`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` now includes:

- `ZERO_EXT_ELIDE`
  - emit only the first 32-bit ALU instruction
  - rely on x86 32-bit write semantics to zero-extend
- `ENDIAN_FUSION`
  - emit `movbe` load/store sequences for 16/32/64-bit widths
  - reject the form when `MOVBE` is unavailable
- `BRANCH_FLIP`
  - invert the conditional jump
  - measure body sizes
  - emit body B first, then skip over body A
  - preserve `ORIGINAL` as a no-op choice that falls back to stock emission

## 4. Validation

### 4.1 Required build/test commands

After the canonical-form implementation batches and again after the final scanner CLI changes:

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
   - success: `Kernel: arch/x86/boot/bzImage is ready  (#23)`
2. `cmake --build scanner/build -j$(nproc)`
   - success: `Built target bpf-jit-scanner`
3. `./scanner/build/test_scanner`
   - success: `PASS 78`

### 4.2 VM smoke

Command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "
cd /home/yunwei37/workspace/bpf-benchmark
./scanner/build/bpf-jit-scanner scan micro/programs/simple.bpf.o --v5 2>&1 | head -20
./scanner/build/bpf-jit-scanner scan micro/programs/binary_search.bpf.o --v5 2>&1 | head -20
"
```

Observed output:

```text
Accepted 1 v5 site(s)
  cmov:   0
  wide:   0
  rotate: 0
  lea:    0
  extract:0
  zeroext:0
  endian: 0
  bflip:  1
Accepted 4 v5 site(s)
  cmov:   1
  wide:   2
  rotate: 0
  lea:    0
  extract:0
  zeroext:0
  endian: 0
  bflip:  1
```

Notes:

- the requested smoke path now works directly on `.bpf.o` inputs
- in this VM/kernel/toolchain combination, the two requested smoke programs surface `BRANCH_FLIP` sites but do not surface `ZERO_EXT_ELIDE` or `ENDIAN_FUSION`
- `ZERO_EXT_ELIDE` and `ENDIAN_FUSION` are still covered by dedicated scanner unit tests and kernel-side validator/emitter build coverage

## 5. Files touched

Scanner:

- `scanner/CMakeLists.txt`
- `scanner/README.md`
- `scanner/include/bpf_jit_scanner/types.h`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
- `scanner/src/cli.cpp`
- `scanner/src/pattern_v5.cpp`
- `scanner/tests/test_scanner.cpp`

Kernel:

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Docs:

- `docs/tmp/v6-interface-design.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/new-canonical-forms-implementation.md`
