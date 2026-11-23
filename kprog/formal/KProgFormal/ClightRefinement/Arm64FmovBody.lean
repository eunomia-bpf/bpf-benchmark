import KProgFormal.ClightRefinement.Arm64FmovDispatch

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Body

def inputs : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
   Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,Arm64Program._imm]

private theorem path_input (id : CC.Ident) (inside : id ∈ inputs) : id ∈ ReadOperands.inputs := by
  simp only [inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
  rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals decide +kernel

private theorem leave_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  exact .refl _

/-- Execute the original complete FMOV64 body: true linked width helper,
all actual dispatch gates, both reads, numerical work, destination helper,
both actual vector writes and the original outer-loop exit. -/
theorem execute {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (writable : Arm64VectorWritable.Writable old.vectors before) (i : Fin 31)
    (oldLow value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (reader : e.get Arm64Program._kprog_arm64_program_read = none)
    (destination : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (op : le.get Arm64Program._op = some (.Vint (35#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (oldVector : CC.Mem.load .Mint64 before old.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ count after le', VectorMemory.Effect before after old.vectors.block value ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le before)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  obtain ⟨dispatchCount,dispatched,dispatch,width,kept⟩ := Dispatch.body_dispatch e le before k widthFree flags op
  obtain ⟨after,le',pathCount,path,effect,afterWritable,pathKept⟩ :=
    Path.execute old writable i oldLow value e dispatched (Dispatch.continuation k) reader destination
      ((kept _ (by simp)).trans entryRead) ((kept _ (by simp)).trans index)
      ((kept _ (by simp)).trans source) ((kept _ (by simp)).trans aux) oldVector word tag
  refine ⟨_,after,le',effect,afterWritable,(dispatch.trans path).trans (leave_loop e le' after k),?_⟩
  intro id inside
  exact (pathKept id (path_input id inside)).trans (kept id inside)

end KProgFormal.ClightRefinement.Arm64Fmov.Body
