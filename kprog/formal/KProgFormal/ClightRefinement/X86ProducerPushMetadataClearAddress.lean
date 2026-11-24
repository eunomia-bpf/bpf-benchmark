import KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress
open X86ProducerLayout (ge)
open X86ProducerPushMetadataClearSource (headerType valueType field)

private theorem values_field (binding : CC.Block) :
    CC.lvalOfField ge headerType X86_program_profile_bpf._values (.Vptr binding 0) = some (binding, (16#64), .Full) := by
  simp only [headerType, X86ProducerHeaderSource.headerType, CC.lvalOfField, X86ProducerLayout.layouts.1,
    X86ProducerHeaderAddress.values_offset ge.genv_cenv X86ProducerLayout.layouts.2.1]
  rfl

private theorem tag_field (binding : CC.Block) :
    CC.lvalOfField ge valueType X86_program_profile_bpf._tag (.Vptr binding (96#64)) = some (binding, (96#64), .Full) := by
  have offset : CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._tag X86ShiftLeftCarry.valueRecord.co_members = .OK (0, .Full) :=
    X86ProducerHeaderAddress.ghost_offset ge.genv_cenv false
  simp only [valueType, CC.lvalOfField, X86ProducerLayout.layouts.2.1, offset]
  rfl

private theorem pointer_field (binding : CC.Block) :
    CC.lvalOfField ge valueType X86_program_profile_bpf._pointer (.Vptr binding (96#64)) = some (binding, (104#64), .Full) := by
  have offset : CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._pointer X86ShiftLeftCarry.valueRecord.co_members = .OK (8, .Full) :=
    X86ProducerHeaderAddress.ghost_offset ge.genv_cenv true
  simp only [valueType, CC.lvalOfField, X86ProducerLayout.layouts.2.1, offset]
  rfl

private theorem add (memory : CC.Mem) (binding : CC.Block) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr binding (16#64)) (CC.tarray valueType 6)
      (.Vint (CC.Integers.Int.repr 5)) CC.tint memory = some (.Vptr binding (96#64)) := by
  simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tarray, CC.tint, valueType, CC.sizeof, X86ProducerLayout.layouts.2.1]
  rfl

private def table : CC.Expr := .Efield (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType)
  X86_program_profile_bpf._values (CC.tarray valueType 6)
private def item : CC.Expr := .Ederef (.Ebinop .Oadd table (.Econst_int (CC.Integers.Int.repr 5) CC.tint) (CC.tptr valueType)) valueType
private theorem field_shape (name : CC.Ident) (ty : CC.Ty) : field name ty = .Efield item name ty := rfl

private theorem table_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0)) :
    CC.doEvalExpr ge e le memory table = some (.Vptr binding (16#64)) := by
  have base : CC.doEvalExpr ge e le memory
      (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType) = some (.Vptr binding 0) := by
    simp only [CC.doEvalExpr, bound]
    rfl
  rw [table, CC.doEvalExpr, base]
  change (match CC.lvalOfField ge headerType X86_program_profile_bpf._values (.Vptr binding 0) with
    | some (b,ofs,bf) => CC.doDerefLoc (CC.tarray valueType 6) memory b ofs bf
    | none => none) = _
  rw [values_field]
  rfl

private theorem item_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0)) :
    CC.doEvalExpr ge e le memory item = some (.Vptr binding (96#64)) := by
  rw [item, CC.doEvalExpr, CC.doEvalExpr, table_value e le memory binding bound]
  change (match CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr binding (16#64))
    (CC.tarray valueType 6) (.Vint (CC.Integers.Int.repr 5)) CC.tint memory with
    | some (.Vptr b ofs) => CC.doDerefLoc valueType memory b ofs .Full
    | _ => none) = _
  rw [add]
  rfl

/-- The actual slot5 metadata pointer loads address original header bytes96
and104. Both values derive real current typed header loads in the same heap. -/
theorem tag_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding tagBlock : CC.Block) (tagOffset : CC.Integers.Ptrofs)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (read : CC.Mem.load CC.Mptr memory binding 96 = some (.Vptr tagBlock tagOffset)) :
    CC.doEvalExpr ge e le memory X86ProducerPushMetadataClearSource.tagExpression = some (.Vptr tagBlock tagOffset) := by
  rw [X86ProducerPushMetadataClearSource.reads.2.2.1, field_shape, CC.doEvalExpr, item_value e le memory binding bound]
  change (match CC.lvalOfField ge valueType X86_program_profile_bpf._tag (.Vptr binding (96#64)) with
    | some (b,ofs,bf) => CC.doDerefLoc (CC.tptr CC.tuchar) memory b ofs bf
    | none => none) = _
  rw [tag_field]
  exact read

theorem pointer_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding pointerBlock : CC.Block) (pointerOffset : CC.Integers.Ptrofs)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (read : CC.Mem.load CC.Mptr memory binding 104 = some (.Vptr pointerBlock pointerOffset)) :
    CC.doEvalExpr ge e le memory X86ProducerPushMetadataClearSource.pointerExpression = some (.Vptr pointerBlock pointerOffset) := by
  rw [X86ProducerPushMetadataClearSource.reads.2.2.2, field_shape, CC.doEvalExpr, item_value e le memory binding bound]
  change (match CC.lvalOfField ge valueType X86_program_profile_bpf._pointer (.Vptr binding (96#64)) with
    | some (b,ofs,bf) => CC.doDerefLoc (CC.tptr (CC.tptr CC.tvoid)) memory b ofs bf
    | none => none) = _
  rw [pointer_field]
  exact read

end KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress
