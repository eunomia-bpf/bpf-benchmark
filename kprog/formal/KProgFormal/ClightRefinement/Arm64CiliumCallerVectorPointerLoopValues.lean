import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSource
import KProgFormal.ClightRefinement.Arm64ProducerVectorLoop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopValues
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (ge allocation)
open Arm64CiliumCallerVectorPointerLoopSource
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerVectorSource (Storage vectorType vectorArrayType)

-- These arithmetic expressions have no old producer heap or allocation dependency.
def headerPointerOffset := Arm64Producer.vectorLoopHeaderOffset
def vectorPointerOffset := Arm64Producer.vectorLoopSourceOffset

theorem offsets (high : Bool) (i : Fin 32) :
    CC.Integers.Ptrofs.unsigned (headerPointerOffset high i) = headerOffset high i ∧
    CC.Integers.Ptrofs.unsigned (vectorPointerOffset high i) =
      16*(i.val : Int)+(if high then 8 else 0) :=
  Arm64Producer.vector_loop_offsets high i

private theorem base_offsets : ∀ (high : Bool) (i : Fin 32),
    Arm64CiliumCallerHeaderVectorNullSource.baseOffset (slot high i) =
      (if high then 352 else 96) := by decide +kernel

private theorem add_index_address (world : CC.CGenv) (env : CC.Env) (le : CC.TempEnv)
    (before : CC.Mem) (a : CC.Expr) (cell : CC.Ty) (n : BitVec 32)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (found : CC.doEvalExpr world env le before a = some (.Vptr b ofs))
    (typed : CC.typeof a = CC.tarray cell 32)
    (indexFound : le.get _i = some (.Vint n)) :
    CC.doEvalExpr world env le before (.Ebinop .Oadd a index (CC.tptr cell)) =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs
        (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr (CC.sizeof world.genv_cenv cell))
          (CC.Cop.ptrofsOfInt .Unsigned n)))) := by
  simp only [CC.doEvalExpr,index,found,indexFound]
  rw [typed]
  rfl

private theorem deref_location (world : CC.CGenv) (env : CC.Env) (le : CC.TempEnv)
    (before : CC.Mem) (a : CC.Expr) (cell : CC.Ty) (b : CC.Block)
    (ofs : CC.Integers.Ptrofs)
    (value : CC.doEvalExpr world env le before a = some (.Vptr b ofs)) :
    CC.doEvalLvalue world env le before (.Ederef a cell) = some (b,ofs,.Full) := by
  simp only [CC.doEvalLvalue,value]

/-- The actual caller header binding and unsigned loop index yield each lvalue. -/
theorem target_locations {m : CC.Mem} (header : Header m) (le : CC.TempEnv)
    (before : CC.Mem) (high : Bool) (i : Fin 32)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalLvalue ge (allocation m).1 le before (lhs high) =
      some (header.block,headerPointerOffset high i,.Full) := by
  have arrayValue := Arm64CiliumCallerHeaderVectorNullSource.array_values
    header le before (slot high i)
  rw [Arm64CiliumCallerHeaderVectorNullSource.arrayExpr,
    (header_slots high i).2,base_offsets high i] at arrayValue
  have added := add_index_address ge (allocation m).1 le before _ pointerType
    (CC.Integers.Int.repr i.val) header.block _ arrayValue rfl indexFound
  have location := deref_location ge (allocation m).1 le before _ pointerType
    header.block _ added
  simpa [lhs,Arm64CiliumCallerHeaderVectorNullSource.arrayType,
    Arm64CiliumCallerHeaderVectorNullSource.pointerType,pointerType,CC.tptr,CC.sizeof,
    CC.Archi.ptr64,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,headerPointerOffset,
    Arm64Producer.vectorLoopHeaderOffset,CC.Cop.ptrofsOfInt] using location

private theorem array_address (world : CC.CGenv) (env : CC.Env) (le : CC.TempEnv)
    (before : CC.Mem) (id : CC.Ident) (cell : CC.Ty) (b : CC.Block)
    (binding : env.get id = some (b,CC.tarray cell 32)) :
    CC.doEvalExpr world env le before (.Evar id (CC.tarray cell 32)) =
      some (.Vptr b 0) := by
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  rfl

private theorem deref_record (world : CC.CGenv) (env : CC.Env) (le : CC.TempEnv)
    (before : CC.Mem) (a : CC.Expr) (cell : CC.Ty) (b : CC.Block)
    (ofs : CC.Integers.Ptrofs)
    (value : CC.doEvalExpr world env le before a = some (.Vptr b ofs))
    (byCopy : CC.accessMode cell = .By_copy) :
    CC.doEvalExpr world env le before (.Ederef a cell) = some (.Vptr b ofs) := by
  change (match CC.doEvalExpr world env le before a with
    | some (.Vptr block offset) => CC.doDerefLoc cell before block offset .Full
    | _ => none) = _
  rw [value]
  simp only [CC.doDerefLoc,byCopy]

private theorem field_address (world : CC.CGenv) (env : CC.Env) (le : CC.TempEnv)
    (before : CC.Mem) (a : CC.Expr) (tag field : CC.Ident) (composite : CC.Composite)
    (delta : Int) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (value : CC.doEvalExpr world env le before a = some (.Vptr b ofs))
    (typed : CC.typeof a = .Tstruct tag CC.noattr)
    (binding : world.genv_cenv.get tag = some composite)
    (location : CC.fieldOffset world.genv_cenv field composite.co_members = .OK (delta,.Full)) :
    CC.doEvalExpr world env le before
      (.Eaddrof (.Efield a field CC.tulong) pointerType) =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr delta))) := by
  simp only [CC.doEvalExpr,CC.doEvalLvalue,value,typed,CC.lvalOfField,binding,location]

/-- Addresses come from the SAME caller's vector allocation; no pointee load is assumed. -/
theorem source_values {m : CC.Mem} (vectors : Storage m) (le : CC.TempEnv)
    (before : CC.Mem) (high : Bool) (i : Fin 32)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before (rhs high) =
      some (.Vptr vectors.block (vectorPointerOffset high i)) := by
  obtain ⟨shape⟩ := Arm64CiliumCallerVectorSource.layout
  have low : CC.fieldOffset ge.genv_cenv _lo shape.composite.co_members = .OK (0,.Full) :=
    shape.offsets 0
  have highField : CC.fieldOffset ge.genv_cenv _hi shape.composite.co_members = .OK (8,.Full) :=
    shape.offsets 1
  have actualBinding : (allocation m).1.get ___a64_vectors =
      some (vectors.block,vectorArrayType) := vectors.binding
  have arrayValue := array_address ge (allocation m).1 le before
    ___a64_vectors vectorType vectors.block actualBinding
  have added := add_index_address ge (allocation m).1 le before _ vectorType
    (CC.Integers.Int.repr i.val) vectors.block 0 arrayValue rfl indexFound
  have size : CC.sizeof ge.genv_cenv vectorType = 16 := by
    simpa only [vectorType,Arm64Producer.vectorTypeFor,CC.sizeof,shape.binding] using shape.size
  rw [size] at added
  have objectValue := deref_record ge (allocation m).1 le before _ vectorType
    vectors.block _ added rfl
  have fieldOffset : CC.fieldOffset ge.genv_cenv (if high then _hi else _lo)
      shape.composite.co_members = .OK ((if high then 8 else 0),.Full) := by
    cases high
    · exact low
    · exact highField
  have address := field_address ge (allocation m).1 le before _
    Arm64CiliumCallerVectorSource.vectorTag (if high then _hi else _lo) shape.composite
    (if high then 8 else 0) vectors.block _ objectValue rfl shape.binding fieldOffset
  simpa only [rhs,vectorArrayType,Arm64Producer.vectorArrayTypeFor,vectorType,Arm64Producer.vectorTypeFor,vectorPointerOffset,Arm64Producer.vectorLoopSourceOffset,CC.Cop.ptrofsOfInt] using address

theorem condition_values {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem) (i : Fin 33)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before condition =
      some (.Vint (if i.val < 32 then 1 else 0)) := by
  simp only [condition,index,CC.doEvalExpr,indexFound]
  change some (CC.Val.ofBool
    (CC.Integers.Int.cmpu .Clt (CC.Integers.Int.repr i.val) (32#32))) = _
  have arithmetic : ∀ j : Fin 33,CC.Val.ofBool
      (CC.Integers.Int.cmpu .Clt (CC.Integers.Int.repr j.val) (32#32)) =
      CC.Val.Vint (if j.val < 32 then 1 else 0) := by decide +kernel
  rw [arithmetic]

theorem increment_values {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem) (i : Fin 32)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd index (.Econst_int (1#32) CC.tint) CC.tuint) =
      some (.Vint (CC.Integers.Int.repr (i.val+1))) := by
  simp only [index,CC.doEvalExpr,indexFound]
  change some (CC.Val.Vint (CC.Integers.Int.add (CC.Integers.Int.repr i.val) (1#32))) = _
  have arithmetic : ∀ j : Fin 32,CC.Integers.Int.add (CC.Integers.Int.repr j.val) (1#32) =
      CC.Integers.Int.repr (j.val+1) := by decide +kernel
  rw [arithmetic]

theorem assignment (before : CC.Mem) (high : Bool) (b : CC.Block) (ofs : CC.Integers.Ptrofs) :
    CC.accessMode pointerType = .By_value .Mint64 ∧
    CC.Cop.semCast (.Vptr b ofs) (CC.typeof (rhs high)) pointerType before =
      some (.Vptr b ofs) := by
  constructor <;> rfl

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopValues
