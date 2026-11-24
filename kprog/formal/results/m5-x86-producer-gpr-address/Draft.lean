import KProgFormal.ClightRefinement.X86ProducerGprLayout
import KProgFormal.ClightRefinement.X86ProducerInputReturn

namespace KProgFormal.ClightRefinement.X86ProducerGprAddress
open X86ProducerGprLayout
open X86ProducerLayout (ge)

def registersType : CC.Ty := .Tunion X86_program_profile_bpf._x86_sim_register_cells CC.noattr
def namedType : CC.Ty := .Tstruct X86_program_profile_bpf.__3130 CC.noattr
def gprType : CC.Ty := .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr

def namedBase : CC.Expr := .Efield
  (.Evar X86_program_profile_bpf.___x86_local_gprs registersType)
  (CC.Positive.ofNat 18727075383868559167) namedType

def pointerTarget (i : Fin 16) : CC.Expr :=
  .Efield (.Efield namedBase (fieldName i) gprType) X86_program_profile_bpf._ptr (CC.tptr CC.tvoid)
def tagTarget (i : Fin 16) : CC.Expr := .Efield namedBase (tagName i) CC.tuchar

private theorem named_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block)
    (bound : e.get X86_program_profile_bpf.___x86_local_gprs = some (block, registersType)) :
    CC.doEvalExpr ge e le memory namedBase = some (.Vptr block 0) := by
  have original : CC.doEvalExpr ge e le memory (.Evar X86_program_profile_bpf.___x86_local_gprs registersType) = some (.Vptr block 0) := by
    simp only [CC.doEvalExpr, CC.lvalOfVar, bound, registersType, CC.doDerefLoc, CC.accessMode]
    rfl
  rw [namedBase, CC.doEvalExpr, original]
  simp only [CC.typeof, registersType, CC.lvalOfField, X86ProducerLayout.layouts.2.2.2,
    nested_offsets.1, CC.doDerefLoc, namedType, CC.accessMode]
  rfl

private theorem register_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block) (i : Fin 16)
    (bound : e.get X86_program_profile_bpf.___x86_local_gprs = some (block, registersType)) :
    CC.doEvalExpr ge e le memory (.Efield namedBase (fieldName i) gprType) =
      some (.Vptr block (CC.Integers.Ptrofs.repr (16 * (i.val : Int)))) := by
  have named := named_value e le memory block bound
  rw [CC.doEvalExpr, named]
  simp only [CC.typeof, namedBase, namedType, CC.lvalOfField, source_layouts.1,
    (field_offsets i).1, gprType, CC.doDerefLoc, CC.accessMode]
  change some (CC.Val.Vptr block ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (16 * (i.val : Int)))) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (CC.Val.Vptr block ofs)) (BitVec.zero_add _)

/-- The actual nested named/union pointer target evaluates to the original cell address. -/
theorem pointer_address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block) (i : Fin 16)
    (bound : e.get X86_program_profile_bpf.___x86_local_gprs = some (block, registersType)) :
    CC.doEvalLvalue ge e le memory (pointerTarget i) =
      some (block, CC.Integers.Ptrofs.repr (16 * (i.val : Int)), .Full) := by
  have reg := register_value e le memory block i bound
  rw [pointerTarget, CC.doEvalLvalue, reg]
  simp only [CC.typeof, gprType, CC.lvalOfField, source_layouts.2.1, nested_offsets.2]
  change some (block, CC.Integers.Ptrofs.repr (16 * (i.val : Int)) + (0 : CC.Integers.Ptrofs), CC.Bitfield.Full) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (block, ofs, CC.Bitfield.Full)) (BitVec.add_zero _)

/-- The original tag field follows its register value at the actual byte offset. -/
theorem tag_address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block) (i : Fin 16)
    (bound : e.get X86_program_profile_bpf.___x86_local_gprs = some (block, registersType)) :
    CC.doEvalLvalue ge e le memory (tagTarget i) =
      some (block, CC.Integers.Ptrofs.repr (16 * (i.val : Int) + 8), .Full) := by
  have named := named_value e le memory block bound
  rw [tagTarget, CC.doEvalLvalue, named]
  simp only [CC.typeof, namedBase, namedType, CC.lvalOfField, source_layouts.1, (field_offsets i).2]
  change some (block, (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (16 * (i.val : Int) + 8), CC.Bitfield.Full) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (block, ofs, CC.Bitfield.Full)) (BitVec.zero_add _)

/-- The first value destination is exactly the original RAX assignment. -/
theorem source_destination : X86ProducerInputReturn.destination =
    .Sassign (pointerTarget 0) (.Etempvar X86_program_profile_bpf._t'1 (CC.tptr CC.tvoid)) := by rfl

def afterRax : CC.Stmt := by
  run_tac do
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(X86ProducerInputReturn.following)) none))
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original RAX tag successor changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_after_rax body.getAppArgs[1]!

theorem source_tag : X86ProducerInputReturn.following =
    .Ssequence (.Sassign (tagTarget 0) (.Econst_int (CC.Integers.Int.repr 0) CC.tuint)) afterRax := by rfl

end KProgFormal.ClightRefinement.X86ProducerGprAddress
