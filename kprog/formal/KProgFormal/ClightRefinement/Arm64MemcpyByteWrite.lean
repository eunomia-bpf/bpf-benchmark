import KProgFormal.ClightRefinement.Arm64MemcpyByteGates
import KProgFormal.ClightRefinement.Arm64MemsetByteWrite

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyByteWrite

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  statement : CC.Stmt
  header : CC.Stmt
  store : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memcpy volatile byte lane changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyByteGates.byteLoop)) none) ``CC.Stmt.Sloop
    let lane ← peel loop[0]! ``CC.Stmt.Ssequence
    let value ← peel lane[1]! ``CC.Stmt.Ssequence
    let shift ← peel value[1]! ``CC.Stmt.Ssequence
    let tail ← peel shift[1]! ``CC.Stmt.Ssequence
    let store ← peel tail[1]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_volatile_byte
      (← Lean.Meta.mkAppM ``Parts.mk #[tail[1]!,store[0]!,store[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_byte_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
private def arguments : List CC.Expr := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(store)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do throwError "original memcpy byte builtin changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_byte_arguments actual.getAppArgs[3]!
theorem source : statement = .Ssequence header store := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint8unsigned)
    [CC.tptr (CC.tvolatile CC.tuchar),CC.tvolatile CC.tuchar] arguments := rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._b entryComposite.co_members = .OK (608,.Full) := by
  constructor <;> decide +kernel
def temps (le : CC.TempEnv) (stack : CC.Block) : CC.TempEnv := le.set Arm64Program._t'141 (.Vptr stack 0)

private theorem header_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry stack : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0)) :
    CC.doStep world (.State handler header (.Kseq store k) e le m) =
      some (CC.E0,.State handler .Sskip (.Kseq store k) e (temps le stack) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.tvolatile,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,temps,CC.Mem.loadv,ite_true,BitVec.zero_add]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 608).toNat) : Nat) : Int) = 608 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 608 = some (.Vptr stack 0) from pointer]

private theorem index_unsigned : ∀ i : Fin 160,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (i.val : Int)) = (i.val : Int) := by decide +kernel
private theorem mask_byte (value : BitVec 8) : value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [←BitVec.setWidth_and,BitVec.and_allOnes]
private theorem cast_byte (value : BitVec 8) :
    (value.setWidth 64).setWidth 32 &&& (255#32) = value.setWidth 32 := by
  rw [BitVec.setWidth_setWidth_of_le _ (by decide : 32≤64),mask_byte]

private theorem arguments_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hvalue : le.get Arm64Program.___kprog_a64_bl_value = some (.Vlong (value.setWidth 64)))
    (hshift : le.get Arm64Program.___kprog_a64_bl_shift = some (.Vlong 0)) :
    CC.doEvalExprlist world e (temps le stack) m arguments
      [CC.tptr (CC.tvolatile CC.tuchar),CC.tvolatile CC.tuchar] =
      some [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int)),.Vint (value.setWidth 32)] := by
  have index : (temps le stack).get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [temps,CC.PTree.gso] using hindex
  have val : (temps le stack).get Arm64Program.___kprog_a64_bl_value = some (.Vlong (value.setWidth 64)) := by
    simpa +decide only [temps,CC.PTree.gso] using hvalue
  have shift : (temps le stack).get Arm64Program.___kprog_a64_bl_shift = some (.Vlong 0) := by
    simpa +decide only [temps,CC.PTree.gso] using hshift
  simp +decide only [arguments,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,CC.PTree.gss,CC.PTree.gso,
    index,val,shift,hindex,hvalue,hshift,CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,
    CC.Cop.semAddPtrLong,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvolatile,CC.tuchar,CC.tulong,
    CC.sizeof,CC.alignof,CC.Archi.ptr64,CC.Integers.Int64.shru,CC.Integers.MI.shru,
    CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,
    CC.Integers.MI.add,CC.Integers.MI.mul,CC.Integers.Int64.ltu,CC.Integers.MI.ltu,CC.Integers.Int64.iwordsize,
    BitVec.zero_add,BitVec.one_mul,BitVec.ushiftRight_zero,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    cast_byte,mask_byte,temps,ite_true,ite_false]
  have actualIndex : (BitVec.ofNat 64 i.val).toNat = i.val := by
    rw [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by have bound:=i.isLt; omega)
  simp only [actualIndex,CC.Archi.ptrWordsize,BitVec.toNat_zero,BitVec.ushiftRight_zero,BitVec.ofInt_natCast]
  change some [CC.Val.Vptr stack ((0#64)+(1#64)*BitVec.ofNat 64 i.val),
    CC.Val.Vint ((value.setWidth 64).setWidth 32 &&& (255#32) &&& (255#32))] =
    some [CC.Val.Vptr stack (BitVec.ofNat 64 i.val),CC.Val.Vint (value.setWidth 32)]
  rw [BitVec.one_mul,BitVec.zero_add,cast_byte,mask_byte]

/-- The actual volatile byte builtin writes its original shifted/cast
source byte through the genuine destination index expression. -/
theorem builtin (e : CC.Env) (le : CC.TempEnv) (m after : CC.Mem) (k : CC.Cont)
    (stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hvalue : le.get Arm64Program.___kprog_a64_bl_value = some (.Vlong (value.setWidth 64)))
    (hshift : le.get Arm64Program.___kprog_a64_bl_shift = some (.Vlong 0))
    (stored : CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint (value.setWidth 32)) = some after) :
    CC.Step2 world (.State handler store k e (temps le stack) m) CC.E0
      (.State handler .Sskip k e (temps le stack) after) := by
  rw [store_source]
  apply CC.Step.builtin (vargs := [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int)),.Vint (value.setWidth 32)])
    (vres := .Vundef)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments_eval e le m stack i value hindex hvalue hshift)
  · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
      (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile stack) (by simpa only [index_unsigned i] using stored))

/-- Current writable stack rights construct the real byte store, exact
readback, original source execution and complete permission/frontier frame. -/
theorem write (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hvalue : le.get Arm64Program.___kprog_a64_bl_value = some (.Vlong (value.setWidth 64)))
    (hshift : le.get Arm64Program.___kprog_a64_bl_shift = some (.Vlong 0))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (range : CC.Mem.rangePerm m stack 0 160 .Cur .Writable = true) :
    ∃ after, CC.Star (CC.Step2 world) (.State handler statement k e le m) CC.E0
      (.State handler .Sskip k e (temps le stack) after) ∧
      CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint (value.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after stack (i.val : Int) = some (.Vint (value.setWidth 32)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have valid : CC.Mem.validAccess m .Mint8unsigned stack (i.val : Int) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true,decide_eq_true_eq]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro offset low high
      exact CC.Mem.rangePerm_perm m stack 0 160 .Cur .Writable range offset (by omega)
        (by have bound:=i.isLt; change offset < (i.val : Int)+1 at high; omega)
    · simp [CC.alignChunk]
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint (value.setWidth 32)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have entered : InternalRun world 3 (.State handler statement k e le m)
      (.State handler store k e (temps le stack) m) := by
    rw [source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (header_eval e le m k entry stack hentry pointer)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have actualStore := builtin e le m after k stack i value hindex hvalue hshift stored
  have one : CC.Star (CC.Step2 world) (.State handler store k e (temps le stack) m) CC.E0
      (.State handler .Sskip k e (temps le stack) after) := .step _ _ _ _ _ _ actualStore (.refl _) rfl
  have normalized : CC.Val.loadResult .Mint8unsigned (.Vint (value.setWidth 32)) = .Vint (value.setWidth 32) := by
    change CC.Val.Vint (value.setWidth 32 &&& (255#32)) = _
    rw [mask_byte]
  refine ⟨after,?_,stored,?_,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans entered.sound one
  · simpa only [normalized] using CC.Mem.load_store_same stored

end KProgFormal.ClightRefinement.Arm64MemcpyByteWrite
