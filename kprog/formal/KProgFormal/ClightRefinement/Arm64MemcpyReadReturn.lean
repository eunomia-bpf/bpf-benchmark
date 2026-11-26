import KProgFormal.ClightRefinement.Arm64MemcpyReadReturnSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadReturn

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)
open Arm64MemcpyReadSource (allocation)

theorem locals_source : reader.fn_vars =
    [(Arm64Program.___kprog_c_load_value,CC.tulong),
     (Arm64Program.___kprog_c_load_value__1,CC.tuint),
     (Arm64Program.___kprog_c_load_value__2,CC.tushort),
     (Arm64Program.___kprog_c_load_value__3,CC.tuchar),
     (Arm64Program.___kprog_c_load_value__4,CC.tulong),
     (Arm64Program.___kprog_c_load_value__5,CC.tuint),
     (Arm64Program.___kprog_c_load_value__6,CC.tushort),
     (Arm64Program.___kprog_c_load_value__7,CC.tuchar),
     (Arm64Program.___kprog_c_load_value__8,CC.tptr CC.tvoid),
     (Arm64Program.___kprog_c_load_value__9,CC.tulong),
     (Arm64Program.___kprog_c_load_value__10,CC.tuint),
     (Arm64Program.___kprog_c_load_value__11,CC.tushort),
     (Arm64Program.___kprog_c_load_value__12,CC.tuchar)] := rfl

/-- The actual PTree-enumerated thirteen local ranges are freed by the
original source return, preserving older memory contents and permissions. -/
structure FreeResult (before current after : CC.Mem) : Prop where
  freed : CC.Mem.freeList current (CC.blocksOfEnv world.genv_cenv (allocation before).1) = some after
  caller : FrameBelow before.nextblock current after
  contents : after.contents = current.contents
  nextblock : after.nextblock = current.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (allocation before).1, ∀ ofs,
    row.2.1 ≤ ofs → ofs < row.2.2 → ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false

/-- Allocation gives every real scratch range its actual Freeable rights.
The selected byte-read body keeps the same access map, so imported local
free semantics constructs a real output and retains the full caller frame. -/
theorem free (before current : CC.Mem)
    (access : current.access = (allocation before).2.access) :
    ∃ after, FreeResult before current after := by
  have owned (id : CC.Ident) (value : CC.Block × CC.Ty)
      (binding : (allocation before).1.get id = some value) :
      CC.Mem.rangePerm current value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true :=
    (CC.Mem.rangePerm_congr (m1 := current) (m2 := (allocation before).2)
      (fun ofs => by simp only [CC.Mem.perm,access])).trans
        (((allocated_local_storage (Arm64MemcpyReadSource.allocated before)).1 id value binding).2.2)
  obtain ⟨after,freed,frame,contents,next,released⟩ := deallocate_live_locals (Arm64MemcpyReadSource.allocated before) owned
  exact ⟨after,freed,frame,contents,next,released⟩

/-- Follow the genuine value-return statement and actual thirteen-object
freeList to the original Returnstate. The call continuation is imported. -/
theorem exit (before current : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (access : current.access = (allocation before).2.access)
    (read : le.get Arm64Program._result = some (.Vlong value)) :
    ∃ after, FreeResult before current after ∧ InternalRun world 1
      (.State reader Arm64MemcpyReadSource.result k (allocation before).1 le current)
      (.Returnstate (.Vlong value) (CC.callCont k) after) := by
  obtain ⟨after,result⟩ := free before current access
  refine ⟨after,result,?_⟩
  rw [Arm64MemcpyReadReturnSource.source.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [CC.doStep,CC.doEvalExpr,read,result.freed]
  rfl

/-- On the actual unchanged reader heap, both its real allocation and local
free compose below the original caller frontier. -/
theorem original_frame (before after : CC.Mem)
    (result : FreeResult before (allocation before).2 after) :
    FrameBelow before.nextblock before after :=
  (Arm64MemcpyReadSource.entry_frame before).trans result.caller

end KProgFormal.ClightRefinement.Arm64MemcpyReadReturn
