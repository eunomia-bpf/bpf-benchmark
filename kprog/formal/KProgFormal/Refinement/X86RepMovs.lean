import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86RepMovsHandler

namespace KProgFormal.Refinement.X86RepMovs
open Reference
open Reference.X86 (ScalarWidth)

/-- The forward loop's progress projection, using the existing generated
pointer-advance primitive. C commits its register writeback after the copy. -/
def advance (width : ScalarWidth) (s : Reference.X86.State) : Reference.X86.State :=
  { s with gpr := fun r => if r = 1 then s.gpr r - 1 else if r = 6 ∨ r = 7 then
      generatedX86RepMovsAdvance (s.gpr r) 1 (X86Scalar.handlerWidth width) else s.gpr r }

theorem advance_refines (width : ScalarWidth) (s : Reference.X86.State)
    (direction : s.rflags.getLsbD 10 = false) :
    advance width s = Reference.X86.stringAdvance width false s := by
  unfold Reference.X86.stringAdvance
  rw [direction]
  cases width <;> simp [advance, generatedX86RepMovsAdvance, x86WidthBitsSpec,
    X86Scalar.handlerWidth, Reference.X86.stringAdvance, Reference.X86.stringAddress,
    Reference.X86.ScalarWidth.bytes, direction]

/-- The generated scalar ladders at the next iteration's source/destination.
Progress registers expose which iteration is represented; a C fault/restart
refinement additionally needs the platform's successful-access witness. -/
def element (width : ScalarWidth) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width (.memory (s.gpr 6)) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match X86Scalar.write s width (.memory (s.gpr 7)) value with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (written, writes) =>
          ⟨{ advance width s with memory := written.memory }, reads ++ writes, none⟩

theorem element_refines (width : ScalarWidth) (s : Reference.X86.State)
    (direction : s.rflags.getLsbD 10 = false) :
    element width s = Reference.X86.repMovsElement width false 0 s := by
  simp only [element, X86Scalar.read_refines, X86Scalar.write_refines,
    Reference.X86.scalarRead, Reference.X86.readSource, Reference.X86.scalarWrite,
    Reference.X86.repMovsElement, advance_refines width s direction,
    Reference.X86.stringAddress, Bool.false_eq_true, ↓reduceIte, BitVec.zero_add]
  by_cases hr : permitted s.memory.readable (s.gpr 6) width.bytes = true <;>
    by_cases hw : permitted s.memory.writable (s.gpr 7) width.bytes = true <;>
    simp [readMemory, writeMemory, hr, hw]

theorem element_flags (width : ScalarWidth) (s : Reference.X86.State) :
    (element width s).state.rflags = s.rflags := by
  unfold element
  split
  · rfl
  · split <;> rfl

def loop (width : ScalarWidth) (nextPc : Reference.Word) :
    Nat → Reference.X86.State → Transition Reference.X86.State
  | 0, s => ⟨{ s with pc := nextPc }, [], none⟩
  | n + 1, s =>
      let first := element width s
      if first.fault.isSome then first else
        let rest := loop width nextPc n first.state
        ⟨rest.state, first.events ++ rest.events, rest.fault⟩

theorem loop_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (count : Nat) (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false) :
    loop width nextPc count s = Reference.X86.repMovsLoop width false 0 nextPc count s := by
  induction count generalizing s with
  | zero => rfl
  | succ n ih =>
      rw [loop, Reference.X86.repMovsLoop, ← element_refines width s direction]
      split
      · rfl
      · rw [ih _ (by rw [element_flags]; exact direction)]

/-- The default-address forward-copy core. Count=RCX, count≤64 and safe
accesses connect this progress projection to the production unrolled handler;
no theorem here claims that C implements reverse/address32/restart faults. -/
def step (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  loop width nextPc (s.gpr 1).toNat s

theorem step_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false) :
    step width nextPc s = Reference.X86.step (.repMovs width false 0 nextPc) s := by
  simpa [step, Reference.X86.step, Reference.X86.repMovsStep,
    Reference.X86.stringStart, Reference.X86.stringAddress] using
    loop_refines width nextPc (s.gpr 1).toNat s direction

theorem bounded_count_exact (count : Nat) (h : count ≤ 64) :
    generatedX86RepMovsElementCount count = count := by
  rw [x86_rep_movs_element_count_refines]
  exact Nat.min_eq_right h

/-- Native numeric register values after a given number of completed forward
iterations. This also relates the loop's index-based addresses to its initial
pointers, rather than assuming each iteration sees an independent buffer. -/
def progressed (width : ScalarWidth) (count : Nat) (s : Reference.X86.State) :
    Reference.X86.Register → Reference.Word := fun r =>
  if r = 1 then s.gpr r - BitVec.ofNat 64 count else if r = 6 ∨ r = 7 then
    generatedX86RepMovsAdvance (s.gpr r) count (X86Scalar.handlerWidth width) else s.gpr r

theorem advance_comp (width : ScalarWidth) (count : Nat) (value : Reference.Word) :
    generatedX86RepMovsAdvance
      (generatedX86RepMovsAdvance value 1 (X86Scalar.handlerWidth width)) count (X86Scalar.handlerWidth width) =
      generatedX86RepMovsAdvance value (count + 1) (X86Scalar.handlerWidth width) := by
  simp only [generatedX86RepMovsAdvance, Nat.add_mul, Nat.one_mul, BitVec.ofNat_add]
  rw [BitVec.add_assoc, BitVec.add_comm (BitVec.ofNat 64 _) (BitVec.ofNat 64 _)]

theorem advance_progressed (width : ScalarWidth) (count : Nat) (s : Reference.X86.State) :
    progressed width count (advance width s) = progressed width (count + 1) s := by
  funext r
  by_cases h1 : r = 1
  · simp only [progressed, advance, h1, ↓reduceIte, BitVec.ofNat_add]
    change (s.gpr 1 - 1) - BitVec.ofNat 64 count = s.gpr 1 - (BitVec.ofNat 64 count + 1)
    generalize s.gpr 1 = value
    clear s width
    bv_decide
  · by_cases h67 : r = 6 ∨ r = 7
    · simpa only [progressed, advance, if_neg h1, if_pos h67] using advance_comp width count (s.gpr r)
    · simp only [progressed, advance, if_neg h1, if_neg h67]

theorem element_registers (width : ScalarWidth) (s : Reference.X86.State)
    (noFault : (element width s).fault = none) :
    (element width s).state.gpr = (advance width s).gpr := by
  cases hr : X86Scalar.read s width (.memory (s.gpr 6)) with
  | error f => simp [element, hr] at noFault
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      cases hw : X86Scalar.write s width (.memory (s.gpr 7)) value with
      | error f => simp [element, hr, hw] at noFault
      | ok pair => rcases pair with ⟨written, writes⟩; simp [element, hr, hw]

theorem loop_registers (width : ScalarWidth) (nextPc : Reference.Word) (count : Nat)
    (s : Reference.X86.State) (noFault : (loop width nextPc count s).fault = none) :
    (loop width nextPc count s).state.gpr = progressed width count s := by
  induction count generalizing s with
  | zero =>
      funext r
      simp [loop, progressed, generatedX86RepMovsAdvance]
  | succ n ih =>
      let first := element width s
      by_cases hf : first.fault.isSome = true
      · have hn : first.fault = none := by simpa [loop, first, hf] using noFault
        simp [hn] at hf
      · have hn : (loop width nextPc n first.state).fault = none := by
          simpa [loop, first, hf] using noFault
        have firstOk : first.fault = none := by
          cases h : first.fault <;> simp_all
        have hg : first.state.gpr = (advance width s).gpr := element_registers width s firstOk
        calc
          (loop width nextPc (n + 1) s).state.gpr = (loop width nextPc n first.state).state.gpr := by simp [loop, first, hf]
          _ = progressed width n first.state := ih _ hn
          _ = progressed width n (advance width s) := by
            funext r
            simp only [progressed, hg]
          _ = progressed width (n + 1) s := advance_progressed width n s

/-- The final generated RCX zeroing and two tagged-pointer advances, projected
to numeric native state after the entry relation materializes their values. -/
def emittedRegisters (width : ScalarWidth) (count : Nat) (s : Reference.X86.State) :
    Reference.X86.Register → Reference.Word := fun r =>
  if r = 1 then (generatedX86RepMovsRcx ⟨s.gpr r, .scalar⟩).bits else if r = 6 ∨ r = 7 then
    generatedX86RepMovsAdvance (s.gpr r) count (X86Scalar.handlerWidth width) else s.gpr r

theorem emitted_registers_refine (width : ScalarWidth) (count : Nat) (s : Reference.X86.State)
    (counter : s.gpr 1 = BitVec.ofNat 64 count) :
    emittedRegisters width count s = progressed width count s := by
  funext r
  by_cases h1 : r = 1
  · subst r
    simp [emittedRegisters, progressed, counter, generatedX86RepMovsRcx,
      generatedX86RegWrite, GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits]
  · simp only [emittedRegisters, progressed, if_neg h1]

def handlerStep (width : ScalarWidth) (count : Nat) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let copied := loop width nextPc (generatedX86RepMovsElementCount count) s
  if copied.fault.isSome then copied else
    ⟨{ copied.state with gpr := emittedRegisters width count s }, copied.events, none⟩

/-- The bounded, forward, default-address C core on successful copies. Count
and DF are explicit input witnesses, never silently substituted for RCX/flags.
Faults/reverse/address32 remain executable ISA cases, not C refinement claims. -/
theorem handler_refines (width : ScalarWidth) (count : Nat) (nextPc : Reference.Word)
    (s : Reference.X86.State) (bound : count ≤ 64) (counter : s.gpr 1 = BitVec.ofNat 64 count)
    (direction : s.rflags.getLsbD 10 = false) (noFault : (loop width nextPc count s).fault = none) :
    handlerStep width count nextPc s = Reference.X86.step (.repMovs width false 0 nextPc) s := by
  have countValue : (s.gpr 1).toNat = count := by
    rw [counter]
    simp only [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by omega)
  rw [← step_refines width nextPc s direction]
  simp only [step, countValue]
  unfold handlerStep
  rw [bounded_count_exact count bound]
  have registers := loop_registers width nextPc count s noFault
  rw [emitted_registers_refine width count s counter, ← registers]
  cases result : loop width nextPc count s with
  | mk state events fault =>
      have hf : fault = none := by simpa only [result] using noFault
      subst fault
      rfl

theorem handler_step_refines (width : ScalarWidth) (count : Nat) (nextPc : Reference.Word)
    (s : Reference.X86.State) (bound : count ≤ 64) (counter : s.gpr 1 = BitVec.ofNat 64 count)
    (direction : s.rflags.getLsbD 10 = false) (noFault : (loop width nextPc count s).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) s (handlerStep width count nextPc s) := by
  rw [handler_refines width count nextPc s bound counter direction noFault]
  exact ⟨rfl, rfl, rfl⟩

/-- Each scalar copy preserves the architectural frame surrounding its
progress registers and memory image. -/
theorem element_fields (width : ScalarWidth) (s : Reference.X86.State) :
    (element width s).state.rflags = s.rflags ∧
    (element width s).state.xmm0 = s.xmm0 ∧
    (element width s).state.fsBase = s.fsBase ∧
    (element width s).state.gsBase = s.gsBase ∧
    (element width s).state.addressWidth = s.addressWidth := by
  unfold element
  split
  · exact ⟨rfl, rfl, rfl, rfl, rfl⟩
  · split <;> exact ⟨rfl, rfl, rfl, rfl, rfl⟩

theorem loop_fields (width : ScalarWidth) (nextPc : Reference.Word) (count : Nat)
    (s : Reference.X86.State) :
    (loop width nextPc count s).state.rflags = s.rflags ∧
    (loop width nextPc count s).state.xmm0 = s.xmm0 ∧
    (loop width nextPc count s).state.fsBase = s.fsBase ∧
    (loop width nextPc count s).state.gsBase = s.gsBase ∧
    (loop width nextPc count s).state.addressWidth = s.addressWidth := by
  induction count generalizing s with
  | zero => exact ⟨rfl, rfl, rfl, rfl, rfl⟩
  | succ n ih =>
      simp only [loop]
      split
      · exact element_fields width s
      · obtain ⟨ef, ex, efs, egs, ea⟩ := element_fields width s
        obtain ⟨lf, lx, lfs, lgs, la⟩ := ih (element width s).state
        exact ⟨lf.trans ef, lx.trans ex, lfs.trans efs, lgs.trans egs, la.trans ea⟩

theorem loop_success_pc (width : ScalarWidth) (nextPc : Reference.Word) (count : Nat)
    (s : Reference.X86.State) (successful : (loop width nextPc count s).fault = none) :
    (loop width nextPc count s).state.pc = nextPc := by
  induction count generalizing s with
  | zero => rfl
  | succ n ih =>
      by_cases stopped : (element width s).fault.isSome = true
      · have contradiction : (element width s).fault = none := by simpa [loop, stopped] using successful
        simp [contradiction] at stopped
      · have rest : (loop width nextPc n (element width s).state).fault = none := by
          simpa [loop, stopped] using successful
        simpa [loop, stopped] using ih _ rest

end KProgFormal.Refinement.X86RepMovs
