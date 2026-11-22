import KProgFormal.ClightRefinement.Arm64RegisterReads
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Reads
open Arm64ProgramEntryLinked (ge)

/-- The actual linked composites retain precisely the source reader layout. -/
theorem layout : Arm64RegisterReads.GprLayout ge := by
  constructor <;> decide +kernel

/-- Both names used by the original CSEL pointer/tag branch resolve to the
actual source functions in the existing linked program. -/
theorem bindings :
    (CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_pointer = some (CC.Positive.ofNat 104) ∧
      CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 104) =
        some (.Internal Arm64Program.f_kprog_arm64_program_pointer)) ∧
    (CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_tag = some (CC.Positive.ofNat 65) ∧
      CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 65) =
        some (.Internal Arm64Program.f_kprog_arm64_program_tag)) := by
  refine ⟨⟨?_,?_⟩,?_,?_⟩ <;> run_tac Arm64ProgramEntryLinked.sourceEquality

/-- Derive both real reader returns from the same existing complete register
relation. Raw pointer identity and every tag bit are retained; the mature native
word remains their imported provenance materialization. Each call preserves the
whole memory and its own arbitrary continuation. -/
theorem helpers (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier m (.Vptr b ofs) native)
    (i : Reference.AArch64.Gpr) (pointerCont tagCont : CC.Cont) :
    ∃ value raw tag,
      Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val = some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Reference.AArch64.gpr native i = Reference.Provenance.AArch64.materialize origins raw tag ∧
      InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] pointerCont m)
        (.Returnstate value (CC.callCont pointerCont) m) ∧
      InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag)
        [.Vptr b ofs,.Vlong (BitVec.ofNat 64 i.val)] tagCont m)
        (.Returnstate (.Vint (tag.setWidth 32)) (CC.callCont tagCont) m) := by
  obtain ⟨value,raw,tag,observed,valueRep,nativeWord⟩ := represented.gpr i
  have pointer := Arm64RegisterReads.gpr_calls_bound ge layout (by decide +kernel)
    addresses frontier b ofs i m pointerCont value raw tag observed valueRep
  have tagged := Arm64RegisterReads.gpr_calls_bound ge layout (by decide +kernel)
    addresses frontier b ofs i m tagCont value raw tag observed valueRep
  exact ⟨value,raw,tag,observed,valueRep,nativeWord,pointer.2.2,tagged.2.1⟩

end KProgFormal.ClightRefinement.Arm64Select.Reads
