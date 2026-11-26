import KProgFormal.ClightRefinement.Arm64MemsetReleaseTagComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberRegisters

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

def entryType : CC.Ty := .Tstruct Arm64Program._kprog_arm64_entry CC.noattr
def wordType : CC.Ty := .Tunion Arm64Program._arm64_sim_gpr CC.noattr
def fieldExpr (name : CC.Ident) (ty : CC.Ty) : CC.Expr :=
  .Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr entryType)) entryType) name ty
def cellExpr (root : CC.Ident) (ty : CC.Ty) (reg : Fin 31) : CC.Expr :=
  .Ederef (.Ebinop .Oadd (.Etempvar root (CC.tptr (CC.tptr ty)))
    (.Econst_int (CC.Integers.Int.repr (reg.val : Int)) CC.tint) (CC.tptr (CC.tptr ty))) (CC.tptr ty)

/-- Every statement and temporary is extracted from one actual original
source pair; shape equalities are checked by the kernel for those statements. -/
structure Declaration where
  reg : Fin 31
  valueKey : CC.Ident
  wordRootKey : CC.Ident
  wordPtrKey : CC.Ident
  tagRootKey : CC.Ident
  tagPtrKey : CC.Ident
  stage : CC.Stmt
  word : CC.Stmt
  tag : CC.Stmt
  next : CC.Stmt
  call : CC.Stmt
  wordRoot : CC.Stmt
  wordPtr : CC.Stmt
  wordAssign : CC.Stmt
  tagRoot : CC.Stmt
  tagPtr : CC.Stmt
  tagAssign : CC.Stmt
  stage_source : stage = .Ssequence word (.Ssequence tag next)
  word_source : word = .Ssequence call (.Ssequence wordRoot (.Ssequence wordPtr wordAssign))
  tag_source : tag = .Ssequence tagRoot (.Ssequence tagPtr tagAssign)
  call_source : call = .Scall (some valueKey)
    (.Evar Arm64Program._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint]
  word_root_source : wordRoot = .Sset wordRootKey (fieldExpr Arm64Program._cells (CC.tptr (CC.tptr wordType)))
  word_ptr_source : wordPtr = .Sset wordPtrKey (cellExpr wordRootKey wordType reg)
  word_assign_source : wordAssign = .Sassign
    (.Efield (.Ederef (.Etempvar wordPtrKey (CC.tptr wordType)) wordType) Arm64Program._x CC.tulong)
    (.Etempvar valueKey CC.tulong)
  tag_root_source : tagRoot = .Sset tagRootKey (fieldExpr Arm64Program._tag_cells (CC.tptr (CC.tptr CC.tuchar)))
  tag_ptr_source : tagPtr = .Sset tagPtrKey (cellExpr tagRootKey CC.tuchar reg)
  tag_assign_source : tagAssign = .Sassign (.Ederef (.Etempvar tagPtrKey (CC.tptr CC.tuchar)) CC.tuchar)
    (.Econst_int (CC.Integers.Int.repr 0) CC.tuint)

private def declarations : Array Declaration := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original clobber register source changed"
      pure actual.getAppArgs
    let key (term : Lean.Expr) : Lean.Elab.Tactic.TacticM Lean.Expr := do
      let fields ← peel term ``CC.Stmt.Sset 2
      pure fields[0]!
    let mut source ← Lean.Elab.Term.elabTerm (← `(Arm64MemsetClobberEntry.rest)) none
    let mut rows : Array Lean.Expr := #[]
    for n in [:18] do
      let stage ← peel source ``CC.Stmt.Ssequence 2
      let tail ← peel stage[1]! ``CC.Stmt.Ssequence 2
      let word ← peel stage[0]! ``CC.Stmt.Ssequence 2
      let wordRest ← peel word[1]! ``CC.Stmt.Ssequence 2
      let wordAssign ← peel wordRest[1]! ``CC.Stmt.Ssequence 2
      let call ← peel word[0]! ``CC.Stmt.Scall 3
      let value ← peel call[0]! ``Option.some 2
      let tag ← peel tail[0]! ``CC.Stmt.Ssequence 2
      let tagAssign ← peel tag[1]! ``CC.Stmt.Ssequence 2
      let regType ← Lean.Elab.Term.elabTerm (← `(Fin 31)) none
      let small ← Lean.Meta.mkAppM ``LT.lt #[Lean.mkNatLit (n+1),Lean.mkNatLit 31]
      let reg ← Lean.Meta.mkAppM ``Fin.mk #[Lean.mkNatLit (n+1),← Lean.Meta.mkDecideProof small]
      unless ← Lean.Meta.isDefEq (← Lean.Meta.inferType reg) regType do throwError "actual clobber register index"
      let row ← Lean.Meta.mkAppM ``Declaration.mk #[reg,value[1]!,← key wordRest[0]!,← key wordAssign[0]!,
        ← key tag[0]!,← key tagAssign[0]!,source,stage[0]!,tail[0]!,tail[1]!,word[0]!,wordRest[0]!,wordAssign[0]!,wordAssign[1]!,
        tag[0]!,tagAssign[0]!,tagAssign[1]!,
        ← Lean.Meta.mkEqRefl source,← Lean.Meta.mkEqRefl stage[0]!,← Lean.Meta.mkEqRefl tail[0]!,← Lean.Meta.mkEqRefl word[0]!,
        ← Lean.Meta.mkEqRefl wordRest[0]!,← Lean.Meta.mkEqRefl wordAssign[0]!,← Lean.Meta.mkEqRefl wordAssign[1]!,
        ← Lean.Meta.mkEqRefl tag[0]!,← Lean.Meta.mkEqRefl tagAssign[0]!,← Lean.Meta.mkEqRefl tagAssign[1]!]
      rows := rows.push row
      source := tail[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_clobber_register_declarations
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

def declaration (i : Fin 18) : Declaration := declarations[i.val]'(by change i.val < 18; exact i.isLt)

theorem first_source : (declaration 0).stage = Arm64MemsetClobberEntry.rest := rfl
theorem register_indices : ∀ i : Fin 18, (declaration i).reg.val = i.val + 1 := by decide +kernel
theorem register_nonzero : ∀ i : Fin 18, (declaration i).reg.val ≠ 0 := by decide +kernel

private theorem source_indices : ∀ i : Fin 17,
    i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨
    i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 ∨ i = 16 := by decide +kernel

theorem next_source (i : Fin 17) :
    (declaration ⟨i.val,Nat.lt_trans i.isLt (by decide)⟩).next =
      (declaration ⟨i.val+1,by omega⟩).stage := by
  rcases source_indices i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem key_names : ∀ i : Fin 18,
    (declaration i).valueKey ≠ Arm64Program._entry ∧
    (declaration i).wordRootKey ≠ Arm64Program._entry ∧
    (declaration i).wordPtrKey ≠ Arm64Program._entry ∧
    (declaration i).tagRootKey ≠ Arm64Program._entry ∧
    (declaration i).tagPtrKey ≠ Arm64Program._entry ∧
    (declaration i).wordRootKey ≠ (declaration i).valueKey ∧
    (declaration i).wordPtrKey ≠ (declaration i).valueKey := by decide +kernel

def valueTemps (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  le.set (declaration i).valueKey (.Vlong value)
def callCont (i : Fin 18) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (declaration i).valueKey) helper CC.emptyEnv le
    (.Kseq (.Ssequence (declaration i).wordRoot (.Ssequence (declaration i).wordPtr (declaration i).wordAssign))
      (.Kseq (.Ssequence (declaration i).tag (declaration i).next) k))

/-- Enter the genuine provider call for any of the18 actual source pairs. -/
theorem ready (i : Fin 18) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State helper (declaration i).stage k CC.emptyEnv le m)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (callCont i le k) m) := by
  rw [(declaration i).stage_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [(declaration i).word_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [(declaration i).call_source]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tuint]) (tyres := CC.tulong) (cconv := CC.cc_default)
    (vf := .Vptr Arm64ProgramEntryCall.inputBlock 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,CC.emptyEnv,CC.PTree.gempty,
      Arm64ProgramEntryColdRead.input_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using Arm64ProgramEntryCall.input_binding.2
  · rfl

/-- The provider returns to the original word-pointer prefix, updating the
actual source result temporary and preserving the real next-pair continuation. -/
theorem returned (i : Fin 18) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 2 (.Returnstate (.Vlong value) (callCont i le k) m)
      (.State helper (.Ssequence (declaration i).wordRoot (.Ssequence (declaration i).wordPtr (declaration i).wordAssign))
        (.Kseq (.Ssequence (declaration i).tag (declaration i).next) k) CC.emptyEnv (valueTemps i le value) m) := by
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

theorem returned_entry (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64) :
    (valueTemps i le value).get Arm64Program._entry = le.get Arm64Program._entry := by
  exact CC.PTree.gso _ _ _ _ (key_names i).1

end KProgFormal.ClightRefinement.Arm64MemsetClobberRegisters
