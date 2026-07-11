# bpfopt LLVM Roundtrip

`bpfopt/llvm` builds the C++ executable named `bpfopt` used by the runner:
stdin/stdout or `--input`/`--output` carry raw `struct bpf_insn[]` bytes, and
the caller selects the binary by path. `bpfopt-loader` supports this with
`--bpfopt <path>` without changing the bytecode protocol.

The accepted CLI surface is intentionally narrow:

```sh
bpfopt --canonicalize-map-refs --input in.bin --output out.bin --map-ids 1,2
bpfopt --pass noop --input in.bin --output out.bin --report report.json --prog-type xdp
bpfopt --pass map_inline --input in.bin --output out.bin --report report.json \
  --prog-type xdp -- \
  --map-values map-values --map-ids 1,2 --inline-hint=map_name:00000000
```

`--canonicalize-map-refs` preserves the existing raw bytecode contract. Pass mode
must be a strict LLVM O3 roundtrip:

1. lift kernel BPF bytecode with llvmbpf in kernel-compatible mode;
2. materialize real LLVM IR for the program;
3. run the LLVM O3 pipeline;
4. lower through LLVM's BPF backend into an ELF object;
5. extract and relocate `.text`;
6. write the new raw BPF instruction stream.

There is no raw-bytecode fallback for `noop`: `noop` is also an LLVM O3
roundtrip and is not byte-preserving. A verifier failure is a real roundtrip
failure and must be fixed in the lift/lower path or surfaced to the caller.

Every `--pass <name>` invocation runs exactly one O3 lift/optimize/lower cycle.
`map_inline` performs a pass-specific IR rewrite before O3; `branch_flip`
validates a real per-site profile and attaches LLVM branch-weight metadata
before O3. All other pass names use the same plain O3 roundtrip.

Post-lowering extraction is not a verifier repair stage. After LLVM's BPF
backend emits the object, this tool only applies ELF relocations and restores
the raw instruction stream. It must not synthesize verifier proofs, insert
bounds checks, delete instructions, or rewrite memory-address forms after
backend codegen.

`map_inline` uses pass-local `--map-values`, `--map-ids`, and
`--inline-hint=<map>:<key_hex>` inputs. A hint identifies one map entry whose
snapshotted value may be used; there is no hard/soft hint split. Katran
`balancer_ingress` passes loader verification and `BPF_PROG_TEST_RUN` with 16
lookup sites reported as inlined.

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

Full O3 verifier run used during validation:

```sh
BASE=/tmp/test-all-noop-strict-llvmbpf-o3
rm -rf "$BASE"
mkdir -p "$BASE"
printf '{"arch":"x86_64","koperation":{}}\n' >"$BASE/target.json"
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
