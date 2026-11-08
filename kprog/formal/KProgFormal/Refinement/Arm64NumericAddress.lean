import KProgFormal.Refinement.EntryEnvironment

namespace KProgFormal.Refinement.Arm64NumericAddress
open Reference EntryEnvironment

/-- The C cells retain relative payloads; numeric reads observe their
materialization in the same invocation and certified entry frame. -/
structure Cells where
  gpr : Reference.AArch64.Gpr → Value
  stackOffset : Word

def read (env : Environment) (frame : Frame) (cells : Cells) :
    Reference.AArch64.RegisterRef → Word
  | .general r => materialize env frame (cells.gpr r)
  | .zero => 0
  | .stack => base env frame .stack + cells.stackOffset

structure Related (env : Environment) (frame : Frame) (cells : Cells)
    (native : Reference.AArch64.State) : Prop where
  registers : ∀ r, materialize env frame (cells.gpr r) = native.gpr r
  stack : base env frame .stack + cells.stackOffset = native.sp

theorem read_refines (env : Environment) (frame : Frame) (cells : Cells)
    (native : Reference.AArch64.State) (relation : Related env frame cells native)
    (register : Reference.AArch64.RegisterRef) :
    read env frame cells register = Reference.AArch64.readData native register := by
  cases register with
  | general r => exact relation.registers r
  | zero => rfl
  | stack => exact relation.stack

/-- A scalar write to SP first narrows the actual bits, then normalizes the
stored offset. Truncating the old offset would lose the native base's low bits. -/
def scalarStackWrite (env : Environment) (frame : Frame)
    (width : Reference.AArch64.Width) (bits : Word) : Word :=
  Reference.AArch64.narrow bits width - base env frame .stack

theorem scalar_stack_write_refines (env : Environment) (frame : Frame)
    (width : Reference.AArch64.Width) (bits : Word) :
    base env frame .stack + scalarStackWrite env frame width bits =
      Reference.AArch64.narrow bits width := by
  simp only [scalarStackWrite, Word]
  bv_decide

/-- A full pointer spill keeps actual guest bytes and an independently stored
private payload. The tag permits using that payload only while the complete
word is intact. No guest initialization follows from this private metadata. -/
structure Spill where
  payload : Value
  guestBytes : List Byte

def Coherent (env : Environment) (frame : Frame) (spill : Spill) : Prop :=
  spill.guestBytes = valueBytes (materialize env frame spill.payload) 8

def spill (env : Environment) (frame : Frame) (payload : Value) : Spill :=
  ⟨payload, valueBytes (materialize env frame payload) 8⟩

theorem spill_coherent (env : Environment) (frame : Frame) (payload : Value) :
    Coherent env frame (spill env frame payload) := rfl

theorem reload_refines (env : Environment) (frame : Frame) (payload : Value) :
    materialize env frame (spill env frame payload).payload =
      materialize env frame payload := rfl

/-- Byte, narrow and vector observations use guest bytes, not the private
offset word. This includes each byte of a saved outer return address. -/
theorem observed_spill_bytes (env : Environment) (frame : Frame) (origin : Base)
    (offset : Word) :
    (spill env frame (.relative origin offset)).guestBytes =
      valueBytes (base env frame origin + offset) 8 := rfl

/-- Normalization is an inverse for all word values, including wrapping
addresses. A private reload must preserve the origin as well as the payload. -/
theorem normalize_materialize (env : Environment) (frame : Frame) (origin : Base)
    (offset : Word) :
    materialize env frame (.relative origin offset) - base env frame origin = offset := by
  simp only [materialize, Word]
  bv_decide

end KProgFormal.Refinement.Arm64NumericAddress

namespace KProgFormal.Refinement.Arm64NumericAddress.GhostDomain
open Reference

/-- Byte tags over the existing unsigned64 slot coordinate. The private
storage layout may omit a slot only if its observable tag remains scalar0.
Guest bytes, permissions and pointer payloads are separate state. -/
abbrev Tags := Word → Byte
abbrev Domain := Word → Bool

def project (kept : Domain) (backing : Tags) : Tags :=
  fun i => if kept i then backing i else 0

def write (tags : Tags) (dst : Word) (tag : Byte) : Tags :=
  fun i => if i = dst then tag else tags i

inductive Action where
  | store (dst : Word) (tag : Byte)
  | clear (erased : Word → Bool)
  | copy (dst src : Word)

/-- Static transformation premise, not an executable check or runtime gate.
A possibly tagged copy source requires storage for its destination. Opaque
analysis selects the full domain rather than rejecting the native program. -/
def Covered (kept : Domain) : Action → Prop
  | .store dst tag => tag ≠ 0 → kept dst = true
  | .clear _ => True
  | .copy dst src => kept src = true → kept dst = true

def fullStep : Action → Tags → Tags
  | .store dst tag, tags => write tags dst tag
  | .clear erased, tags => fun i => if erased i then 0 else tags i
  | .copy dst src, tags => write tags dst (tags src)

def sparseStep (kept : Domain) : Action → Tags → Tags
  | .store dst tag, backing =>
      if kept dst then write backing dst tag else backing
  | .clear erased, backing =>
      fun i => if kept i && erased i then 0 else backing i
  | .copy dst src, backing =>
      if kept dst then write backing dst (project kept backing src) else backing

def fullRun : List Action → Tags → Tags
  | [], tags => tags
  | action :: rest, tags => fullRun rest (fullStep action tags)

def sparseRun (kept : Domain) : List Action → Tags → Tags
  | [], backing => backing
  | action :: rest, backing => sparseRun kept rest (sparseStep kept action backing)

/-- Store, clear and copy commute with the actual read-zero/write-elision
representation. All64 index bits and all byte tags remain arbitrary. -/
theorem step_refines (kept : Domain) (backing : Tags) (action : Action)
    (covered : Covered kept action) :
    project kept (sparseStep kept action backing) = fullStep action (project kept backing) := by
  funext i
  cases action with
  | store dst tag =>
    by_cases same : i = dst
    · subst i
      cases present : kept dst with
      | true => simp [project, sparseStep, fullStep, write, present]
      | false =>
        have scalar : tag = 0 := by
          by_cases zero : tag = 0
          · exact zero
          · have impossible := covered zero
            simp [present] at impossible
        simp [project, sparseStep, fullStep, write, present, scalar]
    · cases present : kept dst <;> simp [project, sparseStep, fullStep, write, same, present]
  | clear erased =>
    cases present : kept i <;> cases cleared : erased i <;>
      simp [project, sparseStep, fullStep, present, cleared]
  | copy dst src =>
    by_cases same : i = dst
    · subst i
      cases present : kept dst with
      | true => simp [project, sparseStep, fullStep, write, present]
      | false =>
        have scalar : kept src = false := by
          cases origin : kept src with
          | false => rfl
          | true => have impossible := covered origin; simp [present] at impossible
        simp [project, sparseStep, fullStep, write, present, scalar]
    · cases present : kept dst <;> simp [project, sparseStep, fullStep, write, same, present]

/-- One universal theorem for every finite transformation history, including
loops unrolled to any length and sequential/overlapping metadata copies.
No per-program certificate or admission predicate is constructed. -/
theorem run_refines (kept : Domain) (backing : Tags) (actions : List Action)
    (covered : ∀ action ∈ actions, Covered kept action) :
    project kept (sparseRun kept actions backing) = fullRun actions (project kept backing) := by
  induction actions generalizing backing with
  | nil => rfl
  | cons action rest ih =>
    simp only [sparseRun, fullRun]
    rw [ih (sparseStep kept action backing) (fun a h => covered a (by simp [h]))]
    rw [step_refines kept backing action (covered action (by simp))]

/-- A dense source table is representable precisely when every omitted slot
is scalar. The analysis producer, not this theorem, must establish this fact. -/
def Supported (kept : Domain) (tags : Tags) : Prop :=
  ∀ i, kept i = false → tags i = 0

theorem project_supported (kept : Domain) (tags : Tags) (supported : Supported kept tags) :
    project kept tags = tags := by
  funext i
  cases present : kept i with
  | true => simp [project, present]
  | false => simp [project, present, supported i present]

theorem project_is_supported (kept : Domain) (backing : Tags) :
    Supported kept (project kept backing) := by
  intro i outside
  simp [project, outside]

theorem supported_preserved (kept : Domain) (tags : Tags) (supported : Supported kept tags)
    (action : Action) (covered : Covered kept action) :
    Supported kept (fullStep action tags) := by
  rw [← project_supported kept tags supported, ← step_refines kept tags action covered]
  exact project_is_supported _ _

/-- Dense and sparse complete lookup functions agree after every covered
history from the same supported initial tag table. Native bytes and payloads
are not read, rewritten or initialized by this private metadata component. -/
theorem supported_run_refines (kept : Domain) (tags : Tags)
    (supported : Supported kept tags) (actions : List Action)
    (covered : ∀ action ∈ actions, Covered kept action) :
    project kept (sparseRun kept actions tags) = fullRun actions tags := by
  simpa only [project_supported kept tags supported] using run_refines kept tags actions covered

/-- Full storage implements the opaque-domain case with no additional premise
on addresses, tag-producing stores or copy destinations. -/
theorem opaque_covered (action : Action) : Covered (fun _ => true) action := by
  cases action <;> simp [Covered]

theorem opaque_run (tags : Tags) (actions : List Action) :
    sparseRun (fun _ => true) actions tags = fullRun actions tags := by
  have result := run_refines (fun _ => true) tags actions (fun a _ => opaque_covered a)
  simpa [project] using result


/-- Numeric packed-tag expressions used by ARM64_SIM_L_TAG_GET/SET. The
physical word is supplied by the private storage relation; object alignment,
C aliasing and volatile/compiler ordering are not inferred from these bits. -/
def packedShift (index : Word) : Word := (index &&& 7) * 8

def packedRead (word index : Word) : Byte :=
  (word >>> packedShift index).setWidth 8

def packedWrite (word index : Word) (tag : Byte) : Word :=
  (word &&& ~~~((255 : Word) <<< packedShift index)) |||
    (tag.setWidth 64 <<< packedShift index)

theorem packed_read_write_same (word index : Word) (tag : Byte) :
    packedRead (packedWrite word index tag) index = tag := by
  unfold packedRead packedWrite packedShift Word Byte at *
  bv_decide

theorem packed_read_write_other (word index other : Word) (tag : Byte)
    (different : (index &&& 7) ≠ (other &&& 7)) :
    packedRead (packedWrite word index tag) other = packedRead word other := by
  unfold packedRead packedWrite packedShift Word Byte at *
  bv_decide

/-- Full byte-frame law: one tag changes, every other byte in the same packed
word is intact. Upper61 index bits do not change the selected byte lane. -/
theorem packed_write_byte_frame (word index other : Word) (tag : Byte) :
    packedRead (packedWrite word index tag) other =
      if (index &&& 7) = (other &&& 7) then tag else packedRead word other := by
  by_cases same : (index &&& 7) = (other &&& 7)
  · rw [if_pos same]
    have readSame : packedRead (packedWrite word index tag) other =
        packedRead (packedWrite word index tag) index := by
      simp only [packedRead, packedShift, same]
    exact readSame.trans (packed_read_write_same word index tag)
  · rw [if_neg same]
    exact packed_read_write_other word index other tag same

def packedBase (index : Word) : Word := index &&& ~~~(7 : Word)

def unpack (words : Word → Word) : Tags :=
  fun index => packedRead (words (packedBase index)) index

def writePacked (words : Word → Word) (index : Word) (tag : Byte) : Word → Word :=
  fun base => if base = packedBase index then packedWrite (words base) index tag else words base

private theorem base_lane_unique (index other : Word)
    (base : packedBase index = packedBase other)
    (lane : (index &&& 7) = (other &&& 7)) : index = other := by
  unfold packedBase Word at *
  bv_decide

/-- Exact packed-word store refines one byte-tag-array update over the whole
unsigned64 index space. Every tag outside the destination cell is retained.
This binds the word arithmetic to the abstract domain table; physical C
alignment/aliasing/volatile lowering remain the stated storage interface. -/
theorem packed_store_refines (words : Word → Word) (index : Word) (tag : Byte) :
    unpack (writePacked words index tag) = write (unpack words) index tag := by
  funext other
  by_cases same : other = index
  · subst other
    simp only [unpack, writePacked, write, ↓reduceIte, packed_read_write_same]
  · simp only [unpack, writePacked, write, if_neg same]
    by_cases block : packedBase other = packedBase index
    · rw [if_pos block]
      have different : (index &&& 7) ≠ (other &&& 7) := by
        intro lane
        have identical := base_lane_unique index other block.symm lane
        exact same identical.symm
      exact packed_read_write_other (words (packedBase other)) index other tag different
    · simp only [if_neg block]

end KProgFormal.Refinement.Arm64NumericAddress.GhostDomain
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.step_refines
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.run_refines
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.supported_run_refines
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.opaque_run

#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.packed_read_write_same
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.packed_read_write_other
#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.packed_write_byte_frame

#print axioms KProgFormal.Refinement.Arm64NumericAddress.GhostDomain.packed_store_refines
