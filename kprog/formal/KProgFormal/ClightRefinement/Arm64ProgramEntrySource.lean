import KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation
import KProgFormal.ClightRefinement.Arm64ProducerLifetime

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntrySource

open Arm64ProgramEntryAllocation (localName)

/-- Extend the declaration map through the actual pointer/array type syntax.
Function signatures in this source prefix contain no anonymous local types. -/
def sourceType : CC.Ty → CC.Ty
  | .Tpointer ty attr => .Tpointer (sourceType ty) attr
  | .Tarray ty size attr => .Tarray (sourceType ty) size attr
  | .Tstruct id attr =>
      .Tstruct (if id = Arm64Entry.__2854 then Arm64ProgramFixture.__5183 else id) attr
  | .Tunion id attr =>
      .Tunion (if id = Arm64Entry.__2856 then Arm64ProgramFixture.__5185 else id) attr
  | ty => ty

/-- Initialization omits the consumer-only return temporary. -/
def initializationTemps : List (CC.Ident × CC.Ty) :=
  Arm64Producer.producer.fn_temps.filter (fun row => row.1 != Arm64Entry._t'131)

/-- Generated identifier ordinals are relative to each export unit's atom
frontier. All real mapped declaration types and distinctness are checked below. -/
def temporaryName (id : CC.Ident) : CC.Ident :=
  if Arm64Entry._t'1.toNat ≤ id.toNat ∧ id.toNat ≤ Arm64Entry._t'130.toNat then
    CC.Positive.ofNat (Arm64ProgramFixture._t'1.toNat + (id.toNat - Arm64Entry._t'1.toNat))
  else id

/-- Every mapped initialization temporary has its real declared target type. -/
theorem temporary_types : ∀ i : Fin initializationTemps.length,
    (temporaryName initializationTemps[i].1, sourceType initializationTemps[i].2) ∈
      Arm64ProgramFixture.f_arm64_execute_compile.fn_temps := by decide +kernel

/-- The actual target declarations introduce no alias between source temporaries. -/
theorem temporary_names_distinct :
    CC.listNorepet (initializationTemps.map (fun row => temporaryName row.1)) := by decide +kernel

/-- The producer accepts void*, while the actual socket program declares a
__sk_buff* parameter. Both expressions refer to the same supplied value. -/
def expression : CC.Expr → CC.Expr
  | .Econst_int n ty => .Econst_int n (sourceType ty)
  | .Econst_float n ty => .Econst_float n (sourceType ty)
  | .Econst_single n ty => .Econst_single n (sourceType ty)
  | .Econst_long n ty => .Econst_long n (sourceType ty)
  | .Evar id ty => .Evar (localName id) (sourceType ty)
  | .Etempvar id ty => .Etempvar (temporaryName id)
      (if id = Arm64Entry._ctx then CC.tptr (.Tstruct Arm64ProgramFixture.___sk_buff CC.noattr)
       else sourceType ty)
  | .Ederef a ty => .Ederef (expression a) (sourceType ty)
  | .Eaddrof a ty => .Eaddrof (expression a) (sourceType ty)
  | .Eunop op a ty => .Eunop op (expression a) (sourceType ty)
  | .Ebinop op a b ty => .Ebinop op (expression a) (expression b) (sourceType ty)
  | .Ecast a ty => .Ecast (expression a) (sourceType ty)
  | .Efield a field ty => .Efield (expression a) field (sourceType ty)
  | .Esizeof ty result => .Esizeof (sourceType ty) (sourceType result)
  | .Ealignof ty result => .Ealignof (sourceType ty) (sourceType result)

mutual
def statement : CC.Stmt → CC.Stmt
  | .Sskip => .Sskip
  | .Sassign a b => .Sassign (expression a) (expression b)
  | .Sset id a => .Sset (temporaryName id) (expression a)
  | .Scall id a args => .Scall (id.map temporaryName) (expression a) (args.map expression)
  | .Sbuiltin id ef tys args => .Sbuiltin (id.map temporaryName) ef (tys.map sourceType) (args.map expression)
  | .Ssequence a b => .Ssequence (statement a) (statement b)
  | .Sifthenelse a b c => .Sifthenelse (expression a) (statement b) (statement c)
  | .Sloop a b => .Sloop (statement a) (statement b)
  | .Sbreak => .Sbreak
  | .Scontinue => .Scontinue
  | .Sreturn a => .Sreturn (a.map expression)
  | .Sswitch a cases => .Sswitch (expression a) (labeled cases)
  | .Slabel id a => .Slabel id (statement a)
  | .Sgoto id => .Sgoto id

def labeled : CC.LStmts → CC.LStmts
  | .LSnil => .LSnil
  | .LScons label s rest => .LScons label (statement s) (labeled rest)
end

/-- Small source equations compose without expanding the whole initialization
spine in a single kernel comparison. Every segment retains its actual tail. -/
inductive Spine : CC.Stmt → List (List CC.Stmt) → CC.Stmt → Prop
  | nil (last : CC.Stmt) : Spine last [] last
  | step (first next last : CC.Stmt) (rows : List CC.Stmt) (rest : List (List CC.Stmt))
      (source : first = rows.foldr CC.Stmt.Ssequence next) (tail : Spine next rest last) :
      Spine first (rows :: rest) last

def plug (rows : List (List CC.Stmt)) (last : CC.Stmt) : CC.Stmt :=
  rows.foldr (fun segment tail => segment.foldr CC.Stmt.Ssequence tail) last

theorem Spine.reconstruct {first last : CC.Stmt} {rows : List (List CC.Stmt)}
    (spine : Spine first rows last) : first = plug rows last := by
  induction spine with
  | nil => rfl
  | step first next last rows rest source tail ih =>
    change first = rows.foldr CC.Stmt.Ssequence (plug rest last)
    rw [source, ih]

/-- Pointwise source equalities keep kernel comparisons local to one statement. -/
private inductive Mapped {α β : Type} (f : α → β) : List α → List β → Prop
  | nil : Mapped f [] []
  | cons (a : α) (b : β) (as : List α) (bs : List β)
      (head : b = f a) (tail : Mapped f as bs) : Mapped f (a :: as) (b :: bs)

private theorem Mapped.sound {α β : Type} {f : α → β} {as : List α} {bs : List β}
    (proof : Mapped f as bs) : bs = as.map f := by
  induction proof with
  | nil => rfl
  | cons a b as bs head tail ih => simp only [List.map_cons, head, ih]

/-- Cache references and kernel-checked small equations for the two actual
exports. No C body, initialization effect or continuation is synthesized. -/
private def parts : { rows : List (List CC.Stmt) × (List (List CC.Stmt) × CC.Stmt) //
    Spine Arm64Producer.producer.fn_body rows.1 Arm64Producer.afterVectorLoop ∧
    Spine Arm64ProgramFixture.f_arm64_execute_compile.fn_body rows.2.1 rows.2.2 ∧
    Mapped (List.map statement) rows.1 rows.2.1 } := by
  run_tac do
    let sourceStart ← Lean.Elab.Term.elabTerm (← `(Arm64Producer.producer.fn_body)) none
    let sourceLast ← Lean.Elab.Term.elabTerm (← `(Arm64Producer.afterVectorLoop)) none
    let target ← Lean.Elab.Term.elabTerm (← `(Arm64Entry._continuation)) none
    let mut source := sourceStart
    let mut front : Array Lean.Expr := #[]
    while true do
      let normalizedBody ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source)
      unless normalizedBody.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer no longer ends at its actual consumer call"
      let head := normalizedBody.getAppArgs[0]!
      let normalized ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head)
      let mut boundary := false
      if normalized.isAppOfArity ``CC.Stmt.Scall 3 then
        let callee ← Lean.Meta.withTransparency .all (Lean.Meta.whnf normalized.getAppArgs[1]!)
        if callee.isAppOfArity ``CC.Expr.Etempvar 2 then
          boundary ← Lean.Meta.isDefEq callee.getAppArgs[0]! target
      if boundary then break
      front := front.push head
      source := normalizedBody.getAppArgs[1]!
    let stmtTy := Lean.mkConst ``CC.Stmt
    let segmentTy ← Lean.Meta.mkAppM ``List #[stmtTy]
    let build := fun (start last : Lean.Expr) (count : Nat) => do
      let mut current := start
      let mut segments : Array (Lean.Expr × Lean.Expr × Lean.Expr) := #[]
      let mut remaining := count
      while remaining > 0 do
        let segmentStart := current
        let mut heads : Array Lean.Expr := #[]
        for _ in [:min 32 remaining] do
          let normalized ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
          unless normalized.isAppOfArity ``CC.Stmt.Ssequence 2 do
            throwError "actual source prefix shorter than producer initialization"
          heads := heads.push normalized.getAppArgs[0]!
          current := normalized.getAppArgs[1]!
        segments := segments.push
          (segmentStart, (← Lean.Meta.mkListLit stmtTy heads.toList), current)
        remaining := remaining - heads.size
      let mut rows ← Lean.Meta.mkListLit segmentTy []
      let mut proof ← Lean.Meta.mkAppM ``Spine.nil #[last]
      for (first, heads, next) in segments.toList.reverse do
        let rhs ← Lean.Meta.mkAppM ``List.foldr
          #[Lean.mkConst ``CC.Stmt.Ssequence, next, heads]
        let equal ← Lean.Meta.mkEqRefl rhs
        proof ← Lean.Meta.mkAppM ``Spine.step #[first, next, last, heads, rows, equal, proof]
        rows ← Lean.Meta.mkAppM ``List.cons #[heads, rows]
      return (rows, proof, current)
    let (sourceRows, sourceProof, _) ← build sourceStart sourceLast front.size
    let actualStart ← Lean.Elab.Term.elabTerm
      (← `(Arm64ProgramFixture.f_arm64_execute_compile.fn_body)) none
    let mut actual := actualStart
    for _ in [:front.size] do
      let normalized ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual)
      unless normalized.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual program initialization spine changed"
      actual := normalized.getAppArgs[1]!
    let (actualRows, actualProof, _) ← build actualStart actual front.size
    let rest ← Lean.Meta.mkAppM ``Prod.mk #[actualRows, actual]
    let data ← Lean.Meta.mkAppM ``Prod.mk #[sourceRows, rest]
    let unpack := fun (input : Lean.Expr) => do
      let mut current := input
      let mut values : Array Lean.Expr := #[]
      while true do
        let normalized ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
        if normalized.isAppOfArity ``List.nil 1 then return values
        unless normalized.isAppOfArity ``List.cons 3 do throwError "expected actual source list"
        values := values.push normalized.getAppArgs[1]!
        current := normalized.getAppArgs[2]!
      return values
    let prove := fun (f xs ys : Lean.Expr) (heads : Array Lean.Expr) => do
      let sourceValues ← unpack xs
      let actualValues ← unpack ys
      unless sourceValues.size == actualValues.size && sourceValues.size == heads.size do
        throwError "source segment lengths differ"
      let sourceTy ← Lean.Meta.inferType sourceValues[0]!
      let actualTy ← Lean.Meta.inferType actualValues[0]!
      let mut as ← Lean.Meta.mkListLit sourceTy []
      let mut bs ← Lean.Meta.mkListLit actualTy []
      let mut proof := Lean.mkAppN (Lean.mkConst ``Mapped.nil) #[sourceTy, actualTy, f]
      for i in (List.range sourceValues.size).reverse do
        proof := Lean.mkAppN (Lean.mkConst ``Mapped.cons)
          #[sourceTy, actualTy, f, sourceValues[i]!, actualValues[i]!, as, bs, heads[i]!, proof]
        as ← Lean.Meta.mkAppM ``List.cons #[sourceValues[i]!, as]
        bs ← Lean.Meta.mkAppM ``List.cons #[actualValues[i]!, bs]
      return proof
    let sourceSegments ← unpack sourceRows
    let actualSegments ← unpack actualRows
    let mut equations : Array Lean.Expr := #[]
    for i in [:sourceSegments.size] do
      let sources ← unpack sourceSegments[i]!
      let mut headProofs : Array Lean.Expr := #[]
      for j in [:sources.size] do
        let image ← Lean.Meta.mkAppM ``statement #[sources[j]!]
        headProofs := headProofs.push (← Lean.Meta.mkEqRefl image)
      let proof ← prove (Lean.mkConst ``statement) sourceSegments[i]! actualSegments[i]! headProofs
      equations := equations.push (← Lean.Meta.mkAppM ``Mapped.sound #[proof])
    let mapStatement ← Lean.Elab.Term.elabTerm (← `(List.map statement)) none
    let mapped ← prove mapStatement sourceRows actualRows equations
    let tailValid ← Lean.Meta.mkAppM ``And.intro #[actualProof, mapped]
    let valid ← Lean.Meta.mkAppM ``And.intro #[sourceProof, tailValid]
    let expected ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    unless expected.isAppOfArity ``Subtype 2 do throwError "expected source certificate"
    Lean.Elab.Tactic.closeMainGoal `actual_entry_source_parts
      (← Lean.Meta.mkAppOptM ``Subtype.mk #[some expected.getAppArgs[0]!,
        some expected.getAppArgs[1]!, some data, some valid])

def initialization : List (List CC.Stmt) := parts.val.1
def actualInitialization : List (List CC.Stmt) := parts.val.2.1
def body : CC.Stmt := parts.val.2.2

theorem producer_source : Spine Arm64Producer.producer.fn_body
    initialization Arm64Producer.afterVectorLoop := parts.property.1

theorem production_source : Spine Arm64ProgramFixture.f_arm64_execute_compile.fn_body
    actualInitialization body := parts.property.2.1

/-- Every original initialization expression and statement is compared,
including all input calls and the live vector-pointer loop. -/
theorem prefix_corresponds : actualInitialization = initialization.map (List.map statement) :=
  Mapped.sound parts.property.2.2

end KProgFormal.ClightRefinement.Arm64ProgramEntrySource
