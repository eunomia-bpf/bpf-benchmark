# Tetragon `event_execve` verifier bugs (2026-03-28)

## Scope

Target program: `event_execve`

Primary evidence source:

- `e2e/results/tetragon_20260328_214746/details/result.json`
- `rejit_result.per_program["212"]`

Observed live-program metadata from the rerun:

- `prog_id=212`
- tentative/original insn count before `const_prop` and `dce`: `2461`
- `const_prop` tentative output: `2461` insns, rejected with `unreachable insn 230`
- `dce` tentative output: `2345` insns, rejected with `R4 !read_ok`

## How I located the actual bytecode

I used the rerun artifact directly rather than the corpus ELF as the source of truth for the failing verifier cases.

- `result.json` still contains per-pass `bytecode_before` / `bytecode_after` blobs for `prog_id=212`
- those blobs match the live `GET_ORIGINAL`-style program image that per-pass verify checked

Important note:

- `corpus/build/tetragon/bpf_execve_event.bpf.o` is useful for fixture coverage, but it is not a perfect proxy for the live original here
- the live failing image contains callback subprog references encoded as `LD_IMM64 src=4` pseudo-func pointers
- the ELF fixture path does not preserve that exact live encoding, so the `dce` bug had to be diagnosed from the rerun bytecode, not just the object file

## Bug 1: `const_prop` -> `unreachable insn 230`

### Root cause

`const_prop` folded a constant-false conditional branch into a NOP, but left the now-dead target block in place.

From the live rerun bytecode around the failure:

- original `pc 218`: `if r1 == 0 goto pc+11`
- `r1` was already known constant `1`
- `const_prop` rewrote `pc 218` to `ja +0` / NOP
- that branch edge was the only predecessor of block `230..238`
- after the fold, verifier saw `insn 230` as unreachable and rejected the tentative bytecode

This was not a jump-fixup bug. The control-flow rewrite itself was semantically correct, but the pass emitted verifier-invalid intermediate code because it did not remove the newly orphaned block.

### Fix

`const_prop` now runs unreachable-block cleanup immediately after applying constant-fold replacements and branch fixups.

Effect:

- branch folds are kept
- freshly orphaned blocks are removed before per-pass verify
- `dce` still runs later for general cleanup, especially NOP stripping

## Bug 2: `dce` -> `Permission denied` / `R4 !read_ok`

### Root cause

This was a real CFG/reachability modeling bug.

The live original contains a callback-only subprog reference:

- at original `pc 1167`: `LD_IMM64 dst=2 src=4 imm=521`
- target = `1167 + 1 + 521 = 1689`
- verifier reports that as `func#1 @1689`

Current `CFG` / `dce` logic only treated `BPF_PSEUDO_CALL` as a subprog root. It ignored `LD_IMM64 src=4` callback references entirely.

That caused two bad effects:

1. the callback-only subprog at `1689` was considered orphaned and removed
2. relocation/fixup logic did not rewrite pseudo-func targets after deletion

In the failing tentative `dce` image, removing that callback-only subprog deleted exactly `116` instructions, which shifted later function entries:

- old `1805 -> 1689`
- old `1996 -> 1880`

That corrupted function entry layout and verifier later failed in a callee with:

- `frame1`
- `1689: (bf) r7 = r4`
- `R4 !read_ok`

### Fix

Added explicit pseudo-func support:

1. `insn.rs`
   - added `BPF_PSEUDO_FUNC`
   - added `is_ldimm64_pseudo_func()`
2. `analysis/cfg.rs`
   - records `LD_IMM64 src=4` targets as subprog entries / block starts
3. `passes/utils.rs`
   - reachability seeding now follows pseudo-func callback refs
   - branch/fixup helpers now rewrite pseudo-func targets after code motion or deletion
4. `test_utils.rs`
   - structural validation now checks pseudo-func targets too

## Tests added / updated

Added:

- `passes::dce::tests::dce_preserves_callback_only_subprog_and_rewrites_func_ref`
- `passes::const_prop::tests::const_prop_removes_dead_target_after_false_branch_fold`
- `passes::utils::tests::test_fixup_all_branches_rewrites_pseudo_func_target_after_growth`
- `passes::tests::test_cfg_analysis_with_callback_subprog_refs`

Updated:

- existing `const_prop` tests that previously assumed folded branches could leave dead blocks behind
- `dce` tests whose site counts changed because `const_prop` now removes those dead blocks earlier

## Validation

Executed:

- `cargo fmt --all`
- `make daemon-tests`

Result:

- `512 passed; 0 failed`

## Net result

The two verifier failures on live `event_execve` were different classes of bugs:

- `const_prop`: emitted a verifier-invalid intermediate CFG after branch folding
- `dce`: mis-modeled callback-only subprogs and failed to relocate pseudo-func references

Both are fixed in the daemon codepath now.
