# Native Lab — running userspace-compiled x86 in kernel as eBPF replacement

A research escape hatch that lets userspace upload arbitrary x86-64 byte
sequences and execute them in kernel context as if they were the body of
a BPF program. The whole pipeline is end-to-end functional and gives us a
true "no verifier, no BPF JIT translation" performance baseline to compare
against bpfopt+kinsn passes — i.e. the A column of the OSDI paper's
three-archetype comparison.

## Goal

For each micro benchmark in `micro/programs/*.bpf.c`:

| column | what runs | what it tells us |
|--------|-----------|------------------|
| **A. native_lab** | clang -target x86_64 -O2 of the same `.bpf.c` source → linked through `native-link` → splatted into a BPF JIT image via the `bpf_x86_native_lab` kinsn | what the function would cost with no verifier inserts, no BPF→x86 translation |
| **B. kinsn** | the production bpfopt+kinsn pipeline (run via `make micro` etc.) | how close the production pipeline gets to A |
| **C. kernel BPF JIT** | stock `.bpf.o` → libbpf → BPF JIT | the BPF performance baseline B is trying to beat |

This directory ships A. B and C run through existing `make micro` infra;
the integration just exposes A as a new runtime mode (`run-native-lab`)
inside the same `micro_exec` binary.

## Architecture

```
                         userspace                                  kernel
   ┌──────────────┐  link   ┌─────────────┐  upload  ┌─────────────────────┐
   │ .native.so   │ ──────▶ │ .native.bin │ ────────▶│ /sys/kernel/debug/  │
   │ (clang x86)  │ native- │ (≤128 B per │ debugfs  │ bpf_x86_native_lab/ │
   └──────────────┘  link   │  chunk × N) │          │ blob{0..63}         │
                            └─────────────┘          └─────────────────────┘
                                                                │
   ┌──────────────────────────────────────┐                     │
   │ tiny BPF stub (built at runtime)     │  BPF_PROG_LOAD      ▼
   │   for each chunk:                    │ ───────────────▶ verifier sees
   │     sidecar(blob_id=i)               │                  `r0 = XDP_PASS`
   │     call bpf_x86_native_lab_emit     │                  (the kinsn's
   │   exit                               │                   instantiate_insn
   └──────────────────────────────────────┘                   proof; the actual
                                                              emit_x86 splats
                                                              raw bytes)
                                                                │
   BPF_PROG_TEST_RUN  ─────────────────────────────────────────▶ JIT image:
                                                                 [BPF prologue]
                                                                 [chunk 0 bytes]
                                                                 [chunk 1 bytes]
                                                                 ...
                                                                 [chunk N-1]
                                                                 [BPF epilogue]
```

## Layout

```
native-sim/x86/native_lab/
├── README.md                        — this file
├── native_link/                     — Rust ELF → native blob linker
│   ├── Cargo.toml
│   └── src/main.rs                  — uses `object` + `iced-x86`
├── tests/
│   ├── poc.c                        — bare-bones mechanism smoke test
│   │                                  (return 42 + multi-chunk wraparound)
│   ├── run_vm.sh                    — vng wrapper for poc.c
│   ├── run_micro_one.sh             — vng wrapper: link + run one program
│   │                                  through both runtimes
│   ├── run_all_micro.sh             — sweep every xdp micro benchmark
│   ├── analyze.py                   — per-program ratio + geomean
│   └── Makefile                     — builds poc.c
└── results/                         — JSONL output of run_all_micro.sh
                                      (gitignored)
```

The kernel-side kinsn module lives at `module/x86/bpf_x86_native_lab.c`
because the project's existing kinsn build pipeline auto-scans that
directory. Conceptually it's part of this research line; physically it
sits with the other kinsn modules so `make host-kinsn-x86` picks it up.

## The linker — what it actually does

`native-link` reads a userspace `.so` produced by
`micro/programs/Makefile`'s `MICRO_NATIVE` build path. It does the
absolute minimum work needed to bridge two ABIs:

1. **SysV AMD64** (what clang emits): `rdi` = first arg, `rax` = return,
   `rbx`/`rbp`/`r12`-`r15` callee-saved, control returns via `ret`.
2. **The native_lab kinsn contract** (what kernel will run): splatted in
   the middle of a BPF JIT image where the BPF JIT prologue already
   pushed the callee-saved registers and the BPF JIT epilogue expects to
   pop them. The blob must fall through to the epilogue, never `ret`.

The transformation:

1. `object` parses the ELF and finds the symbol's `.text` byte slice.
2. `iced_x86::Decoder` disassembles those bytes.
3. Compiler alignment NOPs are dropped (iced re-encodes multi-byte NOPs
   to shorter forms; dropping them sidesteps the size-arithmetic).
4. Every `RET` / `Retfq` / `Ret*_imm16` is replaced with a 5-byte
   `JMP rel32 -> end_label` placeholder.
5. `BlockEncoder::encode` lays out the block at IP=0 and reports each
   instruction's new offset.
6. We patch the `disp32` of each placeholder JMP so it lands at the
   blob's tail (where the BPF JIT's exit epilogue will be emitted).
7. Any PC-relative reference whose target sits outside the function (
   rodata, GOT, other functions) is rejected up front — the kernel splat
   location doesn't match the userspace ELF layout, so silently emitting
   the original `disp` would point at garbage.

We don't strip the prologue's push-callee-saved or the epilogue's pop-
callee-saved. Compilers emit balanced push/pop along every control-flow
path, so each `ret` site already sees a balanced stack. By the time the
rewritten `jmp end_label` fires, the function has popped whatever it
pushed, and the BPF JIT prologue's saved values are intact.

## Building

```sh
# 1. Rust linker
cargo build --release --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml

# 2. Kinsn module (uses the existing host-kinsn-x86 target)
make host-kinsn-x86

# 3. micro_exec (the `run-native-lab` mode is already wired into the
#    existing CMake target via runner/src/native_lab_runner.cpp)
cmake --build runner/build-llvmbpf --target micro_exec -j8

# 4. Micro programs' .native.so (already built by `make micro` or by hand)
make -C micro/programs
```

## Running

End-to-end: link one program, run native_lab and kernel BPF JIT under
the same input, print both samples:

```sh
vng --run .cache/runtime-kernel/x86_64/bzImage \
    --cwd "$(pwd)" --rwdir "$(pwd)" --overlay-rwdir /tmp \
    --cpus 2 --memory 2G \
    --append "loglevel=4 panic=30 oops=panic" \
    --exec "native-sim/x86/native_lab/tests/run_micro_one.sh bitmap_popcount_scan bitmap_popcount_scan_xdp 2056 1000"
```

Full sweep (all 26 xdp micros):

```sh
vng ... --exec native-sim/x86/native_lab/tests/run_all_micro.sh \
    > native-sim/x86/native_lab/results/all_micro.jsonl

python3 native-sim/x86/native_lab/tests/analyze.py
```

## Limitations (and why they're acceptable for the research goal)

- **No verifier protection at all.** Any blob with bad reg/state usage
  panics the kernel. This module is research-only; do not load it on
  production kernels.
- **Single-function symbols only.** `bpf_local_call_fanout_dispatch` is
  the one current micro benchmark that uses `__noinline` subprograms;
  the linker correctly rejects it because the entry function calls into
  bytes that wouldn't be in the splatted blob.
- **Non-xdp prog types** (`tc_packet_checksum_fold`,
  `cgroup_skb_hash_chain`) are skipped — the stub BPF program is
  currently hard-coded to `BPF_PROG_TYPE_XDP`. Extending to sched_cls /
  cgroup_skb is straightforward but unnecessary for the paper claim,
  which targets the xdp population.
- **No `.rodata` references.** The linker bails on any RIP-relative
  load whose target is outside the function's bytes. Today's micro
  programs are pure-compute so this never fires; if a future program
  needs a lookup table, the linker will need to splat the `.rodata`
  bytes adjacent to `.text` and fix up the `disp32`s.
- **`bpf_x86_native_lab` is loaded explicitly, never automatically.**
  It is *not* part of `expected_kinsn_modules()` and the production
  benchmark runner doesn't insmod it. Smoke scripts insmod it before
  use.

## Latest results (`results/all_micro.jsonl`)

See `tests/analyze.py` output. Headline numbers:

- 26 programs measured, 1 linker-rejected, 2 skipped (non-xdp).
- Per-program geomean of `native_lab / kernel_jit` = **0.6438x**
  (native_lab is 1.55x faster on average).
- 23 wins, 2 losses, 1 tie.
- All 26 measured programs match the kernel JIT output bit-for-bit
  (`result` field identity check).
