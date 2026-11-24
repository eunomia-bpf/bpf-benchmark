import KProgFormal.ClightRefinement.X86ProducerScalarInitialize

namespace KProgFormal.ClightRefinement.X86ProducerScalarPrefix
open X86ProducerHeaderSource (producer localName)
open X86ProducerHeaderLocals (Local SourceLocal)
open X86ProducerGhostStore (Locals)
open X86ProducerInitialPrefix (contextValues)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private theorem context_names : ∀ i : Fin 8, ∀ j : Fin 5,
    (X86ProducerScalarSource.site i).resultName ≠ X86ProducerContextSource.tempName j := by decide +kernel

private theorem outside_local (before : CC.Mem) {name : CC.Ident} {ty : CC.Ty}
    (object : Local ge.genv_cenv before name ty)
    (objects : X86ProducerScalarStage.Locals before) (cache : SourceLocal ge.genv_cenv before 1)
    (base : SourceLocal ge.genv_cenv before 14)
    (names : name ≠ localName (14 : Fin 24) ∧ name ≠ localName (1 : Fin 24) ∧
      ∀ i : Fin 8, name ≠ localName (X86ProducerScalarSource.row i)) :
    X86ProducerScalarInitialize.Outside objects cache base object.block :=
  ⟨X86ProducerGprStage.local_separate before object base names.1,
    X86ProducerGprStage.local_separate before object cache names.2.1,
    fun i => X86ProducerGprStage.local_separate before object (objects i) (names.2.2 i)⟩

/-- The SAME original full call now executes all GPR, base-zero and flag/XMM
initializers, carrying every prior typed observation and actual input trace.
The external provider ABI remains explicit; this does not bind native-memory
or provider-oracle semantics. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (inputs : X86ProducerRaxPrefix.Inputs before) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ ghosts : Locals before, ∃ gprs : SourceLocal ge.genv_cenv before 0,
    ∃ cache : SourceLocal ge.genv_cenv before 1, ∃ memory,
    ∃ gpr : X86ProducerGprChain.Result before memory (X86ProducerGprPrefix.initialTemps ctx) k gprs cache 16,
    ∃ objects : X86ProducerScalarStage.Locals before, ∃ base : SourceLocal ge.genv_cenv before 14,
    ∃ scalar : X86ProducerScalarInitialize.Result before gpr.after gpr.output k objects cache base,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx] k before) (CC.Eapp gpr.trace scalar.trace)
      (.State producer X86ProducerScalarSource.following k (allocation ge.genv_cenv before).1 scalar.output scalar.after) ∧
    (∀ i : Fin 16, CC.Mem.load CC.Mptr scalar.after gprs.block (16 * (i.val : Int)) = some (.Vlong (gpr.values i)) ∧
      CC.Mem.load .Mint8unsigned scalar.after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)) ∧
    gpr.values 4 = 0 ∧
    (∀ i : Fin 8, CC.Mem.load (X86ProducerScalarSource.chunk i) scalar.after (objects i).block 0 =
      some (X86ProducerScalarValue.value i (scalar.values i))) ∧
    CC.Mem.load .Mint64 scalar.after base.block 0 = some (.Vlong 0) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) scalar.after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) scalar.after (ghosts i).block 0 = some (X86ProducerGhostSource.value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, scalar.output.get (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    scalar.output.get X86_program_profile_bpf._ctx = some ctx ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c scalar.after b ofs = CC.Mem.load c before b ofs) ∧
    FrameBelow before.nextblock before memory ∧
    scalar.after.access = (allocation ge.genv_cenv before).2.access ∧
    scalar.after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, ghosts, gprs, cache, memory, gpr, priorRun, gprReads, rspZero, abiReads, ghostReads,
    typed, contextReads, callerReads, frame, access, frontier⟩ := X86ProducerGprPrefix.from_call before ctx k inputs
  let objects : X86ProducerScalarStage.Locals before :=
    fun i => Classical.choice (X86ProducerHeaderLocals.source_local ge.genv_cenv before (X86ProducerScalarSource.row i))
  obtain ⟨base⟩ := X86ProducerHeaderLocals.source_local ge.genv_cenv before 14
  obtain ⟨scalar⟩ := X86ProducerScalarInitialize.initialized before gpr.after gpr.output k objects cache base inputs access frontier
  have gprNames : localName (0 : Fin 24) ≠ localName (14 : Fin 24) ∧
      localName (0 : Fin 24) ≠ localName (1 : Fin 24) ∧
      ∀ i : Fin 8, localName (0 : Fin 24) ≠ localName (X86ProducerScalarSource.row i) := by decide +kernel
  have abiNames : X86_program_profile_bpf.___x86_sim_abi ≠ localName (14 : Fin 24) ∧
      X86_program_profile_bpf.___x86_sim_abi ≠ localName (1 : Fin 24) ∧
      ∀ i : Fin 8, X86_program_profile_bpf.___x86_sim_abi ≠ localName (X86ProducerScalarSource.row i) := by decide +kernel
  have ghostNames : ∀ j : Fin 12, localName (X86ProducerGhostSource.row j) ≠ localName (14 : Fin 24) ∧
      localName (X86ProducerGhostSource.row j) ≠ localName (1 : Fin 24) ∧
      ∀ i : Fin 8, localName (X86ProducerGhostSource.row j) ≠ localName (X86ProducerScalarSource.row i) := by decide +kernel
  have gprOutside := outside_local before gprs objects cache base gprNames
  have abiOutside := outside_local before abi objects cache base abiNames
  have initialContext : (X86ProducerGprPrefix.initialTemps ctx).get X86_program_profile_bpf._ctx = some ctx := by
    simp +decide [X86ProducerGprPrefix.initialTemps, X86ProducerGhostSource.finalTemps,
      X86ProducerGhostSource.contextTemps, X86ProducerEntry.initialTemps, CC.PTree.gso]
  have gprContextNames : ∀ i : Fin 16,
      (X86ProducerGprSites.site i).savedName ≠ X86_program_profile_bpf._ctx ∧
      (X86ProducerGprSites.site i).resultName ≠ X86_program_profile_bpf._ctx := by decide +kernel
  have scalarContextNames : ∀ i : Fin 8,
      (X86ProducerScalarSource.site i).resultName ≠ X86_program_profile_bpf._ctx := by decide +kernel
  refine ⟨abi, ghosts, gprs, cache, memory, gpr, objects, base, scalar,
    star_trans priorRun scalar.run, ?_, rspZero, scalar.reads, scalar.base_zero,
    ?_, ?_, typed, ?_, ?_, ?_, frame, scalar.access.trans access, scalar.frontier.trans frontier⟩
  · intro i
    exact ⟨(scalar.outside _ _ _ gprOutside).trans (gprReads i).1,
      (scalar.outside _ _ _ gprOutside).trans (gprReads i).2⟩
  · intro i
    exact (scalar.outside _ _ _ abiOutside).trans (abiReads i)
  · intro i
    exact (scalar.outside _ _ _ (outside_local before (ghosts i) objects cache base (ghostNames i))).trans (ghostReads i)
  · intro j
    exact (scalar.temporary _ (fun i => context_names i j)).trans (contextReads j)
  · exact (scalar.temporary _ scalarContextNames).trans ((gpr.temporary _ gprContextNames).trans initialContext)
  · intro c b ofs below
    have notObject {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) : b ≠ object.block := by
      intro equal
      have fresh := object.fresh
      rw [equal] at below
      omega
    exact (scalar.outside c b ofs ⟨notObject base, notObject cache, fun i => notObject (objects i)⟩).trans (callerReads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerScalarPrefix
