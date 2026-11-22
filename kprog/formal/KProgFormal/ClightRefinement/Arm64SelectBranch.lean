import KProgFormal.ClightRefinement.Arm64SelectPathCall
import KProgFormal.ClightRefinement.Arm64SelectReads

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Select.Branch
open Arm64ProgramEntryLinked (ge)

def source : CC.Stmt := Arm64Program.s_kprog_arm64_program_execute_128
def sourceName (taken : Bool) : CC.Ident := if taken then Arm64Program._src else Arm64Program._src2
private def pointerName (taken : Bool) : CC.Ident := if taken then Arm64Program._t'147 else Arm64Program._t'149
private def tagName (taken : Bool) : CC.Ident := if taken then Arm64Program._t'148 else Arm64Program._t'150
private def entryType : CC.Ty := CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)
private def readTypes : List CC.Ty := [entryType,CC.tulong]
private def writerTypes : List CC.Ty := [entryType,CC.tulong,CC.tptr CC.tvoid,CC.tuchar]
private def inputs (taken : Bool) : List CC.Expr :=
  [.Etempvar Arm64Program._entry entryType,.Etempvar (sourceName taken) CC.tulong]
private def pointerCall (taken : Bool) : CC.Stmt :=
  .Scall (some (pointerName taken))
    (.Evar Arm64Program._kprog_arm64_program_pointer (.Tfunction readTypes (CC.tptr CC.tvoid) CC.cc_default)) (inputs taken)
private def tagCall (taken : Bool) : CC.Stmt :=
  .Scall (some (tagName taken))
    (.Evar Arm64Program._kprog_arm64_program_tag (.Tfunction readTypes CC.tuint CC.cc_default)) (inputs taken)
private def writerCall (taken : Bool) : CC.Stmt :=
  .Scall none (.Evar Arm64Program._kprog_arm64_program_write_pointer (.Tfunction writerTypes CC.tvoid CC.cc_default))
    [.Etempvar Arm64Program._entry entryType,.Etempvar Arm64Program._dst CC.tulong,
     .Etempvar (pointerName taken) (CC.tptr CC.tvoid),.Etempvar (tagName taken) CC.tuint]
private def selected (taken : Bool) : CC.Stmt := .Ssequence (.Ssequence (pointerCall taken) (tagCall taken)) (writerCall taken)

/-- Exact source statement and both original branch-specific temporary names. -/
theorem source_eq : source = .Sifthenelse (.Etempvar Arm64Program.___a64_l_taken CC.tint) (selected true) (selected false) := rfl

private def pointerCont (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (pointerName taken)) Arm64Nop.handler e le (.Kseq (tagCall taken) (.Kseq (writerCall taken) k))
private def tagCont (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (tagName taken)) Arm64Nop.handler e le (.Kseq (writerCall taken) k)

def temps (taken : Bool) (le : CC.TempEnv) (value : CC.Val) (tag : BitVec 8) : CC.TempEnv :=
  (le.set (pointerName taken) value).set (tagName taken) (.Vint (tag.setWidth 32))

private theorem pointer_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_pointer) =
    .Tfunction readTypes (CC.tptr CC.tvoid) CC.cc_default := rfl
private theorem tag_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_tag) =
    .Tfunction readTypes CC.tuint CC.cc_default := rfl
private theorem writer_type : CC.typeOfFundef (.Internal Arm64PointerWrite.procedure) =
    .Tfunction writerTypes CC.tvoid CC.cc_default := rfl
private theorem byte_cast (tag : BitVec 8) (m : CC.Mem) :
    CC.Cop.semCast (.Vint (tag.setWidth 32)) CC.tuint CC.tuchar m = some (.Vint (tag.setWidth 32)) := by
  change some (CC.Val.Vint (tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32)) = _
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]
private theorem pointer_cast (addresses : Arm64Registers.PointerOrigins) (value : CC.Val) (raw : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses value raw) (m : CC.Mem) :
    CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value := by
  cases value <;> try contradiction
  all_goals rfl

private theorem call_pointer (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.Step2 ge (.State Arm64Nop.handler (pointerCall taken) k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] (.Kcall (some (pointerName taken)) Arm64Nop.handler e le k) m) := by
  unfold pointerCall
  apply CC.Step.call (tyargs := readTypes) (tyres := CC.tptr CC.tvoid) (cconv := CC.cc_default)
    (vf := .Vptr (CC.Positive.ofNat 104) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp +decide [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.typeof,CC.accessMode,unshadowed,Reads.bindings.1.1]
  · apply CC.doEvalExprlist_sound
    simp +decide [inputs,readTypes,entryType,entry,index,CC.doEvalExprlist,CC.doEvalExpr,CC.typeof,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tulong,CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.Integers.MI.eq,CC.Integers.MI.zero] using Reads.bindings.1.2
  · exact pointer_type

private theorem call_tag (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_tag = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.Step2 ge (.State Arm64Nop.handler (tagCall taken) k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] (.Kcall (some (tagName taken)) Arm64Nop.handler e le k) m) := by
  unfold tagCall
  apply CC.Step.call (tyargs := readTypes) (tyres := CC.tuint) (cconv := CC.cc_default)
    (vf := .Vptr (CC.Positive.ofNat 65) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp +decide [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.typeof,CC.accessMode,unshadowed,Reads.bindings.2.1]
  · apply CC.doEvalExprlist_sound
    simp +decide [inputs,readTypes,entryType,entry,index,CC.doEvalExprlist,CC.doEvalExpr,CC.typeof,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tulong,CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.Integers.MI.eq,CC.Integers.MI.zero] using Reads.bindings.2.2
  · exact tag_type

private theorem call_writer (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (dst : BitVec 64) (value : CC.Val) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (raw : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses value raw)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (pointerRead : le.get (pointerName taken) = some value)
    (tagRead : le.get (tagName taken) = some (.Vint (tag.setWidth 32))) :
    CC.Step2 ge (.State Arm64Nop.handler (writerCall taken) k e le m) CC.E0
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        [.Vptr b ofs,.Vlong dst,value,.Vint (tag.setWidth 32)] (.Kcall none Arm64Nop.handler e le k) m) := by
  unfold writerCall
  apply CC.Step.call (tyargs := writerTypes) (tyres := CC.tvoid) (cconv := CC.cc_default)
    (vf := .Vptr (CC.Positive.ofNat 67) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp +decide [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.typeof,CC.accessMode,unshadowed,Arm64PointerWrite.Linked.binding.1]
  · apply CC.doEvalExprlist_sound
    have cast := pointer_cast addresses value raw represented m
    simp only [writerTypes,entryType,CC.doEvalExprlist,CC.doEvalExpr,CC.typeof,entry,destination,pointerRead,tagRead,cast,byte_cast]
    simp +decide [CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tulong,CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.Integers.MI.eq,CC.Integers.MI.zero] using Arm64PointerWrite.Linked.binding.2
  · exact writer_type

set_option hygiene false in
private theorem enter (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (decision : le.get Arm64Program.___a64_l_taken = some (.Vint (if taken then 1 else 0)))
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val))) :
    InternalRun ge 4 (.State Arm64Nop.handler source k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] (pointerCont taken e le k) m) := by
  cases taken <;>
    run_tac do
      for _ in [:3] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,source_eq,selected,pointerCall,tagCall,
          writerCall,pointerCont,pointerName,tagName,sourceName,inputs,readTypes,entryType,writerTypes,
          decision,entry,index,unshadowed,Reads.bindings.1.1,Reads.bindings.1.2,pointer_type,
          CC.doEvalExpr,CC.doEvalExprlist,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.accessMode,CC.typeof,
          CC.Cop.classifyFun,CC.Genv.findFunct,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.boolVal,CC.Cop.classifyBool,
          CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tulong,CC.tint,CC.tuint,CC.Archi.ptr64,
          CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
          CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.E0,CC.Eapp,List.nil_append,List.append_nil,
          ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.step trivial
        (call_pointer _ _ _ _ _ b ofs i unshadowed entry index) (InternalRun.refl _)))

set_option hygiene false in
private theorem after_pointer (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31) (value : CC.Val)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_tag = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val))) :
    InternalRun ge 3 (.Returnstate value (pointerCont taken e le k) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] (tagCont taken e (le.set (pointerName taken) value) k) m) := by
  have entry' : (le.set (pointerName taken) value).get Arm64Program._entry = some (.Vptr b ofs) := by
    cases taken <;> simp +decide [pointerName,CC.PTree.gso,entry]
  have index' : (le.set (pointerName taken) value).get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    cases taken <;> simp +decide [pointerName,sourceName,CC.PTree.gso] at * <;> assumption
  cases taken <;>
    run_tac do
      for _ in [:2] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,pointerCont,tagCont,tagCall,writerCall,
          pointerName,tagName,sourceName,inputs,readTypes,entryType,writerTypes,
          entry,index,unshadowed,Reads.bindings.2.1,Reads.bindings.2.2,tag_type,
          CC.setOpttemp,CC.PTree.gss,CC.PTree.gso,CC.doEvalExpr,CC.doEvalExprlist,CC.doEvalLvalue,
          CC.lvalOfVar,CC.doDerefLoc,CC.accessMode,CC.typeof,CC.Cop.classifyFun,CC.Genv.findFunct,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,
          CC.tptr,CC.tvoid,CC.tulong,CC.tint,CC.tuint,CC.Archi.ptr64,
          CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.E0,CC.Eapp,List.nil_append,List.append_nil,
          ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.step trivial
        (call_tag _ _ _ _ _ b ofs i unshadowed entry' index') (InternalRun.refl _)))

set_option hygiene false in
private theorem after_tag (taken : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (dst : BitVec 64) (value : CC.Val) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (raw : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses value raw)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (destination : le.get Arm64Program._dst = some (.Vlong dst)) :
    InternalRun ge 3
      (.Returnstate (.Vint (tag.setWidth 32)) (tagCont taken e (le.set (pointerName taken) value) k) m)
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        [.Vptr b ofs,.Vlong dst,value,.Vint (tag.setWidth 32)]
        (.Kcall none Arm64Nop.handler e (temps taken le value tag) k) m) := by
  have entry' : (temps taken le value tag).get Arm64Program._entry = some (.Vptr b ofs) := by
    cases taken <;> simp +decide [temps,pointerName,tagName,CC.PTree.gso,entry]
  have destination' : (temps taken le value tag).get Arm64Program._dst = some (.Vlong dst) := by
    cases taken <;> simp +decide [temps,pointerName,tagName,CC.PTree.gso,destination]
  have pointerRead : (temps taken le value tag).get (pointerName taken) = some value := by
    cases taken <;> simp +decide [temps,pointerName,tagName,CC.PTree.gss,CC.PTree.gso]
  have tagRead : (temps taken le value tag).get (tagName taken) = some (.Vint (tag.setWidth 32)) := by
    simp [temps,CC.PTree.gss]
  have cast := pointer_cast addresses value raw represented m
  cases taken <;>
    run_tac do
      for _ in [:2] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,tagCont,writerCall,temps,
          pointerName,tagName,entryType,writerTypes,entry,destination,unshadowed,
          Arm64PointerWrite.Linked.binding.1,Arm64PointerWrite.Linked.binding.2,writer_type,
          cast,byte_cast,CC.setOpttemp,CC.PTree.gss,CC.PTree.gso,
          CC.doEvalExpr,CC.doEvalExprlist,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,
          CC.accessMode,CC.typeof,CC.Cop.classifyFun,CC.Genv.findFunct,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,
          CC.tptr,CC.tvoid,CC.tulong,CC.tint,CC.tuint,CC.tuchar,CC.Archi.ptr64,
          CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.E0,CC.Eapp,List.nil_append,List.append_nil,
          ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.step trivial
        (call_writer _ _ _ _ _ b ofs dst value tag addresses raw represented unshadowed entry' destination' pointerRead tagRead) (InternalRun.refl _)))

/-- The original selected CSEL branch reads the chosen raw pointer and full tag,
then reaches the genuine writer call. Inputs come from the same complete native
register relation. Both choices, all ordinary sources and all tags are covered;
the heap is unchanged and no scalar value is forced on relative pointers. -/
theorem to_writer (taken : Bool) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (native : Reference.AArch64.State) (i : Fin 31)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m (.Vptr b ofs) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (dst : BitVec 64)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (decision : le.get Arm64Program.___a64_l_taken = some (.Vint (if taken then 1 else 0)))
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (sourceName taken) = some (.Vlong (BitVec.ofNat 64 i.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong dst)) :
    ∃ value raw tag,
      Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val = some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Reference.AArch64.gpr native i = Reference.Provenance.AArch64.materialize origins raw tag ∧
      InternalRun ge 66 (.State Arm64Nop.handler source k e le m)
        (.Callstate (.Internal Arm64PointerWrite.procedure)
          [.Vptr b ofs,.Vlong dst,value,.Vint (tag.setWidth 32)]
          (.Kcall none Arm64Nop.handler e (temps taken le value tag) k) m) := by
  obtain ⟨value,raw,tag,observed,valueRep,nativeWord⟩ := represented.gpr i
  have calls := Arm64RegisterReads.gpr_calls_bound ge Reads.layout (by decide +kernel)
    addresses frontier b ofs i m (pointerCont taken e le k) value raw tag observed valueRep
  have tagRun := Arm64RegisterReads.gpr_calls_bound ge Reads.layout (by decide +kernel)
    addresses frontier b ofs i m (tagCont taken e (le.set (pointerName taken) value) k) value raw tag observed valueRep
  have begin := enter taken e le m k b ofs i pointerNameFree decision entry index
  have middle := after_pointer taken e le m k b ofs i value tagNameFree entry index
  have finish := after_tag taken e le m k b ofs dst value tag addresses raw valueRep writerNameFree entry destination
  exact ⟨value,raw,tag,observed,valueRep,nativeWord,by
    simpa only [CC.callCont] using (((begin.trans calls.2.2).trans middle).trans tagRun.2.1).trans finish⟩

end KProgFormal.ClightRefinement.Arm64Select.Branch
