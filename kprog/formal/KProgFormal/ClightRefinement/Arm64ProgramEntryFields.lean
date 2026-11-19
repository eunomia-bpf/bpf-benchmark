import KProgFormal.ClightRefinement.Arm64ProgramEntryExpressions

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryFields

open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntrySource (sourceType expression)

private theorem member_layout (first second : CC.CompositeEnv) (row : CC.Member)
    (sizes : CC.sizeof first row.type = CC.sizeof second row.type)
    (alignments : CC.alignof first row.type = CC.alignof second row.type) (position : Int) :
    CC.layoutField first position row = CC.layoutField second position row ∧
    CC.nextField first position row = CC.nextField second position row := by
  cases row with
  | Member_plain name ty =>
    simp only [CC.Member.type] at sizes alignments
    simp only [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof, sizes, alignments]
    trivial
  | Member_bitfield => exact ⟨rfl, rfl⟩

/-- Agreement on the member sizes/alignment suffices. The environments may
contain different composite names elsewhere, and unknown fields retain Error. -/
theorem struct_offsets (first second : CC.CompositeEnv) (rows : List CC.Member)
    (agree : ∀ row ∈ rows, CC.sizeof first row.type = CC.sizeof second row.type ∧
      CC.alignof first row.type = CC.alignof second row.type) (field : CC.Ident) (position : Int) :
    CC.fieldOffsetRec first field position rows = CC.fieldOffsetRec second field position rows := by
  induction rows generalizing position with
  | nil => rfl
  | cons row rest ih =>
    have matched := member_layout first second row
      (agree row List.mem_cons_self).1 (agree row List.mem_cons_self).2 position
    simp only [CC.fieldOffsetRec, matched.1, matched.2]
    split
    · rfl
    · exact ih (fun row present => agree row (List.mem_cons_of_mem _ present)) _

theorem union_offsets (first second : CC.CompositeEnv) (rows : List CC.Member)
    (agree : ∀ row ∈ rows, CC.sizeof first row.type = CC.sizeof second row.type ∧
      CC.alignof first row.type = CC.alignof second row.type) (field : CC.Ident) :
    CC.unionFieldOffset first field rows = CC.unionFieldOffset second field rows := by
  induction rows with
  | nil => rfl
  | cons row rest ih =>
    have matched := (member_layout first second row
      (agree row List.mem_cons_self).1 (agree row List.mem_cons_self).2 0).1
    simp only [CC.unionFieldOffset, matched]
    split
    · rfl
    · exact ih (fun row present => agree row (List.mem_cons_of_mem _ present))

def sourceName (i : Fin 5) : CC.Ident :=
  [Arm64Entry._kprog_arm64_entry, Arm64Entry.__2854, Arm64Entry.__2856,
   Arm64Entry._arm64_sim_gpr, Arm64Entry._arm64_sim_skb_abi][i]
def actualName (i : Fin 5) : CC.Ident :=
  [Arm64ProgramFixture._kprog_arm64_entry, Arm64ProgramFixture.__5183,
   Arm64ProgramFixture.__5185, Arm64ProgramFixture._arm64_sim_gpr,
   Arm64ProgramFixture._arm64_sim_skb_abi][i]
def isUnion (i : Fin 5) : Prop := i = 2 ∨ i = 3
instance (i : Fin 5) : Decidable (isUnion i) := inferInstanceAs (Decidable (i = 2 ∨ i = 3))
def attributes (i : Fin 5) : CC.Attr :=
  if i = 2 then { CC.noattr with attr_volatile := true } else CC.noattr
def compositeType (i : Fin 5) : CC.Ty :=
  if isUnion i then .Tunion (sourceName i) (attributes i)
  else .Tstruct (sourceName i) (attributes i)

private theorem present : ∀ i : Fin 5,
    (Arm64Producer.ge.genv_cenv.get (sourceName i)).isSome = true := by decide +kernel
private def composite (i : Fin 5) : CC.Composite :=
  (Arm64Producer.ge.genv_cenv.get (sourceName i)).get (present i)

/-- Complete real composite records agree for the entry, vector lane, stack,
GPR union and RAW ABI. No whole composite-environment equality is required. -/
theorem layouts : ∀ i : Fin 5,
    Arm64Producer.ge.genv_cenv.get (sourceName i) = some (composite i) ∧
    world.genv_cenv.get (actualName i) = some (composite i) := by decide +kernel

private theorem mapped_type : ∀ i : Fin 5, sourceType (compositeType i) =
    if isUnion i then .Tunion (actualName i) (attributes i)
    else .Tstruct (actualName i) (attributes i) := by decide +kernel

private theorem member_sizes : ∀ (i : Fin 5) (j : Fin (composite i).co_members.length),
    CC.sizeof world.genv_cenv (composite i).co_members[j].type =
      CC.sizeof Arm64Producer.ge.genv_cenv (composite i).co_members[j].type ∧
    CC.alignof world.genv_cenv (composite i).co_members[j].type =
      CC.alignof Arm64Producer.ge.genv_cenv (composite i).co_members[j].type := by decide +kernel

private theorem members_agree (i : Fin 5) : ∀ row ∈ (composite i).co_members,
    CC.sizeof world.genv_cenv row.type = CC.sizeof Arm64Producer.ge.genv_cenv row.type ∧
    CC.alignof world.genv_cenv row.type = CC.alignof Arm64Producer.ge.genv_cenv row.type := by
  intro row present
  obtain ⟨j, rfl⟩ := List.mem_iff_get.mp present
  exact member_sizes i j

/-- Any field name and value are admitted. Nonpointers and unknown fields
retain failure, while successful field addresses retain the exact offset/bitfield. -/
theorem field_address (i : Fin 5) (field : CC.Ident) (value : CC.Val) :
    CC.lvalOfField world (sourceType (compositeType i)) field value =
      CC.lvalOfField Arm64Producer.ge (compositeType i) field value := by
  unfold CC.lvalOfField
  cases value with
  | Vundef => rfl
  | Vint _ => rfl
  | Vlong _ => rfl
  | Vfloat _ => rfl
  | Vsingle _ => rfl
  | Vptr block offset =>
    rw [mapped_type i]
    by_cases kind : isUnion i
    · simp only [compositeType, kind, ite_true, (layouts i).1, (layouts i).2]
      rw [union_offsets world.genv_cenv Arm64Producer.ge.genv_cenv _ (members_agree i)]
    · simp only [compositeType, kind, ite_false, (layouts i).1, (layouts i).2]
      simp only [CC.fieldOffset]
      rw [struct_offsets world.genv_cenv Arm64Producer.ge.genv_cenv _ (members_agree i)]

private theorem dereference_type (ty : CC.Ty) (m : CC.Mem) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (bits : CC.Bitfield) :
    CC.doDerefLoc (sourceType ty) m block offset bits = CC.doDerefLoc ty m block offset bits := by
  cases bits <;> cases ty <;> rfl

/-- Lift an already established base-expression correspondence through the
actual field address operation. Temps may differ between the two programs. -/
theorem field_lvalue (i : Fin 5) (base : CC.Expr) (field : CC.Ident) (result : CC.Ty)
    (source actual : CC.Env) (sourceTemps actualTemps : CC.TempEnv) (m : CC.Mem)
    (baseType : CC.typeof base = compositeType i)
    (actualType : CC.typeof (expression base) = sourceType (compositeType i))
    (evaluated : CC.doEvalExpr world actual actualTemps m (expression base) =
      CC.doEvalExpr Arm64Producer.ge source sourceTemps m base) :
    CC.doEvalLvalue world actual actualTemps m (expression (.Efield base field result)) =
      CC.doEvalLvalue Arm64Producer.ge source sourceTemps m (.Efield base field result) := by
  simp only [expression, CC.doEvalLvalue, evaluated, baseType, actualType]
  cases CC.doEvalExpr Arm64Producer.ge source sourceTemps m base with
  | none => rfl
  | some value => exact field_address i field value

/-- Field reads preserve successful results and all lookup/read failures,
including bitfield results. No valid/readable-memory hypothesis is added. -/
theorem field_read (i : Fin 5) (base : CC.Expr) (field : CC.Ident) (result : CC.Ty)
    (source actual : CC.Env) (sourceTemps actualTemps : CC.TempEnv) (m : CC.Mem)
    (baseType : CC.typeof base = compositeType i)
    (actualType : CC.typeof (expression base) = sourceType (compositeType i))
    (evaluated : CC.doEvalExpr world actual actualTemps m (expression base) =
      CC.doEvalExpr Arm64Producer.ge source sourceTemps m base) :
    CC.doEvalExpr world actual actualTemps m (expression (.Efield base field result)) =
      CC.doEvalExpr Arm64Producer.ge source sourceTemps m (.Efield base field result) := by
  simp only [expression, CC.doEvalExpr, evaluated, baseType, actualType]
  cases CC.doEvalExpr Arm64Producer.ge source sourceTemps m base with
  | none => rfl
  | some value =>
    dsimp only
    rw [field_address i field value]
    cases CC.lvalOfField Arm64Producer.ge (compositeType i) field value with
    | none => rfl
    | some location =>
      rcases location with ⟨block, offset, bits⟩
      exact dereference_type result m block offset bits

/-- The actual allocated entry header discharges the base-expression premise.
Both temporary environments and the subsequent memory remain arbitrary. -/
theorem allocated_header (initial m : CC.Mem) (sourceTemps actualTemps : CC.TempEnv)
    (field : CC.Ident) (result : CC.Ty) :
    CC.doEvalLvalue world (Arm64ProgramEntryAllocation.allocation initial).1 actualTemps m
        (expression (.Efield (.Evar Arm64Entry._entry Arm64Producer.headerType) field result)) =
      CC.doEvalLvalue Arm64Producer.ge (Arm64Producer.allocation initial).1 sourceTemps m
        (.Efield (.Evar Arm64Entry._entry Arm64Producer.headerType) field result) ∧
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 actualTemps m
        (expression (.Efield (.Evar Arm64Entry._entry Arm64Producer.headerType) field result)) =
      CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1 sourceTemps m
        (.Efield (.Evar Arm64Entry._entry Arm64Producer.headerType) field result) := by
  obtain ⟨entry⟩ := Arm64Producer.header_local initial
  have typed := Arm64ProgramEntryExpressions.declaration_type
    (Arm64Entry._entry, Arm64Producer.headerType) (by decide +kernel)
  have base := Arm64ProgramEntryExpressions.bound_read _ _
    (Arm64ProgramEntryAllocation.allocation_corresponds initial).2
    Arm64Entry._entry entry.block Arm64Producer.headerType entry.binding typed m actualTemps
  have independent : CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1
      actualTemps m (.Evar Arm64Entry._entry Arm64Producer.headerType) =
      CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1
        sourceTemps m (.Evar Arm64Entry._entry Arm64Producer.headerType) := by
    unfold CC.doEvalExpr
    rfl
  exact ⟨field_lvalue 0 _ field result _ _ sourceTemps actualTemps m
      (by decide +kernel) (by decide +kernel) (base.trans independent),
    field_read 0 _ field result _ _ sourceTemps actualTemps m
      (by decide +kernel) (by decide +kernel) (base.trans independent)⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryFields
