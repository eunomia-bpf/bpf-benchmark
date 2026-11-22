import KProgFormal.ClightRefinement.X86ShiftWriteback
import KProgFormal.ClightRefinement.Arm64Registers

namespace KProgFormal.ClightRefinement.X86RegisterView

open X86ShiftWriteback

/-- Actual tagged-cell loads represent the original native GPR bank. The shared
Clight value relation binds pointers to explicit origins; x86 tag materialization
and the native register numbering come from their existing reference modules. -/
def RegistersRepresent (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (m : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu) : Prop :=
  ∀ index : Fin 16, ∃ value raw tag,
    CC.Mem.load CC.Mptr m block
      (CC.Integers.Ptrofs.unsigned (base +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) = some value ∧
    CC.Mem.load .Mint8unsigned m block
      (CC.Integers.Ptrofs.unsigned ((base +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (tag.setWidth 32)) ∧
    Arm64Registers.ValueRep addresses value raw ∧
    cpu.regs.get (X86.GPR.ofIndex index) =
      Reference.Provenance.X86.materialize origins index raw tag

/-- The concrete whole-table update represents native byte-register writeback.
Every other register retains its original pointer binding, raw word and tag. -/
theorem byte_table_native (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (before after : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (index : Fin 16) (old next : BitVec 64) (shift : BitVec 8)
    (represented : RegistersRepresent addresses origins before block base cpu)
    (selected : CC.Mem.load CC.Mptr before block
      (CC.Integers.Ptrofs.unsigned (base +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) = some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned before block
      (CC.Integers.Ptrofs.unsigned ((base +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (0#32)))
    (ordinary : index ≠ (4 : Fin 16))
    (table : ∀ other : Fin 16,
      (CC.Mem.load CC.Mptr after block
        (CC.Integers.Ptrofs.unsigned (base +
          CC.Integers.Ptrofs.repr (16 * (other.val : Int)))) =
        if other = index then some (.Vlong (if shift.setWidth 32 = (8#32) then
          X86.Value.writeHigh8 old next else X86.Value.writeView .b old next))
        else CC.Mem.load CC.Mptr before block
          (CC.Integers.Ptrofs.unsigned (base +
            CC.Integers.Ptrofs.repr (16 * (other.val : Int))))) ∧
      (CC.Mem.load .Mint8unsigned after block
        (CC.Integers.Ptrofs.unsigned ((base +
          CC.Integers.Ptrofs.repr (16 * (other.val : Int))) + 8)) =
        if other = index then some (.Vint (0#32))
        else CC.Mem.load .Mint8unsigned before block
          (CC.Integers.Ptrofs.unsigned ((base +
            CC.Integers.Ptrofs.repr (16 * (other.val : Int))) + 8)))) :
    RegistersRepresent addresses origins after block base
      (cpu.setReg .b (X86.GPR.ofIndex index) next (decide (shift.setWidth 32 = (8#32)))) := by
  have selectedNative : cpu.regs.get (X86.GPR.ofIndex index) = old := by
    obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
    have valueEq : value = .Vlong old := Option.some.inj (wordRead.symm.trans selected)
    have tagEq32 : tag.setWidth 32 = (0#32) :=
      CC.Val.Vint.inj (Option.some.inj (tagRead.symm.trans scalar))
    have tagEq : tag = (0#8) := by
      simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) tagEq32
    have rawEq : raw = old := by simpa only [valueEq, Arm64Registers.ValueRep] using valueRep
    simpa [Reference.Provenance.X86.materialize, ordinary, rawEq, tagEq] using native
  intro other
  by_cases same : other = index
  · subst other
    refine ⟨.Vlong (if shift.setWidth 32 = (8#32) then
        X86.Value.writeHigh8 old next else X86.Value.writeView .b old next),
      (if shift.setWidth 32 = (8#32) then
        X86.Value.writeHigh8 old next else X86.Value.writeView .b old next), 0, ?_, ?_, rfl, ?_⟩
    · simpa using (table index).1
    · simpa using (table index).2
    · simp [X86.Cpu.setReg, selectedNative, Reference.Provenance.X86.materialize, ordinary]
  · obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented other
    refine ⟨value, raw, tag, ?_, ?_, valueRep, ?_⟩
    · have read := (table other).1
      simp only [same, ite_false] at read
      exact read.trans wordRead
    · have read := (table other).2
      simp only [same, ite_false] at read
      exact read.trans tagRead
    · have distinct : X86.GPR.ofIndex index ≠ X86.GPR.ofIndex other := by
        intro eq
        have encoded := congrArg X86.GPR.index eq
        exact same (by simpa only [X86.GPR.index_ofIndex] using encoded.symm)
      simpa only [X86.Cpu.setReg, X86.Regs.get_set_ne _ _ _ _ distinct] using native

/-- The original Clight byte writer reaches its original continuation in169
internal steps and updates the represented native GPR bank through Cpu.setReg.
Successful source stores and the entry layout/separation premises stay explicit. -/
theorem byte_writer_native (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((BitVec.ofNat 8 index.val).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .b))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (old : BitVec 64)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong old))
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 (.Vlong old) = some after)
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (0#32)))
    (callerBlocks : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (ordinary : (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32))
    (byteMem : CC.Mem)
    (byteStored : CC.Mem.store .Mint8unsigned after localBlock
      (CC.Integers.Ptrofs.unsigned (byteOffset shift)) (.Vint (byteValue next)) = some byteMem)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (middle final : CC.Mem)
    (wordStored : CC.Mem.store CC.Mptr byteMem cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) (.Vlong ((if shift.setWidth 32 = (8#32) then X86.Value.writeHigh8 old next else X86.Value.writeView .b old next))) = some middle)
    (tagStored : CC.Mem.store .Mint8unsigned middle cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      (.Vint (0#32)) = some final)
    (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : RegistersRepresent addresses origins m cellsBlock cellsOffset cpu) :
    InternalRun ge 169 (.State function writer k e le m)
      (.State function .Sskip k e
        (tableTemps
          (byteTemps
            (classTemps
              (tagTemps
                (cellReadTemps
                  (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
                    (selectTemps le (BitVec.ofNat 8 index.val) .b))) cellsBlock cellsOffset value)
                    .b shift next) cellsBlock cellsOffset (.Vlong old))
                index cellsBlock cellsOffset (0#8)) .b) next)
          (.Vlong ((if shift.setWidth 32 = (8#32) then X86.Value.writeHigh8 old next else X86.Value.writeView .b old next))) (0#8) index cellsBlock cellsOffset) final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        (cpu.setReg .b (X86.GPR.ofIndex index) next (decide (shift.setWidth 32 = (8#32)))) := by
  have actual := byte_register_table ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word index destination width alu
    widthBlock widthBinding unshadowed shift next observedShift observedValue old cellCurrent
    localBlock after declared stored currentTag callerBlocks ordinary byteMem byteStored
    bindingSeparate middle final wordStored tagStored
  have ordinaryIndex : index ≠ (4 : Fin 16) := by
    intro same
    subst index
    exact ordinary rfl
  exact ⟨actual.1, byte_table_native addresses origins m final cellsBlock cellsOffset cpu
    index old next shift represented cellCurrent currentTag ordinaryIndex actual.2⟩

end KProgFormal.ClightRefinement.X86RegisterView
