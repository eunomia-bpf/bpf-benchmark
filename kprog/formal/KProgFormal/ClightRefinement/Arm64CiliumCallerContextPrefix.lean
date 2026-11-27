import KProgFormal.ClightRefinement.Arm64CiliumCallerContext

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerContextPrefix
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext

/-- Availability and effects of the actual context adapter remain an
invocation-environment contract. It states no successful final reader. -/
def Inputs {m : CC.Mem} (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs) : Prop :=
  ∀ which (current : CC.Mem),current.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall effect ge.genv_genv.toSenv
        [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (CC.Integers.Int.repr (inputOffset which))]
        current trace (.Vptr (results which) (resultOffsets which)) supplied ∧
      supplied.access = (allocation m).2.access ∧
      FrameBelow m.nextblock current supplied ∧ supplied.nextblock = current.nextblock ∧
      (∀ c o,CC.Mem.load c supplied abi.block o = CC.Mem.load c current abi.block o)

/-- Actual caller entry and its TWO original context calls execute once.
The explicit adapter outcomes preserve their traces and supplied heaps;
the two ABI pointer readers follow from the same original stores. -/

private structure First (m : CC.Mem) (abi : ABI m) (ctx : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (results : Bool → CC.Block)
    (resultOffsets : Bool → CC.Integers.Ptrofs) (le : CC.TempEnv) (k : CC.Cont) where
  trace : CC.Trace
  supplied : CC.Mem
  after : CC.Mem
  run : CC.Star (CC.Step2 ge)
    (.State procedure (stage false) k (allocation m).1 le (allocation m).2) trace
    (.State procedure (next false) k (allocation m).1
      (le.set _t'1 (.Vptr (results false) (resultOffsets false))) after)
  call : CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (0#32)]
    (allocation m).2 trace (.Vptr (results false) (resultOffsets false)) supplied
  stored : CC.Mem.store .Mint64 supplied abi.block 0 (.Vptr (results false) (resultOffsets false)) = some after
  read : CC.Mem.load .Mint64 after abi.block 0 = some (.Vptr (results false) (resultOffsets false))
  frame : FrameBelow m.nextblock m after
  access : after.access = (allocation m).2.access
  frontier : after.nextblock = (allocation m).2.nextblock

private theorem first_prefix (m : CC.Mem) (abi : ABI m) (ctx : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (results : Bool → CC.Block)
    (resultOffsets : Bool → CC.Integers.Ptrofs) (inputs : Inputs abi ctx ctxOfs results resultOffsets)
    (le : CC.TempEnv) (k : CC.Cont) (input : le.get _ctx = some (.Vptr ctx ctxOfs)) :
    Nonempty (First m abi ctx ctxOfs results resultOffsets le k) := by
  obtain ⟨trace,supplied,call,access,frame,frontier,_⟩ := inputs false (allocation m).2 rfl
  obtain ⟨after,run,stored,read,_,storeFrame,storeAccess,storeFrontier⟩ :=
    execute_pair abi false ctx ctxOfs (results false) (resultOffsets false) trace
      call access le k input
  have allocationFrame : FrameBelow m.nextblock m (allocation m).2 :=
    (FrameBelow.allocVariables (Arm64CiliumCallerLink.allocated m) m.nextblock (Nat.le_refl _)).2
  refine ⟨⟨trace,supplied,after,?_,call,stored,read,
    (allocationFrame.trans frame).trans storeFrame,storeAccess.trans access,
    storeFrontier.trans frontier⟩⟩
  simpa only [temp,Bool.false_eq_true,ite_false] using run

private theorem second_stage : stage true = next false := by
  exact ite_eq_left (rfl : true = true)

private theorem finish_prefix (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Inputs abi ctx ctxOfs results resultOffsets) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get _ctx = some (.Vptr ctx ctxOfs))
    (first : First m abi ctx ctxOfs results resultOffsets le k) :
    ∃ traceFirst suppliedFirst afterFirst traceSecond suppliedSecond after,
      CC.Star (CC.Step2 ge)
        (.State procedure (stage false) k (allocation m).1 le (allocation m).2)
        (CC.Eapp traceFirst traceSecond)
        (.State procedure (next true) k (allocation m).1
          (((le).set _t'1
            (.Vptr (results false) (resultOffsets false))).set _t'2
              (.Vptr (results true) (resultOffsets true))) after) ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (0#32)]
        (allocation m).2 traceFirst (.Vptr (results false) (resultOffsets false)) suppliedFirst ∧
      CC.Mem.store .Mint64 suppliedFirst abi.block 0
        (.Vptr (results false) (resultOffsets false)) = some afterFirst ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (4#32)]
        afterFirst traceSecond (.Vptr (results true) (resultOffsets true)) suppliedSecond ∧
      CC.Mem.store .Mint64 suppliedSecond abi.block 8
        (.Vptr (results true) (resultOffsets true)) = some after ∧
      CC.Mem.load .Mint64 after abi.block 0 =
        some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 after abi.block 8 =
        some (.Vptr (results true) (resultOffsets true)) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  let middle := le.set _t'1 (.Vptr (results false) (resultOffsets false))
  have middleInput : middle.get _ctx = some (.Vptr ctx ctxOfs) := by
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1 ≠ _ctx)]
    exact input
  obtain ⟨traceSecond,suppliedSecond,callSecond,accessSecond,frameSecond,nextSecond,keepABI⟩ :=
    inputs true first.after first.access
  obtain ⟨after,second,storedSecond,readSecond,_,storeFrameSecond,storeAccessSecond,storeNextSecond⟩ :=
    execute_pair abi true ctx ctxOfs (results true) (resultOffsets true) traceSecond
      callSecond accessSecond middle k middleInput
  have dataRead : CC.Mem.load .Mint64 after abi.block 0 =
      some (.Vptr (results false) (resultOffsets false)) :=
    (CC.Mem.load_store_other storedSecond .Mint64 abi.block 0
      (.inr (.inl (by decide)))).trans ((keepABI .Mint64 0).trans first.read)
  rw [second_stage] at second
  have run := star_trans first.run second
  refine ⟨first.trace,first.supplied,first.after,traceSecond,suppliedSecond,after,?_,
    first.call,first.stored,callSecond,storedSecond,dataRead,readSecond,
    (first.frame.trans frameSecond).trans storeFrameSecond,
    storeAccessSecond.trans accessSecond,(storeNextSecond.trans nextSecond).trans first.frontier⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,middle,temp,ite_true] using run

theorem execute_from_body (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Inputs abi ctx ctxOfs results resultOffsets) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get _ctx = some (.Vptr ctx ctxOfs)) :
    ∃ traceFirst suppliedFirst afterFirst traceSecond suppliedSecond after,
      CC.Star (CC.Step2 ge)
        (.State procedure (stage false) k (allocation m).1 le (allocation m).2)
        (CC.Eapp traceFirst traceSecond)
        (.State procedure (next true) k (allocation m).1
          (((le).set _t'1
            (.Vptr (results false) (resultOffsets false))).set _t'2
              (.Vptr (results true) (resultOffsets true))) after) ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (0#32)]
        (allocation m).2 traceFirst (.Vptr (results false) (resultOffsets false)) suppliedFirst ∧
      CC.Mem.store .Mint64 suppliedFirst abi.block 0
        (.Vptr (results false) (resultOffsets false)) = some afterFirst ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (4#32)]
        afterFirst traceSecond (.Vptr (results true) (resultOffsets true)) suppliedSecond ∧
      CC.Mem.store .Mint64 suppliedSecond abi.block 8
        (.Vptr (results true) (resultOffsets true)) = some after ∧
      CC.Mem.load .Mint64 after abi.block 0 =
        some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 after abi.block 8 =
        some (.Vptr (results true) (resultOffsets true)) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨first⟩ := first_prefix m abi ctx ctxOfs results resultOffsets inputs le k input
  exact finish_prefix m abi ctx ctxOfs results resultOffsets inputs le k input first

/-- Enter once and delegate to the same generic body proof. -/
theorem execute (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Inputs abi ctx ctxOfs results resultOffsets) (k : CC.Cont) :
    ∃ traceFirst suppliedFirst afterFirst traceSecond suppliedSecond after,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp traceFirst traceSecond)
        (.State procedure (next true) k (allocation m).1
          (((Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)).set _t'1
            (.Vptr (results false) (resultOffsets false))).set _t'2
              (.Vptr (results true) (resultOffsets true))) after) ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (0#32)]
        (allocation m).2 traceFirst (.Vptr (results false) (resultOffsets false)) suppliedFirst ∧
      CC.Mem.store .Mint64 suppliedFirst abi.block 0
        (.Vptr (results false) (resultOffsets false)) = some afterFirst ∧
      CC.externalCall effect ge.genv_genv.toSenv [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (4#32)]
        afterFirst traceSecond (.Vptr (results true) (resultOffsets true)) suppliedSecond ∧
      CC.Mem.store .Mint64 suppliedSecond abi.block 8
        (.Vptr (results true) (resultOffsets true)) = some after ∧
      CC.Mem.load .Mint64 after abi.block 0 =
        some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 after abi.block 8 =
        some (.Vptr (results true) (resultOffsets true)) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  let initial := Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)
  have input : initial.get _ctx = some (.Vptr ctx ctxOfs) := CC.PTree.gss _ _ _
  obtain ⟨traceFirst,suppliedFirst,afterFirst,traceSecond,suppliedSecond,after,
      run,callFirst,storedFirst,callSecond,storedSecond,dataRead,endRead,frame,access,frontier⟩ :=
    execute_from_body m abi ctx ctxOfs results resultOffsets inputs initial k input
  rw [first_stage] at run
  have entered : InternalRun ge 1
      (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
      (.State procedure procedure.fn_body k (allocation m).1 initial (allocation m).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _
      (Arm64CiliumCallerLink.entry_valid m (.Vptr ctx ctxOfs))) (.refl _)
  refine ⟨traceFirst,suppliedFirst,afterFirst,traceSecond,suppliedSecond,after,?_,
    callFirst,storedFirst,callSecond,storedSecond,dataRead,endRead,frame,access,frontier⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,initial] using star_trans entered.sound run


end KProgFormal.ClightRefinement.Arm64CiliumCallerContextPrefix
