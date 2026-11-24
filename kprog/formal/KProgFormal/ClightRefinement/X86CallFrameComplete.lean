import KProgFormal.ClightRefinement.X86CallFrameClear

namespace KProgFormal.ClightRefinement.X86CallFrameComplete
open X86CallFrameClear (headerOffset)

structure Places where
  tag : Fin 6 → CC.Block × CC.Integers.Ptrofs
  pointer : Fin 6 → CC.Block × CC.Integers.Ptrofs

def Separated (binding : CC.Block) (places : Places) : Prop := ∀ slot,
  (places.tag slot).1 ≠ binding ∧ (places.pointer slot).1 ≠ binding ∧
    (places.tag slot).1 ≠ (places.pointer slot).1

structure View (memory : CC.Mem) (binding : CC.Block) (places : Places) : Prop where
  tags : ∀ slot, CC.Mem.load CC.Mptr memory binding (CC.Integers.Ptrofs.unsigned (headerOffset slot)) =
    some (.Vptr (places.tag slot).1 (places.tag slot).2)
  pointers : ∀ slot, CC.Mem.load CC.Mptr memory binding
    (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add (headerOffset slot) (CC.Integers.Ptrofs.repr 8))) =
      some (.Vptr (places.pointer slot).1 (places.pointer slot).2)
  tag_rights : ∀ slot, CC.Mem.validAccess memory .Mint8unsigned (places.tag slot).1
    (CC.Integers.Ptrofs.unsigned (places.tag slot).2) .Writable = true
  pointer_rights : ∀ slot, CC.Mem.validAccess memory CC.Mptr (places.pointer slot).1
    (CC.Integers.Ptrofs.unsigned (places.pointer slot).2) .Writable = true

def Ready (le : CC.TempEnv) (binding : CC.Block) (sp : BitVec 64) : Prop :=
  le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) ∧
  le.get X86_program_profile_bpf.___x86_sv_sp = some (.Vlong sp)

def Outside (places : Places) (block : CC.Block) : Prop := ∀ slot,
  block ≠ (places.tag slot).1 ∧ block ≠ (places.pointer slot).1

def Frame (places : Places) (before after : CC.Mem) : Prop := ∀ chunk block offset,
  Outside places block → CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset

private theorem stage_run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding : CC.Block) (places : Places) (sp : BitVec 64) (slot : Fin 6)
    (separate : Separated binding places) (view : View memory binding places) (ready : Ready le binding sp) :
    ∃ n after finalTemps, InternalRun ge n
      (.State function (X86CallFrameStages.stage slot) k e le memory)
      (.State function .Sskip k e finalTemps after) ∧
    View after binding places ∧ Ready finalTemps binding sp ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame places memory after := by
  cases decision : X86CallFrameStages.selected slot sp
  · refine ⟨4, memory, le, X86CallFrameStages.skipped ge function e le k memory slot sp ready.2 decision,
      view, ready, rfl, rfl, ?_⟩
    intro chunk block offset outside
    rfl
  · have safe := separate slot
    obtain ⟨middle, after, tagStored, pointerStored, run, tagBack, pointerBack, access, frontier, frame⟩ :=
      X86CallFrameClear.selected ge layout valueLayout function e le k memory slot binding
        (places.tag slot).1 (places.pointer slot).1 (places.tag slot).2 (places.pointer slot).2 sp
        ready.1 ready.2 decision (view.tags slot) (view.pointers slot) safe.1 safe.2.2
        (view.tag_rights slot) (view.pointer_rights slot)
    have afterView : View after binding places := by
      constructor
      · intro i
        exact (frame CC.Mptr binding _ (Ne.symm safe.1) (Ne.symm safe.2.1)).trans (view.tags i)
      · intro i
        exact (frame CC.Mptr binding _ (Ne.symm safe.1) (Ne.symm safe.2.1)).trans (view.pointers i)
      · intro i
        exact (CC.Mem.validAccess_store_eq pointerStored .Mint8unsigned (places.tag i).1 _ .Writable).trans
          ((CC.Mem.validAccess_store_eq tagStored .Mint8unsigned (places.tag i).1 _ .Writable).trans (view.tag_rights i))
      · intro i
        exact (CC.Mem.validAccess_store_eq pointerStored CC.Mptr (places.pointer i).1 _ .Writable).trans
          ((CC.Mem.validAccess_store_eq tagStored CC.Mptr (places.pointer i).1 _ .Writable).trans (view.pointer_rights i))
    have tempsKept := X86CallFrameClear.stable_temps le slot
      (places.tag slot).1 (places.pointer slot).1 (places.tag slot).2 (places.pointer slot).2
    refine ⟨17, after, _, run, afterView, ⟨tempsKept.1.trans ready.1, tempsKept.2.trans ready.2⟩,
      access, frontier, ?_⟩
    intro chunk block offset outside
    exact frame chunk block offset (outside slot).1 (outside slot).2

private def chain : List (Fin 6) → CC.Stmt
  | [] => .Sskip
  | [slot] => X86CallFrameStages.stage slot
  | slot :: rest => .Ssequence (X86CallFrameStages.stage slot) (chain rest)

private theorem original_chain : X86CallFrameEntry.afterSp = chain [0, 1, 2, 3, 4, 5] :=
  X86CallFrameStages.source

private theorem chain_run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (k : CC.Cont) (binding : CC.Block) (places : Places) (sp : BitVec 64)
    (separate : Separated binding places) (slots : List (Fin 6)) (le : CC.TempEnv) (memory : CC.Mem)
    (view : View memory binding places) (ready : Ready le binding sp) :
    ∃ n after finalTemps, InternalRun ge n (.State function (chain slots) k e le memory)
      (.State function .Sskip k e finalTemps after) ∧ View after binding places ∧ Ready finalTemps binding sp ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame places memory after := by
  induction slots generalizing le memory k with
  | nil =>
    refine ⟨0, memory, le, .refl _, view, ready, rfl, rfl, ?_⟩
    intro chunk block offset outside
    rfl
  | cons slot rest ih =>
    cases rest with
    | nil => exact stage_run ge layout valueLayout function e le k memory binding places sp slot separate view ready
    | cons next tail =>
      obtain ⟨n1, middle, middleTemps, first, middleView, middleReady, firstAccess, firstNext, firstFrame⟩ :=
        stage_run ge layout valueLayout function e le (.Kseq (chain (next :: tail)) k) memory
          binding places sp slot separate view ready
      obtain ⟨n2, after, finalTemps, remaining, finalView, finalReady, secondAccess, secondNext, secondFrame⟩ :=
        ih (k := k) middleTemps middle middleView middleReady
      have beginRun : InternalRun ge 1 (.State function (chain (slot :: next :: tail)) k e le memory)
          (.State function (X86CallFrameStages.stage slot) (.Kseq (chain (next :: tail)) k) e le memory) := by
        apply internalRun_of_steps
        all_goals simp only [chain, steps, InternalPath, InternalState, CC.doStep, CC.E0, CC.Eapp, true_and, List.nil_append]
      have continueRun : InternalRun ge 1
          (.State function .Sskip (.Kseq (chain (next :: tail)) k) e middleTemps middle)
          (.State function (chain (next :: tail)) k e middleTemps middle) := by
        apply internalRun_of_steps
        all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.E0, CC.Eapp, true_and, List.nil_append]
      refine ⟨_, after, finalTemps, ((beginRun.trans first).trans continueRun).trans remaining,
        finalView, finalReady, secondAccess.trans firstAccess, secondNext.trans firstNext, ?_⟩
      intro chunk block offset outside
      exact (secondFrame chunk block offset outside).trans (firstFrame chunk block offset outside)

private theorem finish (ge : CC.CGenv) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (boundary : CC.isCallCont k = true) :
    InternalRun ge 3
      (.State X86CallFrameEntry.handler .Sskip (X86CallFrameEntry.continuation k) CC.emptyEnv le memory)
      (.Returnstate .Vundef k memory) := by
  have freed : CC.Mem.freeList memory (CC.blocksOfEnv ge.genv_cenv CC.emptyEnv) = some memory := rfl
  cases k <;> simp only [CC.isCallCont, Bool.false_eq_true] at boundary
  all_goals apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, X86CallFrameEntry.continuation,
    CC.doStep, freed, CC.callCont, CC.E0, CC.Eapp]

/-- All six original guarded clearing loops execute from the actual post-SP
frontier, then leave the real enclosing loop, free no locals and return.
Initial header/rights and target separation derive every subsequent read/store;
no loop result or post-store success is assumed. -/
theorem body (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding : CC.Block) (places : Places) (sp : BitVec 64)
    (separate : Separated binding places) (view : View memory binding places) (ready : Ready le binding sp)
    (boundary : CC.isCallCont k = true) :
    ∃ n after, InternalRun ge n
      (.State X86CallFrameEntry.handler X86CallFrameEntry.afterSp (X86CallFrameEntry.continuation k) CC.emptyEnv le memory)
      (.Returnstate .Vundef k after) ∧ View after binding places ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame places memory after := by
  obtain ⟨n, after, finalTemps, run, finalView, finalReady, access, frontier, frame⟩ :=
    chain_run ge layout valueLayout X86CallFrameEntry.handler CC.emptyEnv
      (X86CallFrameEntry.continuation k) binding places sp separate [0,1,2,3,4,5] le memory view ready
  rw [← original_chain] at run
  exact ⟨_, after, run.trans (finish ge finalTemps k after boundary), finalView, access, frontier, frame⟩

/-- Complete genuine helper call for arbitrary signed raw SP, with both
real clearing/skip outcomes at all six slots and the exact caller return. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block) (base : CC.Integers.Ptrofs)
    (places : Places) (sp : BitVec 64)
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells base))
    (stackPointer : CC.Mem.load CC.Mptr memory cells
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add base (64#64))) = some (.Vlong sp))
    (separate : Separated binding places) (view : View memory binding places)
    (boundary : CC.isCallCont k = true) :
    ∃ n after, InternalRun ge n
      (.Callstate (.Internal X86CallFrameEntry.handler) [.Vptr binding 0] k memory)
      (.Returnstate .Vundef k after) ∧ View after binding places ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame places memory after := by
  let readyTemps := X86CallFrameEntry.temps (X86CallFrameEntry.initialTemps (.Vptr binding 0)) cells base sp
  have ready : Ready readyTemps binding sp := by
    simp +decide [Ready, readyTemps, X86CallFrameEntry.temps, X86CallFrameEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  obtain ⟨n, after, completed, finalView, access, frontier, frame⟩ :=
    body ge layout valueLayout readyTemps k memory binding places sp separate view ready boundary
  exact ⟨_, after, (X86CallFrameEntry.call ge layout k memory binding cells base sp header stackPointer).trans completed,
    finalView, access, frontier, frame⟩

/-- The real call site, complete six-slot helper, return and saved caller
restoration compose from the actual frame-call statement back to caller skip. -/
theorem from_site (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (caller : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding cells helper : CC.Block) (base : CC.Integers.Ptrofs) (places : Places) (sp : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (global : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (notLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells base))
    (stackPointer : CC.Mem.load CC.Mptr memory cells
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add base (64#64))) = some (.Vlong sp))
    (separate : Separated binding places) (view : View memory binding places) :
    ∃ n after, InternalRun ge n
      (.State caller X86RegisterWriteRspReleaseAdvance.frameCall k e le memory)
      (.State caller .Sskip k e le after) ∧ View after binding places ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame places memory after := by
  let readyTemps := X86CallFrameEntry.temps (X86CallFrameEntry.initialTemps (.Vptr binding 0)) cells base sp
  have ready : Ready readyTemps binding sp := by
    simp +decide [Ready, readyTemps, X86CallFrameEntry.temps, X86CallFrameEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  obtain ⟨n, after, completed, finalView, access, frontier, frame⟩ :=
    body ge layout valueLayout readyTemps (.Kcall none caller e le k) memory binding places sp separate view ready rfl
  have returned : InternalRun ge 1 (.Returnstate .Vundef (.Kcall none caller e le k) after)
      (.State caller .Sskip k e le after) := by
    apply internalRun_of_steps
    all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.setOpttemp, CC.E0, CC.Eapp]
  exact ⟨_, after,
    ((X86CallFrameEntry.from_site ge layout caller e le k memory binding cells helper base sp
      symbol global notLocal bindingRead header stackPointer).trans completed).trans returned,
    finalView, access, frontier, frame⟩

/-- Final real release-slot backedge/exit, complete helper and restored caller
retain initial headers/rights and frame every block outside the ghost targets. -/
theorem after_last (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (caller : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding cells helper : CC.Block) (base : CC.Integers.Ptrofs) (places : Places) (sp : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (global : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (notLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index (5 : Fin 6))))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells base))
    (stackPointer : CC.Mem.load CC.Mptr memory cells
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add base (64#64))) = some (.Vlong sp))
    (separate : Separated binding places) (view : View memory binding places) :
    ∃ n after, InternalRun ge n
      (.State caller .Sskip (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State caller .Sskip k e (le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (48#32))) after) ∧
    View after binding places ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    Frame places memory after := by
  let ready := le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (48#32))
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simp +decide [ready, CC.PTree.gso, bindingRead]
  obtain ⟨n, after, completeCall, finalView, access, frontier, frame⟩ :=
    from_site ge layout valueLayout caller e ready k memory binding cells helper base places sp
      symbol global notLocal bindingReady header stackPointer separate view
  exact ⟨_, after, (X86RegisterWriteRspReleaseAdvance.after_last ge caller e le k memory observedIndex).trans completeCall,
    finalView, access, frontier, frame⟩

end KProgFormal.ClightRefinement.X86CallFrameComplete
