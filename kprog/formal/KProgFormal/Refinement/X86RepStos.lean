import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86RepMovsHandler

namespace KProgFormal.Refinement.X86RepStos
open Reference
open Reference.X86 (ScalarWidth)

/-- Progress projection of the source-emitted forward STOS loop. Only RCX and
RDI advance; the immutable accumulator and RSI survive every iteration. -/
def advance (width : ScalarWidth) (s : Reference.X86.State) : Reference.X86.State :=
  { s with gpr := fun r => if r = 1 then s.gpr r - 1 else if r = 7 then
      generatedX86RepMovsAdvance (s.gpr r) 1 (X86Scalar.handlerWidth width) else s.gpr r }

theorem advance_refines (width : ScalarWidth) (s : Reference.X86.State)
    (direction : s.rflags.getLsbD 10 = false) :
    advance width s = Reference.X86.stosAdvance width s := by
  unfold Reference.X86.stosAdvance
  rw [direction]
  cases width <;> simp [advance, generatedX86RepMovsAdvance, x86WidthBitsSpec,
    X86Scalar.handlerWidth, Reference.X86.ScalarWidth.bytes]

def element (width : ScalarWidth) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.write s width (.memory (s.gpr 7)) (s.gpr 0) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (written, writes) =>
      ⟨{ advance width s with memory := written.memory }, writes, none⟩

theorem element_refines (width : ScalarWidth) (s : Reference.X86.State)
    (direction : s.rflags.getLsbD 10 = false) :
    element width s = Reference.X86.repStosElement width s := by
  simp only [element, X86Scalar.write_refines, Reference.X86.scalarWrite,
    Reference.X86.repStosElement, advance_refines width s direction]
  by_cases hw : permitted s.memory.writable (s.gpr 7) width.bytes = true <;>
    simp [writeMemory, hw]

theorem element_fields (width : ScalarWidth) (s : Reference.X86.State) :
    (element width s).state.rflags = s.rflags ∧
    (element width s).state.xmm0 = s.xmm0 ∧
    (element width s).state.fsBase = s.fsBase ∧
    (element width s).state.gsBase = s.gsBase ∧
    (element width s).state.addressWidth = s.addressWidth := by
  unfold element
  split <;> exact ⟨rfl, rfl, rfl, rfl, rfl⟩

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
    loop width nextPc count s = Reference.X86.repStosLoop width nextPc count s := by
  induction count generalizing s with
  | zero => rfl
  | succ n ih =>
      rw [loop, Reference.X86.repStosLoop, ← element_refines width s direction]
      split
      · rfl
      · rw [ih _ (by rw [(element_fields width s).1]; exact direction)]

def progressed (width : ScalarWidth) (count : Nat) (s : Reference.X86.State) :
    Reference.X86.Register → Reference.Word := fun r =>
  if r = 1 then s.gpr r - BitVec.ofNat 64 count else if r = 7 then
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
  · by_cases h7 : r = 7
    · simpa only [progressed, advance, if_neg h1, if_pos h7] using advance_comp width count (s.gpr r)
    · simp only [progressed, advance, if_neg h1, if_neg h7]

theorem element_registers (width : ScalarWidth) (s : Reference.X86.State)
    (noFault : (element width s).fault = none) :
    (element width s).state.gpr = (advance width s).gpr := by
  cases hw : X86Scalar.write s width (.memory (s.gpr 7)) (s.gpr 0) with
  | error f => simp [element, hw] at noFault
  | ok pair => rcases pair with ⟨written, writes⟩; simp [element, hw]

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
          _ = progressed width n (advance width s) := by funext r; simp only [progressed, hg]
          _ = progressed width (n + 1) s := advance_progressed width n s

/-- Projection of the source macro's final full-width RCX zero and tagged RDI
advance. Provenance/materialization and stores remain the arena interface. -/
def emittedRegisters (width : ScalarWidth) (s : Reference.X86.State) :
    Reference.X86.Register → Reference.Word := fun r =>
  if r = 1 then 0 else if r = 7 then
    generatedX86RepMovsAdvance (s.gpr r) (s.gpr 1).toNat (X86Scalar.handlerWidth width) else s.gpr r

theorem emitted_registers_refine (width : ScalarWidth) (s : Reference.X86.State) :
    emittedRegisters width s = progressed width (s.gpr 1).toNat s := by
  funext r
  by_cases h1 : r = 1
  · subst r; simp [emittedRegisters, progressed]
  · simp only [emittedRegisters, progressed, if_neg h1]

/-- Successful full-count progress projection of the forward C handler.
Faulting stores retain the ISA restart semantics in loop_refines; this law
requires successful stores because C commits RCX/RDI only after its loop. -/
def handlerStep (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let stored := loop width nextPc (s.gpr 1).toNat s
  if stored.fault.isSome then stored else
    ⟨{ stored.state with gpr := emittedRegisters width s }, stored.events, none⟩

theorem handler_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false)
    (noFault : (loop width nextPc (s.gpr 1).toNat s).fault = none) :
    handlerStep width nextPc s = Reference.X86.step (.repStos width nextPc) s := by
  change handlerStep width nextPc s = Reference.X86.repStosLoop width nextPc (s.gpr 1).toNat s
  rw [← loop_refines width nextPc (s.gpr 1).toNat s direction]
  have registers := loop_registers width nextPc (s.gpr 1).toNat s noFault
  unfold handlerStep
  rw [emitted_registers_refine width s, ← registers]
  cases result : loop width nextPc (s.gpr 1).toNat s with
  | mk state events fault =>
      have hf : fault = none := by simpa only [result] using noFault
      subst fault
      rfl

theorem handler_step_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false)
    (noFault : (loop width nextPc (s.gpr 1).toNat s).fault = none) :
    Reference.X86.Step (.repStos width nextPc) s (handlerStep width nextPc s) := by
  rw [handler_refines width nextPc s direction noFault]
  exact ⟨rfl, rfl, rfl⟩

/-- Successful prefix states give the original loop-index destination and
unchanged accumulator/source register; no disjoint-store assumption is needed. -/
theorem loop_inputs (width : ScalarWidth) (nextPc : Reference.Word) (count : Nat)
    (s : Reference.X86.State) (noFault : (loop width nextPc count s).fault = none) :
    (loop width nextPc count s).state.gpr 0 = s.gpr 0 ∧
    (loop width nextPc count s).state.gpr 6 = s.gpr 6 ∧
    (loop width nextPc count s).state.gpr 7 =
      generatedX86RepMovsAdvance (s.gpr 7) count (X86Scalar.handlerWidth width) := by
  rw [loop_registers width nextPc count s noFault]
  simp [progressed]

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

end KProgFormal.Refinement.X86RepStos

namespace KProgFormal.Refinement.X86RepStos.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

def project (width : ScalarWidth) (index : Nat) (s : State) : State :=
  { s with gpr := progressed width index s }

theorem project_memory (width : ScalarWidth) (index : Nat) (s : State) :
    (project width index s).memory = s.memory := rfl

theorem project_accumulator (width : ScalarWidth) (index : Nat) (s : State) :
    (project width index s).gpr 0 = s.gpr 0 := by
  simp [project, progressed]

theorem project_destination (width : ScalarWidth) (index : Nat) (s : State) :
    (project width index s).gpr 7 =
      generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width) := by
  simp [project, progressed]

theorem project_memory_commute (width : ScalarWidth) (index : Nat) (s : State) (memory : Memory) :
    project width index { s with memory := memory } = { project width index s with memory := memory } := rfl

theorem project_zero (width : ScalarWidth) (s : State) : project width 0 s = s := by
  unfold project
  have registers : progressed width 0 s = s.gpr := by
    funext r
    simp [progressed, generatedX86RepMovsAdvance]
  rw [registers]

theorem advance_project (width : ScalarWidth) (index : Nat) (s : State) :
    advance width (project width index s) = project width (index + 1) s := by
  unfold advance project
  congr 1
  funext r
  by_cases counter : r = 1
  · simp only [progressed, counter, ↓reduceIte, BitVec.ofNat_add]
    change (s.gpr 1 - BitVec.ofNat 64 index) - 1 = s.gpr 1 - (BitVec.ofNat 64 index + 1)
    generalize s.gpr 1 = value
    clear s width
    bv_decide
  · by_cases pointer : r = 7
    · simp only [progressed, if_neg counter, if_pos pointer, generatedX86RepMovsAdvance,
        Nat.add_mul, Nat.one_mul, BitVec.ofNat_add, BitVec.add_assoc]
    · simp only [progressed, if_neg counter, if_neg pointer]

/-- The emitted STOS loop captures RDI and RAX once, computes each original
pointer plus index times width, and changes memory before final register writes.
The scalar-store primitive carries its tag/provenance and physical interface. -/
def element (width : ScalarWidth) (index : Nat) (s : State) : Transition State :=
  let destination := generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)
  match X86Scalar.write s width (.memory destination) (s.gpr 0) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (written, writes) => ⟨written, writes, none⟩

def projectElement (width : ScalarWidth) (index : Nat) (effect : Transition State) : Transition State :=
  ⟨project width (if effect.fault.isSome then index else index + 1) effect.state, effect.events, effect.fault⟩

theorem element_projects (width : ScalarWidth) (index : Nat) (s : State) :
    X86RepStos.element width (project width index s) = projectElement width index (element width index s) := by
  simp only [X86RepStos.element, element, X86Scalar.write_refines, Reference.X86.scalarWrite,
    project_accumulator, project_destination, project_memory]
  by_cases hw : permitted s.memory.writable
    (generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    simp [writeMemory, hw, projectElement, advance_project, project_memory_commute]

theorem element_gpr (width : ScalarWidth) (index : Nat) (s : State) :
    (element width index s).state.gpr = s.gpr := by
  simp only [element, X86Scalar.write_refines, Reference.X86.scalarWrite]
  by_cases hw : permitted s.memory.writable
    (generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    simp [writeMemory, hw]

/-- Natural recursion presents C's exact unsigned index range. The
full_count_index_exact law supplies the u64 index correspondence. -/
def loop (width : ScalarWidth) (nextPc : Reference.Word) (index : Nat) : Nat → State → Transition State
  | 0, s => ⟨{ s with pc := nextPc }, [], none⟩
  | n + 1, s =>
      let first := element width index s
      if first.fault.isSome then first else
        let rest := loop width nextPc (index + 1) n first.state
        ⟨rest.state, first.events ++ rest.events, rest.fault⟩

theorem loop_gpr (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State) :
    (loop width nextPc index count s).state.gpr = s.gpr := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      simp only [loop]
      split
      · exact element_gpr width index s
      · exact (ih (index + 1) (element width index s).state).trans (element_gpr width index s)

theorem loop_fault_matches (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State) :
    (loop width nextPc index count s).fault =
      (X86RepStos.loop width nextPc count (project width index s)).fault := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      simp only [loop, X86RepStos.loop, element_projects, projectElement]
      by_cases stopped : (element width index s).fault.isSome = true
      · simp only [stopped, ↓reduceIte]
      · simp only [stopped, ↓reduceIte]
        exact ih (index + 1) (element width index s).state

theorem loop_projects (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State)
    (successful : (loop width nextPc index count s).fault = none) :
    X86RepStos.loop width nextPc count (project width index s) =
      ⟨project width (index + count) (loop width nextPc index count s).state,
        (loop width nextPc index count s).events, none⟩ := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      by_cases stopped : (element width index s).fault.isSome = true
      · have bad : (element width index s).fault = none := by simpa [loop, stopped] using successful
        simp [bad] at stopped
      · have firstOk : (element width index s).fault = none := by
          cases h : (element width index s).fault <;> simp_all
        have restOk : (loop width nextPc (index + 1) n (element width index s).state).fault = none := by
          simpa [loop, stopped] using successful
        rw [X86RepStos.loop, element_projects]
        simp only [projectElement, firstOk, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
        rw [ih (index + 1) (element width index s).state restOk]
        have indices : index + 1 + n = index + (n + 1) := by omega
        simp only [loop, if_neg stopped, indices]

/-- Ordered write/fault events agree at every prefix, including a stopped store. -/
theorem loop_events_match (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State) :
    (loop width nextPc index count s).events =
      (X86RepStos.loop width nextPc count (project width index s)).events := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      simp only [loop, X86RepStos.loop, element_projects, projectElement]
      by_cases stopped : (element width index s).fault.isSome = true
      · simp only [stopped, ↓reduceIte]
      · simp only [stopped, ↓reduceIte]
        rw [ih (index + 1) (element width index s).state]
        rfl

def handlerStep (width : ScalarWidth) (nextPc : Reference.Word) (s : State) : Transition State :=
  let count := (s.gpr 1).toNat
  let copied := loop width nextPc 0 count s
  if copied.fault.isSome then copied else
    ⟨{ copied.state with gpr := emittedRegisters width s }, copied.events, none⟩

theorem handler_matches_progress (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    handlerStep width nextPc s = X86RepStos.handlerStep width nextPc s := by
  have projection := loop_projects width nextPc (s.gpr 1).toNat 0 s successful
  rw [project_zero] at projection
  unfold handlerStep X86RepStos.handlerStep
  rw [projection]
  simp only [successful, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
  rfl

theorem handler_refines (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (direction : s.rflags.getLsbD 10 = false)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    handlerStep width nextPc s = Reference.X86.step (.repStos width nextPc) s := by
  have faults := loop_fault_matches width nextPc (s.gpr 1).toNat 0 s
  rw [project_zero] at faults
  have progressOk : (X86RepStos.loop width nextPc (s.gpr 1).toNat s).fault = none := by
    rw [← faults]
    exact successful
  rw [handler_matches_progress width nextPc s successful]
  exact X86RepStos.handler_refines width nextPc s direction progressOk

end KProgFormal.Refinement.X86RepStos.Indexed

namespace KProgFormal.Refinement.X86RepStos.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

theorem full_count_index_exact (counter : Reference.Word) (index : Nat)
    (within : index ≤ counter.toNat) :
    (BitVec.ofNat 64 index).toNat = index := by
  have bound := counter.isLt
  simp only [BitVec.toNat_ofNat]
  exact Nat.mod_eq_of_lt (by omega)

theorem full_count_condition_exact (counter : Reference.Word) (index : Nat)
    (within : index ≤ counter.toNat) :
    (BitVec.ofNat 64 index).ult counter = decide (index < counter.toNat) := by
  simp only [BitVec.ult, full_count_index_exact counter index within]

theorem handler_step_refines (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (direction : s.rflags.getLsbD 10 = false)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    Reference.X86.Step (.repStos width nextPc) s (handlerStep width nextPc s) := by
  rw [handler_refines width nextPc s direction successful]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86RepStos.Indexed
