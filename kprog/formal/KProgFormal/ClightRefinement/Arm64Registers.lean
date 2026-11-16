import KProgFormal.ClightRefinement.Arm64NopEntry
import KProgFormal.Reference.Provenance

namespace KProgFormal.ClightRefinement.Arm64Registers

/-- Physical origins for abstract Clight pointer blocks. None means unbound,
not address zero. Establishing the map from a producer/native invocation and
relating its ranges/permissions to native memory are separate obligations. -/
abbrev PointerOrigins := CC.Block → Option (BitVec 64)

/-- Bind the newly used SP reader to the actual signed-long pointer field.
The reader itself still computes its address through upstream Ctypes. -/
theorem sp_layout :
    Arm64EntryMemory.fieldAddress (.Vptr (CC.Positive.ofNat 1) 0) Arm64Program._sp =
      some (.Vptr (CC.Positive.ofNat 1) 40) ∧
    ((Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).map
      (fun co => CC.fieldType Arm64Program._sp co.co_members)) =
        some (.OK (CC.tptr CC.tlong)) := by
  decide +kernel

/-- Representation of a defined 64-bit union value. Scalar bits retain their
value; pointers require an explicit block origin plus the full offset. Other
Clight value forms, including undef, are not given invented native bits. -/
def ValueRep (addresses : PointerOrigins) : CC.Val → BitVec 64 → Prop
  | .Vlong bits, word => word = bits
  | .Vptr block offset, word =>
    ∃ base, addresses block = some base ∧ word = base + offset.setWidth 64
  | _, _ => False

/-- A binding is single-valued even though different abstract blocks may
still need a separate native range/aliasing admissibility proof. -/
theorem valueRep_unique {addresses : PointerOrigins} {v : CC.Val} {a b : BitVec 64}
    (ha : ValueRep addresses v a) (hb : ValueRep addresses v b) : a = b := by
  cases v <;> try contradiction
  · exact ha.trans hb.symm
  · obtain ⟨base, origin, ha⟩ := ha
    obtain ⟨other, origin', hb⟩ := hb
    rw [origin] at origin'
    cases origin'
    exact ha.trans hb.symm

/-- A concrete architectural-register relation over the actual borrowed entry
reads. The cell map and invocation origins are explicit bindings, not guessed
from register values. All 256 tags use the existing M3 materialization. This
does not yet represent native memory, permissions, or producer bookkeeping. -/
structure Represents (addresses : PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (cells : Reference.AArch64.Gpr → Nat)
    (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (s : Reference.AArch64.State) : Prop where
  gpr : ∀ i, ∃ value raw tag,
    Arm64EntryMemory.gpr frontier m entry (cells i) =
      some (value, .Vint (tag.setWidth 32)) ∧
    ValueRep addresses value raw ∧
    Reference.AArch64.gpr s i = Reference.Provenance.AArch64.materialize origins raw tag
  sp : ∃ offset, Arm64EntryMemory.borrowed frontier .Mint64 m entry Arm64Program._sp =
    some (.Vlong offset) ∧ Reference.AArch64.sp s = offset + origins.stack
  vectors : ∀ i, Arm64EntryMemory.vector frontier m entry i = some
    (.Vlong ((Reference.AArch64.readVector s i).setWidth 64),
     .Vlong (((Reference.AArch64.readVector s i) >>> 64).setWidth 64))
  flags : Arm64Nop.FlagsRepresent frontier m entry s

private theorem vector_halves (word : BitVec 128) :
    ((word >>> 64).setWidth 64 ++ word.setWidth 64) = word := by
  rw [BitVec.setWidth_ushiftRight_eq_extractLsb,
    BitVec.setWidth_eq_extractLsb' (by decide)]
  exact BitVec.extractLsb'_append_extractLsb'

/-- The relation determines every covered architectural bit from the actual
entry reads and explicit bindings. It cannot relate an unchanged heap to
arbitrarily different GPR/SP/vector/NZCV values. Extra native flag bits and
nonregister machine fields are intentionally outside this register law. -/
theorem unique {addresses : PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {cells : Reference.AArch64.Gpr → Nat} {frontier : CC.Block}
    {m : CC.Mem} {entry : CC.Val} {a b : Reference.AArch64.State}
    (ha : Represents addresses origins cells frontier m entry a)
    (hb : Represents addresses origins cells frontier m entry b) :
    (∀ i, Reference.AArch64.gpr a i = Reference.AArch64.gpr b i) ∧
      Reference.AArch64.sp a = Reference.AArch64.sp b ∧
      (∀ i, Reference.AArch64.readVector a i = Reference.AArch64.readVector b i) ∧
      (∀ flag, read_flag flag a.machine = read_flag flag b.machine) := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · intro i
    obtain ⟨va, ra, ta, la, ba, ga⟩ := ha.gpr i
    obtain ⟨vb, rb, tb, lb, bb, gb⟩ := hb.gpr i
    have slots := Option.some.inj (la.symm.trans lb)
    obtain ⟨values, tags⟩ := Prod.mk.inj slots
    cases values
    have sameTag : ta = tb := by
      have widened := CC.Val.Vint.inj tags
      simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) widened
    rw [ga, gb, valueRep_unique ba bb, sameTag]
  · obtain ⟨oa, la, sa⟩ := ha.sp
    obtain ⟨ob, lb, sb⟩ := hb.sp
    have same := CC.Val.Vlong.inj (Option.some.inj (la.symm.trans lb))
    rw [sa, sb, same]
  · intro i
    have slots := Option.some.inj ((ha.vectors i).symm.trans (hb.vectors i))
    obtain ⟨lo, hi⟩ := Prod.mk.inj slots
    have loBits := CC.Val.Vlong.inj lo
    have hiBits := CC.Val.Vlong.inj hi
    calc
      Reference.AArch64.readVector a i =
        (((Reference.AArch64.readVector a i) >>> 64).setWidth 64 ++
          (Reference.AArch64.readVector a i).setWidth 64) := (vector_halves _).symm
      _ = _ := by rw [loBits, hiBits]
      _ = Reference.AArch64.readVector b i := vector_halves _
  · have la := ha.flags
    have lb := hb.flags
    unfold Arm64Nop.FlagsRepresent at la lb
    rw [la] at lb
    simp only [Option.some.injEq, Prod.mk.injEq, CC.Val.Vint.injEq] at lb
    obtain ⟨hn, hz, hc, hv⟩ := lb
    intro flag
    cases flag with
    | N => simpa using congrArg (fun x : BitVec 32 => x.setWidth 1) hn
    | Z => simpa using congrArg (fun x : BitVec 32 => x.setWidth 1) hz
    | C => simpa using congrArg (fun x : BitVec 32 => x.setWidth 1) hc
    | V => simpa using congrArg (fun x : BitVec 32 => x.setWidth 1) hv

/-- Exact raw caller framing preserves every successful read and therefore
the complete register relation, without a caller-supplied decoder law. -/
theorem frame {addresses : PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {cells : Reference.AArch64.Gpr → Nat} {frontier : CC.Block}
    {before after : CC.Mem} (h : FrameBelow frontier before after)
    (entry : CC.Val) (s : Reference.AArch64.State) :
    Represents addresses origins cells frontier after entry s ↔
      Represents addresses origins cells frontier before entry s := by
  constructor
  all_goals
    intro rep
    refine ⟨?_, ?_, ?_, ?_⟩
    · simpa only [Arm64EntryMemory.gpr_frame h] using rep.gpr
    · simpa only [Arm64EntryMemory.borrowed_frame h] using rep.sp
    · simpa only [Arm64EntryMemory.vector_frame h] using rep.vectors
    · simpa only [Arm64Nop.flagsRepresent_frame h] using rep.flags

/-- Updating only the native control cursor changes none of the represented
registers, including every vector half and the distinct SP. -/
theorem cursor {addresses : PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {cells : Reference.AArch64.Gpr → Nat} {frontier : CC.Block}
    (m : CC.Mem) (entry : CC.Val) (s : Reference.AArch64.State) (pc : BitVec 64) :
    Represents addresses origins cells frontier m entry (Arm64Nop.atCursor pc s) ↔
      Represents addresses origins cells frontier m entry s := by
  have hg : ∀ i, Reference.AArch64.gpr (Arm64Nop.atCursor pc s) i =
      Reference.AArch64.gpr s i := by
    intro i
    simp [Reference.AArch64.gpr, Arm64Nop.atCursor, write_pc, r_of_w_different]
  have hsp : Reference.AArch64.sp (Arm64Nop.atCursor pc s) = Reference.AArch64.sp s := by
    simp [Reference.AArch64.sp, Arm64Nop.atCursor, write_pc, r_of_w_different]
  have hv : ∀ i, Reference.AArch64.readVector (Arm64Nop.atCursor pc s) i =
      Reference.AArch64.readVector s i := by
    intro i
    simp [Reference.AArch64.readVector, Arm64Nop.atCursor, write_pc, r_of_w_different]
  constructor
  all_goals
    intro rep
    refine ⟨?_, ?_, ?_, ?_⟩
    · simpa only [hg] using rep.gpr
    · simpa only [hsp] using rep.sp
    · simpa only [hv] using rep.vectors
    · simpa only [Arm64Nop.flagsRepresent_cursor] using rep.flags

/-- The actual procedure preserves the full concrete register relation along
its certified nineteen transitions, while the complete LNSym state advances
by its checked NOP step. General caller continuations are allowed here; this
is the execution witness, not a claim about resumed caller behavior. -/
theorem call_corresponds (addresses : PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (width : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) (s : Reference.AArch64.State)
    (hrep : Represents addresses origins cells m.nextblock m ignored.entry s)
    (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    ∃ after, InternalRun Arm64Program.prog.globalenv 19
      (.Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments ignored width) k m)
      (.Returnstate .Vundef k after) ∧ FrameBelow m.nextblock m after ∧
      Reference.AArch64.step s =
        ⟨Arm64Nop.atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      Represents addresses origins cells m.nextblock after ignored.entry
        (Arm64Nop.atCursor (read_pc s.machine + (4#64)) s) := by
  obtain ⟨after, run, framed⟩ := Arm64Nop.call_internal m ignored width k hk
  exact ⟨after, run, framed, Arm64Nop.reference_step s herror hfetch,
    (cursor _ _ _ _).mpr ((frame framed ignored.entry s).mpr hrep)⟩

/-- Every relational return at Kstop has this concrete register/native
correspondence. The observed trace, result and complete memory are arbitrary
inputs to the theorem, not restricted to the exhibited execution. -/
theorem return_corresponds (addresses : PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (width : BitVec 8)
    (s : Reference.AArch64.State)
    (hrep : Represents addresses origins cells m.nextblock m ignored.entry s)
    (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32))
    (t : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 Arm64Program.prog.globalenv)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments ignored width) .Kstop m) t
      (.Returnstate result .Kstop after)) :
    t = CC.E0 ∧ result = .Vundef ∧ FrameBelow m.nextblock m after ∧
      Reference.AArch64.step s =
        ⟨Arm64Nop.atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      Represents addresses origins cells m.nextblock after ignored.entry
        (Arm64Nop.atCursor (read_pc s.machine + (4#64)) s) := by
  obtain ⟨silent, value, framed, native, _⟩ :=
    Arm64Nop.return_flags_correspond m ignored width s hrep.flags herror hfetch t result after observed
  exact ⟨silent, value, framed, native,
    (cursor _ _ _ _).mpr ((frame framed ignored.entry s).mpr hrep)⟩

end KProgFormal.ClightRefinement.Arm64Registers
