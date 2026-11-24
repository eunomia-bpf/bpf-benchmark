import KProgFormal.ClightRefinement.X86ProducerScalarPrefix
import KProgFormal.ClightRefinement.X86ProducerStackBaseSource

namespace KProgFormal.ClightRefinement.X86ProducerStackBasePrefix
open X86ProducerHeaderSource (producer localName)
open X86ProducerHeaderLocals (Local SourceLocal)
open X86ProducerGhostStore (Locals)
open X86ProducerInitialPrefix (contextValues)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- The SAME original full entry, all GPR/flag/XMM initialization and real
return-zero store reach the actual kind1 Callstate. Every constructed typed
observation survives, without asserting a kind1 outcome or its memory ABI. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (inputs : X86ProducerRaxPrefix.Inputs before) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ ghosts : Locals before, ∃ gprs : SourceLocal ge.genv_cenv before 0,
    ∃ cache : SourceLocal ge.genv_cenv before 1, ∃ memory,
    ∃ gpr : X86ProducerGprChain.Result before memory (X86ProducerGprPrefix.initialTemps ctx) k gprs cache 16,
    ∃ objects : X86ProducerScalarStage.Locals before, ∃ base : SourceLocal ge.genv_cenv before 14,
    ∃ scalar : X86ProducerScalarInitialize.Result before gpr.after gpr.output k objects cache base,
    ∃ ret : SourceLocal ge.genv_cenv before 23, ∃ after,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx] k before) (CC.Eapp gpr.trace scalar.trace)
      (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (1#32)]
        (X86ProducerStackBaseSource.continuation (allocation ge.genv_cenv before).1 scalar.output k) after) ∧
    (∀ i : Fin 16, CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong (gpr.values i)) ∧
      CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)) ∧
    gpr.values 4 = 0 ∧
    (∀ i : Fin 8, CC.Mem.load (X86ProducerScalarSource.chunk i) after (objects i).block 0 =
      some (X86ProducerScalarValue.value i (scalar.values i))) ∧
    CC.Mem.load .Mint64 after base.block 0 = some (.Vlong 0) ∧
    CC.Mem.load .Mint64 after ret.block 0 = some (.Vlong 0) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) after (ghosts i).block 0 = some (X86ProducerGhostSource.value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, scalar.output.get (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    scalar.output.get X86_program_profile_bpf._ctx = some ctx ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) ∧
    FrameBelow before.nextblock before memory ∧ FrameBelow before.nextblock scalar.after after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, ghosts, gprs, cache, memory, gpr, objects, base, scalar, priorRun, gprReads, rspZero,
    scalarReads, baseRead, abiReads, ghostReads, typed, contextReads, ctxRead, callerReads, frame, access, frontier⟩ :=
    X86ProducerScalarPrefix.from_call before ctx k inputs
  obtain ⟨ret⟩ := X86ProducerHeaderLocals.source_local ge.genv_cenv before 23
  obtain ⟨after, zeroRun, zeroStored, retRead, outside, postFrame, rights, next⟩ :=
    X86ProducerStackBaseSource.return_zero before scalar.after scalar.output k ret access
  have enterRun := X86ProducerStackBaseSource.enter before after scalar.output k
  have localNames : localName (0 : Fin 24) ≠ localName (23 : Fin 24) ∧
      localName (14 : Fin 24) ≠ localName (23 : Fin 24) ∧
      X86_program_profile_bpf.___x86_sim_abi ≠ localName (23 : Fin 24) := by decide +kernel
  have scalarNames : ∀ i : Fin 8, localName (X86ProducerScalarSource.row i) ≠ localName (23 : Fin 24) := by decide +kernel
  have ghostNames : ∀ i : Fin 12, localName (X86ProducerGhostSource.row i) ≠ localName (23 : Fin 24) := by decide +kernel
  have gprSeparate := X86ProducerGprStage.local_separate before gprs ret localNames.1
  have baseSeparate := X86ProducerGprStage.local_separate before base ret localNames.2.1
  have abiSeparate := X86ProducerGprStage.local_separate before abi ret localNames.2.2
  refine ⟨abi, ghosts, gprs, cache, memory, gpr, objects, base, scalar, ret, after, ?_, ?_, rspZero,
    ?_, (outside _ _ _ baseSeparate).trans baseRead, retRead, ?_, ?_, typed, contextReads, ctxRead,
    ?_, frame, postFrame, rights.trans access, next.trans frontier⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans priorRun (zeroRun.trans enterRun).sound
  · intro i
    exact ⟨(outside _ _ _ gprSeparate).trans (gprReads i).1, (outside _ _ _ gprSeparate).trans (gprReads i).2⟩
  · intro i
    exact (outside _ _ _ (X86ProducerGprStage.local_separate before (objects i) ret (scalarNames i))).trans (scalarReads i)
  · intro i
    exact (outside _ _ _ abiSeparate).trans (abiReads i)
  · intro i
    exact (outside _ _ _ (X86ProducerGprStage.local_separate before (ghosts i) ret (ghostNames i))).trans (ghostReads i)
  · intro c b ofs below
    have notRet : b ≠ ret.block := by
      intro equal
      have fresh := ret.fresh
      rw [equal] at below
      omega
    exact (outside c b ofs notRet).trans (callerReads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerStackBasePrefix
