import KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPRMemory
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerGPRSource (declaration stage continuation inputIndex)

/-- The actual caller world must satisfy this partial layout check;no old
whole environment or allocator correspondence is assumed. -/
theorem layout : Arm64Producer.GprLayout ge := by
  unfold Arm64Producer.GprLayout
  decide +kernel

structure Stores (m supplied : CC.Mem) (i : Fin 31) (value : BitVec 64) where
  wordBlock : CC.Block
  tagBlock : CC.Block
  middle : CC.Mem
  after : CC.Mem
  wordBinding : (allocation m).1.get (declaration i).word =
    some (wordBlock,.Tunion Arm64Entry._arm64_sim_gpr CC.noattr)
  tagBinding : (allocation m).1.get (declaration i).tag = some (tagBlock,CC.tuchar)
  storedWord : CC.Mem.storev .Mint64 supplied (.Vptr wordBlock (0#64)) (.Vlong value) = some middle
  storedTag : CC.Mem.storev .Mint8unsigned middle (.Vptr tagBlock (0#64)) (.Vint (0#32)) = some after
  wordRead : CC.Mem.load .Mint64 after wordBlock 0 = some (.Vlong value)
  tagRead : CC.Mem.load .Mint8unsigned after tagBlock 0 = some (.Vint (0#32))
  otherLocals : ∀ id ty b,(allocation m).1.get id = some (b,ty) →
    id ≠ (declaration i).word → id ≠ (declaration i).tag → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

private theorem writable {m current : CC.Mem} (id : CC.Ident) (ty : CC.Ty) (b : CC.Block)
    (binding : (allocation m).1.get id = some (b,ty)) (c : CC.Chunk)
    (size : CC.sizeof ge.genv_cenv ty = CC.sizeChunk c)
    (align : (0 % CC.alignChunk c == 0) = true)
    (access : current.access = (allocation m).2.access) :
    CC.Mem.validAccess current c b 0 .Writable = true := by
  have owned := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding).2.2
  rw [size] at owned
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,align⟩
  apply CC.Mem.rangePerm_intro
  intro o lower upper
  have permission := CC.Mem.perm_implies
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned o lower (by simpa only [Int.zero_add] using upper))
    (by decide : CC.permOrder .Freeable .Writable = true)
  simpa only [CC.Mem.perm,access] using permission

/-- Successful stores come from SAME795-local allocated cells/current rights.
The source declarations are bound to these cells by their checked real names. -/
theorem stores {m supplied : CC.Mem} (i : Fin 31) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (Stores m supplied i value) := by
  obtain ⟨words⟩ := Arm64CiliumCallerInitializers.cells_storage false m
  obtain ⟨tags⟩ := Arm64CiliumCallerInitializers.cells_storage true m
  have wb : (allocation m).1.get (declaration i).word =
      some (words.block i,.Tunion Arm64Entry._arm64_sim_gpr CC.noattr) := by
    rw [(Arm64CiliumCallerGPRSource.cell_names i).1]
    exact words.binding i
  have tb : (allocation m).1.get (declaration i).tag = some (tags.block i,CC.tuchar) := by
    rw [(Arm64CiliumCallerGPRSource.cell_names i).2]
    exact tags.binding i
  have wordWritable := writable (declaration i).word _ (words.block i) wb .Mint64 (by rfl) (by decide) access
  obtain ⟨middle,wordStore⟩ : ∃ middle,
      CC.Mem.store .Mint64 supplied (words.block i) 0 (.Vlong value) = some middle := by
    simp only [CC.Mem.store,wordWritable,ite_true]
    exact ⟨_,rfl⟩
  have middleAccess := (CC.Mem.store_access wordStore).trans access
  have tagWritable := writable (declaration i).tag _ (tags.block i) tb .Mint8unsigned rfl (by decide) middleAccess
  obtain ⟨after,tagStore⟩ : ∃ after,
      CC.Mem.store .Mint8unsigned middle (tags.block i) 0 (.Vint (0#32)) = some after := by
    simp only [CC.Mem.store,tagWritable,ite_true]
    exact ⟨_,rfl⟩
  have names : (declaration i).word ≠ (declaration i).tag := by
    have all : ∀ i : Fin 31,(declaration i).word ≠ (declaration i).tag := by decide +kernel
    exact all i
  have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ wb tb names
  have wordFresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ wb).1
  have tagFresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ tb).1
  refine ⟨⟨words.block i,tags.block i,middle,after,wb,tb,wordStore,tagStore,
    (CC.Mem.load_store_other tagStore .Mint64 (words.block i) 0 (.inl separate)).trans
      (CC.Mem.load_store_same wordStore),CC.Mem.load_store_same tagStore,?_,
    (FrameBelow.store wordFresh wordStore).trans (FrameBelow.store tagFresh tagStore),
    (CC.Mem.store_access tagStore).trans (CC.Mem.store_access wordStore),
    (CC.Mem.store_nextblock tagStore).trans (CC.Mem.store_nextblock wordStore)⟩⟩
  intro id ty b binding notWord notTag c o
  have wordDifferent := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding wb notWord
  have tagDifferent := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding tb notTag
  exact (CC.Mem.load_store_other tagStore c b o (.inl tagDifferent)).trans
    (CC.Mem.load_store_other wordStore c b o (.inl wordDifferent))

theorem writeback {m supplied : CC.Mem} (i : Fin 31) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Stores m supplied i value,
      InternalRun ge 9 (.Returnstate (.Vlong value) (continuation (m := m) i le k) supplied)
        (.State procedure (declaration i).rest k (allocation m).1
          ((declaration i).temps le value) writes.after) := by
  obtain ⟨writes⟩ := stores i value access
  have run := Arm64Producer.declaration_return_body_stored ge procedure (allocation m).1 layout
    (declaration i) supplied writes.middle writes.after le k value writes.wordBlock writes.tagBlock
    writes.storedWord writes.storedTag writes.wordBinding writes.tagBinding
  exact ⟨writes,internalRun_of_steps run.2 run.1⟩

theorem literal_zero {m before : CC.Mem} (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Stores m before 30 (0#64),
      InternalRun ge 10 (.State procedure (stage 30) k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerGPRSource.after k (allocation m).1
          (le.set (declaration 30).resultTemp (.Vlong (0#64))) writes.after) := by
  obtain ⟨writes⟩ := stores (m := m) (supplied := before) 30 (0#64) access
  have same : CC.Integers.Int.eq (declaration 30).index (30#32) = true := by
    rw [Arm64CiliumCallerGPRSource.branches]
    rfl
  have run := Arm64Producer.declaration_zero_body_stored ge procedure (allocation m).1 layout
    (declaration 30) before writes.middle writes.after le k same writes.wordBlock writes.tagBlock
    writes.storedWord writes.storedTag writes.wordBinding writes.tagBinding
  refine ⟨writes,?_⟩
  rw [Arm64CiliumCallerGPRSource.source]
  exact internalRun_of_steps run.2 run.1

theorem input_returns {m before supplied : CC.Mem} (i : Fin 30) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Stores m supplied (inputIndex i) value,
      CC.Star (CC.Step2 ge)
        (.State procedure (stage (inputIndex i)) k (allocation m).1 le before)
        trace (.State procedure (declaration (inputIndex i)).rest k (allocation m).1
          ((declaration (inputIndex i)).temps le value) writes.after) := by
  obtain ⟨writes,suffix⟩ := writeback (inputIndex i) value access le k
  have externalStep : CC.Star (CC.Step2 ge)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (m := m) (inputIndex i) le k) before)
      trace (.Returnstate (.Vlong value) (continuation (m := m) (inputIndex i) le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0,CC.Eapp])
  refine ⟨writes,?_⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (Arm64CiliumCallerGPRSource.call_ready i le k).sound (star_trans externalStep suffix.sound)

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPRMemory
