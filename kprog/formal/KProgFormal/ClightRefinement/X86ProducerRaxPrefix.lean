import KProgFormal.ClightRefinement.X86ProducerRaxReturn

namespace KProgFormal.ClightRefinement.X86ProducerRaxPrefix
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local SourceLocal)
open X86ProducerGhostStore (Locals)
open X86ProducerGhostSource (row finalTemps contextTemps)
open X86ProducerInitialPrefix (contextValues)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86ProducerInputReturn (temps)

/-- Explicit initial kind-6 platform ABI at heaps with the actual producer
allocation's permissions/frontier. No initialized header View is fabricated,
and this contract is not inferred from external determinacy/trace length. -/
def Inputs (before : CC.Mem) : Prop := ∀ memory,
  memory.access = (allocation ge.genv_cenv before).2.access →
  memory.nextblock = (allocation ge.genv_cenv before).2.nextblock →
  ∃ cache : SourceLocal ge.genv_cenv before 1, Nonempty (X86ReleaseProvider.Outcome ge cache.block memory)

private theorem separate (before : CC.Mem) {name other : CC.Ident} {ty otherTy : CC.Ty}
    (left : Local ge.genv_cenv before name ty) (right : Local ge.genv_cenv before other otherTy)
    (different : name ≠ other) : left.block ≠ right.block := by
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  exact (allocated_local_storage allocated).2 _ _ _ _ left.binding right.binding different

private theorem context_preserved (le : CC.TempEnv) (word : BitVec 64) (i : Fin 5) :
    (temps le word).get (X86ProducerContextSource.tempName i) = le.get (X86ProducerContextSource.tempName i) := by
  have names : ∀ i : Fin 5,
      X86_program_profile_bpf._t'1 ≠ X86ProducerContextSource.tempName i ∧
      X86_program_profile_bpf._t'2 ≠ X86ProducerContextSource.tempName i := by decide +kernel
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (names i).1, CC.PTree.gso _ _ _ _ (names i).2]

/-- The SAME original call's618-step initialization, actual provider outcome
and genuine return/RAX stores reach RCX. Every earlier ABI/ghost readback and
current context input survives via actual allocated-name separation. The
provider trace/full supplied heap remain explicit. Only typed caller LOADS
are framed across the provider; raw contents equality is claimed only for
source stores after its supplied heap, exactly as the existing ABI permits. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont) (inputs : Inputs before) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ ghosts : Locals before, ∃ gprs : SourceLocal ge.genv_cenv before 0,
    ∃ cache : SourceLocal ge.genv_cenv before 1, ∃ memory,
    ∃ outcome : X86ReleaseProvider.Outcome ge cache.block memory, ∃ middle after,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx] k before) outcome.trace
      (.State producer X86ProducerGprAddress.afterRax k (allocation ge.genv_cenv before).1
        (temps (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) outcome.value) after) ∧
    CC.Mem.store CC.Mptr outcome.supplied gprs.block 0 (.Vlong outcome.value) = some middle ∧
    CC.Mem.store .Mint8unsigned middle gprs.block 8 (.Vint 0) = some after ∧
    CC.Mem.load CC.Mptr after gprs.block 0 = some (.Vlong outcome.value) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 8 = some (.Vint 0) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) after (ghosts i).block 0 = some (X86ProducerGhostSource.value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, (temps (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) outcome.value).get
      (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    (∀ row : Fin 32, row ≠ 0 → row ≠ 1 →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) ∧
    FrameBelow before.nextblock before memory ∧ FrameBelow before.nextblock outcome.supplied after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, ghosts, memory, prefixRun, abiReads, ghostReads, typed, prefixInputs, prefixFrame, access, frontier⟩ :=
    X86ProducerFirstInputPrefix.from_call before ctx k
  obtain ⟨cache, ⟨outcome⟩⟩ := inputs memory access frontier
  obtain ⟨gprs⟩ := X86ProducerHeaderLocals.source_local ge.genv_cenv before 0
  obtain ⟨middle, after, returnRun, valueStored, tagStored, valueRead, tagRead,
    otherRows, outside, storeFrame, storeAccess, storeNext⟩ :=
    X86ProducerRaxReturn.execute before memory outcome.supplied
      (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) k outcome.value outcome.trace gprs
      outcome.call (outcome.access.trans access)
  have gprCache := separate before gprs cache (by decide +kernel)
  have abiCache := separate before abi cache (by decide +kernel)
  have abiGprs := separate before abi gprs (by decide +kernel)
  have names : ∀ i : Fin 12,
      X86ProducerHeaderSource.localName (row i) ≠ X86ProducerHeaderSource.localName (1 : Fin 24) ∧
      X86ProducerHeaderSource.localName (row i) ≠ X86ProducerHeaderSource.localName (0 : Fin 24) := by decide +kernel
  refine ⟨abi, ghosts, gprs, cache, memory, outcome, middle, after, ?_,
    valueStored, tagStored, valueRead, tagRead, ?_, ?_, typed, ?_, ?_, ?_,
    prefixFrame, storeFrame, storeAccess.trans (outcome.access.trans access), storeNext.trans (outcome.frontier.trans frontier)⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans prefixRun.sound returnRun
  · intro i
    exact (outside _ _ _ abiGprs).trans ((outcome.frame _ _ _ abiCache).trans (abiReads i))
  · intro i
    have ghostCache := separate before (ghosts i) cache (names i).1
    have ghostGprs := separate before (ghosts i) gprs (names i).2
    exact (outside _ _ _ ghostGprs).trans ((outcome.frame _ _ _ ghostCache).trans (ghostReads i))
  · intro i
    exact (context_preserved _ _ i).trans (prefixInputs i)
  · intro row notValue notTag
    exact (otherRows row notValue notTag).trans (outcome.frame _ _ _ gprCache)
  · intro c b ofs below
    have notGpr : b ≠ gprs.block := by
      intro equal
      have fresh := gprs.fresh
      rw [equal] at below
      omega
    have notCache : b ≠ cache.block := by
      intro equal
      have fresh := cache.fresh
      rw [equal] at below
      omega
    exact (outside c b ofs notGpr).trans ((outcome.frame c b ofs notCache).trans (prefixFrame.load c b ofs below))

end KProgFormal.ClightRefinement.X86ProducerRaxPrefix
