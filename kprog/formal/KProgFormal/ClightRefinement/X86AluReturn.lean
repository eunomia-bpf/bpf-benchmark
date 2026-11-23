import KProgFormal.ClightRefinement.X86LogicByteWriteback
import KProgFormal.ClightRefinement.X86AluEntry

namespace KProgFormal.ClightRefinement.X86AluReturn
open X86RegisterView X86LogicFlagOrder X86LogicFlagMemory

/-- The two original handler loops exit through their actual break statements,
retaining every temporary, local binding and heap byte. -/
theorem loops (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 4
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip
        (X86AluEntry.continuation k) e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k e le m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, X86AluEntry.continuation,
      X86AluEntry.loop_exits.1, X86AluEntry.loop_exits.2,
      CC.doStep, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Successful source free and a genuine call boundary give the actual void
fallthrough return. The returned value is the source's undefined void value. -/
theorem fallthrough (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before after : CC.Mem) (boundary : CC.isCallCont k = true)
    (freed : CC.Mem.freeList before (CC.blocksOfEnv ge.genv_cenv e) = some after) :
    InternalRun ge 1
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k e le before)
      (.Returnstate .Vundef k after) := by
  cases k <;> simp only [CC.isCallCont, Bool.false_eq_true] at boundary
  all_goals
    apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, freed,
      CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Actual allocator permissions survive the body stores and derive local
release. The five transitions preserve the caller frame, retain byte contents,
and remove every permission from the declared local ranges. -/
theorem finish (ge : CC.CGenv) (caller before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (boundary : CC.isCallCont k = true)
    (access : before.access = (writerAllocation ge.genv_cenv caller).2.access) :
    ∃ after, InternalRun ge 5
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip
        (X86AluEntry.continuation k) (writerAllocation ge.genv_cenv caller).1 le before)
      (.Returnstate .Vundef k after) ∧
      FrameBelow caller.nextblock before after ∧ after.contents = before.contents ∧
      after.nextblock = before.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
        ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 offset kind permission = false) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  have owned : ∀ id value, (writerAllocation ge.genv_cenv caller).1.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
    intro id value binding
    have live := ((allocated_local_storage allocated).1 id value binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := before)
      (m2 := (writerAllocation ge.genv_cenv caller).2)
      (fun _ => by simp only [CC.Mem.perm, access])).trans live
  obtain ⟨after, freed, frame, contents, next, released⟩ := deallocate_live_locals allocated owned
  exact ⟨after, (loops ge _ le k before).trans
    (fallthrough ge _ le k before after boundary freed), frame, contents, next, released⟩

/-- The represented native register bank survives source local release,
including every register's pointer origin and tag. -/
theorem registers {frontier : CC.Block} {before after : CC.Mem}
    (frame : FrameBelow frontier before after) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (block : CC.Block) (base : CC.Integers.Ptrofs)
    (cpu : X86.Cpu) (old : block.toNat < frontier.toNat)
    (represented : RegistersRepresent addresses origins before block base cpu) :
    RegistersRepresent addresses origins after block base cpu := by
  intro index
  obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
  exact ⟨value, raw, tag, (frame.load CC.Mptr block _ old).trans wordRead,
    (frame.load .Mint8unsigned block _ old).trans tagRead, valueRep, native⟩

/-- All five represented flags survive release of the genuine fresh locals. -/
theorem flags {frontier : CC.Block} {before after : CC.Mem}
    (frame : FrameBelow frontier before after) (places : Locations) (native : X86.Flags)
    (old : places.cf.1.toNat < frontier.toNat ∧ places.zf.1.toNat < frontier.toNat ∧
      places.sf.1.toNat < frontier.toNat ∧ places.overflow.1.toNat < frontier.toNat ∧
      places.pf.1.toNat < frontier.toNat)
    (represented : FlagsRepresent before places native) : FlagsRepresent after places native := by
  exact ⟨(frame.load .Mint8unsigned _ _ old.1).trans represented.cf,
    (frame.load .Mint8unsigned _ _ old.2.1).trans represented.zf,
    (frame.load .Mint8unsigned _ _ old.2.2.1).trans represented.sf,
    (frame.load .Mint8unsigned _ _ old.2.2.2.1).trans represented.overflow,
    (frame.load .Mint8unsigned _ _ old.2.2.2.2).trans represented.pf⟩

end KProgFormal.ClightRefinement.X86AluReturn
