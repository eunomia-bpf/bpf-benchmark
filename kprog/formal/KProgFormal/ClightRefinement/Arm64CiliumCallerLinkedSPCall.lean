import KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedProgram
import KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPCall
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header headerType)
open Arm64CiliumCallerSPWriterCall
  (types functionType calleeExpr headerExpr payloadExpr argumentExprs arguments call_source unshadowed)

/- These actual expression evaluations are independent of the global world.
The allocation remains the actual795-local caller allocation, whose equality
with the linked-world allocation was checked in LinkedProgram.linked_allocation. -/

theorem header_value (world : CC.CGenv) {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world (allocation m).1 le memory headerExpr = some (.Vptr header.block 0) := by
  simp only [headerExpr,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header.binding,ite_true]
  rfl

theorem payload_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (Arm64CiliumCallerSPPreindex.resultEnv le) memory payloadExpr =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  have different : _t'13900 ≠ ___a64_l_pp := by decide +kernel
  have spRead : (Arm64CiliumCallerSPPreindex.resultEnv le).get _t'13900 =
      some (.Vlong (0#64)) := CC.PTree.gss _ _ _
  have ppRead : (Arm64CiliumCallerSPPreindex.resultEnv le).get ___a64_l_pp =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
    unfold Arm64CiliumCallerSPPreindex.resultEnv
    rw [CC.PTree.gso _t'13900 ___a64_l_pp _ _ different]
    exact CC.PTree.gss _ _ _
  simp only [payloadExpr,CC.doEvalExpr,spRead,ppRead]
  rfl

private theorem reg_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Econst_int (32#32) CC.tuint) = some (.Vint (32#32)) := rfl
private theorem tag_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Econst_int (4#32) CC.tuint) = some (.Vint (4#32)) := rfl
private theorem argument_types :
    CC.typeof headerExpr = CC.tptr headerType ∧ CC.typeof payloadExpr = CC.tptr CC.tvoid ∧
    CC.typeof (.Econst_int (32#32) CC.tuint) = CC.tuint ∧
    CC.typeof (.Econst_int (4#32) CC.tuint) = CC.tuint := ⟨rfl,rfl,rfl,rfl⟩
private theorem cast_header (memory : CC.Mem) (b : CC.Block) :
    CC.Cop.semCast (.Vptr b 0) (CC.tptr headerType) (CC.tptr headerType) memory = some (.Vptr b 0) := rfl
private theorem cast_payload (memory : CC.Mem) :
    CC.Cop.semCast (.Vlong Arm64CiliumCallerSPPreindex.delta) (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := rfl
private theorem cast_reg (memory : CC.Mem) :
    CC.Cop.semCast (.Vint (32#32)) CC.tuint CC.tulong memory = some (.Vlong (32#64)) := rfl
private theorem cast_tag (memory : CC.Mem) :
    CC.Cop.semCast (.Vint (4#32)) CC.tuint CC.tuchar memory = some (.Vint (4#32)) := rfl

/-- All four original arguments derive from actual bindings and reached temporaries. -/
theorem arguments_value (world : CC.CGenv) {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExprlist world (allocation m).1 (Arm64CiliumCallerSPPreindex.resultEnv le) memory
      argumentExprs types = some (arguments header.block) := by
  have actualHeader := header_value world header (Arm64CiliumCallerSPPreindex.resultEnv le) memory
  simp only [argumentExprs,types,CC.doEvalExprlist,actualHeader,payload_value,reg_value,tag_value,
    argument_types.1,argument_types.2.1,argument_types.2.2.1,argument_types.2.2.2,
    cast_header,cast_payload,cast_reg,cast_tag,arguments]

private theorem callee_value {m : CC.Mem} (le : CC.TempEnv) (memory : CC.Mem) (b : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv _kprog_arm64_program_write_pointer = some b) :
    CC.doEvalExpr ge (allocation m).1 le memory calleeExpr = some (.Vptr b 0) := by
  simp only [calleeExpr,CC.doEvalExpr,CC.lvalOfVar,unshadowed m,symbol]
  rfl
private theorem function_class :
    CC.Cop.classifyFun (CC.typeof calleeExpr) = .f types CC.tvoid CC.cc_default := rfl
private theorem callee_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_write_pointer) = .Tfunction types CC.tvoid CC.cc_default := rfl

/-- Resolve the same original Scall in the actual linked world, without assuming helper execution. -/
theorem call_ready {m : CC.Mem} (header : Header m) (le : CC.TempEnv)
    (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 1
      (.State procedure Arm64CiliumCallerSPPreindex.call k (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) memory)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_write_pointer) (arguments header.block)
        (.Kcall none procedure (allocation m).1 (Arm64CiliumCallerSPPreindex.resultEnv le) k) memory) := by
  obtain ⟨block,symbol,function⟩ := Arm64CiliumCallerLinkedProgram.writer_lookup
  have callable : CC.Genv.findFunct ge.genv_genv (.Vptr block 0) = some (.Internal Arm64Program.f_kprog_arm64_program_write_pointer) := by
    simpa [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using function
  have target := callee_value (m := m) (Arm64CiliumCallerSPPreindex.resultEnv le) memory block symbol
  have actuals := arguments_value ge header le memory
  apply internalRun_of_steps
  all_goals
    simp only [steps,InternalPath,InternalState,CC.doStep,call_source,function_class,target,
      actuals,callable,callee_type,ite_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append]

end KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPCall
