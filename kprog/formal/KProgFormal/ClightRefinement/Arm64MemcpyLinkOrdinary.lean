import KProgFormal.ClightRefinement.Arm64MemcpyLinkWriter

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkOrdinary
open Arm64MemcpyLinkProgram (ge writer)
open Arm64MemcpyLinkWriter (Table allocation temps)
open Arm64MemcpyLinkSource (tableName cellType cellOffset)
open Arm64MemcpyLinkCall (Header slot)

private structure Pieces where
  eager : CC.Stmt
  regSet : CC.Stmt
  pointerSet : CC.Stmt
  spTest : CC.Expr
  spAlternative : CC.Stmt
  ordinary : CC.Stmt
  tagSet : CC.Stmt
  releaseTest : CC.Expr
  releaseAlternative : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let mut root ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyLinkWriter.ordinary)) none
    root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root)
    unless root.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "pointer writer loop changed"
    let mut rest := root.getAppArgs[0]!
    let mut prefixStmts : Array Lean.Expr := #[]
    for _ in [:4] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "pointer writer prefix changed"
      prefixStmts := prefixStmts.push rest.getAppArgs[0]!
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "pointer writer tail changed"
    let destination ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[0]!)
    let release ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[1]!)
    unless destination.isAppOfArity ``CC.Stmt.Sifthenelse 3 && release.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
      throwError "pointer writer destination/release tests changed"
    let result ← Lean.Meta.mkAppM ``Pieces.mk #[prefixStmts[0]!, prefixStmts[1]!, prefixStmts[2]!,
      destination.getAppArgs[0]!, destination.getAppArgs[1]!, destination.getAppArgs[2]!, prefixStmts[3]!,
      release.getAppArgs[0]!, release.getAppArgs[1]!]
    Lean.Elab.Tactic.closeMainGoal `actual_pointer_writer_parts result

/-- Cache only actual source components; the equation below checks their assembly. -/
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  Lean.Elab.Tactic.closeMainGoal `actual_writer_part actual

private def eager : CC.Stmt := by
  run_tac cachePart (← `(pieces.eager))
private def regSet : CC.Stmt := by
  run_tac cachePart (← `(pieces.regSet))
private def pointerSet : CC.Stmt := by
  run_tac cachePart (← `(pieces.pointerSet))
private def tagSet : CC.Stmt := by
  run_tac cachePart (← `(pieces.tagSet))
private def spTest : CC.Expr := by
  run_tac cachePart (← `(pieces.spTest))
private def spAlternative : CC.Stmt := by
  run_tac cachePart (← `(pieces.spAlternative))
private def ordinary : CC.Stmt := by
  run_tac cachePart (← `(pieces.ordinary))
private def releaseTest : CC.Expr := by
  run_tac cachePart (← `(pieces.releaseTest))
private def releaseAlternative : CC.Stmt := by
  run_tac cachePart (← `(pieces.releaseAlternative))
private def body : CC.Stmt := .Ssequence eager (.Ssequence regSet (.Ssequence pointerSet
  (.Ssequence tagSet (.Ssequence (.Sifthenelse spTest spAlternative ordinary)
    (.Sifthenelse releaseTest releaseAlternative .Sskip)))))
private theorem body_eq : Arm64MemcpyLinkWriter.ordinary = .Sloop body .Sbreak := rfl


private def coordinatesComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Address._kprog_arm64_coordinates).get (by decide +kernel)
private def gprComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Address._arm64_sim_gpr).get (by decide +kernel)

theorem layouts :
    ge.genv_cenv.get Arm64Address._kprog_arm64_coordinates = some coordinatesComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Address._stack_offset coordinatesComposite.co_members = .OK (16,.Full) ∧
    ge.genv_cenv.get Arm64Address._arm64_sim_gpr = some gprComposite ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Address._ptr gprComposite.co_members = .OK (0,.Full) := by
  decide +kernel


private def eagerExpr : CC.Expr :=
  .Efield (.Ederef (.Etempvar Arm64Address._coordinates
    (CC.tptr (.Tstruct Arm64Address._kprog_arm64_coordinates CC.noattr)))
    (.Tstruct Arm64Address._kprog_arm64_coordinates CC.noattr))
    Arm64Address._stack_offset CC.tlong

private theorem eager_source : eager = .Sset Arm64Address.___a64_write_old_sp eagerExpr := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private theorem eager_eval (e : CC.Env) (le : CC.TempEnv) (before : CC.Mem)
    (coordinates : CC.Block) (offset : CC.Integers.Ptrofs) (sp : BitVec 64)
    (input : le.get Arm64Address._coordinates = some (.Vptr coordinates offset))
    (read : CC.Mem.load .Mint64 before coordinates (slot offset 16) = some (.Vlong sp)) :
    CC.doEvalExpr ge e le before eagerExpr = some (.Vlong sp) := by
  simp only [slot] at read
  simp only [eagerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.accessMode,input,
    CC.lvalOfField,CC.typeof,layouts.1,layouts.2.1,CC.Mem.loadv,read,CC.tlong]

private theorem guard_data :
    CC.Cop.semCmp .Ceq (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 32)) CC.tuint CC.Mem.empty = some (.Vint 0) ∧
    CC.Cop.semCmp .Clt (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint CC.Mem.empty = some (.Vint 1) ∧
    CC.Cop.semCmp .Cne (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint CC.Mem.empty = some (.Vint 1) ∧
    CC.Cop.semCmp .Cne (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 255)) CC.tuint CC.Mem.empty = some (.Vint 1) := by decide +kernel

private theorem guards (cenv : CC.CompositeEnv) (memory : CC.Mem) :
    CC.Cop.semBinaryOperation cenv .Oeq (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 32)) CC.tuint memory = some (.Vint 0) ∧
    CC.Cop.semBinaryOperation cenv .Olt (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint memory = some (.Vint 1) ∧
    CC.Cop.semBinaryOperation cenv .One (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint memory = some (.Vint 1) ∧
    CC.Cop.semBinaryOperation cenv .One (.Vlong (30#64)) CC.tulong (.Vint (CC.Integers.Int.repr 255)) CC.tuint memory = some (.Vint 1) := by
  simp only [CC.Cop.semBinaryOperation]
  exact guard_data

private theorem add_slot (memory : CC.Mem) (tags : Bool) (block : CC.Block) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr block 0)
      (CC.tarray (CC.tptr (if tags then CC.tuchar else .Tunion Arm64Address._arm64_sim_gpr CC.noattr)) 31) (.Vint (30#32)) CC.tuchar memory =
      some (.Vptr block (CC.Integers.Ptrofs.repr 240)) := by
  cases tags <;> rfl

private theorem ptr_add_zero (offset : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset := BitVec.add_zero offset

private theorem nine_mask : (9#32) &&& (BitVec.allOnes 32 >>> (32-8)) = (9#32) := by decide +kernel


private def setupTemps {original header offset} (h : Header original header offset) (address sp : BitVec 64) : CC.TempEnv :=
  let a := (temps h address).set Arm64Address.___a64_write_old_sp (.Vlong sp)
  let b := a.set Arm64Address.___a64_l_reg (.Vlong (30#64))
  let c := b.set Arm64Address.___a64_l_next_ptr (.Vlong address)
  c.set Arm64Address.___a64_l_next_tag (.Vint (9#32))

private def guardTemps {original header offset} (h : Header original header offset) (address sp : BitVec 64) : CC.TempEnv :=
  let e := (setupTemps h address sp).set Arm64Address._t'5 (.Vint 1)
  let f := e.set Arm64Address._t'6 (.Vint 1)
  f.set Arm64Address._t'4 (.Vint 1)

def finalTemps {original header offset} (h : Header original header offset) (address sp : BitVec 64) : CC.TempEnv :=
  let j := (guardTemps h address sp).set Arm64Address._t'13
    (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩)))
  j.set Arm64Address._t'12
    (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩)))

private def plainOrdinary : CC.Stmt := by
  run_tac do
    let mut rest ← Lean.Elab.Term.elabTerm (← `(Arm64Address.f_kprog_arm64_write_ptr.fn_body)) none
    for _ in [:62] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "writer source table shape changed"
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[1]!)
    rest := loop.getAppArgs[0]!
    for _ in [:4] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    let choice ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[0]!)
    Lean.Elab.Tactic.closeMainGoal `plain_ordinary_source choice.getAppArgs[2]!

private theorem ordinary_source : ordinary = plainOrdinary := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private def storeBranch : CC.Stmt := by
  run_tac do
    let root ← Lean.Elab.Term.elabTerm (← `(plainOrdinary)) none
    let root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root)
    let choice ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root.getAppArgs[1]!)
    Lean.Elab.Tactic.closeMainGoal `actual_ordinary_stores choice.getAppArgs[1]!

private def tailBody : CC.Stmt := .Ssequence (.Sifthenelse spTest spAlternative ordinary)
  (.Sifthenelse releaseTest releaseAlternative .Sskip)
private def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def storeCont (k : CC.Cont) : CC.Cont :=
  .Kseq (.Sifthenelse releaseTest releaseAlternative .Sskip) (loopCont k)

set_option hygiene false in
private theorem setup_run {original header offset} (h : Header original header offset)
    (address sp : BitVec 64) (m before middle after : CC.Mem)
    (words : Table false m) (tags : Table true m) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 before h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordSlot : CC.Mem.load CC.Mptr before words.block 240 =
      some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩))))
    (tagSlot : CC.Mem.load CC.Mptr middle tags.block 240 =
      some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩))))
    (wordStore : CC.Mem.store .Mint64 before h.registers (slot h.registerOffset 240) (.Vlong address) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle h.tags (slot h.tagOffset 30) (.Vint (9#32)) = some after) :
    InternalRun ge 13
      (.State writer Arm64MemcpyLinkWriter.ordinary k (allocation m).1 (temps h address) before)
      (.State writer tailBody (loopCont k) (allocation m).1 (setupTemps h address sp) before) := by
  have coordinatesInput : (temps h address).get Arm64Address._coordinates =
      some (.Vptr h.coordinates h.coordinateOffset) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have regInput : (temps h address).get Arm64Address._reg = some (.Vlong (30#64)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have valueInput : (temps h address).get Arm64Address._value = some (.Vlong address) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have tagInput : (temps h address).get Arm64Address._tag = some (.Vint (9#32)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have eagerRead := eager_eval (allocation m).1 (temps h address) before h.coordinates h.coordinateOffset sp coordinatesInput spRead
  have beforeChecks := guards ge.genv_cenv before
  have afterChecks := guards ge.genv_cenv after
  have wordBinding : (allocation m).1.get Arm64Address.___a64_cells =
      some (words.block,CC.tarray (CC.tptr (.Tunion Arm64Address._arm64_sim_gpr CC.noattr)) 31) := words.binding
  have tagBinding : (allocation m).1.get Arm64Address.___a64_tag_cells =
      some (tags.block,CC.tarray (CC.tptr CC.tuchar) 31) := tags.binding
  have narrowed : CC.Integers.Int.repr (CC.Integers.Int64.unsigned (30#64)) &&&
      (BitVec.allOnes 32 >>> (32-8)) = (30#32) := by decide +kernel
  simp only [CC.tarray,CC.tptr,CC.tuchar] at wordBinding tagBinding
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at wordSlot tagSlot
  have wordAdd := add_slot before false words.block
  have tagAdd := add_slot middle true tags.block
  have tableZero : CC.Integers.Ptrofs.zero = (0 : CC.Integers.Ptrofs) := rfl
  have slotUnsigned : (CC.Integers.Ptrofs.repr 240).unsigned = 240 := rfl
  have wordOffset : cellOffset false ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 240 := rfl
  have tagOffset : cellOffset true ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 30 := rfl
  simp only [slot,wordOffset,tagOffset] at spRead wordSlot tagSlot wordStore tagStore
  simp only [CC.tarray,CC.tptr,CC.tuchar,cellType,eq_self,Bool.false_eq_true,ite_true,ite_false] at wordAdd tagAdd
  rw [body_eq]
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [body_eq,body,eager_source,eagerRead,regSet,pointerSet,tagSet,spTest,ordinary_source,plainOrdinary,releaseTest,tailBody,loopCont,storeCont,storeBranch,
        CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfField,CC.lvalOfVar,
        CC.Mem.loadv,CC.Mem.storev,CC.accessMode,CC.typeof,
        finalTemps,guardTemps,setupTemps,coordinatesInput,regInput,valueInput,tagInput,CC.PTree.gss,CC.PTree.gso,wordBinding,tagBinding,narrowed,
        layouts.1,layouts.2.1,layouts.2.2.1,layouts.2.2.2,
        spRead,wordSlot,tagSlot,wordStore,tagStore,beforeChecks.1,beforeChecks.2.1,
        beforeChecks.2.2.1,beforeChecks.2.2.2,afterChecks.1,wordAdd,tagAdd,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tlong,CC.tbool,CC.tptr,CC.tarray,
        CC.Mptr,CC.Archi.ptr64,tableZero,slotUnsigned,wordOffset,tagOffset,ptr_add_zero,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_false,ite_true,eq_self,
        Bool.false_eq_true,Bool.true_eq_false,Bool.not_true,Bool.not_false,nine_mask,
        BitVec.zero_add,BitVec.add_zero,BitVec.and_allOnes,BitVec.ofInt_natCast,BitVec.ofNat_toNat] <;> try rfl)
    for i in [:13] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))


set_option hygiene false in
private theorem guards_run {original header offset} (h : Header original header offset)
    (address sp : BitVec 64) (m before middle after : CC.Mem)
    (words : Table false m) (tags : Table true m) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 before h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordSlot : CC.Mem.load CC.Mptr before words.block 240 =
      some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩))))
    (tagSlot : CC.Mem.load CC.Mptr middle tags.block 240 =
      some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩))))
    (wordStore : CC.Mem.store .Mint64 before h.registers (slot h.registerOffset 240) (.Vlong address) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle h.tags (slot h.tagOffset 30) (.Vint (9#32)) = some after) :
    InternalRun ge 15
      (.State writer tailBody (loopCont k) (allocation m).1 (setupTemps h address sp) before)
      (.State writer storeBranch (storeCont k) (allocation m).1 (guardTemps h address sp) before) := by
  have coordinatesInput : (temps h address).get Arm64Address._coordinates =
      some (.Vptr h.coordinates h.coordinateOffset) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have regInput : (temps h address).get Arm64Address._reg = some (.Vlong (30#64)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have valueInput : (temps h address).get Arm64Address._value = some (.Vlong address) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have tagInput : (temps h address).get Arm64Address._tag = some (.Vint (9#32)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have eagerRead := eager_eval (allocation m).1 (temps h address) before h.coordinates h.coordinateOffset sp coordinatesInput spRead
  have beforeChecks := guards ge.genv_cenv before
  have afterChecks := guards ge.genv_cenv after
  have wordBinding : (allocation m).1.get Arm64Address.___a64_cells =
      some (words.block,CC.tarray (CC.tptr (.Tunion Arm64Address._arm64_sim_gpr CC.noattr)) 31) := words.binding
  have tagBinding : (allocation m).1.get Arm64Address.___a64_tag_cells =
      some (tags.block,CC.tarray (CC.tptr CC.tuchar) 31) := tags.binding
  have narrowed : CC.Integers.Int.repr (CC.Integers.Int64.unsigned (30#64)) &&&
      (BitVec.allOnes 32 >>> (32-8)) = (30#32) := by decide +kernel
  simp only [CC.tarray,CC.tptr,CC.tuchar] at wordBinding tagBinding
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at wordSlot tagSlot
  have wordAdd := add_slot before false words.block
  have tagAdd := add_slot middle true tags.block
  have tableZero : CC.Integers.Ptrofs.zero = (0 : CC.Integers.Ptrofs) := rfl
  have slotUnsigned : (CC.Integers.Ptrofs.repr 240).unsigned = 240 := rfl
  have wordOffset : cellOffset false ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 240 := rfl
  have tagOffset : cellOffset true ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 30 := rfl
  simp only [slot,wordOffset,tagOffset] at spRead wordSlot tagSlot wordStore tagStore
  simp only [CC.tarray,CC.tptr,CC.tuchar,cellType,eq_self,Bool.false_eq_true,ite_true,ite_false] at wordAdd tagAdd
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [body_eq,body,eager_source,eagerRead,regSet,pointerSet,tagSet,spTest,ordinary_source,plainOrdinary,releaseTest,tailBody,loopCont,storeCont,storeBranch,
        CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfField,CC.lvalOfVar,
        CC.Mem.loadv,CC.Mem.storev,CC.accessMode,CC.typeof,
        finalTemps,guardTemps,setupTemps,coordinatesInput,regInput,valueInput,tagInput,CC.PTree.gss,CC.PTree.gso,wordBinding,tagBinding,narrowed,
        layouts.1,layouts.2.1,layouts.2.2.1,layouts.2.2.2,
        spRead,wordSlot,tagSlot,wordStore,tagStore,beforeChecks.1,beforeChecks.2.1,
        beforeChecks.2.2.1,beforeChecks.2.2.2,afterChecks.1,wordAdd,tagAdd,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tlong,CC.tbool,CC.tptr,CC.tarray,
        CC.Mptr,CC.Archi.ptr64,tableZero,slotUnsigned,wordOffset,tagOffset,ptr_add_zero,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_false,ite_true,eq_self,
        Bool.false_eq_true,Bool.true_eq_false,Bool.not_true,Bool.not_false,nine_mask,
        BitVec.zero_add,BitVec.add_zero,BitVec.and_allOnes,BitVec.ofInt_natCast,BitVec.ofNat_toNat] <;> try rfl)
    for i in [:15] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))


set_option hygiene false in
private theorem stores_run {original header offset} (h : Header original header offset)
    (address sp : BitVec 64) (m before middle after : CC.Mem)
    (words : Table false m) (tags : Table true m) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 before h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordSlot : CC.Mem.load CC.Mptr before words.block 240 =
      some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩))))
    (tagSlot : CC.Mem.load CC.Mptr middle tags.block 240 =
      some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩))))
    (wordStore : CC.Mem.store .Mint64 before h.registers (slot h.registerOffset 240) (.Vlong address) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle h.tags (slot h.tagOffset 30) (.Vint (9#32)) = some after) :
    InternalRun ge 14
      (.State writer storeBranch (storeCont k) (allocation m).1 (guardTemps h address sp) before)
      (.State writer .Sskip k (allocation m).1 (finalTemps h address sp) after) := by
  have coordinatesInput : (temps h address).get Arm64Address._coordinates =
      some (.Vptr h.coordinates h.coordinateOffset) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have regInput : (temps h address).get Arm64Address._reg = some (.Vlong (30#64)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have valueInput : (temps h address).get Arm64Address._value = some (.Vlong address) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have tagInput : (temps h address).get Arm64Address._tag = some (.Vint (9#32)) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  have eagerRead := eager_eval (allocation m).1 (temps h address) before h.coordinates h.coordinateOffset sp coordinatesInput spRead
  have beforeChecks := guards ge.genv_cenv before
  have afterChecks := guards ge.genv_cenv after
  have wordBinding : (allocation m).1.get Arm64Address.___a64_cells =
      some (words.block,CC.tarray (CC.tptr (.Tunion Arm64Address._arm64_sim_gpr CC.noattr)) 31) := words.binding
  have tagBinding : (allocation m).1.get Arm64Address.___a64_tag_cells =
      some (tags.block,CC.tarray (CC.tptr CC.tuchar) 31) := tags.binding
  have narrowed : CC.Integers.Int.repr (CC.Integers.Int64.unsigned (30#64)) &&&
      (BitVec.allOnes 32 >>> (32-8)) = (30#32) := by decide +kernel
  simp only [CC.tarray,CC.tptr,CC.tuchar] at wordBinding tagBinding
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at wordSlot tagSlot
  have wordAdd := add_slot before false words.block
  have tagAdd := add_slot middle true tags.block
  have tableZero : CC.Integers.Ptrofs.zero = (0 : CC.Integers.Ptrofs) := rfl
  have slotUnsigned : (CC.Integers.Ptrofs.repr 240).unsigned = 240 := rfl
  have wordOffset : cellOffset false ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 240 := rfl
  have tagOffset : cellOffset true ⟨30,by decide⟩ = CC.Integers.Ptrofs.repr 30 := rfl
  simp only [slot,wordOffset,tagOffset] at spRead wordSlot tagSlot wordStore tagStore
  simp only [CC.tarray,CC.tptr,CC.tuchar,cellType,eq_self,Bool.false_eq_true,ite_true,ite_false] at wordAdd tagAdd
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [body_eq,body,eager_source,eagerRead,regSet,pointerSet,tagSet,spTest,ordinary_source,plainOrdinary,releaseTest,tailBody,loopCont,storeCont,storeBranch,
        CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfField,CC.lvalOfVar,
        CC.Mem.loadv,CC.Mem.storev,CC.accessMode,CC.typeof,
        finalTemps,guardTemps,setupTemps,coordinatesInput,regInput,valueInput,tagInput,CC.PTree.gss,CC.PTree.gso,wordBinding,tagBinding,narrowed,
        layouts.1,layouts.2.1,layouts.2.2.1,layouts.2.2.2,
        spRead,wordSlot,tagSlot,wordStore,tagStore,beforeChecks.1,beforeChecks.2.1,
        beforeChecks.2.2.1,beforeChecks.2.2.2,afterChecks.1,wordAdd,tagAdd,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tlong,CC.tbool,CC.tptr,CC.tarray,
        CC.Mptr,CC.Archi.ptr64,tableZero,slotUnsigned,wordOffset,tagOffset,ptr_add_zero,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_false,ite_true,eq_self,
        Bool.false_eq_true,Bool.true_eq_false,Bool.not_true,Bool.not_false,nine_mask,
        BitVec.zero_add,BitVec.add_zero,BitVec.and_allOnes,BitVec.ofInt_natCast,BitVec.ofNat_toNat] <;> try rfl)
    for i in [:14] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))


/-- The actual reg30 branch is checked in its three genuine sequential
phases at the original proof limits. No prefix or transition is replayed. -/
theorem execute_stores {original header offset} (h : Header original header offset)
    (address sp : BitVec 64) (m before middle after : CC.Mem)
    (words : Table false m) (tags : Table true m) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 before h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordSlot : CC.Mem.load CC.Mptr before words.block 240 =
      some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩))))
    (tagSlot : CC.Mem.load CC.Mptr middle tags.block 240 =
      some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩))))
    (wordStore : CC.Mem.store .Mint64 before h.registers (slot h.registerOffset 240) (.Vlong address) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle h.tags (slot h.tagOffset 30) (.Vint (9#32)) = some after) :
    InternalRun ge 42
      (.State writer Arm64MemcpyLinkWriter.ordinary k (allocation m).1 (temps h address) before)
      (.State writer .Sskip k (allocation m).1 (finalTemps h address sp) after) := by
  exact ((setup_run h address sp m before middle after words tags k spRead wordSlot tagSlot wordStore tagStore).trans (guards_run h address sp m before middle after words tags k spRead wordSlot tagSlot wordStore tagStore)).trans (stores_run h address sp m before middle after words tags k spRead wordSlot tagSlot wordStore tagStore)

private theorem valid_old {m : CC.Mem} {chunk : CC.Chunk} {b : CC.Block} {ofs : Int}
    {permission : CC.Permission} (positive : 0 < CC.sizeChunk chunk)
    (valid : CC.Mem.validAccess m chunk b ofs permission = true) :
    b.toNat < m.nextblock.toNat := by
  have range := valid
  simp only [CC.Mem.validAccess,Bool.and_eq_true] at range
  exact CC.Mem.perm_valid_block m b ofs .Cur permission
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ range.1 ofs (Int.le_refl _) (Int.lt_add_of_pos_right ofs positive))

private theorem read_old {m : CC.Mem} {b : CC.Block} {ofs : Int} {value : CC.Val}
    (read : CC.Mem.load .Mint64 m b ofs = some value) : b.toNat < m.nextblock.toNat := by
  unfold CC.Mem.load at read
  split at read
  · have current : CC.Mem.validAccess m .Mint64 b ofs .Readable = true := by assumption
    exact valid_old (by decide) current
  · contradiction

private theorem valid_frame {m before : CC.Mem} (frame : FrameBelow m.nextblock m before)
    {chunk : CC.Chunk} {b : CC.Block} {ofs : Int} {permission : CC.Permission}
    (positive : 0 < CC.sizeChunk chunk)
    (valid : CC.Mem.validAccess m chunk b ofs permission = true) :
    CC.Mem.validAccess before chunk b ofs permission = true := by
  have old := valid_old positive valid
  exact (CC.Mem.validAccess_congr (fun o => by
    simp only [CC.Mem.perm,(frame b old).2])).trans valid

private theorem store_exists (m : CC.Mem) (chunk : CC.Chunk) (b : CC.Block) (ofs : Int) (value : CC.Val)
    (valid : CC.Mem.validAccess m chunk b ofs .Writable = true) :
    ∃ after, CC.Mem.store chunk m b ofs value = some after := by
  unfold CC.Mem.store
  rw [valid]
  exact ⟨_,rfl⟩

/-- Actual reached heaps and stores of one original LINK execution.
The real allocator and saved continuation remain explicit for both freeLists. -/
structure Written {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (address sp : BitVec 64) (k : CC.Cont) where
  entryMemory : CC.Mem
  before : CC.Mem
  middle : CC.Mem
  after : CC.Mem
  run : InternalRun ge 632
    (.Callstate (.Internal Arm64MemcpyLinkProgram.entry) [.Vptr header offset,.Vlong address] k m)
    (.State writer .Sskip
      (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k)
      (allocation entryMemory).1 (finalTemps h address sp) after)
  wordStore : CC.Mem.store .Mint64 before h.registers (slot h.registerOffset 240) (.Vlong address) = some middle
  tagStore : CC.Mem.store .Mint8unsigned middle h.tags (slot h.tagOffset 30) (.Vint (9#32)) = some after
  wordRead : CC.Mem.load .Mint64 after h.registers (slot h.registerOffset 240) = some (.Vlong address)
  tagRead : CC.Mem.load .Mint8unsigned after h.tags (slot h.tagOffset 30) = some (.Vint (9#32))
  wordOld : h.registers.toNat < m.nextblock.toNat
  tagOld : h.tags.toNat < m.nextblock.toNat
  beforeFrame : FrameBelow m.nextblock m before
  beforeAccess : before.access = (allocation entryMemory).2.access
  innerFrame : FrameBelow entryMemory.nextblock entryMemory before
  entryAccess : entryMemory.access = (Arm64MemcpyLinkSource.allocation m).2.access
  entryNext : entryMemory.nextblock = (Arm64MemcpyLinkSource.allocation m).2.nextblock

theorem Written.access {m header offset} {h : Header m header offset} {address sp k}
    (w : Written h address sp k) : w.after.access = w.before.access :=
  (CC.Mem.store_access w.tagStore).trans (CC.Mem.store_access w.wordStore)

theorem Written.next {m header offset} {h : Header m header offset} {address sp k}
    (w : Written h address sp k) : w.after.nextblock = w.before.nextblock :=
  (CC.Mem.store_nextblock w.tagStore).trans (CC.Mem.store_nextblock w.wordStore)


/-- Original read/permissions,not successful stores,supply the SAME reached
reg30 branch. All actual setup and table initialization execute once. -/
theorem execute {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (address sp : BitVec 64) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 m h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordWritable : CC.Mem.validAccess m .Mint64 h.registers (slot h.registerOffset 240) .Writable = true)
    (tagWritable : CC.Mem.validAccess m .Mint8unsigned h.tags (slot h.tagOffset 30) .Writable = true)
    (separate : h.registers ≠ h.tags) : Nonempty (Written h address sp k) := by
  obtain ⟨outerWords,outerTags,entryMemory,words,tags,stack,before,initialized,
    outerWordSlots,outerTagSlots,wordSlots,tagSlots,stackBinding,stackRead,
    frame,innerFrame,entryAccess,entryNext,access,next⟩ :=
    Arm64MemcpyLinkWriter.execute h old address k
  have oldCoordinates := read_old spRead
  have oldWord := valid_old (by decide) wordWritable
  have oldTag := valid_old (by decide) tagWritable
  have entryBound : m.nextblock.toNat ≤ entryMemory.nextblock.toNat := by
    rw [entryNext]
    exact (FrameBelow.allocVariables (Arm64MemcpyLinkSource.allocated m) m.nextblock (Nat.le_refl _)).1
  have tagTableOther : tags.block ≠ h.registers := by
    have fresh := tags.fresh
    intro equal
    rw [equal] at fresh
    omega
  have currentSp := (frame.load .Mint64 h.coordinates _ oldCoordinates).trans spRead
  have currentWord := valid_frame frame (by decide) wordWritable
  have currentTag := valid_frame frame (by decide) tagWritable
  obtain ⟨middle,wordStore⟩ := store_exists before .Mint64 h.registers _ (.Vlong address) currentWord
  have tagWritableMiddle := (CC.Mem.validAccess_store_eq wordStore .Mint8unsigned h.tags
    (slot h.tagOffset 30) .Writable).trans currentTag
  obtain ⟨after,tagStore⟩ := store_exists middle .Mint8unsigned h.tags _ (.Vint (9#32)) tagWritableMiddle
  have wordSlot : CC.Mem.load CC.Mptr before words.block 240 =
      some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false ⟨30,by decide⟩))) :=
    wordSlots ⟨30,by decide⟩
  have tagSlot : CC.Mem.load CC.Mptr middle tags.block 240 =
      some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true ⟨30,by decide⟩))) :=
    (CC.Mem.load_store_other wordStore CC.Mptr tags.block 240 (.inl tagTableOther)).trans (tagSlots ⟨30,by decide⟩)
  have bodyRun := execute_stores h address sp entryMemory before middle after words tags
    (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k)
    currentSp wordSlot tagSlot wordStore tagStore
  have wordRead : CC.Mem.load .Mint64 after h.registers (slot h.registerOffset 240) = some (.Vlong address) := by
    rw [CC.Mem.load_store_other tagStore .Mint64 _ _ (.inl separate)]
    exact CC.Mem.load_store_same wordStore
  have tagRead : CC.Mem.load .Mint8unsigned after h.tags (slot h.tagOffset 30) = some (.Vint (9#32)) := by
    simpa +decide only [CC.Val.loadResult,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,nine_mask,ite_false] using CC.Mem.load_store_same tagStore
  exact ⟨⟨entryMemory,before,middle,after,initialized.trans bodyRun,wordStore,tagStore,
    wordRead,tagRead,oldWord,oldTag,frame,access,innerFrame,entryAccess,entryNext⟩⟩


/-- Genuine local permissions derive the writer's three-local freeList.
Its return resumes the exact saved LINK continuation. -/
theorem Written.release_inner {m header offset} {h : Header m header offset} {address sp k}
    (w : Written h address sp k) :
    ∃ returned, InternalRun ge 633
      (.Callstate (.Internal Arm64MemcpyLinkProgram.entry) [.Vptr header offset,.Vlong address] k m)
      (.Returnstate .Vundef
        (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k) returned) ∧
      CC.Mem.freeList w.after (CC.blocksOfEnv ge.genv_cenv (allocation w.entryMemory).1) = some returned ∧
      FrameBelow w.entryMemory.nextblock w.after returned ∧
      returned.contents = w.after.contents ∧ returned.nextblock = w.after.nextblock := by
  have live : ∀ id value, (allocation w.entryMemory).1.get id = some value →
      CC.Mem.rangePerm w.after value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
    intro id value binding
    have owned := ((allocated_local_storage (Arm64MemcpyLinkWriter.allocated w.entryMemory)).1 id value binding).2.2
    exact (CC.Mem.rangePerm_congr (fun o => by
      simp only [CC.Mem.perm,w.access,w.beforeAccess])).trans owned
  obtain ⟨returned,freed,frame,contents,next,released⟩ :=
    deallocate_live_locals (Arm64MemcpyLinkWriter.allocated w.entryMemory) live
  have finish : InternalRun ge 1
      (.State writer .Sskip
        (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k)
        (allocation w.entryMemory).1 (finalTemps h address sp) w.after)
      (.Returnstate .Vundef
        (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k) returned) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  exact ⟨returned,w.run.trans finish,freed,frame,contents,next⟩

theorem return_source : Arm64MemcpyLinkCall.returnStmt =
    .Sreturn (some (.Etempvar Arm64Addressing.___a64_lr CC.tulong)) := rfl

private theorem return_type : Arm64MemcpyLinkProgram.entry.fn_return = CC.tulong := rfl

set_option hygiene false in
/-- Actual callee return,loop break and original LINK return;the actual
outer freeList supplied here is constructed from live allocation below. -/
theorem return_to_caller {m header offset} (h : Header m header offset) (address : BitVec 64)
    (k : CC.Cont) (returned after : CC.Mem)
    (freed : CC.Mem.freeList returned
      (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkSource.allocation m).1) = some after) :
    InternalRun ge 5
      (.Returnstate .Vundef
        (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k) returned)
      (.Returnstate (.Vlong address) (CC.callCont k) after) := by
  have lr := Arm64MemcpyLinkCall.lr_readback h address (Arm64MemcpyLinkCall.initializedTemps h address)
  run_tac do
    let reduce ← `(tactic|
      simp only [CC.doStep,Arm64MemcpyLinkCall.writerCont,Arm64MemcpyLinkCall.inner,
        return_source,return_type,CC.setOpttemp,CC.doEvalExpr,lr,freed,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.tulong,CC.E0,CC.Eapp,
        List.nil_append,List.append_nil] <;> try rfl)
    for _ in [:5] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))


/-- Both real freeLists and the original return execute on the SAME heaps.
Raw original blocks outside the two written blocks and all original access
maps are retained;store equations expose exact within-block effects. -/
theorem Written.complete {m header offset} {h : Header m header offset} {address sp k}
    (w : Written h address sp k) :
    ∃ returned after,
      InternalRun ge 638
        (.Callstate (.Internal Arm64MemcpyLinkProgram.entry) [.Vptr header offset,.Vlong address] k m)
        (.Returnstate (.Vlong address) (CC.callCont k) after) ∧
      CC.Mem.freeList w.after (CC.blocksOfEnv ge.genv_cenv (allocation w.entryMemory).1) = some returned ∧
      CC.Mem.freeList returned (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkSource.allocation m).1) = some after ∧
      FrameBelow w.entryMemory.nextblock w.after returned ∧
      FrameBelow m.nextblock returned after ∧
      after.contents = w.after.contents ∧ after.nextblock = w.after.nextblock ∧
      CC.Mem.load .Mint64 after h.registers (slot h.registerOffset 240) = some (.Vlong address) ∧
      CC.Mem.load .Mint8unsigned after h.tags (slot h.tagOffset 30) = some (.Vint (9#32)) ∧
      (∀ b, b.toNat < m.nextblock.toNat → CC.PMap.get b after.access = CC.PMap.get b m.access) ∧
      (∀ b, b.toNat < m.nextblock.toNat → b ≠ h.registers → b ≠ h.tags →
        CC.PMap.get b after.contents = CC.PMap.get b m.contents) := by
  obtain ⟨returned,bodyRun,innerFree,innerRaw,innerContents,innerNext⟩ := w.release_inner
  have frontier : m.nextblock.toNat ≤ w.entryMemory.nextblock.toNat := by
    rw [w.entryNext]
    exact (FrameBelow.allocVariables (Arm64MemcpyLinkSource.allocated m) m.nextblock (Nat.le_refl _)).1
  have accessAt : ∀ b, b.toNat < w.entryMemory.nextblock.toNat →
      CC.PMap.get b returned.access = CC.PMap.get b w.entryMemory.access := by
    intro b below
    exact (innerRaw b below).2.trans
      ((congrArg (CC.PMap.get b) w.access).trans (w.innerFrame b below).2)
  have live : ∀ id value, (Arm64MemcpyLinkSource.allocation m).1.get id = some value →
      CC.Mem.rangePerm returned value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
    intro id value binding
    have ownedLocal := (allocated_local_storage (Arm64MemcpyLinkSource.allocated m)).1 id value binding
    have below : value.1.toNat < w.entryMemory.nextblock.toNat := by
      rw [w.entryNext]
      exact ownedLocal.2.1
    exact (CC.Mem.rangePerm_congr (fun o => by
      simp only [CC.Mem.perm,accessAt value.1 below,w.entryAccess])).trans ownedLocal.2.2
  obtain ⟨after,outerFree,outerRaw,outerContents,outerNext,released⟩ :=
    deallocate_live_locals (Arm64MemcpyLinkSource.allocated m) live
  have tailRun := return_to_caller h address k returned after outerFree
  have wordBelow : h.registers.toNat < w.entryMemory.nextblock.toNat := by have := w.wordOld; omega
  have tagBelow : h.tags.toNat < w.entryMemory.nextblock.toNat := by have := w.tagOld; omega
  refine ⟨returned,after,bodyRun.trans tailRun,innerFree,outerFree,innerRaw,outerRaw,
    outerContents.trans innerContents,outerNext.trans innerNext,?_,?_,?_,?_⟩
  · exact (outerRaw.load .Mint64 _ _ w.wordOld).trans
      ((innerRaw.load .Mint64 _ _ wordBelow).trans w.wordRead)
  · exact (outerRaw.load .Mint8unsigned _ _ w.tagOld).trans
      ((innerRaw.load .Mint8unsigned _ _ tagBelow).trans w.tagRead)
  · intro b below
    exact (outerRaw b below).2.trans ((innerRaw b (by omega)).2.trans
      ((congrArg (CC.PMap.get b) w.access).trans (w.beforeFrame b below).2))
  · intro b below wordOther tagOther
    rw [outerContents,innerContents,CC.Mem.store_contents w.tagStore,
      CC.PMap.gso _ _ _ _ tagOther.symm,CC.Mem.store_contents w.wordStore,
      CC.PMap.gso _ _ _ _ wordOther.symm]
    exact (w.beforeFrame b below).1

/-- Complete original LINK invocation from original typed read and writable
resource evidence. Neither a callee summary nor a final-store success is an input. -/
theorem link {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (address sp : BitVec 64) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 m h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordWritable : CC.Mem.validAccess m .Mint64 h.registers (slot h.registerOffset 240) .Writable = true)
    (tagWritable : CC.Mem.validAccess m .Mint8unsigned h.tags (slot h.tagOffset 30) .Writable = true)
    (separate : h.registers ≠ h.tags) :
    ∃ (w : Written h address sp k) (returned after : CC.Mem),
      InternalRun ge 638
        (.Callstate (.Internal Arm64MemcpyLinkProgram.entry) [.Vptr header offset,.Vlong address] k m)
        (.Returnstate (.Vlong address) (CC.callCont k) after) ∧
      CC.Mem.freeList w.after (CC.blocksOfEnv ge.genv_cenv (allocation w.entryMemory).1) = some returned ∧
      CC.Mem.freeList returned (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkSource.allocation m).1) = some after ∧
      FrameBelow w.entryMemory.nextblock w.after returned ∧
      FrameBelow m.nextblock returned after ∧
      after.contents = w.after.contents ∧ after.nextblock = w.after.nextblock ∧
      CC.Mem.load .Mint64 after h.registers (slot h.registerOffset 240) = some (.Vlong address) ∧
      CC.Mem.load .Mint8unsigned after h.tags (slot h.tagOffset 30) = some (.Vint (9#32)) ∧
      (∀ b, b.toNat < m.nextblock.toNat → CC.PMap.get b after.access = CC.PMap.get b m.access) ∧
      (∀ b, b.toNat < m.nextblock.toNat → b ≠ h.registers → b ≠ h.tags →
        CC.PMap.get b after.contents = CC.PMap.get b m.contents) := by
  obtain ⟨w⟩ := execute h old address sp k spRead wordWritable tagWritable separate
  obtain ⟨returned,after,result⟩ := w.complete
  exact ⟨w,returned,after,result⟩

end KProgFormal.ClightRefinement.Arm64MemcpyLinkOrdinary
