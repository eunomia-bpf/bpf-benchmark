# bpf-jit-scanner

`bpf-jit-scanner` is the userspace front end for the v5 BpfReJIT policy
format. It scans post-verifier xlated BPF bytecode, emits declarative pattern
rules, and can pass the resulting blob to `BPF_PROG_JIT_RECOMPILE`.

## Layout

```text
scanner/
├── CMakeLists.txt
├── include/bpf_jit_scanner/
│   ├── pattern_v5.hpp
│   ├── policy_config.hpp
│   └── types.h
├── src/
│   ├── cli.cpp
│   ├── pattern_v5.cpp
│   └── policy_config.cpp
└── tests/
    └── test_scanner.cpp
```

## Build

```bash
cd scanner
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## CLI

```bash
# Scan a live program and print the accepted v5 sites
./build/bpf-jit-scanner scan --prog-fd 5 --all

# Scan a BPF ELF object; the CLI will try to load it and fetch xlated
# bytecode, then fall back to the ELF program instructions if loading fails
./build/bpf-jit-scanner scan ../micro/programs/simple.bpf.o --all

# Offline scan from xlated bytecode and write a v5 blob
./build/bpf-jit-scanner scan --xlated dump.bin --all --output policy.blob

# Emit a machine-readable site manifest
./build/bpf-jit-scanner scan --xlated dump.bin --all --json

# Compile a filtered blob from a YAML/JSON policy file
./build/bpf-jit-scanner compile-policy --xlated dump.bin --config policy.yaml --output policy.blob

# Or stream the filtered blob to stdout
./build/bpf-jit-scanner compile-policy --xlated dump.bin --config policy.yaml > policy.blob

# Apply a v5 blob generated from the current program
./build/bpf-jit-scanner apply --prog-fd 5 --all

# Apply a filtered policy directly from config
./build/bpf-jit-scanner apply --prog-fd 5 --config policy.yaml

# Dump post-verifier xlated bytecode for offline analysis
./build/bpf-jit-scanner dump --prog-fd 5 --output dump.bin
```

Supported family flags:

- `--cmov`
- `--wide-mem`
- `--rotate`
- `--lea`
- `--bitfield-extract` or `--extract`
- `--zero-ext`
- `--endian`
- `--branch-flip`
- `--all`
- `--rorx`

The CLI is v5-only. `--v5` is still accepted as a no-op so existing v5
automation does not need to change in lockstep.

`scan --json` prints a JSON manifest with program metadata, per-family counts,
and per-site entries. `compile-policy` reads a single-program version 2 policy
file with a per-site schema such as:

```yaml
version: 2
program: demo-program
default: skip
sites:
  - insn: 12
    family: wide
    action: apply
  - insn: 44
    family: rotate
    action: apply
```

JSON input is accepted too because the parser goes through `yaml-cpp`.

When `scan` is given a positional file path, the CLI auto-detects ELF input.
For `.bpf.o` objects it first tries to load the selected program and fetch
kernel xlated bytecode. If loading is unavailable, it falls back to scanning
the ELF program instructions directly. `--program-name` selects the program in
multi-program objects.

## Library

[`include/bpf_jit_scanner/pattern_v5.hpp`](./include/bpf_jit_scanner/pattern_v5.hpp)
exposes the full v5 API:

- `scan_v5_builtin()`: builtin declarative-pattern scanning
- `build_policy_blob_v5()`: serialize rules into the kernel v5 blob format

[`include/bpf_jit_scanner/policy_config.hpp`](./include/bpf_jit_scanner/policy_config.hpp)
adds:

- version 2 policy config loading/filtering for per-site apply/skip decisions
- JSON manifest construction for `scan --json`

The library API operates on post-verifier xlated bytecode. The CLI can also
accept ELF objects for convenience and will resolve them to xlated or raw BPF
instructions before calling the library.
