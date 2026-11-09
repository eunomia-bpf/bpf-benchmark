import KProgFormal.Reference.Memory

/-! Universal spill/body/reload control transformation. This module supplies
control and saved-value liveness for arbitrary source graphs and finite paths.
PrivateSpillProjection supplies actual decoded STXDW/LDXDW value and event
laws. Connecting the compiler's emitted graph, byte ownership and address
registers to these three phases remains the producer interface. -/
namespace KProgFormal.SpillControl
open Reference

/-- A path retains the complete ordered canonical effect trace. -/
inductive Path {State : Type} (edge : State → List Event → State → Prop) :
    State → List Event → State → Prop where
  | refl (state) : Path edge state [] state
  | next {first middle last head tail} : edge first head middle →
      Path edge middle tail last → Path edge first (head ++ tail) last

theorem Path.append {State : Type} {edge : State → List Event → State → Prop}
    {first middle last : State} {head tail : List Event}
    (left : Path edge first head middle) (right : Path edge middle tail last) :
    Path edge first (head ++ tail) last := by
  induction left with
  | refl => exact right
  | next step rest ih => simpa [List.append_assoc] using Path.next step (ih right)

/-- The private saved value persists from spill through reload. It belongs to
the compiler frame; the source state carries all public registers and memory. -/
inductive Phase (State Saved : Type) where
  | entry (source : State)
  | body (source : State) (saved : Saved)
  | reload (source : State) (saved : Saved)

def source {State Saved : Type} : Phase State Saved → State
  | .entry state | .body state _ | .reload state _ => state

/-- Each source edge expands to spill, one body edge and reload. The body may
represent any finite block supplied by the existing decoded execution law. -/
inductive Edge {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop) :
    Phase State Saved → List Event → Phase State Saved → Prop where
  | spill (state) : Edge capture body (.entry state) [] (.body state (capture state))
  | execute {first last events saved} : body first events last →
      Edge capture body (.body first saved) events (.reload last saved)
  | reload (state saved) : Edge capture body (.reload state saved) [] (.entry state)

/-- Every transformed edge projects to a real source path with exact effects.
Spill/reload edges stutter; body effects retain their order and contents. -/
theorem edge_projects {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    {first last : Phase State Saved} {events : List Event}
    (edge : Edge capture body first events last) :
    Path body (source first) events (source last) := by
  cases edge with
  | spill state => exact Path.refl state
  | execute step => simpa using Path.next step (Path.refl _)
  | reload state saved => exact Path.refl state

/-- Arbitrarily many wrappers preserve the entire source control path, even
for loops, early exits and dynamic source graphs. -/
theorem path_projects {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    {first last : Phase State Saved} {events : List Event}
    (path : Path (Edge capture body) first events last) :
    Path body (source first) events (source last) := by
  induction path with
  | refl state => exact Path.refl (source state)
  | next edge rest ih => exact (edge_projects capture body edge).append ih

/-- One source edge has a complete wrapper path returning to entry phase. -/
theorem edge_lifts {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    {first last : State} {events : List Event} (step : body first events last) :
    Path (Edge capture body) (.entry first) events (.entry last) := by
  have reloaded : Path (Edge capture body) (.reload last (capture first)) [] (.entry last) :=
    Path.next (Edge.reload last (capture first)) (Path.refl (Phase.entry (Saved := Saved) last))
  have executed : Path (Edge capture body) (.body first (capture first)) events (.entry last) := by
    simpa using Path.next (Edge.execute step) reloaded
  exact Path.next (Edge.spill first) executed

/-- Every finite source run expands, including each branch and back edge. -/
theorem path_lifts {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    {first last : State} {events : List Event} (path : Path body first events last) :
    Path (Edge capture body) (.entry first) events (.entry last) := by
  induction path with
  | refl state => exact Path.refl (Phase.entry state)
  | next step rest ih => exact (edge_lifts capture body step).append ih

/-- A complete wrapper graph preserves and reflects the original source run. -/
theorem spill_reload_control {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop) (first last : State) (events : List Event) :
    Path (Edge capture body) (.entry first) events (.entry last) ↔
      Path body first events last := by
  constructor
  · exact path_projects capture body
  · exact path_lifts capture body

/-- The body phase exits through reload with its exact captured value. -/
theorem body_saved_live {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    (first : State) (saved : Saved) (last : Phase State Saved) (events : List Event)
    (edge : Edge capture body (.body first saved) events last) :
    ∃ after, last = .reload after saved ∧ body first events after := by
  cases edge with
  | execute step => exact ⟨_, rfl, step⟩

/-- Reload has a unique control successor and preserves the public body state. -/
theorem reload_successor {State Saved : Type} (capture : State → Saved)
    (body : State → List Event → State → Prop)
    (state : State) (saved : Saved) (last : Phase State Saved) (events : List Event)
    (edge : Edge capture body (.reload state saved) events last) :
    last = .entry state ∧ events = [] := by
  cases edge
  exact ⟨rfl, rfl⟩

end KProgFormal.SpillControl

#print axioms KProgFormal.SpillControl.spill_reload_control
#print axioms KProgFormal.SpillControl.body_saved_live
#print axioms KProgFormal.SpillControl.reload_successor
