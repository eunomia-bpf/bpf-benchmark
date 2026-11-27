import KProgFormal.ClightRefinement.Arm64CiliumCallerGPRMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPRFrames
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerGPRSource (declaration stage continuation inputIndex)

noncomputable def localRead (m heap : CC.Mem) (id : CC.Ident) (chunk : CC.Chunk) (offset : Int) : Option CC.Val :=
  ((allocation m).1.get id).bind fun cell => CC.Mem.load chunk heap cell.1 offset

def LocalFrame (m before after : CC.Mem) : Prop :=
  ∀ id chunk offset, localRead m after id chunk offset = localRead m before id chunk offset

def value (inputs : Fin 30 → BitVec 64) (i : Fin 31) : BitVec 64 :=
  if h : i.val < 30 then inputs ⟨i.val,h⟩ else 0#64

structure Initialized (m heap : CC.Mem) (inputs : Fin 30 → BitVec 64) (count : Nat) : Prop where
  word : ∀ i : Fin 31,i.val < count →
    localRead m heap (declaration i).word .Mint64 0 = some (.Vlong (value inputs i))
  tag : ∀ i : Fin 31,i.val < count →
    localRead m heap (declaration i).tag .Mint8unsigned 0 = some (.Vint (0#32))

/-- Real extracted identifiers,not a dense array or old producer environment. -/
theorem names :
    (∀ i j : Fin 31,i ≠ j → (declaration i).word ≠ (declaration j).word) ∧
    (∀ i j : Fin 31,i ≠ j → (declaration i).tag ≠ (declaration j).tag) ∧
    (∀ i j : Fin 31,(declaration i).word ≠ (declaration j).tag) := by
  decide +kernel

theorem stored_reads {m supplied : CC.Mem} {i : Fin 31} {v : BitVec 64}
    (writes : Arm64CiliumCallerGPRMemory.Stores m supplied i v) :
    localRead m writes.after (declaration i).word .Mint64 0 = some (.Vlong v) ∧
    localRead m writes.after (declaration i).tag .Mint8unsigned 0 = some (.Vint (0#32)) := by
  constructor
  · simpa only [localRead,writes.wordBinding,Option.bind_some] using writes.wordRead
  · simpa only [localRead,writes.tagBinding,Option.bind_some] using writes.tagRead

theorem stored_frame {m supplied : CC.Mem} {i : Fin 31} {v : BitVec 64}
    (writes : Arm64CiliumCallerGPRMemory.Stores m supplied i v)
    (id : CC.Ident) (notWord : id ≠ (declaration i).word) (notTag : id ≠ (declaration i).tag)
    (chunk : CC.Chunk) (offset : Int) :
    localRead m writes.after id chunk offset = localRead m supplied id chunk offset := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using
      writes.otherLocals id cell.2 cell.1 binding notWord notTag chunk offset

theorem prefix_frame {m before after : CC.Mem} {inputs : Fin 30 → BitVec 64} {n : Nat}
    (frame : LocalFrame m before after) (old : Initialized m before inputs n) :
    Initialized m after inputs n :=
  ⟨fun i below => (frame _ _ _).trans (old.word i below),
   fun i below => (frame _ _ _).trans (old.tag i below)⟩

/-- SAME two genuine stores extend the initialized prefix and preserve every
older pair using checked actual local identifiers and allocated bindings. -/
theorem stored_prefix {m supplied : CC.Mem} {i : Fin 31} {inputs : Fin 30 → BitVec 64}
    (writes : Arm64CiliumCallerGPRMemory.Stores m supplied i (value inputs i))
    (old : Initialized m supplied inputs i.val) :
    Initialized m writes.after inputs (i.val+1) := by
  have reads := stored_reads writes
  constructor
  · intro j below
    by_cases same : j = i
    · subst j;exact reads.1
    · have prior : j.val < i.val := by
        have different : j.val ≠ i.val := fun h => same (Fin.ext h)
        omega
      exact (stored_frame writes (declaration j).word (names.1 j i same)
        (names.2.2 j i) .Mint64 0).trans (old.word j prior)
  · intro j below
    by_cases same : j = i
    · subst j;exact reads.2
    · have prior : j.val < i.val := by
        have different : j.val ≠ i.val := fun h => same (Fin.ext h)
        omega
      exact (stored_frame writes (declaration j).tag (Ne.symm (names.2.2 i j))
        (names.2.1 j i same) .Mint8unsigned 0).trans (old.tag j prior)

/-- The SAME actual callback outcome/writeback advances one prefix.
The callback's local-read and caller frames are explicit effect premises. -/
theorem input_returns {m before supplied : CC.Mem} (i : Fin 30) (inputs : Fin 30 → BitVec 64)
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv
      [.Vint (6#32)] before trace (.Vlong (value inputs (inputIndex i))) supplied)
    (access : supplied.access = (allocation m).2.access)
    (effects : LocalFrame m before supplied)
    (callerEffects : FrameBelow m.nextblock before supplied)
    (old : Initialized m before inputs i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Arm64CiliumCallerGPRMemory.Stores m supplied (inputIndex i) (value inputs (inputIndex i)),
      CC.Star (CC.Step2 ge)
        (.State procedure (stage (inputIndex i)) k (allocation m).1 le before)
        trace (.State procedure (declaration (inputIndex i)).rest k (allocation m).1
          ((declaration (inputIndex i)).temps le (value inputs (inputIndex i))) writes.after) ∧
      Initialized m writes.after inputs (i.val+1) ∧
      FrameBelow m.nextblock before writes.after ∧
      (∀ id,id ≠ (declaration (inputIndex i)).word → id ≠ (declaration (inputIndex i)).tag →
        ∀ chunk offset,localRead m writes.after id chunk offset = localRead m before id chunk offset) := by
  obtain ⟨writes,run⟩ := Arm64CiliumCallerGPRMemory.input_returns i
    (value inputs (inputIndex i)) trace provider access le k
  refine ⟨writes,run,stored_prefix (inputs := inputs) writes (prefix_frame effects old),
    callerEffects.trans writes.frame,?_⟩
  intro id notWord notTag chunk offset
  exact (stored_frame writes id notWord notTag chunk offset).trans (effects id chunk offset)

/-- The actual final literal-zero stage needs no outcome/fairness/purity
premise. SAME writes close prefix30 to31 at the original table initializer. -/
theorem literal_zero {m before : CC.Mem} (inputs : Fin 30 → BitVec 64)
    (access : before.access = (allocation m).2.access)
    (old : Initialized m before inputs 30) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Arm64CiliumCallerGPRMemory.Stores m before 30 (0#64),
      InternalRun ge 10 (.State procedure (stage 30) k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerGPRSource.after k (allocation m).1
          (le.set (declaration 30).resultTemp (.Vlong (0#64))) writes.after) ∧
      Initialized m writes.after inputs 31 := by
  obtain ⟨writes,run⟩ := Arm64CiliumCallerGPRMemory.literal_zero access le k
  exact ⟨writes,run,stored_prefix (inputs := inputs) writes old⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPRFrames
