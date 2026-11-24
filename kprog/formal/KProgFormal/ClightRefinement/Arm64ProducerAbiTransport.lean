import KProgFormal.ClightRefinement.Arm64ProducerAbiInit
import KProgFormal.ClightRefinement.Arm64ProgramEntryInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiTransport

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (TailLocal)

private def Away (e : CC.Env) (cell : CC.Block) (stmt : CC.Stmt) : Prop :=
  ∃ id ty rhs block chunk, stmt = .Sassign (.Evar id ty) rhs ∧
    e.get id = some (block,ty) ∧ cell ≠ block ∧ CC.accessMode ty = .By_value chunk

/-- Invert the actual assignment/sequence transitions, retaining all loads
of the distinct allocated local. No successful protected read is assumed. -/
private theorem stores_preserve {ge : CC.CGenv} (front : List CC.Stmt)
    (f : CC.Function) (rest : CC.Stmt) (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv)
    (cell : CC.Block) (away : ∀ stmt ∈ front, Away e cell stmt)
    (before after : CC.Mem)
    (run : InternalRun ge (3 * front.length)
      (.State f (front.foldr CC.Stmt.Ssequence rest) k e le before)
      (.State f rest k e le after)) :
    ∀ chunk ofs, CC.Mem.load chunk after cell ofs = CC.Mem.load chunk before cell ofs := by
  induction front generalizing before with
  | nil =>
    cases run
    intro chunk ofs
    rfl
  | cons head tail ih =>
    obtain ⟨id,ty,rhs,block,sourceChunk,rfl,binding,different,scalar⟩ := away head (by simp)
    have count : 3 * (CC.Stmt.Sassign (.Evar id ty) rhs :: tail).length =
        ((3 * tail.length+1)+1)+1 := by simp only [List.length_cons]; omega
    rw [count] at run
    simp only [List.foldr] at run
    cases run with
    | step _ first following =>
      cases first <;> try (simp_all [CC.isCallCont]; done)
      cases following with
      | step _ assigned following =>
        cases assigned with
        | assign _ _ _ _ _ _ _ loc offset bits v2 value middle hlv he hc ha =>
          have target : CC.EvalLvalue ge e le before (.Evar id ty) block 0 .Full :=
            .Evar_local _ _ _ binding
          obtain ⟨sameBlock,sameOffset,sameBits⟩ := CC.evalLvalue_determ hlv target
          cases sameBlock
          cases sameOffset
          cases sameBits
          cases ha with
          | value _ storedChunk _ mode stored =>
            cases following with
            | step _ skip following =>
              cases skip <;> try (simp_all [CC.isCallCont]; done)
              have kept := ih (fun stmt member => away stmt (List.mem_cons.mpr (.inr member))) _ following
              intro chunk ofs
              exact (kept chunk ofs).trans (CC.Mem.load_store_other stored chunk cell ofs (.inl different))
          | copy _ _ _ _ mode _ _ _ _ _ =>
            simp only [CC.typeof,scalar] at mode
            cases mode

private theorem cancel_prefix {ge : CC.CGenv} {n m : Nat} {start middle last : CC.State}
    (headRun : InternalRun ge n start middle) (whole : InternalRun ge (n+m) start last) :
    InternalRun ge m middle last := by
  induction headRun with
  | refl _ => simpa using whole
  | @step n start next middle hs step tail ih =>
    have reordered : InternalRun ge ((n+m)+1) start last := by
      simpa only [Nat.add_assoc,Nat.add_comm,Nat.add_left_comm] using whole
    cases reordered with
    | step _ other remaining =>
      have same := (internal_step_unique hs step other).2
      cases same
      exact ih remaining

private theorem actual_binding {initial : CC.Mem} (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = some (block,ty) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty binding
  simpa only [name,type] using actual

private theorem cache_away (initial : CC.Mem) (kind : TailLocal initial 6) :
    ∀ stmt ∈ Arm64Producer.cacheAssignments, Away (allocation initial).1 kind.block stmt := by
  obtain ⟨stack⟩ := Arm64Producer.cache_locals false initial
  obtain ⟨ret⟩ := Arm64Producer.cache_locals true initial
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have sb := actual_binding _ _ _ stack.baseBinding (by decide +kernel) rfl
  have rb := actual_binding _ _ _ ret.baseBinding (by decide +kernel) rfl
  have sv := actual_binding _ _ _ stack.validBinding (by decide +kernel) rfl
  have rv := actual_binding _ _ _ ret.validBinding (by decide +kernel) rfl
  intro stmt member
  simp only [Arm64Producer.cacheAssignments,List.mem_cons,List.not_mem_nil,or_false] at member
  rcases member with rfl | rfl | rfl | rfl
  · exact ⟨_,_,_,_,_,rfl,sb,distinct _ _ _ _ kind.binding stack.baseBinding (by decide +kernel),rfl⟩
  · exact ⟨_,_,_,_,_,rfl,rb,distinct _ _ _ _ kind.binding ret.baseBinding (by decide +kernel),rfl⟩
  · exact ⟨_,_,_,_,_,rfl,sv,distinct _ _ _ _ kind.binding stack.validBinding (by decide +kernel),rfl⟩
  · exact ⟨_,_,_,_,_,rfl,rv,distinct _ _ _ _ kind.binding ret.validBinding (by decide +kernel),rfl⟩

/-- Every complete original580-transition cache prefix retains the ABI byte
produced by its own original568-transition initializer. -/
theorem cache_observed (initial after : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (whole : InternalRun world 580
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after)) :
    CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) := by
  obtain ⟨before,run,_access,_next,_frame,read⟩ := Arm64ProducerAbiInit.prefix_with_kind initial ctx k kind
  have tail : InternalRun world 12
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.cacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after) :=
    cancel_prefix run (by simpa using whole)
  rw [Arm64ProgramEntryPrefix.cache_source] at tail
  exact (stores_preserve Arm64Producer.cacheAssignments _ _ _ _ _ kind.block (cache_away initial kind)
    before after tail .Mint8unsigned 0).trans read

private theorem setup_away (initial : CC.Mem) (kind : TailLocal initial 6) :
    ∀ stmt ∈ Arm64Producer.setupAssignments, Away (allocation initial).1 kind.block stmt := by
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  intro stmt member
  simp only [Arm64Producer.setupAssignments,List.mem_cons,List.not_mem_nil,or_false] at member
  rcases member with rfl | rfl | rfl
  · obtain ⟨block,binding,_⟩ := Arm64Producer.local_storage initial Arm64Entry.___a64_sim_is_xdp CC.tuchar (by decide +kernel)
    exact ⟨_,_,_,block,_,rfl,actual_binding _ _ _ binding (by decide +kernel) rfl,
      distinct _ _ _ _ kind.binding binding (by decide +kernel),rfl⟩
  · obtain ⟨block,binding,_⟩ := Arm64Producer.local_storage initial Arm64Entry.___a64_sim_helper_ctx (CC.tptr CC.tvoid) (by decide +kernel)
    exact ⟨_,_,_,block,_,rfl,actual_binding _ _ _ binding (by decide +kernel) rfl,
      distinct _ _ _ _ kind.binding binding (by decide +kernel),rfl⟩
  · obtain ⟨block,binding,_⟩ := Arm64Producer.local_storage initial Arm64Entry.___a64_sim_helper_abi_base (CC.tptr CC.tvoid) (by decide +kernel)
    exact ⟨_,_,_,block,_,rfl,actual_binding _ _ _ binding (by decide +kernel) rfl,
      distinct _ _ _ _ kind.binding binding (by decide +kernel),rfl⟩

/-- Every real589-transition setup prefix retains that same initialized byte
through all four cache stores and the actual three setup stores. -/
theorem setup_observed (initial after : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (whole : InternalRun world 589
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after)) :
    CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) := by
  obtain ⟨before,run,_caches,_frame,_access,_next⟩ := Arm64ProgramEntryPrefix.entry_caches_initialized initial ctx k
  have read := cache_observed initial before ctx k kind run
  have tail : InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after) :=
    cancel_prefix run (by simpa using whole)
  rw [Arm64ProgramEntryInputs.setup_source] at tail
  exact (stores_preserve Arm64Producer.setupAssignments _ _ _ _ _ kind.block (setup_away initial kind)
    before after tail .Mint8unsigned 0).trans read

/-- The original first kind6 provider boundary retains its actual caches,
caller frame, allocation frontier and the ABI byte from the same source run. -/
theorem first_provider (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) (kind : TailLocal initial 6) :
    ∃ before, InternalRun world 594
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (Arm64ProgramEntryInputs.inputContinuation initial (Arm64ProgramEntryCall.initialTemps ctx) k) before) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial before ∧ FrameBelow initial.nextblock initial before ∧
      before.access = (allocation initial).2.access ∧ before.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned before kind.block 0 = some (.Vint 2) := by
  obtain ⟨before,run,caches,frame,access,next⟩ := Arm64ProgramEntryInputs.entry_setup initial ctx k
  exact ⟨before,run.trans (Arm64ProgramEntryInputs.first_call_ready initial before _ k),
    caches,frame,access,next,setup_observed initial before ctx k kind run⟩

end KProgFormal.ClightRefinement.Arm64ProducerAbiTransport
