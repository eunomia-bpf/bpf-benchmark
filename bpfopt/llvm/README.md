# bpfopt LLVM Drop-In

`bpfopt/llvm` builds a C++ executable named `bpfopt` with the same file-oriented
CLI surface used by the daemon when it shells out to the Rust `bpfopt` binary.
It is intended to be selected by path, for example by putting
`bpfopt/llvm/build` before the Rust binary in `PATH`.

The tool accepts the daemon/loader contract:

```sh
bpfopt --canonicalize-map-refs --input in.bin --output out.bin --map-ids 1,2
bpfopt --pass noop --input in.bin --output out.bin --report report.json --prog-type xdp
```

`--canonicalize-map-refs` preserves the existing raw bytecode contract by
rewriting loader map-fd pseudos into fd-array map-index pseudos and shifting
`target.json` module call offsets when `--target-output` is used. Pass mode runs
a kernel-compatible llvmbpf lift, LLVM optimization, LLVM BPF lowering,
relocation repair, and writes raw `struct bpf_insn[]` bytes to `--output`.

`bpfopt-loader` is not path-selectable today: it hardcodes
`bpfopt/target/debug/bpfopt` and rewrites yaml commands to that path. Testing
this binary through the loader therefore requires either an explicit loader
change or replacing that artifact outside this tree.

Build:

```sh
cmake -S bpfopt/llvm -B bpfopt/llvm/build -DCMAKE_BUILD_TYPE=Release
cmake --build bpfopt/llvm/build -j
```
