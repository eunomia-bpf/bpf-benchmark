import KProgFormal.ClightRefinement.Arm64MemcpyStoreAction
import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStorePrefix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

def offset (i : Fin 16) : BitVec 64 := (-16#64)+BitVec.ofNat 64 i.val
def temps (le : CC.TempEnv) (byte : BitVec 8) (i : Fin 16) : CC.TempEnv :=
  Arm64MemcpyStoreAction.temps
    (Arm64MemcpyStoreMask.temps (Arm64MemcpyStoreIndex.temps le (offset i)) (byte.setWidth 64)) i

private theorem mask_kept (le : CC.TempEnv) (word : BitVec 64) (id : CC.Ident)
    (valueOther : Arm64Program.___a64_stw_value ≠ id) (maskOther : Arm64Program._t'30 ≠ id)
    (widthOther : Arm64Program.___a64_stw_width ≠ id) :
    (Arm64MemcpyStoreMask.temps le word).get id = le.get id := by
  simp only [Arm64MemcpyStoreMask.temps,CC.PTree.gso _ _ _ _ valueOther,
    CC.PTree.gso _ _ _ _ maskOther,CC.PTree.gso _ _ _ _ widthOther]

theorem outputs (le : CC.TempEnv) (byte : BitVec 8) (i : Fin 16) :
    (temps le byte i).get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))) ∧
    (temps le byte i).get Arm64Program.___a64_stw_width = some (.Vint 1) ∧
    (temps le byte i).get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)) := by
  let indexed := Arm64MemcpyStoreIndex.temps le (offset i)
  let masked := Arm64MemcpyStoreMask.temps indexed (byte.setWidth 64)
  have indexRead : indexed.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))) := by
    have actual : indexed.get Arm64Program.___a64_stw_index = some (.Vlong ((96#64)+offset i)) := CC.PTree.gss _ _ _
    simpa only [offset,Arm64MemcpyStoreIndex.physical_index i] using actual
  have maskedIndex : masked.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))) :=
    (mask_kept indexed (byte.setWidth 64) _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans indexRead
  have observed := Arm64MemcpyStoreMask.observations indexed byte
  refine ⟨?_,?_,?_⟩
  · exact (Arm64MemcpyStoreAction.kept masked i _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans maskedIndex
  · exact (Arm64MemcpyStoreAction.kept masked i _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans observed.1
  · exact (Arm64MemcpyStoreAction.kept masked i _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans observed.2

/-- The same original store executes real bias/index, width/mask/value and
alignment/action controls, retaining the true source81 continuation. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry : CC.Block) (byte : BitVec 8) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (offset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 38 (.State handler Arm64MemcpyReadCall.store k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81 (Arm64MemcpyStoreIndex.continuation k)
        e (temps le byte i) m) := by
  let indexed := Arm64MemcpyStoreIndex.temps le (offset i)
  let masked := Arm64MemcpyStoreMask.temps indexed (byte.setWidth 64)
  have width := (Arm64MemcpyStoreIndex.kept le (offset i) _ (by decide +kernel) (by decide +kernel)).trans hwidth
  have value := (Arm64MemcpyStoreIndex.kept le (offset i) _ (by decide +kernel) (by decide +kernel)).trans hvalue
  have indexRead : indexed.get Arm64Program.___a64_stw_index = some (.Vlong (Arm64MemcpyStoreAction.index i)) := by
    have actual : indexed.get Arm64Program.___a64_stw_index = some (.Vlong ((96#64)+offset i)) := CC.PTree.gss _ _ _
    simpa only [offset,Arm64MemcpyStoreIndex.physical_index i,Arm64MemcpyStoreAction.index] using actual
  have maskedIndex := (mask_kept indexed (byte.setWidth 64) Arm64Program.___a64_stw_index
    (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans indexRead
  have stepIndex := Arm64MemcpyStoreIndex.execute e le m k entry (offset i) hentry bias hoff
  have stepMask := Arm64MemcpyStoreMask.execute e indexed m (Arm64MemcpyStoreIndex.continuation k) (byte.setWidth 64) width value
  have stepAction := Arm64MemcpyStoreAction.execute e masked m (Arm64MemcpyStoreIndex.continuation k) i
    (Arm64MemcpyStoreMask.observations indexed byte).1 maskedIndex
  exact (stepIndex.trans stepMask).trans stepAction

private def changed : List CC.Ident :=
  [Arm64Program.___a64_stw_index,Arm64Program._t'158,Arm64Program.___a64_stw_width,
   Arm64Program._t'30,Arm64Program.___a64_stw_value,Arm64Program.___a64_stw_action,
   Arm64Program._t'32,Arm64Program._t'33,Arm64Program._t'31]
theorem kept (le : CC.TempEnv) (byte : BitVec 8) (i : Fin 16) (id : CC.Ident) (other : id ∉ changed) :
    (temps le byte i).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  let indexed := Arm64MemcpyStoreIndex.temps le (offset i)
  let masked := Arm64MemcpyStoreMask.temps indexed (byte.setWidth 64)
  have first := Arm64MemcpyStoreIndex.kept le (offset i) id
    (different _ (by decide +kernel)) (different _ (by decide +kernel))
  have second := mask_kept indexed (byte.setWidth 64) id
    (different _ (by decide +kernel)) (different _ (by decide +kernel)) (different _ (by decide +kernel))
  have third := Arm64MemcpyStoreAction.kept masked i id
    (different _ (by decide +kernel)) (different _ (by decide +kernel))
    (different _ (by decide +kernel)) (different _ (by decide +kernel))
  exact third.trans (second.trans first)

/-- The actual current store inputs supply the original prefix, retaining
its same complete packet and eight caller-local rights on the same heap. -/
def current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv} (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m le) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m (temps le byte i) := by
  refine ⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩
  · exact (kept le byte i Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le byte i Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le byte i Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le byte i Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyStorePrefix
