import KProgFormal.ClightRefinement.X86ProducerGprChain

namespace KProgFormal.ClightRefinement.X86ProducerGprPrefix
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local SourceLocal)
open X86ProducerGhostStore (Locals)
open X86ProducerGhostSource (row finalTemps contextTemps)
open X86ProducerInitialPrefix (contextValues)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def initialTemps (ctx : CC.Val) : CC.TempEnv := finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))

private theorem context_names : ∀ i : Fin 16, ∀ j : Fin 5,
    (X86ProducerGprSites.site i).savedName ≠ X86ProducerContextSource.tempName j ∧
    (X86ProducerGprSites.site i).resultName ≠ X86ProducerContextSource.tempName j := by decide +kernel

/-- The SAME full original producer call executes its613-step entry/ABI/ghost
prefix followed by every original GPR initializer in order. Actual external
outcomes supply all15 ordinary GPR values; the real RSP branch supplies zero.
Every ABI/ghost readback, current context temporary and old caller typed load
survives. Real provider availability and its explicit memory ABI remain a
premise, and raw caller contents are not equated across that ABI. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (inputs : X86ProducerRaxPrefix.Inputs before) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ ghosts : Locals before, ∃ gprs : SourceLocal ge.genv_cenv before 0,
    ∃ cache : SourceLocal ge.genv_cenv before 1, ∃ memory,
    ∃ result : X86ProducerGprChain.Result before memory (initialTemps ctx) k gprs cache 16,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx] k before) result.trace
      (.State producer X86ProducerGprChain.following k (allocation ge.genv_cenv before).1 result.output result.after) ∧
    (∀ i : Fin 16, CC.Mem.load CC.Mptr result.after gprs.block (16 * (i.val : Int)) = some (.Vlong (result.values i)) ∧
      CC.Mem.load .Mint8unsigned result.after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)) ∧
    result.values 4 = 0 ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) result.after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) result.after (ghosts i).block 0 = some (X86ProducerGhostSource.value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, result.output.get (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c result.after b ofs = CC.Mem.load c before b ofs) ∧
    FrameBelow before.nextblock before memory ∧
    result.after.access = (allocation ge.genv_cenv before).2.access ∧
    result.after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, ghosts, memory, entryRun, abiReads, ghostReads, typed, contextReads, frame, access, frontier⟩ :=
    X86ProducerInitialPrefix.from_call before ctx k
  obtain ⟨gprs⟩ := X86ProducerHeaderLocals.source_local ge.genv_cenv before 0
  obtain ⟨cache⟩ := X86ProducerHeaderLocals.source_local ge.genv_cenv before 1
  obtain ⟨result⟩ := X86ProducerGprChain.complete before memory (initialTemps ctx) k gprs cache inputs access frontier
  have abiGprs := X86ProducerGprStage.local_separate before abi gprs (by decide +kernel)
  have abiCache := X86ProducerGprStage.local_separate before abi cache (by decide +kernel)
  have ghostNames : ∀ i : Fin 12,
      X86ProducerHeaderSource.localName (row i) ≠ X86ProducerHeaderSource.localName (0 : Fin 24) ∧
      X86ProducerHeaderSource.localName (row i) ≠ X86ProducerHeaderSource.localName (1 : Fin 24) := by decide +kernel
  have initialization : CC.Star (CC.Step2 ge)
      (.State producer X86ProducerGhostSource.beforeProvider k (allocation ge.genv_cenv before).1 (initialTemps ctx) memory)
      result.trace (.State producer X86ProducerGprChain.following k (allocation ge.genv_cenv before).1 result.output result.after) := by
    exact result.run
  refine ⟨abi, ghosts, gprs, cache, memory, result, ?_, ?_, result.rsp (by omega), ?_, ?_, typed, ?_, ?_, frame,
    result.access.trans access, result.frontier.trans frontier⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans entryRun.sound initialization
  · intro i
    exact result.reads i i.isLt
  · intro i
    exact (result.outside _ _ _ abiGprs abiCache).trans (abiReads i)
  · intro i
    have notGpr := X86ProducerGprStage.local_separate before (ghosts i) gprs (ghostNames i).1
    have notCache := X86ProducerGprStage.local_separate before (ghosts i) cache (ghostNames i).2
    exact (result.outside _ _ _ notGpr notCache).trans (ghostReads i)
  · intro j
    exact (result.temporary _ (fun i => context_names i j)).trans (contextReads j)
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
    exact (result.outside c b ofs notGpr notCache).trans (frame.load c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerGprPrefix
