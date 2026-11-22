import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.Arm64Numeric

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Path

/-- Actual C pointer/tag-path return, for supported conditional-select codes. -/
def result (op width : BitVec 64) : CC.Val :=
  .Vlong (if (op == 28#64) && (width == 8#64) then 1#64 else 0#64)

private theorem execution_csel (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (width : BitVec 64) :
    steps ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong (28#64),.Vlong width] k m) = some (CC.E0,.Returnstate (result (28#64) width) (CC.callCont k) m) ∧
    InternalPath ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong (28#64),.Vlong width] k m) := by
  cases compared : (width == 8#64)
  all_goals
    conv at compared => lhs; cbv
    constructor
    · conv => lhs; cbv
      conv => rhs; cbv
      simp only [compared, Bool.false_eq_true, ite_false, ite_true]
      conv => lhs; cbv
    · repeat' constructor
      conv => cbv
      simp only [compared, Bool.false_eq_true, ite_false, ite_true]
      repeat' constructor

private theorem execution_scalar (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (op width : BitVec 64)
    (supported : op=29#64 ∨ op=30#64 ∨ op=52#64 ∨ op=61#64 ∨ op=62#64 ∨ op=68#64 ∨ op=69#64) :
    steps ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) = some (CC.E0,.Returnstate (result op width) (CC.callCont k) m) ∧
    InternalPath ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) := by
  rcases supported with rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals
    constructor
    · rfl
    · repeat' constructor

private theorem execution (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (op width : BitVec 64)
    (supported : op=28#64 ∨ op=29#64 ∨ op=30#64 ∨ op=52#64 ∨
      op=61#64 ∨ op=62#64 ∨ op=68#64 ∨ op=69#64) :
    steps ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) = some (CC.E0,.Returnstate (result op width) (CC.callCont k) m) ∧
    InternalPath ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) := by
  rcases supported with rfl|other
  · exact execution_csel ge m k width
  · exact execution_scalar ge m k op width other

/-- Complete actual source execution for all eight family codes and arbitrary
64-bit width values; unsupported source codes retain their original branch. -/
theorem executes (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont) (op width : BitVec 64)
    (supported : op=28#64 ∨ op=29#64 ∨ op=30#64 ∨ op=52#64 ∨
      op=61#64 ∨ op=62#64 ∨ op=68#64 ∨ op=69#64) :
    steps ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) = some (CC.E0,.Returnstate (result op width) (CC.callCont k) m) :=
  (execution ge m k op width supported).1

theorem internal (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont) (op width : BitVec 64)
    (supported : op=28#64 ∨ op=29#64 ∨ op=30#64 ∨ op=52#64 ∨
      op=61#64 ∨ op=62#64 ∨ op=68#64 ∨ op=69#64) :
    InternalRun ge 26 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
      [.Vlong op,.Vlong width] k m) (.Returnstate (result op width) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge m k op width supported).2 (execution ge m k op width supported).1

/-- Every finite relational run is a silent prefix of the same return, its
stuck endpoint is unique and infinite executions are excluded. -/
theorem all_behaviors (ge : CC.CGenv) (m : CC.Mem) (op width : BitVec 64)
    (supported : op=28#64 ∨ op=29#64 ∨ op=30#64 ∨ op=52#64 ∨
      op=61#64 ∨ op=62#64 ∨ op=68#64 ∨ op=69#64) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path) [.Vlong op,.Vlong width] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate (result op width) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path) [.Vlong op,.Vlong width] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result op width) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path) [.Vlong op,.Vlong width] .Kstop m ∧
      ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j+1))) := by
  have run := internal ge m .Kstop op width supported
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result op width) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64Select.Path
