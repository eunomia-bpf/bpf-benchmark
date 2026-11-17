import KProgFormal.ClightRefinement.Arm64Nop
import KProgFormal.ClightRefinement.Deallocation
import KProgFormal.ClightRefinement.Arm64NopDeclarations

namespace KProgFormal.ClightRefinement.Arm64Nop

/-- NOP ignores these values. Keeping arbitrary Clight values here does not
silently restrict pointers, undefined values, or the unused operand widths. -/
structure IgnoredArguments where
  entry : CC.Val
  dst : CC.Val
  src : CC.Val
  src2 : CC.Val
  src3 : CC.Val
  aux : CC.Val
  imm : CC.Val

def arguments (ignored : IgnoredArguments) (flags : BitVec 8) : List CC.Val :=
  [ignored.entry, .Vint 0, ignored.dst, ignored.src, ignored.src2,
    ignored.src3, Arm64Width.argument flags, ignored.aux, ignored.imm]

/-- The actual nine parameter bindings over all of the exported undef temps. -/
def initialTemps (ignored : IgnoredArguments) (flags : BitVec 8) : CC.TempEnv :=
  (((((((((CC.createUndefTemps handler.fn_temps).set
    Arm64Program._entry ignored.entry).set Arm64Program._op (.Vint 0)).set
    Arm64Program._dst ignored.dst).set Arm64Program._src ignored.src).set
    Arm64Program._src2 ignored.src2).set Arm64Program._src3 ignored.src3).set
    Arm64Program._flags (Arm64Width.argument flags)).set
    Arm64Program._aux ignored.aux).set Arm64Program._imm ignored.imm

private theorem bind_parameters (ignored : IgnoredArguments) (flags : BitVec 8) :
    CC.bindParameterTemps handler.fn_params (arguments ignored flags)
      (CC.createUndefTemps handler.fn_temps) = some (initialTemps ignored flags) := rfl

private theorem flags_temp (ignored : IgnoredArguments) (flags : BitVec 8) :
    (initialTemps ignored flags).get Arm64Program._flags =
      some (Arm64Width.argument flags) := by
  have hi : Arm64Program._imm ≠ Arm64Program._flags := by decide
  have ha : Arm64Program._aux ≠ Arm64Program._flags := by decide
  simp only [initialTemps, CC.PTree.gso _ _ _ _ hi, CC.PTree.gso _ _ _ _ ha, CC.PTree.gss]

private theorem op_temp (ignored : IgnoredArguments) (flags : BitVec 8) :
    (initialTemps ignored flags).get Arm64Program._op = some (.Vint 0) := by
  have hi : Arm64Program._imm ≠ Arm64Program._op := by decide
  have ha : Arm64Program._aux ≠ Arm64Program._op := by decide
  have hf : Arm64Program._flags ≠ Arm64Program._op := by decide
  have hs3 : Arm64Program._src3 ≠ Arm64Program._op := by decide
  have hs2 : Arm64Program._src2 ≠ Arm64Program._op := by decide
  have hs : Arm64Program._src ≠ Arm64Program._op := by decide
  have hd : Arm64Program._dst ≠ Arm64Program._op := by decide
  simp only [initialTemps, CC.PTree.gso _ _ _ _ hi, CC.PTree.gso _ _ _ _ ha,
    CC.PTree.gso _ _ _ _ hf, CC.PTree.gso _ _ _ _ hs3, CC.PTree.gso _ _ _ _ hs2,
    CC.PTree.gso _ _ _ _ hs, CC.PTree.gso _ _ _ _ hd, CC.PTree.gss]

/-- Production C allocation, once, for all locals even on the NOP path. -/
def allocation (ge : CC.CGenv) (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ge.genv_cenv CC.emptyEnv m handler.fn_vars

private theorem allocation_valid (ge : CC.CGenv) (m : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv m handler.fn_vars
      (allocation ge m).1 (allocation ge m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge m)).symm

/-- Actual function entry exists for every memory, ignored operand value and
flags byte. The exported declarations discharge all three name obligations. -/
theorem entry_valid (ge : CC.CGenv) (m : CC.Mem)
    (ignored : IgnoredArguments) (flags : BitVec 8) :
    CC.FunctionEntry2 ge handler (arguments ignored flags) m
      (allocation ge m).1 (initialTemps ignored flags) (allocation ge m).2 :=
  .intro Arm64NopDeclarations.vars_norepet Arm64NopDeclarations.params_norepet
    Arm64NopDeclarations.params_temps_disjoint
    (allocation_valid ge m) (bind_parameters ignored flags)

/-- The actual allocated locals cannot hide the exported internal width call. -/
theorem entry_unshadowed (ge : CC.CGenv) (m : CC.Mem) :
    (allocation ge m).1.get Arm64Program._arm64_width_effective = none :=
  by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using
      CC.allocVariables_env_other (allocation_valid ge m) Arm64NopDeclarations.width_not_local

/-- Function entry retains every caller byte and permission below nextblock. -/
theorem entry_frame (ge : CC.CGenv) (m : CC.Mem) :
    FrameBelow m.nextblock m (allocation ge m).2 :=
  (FrameBelow.allocVariables (allocation_valid ge m) m.nextblock (Nat.le_refl _)).2

/-- Certify all nineteen actual transitions, including function entry,
the internal width call and local deallocation. -/
private theorem execute_internal (ge : CC.CGenv) (m m' : CC.Mem)
    (binding : WidthBinding ge (allocation ge m).1) (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true)
    (hfree : CC.Mem.freeList (allocation ge m).2
      (CC.blocksOfEnv ge.genv_cenv
        (allocation ge m).1) = some m') :
    InternalRun ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.Returnstate .Vundef k m') := by
  let e := (allocation ge m).1
  let m1 := (allocation ge m).2
  let le := initialTemps ignored flags
  have enter : InternalRun ge 1
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.State handler handler.fn_body k e le m1) :=
    .step trivial (.internal_function _ _ _ _ _ _ _
      (entry_valid ge m ignored flags)) (.refl _)
  have run := body_internal ge e binding le m1 k flags
    (flags_temp ignored flags) (op_temp ignored flags)
  have leave : InternalRun ge 1
      (.State handler .Sskip k e (resultEnv le flags) m1)
      (.Returnstate .Vundef k m') :=
    .step trivial (.skip_call _ _ _ _ _ _ hk hfree) (.refl _)
  exact (enter.trans run).trans leave

/-- The actual allocated local environment always frees successfully and
preserves every caller block. Its enumeration needs no caller premise. -/
theorem return_frame (ge : CC.CGenv) (m : CC.Mem) :
    ∃ m', CC.Mem.freeList (allocation ge m).2
      (CC.blocksOfEnv ge.genv_cenv (allocation ge m).1) = some m' ∧
      FrameBelow m.nextblock m m' :=
  deallocate_locals (allocation_valid ge m)

/-- One procedure proof for any environment with the actual internal width
binding. Allocation, all nineteen internal transitions and freeing are derived. -/
theorem call_internal_bound (ge : CC.CGenv) (m : CC.Mem)
    (binding : WidthBinding ge (allocation ge m).1)
    (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ m', InternalRun ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' := by
  obtain ⟨m', free, frame⟩ := return_frame ge m
  exact ⟨m', execute_internal ge m m' binding ignored flags k hk free, frame⟩

/-- The standalone export is an instance of the same procedure proof. -/
theorem call_internal (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ m', InternalRun Arm64Program.prog.globalenv 19
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' :=
  call_internal_bound _ m
    (programBinding _ (entry_unshadowed Arm64Program.prog.globalenv m)) ignored flags k hk

/-- Complete actual C procedure execution, including successful allocation and
freeing, for arbitrary caller memory, ignored arguments and flags byte. -/
theorem call_returns (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ m', CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal handler) (arguments ignored flags) k m) CC.E0
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' := by
  obtain ⟨m', run, frame⟩ := call_internal m ignored flags k hk
  exact ⟨m', run.sound, frame⟩

private theorem return_stop_stuck (ge : CC.CGenv) (v : CC.Val) (m : CC.Mem) :
    ∀ t next, ¬ CC.Step2 ge (.Returnstate v .Kstop m) t next := by
  intro t next step
  cases step

/-- At the top-level procedure boundary, every finite relational execution
is a silent prefix of the nineteen-step return, every stuck endpoint is that
same full return state, and an infinite execution is impossible. Traces of
proposed executions are arbitrary, not assumed silent. General caller-control
composition remains separate because a Kcall return may resume its caller. -/
theorem call_all_behaviors (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8) :
    ∃ m', InternalRun Arm64Program.prog.globalenv 19
      (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m)
      (.Returnstate .Vundef .Kstop m') ∧ FrameBelow m.nextblock m m' ∧
      (∀ t other, CC.Star (CC.Step2 Arm64Program.prog.globalenv)
        (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun Arm64Program.prog.globalenv remaining other
          (.Returnstate .Vundef .Kstop m')) ∧
      (∀ t other, CC.Star (CC.Step2 Arm64Program.prog.globalenv)
        (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m) t other →
        (∀ u next, ¬ CC.Step2 Arm64Program.prog.globalenv other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop m') ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal handler) (arguments ignored flags) .Kstop m ∧
        ∀ i, ∃ t, CC.Step2 Arm64Program.prog.globalenv (states i) t (states (i + 1))) := by
  obtain ⟨m', run, frame⟩ := call_internal m ignored flags .Kstop rfl
  have stuck := return_stop_stuck Arm64Program.prog.globalenv .Vundef m'
  exact ⟨m', run, frame, fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed otherStuck => run.endpoint_unique stuck observed otherStuck,
    run.no_infinite stuck⟩

/-- The full native view transports through real C allocation and deallocation.
Only concrete decoder stability and the native/control representation remain
explicit; frame freshness and successful freeing are proved internally. -/
theorem call_corresponds (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true)
    (decodeHeap : CC.Mem → Reference.AArch64.State)
    (decode_frame : ∀ after, FrameBelow m.nextblock m after → decodeHeap after = decodeHeap m)
    (cursor : BitVec 64) (s : Reference.AArch64.State)
    (hrep : Represents decodeHeap cursor m s) (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    ∃ m', CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal handler) (arguments ignored flags) k m) CC.E0
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' ∧
    Reference.AArch64.step s = ⟨atCursor (cursor + (4#64)) (decodeHeap m'), [], none⟩ := by
  obtain ⟨m', call, frame⟩ := call_returns m ignored flags k hk
  refine ⟨m', call, frame, ?_⟩
  rw [decode_frame m' frame, reference_step s herror hfetch]
  unfold Represents at hrep
  rw [hrep]
  simp [atCursor, read_pc, write_pc, r_of_w_same, w_of_w_shadow]

end KProgFormal.ClightRefinement.Arm64Nop
