import Std

/-! Universal target-object retention through the kernel RCU protocol.
Program-array references keep a target published. The final array/reference
release retires it through call_rcu or call_rcu_tasks_trace. A callback executes
after every reader in its matching retirement snapshot has completed. Lookup
and tail-entry use the same read-side domain, as supplied by the kernel's
invocation and program-array compatibility contracts. Payload includes the
complete immutable target image, entry ABI, maps and executable permissions.
-/
namespace KProgFormal.ControlABI.RCUTarget

inductive Domain | normal | tasksTrace deriving DecidableEq, Repr
/-- Fields of the existing program-array owner compatibility conjunction in
kernel/bpf/core.c: __bpf_prog_map_compatible. -/
structure ProgramProfile where
  programType : Nat
  jited : Bool
  xdpFragments : Bool
  sleepable : Bool
  deriving DecidableEq

def compatible (owner program : ProgramProfile) : Bool :=
  owner.programType == program.programType && owner.jited == program.jited &&
  owner.xdpFragments == program.xdpFragments && owner.sleepable == program.sleepable

def releaseDomain (sleepable : Bool) : Domain := if sleepable then .tasksTrace else .normal

/-- Two programs admitted to one program array use the same grace domain.
The source conjunction derives the sleepable equality used by both invocation
and __bpf_prog_put_noref, including arbitrary other profile fields. -/
theorem program_array_domain (owner caller target : ProgramProfile)
    (callerAccepted : compatible owner caller = true)
    (targetAccepted : compatible owner target = true) :
    releaseDomain caller.sleepable = releaseDomain target.sleepable := by
  have callerSleep : owner.sleepable = caller.sleepable := by
    have h := callerAccepted
    simp only [compatible, Bool.and_eq_true, beq_iff_eq] at h
    exact h.2
  have targetSleep : owner.sleepable = target.sleepable := by
    have h := targetAccepted
    simp only [compatible, Bool.and_eq_true, beq_iff_eq] at h
    exact h.2
  rw [← callerSleep, ← targetSleep]

abbrev Reader := Domain × Nat

inductive Phase | privateObject | published | retired | reclaimed deriving DecidableEq, Repr

structure State (Payload : Type) where
  payload : Payload
  domain : Domain
  phase : Phase
  active : Reader → Bool
  observed : Reader → Option Payload
  awaiting : Reader → Bool

/-- An active observation carries both the original object payload and the
matching grace-period membership after the final reference has retired. -/
def Valid {Payload : Type} (s : State Payload) : Prop :=
  ∀ reader value, s.active reader = true → s.observed reader = some value →
    s.payload = value ∧ s.phase ≠ .reclaimed ∧
    reader.1 = s.domain ∧ (s.phase = .retired → s.awaiting reader = true)

inductive Event (Payload : Type)
  | beginRead (reader : Reader)
  | observe (reader : Reader) (value : Payload)
  | endRead (reader : Reader)
  | publish | retire | reclaim
  | allocate (value : Payload) (domain : Domain)
  | enter (reader : Reader) (value : Payload)
  | other

/-- Reader snapshots are proof state for the existing RCU primitive. A target
can be republished with a new payload after reclamation, so address reuse is
covered by the same invariant. Other kernel/map activity stutters in this view. -/
inductive Step {Payload : Type} : State Payload → Event Payload → State Payload → Prop
  | beginRead (s : State Payload) (reader : Reader)
      (idle : s.active reader = false) (fresh : s.observed reader = none) :
      Step s (.beginRead reader) { s with active := fun r => if r = reader then true else s.active r }
  | observe (s : State Payload) (reader : Reader)
      (active : s.active reader = true) (published : s.phase = .published)
      (domain : reader.1 = s.domain) :
      Step s (.observe reader s.payload)
        { s with observed := fun r => if r = reader then some s.payload else s.observed r }
  | endRead (s : State Payload) (reader : Reader) :
      Step s (.endRead reader)
        { s with active := fun r => if r = reader then false else s.active r
                 observed := fun r => if r = reader then none else s.observed r }
  | publish (s : State Payload) (privateObject : s.phase = .privateObject) :
      Step s .publish { s with phase := .published }
  | retire (s : State Payload) (published : s.phase = .published) :
      Step s .retire
        { s with phase := .retired
                 awaiting := fun r => if r.1 = s.domain then s.active r else false }
  | reclaim (s : State Payload) (retired : s.phase = .retired)
      (grace : ∀ reader, s.awaiting reader = true → s.active reader = false) :
      Step s .reclaim { s with phase := .reclaimed }
  | allocate (s : State Payload) (value : Payload) (domain : Domain)
      (reclaimed : s.phase = .reclaimed) :
      Step s (.allocate value domain)
        { s with payload := value, domain := domain, phase := .privateObject,
                 awaiting := fun _ => false }
  | enter (s : State Payload) (reader : Reader) (value : Payload)
      (active : s.active reader = true) (observed : s.observed reader = some value) :
      Step s (.enter reader value) s
  | other (s : State Payload) : Step s .other s

/-- Every operational step preserves observed payload and lifetime. The
reclaim case derives its contradiction from actual snapshot membership and
the grace condition; the allocate case covers post-grace address reuse. -/
theorem step_preserves {Payload : Type} {before after : State Payload} {event : Event Payload}
    (valid : Valid before) (step : Step before event after) : Valid after := by
  cases step with
  | beginRead reader idle fresh =>
    intro query value active seen
    dsimp only at active seen ⊢
    by_cases same : query = reader
    · subst query
      rw [fresh] at seen
      contradiction
    · exact valid query value (by simpa [same] using active) seen
  | observe reader active published domain =>
    intro query value queryActive seen
    dsimp only at queryActive seen ⊢
    by_cases same : query = reader
    · subst query
      have equal : before.payload = value := by simpa using seen
      exact ⟨equal, by simp [published], domain, by simp [published]⟩
    · exact valid query value queryActive (by simpa [same] using seen)
  | endRead reader =>
    intro query value active seen
    dsimp only at active seen ⊢
    by_cases same : query = reader
    · simp [same] at active
    · exact valid query value (by simpa [same] using active) (by simpa [same] using seen)
  | publish privateObject =>
    intro reader value active seen
    dsimp only at active seen ⊢
    obtain ⟨payload, _, domain, _⟩ := valid reader value active seen
    exact ⟨payload, by simp, domain, by simp⟩
  | retire published =>
    intro reader value active seen
    dsimp only at active seen ⊢
    obtain ⟨payload, _, domain, _⟩ := valid reader value active seen
    exact ⟨payload, by simp, domain, by simp [domain, active]⟩
  | reclaim retired grace =>
    intro reader value active seen
    dsimp only at active seen ⊢
    obtain ⟨_, _, _, waiting⟩ := valid reader value active seen
    have ended := grace reader (waiting retired)
    rw [ended] at active
    contradiction
  | allocate value domain reclaimed =>
    intro reader previous active seen
    have live := (valid reader previous active seen).2.1
    exact False.elim (live reclaimed)
  | enter => exact valid
  | other => exact valid

inductive Run {Payload : Type} : State Payload → List (Event Payload) → State Payload → Prop
  | refl (s) : Run s [] s
  | next {first middle last event events} : Step first event middle →
      Run middle events last → Run first (event :: events) last

theorem run_preserves {Payload : Type} {first last : State Payload} {events : List (Event Payload)}
    (valid : Valid first) (run : Run first events last) : Valid last := by
  induction run with
  | refl => exact valid
  | next step rest ih => exact ih (step_preserves valid step)

/-- A newly allocated target starts with arbitrary payload and cold readers. -/
def initial {Payload : Type} (payload : Payload) (domain : Domain) : State Payload :=
  ⟨payload, domain, .privateObject, fun _ => false, fun _ => none, fun _ => false⟩

theorem initial_valid {Payload : Type} (payload : Payload) (domain : Domain) :
    Valid (initial payload domain) := by
  intro reader value active
  contradiction

/-- At every tail entry in every concurrent finite kernel history, the cached
object is live and retains its exact observed image and ABI, even after slot
replacement and final reference release. -/
theorem tail_entry_retained {Payload : Type} (payload : Payload) (domain : Domain)
    {before after : State Payload} {history : List (Event Payload)}
    (run : Run (initial payload domain) history before) (reader : Reader) (target : Payload)
    (entry : Step before (.enter reader target) after) :
    before.payload = target ∧ before.phase ≠ .reclaimed ∧ reader.1 = before.domain := by
  have valid := run_preserves (initial_valid payload domain) run
  cases entry with
  | enter reader target active observed =>
    have witness := valid reader target active observed
    exact ⟨witness.1, witness.2.1, witness.2.2.1⟩

/-- Every selected property of the complete target payload is retained. -/
theorem tail_entry_payload {Payload Value : Type} (project : Payload → Value)
    (payload : Payload) (domain : Domain) {before after : State Payload}
    {history : List (Event Payload)} (run : Run (initial payload domain) history before)
    (reader : Reader) (target : Payload) (entry : Step before (.enter reader target) after) :
    project before.payload = project target :=
  congrArg project (tail_entry_retained payload domain run reader target entry).1

end KProgFormal.ControlABI.RCUTarget

#print axioms KProgFormal.ControlABI.RCUTarget.step_preserves
#print axioms KProgFormal.ControlABI.RCUTarget.tail_entry_retained
