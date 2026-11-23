import KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64VectorWritable

open Arm64Producer

/-- The actual512-byte vector local's original writable range, in a reached heap. -/
def Writable {initial : CC.Mem} (vectors : VectorLocal initial) (memory : CC.Mem) : Prop :=
  CC.Mem.rangePerm memory vectors.block 0 512 .Cur .Writable = true

/-- Typed producer allocation supplies the original permission certificate. -/
theorem allocated (initial : CC.Mem) (vectors : VectorLocal initial) :
    Writable vectors (allocation initial).2 := vectors.range

/-- Real stores preserve permissions of the vector allocation, including
stores to its own data bytes. -/
theorem store {initial before after : CC.Mem} (vectors : VectorLocal initial)
    (writable : Writable vectors before) (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (value : CC.Val)
    (written : CC.Mem.store chunk before block offset value = some after) : Writable vectors after :=
  CC.Mem.rangePerm_store written vectors.block 0 512 .Cur .Writable writable

/-- Actual owned frame preservation carries vector permissions across
callee allocations/frees and provider frames at the original frontier. -/
theorem frame {initial before after : CC.Mem} (vectors : VectorLocal initial)
    (writable : Writable vectors before) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (kept : FrameBelow frontier before after) : Writable vectors after := by
  have owned := Nat.lt_of_lt_of_le (Arm64RegisterStorageFrontier.local_owned initial _ _ _ vectors.binding) bound
  exact (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (b := vectors.block) (lo := 0) (hi := 512) (k := .Cur) (p := .Writable)
    (fun offset => by simp only [CC.Mem.perm,(kept _ owned).2])).trans writable

private theorem half_bounds : ∀ (high : Bool) (i : Fin 32),
    (0 : Int) ≤ 16 * (i.val : Int) + (if high then 8 else 0) ∧
      16 * (i.val : Int) + (if high then 8 else 0) + 8 ≤ 512 := by decide +kernel
private theorem half_align : ∀ (high : Bool) (i : Fin 32),
    (16 * (i.val : Int) + (if high then 8 else 0)) % CC.alignChunk .Mint64 = 0 := by decide +kernel

/-- All64 actual vector halves have writable, aligned8-byte C access,
derived from the real allocation range rather than a successful store premise. -/
theorem half {initial memory : CC.Mem} (vectors : VectorLocal initial)
    (writable : Writable vectors memory) (high : Bool) (i : Fin 32) :
    CC.Mem.validAccess memory .Mint64 vectors.block
      (16 * (i.val : Int) + (if high then 8 else 0)) .Writable = true := by
  have range : CC.Mem.rangePerm memory vectors.block
      (16 * (i.val : Int) + (if high then 8 else 0))
      (16 * (i.val : Int) + (if high then 8 else 0) + 8) .Cur .Writable = true := by
    apply CC.Mem.rangePerm_intro
    intro offset low highBound
    exact CC.Mem.rangePerm_perm memory vectors.block 0 512 .Cur .Writable writable offset
      (Int.le_trans (half_bounds high i).1 low) (Int.lt_of_lt_of_le highBound (half_bounds high i).2)
  simp only [CC.Mem.validAccess,show CC.sizeChunk .Mint64 = (8 : Int) from rfl,range,half_align high i]
  rfl

/-- The concrete low/high pointers in Storage use these same actual offsets. -/
theorem half_pointer {initial memory : CC.Mem} (vectors : VectorLocal initial)
    (writable : Writable vectors memory) (high : Bool) (i : Fin 32) :
    CC.Mem.validAccess memory .Mint64 vectors.block
      (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset high i)) .Writable = true := by
  simpa only [(vector_loop_offsets high i).2] using half vectors writable high i

end KProgFormal.ClightRefinement.Arm64VectorWritable
