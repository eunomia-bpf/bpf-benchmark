import KProgFormal.ClightRefinement.Arm64MemcpyTransferGuardPrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceAddress

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64MemcpyTransferLoop (active)

private structure Parts where
  setup : CC.Stmt
  guard : CC.Stmt
  call : CC.Stmt
  rest : CC.Stmt
  biasRead : CC.Stmt
  sourceSet : CC.Stmt
  sourceValue : CC.Expr
  test : CC.Expr
  alignedBody : CC.Stmt
  tagLoop : CC.Stmt
  payload : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy transfer source address changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyGates.copyBody)) none) ``CC.Stmt.Ssequence 2
    let setup ← peel root[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel setup[1]! ``CC.Stmt.Ssequence 2
    let setter ← peel rest[1]! ``CC.Stmt.Sset 2
    let guard ← peel root[1]! ``CC.Stmt.Sifthenelse 3
    let aligned ← peel guard[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_source_address
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,setup[0]!,setup[1]!,rest[0]!,rest[1]!,
        setter[1]!,guard[0]!,guard[1]!,aligned[0]!,aligned[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_source_address_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def biasRead : CC.Stmt := by run_tac cachePart (← `(parts.biasRead))
private def sourceSet : CC.Stmt := by run_tac cachePart (← `(parts.sourceSet))
private def sourceValue : CC.Expr := by run_tac cachePart (← `(parts.sourceValue))
private def test : CC.Expr := by run_tac cachePart (← `(parts.test))
private def alignedBody : CC.Stmt := by run_tac cachePart (← `(parts.alignedBody))
def tagLoop : CC.Stmt := by run_tac cachePart (← `(parts.tagLoop))
def payload : CC.Stmt := by run_tac cachePart (← `(parts.payload))
private theorem source : Arm64MemcpyTransferCopyGates.copyBody = .Ssequence setup guard ∧
    setup = .Ssequence call rest ∧ rest = .Ssequence biasRead sourceSet ∧
    sourceSet = .Sset Arm64Program.___a64_mt_src sourceValue ∧
    guard = .Sifthenelse test alignedBody .Sskip ∧ alignedBody = .Ssequence tagLoop payload :=
  ⟨rfl,rfl,rfl,rfl,rfl,rfl⟩

def position (i : Fin 16) : BitVec 64 := (64#64)+BitVec.ofNat 64 i.val
private def pointerTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'73 (.Vlong (-32#64))
private def biasTemps (le : CC.TempEnv) : CC.TempEnv := (pointerTemps le).set Arm64Program._t'94 (.Vlong 96)
def temps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv := (biasTemps le).set Arm64Program.___a64_mt_src (.Vlong (position i))
def continuation (k : CC.Cont) : CC.Cont := .Kseq payload (Arm64MemcpyTransferCopyGates.continuation k)
private def callCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'73) handler (Arm64MemcpySource.allocation before).1 le
    (.Kseq rest (.Kseq guard (Arm64MemcpyTransferCopyGates.continuation k)))

private theorem call_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler call k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 1]
        (.Kcall (some Arm64Program._t'73) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
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
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel
private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State handler biasRead k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'94 (.Vlong 96)) m) := by
  simp only [biasRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tlong,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,bias]

private theorem source_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doEvalExpr world e (biasTemps le) m sourceValue = some (.Vlong (position i)) := by
  have raw : (biasTemps le).get Arm64Program._t'73 = some (.Vlong (-32#64)) := by
    simp only [biasTemps,pointerTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'94 ≠ Arm64Program._t'73),CC.PTree.gss]
  have bias : (biasTemps le).get Arm64Program._t'94 = some (.Vlong 96) := CC.PTree.gss _ _ _
  have counter : (biasTemps le).get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [biasTemps,pointerTemps,CC.PTree.gso] using hi
  simp +decide [sourceValue,CC.doEvalExpr,raw,bias,counter,position,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tlong,CC.tulong,
    CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.repr,CC.Integers.MI.repr]
private theorem source_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doStep world (.State handler sourceSet k e (biasTemps le) m) =
      some (CC.E0,.State handler .Sskip k e (temps le i) m) := by
  rw [source.2.2.2.1]
  simp only [CC.doStep,source_eval e le m i hi,temps]
private theorem aligned_data : ∀ i : Fin 16, active i = true →
    (position i &&& (7#64) == (0#64)) = true := by decide +kernel
private theorem test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (chosen : active i = true) :
    CC.doEvalExpr world e (temps le i) m test = some (.Vint 1) := by
  simp only [test,CC.doEvalExpr,temps,CC.PTree.gss,CC.Cop.semUnaryOperation,CC.Cop.semNotbool,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tulong,CC.tuint,CC.tint,ite_true,ite_false,CC.Archi.ptr64,CC.Integers.Int.repr,
    CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.zero,CC.Integers.MI.zero,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
  change some (CC.Val.ofBool (!( !(position i &&& (7#64) == (0#64))))) = _
  rw [Bool.not_not,aligned_data i chosen]
  rfl
private theorem returned (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (chosen : active i = true)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 9 (.Returnstate (.Vlong (-32#64)) (callCont before le k) m)
      (.State handler tagLoop (continuation k) (Arm64MemcpySource.allocation before).1 (temps le i) m) := by
  have entryRead : (pointerTemps le).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [pointerTemps,CC.PTree.gso] using hentry
  refine .step (mid := .State handler .Sskip
    (.Kseq rest (.Kseq guard (Arm64MemcpyTransferCopyGates.continuation k)))
    (Arm64MemcpySource.allocation before).1 (pointerTemps le) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step _ (pointerTemps le) m _ entry entryRead bias)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (source_step _ le m _ i hi)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2.2.1]
  refine .step (mid := .State handler alignedBody (Arm64MemcpyTransferCopyGates.continuation k)
    (Arm64MemcpySource.allocation before).1 (temps le i) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,test_eval _ le m i chosen]
    rfl
  rw [source.2.2.2.2.2]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The actual copy arm calls pointer(R1), reads the actual bias, assigns
source64+i and selects the real source-tag loop at the original indices. -/
theorem execute (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (addresses : Arm64Registers.PointerOrigins) (chosen : active i = true)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry 0) 1 = some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 40
      (.State handler Arm64MemcpyTransferCopyGates.copyBody (Arm64MemcpyTransferCopyGates.continuation k)
        (Arm64MemcpySource.allocation before).1 le m)
      (.State handler tagLoop (continuation k) (Arm64MemcpySource.allocation before).1 (temps le i) m) := by
  have start : InternalRun world 3
      (.State handler Arm64MemcpyTransferCopyGates.copyBody (Arm64MemcpyTransferCopyGates.continuation k)
        (Arm64MemcpySource.allocation before).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer) [.Vptr entry 0,.Vlong 1]
        (callCont before le k) m) := by
    rw [source.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.1]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (call_step before m entry le _ hentry) (.refl _))
  have layout : Arm64RegisterReads.GprLayout world := Arm64Select.Reads.layout
  have run := (Arm64RegisterReads.gpr_calls_bound world layout (by decide +kernel) addresses
    m.nextblock entry 0 (1 : Fin 31) m (callCont before le k) (.Vlong (-32#64)) (-32#64) (4#8) gpr rfl).2.2
  exact (start.trans run).trans (returned before m entry le k i chosen hentry hi bias)

private def changed : List CC.Ident := [Arm64Program.___a64_mt_src,Arm64Program._t'94,Arm64Program._t'73]
theorem kept (le : CC.TempEnv) (i : Fin 16) (id : CC.Ident) (other : id ∉ changed) :
    (temps le i).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,biasTemps,pointerTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_src (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'94 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'73 (by decide +kernel))]

theorem observations (le : CC.TempEnv) (i : Fin 16) :
    (temps le i).get Arm64Program.___a64_mt_src = some (.Vlong (position i)) ∧
    (temps le i).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le i).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le i).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le i).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at :=
  ⟨CC.PTree.gss _ _ _,kept le i _ (by decide +kernel),kept le i _ (by decide +kernel),
    kept le i _ (by decide +kernel),kept le i _ (by decide +kernel)⟩

/-- The same current packet supplies the real R1 and bias reads and retains
all copied bytes and eight caller-local resources at the source-tag loop. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (chosen : active i = true)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m (temps le i),
      InternalRun world 40
        (.State handler Arm64MemcpyTransferCopyGates.copyBody (Arm64MemcpyTransferCopyGates.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler tagLoop (continuation k) (Arm64MemcpySource.allocation calleeBefore).1 (temps le i) m) := by
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute calleeBefore m entry.block le k i addresses chosen prior.entryRead hi prior.packet.r1 prior.packet.view.bias⟩
  · exact (kept le i Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le i Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le i Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le i Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceAddress
