import KProgFormal.ClightRefinement.Arm64AddImmediatePointer

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Pointer

private theorem reader_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_pointer) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong]
      (CC.tptr CC.tvoid) CC.cc_default := rfl
private theorem writer_type : CC.typeOfFundef (.Internal Arm64PointerWrite.procedure) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
      CC.tptr CC.tvoid, CC.tuchar] CC.tvoid CC.cc_default := rfl

private theorem call_reader (world : CC.CGenv) (block b : CC.Block) (e : CC.Env)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_pointer = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_pointer))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (src : le.get Arm64Program._src = some (.Vlong (32#64))) :
    CC.Step2 world (.State Arm64Nop.handler readCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr b 0, .Vlong (32#64)]
        (.Kcall (some Arm64Program._t'20) Arm64Nop.handler e le k) m) := by
  unfold readCall
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong])
    (tyres := CC.tptr CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist, CC.doEvalExpr, entry, src, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.Cop.castIntInt, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact reader_type

def writerTemps (le : CC.TempEnv) (offset : BitVec 64) : CC.TempEnv :=
  (selectedTemps le).set Arm64Program._t'20 (.Vlong offset)

def writerCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) (offset : BitVec 64) : CC.Cont :=
  .Kcall none Arm64Nop.handler e (writerTemps le offset) k

private theorem after_reader (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64) :
    InternalRun world 2 (.Returnstate (.Vlong offset) (readCont k e le) m)
      (.State Arm64Nop.handler writeCall k e (writerTemps le offset) m) := by
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    simp only [CC.doStep, readCont, writerTemps, CC.setOpttemp]
    rfl
  apply InternalRun.step
  · trivial
  · exact .skip_seq _ _ _ _ _ _
  exact .refl _

private theorem call_writer (world : CC.CGenv) (block b : CC.Block) (e : CC.Env)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 31) (offset rhs : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write_pointer = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64PointerWrite.procedure))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (pointer : le.get Arm64Program._t'20 = some (.Vlong offset))
    (right : le.get Arm64Program.___a64_alu_rhs = some (.Vlong rhs))
    (tag : le.get Arm64Program.___a64_alu_src_tag = some (.Vint (4#32))) :
    CC.Step2 world (.State Arm64Nop.handler writeCall k e le m) CC.E0
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments b i (offset + rhs) (4#8))
        (.Kcall none Arm64Nop.handler e le k) m) := by
  unfold writeCall Arm64PointerWrite.arguments
  apply CC.Step.call
    (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
      CC.tptr CC.tvoid, CC.tuchar])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist, CC.doEvalExpr, entry, dst, pointer, right, tag, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.Cop.castIntInt, CC.typeconv, CC.removeAttributes,
      CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.tattr, CC.tptr, CC.tulong, CC.tuchar, CC.tvoid, CC.Archi.ptr64,
      CC.Integers.Int64.add, CC.Integers.MI.add, CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int64.repr, CC.Integers.MI.repr]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact writer_type

private theorem ordinary_not_sp (i : Fin 31) : BitVec.ofNat 64 i.val ≠ (32#64) := by
  intro equal
  have bits := congrArg BitVec.toNat equal
  change i.val % (2^64) = 32 at bits
  have bound := i.isLt
  omega

/-- Execute the original four gate groups, its selected raw-SP read, every
source argument cast, and enter the actual pointer writer on the same heap. -/
theorem enter_writer {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 31) (rhs : BitVec 64)
    (readerName : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (writerName : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entryTemp : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (src : le.get Arm64Program._src = some (.Vlong (32#64)))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32)))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (op : le.get Arm64Program.___a64_alu_op = some (.Vint (0#32)))
    (tag : le.get Arm64Program.___a64_alu_src_tag = some (.Vint (4#32)))
    (right : le.get Arm64Program.___a64_alu_rhs = some (.Vlong rhs)) :
    InternalRun Arm64ProgramEntryLinked.ge 78
      (.State Arm64Nop.handler Tail.selection k e le m)
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments entry.block i (storage.spValue + rhs) (4#8))
        (writerCont k e le storage.spValue) m) := by
  have choose := select Arm64ProgramEntryLinked.ge e le m k (BitVec.ofNat 64 i.val)
    (ordinary_not_sp i) width dst op tag
  have entry' : (selectedTemps le).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [selectedTemps, CC.PTree.gso, entryTemp]
  have src' : (selectedTemps le).get Arm64Program._src = some (.Vlong (32#64)) := by
    simp +decide only [selectedTemps, CC.PTree.gso, src]
  have call : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler readCall (.Kseq writeCall k) e (selectedTemps le) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr entry.block 0, .Vlong (32#64)] (readCont k e le) m) :=
    .step trivial (call_reader _ _ _ e _ m _ Arm64AddOperandReads.Linked.bindings.1 readerName entry' src') (.refl _)
  have read := Arm64AddOperandReads.sp_pointer Arm64ProgramEntryLinked.ge
    Arm64ProgramEntryColdRead.stack_layout storage (readCont k e le)
  have leave := after_reader Arm64ProgramEntryLinked.ge e le m k storage.spValue
  have write : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler writeCall k e (writerTemps le storage.spValue) m)
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments entry.block i (storage.spValue + rhs) (4#8))
        (writerCont k e le storage.spValue) m) := by
    apply InternalRun.step
    · trivial
    · apply call_writer _ _ _ e _ m k i storage.spValue rhs
        Arm64PointerWrite.Linked.binding writerName
      all_goals simp +decide only [writerTemps, selectedTemps, CC.PTree.gss, CC.PTree.gso,
        entryTemp, dst, right, tag] <;> first | rfl | assumption
    exact .refl _
  simpa only [CC.callCont] using (((choose.trans call).trans read).trans leave).trans write

/-- Complete the selected original pointer path through its actual writer and
return into the original handler. Stores are derived from Storage rights;
all register observations and canonical cache locals are retained. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 31) (rhs : BitVec 64)
    (readerName : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (writerName : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entryTemp : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (src : le.get Arm64Program._src = some (.Vlong (32#64)))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32)))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (op : le.get Arm64Program.___a64_alu_op = some (.Vint (0#32)))
    (tag : le.get Arm64Program.___a64_alu_src_tag = some (.Vint (4#32)))
    (right : le.get Arm64Program.___a64_alu_rhs = some (.Vlong rhs)) :
    ∃ after, Arm64PointerWrite.Result storage i (storage.spValue + rhs) (4#8) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 132
        (.State Arm64Nop.handler Tail.selection k e le m)
        (.State Arm64Nop.handler .Sskip k e (writerTemps le storage.spValue) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native i (storage.spValue + rhs) (4#8)) ∧
      Arm64CacheLocalFrame.Kept initial m after i := by
  have enter := enter_writer storage e le k i rhs readerName writerName entryTemp src width dst op tag right
  obtain ⟨after, result, write, registers, kept⟩ := Arm64PointerWrite.Linked.write storage i
    (storage.spValue + rhs) (4#8) addresses origins native represented (writerCont k e le storage.spValue) rfl
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate .Vundef (writerCont k e le storage.spValue) after)
      (.State Arm64Nop.handler .Sskip k e (writerTemps le storage.spValue) after) :=
    .step trivial (by apply CC.doStep_sound; rfl) (.refl _)
  exact ⟨after, result, (enter.trans write).trans leave, registers, kept⟩

end KProgFormal.ClightRefinement.Arm64AddImmediate.Pointer
