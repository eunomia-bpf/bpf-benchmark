# Stack-slot coalescing census

Date: 2026-05-06

HEAD: `383f2a36`

## Summary

Recommendation: **do not put stack-slot coalescing in the first wave**.

Under the requested conservative static gate, the supported runtime corpus has
`16,053` exact stack slots, but only `918` survive as scalar-only safe slots.
Those safe slots produce **0 lifetime-disjoint coalescable pairs** and therefore
`0` stack-depth bytes saved.

The root cause is not lack of stack use. Tracee, Tetragon, and Cilium have many
stack accesses, but the slots that look safe are long-lived save slots whose
linear `[first def, last use]` ranges overlap. The short-lived stack regions are
usually helper-visible buffers, address-taken map keys/values, pointer spills,
partial-overlap aggregate fields, or ranges with a load before the first visible
store in the function slice.

This does not rule out a future verifier-state-driven pass, but it does mean the
static scalar-only version is not a good Paper A first-wave candidate.

## Method

Inputs:

- Requested root scan: all `.bpf.o` under `runner/repos/` and `corpus/bcf/`.
- Supported runtime scan: canonical attached objects under
  `corpus/build/{tracee,tetragon,bpftrace,bcc,katran,cilium,opentelemetry-ebpf-profiler}`.
- The user text says "8 supported apps" but lists seven, matching the current
  supported app list in this tree. No supported Calico objects exist in
  `corpus/build`.

Tools:

- `llvm-objdump -d`: Ubuntu LLVM `18.1.3`, used for disassembly spot checks.
- `bpftool`: `v7.7.0`, libbpf `v1.7`.
- Scanner: Python 3 + `pyelftools 0.32`, decoding executable eBPF sections as
  8-byte instructions.

Static gate:

- Stack slots are exact intervals: `[fp+off, fp+off+size)`.
- Defs: `STX` and immediate `ST` to `r10 + off`.
- Uses: `LDX` from `r10 + off`.
- Live range: `[first def, last use]`; slots with `first def > last use` are
  excluded as `load_before_first_def`.
- Excluded slots:
  - no def or no use;
  - partial-overlap stack accesses;
  - stack address passed to helper or subprogram;
  - stack pointer passed with unknown helper size, conservatively marking the
    verifier-visible `[ptr, fp)` range;
  - stored value is not statically proven scalar;
  - loaded slot value is later used as a memory base.
- Coalescing model:
  - greedy coloring only among safe slots with non-overlapping live ranges;
  - singletons stay at their original offsets;
  - only multi-slot colors may reduce the physical frame;
  - unsafe/fixed slots keep their original offsets.

Parse errors: `0`.

## Scan Sets

| scan set | objects | functions | stack slots | safe slots | coalescable pairs | saved bytes |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| requested roots: `runner/repos` + `corpus/bcf` `.bpf.o` | 60 | 145 | 889 | 54 | 0 | 0 |
| supported runtime corpus | 178 | 775 | 16,053 | 918 | 0 | 0 |

The requested roots contain some safe slots, but no two safe slots in the same
function have disjoint valid live ranges.

## Per-App Census

`total objects` includes `.bpf.o` and Tetragon `.o` eBPF objects.

| app | total objects | functions | total stack slots | scalar-only safe slots | coalescable slot pairs | stack_depth saved (bytes) | stack_depth saved (%) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| tracee | 3 | 159 | 4,097 | 455 | 0 | 0 | 0.00 |
| tetragon | 94 | 202 | 6,808 | 367 | 0 | 0 | 0.00 |
| bpftrace | 9 | 9 | 2 | 0 | 0 | 0 | 0.00 |
| bcc | 57 | 366 | 1,967 | 24 | 0 | 0 | 0.00 |
| katran | 5 | 6 | 77 | 2 | 0 | 0 | 0.00 |
| cilium | 7 | 27 | 2,814 | 61 | 0 | 0 | 0.00 |
| otelcol-ebpf-profiler | 3 | 6 | 288 | 9 | 0 | 0 | 0.00 |
| **total** | **178** | **775** | **16,053** | **918** | **0** | **0** | **0.00** |

## Exclusion Counters

Counts are per exact stack slot; one slot can have multiple reasons.

| reason | supported slots |
| --- | ---: |
| `address_taken_unknown_size` | 12,297 |
| `helper_memory_arg` | 9,345 |
| `partial_overlap_access` | 9,213 |
| `no_use` | 7,337 |
| `stored_non_scalar_or_unknown` | 3,705 |
| `loaded_value_used_as_ptr_base` | 1,659 |
| `no_def` | 963 |
| `load_before_first_def` | 339 |

The dominant blockers are helper-visible stack ranges and partial-overlap
aggregate-style accesses. These are exactly the cases a static scalar-only pass
should not move without verifier stack-state facts.

## Stack-Depth Histogram

Per function, supported runtime corpus.

| stack_depth bin | before | after |
| --- | ---: | ---: |
| 0 | 124 | 124 |
| 1-32 | 206 | 206 |
| 33-64 | 83 | 83 |
| 65-128 | 87 | 87 |
| 129-256 | 195 | 195 |
| 257-512 | 80 | 80 |
| >512 | 0 | 0 |

There is no before/after movement because there are no valid multi-slot colors.

## Top Object Savings

No object has positive stack-depth savings under the strict candidate gate.

| rank | object | app | saved bytes | coalescable pairs |
| ---: | --- | --- | ---: | ---: |
| 1-20 | none | - | 0 | 0 |

## Top Function Savings

No function has positive stack-depth savings under the strict candidate gate.

| rank | object:function | saved bytes | coalescable pairs | representative slot offsets |
| ---: | --- | ---: | ---: | --- |
| 1-10 | none | 0 | 0 | - |

## Representative Near Misses

These are not candidates; they explain why the zero result is plausible.

| object:function | observed offsets | blocker |
| --- | --- | --- |
| `corpus/build/tracee/tracee.bpf.o:kretprobe/do_mmap` | safe-looking `[-296,-288)`, `[-288,-280)`, `[-280,-272)`, `[-272,-264)`, `[-264,-256)`, `[-256,-248)`, `[-248,-240)` | all safe slot live ranges overlap; adjacent `[-240,-232)` and `[-232,-224)` are pointer-like (`loaded_value_used_as_ptr_base`, `stored_non_scalar_or_unknown`) |
| `corpus/build/tracee/tracee.bpf.o:kretprobe/vfs_read` | safe-looking `[-344,-336)`, `[-336,-328)`, `[-328,-320)`, `[-320,-312)`, `[-312,-304)`, `[-304,-296)` | all safe slot live ranges overlap; `[-296,-288)` is pointer-like |
| `corpus/build/tracee/tracee.bpf.o:kprobe/commit_creds` | safe-looking `[-336,-328)`, `[-328,-320)`, `[-320,-312)`, `[-312,-304)` | all safe slot live ranges overlap; `[-304,-296)` is pointer-like |
| `corpus/build/tetragon/bpf_generic_lsm_core_v61.o:.text` | apparent pair `[-112,-104)` / `[-104,-96)` | excluded by final pass as `load_before_first_def`, not a valid linear live range |
| `corpus/build/cilium/bpf_lxc.bpf.o:snat_v6_needs_masquerade` | stack slots around `[-160,-152)`, `[-152,-144)`, `[-144,-136)`, `[-128,-120)`, `[-112,-104)` | dense helper-visible/partial-overlap packet and map-value state; not scalar-only movable |

## Payoff Upper Bound

Static payoff is zero:

- x86: `0` saved stack-depth bytes, so no prologue/epilogue stack-adjustment or
  instruction-cache saving is available.
- arm64: `0` saved stack-depth bytes, so no SP adjustment reduction and no
  16-byte-boundary STP/LDP pair can be removed.

I checked the existing baseline counter source used by prior P89 research:

`corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/result.json`

It contains one-second baseline run counts by runner:

| runner | baseline BPF runs |
| --- | ---: |
| tracee | 11,513,652 |
| tetragon | 7,260,591 |
| bcc | 4,837,729 |
| bpftrace | 810,019 |
| cilium | 17,710 |
| katran | 768 |
| otelcol-ebpf-profiler | 260 |

Because the static candidate count is zero, multiplying by runtime frequency
still gives `0` cycles/s and `0` ns/s saved. The result file status is `error`,
so these counters should only be treated as context; they are not needed for the
recommendation.

## Conservative Misses

The static scanner intentionally undercounts:

- Unknown helper memory size marks every exact slot in `[ptr, fp)` as
  address-taken. Real verifier metadata could narrow map key/value and helper
  buffer widths.
- Initial `r1..r5` and unknown helper returns are treated conservatively when
  stored to stack. Verifier register types could prove some of these scalar.
- Partial overlaps are rejected even when they may be scalar struct fields.
- Path-sensitive initialization is not modeled. A CFG + reaching-def analysis
  could prove some `load_before_first_def` ranges valid on all paths, but the
  linear census must reject them.
- BPF-to-BPF subprogram frame boundaries are not coalesced across functions.

## Implementation Requirements If Revisited

A real pass should be verifier-state-driven, not just disassembly-driven:

- use verifier stack slot classes to distinguish scalar spills from pointer,
  dynptr, refstate, packet, and map-value pointers;
- use helper/kfunc metadata and verifier stack bounds for exact memory-argument
  ranges;
- build CFG-aware reaching-def and live intervals per BPF function;
- keep subprogram frames separate;
- re-run verifier/ReJIT after every candidate; never move helper-visible or
  pointer-like stack state on static guesses.

## Conclusion

Status: **do not do first wave; not enough evidence for second wave yet**.

The static corpus signal is negative: `0` coalescable safe pairs and `0` saved
stack-depth bytes in the supported runtime corpus. The idea remains plausible
only as a verifier-state-driven analysis pass, but the simple scalar-only static
version should not be scheduled ahead of candidates with measured nonzero sites.
