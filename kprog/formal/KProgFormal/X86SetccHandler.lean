import KProgFormal.GeneratedX86Setcc
import KProgFormal.X86ControlFlow
import KProgFormal.X86RegLaneAux
import KProgFormal.X86RegWrite

namespace KProgFormal

abbrev X86SetccCond := GeneratedX86Cond.Cond
abbrev X86SetccLane := GeneratedX86Setcc.Lane

/-- The 64-bit register value a condition's boolean writes: one or zero. The C
handler writes the `_Bool` result of `X86_SIM_L_EVAL_CC` widened to `__u64`,
which is the same value. -/
def x86BoolValue (b : Bool) : BitVec 64 := if b then 1 else 0

/-- The raw condition-code evaluator, closed over every `BitVec 8` value. The
generated `evalRaw` composes the generated condition table with the generated
expression table and yields `false` for a code outside the accepted subset,
which is the C `KPROG_X86_EVAL_CC` default arm. -/
def generatedX86SetccRaw (flags : X86Flags) (cc : BitVec 8) : Bool :=
  GeneratedX86Setcc.evalRaw flags.cf flags.zf flags.sf flags.of cc

/-- The byte-lane table the handler consults, restated over the decoded
destination shift the AUX lane carries instead of the raw boolean. -/
def generatedX86SetccLane (dstShift : BitVec 8) : X86SetccLane :=
  GeneratedX86Setcc.lane (dstShift == 8)

/-- The generated writeback: the selected byte lane, written at 8 bits, on top
of the register write-at contract. -/
def generatedX86SetccWrite (old : X86RegValue) (value : BitVec 64)
    (dstShift : BitVec 8) : X86RegValue :=
  generatedX86RegWriteAt old value .w8
    (GeneratedX86Setcc.toRegLane (generatedX86SetccLane dstShift))

/-- The generated `_SETCC` step over one decoded condition byte and one decoded
destination-shift byte: the shape the handler proof and the memory form share.
-/
def generatedX86SetccStepAt (old : X86RegValue) (payload dstShift : BitVec 8)
    (flags : X86Flags) : X86RegValue :=
  generatedX86SetccWrite old
    (x86BoolValue (generatedX86SetccRaw flags payload)) dstShift

/-- The generated `_SETCC` step over the packed register-lane AUX word: the two
raw fields are extracted with the same decoders the C handler uses. -/
def generatedX86SetccStep (old : X86RegValue) (aux : BitVec 32)
    (flags : X86Flags) : X86RegValue :=
  generatedX86SetccStepAt old
    (BitVec.ofNat 8 (GeneratedX86RegLaneAux.payload aux).toNat)
    (BitVec.ofNat 8 (GeneratedX86RegLaneAux.dstShift aux).toNat)
    flags

/-- The condition the handler's destination byte receives, stated over the raw
register-lane AUX payload field and the architectural condition table rather
than the generated one. An unsupported raw code is false, the C default. -/
def x86SetccCondition (payload : BitVec 8) (flags : X86Flags) : Bool :=
  match GeneratedX86Setcc.condOf payload with
  | some cond => x86CondSpec flags cond
  | none => false

/-- The generated expression table agrees with the architectural condition
semantics. This is the obligation that makes the generated table a statement
rather than a restatement: `evalCond` is built from the raw `X86_CC_*` arms'
expressions and `x86CondSpec` from the `X86Cond` table, so a transposition in
either table makes this fail. -/
theorem x86_setcc_eval_cond_sound (flags : X86Flags) (cond : X86SetccCond) :
    GeneratedX86Setcc.evalCond flags.cf flags.zf flags.sf flags.of cond =
      x86CondSpec flags cond := by
  cases flags with
  | mk cf zf sf of =>
      cases cond <;> rfl

/-- Every condition the generated raw table accepts denotes exactly the
architectural condition of the same name. This lifts
`x86_setcc_eval_cond_sound` through the generated condition table, so the whole
`KPROG_X86_EVAL_CC` expression is pinned to the architectural semantics for
every accepted raw code. -/
theorem x86_setcc_raw_cond_sound (cc : BitVec 8) (flags : X86Flags)
    (cond : X86SetccCond) (h : GeneratedX86Setcc.condOf cc = some cond) :
    generatedX86SetccRaw flags cc = x86CondSpec flags cond := by
  unfold generatedX86SetccRaw GeneratedX86Setcc.evalRaw
  rw [h]
  exact x86_setcc_eval_cond_sound flags cond

/-- An unsupported raw condition code — any code outside the accepted subset —
evaluates to false, exactly as the C `KPROG_X86_EVAL_CC` default arm does. -/
theorem x86_setcc_raw_unsupported (cc : BitVec 8) (flags : X86Flags)
    (h : GeneratedX86Setcc.condOf cc = none) :
    generatedX86SetccRaw flags cc = false := by
  simp [generatedX86SetccRaw, GeneratedX86Setcc.evalRaw, h]

/-- The condition the executed matched fold's result denotes, stated over the
16-bit word the C macro's promoted comparison sees. Each accepted code maps to
the architectural condition of the same name; the no-match sentinel and every
code outside the accepted subset map to `none`. The table is deliberately
independent of the generated one: it is written from the architectural
condition names, so a transposition in the generated fold fails the refinement
below. -/
def x86MatchedCodeTable (code : BitVec 16) : Option X86SetccCond :=
  if code = 0 then some .o
  else if code = 1 then some .no
  else if code = 2 then some .b
  else if code = 3 then some .ae
  else if code = 4 then some .e
  else if code = 5 then some .ne
  else if code = 6 then some .be
  else if code = 7 then some .a
  else if code = 8 then some .s
  else if code = 9 then some .ns
  else if code = 12 then some .l
  else if code = 13 then some .ge
  else if code = 14 then some .le
  else if code = 15 then some .g
  else none

/-- The whole routed condition: the matched fold's result interpreted through
the architectural condition table, with the sentinel and any unaccepted code
false, exactly as the C `KPROG_X86_EVAL_CC` default arm yields. -/
def x86MatchedCondSpec (flags : X86Flags) (code : BitVec 16) : Bool :=
  match x86MatchedCodeTable code with
  | some cond => x86CondSpec flags cond
  | none => false

/-- The routed condition fold refines the raw condition evaluation for every
payload byte. This is the machine-checked content of the simulator's
`KPROG_X86_SETCC_COND_MATCHED` route: the generated matched fold is the
identity on the accepted subset and the sentinel elsewhere, the sentinel and
every unaccepted byte are rejected by the architectural table, and the accepted
identity is the same condition the generated raw table denotes; the sweep
covers every payload byte crossed with every flag assignment, so a transposed
arm in the generated fold, a sentinel that collided with an accepted code, or a
gap in the accepted subset all break it. -/
theorem x86_setcc_cond_matched_refines (flags : X86Flags)
    (payload : BitVec 8) :
    x86MatchedCondSpec flags
        (GeneratedX86Setcc.condMatchedCode payload) =
      generatedX86SetccRaw flags payload := by
  cases flags with
  | mk cf zf sf of => decide +kernel +revert

/-- Accepted matched codes hold on the architectural condition they name. -/
theorem x86_setcc_cond_matched_accepted :
    x86MatchedCondSpec ⟨true, false, true, false⟩ 12 = true := by
  native_decide

/-- The no-match sentinel is rejected, like the C default arm. -/
theorem x86_setcc_cond_matched_sentinel_rejected :
    x86MatchedCondSpec ⟨true, true, true, true⟩ 0xffff = false := by
  native_decide

/-- A parity code the subset drops is rejected too. -/
theorem x86_setcc_cond_matched_parity_rejected :
    x86MatchedCondSpec ⟨true, true, true, true⟩ 10 = false := by
  native_decide

/-- The lane table is an equality test, not a truthiness test: any destination
shift other than exactly 8 selects the low byte. -/
theorem x86_setcc_lane_not_eight (dstShift : BitVec 8) (h : dstShift != 8) :
    generatedX86SetccLane dstShift = .low := by
  unfold generatedX86SetccLane GeneratedX86Setcc.lane
  cases hc : (dstShift == 8) <;> simp_all [beq_iff_eq]

/-- The lane table selects the high byte exactly when the destination shift is
8, so the byte-lane decode agrees with the write helper's equality branch. -/
theorem x86_setcc_lane_high_iff (dstShift : BitVec 8) :
    generatedX86SetccLane dstShift = .high ↔ dstShift = 8 := by
  unfold generatedX86SetccLane GeneratedX86Setcc.lane
  cases hc : (dstShift == 8) <;> simp_all [beq_iff_eq]

/-- Decoding the packed register-lane AUX word yields exactly the unmasked
payload and destination-shift bytes, so the packed-word step is the same step
as the direct one. -/
theorem x86_setcc_aux_fields (payload dstShift srcShift : BitVec 32) :
    BitVec.ofNat 8 (GeneratedX86RegLaneAux.payload
        (GeneratedX86RegLaneAux.pack payload dstShift srcShift)).toNat =
      BitVec.ofNat 8 payload.toNat ∧
    BitVec.ofNat 8 (GeneratedX86RegLaneAux.dstShift
        (GeneratedX86RegLaneAux.pack payload dstShift srcShift)).toNat =
      BitVec.ofNat 8 dstShift.toNat := by
  constructor <;>
    simp [x86_reg_lane_aux_payload_roundtrip,
      x86_reg_lane_aux_dst_roundtrip] <;>
    bv_decide

/-- The same step stated over the raw register-lane AUX fields the C reads,
with the condition taken from the architectural table rather than the generated
one. -/
def x86SetccStepSpec (old : X86RegValue) (payload dstShift : BitVec 8)
    (flags : X86Flags) : X86RegValue :=
  generatedX86RegWriteAt old (x86BoolValue (x86SetccCondition payload flags))
    .w8
    (GeneratedX86Setcc.toRegLane (generatedX86SetccLane dstShift))

/-- The handler contract: the generated step refines the independent step over
the raw AUX fields. This is the composition the `_SETCC` body performs —
condition decode, lane decode, 8-bit writeback — and it inherits the register
write-at refinement rather than restating it. The raw-code-to-condition
mapping itself is swept exhaustively against `KPROG_X86_EVAL_CC` by the host
oracle; the proof here pins the generated expression table, and the
unsupported-code default, to the architectural semantics. -/
theorem x86_setcc_step_at_refines (old : X86RegValue)
    (payload dstShift : BitVec 8) (flags : X86Flags) :
    generatedX86SetccStepAt old payload dstShift flags =
      x86SetccStepSpec old payload dstShift flags := by
  unfold generatedX86SetccStepAt x86SetccStepSpec generatedX86SetccWrite
  cases h : GeneratedX86Setcc.condOf payload with
  | some cond =>
      have hs : generatedX86SetccRaw flags payload = x86CondSpec flags cond :=
        x86_setcc_raw_cond_sound payload flags cond h
      simp [x86SetccCondition, x86BoolValue, hs, h]
  | none =>
      have hs : generatedX86SetccRaw flags payload = false :=
        x86_setcc_raw_unsupported payload flags h
      simp [x86SetccCondition, x86BoolValue, hs, h]

/-- The packed-AUX form of the handler contract, the shape the `X86_OP_SETCC`
dispatch actually has. -/
theorem x86_setcc_step_refines (old : X86RegValue) (aux : BitVec 32)
    (flags : X86Flags) :
    generatedX86SetccStep old aux flags =
      x86SetccStepSpec old
        (BitVec.ofNat 8 (GeneratedX86RegLaneAux.payload aux).toNat)
        (BitVec.ofNat 8 (GeneratedX86RegLaneAux.dstShift aux).toNat)
        flags :=
  x86_setcc_step_at_refines old _ _ flags

/-- The 8-bit width is fixed by the opcode, so the writeback touches exactly one
of the destination's eight bytes: whichever lane it selects, every byte above
the low two is unchanged. -/
theorem x86_setcc_step_preserves_upper_bytes (old : X86RegValue)
    (payload dstShift : BitVec 8) (flags : X86Flags) :
    (x86SetccStepSpec old payload dstShift flags).bits &&&
        0xffffffffffff0000 =
      old.bits &&& 0xffffffffffff0000 := by
  unfold x86SetccStepSpec
  cases h : generatedX86SetccLane dstShift <;>
    cases x86SetccCondition payload flags <;>
    simp [h, x86BoolValue, GeneratedX86Setcc.toRegLane,
      x86_reg_write_at_refines, x86RegWriteAtSpec, x86RegWriteBitsAtSpec,
      x86ByteShiftSpec] <;>
    bv_decide

/-- The writeback always tags the destination as scalar, whatever the register
held before, because the byte write is a scalar register write. -/
theorem x86_setcc_step_scalarizes (old : X86RegValue)
    (payload dstShift : BitVec 8) (flags : X86Flags) :
    (x86SetccStepSpec old payload dstShift flags).tag = .scalar := by
  unfold x86SetccStepSpec
  cases h : generatedX86SetccLane dstShift <;>
    simp [h, GeneratedX86Setcc.toRegLane, x86_reg_write_at_refines,
      x86RegWriteAtSpec]

/-- With the low lane selected, the destination's low byte is exactly the
condition's boolean value and nothing else. -/
theorem x86_setcc_step_low_lane_writes_condition (old : X86RegValue)
    (payload dstShift : BitVec 8) (flags : X86Flags)
    (h : generatedX86SetccLane dstShift = .low) :
    (x86SetccStepSpec old payload dstShift flags).bits &&& 0xff =
      x86BoolValue (x86SetccCondition payload flags) &&& 0xff := by
  unfold x86SetccStepSpec
  cases x86SetccCondition payload flags <;>
    simp [h, x86BoolValue, GeneratedX86Setcc.toRegLane,
      x86_reg_write_at_refines, x86RegWriteAtSpec, x86RegWriteBitsAtSpec,
      x86ByteShiftSpec] <;>
    bv_decide

/-- With the high lane selected, the destination's second byte is exactly the
condition's boolean value; the low byte keeps its previous contents. -/
theorem x86_setcc_step_high_lane_writes_condition (old : X86RegValue)
    (payload dstShift : BitVec 8) (flags : X86Flags)
    (h : generatedX86SetccLane dstShift = .high) :
    (x86SetccStepSpec old payload dstShift flags).bits >>> 8 &&& 0xff =
        x86BoolValue (x86SetccCondition payload flags) &&& 0xff ∧
      (x86SetccStepSpec old payload dstShift flags).bits &&& 0xff =
        old.bits &&& 0xff := by
  unfold x86SetccStepSpec
  cases x86SetccCondition payload flags <;>
    simp [h, x86BoolValue, GeneratedX86Setcc.toRegLane,
      x86_reg_write_at_refines, x86RegWriteAtSpec, x86RegWriteBitsAtSpec,
      x86ByteShiftSpec] <;>
    bv_decide

/-- Byte-shift 8 and nothing else selects the high byte; the byte-shift decode
is therefore an equality, and the natural `nonzero selects high` reading is
wrong. -/
example : generatedX86SetccLane 8 = .high := by
  simp [generatedX86SetccLane, GeneratedX86Setcc.lane]

example : generatedX86SetccLane 0 = .low := by
  simp [generatedX86SetccLane, GeneratedX86Setcc.lane]

example : generatedX86SetccLane 9 = .low := by
  simp [generatedX86SetccLane, GeneratedX86Setcc.lane]

example : generatedX86SetccLane 1 = .low := by
  simp [generatedX86SetccLane, GeneratedX86Setcc.lane]

/-- The accepted subset maps each raw code to its own condition. -/
example : GeneratedX86Setcc.condOf 13 = some .ge := by
  simp [GeneratedX86Setcc.condOf]

/-- The parity codes are unsupported, and so is every code from 16 up. -/
example : GeneratedX86Setcc.condOf 10 = none := by
  simp [GeneratedX86Setcc.condOf]

example : GeneratedX86Setcc.condOf 16 = none := by
  simp [GeneratedX86Setcc.condOf]

/-- An unsupported code is a defined false, not an undefined value. -/
example : generatedX86SetccRaw ⟨false, true, false, false⟩ 10 = false := by
  simp [generatedX86SetccRaw, GeneratedX86Setcc.evalRaw,
    GeneratedX86Setcc.condOf]

/-- `SET` on `ne` writes 1 when the zero flag is clear. -/
example : generatedX86SetccRaw ⟨false, false, false, false⟩ 5 = true := by
  simp [generatedX86SetccRaw, GeneratedX86Setcc.evalRaw,
    GeneratedX86Setcc.condOf, GeneratedX86Setcc.evalCond]

/-- `SET` on `b` writes 0 when the carry flag is clear. -/
example : generatedX86SetccRaw ⟨false, true, false, false⟩ 2 = false := by
  simp [generatedX86SetccRaw, GeneratedX86Setcc.evalRaw,
    GeneratedX86Setcc.condOf, GeneratedX86Setcc.evalCond]

end KProgFormal
