# bpf-jit-scanner

`bpf-jit-scanner` is the userspace policy layer for the kernel JIT rewrite
prototype. It keeps the original low-level C scan/blob APIs, and adds a new
C++ engine that provides:

- A pluggable pattern registry
- Static per-site feature extraction
- Policy selection from static heuristics plus config overrides
- Overlap arbitration across pattern families
- A profile-provider hook for future PGO

The matcher bodies remain the same as the original extraction from
`micro/runner/src/kernel_runner.cpp`. The redesign changes how matches are
registered, merged, and turned into final policy rules.

## Layout

```text
scanner/
├── CMakeLists.txt
├── README.md
├── examples/
│   └── default_policy.yaml
├── include/bpf_jit_scanner/
│   ├── engine.hpp
│   ├── policy.h
│   ├── scanner.h
│   └── types.h
├── src/
│   ├── cli.cpp
│   ├── engine.cpp
│   ├── policy.cpp
│   └── scanner.cpp
└── tests/
    └── test_scanner.cpp
```

## Build

```bash
cd scanner
cmake -B build
cmake --build build
./build/test_scanner
```

## CLI

```bash
# Scan a live program and print policy decisions
./build/bpf-jit-scanner scan --prog-fd 5 --all

# Offline scan from xlated bytecode using selected families
./build/bpf-jit-scanner scan --xlated dump.bin --rotate --wide-mem

# Apply policy decisions to a live program
./build/bpf-jit-scanner apply --prog-fd 5 --policy examples/default_policy.yaml

# Dump post-verifier xlated bytecode for offline analysis
./build/bpf-jit-scanner dump --prog-fd 5 --output dump.bin
```

`scan` and `apply` default to all registered families when no family flags are
provided. `--rorx` requests BMI2 rotate lowering. `apply` builds a blob,
creates a sealed memfd, and issues `BPF_PROG_JIT_RECOMPILE`.

## Policy File

The parser intentionally supports a very small YAML subset: top-level
`default_*` keys and an `overrides:` list with `program:` glob patterns.

```yaml
default_rotate: rorx
default_cmov: branch
default_wide_mem: wide
default_lea: lea

overrides:
  - program: "log2_fold*"
    cmov: branch
  - program: "cmov_select*"
    cmov: cmovcc
```

Supported values:

- `default_cmov`: `branch`, `cmovcc`, `profile`, `skip`
- `default_rotate`: `ror`, `rorx`, `profile`, `skip`
- `default_wide_mem`: `wide`, `profile`, `skip`
- `default_lea`: `lea`, `profile`, `skip`

`profile` is a placeholder hook today. If no profile provider is installed, the
engine falls back to the static heuristic and marks the decision source as a
profile fallback.

## APIs

### C APIs

The C layer remains the low-level boundary:

- [`include/bpf_jit_scanner/scanner.h`](./include/bpf_jit_scanner/scanner.h)
  exposes the family scanners.
- [`include/bpf_jit_scanner/policy.h`](./include/bpf_jit_scanner/policy.h)
  serializes final rules into the kernel blob format.

These functions are intentionally simple and operate directly on raw xlated
bytecode.

### C++ Engine

[`include/bpf_jit_scanner/engine.hpp`](./include/bpf_jit_scanner/engine.hpp)
adds the higher-level orchestration layer:

- `PatternRegistry`: register built-in or custom pattern families
- `PolicyEngine::scan()`: collect raw candidates, extract features, resolve overlaps
- `PolicyEngine::decide()`: apply static heuristics, config defaults, overrides,
  and optional profile guidance
- `PolicyEngine::materialize()`: emit the final `bpf_jit_scan_rule` list

The built-in static heuristic is deliberately conservative for CMOV:

- Loop-heavy / branch-dense sites prefer `CMOVCC`
- Otherwise the engine prefers `BRANCH`
- ROTATE, WIDE_MEM, and LEA default to their optimized lowerings

## Pattern Families

- `cmov`: 4-insn diamond and 3-insn compact conditional-select patterns
- `wide-mem`: 2/4/8-byte byte-load ladders, including clang’s high-byte-first form
- `rotate`: 4/5/6-insn rotate idioms
- `lea`: `mov64 + lsh64 + add64` address-calculation idiom

The engine merges sites from multiple families and rejects overlaps using a
deterministic arbitration priority. Conflicts are reported in CLI output.

## Notes

- The scanner works on post-verifier xlated bytecode, not ELF instructions.
- Offline blob generation uses a zero `prog_tag` unless `--prog-tag` is supplied.
- The library has no third-party dependencies beyond a C++20 compiler and CMake.
