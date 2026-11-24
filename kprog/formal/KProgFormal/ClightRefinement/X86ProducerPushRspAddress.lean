import KProgFormal.ClightRefinement.X86ProducerPushRspSource

namespace KProgFormal.ClightRefinement.X86ProducerPushRspAddress
open X86ProducerLayout (ge)
open X86ProducerPushReadValue (layout)

def cellType : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr
def gprType : CC.Ty := .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr
def headerType : CC.Ty := X86ProducerHeaderSource.headerType

def header : CC.Expr := .Efield (.Ederef
  (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType)
  X86_program_profile_bpf._cells (CC.tptr cellType)
def cell (temporary : CC.Ident) : CC.Expr := .Ebinop .Oadd
  (.Etempvar temporary (CC.tptr cellType)) (.Econst_int (CC.Integers.Int.repr 4) CC.tint) (CC.tptr cellType)
def unionValue (temporary : CC.Ident) : CC.Expr := .Efield (.Ederef (cell temporary) cellType)
  X86_program_profile_bpf._value gprType
def pointer (temporary : CC.Ident) : CC.Expr := .Efield (unionValue temporary)
  X86_program_profile_bpf._ptr (CC.tptr CC.tvoid)

theorem original : X86ProducerPushRspSource.headerRead = header ∧
    X86ProducerPushRspSource.currentRead = pointer X86_program_profile_bpf._t'229 ∧
    X86ProducerPushRspSource.target = pointer X86_program_profile_bpf._t'228 := ⟨rfl,rfl,rfl⟩

theorem header_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding cells : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (read : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells 0)) :
    CC.doEvalExpr ge e le memory X86ProducerPushRspSource.headerRead = some (.Vptr cells 0) := by
  rw [original.1]
  simp only [header, CC.doEvalExpr, bound, CC.doDerefLoc, CC.accessMode, headerType,
    X86ProducerHeaderSource.headerType, CC.typeof,
    X86RegisterReadValue.table_address ge layout binding 0, CC.tptr]
  exact read

private theorem union_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cells : CC.Block)
    (temporary : CC.Ident) (read : le.get temporary = some (.Vptr cells 0)) :
    CC.doEvalExpr ge e le memory (unionValue temporary) = some (.Vptr cells (64#64)) := by
  simp only [unionValue, CC.doEvalExpr, cell, read, CC.typeof, CC.doDerefLoc,
    cellType, CC.accessMode]
  rfl

/-- Both genuine typed union destinations point at byte64 in the same actual GPR object. -/
theorem pointer_address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cells : CC.Block)
    (temporary : CC.Ident) (read : le.get temporary = some (.Vptr cells 0)) :
    CC.doEvalLvalue ge e le memory (pointer temporary) = some (cells, (64#64), .Full) := by
  rw [pointer, CC.doEvalLvalue, union_value e le memory cells temporary read]
  exact X86RegisterReadValue.pointer_address ge layout cells (64#64)

theorem current_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cells : CC.Block)
    (read : le.get X86_program_profile_bpf._t'229 = some (.Vptr cells 0))
    (rsp : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong 0)) :
    CC.doEvalExpr ge e le memory X86ProducerPushRspSource.currentRead = some (.Vlong 0) := by
  rw [original.2.1, pointer, CC.doEvalExpr, union_value e le memory cells _ read]
  simp only [CC.typeof, unionValue, gprType, X86RegisterReadValue.pointer_address ge layout cells (64#64),
    CC.doDerefLoc, CC.tptr, CC.accessMode]
  exact rsp

end KProgFormal.ClightRefinement.X86ProducerPushRspAddress
