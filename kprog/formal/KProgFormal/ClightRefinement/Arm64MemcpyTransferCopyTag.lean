import KProgFormal.ClightRefinement.Arm64MemcpyTransferLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyTag

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  init : CC.Stmt
  tagCall : CC.Stmt
  testSet : CC.Stmt
  sourceGuard : CC.Stmt
  sourceSP : CC.Stmt
  destinationGuard : CC.Stmt
  alignmentGuard : CC.Stmt
  lengthGuard : CC.Stmt
  copyGuard : CC.Stmt
  tagStore : CC.Stmt
private def parts : Parts := by
  run_tac do
    let pair (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original memcpy copy-tag guard sequence changed"
      pure actual.getAppArgs
    let root ← pair (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memcpy_110)) none)
    let tail ← pair root[1]!
    let copy ← pair tail[0]!
    let length ← pair copy[0]!
    let alignment ← pair length[0]!
    let destination ← pair alignment[0]!
    let source ← pair destination[0]!
    let tag ← pair source[0]!
    let guard ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source[1]!)
    unless guard.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
      throwError "original memcpy source-SP guard changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_tag
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,tag[0]!,tag[1]!,source[1]!,guard.getAppArgs[1]!,
        destination[1]!,alignment[1]!,length[1]!,copy[1]!,tail[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_tag_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def init : CC.Stmt := by run_tac cachePart (← `(parts.init))
private def tagCall : CC.Stmt := by run_tac cachePart (← `(parts.tagCall))
private def testSet : CC.Stmt := by run_tac cachePart (← `(parts.testSet))
private def sourceGuard : CC.Stmt := by run_tac cachePart (← `(parts.sourceGuard))
def sourceSP : CC.Stmt := by run_tac cachePart (← `(parts.sourceSP))
def destinationGuard : CC.Stmt := by run_tac cachePart (← `(parts.destinationGuard))
def alignmentGuard : CC.Stmt := by run_tac cachePart (← `(parts.alignmentGuard))
def lengthGuard : CC.Stmt := by run_tac cachePart (← `(parts.lengthGuard))
def copyGuard : CC.Stmt := by run_tac cachePart (← `(parts.copyGuard))
def tagStore : CC.Stmt := by run_tac cachePart (← `(parts.tagStore))

private def testValue : CC.Expr := .Ecast (.Ebinop .Oeq (.Etempvar Arm64Program._t'78 CC.tuint)
  (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) CC.tbool
private theorem test_set_source : testSet = .Sset Arm64Program._t'77 testValue := rfl
private theorem test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (tag : le.get Arm64Program._t'78 = some (.Vint 4)) :
    CC.doEvalExpr world e le m testValue = some (.Vint 1) := by
  simp only [testValue,CC.doEvalExpr,tag,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.Val.ofBool,CC.Val.Vtrue,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tbool,CC.tuint,CC.tint,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,
    CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl
private theorem test_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tag : le.get Arm64Program._t'78 = some (.Vint 4)) :
    CC.doStep world (.State handler testSet k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'77 (.Vint 1)) m) := by
  rw [test_set_source]
  simp only [CC.doStep,test_eval e le m tag]

private theorem source : Arm64Program.s_kprog_arm64_program_memcpy_110 =
    .Ssequence init (.Ssequence (.Ssequence (.Ssequence (.Ssequence (.Ssequence
      (.Ssequence (.Ssequence tagCall testSet) sourceGuard) destinationGuard)
      alignmentGuard) lengthGuard) copyGuard) tagStore) := rfl
private theorem guard_source : sourceGuard = .Sifthenelse (.Etempvar Arm64Program._t'77 CC.tint)
    sourceSP (.Sset Arm64Program._t'79 (.Econst_int (CC.Integers.Int.repr 0) CC.tint)) := rfl
private def afterInit : CC.Stmt := .Ssequence (.Ssequence (.Ssequence (.Ssequence (.Ssequence
  (.Ssequence (.Ssequence tagCall testSet) sourceGuard) destinationGuard)
  alignmentGuard) lengthGuard) copyGuard) tagStore
def continuation (k : CC.Cont) : CC.Cont := .Kseq destinationGuard (.Kseq alignmentGuard
  (.Kseq lengthGuard (.Kseq copyGuard (.Kseq tagStore k))))
private def initTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program.___a64_mt_tag (.Vint 0)
def temps (le : CC.TempEnv) : CC.TempEnv :=
  ((initTemps le).set Arm64Program._t'78 (.Vint 4)).set Arm64Program._t'77 (.Vint 1)
private def callCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'78) handler (Arm64MemcpySource.allocation before).1 (initTemps le)
    (.Kseq testSet (.Kseq sourceGuard (continuation k)))

private theorem ready (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 10 (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k e le m)
      (.State handler tagCall (.Kseq testSet (.Kseq sourceGuard (continuation k))) e (initTemps le) m) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterInit k) e (initTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [init,initTemps,CC.doStep,CC.doEvalExpr,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tuchar,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl)
          (.step trivial (CC.doStep_sound _ _ _ _ rfl)
            (.step trivial (CC.doStep_sound _ _ _ _ rfl)
              (.step trivial (CC.doStep_sound _ _ _ _ rfl)
                (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))))))

private theorem call_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler tagCall k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 1]
        (.Kcall (some Arm64Program._t'78) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
  have outside : Arm64Program._kprog_arm64_program_tag ∉ CC.varNames handler.fn_vars := by decide +kernel
  have unshadowed : (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_tag = none := by
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside
  have binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_tag = some (CC.Positive.ofNat 65) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 65) = some (.Internal Arm64Program.f_kprog_arm64_program_tag) := by
    simpa only [world] using Arm64Select.Reads.bindings.2
  unfold tagCall
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tuint) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 65) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

private theorem returned (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 5
      (.Returnstate (.Vint 4) (.Kcall (some Arm64Program._t'78) handler e (initTemps le)
        (.Kseq testSet (.Kseq sourceGuard (continuation k)))) m)
      (.State handler sourceSP (continuation k) e (temps le) m) := by
  refine .step (mid := .State handler .Sskip (.Kseq testSet (.Kseq sourceGuard (continuation k))) e
    ((initTemps le).set Arm64Program._t'78 (.Vint 4)) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq sourceGuard (continuation k)) e (temps le) m)
    trivial (CC.doStep_sound _ _ _ _ (test_step e _ m _ (CC.PTree.gss _ _ _))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guard_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
  rfl

/-- Body110 executes its actual zero-tag initialization, linked R1 tag
call, tag4 test and genuine true source-SP branch on the same current heap. -/
theorem execute (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry 0) 1 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))) :
    InternalRun world 44
      (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation before).1 le m)
      (.State handler sourceSP (continuation k) (Arm64MemcpySource.allocation before).1 (temps le) m) := by
  have start := ready (Arm64MemcpySource.allocation before).1 le m k
  have entryRead : (initTemps le).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [initTemps,CC.PTree.gso] using hentry
  have call : InternalRun world 1
      (.State handler tagCall (.Kseq testSet (.Kseq sourceGuard (continuation k)))
        (Arm64MemcpySource.allocation before).1 (initTemps le) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 1]
        (callCont before le k) m) :=
    .step trivial (call_step before m entry (initTemps le) _ entryRead) (.refl _)
  have layout : Arm64RegisterReads.GprLayout world := Arm64Select.Reads.layout
  have read := (Arm64RegisterReads.gpr_calls_bound world layout (by decide +kernel) addresses
    m.nextblock entry 0 (1 : Fin 31) m (callCont before le k) (.Vlong (-32#64)) (-32#64) (4#8) gpr rfl).2.1
  exact ((start.trans call).trans read).trans (returned (Arm64MemcpySource.allocation before).1 le m k)

private def changed : List CC.Ident := [Arm64Program._t'77,Arm64Program._t'78,Arm64Program.___a64_mt_tag]
theorem kept (le : CC.TempEnv) (id : CC.Ident) (other : id ∉ changed) : (temps le).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,initTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'77 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'78 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_tag (by decide +kernel))]

theorem observations (le : CC.TempEnv) :
    (temps le).get Arm64Program.___a64_mt_tag = some (.Vint 0) ∧
    (temps le).get Arm64Program._t'78 = some (.Vint 4) ∧
    (temps le).get Arm64Program._t'77 = some (.Vint 1) ∧
    (temps le).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  refine ⟨?_,?_,?_,?_,?_,?_,?_⟩
  · simp only [temps,initTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'77 ≠ Arm64Program.___a64_mt_tag),
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'78 ≠ Arm64Program.___a64_mt_tag),CC.PTree.gss]
  · simp only [temps,CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'77 ≠ Arm64Program._t'78),CC.PTree.gss]
  · exact CC.PTree.gss _ _ _
  · exact kept le Arm64Program.___a64_mt_i (by decide +kernel)
  · exact kept le Arm64Program.___a64_mt_dst (by decide +kernel)
  · exact kept le Arm64Program.___a64_mt_len (by decide +kernel)
  · exact kept le Arm64Program.___a64_mt_at (by decide +kernel)

/-- The actual R1 observation supplies the source tag call while the full
current copy packet, eight live locals and prior copied bytes stay intact. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m (temps le),
      InternalRun world 44
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler sourceSP (continuation k) (Arm64MemcpySource.allocation calleeBefore).1 (temps le) m) := by
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute calleeBefore m entry.block le k addresses prior.entryRead prior.packet.r1⟩
  · exact (kept le Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyTag
