# BPF kinsn LLVM backend notes

This directory contains the experimental LLVM fork/build used to emit BPF
kinsn pseudo instructions directly from the BPF backend.

## Selection model

The intended pipeline is:

1. Let LLVM canonicalize source code into standard IR/DAG/MI semantics.
2. Collect kinsn candidates from those canonical forms.
3. Check legality: target module exists, operand form is supported, local
   subprog/verifier risks are avoided, and the replacement has no overlapping
   MI range.
4. Score profitability using static cost first: loop weight, expected native
   instruction savings, kinsn bundle/proof cost, and one-time scratch init.
5. Select positive, non-overlapping candidates and lower them to kinsn pseudos.
6. Let `BPFAsmPrinter` emit `kinsn_sidecar` plus a named kfunc call. BTF id and
   module fd resolution stay outside LLVM.

The backend should prefer LLVM semantic nodes over late bytecode guessing. Late
MI peepholes are acceptable only when the semantic form survives naturally in
MI; they should not rebuild a small compiler from final BPF bytecode.

## Experiment protocol

For each optimization step:

1. Build the BPF backend:
   `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`
2. Generate micro objects with kinsn selection:
   `make -C micro/programs OUTPUT_DIR=$PWD/micro/results/llvm_kinsn_programs_<tag> KERNEL_OFFSETS_INPUT=$PWD/.cache/repo-build/host/kernel-offsets/x86_64/kernel_offsets.h BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=$PWD/llvm-backend/build-bpf-kinsn/bin/llc all`
3. Run full micro through the normal entrypoint:
   `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir micro/results/llvm_kinsn_programs_<tag>"`
4. Compare against the no-kinsn LLVM baseline:
   `micro/results/x86_kvm_micro_20260518_210242_364278/metadata.json`

## Baseline before this series

Current kinsn build:

- Objects: `micro/results/llvm_kinsn_programs_20260518_133500`
- Micro run: `micro/results/x86_kvm_micro_20260518_204755_001539/metadata.json`
- Baseline run: `micro/results/x86_kvm_micro_20260518_210242_364278/metadata.json`
- Config: `SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000 runtime=kernel`
- Correctness: 29/29 matched expected result

Summary versus no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9748 |
| summed exec delta | -94 ns |
| summed JIT byte delta | -1410 bytes |

Notable deltas:

| Benchmark | Baseline | kinsn | Ratio | JIT bytes |
|---|---:|---:|---:|---:|
| `siphash_rotate64_mixer` | 54 ns | 38 ns | 0.704 | 3529 -> 2399 |
| `flow_5tuple_rss_hash` | 13 ns | 11 ns | 0.846 | 819 -> 702 |
| `packet_toeplitz_rss_hash` | 280 ns | 252 ns | 0.900 | 989 -> 989 |
| `katran_lb_consistent_hash_select` | 17 ns | 16 ns | 0.941 | 2975 -> 2817 |
| `payload_prefix_memcmp_scan` | 106 ns | 100 ns | 0.943 | 569 -> 572 |

Selected kinsns in that object set:

| kinsn | count |
|---|---:|
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |

## Planned optimization steps

| Step | Candidate | Kernel support | Target micro |
|---|---|---|---|
| 1 | `ctpop` -> `bpf_x86_popcntq` | existing | `bitmap_popcount_scan` |
| 2 | `bswap(load)` -> `bpf_x86_movbe{16,32,64}` | existing | Toeplitz, packet field loads, Katran endian fields |
| 3 | LLVM `select` -> `cmp/test` + `bpf_x86_cmov*` | existing | policy/tree/table selection |
| 4 | `(x >> c) & mask` -> `bpf_x86_bextr` | needs module | `packed_header_bitfield_decode` |
| 5 | `x & (x - 1)` / `x & -x` -> `bpf_x86_blsr/blsi` | existing | bitmap/mask traversal |
| 6 | funnel/cross-word shift -> `bpf_x86_shld/shrd` | existing | Toeplitz, bit slicing |

## Experiment log

Entries below are appended after each optimization step runs the full micro
suite.

### Step 1: `ctpop` -> `bpf_x86_popcntq`

Implementation:

- Added `BPF_KINSN_X86_POPCNTQ` pseudo.
- `BPFISelLowering` keeps `ISD::CTPOP` legal only when
  `-bpf-enable-kinsn-select` is enabled; without the flag it keeps the original
  generic expansion path.
- `BPFAsmPrinter` lowers the pseudo to `bpf_x86_popcntq` with the module's RR
  payload schema.

Build/object checks:

- `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`: pass.
- Objects: `micro/results/llvm_kinsn_programs_popcnt_20260518_144243`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |

Micro status:

- Full `make micro` with default host setup was blocked by the current sandbox:
  `sudo: The "no new privileges" flag is set`.
- Retrying through `make micro KVM_HOST_SETUP=` kept the Makefile entrypoint but
  the VM failed before benchmark execution: `failed to setup loop device for
  /var/tmp/bpf-benchmark-docker.img`.
- Therefore this step has build/object validation but no valid full micro data
  yet. It needs an unrestricted `make micro` run before comparing performance.
