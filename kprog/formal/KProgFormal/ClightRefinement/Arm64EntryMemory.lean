import KProgFormal.Clight.Arm64Program
import KProgFormal.ClightRefinement.Frame

namespace KProgFormal.ClightRefinement.Arm64EntryMemory

/-- The actual exported composite environment, including the borrowed entry
and union layouts. No separate dense register-bank layout is introduced. -/
def composites : CC.CompositeEnv := Arm64Program.prog.globalenv.genv_cenv

/-- Address a full field using the imported C layout algorithm. Missing
composites/fields and bitfields are refused rather than assigned an offset. -/
def fieldAddress (entry : CC.Val) (field : CC.Ident) : Option CC.Val := do
  let co ← composites.get Arm64Program._kprog_arm64_entry
  match CC.fieldOffset composites field co.co_members with
  | .OK (offset, .Full) =>
    pure (CC.Val.offsetPtr entry (CC.Integers.Ptrofs.repr offset))
  | _ => none

/-- Checked observation of caller-owned storage. A successful observation
requires every traversed block to precede the fixed caller frontier. Crossing
it, a nonpointer address, or a refused load fails the entire query. Undefined
values and pointer fragments retain the imported load semantics. -/
def load (frontier : CC.Block) (chunk : CC.Chunk) (m : CC.Mem)
    (address : CC.Val) : Option CC.Val :=
  match address with
  | .Vptr block offset =>
    if block.toNat < frontier.toNat then
      CC.Mem.load chunk m block (CC.Integers.Ptrofs.unsigned offset)
    else none
  | _ => none

def field (frontier : CC.Block) (chunk : CC.Chunk) (m : CC.Mem)
    (entry : CC.Val) (name : CC.Ident) : Option CC.Val := do
  let address ← fieldAddress entry name
  load frontier chunk m address

/-- Read through an actual entry pointer, such as n/z/c/v, sp, or lr. -/
def borrowed (frontier : CC.Block) (chunk : CC.Chunk) (m : CC.Mem)
    (entry : CC.Val) (name : CC.Ident) : Option CC.Val := do
  let pointer ← field frontier CC.Mptr m entry name
  load frontier chunk m pointer

private def pointerSlot (base : CC.Val) (index : Nat) : CC.Val :=
  CC.Val.offsetPtr base (CC.Integers.Ptrofs.repr
    (CC.sizeof composites (CC.tptr CC.tvoid) * index))

/-- Follow both real pointer tables to an individual union cell and its tag.
The index is a storage-cell index; relating a producer's compact cell map to
an architectural register remains a separate source-admissibility obligation.
Mint64 retains either the union's integer or pointer value, including undef. -/
def gpr (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (cellIndex : Nat) : Option (CC.Val × CC.Val) := do
  let cells ← field frontier CC.Mptr m entry Arm64Program._cells
  let cell ← load frontier CC.Mptr m (pointerSlot cells cellIndex)
  let tags ← field frontier CC.Mptr m entry Arm64Program._tag_cells
  let tag ← load frontier CC.Mptr m (pointerSlot tags cellIndex)
  let value ← load frontier .Mint64 m cell
  let kind ← load frontier .Mint8unsigned m tag
  pure (value, kind)

/-- The vector pointer arrays are embedded in the entry, unlike cells and
tag_cells. Each half points to a separately supplied producer location. -/
def vector (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (index : Fin 32) : Option (CC.Val × CC.Val) := do
  let loArray ← fieldAddress entry Arm64Program._vector_lo
  let hiArray ← fieldAddress entry Arm64Program._vector_hi
  let loPointer ← load frontier CC.Mptr m (pointerSlot loArray index.val)
  let hiPointer ← load frontier CC.Mptr m (pointerSlot hiArray index.val)
  let lo ← load frontier .Mint64 m loPointer
  let hi ← load frontier .Mint64 m hiPointer
  pure (lo, hi)

def flags (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val) :
    Option (CC.Val × CC.Val × CC.Val × CC.Val) := do
  let n ← borrowed frontier .Mint8unsigned m entry Arm64Program._n
  let z ← borrowed frontier .Mint8unsigned m entry Arm64Program._z
  let c ← borrowed frontier .Mint8unsigned m entry Arm64Program._c
  let v ← borrowed frontier .Mint8unsigned m entry Arm64Program._v
  pure (n, z, c, v)

/-- Kernel-check the layout used by these readers against the actual export.
The implementation computes offsets from Ctypes; these numbers are witnesses,
not an alternate field-layout implementation. -/
theorem entry_offsets :
    ([Arm64Program._cells, Arm64Program._tag_cells,
      Arm64Program._n, Arm64Program._z, Arm64Program._c, Arm64Program._v,
      Arm64Program._vector_lo, Arm64Program._vector_hi].map
        (fieldAddress (.Vptr (CC.Positive.ofNat 1) 0))) =
    ([0, 8, 64, 72, 80, 88, 96, 352].map (fun offset =>
      some (.Vptr (CC.Positive.ofNat 1) (CC.Integers.Ptrofs.repr offset)))) := by
  decide +kernel

/-- An offset match alone is insufficient: these fields must retain their
actual pointer/table types for the readers above to describe the C accesses. -/
theorem entry_types :
    ((composites.get Arm64Program._kprog_arm64_entry).map (fun co =>
      [Arm64Program._cells, Arm64Program._tag_cells,
       Arm64Program._n, Arm64Program._z, Arm64Program._c, Arm64Program._v,
       Arm64Program._vector_lo, Arm64Program._vector_hi].map
        (fun name => CC.fieldType name co.co_members))) = some
    [.OK (CC.tptr (CC.tptr (.Tunion Arm64Program._arm64_sim_gpr CC.noattr))),
     .OK (CC.tptr (CC.tptr CC.tuchar)),
     .OK (CC.tptr CC.tuchar), .OK (CC.tptr CC.tuchar),
     .OK (CC.tptr CC.tuchar), .OK (CC.tptr CC.tuchar),
     .OK (CC.tarray (CC.tptr CC.tulong) 32),
     .OK (CC.tarray (CC.tptr CC.tulong) 32)] := by
  decide +kernel

/-- The union's x member begins at its cell address, and table elements use
the exported ABI's pointer size. This does not identify pointers with integers. -/
theorem cell_layout :
    ((composites.get Arm64Program._arm64_sim_gpr).map (fun co =>
      CC.unionFieldOffset composites Arm64Program._x co.co_members)) =
      some (.OK (0, .Full)) ∧
    CC.sizeof composites (CC.tptr CC.tvoid) = 8 := by
  decide +kernel

/-- Stability includes failure and undef, without synthesizing a scalar or
discarding a pointer tag when an observation cannot be decoded. -/
theorem load_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (chunk : CC.Chunk) (address : CC.Val) :
    load frontier chunk after address = load frontier chunk before address := by
  cases address <;> simp only [load]
  rename_i block offset
  split
  next hb => exact FrameBelow.load h chunk block _ hb
  next => rfl

theorem field_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (chunk : CC.Chunk)
    (entry : CC.Val) (name : CC.Ident) :
    field frontier chunk after entry name = field frontier chunk before entry name := by
  simp only [field, load_frame h]

theorem borrowed_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (chunk : CC.Chunk)
    (entry : CC.Val) (name : CC.Ident) :
    borrowed frontier chunk after entry name = borrowed frontier chunk before entry name := by
  simp only [borrowed, field_frame h, load_frame h]

theorem gpr_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (entry : CC.Val) (cellIndex : Nat) :
    gpr frontier after entry cellIndex = gpr frontier before entry cellIndex := by
  simp only [gpr, field_frame h, load_frame h]

theorem vector_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (entry : CC.Val) (index : Fin 32) :
    vector frontier after entry index = vector frontier before entry index := by
  simp only [vector, load_frame h]

theorem flags_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (entry : CC.Val) :
    flags frontier after entry = flags frontier before entry := by
  simp only [flags, borrowed_frame h]

end KProgFormal.ClightRefinement.Arm64EntryMemory
