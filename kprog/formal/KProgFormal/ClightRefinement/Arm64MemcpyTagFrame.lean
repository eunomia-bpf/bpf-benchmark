import KProgFormal.ClightRefinement.Arm64MemcpyTagWrite
import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTagFrame

private theorem set_existing {A : Type} (i : CC.Positive) (tree : CC.PTree A) (value : A)
    (read : tree.get i = some value) : tree.set i value = tree := by
  induction i generalizing tree with
  | xH =>
    cases tree with
    | Leaf => simp only [CC.PTree.get] at read; cases read
    | Node left old right =>
      change old = some value at read
      simp only [CC.PTree.set,read]
  | xO i ih =>
    cases tree with
    | Leaf => simp only [CC.PTree.get] at read; cases read
    | Node left old right =>
      change CC.PTree.Node (left.set i value) old right = _
      rw [ih left read]
  | xI i ih =>
    cases tree with
    | Leaf => simp only [CC.PTree.get] at read; cases read
    | Node left old right =>
      change CC.PTree.Node left old (right.set i value) = _
      rw [ih right read]

private theorem set_zero (cells : CC.ZMap CC.MemVal) (ofs : Int)
    (default : cells.dflt = .Undef) (read : CC.ZMap.get ofs cells = .Byte 0) :
    CC.ZMap.set ofs (.Byte 0) cells = cells := by
  have present : cells.tree.get (CC.ZIndexed.index ofs) = some (.Byte 0) := by
    cases actual : cells.tree.get (CC.ZIndexed.index ofs) with
    | none => simp only [CC.ZMap.get,CC.PMap.get,actual,Option.getD_none,default] at read; cases read
    | some value =>
      have same : value = .Byte 0 := by
        simpa only [CC.ZMap.get,CC.PMap.get,actual,Option.getD_some] using read
      exact congrArg some same
  change CC.PMap.mk cells.dflt (cells.tree.set (CC.ZIndexed.index ofs) (.Byte 0)) = cells
  rw [set_existing _ _ _ present]

private theorem set_zeros (n : Nat) (start : Int) (cells : CC.ZMap CC.MemVal)
    (default : cells.dflt = .Undef)
    (zero : ∀ j : Nat, j < n → CC.ZMap.get (start+(j : Int)) cells = .Byte 0) :
    CC.Mem.setN (List.replicate n (.Byte 0)) start cells = cells := by
  induction n generalizing start with
  | zero => rfl
  | succ n ih =>
    have first : CC.ZMap.get start cells = .Byte 0 := by simpa only [Int.ofNat_zero,Int.add_zero] using zero 0 (by omega)
    change CC.Mem.setN (List.replicate n (.Byte 0)) (start+1) (CC.ZMap.set start (.Byte 0) cells) = cells
    rw [set_zero cells start default first]
    apply ih (start+1)
    intro j limit
    have later := zero (j+1) (by omega)
    have address : start+((j+1 : Nat) : Int) = (start+1)+(j : Int) := by omega
    rw [address] at later
    exact later

private theorem encoding : CC.encodeVal .Mint64 (.Vlong 0) = List.replicate 8 (.Byte 0) := by decide +kernel

/-- The genuine zero-word store writes exactly the eight existing raw
zero bytes. It therefore retains every older block's complete contents and
permissions, including all caller and current producer observations. -/
theorem word_store {before after : CC.Mem} {tags : CC.Block}
    (stored : CC.Mem.store .Mint64 before tags 8 (.Vlong 0) = some after)
    (zero : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before tags (j.val : Int) = some (.Vint 0))
    (frontier : CC.Block) : FrameBelow frontier before after := by
  have bytes : ∀ j : Nat, j < 8 → CC.ZMap.get (8+(j : Int)) (CC.PMap.get tags before.contents) = .Byte 0 := by
    intro j limit
    let which : Fin 24 := ⟨8+j,by omega⟩
    have actual := (Arm64MemsetTagWords.byte_zero before tags (which.val : Int) (zero which)).2
    exact actual
  have unchanged := set_zeros 8 8 (CC.PMap.get tags before.contents) (before.contents_default tags) bytes
  intro block _old
  rw [CC.Mem.store_contents stored,CC.Mem.store_access stored]
  by_cases same : tags = block
  · subst block
    rw [CC.PMap.gss,encoding,unchanged]
    exact ⟨rfl,rfl⟩
  · exact ⟨CC.PMap.gso _ _ _ _ same,rfl⟩

/-- The same current iteration survives its real tag-word effect with all
eight memcpy local ranges and copied-byte progress intact. -/
def current {initial seed calleeBefore before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv} {n : Nat}
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (stored : CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some after) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after le :=
  Arm64MemcpyReadFrame.transport before.nextblock producerBound callerBound
    (word_store stored prior.packet.tagBytes before.nextblock) prior

end KProgFormal.ClightRefinement.Arm64MemcpyTagFrame
