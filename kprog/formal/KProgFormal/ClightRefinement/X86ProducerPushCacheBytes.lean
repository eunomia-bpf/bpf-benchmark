import KProgFormal.ClightRefinement.X86ScalarStoreBytes
import KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheBytes

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Every actual written cache byte survives the genuine local free. -/
theorem written (complete : X86ProducerPushComplete.Result cache) (lane : Fin 8) :
    CC.Mem.load .Mint8unsigned complete.after (ready.sources 1).block (40 + lane.val) =
      some (.Vint (((ready.values 3 >>> (8 * lane.val)).setWidth 8).setWidth 32)) := by
  have old : (ready.sources 1).block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact (ready.sources 1).owned
  exact (complete.old_frame.load _ _ _ old).trans (X86ScalarStoreBytes.load cache.stored lane)

/-- The complete actual48-byte cache image: all40 lower observations are
preserved, and every selected byte is the real saved RBX payload. -/
theorem table (complete : X86ProducerPushComplete.Result cache) (byte : Fin 48) :
    CC.Mem.load .Mint8unsigned complete.after (ready.sources 1).block byte.val =
      if byte.val < 40 then CC.Mem.load .Mint8unsigned ready.after (ready.sources 1).block byte.val
      else some (.Vint (((ready.values 3 >>> (8 * (byte.val - 40))).setWidth 8).setWidth 32)) := by
  by_cases lower : byte.val < 40
  · rw [if_pos lower]
    exact X86ProducerPushCacheFrame.lower_bytes complete ⟨byte.val,lower⟩
  · rw [if_neg lower]
    have bound : byte.val - 40 < 8 := by have bound := byte.isLt; omega
    have offset : (byte.val : Int) = 40 + ((byte.val - 40 : Nat) : Int) := by omega
    simpa only [offset] using written complete ⟨byte.val - 40,bound⟩

/-- The actual written bytes have exactly the common native byte-list
projection of RBX, rather than an independent C-only serialization. -/
theorem native_payload (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu)
    (lane : Fin 8) :
    CC.Mem.load .Mint8unsigned complete.after (ready.sources 1).block (40 + lane.val) =
      some (.Vint (((Reference.valueBytes (cpu.regs.get (X86.GPR.ofIndex 3)) 8)[lane.val]!).setWidth 32)) := by
  have payload := X86ProducerPushNativeRegisters.payload complete addresses origins cpu represented
  have same : ready.values 3 = cpu.regs.get (X86.GPR.ofIndex 3) := by
    exact CC.Val.Vlong.inj (Option.some.inj (complete.word_read.symm.trans payload))
  simpa [Reference.valueBytes,lane.isLt,same] using written complete lane

end KProgFormal.ClightRefinement.X86ProducerPushCacheBytes
