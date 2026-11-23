import KProgFormal.ClightRefinement.Arm64Width
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ConditionGe

def arguments (n z c v : CC.Val) : List CC.Val := [.Vlong 10,n,z,c,v]

/-- The actual C equality result after unsigned-byte integer promotion. -/
def result (n v : BitVec 8) : CC.Val :=
  CC.Val.ofBool (n.setWidth 32 == v.setWidth 32)

/-- Ten failed condition gates and the GE branch execute the actual two loads;
Z and C are not dereferenced on this source path. -/
private theorem execution (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (z c : CC.Val) (nb vb : CC.Block) (no vo : CC.Integers.Ptrofs) (n v : BitVec 8)
    (readN : CC.Mem.load .Mint8unsigned m nb (CC.Integers.Ptrofs.unsigned no) =
      some (.Vint (n.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m vb (CC.Integers.Ptrofs.unsigned vo) =
      some (.Vint (v.setWidth 32))) :
    steps ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments (.Vptr nb no) z c (.Vptr vb vo)) k m) =
      some (CC.E0,.Returnstate (result n v) (CC.callCont k) m) ∧
    InternalPath ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments (.Vptr nb no) z c (.Vptr vb vo)) k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  by_cases equal : (n.setWidth 32 == v.setWidth 32)
  all_goals simp +decide [equal,steps,InternalPath,InternalState,arguments,CC.doStep,CC.doFunctionEntry2,
    Arm64Program.f_kprog_arm64_program_condition,Arm64Program.s_kprog_arm64_program_condition_7,CC.listNorepet,CC.varNames,CC.listDisjoint,
    CC.doAllocVariables,CC.bindParameterTemps,CC.createUndefTemps,CC.PTree.gss,CC.PTree.gso,
    CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.Mem.loadv,CC.typeof,CC.accessMode,readN,readV,result,CC.setOpttemp,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tulong,
    CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.Int64.cmpu,CC.Integers.Int.eq,CC.Integers.Int64.eq,CC.Integers.MI.eq,
    CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int64.repr,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.E0,CC.Eapp,empty,CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList]

/-- Complete actual GE call with the same full heap and original continuation. -/
theorem internal (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (z c : CC.Val) (nb vb : CC.Block) (no vo : CC.Integers.Ptrofs) (n v : BitVec 8)
    (readN : CC.Mem.load .Mint8unsigned m nb (CC.Integers.Ptrofs.unsigned no) =
      some (.Vint (n.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m vb (CC.Integers.Ptrofs.unsigned vo) =
      some (.Vint (v.setWidth 32))) :
    InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments (.Vptr nb no) z c (.Vptr vb vo)) k m)
      (.Returnstate (result n v) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge m k z c nb vb no vo n v readN readV).2
    (execution ge m k z c nb vb no vo n v readN readV).1

/-- Existing NZCV storage and representation derive both current flag loads;
no independent N/V readback or supplied native result is assumed. -/
theorem from_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (ge : CC.CGenv) (k : CC.Cont) :
    InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments (.Vptr (storage.flags 0).block 0) (.Vptr (storage.flags 1).block 0)
        (.Vptr (storage.flags 2).block 0) (.Vptr (storage.flags 3).block 0)) k m)
      (.Returnstate
        (result ((read_flag .N s.machine).setWidth 8) ((read_flag .V s.machine).setWidth 8))
        (CC.callCont k) m) := by
  have nn := Arm64RegisterWrite.storage_flag storage 0
  have zz := Arm64RegisterWrite.storage_flag storage 1
  have cc := Arm64RegisterWrite.storage_flag storage 2
  have vv := Arm64RegisterWrite.storage_flag storage 3
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    Arm64Program._n = _ at nn
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    Arm64Program._z = _ at zz
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    Arm64Program._c = _ at cc
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    Arm64Program._v = _ at vv
  have actual := represented
  unfold Arm64Nop.FlagsRepresent Arm64EntryMemory.flags at actual
  rw [nn,zz,cc,vv] at actual
  simp only [bind,pure,Option.bind_eq_some_iff,Option.some.injEq,Prod.mk.injEq] at actual
  obtain ⟨nv,nr,zv,_zr,cv,_cr,vv,vr,ne,_ze,_ce,ve⟩ := actual
  have readN : CC.Mem.load .Mint8unsigned m (storage.flags 0).block 0 =
      some (.Vint (((read_flag .N s.machine).setWidth 8).setWidth 32)) := by
    simpa [ne] using nr
  have readV : CC.Mem.load .Mint8unsigned m (storage.flags 3).block 0 =
      some (.Vint (((read_flag .V s.machine).setWidth 8).setWidth 32)) := by
    simpa [ve] using vr
  exact internal ge m k _ _ _ _ 0 0
    ((read_flag .N s.machine).setWidth 8) ((read_flag .V s.machine).setWidth 8) readN readV

/-- Normalizing the actual comparison agrees with the imported GE condition,
using the architectural one-bit N/V view rather than a local condition model. -/
theorem native_truth (m : CC.Mem) (s : Reference.AArch64.State) :
    CC.Cop.boolVal
      (result ((read_flag .N s.machine).setWidth 8) ((read_flag .V s.machine).setWidth 8))
      CC.tint m = some (ConditionHolds (10#4) s.machine) := by
  have comparison : ∀ n v : BitVec 1,
      ((n.setWidth 8).setWidth 32 == (v.setWidth 8).setWidth 32) = decide (n = v) := by
    decide +kernel
  simp only [result,comparison]
  by_cases equal : read_flag .N s.machine = read_flag .V s.machine
  all_goals simp +decide [ConditionHolds,equal,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.Int.one,
    CC.Integers.MI.zero,CC.Integers.MI.one]

/-- The actual helper result itself is the normalized imported GE Boolean. -/
theorem native_result (s : Reference.AArch64.State) :
    result ((read_flag .N s.machine).setWidth 8) ((read_flag .V s.machine).setWidth 8) =
      CC.Val.ofBool (ConditionHolds (10#4) s.machine) := by
  have comparison : ∀ n v : BitVec 1,
      ((n.setWidth 8).setWidth 32 == (v.setWidth 8).setWidth 32) = decide (n = v) := by
    decide +kernel
  simp only [result,comparison]
  simp +decide [ConditionHolds]

end KProgFormal.ClightRefinement.Arm64ConditionGe
