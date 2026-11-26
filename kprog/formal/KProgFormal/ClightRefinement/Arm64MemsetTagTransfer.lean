import KProgFormal.ClightRefinement.Arm64MemsetWriteLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagTransfer

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  transfer : CC.Stmt
  clobbers : CC.Stmt
  body : CC.Stmt
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
      unless actual.isAppOfArity ctor arity do throwError "original memset tag-transfer control changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetLoop.effects)) none) ``CC.Stmt.Ssequence 2
    let transfer ← peel root[0]! ``CC.Stmt.Sloop 2
    let body ← peel transfer[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    let selected ← peel guard[1]! ``CC.Stmt.Ssequence 2
    let pointer ← peel selected[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel pointer[1]! ``CC.Stmt.Ssequence 2
    let remainder ← peel selected[1]! ``CC.Stmt.Ssequence 2
    let initialized ← peel remainder[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_transfer
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,transfer[0]!,body[0]!,body[1]!,guard[1]!,
        selected[0]!,pointer[0]!,pointer[1]!,tail[0]!,tail[1]!,selected[1]!,remainder[0]!,remainder[1]!,
        initialized[0]!,initialized[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_transfer_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def transfer : CC.Stmt := by run_tac cachePart (← `(parts.transfer))
def clobbers : CC.Stmt := by run_tac cachePart (← `(parts.clobbers))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
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

theorem source : Arm64MemsetLoop.effects = .Ssequence transfer clobbers := rfl
private theorem transfer_source : transfer = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence tagCall guard := rfl
private def tagTest : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(guard)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original tag transfer test changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memset_transfer_test actual.getAppArgs[0]!
private theorem guard_source : guard = .Sifthenelse tagTest selected .Sskip := rfl
private theorem selected_source : selected = .Ssequence pointerSetup remainder := rfl
private theorem pointer_source : pointerSetup = .Ssequence pointerCall pointerTail := rfl
private theorem tail_source : pointerTail = .Ssequence biasRead dstSet := rfl
private theorem remainder_source : remainder = .Ssequence lenSet initialized := rfl
private theorem initialized_source : initialized = .Ssequence iSet loop := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq clobbers k)
private def tagCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'80) handler (Arm64MemsetSource.allocation before).1 le (.Kseq guard (continuation k))
private def tagTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'80 (.Vint 4)
private def pointerCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'68) handler (Arm64MemsetSource.allocation before).1 (tagTemps le)
    (.Kseq pointerTail (.Kseq remainder (continuation k)))

private theorem unshadowed (before : CC.Mem) :
    (Arm64MemsetSource.allocation before).1.get Arm64Program._kprog_arm64_program_tag = none ∧
    (Arm64MemsetSource.allocation before).1.get Arm64Program._kprog_arm64_program_pointer = none := by
  constructor
  · have outside : Arm64Program._kprog_arm64_program_tag ∉ CC.varNames handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using
      CC.allocVariables_env_other (Arm64MemsetSource.allocated before) outside
  · have outside : Arm64Program._kprog_arm64_program_pointer ∉ CC.varNames handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using
      CC.allocVariables_env_other (Arm64MemsetSource.allocated before) outside

private theorem tag_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler tagCall k (Arm64MemsetSource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 0]
        (.Kcall (some Arm64Program._t'80) handler (Arm64MemsetSource.allocation before).1 le k) m) := by
  have binding :
      CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_tag = some (CC.Positive.ofNat 65) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 65) =
        some (.Internal Arm64Program.f_kprog_arm64_program_tag) := by
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
    CC.Step2 world (.State handler pointerCall k (Arm64MemsetSource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 0]
        (.Kcall (some Arm64Program._t'68) handler (Arm64MemsetSource.allocation before).1 le k) m) := by
  have binding :
      CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_pointer = some (CC.Positive.ofNat 104) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 104) =
        some (.Internal Arm64Program.f_kprog_arm64_program_pointer) := by
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
    InternalRun world 4 (.State handler Arm64MemsetLoop.effects k (Arm64MemsetSource.allocation before).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr entry 0,.Vlong 0] (tagCont before le k) m) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [transfer_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (tag_step before m entry le _ hentry) (.refl _)

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
    (Arm64MemsetSource.allocation before).1 (tagTemps le) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler selected (continuation k) (Arm64MemsetSource.allocation before).1 (tagTemps le) m)
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
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel

private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State handler biasRead k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'92 (.Vlong 96)) m) := by
  simp only [biasRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tlong,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,bias]

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((((tagTemps le).set Arm64Program._t'68 (.Vlong (-32#64))).set Arm64Program._t'92 (.Vlong 96)).set
    Arm64Program.___a64_mt_dst (.Vlong 64)).set Arm64Program.___a64_mt_len (.Vlong 16)).set
      Arm64Program.___a64_mt_i (.Vlong 0)

private theorem after_pointer (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 13 (.Returnstate (.Vlong (-32#64)) (pointerCont before le k) m)
      (.State handler loop (continuation k) (Arm64MemsetSource.allocation before).1 (temps le) m) := by
  let l1 := (tagTemps le).set Arm64Program._t'68 (.Vlong (-32#64))
  let l2 := l1.set Arm64Program._t'92 (.Vlong 96)
  let l3 := l2.set Arm64Program.___a64_mt_dst (.Vlong 64)
  let l4 := l3.set Arm64Program.___a64_mt_len (.Vlong 16)
  have entry1 : l1.get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [l1,tagTemps,CC.PTree.gso] using hentry
  have length3 : l3.get Arm64Program.___a64_lib_len = some (.Vlong 16) := by
    simpa +decide only [l3,l2,l1,tagTemps,CC.PTree.gso] using hlen
  refine .step (mid := .State handler .Sskip (.Kseq pointerTail (.Kseq remainder (continuation k)))
    (Arm64MemsetSource.allocation before).1 l1 m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tail_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step _ l1 m _ entry entry1 bias)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq remainder (continuation k))
    (Arm64MemsetSource.allocation before).1 l3 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide [CC.doStep,dstSet,l3,l2,l1,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tlong,CC.tulong,
      CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.repr,CC.Integers.MI.repr]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [remainder_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq initialized (continuation k))
    (Arm64MemsetSource.allocation before).1 l4 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,lenSet,CC.doEvalExpr,length3]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [initialized_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Both original internal reader calls, their real returns, actual bias read,
destination computation and independent transfer-loop initialization execute. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (addresses : Arm64Registers.PointerOrigins)
    (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))) :
    InternalRun world 79 (.State handler Arm64MemsetLoop.effects k (Arm64MemsetSource.allocation before).1 le m)
      (.State handler loop (continuation k) (Arm64MemsetSource.allocation before).1 (temps le) m) := by
  have layout : Arm64RegisterReads.GprLayout world := Arm64Select.Reads.layout
  have tag := (Arm64RegisterReads.gpr_calls_bound world layout (by decide +kernel) addresses m.nextblock entry.block 0
    (0 : Fin 31) m (tagCont before le k) (.Vlong (-32#64)) (-32#64) (4#8) gpr rfl).2.1
  have pointer := (Arm64RegisterReads.gpr_calls_bound world layout (by decide +kernel) addresses m.nextblock entry.block 0
    (0 : Fin 31) m (pointerCont before le k) (.Vlong (-32#64)) (-32#64) (4#8) gpr rfl).2.2
  exact ((((enter_tag before m entry.block le k hentry).trans tag).trans
    (after_tag before m entry.block le k hentry)).trans pointer).trans
      (after_pointer before m entry.block le k hentry hlen view.bias)

/-- Inspect the actual source setters: entry and all original byte-loop
inputs survive; transfer destination64, length16 and counter0 are established. -/
theorem observations (le : CC.TempEnv) :
    (temps le).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps le).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps le).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte ∧
    (temps le).get Arm64Program.___a64_mt_dst = some (.Vlong 64) ∧
    (temps le).get Arm64Program.___a64_mt_len = some (.Vlong 16) ∧
    (temps le).get Arm64Program.___a64_mt_i = some (.Vlong 0) := by
  refine ⟨?_,?_,?_,?_,?_,?_,?_⟩
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program._entry := by decide +kernel
    have other1 : Arm64Program.___a64_mt_len ≠ Arm64Program._entry := by decide +kernel
    have other2 : Arm64Program.___a64_mt_dst ≠ Arm64Program._entry := by decide +kernel
    have other3 : Arm64Program._t'92 ≠ Arm64Program._entry := by decide +kernel
    have other4 : Arm64Program._t'68 ≠ Arm64Program._entry := by decide +kernel
    have other5 : Arm64Program._t'80 ≠ Arm64Program._entry := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5]
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other1 : Arm64Program.___a64_mt_len ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other2 : Arm64Program.___a64_mt_dst ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other3 : Arm64Program._t'92 ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other4 : Arm64Program._t'68 ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other5 : Arm64Program._t'80 ≠ Arm64Program.___a64_lib_i := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5]
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other1 : Arm64Program.___a64_mt_len ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other2 : Arm64Program.___a64_mt_dst ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other3 : Arm64Program._t'92 ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other4 : Arm64Program._t'68 ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other5 : Arm64Program._t'80 ≠ Arm64Program.___a64_lib_len := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5]
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other1 : Arm64Program.___a64_mt_len ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other2 : Arm64Program.___a64_mt_dst ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other3 : Arm64Program._t'92 ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other4 : Arm64Program._t'68 ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other5 : Arm64Program._t'80 ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5]
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program.___a64_mt_dst := by decide +kernel
    have other1 : Arm64Program.___a64_mt_len ≠ Arm64Program.___a64_mt_dst := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1]
  · have other0 : Arm64Program.___a64_mt_i ≠ Arm64Program.___a64_mt_len := by decide +kernel
    simp only [temps,tagTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0]
  · simp only [temps,tagTemps,CC.PTree.gss]

/-- Continue directly from the SAME completed sixteen-byte loop packet,
executing the real sequence transition and both original reader calls. -/
theorem after_bytes {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6}
    {byte : BitVec 8} {le : CC.TempEnv}
    (current : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le)
    (addresses : Arm64Registers.PointerOrigins) (before : CC.Mem) (k : CC.Cont) :
    InternalRun world 80
      (.State handler .Sskip (.Kseq Arm64MemsetLoop.effects k) (Arm64MemsetSource.allocation before).1 le m)
      (.State handler loop (continuation k) (Arm64MemsetSource.allocation before).1 (temps le) m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (execute current.view addresses before le k current.entryRead current.length current.gpr)

end KProgFormal.ClightRefinement.Arm64MemsetTagTransfer
