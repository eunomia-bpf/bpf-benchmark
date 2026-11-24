import KProgFormal.ClightRefinement.X86RegisterReadRsp
import KProgFormal.ClightRefinement.X86RegisterReadLanes

namespace KProgFormal.ClightRefinement.X86RegisterReadRspCall

def length (size : X86.Size) : Nat := 55 + X86RegisterReadLanes.length size

/-- A genuine RSP reader call executes entry, the width helper, the actual
cell and native-base reads, lane selection, empty-frame release and return.
The real initial memory supplies both base loads; no tag load is assumed. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (memory : CC.Mem) (k : CC.Cont) (width shift : BitVec 8) (size : X86.Size)
    (offset nativeBase : BitVec 64) (helperBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (bound : shift.toNat < 64)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong offset))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong nativeBase)) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock 0) (4#8) width shift) k memory)
      (.Returnstate (.Vlong (X86RegisterReadLanes.result (offset + nativeBase) size shift))
        (CC.callCont k) memory) := by
  let initial := X86RegisterReadEntry.initialTemps (.Vptr bindingBlock 0)
    (.Vlong ((4#8).setWidth 64)) (.Vlong (width.setWidth 64)) (.Vlong (shift.setWidth 64))
  let prepared := X86RegisterReadEntry.widthTemps
    (X86RegisterReadEntry.prefixTemps initial (4#8) width) width
  let loaded := X86RegisterReadValue.valueTemps prepared shift cellsBlock cellsOffset offset
  let ready := X86RegisterReadRsp.temps loaded baseBlock baseOffset offset nativeBase
  have reading := X86RegisterReadValue.from_call ge layout memory k (4 : Fin 16) width shift
    helperBlock bindingBlock cellsBlock 0 cellsOffset offset helper cells current
  have binding : loaded.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [loaded, prepared, initial, X86RegisterReadValue.valueTemps,
      X86RegisterReadEntry.widthTemps, X86RegisterReadEntry.prefixTemps,
      X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have reg : loaded.get X86_program_profile_bpf.___x86_rd_reg = some (.Vint (4#32)) := by
    simp +decide [loaded, prepared, X86RegisterReadValue.valueTemps,
      X86RegisterReadEntry.widthTemps, X86RegisterReadEntry.prefixTemps, CC.PTree.gss, CC.PTree.gso]
  have raw : loaded.get X86_program_profile_bpf.___x86_rd_value = some (.Vlong offset) := by
    simp only [loaded, X86RegisterReadValue.valueTemps, CC.PTree.gss]
  have materialized := X86RegisterReadRsp.materialize_rsp ge layout.bindings valueLayout
    CC.emptyEnv loaded (X86RegisterReadEntry.continuation k) memory bindingBlock baseBlock baseOffset
    offset nativeBase binding reg raw header native
  have widthReady : ready.get X86_program_profile_bpf.___x86_rd_width =
      some (X86ShiftLeft.argument size) := by
    simp +decide [ready, loaded, prepared, X86RegisterReadRsp.temps,
      X86RegisterReadValue.valueTemps, X86RegisterReadEntry.widthTemps,
      CC.PTree.gss, CC.PTree.gso, effective]
  have shiftReady : ready.get X86_program_profile_bpf.___x86_rd_shift = some (X86Width.argument shift) := by
    simp +decide [ready, loaded, X86RegisterReadRsp.temps,
      X86RegisterReadValue.valueTemps, CC.PTree.gss, CC.PTree.gso]
  have wordReady : ready.get X86_program_profile_bpf.___x86_rd_value =
      some (.Vlong (offset + nativeBase)) := by
    simp only [ready, X86RegisterReadRsp.temps, CC.PTree.gss]
  have selected := X86RegisterReadLanes.scalar ge CC.emptyEnv ready (X86RegisterReadEntry.continuation k)
    memory (offset + nativeBase) size shift widthReady shiftReady wordReady bound
  have returned : (X86RegisterReadLanes.temps ready (offset + nativeBase) size shift).get
      X86_program_profile_bpf._value =
      some (.Vlong (X86RegisterReadLanes.result (offset + nativeBase) size shift)) := by
    simp only [X86RegisterReadLanes.temps, CC.PTree.gss]
  have finished := X86RegisterReadEntry.finish ge memory k
    (X86RegisterReadLanes.temps ready (offset + nativeBase) size shift) _ returned
  have counts : 41 + 10 + X86RegisterReadLanes.length size + 4 = length size := by
    simp only [length]
    omega
  have code : X86RegisterReadValue.registerByte (4 : Fin 16) = (4#8) := rfl
  simpa only [counts, code] using ((reading.trans materialized).trans selected).trans finished

end KProgFormal.ClightRefinement.X86RegisterReadRspCall
