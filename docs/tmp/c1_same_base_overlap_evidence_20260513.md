# C1 same-base overlap evidence (2026-05-13)

## Verdict
(a) theoretical only: the committed `testbin` corpus has no same-base overlapping byte-ladder memcpy candidate, so the C1 guard has no corpus-backed hit and is safe to delete on this evidence.

## Statistics
- Total byte-ladder memcpy candidates detected: 107
- SAME-base candidates: 3 (2.8%)
- SAME-base + overlap: 0 (0.0% of all candidates; 0.0% of same-base candidates)
- SAME-base + overlap + dangerous direction (dst > src): 0

Supplementary scan of committed `testobject/*.o`: 36 objects, 100 executable sections, 0 candidates, 0 same-base candidates, 0 same-base overlap, 0 dangerous. Note: an untracked workspace object `bpfopt/testobject/tracee_tracee.bpf.o` was present but is not part of the committed corpus, so it is not included in this committed-object statistic.

Source grep in `bpfopt/testccode/`: `__builtin_memmove` / `memmove(`: 0 occurrences. `__builtin_memcpy`: 24 occurrences in 5 files. Plain `memcpy(`: 14 occurrences in 8 files. Inline asm spellings: 45 occurrences in 11 files.

## Method
The scanner decoded every `bpfopt/testbin/*/*/canonicalize_output.bin` as raw little-endian `struct bpf_insn[]` and matched the same local memcpy lane shape as `try_match_memcpy_run_at`:

- `LDX_MEM` of width B/H/W/DW into a temp register
- immediately followed by `STX_MEM` of the same width from that temp
- temp register distinct from source and destination base registers
- following lanes must keep width/source base/destination base and advance source and destination offsets by the lane width
- only runs whose `uniform_chunk_sizes(raw_bytes)` is non-empty are counted, matching the pass's minimum 32-byte bulk threshold

The scan split programs at basic-block boundaries so a run could not be counted across a branch target or terminator. It intentionally did not apply the pass's later live-out skip because the C1 overlap guard is evaluated before liveness and the audit question is about the existence of the same-base overlap shape.

## Concrete examples

### SAME-base + overlap
None found.

### SAME-base, non-overlap

1. `tracee_monitor`, `635_trace_mmap_alert`, PC 3475
   - source: `r10 -152`, destination: `r10 -264`, consumed length: 56 bytes
   - ranges: source `[-152, -96)`, destination `[-264, -208)`, overlap: no
   - direction: `dst < src`, not dangerous
   - likely source-level cause: C struct assignment `file_info = get_file_info(file);` in `bpfopt/testccode/tracee_tracee.bpf.c:3593`, not `__builtin_memcpy`, `__builtin_memmove`, or inline asm.

```text
3475: ldxdw r2, [r10 -152]
3476: stxdw [r10 -264], r2
3477: ldxdw r2, [r10 -144]
3478: stxdw [r10 -256], r2
3479: ldxdw r2, [r10 -136]
3480: stxdw [r10 -248], r2
3481: ldxdw r2, [r10 -128]
3482: stxdw [r10 -240], r2
3483: ldxdw r2, [r10 -120]
3484: stxdw [r10 -232], r2
3485: ldxdw r2, [r10 -112]
3486: stxdw [r10 -224], r2
3487: ldxdw r2, [r10 -104]
3488: stxdw [r10 -216], r2
```

2. `tracee_monitor`, `639_trace_security_file_mprotect`, PC 3436
   - source: `r10 -72`, destination: `r10 -296`, consumed length: 56 bytes
   - ranges: source `[-72, -16)`, destination `[-296, -240)`, overlap: no
   - direction: `dst < src`, not dangerous
   - likely source-level cause: C struct assignment `file_info = get_file_info(file);` in `bpfopt/testccode/tracee_tracee.bpf.c:3740`, not `__builtin_memcpy`, `__builtin_memmove`, or inline asm.

```text
3436: ldxdw r2, [r10 -72]
3437: stxdw [r10 -296], r2
3438: ldxdw r2, [r10 -64]
3439: stxdw [r10 -288], r2
3440: ldxdw r2, [r10 -56]
3441: stxdw [r10 -280], r2
3442: ldxdw r2, [r10 -48]
3443: stxdw [r10 -272], r2
3444: ldxdw r2, [r10 -40]
3445: stxdw [r10 -264], r2
3446: ldxdw r2, [r10 -32]
3447: stxdw [r10 -256], r2
3448: ldxdw r2, [r10 -24]
3449: stxdw [r10 -248], r2
```

3. `tracee_monitor`, `639_trace_security_file_mprotect`, PC 6731
   - source: `r10 -72`, destination: `r10 -296`, consumed length: 56 bytes
   - ranges: source `[-72, -16)`, destination `[-296, -240)`, overlap: no
   - direction: `dst < src`, not dangerous
   - likely source-level cause: second C struct assignment `file_info = get_file_info(file);` in `bpfopt/testccode/tracee_tracee.bpf.c:3765`, not `__builtin_memcpy`, `__builtin_memmove`, or inline asm.

```text
6731: ldxdw r2, [r10 -72]
6732: stxdw [r10 -296], r2
6733: ldxdw r2, [r10 -64]
6734: stxdw [r10 -288], r2
6735: ldxdw r2, [r10 -56]
6736: stxdw [r10 -280], r2
6737: ldxdw r2, [r10 -48]
6738: stxdw [r10 -272], r2
6739: ldxdw r2, [r10 -40]
6740: stxdw [r10 -264], r2
6741: ldxdw r2, [r10 -32]
6742: stxdw [r10 -256], r2
6743: ldxdw r2, [r10 -24]
6744: stxdw [r10 -248], r2
```

### CROSS-base examples

1. `tetragon_observer`, `237_event_wake_up_new_task`, PC 337
   - source: `r1 +104`, destination: `r8 +104`, consumed length: 768 bytes
   - classification: cross-base, static alias not decidable from register numbers

```text
337: ldxdw r2, [r1 +104]
338: stxdw [r8 +104], r2
339: ldxdw r2, [r1 +112]
340: stxdw [r8 +112], r2
341: ldxdw r2, [r1 +120]
342: stxdw [r8 +120], r2
343: ldxdw r2, [r1 +128]
344: stxdw [r8 +128], r2
345: ldxdw r2, [r1 +136]
346: stxdw [r8 +136], r2
```

2. `tracee_monitor`, `551_trace_sys_enter`, PC 746
   - source: `r0 +16`, destination: `r7 +32240`, consumed length: 48 bytes
   - classification: cross-base, static alias not decidable from register numbers

```text
746: ldxdw r1, [r0 +16]
747: stxdw [r7 +32240], r1
748: ldxdw r1, [r0 +24]
749: stxdw [r7 +32248], r1
750: ldxdw r1, [r0 +32]
751: stxdw [r7 +32256], r1
752: ldxdw r1, [r0 +40]
753: stxdw [r7 +32264], r1
754: ldxdw r1, [r0 +48]
755: stxdw [r7 +32272], r1
756: ldxdw r1, [r0 +56]
757: stxdw [r7 +32280], r1
```

## Recommendation
Delete the C1 same-base overlap guard if the project decision is based on committed corpus evidence. There is no actual same-base overlap byte-ladder in `testbin` or committed `testobject`; the only same-base candidates found in the committed corpus are non-overlapping stack-to-stack struct copies in `testbin`.

This does not prove same-base overlap is semantically impossible in hand-written future BPF. It only says the current committed corpus provides no concrete case requiring the guard.
