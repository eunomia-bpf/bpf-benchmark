import KProgFormal.ClightRefinement.Arm64SelectDispatch

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Body

private theorem leave_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    rfl
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    rfl
  exact .refl _

/-- The whole original CSEL64 EQ body, from its true loop entry through the
linked width helper, all dispatch gates, condition/read/writeback and loop exit.
This retains the real generic frame; allocation and release are caller work. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthNameFree : e.get Arm64Program._arm64_width_effective = none)
    (conditionNameFree : e.get Arm64Program._kprog_arm64_program_condition = none)
    (pathNameFree : e.get Arm64Program._kprog_arm64_csel_path = none)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (left : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 lhs.val)))
    (right : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 rhs.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (op : le.get Arm64Program._op = some (.Vint (28#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields dst lhs rhs (0#4))))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ count value raw tag after le',
      Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0)
        (if ConditionHolds (0#4) native.machine then lhs else rhs).val =
          some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Arm64PointerWrite.ValueResult storage dst value tag after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step native).state ∧
      Arm64CacheLocalFrame.Kept initial m after dst ∧
      Reference.AArch64.step native =
        ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
          (Arm64PointerWrite.nativeUpdate origins native dst raw tag), [], none⟩ := by
  obtain ⟨count,selected,dispatch,width,kept⟩ := Dispatch.body_dispatch e le m k widthNameFree flags op
  have entry' := (kept Arm64Program._entry (by simp)).trans entryRead
  have dst' := (kept Arm64Program._dst (by simp)).trans destination
  have left' := (kept Arm64Program._src (by simp)).trans left
  have right' := (kept Arm64Program._src2 (by simp)).trans right
  have aux' := (kept Arm64Program._aux (by simp)).trans aux
  have op' := (kept Arm64Program._op (by simp)).trans op
  obtain ⟨value,raw,tag,after,read,bits,result,bodyRun,registers,locals,step⟩ := eq_write_matches
    storage addresses origins native instruction dst lhs rhs represented e selected (Dispatch.continuation k)
    conditionNameFree pathNameFree pointerNameFree tagNameFree writerNameFree
    entry' left' right' dst' aux' op' width decoded noError fetched
  have returned := leave_loop e
    (Branch.temps (ConditionHolds (0#4) native.machine) (eqTemps storage selected native) value tag) after k
  refine ⟨_,value,raw,tag,after,_,read,bits,result,(dispatch.trans bodyRun).trans returned,?_,locals,step⟩
  rw [step]
  exact (Arm64Registers.cursor after (.Vptr entry.block 0)
    (Arm64PointerWrite.nativeUpdate origins native dst raw tag) (read_pc native.machine + 4#64)).mpr registers

end KProgFormal.ClightRefinement.Arm64Select.Body
