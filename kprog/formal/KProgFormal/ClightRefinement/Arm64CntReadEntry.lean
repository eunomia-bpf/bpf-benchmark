import KProgFormal.ClightRefinement.Arm64CntReductionSite
import KProgFormal.ClightRefinement.Arm64CntInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cnt.ReadEntry

private def pointerKey (upper : Bool) : CC.Ident := if upper then Arm64Program._t'2836 else Arm64Program._t'2834
private def field (upper : Bool) : CC.Ident := if upper then Arm64Program._vector_hi else Arm64Program._vector_lo
private def fieldOffset (upper : Bool) : Int := if upper then 352 else 96

private def pointer (upper : Bool) : CC.Stmt :=
  .Sset (pointerKey upper)
    (.Ederef (.Ebinop .Oadd
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field upper) (CC.tarray (CC.tptr CC.tulong) 32))
      (.Econst_int (CC.Integers.Int.repr 0) CC.tint) (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong))

private def word (upper : Bool) : CC.Stmt :=
  .Sset (ReductionSite.inputKey upper) (.Ederef (.Etempvar (pointerKey upper) (CC.tptr CC.tulong)) CC.tulong)

/-- Both prefixes are the actual pointer and word assignments before their
respective original high/low reduction call. -/
theorem source (upper : Bool) : ReductionSite.readPrefix upper =
    .Ssequence (pointer upper) (.Ssequence (word upper) (ReductionSite.site upper)) := by
  cases upper <;> rfl

private def entryComposite : CC.Composite :=
  (Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)

private theorem layouts :
    Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    (∀ upper, CC.fieldOffset Arm64ProgramEntryLinked.ge.genv_cenv (field upper) entryComposite.co_members =
      .OK (fieldOffset upper,.Full)) ∧
    CC.sizeof Arm64ProgramEntryLinked.ge.genv_cenv (CC.tptr CC.tulong) = 8 := by
  constructor
  · decide +kernel
  constructor
  · intro upper; cases upper <;> decide +kernel
  · decide +kernel

private theorem pointer_step (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (fieldOffset upper))) = some (.Vptr vb vo)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler (pointer upper) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set (pointerKey upper) (.Vptr vb vo)) m) := by
  apply CC.doStep_sound
  simp +decide only [pointer,CC.doStep,CC.doEvalExpr,
    CC.doEvalLvalue,CC.lvalOfField,CC.typeof,entry,CC.doDerefLoc,CC.accessMode,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tint,CC.tulong,CC.tptr,CC.tarray,CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,
    ite_true,ite_false,layouts.1,layouts.2.1 upper,layouts.2.2,
    CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,CC.Integers.Ptrofs.of_intu,CC.Integers.Ptrofs.of_int,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.MI.add,CC.Integers.MI.mul] <;> try rfl
  change (match CC.Mem.loadv CC.Mptr m (.Vptr b
      ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset upper) +
        CC.Integers.Ptrofs.repr 8 * BitVec.signExtend CC.Archi.ptrWordsize (0#32))) with
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e (le.set (pointerKey upper) value) m)
    | none => none) = _
  have offset : (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset upper) +
      CC.Integers.Ptrofs.repr 8 * BitVec.signExtend CC.Archi.ptrWordsize (0#32) =
      CC.Integers.Ptrofs.repr (fieldOffset upper) := by cases upper <;> decide +kernel
  rw [offset,slot]

private theorem word_step (upper : Bool) (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64)
    (ptr : le.get (pointerKey upper) = some (.Vptr vb vo))
    (loaded : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler (word upper) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set (ReductionSite.inputKey upper) (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [word,CC.doStep,CC.doEvalExpr,ptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,loaded,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tulong]

def temps (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (value : BitVec 64) : CC.TempEnv :=
  (le.set (pointerKey upper) (.Vptr vb vo)).set (ReductionSite.inputKey upper) (.Vlong value)

/-- Six original source transitions load the genuine input word and reach
the actual reduction call, with the complete memory and continuation retained. -/
theorem prepare (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (fieldOffset upper))) = some (.Vptr vb vo))
    (loaded : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value)) :
    InternalRun Arm64ProgramEntryLinked.ge 6
      (.State Arm64Nop.handler (ReductionSite.readPrefix upper) k e le m)
      (.State Arm64Nop.handler (ReductionSite.site upper) k e (temps upper le vb vo value) m) := by
  rw [source]
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact pointer_step upper e le m _ b vb vo entry slot
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact word_step upper _ e _ m _ vb vo value (CC.PTree.gss _ _ _) loaded
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  exact .refl _

theorem from_storage {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 6
      (.State Arm64Nop.handler (ReductionSite.readPrefix upper) k e le before)
      (.State Arm64Nop.handler (ReductionSite.site upper) k e
        (temps upper le old.vectors.block (CC.Integers.Ptrofs.repr (if upper then 8 else 0))
          (if upper then (Reference.AArch64.readVector s 0 >>> 64).setWidth 64
            else (Reference.AArch64.readVector s 0).setWidth 64)) before) := by
  obtain ⟨slot,loaded⟩ := Inputs.reads old addresses origins s represented upper
  exact prepare upper e le before k entry.block old.vectors.block _ _ entryRead slot loaded

theorem input (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps upper le vb vo value).get (ReductionSite.inputKey upper) = some (.Vlong value) :=
  CC.PTree.gss _ _ _

theorem retained (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (value : BitVec 64) (id : CC.Ident)
    (pointerOther : id ≠ pointerKey upper) (wordOther : id ≠ ReductionSite.inputKey upper) :
    (temps upper le vb vo value).get id = le.get id :=
  (CC.PTree.gso _ _ _ _ (Ne.symm wordOther)).trans (CC.PTree.gso _ _ _ _ (Ne.symm pointerOther))

end KProgFormal.ClightRefinement.Arm64Cnt.ReadEntry
