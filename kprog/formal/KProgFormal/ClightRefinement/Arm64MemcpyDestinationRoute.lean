import KProgFormal.ClightRefinement.Arm64MemcpyReadSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyDestinationRoute

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private def inputKey (j : Fin 5) : CC.Ident :=
  [Arm64Program._entry,Arm64Program.___a64_lib_i,Arm64Program.___a64_lib_len,
    Arm64Program.___a64_lib_src_tag,Arm64Program.___a64_mwr_off][j.val]

private def changed : List CC.Ident :=
  [Arm64Program.___a64_mwr_arm,Arm64Program._t'20,Arm64Program._t'19,
    Arm64Program._t'71,Arm64Program._t'180,Arm64Program._t'179,
    Arm64Program.___a64_mwr_base,Arm64Program._t'164,Arm64Program.___a64_mwr_bsrc,Arm64Program._t'27,
    Arm64Program.___a64_mwr_pointer,Arm64Program._t'28,Arm64Program._t'161,Arm64Program._t'160,
    Arm64Program._t'159,Arm64Program.___a64_l_reg__6]

private theorem separate : ∀ j : Fin 5, inputKey j ∉ changed := by decide +kernel

private def afterAbiTemps (le : CC.TempEnv) (sp : CC.Block) (spValue : BitVec 64)
    (table cell : CC.Block) : CC.TempEnv :=
  Arm64MemcpyPointerRoute.temps
    (Arm64MemcpyPointerRoute.readTemps
      (Arm64MemcpyPointerRoute.regTemps (Arm64MemcpyStackRoute.temps le sp spValue)) table cell (-16#64)) (-16#64)

private def afterTagTemps (le : CC.TempEnv) (flag sp : CC.Block) (spValue : BitVec 64)
    (table cell : CC.Block) : CC.TempEnv :=
  afterAbiTemps (Arm64MemcpyAbiRead.temps (Arm64MemcpyArmSelect.temps le) flag (2#8)) sp spValue table cell

private theorem kept_keys (le : CC.TempEnv) (flag sp : CC.Block) (spValue : BitVec 64)
    (table cell : CC.Block) :
    ∀ j : Fin 5, (afterTagTemps le flag sp spValue table cell).get (inputKey j) = le.get (inputKey j) := by
  let armTemps := Arm64MemcpyArmSelect.temps le
  let abiTemps := Arm64MemcpyAbiRead.temps armTemps flag (2#8)
  let spTemps := Arm64MemcpyStackRoute.temps abiTemps sp spValue
  intro j
  have diff (id : CC.Ident) (member : id ∈ changed) : id ≠ inputKey j := by
    intro same
    exact separate j (same ▸ member)
  have d_base : Arm64Program.___a64_mwr_base ≠ inputKey j := diff Arm64Program.___a64_mwr_base (by decide +kernel)
  have d_pointer : Arm64Program.___a64_mwr_pointer ≠ inputKey j := diff Arm64Program.___a64_mwr_pointer (by decide +kernel)
  have d_copy : Arm64Program._t'28 ≠ inputKey j := diff Arm64Program._t'28 (by decide +kernel)
  have d_word : Arm64Program._t'161 ≠ inputKey j := diff Arm64Program._t'161 (by decide +kernel)
  have d_cell : Arm64Program._t'160 ≠ inputKey j := diff Arm64Program._t'160 (by decide +kernel)
  have d_table : Arm64Program._t'159 ≠ inputKey j := diff Arm64Program._t'159 (by decide +kernel)
  have d_selector : Arm64Program.___a64_l_reg__6 ≠ inputKey j := diff Arm64Program.___a64_l_reg__6 (by decide +kernel)
  have d_spPointer : Arm64Program._t'164 ≠ inputKey j := diff Arm64Program._t'164 (by decide +kernel)
  have d_bsrc : Arm64Program.___a64_mwr_bsrc ≠ inputKey j := diff Arm64Program.___a64_mwr_bsrc (by decide +kernel)
  have d_spChoice : Arm64Program._t'27 ≠ inputKey j := diff Arm64Program._t'27 (by decide +kernel)
  have d_abiCondition : Arm64Program._t'71 ≠ inputKey j := diff Arm64Program._t'71 (by decide +kernel)
  have d_abiByte : Arm64Program._t'180 ≠ inputKey j := diff Arm64Program._t'180 (by decide +kernel)
  have d_abiPointer : Arm64Program._t'179 ≠ inputKey j := diff Arm64Program._t'179 (by decide +kernel)
  have d_arm : Arm64Program.___a64_mwr_arm ≠ inputKey j := diff Arm64Program.___a64_mwr_arm (by decide +kernel)
  have d_second : Arm64Program._t'20 ≠ inputKey j := diff Arm64Program._t'20 (by decide +kernel)
  have d_first : Arm64Program._t'19 ≠ inputKey j := diff Arm64Program._t'19 (by decide +kernel)
  have pointerKept := Arm64MemcpyPointerRoute.kept spTemps table
    cell (-16#64) (inputKey j)
    d_base d_pointer d_copy d_word d_cell d_table d_selector
  have spKept := Arm64MemcpyStackRoute.kept abiTemps sp spValue (inputKey j)
    d_base d_spPointer d_bsrc d_spChoice
  have abiKept := Arm64MemcpyAbiRead.kept armTemps flag (2#8) (inputKey j)
    d_abiCondition d_abiByte d_abiPointer
  have armKept := Arm64MemcpyArmSelect.kept le (inputKey j) d_arm d_second d_first
  exact pointerKept.trans (spKept.trans (abiKept.trans armKept))

private theorem stack_binding : Arm64MemcpyAbiRead.stack = Arm64Program.s_kprog_arm64_program_memcpy_108 := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem run_after_abi {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (arm : le.get Arm64Program.___a64_mwr_arm = some (.Vint 0))
    (r0 : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong (-16#64),.Vint ((4#8).setWidth 32))) :
    InternalRun world 44 (.State handler Arm64MemcpyAbiRead.stack k e le m)
      (.State handler Arm64MemcpyPointerRoute.loss k e
        (afterAbiTemps le storage.sp.block storage.spValue
          (storage.tables false).tableBlock ((storage.tables false).cellBlock 0)) m) := by
  rw [stack_binding]
  let actualTemps := Arm64MemcpyStackRoute.temps le storage.sp.block storage.spValue
  have spRun := Arm64MemcpyStackRoute.execute storage e le k hentry arm
  have spEntry : actualTemps.get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (Arm64MemcpyStackRoute.kept le storage.sp.block storage.spValue _
      (by decide) (by decide) (by decide) (by decide)).trans hentry
  have pointerRun := Arm64MemcpyPointerRoute.execute storage (-16#64) (4#8) e actualTemps k spEntry
    (Arm64MemcpyStackRoute.outputs le storage.sp.block storage.spValue).2 r0
  exact spRun.trans pointerRun

section Current
variable {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

private def retain {le nextLe : CC.TempEnv} {n : Nat}
    (packet : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m le)
    (entryRead : nextLe.get Arm64Program._entry = some (.Vptr entry.block 0))
    (counter : nextLe.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 n)))
    (length : nextLe.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (sourceTag : nextLe.get Arm64Program.___a64_lib_src_tag = some (.Vint ((4#8).setWidth 32))) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m nextLe :=
  ⟨packet.packet,packet.callee,entryRead,length,counter,sourceTag,packet.copied⟩

/-- The same reached iteration executes all actual destination setup, tag,
arm, ABI, SP and R0 paths before its source-byte call. Every current packet
observation, live callee range and copied-byte observation stays on this heap. -/
theorem destination (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (packet : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m le) :
    ∃ nextLe, ∃ _current :
      Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m nextLe,
      nextLe.get Arm64Program.___a64_mwr_off = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
      nextLe.get Arm64Program.___a64_mwr_base = some (.Vlong (-16#64)) ∧
      InternalRun world 172 (.State handler Arm64MemcpyLoop.write k e le m)
        (.State handler Arm64MemcpyPointerRoute.loss (Arm64MemcpyDestinationTag.continuation k) e nextLe m) := by
  let storage := packet.packet.storage
  let tagged := Arm64MemcpyDestinationTag.finalTemps (Arm64MemcpyStackSetup.temps le (BitVec.ofNat 64 i.val))
    (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) (4#8)
  let armTemps := Arm64MemcpyArmSelect.temps tagged
  let abiTemps := Arm64MemcpyAbiRead.temps armTemps abi.block (2#8)
  let spTemps := Arm64MemcpyStackRoute.temps abiTemps storage.sp.block storage.spValue
  let nextLe := Arm64MemcpyPointerRoute.temps
    (Arm64MemcpyPointerRoute.readTemps (Arm64MemcpyPointerRoute.regTemps spTemps)
      (storage.tables false).tableBlock ((storage.tables false).cellBlock 0) (-16#64)) (-16#64)
  have inputs := Arm64MemcpyDestinationTag.inputs le (BitVec.ofNat 64 i.val)
    (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) (4#8)
  have actualEntry : abiTemps.get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (Arm64MemcpyAbiRead.kept armTemps abi.block (2#8) _ (by decide) (by decide) (by decide)).trans
      ((Arm64MemcpyArmSelect.kept tagged _ (by decide) (by decide) (by decide)).trans
        (inputs.1.trans packet.entryRead))
  have actualArm : abiTemps.get Arm64Program.___a64_mwr_arm = some (.Vint 0) := by
    rw [show abiTemps.get Arm64Program.___a64_mwr_arm = armTemps.get Arm64Program.___a64_mwr_arm from
      Arm64MemcpyAbiRead.kept armTemps abi.block (2#8) _ (by decide) (by decide) (by decide)]
    exact CC.PTree.gss _ _ _
  have prefixRun := Arm64MemcpyAbiRead.current e le k i packet
  have postRun := run_after_abi storage e abiTemps (Arm64MemcpyDestinationTag.continuation k)
    actualEntry actualArm packet.packet.r0
  have keep := kept_keys tagged abi.block storage.sp.block storage.spValue
    (storage.tables false).tableBlock ((storage.tables false).cellBlock 0)
  have current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m nextLe :=
    retain packet
      ((keep 0).trans (inputs.1.trans packet.entryRead))
      ((keep 1).trans (inputs.2.1.trans packet.counter))
      ((keep 2).trans (inputs.2.2.1.trans packet.length))
      ((keep 3).trans (inputs.2.2.2.1.trans packet.sourceTag))
  refine ⟨nextLe,current,(keep 4).trans inputs.2.2.2.2.1,?_,?_⟩
  · exact CC.PTree.gss _ _ _
  · exact prefixRun.trans postRun

/-- Destination work and the real seven-argument nested call execute in the
original order. The same complete iteration packet and all eight callee
ranges describe the actual saved memcpy caller at reader entry. -/
theorem reader_call (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (packet : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m le) :
    ∃ savedLe, ∃ _current :
      Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m savedLe,
      InternalRun world 182
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.Callstate (.Internal Arm64MemcpyReadCall.reader)
          (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val))
          (.Kcall (some Arm64Program._t'29) handler (Arm64MemcpySource.allocation calleeBefore).1 savedLe
            (Arm64MemcpyReadCall.continuation (Arm64MemcpyDestinationTag.continuation k))) m) := by
  obtain ⟨nextLe,current,off,raw,prefixRun⟩ := destination (Arm64MemcpySource.allocation calleeBefore).1 le k i packet
  let savedLe := Arm64MemcpyReadCall.temps nextLe (-16#64) (BitVec.ofNat 64 i.val)
  have retain (key : CC.Ident) (widthOther : Arm64Program.___a64_loss_width ≠ key)
      (offsetOther : Arm64Program.___a64_loss_off ≠ key) : savedLe.get key = nextLe.get key := by
    simp only [savedLe,Arm64MemcpyReadCall.temps,CC.PTree.gso _ _ _ _ widthOther,
      CC.PTree.gso _ _ _ _ offsetOther]
  have nextPacket : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m savedLe := {
    packet := current.packet
    callee := current.callee
    copied := current.copied
    entryRead := (retain _ (by decide) (by decide)).trans current.entryRead
    counter := (retain _ (by decide) (by decide)).trans current.counter
    length := (retain _ (by decide) (by decide)).trans current.length
    sourceTag := (retain _ (by decide) (by decide)).trans current.sourceTag }
  have setup := Arm64MemcpyReadCall.enter (Arm64MemcpySource.allocation calleeBefore).1 nextLe m
    (Arm64MemcpyDestinationTag.continuation k) (-16#64) (BitVec.ofNat 64 i.val) raw off
  have call : InternalRun world 1
      (.State handler Arm64MemcpyReadCall.call
        (Arm64MemcpyReadCall.continuation (Arm64MemcpyDestinationTag.continuation k))
        (Arm64MemcpySource.allocation calleeBefore).1 savedLe m)
      (.Callstate (.Internal Arm64MemcpyReadCall.reader)
        (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val))
        (.Kcall (some Arm64Program._t'29) handler (Arm64MemcpySource.allocation calleeBefore).1 savedLe
          (Arm64MemcpyReadCall.continuation (Arm64MemcpyDestinationTag.continuation k))) m) :=
    .step (by rw [Arm64MemcpyReadCall.call_source]; trivial)
      (Arm64MemcpyReadCall.call_step calleeBefore m entry.block (BitVec.ofNat 64 i.val) savedLe _
        nextPacket.entryRead nextPacket.counter) (.refl _)
  exact ⟨savedLe,nextPacket,prefixRun.trans (setup.trans call)⟩

end Current
end KProgFormal.ClightRefinement.Arm64MemcpyDestinationRoute
