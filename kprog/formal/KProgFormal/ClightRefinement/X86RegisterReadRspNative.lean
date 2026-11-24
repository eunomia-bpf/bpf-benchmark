import KProgFormal.ClightRefinement.X86RegisterReadRspCall

namespace KProgFormal.ClightRefinement.X86RegisterReadRspNative

/-- RSP's represented native word is raw+stack origin for every initial tag.
The scalar raw word is derived from the actual row load and ValueRep. -/
theorem native_word (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu) (offset : BitVec 64)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base cpu)
    (current : CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some (.Vlong offset)) :
    cpu.regs.get (X86.GPR.ofIndex (4 : Fin 16)) = offset + origins.stack := by
  obtain ⟨word, raw, tag, wordRead, _, valueRep, native⟩ := represented (4 : Fin 16)
  have wordEq : word = .Vlong offset := Option.some.inj (wordRead.symm.trans current)
  have rawEq : raw = offset := by simpa only [wordEq, Arm64Registers.ValueRep] using valueRep
  simpa [Reference.Provenance.X86.materialize, rawEq] using native

/-- A complete genuine RSP reader call returns the existing native register
view for every width. Its initial native-base read is the SAME stack origin
used by the shared register relation; no independent result equality is assumed. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (memory : CC.Mem) (k : CC.Cont) (cpu : X86.Cpu) (size : X86.Size) (width : BitVec 8)
    (offset : BitVec 64) (helperBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong offset))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack)) :
    InternalRun ge (X86RegisterReadRspCall.length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock 0) (4#8) width (0#8)) k memory)
      (.Returnstate (.Vlong (cpu.getReg size (X86.GPR.ofIndex (4 : Fin 16)) false))
        (CC.callCont k) memory) := by
  have word := native_word addresses origins memory cellsBlock cellsOffset cpu offset represented current
  have result : X86RegisterReadLanes.result (offset + origins.stack) size (0#8) =
      cpu.getReg size (X86.GPR.ofIndex (4 : Fin 16)) false := by
    rw [X86.Cpu.getReg, word]
    simp [X86RegisterReadLanes.result]
  simpa only [result] using X86RegisterReadRspCall.call ge layout valueLayout memory k
    width (0#8) size offset origins.stack helperBlock bindingBlock cellsBlock baseBlock
    cellsOffset baseOffset (by decide) effective helper cells current header native

end KProgFormal.ClightRefinement.X86RegisterReadRspNative
