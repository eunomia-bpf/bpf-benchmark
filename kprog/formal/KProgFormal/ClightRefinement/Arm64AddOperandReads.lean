import KProgFormal.ClightRefinement.Arm64PointerWriteLinked
import KProgFormal.ClightRefinement.Arm64ProgramEntryWarmRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddOperandReads

private theorem sp_executes (world : CC.CGenv) (layout : Arm64RegisterReads.StackLayout world) (b sb : CC.Block)
    (ofs so : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 40))) = some (.Vptr sb so))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr sb so) = some (.Vlong offset)) :
    steps world 21 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
      [.Vptr b ofs, .Vlong (32#64)] k m) =
      some (CC.E0, .Returnstate (.Vlong offset) (CC.callCont k) m) ∧
    InternalPath world 21 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
      [.Vptr b ofs, .Vlong (32#64)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header
  simp +decide [steps, InternalPath, InternalState, CC.doStep,
      CC.doFunctionEntry2, Arm64Program.f_kprog_arm64_program_raw,
      Arm64Program.f_kprog_arm64_program_pointer,
      CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps, CC.PTree.gso,
      CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.typeconv,
      CC.removeAttributes, CC.tattr, CC.accessMode, layout.entry, layout.sp,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
      CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tvoid, CC.tint, CC.tuint, CC.tlong, CC.tulong,
      CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, header, cell, empty]

/-- The raw SP pointer read returns the relative coordinate, without adding an origin. -/
theorem sp_pointer (world : CC.CGenv) (layout : Arm64RegisterReads.StackLayout world)
    {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry) (k : CC.Cont) :
    InternalRun world 21
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr entry.block 0, .Vlong (32#64)] k memory)
      (.Returnstate (.Vlong storage.spValue) (CC.callCont k) memory) := by
  have header : CC.Mem.loadv CC.Mptr memory
      (.Vptr entry.block (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr 40))) =
        some (.Vptr storage.sp.block 0) := by
    simpa only [CC.Mem.loadv, show (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr 40)).unsigned = 40 from by decide] using storage.spPointer
  have cell : CC.Mem.loadv .Mint64 memory (.Vptr storage.sp.block 0) = some (.Vlong storage.spValue) := storage.spRead
  have run := sp_executes world layout entry.block storage.sp.block 0 0 memory k storage.spValue header cell
  exact internalRun_of_steps run.2 run.1

/-- The real SP tag branch needs no memory read or validity assumption on
its entry argument. Its constant is the C STACK tag, not a native SP value. -/
private theorem sp_tag_executes (world : CC.CGenv) (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    steps world 15 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [entry, .Vlong (32#64)] k m) =
      some (CC.E0, .Returnstate (.Vint (4#32)) (CC.callCont k) m) ∧
    InternalPath world 15 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [entry, .Vlong (32#64)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
    Arm64Program.f_kprog_arm64_program_tag, CC.doAllocVariables, CC.bindParameterTemps,
    CC.createUndefTemps, CC.PTree.gso, CC.doEvalExpr, CC.typeof, CC.typeconv,
    CC.removeAttributes, CC.tattr,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.tptr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty]

/-- Complete SP tag call for any entry value, memory and continuation. -/
theorem sp_tag (world : CC.CGenv) (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 15 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [entry, .Vlong (32#64)] k m)
      (.Returnstate (.Vint (4#32)) (CC.callCont k) m) := by
  have run := sp_tag_executes world entry m k
  exact internalRun_of_steps run.2 run.1


set_option hygiene false in
/-- XZR31 and NONE255 return scalar zero without following an entry or cache pointer. -/
theorem zero_read (world : CC.CGenv) (none : Bool) (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 55
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [entry, .Vlong (if none then (255#64) else (31#64))] k m)
      (.Returnstate (.Vlong (0#64)) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  cases none <;>
    run_tac do
      let reduce ← `(tactic| simp +decide only [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
    Arm64Program.f_kprog_arm64_program_read, CC.doAllocVariables, CC.bindParameterTemps,
    CC.createUndefTemps, CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof, CC.typeof, CC.typeconv,
    CC.removeAttributes, CC.tattr,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.tuchar, CC.tptr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl)
      for _ in [:55] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

namespace Linked

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage
open Arm64ProgramEntryLinked (ge sourceEquality)

/-- Bind the original helper bodies in the one actual source-linked world. -/
theorem bindings :
    (CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_pointer = some (CC.Positive.ofNat 104) ∧
      CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 104) = some (.Internal Arm64Program.f_kprog_arm64_program_pointer)) ∧
    (CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_tag = some (CC.Positive.ofNat 65) ∧
      CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 65) = some (.Internal Arm64Program.f_kprog_arm64_program_tag)) ∧
    (CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 66) = some (.Internal Arm64Program.f_kprog_arm64_program_read)) := by
  refine ⟨⟨?_, ?_⟩, ⟨?_, ?_⟩, ?_, ?_⟩ <;> run_tac sourceEquality

/-- Both the raw pointer reader and the SP tag reader retain this same memory. -/
theorem sp_reads {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (k : CC.Cont) :
    InternalRun ge 21
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr entry.block 0, .Vlong (32#64)] k memory)
      (.Returnstate (.Vlong storage.spValue) (CC.callCont k) memory) ∧
    InternalRun ge 15
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag)
        [.Vptr entry.block 0, .Vlong (32#64)] k memory)
      (.Returnstate (.Vint (4#32)) (CC.callCont k) memory) :=
  ⟨sp_pointer ge Arm64ProgramEntryColdRead.stack_layout storage k,
    sp_tag ge (.Vptr entry.block 0) memory k⟩

/-- The actual stored relative SP and the established native view identify the
same offset. No independent native-address or raw-offset premise is added. -/
theorem sp_native {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) native) :
    Reference.AArch64.sp native = storage.spValue + origins.stack := by
  have actual := Arm64ProducerEntryView.header_borrowed_readback memory entry.block 5 .Mint64
    storage.sp.block 0 (.Vlong storage.spValue) storage.spPointer storage.spRead
  obtain ⟨offset, read, nativeSP⟩ := represented.sp
  have same := CC.Val.Vlong.inj (Option.some.inj (read.symm.trans actual))
  exact nativeSP.trans (congrArg (fun value => value + origins.stack) same)

end Linked

end KProgFormal.ClightRefinement.Arm64AddOperandReads
