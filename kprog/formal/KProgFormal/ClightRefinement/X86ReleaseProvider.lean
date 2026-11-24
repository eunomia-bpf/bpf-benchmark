import KProgFormal.ClightRefinement.X86CallFrameComplete

namespace KProgFormal.ClightRefinement.X86ReleaseProvider

/-- Caller memory protected outside the actual release cache, including every
provider effect permitted by this explicitly stated ABI contract. -/
def Frame (stack : CC.Block) (before after : CC.Mem) : Prop := ∀ chunk block offset,
  block ≠ stack → CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset

structure View (memory : CC.Mem) (binding stack : CC.Block) (base : CC.Integers.Ptrofs) : Prop where
  header : CC.Mem.load CC.Mptr memory binding 8 = some (.Vptr stack base)
  bytes : ∀ slot lane, CC.Mem.validAccess memory .Mint8unsigned stack
    (CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseByteCall.address base slot lane)) .Writable = true
  words : ∀ slot, CC.Mem.validAccess memory .Mint64 stack
    (CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseWord.address base slot)) .Writable = true

/-- An actual kind-6 external outcome, with ABI memory guarantees explicit.
No external-call frame law or provider result is asserted as a new axiom. -/
structure Outcome (ge : CC.CGenv) (stack : CC.Block) (before : CC.Mem) where
  value : BitVec 64
  trace : CC.Trace
  supplied : CC.Mem
  call : CC.externalCall X86RegisterWriteRspReleaseWord.inputEF (CC.Genv.toSenv ge.genv_genv)
    [.Vint (6#32)] before trace (.Vlong value) supplied
  access : supplied.access = before.access
  frontier : supplied.nextblock = before.nextblock
  frame : Frame stack before supplied

/-- Total availability is an explicit platform ABI premise, not a consequence
of the imported determinacy/trace-length laws. It supplies actual outcomes. -/
def Available (ge : CC.CGenv) (binding stack : CC.Block) (base : CC.Integers.Ptrofs) : Prop :=
  ∀ memory, View memory binding stack base → Nonempty (Outcome ge stack memory)

/-- Access equality transports every original typed permission. -/
theorem access_rights (before after : CC.Mem) (same : after.access = before.access)
    (chunk : CC.Chunk) (block : CC.Block) (offset : CC.Z) (permission : CC.Permission) :
    CC.Mem.validAccess after chunk block offset permission = CC.Mem.validAccess before chunk block offset permission :=
  CC.Mem.validAccess_congr (fun ofs => by simp only [CC.Mem.perm, same])

/-- Protected header reads and access equality derive the supplied cache view. -/
theorem outcome_view (ge : CC.CGenv) (binding stack : CC.Block) (base : CC.Integers.Ptrofs)
    (memory : CC.Mem) (view : View memory binding stack base) (separate : binding ≠ stack)
    (outcome : Outcome ge stack memory) : View outcome.supplied binding stack base := by
  refine ⟨(outcome.frame CC.Mptr binding 8 separate).trans view.header, ?_, ?_⟩
  · intro slot lane
    exact (access_rights memory outcome.supplied outcome.access _ _ _ _).trans (view.bytes slot lane)
  · intro slot
    exact (access_rights memory outcome.supplied outcome.access _ _ _ _).trans (view.words slot)

/-- A real source store frame and permission equality carry the next view. -/
theorem view_transport (binding stack : CC.Block) (base : CC.Integers.Ptrofs) (before after : CC.Mem)
    (view : View before binding stack base) (separate : binding ≠ stack)
    (same : after.access = before.access) (frame : Frame stack before after) : View after binding stack base := by
  refine ⟨(frame CC.Mptr binding 8 separate).trans view.header, ?_, ?_⟩
  · intro slot lane
    exact (access_rights before after same _ _ _ _).trans (view.bytes slot lane)
  · intro slot
    exact (access_rights before after same _ _ _ _).trans (view.words slot)

/-- Exact original release observations; the changing lane is kept separate. -/
structure Core (le : CC.TempEnv) (binding : CC.Block) (slot : Fin 6) (old next : BitVec 64) : Prop where
  binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0)
  index : le.get X86_program_profile_bpf.___x86_release_i__5 =
    some (.Vint (X86RegisterWriteRspReleaseSelect.index slot))
  offset : le.get X86_program_profile_bpf.___x86_release_off__5 =
    some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot))
  old : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old)
  next : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next)

/-- Original byte decisions and provider-return temporaries preserve Core. -/
theorem core_byte (le : CC.TempEnv) (binding stack : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (lane : Fin 8) (old next value : BitVec 64) (core : Core le binding slot old next) :
    Core (X86RegisterWriteRspReleaseByteCall.temps
      (X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next) value stack base) binding slot old next := by
  constructor <;> simp +decide [X86RegisterWriteRspReleaseByteCall.temps, X86RegisterWriteRspReleaseByteLoop.temps,
    CC.PTree.gso, core.binding, core.index, core.offset, core.old, core.next]

/-- The skip decisions and the actual lane assignment preserve Core. -/
theorem core_control (le : CC.TempEnv) (binding : CC.Block) (slot : Fin 6) (lane : Fin 8)
    (old next : BitVec 64) (value : BitVec 32) (core : Core le binding slot old next) :
    Core ((X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next).set
      X86_program_profile_bpf.___x86_release_lane__5 (.Vint value)) binding slot old next := by
  constructor <;> simp +decide [X86RegisterWriteRspReleaseByteLoop.temps, CC.PTree.gso,
    core.binding, core.index, core.offset, core.old, core.next]

/-- The real lane assignment alone preserves all original Core observations. -/
theorem core_lane (le : CC.TempEnv) (binding : CC.Block) (slot : Fin 6) (old next : BitVec 64)
    (value : BitVec 32) (core : Core le binding slot old next) :
    Core (le.set X86_program_profile_bpf.___x86_release_lane__5 (.Vint value)) binding slot old next := by
  constructor <;> simp +decide [CC.PTree.gso, core.binding, core.index, core.offset, core.old, core.next]

/-- Original whole-word selection and provider-return temps preserve Core. -/
theorem core_word (le : CC.TempEnv) (binding stack : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (old next value : BitVec 64) (core : Core le binding slot old next) :
    Core (X86RegisterWriteRspReleaseWord.temps
      (X86RegisterWriteRspReleaseSelect.temps le slot old next) value stack base) binding slot old next := by
  constructor <;> simp +decide [X86RegisterWriteRspReleaseWord.temps, X86RegisterWriteRspReleaseSelect.temps,
    CC.PTree.gso, core.binding, core.index, core.offset, core.old, core.next]

end KProgFormal.ClightRefinement.X86ReleaseProvider
