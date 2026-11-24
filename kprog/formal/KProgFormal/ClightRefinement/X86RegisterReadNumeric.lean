import KProgFormal.ClightRefinement.X86RegisterReadRspNative
import KProgFormal.ClightRefinement.X86RegisterReadScalar

namespace KProgFormal.ClightRefinement.X86RegisterReadNumeric

def length (index : Fin 16) (size : X86.Size) : Nat :=
  if index = 4 then X86RegisterReadRspCall.length size else X86RegisterReadScalar.length size

/-- One genuine reader interface covers ordinary scalar cells and the real
RSP materialization path. Only non-RSP rows require a scalar tag; the native
base is the same origin used by RegistersRepresent. Legal high-byte reads
remain available on their actual four registers. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (memory : CC.Mem) (k : CC.Cont) (cpu : X86.Cpu) (index : Fin 16)
    (size : X86.Size) (width : BitVec 8) (high : Bool) (raw : BitVec 64)
    (helperBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (legalHigh : high = true → size = .b ∧ index.val < 4)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong raw))
    (scalar : index ≠ 4 → CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack)) :
    InternalRun ge (length index size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock 0)
          (X86RegisterReadValue.registerByte index) width (if high then 8 else 0)) k memory)
      (.Returnstate (.Vlong (cpu.getReg size (X86.GPR.ofIndex index) high)) (CC.callCont k) memory) := by
  by_cases sp : index = 4
  · subst index
    have noHigh : high = false := by
      cases h : high
      · rfl
      · have impossible : (4 : Nat) < 4 := (legalHigh h).2
        omega
    have code : X86RegisterReadValue.registerByte (4 : Fin 16) = (4#8) := rfl
    have zero : (0#8) = (0 : BitVec 8) := rfl
    simpa only [length, ite_true, noHigh, Bool.false_eq_true, ite_false, code, zero] using
      X86RegisterReadRspNative.call ge layout valueLayout addresses origins memory k cpu size width raw
        helperBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
        represented effective helper cells current header native
  · simpa only [length, if_neg sp] using
      X86RegisterReadScalar.native_call ge layout addresses origins memory k cpu index size width high raw
        helperBlock bindingBlock cellsBlock 0 cellsOffset represented sp legalHigh effective
        helper cells current (scalar sp)

end KProgFormal.ClightRefinement.X86RegisterReadNumeric
