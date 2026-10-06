# Step 0030 — x86 two-destination MULX handler composition

Date: 2026-09-27 UTC

## Scope

Close the next item on the open x86 proof surface: the two-destination `MULX`
handler, chosen over the register-source IMUL forms because it is genuinely
unproven and distinct (implicit `RDX` left operand, 128-bit high-half
computation, two width-confined writebacks, no flag production), and because its
hard part — the radix-`2^32` ladder identity — is already proved for the AArch64
`UMULH` handler.

Target C path (read-only reference):
- `kprog/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_MULX` (line 1198),
  dispatched for `X86_OP_MULX` (0x39) at line 1750.

## Changes

- New `kprog/formal/KProgFormal/X86MulxHandler.lean`:
  - `structure X86MulxState { dst, aux, flags }`: unlike the single-destination
    arithmetic handlers, `MULX` writes two registers, so the auxiliary register
    is carried beside the destination to make the conditional second writeback
    observable.
  - `x86MulxHighLadder lhs rhs`: the C `else`-branch limb ladder (`p0..p3`,
    `mid`), as a `let` chain over 32-bit halves.
  - `x86MulxHighLadderEqUmulhAlg`: the MULX ladder equals `arm64MulUmulhAlg` up
    to the order of the two cross terms — `simp only` over both definitions then
    `ac_rfl`. `ac_rfl` is core Lean 4 and available here.
  - `x86MulxHighLadderEqHighWord`: the ladder equals
    `BitVec.setWidth 64 ((lhs.setWidth 128 * rhs.setWidth 128) >>> 64)`, by
    rewriting to `arm64MulUmulhAlg` and applying
    `arm64MulUmulhLadderEqHighWord` from `Arm64Mul.lean`.
  - `generatedX86MulxStep` / `x86MulxStepSpec` / `x86_mulx_step_refines`:
    `cases width` over the four widths; the `w32` arm splits a single
    zero-extended low-word product, every other arm takes the 64-bit ladder for
    the high half and the plain product for the low half. `x86MulxMask32EqSetWidth`
    (`bv_decide`) bridges the C mask with the spec's `setWidth 32`/`setWidth 64`.
  - `x86_mulx_preserves_flags` (`cases width <;> rfl`): the C arm writes no flag
    register, so the flag word is the identity.
  - `x86_mulx_aux_absent_preserves_aux`: the `if ((AUX) != X86_REG_NONE)` guard
    modelled as `auxPresent = false`.
  - `x86_mulx_dst_tag_scalar` / `x86_mulx_aux_tag_scalar`: both writebacks
    scalarize.
  - Four `native_decide` examples: 64-bit max×max (low `1`, high
    `0xfffffffffffffffe`), 32-bit max×max (low `1`, high `0xfffffffe`, upper
    halves cleared), an aux-absent case leaving the auxiliary register and its
    tag untouched, and a 16-bit case that pins the limb branch (the width
    discriminates only on the 32-bit form). Two example values were corrected
    from first drafts — `native_decide` caught them, the module was fixed, never
    the C arm. No `sorry` or `admit`.
- New `kprog/formal/test_x86_mulx_handler_host.c`: independent oracle whose
  two halves come from an exact 128-bit product (`__int128`), sharing no
  arithmetic with the limb ladder, against the real `KPROG_X86_WRITE_REG8/16/32/64`
  macros. 4 widths x 18 x 18 boundary vectors plus 40000 fixed-seed LCG cases,
  each swept with and without the auxiliary destination.
- Wiring: `KProgFormal.lean` import; `Makefile` check-target block;
  `README.md` MULX paragraph and TCB binding sentence; `docs/shared/implementation.md`
  open-surface bullet.

## Verification

- `lake env lean KProgFormal/X86MulxHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mulx_handler_host.c ... &&
  ./build/test_x86_mulx_handler_host` — zero warnings,
  `x86 MULX host cross-check: OK (41296 cases)`.
- Full `make -C kprog/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-mulx.log`, 145 s, **39** host cross-checks
  (was 38).
- Probe files `KProgFormal/Mulx*.lean` removed before the commit.

## Modeling notes

- **The ladder reuse is the whole increment.** `arm64MulUmulhAlg` computes
  `carry = ((lo >>> 32) + (mid1 &&& 0xffffffff) + (mid2 &&& 0xffffffff)) >>> 32`
  then `hi + (mid1 >>> 32) + (mid2 >>> 32) + carry`; the C MULX arm computes
  `mid` the same way and `high = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32)`.
  The two differ only by the order of `p1`/`p2` inside the additions, which
  `ac_rfl` discharges. This is why the MULX proof needs no `omega` and no
  nonlinear reasoning of its own: `Arm64Mul.lean`'s three-step Nat route
  (`arm64MulPq` -> `arm64MulSplitHi` -> `arm64MulCrossTerm` -> `omega`) already
  proved the arithmetic identity.
- `bv_decide` is **not** used on the 64x64->128 identity — it times out or
  stack-overflows (recorded in step 0029's probes). It is used only on the
  small `w32` mask-vs-setWidth bridge.
- `omega` cannot prove the products (`0 < a0 < 2^32`, `0 < b0 < 2^32` =>
  `a0*b0 < 2^64` fails with a spurious counterexample), confirming the earlier
  finding; the MULX proof avoids `omega` entirely.
- The 16-bit and 8-bit widths take the limb branch in C, because the width
  discriminates only on `X86_WIDTH_32`. The theorem models this exactly with
  `match width with | .w32 => ... | _ => ...`, and the 16-bit `native_decide`
  example pins the consequence: the high half comes from the ladder (there is no
  single 32-bit product to split), and the 16-bit writeback keeps only the low
  word of each half.
- The implicit `RDX` read (`X86_SIM_L_READ_REG(X86_RDX)`), the
  auxiliary-destination decode, and effective-address derivation are supplied as
  already-selected operands, keeping this a bounded step.

## Remaining open x86 surface

Register-source multiply handler composition (`X86_SIM_L_EXEC_IMUL_IMM` and the
AUX-payload `X86_SIM_L_EXEC_ALU_REG` IMUL path), then
effective-address/address-space and immediate/register-RHS selection,
objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
correspondence, compiler/native-byte correspondence, multi-step control-flow
traces, specialization preservation.

## Commit

`bd518d708` — code increment, 6 files, pushed to `origin/master`. Step report
and research log: `4eb558734`.

## Evidence pair regeneration

Committed and pushed first: `bd518d708` (code increment, 6 files), `4eb558734`
(step report + research log). The retained receipt and log were regenerated at
`4eb558734` (`make -C kprog/formal check`, exit 0): 52 generator `--check`
runs, 89 Lean module checks, 39 host cross-checks over 1,771,964 oracle cases;
log bytes 13746, sha256
`240b0fcf0ecd98fc147c3be4c655e93dfcadba4cf8357e715e01651024a72a91`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `kprog/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid). Evidence refresh
committed and pushed as `8662d7070` (4 files: receipt, log, AE guide paragraph,
CHANGELOG).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `8662d7070`: sha256
`fb1e4aefe296d083a8e149e5e567c776f61f202585a8ca71691b8925e037dcf9`,
933,758,622 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`8662d707077801f60b2837499fcf0060bef19060` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design. This closes the prior "ZIP is one docs commit stale"
follow-up: the archive now matches HEAD including the MULX increment and its
evidence refresh.
