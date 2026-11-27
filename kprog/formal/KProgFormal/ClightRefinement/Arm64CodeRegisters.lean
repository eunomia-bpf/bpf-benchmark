import KProgFormal.ClightRefinement.Arm64Registers

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CodeRegisters
/-- A source code label resolves to an actual physical instruction site.
The lookup is partial;unbound source labels do not acquire invented addresses. -/
abbrev Labels := BitVec 64 → Option (BitVec 64 × Reference.AArch64.Instruction)

def CodeAt (labels : Labels) (s : Reference.AArch64.State) (token physical : BitVec 64) : Prop :=
  ∃ instruction, labels token = some (physical,instruction) ∧
    fetch_inst physical s.machine = some instruction.encoding

theorem codeAt_unique {labels : Labels} {a b : Reference.AArch64.State} {token left right}
    (ha : CodeAt labels a token left) (hb : CodeAt labels b token right) : left = right := by
  obtain ⟨ia,la,_⟩ := ha
  obtain ⟨ib,lb,_⟩ := hb
  exact congrArg Prod.fst (Option.some.inj (la.symm.trans lb))

theorem codeAt_transport {labels : Labels} {a b : Reference.AArch64.State} {token physical}
    (program : b.machine.program = a.machine.program) (h : CodeAt labels a token physical) :
    CodeAt labels b token physical := by
  obtain ⟨instruction,label,fetched⟩ := h
  exact ⟨instruction,label,by simpa only [fetch_inst,program] using fetched⟩

/-- CODE9 uses its fetched-label observation. All other tags use the
existing canonical materialize operation,with the same distinct origins. -/
def Coordinate (labels : Labels) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (raw : BitVec 64) (tag : BitVec 8) (physical : BitVec 64) : Prop :=
  if tag = 9#8 then CodeAt labels s raw physical
  else physical = Reference.Provenance.AArch64.materialize origins raw tag

theorem coordinate_unique {labels : Labels} {origins : Reference.Provenance.AArch64.Origins}
    {a b : Reference.AArch64.State} {raw tag left right}
    (ha : Coordinate labels origins a raw tag left) (hb : Coordinate labels origins b raw tag right) : left = right := by
  unfold Coordinate at ha hb
  split at ha <;> rename_i code
  · rw [ite_eq_left code] at hb
    exact codeAt_unique ha hb
  · rw [ite_eq_right code] at hb
    exact ha.trans hb.symm

theorem coordinate_transport {labels : Labels} {origins : Reference.Provenance.AArch64.Origins}
    {a b : Reference.AArch64.State} {raw tag physical}
    (program : b.machine.program = a.machine.program)
    (h : Coordinate labels origins a raw tag physical) : Coordinate labels origins b raw tag physical := by
  unfold Coordinate at h ⊢
  split <;> rename_i code
  · rw [ite_eq_left code] at h
    exact codeAt_transport program h
  · rw [ite_eq_right code] at h
    exact h

/-- All actual31 GPR reads,SP,32 vectors and NZCV remain present. The
control-code observation is separate from canonical M3 materialization. -/
structure Represents (labels : Labels) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val) (s : Reference.AArch64.State) : Prop where
  gpr : ∀ i, ∃ value raw tag,
    Arm64EntryMemory.gpr frontier m entry (cells i) = some (value,.Vint (tag.setWidth 32)) ∧
    Arm64Registers.ValueRep addresses value raw ∧ Coordinate labels origins s raw tag (Reference.AArch64.gpr s i)
  sp : ∃ offset, Arm64EntryMemory.borrowed frontier .Mint64 m entry Arm64Program._sp = some (.Vlong offset) ∧
    Reference.AArch64.sp s = offset+origins.stack
  vectors : ∀ i, Arm64EntryMemory.vector frontier m entry i = some
    (.Vlong ((Reference.AArch64.readVector s i).setWidth 64),
     .Vlong (((Reference.AArch64.readVector s i) >>> 64).setWidth 64))
  flags : Arm64Nop.FlagsRepresent frontier m entry s

/-- Identity code coordinates project to the complete original numeric
relation without changing that published type or canonical materialize. -/
theorem numeric {labels : Labels} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {cells frontier m entry s}
    (identity : ∀ token physical instruction, labels token = some (physical,instruction) → physical = token)
    (h : Represents labels addresses origins cells frontier m entry s) :
    Arm64Registers.Represents addresses origins cells frontier m entry s := by
  refine ⟨?_,h.sp,h.vectors,h.flags⟩
  intro i
  obtain ⟨value,raw,tag,read,bits,coordinate⟩ := h.gpr i
  refine ⟨value,raw,tag,read,bits,?_⟩
  unfold Coordinate at coordinate
  split at coordinate <;> rename_i code
  · obtain ⟨instruction,label,_⟩ := coordinate
    rw [identity _ _ _ label]
    subst tag
    rfl
  · exact coordinate

theorem frame {labels : Labels} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {cells frontier before after}
    (h : FrameBelow frontier before after) (entry : CC.Val) (s : Reference.AArch64.State) :
    Represents labels addresses origins cells frontier after entry s ↔
      Represents labels addresses origins cells frontier before entry s := by
  constructor
  all_goals
    intro rep
    refine ⟨?_,?_,?_,?_⟩
    · simpa only [Arm64EntryMemory.gpr_frame h] using rep.gpr
    · simpa only [Arm64EntryMemory.borrowed_frame h] using rep.sp
    · simpa only [Arm64EntryMemory.vector_frame h] using rep.vectors
    · simpa only [Arm64Nop.flagsRepresent_frame h] using rep.flags

/-- Control-cursor motion preserves the same complete relation and fetched
instruction map. No equality between local labels and physical PCs is used. -/
theorem cursor {labels : Labels} {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {cells : Reference.AArch64.Gpr → Nat} {frontier : CC.Block}
    (m : CC.Mem) (entry : CC.Val) (s : Reference.AArch64.State) (pc : BitVec 64) :
    Represents labels addresses origins cells frontier m entry (Arm64Nop.atCursor pc s) ↔
      Represents labels addresses origins cells frontier m entry s := by
  have hg : ∀ i, Reference.AArch64.gpr (Arm64Nop.atCursor pc s) i =
      Reference.AArch64.gpr s i := by
    intro i
    simp [Reference.AArch64.gpr, Arm64Nop.atCursor, write_pc, r_of_w_different]
  have hsp : Reference.AArch64.sp (Arm64Nop.atCursor pc s) = Reference.AArch64.sp s := by
    simp [Reference.AArch64.sp, Arm64Nop.atCursor, write_pc, r_of_w_different]
  have hv : ∀ i, Reference.AArch64.readVector (Arm64Nop.atCursor pc s) i =
      Reference.AArch64.readVector s i := by
    intro i
    simp [Reference.AArch64.readVector, Arm64Nop.atCursor, write_pc, r_of_w_different]

  have program : (Arm64Nop.atCursor pc s).machine.program = s.machine.program := by
    simp [Arm64Nop.atCursor,write_pc,w,write_base_pc]
  constructor
  · intro rep
    refine ⟨?_,?_,?_,?_⟩
    · intro i
      obtain ⟨value,raw,tag,read,bits,coordinate⟩ := rep.gpr i
      refine ⟨value,raw,tag,read,bits,?_⟩
      have current : Coordinate labels origins (Arm64Nop.atCursor pc s) raw tag (Reference.AArch64.gpr s i) := by
        simpa only [hg] using coordinate
      exact coordinate_transport program.symm current
    · simpa only [hsp] using rep.sp
    · simpa only [hv] using rep.vectors
    · simpa only [Arm64Nop.flagsRepresent_cursor] using rep.flags
  · intro rep
    refine ⟨?_,?_,?_,?_⟩
    · intro i
      obtain ⟨value,raw,tag,read,bits,coordinate⟩ := rep.gpr i
      refine ⟨value,raw,tag,read,bits,?_⟩
      rw [hg]
      exact coordinate_transport program coordinate
    · simpa only [hsp] using rep.sp
    · simpa only [hv] using rep.vectors
    · simpa only [Arm64Nop.flagsRepresent_cursor] using rep.flags


/-- An actual CODE9 reader exposes the same resolved,fetched native code
site;the source token and physical address are kept as separate values. -/
theorem code_at {labels : Labels} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {cells frontier m entry s}
    (h : Represents labels addresses origins cells frontier m entry s) (i : Reference.AArch64.Gpr)
    (token : BitVec 64)
    (read : Arm64EntryMemory.gpr frontier m entry (cells i) = some (.Vlong token,.Vint (9#32))) :
    CodeAt labels s token (Reference.AArch64.gpr s i) := by
  obtain ⟨value,raw,tag,read',bits,coordinate⟩ := h.gpr i
  have same := Option.some.inj (read'.symm.trans read)
  obtain ⟨valueEq,tagEq⟩ := Prod.mk.inj same
  cases valueEq
  have tagBits := CC.Val.Vint.inj tagEq
  have tagSmall : tag = (9#8) := by
    simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) tagBits
  subst tag
  change raw = token at bits
  subst raw
  exact coordinate

end KProgFormal.ClightRefinement.Arm64CodeRegisters
