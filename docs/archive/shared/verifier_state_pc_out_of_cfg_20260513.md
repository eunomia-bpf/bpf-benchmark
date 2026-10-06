# Verifier State PC 2425 Out Of CFG Investigation

## Verdict

`pc 2425` comes from the step-14 verifier log as a `frame1` callee-entry full-state line, not from a raw `output_step14.bin` executable instruction site. The immediate failing state is `PcFullState`, so the current lifter does not apply its `InsnDeltaState` round-up rule and correctly fail-fasts. The strongest evidence points to a verifier-log PC namespace mismatch after kinsn-emitting passes: the raw bytecode still has 2456 slots, raw slot 2425 is the second word of an `LD_IMM64`, and the raw BPF-to-BPF subprog target that appears to correspond to the verifier's `2425` sequence is raw PC 2408. Adding raw second-slot sites or silently skipping/rounding `PcFullState` would attach verifier state to the wrong instruction.

## Evidence

### Final katran run failure

- Result file: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260513_072625_341335/details/apps/katran.json`
- The final run records step 14 as `noop` with `log_level=2`, `insn_count_after = 2456`, followed by step 15 `const_prop` failing while consuming `verifier_log_step14.log`.
- Error excerpt from `katran.json:1548`:

```text
step 15 failed (exit 1): timeout 6000 bpfopt --pass const_prop --input .../output_step14.bin ... --verifier-states .../verifier_log_step14.log ...
...
error: verifier state pc 2425 is not present in the control-flow graph
```

### Step-14 artifact sizes and PC range

- Workdir extracted from:
  `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260513_071002_774876/details/failure-artifacts/9.tar.gz`
- Extracted path used for inspection:
  `/tmp/bpfbench_pc_out_cfg_20260513`
- `wc -c /tmp/bpfbench_pc_out_cfg_20260513/output_step14.bin` = `19648` bytes.
- `19648 / 8 = 2456` raw BPF instruction slots, valid raw slot indexes `0..2455`.
- Therefore numeric PC `2425` is inside the raw slot range, but it is not necessarily an executable site.
- Raw executable-site scan:
  - raw slots: `2456`
  - executable first-slot sites: `2373`
  - `LD_IMM64` second slots: `83`
  - `pc2425_is_site = False`
  - `pc2425_is_second_slot = True`

Raw byte dump around the relevant area:

```text
2408  07 02 00 00 f7 c0 ad e0   # r2 += -525483785
2409  18 03 00 00 00 00 fc ff   # LD_IMM64 first slot
2410  00 00 00 00 00 00 00 00   # LD_IMM64 second slot
...
2424  18 01 00 00 80 ff ff ff   # LD_IMM64 first slot
2425  00 00 00 00 00 00 00 00   # LD_IMM64 second slot
2426  b7 36 95 01 00 00 00 00
```

### Where verifier-log PC 2425 appears

- Log file:
  `/tmp/bpfbench_pc_out_cfg_20260513/verifier_log_step14.log`
- First relevant context, lines `3620..3627`:

```text
3620  1966: (85) call pc+458
3621  R3 is not a scalar
3622  caller:
3623   R6=ctx() R7=map_value(map=stats,ks=4,vs=16) ...
3624  callee:
3625   frame1: R1=scalar(...) R2=scalar(...) R10=fp0
3626  2425: frame1: R1=scalar(...) R2=scalar(...) R10=fp0
3627  2425: (07) r2 += -525483785           ; frame1: R2=scalar(...)
```

- The `1966: call pc+458` target is `1966 + 1 + 458 = 2425`, so verifier PC 2425 is the callee-entry PC for a BPF-to-BPF subprogram in `frame1`.
- The exact failing parsed line is line `3626`, which the parser classifies as `PcFullState` because the text after `2425:` starts with `frame1:`.
- Line `3627` at the same PC is `InsnDeltaState`, but that line is not the first strict failure.
- Step-14 log contains many later repeats of both forms, for example lines `6138..6139`, `6862..6863`, and `48133..48134`.
- Step-14 log also contains `mark_precise` references to the same PC, for example lines `6214` and `6280`:

```text
6214  mark_precise: frame0: last_idx 1967 first_idx 2425 subseq_idx -1
6280  mark_precise: frame1: last_idx 1966 first_idx 1957 subseq_idx 2425
```

### Parser behavior

- Parser file: `/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/verifier_log.rs`
- `parse_log_states()` filters out `BranchDeltaState` for normal production parsing, but keeps `PcFullState` and `InsnDeltaState` (`verifier_log.rs:120..125`).
- `parse_pc_state_line()` classifies `pc: frame...` as `PcFullState` (`verifier_log.rs:240..249`), and `pc: (insn) ; frame...` as `InsnDeltaState` unless the insn text is a conditional branch (`verifier_log.rs:250..258`).
- `strip_frame_prefix()` records `frame1` as `frame = 1` (`verifier_log.rs:263..275`).
- So this is not a parser loss of the frame number: `frame1` is preserved in `VerifierInsn.frame`.
- The parser does not parse the unnumbered `callee:` frame line at `verifier_log_step14.log:3625`, because it has no PC. It does parse line `3626`.

State-like scan of step 14:

```text
parsed_state_like_lines = 29034
kind_counts = { PcFullState: 1966, InsnDeltaState: 24690, BranchDeltaState: 2378 }
bad included states against raw CFG = { PcFullState: 132, InsnDeltaState: 2958 }
first included bad non-delta =
  line 3626, pc 2425, PcFullState, raw classification second_slot
```

The first invalid `InsnDeltaState` appears earlier at line `2601`, PC `1545`, also on an `LD_IMM64` second slot; the lifter's existing `InsnDeltaState` special case masks that class. Branch-delta invalid states also appear, but production parsing drops branch deltas before lift.

### CFG lifter behavior

- Lifter file:
  `/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs`
- `pc_to_site` is built from the raw BTF/original-PC map (`bbprogram_lift.rs:398..401`).
- Each parsed verifier state is immediately mapped through `verifier_state_site()` (`bbprogram_lift.rs:403..407`).
- Strict bail applies to every missing PC except `InsnDeltaState` (`bbprogram_lift.rs:417..435`):

```text
if state.kind != VerifierInsnKind::InsnDeltaState {
    bail!("verifier state pc {} is not present in the control-flow graph", state.pc);
}
```

- Subprog collection exists and is not obviously absent: `collect_subprog_starts()` adds raw `BPF_PSEUDO_CALL` targets (`bbprogram_lift.rs:504..514`) and validates they are instruction boundaries (`bbprogram_lift.rs:520..529`).
- Raw `output_step14.bin` has BPF-to-BPF subprogram calls:

```text
pseudo_calls = [(1293, imm 1018, target 2312),
                (1296, imm 1111, target 2408),
                (1980, imm 427,  target 2408)]
pseudo_call_count = 3
```

- The raw program also has many kinsn calls after earlier kinsn passes:

```text
call_src_counts = { helper src 0: 82, kinsn src 4: 69, pseudo-call src 1: 3 }
kinsn_call_count = 69
kinsn_2312_to_2408 = 13
kinsn_2408_to_2456 = 7
```

### Raw PC space differs from verifier-log PC space

Concrete mismatches:

```text
Raw output_step14.bin:
  pc 1293: BPF_PSEUDO_CALL imm 1018 -> raw target 2312
  pc 1296: BPF_PSEUDO_CALL imm 1111 -> raw target 2408
  pc 1980: BPF_PSEUDO_CALL imm 427  -> raw target 2408

Verifier log:
  1285: (85) call pc+1004 -> verifier target 2290
  1288: (85) call pc+1136 -> verifier target 2425
  1966: (85) call pc+458  -> verifier target 2425
```

Raw and verifier disassembly also disagree at numeric PC 2425:

```text
Raw pc 2425:
  code=0x00 regs=0x00 off=0 imm=0       # LD_IMM64 second slot

Verifier pc 2425:
  2425: (07) r2 += -525483785           ; frame1: R2=scalar(...)
```

The verifier instruction at `2425` matches raw PC `2408` by opcode/immediate:

```text
Raw pc 2408:
  code=0x07 regs=0x02 off=0 imm=-525483785

Verifier pc 2425:
  2425: (07) r2 += -525483785
```

This is the main evidence that the verifier states cannot be mapped by direct numeric PC lookup after the prior kinsn-emitting steps.

### Earlier step comparison

- `verifier_log_step13.log` exists but is a log-level-1 summary only:

```text
wc -c verifier_log_step13.log = 107
step13 state_like = 0, maxpc = -1
step13 hits for 2425 = 0
```

- `verifier_log_step14.log` is the first full state log in this saved workdir:

```text
wc -c verifier_log_step14.log = 14357910
step14 state_like = 29034, maxpc = 2492
step14 hits for 2425 = 267
```

So there is no earlier full verifier-state file here that demonstrates the same failure being harmless before step 14. The new trigger is that step 14's `noop` was run at `log_level=2`, producing a full verifier-state log for bytecode that already contains prior kinsn-pass output.

## Root cause hypothesis

1. **High confidence: verifier-log PCs are not in raw `output_step14.bin` PC space after kinsn-bearing bytecode.** Evidence: raw BPF pseudo calls are at `1293`, `1296`, `1980`, while the verifier logs the analogous calls at `1285`, `1288`, `1966`; raw PC `2425` is an `LD_IMM64` second slot, while verifier PC `2425` is an executable `frame1` instruction; raw PC `2408` has the same `r2 += -525483785` instruction shown by verifier PC `2425`. Direct `pc_to_site.get(state.pc)` is therefore using the wrong namespace.

2. **Medium confidence: the parser is structurally preserving the important data, but the lifter ignores enough of it to fail.** The parser records `frame = 1` for `2425: frame1: ...`, but `lift_verifier_states_by_site()` maps only by `state.pc`; it does not use `(frame, verifier_pc)` or any verifier-PC to raw-PC remap. This is not exactly "frame1 PC parsed as main-frame PC"; it is "frame1 PC preserved, then site mapping treats the numeric PC as a raw original PC."

3. **Low confidence as root cause: missing subprog CFG coverage.** The raw program definitely has subprogs and the lifter has explicit pseudo-call target discovery. The problem is not that raw subprog instructions are absent from the CFG; raw PC `2408` is a real instruction site. The problem is that verifier PC `2425` is looked up as raw PC `2425`, which is the wrong raw slot.

4. **Rejected fix direction: adding second slots to `pc_to_site`.** That would make raw PC `2425` map to something, but it would map the verifier state for `r2 += -525483785` to the second word of a raw `LD_IMM64` at PC `2424`, which is semantically wrong.

## Suggested fix dimensions

- **Keep fail-fast strictness for non-delta states.** The current bail is useful: it exposed that the verifier-state input cannot be trusted under direct raw-PC lookup. A silent skip would hide lost verifier information; a broad round-up for `PcFullState` would attach the state to raw PC `2426`, which is still wrong for this artifact.

- **Add an explicit verifier-PC to raw-site remapping layer before lifting states.** Conceptually this should map verifier log PCs in each frame to raw `InsnSite`s in the same frame. It must account for `LD_IMM64` second slots and for kinsn call encodings whose verifier-log PC stream differs from raw bytecode. The input validation should fail if a retained verifier state cannot be mapped exactly.

- **Use frame-aware mapping.** The parser already records `VerifierInsn.frame`; the lifter should not reduce all verifier states to a single global `pc_to_site` lookup. A safe design would map by `(frame, verifier_pc)` to the corresponding raw `InsnSite`, using the raw subprog frame map plus a verified per-frame PC translation.

- **Do not treat all verifier state kinds the same without confirming semantics.** `PcFullState` lines such as `2425: frame1: ...` are full states at a verifier PC, while `InsnDeltaState` lines such as `2425: (07) ... ; frame1: ...` are post-instruction deltas. The current `InsnDeltaState` second-slot round-up exists for a narrower case; extending it to `PcFullState` would be unsupported by this artifact.

- **Improve diagnostics.** The fail-fast message should include at least verifier-log line number, `kind`, `frame`, raw program length, and whether the numeric PC is a raw second slot or past raw length. The current message has only the numeric PC, which made it look like a missing CFG node rather than a PC-namespace mismatch.

- **Parser improvements are secondary.** The parser should continue preserving `frame[N]`; it may also need to retain the original verifier-log line number and instruction text so a remapper can validate that the mapped raw instruction matches the verifier line. The parser should not silently drop `caller:` / `callee:` regions unless the mapping layer can prove the numbered state lines are handled.

## What other passes likely also hit this

The pass registry marks these passes as verifier-state consumers:

```text
map_inline      needs_verifier_states = true
const_prop      needs_verifier_states = true
bulk_memory     needs_verifier_states = true
```

Source: `/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/mod.rs:72..80`.

Any of those passes can hit the same failure when their `--verifier-states` input comes from a full `log_level=2` verifier log for bytecode whose verifier PC stream no longer matches raw `bpfopt` bytecode PCs. In the observed pipeline, `const_prop` is the first such pass after the second `noop` emits the full step-14 verifier-state log, so it surfaces the bug first.
