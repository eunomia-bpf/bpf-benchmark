import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent
import KProgFormal.ClightRefinement.Arm64MemcpyDestinationRoute

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadCaller

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyPointerRoute.loss)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Sloop 2 do
      throwError "original memcpy loss loop changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_loss_body actual.getAppArgs[0]!

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 body .Sbreak (Arm64MemcpyDestinationTag.continuation k)

def temps (saved : CC.TempEnv) (word : BitVec 64) : CC.TempEnv :=
  (saved.set Arm64Program._t'29 (.Vlong word)).set Arm64Program.___a64_loss_value (.Vlong word)

private theorem kept (le : CC.TempEnv) (word : BitVec 64) (id : CC.Ident)
    (valueOther : Arm64Program.___a64_loss_value ≠ id) (resultOther : Arm64Program._t'29 ≠ id) :
    (temps le word).get id = le.get id := by
  simp only [temps,CC.PTree.gso _ _ _ _ valueOther,CC.PTree.gso _ _ _ _ resultOther]

private def retain {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le nextLe : CC.TempEnv} {n : Nat}
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m le)
    (same : ∀ id ∈ [Arm64Program._entry,Arm64Program.___a64_lib_len,
      Arm64Program.___a64_lib_i,Arm64Program.___a64_lib_src_tag], nextLe.get id = le.get id) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m nextLe :=
  ⟨prior.packet,prior.callee,(same Arm64Program._entry (by decide +kernel)).trans prior.entryRead,
    (same Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length,
    (same Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter,
    (same Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag,prior.copied⟩

private theorem input_names : ∀ id ∈ [Arm64Program._entry,Arm64Program.___a64_lib_len,
      Arm64Program.___a64_lib_i,Arm64Program.___a64_lib_src_tag],
    Arm64Program.___a64_loss_width ≠ id ∧ Arm64Program.___a64_loss_off ≠ id ∧
    Arm64Program.___a64_loss_value ≠ id ∧ Arm64Program._t'29 ≠ id := by decide +kernel

set_option hygiene false in
private theorem resume (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (word : BitVec 64) :
    InternalRun world 4
      (.Returnstate (.Vlong word) (.Kcall (some Arm64Program._t'29) handler e le
        (Arm64MemcpyReadCall.continuation (Arm64MemcpyDestinationTag.continuation k))) m)
      (.State handler Arm64MemcpyReadCall.store (continuation k) e (temps le word) m) := by
  run_tac do
    let proof ← Lean.Elab.Term.elabTerm
      (← `(Arm64MemcpyReadCall.resume e le m (Arm64MemcpyDestinationTag.continuation k) word)) none
    (← Lean.Elab.Tactic.getMainGoal).assign proof
    Lean.Elab.Tactic.replaceMainGoal []

/-- Actual saved reader return restores the original memcpy frame and
copies the source word into its genuine destination-store inputs. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyReadCall.store (continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      nextLe.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64) + BitVec.ofNat 64 i.val)) ∧
      nextLe.get Arm64Program.___a64_loss_width = some (.Vint 1) ∧
      nextLe.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)) ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨destLe,destCurrent,off,raw,destRun⟩ :=
    Arm64MemcpyDestinationRoute.destination (Arm64MemcpySource.allocation calleeBefore).1 le k i current
  let saved := Arm64MemcpyReadCall.temps destLe (-16#64) (BitVec.ofNat 64 i.val)
  have savedSame (id : CC.Ident) (member : id ∈ [Arm64Program._entry,Arm64Program.___a64_lib_len,
      Arm64Program.___a64_lib_i,Arm64Program.___a64_lib_src_tag]) : saved.get id = destLe.get id := by
    have other := input_names id member
    simp only [saved,Arm64MemcpyReadCall.temps,CC.PTree.gso _ _ _ _ other.1,
      CC.PTree.gso _ _ _ _ other.2.1]
  let savedCurrent := retain destCurrent savedSame
  let callK := Arm64MemcpyReadCall.continuation (Arm64MemcpyDestinationTag.continuation k)
  let readerK := CC.Cont.Kcall (some Arm64Program._t'29) handler
    (Arm64MemcpySource.allocation calleeBefore).1 saved callK
  have setupRun := Arm64MemcpyReadCall.enter (Arm64MemcpySource.allocation calleeBefore).1 destLe before
    (Arm64MemcpyDestinationTag.continuation k) (-16#64) (BitVec.ofNat 64 i.val) raw off
  have callRun : InternalRun world 1
      (.State handler Arm64MemcpyReadCall.call callK (Arm64MemcpySource.allocation calleeBefore).1 saved before)
      (.Callstate (.Internal Arm64MemcpyReadCall.reader)
        (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val)) readerK before) :=
    .step (by rw [Arm64MemcpyReadCall.call_source]; trivial)
      (Arm64MemcpyReadCall.call_step calleeBefore before entry.block (BitVec.ofNat 64 i.val) saved callK
        savedCurrent.entryRead savedCurrent.counter) (.refl _)
  obtain ⟨after,readerCurrent,_freed,readerRun,frame,flagAfter,_advanced,pbound,cbound⟩ :=
    Arm64MemcpyReadCurrent.execute i readerK savedCurrent producerBound callerBound flag
  let nextLe := temps saved (byte.setWidth 64)
  have nextSame (id : CC.Ident) (member : id ∈ [Arm64Program._entry,Arm64Program.___a64_lib_len,
      Arm64Program.___a64_lib_i,Arm64Program.___a64_lib_src_tag]) : nextLe.get id = saved.get id :=
    kept saved (byte.setWidth 64) id (input_names id member).2.2.1 (input_names id member).2.2.2
  let next := retain readerCurrent nextSame
  have resumed := resume (Arm64MemcpySource.allocation calleeBefore).1 saved after k (byte.setWidth 64)
  have actualReader : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64MemcpyReadCall.reader)
        (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val)) readerK before) CC.E0
      (.Returnstate (.Vlong (byte.setWidth 64)) readerK after) := by
    simpa only [readerK,CC.callCont] using readerRun
  refine ⟨after,nextLe,next,?_,?_,?_,?_,frame,flagAfter,pbound,cbound⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append,nextLe,readerK,callK] using
      star_trans destRun.sound (star_trans setupRun.sound
        (star_trans callRun.sound (star_trans actualReader resumed.sound)))
  · have savedOff : saved.get Arm64Program.___a64_loss_off =
        some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)) := by
      simp only [saved,Arm64MemcpyReadCall.temps,
        CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program.___a64_loss_width ≠ Arm64Program.___a64_loss_off),
        CC.PTree.gss]
    exact (kept saved (byte.setWidth 64) _ (by decide +kernel) (by decide +kernel)).trans savedOff
  · have savedWidth : saved.get Arm64Program.___a64_loss_width = some (.Vint 1) := CC.PTree.gss _ _ _
    exact (kept saved (byte.setWidth 64) _ (by decide +kernel) (by decide +kernel)).trans savedWidth
  · exact CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpyReadCaller
