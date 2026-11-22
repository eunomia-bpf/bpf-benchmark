import KProgFormal.ClightRefinement.X86ShiftWriteback
import KProgFormal.ClightRefinement.Arm64Registers
import KProgFormal.ClightRefinement.Deallocation

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


private theorem byte_writable_at (m : CC.Mem) (block : CC.Block)
    (offset : _root_.Int) (lower : 0 ≤ offset) (upper : offset < 8)
    (word : CC.Mem.validAccess m CC.Mptr block 0 .Writable = true) :
    CC.Mem.validAccess m .Mint8unsigned block offset .Writable = true := by
  have parts := word
  simp only [CC.Mem.validAccess, Bool.and_eq_true] at parts
  have range : CC.Mem.rangePerm m block 0 8 .Cur .Writable = true := parts.1
  change CC.Mem.rangePerm m block offset (offset + 1) .Cur .Writable &&
    (offset % 1 == 0) = true
  rw [Bool.and_eq_true]
  refine ⟨CC.Mem.rangePerm_intro m block offset (offset + 1) .Cur .Writable
    (fun point lo hi => CC.Mem.rangePerm_perm m block 0 8 .Cur .Writable range point
      (by omega) (by omega)), ?_⟩
  simp

private theorem source_store_exists (m : CC.Mem) (chunk : CC.Chunk) (block : CC.Block)
    (offset : CC.Z) (value : CC.Val)
    (writable : CC.Mem.validAccess m chunk block offset .Writable = true) :
    ∃ after, CC.Mem.store chunk m block offset value = some after := by
  simp only [CC.Mem.store, writable, ite_true]
  exact ⟨_, rfl⟩

/-- Initial source permissions construct all four intermediate heaps of the
ordinary scalar byte writer. The native register result shares the original
permission map and allocation frontier. -/
theorem byte_writer_writable (ge : CC.CGenv)
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
    (localBlock : CC.Block)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (0#32)))
    (callerBlocks : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (ordinary : (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localWritable : CC.Mem.validAccess m CC.Mptr localBlock 0 .Writable = true)
    (cellWritable : CC.Mem.validAccess m CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess m .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) .Writable = true)
    (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : RegistersRepresent addresses origins m cellsBlock cellsOffset cpu) :
    ∃ final, InternalRun ge 169 (.State function writer k e le m)
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
        (cpu.setReg .b (X86.GPR.ofIndex index) next (decide (shift.setWidth 32 = (8#32)))) ∧
      final.access = m.access ∧ final.nextblock = m.nextblock := by
  obtain ⟨after, stored⟩ := source_store_exists m CC.Mptr localBlock 0 (.Vlong old)
    localWritable
  have localByte : CC.Mem.validAccess after .Mint8unsigned localBlock
      (CC.Integers.Ptrofs.unsigned (byteOffset shift)) .Writable = true := by
    rw [CC.Mem.validAccess_store_eq stored]
    have atZero := byte_writable_at m localBlock 0 (by omega) (by omega) localWritable
    have atOne := byte_writable_at m localBlock 1 (by omega) (by omega) localWritable
    by_cases high : shift.setWidth 32 = (8#32)
    · simpa +decide [byteOffset, high, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using atOne
    · simpa +decide [byteOffset, high, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using atZero
  obtain ⟨byteMem, byteStored⟩ := source_store_exists after .Mint8unsigned localBlock
    (CC.Integers.Ptrofs.unsigned (byteOffset shift)) (.Vint (byteValue next)) localByte
  have tableWord : CC.Mem.validAccess byteMem CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true := by
    rw [CC.Mem.validAccess_store_eq byteStored, CC.Mem.validAccess_store_eq stored]
    exact cellWritable
  obtain ⟨middle, wordStored⟩ := source_store_exists byteMem CC.Mptr cellsBlock
    (CC.Integers.Ptrofs.unsigned (cellsOffset +
      CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
    (.Vlong (if shift.setWidth 32 = (8#32) then X86.Value.writeHigh8 old next
      else X86.Value.writeView .b old next)) tableWord
  have tableTag : CC.Mem.validAccess middle .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) .Writable = true := by
    rw [CC.Mem.validAccess_store_eq wordStored, CC.Mem.validAccess_store_eq byteStored,
      CC.Mem.validAccess_store_eq stored]
    exact tagWritable
  obtain ⟨final, tagStored⟩ := source_store_exists middle .Mint8unsigned cellsBlock
    (CC.Integers.Ptrofs.unsigned ((cellsOffset +
      CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) (.Vint (0#32)) tableTag
  have actual := byte_writer_native ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word index destination width alu
    widthBlock widthBinding unshadowed shift next observedShift observedValue old cellCurrent
    localBlock after declared stored currentTag callerBlocks ordinary byteMem byteStored
    bindingSeparate middle final wordStored tagStored addresses origins cpu represented
  refine ⟨final, actual.1, actual.2, ?_, ?_⟩
  · exact (CC.Mem.store_access tagStored).trans ((CC.Mem.store_access wordStored).trans
      ((CC.Mem.store_access byteStored).trans (CC.Mem.store_access stored)))
  · exact (CC.Mem.store_nextblock tagStored).trans ((CC.Mem.store_nextblock wordStored).trans
      ((CC.Mem.store_nextblock byteStored).trans (CC.Mem.store_nextblock stored)))


/-- The imported handler allocates its actual nine typed local declarations. -/
def writerAllocation (ce : CC.CompositeEnv) (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ce CC.emptyEnv m
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars

/-- The imported eight parameters are bound in their original order. -/
def writerInitialTemps (binding op dst src flags aux imm width : CC.Val) : CC.TempEnv :=
  ((((((((CC.createUndefTemps
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_temps).set
    X86_program_profile_bpf.___x86_bind binding).set X86_program_profile_bpf._op op).set
    X86_program_profile_bpf._dst dst).set X86_program_profile_bpf._src src).set
    X86_program_profile_bpf._flags flags).set X86_program_profile_bpf._aux aux).set
    X86_program_profile_bpf._imm imm).set X86_program_profile_bpf._width width

private theorem writer_names :
    CC.listNorepet (CC.varNames
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars) ∧
    CC.listNorepet (CC.varNames
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_params) ∧
    CC.listDisjoint
      (CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_params)
      (CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_temps) := by
  decide +kernel

private theorem writer_cell_declared :
    (X86_program_profile_bpf.___x86_wr_cell__2,
      CC.Ty.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) ∈
        X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
  decide +kernel

private theorem writer_allocation_valid (ce : CC.CompositeEnv) (m : CC.Mem) :
    CC.AllocVariables ce CC.emptyEnv m
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars
      (writerAllocation ce m).1 (writerAllocation ce m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (writerAllocation ce m)).symm

/-- Actual function entry allocates the original locals and binds all eight
parameters for arbitrary caller memory and the linked composite environment. -/
theorem writer_entry (ge : CC.CGenv) (m : CC.Mem)
    (binding op dst src flags aux imm width : CC.Val) :
    CC.FunctionEntry2 ge X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      [binding, op, dst, src, flags, aux, imm, width] m
      (writerAllocation ge.genv_cenv m).1
      (writerInitialTemps binding op dst src flags aux imm width)
      (writerAllocation ge.genv_cenv m).2 :=
  .intro writer_names.1 writer_names.2.1 writer_names.2.2
    (writer_allocation_valid ge.genv_cenv m) rfl

/-- The genuine caller enters the imported handler in one internal step. -/
theorem writer_entry_internal (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (binding op dst src flags aux imm width : CC.Val) :
    InternalRun ge 1
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, dst, src, flags, aux, imm, width] k m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
        X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body k
        (writerAllocation ge.genv_cenv m).1
        (writerInitialTemps binding op dst src flags aux imm width)
        (writerAllocation ge.genv_cenv m).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _
    (writer_entry ge m binding op dst src flags aux imm width)) (.refl _)

/-- The real byte-writer union local has its declared binding, fresh block,
owned range and writable word from that same actual function allocation. -/
theorem writer_local_storage (ce : CC.CompositeEnv)
    (layout : ce.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord) (m : CC.Mem) :
    ∃ block, (writerAllocation ce m).1.get X86_program_profile_bpf.___x86_wr_cell__2 =
        some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) ∧
      m.nextblock.toNat ≤ block.toNat ∧
      block.toNat < (writerAllocation ce m).2.nextblock.toNat ∧
      CC.Mem.validAccess (writerAllocation ce m).2 CC.Mptr block 0 .Writable = true := by
  have allocation := writer_allocation_valid ce m
  obtain ⟨block, binding⟩ := allocated_local_binding allocation writer_names.1 writer_cell_declared
  obtain ⟨fresh, owned, range⟩ := (allocated_local_storage allocation).1 _ _ binding
  have size : CC.sizeof ce (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      CC.sizeChunk CC.Mptr := by
    simp only [CC.sizeof, layout]
    rfl
  have writable := CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)
  have align : (0 : Int) % CC.alignChunk CC.Mptr = 0 := by decide
  refine ⟨block, binding, fresh, owned, ?_⟩
  simpa only [CC.Mem.validAccess, size, Int.zero_add, align, beq_self_eq_true,
    Bool.and_true] using writable

/-- Reached heaps carrying the allocation's access map retain the real local
word permission; the declared binding identifies its unique allocated block. -/
theorem writer_local_writable (ce : CC.CompositeEnv)
    (layout : ce.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord) (caller memory : CC.Mem) (block : CC.Block)
    (binding : (writerAllocation ce caller).1.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (access : memory.access = (writerAllocation ce caller).2.access) :
    CC.Mem.validAccess memory CC.Mptr block 0 .Writable = true := by
  obtain ⟨allocated, actual, _, _, writable⟩ := writer_local_storage ce layout caller
  have same : allocated = block := congrArg Prod.fst (Option.some.inj (actual.symm.trans binding))
  subst allocated
  exact (CC.Mem.validAccess_congr (m1 := memory) (m2 := (writerAllocation ce caller).2)
    (chunk := CC.Mptr) (b := block) (ofs := 0) (p := .Writable)
    (fun offset => by simp only [CC.Mem.perm, access])).trans writable

end KProgFormal.ClightRefinement.X86RegisterView
