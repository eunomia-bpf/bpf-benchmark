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
This is the verifier-compatible mode. On May 15, 2026 it passed all 37
`bpfopt/testobject` objects through `bpfopt-loader --pass noop --bpfopt
bpfopt/llvm/build/bpfopt`, covering 378 individual BPF programs.

Non-`noop` pass mode currently enables the O3 pipeline. O3 is not yet
verifier-compatible across the corpus: using the existing `dce` loader config to
trigger O3 passes bcc, bpftrace, `cilium_bpf_host`, and `cilium_bpf_lxc`, then
fails at `cilium_bpf_overlay.bpf.o`. The first observed failure is a map-value
offset bounds check that is semantically redundant after LLVM optimization but
still required for the kernel verifier to prove bounded access. O3 therefore
needs verifier-aware range-check preservation before it can replace O0.

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

The llvmbpf changes are published on
`origin/codex/bpfopt-llvm-roundtrip-20260515` in the upstream llvmbpf
repository.

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

Full O0 verifier run used during validation:

```sh
BASE=/tmp/test-all-noop-strict-llvmbpf-o0
rm -rf "$BASE"
mkdir -p "$BASE"
printf '{"arch":"x86_64","kinsns":{}}\n' >"$BASE/target.json"
for obj in $(find bpfopt/testobject -maxdepth 1 -type f \
  \( -name '*.bpf.o' -o -name 'tetragon_*.o' \) | sort); do
  name=$(basename "$obj")
  mkdir -p "$BASE/$name"
  sudo -n bash -lc "ulimit -l unlimited; cd $(pwd); \
    timeout 900 bpfopt/target/debug/bpfopt-loader \
      --obj '$obj' --pass noop \
      --bpfopt bpfopt/llvm/build/bpfopt \
      --target '$BASE/target.json' \
      --workdir '$BASE/$name/work'"
done
```
