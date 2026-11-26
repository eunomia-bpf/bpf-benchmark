import KProgFormal.ClightRefinement.Arm64MemcpyStoreAction
import KProgFormal.ClightRefinement.Arm64MemsetTagWrite

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTagSetup

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  loop : CC.Stmt
  afterTag : CC.Stmt
  body : CC.Stmt
  address : CC.Stmt
  header : CC.Stmt
  pointer : CC.Stmt
  statement : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memcpy tag-word preparation changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memcpy_81)) none) ``CC.Stmt.Ssequence
    let loop ← peel root[0]! ``CC.Stmt.Sloop
    let index ← peel loop[0]! ``CC.Stmt.Ssequence
    let shift ← peel index[1]! ``CC.Stmt.Ssequence
    let address ← peel shift[1]! ``CC.Stmt.Ssequence
    let header ← peel address[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_prepare
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,loop[0]!,shift[1]!,header[0]!,header[1]!,address[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_prepare_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
def afterTag : CC.Stmt := by run_tac cachePart (← `(parts.afterTag))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def address : CC.Stmt := by run_tac cachePart (← `(parts.address))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def pointer : CC.Stmt := by run_tac cachePart (← `(parts.pointer))
def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
theorem source : Arm64Program.s_kprog_arm64_program_memcpy_81 = .Ssequence loop afterTag ∧
    loop = .Sloop body .Sbreak ∧ address = .Ssequence (.Ssequence header pointer) statement := ⟨rfl,rfl,rfl⟩

def tag (i : Fin 16) : Fin 20 := ⟨(80+i.val)/8,by have bound:=i.isLt; omega⟩
private def index (i : Fin 16) : BitVec 64 := BitVec.ofNat 64 (80+i.val)
private def mathTemps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  (le.set Arm64Program.___ti__1 (.Vlong (index i >>> 3))).set
    Arm64Program.___ts__1 (.Vint ((((index i >>> 3) &&& (7#64)) * (8#64)).setWidth 32))
def temps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  ((mathTemps le i).set Arm64Program._t'143 (.Vptr tags 0)).set
    Arm64Program.___tp__1 (.Vptr tags ((index i >>> 3) &&& ~~~(7#64)))
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq afterTag k)

private theorem packing : ∀ i : Fin 16,
    (((index i >>> 3) &&& (7#64)) * (8#64)).setWidth 32 = Arm64MemsetTagWrite.shift (tag i) ∧
    ((index i >>> 3) &&& ~~~(7#64)) = BitVec.ofInt 64 (Arm64MemsetTagWrite.offset (tag i)) := by decide +kernel

theorem prepared (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) :
    (temps le i tags).get Arm64Program.___tp__1 =
      some (.Vptr tags (CC.Integers.Ptrofs.repr (Arm64MemsetTagWrite.offset (tag i)))) ∧
    (temps le i tags).get Arm64Program.___ts__1 = some (.Vint (Arm64MemsetTagWrite.shift (tag i))) := by
  constructor
  · simp only [temps,CC.PTree.gss]
    exact congrArg (fun value : BitVec 64 => some (CC.Val.Vptr tags value)) (packing i).2
  · simp +decide only [temps,mathTemps,CC.PTree.gso,CC.PTree.gss,(packing i).1]

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (index i))) :
    InternalRun world 7 (.State handler loop (.Kseq afterTag k) e le m)
      (.State handler address (continuation k) e (mathTemps le i) m) := by
  apply internalRun_of_steps
  all_goals simp +decide [source.2.1,body,steps,InternalPath,InternalState,
    CC.doStep,CC.doEvalExpr,CC.PTree.gso,CC.PTree.gss,hindex,index,mathTemps,continuation,
    CC.Cop.semBinaryOperation,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
    CC.Cop.semAnd,CC.Cop.semMul,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeof,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shru,
    CC.Integers.MI.shru,CC.Integers.Int.ltu,CC.Integers.MI.ltu,CC.Integers.Int64.and,
    CC.Integers.MI.and,CC.Integers.Int64.mul,CC.Integers.MI.mul,CC.Integers.Int.unsigned,
    CC.Integers.MI.unsigned,CC.E0,CC.Eapp,List.nil_append,BitVec.ofInt_natCast]
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
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'143 (.Vptr tags 0)) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,
    CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 648).toNat) : Nat) : Int) = 648 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 648 = some (.Vptr tags 0) from read]

private theorem address_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 6 (.State handler address (continuation k) e (mathTemps le i) m)
      (.State handler statement (continuation k) e (temps le i tags) m) := by
  have carried : (mathTemps le i).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [mathTemps,CC.PTree.gso] using hentry
  rw [source.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e (mathTemps le i) m _ entry tags carried read)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq statement (continuation k)) e (temps le i tags) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide [pointer,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,mathTemps,temps,
      CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrLong,
      CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tvolatile,CC.tulong,
      CC.tuchar,CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,CC.Integers.Int64.not,CC.Integers.MI.not,
      CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int.repr,CC.Integers.Int64.repr,
      CC.Integers.MI.repr,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,
      CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,
      CC.Integers.MI.add,CC.Integers.MI.mul,BitVec.ofInt_natCast,index]
    have natural : BitVec.ofNat 64 (((80+i.val) % 2^64) >>> 3) = BitVec.ofNat 64 (80+i.val) >>> 3 := by
      change BitVec.ofNat 64 (BitVec.ofNat 64 (80+i.val) >>> 3).toNat = _
      rw [BitVec.ofNat_toNat,BitVec.setWidth_eq]
    apply congrArg (fun value : BitVec 64 =>
      ((mathTemps le i).set Arm64Program._t'143 (.Vptr tags 0)).set Arm64Program.___tp__1 (.Vptr tags value))
    change (0#64)+(1#64)*(BitVec.ofNat 64 (((80+i.val) % 2^64) >>> 3) &&& ~~~(7#64)) =
      ((BitVec.ofNat 64 (80+i.val) >>> 3) &&& ~~~(7#64))
    rw [natural,BitVec.one_mul,BitVec.zero_add]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Source81 retains its real successor and enters the actual volatile
tag-word statement after original index, shift, header and pointer casts. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 14 (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81 k e le m)
      (.State handler statement (continuation k) e (temps le i tags) m) := by
  rw [source.1]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    ((math_setup e le m k i hindex).trans (address_setup e le m k entry tags i hentry read))

end KProgFormal.ClightRefinement.Arm64MemcpyTagSetup
