# arm64 ReverseSim Prototype

This directory is the arm64 counterpart of `../x86`.

Current scope:

- C-authored simulator macros for the AArch64 subset emitted by current micro
  native builds.
- Generated micro proof objects for the pure and helper/map suites.
- A hardcoded BPF object that still verifies the basic build/load path.
- No memory safety guards, no fallback/trap path, no synthetic proof facts.

The simulator state is architectural state only: general-purpose registers plus
NZCV flags when a covered instruction updates them. Unsupported instructions
must fail at generation/build time rather than falling back at runtime.

The generator consumes prebuilt `.proof.o` files emitted by
`native-link --mode proof`, disassembles them, and emits labels plus simulator
instruction macros. Helper/map/rodata sites stay represented by ELF
relocations in the proof object; the generator does not parse the original
native object relocation frontend.

## Smoke

```bash
make -C native-sim/arm64 run
```

This compiles `arm64_sim_hardcoded.bpf.c` and load-tests
`arm64_sim_hardcoded_xdp`.

Current local result:

```bash
make -C native-sim/arm64 build
sudo native-sim/loader/target/debug/reversesim-loader \
  --object native-sim/arm64/build/arm64_sim_hardcoded.bpf.o \
  --program arm64_sim_hardcoded_xdp \
  --case simple \
  --load-only
```

Result:

- load ok
- verifier/load time: `0.000248 s`

## AWS Arm64 Note

Use the repository Makefile for AWS runs:

```bash
PLATFORM=aws ARCH=arm64 SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000 make micro
```

`runner/targets/aws-arm64.env` currently defaults benchmark instances to
`t4g.small` and test instances to `t4g.micro`.

Current AWS smoke:

```bash
PLATFORM=aws ARCH=arm64 SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000 make micro
```

Result:

- raw result: `micro/results/aws_arm64_micro_20260520_052452_727433/metadata.json`
- status: completed
- benchmarks: 29/29
- runtimes: native userspace (`native`), LLVM-BPF (`llvmbpf`), kernel eBPF (`kernel`)
- AWS instance: one `t4g.small`, terminated by the executor after result sync
