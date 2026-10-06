import KProgFormal.GeneratedX86RepMovs
import KProgFormal.TagErasure
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86RepMovs (repMovsBound repMovsCopyWidthDefault repMovsCountWidth
  repMovsElementCount resolveWidth)
open GeneratedX86Store (Code)

/-- The literal element bound the `REP MOVS` body iterates to, as an independent
`Nat`. The body copies `min bound count` elements whatever the instruction
immediate says. -/
def x86RepMovsBoundSpec : Nat := 64

/-- The generated literal bound equals the independent one. -/
theorem x86_rep_movs_bound_refines : repMovsBound = x86RepMovsBoundSpec := by
  rfl

/-- The bound is sixty-four. -/
theorem x86_rep_movs_bound_is_sixty_four : x86RepMovsBoundSpec = 64 := by
  rfl

/-- The width a `REP MOVS` body copies at, as an `X86Width` with the `FLAGS`
code reading: the code itself, or 64 bits when it carries none. -/
def x86RepMovsWidthSpec : Code -> X86Width
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The copy width the generated `resolveWidth` table selects, restated for the
width definitions. -/
def generatedX86RepMovsWidth (flags : Code) : X86Width :=
  match resolveWidth flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated copy width equals the independent statement, for every `FLAGS`
code. -/
theorem x86_rep_movs_width_refines (flags : Code) :
    generatedX86RepMovsWidth flags = x86RepMovsWidthSpec flags := by
  cases flags <;> rfl

/-- A `REP MOVS` body honours the `FLAGS`-resolved width: a narrow code narrows
the copy, and an absent code defaults to 64 bits. -/
theorem x86_rep_movs_width_is_flags_resolved (flags : Code) :
    x86RepMovsWidthSpec flags =
      match flags with
      | .absent => .w64
      | .b8 => .w8
      | .b16 => .w16
      | .b32 => .w32
      | .b64 => .w64 := by
  cases flags <;> rfl

/-- An absent `FLAGS` code resolves to the 64-bit width. -/
theorem x86_rep_movs_absent_defaults (flags : Code) (h : flags = Code.absent) :
    x86RepMovsWidthSpec flags = .w64 := by
  subst h; rfl

/-- The number of elements the body copies: the literal bound capped by the
instruction immediate. -/
def x86RepMovsElementCountSpec (count : Nat) : Nat :=
  min x86RepMovsBoundSpec count

/-- The generated element count, restated. -/
def generatedX86RepMovsElementCount (count : Nat) : Nat :=
  repMovsElementCount count

/-- The generated element count equals the independent statement. -/
theorem x86_rep_movs_element_count_refines (count : Nat) :
    generatedX86RepMovsElementCount count = x86RepMovsElementCountSpec count := by
  simp [generatedX86RepMovsElementCount, x86RepMovsElementCountSpec,
    x86RepMovsBoundSpec, repMovsElementCount, repMovsBound]

/-- The body copies at most the literal bound, whatever the immediate says. -/
theorem x86_rep_movs_element_count_bounded (count : Nat) :
    x86RepMovsElementCountSpec count ≤ 64 := by
  show min x86RepMovsBoundSpec count ≤ 64
  exact Nat.min_le_left _ _

/-- The byte stride one element advances a pointer by: the copy width's byte
count. -/
def x86RepMovsStrideSpec (width : X86Width) : Nat :=
  x86WidthBitsSpec width / 8

/-- The stride is exactly the width's byte code. -/
theorem x86_rep_movs_stride_is_width_bytes (width : X86Width) :
    x86RepMovsStrideSpec width = x86WidthCodeSpec width := by
  cases width <;> rfl

/-- The pointer advance the generated body performs: the pointer plus the raw
count times the copy width's byte count. -/
def generatedX86RepMovsAdvance (ptr : BitVec 64) (count : Nat)
    (width : X86Width) : BitVec 64 :=
  ptr + BitVec.ofNat 64 (count * (x86WidthBitsSpec width / 8))

/-- Independent statement of the same advance. -/
def x86RepMovsAdvanceSpec (ptr : BitVec 64) (count : Nat)
    (width : X86Width) : BitVec 64 :=
  ptr + BitVec.ofNat 64 (count * x86RepMovsStrideSpec width)

/-- The generated advance equals the independent statement. -/
theorem x86_rep_movs_advance_refines (ptr : BitVec 64) (count : Nat)
    (width : X86Width) :
    generatedX86RepMovsAdvance ptr count width =
      x86RepMovsAdvanceSpec ptr count width := by
  simp [generatedX86RepMovsAdvance, x86RepMovsAdvanceSpec,
    x86RepMovsStrideSpec]

/-- The pointer advances by the *raw* instruction immediate, not by the capped
element count: a count beyond the bound copies only the bound's elements yet
still advances the full count. -/
theorem x86_rep_movs_overshoot_beyond_bound :
    x86RepMovsElementCountSpec 100 = 64 ∧
      x86RepMovsAdvanceSpec 0x1000 100 .w64 =
        0x1000 + BitVec.ofNat 64 (100 * 8) := by
  refine ⟨?_, ?_⟩
  · decide
  · simp [x86RepMovsAdvanceSpec, x86RepMovsStrideSpec, x86WidthBitsSpec]

/-- The count the body reads is the instruction immediate, not `RCX`. -/
theorem x86_rep_movs_count_is_immediate (count : Nat) :
    x86RepMovsElementCountSpec count = min 64 count := by
  simp [x86RepMovsElementCountSpec, x86RepMovsBoundSpec]

/-- The width at which the body zeroes `RCX`, as the fixed 64-bit width. -/
def x86RepMovsCountWidthSpec : X86Width := .w64

/-- The width the generated count-width table selects, restated. -/
def generatedX86RepMovsCountWidth : X86Width :=
  match repMovsCountWidth with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated count width equals the independent fixed 64-bit width: it does
not track the `FLAGS`-resolved copy width. -/
theorem x86_rep_movs_count_width_refines :
    generatedX86RepMovsCountWidth = x86RepMovsCountWidthSpec := by
  rfl

/-- The `RCX` writeback the generated body performs: zero at the fixed 64-bit
width. -/
def generatedX86RepMovsRcx (old : X86RegValue) : X86RegValue :=
  generatedX86RegWrite old 0 .w64

/-- Independent statement of the `RCX` writeback. -/
def x86RepMovsRcxSpec (old : X86RegValue) : X86RegValue :=
  x86RegWriteSpec old 0 .w64

/-- The generated `RCX` writeback equals the independent statement. -/
theorem x86_rep_movs_rcx_refines (old : X86RegValue) :
    generatedX86RepMovsRcx old = x86RepMovsRcxSpec old := by
  simp [generatedX86RepMovsRcx, x86RepMovsRcxSpec, x86_reg_write_refines]

/-- The `RCX` writeback zeroes `RCX` and scalarizes its tag, at the fixed 64-bit
width. -/
theorem x86_rep_movs_rcx_zeroed (old : X86RegValue) :
    (x86RepMovsRcxSpec old).bits = 0 ∧ (x86RepMovsRcxSpec old).tag = .scalar := by
  cases old
  exact ⟨rfl, rfl⟩

/-- The effect of one `REP MOVS` body. `width` is the `FLAGS`-resolved copy
width, `bound` the literal iteration bound, `count` the raw instruction
immediate, `elements` the copied element count (`min bound count`), `stride` the
per-element advance, `src`/`dst` the pointers the body copies between,
`srcAdvance`/`dstAdvance` the pointers it leaves behind, `srcTag`/`dstTag` the
provenance tags it rewrites each pointer with, `countWidth` the fixed width at
which it zeroes `RCX`, and `rcx` the zeroed register. -/
structure X86RepMovsEffect where
  width : X86Width
  bound : Nat
  count : Nat
  elements : Nat
  stride : Nat
  src : BitVec 64
  dst : BitVec 64
  srcAdvance : BitVec 64
  dstAdvance : BitVec 64
  srcTag : Tag
  dstTag : Tag
  countWidth : X86Width
  rcx : X86RegValue
  deriving DecidableEq, Repr

/-- The composed handler transition used by the body: the generated tables
select the `FLAGS`-resolved copy width and the fixed count width, the count is
the raw instruction immediate, the elements are the literal bound capped by it,
each pointer advances by the raw count times the copy stride, and `RCX` is
zeroed at the fixed 64-bit width. -/
def generatedX86RepMovsStep (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) : X86RepMovsEffect :=
  let width := generatedX86RepMovsWidth flags
  let count := imm.toNat
  { width := width, bound := repMovsBound, count := count,
    elements := generatedX86RepMovsElementCount count,
    stride := x86WidthBitsSpec width / 8,
    src := src, dst := dst,
    srcAdvance := generatedX86RepMovsAdvance src count width,
    dstAdvance := generatedX86RepMovsAdvance dst count width,
    srcTag := srcTagIn, dstTag := dstTagIn,
    countWidth := generatedX86RepMovsCountWidth,
    rcx := generatedX86RepMovsRcx old }

/-- Independent statement of the same handler: the width, bound, element count,
stride, advances, count width, and `RCX` writeback are the independent
statements. -/
def x86RepMovsStepSpec (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) : X86RepMovsEffect :=
  let width := x86RepMovsWidthSpec flags
  let count := imm.toNat
  { width := width, bound := x86RepMovsBoundSpec, count := count,
    elements := x86RepMovsElementCountSpec count,
    stride := x86RepMovsStrideSpec width,
    src := src, dst := dst,
    srcAdvance := x86RepMovsAdvanceSpec src count width,
    dstAdvance := x86RepMovsAdvanceSpec dst count width,
    srcTag := srcTagIn, dstTag := dstTagIn,
    countWidth := x86RepMovsCountWidthSpec, rcx := x86RepMovsRcxSpec old }

/-- The `REP MOVS` handler composition refines the independent width / bound /
count / element / advance / `RCX` statement for every `FLAGS` code, immediate,
source and destination pointer, and register. -/
theorem x86_rep_movs_step_refines (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    generatedX86RepMovsStep flags imm src dst srcTagIn dstTagIn old =
      x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old := by
  cases flags <;>
    simp [generatedX86RepMovsStep, x86RepMovsStepSpec, generatedX86RepMovsWidth,
      x86RepMovsWidthSpec, resolveWidth, generatedX86RepMovsElementCount,
      x86RepMovsElementCountSpec, repMovsElementCount, repMovsBound,
      x86RepMovsBoundSpec, generatedX86RepMovsAdvance, x86RepMovsAdvanceSpec,
      x86RepMovsStrideSpec, generatedX86RepMovsCountWidth, repMovsCountWidth,
      x86RepMovsCountWidthSpec, generatedX86RepMovsRcx, x86RepMovsRcxSpec,
      x86_reg_write_refines]

/-- The element width the body copies at is exactly the `FLAGS`-resolved width. -/
theorem x86_rep_movs_copy_width_is_flags_resolved (flags : Code)
    (imm src dst : BitVec 64) (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).width =
      x86RepMovsWidthSpec flags := by
  rfl

/-- The count the body carries is the raw instruction immediate, not `RCX`. -/
theorem x86_rep_movs_count_is_raw_immediate (flags : Code)
    (imm src dst : BitVec 64) (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).count =
      imm.toNat := by
  rfl

/-- The body copies at most the literal bound, whatever the immediate says. -/
theorem x86_rep_movs_copies_at_most_bound (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).elements ≤ 64 := by
  show min x86RepMovsBoundSpec imm.toNat ≤ 64
  exact Nat.min_le_left _ _

/-- Each pointer advances by the raw immediate times the `FLAGS`-resolved copy
width's stride — the same width the bytes are copied at. -/
theorem x86_rep_movs_advance_uses_flags_width (flags : Code)
    (imm src dst : BitVec 64) (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).srcAdvance =
        src + BitVec.ofNat 64
          (imm.toNat * x86RepMovsStrideSpec (x86RepMovsWidthSpec flags)) ∧
      (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).dstAdvance =
        dst + BitVec.ofNat 64
          (imm.toNat * x86RepMovsStrideSpec (x86RepMovsWidthSpec flags)) := by
  exact ⟨rfl, rfl⟩

/-- `RCX` is zeroed and scalarized at the fixed 64-bit width, whatever the
`FLAGS`-resolved copy width was: `countWidth` does not track `flags`. -/
theorem x86_rep_movs_step_rcx_zeroed (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).rcx.bits = 0 ∧
      (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).rcx.tag =
        .scalar ∧
      (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).countWidth =
        .w64 := by
  cases old
  refine ⟨?_, ?_, rfl⟩ <;>
    simp [x86RepMovsStepSpec, x86RepMovsRcxSpec, x86RegWriteSpec,
      x86RegWriteBitsSpec]

/-- Neither pointer's provenance tag changes: the body rewrites `RSI` and `RDI`
with the tags it read from them. -/
theorem x86_rep_movs_tags_preserved (flags : Code) (imm src dst : BitVec 64)
    (srcTagIn dstTagIn : Tag) (old : X86RegValue) :
    (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).srcTag =
        srcTagIn ∧
      (x86RepMovsStepSpec flags imm src dst srcTagIn dstTagIn old).dstTag =
        dstTagIn := by
  exact ⟨rfl, rfl⟩

/-- Canonical example: an absent `FLAGS` code copies at 64-bit width, three
elements advance each pointer by three eight-byte strides, and `RCX` is zeroed. -/
theorem x86_rep_movs_example :
    (x86RepMovsStepSpec .absent 3 0x100 0x200 .abi .packet
      ⟨0xdead, .scalar⟩).width = .w64 ∧
    (x86RepMovsStepSpec .absent 3 0x100 0x200 .abi .packet
      ⟨0xdead, .scalar⟩).elements = 3 ∧
    (x86RepMovsStepSpec .absent 3 0x100 0x200 .abi .packet
      ⟨0xdead, .scalar⟩).stride = 8 ∧
    (x86RepMovsStepSpec .absent 3 0x100 0x200 .abi .packet
      ⟨0xdead, .scalar⟩).srcAdvance = 0x100 + BitVec.ofNat 64 24 ∧
    (x86RepMovsStepSpec .absent 3 0x100 0x200 .abi .packet
      ⟨0xdead, .scalar⟩).rcx.bits = 0 := by
  simp only [x86RepMovsStepSpec, x86RepMovsWidthSpec,
    x86RepMovsElementCountSpec, x86RepMovsBoundSpec, x86RepMovsStrideSpec,
    x86WidthBitsSpec, x86RepMovsAdvanceSpec, x86RepMovsRcxSpec,
    x86RegWriteSpec, x86RegWriteBitsSpec]
  decide

/-- Canonical example: a narrow 8-bit `FLAGS` code copies at 8-bit width, so a
count of three advances each pointer by three single bytes, while `RCX` is still
zeroed at the fixed 64-bit width. -/
theorem x86_rep_movs_narrow_example :
    (x86RepMovsStepSpec .b8 3 0x100 0x200 .scalar .scalar
      ⟨0, .scalar⟩).width = .w8 ∧
    (x86RepMovsStepSpec .b8 3 0x100 0x200 .scalar .scalar
      ⟨0, .scalar⟩).stride = 1 ∧
    (x86RepMovsStepSpec .b8 3 0x100 0x200 .scalar .scalar
      ⟨0, .scalar⟩).srcAdvance = 0x100 + BitVec.ofNat 64 3 ∧
    (x86RepMovsStepSpec .b8 3 0x100 0x200 .scalar .scalar
      ⟨0, .scalar⟩).countWidth = .w64 := by
  simp only [x86RepMovsStepSpec, x86RepMovsWidthSpec,
    x86RepMovsElementCountSpec, x86RepMovsBoundSpec, x86RepMovsStrideSpec,
    x86WidthBitsSpec, x86RepMovsAdvanceSpec, x86RepMovsCountWidthSpec]
  decide

/-- Canonical example: the element count saturates at the literal bound while the
advance keeps the raw count — a hundred-element request copies sixty-four
elements but advances a hundred. -/
theorem x86_rep_movs_saturation_example :
    x86RepMovsElementCountSpec 100 = 64 ∧ x86RepMovsElementCountSpec 64 = 64 ∧
      x86RepMovsElementCountSpec 63 = 63 ∧ x86RepMovsElementCountSpec 0 = 0 := by
  decide

end KProgFormal
