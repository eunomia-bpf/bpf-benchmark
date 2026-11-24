import KProgFormal.ClightRefinement.X86LogicRegisterReference
import KProgFormal.ClightRefinement.X86LogicDwordOperands
import KProgFormal.ClightRefinement.X86AluLogicResultEntry

namespace KProgFormal.ClightRefinement.X86LogicDwordReference

def kind (isAnd : Bool) : Reference.X86.LogicKind := if isAnd then .and else .or

/-- Both source observations derive the SAME canonical OR/AND dword full-state step. -/
theorem step (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (state : Reference.X86.State)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base
      (X86LogicReference.input state))
    (dst src : Reference.X86.RegisterSlice) (left right nextPc : BitVec 64)
    (aux : BitVec 32) (isAnd : Bool) (ordinaryDst : dst.reg ≠ 4) (ordinarySrc : src.reg ≠ 4)
    (dstLane : (aux >>> 8).setWidth 8 = BitVec.ofNat 8 (dst.shift .w32))
    (srcLane : (aux >>> 16).setWidth 8 = BitVec.ofNat 8 (src.shift .w32))
    (leftRead : CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (src.reg.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned memory block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (rightTag : CC.Mem.load .Mint8unsigned memory block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (src.reg.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (running : state.modelError = none) :
    let value := X86AluLogicResultEntry.result isAnd
      (X86RegisterReadLanes.result left .d ((aux >>> 8).setWidth 8))
      (X86RegisterReadLanes.result right .d ((aux >>> 16).setWidth 8))
    Reference.X86.step (.logic .w32 (kind isAnd) (.register dst) (.register src) nextPc) state =
      ⟨{state with
        gpr := fun reg => ((X86LogicReference.input state).setReg .d
          (X86.GPR.ofIndex dst.reg) (X86.Value.trunc .d value) (dst.shift .w32 == 8)).regs.get (X86.GPR.ofIndex reg),
        rflags := X86LogicReference.flagsWord state.rflags
          (X86.Flags.logic .d (X86.Value.trunc .d value)
            (state.oracle.bits state.oracle.cursor) (X86LogicReference.input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
  dsimp only
  apply X86LogicRegisterReference.step .w32 state dst src (kind isAnd) _ nextPc running
  have left := X86LogicDwordOperands.scalar addresses origins memory block base _ represented
    dst left _ ordinaryDst dstLane leftRead leftTag
  have right := X86LogicDwordOperands.scalar addresses origins memory block base _ represented
    src right _ ordinarySrc srcLane rightRead rightTag
  cases isAnd
  · exact .inr (.inl ⟨rfl, by simp only [X86AluLogicResultEntry.result, Bool.false_eq_true,
      ite_false, left, right]; rfl⟩)
  · exact .inr (.inr ⟨rfl, by simp only [X86AluLogicResultEntry.result, ite_true, left, right]; rfl⟩)

end KProgFormal.ClightRefinement.X86LogicDwordReference
