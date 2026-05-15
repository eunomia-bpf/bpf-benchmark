# bpfopt LLVM Roundtrip

`bpfopt/llvm` builds a C++ executable named `bpfopt`. It is a drop-in
replacement for the Rust `bpfopt` bytecode CLI at the daemon/loader boundary:
stdin/stdout or `--input`/`--output` carry raw `struct bpf_insn[]` bytes, and
the caller selects the binary by path. `bpfopt-loader` supports this with
`--bpfopt <path>`; daemon-side integration should use the same path-selection
model rather than changing the daemon protocol.

The accepted CLI surface is intentionally narrow:

```sh
bpfopt --canonicalize-map-refs --input in.bin --output out.bin --map-ids 1,2
bpfopt --pass noop --input in.bin --output out.bin --report report.json --prog-type xdp
```

`--canonicalize-map-refs` preserves the existing raw bytecode contract. Pass mode
must be a strict LLVM roundtrip:

1. lift kernel BPF bytecode with llvmbpf in kernel-compatible mode;
2. materialize real LLVM IR for the program;
3. run the selected LLVM pipeline;
4. lower through LLVM's BPF backend into an ELF object;
5. extract and relocate `.text`;
6. write the new raw BPF instruction stream.

There is no raw-bytecode fallback for `noop`. A verifier failure is a real
roundtrip failure and must be fixed in the lift/lower path or surfaced to the
caller.

Current `noop` uses the O0-oriented path: register allocas are promoted enough
for LLVM codegen to lower the IR, but the O3 module pipeline is not enabled.
Non-`noop` pass mode currently enables the O3 pipeline. The expected validation
order is: first make strict O0 `noop` pass every loader test object, then test
the same corpus with O3 enabled.

The local llvmbpf changes are kept to compatibility fixes needed by kernel
bytecode:

- expose `generateModule()` so this CLI can inspect and emit the generated IR;
- preserve kernel pseudo map, map-value, map-index, function-pointer, and
  BPF-to-BPF call relocations as external symbols for LLVM's BPF object writer;
- model helper calls with the real helper arity so LLVM does not read
  uninitialized argument registers;
- load 32-bit ALU/JMP operands from the 64-bit BPF register storage and truncate;
- attach natural alignment to memory loads/stores emitted from BPF memory ops;
- compute kernel stack requirements only for the entry function prefix that is
  actually lifted into the generated module.

Build:

```sh
cmake -S bpfopt/llvm -B bpfopt/llvm/build -DCMAKE_BUILD_TYPE=Release
cmake --build bpfopt/llvm/build -j
```

Strict loader smoke:

```sh
sudo -n bash -lc 'ulimit -l unlimited; bpfopt/target/debug/bpfopt-loader \
  --obj bpfopt/testobject/tracee_tracee.bpf.o \
  --pass noop \
  --bpfopt bpfopt/llvm/build/bpfopt \
  --target /tmp/bpfopt-llvm-target.json \
  --workdir /tmp/bpfopt-llvm-work'
```
