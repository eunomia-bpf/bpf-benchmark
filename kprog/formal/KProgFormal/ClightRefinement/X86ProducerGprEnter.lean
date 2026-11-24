import KProgFormal.ClightRefinement.X86ProducerGprSites

namespace KProgFormal.ClightRefinement.X86ProducerGprEnter
open X86ProducerGprSites
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86RegisterWriteRspReleaseWord (inputFunction)

def tail (i : Fin 16) : CC.Stmt := .Ssequence (site i).tag (site i).following
def callCont (i : Fin 16) (k : CC.Cont) : CC.Cont :=
  .Kseq (site i).saved (.Kseq (site i).destination (.Kseq (tail i) k))
def continuation (i : Fin 16) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (site i).resultName) producer e le (callCont i k)
def temps (i : Fin 16) (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv :=
  (le.set (site i).resultName (.Vlong word)).set (site i).savedName (.Vlong word)

private theorem ordinary_condition (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (i : Fin 16) (ordinary : i ≠ 4) :
    CC.doEvalExpr ge e le memory (site i).condition = some (.Vint 0) ∧
    CC.Cop.boolVal (.Vint 0) (CC.typeof (site i).condition) memory = some false := by
  have cases : ∀ i : Fin 16, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 := by decide +kernel
  rcases cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first | contradiction | (constructor <;> rfl)

/-- All15 ordinary source decisions, original sequences and real input calls
reach their actual kind6 external Callstate with complete original continuation. -/
theorem enter (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (ordinary : i ≠ 4) :
    InternalRun ge 5 (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory)
      (.Callstate inputFunction [.Vint (6#32)] (continuation i (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated absent
  have decision := ordinary_condition (allocation ge.genv_cenv before).1 le memory i ordinary
  have branch : CC.doStep ge
      (.State producer (.Sifthenelse (site i).condition (site i).zero (.Ssequence (site i).call (site i).saved))
        (.Kseq (site i).destination (.Kseq (tail i) k)) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer (.Ssequence (site i).call (site i).saved)
        (.Kseq (site i).destination (.Kseq (tail i) k)) (allocation ge.genv_cenv before).1 le memory) := by
    simp only [CC.doStep, decision.1, decision.2]
    all_goals rfl
  have call : CC.doStep ge (.State producer (site i).call (callCont i k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .Callstate inputFunction [.Vint (6#32)] (continuation i (allocation ge.genv_cenv before).1 le k) memory) := by
    simp +decide [source_call, continuation, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
      CC.lvalOfVar, notLocal, CC.doDerefLoc, CC.accessMode, CC.typeof,
      X86ProducerFirstInput.input_binding.1, X86ProducerFirstInput.input_binding.2,
      CC.Genv.findFunct, CC.Cop.classifyFun, inputFunction, X86RegisterWriteRspReleaseWord.inputEF,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuint, CC.tint, CC.tulong]
  rw [source_route]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ branch)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step (by rw [source_call]; trivial) (CC.doStep_sound ge _ _ _ call) (.refl _)))))

/-- Actual return and both casts retain each site's own original result/saved
identifiers, not the first site's temporary names. Supplied heap is unchanged. -/
theorem returned (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) (i : Fin 16) (word : BitVec 64) :
    InternalRun ge 4 (.Returnstate (.Vlong word) (continuation i e le k) memory)
      (.State producer (site i).destination (.Kseq (tail i) k) e (temps i le word) memory) := by
  have evaluated : CC.doEvalExpr ge e (le.set (site i).resultName (.Vlong word)) memory
      (.Ecast (.Ecast (.Etempvar (site i).resultName CC.tulong) (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)) = some (.Vlong word) := by
    simp only [CC.doEvalExpr, CC.PTree.gss, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.tulong, CC.tptr, CC.Archi.ptr64, ite_true]
  have saved : CC.doStep ge (.State producer (site i).saved
      (.Kseq (site i).destination (.Kseq (tail i) k)) e (le.set (site i).resultName (.Vlong word)) memory) =
      some (CC.E0, .State producer .Sskip (.Kseq (site i).destination (.Kseq (tail i) k)) e (temps i le word) memory) := by
    rw [source_saved]
    simp only [CC.doStep, evaluated, temps]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step (by rw [source_saved]; trivial) (CC.doStep_sound ge _ _ _ saved)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))))

/-- The real RSP decision uses its actual zero-pointer arm in5 transitions;
no provider call or output word is invented for this special branch. -/
theorem rsp (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 5 (.State producer (site 4).whole k e le memory)
      (.State producer (site 4).destination (.Kseq (tail 4) k) e
        (le.set (site 4).savedName (.Vlong 0)) memory) := by
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))))

end KProgFormal.ClightRefinement.X86ProducerGprEnter
