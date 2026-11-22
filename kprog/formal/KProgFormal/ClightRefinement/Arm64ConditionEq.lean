import KProgFormal.ClightRefinement.Arm64Width
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ConditionEq

def arguments (n z c v : CC.Val) : List CC.Val := [.Vlong 0,n,z,c,v]

/-- EQ returns the actual unsigned Z byte, before its caller normalizes the
truth value. The other pointer arguments are not dereferenced on this path. -/
private theorem execution (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (n c v : CC.Val) (block : CC.Block) (offset : CC.Integers.Ptrofs) (z : BitVec 8)
    (read : CC.Mem.load .Mint8unsigned m block (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (z.setWidth 32))) :
    steps ge 12 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments n (.Vptr block offset) c v) k m) =
      some (CC.E0,.Returnstate (.Vint (z.setWidth 32)) (CC.callCont k) m) ∧
    InternalPath ge 12 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments n (.Vptr block offset) c v) k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp +decide [steps,InternalPath,InternalState,arguments,CC.doStep,CC.doFunctionEntry2,
    Arm64Program.f_kprog_arm64_program_condition,CC.listNorepet,CC.varNames,CC.listDisjoint,
    CC.doAllocVariables,CC.bindParameterTemps,CC.createUndefTemps,CC.PTree.gss,CC.PTree.gso,
    CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.Mem.loadv,CC.typeof,CC.accessMode,read,CC.setOpttemp,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tulong,
    CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.Int64.cmpu,CC.Integers.Int.eq,CC.Integers.Int64.eq,CC.Integers.MI.eq,
    CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int64.repr,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.E0,CC.Eapp,empty,CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList]

/-- Complete actual EQ condition call, same full memory and continuation. -/
theorem internal (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (n c v : CC.Val) (block : CC.Block) (offset : CC.Integers.Ptrofs) (z : BitVec 8)
    (read : CC.Mem.load .Mint8unsigned m block (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (z.setWidth 32))) :
    InternalRun ge 12 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments n (.Vptr block offset) c v) k m)
      (.Returnstate (.Vint (z.setWidth 32)) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge m k n c v block offset z read).2
    (execution ge m k n c v block offset z read).1

/-- The byte path specializes to the existing architectural one-bit view. -/
theorem internal_bit (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (n c v : CC.Val) (block : CC.Block) (offset : CC.Integers.Ptrofs) (z : BitVec 1)
    (read : CC.Mem.load .Mint8unsigned m block (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (z.setWidth 32))) :
    InternalRun ge 12 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments n (.Vptr block offset) c v) k m)
      (.Returnstate (.Vint (z.setWidth 32)) (CC.callCont k) m) := by
  have byteRead : CC.Mem.load .Mint8unsigned m block (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint ((z.setWidth 8).setWidth 32)) := by simpa using read
  simpa using internal ge m k n c v block offset (z.setWidth 8) byteRead

/-- Existing concrete NZCV representation and the same actual storage derive
Z's current load; no independent flag readback/native result is supplied. -/
theorem from_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (ge : CC.CGenv) (k : CC.Cont) :
    InternalRun ge 12 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
      (arguments (.Vptr (storage.flags 0).block 0) (.Vptr (storage.flags 1).block 0)
        (.Vptr (storage.flags 2).block 0) (.Vptr (storage.flags 3).block 0)) k m)
      (.Returnstate (.Vint ((read_flag .Z s.machine).setWidth 32)) (CC.callCont k) m) := by
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
  obtain ⟨nv,_nr,zv,zr,cv,_cr,vv,_vr,_ne,ze,_ce,_ve⟩ := actual
  have read : CC.Mem.load .Mint8unsigned m (storage.flags 1).block 0 =
      some (.Vint ((read_flag .Z s.machine).setWidth 32)) := by simpa only [ze] using zr
  exact internal_bit ge m k _ _ _ _ 0 (read_flag .Z s.machine) read

/-- Converting the actual represented Z scalar to C truth equals the imported
mature condition test itself, not a second local condition definition. -/
theorem native_truth (m : CC.Mem) (s : Reference.AArch64.State) :
    CC.Cop.boolVal (.Vint ((read_flag .Z s.machine).setWidth 32)) CC.tint m =
      some (ConditionHolds (0#4) s.machine) := by
  change some (!((read_flag .Z s.machine).setWidth 32 == 0#32)) =
    some (decide (read_flag .Z s.machine = 1#1))
  have law : ∀ z : BitVec 1, (!(z.setWidth 32 == 0#32)) = decide (z = 1#1) := by decide +kernel
  rw [law]

/-- Every relational execution at Kstop is a silent prefix of the same real
return; stuck endpoints agree and infinite executions are excluded. -/
theorem all_behaviors (ge : CC.CGenv) (m : CC.Mem)
    (n c v : CC.Val) (block : CC.Block) (offset : CC.Integers.Ptrofs) (z : BitVec 8)
    (read : CC.Mem.load .Mint8unsigned m block (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (z.setWidth 32))) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
        (arguments n (.Vptr block offset) c v) .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (.Vint (z.setWidth 32)) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
        (arguments n (.Vptr block offset) c v) .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (.Vint (z.setWidth 32)) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
        (arguments n (.Vptr block offset) c v) .Kstop m ∧
      ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j+1))) := by
  have run := internal ge m .Kstop n c v block offset z read
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (.Vint (z.setWidth 32)) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64ConditionEq
