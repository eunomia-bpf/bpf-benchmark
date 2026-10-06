# Step 0035 — shared x86 memory read-dispatch (`READ_MEM_VALUE`) classification

Date: 2026-09-28 UTC

## Scope

Open the memory-load family on the x86 proof surface by proving the
value-source selection of the one read body every plain load and store form
shares: `X86_SIM_L_READ_MEM_VALUE`. Before this step the memory-touching `MOV`
forms (`MOV_LOAD`, `MOVSX_LOAD`, `MOV_LOAD_SCALAR`, `MOVBE_LOAD`, `MOVBE_STORE`,
`MOV_STORE_*`) were all blocked on an unstated read body; this step states and
proves the dispatch that selects among its three read arms, so each concrete
load form can now compose over it in a later increment.

Target C path (read-only reference):
- `kprog/x86/x86_sim_local_bpf.h` `X86_SIM_L_READ_MEM_VALUE(BASE_REG, AUX,
  IMM, WIDTH, STORE_DISP)` (638-667), whose three-arm chain is
  `(BASE_REG) == X86_RSP` → `X86_SIM_L_STACK_READ`;
  `__x86_l_base_tag == X86_SIM_TAG_ABI && __x86_l_mem_width == X86_WIDTH_64`
  → `X86_SIM_L_LOAD_PTR_ADDR`; else `X86_SIM_L_LOAD_ADDR`.
- Supporting macros: `X86_SIM_L_EFFECTIVE_WIDTH` (114-115), `X86_SIM_L_REG_TAG`
  (309-318), `X86_SIM_L_MEM_OFFSET` (411-423), `X86_SIM_L_STACK_READ` (464-496),
  `X86_SIM_L_LOAD_ADDR` (504), `X86_SIM_L_LOAD_PTR_ADDR` (506).
- Callers (14 sites): `_MOVBE_LOAD` (745) and 13 inline `X86_SIM_L_EXEC` arms
  (960, 989, 1017, 1062, 1123, 1159, 1184, 1358, 1372, 1392, 1513, 1715, 1730).

## Changes

- New `kprog/formal/generate_x86_mem_dispatch_spec.py` (54th generator),
  emitting `kprog/formal/x86_mem_dispatch_spec.json`,
  `kprog/formal/KProgFormal/GeneratedX86MemDispatch.lean` and
  `kprog/formal/generated/x86_mem_dispatch.h`. The closed table has eight
  rows over the three selector facts; the three value-source codes are
  `KPROG_X86_MEM_SRC_STACK` (0), `_ABI_PTR_LOAD` (1), `_NORMAL_LOAD` (2).
- New `kprog/formal/KProgFormal/X86MemDispatch.lean`:
  - `x86MemReadSrcSpec : Bool -> Bool -> Bool -> ValueSrc` — the independent
    statement of the dispatch, written as a predicate *nesting*
    (`if isRsp then .stackRead else if isAbi && w64 then .abiPtrLoad else
    .normalLoad`) rather than as the generated table, so the refinement is not a
    restatement of what the generator writes.
  - `x86_mem_dispatch_src_refines` — the generated table equals the predicate
    nesting for all eight combinations (`cases … <;> rfl`).
  - `x86_mem_dispatch_stack_overrides_tag` — an ABI-tagged stack pointer still
    reads through the stack helper at either width (the x86 asymmetry against
    AArch64, whose first test is a memory tag).
  - `x86_mem_dispatch_abi_requires_width64` — the ABI arm holds only at width
    64; off width 64 an ABI base falls through to the ordinary load.
  - `x86_mem_dispatch_no_tag_widening` — off width 64 the tag is irrelevant;
    only register identity moves the selection.
  - `x86_mem_dispatch_all_arms_reachable` — no dead table entry.
  No `sorry` or `admit`.
- New `kprog/formal/test_x86_mem_read_dispatch_host.c` — the independent
  oracle. Part 1 sweeps the generated `KPROG_X86_MEM_READ_SRC` over
  (2 stack-pointer identities × 5 tags × 4 widths) plus the
  override/non-widening/reachability blocks against a hand-written
  `oracle_src`. Part 2 drives the generated `KPROG_X86_MEM_OFFSET` and
  `KPROG_X86_MEM_LOAD` contracts together with the dispatch over a
  deterministic memory/register/stack model — 16 base registers × 4 tags ×
  4 widths × 7 displacements × 2 `STORE_DISP` (1,792) plus a 16-case indexed
  block — selecting the value source from the generated contract and
  cross-checking against an explicit read-body model. **3,650 cases**, zero
  warnings.
- Wiring: `import KProgFormal.GeneratedX86MemDispatch` and
  `import KProgFormal.X86MemDispatch` in `kprog/formal/KProgFormal.lean`
  (52-53); Makefile `--check` line after the last generator (58) and the
  Lean+oracle triple after the MOVX triple (151-154); README paragraph after the
  MOVX paragraph; `docs/shared/implementation.md` open-surface bullet extended.

## Design notes

- **Register identity versus tag.** The x86 selector's *first* test is register
  identity — `(BASE_REG) == X86_RSP` — while only the second test consults the
  base register's memory tag. This is stated explicitly in the generator
  docstring, the generated C header comment, the Lean doc comments and the
  oracle's header. A `Space`-shaped three-arm inductive is still the faithful
  abstraction, because `.abiPtrLoad` is only reachable when the tag is ABI *and*
  the width is 64.
- **No reloc arm, no result tag.** Unlike the AArch64 dispatch,
  `READ_MEM_VALUE` has no reloc arm and produces no tag: the ABI packet tag
  refinement (`KPROG_ABI_LOAD_TAG`) lives in `X86_SIM_L_EXEC_MOV_LOAD`
  (690-700), not here. The contract is therefore a value-source table only.
- **First arm selector is width-independent.** With `BASE_REG == X86_RSP` the
  ABI arm is unreachable because the `X86_RSP` test precedes it, exactly as the
  generated table records for the four `is_rsp = true` rows.
- **`X86_REG_NONE` falls through safely.** `X86_REG_NONE` (0xff) is not
  `X86_RSP` (4), and `X86_SIM_L_REG_TAG`'s `switch` default leaves the tag
  `X86_SIM_TAG_SCALAR`, so a `NONE` base takes the ordinary load arm — the
  abstraction is faithful without a separate `NONE` row.
- **The generated contract is not wired into the live sim.** Most x86 generated
  contracts are proof-only (audit: `used=0` for `x86_mem_offset.h`,
  `x86_bitops.h`, `x86_width.h`, …). Wiring `X86_SIM_L_READ_MEM_VALUE` is a
  separate, riskier edit; same decision as the MOVX increment.

## Verification

- `lake build` then `lake env lean KProgFormal/GeneratedX86MemDispatch.lean`
  and `lake env lean KProgFormal/X86MemDispatch.lean`: both pass.
- `python3 generate_x86_mem_dispatch_spec.py --check`: passes (no stale output).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_mem_read_dispatch_host.c
  -o build/test_x86_mem_read_dispatch_host && ./build/test_x86_mem_read_dispatch_host`
  → `x86 mem read dispatch host cross-check: OK (3650 cases)`.
- Full `make -C kprog/formal check`: RC=0, 0 `error:` lines, **54
  generators / 97 Lean module checks / 44 host cross-checks over 2,041,207
  cases**.
- Commit `7a43a5b27` (code increment, 9 files).

## Open after this step

The concrete memory-load forms composed on top of this dispatch remain open
(`_MOV_LOAD`/`_MOVSX_LOAD`/`_MOV_LOAD_SCALAR`/`_MOVBE_LOAD`/`_MOVBE_STORE`/
`_MOV_STORE_*`), and `_MOV_LOAD_MAP_PTR` must be proved separately as a
pointer-immediate write, not a memory read. The remaining x86 surface
(`_CMOV`/`_CMOV_MEM`, `_SETCC`/`_SETCC_MEM`, `_STORE_XMM0`/`_LOAD_XMM0`,
`_CALL_MEMCPY_{,REG}`/`_CALL_MEMSET_{,REG}`, `_PUSH`/`_POP`, `_REP_MOVS`,
`_ANDN{,_MEM}`, `_BZHI{,_MEM}`, `_CMP_IMM_OP`/`_CMP_REG_OP` and `_AUX`
variants), the index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
multi-step traces, and specialization preservation remain outside the theorem.
