import KProgFormal.ClightRefinement.X86RegisterReadValue

namespace KProgFormal.ClightRefinement.X86RegisterWriterInputs

/-- Every represented union value is a real scalar word or bound pointer;
the original pointer-copy and pointer-to-long casts retain that Clight value. -/
theorem casts (addresses : Arm64Registers.PointerOrigins) (value : CC.Val)
    (raw : BitVec 64) (memory : CC.Mem) (represented : Arm64Registers.ValueRep addresses value raw) :
    CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory = some value ∧
    CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong memory = some value := by
  cases value <;> simp only [Arm64Registers.ValueRep] at represented
  all_goals first | contradiction | exact ⟨rfl, rfl⟩

/-- The whole-register relation supplies the exact real destination cell/tag
and the source copy cast; no scalar/tag0 restriction is needed for overwrite. -/
theorem cell (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base cpu)
    (index : Fin 16) :
    ∃ (value : CC.Val) (tag : BitVec 8),
      CC.Mem.load CC.Mptr memory block
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) = some value ∧
      CC.Mem.load .Mint8unsigned memory block
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (tag.setWidth 32)) ∧
      CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory = some value := by
  obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, _⟩ := represented index
  exact ⟨value, tag, wordRead, tagRead, (casts addresses value raw memory valueRep).1⟩

/-- The actual writer's old-SP read and cast follow from register4 of the
same relation, including a represented pointer. No numerical shift is used. -/
theorem stack (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory block base cpu) :
    ∃ value, CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some value ∧
      CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong memory = some value := by
  obtain ⟨value, raw, tag, wordRead, _, valueRep, _⟩ := represented (4 : Fin 16)
  exact ⟨value, wordRead, (casts addresses value raw memory valueRep).2⟩

end KProgFormal.ClightRefinement.X86RegisterWriterInputs
