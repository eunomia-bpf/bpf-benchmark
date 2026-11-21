import KProgFormal.ClightRefinement.Arm64AddImmediateOperands

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate

/-- From the original handler body through width/opcode dispatch, the actual
warm SP read and conditional immediate selection to the original arithmetic
tail. The source memory, environment and caller continuation stay shared. -/
theorem body_operands (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem) (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m (.Vptr b ofs) native)
    (cache : Arm64RegisterReads.WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool) (imm : BitVec 64)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong (32#64)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (Dispatch.flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (3#32)))
    (immediate : le.get Arm64Program._imm = some (.Vlong imm)) :
    InternalRun Arm64ProgramEntryLinked.ge 152
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler Operands.tail (Operands.tailCont (Dispatch.continuation k)) e
        (Operands.tailTemps (Dispatch.temps le narrow) narrow (Reference.AArch64.sp native) imm) m) := by
  have dispatch := Dispatch.Linked.body_dispatch e le m k narrow widthName flags op
  have entry' : (Dispatch.temps le narrow).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, entry]
  have source' : (Dispatch.temps le narrow).get Arm64Program._src = some (.Vlong (32#64)) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, source]
  have op' : (Dispatch.temps le narrow).get Arm64Program._op = some (.Vint (3#32)) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, op]
  have imm' : (Dispatch.temps le narrow).get Arm64Program._imm = some (.Vlong imm) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, immediate]
  have effective : (Dispatch.temps le narrow).get Arm64Program.___a64_l_width = some (Operands.width narrow) := by
    cases narrow <;> simp +decide [Dispatch.temps, Arm64Nop.resultEnv, Operands.width, Dispatch.flags,
      Arm64Width.result, Arm64Width.argument, CC.PTree.gss, CC.PTree.gso]
  have operands := Operands.evaluate addresses origins frontier b ofs m native represented cache
    e (Dispatch.temps le narrow) (Dispatch.continuation k) narrow imm readName selectorName
    entry' source' effective op' imm'
  exact dispatch.trans operands

end KProgFormal.ClightRefinement.Arm64AddImmediate
