import KProgFormal.ClightRefinement.Arm64LinkedNop
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64LinkedNop.Inspection
open Arm64Producer
open Arm64Nop

-- A full actual Callstate execution must inhabit the linked environment.
example (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8) (k : CC.Cont)
    (call : CC.isCallCont k = true) :
    ∃ after, InternalRun Binding.ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.Returnstate .Vundef k after) ∧ FrameBelow m.nextblock m after :=
  Arm64LinkedNop.call_internal m ignored flags k call

-- The width call resolves to the unchanged internal body at actual block66.
example (m : CC.Mem) :
    CC.Genv.findSymbol Binding.ge.genv_genv Arm64Program._arm64_width_effective = some (CC.Positive.ofNat 66) ∧
    CC.Genv.findFunctPtr Binding.ge.genv_genv (CC.Positive.ofNat 66) =
      some (.Internal Arm64Program.f_arm64_width_effective) :=
  ⟨(widthBinding m).symbol, (widthBinding m).function⟩

-- Global/data access maps survive the complete initialized execution. This
-- checks both permission kinds after actual allocation, body and deallocation.
example (ignored : IgnoredArguments) (flags : BitVec 8) :
    ∃ after, InternalRun Binding.ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) .Kstop Arm64GlobalMemory.initialMemory)
      (.Returnstate .Vundef .Kstop after) ∧
      ∀ k, CC.Mem.perm after (CC.Positive.ofNat 20) 47 k .Readable = true ∧
        CC.Mem.perm after (CC.Positive.ofNat 20) 48 k .Nonempty = false ∧
        CC.Mem.perm after (CC.Positive.ofNat 61) 0 k .Nonempty = false ∧
        CC.Mem.perm after (CC.Positive.ofNat 66) 0 k .Nonempty = true := by
  obtain ⟨after, run, frame⟩ := initialized_call ignored flags .Kstop rfl
  refine ⟨after, run, ?_⟩
  intro k
  have string := (frame (CC.Positive.ofNat 20) (by decide +kernel)).2
  have stderr := (frame (CC.Positive.ofNat 61) (by decide +kernel)).2
  have width := (frame (CC.Positive.ofNat 66) (by decide +kernel)).2
  have pointer := (Arm64GlobalMemory.function_permissions 65 Arm64Program._arm64_width_effective
    (.Internal Arm64Program.f_arm64_width_effective) (by rw [Binding.linked_definitions]; rfl)
    (CC.Positive.ofNat 66) (by decide +kernel) k).1
  have pointerAfter : CC.Mem.perm after (CC.Positive.ofNat 66) 0 k .Nonempty = true := by
    simpa only [CC.Mem.perm, width] using pointer
  refine ⟨?_, ?_, ?_, pointerAfter⟩
  all_goals simp [CC.Mem.perm, string, stderr, width, Arm64GlobalMemory.string_access,
    Arm64GlobalMemory.stderr_access, CC.permOrder', CC.permOrder, CC.Permission.rank]
end KProgFormal.ClightRefinement.Arm64LinkedNop.Inspection
