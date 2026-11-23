import KProgFormal.ClightRefinement.X86RegisterReadLanes

namespace KProgFormal.ClightRefinement.X86RegisterReadScalar

def length (size : X86.Size) : Nat := 22 + 42 + X86RegisterReadLanes.length size + 4

/-- A complete call of the actual reader for a non-RSP scalar cell with a
non-stack tag. Entry, helper, word/tag loads, lane selection and return all
execute; the original caller memory is returned unchanged. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (m : CC.Mem) (k : CC.Cont) (index : Fin 16) (width shift tag : BitVec 8)
    (size : X86.Size) (value : BitVec 64) (helperBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (notSp : index ≠ 4) (notStack : tag ≠ (4#8)) (bound : shift.toNat < 64)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value))
    (tagRead : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset)
          (X86RegisterReadValue.registerByte index) width shift) k m)
      (.Returnstate (.Vlong (X86RegisterReadLanes.result value size shift)) (CC.callCont k) m) := by
  let code := X86RegisterReadValue.registerByte index
  let initial := X86RegisterReadEntry.initialTemps (.Vptr bindingBlock bindingOffset)
    (.Vlong (code.setWidth 64)) (.Vlong (width.setWidth 64)) (.Vlong (shift.setWidth 64))
  let prepared := X86RegisterReadEntry.widthTemps
    (X86RegisterReadEntry.prefixTemps initial code width) width
  let ready := X86RegisterReadTag.tagTemps
    (X86RegisterReadValue.valueTemps prepared shift cellsBlock cellsOffset value)
      index cellsBlock cellsOffset tag
  have binding : prepared.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [prepared, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have reg : prepared.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument code) := by
    simp +decide [prepared, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, CC.PTree.gss, CC.PTree.gso]
  have shiftRead : prepared.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)) := by
    simp +decide [prepared, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have widthReady : ready.get X86_program_profile_bpf.___x86_rd_width =
      some (X86ShiftLeft.argument size) := by
    simp +decide [ready, prepared, X86RegisterReadTag.tagTemps, X86RegisterReadValue.valueTemps,
      X86RegisterReadEntry.widthTemps, CC.PTree.gss, CC.PTree.gso, effective]
  have shiftReady : ready.get X86_program_profile_bpf.___x86_rd_shift =
      some (X86Width.argument shift) := by
    simp +decide [ready, X86RegisterReadTag.tagTemps, X86RegisterReadValue.valueTemps,
      CC.PTree.gss, CC.PTree.gso]
  have wordReady : ready.get X86_program_profile_bpf.___x86_rd_value = some (.Vlong value) := by
    simp +decide [ready, X86RegisterReadTag.tagTemps, X86RegisterReadValue.valueTemps,
      CC.PTree.gss, CC.PTree.gso]
  have returned : (X86RegisterReadLanes.temps ready value size shift).get
      X86_program_profile_bpf._value = some (.Vlong (X86RegisterReadLanes.result value size shift)) := by
    simp only [X86RegisterReadLanes.temps, CC.PTree.gss]
  rw [X86RegisterReadEntry.arguments]
  exact (((X86RegisterReadEntry.from_call ge m k (.Vptr bindingBlock bindingOffset)
    code width shift helperBlock helper).trans
      (X86RegisterReadTag.from_value ge layout CC.emptyEnv prepared
        (X86RegisterReadEntry.continuation k) m index shift tag value bindingBlock cellsBlock
        bindingOffset cellsOffset notSp notStack binding reg shiftRead cells current tagRead)).trans
          (X86RegisterReadLanes.scalar ge CC.emptyEnv ready (X86RegisterReadEntry.continuation k)
            m value size shift widthReady shiftReady wordReady bound)).trans
              (X86RegisterReadEntry.finish ge m k
                (X86RegisterReadLanes.temps ready value size shift) _ returned)

/-- The complete actual scalar reader returns the external x86lean register
view, including legal high-byte reads, from the shared register relation. -/
theorem native_call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (m : CC.Mem) (k : CC.Cont) (cpu : X86.Cpu) (index : Fin 16)
    (size : X86.Size) (width : BitVec 8) (high : Bool) (value : BitVec 64)
    (helperBlock bindingBlock cellsBlock : CC.Block) (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (represented : X86RegisterView.RegistersRepresent addresses origins m cellsBlock cellsOffset cpu)
    (notSp : index ≠ 4) (legalHigh : high = true → size = .b ∧ index.val < 4)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value))
    (scalar : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (.Vint (0#32))) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset)
          (X86RegisterReadValue.registerByte index) width (if high then 8 else 0)) k m)
      (.Returnstate (.Vlong (cpu.getReg size (X86.GPR.ofIndex index) high)) (CC.callCont k) m) := by
  let shift : BitVec 8 := if high then 8 else 0
  have bound : shift.toNat < 64 := by cases high <;> decide +kernel
  have native := X86RegisterReadValue.native_word addresses origins m cellsBlock cellsOffset cpu
    represented index value notSp current scalar
  have result : X86RegisterReadLanes.result value size shift =
      cpu.getReg size (X86.GPR.ofIndex index) high := by
    rw [X86.Cpu.getReg, native]
    cases h : high with
    | false => simp [shift, h, X86RegisterReadLanes.result]
    | true =>
        have byte := (legalHigh h).1
        simp [shift, h, byte, X86RegisterReadLanes.result, X86.Value.readHigh8,
          X86.Value.trunc, X86.Size.mask]
  simpa only [result] using call ge layout m k index width shift 0 size value
    helperBlock bindingBlock cellsBlock bindingOffset cellsOffset notSp (by decide +kernel)
      bound effective helper cells current scalar

end KProgFormal.ClightRefinement.X86RegisterReadScalar
