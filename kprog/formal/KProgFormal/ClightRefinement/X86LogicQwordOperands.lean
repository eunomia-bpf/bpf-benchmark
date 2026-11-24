import KProgFormal.ClightRefinement.X86RegisterReadScalar
import KProgFormal.ClightRefinement.X86LogicRegisterReference

namespace KProgFormal.ClightRefinement.X86LogicQwordOperands

/-- Actual scalar/tag0 loads determine the canonical qword input; every
legal register slice selects its ordinary low32 lane. -/
theorem scalar (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base cpu)
    (slice : Reference.X86.RegisterSlice) (word : BitVec 64) (shift : BitVec 8)
    (ordinary : slice.reg ≠ 4)
    (lane : shift = BitVec.ofNat 8 (slice.shift .w64))
    (current : CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (slice.reg.val : Int)))) =
        some (.Vlong word))
    (tag : CC.Mem.load .Mint8unsigned memory block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (slice.reg.val : Int))) + 8)) =
        some (.Vint (0#32))) :
    X86RegisterReadLanes.result word .q shift =
      cpu.getReg .q (X86.GPR.ofIndex slice.reg) (slice.shift .w64 == 8) := by
  have native := X86RegisterReadValue.native_word addresses origins memory block base cpu
    represented slice.reg word ordinary current tag
  rw [X86.Cpu.getReg, native, lane]
  cases slice <;> simp [Reference.X86.RegisterSlice.shift,
    X86RegisterReadLanes.result, X86.Value.readHigh8]


/-- Both source observations derive the SAME canonical XOR qword full-state step. -/
theorem xor_step (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (state : Reference.X86.State)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base
      (X86LogicReference.input state))
    (dst src : Reference.X86.RegisterSlice) (left right nextPc : BitVec 64)
    (aux : BitVec 32) (ordinaryDst : dst.reg ≠ 4) (ordinarySrc : src.reg ≠ 4)
    (dstLane : (aux >>> 8).setWidth 8 = BitVec.ofNat 8 (dst.shift .w64))
    (srcLane : (aux >>> 16).setWidth 8 = BitVec.ofNat 8 (src.shift .w64))
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
    let value := X86RegisterReadLanes.result left .q ((aux >>> 8).setWidth 8) ^^^
      X86RegisterReadLanes.result right .q ((aux >>> 16).setWidth 8)
    Reference.X86.step (.logic .w64 .xor (.register dst) (.register src) nextPc) state =
      ⟨{state with
        gpr := fun reg => ((X86LogicReference.input state).setReg .q
          (X86.GPR.ofIndex dst.reg) (X86.Value.trunc .q value) (dst.shift .w64 == 8)).regs.get (X86.GPR.ofIndex reg),
        rflags := X86LogicReference.flagsWord state.rflags
          (X86.Flags.logic .q (X86.Value.trunc .q value)
            (state.oracle.bits state.oracle.cursor) (X86LogicReference.input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
  dsimp only
  apply X86LogicRegisterReference.step .w64 state dst src .xor _ nextPc running
  refine .inl ⟨rfl, ?_⟩
  rw [scalar addresses origins memory block base _ represented dst left _ ordinaryDst
      dstLane leftRead leftTag,
    scalar addresses origins memory block base _ represented src right _ ordinarySrc
      srcLane rightRead rightTag]
  rfl

end KProgFormal.ClightRefinement.X86LogicQwordOperands
