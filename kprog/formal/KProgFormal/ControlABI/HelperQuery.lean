import KProgFormal.ClightRefinement.Execution
import CCLib.FunPtr

/-! Source-shaped helper query and typed calls through the actual prototype.
The source is native_lab_helper_query_impl.h and the paired trusted loader:
freplace selects its destination type's ops, while get_func_proto receives the
original referenced program and its complete metadata. Every returned legacy
spelling uses that same prototype, and complete Clight effects remain intact.
-/
namespace KProgFormal.ControlABI.HelperQuery
abbrev Word := BitVec 64
abbrev HelperId := BitVec 32

structure Program (Metadata : Type) where
  programType : Nat
  destinationType : Option Nat
  metadata : Metadata

structure Prototype where
  address : Word
  code : CC.FunDef

structure Identity where
  id : HelperId
  name : String
  deriving DecidableEq

/-- EXT's numeric value is supplied by the sole kernel's enum layout. -/
def opsIndex {Metadata : Type} (extensionType : Nat) (program : Program Metadata) : Nat :=
  if program.programType = extensionType then program.destinationType.getD program.programType
  else program.programType

abbrev Callback (Metadata : Type) := HelperId → Program Metadata → Option Prototype

def resolve {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata) (id : HelperId) :
    Option Prototype := (table (opsIndex extensionType program)).bind fun getProto => getProto id program

/-- Ordinary programs select their own verifier ops with their original metadata. -/
theorem ordinary_callback {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (id : HelperId) (callback : Callback Metadata)
    (ordinary : program.programType ≠ extensionType)
    (selected : table program.programType = some callback) :
    resolve extensionType table program id = callback id program := by
  simp [resolve, opsIndex, ordinary, selected]

/-- freplace inherits destination ops while retaining the original prog object. -/
theorem extension_callback {Metadata : Type} (extensionType targetType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (id : HelperId) (callback : Callback Metadata)
    (extension : program.programType = extensionType)
    (target : program.destinationType = some targetType)
    (selected : table targetType = some callback) :
    resolve extensionType table program id = callback id program := by
  simp [resolve, opsIndex, extension, target, selected]

/-- The kernel writes one full-width target per ID, preserving request order. -/
def response {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (identities : List Identity) : List Word :=
  identities.map fun identity =>
    ((resolve extensionType table program identity.id).map Prototype.address).getD 0

theorem response_length {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (identities : List Identity) :
    (response extensionType table program identities).length = identities.length := by
  simp [response]

/-- Canonical and historical spellings are paired by the original helper ID. -/
def aliases (identity : Identity) (legacy : List Identity) (address : Word) : List (String × Word) :=
  (identity.name, address) ::
    ((legacy.filter fun row => row.id == identity.id && row.name != identity.name).map
      fun row => (row.name, address))

def bindings {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (identities legacy : List Identity) : List (String × Word) :=
  (identities.filter fun identity => identity.id != 0).flatMap fun identity =>
    match resolve extensionType table program identity.id with
    | none => []
    | some prototype => if prototype.address = 0 then [] else aliases identity legacy prototype.address

/-- Every published spelling preserves its canonical ID and exact queried address. -/
theorem alias_identity (identity : Identity) (legacy : List Identity)
    (address : Word) (name : String) (observed : Word)
    (member : (name, observed) ∈ aliases identity legacy address) :
    observed = address ∧ (name = identity.name ∨
      ∃ row ∈ legacy, row.id = identity.id ∧ name = row.name) := by
  rcases List.mem_cons.mp member with same | later
  · have fields := Prod.mk.inj same
    exact ⟨fields.2, Or.inl fields.1⟩
  · obtain ⟨row, filtered, fields⟩ := List.mem_map.mp later
    obtain ⟨inside, selected⟩ := List.mem_filter.mp filtered
    have id : row.id = identity.id := by
      have h := selected
      simp only [Bool.and_eq_true, beq_iff_eq] at h
      exact h.1
    have fields := Prod.mk.inj fields
    exact ⟨fields.2.symm, Or.inr ⟨row, inside, id, fields.1.symm⟩⟩

/-- Binding provenance follows the actual request's callback, original program
and ID. Arbitrary unrelated helpers, addresses and metadata remain unrestricted. -/
theorem binding_prototype {Metadata : Type} (extensionType : Nat)
    (table : Nat → Option (Callback Metadata)) (program : Program Metadata)
    (identities legacy : List Identity) (name : String) (address : Word)
    (bound : (name, address) ∈ bindings extensionType table program identities legacy) :
    ∃ identity ∈ identities, identity.id ≠ 0 ∧ ∃ prototype,
      resolve extensionType table program identity.id = some prototype ∧
      prototype.address ≠ 0 ∧ address = prototype.address ∧
      (name = identity.name ∨ ∃ row ∈ legacy, row.id = identity.id ∧ name = row.name) := by
  obtain ⟨identity, queried, member⟩ := List.mem_flatMap.mp bound
  obtain ⟨inside, nonzero⟩ := List.mem_filter.mp queried
  have queriedId : identity.id ≠ 0 := by simpa using nonzero
  cases query : resolve extensionType table program identity.id with
  | none => simp [query] at member
  | some prototype =>
    by_cases zero : prototype.address = 0
    · simp [query, zero] at member
    · have selected : (name, address) ∈ aliases identity legacy prototype.address := by
        simpa only [query, ite_eq_right zero] using member
      obtain ⟨addressEq, identityEq⟩ := alias_identity identity legacy prototype.address name address selected
      exact ⟨identity, inside, queriedId, prototype, query, zero, addressEq, identityEq⟩

/-- After wire-to-code-pointer transport, the actual imported Clight call rule
enters the queried function with its typed argument list and complete memory. -/
theorem typed_call_enters (world : CC.CGenv) (caller : CC.Function) (callee : CC.Expr)
    (operands : List CC.Expr) (result : Option CC.Ident) (continuation : CC.Cont)
    (locals : CC.Env) (temps : CC.TempEnv) (memory : CC.Mem)
    (prototype : Prototype) (pointer : CC.Val) (arguments : List CC.Val)
    (types : List CC.Ty) (returnType : CC.Ty) (convention : CC.CallConv)
    (classified : CC.Cop.classifyFun (CC.typeof callee) = .f types returnType convention)
    (calleeValue : CC.doEvalExpr world locals temps memory callee = some pointer)
    (captured : CC.doEvalExprlist world locals temps memory operands types = some arguments)
    (code : CC.Genv.findFunct world.genv_genv pointer = some prototype.code)
    (signature : CC.typeOfFundef prototype.code = .Tfunction types returnType convention) :
    CC.Step2 world (.State caller (.Scall result callee operands) continuation locals temps memory)
      CC.E0 (.Callstate prototype.code arguments (.Kcall result caller locals temps continuation) memory) := by
  apply CC.doStep_sound
  simp only [CC.doStep, classified, calleeValue, captured, code, signature, ite_true]

/-- Full foreign-function behavior includes its ordered trace, return value,
allocated/freed objects and permissions. Matching one queried function and
argument/memory snapshot admits every one of those same native outcomes. -/
def Effect (world : CC.CGenv) (prototype : Prototype) (arguments : List CC.Val)
    (before : CC.Mem) (trace : CC.Trace) (value : CC.Val) (after : CC.Mem) : Prop :=
  CC.Star (CC.Step2 world) (.Callstate prototype.code arguments .Kstop before)
    trace (.Returnstate value .Kstop after)

/-- One actual function pointer resolves to one body in the shared kernel
world; source aliases carry the same pointer through the query response. -/
theorem same_target_code (world : CC.CGenv) (pointer : CC.Val) (native proof : Prototype)
    (nativeTarget : CC.Genv.findFunct world.genv_genv pointer = some native.code)
    (proofTarget : CC.Genv.findFunct world.genv_genv pointer = some proof.code) :
    native.code = proof.code := Option.some.inj (nativeTarget.symm.trans proofTarget)

/-- Every finite helper prefix transports, including paths that keep running
or release an argument object before returning. All memory permissions and
caller-visible changes remain in the exact reached Clight state. -/
theorem queried_prefix_preserved (world : CC.CGenv) (pointer : CC.Val)
    (native proof : Prototype) (arguments : List CC.Val) (before : CC.Mem)
    (continuation : CC.Cont) (trace : CC.Trace) (after : CC.State)
    (nativeTarget : CC.Genv.findFunct world.genv_genv pointer = some native.code)
    (proofTarget : CC.Genv.findFunct world.genv_genv pointer = some proof.code)
    (nativeExecution : CC.Star (CC.Step2 world)
      (.Callstate native.code arguments continuation before) trace after) :
    CC.Star (CC.Step2 world) (.Callstate proof.code arguments continuation before) trace after := by
  rw [same_target_code world pointer native proof nativeTarget proofTarget] at nativeExecution
  exact nativeExecution

/-- Identity transport preserves the complete imported effect relation. -/
theorem queried_effect_preserved (world : CC.CGenv) (native proof : Prototype)
    (arguments : List CC.Val) (before after : CC.Mem) (trace : CC.Trace) (value : CC.Val)
    (sameCode : native.code = proof.code)
    (nativeExecution : Effect world native arguments before trace value after) :
    Effect world proof arguments before trace value after := by
  simpa only [Effect, sameCode] using nativeExecution

/-- The current mature Clight external-call rule has a returning outcome.
Successful kernel tail transfer therefore needs its own native/B relation;
it is not a returning helper case silently covered by Effect. -/
theorem external_step_returns (world : CC.CGenv)
    (external : CC.ExtFun) (types : List CC.Ty) (result : CC.Ty)
    (convention : CC.CallConv) (arguments : List CC.Val) (continuation : CC.Cont)
    (before : CC.Mem) (trace : CC.Trace) (after : CC.State)
    (transition : CC.Step2 world
      (.Callstate (.External external types result convention) arguments continuation before)
      trace after) :
    ∃ value memory, after = .Returnstate value continuation memory := by
  cases transition with
  | external_function ef targs tres cconv vargs k m vres t m' call =>
    exact ⟨vres, m', rfl⟩

end KProgFormal.ControlABI.HelperQuery

#print axioms KProgFormal.ControlABI.HelperQuery.extension_callback
#print axioms KProgFormal.ControlABI.HelperQuery.binding_prototype
#print axioms KProgFormal.ControlABI.HelperQuery.typed_call_enters
