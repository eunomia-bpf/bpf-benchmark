import KProgFormal.ClightRefinement.X86LogicFlagStores

namespace KProgFormal.ClightRefinement.X86LogicFlagOrder
open X86LogicFlagStores

structure Locations where
  cf : CC.Block × CC.Integers.Ptrofs
  zf : CC.Block × CC.Integers.Ptrofs
  sf : CC.Block × CC.Integers.Ptrofs
  overflow : CC.Block × CC.Integers.Ptrofs
  pf : CC.Block × CC.Integers.Ptrofs

/-- Actual initial pointer loads from the binding header. -/
structure HeaderLoads (m : CC.Mem) (bindingBlock : CC.Block) (places : Locations) : Prop where
  cf : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr places.cf.1 places.cf.2)
  zf : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr places.zf.1 places.zf.2)
  sf : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr places.sf.1 places.sf.2)
  overflow : CC.Mem.load CC.Mptr m bindingBlock 144 = some (.Vptr places.overflow.1 places.overflow.2)
  pf : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr places.pf.1 places.pf.2)

private theorem header_store {m after : CC.Mem} {bindingBlock target : CC.Block}
    {places : Locations} {offset : CC.Integers.Ptrofs} {byte : CC.Val}
    (headers : HeaderLoads m bindingBlock places)
    (separate : target ≠ bindingBlock)
    (stored : CC.Mem.store .Mint8unsigned m target (CC.Integers.Ptrofs.unsigned offset) byte = some after) :
    HeaderLoads after bindingBlock places := by
  exact ⟨(CC.Mem.load_store_other stored CC.Mptr bindingBlock 120 (.inl separate.symm)).trans headers.cf,
    (CC.Mem.load_store_other stored CC.Mptr bindingBlock 128 (.inl separate.symm)).trans headers.zf,
    (CC.Mem.load_store_other stored CC.Mptr bindingBlock 136 (.inl separate.symm)).trans headers.sf,
    (CC.Mem.load_store_other stored CC.Mptr bindingBlock 144 (.inl separate.symm)).trans headers.overflow,
    (CC.Mem.load_store_other stored CC.Mptr bindingBlock 152 (.inl separate.symm)).trans headers.pf⟩

private def body : CC.Stmt := .Ssequence cf (.Ssequence zf (.Ssequence sf ofStmt))

theorem source : X86LogicFlagWidths.rest = .Ssequence (.Sloop body .Sbreak) parity := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq parity k)

def temps (le : CC.TempEnv) (places : Locations) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf._t'206 (.Vptr places.cf.1 places.cf.2)).set
    X86_program_profile_bpf._t'205 (.Vptr places.zf.1 places.zf.2)).set
    X86_program_profile_bpf._t'204 (.Vptr places.sf.1 places.sf.2)).set
    X86_program_profile_bpf._t'203 (.Vptr places.overflow.1 places.overflow.2)).set
    X86_program_profile_bpf._t'202 (.Vptr places.pf.1 places.pf.2)

private theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 3 (.State function X86LogicFlagWidths.rest k e le m)
      (.State function cf (.Kseq (.Ssequence zf (.Ssequence sf ofStmt)) (continuation k)) e le m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, body, continuation, CC.doStep, CC.Eapp, CC.E0]

private theorem next_two (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (first next : CC.Stmt) :
    InternalRun ge 2 (.State function .Sskip (.Kseq (.Ssequence first next) k) e le m)
      (.State function first (.Kseq next k) e le m) := by
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]

private theorem next_one (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (next : CC.Stmt) :
    InternalRun ge 1 (.State function .Sskip (.Kseq next k) e le m)
      (.State function next k e le m) := by
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]

private theorem to_parity (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 3 (.State function .Sskip (continuation k) e le m)
      (.State function parity k e le m) := by
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, continuation, CC.doStep, CC.Eapp, CC.E0]

/-- Original CF/ZF/SF/OF/PF bodies and loop control compose in31 steps.
All later pointer loads follow from the initial header and actual store
frames. Flag locations may share a data block; each stays outside the header
block. The final header loads are retained for the following source stage. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m cfHeap zfHeap sfHeap ofHeap after : CC.Mem) (bindingBlock : CC.Block) (places : Locations)
    (value : BitVec 64) (size : X86.Size)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value))
    (bitsRead : le.get X86_program_profile_bpf.___x86_fl_bits = some (.Vint (BitVec.ofNat 32 size.bits)))
    (headers : HeaderLoads m bindingBlock places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (cfStored : CC.Mem.store .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2)
      (.Vint (0#32)) = some cfHeap)
    (zfStored : CC.Mem.store .Mint8unsigned cfHeap places.zf.1 (CC.Integers.Ptrofs.unsigned places.zf.2)
      (X86ShiftFlagZF.bit value) = some zfHeap)
    (sfStored : CC.Mem.store .Mint8unsigned zfHeap places.sf.1 (CC.Integers.Ptrofs.unsigned places.sf.2)
      (signByte value size) = some sfHeap)
    (ofStored : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (.Vint (0#32)) = some ofHeap)
    (pfStored : CC.Mem.store .Mint8unsigned ofHeap places.pf.1 (CC.Integers.Ptrofs.unsigned places.pf.2)
      (X86ShiftFlagPF.bit value) = some after) :
    InternalRun ge 31 (.State function X86LogicFlagWidths.rest k e le m)
      (.State function .Sskip k e (temps le places) after) ∧ HeaderLoads after bindingBlock places := by
  let cfLe := le.set X86_program_profile_bpf._t'206 (.Vptr places.cf.1 places.cf.2)
  let zfLe := cfLe.set X86_program_profile_bpf._t'205 (.Vptr places.zf.1 places.zf.2)
  let sfLe := zfLe.set X86_program_profile_bpf._t'204 (.Vptr places.sf.1 places.sf.2)
  let ofLe := sfLe.set X86_program_profile_bpf._t'203 (.Vptr places.overflow.1 places.overflow.2)
  have cfHeaders := header_store headers separate.1 cfStored
  have zfHeaders := header_store cfHeaders separate.2.1 zfStored
  have sfHeaders := header_store zfHeaders separate.2.2.1 sfStored
  have ofHeaders := header_store sfHeaders separate.2.2.2.1 ofStored
  have finalHeaders := header_store ofHeaders separate.2.2.2.2 pfStored
  have zfBinding : cfLe.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [cfLe, CC.PTree.gso, binding]
  have zfWord : cfLe.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [cfLe, CC.PTree.gso, word]
  have sfBinding : zfLe.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [zfLe, cfLe, CC.PTree.gso, binding]
  have sfWord : zfLe.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [zfLe, cfLe, CC.PTree.gso, word]
  have sfBits : zfLe.get X86_program_profile_bpf.___x86_fl_bits = some (.Vint (BitVec.ofNat 32 size.bits)) := by
    simp +decide [zfLe, cfLe, CC.PTree.gso, bitsRead]
  have ofBinding : sfLe.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [sfLe, zfLe, cfLe, CC.PTree.gso, binding]
  have pfBinding : ofLe.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [ofLe, sfLe, zfLe, cfLe, CC.PTree.gso, binding]
  have pfWord : ofLe.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [ofLe, sfLe, zfLe, cfLe, CC.PTree.gso, word]
  have carry := cf_internal ge bindingsLayout valueLayout function e le
    (.Kseq (.Ssequence zf (.Ssequence sf ofStmt)) (continuation k)) m cfHeap
    bindingBlock places.cf.1 places.cf.2 binding headers.cf cfStored
  have zero := zf_internal ge bindingsLayout valueLayout function e cfLe
    (.Kseq (.Ssequence sf ofStmt) (continuation k)) cfHeap zfHeap
    bindingBlock places.zf.1 places.zf.2 value zfBinding zfWord cfHeaders.zf zfStored
  have sign := sf_internal ge bindingsLayout valueLayout function e zfLe
    (.Kseq ofStmt (continuation k)) zfHeap sfHeap
    bindingBlock places.sf.1 places.sf.2 value size sfBinding sfWord sfBits zfHeaders.sf sfStored
  have overflow := of_internal ge bindingsLayout valueLayout function e sfLe
    (continuation k) sfHeap ofHeap bindingBlock places.overflow.1 places.overflow.2
    ofBinding sfHeaders.overflow ofStored
  have parityRun := parity_internal ge bindingsLayout valueLayout function e ofLe
    k ofHeap after bindingBlock places.pf.1 places.pf.2 value pfBinding pfWord ofHeaders.pf pfStored
  refine ⟨?_, finalHeaders⟩
  have first := (enter ge function e le k m).trans carry
  have second := (first.trans (next_two ge function e cfLe (continuation k) cfHeap
    zf (.Ssequence sf ofStmt))).trans zero
  have third := (second.trans (next_two ge function e zfLe (continuation k) zfHeap
    sf ofStmt)).trans sign
  have fourth := (third.trans (next_one ge function e sfLe (continuation k) sfHeap ofStmt)).trans overflow
  exact (fourth.trans (to_parity ge function e ofLe k ofHeap)).trans parityRun

end KProgFormal.ClightRefinement.X86LogicFlagOrder
