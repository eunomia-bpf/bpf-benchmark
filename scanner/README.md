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
│   └── types.h
├── src/
│   ├── cli.cpp
│   └── pattern_v5.cpp
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

# Offline scan from xlated bytecode and write a v5 blob
./build/bpf-jit-scanner scan --xlated dump.bin --all --output policy.blob

# Apply a v5 blob generated from the current program
./build/bpf-jit-scanner apply --prog-fd 5 --all

# Dump post-verifier xlated bytecode for offline analysis
./build/bpf-jit-scanner dump --prog-fd 5 --output dump.bin
```

Supported family flags:

- `--cmov`
- `--wide-mem`
- `--rotate`
- `--lea`
- `--bitfield-extract` or `--extract`
- `--all`
- `--rorx`

The CLI is v5-only. `--v5` is still accepted as a no-op so existing v5
automation does not need to change in lockstep.

## Library

[`include/bpf_jit_scanner/pattern_v5.hpp`](./include/bpf_jit_scanner/pattern_v5.hpp)
exposes the full v5 API:

- `scan_v5_builtin()`: builtin declarative-pattern scanning
- `build_policy_blob_v5()`: serialize rules into the kernel v5 blob format

The scanner operates on post-verifier xlated bytecode, not ELF instructions.
