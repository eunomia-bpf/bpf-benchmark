import KProgFormal.ClightRefinement.X86ProducerSubFlagSource

namespace KProgFormal.ClightRefinement.X86ProducerSubOldCf
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubFlagSource (pointerLoad pointerTemp pointerExpr certificate)

private theorem cf_address (world : CC.CGenv)
    (bindingsLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (block : CC.Block) :
    CC.lvalOfField world X86ProducerHeaderSource.headerType X86_program_profile_bpf._cf (.Vptr block 0) = some (block,120,.Full) := by
  change CC.lvalOfField world (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) _ _ = _
  simp only [CC.lvalOfField,bindingsLayout,X86ShiftLeftCarry.cf_offset world.genv_cenv valueLayout]
  rfl

/-- Evaluate the SAME original header120 load using actual layout and a
current source read. Its whole statement and pointer temporary are retained. -/
theorem pointer (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (bindingBlock cfBlock : CC.Block)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 120 = some (.Vptr cfBlock 0)) :
    InternalRun ge 1 (.State handler pointerLoad k e le memory)
      (.State handler .Sskip k e (le.set pointerTemp (.Vptr cfBlock 0)) memory) := by
  have address := cf_address ge X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 bindingBlock
  have structAccess : CC.accessMode X86ProducerHeaderSource.headerType = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned120 : CC.Integers.Ptrofs.unsigned (120 : CC.Integers.Ptrofs) = 120 := rfl
  have evaluated : CC.doEvalExpr ge e le memory pointerExpr = some (.Vptr cfBlock 0) := by
    simp only [pointerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.typeof,CC.tptr,
      structAccess,ptrAccess,CC.Mem.loadv,binding,address,unsigned120,header]
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,X86ProducerSubFlagSource.pointer_source,
    evaluated,CC.E0,CC.Eapp,List.nil_append,true_and]

def byteLoad : CC.Stmt := by
  run_tac do
    let cert ← Lean.Elab.Term.elabTerm (← `(certificate CC.Positive.xH .Kstop CC.Mem.empty (0#64))) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubFlagSource.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cont)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual oldCF byte read missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_old_cf_byte node.getAppArgs[0]!

def byteExpr : CC.Expr := .Ederef (.Etempvar pointerTemp (CC.tptr CC.tuchar)) CC.tuchar

def byteTemp : CC.Ident := X86_program_profile_bpf._t'258

def castExpr : CC.Expr := .Ecast (.Etempvar byteTemp CC.tuchar) CC.tuchar

theorem byte_source : byteLoad = .Ssequence (.Sset byteTemp byteExpr)
    (.Sset X86_program_profile_bpf.___x86_l_old_cf castExpr) := by rfl

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual oldCF source parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerSubFlagSource.certificate arguments
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubFlagSource.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cont)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original oldCF byte continuation missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_old_cf_following node.getAppArgs[1]!

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (certificate binding k memory lhs).continuation = .Kseq byteLoad (following binding k memory lhs) := rfl

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (oldCf : CC.Val) : CC.TempEnv :=
  (((certificate binding k memory lhs).output.set pointerTemp (.Vptr cfBlock 0)).set byteTemp oldCf).set
    X86_program_profile_bpf.___x86_l_old_cf oldCf

/-- Actual oldCF byte dereference, intermediate temporary, uchar cast and
save all execute on precisely the SAME heap. No cast/result is assumed. -/
theorem byte (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (cfBlock : CC.Block) (word : BitVec 64)
    (current : le.get pointerTemp = some (.Vptr cfBlock 0))
    (read : CC.Mem.load .Mint8unsigned memory cfBlock 0 = some (X86ProducerScalarValue.value 0 word)) :
    InternalRun ge 4 (.State handler byteLoad k e le memory)
      (.State handler .Sskip k e
        ((le.set byteTemp (X86ProducerScalarValue.value 0 word)).set X86_program_profile_bpf.___x86_l_old_cf
          (X86ProducerScalarValue.value 0 word)) memory) := by
  have evaluated : CC.doEvalExpr ge e le memory byteExpr = some (X86ProducerScalarValue.value 0 word) := by
    simp only [byteExpr,CC.doEvalExpr,CC.doDerefLoc,CC.accessMode,CC.Mem.loadv,current]
    exact read
  have casted : CC.Cop.semCast (X86ProducerScalarValue.value 0 word) CC.tuchar CC.tuchar memory =
      some (X86ProducerScalarValue.value 0 word) := by
    simp [X86ProducerScalarValue.value,CC.tuchar,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,BitVec.and_assoc]
  have saved : CC.doEvalExpr ge e (le.set byteTemp (X86ProducerScalarValue.value 0 word)) memory castExpr =
      some (X86ProducerScalarValue.value 0 word) := by
    simp only [castExpr,CC.doEvalExpr,CC.PTree.gss,CC.typeof,casted]
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,byte_source,evaluated,saved,
    CC.E0,CC.Eapp,List.nil_append,true_and]

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Header and byte observations derive SAME original producer resources;
actual header load/byte read/save includes every real source transition. -/
theorem from_result (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) (k : CC.Cont) :
    InternalRun ge ((certificate ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))).count+6)
      (X86ProducerSubFlagSource.start ready.entry.block k complete.after (ready.stackOutcome.value-(8#64)))
      (.State handler .Sskip (following ready.entry.block k complete.after (ready.stackOutcome.value-(8#64)))
        (allocation complete.after).1
        (temps ready.entry.block k complete.after (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block
          (X86ProducerScalarValue.value 0 (ready.scalarValues 0))) (allocation complete.after).2) := by
  let cert := certificate ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))
  have headerRead := X86ProducerSubScalarResources.headers complete header 0
  have pointerRun := pointer (allocation complete.after).1 cert.output cert.continuation (allocation complete.after).2
    ready.entry.block (ready.scalars 0).block (X86ProducerSubFlagSource.binding _ _ _ _) headerRead
  have sequence : InternalRun ge 1
      (.State handler .Sskip cert.continuation (allocation complete.after).1
        (cert.output.set pointerTemp (.Vptr (ready.scalars 0).block 0)) (allocation complete.after).2)
      (.State handler byteLoad (following ready.entry.block k complete.after (ready.stackOutcome.value-(8#64)))
        (allocation complete.after).1 (cert.output.set pointerTemp (.Vptr (ready.scalars 0).block 0)) (allocation complete.after).2) := by
    rw [show cert.continuation = .Kseq byteLoad (following ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))) from source _ _ _ _]
    exact .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have byteRun := byte (allocation complete.after).1 (cert.output.set pointerTemp (.Vptr (ready.scalars 0).block 0))
    (following ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))) (allocation complete.after).2
    (ready.scalars 0).block (ready.scalarValues 0) (CC.PTree.gss _ _ _) (X86ProducerSubScalarResources.scalars complete 0)
  simpa only [Nat.add_assoc,temps,cert] using
    ((X86ProducerSubFlagSource.executes ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))).trans pointerRun).trans
      (sequence.trans byteRun)

end KProgFormal.ClightRefinement.X86ProducerSubOldCf
