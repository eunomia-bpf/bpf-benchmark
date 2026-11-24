import KProgFormal.ClightRefinement.Arm64MemsetStackRoute

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStackAction

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- Original fixture positions in the real160-byte stack allocation. -/
def index (i : Fin 16) : BitVec 64 := BitVec.ofNat 64 (64 + i.val)

/-- The actual source alignment alternatives for the sixteen byte stores. -/
def action (i : Fin 16) : BitVec 32 := if i.val = 0 ∨ i.val = 8 then 1 else 2
private def aligned (i : Fin 16) : BitVec 32 := if i.val = 0 ∨ i.val = 8 then 1 else 0

def temps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  (((le.set Arm64Program._t'28 (.Vint 0)).set Arm64Program._t'30 (.Vint (aligned i))).set
    Arm64Program._t'29 (.Vint (action i))).set Arm64Program._t'29 (.Vint (action i))

private theorem cases16 : ∀ i : Fin 16,
    i=⟨0,by decide⟩ ∨ i=⟨1,by decide⟩ ∨ i=⟨2,by decide⟩ ∨ i=⟨3,by decide⟩ ∨ i=⟨4,by decide⟩ ∨ i=⟨5,by decide⟩ ∨ i=⟨6,by decide⟩ ∨ i=⟨7,by decide⟩ ∨ i=⟨8,by decide⟩ ∨ i=⟨9,by decide⟩ ∨ i=⟨10,by decide⟩ ∨ i=⟨11,by decide⟩ ∨ i=⟨12,by decide⟩ ∨ i=⟨13,by decide⟩ ∨ i=⟨14,by decide⟩ ∨ i=⟨15,by decide⟩ := by decide +kernel

/-- Execute the original width8 guard, low-three-bit test and both actual
result casts for all sixteen real stack offsets. The same source chooses1
at64/72 and2 at the other14 offsets. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (index i))) :
    InternalRun world 14 (.State handler Arm64Program.s_kprog_arm64_program_memset_29 k e le m)
      (.State handler .Sskip k e (temps le i) m) := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals
    apply internalRun_of_steps
    · simp +decide [Arm64Program.s_kprog_arm64_program_memset_29,InternalPath,InternalState,steps,
        CC.doStep,CC.doEvalExpr,hwidth,hindex,index,CC.PTree.gss,CC.PTree.gso,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.semAnd,
        CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
        CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.Cop.boolVal,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tbool,CC.tattr,CC.Archi.ptr64,
        CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
        CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
        CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed]
    · simp +decide [Arm64Program.s_kprog_arm64_program_memset_29,steps,temps,action,aligned,
        CC.doStep,CC.doEvalExpr,hwidth,hindex,index,CC.PTree.gss,CC.PTree.gso,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.semAnd,
        CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
        CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.Cop.boolVal,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tbool,CC.tattr,CC.Archi.ptr64,
        CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
        CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
        CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,CC.E0,CC.Eapp]

theorem result (le : CC.TempEnv) (i : Fin 16) :
    (temps le i).get Arm64Program._t'29 = some (.Vint (action i)) := by simp only [temps,CC.PTree.gss]

end KProgFormal.ClightRefinement.Arm64MemsetStackAction
