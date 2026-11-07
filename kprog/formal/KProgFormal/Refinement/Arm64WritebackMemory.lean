import KProgFormal.Refinement.Arm64VectorMemory
import KProgFormal.Arm64LdrsxOp

namespace KProgFormal.Refinement.Arm64WritebackMemory
open Reference Reference.AArch64
open Arm64VectorMemory (bumpBase)

/-- Numeric successful scalar transfer in the actual generated body: exact
load narrowing/sign extension and destination write, or a native-width store.
It contains no invented C permission or alignment branch. -/
def success (width : MemoryWidth) (transfer : MemoryTransfer) (address : Word)
    (s : State) : Transition State :=
  match transfer with
  | .load dst signedTo =>
      let value := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width)
        (wordAt s.memory address 8)
      ⟨{ Arm64Register.writeReg s dst (Arm64Memory.loadResult width signedTo value)
          (Arm64Memory.destinationWidth width signedTo) with pc := s.pc + 4 },
       [.memory .read address (bytesAt s.memory address width.bytes)
         (initializedAt s.memory address width.bytes)], none⟩
  | .store src =>
      let value := Arm64Register.readReg s src
      ⟨{ s with memory := Arm64Memory.store width s.memory address value, pc := s.pc + 4 },
       [.memory .write address (valueBytes value width.bytes) true], none⟩

/-- A writeback base is SP or differs from the transfer data field. This is
exactly the existing canonical constrained-unpredictability witness, including
stores; field31 still reads/discards ZR when used as transfer data. -/
def separate (transfer : MemoryTransfer) (base : Register) : Prop :=
  base.val = 31 ∨ transfer.register ≠ base

theorem read_bump (s : State) (base src : Register) (delta : Word)
    (apart : base.val = 31 ∨ src ≠ base) :
    Arm64Register.readReg (bumpBase s base delta) src = Arm64Register.readReg s src := by
  simp only [Arm64VectorMemory.bump_refines, Arm64Register.read_refines]
  rcases apart with stack | different
  · simp [writeMemoryBase, stack, readReg]
  · have values : src.val ≠ base.val := by
      intro equal
      exact different (Fin.ext equal)
    by_cases stack : base.val = 31
    · simp [writeMemoryBase, stack, readReg]
    · simp [writeMemoryBase, stack, readReg, writeReg, values]

theorem base_success (width : MemoryWidth) (transfer : MemoryTransfer) (address : Word)
    (s : State) (base : Register) (apart : separate transfer base) :
    memoryBase (success width transfer address s).state base = memoryBase s base := by
  cases transfer with
  | store src => rfl
  | load dst signedTo =>
    simp only [success, Arm64Register.write_refines]
    rcases apart with stack | different
    · simp [memoryBase, writeReg, show ¬base.val < 31 by omega]
    · have values : base.val ≠ dst.val := by
        intro equal
        exact different (Fin.ext equal.symm)
      simp [memoryBase, writeReg, values]

/-- Pre-indexing does not change a legal transfer's source or destination
cell. Commutation preserves the whole numeric state and the exact byte event. -/
theorem bump_success (width : MemoryWidth) (transfer : MemoryTransfer) (address : Word)
    (s : State) (base : Register) (delta : Word) (apart : separate transfer base) :
    success width transfer address (bumpBase s base delta) =
      { success width transfer address s with
        state := bumpBase (success width transfer address s).state base delta } := by
  have readApart : base.val = 31 ∨ transfer.register ≠ base := apart
  simp only [Arm64VectorMemory.bump_refines, base_success width transfer address s base apart]
  cases transfer with
  | store src =>
    have source := read_bump s base src delta readApart
    rw [Arm64VectorMemory.bump_refines] at source
    simp only [success, source]
    by_cases stack : base.val = 31 <;> simp [writeMemoryBase, stack, writeReg]
  | load dst signedTo =>
    simp only [success, Arm64Register.write_refines]
    rcases readApart with stack | different
    · simp [writeMemoryBase, stack, writeReg]
    · have values : dst.val ≠ base.val := by
        intro equal
        exact different (Fin.ext equal)
      by_cases stack : base.val = 31
      · simp [writeMemoryBase, stack, writeReg]
      · simp only [writeMemoryBase, stack, ↓reduceIte, writeReg]
        congr 1
        congr 1
        funext r
        by_cases d : r.val = dst.val <;> by_cases b : r.val = base.val <;>
          simp_all

/-- Actual numeric pre/access/post order, using the generated deltas and
immediate suppression. Entry/O4 supplies native values and successful access. -/
def core (width : MemoryWidth) (transfer : MemoryTransfer) (mode : Writeback)
    (base : Register) (delta : Word) (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s base (GeneratedArm64MemPrepost.preDelta flags delta)
  let offset := GeneratedArm64MemOffset.value
    (GeneratedArm64MemPrepost.suppressOffset flags) false delta 0
  let transferred := success width transfer (Arm64Memory.baseValue before base + offset) before
  { transferred with state := bumpBase transferred.state base (GeneratedArm64MemPrepost.postDelta flags delta) }

theorem core_eq (width : MemoryWidth) (transfer : MemoryTransfer) (mode : Writeback)
    (base : Register) (delta : Word) (s : State)
    (apart : mode ≠ .none → separate transfer base) :
    core width transfer mode base delta s =
      let address := memoryBase s base + (if mode = .post then 0 else delta)
      let transferred := success width transfer address s
      { transferred with state := if mode = .none then transferred.state else
          writeMemoryBase transferred.state base (memoryBase s base + delta) } := by
  cases mode with
  | none =>
    simp [core, Arm64AddressedMemory.flags, GeneratedArm64MemPrepost.preDelta,
      GeneratedArm64MemPrepost.postDelta, GeneratedArm64MemPrepost.preWriteback,
      GeneratedArm64MemPrepost.postWriteback, GeneratedArm64MemPrepost.suppressOffset,
      GeneratedArm64MemPrepost.flags, GeneratedArm64MemOffset.value, bumpBase,
      Arm64Memory.base_refines, Reference.Word]
  | pre =>
    have distinct := apart (by decide)
    simp only [core, Arm64Memory.base_refines, Arm64VectorMemory.base_bump, BitVec.add_assoc,
      Arm64AddressedMemory.access_offset_refines, bump_success width transfer _ s base _ distinct]
    rw [Arm64VectorMemory.writeback_base_refines]
    simp [Reference.Word, base_success width transfer _ s base distinct]
  | post =>
    have distinct := apart (by decide)
    simp only [core, Arm64Memory.base_refines, Arm64VectorMemory.base_bump, BitVec.add_assoc,
      Arm64AddressedMemory.access_offset_refines, bump_success width transfer _ s base _ distinct]
    rw [Arm64VectorMemory.writeback_base_refines]
    simp [Reference.Word, base_success width transfer _ s base distinct]

/-- Exact success refinement for the generated scalar transfer at an admitted
address, including all widths, signed W/X results, ZR and byte effects. -/
theorem success_refines (i : MemoryInstruction) (s : State)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted (match i.transfer with
      | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (memoryBase s i.base + i.offset) i.width.bytes = true) :
    success i.width i.transfer (memoryBase s i.base + i.offset) s = step (.memory i) s := by
  simp only [step, memoryStep, alignment]
  cases h : i.transfer <;>
    simp_all [h, success, readMemory, writeMemory, Arm64Memory.load_value,
      Arm64Register.write_refines, Arm64Register.read_refines, Arm64Memory.store_refines,
      Arm64Memory.load_result_refines]

/-- For valid immediate forms, the numeric C pre/access/post body implements
one canonical scalar memory step. The existing noOverlap field supplies the
architectural alias restriction; original-SP alignment and successful memory
access remain explicit admission witnesses, not inserted runtime guards. -/
theorem core_refines (i : AddressedMemoryInstruction) (delta : Word) (s : State)
    (immediate : i.offset = .immediate delta)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted (match i.transfer with
      | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true) :
    core i.width i.transfer i.writeback i.base delta s = step (.addressedMemory i) s := by
  have apart : i.writeback ≠ .none → separate i.transfer i.base := by
    intro writes
    by_cases stack : i.base.val = 31
    · exact Or.inl stack
    · exact Or.inr (i.noOverlap writes stack)
  rw [core_eq _ _ _ _ _ _ apart]
  have refined := success_refines
    (⟨i.width, i.transfer, i.base, if i.writeback = .post then 0 else delta⟩ : MemoryInstruction)
    s alignment accessible
  simp only [step] at refined
  simp only [step, addressedMemoryStep, immediate, memoryOffset]
  rw [← refined]
  cases h : i.transfer <;> cases mode : i.writeback <;>
    simp [h, mode, success, writeMemoryBase, writeReg]

/-- The actual unsigned LOAD and STORE singleton predicates select the core.
Sign-extending loads use their own opcode family and retain the core theorem's
explicit signedTo parameter; they are not mislabeled as the LOAD singleton. -/
def dispatch (op : GeneratedArm64DispatchSingleton.SingletonOp) (width : MemoryWidth)
    (data base : Register) (mode : Writeback) (delta : Word) (s : State) :
    Option (Transition State) :=
  if GeneratedArm64DispatchSingleton.loadHandled op then
    some (core width (.load data none) mode base delta s)
  else if GeneratedArm64DispatchSingleton.storeHandled op then
    some (core width (.store data) mode base delta s)
  else none

theorem dispatch_load_refines (i : AddressedMemoryInstruction) (dst : Register)
    (delta : Word) (s : State) (transfer : i.transfer = .load dst none)
    (immediate : i.offset = .immediate delta)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true) :
    dispatch .load i.width dst i.base i.writeback delta s =
      some (step (.addressedMemory i) s) := by
  have permittedAccess : permitted (match i.transfer with
      | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true := by
    simpa only [transfer] using accessible
  have refined := core_refines i delta s immediate alignment permittedAccess
  rw [transfer] at refined
  change some (core i.width (.load dst none) i.writeback i.base delta s) = _
  rw [refined]

theorem dispatch_store_refines (i : AddressedMemoryInstruction) (src : Register)
    (delta : Word) (s : State) (transfer : i.transfer = .store src)
    (immediate : i.offset = .immediate delta)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.writable
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true) :
    dispatch .store i.width src i.base i.writeback delta s =
      some (step (.addressedMemory i) s) := by
  have permittedAccess : permitted (match i.transfer with
      | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true := by
    simpa only [transfer] using accessible
  have refined := core_refines i delta s immediate alignment permittedAccess
  rw [transfer] at refined
  change some (core i.width (.store src) i.writeback i.base delta s) = _
  rw [refined]

theorem dispatch_other (op : GeneratedArm64DispatchSingleton.SingletonOp)
    (width : MemoryWidth) (data base : Register) (mode : Writeback) (delta : Word) (s : State)
    (notLoad : op ≠ .load) (notStore : op ≠ .store) :
    dispatch op width data base mode delta s = none := by
  simp [dispatch, GeneratedArm64DispatchSingleton.loadHandled,
    GeneratedArm64DispatchSingleton.storeHandled, notLoad, notStore]

/-- Generated register-offset modifier, parameterized by the scalar width:
W zero/sign extension, X/ZR reads and optional scaling are all retained. -/
def offsetValue (width : MemoryWidth) (s : State) : MemoryOffset → Word
  | .immediate value => value
  | .register index kind scaled =>
      GeneratedArm64Mod.value (Arm64AddressedMemory.modifier kind)
        (Arm64Register.readReg s index) (BitVec.ofNat 64 (if scaled then width.scale else 0)) .w64

theorem offset_refines (width : MemoryWidth) (s : State) (offset : MemoryOffset) :
    offsetValue width s offset = memoryOffset s width.scale offset := by
  cases offset with
  | immediate value => rfl
  | register index kind scaled =>
    have bound : (if scaled then width.scale else 0) < 5 := by
      cases width <;> cases scaled <;> decide
    simpa only [offsetValue, Arm64Register.read_refines, memoryOffset,
      Arm64AddressedMemory.indexValue] using
      Arm64AddressedMemory.index_refines kind (readReg s index)
        ⟨if scaled then width.scale else 0, bound⟩

/-- Register-offset forms carry no writeback. Compute the actual generated
modifier before accessing the transfer; all base/destination/index aliases
remain allowed, including a load overwriting its own address/index register. -/
theorem indexed_refines (i : AddressedMemoryInstruction) (s : State)
    (noWriteback : i.writeback = .none)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted (match i.transfer with
      | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (memoryBase s i.base + offsetValue i.width s i.offset) i.width.bytes = true) :
    core i.width i.transfer .none i.base (offsetValue i.width s i.offset) s =
      step (.addressedMemory i) s := by
  let direct : AddressedMemoryInstruction :=
    ⟨i.width, i.transfer, i.base, .immediate (offsetValue i.width s i.offset), .none,
      by intro impossible; exact False.elim (impossible rfl)⟩
  have refined := core_refines direct (offsetValue i.width s i.offset) s rfl alignment
    (by simpa only [direct, reduceCtorEq, ↓reduceIte] using accessible)
  simpa only [direct, step, addressedMemoryStep, noWriteback, memoryOffset,
    offset_refines, reduceCtorEq, ↓reduceIte] using refined

/-- Contract adapters retain the generated load opcode, independent memory
width and derived SXTB/SXTH/SXTW opcode. They define no second ISA semantics. -/
def signedWidth : GeneratedArm64LdrSx.LdrSx → MemoryWidth
  | .ldrSb => .byte | .ldrSh => .half | .ldrSw => .word

def signedSelector : GeneratedArm64LdrSx.LdrSx → GeneratedArm64LdrsxOp.LdrSxLoad
  | .ldrSb => .ldrSb | .ldrSh => .ldrSh | .ldrSw => .ldrSw

def signedExtend : GeneratedArm64LdrSx.LdrSx → GeneratedArm64Extrev.Extrev
  | .ldrSb => .sxtb | .ldrSh => .sxth | .ldrSw => .sxtw

theorem signed_selection (op : GeneratedArm64LdrSx.LdrSx) :
    Arm64Memory.valueWidth (signedWidth op) = GeneratedArm64LdrSx.loadWidth op ∧
    GeneratedArm64LdrsxOp.code (signedSelector op) = GeneratedArm64LdrSx.code op ∧
    GeneratedArm64Extrev.code (signedExtend op) = GeneratedArm64LdrsxOp.sxCode (signedSelector op) := by
  cases op <;> decide

/-- Actual LDRSX successful transfer: opcode-selected native load width,
opcode-selected shared sign-extension operation, then W/X destination write.
The destination width is independent of the memory access width. -/
def signedSuccess (op : GeneratedArm64LdrSx.LdrSx) (dst : Register) (output : Width)
    (address : Word) (s : State) : Transition State :=
  let width := signedWidth op
  let loaded := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width)
    (wordAt s.memory address 8)
  let value := GeneratedArm64Extrev.value (signedExtend op) loaded 0 0
    (Arm64Register.handlerWidth output)
  ⟨{ Arm64Register.writeReg s dst value output with pc := s.pc + 4 },
   [.memory .read address (bytesAt s.memory address width.bytes)
     (initializedAt s.memory address width.bytes)], none⟩

theorem signed_success_eq (op : GeneratedArm64LdrSx.LdrSx) (dst : Register) (output : Width)
    (address : Word) (s : State) :
    signedSuccess op dst output address s =
      success (signedWidth op) (.load dst (some output)) address s := by
  cases op <;> rfl

/-- The signed arm uses the same actual pre/access/post order, with the
explicit generated LDRSX transfer rather than an assumed signed result. -/
def signedCore (op : GeneratedArm64LdrSx.LdrSx) (dst : Register) (output : Width)
    (mode : Writeback) (base : Register) (delta : Word) (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s base (GeneratedArm64MemPrepost.preDelta flags delta)
  let offset := GeneratedArm64MemOffset.value
    (GeneratedArm64MemPrepost.suppressOffset flags) false delta 0
  let transferred := signedSuccess op dst output (Arm64Memory.baseValue before base + offset) before
  { transferred with state := bumpBase transferred.state base (GeneratedArm64MemPrepost.postDelta flags delta) }

theorem signed_core_eq (op : GeneratedArm64LdrSx.LdrSx) (dst : Register) (output : Width)
    (mode : Writeback) (base : Register) (delta : Word) (s : State) :
    signedCore op dst output mode base delta s =
      core (signedWidth op) (.load dst (some output)) mode base delta s := by
  simp only [signedCore, signed_success_eq, core]

theorem signed_core_refines (op : GeneratedArm64LdrSx.LdrSx) (i : AddressedMemoryInstruction)
    (dst : Register) (output : Width) (delta : Word) (s : State)
    (width : i.width = signedWidth op) (transfer : i.transfer = .load dst (some output))
    (immediate : i.offset = .immediate delta)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true) :
    signedCore op dst output i.writeback i.base delta s = step (.addressedMemory i) s := by
  rw [signed_core_eq, ← width, ← transfer]
  apply core_refines i delta s immediate alignment
  simpa only [transfer] using accessible

/-- The numeric family gate mirrors KPROG_ARM64_LDRSX_HANDLED and its three
case labels. An unrelated opcode is left to its own dispatcher arm. -/
def signedDecode (code : Nat) : Option GeneratedArm64LdrSx.LdrSx :=
  if code = GeneratedArm64LdrSx.code .ldrSb then some .ldrSb
  else if code = GeneratedArm64LdrSx.code .ldrSw then some .ldrSw
  else if code = GeneratedArm64LdrSx.code .ldrSh then some .ldrSh
  else none

theorem signed_decode_code (op : GeneratedArm64LdrSx.LdrSx) :
    signedDecode (GeneratedArm64LdrSx.code op) = some op := by
  cases op <;> rfl

def dispatchSigned (code : Nat) (dst : Register) (output : Width) (mode : Writeback)
    (base : Register) (delta : Word) (s : State) : Option (Transition State) :=
  (signedDecode code).map (fun op => signedCore op dst output mode base delta s)

theorem dispatch_signed_refines (op : GeneratedArm64LdrSx.LdrSx) (i : AddressedMemoryInstruction)
    (dst : Register) (output : Width) (delta : Word) (s : State)
    (width : i.width = signedWidth op) (transfer : i.transfer = .load dst (some output))
    (immediate : i.offset = .immediate delta)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (memoryBase s i.base + (if i.writeback = .post then 0 else delta)) i.width.bytes = true) :
    dispatchSigned (GeneratedArm64LdrSx.code op) dst output i.writeback i.base delta s =
      some (step (.addressedMemory i) s) := by
  simp only [dispatchSigned, signed_decode_code]
  change some (signedCore op dst output i.writeback i.base delta s) = _
  rw [signed_core_refines op i dst output delta s width transfer immediate alignment accessible]

theorem dispatch_signed_other (code : Nat) (dst : Register) (output : Width) (mode : Writeback)
    (base : Register) (delta : Word) (s : State)
    (notByte : code ≠ 54) (notWord : code ≠ 57) (notHalf : code ≠ 63) :
    dispatchSigned code dst output mode base delta s = none := by
  simp [dispatchSigned, signedDecode, GeneratedArm64LdrSx.code, notByte, notWord, notHalf]

/-- Signed register-offset forms retain the generated index modifier and
memory scale as well as the independently selected sign-extension operation. -/
theorem signed_indexed_refines (op : GeneratedArm64LdrSx.LdrSx) (i : AddressedMemoryInstruction)
    (dst : Register) (output : Width) (s : State)
    (width : i.width = signedWidth op) (transfer : i.transfer = .load dst (some output))
    (noWriteback : i.writeback = .none)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (memoryBase s i.base + offsetValue i.width s i.offset) i.width.bytes = true) :
    signedCore op dst output .none i.base (offsetValue i.width s i.offset) s =
      step (.addressedMemory i) s := by
  rw [signed_core_eq, ← width, ← transfer]
  apply indexed_refines i s noWriteback alignment
  simpa only [transfer] using accessible

theorem dispatch_signed_indexed_refines (op : GeneratedArm64LdrSx.LdrSx)
    (i : AddressedMemoryInstruction) (dst : Register) (output : Width) (s : State)
    (width : i.width = signedWidth op) (transfer : i.transfer = .load dst (some output))
    (noWriteback : i.writeback = .none)
    (alignment : spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (memoryBase s i.base + offsetValue i.width s i.offset) i.width.bytes = true) :
    dispatchSigned (GeneratedArm64LdrSx.code op) dst output .none i.base
      (offsetValue i.width s i.offset) s = some (step (.addressedMemory i) s) := by
  simp only [dispatchSigned, signed_decode_code]
  change some (signedCore op dst output .none i.base (offsetValue i.width s i.offset) s) = _
  rw [signed_indexed_refines op i dst output s width transfer noWriteback alignment accessible]

/-- Two ordered scalar-sized accesses on the non-LSE2 pair profile. Both
addresses are captured before either register write; the final PC advances once.
Generated pair direction and width-dependent stride remain explicit. -/
def pairSuccess (i : PairMemoryInstruction) (address : Word) (s : State) : Transition State :=
  let load := GeneratedArm64PairMem.access (Arm64PairMemory.opcode i) == .load
  let firstTransfer := if load then MemoryTransfer.load i.first none else .store i.first
  let secondTransfer := if load then MemoryTransfer.load i.second none else .store i.second
  let first := success (Arm64PairMemory.accessWidth i) firstTransfer address s
  let second := success (Arm64PairMemory.accessWidth i) secondTransfer
    (Arm64PairMemory.secondAddress i address) first.state
  { second with state := { second.state with pc := s.pc + 4 }, events := first.events ++ second.events }

/-- Actual successful LDP/STP core on the two-access profile, retaining both
ordered element events and all state. This is not a single-copy atomicity claim. -/
theorem pair_success_refines (i : PairMemoryInstruction) (s : State)
    (alignment : spAlignmentFault s i.base = none) (twoAccesses : s.pairSingleAccess = false)
    (firstAccess : permitted (if i.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.base + i.offset) i.width.bytes = true)
    (secondAccess : permitted (if i.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.base + i.offset + BitVec.ofNat 64 i.width.bytes) i.width.bytes = true) :
    pairSuccess i (memoryBase s i.base + i.offset) s = step (.pairMemory i) s := by
  have storePermission (m : Memory) (address value : Word) (bytes : Nat) :
      (storeMemory m address value bytes).writable = m.writable := rfl
  have fields := Arm64PairMemory.fields_refine i s
  simp only [pairSuccess, fields.2.2.2.1, fields.2.2.2.2, step, pairMemoryStep, alignment,
    twoAccesses, Bool.false_eq_true, ↓reduceIte]
  rcases i with ⟨width, load, first, second, base, offset, distinct⟩
  cases width <;> cases load <;>
    simp_all only [success, Arm64PairMemory.accessWidth, readMemory, writeMemory,
      Arm64Memory.load_value, Arm64Memory.store_refines, Arm64Register.write_refines,
      Arm64Register.read_refines, Arm64Memory.load_result_refines, pairRegisters,
      Width.bytes, MemoryWidth.bytes, Bool.false_eq_true, ↓reduceIte] <;>
    simp_all [memoryLoadValue, narrow, Width.bits, MemoryWidth.bits,
      MemoryWidth.bytes, readReg, writeReg, Arm64Memory.destinationWidth, storePermission]


theorem bump_pc_value (s : State) (base : Register) (delta : Word) :
    (bumpBase s base delta).pc = s.pc := by
  simp only [Arm64VectorMemory.bump_refines, writeMemoryBase, writeReg]
  split <;> rfl

theorem bump_pc (s : State) (base : Register) (delta pc : Word) :
    bumpBase { s with pc := pc } base delta = { bumpBase s base delta with pc := pc } := by
  simp only [Arm64VectorMemory.bump_refines]
  by_cases stack : base.val = 31 <;>
    simp [writeMemoryBase, memoryBase, stack, writeReg]

theorem base_pc (s : State) (base : Register) (pc : Word) :
    memoryBase { s with pc := pc } base = memoryBase s base := rfl

/-- Both pair data fields are distinct from a written-back GPR base. SP is a
separate cell even when a transfer field31 denotes ZR. -/
theorem pair_bump_success (i : PairMemoryInstruction) (address : Word) (s : State)
    (base : Register) (delta : Word)
    (firstApart : base.val = 31 ∨ i.first ≠ base)
    (secondApart : base.val = 31 ∨ i.second ≠ base) :
    pairSuccess i address (bumpBase s base delta) =
      { pairSuccess i address s with state := bumpBase (pairSuccess i address s).state base delta } := by
  let load := GeneratedArm64PairMem.access (Arm64PairMemory.opcode i) == .load
  have one : separate (if load then .load i.first none else .store i.first) base := by
    split <;> exact firstApart
  have two : separate (if load then .load i.second none else .store i.second) base := by
    split <;> exact secondApart
  simp only [pairSuccess]
  rw [bump_success _ _ _ s base delta one]
  simp only []
  rw [bump_success _ _ _ _ base delta two]
  simp only [bump_pc_value, bump_pc] <;> rfl

theorem pair_base_success (i : PairMemoryInstruction) (address : Word) (s : State)
    (base : Register) (firstApart : base.val = 31 ∨ i.first ≠ base)
    (secondApart : base.val = 31 ∨ i.second ≠ base) :
    memoryBase (pairSuccess i address s).state base = memoryBase s base := by
  let load := GeneratedArm64PairMem.access (Arm64PairMemory.opcode i) == .load
  have one : separate (if load then .load i.first none else .store i.first) base := by
    split <;> exact firstApart
  have two : separate (if load then .load i.second none else .store i.second) base := by
    split <;> exact secondApart
  simp only [pairSuccess, base_pc]
  rw [base_success _ _ _ _ base two, base_success _ _ _ _ base one]

/-- Actual pair pre/access/post order; the pair transfer keeps both ordered
native-width effects instead of coalescing them into one access. -/
def pairCore (i : PairMemoryInstruction) (mode : Writeback) (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s i.base (GeneratedArm64MemPrepost.preDelta flags i.offset)
  let offset := GeneratedArm64MemOffset.value
    (GeneratedArm64MemPrepost.suppressOffset flags) false i.offset 0
  let transferred := pairSuccess i (Arm64Memory.baseValue before i.base + offset) before
  { transferred with state := bumpBase transferred.state i.base (GeneratedArm64MemPrepost.postDelta flags i.offset) }

theorem pair_core_eq (i : PairMemoryInstruction) (mode : Writeback) (s : State)
    (apart : mode ≠ .none → i.base.val ≠ 31 → i.first ≠ i.base ∧ i.second ≠ i.base) :
    pairCore i mode s =
      let address := memoryBase s i.base + (if mode = .post then 0 else i.offset)
      let transferred := pairSuccess i address s
      { transferred with state := if mode = .none then transferred.state else
          writeMemoryBase transferred.state i.base (memoryBase s i.base + i.offset) } := by
  cases mode with
  | none =>
    simp [pairCore, Arm64AddressedMemory.flags, GeneratedArm64MemPrepost.preDelta,
      GeneratedArm64MemPrepost.postDelta, GeneratedArm64MemPrepost.preWriteback,
      GeneratedArm64MemPrepost.postWriteback, GeneratedArm64MemPrepost.suppressOffset,
      GeneratedArm64MemPrepost.flags, GeneratedArm64MemOffset.value, bumpBase,
      Arm64Memory.base_refines, Reference.Word]
  | pre | post =>
    have firstApart : i.base.val = 31 ∨ i.first ≠ i.base := by
      by_cases stack : i.base.val = 31
      · exact Or.inl stack
      · exact Or.inr (apart (by decide) stack).1
    have secondApart : i.base.val = 31 ∨ i.second ≠ i.base := by
      by_cases stack : i.base.val = 31
      · exact Or.inl stack
      · exact Or.inr (apart (by decide) stack).2
    simp only [pairCore, Arm64Memory.base_refines, Arm64VectorMemory.base_bump, BitVec.add_assoc,
      Arm64AddressedMemory.access_offset_refines, pair_bump_success i _ s i.base _ firstApart secondApart]
    rw [Arm64VectorMemory.writeback_base_refines]
    simp [Reference.Word, pair_base_success i _ s i.base firstApart secondApart]

theorem success_fault (width : MemoryWidth) (transfer : MemoryTransfer)
    (address : Word) (s : State) : (success width transfer address s).fault = none := by
  cases transfer <;> rfl

theorem pair_success_fault (i : PairMemoryInstruction) (address : Word) (s : State) :
    (pairSuccess i address s).fault = none := by
  simp only [pairSuccess, success_fault]

/-- Full numeric LDP/STP pre/access/post refinement on the two-access profile.
Each element is accessible, and the original incoming SP passes alignment.
The canonical noOverlap field supplies exactly the writeback alias restriction;
no-writeback forms retain legal base/destination aliases. -/
theorem pair_core_refines (i : AddressedPairMemoryInstruction) (s : State)
    (alignment : spAlignmentFault s i.instruction.base = none)
    (twoAccesses : s.pairSingleAccess = false)
    (firstAccess : permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset))
      i.instruction.width.bytes = true)
    (secondAccess : permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset) +
        BitVec.ofNat 64 i.instruction.width.bytes) i.instruction.width.bytes = true) :
    pairCore i.instruction i.writeback s = step (.addressedPairMemory i) s := by
  rw [pair_core_eq i.instruction i.writeback s i.noOverlap]
  let transfer := if i.writeback = .post then { i.instruction with offset := 0 } else i.instruction
  have aligned : spAlignmentFault s transfer.base = none := by
    dsimp only [transfer]
    split <;> exact alignment
  have first : permitted (if transfer.load then s.memory.readable else s.memory.writable)
      (memoryBase s transfer.base + transfer.offset) transfer.width.bytes = true := by
    dsimp only [transfer]
    split <;> rename_i mode <;> simpa only [mode, ↓reduceIte] using firstAccess
  have second : permitted (if transfer.load then s.memory.readable else s.memory.writable)
      (memoryBase s transfer.base + transfer.offset + BitVec.ofNat 64 transfer.width.bytes)
      transfer.width.bytes = true := by
    dsimp only [transfer]
    split <;> rename_i mode <;> simpa only [mode, ↓reduceIte] using secondAccess
  have refined := pair_success_refines transfer s aligned twoAccesses first second
  have projection : pairSuccess transfer (memoryBase s transfer.base + transfer.offset) s =
      pairSuccess i.instruction
        (memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset)) s := by
    dsimp only [transfer]
    split <;> rename_i mode <;> simp only [mode, ↓reduceIte] <;> rfl
  rw [projection] at refined
  simp only [step] at refined
  simp only [step, addressedPairMemoryStep]
  change _ = let result := pairMemoryStep transfer s
    if result.fault.isSome || i.writeback = .none then result else
      { result with state := writeMemoryBase result.state i.instruction.base (memoryBase s i.instruction.base + i.instruction.offset) }
  rw [← refined]
  by_cases mode : i.writeback = .none
  · simp [mode, pair_success_fault]
    rw [← pair_success_fault i.instruction (memoryBase s i.instruction.base + i.instruction.offset) s]
  · simp [mode, pair_success_fault]

/-- Pair dispatcher slice over a decoded descriptor. The refinement theorem
binds its load/store direction to the selected numeric singleton; this is a
source-descriptor relation, not a new C runtime guard. -/
def dispatchPair (op : GeneratedArm64DispatchSingleton.SingletonOp) (i : PairMemoryInstruction)
    (mode : Writeback) (s : State) : Option (Transition State) :=
  if GeneratedArm64DispatchSingleton.ldpHandled op then some (pairCore i mode s)
  else if GeneratedArm64DispatchSingleton.stpHandled op then some (pairCore i mode s)
  else none

theorem dispatch_pair_refines (i : AddressedPairMemoryInstruction) (s : State)
    (alignment : spAlignmentFault s i.instruction.base = none)
    (twoAccesses : s.pairSingleAccess = false)
    (firstAccess : permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset))
      i.instruction.width.bytes = true)
    (secondAccess : permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
      (memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset) +
        BitVec.ofNat 64 i.instruction.width.bytes) i.instruction.width.bytes = true) :
    dispatchPair (if i.instruction.load then .ldp else .stp) i.instruction i.writeback s =
      some (step (.addressedPairMemory i) s) := by
  have refined := congrArg some (pair_core_refines i s alignment twoAccesses firstAccess secondAccess)
  cases direction : i.instruction.load <;>
    simpa only [dispatchPair, direction, Bool.false_eq_true, ↓reduceIte,
      GeneratedArm64DispatchSingleton.ldpHandled, GeneratedArm64DispatchSingleton.stpHandled,
      beq_self_eq_true, reduceCtorEq] using refined

theorem dispatch_pair_other (op : GeneratedArm64DispatchSingleton.SingletonOp)
    (i : PairMemoryInstruction) (mode : Writeback) (s : State)
    (notLoad : op ≠ .ldp) (notStore : op ≠ .stp) :
    dispatchPair op i mode s = none := by
  simp [dispatchPair, GeneratedArm64DispatchSingleton.ldpHandled,
    GeneratedArm64DispatchSingleton.stpHandled, notLoad, notStore]

end KProgFormal.Refinement.Arm64WritebackMemory
