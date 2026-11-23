import KProgFormal.ClightRefinement.X86LogicFlagNative
import KProgFormal.ClightRefinement.X86ShiftWriteback

namespace KProgFormal.ClightRefinement.X86LogicFlagStage
open X86LogicFlagOrder X86LogicFlagStores X86LogicFlagMemory

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_flag_continuation
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def widthBody : CC.Stmt := by
  run_tac cachePart (← `(match X86LogicFlagWidths.continuation .Kstop with
    | .Kloop1 body _ _ => body | _ => .Sskip))
private def widthTail : CC.Stmt := by
  run_tac cachePart (← `(match X86LogicFlagWidths.continuation .Kstop with
    | .Kloop1 _ _ (.Kseq _ (.Kseq tail _)) => tail | _ => .Sskip))
private def flagBody : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftLeftCarry.continuation .Kstop with
    | .Kloop1 body _ _ => body | _ => .Sskip))

theorem continuation_source (k : CC.Cont) :
    X86LogicFlagWidths.continuation k =
      .Kloop1 widthBody .Sbreak (.Kseq .Sbreak (.Kseq widthTail k)) := rfl

/-- The actual logical width/flag loop exits reach the original shared writer
in8 transitions, retaining the reached heap, locals and temporary map. -/
theorem resume_writer (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 8
      (.State function .Sskip
        (X86LogicFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) e le m)
      (.State function X86ShiftWriteback.writer k e le m) := by
  rw [continuation_source, (X86ShiftWriteback.continuation_source k).2]
  exact X86ShiftWriteback.resume_loops ge function e le k m widthBody widthTail flagBody
    X86ShiftWriteback.writer

def selectedTemps (le : CC.TempEnv) (places : Locations) (old : BitVec 8) : CC.TempEnv :=
  X86LogicFlagClassify.temps (X86ShiftLeftCarry.afterTemps le places.cf.1 places.cf.2 old)

def temps (le : CC.TempEnv) (places : Locations) (old : BitVec 8)
    (value : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  X86LogicFlagOrder.temps
    (X86LogicFlagWidths.preparedTemps (selectedTemps le places old) value size) places

def length (size : X86.Size) : Nat := 64 + X86LogicFlagWidths.length size + 31 + 8

private theorem selected_get (le : CC.TempEnv) (places : Locations) (old : BitVec 8) (id : CC.Ident)
    (kind : id ≠ X86_program_profile_bpf._t'43)
    (carry : id ≠ X86_program_profile_bpf.___x86_l_old_cf)
    (byte : id ≠ X86_program_profile_bpf._t'265) (pointer : id ≠ X86_program_profile_bpf._t'264) :
    (selectedTemps le places old).get id = le.get id := by
  exact ((X86LogicFlagClassify.observations
    (X86ShiftLeftCarry.afterTemps le places.cf.1 places.cf.2 old)).2 id kind).trans
      ((X86ShiftLeftCarry.temps le places.cf.1 places.cf.2 old).2.2.2 id carry byte pointer)

/-- The six original writer inputs retain their preceding values across
old-CF sampling, classifier, width helpers and all five flag stores. -/
theorem writer_observations (le : CC.TempEnv) (places : Locations) (old : BitVec 8)
    (value : BitVec 64) (size : X86.Size) :
    (temps le places old value size).get X86_program_profile_bpf.___x86_bind =
      le.get X86_program_profile_bpf.___x86_bind ∧
    (temps le places old value size).get X86_program_profile_bpf._dst =
      le.get X86_program_profile_bpf._dst ∧
    (temps le places old value size).get X86_program_profile_bpf.___x86_l_alu =
      le.get X86_program_profile_bpf.___x86_l_alu ∧
    (temps le places old value size).get X86_program_profile_bpf.___x86_l_width__1 =
      le.get X86_program_profile_bpf.___x86_l_width__1 ∧
    (temps le places old value size).get X86_program_profile_bpf.___x86_l_result =
      le.get X86_program_profile_bpf.___x86_l_result ∧
    (temps le places old value size).get X86_program_profile_bpf.___x86_l_dst_shift =
      le.get X86_program_profile_bpf.___x86_l_dst_shift := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals
    simp +decide only [temps, X86LogicFlagOrder.temps, CC.PTree.gso]
    rw [(X86LogicFlagWidths.observations _ value size).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    exact selected_get le places old _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)

/-- The complete actual logical flags stage executes from its original old-CF
load through classifier, three real width helpers, all five original stores
and loop exits to the unchanged writer, with native final bytes and header. -/
theorem to_writer (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (effectiveBlock applyBlock bitsBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (applyBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some applyBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv applyBlock =
        some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_apply_width = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none)
    (m cfHeap zfHeap sfHeap ofHeap after : CC.Mem) (bindingBlock : CC.Block) (places : Locations)
    (value : BitVec 64) (size : X86.Size) (af : Bool) (before : X86.Flags) (old code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (oldByte : CC.Mem.load .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (old.setWidth 32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (headers : HeaderLoads m bindingBlock places)
    (different : X86LogicFlagMemory.Distinct places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (cfStored : CC.Mem.store .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2)
      (.Vint (0#32)) = some cfHeap)
    (zfStored : CC.Mem.store .Mint8unsigned cfHeap places.zf.1 (CC.Integers.Ptrofs.unsigned places.zf.2)
      (X86ShiftFlagZF.bit (X86.Value.trunc size value)) = some zfHeap)
    (sfStored : CC.Mem.store .Mint8unsigned zfHeap places.sf.1 (CC.Integers.Ptrofs.unsigned places.sf.2)
      (signByte (X86.Value.trunc size value) size) = some sfHeap)
    (ofStored : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (.Vint (0#32)) = some ofHeap)
    (pfStored : CC.Mem.store .Mint8unsigned ofHeap places.pf.1 (CC.Integers.Ptrofs.unsigned places.pf.2)
      (X86ShiftFlagPF.bit (X86.Value.trunc size value)) = some after) :
    InternalRun ge (length size) (.State function X86ShiftLeftRoute.flags k e le m)
      (.State function X86ShiftWriteback.writer k e (temps le places old value size) after) ∧
    HeaderLoads after bindingBlock places ∧
    FlagsRepresent after places (X86.Flags.logic size (X86.Value.trunc size value) af before) := by
  let selected := selectedTemps le places old
  let prepared := X86LogicFlagWidths.preparedTemps selected value size
  have selectedBinding := (selected_get le places old X86_program_profile_bpf.___x86_bind
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans binding
  have selectedWord := (selected_get le places old X86_program_profile_bpf.___x86_l_result
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans word
  have selectedWidth := (selected_get le places old X86_program_profile_bpf.___x86_l_width__1
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans width
  have preparedBinding : prepared.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    rw [(X86LogicFlagWidths.observations selected value size).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    exact selectedBinding
  have classify := X86LogicFlagClassify.from_flags ge bindingsLayout valueLayout function e le k m
    code supported operation bindingBlock places.cf.1 places.cf.2 old binding headers.cf oldByte
  have prepare := X86LogicFlagWidths.prepare ge effectiveBlock applyBlock bitsBlock
    effectiveBinding applyBinding bitsBinding function e selected unshadowed value size
    (.Kswitch (X86ShiftLeftCarry.continuation k)) m selectedWord selectedWidth
  have stores := X86LogicFlagNative.internal ge bindingsLayout valueLayout function e prepared
    (X86LogicFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))
    m cfHeap zfHeap sfHeap ofHeap after bindingBlock places value size af before preparedBinding
    (X86LogicFlagWidths.observations selected value size).2.1
    (X86LogicFlagWidths.observations selected value size).2.2.1
    headers different separate cfStored zfStored sfStored ofStored pfStored
  have resume := resume_writer ge function e (X86LogicFlagOrder.temps prepared places) k after
  refine ⟨?_, stores.2.1, stores.2.2⟩
  exact ((classify.trans prepare).trans stores.1).trans resume

end KProgFormal.ClightRefinement.X86LogicFlagStage
