import KProgFormal.Refinement.X86RepStos
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

namespace KProgFormal.Refinement.X86RepMovs
open Reference
open Reference.X86 (ScalarWidth)

/-- Current source reads the complete incoming RCX and commits progress once
its forward loop completes. The historical bounded handler remains above. -/
def fullCountHandlerStep (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let copied := loop width nextPc (s.gpr 1).toNat s
  if copied.fault.isSome then copied else
    ⟨{ copied.state with gpr := emittedRegisters width (s.gpr 1).toNat s }, copied.events, none⟩

theorem full_count_handler_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false)
    (successful : (loop width nextPc (s.gpr 1).toNat s).fault = none) :
    fullCountHandlerStep width nextPc s = Reference.X86.step (.repMovs width false 0 nextPc) s := by
  rw [← step_refines width nextPc s direction]
  unfold step fullCountHandlerStep
  have registers := loop_registers width nextPc (s.gpr 1).toNat s successful
  rw [emitted_registers_refine width (s.gpr 1).toNat s (by simp), ← registers]
  cases result : loop width nextPc (s.gpr 1).toNat s with
  | mk state events fault =>
      have hf : fault = none := by simpa only [result] using successful
      subst fault
      rfl

theorem full_count_handler_step_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) (direction : s.rflags.getLsbD 10 = false)
    (successful : (loop width nextPc (s.gpr 1).toNat s).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) s (fullCountHandlerStep width nextPc s) := by
  rw [full_count_handler_refines width nextPc s direction successful]
  exact ⟨rfl, rfl, rfl⟩

/-- The prefix's progress gives the original-index addresses used by C's
capture-once pointers; overlap is allowed and the memory image is sequential. -/
theorem full_count_prefix_addresses (width : ScalarWidth) (nextPc : Reference.Word)
    (done : Nat) (s : Reference.X86.State)
    (successful : (loop width nextPc done s).fault = none) :
    (loop width nextPc done s).state.gpr 6 =
      generatedX86RepMovsAdvance (s.gpr 6) done (X86Scalar.handlerWidth width) ∧
    (loop width nextPc done s).state.gpr 7 =
      generatedX86RepMovsAdvance (s.gpr 7) done (X86Scalar.handlerWidth width) ∧
    (loop width nextPc done s).state.gpr 1 = s.gpr 1 - BitVec.ofNat 64 done := by
  rw [loop_registers width nextPc done s successful]
  simp [progressed]

/-- The u64 induction index cannot wrap before the original u64 count.
This is a consequence of the input representation, not a simulator limit. -/
theorem full_count_index_exact (counter : Reference.Word) (index : Nat)
    (inside : index < counter.toNat) :
    (BitVec.ofNat 64 index).toNat = index ∧
    (BitVec.ofNat 64 (index + 1)).toNat = index + 1 := by
  have bounded := counter.isLt
  simp only [BitVec.toNat_ofNat]
  constructor <;> apply Nat.mod_eq_of_lt <;> omega

end KProgFormal.Refinement.X86RepMovs

namespace KProgFormal.Refinement.X86RepMovs.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

def project (width : ScalarWidth) (index : Nat) (s : State) : State :=
  { s with gpr := progressed width index s }

theorem project_memory (width : ScalarWidth) (index : Nat) (s : State) :
    (project width index s).memory = s.memory := rfl

theorem project_source (width : ScalarWidth) (index : Nat) (s : State) :
    (project width index s).gpr 6 =
      generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width) := by
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
  · by_cases pointer : r = 6 ∨ r = 7
    · simp only [progressed, if_neg counter, if_pos pointer, generatedX86RepMovsAdvance,
        Nat.add_mul, Nat.one_mul, BitVec.ofNat_add, BitVec.add_assoc]
    · simp only [progressed, if_neg counter, if_neg pointer]

/-- The C iteration retains captured register cells, uses initial+index*width
addresses and updates only memory. Tags/physical access are the primitive
correspondence interface; these operations are the existing scalar ladders. -/
def element (width : ScalarWidth) (index : Nat) (s : State) : Transition State :=
  let source := generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width)
  let destination := generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)
  match X86Scalar.read s width (.memory source) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match X86Scalar.write s width (.memory destination) value with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (written, writes) => ⟨written, reads ++ writes, none⟩

def projectElement (width : ScalarWidth) (index : Nat) (effect : Transition State) : Transition State :=
  ⟨project width (if effect.fault.isSome then index else index + 1) effect.state, effect.events, effect.fault⟩

theorem element_projects (width : ScalarWidth) (index : Nat) (s : State) :
    X86RepMovs.element width (project width index s) = projectElement width index (element width index s) := by
  simp only [X86RepMovs.element, element, X86Scalar.read_refines, X86Scalar.write_refines,
    Reference.X86.scalarRead, Reference.X86.readSource, Reference.X86.scalarWrite,
    project_source, project_destination, project_memory]
  by_cases hr : permitted s.memory.readable
    (generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    by_cases hw : permitted s.memory.writable
    (generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    simp [readMemory, writeMemory, hr, hw, projectElement, advance_project, project_memory_commute]



theorem element_gpr (width : ScalarWidth) (index : Nat) (s : State) :
    (element width index s).state.gpr = s.gpr := by
  simp only [element, X86Scalar.read_refines, X86Scalar.write_refines,
    Reference.X86.scalarRead, Reference.X86.readSource, Reference.X86.scalarWrite]
  by_cases hr : permitted s.memory.readable
    (generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    by_cases hw : permitted s.memory.writable
    (generatedX86RepMovsAdvance (s.gpr 7) index (X86Scalar.handlerWidth width)) width.bytes = true <;>
    simp [readMemory, writeMemory, hr, hw]

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
      (X86RepMovs.loop width nextPc count (project width index s)).fault := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      simp only [loop, X86RepMovs.loop, element_projects, projectElement]
      by_cases stopped : (element width index s).fault.isSome = true
      · simp only [stopped, ↓reduceIte]
      · simp only [stopped, ↓reduceIte]
        exact ih (index + 1) (element width index s).state

theorem loop_projects (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State)
    (successful : (loop width nextPc index count s).fault = none) :
    X86RepMovs.loop width nextPc count (project width index s) =
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
        rw [X86RepMovs.loop, element_projects]
        simp only [projectElement, firstOk, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
        rw [ih (index + 1) (element width index s).state restOk]
        have indices : index + 1 + n = index + (n + 1) := by omega
        simp only [loop, if_neg stopped, indices]

def handlerStep (width : ScalarWidth) (nextPc : Reference.Word) (s : State) : Transition State :=
  let count := (s.gpr 1).toNat
  let copied := loop width nextPc 0 count s
  if copied.fault.isSome then copied else
    ⟨{ copied.state with gpr := emittedRegisters width count s }, copied.events, none⟩

theorem handler_matches_progress (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    handlerStep width nextPc s = fullCountHandlerStep width nextPc s := by
  have projection := loop_projects width nextPc (s.gpr 1).toNat 0 s successful
  rw [project_zero] at projection
  unfold handlerStep fullCountHandlerStep
  rw [projection]
  simp only [successful, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
  rfl

theorem handler_refines (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (direction : s.rflags.getLsbD 10 = false)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    handlerStep width nextPc s = Reference.X86.step (.repMovs width false 0 nextPc) s := by
  have faults := loop_fault_matches width nextPc (s.gpr 1).toNat 0 s
  rw [project_zero] at faults
  have progressOk : (X86RepMovs.loop width nextPc (s.gpr 1).toNat s).fault = none := by
    rw [← faults]
    exact successful
  rw [handler_matches_progress width nextPc s successful]
  exact full_count_handler_refines width nextPc s direction progressOk

end KProgFormal.Refinement.X86RepMovs.Indexed

namespace KProgFormal.Refinement.X86RepMovs
open Reference
open Reference.X86 (ScalarWidth State)

theorem full_count_condition_exact (counter : Reference.Word) (index : Nat)
    (within : index ≤ counter.toNat) :
    (BitVec.ofNat 64 index).ult counter = decide (index < counter.toNat) := by
  have bound := counter.isLt
  have exactIndex : (BitVec.ofNat 64 index).toNat = index := by
    simp only [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by omega)
  simp only [BitVec.ult, exactIndex]

theorem Indexed.handler_step_refines (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (direction : s.rflags.getLsbD 10 = false)
    (successful : (Indexed.loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) s (Indexed.handlerStep width nextPc s) := by
  rw [Indexed.handler_refines width nextPc s direction successful]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86RepMovs

namespace KProgFormal.Refinement.X86RepMovs
open Reference
open Reference.X86 (ScalarWidth State)

theorem element_pc (width : ScalarWidth) (s : State) :
    (element width s).state.pc = s.pc := by
  unfold element
  split
  · rfl
  · split <;> rfl

/-- A successful doneCount keeps the original instruction PC before the remaining
iterations, including when the following source access faults. -/
theorem loop_prefix_split (width : ScalarWidth) (nextPc : Reference.Word)
    (doneCount rest : Nat) (s : State)
    (successful : (loop width s.pc doneCount s).fault = none) :
    loop width nextPc (doneCount + rest) s =
      let before := loop width s.pc doneCount s
      let after := loop width nextPc rest before.state
      ⟨after.state, before.events ++ after.events, after.fault⟩ := by
  induction doneCount generalizing s with
  | zero => simp [loop]
  | succ n ih =>
      by_cases stopped : (element width s).fault.isSome = true
      · have bad : (element width s).fault = none := by simpa [loop, stopped] using successful
        simp [bad] at stopped
      · have nextOk : (loop width s.pc n (element width s).state).fault = none := by
          simpa [loop, stopped] using successful
        have nextPc : (element width s).state.pc = s.pc := element_pc width s
        have stepSplit := ih (element width s).state (by simpa only [nextPc] using nextOk)
        simp only [nextPc] at stepSplit
        rw [Nat.succ_add, loop]
        simp only [if_neg stopped]
        rw [stepSplit]
        simp only [loop, if_neg stopped, List.append_assoc]

theorem loop_read_fault_after_prefix (width : ScalarWidth) (nextPc : Reference.Word)
    (doneCount count : Nat) (s : State) (remaining : doneCount < count)
    (successful : (loop width s.pc doneCount s).fault = none)
    (failed : readMemory (loop width s.pc doneCount s).state.memory
      ((loop width s.pc doneCount s).state.gpr 6) width.bytes =
      .error (.read ((loop width s.pc doneCount s).state.gpr 6) width.bytes)) :
    loop width nextPc count s =
      ⟨(loop width s.pc doneCount s).state,
        (loop width s.pc doneCount s).events ++
          [.fault (.read ((loop width s.pc doneCount s).state.gpr 6) width.bytes)],
        some (.read ((loop width s.pc doneCount s).state.gpr 6) width.bytes)⟩ := by
  have counts : count = doneCount + (count - doneCount - 1 + 1) := by omega
  rw [counts, loop_prefix_split width nextPc doneCount _ s successful]
  simp only [loop, element, X86Scalar.read_refines, Reference.X86.scalarRead,
    Reference.X86.readSource, failed, Option.isSome_some, ↓reduceIte]

end KProgFormal.Refinement.X86RepMovs

namespace KProgFormal.Refinement.X86RepMovs.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

theorem loop_events_match (width : ScalarWidth) (nextPc : Reference.Word) (count index : Nat) (s : State) :
    (loop width nextPc index count s).events =
      (X86RepMovs.loop width nextPc count (project width index s)).events := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      simp only [loop, X86RepMovs.loop, element_projects, projectElement]
      by_cases stopped : (element width index s).fault.isSome = true
      · simp only [stopped, ↓reduceIte]
      · simp only [stopped, ↓reduceIte]
        rw [ih (index + 1) (element width index s).state]
        rfl

/-- C selects a recovery before the next scalar read, sets its completed count
to the current index, and uses the existing final pointer/RCX writeback. -/
def recoveryFinish (width : ScalarWidth) (nextPc : Reference.Word) (completed : Nat)
    (s : State) : Transition State :=
  let copied := loop width s.pc 0 completed s
  ⟨{ copied.state with gpr := emittedRegisters width completed s, pc := nextPc }, copied.events, none⟩

theorem recovery_finish_matches_progress (width : ScalarWidth) (nextPc : Reference.Word)
    (completed : Nat) (s : State)
    (successful : (loop width s.pc 0 completed s).fault = none) :
    (recoveryFinish width nextPc completed s).state =
      { (X86RepMovs.loop width s.pc completed s).state with
        gpr := fun r => if r = 1 then 0 else (X86RepMovs.loop width s.pc completed s).state.gpr r,
        pc := nextPc } := by
  have projection := loop_projects width s.pc completed 0 s successful
  rw [project_zero] at projection
  rw [projection]
  simp only [recoveryFinish, project]
  congr 1
  funext r
  by_cases counter : r = 1
  · subst r
    simp [emittedRegisters, progressed, generatedX86RepMovsRcx,
      generatedX86RegWrite, GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits]
  · have captured := congrFun (loop_gpr width s.pc completed 0 s) r
    simp only [emittedRegisters, progressed, if_neg counter, captured, Nat.zero_add]

end KProgFormal.Refinement.X86RepMovs.Indexed

namespace KProgFormal.Refinement.X86RepMovs.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

/-- The existing source branch: only a scalar RSI can select recovery; the
complete effective address forces low-page recovery and otherwise consumes a
fresh low bit. The per-iteration word view is coupled to the global dynamic
input stream at the primitive/compiler interface. -/
def recoveryDecision (scalarSource : Bool) (width : ScalarWidth) (s : State)
    (choices : Nat → Reference.Word) (index : Nat) : Bool :=
  scalarSource && (decide ((generatedX86RepMovsAdvance (s.gpr 6) index
    (X86Scalar.handlerWidth width)).toNat < 4096) || (choices index).getLsbD 0)

theorem recovery_decision_typed (width : ScalarWidth) (s : State)
    (choices : Nat → Reference.Word) (index : Nat) :
    recoveryDecision false width s choices index = false := rfl

theorem recovery_decision_low (width : ScalarWidth) (s : State)
    (choices : Nat → Reference.Word) (index : Nat)
    (low : (generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width)).toNat < 4096) :
    recoveryDecision true width s choices index = true := by
  simp [recoveryDecision, low]

theorem recovery_decision_high (width : ScalarWidth) (s : State)
    (choices : Nat → Reference.Word) (index : Nat)
    (high : 4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width)).toNat) :
    recoveryDecision true width s choices index = (choices index).getLsbD 0 := by
  simp [recoveryDecision, Nat.not_lt.mpr high]

/-- Captured-register source loop. The completed index controls final pointer
writeback. A selected recovery returns before the next read or destination
store; primitive memory faults retain their ordered effects separately. -/
def sourceLoop (width : ScalarWidth) (nextPc : Reference.Word) (decisions : Nat → Bool)
    (index : Nat) : Nat → State → Transition State × Nat
  | 0, s => (⟨{ s with pc := nextPc }, [], none⟩, index)
  | n + 1, s =>
      if decisions index then (⟨{ s with pc := nextPc }, [], none⟩, index) else
        let first := element width index s
        if first.fault.isSome then (first, index) else
          let after := sourceLoop width nextPc decisions (index + 1) n first.state
          (⟨after.1.state, first.events ++ after.1.events, after.1.fault⟩, after.2)

/-- Any selected first recovery index, or the entire count for ordinary
completion, gives exactly the earlier scalar-copy prefix and its events. -/
theorem source_loop_selected (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (completed index count : Nat) (s : State)
    (within : completed ≤ count)
    (earlier : ∀ j, index ≤ j → j < index + completed → decisions j = false)
    (selected : completed < count → decisions (index + completed) = true)
    (successful : (loop width nextPc index completed s).fault = none) :
    sourceLoop width nextPc decisions index count s =
      (loop width nextPc index completed s, index + completed) := by
  induction completed generalizing index count s with
  | zero =>
      cases count with
      | zero => rfl
      | succ n =>
          have first : decisions index = true := by simpa using selected (by omega)
          simp [sourceLoop, loop, first]
  | succ n ih =>
      cases count with
      | zero => omega
      | succ remaining =>
          have firstDecision : decisions index = false := earlier index (by omega) (by omega)
          by_cases stopped : (element width index s).fault.isSome = true
          · have bad : (element width index s).fault = none := by simpa [loop, stopped] using successful
            simp [bad] at stopped
          · have firstOk : (element width index s).fault = none := by
              cases h : (element width index s).fault <;> simp_all
            have restOk : (loop width nextPc (index + 1) n (element width index s).state).fault = none := by
              simpa [loop, stopped] using successful
            have restSelected : n < remaining → decisions (index + 1 + n) = true := by
              intro active
              have same : index + 1 + n = index + (n + 1) := by omega
              rw [same]
              exact selected (by omega)
            have restEarlier : ∀ j, index + 1 ≤ j → j < index + 1 + n → decisions j = false := by
              intro j start bound
              exact earlier j (by omega) (by omega)
            have rest := ih (index + 1) remaining (element width index s).state
              (by omega) restEarlier restSelected restOk
            simp only [sourceLoop, firstDecision, Bool.false_eq_true, ↓reduceIte,
              firstOk, Option.isSome_none]
            rw [rest]
            have same : index + 1 + n = index + (n + 1) := by omega
            simp only [loop, if_neg stopped, same]

def sourceHandler (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (s : State) : Transition State :=
  let copied := sourceLoop width nextPc decisions 0 (s.gpr 1).toNat s
  if copied.1.fault.isSome then copied.1 else
    ⟨{ copied.1.state with gpr := emittedRegisters width copied.2 s }, copied.1.events, none⟩

theorem source_handler_selected (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (completed : Nat) (s : State)
    (within : completed ≤ (s.gpr 1).toNat)
    (earlier : ∀ j, j < completed → decisions j = false)
    (selected : completed < (s.gpr 1).toNat → decisions completed = true)
    (successful : (loop width nextPc 0 completed s).fault = none) :
    sourceHandler width nextPc decisions s =
      ⟨{ (loop width nextPc 0 completed s).state with gpr := emittedRegisters width completed s },
        (loop width nextPc 0 completed s).events, none⟩ := by
  have result := source_loop_selected width nextPc decisions completed 0 (s.gpr 1).toNat s within
    (by intro j start bound; exact earlier j (by simpa using bound))
    (by simpa using selected) successful
  unfold sourceHandler
  rw [result]
  simp only [Nat.zero_add, successful, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]

theorem source_handler_success (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (s : State)
    (ordinary : ∀ j, j < (s.gpr 1).toNat → decisions j = false)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    sourceHandler width nextPc decisions s = handlerStep width nextPc s := by
  rw [source_handler_selected width nextPc decisions (s.gpr 1).toNat s (by omega) ordinary
    (by intro impossible; omega) successful]
  simp [handlerStep, successful]

theorem loop_next_pc (width : ScalarWidth) (nextPc priorPc : Reference.Word)
    (count index : Nat) (s : State)
    (successful : (loop width priorPc index count s).fault = none) :
    loop width nextPc index count s =
      ⟨{ (loop width priorPc index count s).state with pc := nextPc },
        (loop width priorPc index count s).events, none⟩ := by
  induction count generalizing index s with
  | zero => rfl
  | succ n ih =>
      by_cases stopped : (element width index s).fault.isSome = true
      · have bad : (element width index s).fault = none := by simpa [loop, stopped] using successful
        simp [bad] at stopped
      · have restOk : (loop width priorPc (index + 1) n (element width index s).state).fault = none := by
          simpa [loop, stopped] using successful
        rw [loop]
        simp only [if_neg stopped]
        rw [ih (index + 1) (element width index s).state restOk]
        simp only [loop, if_neg stopped]

theorem source_handler_recovery_matches (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (completed : Nat) (s : State)
    (within : completed ≤ (s.gpr 1).toNat)
    (earlier : ∀ j, j < completed → decisions j = false)
    (selected : completed < (s.gpr 1).toNat → decisions completed = true)
    (successful : (loop width s.pc 0 completed s).fault = none) :
    sourceHandler width nextPc decisions s = recoveryFinish width nextPc completed s := by
  have changed := loop_next_pc width nextPc s.pc completed 0 s successful
  have nextOk : (loop width nextPc 0 completed s).fault = none := by rw [changed]
  rw [source_handler_selected width nextPc decisions completed s within earlier selected nextOk]
  rw [changed]
  rfl

theorem source_handler_step_refines (width : ScalarWidth) (nextPc : Reference.Word)
    (decisions : Nat → Bool) (s : State)
    (direction : s.rflags.getLsbD 10 = false)
    (ordinary : ∀ j, j < (s.gpr 1).toNat → decisions j = false)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) s (sourceHandler width nextPc decisions s) := by
  rw [source_handler_success width nextPc decisions s ordinary successful]
  exact handler_step_refines width nextPc s direction successful

theorem recovery_fresh_bit (word : Reference.Word) :
    decide (word &&& 1 ≠ 0) = word.getLsbD 0 := by bv_decide

theorem recovery_effective_address (width : ScalarWidth) (s : State) (index : Nat) :
    generatedX86RepMovsAdvance (s.gpr 6) index (X86Scalar.handlerWidth width) =
      s.gpr 6 + BitVec.ofNat 64 index * BitVec.ofNat 64 width.bytes := by
  cases width <;> apply BitVec.eq_of_toNat_eq <;>
    simp [generatedX86RepMovsAdvance, X86Scalar.handlerWidth, x86WidthBitsSpec,
      Reference.X86.ScalarWidth.bytes, Nat.mul_mod]

/-- Every ordinary physical-copy path above the unmapped low page has a
constant-zero per-read choice witness. Typed source routes bypass the branch. -/
theorem ordinary_choices_exist (scalarSource : Bool) (width : ScalarWidth) (s : State)
    (count : Nat)
    (high : scalarSource = true → ∀ j, j < count →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat) :
    ∃ choices : Nat → Reference.Word, ∀ j, j < count →
      recoveryDecision scalarSource width s choices j = false := by
  refine ⟨fun _ => 0, ?_⟩
  intro j within
  cases scalarSource with
  | false => rfl
  | true => rw [recovery_decision_high width s _ j (high rfl j within)]; rfl

/-- Choose the first selected recovery at any index. The lower-page rule and
fresh-bit route both select that point, while earlier successful addresses
carry the physical high-page premise. -/
theorem first_recovery_choices_exist (width : ScalarWidth) (s : State) (completed : Nat)
    (high : ∀ j, j < completed →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat) :
    ∃ choices : Nat → Reference.Word,
      (∀ j, j < completed → recoveryDecision true width s choices j = false) ∧
      recoveryDecision true width s choices completed = true := by
  refine ⟨fun j => if j = completed then 1 else 0, ?_, ?_⟩
  · intro j earlier
    rw [recovery_decision_high width s _ j (high j earlier)]
    have different : j ≠ completed := by omega
    simp [different]
  · simp [recoveryDecision]

/-- A generic witness for the actual branch predicate along a successful
physical copy profile. This proof is quantified over the whole state/count. -/
theorem source_body_success_witness (scalarSource : Bool) (width : ScalarWidth)
    (nextPc : Reference.Word) (s : State) (direction : s.rflags.getLsbD 10 = false)
    (high : scalarSource = true → ∀ j, j < (s.gpr 1).toNat →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    ∃ choices : Nat → Reference.Word,
      Reference.X86.Step (.repMovs width false 0 nextPc) s
        (sourceHandler width nextPc (recoveryDecision scalarSource width s choices) s) := by
  obtain ⟨choices, ordinary⟩ := ordinary_choices_exist scalarSource width s (s.gpr 1).toNat high
  exact ⟨choices, source_handler_step_refines width nextPc _ s direction ordinary successful⟩

end KProgFormal.Refinement.X86RepMovs.Indexed

namespace KProgFormal.Refinement.X86RepMovs.Indexed
open Reference
open Reference.X86 (ScalarWidth State)

/-- Install one finite family of per-read choices at dynamic input positions.
The schedule carries the primitive/compiler visit correspondence; injectivity
keeps the recovery choices independent of each other. Other input words retain
their original values, including interleaved primitive choices. -/
def installFresh (original : Nat → Reference.Word) (schedule : Nat → Nat)
    (values : Nat → Reference.Word) : Nat → Nat → Reference.Word
  | 0 => original
  | count + 1 => fun slot =>
      if slot = schedule count then values count else
        installFresh original schedule values count slot

theorem install_fresh_selected (original : Nat → Reference.Word) (schedule : Nat → Nat)
    (values : Nat → Reference.Word) (independent : ∀ ⦃i j : Nat⦄, schedule i = schedule j → i = j)
    (count index : Nat) (within : index < count) :
    installFresh original schedule values count (schedule index) = values index := by
  induction count with
  | zero => omega
  | succ count ih =>
      by_cases last : index = count
      · subst index; simp [installFresh]
      · have different : schedule index ≠ schedule count := fun same => last (independent same)
        simp only [installFresh, if_neg different]
        exact ih (by omega)

theorem install_fresh_outside (original : Nat → Reference.Word) (schedule : Nat → Nat)
    (values : Nat → Reference.Word) (count slot : Nat)
    (outside : ∀ index, index < count → slot ≠ schedule index) :
    installFresh original schedule values count slot = original slot := by
  induction count with
  | zero => rfl
  | succ count ih =>
      simp only [installFresh, if_neg (outside count (by omega))]
      exact ih (by intro index within; exact outside index (by omega))

/-- Whole-count ordinary recovery decisions embed into any independent set of
fresh-word visits, with the surrounding input stream preserved. -/
theorem ordinary_stream_exists (scalarSource : Bool) (width : ScalarWidth) (s : State)
    (original : Nat → Reference.Word) (schedule : Nat → Nat) (independent : ∀ ⦃i j : Nat⦄, schedule i = schedule j → i = j)
    (count : Nat)
    (high : scalarSource = true → ∀ j, j < count →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat) :
    ∃ stream : Nat → Reference.Word,
      (∀ slot, (∀ j, j < count → slot ≠ schedule j) → stream slot = original slot) ∧
      (∀ j, j < count → recoveryDecision scalarSource width s (fun i => stream (schedule i)) j = false) := by
  obtain ⟨values, ordinary⟩ := ordinary_choices_exist scalarSource width s count high
  refine ⟨installFresh original schedule values count, ?_, ?_⟩
  · intro slot outside
    exact install_fresh_outside original schedule values count slot outside
  · intro j within
    simpa only [recoveryDecision, install_fresh_selected original schedule values independent count j within]
      using ordinary j within

/-- The first selected recovery and its successful prefix use a finite set of
visits. Positions after that recovery and interleaved inputs retain their words. -/
theorem first_recovery_stream_exists (width : ScalarWidth) (s : State)
    (original : Nat → Reference.Word) (schedule : Nat → Nat) (independent : ∀ ⦃i j : Nat⦄, schedule i = schedule j → i = j)
    (completed : Nat)
    (high : ∀ j, j < completed →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat) :
    ∃ stream : Nat → Reference.Word,
      (∀ slot, (∀ j, j < completed + 1 → slot ≠ schedule j) → stream slot = original slot) ∧
      (∀ j, j < completed → recoveryDecision true width s (fun i => stream (schedule i)) j = false) ∧
      recoveryDecision true width s (fun i => stream (schedule i)) completed = true := by
  obtain ⟨values, earlier, selected⟩ := first_recovery_choices_exist width s completed high
  refine ⟨installFresh original schedule values (completed + 1), ?_, ?_, ?_⟩
  · intro slot outside
    exact install_fresh_outside original schedule values (completed + 1) slot outside
  · intro j within
    have bound : j < completed + 1 := by omega
    simpa only [recoveryDecision, install_fresh_selected original schedule values independent (completed + 1) j bound]
      using earlier j within
  · simpa only [recoveryDecision, install_fresh_selected original schedule values independent (completed + 1) completed (by omega)]
      using selected

/-- Generic successful source-body refinement with a shared input-stream
witness. The schedule, scalar primitive and native entry/profile transport
remain explicit caller interfaces. -/
theorem source_body_success_stream_witness (scalarSource : Bool) (width : ScalarWidth)
    (nextPc : Reference.Word) (s : State) (direction : s.rflags.getLsbD 10 = false)
    (original : Nat → Reference.Word) (schedule : Nat → Nat) (independent : ∀ ⦃i j : Nat⦄, schedule i = schedule j → i = j)
    (high : scalarSource = true → ∀ j, j < (s.gpr 1).toNat →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat)
    (successful : (loop width nextPc 0 (s.gpr 1).toNat s).fault = none) :
    ∃ stream : Nat → Reference.Word,
      (∀ slot, (∀ j, j < (s.gpr 1).toNat → slot ≠ schedule j) → stream slot = original slot) ∧
      Reference.X86.Step (.repMovs width false 0 nextPc) s
        (sourceHandler width nextPc (recoveryDecision scalarSource width s (fun j => stream (schedule j))) s) := by
  obtain ⟨stream, outside, ordinary⟩ := ordinary_stream_exists scalarSource width s original schedule independent (s.gpr 1).toNat high
  exact ⟨stream, outside, source_handler_step_refines width nextPc _ s direction ordinary successful⟩

/-- Shared-stream recovery reaches the exact captured-prefix memory, events,
pointer writeback and RCX clear. O4 supplies the actual fault and registered
continuation relation through recoveryFinish. -/
theorem source_recovery_stream_witness (width : ScalarWidth) (nextPc : Reference.Word) (s : State)
    (original : Nat → Reference.Word) (schedule : Nat → Nat) (independent : ∀ ⦃i j : Nat⦄, schedule i = schedule j → i = j)
    (completed : Nat) (remaining : completed < (s.gpr 1).toNat)
    (high : ∀ j, j < completed →
      4096 ≤ (generatedX86RepMovsAdvance (s.gpr 6) j (X86Scalar.handlerWidth width)).toNat)
    (successful : (loop width s.pc 0 completed s).fault = none) :
    ∃ stream : Nat → Reference.Word,
      (∀ slot, (∀ j, j < completed + 1 → slot ≠ schedule j) → stream slot = original slot) ∧
      sourceHandler width nextPc (recoveryDecision true width s (fun j => stream (schedule j))) s =
        recoveryFinish width nextPc completed s := by
  obtain ⟨stream, outside, earlier, selected⟩ := first_recovery_stream_exists width s original schedule independent completed high
  exact ⟨stream, outside, source_handler_recovery_matches width nextPc _ completed s (by omega)
    earlier (by intro _; exact selected) successful⟩

end KProgFormal.Refinement.X86RepMovs.Indexed
