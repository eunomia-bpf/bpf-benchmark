import KProgFormal.ClightRefinement.X86NopCall
import KProgFormal.ClightRefinement.X86NopReference

namespace KProgFormal.ClightRefinement.X86NopNative
open X86RegisterView

/-- The complete original NOP handler refines the SAME canonical checked ISA
step. All original ignored arguments, pointer tags, heap permissions, oracle,
flags and native state are unrestricted. The identical heap preserves the
initial GPR and flag representations and every caller allocation. Dispatcher
selection is a separate composition obligation. -/
theorem execute (ge : CC.CGenv) (memory : CC.Mem) (k : CC.Cont)
    (binding op dst src flags aux imm : CC.Val) (width : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cells : CC.Block) (base : CC.Integers.Ptrofs) (places : X86LogicFlagOrder.Locations)
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (registers : RegistersRepresent addresses origins memory cells base (X86LogicReference.input state))
    (flagBytes : X86LogicFlagMemory.FlagsRepresent memory places (X86LogicReference.input state).flags)
    (running : state.modelError = none) (boundary : CC.isCallCont k = true) :
    let native := Reference.X86.step (.nop nextPc) state
    InternalRun ge 6
      (.Callstate (.Internal X86NopCall.handler)
        [binding, op, dst, src, flags, aux, imm, .Vint (width.setWidth 32)] k memory)
      (.Returnstate .Vundef k memory) ∧
    RegistersRepresent addresses origins memory cells base (X86LogicReference.input native.state) ∧
    X86LogicFlagMemory.FlagsRepresent memory places (X86LogicReference.input native.state).flags ∧
    native = ⟨{state with pc := nextPc}, [], none⟩ := by
  have canonical := X86NopReference.step state nextPc running
  dsimp only
  refine ⟨X86NopCall.execute ge memory k binding op dst src flags aux imm width boundary, ?_, ?_, canonical⟩
  · rw [canonical]
    exact registers
  · rw [canonical]
    exact flagBytes

end KProgFormal.ClightRefinement.X86NopNative
