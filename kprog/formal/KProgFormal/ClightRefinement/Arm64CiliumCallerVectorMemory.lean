import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorMemory
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerVectorSource (Storage vectorTag stage temporary rest continuation)
open Arm64CiliumCallerGPRFrames (localRead)

structure Store {m : CC.Mem} (storage : Storage m) (supplied : CC.Mem)
    (i : Fin 64) (value : BitVec 64) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 supplied storage.block (8*(i.val : Int)) (.Vlong value) = some after
  read : CC.Mem.load .Mint64 after storage.block (8*(i.val : Int)) = some (.Vlong value)
  otherFields : ∀ j : Fin 64,j ≠ i →
    CC.Mem.load .Mint64 after storage.block (8*(j.val : Int)) =
      CC.Mem.load .Mint64 supplied storage.block (8*(j.val : Int))
  otherBlocks : ∀ b,b ≠ storage.block → ∀ c o,
    CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Actual512-byte allocation/current rights derive the real store at each
original lo/hi offset;all other vector lanes and blocks retain their loads. -/
theorem store {m supplied : CC.Mem} (storage : Storage m) (i : Fin 64) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (Store storage supplied i value) := by
  have valid : CC.Mem.validAccess supplied .Mint64 storage.block (8*(i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ o := by omega
      have hi : o < (512 : Int) := by
        change o < 8*(i.val : Int)+8 at upper
        omega
      have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _ storage.range o lo hi
      simpa only [CC.Mem.perm,access] using permission
    · change ((8*(i.val : Int)) % 8 == 0) = true
      have aligned : (8*(i.val : Int)) % 8 = 0 := by omega
      simp only [aligned,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 supplied storage.block
      (8*(i.val : Int)) (.Vlong value) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  refine ⟨⟨after,stored,CC.Mem.load_store_same stored,?_,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store storage.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  intro j different
  have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
  have separate : 8*(j.val : Int)+8 ≤ 8*(i.val : Int) ∨
      8*(i.val : Int)+8 ≤ 8*(j.val : Int) := by omega
  exact CC.Mem.load_store_other stored .Mint64 storage.block (8*(j.val : Int)) (.inr separate)

/-- SAME mature four-step return/store body,actual anonymous layout and
actual caller binding;no old producer VectorLocal/allocator is reconstructed. -/
theorem writeback {m supplied : CC.Mem} (storage : Storage m) (i : Fin 64) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Store storage supplied i value,
      InternalRun ge 4 (.Returnstate (.Vlong value) (continuation (m := m) i le k) supplied)
        (.State procedure (rest i) k (allocation m).1
          (le.set (temporary i) (.Vlong value)) writes.after) := by
  obtain ⟨writes⟩ := store storage i value access
  obtain ⟨shape⟩ := Arm64CiliumCallerVectorSource.layout
  have storedv : CC.Mem.storev .Mint64 supplied
      (.Vptr storage.block (Arm64Producer.vectorPointerOffset i)) (.Vlong value) = some writes.after := by
    simpa only [CC.Mem.storev,Arm64Producer.vector_offsets] using writes.stored
  have run := Arm64Producer.vector_return_body_stored ge procedure (allocation m).1
    vectorTag (temporary i) i (rest i) supplied writes.after storage.block shape
    storage.binding le k value storedv
  exact ⟨writes,run⟩

/-- One actual call/explicit external outcome/SAME genuine vector store;
the provider's real trace and supplied heap are carried without substitution. -/
theorem input_returns {m before supplied : CC.Mem} (storage : Storage m)
    (i : Fin 64) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Store storage supplied i value,
      CC.Star (CC.Step2 ge) (.State procedure (stage i) k (allocation m).1 le before)
        trace (.State procedure (rest i) k (allocation m).1
          (le.set (temporary i) (.Vlong value)) writes.after) := by
  obtain ⟨writes,suffix⟩ := writeback storage i value access le k
  have externalStep : CC.Star (CC.Step2 ge)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (continuation (m := m) i le k) before)
      trace (.Returnstate (.Vlong value) (continuation (m := m) i le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0,CC.Eapp])
  refine ⟨writes,?_⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (Arm64CiliumCallerVectorSource.call_ready i le k).sound (star_trans externalStep suffix.sound)

/-- Actual allocated names turn the real other-block frame into local reads. -/
theorem named_frame {m supplied : CC.Mem} {storage : Storage m} {i : Fin 64} {v : BitVec 64}
    (writes : Store storage supplied i v) (id : CC.Ident) (different : id ≠ Arm64Entry.___a64_vectors)
    (c : CC.Chunk) (o : Int) :
    localRead m writes.after id c o = localRead m supplied id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding storage.binding different
    simpa only [localRead,binding,Option.bind_some] using writes.otherBlocks cell.1 separate c o

theorem stored_read {m supplied : CC.Mem} {storage : Storage m} {i : Fin 64} {v : BitVec 64}
    (writes : Store storage supplied i v) :
    localRead m writes.after Arm64Entry.___a64_vectors .Mint64 (8*(i.val : Int)) = some (.Vlong v) := by
  simpa only [localRead,storage.binding,Option.bind_some] using writes.read

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorMemory
