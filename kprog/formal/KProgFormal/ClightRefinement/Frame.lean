import KProgFormal.ClightRefinement.Execution
import CCLib.MemoryLemmas

namespace KProgFormal.ClightRefinement

/-- Exact raw contents and both permission maps below a block frontier.
The frontier itself may advance when C allocates a function frame. -/
def FrameBelow (frontier : CC.Block) (before after : CC.Mem) : Prop :=
  ∀ b, b.toNat < frontier.toNat →
    CC.PMap.get b after.contents = CC.PMap.get b before.contents ∧
    CC.PMap.get b after.access = CC.PMap.get b before.access

namespace FrameBelow

theorem refl (frontier : CC.Block) (m : CC.Mem) : FrameBelow frontier m m :=
  fun _ _ => ⟨rfl, rfl⟩

theorem trans {frontier : CC.Block} {a b c : CC.Mem}
    (hab : FrameBelow frontier a b) (hbc : FrameBelow frontier b c) :
    FrameBelow frontier a c := by
  intro blk hblk
  exact ⟨(hbc blk hblk).1.trans (hab blk hblk).1,
    (hbc blk hblk).2.trans (hab blk hblk).2⟩

/-- Allocation preserves every byte (including undefined bytes) and Cur/Max
permission at every old offset, rather than merely preserving successful loads. -/
theorem alloc (frontier : CC.Block) (m : CC.Mem) (lo hi : CC.Z)
    (hnext : frontier.toNat ≤ m.nextblock.toNat) :
    FrameBelow frontier m (CC.Mem.alloc m lo hi).1 := by
  intro b hb
  have hne : m.nextblock ≠ b := by intro heq; rw [heq] at hnext; omega
  simp only [CC.Mem.alloc_contents, CC.Mem.alloc_access,
    CC.PMap.gso _ _ _ _ hne, and_self]

/-- Freeing a new frame block preserves the complete old-block view. -/
theorem free {frontier : CC.Block} {m after : CC.Mem} {b : CC.Block} {lo hi : CC.Z}
    (fresh : frontier.toNat ≤ b.toNat) (hfree : CC.Mem.free m b lo hi = some after) :
    FrameBelow frontier m after := by
  rw [CC.Mem.free_result hfree]
  intro old hold
  have hne : b ≠ old := by intro heq; rw [heq] at fresh; omega
  exact ⟨rfl, CC.PMap.gso _ _ _ _ hne⟩

/-- The existing allocator advances nextblock and frames all prior blocks.
No assumptions on the local-variable names, sizes, or caller bytes are needed. -/
theorem allocVariables {ce : CC.CompositeEnv} {e e' : CC.Env} {m m' : CC.Mem}
    {vars : List (CC.Ident × CC.Ty)}
    (h : CC.AllocVariables ce e m vars e' m') (frontier : CC.Block)
    (hnext : frontier.toNat ≤ m.nextblock.toNat) :
    frontier.toNat ≤ m'.nextblock.toNat ∧ FrameBelow frontier m m' := by
  induction h with
  | nil e m => exact ⟨hnext, refl frontier m⟩
  | cons e m id ty vars m1 b1 m2 e2 ha _ ih =>
    cases ha
    have hnext' : frontier.toNat ≤ (CC.Mem.alloc m 0 (CC.sizeof ce ty)).1.nextblock.toNat := by
      simp only [CC.Mem.alloc_nextblock, CC.Positive.toNat_succ]
      omega
    obtain ⟨hn, hf⟩ := ih hnext'
    exact ⟨hn, trans (alloc frontier m _ _ hnext) hf⟩

/-- A successful free-list of new blocks leaves the entire prior frame exact.
Success is explicit: this lemma does not turn a refused free into a no-op. -/
theorem freeList {frontier : CC.Block} {m m' : CC.Mem}
    {blocks : List (CC.Block × CC.Z × CC.Z)}
    (fresh : ∀ p ∈ blocks, frontier.toNat ≤ p.1.toNat)
    (h : CC.Mem.freeList m blocks = some m') : FrameBelow frontier m m' := by
  induction blocks generalizing m with
  | nil =>
    simp only [CC.Mem.freeList, Option.some.injEq] at h
    subst m'
    exact refl frontier m
  | cons p ps ih =>
    rcases p with ⟨b, lo, hi⟩
    cases hfree : CC.Mem.free m b lo hi with
    | none => simp [CC.Mem.freeList, hfree] at h
    | some mid =>
      simp only [CC.Mem.freeList, hfree] at h
      exact trans (free (fresh (b, lo, hi) (by simp)) hfree)
        (ih (fun p hp => fresh p (by simp [hp])) h)

/-- The raw frame entails equality of every typed load at every old offset,
including refused loads and loads decoding to undefined values. -/
theorem load {frontier : CC.Block} {m m' : CC.Mem} (h : FrameBelow frontier m m')
    (chunk : CC.Chunk) (b : CC.Block) (ofs : CC.Z) (hb : b.toNat < frontier.toNat) :
    CC.Mem.load chunk m' b ofs = CC.Mem.load chunk m b ofs := by
  have ha : ∀ o, CC.Mem.perm m' b o .Cur .Readable = CC.Mem.perm m b o .Cur .Readable := by
    intro o
    simp only [CC.Mem.perm, (h b hb).2]
  unfold CC.Mem.load
  rw [CC.Mem.validAccess_congr ha, (h b hb).1]

end FrameBelow

end KProgFormal.ClightRefinement
