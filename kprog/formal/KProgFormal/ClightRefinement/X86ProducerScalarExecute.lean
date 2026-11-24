import KProgFormal.ClightRefinement.X86ProducerScalarStore
import KProgFormal.ClightRefinement.X86ProducerScalarValue

namespace KProgFormal.ClightRefinement.X86ProducerScalarExecute
open X86ProducerScalarSource
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86RegisterWriteRspReleaseWord (inputFunction inputEF)

def storeRow (i : Fin 8) : Fin 10 := ⟨i.val + 1, by omega⟩
def callCont (i : Fin 8) (k : CC.Cont) : CC.Cont := .Kseq (site i).assignment (.Kseq (site i).following k)
def continuation (i : Fin 8) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (site i).resultName) producer e le (callCont i k)
def temps (i : Fin 8) (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv := le.set (site i).resultName (.Vlong word)

private theorem mapping : ∀ i : Fin 8,
    X86ProducerScalarStore.row (storeRow i) = row i ∧ X86ProducerScalarStore.chunk (storeRow i) = chunk i := by decide +kernel

/-- The intervening actual native-base zero assignment is executed, rather
than jumping from the GPR prefix to flags. -/
theorem initial_zero (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (base : SourceLocal ge.genv_cenv before 14)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer X86ProducerGprChain.following k (allocation ge.genv_cenv before).1 le memory)
      (.State producer start k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store .Mint64 memory base.block 0 (.Vlong 0) = some after ∧
    CC.Mem.load .Mint64 after base.block 0 = some (.Vlong 0) ∧
    (∀ c b ofs, b ≠ base.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨after, run, stored, read, outside, frame, rights, next⟩ :=
    X86ProducerScalarStore.write before memory le k start 0 base (.Econst_int (CC.Integers.Int.repr 0) CC.tint)
      (.Vint 0) (.Vlong 0) rfl rfl rfl access
  refine ⟨after, ?_, stored, read, outside, frame, rights, next⟩
  rw [source_begin.1]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl) run

/-- The original scalar call uses the complete producer's actual symbol and
unshadowed local environment and retains the genuine assignment continuation. -/
theorem enter (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 8) :
    InternalRun ge 3 (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory)
      (.Callstate inputFunction [.Vint (6#32)] (continuation i (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated absent
  have call : CC.doStep ge (.State producer (site i).call (callCont i k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .Callstate inputFunction [.Vint (6#32)] (continuation i (allocation ge.genv_cenv before).1 le k) memory) := by
    simp +decide [source_call, continuation, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
      CC.lvalOfVar, notLocal, CC.doDerefLoc, CC.accessMode, CC.typeof,
      X86ProducerFirstInput.input_binding.1, X86ProducerFirstInput.input_binding.2,
      CC.Genv.findFunct, CC.Cop.classifyFun, inputFunction, inputEF,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuint, CC.tint, CC.tulong]
  rw [source_route]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step (by rw [source_call]; trivial) (CC.doStep_sound ge _ _ _ call) (.refl _)))

/-- An actual returned word reaches the genuine assignment without changing
any byte of the complete supplied heap. -/
theorem returned (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) (i : Fin 8) (word : BitVec 64) :
    InternalRun ge 2 (.Returnstate (.Vlong word) (continuation i e le k) memory)
      (.State producer (site i).assignment (.Kseq (site i).following k) e (temps i le word) memory) := by
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))

/-- The actual masked/full-word rhs and target cast construct each successful
store and readback from current source-local rights. -/
theorem stored (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 8) (word : BitVec 64)
    (object : SourceLocal ge.genv_cenv before (row i))
    (read : le.get (site i).resultName = some (.Vlong word))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 2
      (.State producer (site i).assignment (.Kseq (site i).following k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer (site i).following k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory object.block 0 (X86ProducerScalarValue.value i word) = some after ∧
    CC.Mem.load (chunk i) after object.block 0 = some (X86ProducerScalarValue.value i word) ∧
    (∀ c b ofs, b ≠ object.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  let object' : SourceLocal ge.genv_cenv before (X86ProducerScalarStore.row (storeRow i)) :=
    { block := object.block
      binding := by simpa only [(mapping i).1] using object.binding
      fresh := object.fresh
      owned := object.owned
      range := by simpa only [(mapping i).1] using object.range }
  have sameBlock : object'.block = object.block := rfl
  have cast := X86ProducerScalarValue.cast memory i word
  have run := X86ProducerScalarStore.write before memory le k (site i).following (storeRow i) object'
    (rhs i) (X86ProducerScalarValue.input i word) (X86ProducerScalarValue.value i word)
    (X86ProducerScalarValue.evaluated _ _ _ i word read)
    (by simpa only [(mapping i).1] using cast.1)
    (by simpa only [(mapping i).2] using cast.2) access
  simpa only [(mapping i).1, (mapping i).2, source_assignment, sameBlock] using run

/-- Genuine scalar source entry, external outcome, return and store compose
with the actual trace and complete supplied heap, never a no-op provider. -/
theorem execute (before memory supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 8)
    (word : BitVec 64) (trace : CC.Trace) (object : SourceLocal ge.genv_cenv before (row i))
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv) [.Vint (6#32)] memory trace (.Vlong word) supplied)
    (access : supplied.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory) trace
      (.State producer (site i).following k (allocation ge.genv_cenv before).1 (temps i le word) after) ∧
    CC.Mem.load (chunk i) after object.block 0 = some (X86ProducerScalarValue.value i word) ∧
    (∀ c b ofs, b ≠ object.block → CC.Mem.load c after b ofs = CC.Mem.load c supplied b ofs) ∧
    FrameBelow before.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  have entered := enter before memory le k i
  have returnRun := returned (allocation ge.genv_cenv before).1 le supplied k i word
  obtain ⟨after, storeRun, storeEquation, loaded, outside, frame, rights, next⟩ :=
    stored before supplied (temps i le word) k i word object (CC.PTree.gss _ _ _) access
  have call : CC.Star (CC.Step2 ge)
      (.Callstate inputFunction [.Vint (6#32)] (continuation i (allocation ge.genv_cenv before).1 le k) memory)
      trace (.Returnstate (.Vlong word) (continuation i (allocation ge.genv_cenv before).1 le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _) (by simp [CC.E0, CC.Eapp])
  refine ⟨after, ?_, loaded, outside, frame, rights, next⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) (returnRun.trans storeRun).sound

end KProgFormal.ClightRefinement.X86ProducerScalarExecute
