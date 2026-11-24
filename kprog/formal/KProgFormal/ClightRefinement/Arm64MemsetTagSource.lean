import KProgFormal.ClightRefinement.Arm64MemsetTagWrite

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagSource

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  address : CC.Stmt
  header : CC.Stmt
  pointer : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original memset tag preparation changed"
      pure actual.getAppArgs
    let index ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetTagWrite.body)) none)
    let shift ← peel index[1]!
    let address ← peel shift[1]!
    let header ← peel address[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_prepare
      (← Lean.Meta.mkAppM ``Parts.mk #[shift[1]!,header[0]!,header[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_preparation
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def address : CC.Stmt := by run_tac cachePart (← `(parts.address))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def pointer : CC.Stmt := by run_tac cachePart (← `(parts.pointer))
private theorem address_source : address = .Ssequence (.Ssequence header pointer) Arm64MemsetTagWrite.statement := rfl

def tagOf (i : Fin 160) : Fin 20 := ⟨i.val / 8,by have bound := i.isLt; omega⟩
private def mathTemps (le : CC.TempEnv) (i : Fin 160) : CC.TempEnv :=
  (le.set Arm64Program.___ti__1 (.Vlong (BitVec.ofNat 64 i.val >>> 3))).set
    Arm64Program.___ts__1 (.Vint ((((BitVec.ofNat 64 i.val >>> 3) &&& (7#64)) * (8#64)).setWidth 32))

def preparedTemps (le : CC.TempEnv) (i : Fin 160) (tags : CC.Block) : CC.TempEnv :=
  ((mathTemps le i).set Arm64Program._t'136 (.Vptr tags 0)).set
    Arm64Program.___tp__1 (.Vptr tags ((BitVec.ofNat 64 i.val >>> 3) &&& ~~~(7#64)))

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 Arm64MemsetTagWrite.body .Sbreak k

private theorem packing : ∀ i : Fin 160,
    (((BitVec.ofNat 64 i.val >>> 3) &&& (7#64)) * (8#64)).setWidth 32 = Arm64MemsetTagWrite.shift (tagOf i) ∧
    ((BitVec.ofNat 64 i.val >>> 3) &&& ~~~(7#64)) =
      BitVec.ofInt 64 (Arm64MemsetTagWrite.offset (tagOf i)) := by
  have checked : (List.finRange 160).all (fun i => decide
      ((((BitVec.ofNat 64 i.val >>> 3) &&& (7#64)) * (8#64)).setWidth 32 = Arm64MemsetTagWrite.shift (tagOf i) ∧
       ((BitVec.ofNat 64 i.val >>> 3) &&& ~~~(7#64)) =
         BitVec.ofInt 64 (Arm64MemsetTagWrite.offset (tagOf i)))) = true := by decide +kernel
  intro i
  exact of_decide_eq_true (List.all_eq_true.mp checked i (List.mem_finRange i))

set_option hygiene false in
/-- The original source calculation gives precisely the tag word pointer
and shift consumed by the real volatile read-modify-write component. -/
theorem prepared (le : CC.TempEnv) (i : Fin 160) (tags : CC.Block) :
    (preparedTemps le i tags).get Arm64Program.___tp__1 =
      some (.Vptr tags (CC.Integers.Ptrofs.repr (Arm64MemsetTagWrite.offset (tagOf i)))) ∧
    (preparedTemps le i tags).get Arm64Program.___ts__1 = some (.Vint (Arm64MemsetTagWrite.shift (tagOf i))) := by
  constructor
  · simp only [preparedTemps,CC.PTree.gss]
    run_tac do
      Lean.Meta.withTransparency .all do
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact congrArg
          (fun value : BitVec 64 => some (CC.Val.Vptr tags value)) (packing i).2))
  · have pointerOther : Arm64Program.___tp__1 ≠ Arm64Program.___ts__1 := by decide +kernel
    have headerOther : Arm64Program._t'136 ≠ Arm64Program.___ts__1 := by decide +kernel
    simp only [preparedTemps,mathTemps,CC.PTree.gso _ _ _ _ pointerOther,
      CC.PTree.gso _ _ _ _ headerOther,CC.PTree.gss,(packing i).1]

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160)
    (index : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val))) :
    InternalRun world 7 (.State handler Arm64MemsetTagWrite.loop k e le m)
      (.State handler address (continuation k) e (mathTemps le i) m) := by
  apply internalRun_of_steps
  · simp +decide [Arm64MemsetTagWrite.loop_source,Arm64MemsetTagWrite.body,steps,InternalPath,InternalState,
      CC.doStep,CC.doEvalExpr,CC.PTree.gso,CC.PTree.gss,index,CC.Cop.semBinaryOperation,CC.Cop.semShr,
      CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semAnd,CC.Cop.semMul,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,
      CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.shru,CC.Integers.MI.shru,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.mul,CC.Integers.MI.mul,
      CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
  · simp +decide [Arm64MemsetTagWrite.loop_source,Arm64MemsetTagWrite.body,steps,
      CC.doStep,CC.doEvalExpr,CC.PTree.gso,CC.PTree.gss,index,mathTemps,continuation,
      CC.Cop.semBinaryOperation,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semAnd,CC.Cop.semMul,
      CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,
      CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.shru,CC.Integers.MI.shru,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.mul,CC.Integers.MI.mul,
      CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.E0,CC.Eapp,List.nil_append,BitVec.ofInt_natCast]
    constructor
    · rfl
    · simp only [CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,BitVec.ofInt_natCast]
      rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._stack_tags entryComposite.co_members = .OK (648,.Full) := by
  constructor <;> decide +kernel

private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    CC.doStep world (.State handler header k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'136 (.Vptr tags 0)) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 648).toNat) : Nat) : Int) = 648 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 648 = some (.Vptr tags 0) from read]

private theorem address_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 6 (.State handler address (continuation k) e (mathTemps le i) m)
      (.State handler Arm64MemsetTagWrite.statement (continuation k) e (preparedTemps le i tags) m) := by
  have carried : (mathTemps le i).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [mathTemps,CC.PTree.gso] using hentry
  rw [address_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e (mathTemps le i) m
    (.Kseq pointer (.Kseq Arm64MemsetTagWrite.statement (continuation k))) entry tags carried read)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq Arm64MemsetTagWrite.statement (continuation k)) e
    (preparedTemps le i tags) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide [pointer,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,mathTemps,preparedTemps,
      CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrLong,
      CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
      CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
      CC.tptr,CC.tvoid,CC.tvolatile,CC.tulong,CC.tuchar,CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,
      CC.Integers.Int64.not,CC.Integers.MI.not,CC.Integers.Int64.and,CC.Integers.MI.and,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.unsigned,
      CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,
      CC.Integers.Ptrofs.of_int64,CC.Integers.MI.add,CC.Integers.MI.mul,BitVec.ofInt_natCast]
    have natural : BitVec.ofNat 64 ((i.val % 2^64) >>> 3) = BitVec.ofNat 64 i.val >>> 3 := by
      change BitVec.ofNat 64 (BitVec.ofNat 64 i.val >>> 3).toNat = _
      rw [BitVec.ofNat_toNat,BitVec.setWidth_eq]
    apply congrArg (fun value : BitVec 64 =>
      ((mathTemps le i).set Arm64Program._t'136 (.Vptr tags 0)).set Arm64Program.___tp__1 (.Vptr tags value))
    change (0#64) + (1#64) * (BitVec.ofNat 64 ((i.val % 2^64) >>> 3) &&& ~~~(7#64)) =
      ((BitVec.ofNat 64 i.val >>> 3) &&& ~~~(7#64))
    rw [natural,BitVec.one_mul,BitVec.zero_add]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Actual index/shift calculation, header read and pointer casts reach the
same original volatile tag statement, at every stack byte index. -/
theorem to_rmw (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (index : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 13 (.State handler Arm64MemsetTagWrite.loop k e le m)
      (.State handler Arm64MemsetTagWrite.statement (continuation k) e (preparedTemps le i tags) m) :=
  (math_setup e le m k i index).trans (address_setup e le m k entry tags i hentry read)

/-- Complete the original tag loop, retaining its full source memory effect
and both real loop-exit transitions. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 160) (word : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (index : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (observed : CC.Mem.load .Mint64 m tags (Arm64MemsetTagWrite.offset (tagOf i)) = some (.Vlong word))
    (range : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetTagWrite.loop k e le m) CC.E0
        (.State handler .Sskip k e (Arm64MemsetTagWrite.temps (preparedTemps le i tags) word) after) ∧
      CC.Mem.store .Mint64 m tags (Arm64MemsetTagWrite.offset (tagOf i))
        (.Vlong (Arm64MemsetTagWrite.cleared (tagOf i) word)) = some after ∧
      CC.Mem.load .Mint64 after tags (Arm64MemsetTagWrite.offset (tagOf i)) =
        some (.Vlong (Arm64MemsetTagWrite.cleared (tagOf i) word)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have prefixRun := to_rmw e le m k entry tags i hentry index read
  obtain ⟨after,run,stored,loaded,access,next⟩ := Arm64MemsetTagWrite.execute e (preparedTemps le i tags) m
    (continuation k) tags (tagOf i) word (prepared le i tags).1 (prepared le i tags).2 observed range
  have leave : InternalRun world 2
      (.State handler .Sskip (continuation k) e (Arm64MemsetTagWrite.temps (preparedTemps le i tags) word) after)
      (.State handler .Sskip k e (Arm64MemsetTagWrite.temps (preparedTemps le i tags) word) after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  refine ⟨after,?_,stored,loaded,access,next⟩
  simpa only [CC.Eapp,CC.E0,List.nil_append] using star_trans (star_trans prefixRun.sound run) leave.sound

/-- The complete original tag loop retains the caller frame supplied by
the same real producer tag allocation, including its address preparation. -/
theorem execute_local {initial : CC.Mem} (tags : Arm64Producer.StackTagLocal initial)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (i : Fin 160) (word : BitVec 64)
    (access : CC.PMap.get tags.block m.access = CC.PMap.get tags.block (Arm64Producer.allocation initial).2.access)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (index : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags.block 0))
    (observed : CC.Mem.load .Mint64 m tags.block (Arm64MemsetTagWrite.offset (tagOf i)) = some (.Vlong word)) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetTagWrite.loop k e le m) CC.E0
        (.State handler .Sskip k e (Arm64MemsetTagWrite.temps (preparedTemps le i tags.block) word) after) ∧
      CC.Mem.store .Mint64 m tags.block (Arm64MemsetTagWrite.offset (tagOf i))
        (.Vlong (Arm64MemsetTagWrite.cleared (tagOf i) word)) = some after ∧
      CC.Mem.load .Mint64 after tags.block (Arm64MemsetTagWrite.offset (tagOf i)) =
        some (.Vlong (Arm64MemsetTagWrite.cleared (tagOf i) word)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have range : CC.Mem.rangePerm m tags.block 0 24 .Cur .Writable = true :=
    (CC.Mem.rangePerm_congr (m1 := m) (m2 := (Arm64Producer.allocation initial).2)
      (fun pos => by simp only [CC.Mem.perm,access])).trans tags.range
  obtain ⟨after,run,stored,loaded,permissions,next⟩ := execute e le m k entry tags.block i word
    hentry index read observed range
  exact ⟨after,run,stored,loaded,FrameBelow.store tags.fresh stored,permissions,next⟩

end KProgFormal.ClightRefinement.Arm64MemsetTagSource
