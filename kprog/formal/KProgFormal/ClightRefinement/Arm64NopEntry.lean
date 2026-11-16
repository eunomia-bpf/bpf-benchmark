import KProgFormal.ClightRefinement.Arm64EntryMemory
import KProgFormal.ClightRefinement.Arm64NopCall

namespace KProgFormal.ClightRefinement.Arm64Nop

/-- Concrete, partial native representation: the four borrowed C flag bytes
must be defined scalar values equal to LNSym's individual flag bits. This says
nothing yet about GPR pointer provenance or the native address space. -/
def FlagsRepresent (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (s : Reference.AArch64.State) : Prop :=
  Arm64EntryMemory.flags frontier m entry = some
    (.Vint ((read_flag .N s.machine).setWidth 32),
     .Vint ((read_flag .Z s.machine).setWidth 32),
     .Vint ((read_flag .C s.machine).setWidth 32),
     .Vint ((read_flag .V s.machine).setWidth 32))

theorem flagsRepresent_frame {frontier : CC.Block} {before after : CC.Mem}
    (h : FrameBelow frontier before after) (entry : CC.Val)
    (s : Reference.AArch64.State) :
    FlagsRepresent frontier after entry s ↔ FlagsRepresent frontier before entry s := by
  simp only [FlagsRepresent, Arm64EntryMemory.flags_frame h]

theorem flagsRepresent_cursor (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (s : Reference.AArch64.State) (cursor : BitVec 64) :
    FlagsRepresent frontier m entry (atCursor cursor s) ↔
      FlagsRepresent frontier m entry s := by
  simp [FlagsRepresent, atCursor, read_flag, write_pc, r_of_w_different]

/-- The actual Callstate-to-Returnstate witness preserves every checked field,
borrowed scalar, GPR-cell/tag pair, vector half and flag tuple. In particular,
every successful query stays successful with the same value. The fixed
frontier is the caller's nextblock, not the enlarged post-call nextblock. -/
theorem call_preserves_entry (m : CC.Mem) (ignored : IgnoredArguments) (width : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ m', CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal handler) (arguments ignored width) k m) CC.E0
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' ∧
      (∀ chunk name, Arm64EntryMemory.field m.nextblock chunk m' ignored.entry name =
        Arm64EntryMemory.field m.nextblock chunk m ignored.entry name) ∧
      (∀ chunk name, Arm64EntryMemory.borrowed m.nextblock chunk m' ignored.entry name =
        Arm64EntryMemory.borrowed m.nextblock chunk m ignored.entry name) ∧
      (∀ i, Arm64EntryMemory.gpr m.nextblock m' ignored.entry i =
        Arm64EntryMemory.gpr m.nextblock m ignored.entry i) ∧
      (∀ i, Arm64EntryMemory.vector m.nextblock m' ignored.entry i =
        Arm64EntryMemory.vector m.nextblock m ignored.entry i) ∧
      Arm64EntryMemory.flags m.nextblock m' ignored.entry =
        Arm64EntryMemory.flags m.nextblock m ignored.entry := by
  obtain ⟨m', call, frame⟩ := call_returns m ignored width k hk
  exact ⟨m', call, frame, (fun chunk name => Arm64EntryMemory.field_frame frame chunk ignored.entry name),
    (fun chunk name => Arm64EntryMemory.borrowed_frame frame chunk ignored.entry name),
    Arm64EntryMemory.gpr_frame frame ignored.entry,
    Arm64EntryMemory.vector_frame frame ignored.entry,
    Arm64EntryMemory.flags_frame frame ignored.entry⟩

/-- Concrete NZCV representation survives the complete real C procedure and
the full checked LNSym/reference NOP step, without an opaque heap decoder or
caller-supplied decoder-stability premise. Source-entry admissibility, the
remaining architectural representation and control refinement remain open. -/
theorem call_flags_correspond (m : CC.Mem) (ignored : IgnoredArguments) (width : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) (s : Reference.AArch64.State)
    (hrep : FlagsRepresent m.nextblock m ignored.entry s)
    (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    ∃ m', CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal handler) (arguments ignored width) k m) CC.E0
      (.Returnstate .Vundef k m') ∧ FrameBelow m.nextblock m m' ∧
      Reference.AArch64.step s =
        ⟨atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      FlagsRepresent m.nextblock m' ignored.entry
        (atCursor (read_pc s.machine + (4#64)) s) := by
  obtain ⟨m', call, frame⟩ := call_returns m ignored width k hk
  refine ⟨m', call, frame, reference_step s herror hfetch, ?_⟩
  exact (flagsRepresent_cursor _ _ _ _ _).mpr
    ((flagsRepresent_frame frame ignored.entry s).mpr hrep)

/-- Every relational return at the top-level boundary, with an arbitrary
proposed trace/result/memory, has the same concrete NZCV/native correspondence.
This is universal over returns; it does not assume that the observed run is
the particular executable witness or that its trace is already empty. -/
theorem return_flags_correspond (m : CC.Mem) (ignored : IgnoredArguments) (width : BitVec 8)
    (s : Reference.AArch64.State) (hrep : FlagsRepresent m.nextblock m ignored.entry s)
    (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32))
    (t : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal handler) (arguments ignored width) .Kstop m) t
      (.Returnstate result .Kstop after)) :
    t = CC.E0 ∧ result = .Vundef ∧ FrameBelow m.nextblock m after ∧
      Reference.AArch64.step s =
        ⟨atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      FlagsRepresent m.nextblock after ignored.entry
        (atCursor (read_pc s.machine + (4#64)) s) := by
  obtain ⟨m', _, frame, _, unique, _⟩ := call_all_behaviors m ignored width
  have stuck : ∀ u next, ¬ CC.Step2 Arm64Program.prog.globalenv
      (.Returnstate result .Kstop after) u next := by
    intro u next step
    cases step
  obtain ⟨silent, same⟩ := unique _ _ observed stuck
  cases same
  exact ⟨silent, rfl, frame, reference_step s herror hfetch,
    (flagsRepresent_cursor _ _ _ _ _).mpr
      ((flagsRepresent_frame frame ignored.entry s).mpr hrep)⟩

end KProgFormal.ClightRefinement.Arm64Nop
