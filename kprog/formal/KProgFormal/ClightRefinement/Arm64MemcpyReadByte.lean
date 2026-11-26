import KProgFormal.ClightRefinement.Arm64MemcpyReadDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadByte

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  bytes : CC.Stmt
  byteHead : CC.Stmt
  setup : CC.Stmt
  header : CC.Stmt
  load : CC.Stmt
  copy : CC.Stmt
  remaining : CC.Stmt
  arguments : List CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memory-reader volatile byte path changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadDispatch.read)) none) ``CC.Stmt.Ssequence 2
    let outer ← peel root[0]! ``CC.Stmt.Sloop 2
    let outerBody ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let loop ← peel outerBody[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let afterIndex ← peel body[1]! ``CC.Stmt.Ssequence 2
    let afterWidth ← peel afterIndex[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel afterWidth[0]! ``CC.Stmt.Ssequence 2
    let test ← peel choose[1]! ``CC.Stmt.Sifthenelse 3
    let bytes ← peel test[2]! ``CC.Stmt.Ssequence 2
    let byteHead ← peel bytes[0]! ``CC.Stmt.Ssequence 2
    let setup ← peel byteHead[0]! ``CC.Stmt.Ssequence 2
    let load ← peel setup[1]! ``CC.Stmt.Sbuiltin 4
    Lean.Elab.Tactic.closeMainGoal `actual_reader_volatile_byte
      (← Lean.Meta.mkAppM ``Parts.mk #[test[2]!,bytes[0]!,byteHead[0]!,setup[0]!,setup[1]!,byteHead[1]!,bytes[1]!,load[3]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_byte_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def bytes : CC.Stmt := by run_tac cachePart (← `(parts.bytes))
private def byteHead : CC.Stmt := by run_tac cachePart (← `(parts.byteHead))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
def remaining : CC.Stmt := by run_tac cachePart (← `(parts.remaining))
private def arguments : List CC.Expr := by run_tac cachePart (← `(parts.arguments))

theorem source : bytes = .Ssequence byteHead remaining ∧
    byteHead = .Ssequence setup copy ∧ setup = .Ssequence header load := ⟨rfl,rfl,rfl⟩

private theorem load_source : load = .Sbuiltin (some Arm64Program._t'47) (.EF_vload .Mint8unsigned)
    [CC.tptr (CC.tvolatile CC.tuchar)] arguments := rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._b entryComposite.co_members = .OK (608,.Full) := by
  constructor <;> decide +kernel

private def headerTemps (le : CC.TempEnv) (stack : CC.Block) : CC.TempEnv :=
  le.set Arm64Program._t'91 (.Vptr stack 0)

def temps (le : CC.TempEnv) (stack : CC.Block) (value : BitVec 8) : CC.TempEnv :=
  ((headerTemps le stack).set Arm64Program._t'47 (.Vint (value.setWidth 32))).set
    Arm64Program.___a64_str_value (.Vlong (value.setWidth 64))

private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry stack : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0)) :
    CC.doStep world (.State reader header (.Kseq load k) e le m) =
      some (CC.E0,.State reader .Sskip (.Kseq load k) e (headerTemps le stack) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.tvolatile,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,headerTemps,CC.Mem.loadv,ite_true,BitVec.zero_add]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 608).toNat) : Nat) : Int) = 608 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 608 = some (.Vptr stack 0) from pointer]

private theorem index_unsigned : ∀ i : Fin 160,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (i.val : Int)) = (i.val : Int) := by decide +kernel

private theorem arguments_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (stack : CC.Block) (i : Fin 160)
    (hptr : le.get Arm64Program._t'91 = some (.Vptr stack 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doEvalExprlist world e le m arguments [CC.tptr (CC.tvolatile CC.tuchar)] =
      some [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int))] := by
  simp only [arguments,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,hptr,hindex,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrLong,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tvolatile,CC.tuchar,CC.tulong,CC.sizeof,CC.alignof,CC.Archi.ptr64,
    CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,CC.Integers.MI.add,CC.Integers.MI.mul,
    BitVec.zero_add,BitVec.one_mul,ite_true,ite_false]
  have index_value : (BitVec.ofNat 64 i.val).toNat = i.val := by
    rw [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by have bound := i.isLt; omega)
  simp only [index_value,BitVec.ofInt_natCast]
  change some [CC.Val.Vptr stack (0 + (1 : CC.Integers.Ptrofs) * CC.Integers.Ptrofs.repr (i.val : Int))] = _
  exact congrArg (fun offset : CC.Integers.Ptrofs => some [CC.Val.Vptr stack offset])
    ((BitVec.zero_add ((1 : CC.Integers.Ptrofs) * CC.Integers.Ptrofs.repr (i.val : Int))).trans
      (BitVec.one_mul (CC.Integers.Ptrofs.repr (i.val : Int))))

/-- The original volatile builtin reads the actual unsigned byte from the
same stack object through the imported nonvolatile-load relation. -/
theorem builtin (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hptr : le.get Arm64Program._t'91 = some (.Vptr stack 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (observed : CC.Mem.load .Mint8unsigned m stack (i.val : Int) = some (.Vint (value.setWidth 32))) :
    CC.Step2 world (.State reader load k e le m) CC.E0
      (.State reader .Sskip k e (le.set Arm64Program._t'47 (.Vint (value.setWidth 32))) m) := by
  rw [load_source]
  apply CC.Step.builtin (vargs := [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int))])
    (vres := .Vint (value.setWidth 32))
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments_eval e le m stack i hptr hindex)
  · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
      (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile stack)
        (by simpa only [index_unsigned i] using observed))

private theorem widen_byte : ∀ value : BitVec 8,
    BitVec.ofNat 64 (value.setWidth 32).toNat = value.setWidth 64 := by decide +kernel

private theorem copy_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 8)
    (read : le.get Arm64Program._t'47 = some (.Vint (value.setWidth 32))) :
    CC.doStep world (.State reader copy k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program.___a64_str_value (.Vlong (value.setWidth 64))) m) := by
  simp only [copy,CC.doStep,CC.doEvalExpr,read,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tvolatile,CC.tulong,
    CC.Integers.Int64.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.MI.repr,BitVec.ofInt_natCast,widen_byte]

/-- Execute the five original setup transitions, the genuine volatile load
and three original value/sequence transitions, retaining all width guards.
The builtin uses Step2 directly; the surrounding paths use InternalRun. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (observed : CC.Mem.load .Mint8unsigned m stack (i.val : Int) = some (.Vint (value.setWidth 32))) :
    CC.Star (CC.Step2 world) (.State reader bytes k e le m) CC.E0
      (.State reader remaining k e (temps le stack value) m) := by
  let loadCont := CC.Cont.Kseq copy (.Kseq remaining k)
  have enter : InternalRun world 5 (.State reader bytes k e le m)
      (.State reader load loadCont e (headerTemps le stack) m) := by
    rw [source.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.2]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e le m loadCont entry stack hentry pointer)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have carried : (headerTemps le stack).get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [headerTemps,CC.PTree.gso] using hindex
  have actual := builtin e (headerTemps le stack) m loadCont stack i value
    (CC.PTree.gss _ _ _) carried observed
  have oneRead : CC.Star (CC.Step2 world) (.State reader load loadCont e (headerTemps le stack) m) CC.E0
      (.State reader .Sskip loadCont e ((headerTemps le stack).set Arm64Program._t'47 (.Vint (value.setWidth 32))) m) :=
    .step _ _ _ _ _ _ actual (.refl _) rfl
  have leave : InternalRun world 3
      (.State reader .Sskip loadCont e ((headerTemps le stack).set Arm64Program._t'47 (.Vint (value.setWidth 32))) m)
      (.State reader remaining k e (temps le stack value) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (copy_step e _ m _ value (CC.PTree.gss _ _ _))) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  simpa only [CC.Eapp,CC.E0,List.nil_append] using star_trans enter.sound (star_trans oneRead leave.sound)

/-- All other source parameters and temporaries survive the actual byte path. -/
theorem kept (le : CC.TempEnv) (stack : CC.Block) (value : BitVec 8) (key : CC.Ident)
    (resultOther : Arm64Program.___a64_str_value ≠ key)
    (byteOther : Arm64Program._t'47 ≠ key) (pointerOther : Arm64Program._t'91 ≠ key) :
    (temps le stack value).get key = le.get key := by
  simp only [temps,headerTemps,CC.PTree.gso _ _ _ _ resultOther,
    CC.PTree.gso _ _ _ _ byteOther,CC.PTree.gso _ _ _ _ pointerOther]

/-- The same current packet supplies both the real stack pointer and the
source64+i value produced by the preceding actual memset stores. -/
theorem of_packet {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values m)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 (64+i.val)))) :
    CC.Star (CC.Step2 world) (.State reader bytes k e le m) CC.E0
      (.State reader remaining k e (temps le base.stack.block byte) m) := by
  let physical : Fin 160 := ⟨64+i.val,by have bound := i.isLt; omega⟩
  have pointer : CC.Mem.load CC.Mptr m entry.block 608 = some (.Vptr base.stack.block 0) := by
    simpa only [packet.stackSame] using packet.view.stackPointer
  have observed : CC.Mem.load .Mint8unsigned m base.stack.block (physical.val : Int) = some (.Vint (byte.setWidth 32)) := by
    simpa only [physical,Arm64MemsetStoreExecution.index] using packet.written i
  exact execute e le m k entry.block base.stack.block physical byte hentry hindex pointer observed

end KProgFormal.ClightRefinement.Arm64MemcpyReadByte
