import KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSequence

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPREntry
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext (ABI)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerGPRFrames (localRead Initialized)
open Arm64CiliumCallerGPRSequence (Outside Outcomes finalTemps)

theorem abi_outside : Outside ___a64_sim_abi := by
  unfold Outside
  decide +kernel

theorem defaults_outside : ∀ i : Fin 9,Outside (Arm64CiliumCallerDefaults.name i) := by
  unfold Outside
  decide +kernel

/-- Resolve the original ABI identifier in the actual allocated environment;
the existing outside-local frame therefore preserves every real ABI load. -/
theorem abi_frame {m before after : CC.Mem} (abi : ABI m)
    (frame : ∀ id,Outside id → ∀ c o,localRead m after id c o = localRead m before id c o) :
    ∀ c o,CC.Mem.load c after abi.block o = CC.Mem.load c before abi.block o := by
  intro c o
  simpa only [localRead,abi.binding,Option.bind_some] using
    frame ___a64_sim_abi abi_outside c o

theorem defaults_frame {m before after : CC.Mem} (locals : Locals m)
    (frame : ∀ id,Outside id → ∀ c o,localRead m after id c o = localRead m before id c o) :
    ∀ i,CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) after (locals.block i) 0 =
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) before (locals.block i) 0 := by
  intro i
  simpa only [localRead,locals.binding i,Option.bind_some] using
    frame (Arm64CiliumCallerDefaults.name i) (defaults_outside i) (Arm64CiliumCallerDefaults.chunk i) 0

noncomputable def contextTemps (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs) : CC.TempEnv :=
  ((Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)).set _t'1
    (.Vptr (results false) (resultOffsets false))).set _t'2
      (.Vptr (results true) (resultOffsets true))

/-- SAME original FunctionEntry/context/CB/default execution,followed ONCE
by all31 actual GPR initializers. All observers use the SAME reached heap. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (words : Fin 30 → BitVec 64) (outcomes : Outcomes m words) (k : CC.Cont) :
    ∃ locals : Locals m,∃ traceFirst traceSecond traceGPR finalMem,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR)
        (.State procedure Arm64CiliumCallerInitializers.start k (allocation m).1
          (finalTemps words 0 31 (contextTemps ctx ctxOfs results resultOffsets)) finalMem) ∧
      Initialized m finalMem words 31 ∧
      CC.Mem.load .Mint64 finalMem abi.block 0 =
        some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 finalMem abi.block 8 =
        some (.Vptr (results true) (resultOffsets true)) ∧
      (∀ i,CC.Mem.load .Mint32 finalMem abi.block (Arm64CiliumCallerCB.offset i) =
        some (.Vint (0#32))) ∧
      (∀ i,CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (Arm64CiliumCallerDefaults.value i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨locals,traceFirst,traceSecond,beforeGPR,firstRun,dataRead,endRead,cbReads,
      defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerDefaults.entry m abi ctx ctxOfs results resultOffsets contextInputs k
  obtain ⟨traceGPR,finalMem,gprRun,initialized,lastAccess,lastNext,lastFrame,localFrames⟩ :=
    Arm64CiliumCallerGPRSequence.execute words outcomes firstAccess
      (contextTemps ctx ctxOfs results resultOffsets) k
  have abiReads := abi_frame abi localFrames
  have defaultFrame := defaults_frame locals localFrames
  refine ⟨locals,traceFirst,traceSecond,traceGPR,finalMem,?_,initialized,
    (abiReads .Mint64 0).trans dataRead,(abiReads .Mint64 8).trans endRead,
    (fun i => (abiReads .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    (fun i => (defaultFrame i).trans (defaultReads i)),firstFrame.trans lastFrame,
    lastAccess.trans firstAccess,lastNext.trans firstNext⟩
  exact star_trans firstRun gprRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPREntry
