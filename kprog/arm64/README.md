# arm64 ReverseSim Prototype

This directory is the arm64 counterpart of `../x86`.

Current scope:

- C-authored simulator macros for the AArch64 subset emitted by current micro
  native builds.
- Generated micro proof objects for the pure and helper/map suites.
- A hardcoded BPF object that still verifies the basic build/load path.
- No memory safety guards, no fallback/trap path, no synthetic proof facts.

The simulator stores architectural general-purpose registers and NZCV flags,
plus all 32 architectural 128-bit SIMD registers and proof-side provenance
tags used to select verifier-visible pointer operations. Scalar FMOV selects
its encoded SIMD register; writes of S/D lanes clear the upper bits. `../formal` machine-checks the shared width/narrowing contract, the
NZCV flag transitions for the ADD/SUB/logical families, the six-operation ALU
op-step result contract, the eleven-arm source-modifier (shift/rotate/extend)
value contract, the five-kind bitfield (UBFX/SBFX/UBFIZ/BFXIL/BFI) value
contract, the eight-operation multiply-family (MADD/MSUB/MUL/UMULL/UDIV/UMULH/
UMADDL/SMADDL) value contract, the six-operation extract/reverse/extend
(`EXTR`/`REV`/`REV16`/`SXTH`/`SXTW`/`SXTB`) value contract, the
eight-operation conditional-select (`CSEL`/`CINC`/`CSET`/`CSETM`/`CINV`/
`CSINV`/`CSINC`/`CSNEG`) value contract composed with the condition table, the
four-kind compare-and-branch (`CBZ`/`CBNZ`/`TBZ`/`TBNZ`) predicate contract, the
four-column move-wide (`MOVK`) insertion contract, the four-kind shift
(`LSL`/`LSR`/`ASR`/`ROR`) value contract shared with the decode table, the
two-kind byte-lane reduction (`CNT`/`UADDLV`) contract, the four-form
load/store address-offset contract, the four-direction FMOV move contract, the
four-width little-endian byte-ladder load contract, the eight-lane byte-lane
scatter contract (proved inverse to the load ladder), the four-space memory
tag-dispatch contract, the two-condition stack slot-tag contract, the
two-shape branch-emission contract (bridging the branch predicates to the
generated `goto`/label emission), the
ALU/shift/modifier/bitfield decode tables, the condition table, and the
pointer-add/ABI-load contracts against independently stated specs
(`make -C ../formal check`), plus tag erasure for a four-operation shared
fragment. Those per-step contracts are not yet mechanically tied to every C
C macro in this directory and do not cover the full implemented subset. Verifier
acceptance therefore establishes safety for the generated BPF artifact but does
not by itself prove native ISA fidelity. Unsupported instructions must fail at
generation/build time rather than falling back at runtime.

The generator consumes prebuilt `.proof.o` files emitted by
`native-link --mode proof`, disassembles them, and emits labels plus simulator
instruction macros. Helper/map/rodata sites stay represented by ELF
relocations in the proof object; the generator does not parse the original
native object relocation frontend.

Literal decoded opcodes use `ARM64_SIM_RUN_KNOWN_OP3`. The generated
`arm64_sim_direct.h` copies the selected bodies from the canonical C dispatcher;
its own existing C predicates select the body, including the rejection arm.
This avoids expanding every opcode handler at every native instruction. The
owning Makefile regenerates it, and the formal check verifies that it still
matches the canonical source. The dynamic dispatcher remains the source used
by the existing semantic hosts. No instruction semantics move into Python.

The producer resolves BR/BLR to finite CFG-joined target sets and emits actual
value switches. Calls write X30; returns dispatch on the real restored operand.
CODE and outer RETURN provenance distinguish local offsets from forged scalar
return values. Any reachable unknown-PC default fails verification. The
recorded control regressions and current native-address integration work are in
`../../corpus/results/kprog_arm64_app_coverage_20261106/README.md`.

Local CODE values currently carry offsets for finite label dispatch. The
materialization macro handles stack and outer-return bases; ordinary arithmetic,
memory and helper observations of CODE values require a generic relation between
proof offsets and actual native addresses. The common kernel input ABI already
provides CODE-base input, and native-link remaps local ADR targets through its
final code layout. Their address/layout preservation bridge remains part of the
universal O1/O4 work alongside the dispatcher relation.

The shared native-link readonly-data resolver gives proof payloads and native
layout records the same checked ELF extent. Typed objects retain declared
bounds; zero-sized labels retain the section suffix from their original symbol
base. Aliases at the same section/base share an identity. The [coherent ARM
service integration](../../corpus/results/kprog_arm64_app_coverage_20261107/arm-runtime-adoption/README.md)
records the combined crate regression and QEMU generation-bound control, with
native retval2 and matching kernel-owned request identities. Its exact loader,
client, DSO and linker build inputs accompany the runtime archive.

The LSE atomic family covers LDADD/STADD, LDSET/STSET and LDCLR/STCLR,
including acquire/release suffixes and the zero-register store aliases. Each
operation captures its source and address before returning the old memory value,
updates the native byte extent, and scalarizes the written private-memory tags.
The approved incoming-SP alignment predicate applies to the shared body. The
[current component receipt](../../corpus/results/kprog_arm64_app_coverage_20261108/bitwise-lse/README.md)
records 11,520 host C-model observations and successful 32/64-bit BPF compilation.
The earlier 8/16-bit C-model observations agree and retain clang18's original
subword-atomic lowering diagnostics. The current byte path uses the typed
atomic8 kfunc in the ARM lab module; its one-byte read/write argument follows
the stock verifier memory rules, and its operation body uses native atomics.
The [byte receipt](../../corpus/results/kprog_arm64_app_coverage_20261108/byte-atomic/README.md)
records compiler and QEMU primitive results. The halfword-address alignment
predicate case remains with the operator. The complete Tetragon QEMU epoch and
the universal operation theorems retain their own result records.

## Smoke

```bash
make -C kprog/arm64 run
```

This compiles `arm64_sim_hardcoded.bpf.c` and load-tests
`arm64_sim_hardcoded_xdp`.

Current local result:

```bash
make -C kprog/arm64 build
sudo kprog/loader/target/debug/reversesim-loader \
  --object kprog/arm64/build/arm64_sim_hardcoded.bpf.o \
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

The canonical generator compacts private stack/outer-return identity payloads to
slots found by the ABI analysis. An unknown alias or copy extent keeps the full
payload layout. XDP context fields use opaque 64-bit results from typed BPF loads;
partial native reads scalarize the actual pointer bits before shifting/masking.
Other native offsets retain their accesses for verifier review. The trusted
Katran replay, 45 safety cases and canonical source/compiled-code comparisons are
recorded in [context-native](../../corpus/results/kprog_arm64_app_coverage_20261106/trusted-bcc-frame-result/context-native/README.md).

Native ELF map dependencies accompany source-used maps through the shared
request interface. The five-step ARM transition keeps one request-owned kernel
copy, generates B through the registered service, passes B to the stock verifier,
and emits the same copy with map/helper/kfunc relocations resolved. Entry and
helper caller-clobbered state is represented in B. Stack/payload analysis supplies
storage geometry. The [ARM migration ledger](../results/kprog_design_only_20261108/README.md#aarch64-migration)
records the removal and functional keep decisions, source epochs, incremental
builds and whole-application/native-only replay receipts.

Numeric labels3/4 (ADD_IMM/SUB_IMM) select the same ALU immediate body as
label6; AUX supplies its arithmetic operation. The [shared operand/family
contracts](../../corpus/results/kprog_arm64_app_coverage_20261107/numeric-contract-sync/README.md)
record the universal alias equation, operation-specific refinement and focused
C/Lean checks. Existing label6/7 bodies retain their implementation.

The [generic fresh compiler profile](../../corpus/results/kprog_arm64_app_coverage_20261108/host-compile/README.md) retains ARM O2/BPFv4/4096-byte settings and the captured guest header sysroot. Thirteen transport/profile controls pass, including complete allocated-section and relocation identity for two accepted QEMU helper fixtures. The captured private source epoch supports subsequent whole-application memory-capacity runs.

The [canonical five-step adoption](../../corpus/results/kprog_arm64_app_coverage_20261108/canonical-adoption/README.md) represents unspecified entry/helper state through kind6, preserves the x30 return coordinate, and uses layout-only collection plus request-field decoding. Existing stack/CB byte representations and80helper identities join this source. Four UBSan stack hosts pass6,885,971cases, skb142,080cases,29micro generation/compile and the helper/frame controls pass; a fresh QEMU native control returns2. The recorded architecture-fault predicate case follows operator Notices.

## LSE atomic input

The canonical generator and local simulator encode LDADD/LDADDA/LDADDL/LDADDAL and STADD/STADDL, including byte/half mnemonic forms, as opcode0x46 with width and acquire/release fields. The body captures the address and addend before destination writeback, atomically updates memory, returns the old value, preserves the loaded provenance and clears the updated private slot tag. Existing native arithmetic, flags and private-stack byte layout keep their current representation. The implementation follows [Arm100076,D3.6](https://documentation-service.arm.com/static/6245c734b059dc5ff9a8bdab#page=888).

The [complete BCC LSE replay](../../corpus/results/kprog_arm64_app_coverage_20261108/lse-app/README.md) uses eight upstream tools, all23original application rows and the paired five-step QEMU runtime. All23service requests generate, compile, pass stock verification and install; the complete two-start workload closes successfully in b9378e020. Its phase counters record13positive and10zero program rows, with block/TCP/fsync triggers continuing toward full execution coverage. The existing29microprograms generate and compile with the added operation. Actual compiler input contains12LDADD and3LDADDAL instructions. The current default native compiler flags remain at their existing profile; the captured LSE invocation adds -march=armv8.1-a+lse. Universal O1/O2 atomic operation and memory-order contracts are tracked with V's official ASL work.

The ARM helper identity table now carries82Linux IDs, including105 strtol and163 check_mtu. Their C bodies use the public typed ABI and retain output memory effects: strtol replaces its eight-byte result on every return, and check_mtu replaces its four-byte result on nonnegative returns. Existing tag-transfer follows those writes. [Helper selftest coverage](../../corpus/results/kprog_arm64_app_coverage_20261108/kernel-selftest-helpers/README.md) retains the C/Lean contracts, typed ABI/byte/tag observations, micro batch and original kernel-source compilation.

Private numeric tag words use ordinary local C storage so clang can propagate and remove redundant tag updates. The raw native memory arena and pointer payload accesses keep their existing volatile operations. The [tag-storage receipt](../../corpus/results/kprog_arm64_app_coverage_20261108/tetragon-execve/tag-storage/README.md) records four UBSan routing hosts, the existing29+1 compile cohort and the existing34 QEMU ISA outcomes at this exact tag source.
