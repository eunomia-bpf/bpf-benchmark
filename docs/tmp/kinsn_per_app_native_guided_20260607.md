# kinsn per-app native-guided tuning 2026-06-07

This note records two per-app configuration trials for Cilium and Katran. Both trials only edited
`runner/config/passes/kinsn/{cilium,katran}.yaml`; no LLVM selector, bpfopt gate, or benchmark
policy was changed. Runs used x86 KVM, `BPFREJIT_CORPUS_APPS="cilium/agent,katran"`,
`BPFREJIT_BENCH_PASSES=kinsn`, `SAMPLES=3`, and `WORKLOAD_DURATION=30`.

## Trial A: Cilium full bytecode, Katran no-bulk with prefetch

Artifact: `corpus/results/x86_kvm_corpus_20260607_001205_754492`

- Cilium: ok; workload `1.013x`, BPF cost `0.959x`, retained programs `2`, applied sites `4697`.
  Families: `lea=2346`, `bulk_memory=587`, `cond_select=385`, `endian_fusion=766`,
  `prefetch=611`, `extract=2`.
- Katran: ok; workload `1.003x`, BPF cost `0.966x`, retained programs `1`, applied sites `77`.
  Families: `endian_fusion=11`, `extract=1`, `lea=39`, `prefetch=6`, `rotate=20`.

This did not improve on prior x86 corpus bests for the same apps. Existing Cilium full history had
`1.114x` workload / `0.776x` BPF cost in
`corpus/results/x86_kvm_corpus_20260605_145112_835705`; Katran prior best workload was `1.052x`
in `corpus/results/x86_kvm_corpus_20260604_080246_742228`, and prior best BPF cost was `0.922x`
in `corpus/results/x86_kvm_corpus_20260605_141420_746952`.

## Trial B: explicit all LLVM selector / movbe-load path

Artifact: `corpus/results/x86_kvm_corpus_20260607_003024_382618`

- Cilium: failed naturally during post-ReJIT startup. The app payload records verifier failure for
  `cil_xdp_entry` (`load program: invalid argument`), and the VM log showed `bpfopt` segfaults.
  Only `7` `lea` sites were applied before the failure was recorded.
- Katran: ok; workload `1.036x`, BPF cost `0.958x`, retained programs `1`, applied sites `90`.
  Families: `bulk_memory=19`, `endian_fusion=11`, `extract=1`, `lea=39`, `rotate=20`.

The explicit all-selector path is not usable for Cilium and did not beat prior Katran bests.
The per-app YAML was therefore returned to the conservative pre-trial configuration:
`wide-load=disable,indexed-load=disable,movbe-load=disable` and
`bulk_memory=disable,prefetch=disable` on x86 for both Cilium and Katran.

## Native census for new bit-scan candidates

The next candidate pass was not another already-working family. I checked the
current native/codegen corpus for bit-scan style opcodes before adding any new
kinsn:

| Candidate | Native/codegen hits | Decision |
| --- | ---: | --- |
| `tzcnt`, `lzcnt`, `bsf`, `bsr` | 0 | no x86 native census evidence |
| `rbit`, `clz`, `ctz` | 0 | no arm64/native census evidence |
| `popcnt` | 14 textual hits | use existing `bpf_x86_popcntq`; selector trial only |
| `shlx`/`shrx` | native/codegen and micro bytecode hits | add x86 BMI2 variable-shift kinsns |
| `bzhi` | 26 x86 Cilium native hits | next x86 candidate; needs BPF mask-shape selector |
| `bfi`/`bfxil` | arm64 Cilium `49/19`, Katran `1/0` native hits | next arm64 candidate; needs insert/extract mask selector |

The useful `popcnt` evidence is micro plus old Tracee native assembly:
`bpfopt/testccode/tracee_tracee.bpf.x86.s` has seven `popcnt eax,eax` sites,
and `bitmap_popcount_scan` has explicit native/micro popcnt coverage. A static
`llvm-objdump` scan over Katran and Cilium `.bpf.o` objects found no SWAR
popcount constants (`0x5555...`, `0x3333...`, `0x0f0f...`, `0x0101...`), so
this selector is not expected to improve the current Cilium/Katran corpus runs.

## Retained synthetic x86 popcnt selector probe

This probe is retained as micro coverage. It is not used as Cilium/Katran app
evidence because it exercises a synthetic micro shape that the selected app
corpus objects do not contain.

I tried bytecode recovery for Clang's 64-bit SWAR popcount expansion into the
existing `bpf_x86_popcntq` kinsn target. This was not a new opcode or a global
gate change; it was a narrow selector under the existing `bitops` family. The
selector is retained because it does apply and because micro-only coverage is
still useful; the ablation only says this is not app-relevant incremental
evidence for the Cilium/Katran case study.

Artifact: `micro/results/x86_kvm_micro_20260607_024957_762600`

Command:

```sh
RUNTIMES="kernel kernel_rejit" BPFREJIT_BENCH_PASSES=kinsn \
  BENCH=bitmap_popcount_scan SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 make micro
```

Result:

| Runtime | exec_ns samples | median |
| --- | --- | ---: |
| `kernel` | `1113, 1113, 1113` | `1113` |
| `kernel_rejit` | `496, 499, 486` | `496` |

Median matched speedup is `2.24x` for this micro case. Every ReJIT sample
applied `6` sites on the hot program: `bpf_x86_popcntq=1`, `bpf_x86_leaq=3`,
and `bpf_x86_movl=2`; instruction count changed from `116` to `78`, and the
result value matched the baseline in all samples.

I then reran the same matched micro with `bitops=disable` added to the kinsn
mode:

Artifact: `micro/results/x86_kvm_micro_20260607_025910_494812`

| Runtime | exec_ns samples | median |
| --- | --- | ---: |
| `kernel` | `1114, 1112, 1112` | `1112` |
| `kernel_rejit` | `487, 485, 485` | `485` |

That run still applied `bpf_x86_popcntq=1`, `bpf_x86_leaq=3`, and
`bpf_x86_movl=2` on the hot program, so the speedup is already reachable
through the existing selector path used by this micro setup. Because
Cilium/Katran objects also lacked the SWAR shape, the bytecode popcnt selector
is documented as micro coverage rather than a Cilium/Katran app win; the code
remains enabled.

## x86 BMI2 variable-shift selector probe

The follow-up added a new x86 kinsn module and selector for register-count
`LSH/RSH` forms: `bpf_x86_shlxl`, `bpf_x86_shlxq`, `bpf_x86_shrxl`, and
`bpf_x86_shrxq`. The selector lives under the existing `bitops` bytecode
family, so this is not a new benchmark policy gate.

Focused micro artifact:
`micro/results/x86_kvm_micro_20260607_072937_370032`
(`SAMPLES=3`, `INNER_REPEAT=100000`).

| Micro case | kernel median ns | ReJIT median ns | speedup | BMI2 shift sites/sample |
| --- | ---: | ---: | ---: | ---: |
| `packet_toeplitz_rss_hash` | 257 | 209 | `1.230x` | 5 |
| `bpftrace_comm_key_fnv_hash` | 435 | 441 | `0.986x` | 4 |
| `packed_header_bitfield_decode` | 277 | 242 | `1.145x` | 4 |

The three-case geomean was `1.116x` with zero mismatches. The result proves the
new names and bytecode selector apply. It is not a pure new machine-code
capability claim because the stock kernel JIT can already emit BMI2
`shlx`/`shrx` for some variable-shift BPF operations.

Cilium/Katran smoke artifact:
`corpus/results/x86_kvm_corpus_20260607_073922_108307`
(`SAMPLES=1`, `WORKLOAD_DURATION=10`).

- Cilium: ok; applied `102` new BMI2 shift sites (`bpf_x86_shlxl=84`,
  `bpf_x86_shrxl=18`) plus the existing LEA/endian/cond-select/extract mix.
  Raw workload pps ratio was `1.110x`; this is smoke signal, not a replacement
  for the authoritative SAMPLES=3 run.
- Katran: ok; no new BMI2 shift sites. It retained the existing mix
  (`lea=39`, `rotate=20`, `endian_fusion=11`, `extract=1`). Raw workload pps
  ratio was `1.049x` in this smoke.

## x86 BZHI selector probe

The next x86 native-backed candidate was `bzhi`. Cilium native code had `26`
`bzhi` instructions, while Katran had no `bzhi` native evidence. I added
`bpf_x86_bzhil` and `bpf_x86_bzhiq` to the existing BMI2 shift module and kept
the bytecode selector under the existing `bitops` family. The selector is
intentionally narrow: it only replaces an all-ones mask shifted by a register
count and then inverted when the count is statically proven below the operand
width by an exact constant or an `AND` bound.

Cilium/Katran app smoke artifact:
`corpus/results/x86_kvm_corpus_20260607_210624_356236`

Command:

```sh
SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APPS="cilium/agent,katran" \
  BPFREJIT_BENCH_PASSES=kinsn make corpus
```

Both apps completed with `status=ok`. Cilium applied `8` real app
`bpf_x86_bzhil` sites, all in `sched_cls` programs:
`cil_to_netdev`, `tail_handle_ipv`, and `cil_to_containe*`. Katran had no
BZHI hits and retained its existing rotate/endian/extract/LEA mix.

| App | Workload ratio | retained BPF cost | BZHI sites | Total applied families |
| --- | ---: | ---: | ---: | --- |
| Cilium | `1.156x` | `0.696x` over 2 rows | 8 | `lea=1072`, `endian_fusion=305`, `cond_select=190`, `bitops=52`, `extract=2` |
| Katran | `1.028x` | `0.948x` over 1 row | 0 | `lea=39`, `rotate=20`, `endian_fusion=11`, `extract=1` |

This is a 10-second SAMPLES=1 follow-up, so it is not a replacement for the
paper SAMPLES=3 corpus. It is enough to change the BZHI status from
"native-only candidate" to "implemented and applied on a real Cilium app path."

## arm64 policy follow-up

For arm64, the useful split is micro coverage versus app policy. Full selector
coverage is good on the pure-bytecode micro suite, but the app/corpus data says
the performance policy should stay conservative.

Existing AWS arm64 corpus artifacts:

| Artifact | Policy shape | Cilium workload | Katran workload | Applied families |
| --- | --- | ---: | ---: | --- |
| `corpus/results/aws_arm64_corpus_20260605_053223_453376` | prefetch disabled only | `0.974x` | `1.020x` | endian `791`, extract `3`, rotate `20` |
| `corpus/results/aws_arm64_corpus_20260605_080836_924256` | no bulk/endian/prefetch | `0.983x` | `1.073x` | extract `4`, rotate `20` |
| `corpus/results/aws_arm64_corpus_20260605_094729_221231` | coverage-max with bulk/prefetch/endian | `0.978x` | `0.995x` | bulk `8685`, prefetch `1810`, endian `791`, extract `3`, rotate `20` |

The best current arm64 app result is therefore the conservative
no-bulk/no-endian/no-prefetch policy, with Katran at `1.073x` workload and
Cilium still below parity. The current runner YAML makes that explicit for
arm64 default/Cilium/Katran/Tracee:

```sh
--bytecode-kinsn-mode bulk_memory=disable,endian_fusion=disable,prefetch=disable
```

This is a benchmark policy choice, not a bpfopt selector gate. Full-selector
arm64 coverage remains valid for micro experiments. The current full arm64 AWS
micro artifact, `micro/results/aws_arm64_micro_20260606_001225_821028`, has
all-29 geomean `1.208x` and kinsn-bearing geomean `1.222x` over 27 cases.
Total applied names include `bpf_arm64_extr_x=387`, `bpf_arm64_ldr_w=198`,
`bpf_arm64_ubfm_x=144`, `bpf_arm64_ldrh=114`, `bpf_arm64_rev16_w=39`,
`bpf_arm64_stp_x=21`, `bpf_arm64_rev_w=15`, and `bpf_arm64_ldp_x=6`.

The same micro artifact explains why app policy should not chase maximum site
count yet: `bpftrace_comm_key_fnv_hash` regressed to `0.862x` with
`ldr_w/stp_x` sites, and `bitmap_popcount_scan` regressed to `0.966x` with
`ldr_w` sites. On real corpus apps, the high-count `bulk_memory`/load-store
families produced more applied sites but worse workload ratios.

Local QEMU smoke:
`corpus/results/arm64_qemu_corpus_19700101_000005_357787`
(`SAMPLES=1`, `WORKLOAD_DURATION=10`, Cilium/Katran).

- Cilium: ok; raw pps ratio `1.003x`; applied `1326` sites with
  `bulk_memory=959`, `endian_fusion=365`, and `extract=2`.
- Katran: ok; raw pps ratio `1.017x`; applied `62` sites with
  `bulk_memory=30`, `endian_fusion=11`, `extract=1`, and `rotate=20`.

This QEMU smoke is not evidence for the new conservative YAML. Its reports show
`kinsn_policy.pass_args=[]` and only `prefetch=false`, meaning the existing
extracted QEMU rootfs/runtime image was stale relative to the YAML edits. Keep
it as a path check only; use AWS artifacts above for arm64 performance claims.

## Native census after the arm64 policy pass

I reran a focused native-code census over the staged Cilium/Katran native
objects after the arm64 policy update:

| Scope | Objects | Native hits |
| --- | ---: | --- |
| x86 Cilium | 8 | `movbe=339`, `rol=62`, `shlx=30`, `bzhi=26`, `rorx=20`, `shrx=13` |
| x86 Katran | 9 | `rorx=60`, `movbe=22`, `rol=17` |
| arm64 Cilium | 8 | `ldr=9521`, `str=4701`, `stp=1636`, `ldp=1010`, `rev=369`, `csel=343`, `tst=298`, `cset=124`, `bfi=49`, `ror=40`, `bfxil=19`, `ccmp=11` |
| arm64 Katran | 4 | `ldr=392`, `str=257`, `stp=57`, `ldp=47`, `csel=16`, `ror=14`, `tst=11`, `rev=10`, `cset=3`, `bfi=1` |

This changes the next-candidate ordering. For x86, `bzhi` is a better new
opcode candidate than bit-scan because it appears in Cilium native code and is
now a kinsn target with micro and Cilium app coverage. For arm64, `bfi`/`bfxil`
are the only genuinely new native-backed candidates in the Cilium/Katran set;
`rbit/clz/ctz` remain unsupported by current native evidence. A native disasm
spot-check shows `bfi/bfxil` are mostly bitfield pack/unpack shapes such as
`and #0xff; bfi #8,#8; str` and repeated one-bit field copies. They need a new
arm64 module plus a strict insert-mask bytecode proof before they should be
enabled; this is not a safe per-app YAML tweak. The high-count arm64
`ldr/str/ldp/stp` families are already proven to increase site count but hurt
app performance when forced, so they should not be the next app-performance
target.
