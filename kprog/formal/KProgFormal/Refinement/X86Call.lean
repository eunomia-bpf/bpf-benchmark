import KProgFormal.Refinement.X86Push
import KProgFormal.Refinement.X86Scalar

namespace KProgFormal.Refinement.X86Call
open Reference
open Reference.X86 (ScalarSource)

/-- The internal CFG call core: materialized target and return-PC values are
native addresses, not helper IDs or unrelocated source-code tokens. Its push
uses the same generated64-bit stack-transfer primitives as the C call macro. -/
def callStep (source : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  match X86Scalar.read s .w64 source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (target, reads) =>
      let address := s.gpr 4 - 8
      if permitted s.memory.writable address 8 then
        if Reference.X86.canonicalTarget s.addressWidth target then
          X86Push.transferStep .w64 nextPc reads target s
        else ⟨s, reads ++ [.fault (.nonCanonical target)], some (.nonCanonical target)⟩
      else ⟨s, reads ++ [.fault (.write address 8)], some (.write address 8)⟩

theorem call_refines (source : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    callStep source nextPc s = Reference.X86.step (.call source nextPc) s := by
  simp only [callStep, X86Scalar.read_refines, X86Push.transfer_refines,
    Reference.X86.step, Reference.X86.callStep]
  rfl

/-- C's subroutine return reads its saved PC then increments the stack pointer.
The generated load and stack-step tables are composed with canonical PC use.
The outer invocation return additionally needs the platform/ABI certificate. -/
def returnStep (s : Reference.X86.State) : Transition Reference.X86.State :=
  let address := generatedX86PushPopAccessAt .pop (s.gpr 4) .b64
  match X86Scalar.read s .w64 (.memory address) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (target, reads) =>
      if Reference.X86.canonicalTarget s.addressWidth target then
        let advanced := generatedX86PushPopRspAt .pop (s.gpr 4) .b64
        ⟨{ s with gpr := fun r => if r = 4 then advanced else s.gpr r, pc := target }, reads, none⟩
      else ⟨s, reads ++ [.fault (.nonCanonical target)], some (.nonCanonical target)⟩

theorem return_refines (nextPc : Reference.Word) (s : Reference.X86.State) :
    returnStep s = Reference.X86.step (.returnNear 0 nextPc) s := by
  have access : generatedX86PushPopAccessAt .pop (s.gpr 4) .b64 = s.gpr 4 := rfl
  have advanced : generatedX86PushPopRspAt .pop (s.gpr 4) .b64 = s.gpr 4 + 8 := rfl
  simp only [returnStep, access, advanced, X86Scalar.read_refines,
    Reference.X86.step, Reference.X86.returnStep,
    Reference.X86.scalarRead, Reference.X86.readSource]
  by_cases hr : permitted s.memory.readable (s.gpr 4) 8 = true <;>
    simp [readMemory, Reference.X86.ScalarWidth.bytes, hr]

/-- These cores include specification fault tests. The actual branch/stack
macros need successful-access and canonical-target witnesses from artifact and
entry certificates; no new C fault checks are asserted here. -/
theorem call_checked_refines (source : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.call source nextPc) s (callStep source nextPc s) := by
  rw [call_refines]
  exact ⟨rfl, rfl, rfl⟩

theorem return_checked_refines (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.returnNear 0 nextPc) s (returnStep s) := by
  rw [return_refines nextPc]
  exact ⟨rfl, rfl, rfl⟩

/-- The actual internal-call body on a successful stack access. No runtime
canonicality guard is invented: the certificate supplies that witness. -/
def callSuccess (target nextPc : Reference.Word) (reads : List Event) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  let address := generatedX86PushPopAccessAt .push (s.gpr 4) .b64
  let advanced := generatedX86PushPopRspAt .push (s.gpr 4) .b64
  ⟨{ s with gpr := (fun r => if r = 4 then advanced else s.gpr r), memory := X86Push.store .w64 s.memory address nextPc, pc := target },
    reads ++ [.memory .write address (valueBytes nextPc 8) true], none⟩

theorem call_success_refines (source : ScalarSource) (target nextPc : Reference.Word)
    (reads : List Event) (s : Reference.X86.State)
    (sampled : X86Scalar.read s .w64 source = .ok (target, reads))
    (canonical : Reference.X86.canonicalTarget s.addressWidth target = true)
    (writable : permitted s.memory.writable (s.gpr 4 - 8) 8 = true) :
    callSuccess target nextPc reads s = Reference.X86.step (.call source nextPc) s := by
  rw [← call_refines]
  simp only [callStep, sampled, writable, canonical, ↓reduceIte]
  change callSuccess target nextPc reads s =
    if permitted s.memory.writable (s.gpr 4 - 8) 8 then
      callSuccess target nextPc reads s
    else ⟨s, reads ++ [.fault (.write (s.gpr 4 - 8) 8)], some (.write (s.gpr 4 - 8) 8)⟩
  simp only [writable, ↓reduceIte]

def returnSuccess (target : Reference.Word) (reads : List Event) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  let advanced := generatedX86PushPopRspAt .pop (s.gpr 4) .b64
  ⟨{ s with gpr := fun r => if r = 4 then advanced else s.gpr r, pc := target }, reads, none⟩

theorem return_success_refines (target nextPc : Reference.Word) (reads : List Event)
    (s : Reference.X86.State)
    (sampled : X86Scalar.read s .w64 (.memory (s.gpr 4)) = .ok (target, reads))
    (canonical : Reference.X86.canonicalTarget s.addressWidth target = true) :
    returnSuccess target reads s = Reference.X86.step (.returnNear 0 nextPc) s := by
  rw [← return_refines nextPc]
  have access : generatedX86PushPopAccessAt .pop (s.gpr 4) .b64 = s.gpr 4 := rfl
  simp only [returnStep, access, sampled, canonical, ↓reduceIte, returnSuccess]

end KProgFormal.Refinement.X86Call
