import KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyTag

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceSP

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  call : CC.Stmt
  rest : CC.Stmt
  header : CC.Stmt
  afterHeader : CC.Stmt
  read : CC.Stmt
  compare : CC.Stmt
private def parts : Parts := by
  run_tac do
    let pair (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy source-SP sequence changed"
      pure actual.getAppArgs
    let root ← pair (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyTag.sourceSP)) none)
    let rest ← pair root[1]!
    let tail ← pair rest[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_source_sp
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,rest[0]!,rest[1]!,tail[0]!,tail[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_source_sp_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def afterHeader : CC.Stmt := by run_tac cachePart (← `(parts.afterHeader))
private def read : CC.Stmt := by run_tac cachePart (← `(parts.read))
private def compare : CC.Stmt := by run_tac cachePart (← `(parts.compare))
private theorem source : Arm64MemcpyTransferCopyTag.sourceSP = .Ssequence call rest ∧
    rest = .Ssequence header afterHeader ∧ afterHeader = .Ssequence read compare := ⟨rfl,rfl,rfl⟩

private def pointerTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'80 (.Vlong (-32#64))
private def headerTemps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv := (pointerTemps le).set Arm64Program._t'97 (.Vptr sp 0)
private def readTemps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv := (headerTemps le sp).set Arm64Program._t'98 (.Vlong (-32#64))
def temps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv := (readTemps le sp).set Arm64Program._t'79 (.Vint 1)
private def callCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'80) handler (Arm64MemcpySource.allocation before).1 le (.Kseq rest k)

private theorem call_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler call k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 1]
        (.Kcall (some Arm64Program._t'80) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
  have outside : Arm64Program._kprog_arm64_program_pointer ∉ CC.varNames handler.fn_vars := by decide +kernel
  have unshadowed : (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_pointer = none := by
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside
  have binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_pointer = some (CC.Positive.ofNat 104) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 104) = some (.Internal Arm64Program.f_kprog_arm64_program_pointer) := by
    simpa only [world] using Arm64Select.Reads.bindings.1
  unfold call
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tptr CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 104) 0)
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

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor <;> decide +kernel
private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doStep world (.State handler header k e (pointerTemps le) m) =
      some (CC.E0,.State handler .Sskip k e (headerTemps le sp) m) := by
  have entryRead : (pointerTemps le).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [pointerTemps,CC.PTree.gso] using hentry
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,entryRead,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,
    CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,headerTemps,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 40 = some (.Vptr sp 0) from pointer]
private theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block)
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    CC.doStep world (.State handler read k e (headerTemps le sp) m) =
      some (CC.E0,.State handler .Sskip k e (readTemps le sp) m) := by
  simp only [read,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,headerTemps,CC.PTree.gss,
    CC.doDerefLoc,CC.accessMode,CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,readTemps]
  change (match CC.Mem.load .Mint64 m sp 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e
        (((pointerTemps le).set Arm64Program._t'97 (CC.Val.Vptr sp 0)).set Arm64Program._t'98 value) m)
    | none => none) = _
  rw [observed]

private def compareValue : CC.Expr := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(compare)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Sset 2 do throwError "original memcpy source-SP comparison changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_source_sp_compare actual.getAppArgs[1]!
private theorem compare_source : compare = .Sset Arm64Program._t'79 compareValue := rfl
private theorem in_range : ∀ i : Fin 16,
    CC.Integers.MI.lt ((-32#64)+BitVec.ofNat 64 i.val) (-32#64) = false := by decide +kernel
private theorem compare_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (sp : CC.Block) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doEvalExpr world e (readTemps le sp) m compareValue = some (.Vint 1) := by
  have raw : (readTemps le sp).get Arm64Program._t'80 = some (.Vlong (-32#64)) := by
    simp only [readTemps,headerTemps,pointerTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'98 ≠ Arm64Program._t'80),
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'97 ≠ Arm64Program._t'80),CC.PTree.gss]
  have observed : (readTemps le sp).get Arm64Program._t'98 = some (.Vlong (-32#64)) := CC.PTree.gss _ _ _
  have counter : (readTemps le sp).get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [readTemps,headerTemps,pointerTemps,CC.PTree.gso] using hi
  have checked := in_range i
  have minus32 : (-32#64) = (18446744073709551584#64) := by decide +kernel
  rw [minus32] at checked
  simp +decide [compareValue,CC.doEvalExpr,raw,observed,counter,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tlong,CC.tulong,CC.tint,CC.tbool,
    CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.cmp,CC.Integers.MI.cmp,checked]
  all_goals rfl
private theorem compare_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doStep world (.State handler compare k e (readTemps le sp) m) =
      some (CC.E0,.State handler .Sskip k e (temps le sp) m) := by
  rw [compare_source]
  simp only [CC.doStep,compare_eval e le m sp i hi,temps]

private theorem returned (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    InternalRun world 9
      (.Returnstate (.Vlong (-32#64)) (.Kcall (some Arm64Program._t'80) handler e le (.Kseq rest k)) m)
      (.State handler .Sskip k e (temps le sp) m) := by
  refine .step (mid := .State handler .Sskip (.Kseq rest k) e (pointerTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e le m _ entry sp hentry pointer)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (read_step e le m _ sp observed)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ (compare_step e le m k sp i hi)) (.refl _)

/-- The true source-SP arm makes its real R1 pointer call and both actual
SP reads before the original signed(-32+i>=-32) comparison succeeds. -/
theorem execute (before m : CC.Mem) (entry sp : CC.Block) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (addresses : Arm64Registers.PointerOrigins)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry 0) 1 = some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    InternalRun world 39
      (.State handler Arm64MemcpyTransferCopyTag.sourceSP k (Arm64MemcpySource.allocation before).1 le m)
      (.State handler .Sskip k (Arm64MemcpySource.allocation before).1 (temps le sp) m) := by
  have start : InternalRun world 2
      (.State handler Arm64MemcpyTransferCopyTag.sourceSP k (Arm64MemcpySource.allocation before).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 1]
        (callCont before le k) m) := by
    rw [source.1]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (call_step before m entry le _ hentry) (.refl _))
  have layout : Arm64RegisterReads.GprLayout world := Arm64Select.Reads.layout
  have run := (Arm64RegisterReads.gpr_calls_bound world layout (by decide +kernel) addresses
    m.nextblock entry 0 (1 : Fin 31) m (callCont before le k) (.Vlong (-32#64)) (-32#64) (4#8) gpr rfl).2.2
  exact (start.trans run).trans (returned (Arm64MemcpySource.allocation before).1 le m k entry sp i hentry hi pointer observed)

private def changed : List CC.Ident := [Arm64Program._t'79,Arm64Program._t'98,Arm64Program._t'97,Arm64Program._t'80]
theorem kept (le : CC.TempEnv) (sp : CC.Block) (id : CC.Ident) (other : id ∉ changed) :
    (temps le sp).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,readTemps,headerTemps,pointerTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'79 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'98 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'97 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'80 (by decide +kernel))]

theorem observations (le : CC.TempEnv) (sp : CC.Block) :
    (temps le sp).get Arm64Program._t'79 = some (.Vint 1) ∧
    (temps le sp).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le sp).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le sp).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le sp).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at :=
  ⟨CC.PTree.gss _ _ _,kept le sp _ (by decide +kernel),kept le sp _ (by decide +kernel),
    kept le sp _ (by decide +kernel),kept le sp _ (by decide +kernel)⟩

/-- Current SP and R1 facts supply both real reads; the same packet and
eight live caller-local ranges reach the genuine true comparison result. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m
        (temps le prior.packet.storage.sp.block),
      InternalRun world 39
        (.State handler Arm64MemcpyTransferCopyTag.sourceSP k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 (temps le prior.packet.storage.sp.block) m) := by
  have read : CC.Mem.load .Mint64 m prior.packet.storage.sp.block 0 = some (.Vlong (-32#64)) := by
    rw [prior.packet.storage.spRead,prior.packet.spAtBase]
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute calleeBefore m entry.block _ le k i addresses prior.entryRead hi prior.packet.r1 prior.packet.storage.spPointer read⟩
  · exact (kept le _ Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le _ Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le _ Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le _ Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceSP
