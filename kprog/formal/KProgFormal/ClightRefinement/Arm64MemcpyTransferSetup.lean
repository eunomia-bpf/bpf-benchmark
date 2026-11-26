import KProgFormal.ClightRefinement.Arm64MemcpyTransferSource
import KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSetup

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  tagCall : CC.Stmt
  guard : CC.Stmt
  selected : CC.Stmt
  pointerSetup : CC.Stmt
  pointerCall : CC.Stmt
  pointerTail : CC.Stmt
  biasRead : CC.Stmt
  dstSet : CC.Stmt
  remainder : CC.Stmt
  lenSet : CC.Stmt
  initialized : CC.Stmt
  iSet : CC.Stmt
  loop : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy transfer setup changed"
      pure actual.getAppArgs
    let body ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferSource.body)) none) ``CC.Stmt.Ssequence 2
    let guard ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    let selected ← peel guard[1]! ``CC.Stmt.Ssequence 2
    let pointer ← peel selected[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel pointer[1]! ``CC.Stmt.Ssequence 2
    let remainder ← peel selected[1]! ``CC.Stmt.Ssequence 2
    let initialized ← peel remainder[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_setup
      (← Lean.Meta.mkAppM ``Parts.mk #[body[0]!,body[1]!,guard[1]!,selected[0]!,pointer[0]!,pointer[1]!,
        tail[0]!,tail[1]!,selected[1]!,remainder[0]!,remainder[1]!,initialized[0]!,initialized[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_setup_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def tagCall : CC.Stmt := by run_tac cachePart (← `(parts.tagCall))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def pointerSetup : CC.Stmt := by run_tac cachePart (← `(parts.pointerSetup))
private def pointerCall : CC.Stmt := by run_tac cachePart (← `(parts.pointerCall))
private def pointerTail : CC.Stmt := by run_tac cachePart (← `(parts.pointerTail))
private def biasRead : CC.Stmt := by run_tac cachePart (← `(parts.biasRead))
private def dstSet : CC.Stmt := by run_tac cachePart (← `(parts.dstSet))
private def remainder : CC.Stmt := by run_tac cachePart (← `(parts.remainder))
private def lenSet : CC.Stmt := by run_tac cachePart (← `(parts.lenSet))
private def initialized : CC.Stmt := by run_tac cachePart (← `(parts.initialized))
private def iSet : CC.Stmt := by run_tac cachePart (← `(parts.iSet))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def tagTest : CC.Expr := .Ebinop .Oeq (.Etempvar Arm64Program._t'87 CC.tuint)
  (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint
private theorem body_source : Arm64MemcpyTransferSource.body = .Ssequence tagCall guard := rfl
private theorem guard_source : guard = .Sifthenelse tagTest selected .Sskip := rfl
private theorem selected_source : selected = .Ssequence pointerSetup remainder := rfl
private theorem pointer_source : pointerSetup = .Ssequence pointerCall pointerTail := rfl
private theorem tail_source : pointerTail = .Ssequence biasRead dstSet := rfl
private theorem remainder_source : remainder = .Ssequence lenSet initialized := rfl
private theorem initialized_source : initialized = .Ssequence iSet loop := rfl

def continuation (k : CC.Cont) : CC.Cont := Arm64MemcpyTransferSource.continuation k
private def tagCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'87) handler (Arm64MemcpySource.allocation before).1 le (.Kseq guard (continuation k))
private def tagTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'87 (.Vint 4)
private def pointerCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'72) handler (Arm64MemcpySource.allocation before).1 (tagTemps le)
    (.Kseq pointerTail (.Kseq remainder (continuation k)))

private theorem unshadowed (before : CC.Mem) :
    (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_tag = none ∧
    (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_pointer = none := by
  constructor
  · have outside : Arm64Program._kprog_arm64_program_tag ∉ CC.varNames handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside
  · have outside : Arm64Program._kprog_arm64_program_pointer ∉ CC.varNames handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside

private theorem tag_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler tagCall k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 0]
        (.Kcall (some Arm64Program._t'87) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
  have binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_tag = some (CC.Positive.ofNat 65) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 65) = some (.Internal Arm64Program.f_kprog_arm64_program_tag) := by
    simpa only [world] using Arm64Select.Reads.bindings.2
  unfold tagCall
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tuint) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 65) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,(unshadowed before).1,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

private theorem pointer_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler pointerCall k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 0]
        (.Kcall (some Arm64Program._t'72) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
  have binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_pointer = some (CC.Positive.ofNat 104) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 104) = some (.Internal Arm64Program.f_kprog_arm64_program_pointer) := by
    simpa only [world] using Arm64Select.Reads.bindings.1
  unfold pointerCall
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tptr CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 104) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,(unshadowed before).2,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

private theorem enter_tag (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    InternalRun world 4 (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation before).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 0] (tagCont before le k) m) := by
  have enter := Arm64MemcpyTransferSource.enter (Arm64MemcpySource.allocation before).1 le m k
  have call : InternalRun world 2
      (.State handler Arm64MemcpyTransferSource.body (continuation k) (Arm64MemcpySource.allocation before).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 0] (tagCont before le k) m) := by
    rw [body_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (tag_step before m entry le _ hentry) (.refl _))
  exact enter.trans call

private theorem tag_test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExpr world e (tagTemps le) m tagTest = some (.Vint 1) := by
  simp only [tagTest,tagTemps,CC.doEvalExpr,CC.PTree.gss,CC.Cop.semBinaryOperation,
    CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Val.ofBool,CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl
private theorem after_tag (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    InternalRun world 6 (.Returnstate (.Vint 4) (tagCont before le k) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 0]
        (pointerCont before le k) m) := by
  refine .step (mid := .State handler .Sskip (.Kseq guard (continuation k))
    (Arm64MemcpySource.allocation before).1 (tagTemps le) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler selected (continuation k) (Arm64MemcpySource.allocation before).1 (tagTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · rw [guard_source]
    simp only [CC.doStep]
    rw [tag_test_eval]
    rfl
  rw [selected_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [pointer_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  have carried : (tagTemps le).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [tagTemps,CC.PTree.gso] using hentry
  exact .step trivial (pointer_step before m entry (tagTemps le) _ carried) (.refl _)

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel
private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State handler biasRead k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'99 (.Vlong 96)) m) := by
  simp only [biasRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tlong,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,bias]

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((((tagTemps le).set Arm64Program._t'72 (.Vlong (-16#64))).set Arm64Program._t'99 (.Vlong 96)).set
    Arm64Program.___a64_mt_dst (.Vlong 80)).set Arm64Program.___a64_mt_len (.Vlong 16)).set
      Arm64Program.___a64_mt_i (.Vlong 0)
private theorem after_pointer (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 13 (.Returnstate (.Vlong (-16#64)) (pointerCont before le k) m)
      (.State handler loop (continuation k) (Arm64MemcpySource.allocation before).1 (temps le) m) := by
  let l1 := (tagTemps le).set Arm64Program._t'72 (.Vlong (-16#64))
  let l2 := l1.set Arm64Program._t'99 (.Vlong 96)
  let l3 := l2.set Arm64Program.___a64_mt_dst (.Vlong 80)
  let l4 := l3.set Arm64Program.___a64_mt_len (.Vlong 16)
  have entry1 : l1.get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [l1,tagTemps,CC.PTree.gso] using hentry
  have length3 : l3.get Arm64Program.___a64_lib_len = some (.Vlong 16) := by
    simpa +decide only [l3,l2,l1,tagTemps,CC.PTree.gso] using hlen
  refine .step (mid := .State handler .Sskip (.Kseq pointerTail (.Kseq remainder (continuation k)))
    (Arm64MemcpySource.allocation before).1 l1 m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tail_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step _ l1 m _ entry entry1 bias)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq remainder (continuation k))
    (Arm64MemcpySource.allocation before).1 l3 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide [CC.doStep,dstSet,l3,l2,l1,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tlong,CC.tulong,
      CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.repr,CC.Integers.MI.repr]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [remainder_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq initialized (continuation k))
    (Arm64MemcpySource.allocation before).1 l4 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,lenSet,CC.doEvalExpr,length3]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [initialized_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Both actual linked R0 reader calls and original guard/bias/initializers
reach the genuine copy-tag transfer loop on the same current heap. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (addresses : Arm64Registers.PointerOrigins)
    (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-16#64),.Vint ((4#8).setWidth 32))) :
    InternalRun world 79 (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation before).1 le m)
      (.State handler loop (continuation k) (Arm64MemcpySource.allocation before).1 (temps le) m) := by
  have readerLayout : Arm64RegisterReads.GprLayout world := Arm64Select.Reads.layout
  have tag := (Arm64RegisterReads.gpr_calls_bound world readerLayout (by decide +kernel) addresses m.nextblock entry.block 0
    (0 : Fin 31) m (tagCont before le k) (.Vlong (-16#64)) (-16#64) (4#8) gpr rfl).2.1
  have pointer := (Arm64RegisterReads.gpr_calls_bound world readerLayout (by decide +kernel) addresses m.nextblock entry.block 0
    (0 : Fin 31) m (pointerCont before le k) (.Vlong (-16#64)) (-16#64) (4#8) gpr rfl).2.2
  exact ((((enter_tag before m entry.block le k hentry).trans tag).trans
    (after_tag before m entry.block le k hentry)).trans pointer).trans
      (after_pointer before m entry.block le k hentry hlen view.bias)

private def changed : List CC.Ident := [Arm64Program.___a64_mt_i,Arm64Program.___a64_mt_len,
  Arm64Program.___a64_mt_dst,Arm64Program._t'99,Arm64Program._t'72,Arm64Program._t'87]
theorem kept (le : CC.TempEnv) (id : CC.Ident) (other : id ∉ changed) : (temps le).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,tagTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_i (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_len (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_dst (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'99 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'72 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'87 (by decide +kernel))]

theorem outputs (le : CC.TempEnv) :
    (temps le).get Arm64Program.___a64_mt_dst = some (.Vlong 80) ∧
    (temps le).get Arm64Program.___a64_mt_len = some (.Vlong 16) ∧
    (temps le).get Arm64Program.___a64_mt_i = some (.Vlong 0) := by
  simp +decide only [temps,CC.PTree.gso,CC.PTree.gss]

/-- This actual setup retains the complete sixteen-copy packet and all
eight current memcpy-local rights, with every copied byte on the same heap. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m (temps le),
      InternalRun world 79 (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler loop (continuation k) (Arm64MemcpySource.allocation calleeBefore).1 (temps le) m) := by
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute prior.packet.view addresses calleeBefore le k prior.entryRead prior.length prior.packet.r0⟩
  · exact (kept le Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSetup
