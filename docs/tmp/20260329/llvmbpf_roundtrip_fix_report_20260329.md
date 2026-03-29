# llvmbpf Round-Trip Fix Report (2026-03-29)

## Summary

I did not reach the requested `>20%` verifier pass rate. The final full-corpus result improved from `7/309` (`2.3%`) to `16/413` (`3.9%`), with much better host-side lift/lower coverage but still poor verifier success because the dominant remaining blocker is now map semantics, not subprog boundaries.

The key outcome of this round is that the original `last insn is not an exit or jmp` failure was correctly root-caused and eliminated:

- Baseline `last insn is not an exit or jmp`: `106`
- Fixed run `last insn is not an exit or jmp`: `0`
- Baseline `program not reported by llvmbpf build output`: `376`
- Fixed run `program not reported by llvmbpf build output`: `77`

## Root Cause: Why `last insn is not an exit or jmp` Happened

This was not a real “missing final `BPF_EXIT`” problem in the generated program tail.

I inspected failing round-trip objects such as:

- `corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o`
- `corpus/build/bcc/libbpf-tools/biosnoop.bpf.o`
- `corpus/build/bcc/libbpf-tools/filelife.bpf.o`
- `corpus/build/bcc/libbpf-tools/cpufreq.bpf.o`

The pattern was consistent:

1. The verifier reported subprog boundaries exactly at helper call instruction indices, for example `func#1 @7`, `func#2 @15`.
2. The lowered BPF at those PCs was not a real BPF-to-BPF call target. It was a helper call encoded as:

```text
85 10 00 00 ff ff ff ff   call -1
```

3. The second byte `0x10` means `src_reg = 1`, which is `BPF_PSEUDO_CALL`.
4. With `imm = -1`, the verifier interprets the instruction as a local call whose target is the call instruction itself (`pc + 1 - 1 = pc`).
5. That creates bogus subprog boundaries at every helper call site, and the previous region then appears to end without an `exit` or terminal jump.

Concrete example from `ipv4_bind_entry_roundtrip.bpf.o` before post-processing:

```text
7:  85 10 00 00 ff ff ff ff  call -0x1
15: 85 10 00 00 ff ff ff ff  call -0x1
```

The section tail already ended with a real `exit`. The verifier failure was caused by fake subprogs, not by a missing terminal instruction.

## Fixes Implemented

### 1. Helper-call post-processing

Added:

- `docs/tmp/20260329/llvmbpf_bulk_roundtrip/llvmbpf_postprocess.py`

This script:

- parses the round-trip ELF with `pyelftools`
- finds executable sections and `.rel.*` relocation sections
- rewrites `_bpf_helper_ext_XXXX` relocations into real helper calls
- clears `src_reg` from `1` to `0`
- writes the helper id into `imm`
- removes `.rel.text` when it only contains those helper relocations
- dumps the patched `.text` for raw verifier use

Example rewrite:

```text
before: 85 10 00 00 ff ff ff ff   call -1
after:  85 00 00 00 0e 00 00 00   call 14
```

Across the fixed full run:

- lowered programs: `413`
- programs with helper-call rewrites: `336`
- total helper-call rewrites: `954`

### 2. Bulk driver integration

Updated:

- `docs/tmp/20260329/llvmbpf_bulk_roundtrip/llvmbpf_bulk_roundtrip.py`

Changes:

- round-trip objects are now post-processed automatically after `llc`
- the manifest records post-processing summaries
- guest verify now passes `expected_attach_type`
- host prepare now supports `--opt-level` and `--opt-passes` for pass experiments

### 3. Verifier metadata stripping

Updated:

- `docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/src/main.rs`

The old helper reused the original program’s `func_info` and `line_info`. Once the fake subprog issue was fixed, that metadata started failing against the new instruction layout.

I replaced the verifier path with a minimal `BPF_PROG_LOAD` syscall that keeps only the necessary load metadata and drops stale `func_info`/`line_info`.

This removed:

- `Invalid line_info`: `0` in the fixed full run
- `Invalid func_info`: `0` in the fixed full run

### 4. llvmbpf CLI continue-on-failure

Updated:

- `vendor/llvmbpf/cli/main.cpp`

The CLI previously returned immediately on the first failing program in an object, which made many later programs look like `program not reported by llvmbpf build output`.

It now continues processing later programs and returns non-zero only after finishing the full object.

This changed lift behavior substantially:

- baseline lift success: `556/962`
- fixed lift success: `779/962`

## Full-Corpus Results

### Baseline vs fixed

| Metric | Baseline | Fixed |
| --- | ---: | ---: |
| Objects | 170 | 170 |
| Programs | 962 | 962 |
| Lift success | 556 / 962 (57.8%) | 779 / 962 (81.0%) |
| LLVM lower success | 309 / 556 (55.6%) | 413 / 779 (53.0%) |
| Verifier pass | 7 / 309 (2.3%) | 16 / 413 (3.9%) |
| End-to-end coverage | 7 / 962 (0.7%) | 16 / 962 (1.7%) |
| `last insn is not an exit or jmp` | 106 | 0 |
| `program not reported by llvmbpf` | 376 | 77 |

### Fixed run failure breakdown

- `program not pinned by bpftool prog loadall`: `164`
- `BPF_PROG_LOAD: Permission denied (os error 13)`: `181`
- `BPF_PROG_LOAD: Invalid argument (os error 22)`: `51`
- `BPF_PROG_LOAD: Argument list too long (os error 7)`: `1`

## Why The Pass Rate Is Still Low

After removing the bogus subprog failures, the remaining verifier errors are much more real.

The main one is loss of map semantics. Typical failing lowered programs now look like this:

```text
11: (b7) r1 = 0
12: (b7) r4 = 0
13: (85) call bpf_map_update_elem#2
R1 type=scalar expected=map_ptr
```

and:

```text
4: (b7) r1 = 0
5: (bf) r2 = r6
6: (85) call bpf_map_lookup_elem#1
R1 type=scalar expected=map_ptr
```

So the next blocker is not CFG shape. It is that the lifted/lowered code is still losing the map object operand and replacing it with zero in many helper-call sites.

This also matches the scale of the corpus:

- `map_lookup_elem` candidate sites in lifted LLVM IR: `8047`

## ELF Loadability Note

The round-trip ELF produced by `llc` is still not a libbpf-quality BPF object. A representative sample such as:

- `docs/tmp/20260329/llvmbpf_bulk_roundtrip/artifacts/corpus_build_xdp-tutorial_basic01-xdp-pass_xdp_pass_kern.bpf_d445ea01/programs/000_xdp_prog_simple/xdp_prog_simple_roundtrip.bpf.o`

contains only:

- `.text`
- `.symtab`
- `.strtab`

It does not contain the normal program section name, `license`, or BTF metadata needed for a clean `bpftool prog load{,all}` object-loading workflow. I therefore used the raw verifier path for the stable corpus measurement and treat direct `bpftool` loading of these objects as out of scope until ELF metadata synthesis is added.

## Pass-Pipeline Experiment

I tested `-O1` on a representative 120-object subset that includes:

- `bcc`
- `libbpf-bootstrap`
- `katran`
- `tracee`
- `xdp-tools`
- `xdp-tutorial`
- `KubeArmor`

Results on the same 120-object subset:

| Pipeline | Lift ok | Lower ok | Verifier ok |
| --- | ---: | ---: | ---: |
| `-O2` | 624 | 388 | 12 |
| `-O1` | 624 | 388 | 11 |

Failure signatures were unchanged:

- no `last insn` failures
- no `Invalid line_info`
- no `Invalid func_info`
- dominant failures still `map_ptr expected`

Conclusion: pass tuning is not the current bottleneck. A custom lightweight pipeline like `SCCP + SimplifyCFG + ADCE` is unlikely to change the dominant failure mode without first fixing map operand reconstruction.

## Conclusion

This round successfully fixed the verifier false-positive class that motivated the work:

- helper calls were being lowered as `BPF_PSEUDO_CALL`
- that created fake subprogs
- `last insn is not an exit or jmp` is now eliminated

It also materially improved host-side coverage by fixing llvmbpf CLI early-exit behavior:

- lift: `556 -> 779`
- lower: `309 -> 413`

But the overall verifier pass rate only improved to `16/413` (`3.9%`), far below the `>20%` target, because the dominant remaining blocker is now missing map semantics in lifted/lowered helper calls.

## Recommended Next Steps

1. Preserve map object operands through lift/lower.
   Current verifier failures overwhelmingly come from helper calls receiving `r1 = 0` instead of a map pointer.

2. Add BPF-object metadata synthesis for round-trip ELF.
   Program section names, `license`, and optional BTF/func/line info need to be rebuilt if direct `bpftool prog load` is a goal.

3. Decouple corpus verification from original `bpftool prog loadall` pinning.
   `164` lowered programs are currently blocked because the original object could not be pinned in the VM, even before round-trip verification.

4. Revisit pass tuning only after map semantics are fixed.
   `-O1` already showed that optimizer choice is not the primary issue right now.
