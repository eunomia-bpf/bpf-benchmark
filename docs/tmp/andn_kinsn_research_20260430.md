# P89 ANDN kinsn research

Date: 2026-04-30

HEAD: `ddba9a58`

## Summary

Recommendation: **do not add ANDN to the first-wave/default Paper A pipeline**.

The corpus does contain `a & ~b` idioms, but not in the clean `mov tmp, b; xor tmp, -1; dst &= tmp` form that would be an easy local rewrite. Across `957` scanned `.bpf.o` files, strict no-liveness patterns are `0`. After de-duplicating the identical `corpus/build/x86_64/tracee/tracee.bpf.o` copy, there are `45` candidate sites, all requiring liveness proof because the inverted temporary is not the output register:

| source | sites | width | shape |
| --- | ---: | --- | --- |
| Tracee | 15 | 64-bit | `tmp = b; tmp ^= -1; out = a; out &= tmp` |
| Tracee | 15 | 64-bit | `tmp ^= -1; out &= tmp` |
| Cilium | 14 | 32-bit | `tmp ^= -1; out &= tmp` |
| scx | 1 | 64-bit | `tmp ^= -1; out &= tmp` |
| `corpus/bcf` | 0 | - | - |
| `runner/repos` | 0 | - | - |

`scx` is a removed app, so supported-app coverage is `44` de-duplicated sites: Tracee `30`, Cilium `14`.

## Stage 1: Existing research coverage

The user-provided path `docs/tmp/bit_ops_kinsn_research_20260329.md` does not exist in this tree. The actual file is `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md`.

That bit-ops research explicitly scopes itself to `POPCNT/CLZ/CTZ + PDEP/PEXT + SHRX/SHLX`. It does not cover `ANDN`.

`docs/tmp/p89_research_audit.md` already says the same thing: no dedicated ANDN corpus census existed before this task. The only seed observation was `docs/tmp/20260320/x86_new_optimization_opportunities_20260320.md`, which notes Tracee native-code gaps involving `sete/setne + andn`.

The plan row's fourth column was accurate before this task: it recorded the Tracee observation but said corpus-wide `a & ~b` census was missing.

## Stage 2: Corpus census

Method:

- Disassembled `.bpf.o` files with `llvm-objdump -d`.
- Parsed instructions by object, section, label, and BPF register width.
- Scanned:
  - `corpus/build`: `897` objects
  - `corpus/bcf`: `17` objects
  - `runner/repos`: `43` objects
  - total: `957` objects
- Counted these forms:
  - `tmp = b; tmp ^= -1; dst &= tmp`
  - `tmp = -1; tmp ^= b; dst &= tmp`
  - `tmp = b; tmp ^= -1; out = a; out &= tmp`
  - `out = a; tmp = b; tmp ^= -1; out &= tmp`
  - `tmp ^= -1; dst &= tmp`

Raw count before de-duplicating identical object content:

| kind | width | raw sites |
| --- | --- | ---: |
| `copy_xor_dstcopy_and` | 64-bit | 30 |
| `inplace_xor_and_other_dst` | 64-bit | 31 |
| `inplace_xor_and_other_dst` | 32-bit | 14 |
| **total** | | **75** |

`corpus/build/x86_64/tracee/tracee.bpf.o` and `corpus/build/tracee/tracee.bpf.o` have the same SHA-256, so the de-duplicated count is:

| kind | width | de-duplicated sites |
| --- | --- | ---: |
| `copy_xor_dstcopy_and` | 64-bit | 15 |
| `inplace_xor_and_other_dst` | 64-bit | 16 |
| `inplace_xor_and_other_dst` | 32-bit | 14 |
| **total** | | **45** |

Representative Tracee 4-instruction candidate:

```text
kprobe/security_file_open:LBB55_398
3959: r1 = r2
3960: r1 ^= -0x1
3961: r9 = r7
3962: r9 &= r1
```

Representative Tracee 2-instruction candidate:

```text
kprobe/security_file_open:LBB55_398
3966: r7 ^= -0x1
3967: r2 &= r7
```

Representative Cilium 32-bit candidate:

```text
tc/entry:LBB33_1131
10520: w0 ^= -0x1
10521: w4 &= w0
```

All de-duplicated candidates require liveness proof. In every candidate, the register holding `~b` is not the final output register, so replacing the sequence with `bpf_andn(out, a, b)` is only correct if the temporary/inverted register is dead after the site.

## Stage 3: ROI estimate

Using the current P89 x86 KVM corpus result:

`corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/result.json`

`workload_seconds` is `1.0`. Relevant baseline per-program run counts:

| program | candidate sites | baseline run count | avg ns/run | active upper-bound site executions |
| --- | ---: | ---: | ---: | ---: |
| `trace_security_file_open` | 6 | 17,736 | 673.79 | 106,416 |
| `trace_ret_vfs_write` | 6 | 143,338 | 34.34 | 860,028 |
| `trace_ret_vfs_writev` | 6 | 0 | n/a | 0 |
| `trace_ret_kernel_write` | 6 | 0 | n/a | 0 |
| `trace_security_mmap_file` | 6 | 911 | 687.77 | 5,466 |
| `cil_from_netdev` | 2 measured-object sites | 17,710 | 244.28 | 35,420 |

This is an optimistic upper bound of about `1.01M` candidate-site executions per second, assuming every listed program run executes every candidate site in that program. The real number is lower because these sites are inside specific local blocks, not guaranteed on every program invocation.

With the task's requested `2 cycles/site` estimate, the optimistic upper bound is about `2.0M cycles/s`, or roughly `0.07%` of one 3 GHz core. A shape-specific estimate is lower:

- Tracee 4-insn form: likely saves `2` native instructions/cycles.
- Tracee/Cilium 2-insn form: likely saves `1` native instruction/cycle.
- Shape-specific optimistic bound: about `1.5M cycles/s`, or `0.05%` of one 3 GHz core.

This is too small to justify default-pipeline implementation without per-site PGO proving that the specific local blocks are hotter than the per-program upper bound suggests.

## Stage 4: Cross-architecture and implementation complexity

Semantic kinsn:

```text
bpf_andn(dst, a, b) => dst = a & ~b
```

Architecture lowering:

- x86-64: `ANDN dst, b, a`, gated by BMI1.
- ARM64: `BIC dst, a, b`; no CPUID-style feature gate needed.

This should be one architecture-neutral semantic kinsn family, not separate x86-only and ARM64-only semantics. To cover Cilium, the implementation must also handle 32-bit ALU semantics (`w` registers zero-extend on BPF ALU32). Either use separate `bpf_andn32`/`bpf_andn64` targets or encode width in the packed payload. A 64-bit-only kinsn would miss all `14` Cilium sites.

Non-BMI1 x86 should skip the pass or not advertise the target. Emitting a hidden `not; and` native fallback would erase the ROI and hide a missing capability. The verifier/proof `instantiate_insn` path can still expand the kinsn to the original BPF sequence, as existing kinsn modules do.

Implementation work:

- Add kinsn registry / target JSON / CLI plumbing for `bpf_andn`.
- Add x86 module emitter for BMI1 `ANDN`.
- Add ARM64 module emitter for `BIC`.
- Add pass pattern matching for the local 2-insn and 4-insn forms above.
- Require `LivenessAnalysis` to prove the inverted temporary is dead after the replacement window.
- Keep the usual branch-target and subprogram replacement checks.

This is smaller than `extract` or `rotate`, but not a trivial emitter-only patch because every real site found by the census depends on liveness.

## Stage 5: Recommendation

Status: **low ROI; do not do first wave / default Paper A pass**.

Rationale:

- Strict no-liveness corpus sites: `0`.
- Supported-app de-duplicated sites: `44`.
- All real sites need liveness proof.
- Hot-path upper bound is about `1.0M` site executions/s in the current P89 result, and the true value is likely lower.
- x86 BMI1 + ARM64 BIC make the semantic kinsn clean, but the measured opportunity is too small compared with the plumbing and test burden.

If this is revisited later, implement it only as a low-priority, liveness-gated pass with both 32-bit and 64-bit support, and require per-site profile evidence before enabling it by default.
