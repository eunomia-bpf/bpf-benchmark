import KProgFormal.ClightRefinement.X86ProducerPushLocalFrame
import KProgFormal.ClightRefinement.X86PushReference

namespace KProgFormal.ClightRefinement.X86ProducerScalarView

/-- The original source flag-object order, projected from the existing
native flag record. RFLAGS bit interpretation remains in the reference. -/
def flag (cpu : X86.Cpu) (index : Fin 6) : Bool :=
  [cpu.flags.cf,cpu.flags.zf,cpu.flags.sf,cpu.flags.of,cpu.flags.pf,cpu.flags.af][index.val]!

structure Represents {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (memory : CC.Mem) (cpu : X86.Cpu) : Prop where
  flags : ∀ index : Fin 6, CC.Mem.load .Mint8unsigned memory (ready.scalars ⟨index.val,by omega⟩).block 0 =
    some (.Vint (if flag cpu index then 1 else 0))
  low : CC.Mem.load .Mint64 memory (ready.scalars 6).block 0 = some (.Vlong ((cpu.getXmm .x0).extractLsb' 0 64))
  high : CC.Mem.load .Mint64 memory (ready.scalars 7).block 0 = some (.Vlong ((cpu.getXmm .x0).extractLsb' 64 64))

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Genuine store/free frames preserve the same actual native scalar view;
initial platform-input correspondence is explicit rather than assumed from
provider determinacy or trace-length laws. -/
theorem preserve (complete : X86ProducerPushComplete.Result cache) (cpu : X86.Cpu)
    (initial : Represents ready ready.after cpu) : Represents ready complete.after cpu := by
  constructor
  · intro index
    let i : Fin 8 := ⟨index.val,by omega⟩
    have current := (X86ProducerPushLocalFrame.scalars complete i).trans (ready.scalar_reads i).symm
    have kind : X86ProducerScalarSource.chunk i = .Mint8unsigned := by
      simp only [X86ProducerScalarSource.chunk,i,show index.val < 6 from index.isLt,ite_true]
    rw [kind] at current
    exact current.trans (initial.flags index)
  · exact ((X86ProducerPushLocalFrame.scalars complete 6).trans (ready.scalar_reads 6).symm).trans initial.low
  · exact ((X86ProducerPushLocalFrame.scalars complete 7).trans (ready.scalar_reads 7).symm).trans initial.high

/-- The same source scalar view represents the EXACT canonical PUSH output,
whose native flags/vector frame was proved through original checked ISA. -/
theorem reference (complete : X86ProducerPushComplete.Result cache) (state : Reference.X86.State) (nextPc : BitVec 64)
    (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true)
    (initial : Represents ready ready.after (X86LogicReference.input state)) :
    Represents ready complete.after (X86LogicReference.input (Reference.X86.step (.push .w64 3 nextPc) state).state) := by
  rw [X86PushReference.step state nextPc running canonical writable]
  have current := preserve complete (X86LogicReference.input state) initial
  exact ⟨current.flags,current.low,current.high⟩

end KProgFormal.ClightRefinement.X86ProducerScalarView
