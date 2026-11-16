import KProgFormal.ClightRefinement.Arm64Width
import KProgFormal.ClightRefinement.Globalenv
import KProgFormal.Reference.AArch64

namespace KProgFormal.ClightRefinement.Arm64Nop

/-- The generic exported production handler, not a NOP-specific C fixture. -/
def handler : CC.Function := Arm64Program.f_kprog_arm64_program_execute

/-- Structural names for the real prefix and NOP gate. An incompatible export
is refused by `unpack`; `parts` below requires its actual successful shape. -/
private structure Parts where
  callStmt : CC.Stmt
  storeStmt : CC.Stmt
  test : CC.Expr
  alternative : CC.Stmt

private def unpack : Option Parts :=
  match handler.fn_body with
  | .Sloop (.Ssequence (.Ssequence callStmt storeStmt)
      (.Sifthenelse test .Sskip alternative)) .Sbreak =>
    some ⟨callStmt, storeStmt, test, alternative⟩
  | _ => none

private def parts : Parts := unpack.get (by decide)
private def branch : CC.Stmt := .Sifthenelse parts.test .Sskip parts.alternative
private def body : CC.Stmt := .Ssequence (.Ssequence parts.callStmt parts.storeStmt) branch

private theorem body_eq : handler.fn_body = .Sloop body .Sbreak := rfl

private theorem call_eq : parts.callStmt =
    .Scall (some Arm64Program._t'1)
      (.Evar Arm64Program._arm64_width_effective
        (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
      [.Etempvar Arm64Program._flags CC.tuchar] := rfl

private theorem store_eq : parts.storeStmt =
    .Sset Arm64Program.___a64_l_width
      (.Ecast (.Etempvar Arm64Program._t'1 CC.tuchar) CC.tuchar) := rfl

private theorem test_eq : parts.test =
    .Ebinop .Oeq (.Etempvar Arm64Program._op CC.tuint)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint := rfl

private def afterCall (k : CC.Cont) : CC.Cont :=
  .Kseq parts.storeStmt (.Kseq branch (.Kloop1 body .Sbreak k))

/-- Ordinary C function binding: no local shadow, and the linked symbol points
at the actual exported width function. No external-call semantics is assumed. -/
structure WidthBinding (ge : CC.CGenv) (e : CC.Env) where
  block : CC.Block
  unshadowed : e.get Arm64Program._arm64_width_effective = none
  symbol : CC.Genv.findSymbol ge.genv_genv Arm64Program._arm64_width_effective = some block
  function : CC.Genv.findFunctPtr ge.genv_genv block =
    some (.Internal Arm64Program.f_arm64_width_effective)

private def preceding := Arm64Program.global_definitions.take 65
private def following := Arm64Program.global_definitions.drop 66
private def widthGlobal : CC.Ident × CC.GlobDef CC.FunDef CC.Ty :=
  (Arm64Program._arm64_width_effective, .Gfun (.Internal Arm64Program.f_arm64_width_effective))

private theorem globals_eq : Arm64Program.global_definitions =
    preceding ++ widthGlobal :: following := by rfl

private def beforeEnv : CC.Genv CC.FunDef CC.Ty :=
  CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public) preceding

private theorem next_eq : beforeEnv.genv_next = CC.Positive.ofNat 66 := by rfl

private theorem env_eq : Arm64Program.prog.globalenv.genv_genv =
    CC.Genv.addGlobals (CC.Genv.addGlobal beforeEnv widthGlobal) following := by
  change CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public)
    Arm64Program.global_definitions = _
  rw [globals_eq, addGlobals_append]
  simpa only [beforeEnv] using addGlobals_cons beforeEnv widthGlobal following

private theorem width_symbol : CC.Genv.findSymbol Arm64Program.prog.globalenv.genv_genv
    Arm64Program._arm64_width_effective = some (CC.Positive.ofNat 66) := by decide +kernel

private theorem width_function : CC.Genv.findFunctPtr Arm64Program.prog.globalenv.genv_genv
    (CC.Positive.ofNat 66) = some (.Internal Arm64Program.f_arm64_width_effective) := by
  rw [env_eq, ← next_eq]
  simpa only [widthGlobal] using findFunctPtr_next beforeEnv Arm64Program._arm64_width_effective
    (.Internal Arm64Program.f_arm64_width_effective) following

/-- Concrete function binding in the exported program. Block 66 is its Clight
block, not a native address; structural lookup proofs retain default limits. -/
def programBinding (e : CC.Env)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none) :
    WidthBinding Arm64Program.prog.globalenv e where
  block := CC.Positive.ofNat 66
  unshadowed := unshadowed
  symbol := width_symbol
  function := width_function

private theorem enter_width (ge : CC.CGenv) (e : CC.Env) (binding : WidthBinding ge e)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flags : BitVec 8)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument flags)) :
    steps ge 4 (.State handler handler.fn_body k e le m) =
      some (CC.E0, .Callstate (.Internal Arm64Program.f_arm64_width_effective)
        [Arm64Width.argument flags]
        (.Kcall (some Arm64Program._t'1) handler e le (afterCall k)) m) := by
  simp [body_eq, body, branch, call_eq, afterCall, steps, CC.doStep,
    CC.doEvalExpr, CC.doEvalExprlist, CC.Cop.classifyFun, CC.typeof,
    CC.lvalOfVar, binding.unshadowed, binding.symbol, CC.doDerefLoc,
    CC.accessMode, CC.Genv.findFunct, binding.function, hflags,
    Arm64Width.cast_argument, CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams, CC.Integers.MI.zero,
    Arm64Program.f_arm64_width_effective, CC.E0, CC.Eapp,
    CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq]

/-- Only the two actual compiler temporaries change; all caller memory and
other temporary bindings are retained. -/
def resultEnv (le : CC.TempEnv) (flags : BitVec 8) : CC.TempEnv :=
  (le.set Arm64Program._t'1 (Arm64Width.result flags)).set
    Arm64Program.___a64_l_width (Arm64Width.result flags)

private theorem leave_width (ge : CC.CGenv) (e : CC.Env)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flags : BitVec 8)
    (hop : le.get Arm64Program._op = some (.Vint 0)) :
    steps ge 7 (.Returnstate (Arm64Width.result flags)
      (.Kcall (some Arm64Program._t'1) handler e le (afterCall k)) m) =
      some (CC.E0, .State handler .Sskip k e (resultEnv le flags) m) := by
  have op_temp : Arm64Program._t'1 ≠ Arm64Program._op := by decide
  have op_width : Arm64Program.___a64_l_width ≠ Arm64Program._op := by decide
  have cast : CC.Cop.semCast (Arm64Width.result flags) CC.tuchar CC.tuchar m =
      some (Arm64Width.result flags) :=
    Arm64Width.cast_argument (if flags == 0 then 8 else flags) m
  simp only [steps, CC.doStep, CC.setOpttemp, afterCall, resultEnv, branch,
    store_eq, test_eq, CC.doEvalExpr, CC.typeof, CC.PTree.gss, cast]
  simp [CC.PTree.gso,
    op_temp, op_width, hop, CC.Cop.semBinaryOperation,
    CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast,
    CC.Cop.classifyCast, CC.Cop.castIntInt, CC.typeconv,
    CC.removeAttributes, CC.tattr, CC.tuint, CC.tint, CC.Cop.boolVal,
    CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq,
    CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Eapp, CC.E0]

/-- Execution of the entire actual generic NOP body, from entry to completion
of its statement. Function-frame allocation/freeing belongs to its caller. -/
theorem body_returns (ge : CC.CGenv) (e : CC.Env) (binding : WidthBinding ge e)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flags : BitVec 8)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument flags))
    (hop : le.get Arm64Program._op = some (.Vint 0)) :
    CC.Star (CC.Step2 ge) (.State handler handler.fn_body k e le m) CC.E0
      (.State handler .Sskip k e (resultEnv le flags) m) := by
  have enter := steps_sound ge 4 _ _ _ (enter_width ge e binding le m k flags hflags)
  have call := Arm64Width.returns ge flags
    (.Kcall (some Arm64Program._t'1) handler e le (afterCall k)) m
  have leave := steps_sound ge 7 _ _ _ (leave_width ge e le m k flags hop)
  simpa [CC.Eapp, CC.E0, CC.callCont] using star_trans (star_trans enter call) leave

/-- The retained native word is decoded by LNSym, not by a local classifier. -/
theorem decode_native : decode_raw_inst (0xd503201f#32) =
    some (.BR (.Hints { CRm := 0, op2 := 0 })) := by decide

/-- Exact full external state, including all memory/attributes/history fields. -/
theorem native_step (s : ArmState) (herror : read_err s = .None)
    (hfetch : fetch_inst (read_pc s) s = some (0xd503201f#32)) :
    stepi_checked s = write_pc (read_pc s + (4#64)) s := by
  simp [stepi_checked, stepi, herror, hfetch, decode_native, exec_inst, BR.exec_hints]

/-- The thin native binding retains extra native flag bits and computes the
actual empty effect/fault delta without clearing its existing history. -/
theorem reference_step (s : Reference.AArch64.State)
    (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    Reference.AArch64.step s =
      ⟨{ s with machine := write_pc (read_pc s.machine + (4#64)) s.machine }, [], none⟩ := by
  have history : read_memory_accesses
      (write_pc (read_pc s.machine + (4#64)) s.machine) = read_memory_accesses s.machine := by
    simp [read_memory_accesses, write_pc, w, write_base_pc]
  have afterError : read_err (write_pc (read_pc s.machine + (4#64)) s.machine) = .None := by
    simpa [read_err, write_pc, r_of_w_different] using herror
  simp [Reference.AArch64.step, native_step s.machine herror hfetch,
    history, afterError, herror] <;> constructor <;> rfl

/-- PC is an explicit producer control cursor; every other field, including
extra flag bits, memory profiles and histories, comes from the complete view. -/
def atCursor (cursor : BitVec 64) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  { s with machine := write_pc cursor s.machine }

/-- A heap decoder supplies the complete native wrapper state. Instantiating
it with actual entry cells is a separate representation obligation. -/
def Represents (decodeHeap : CC.Mem → Reference.AArch64.State) (cursor : BitVec 64)
    (m : CC.Mem) (s : Reference.AArch64.State) : Prop :=
  s = atCursor cursor (decodeHeap m)

/-- Conditional body-level correspondence: the actual generic Clight NOP body
preserves the full represented native frame; the checked native step advances
PC and emits no event or fault. Function frames, a concrete heap decoder and
the compiled-label/PC embedding remain separate proof obligations. -/
theorem corresponds (ge : CC.CGenv) (e : CC.Env) (binding : WidthBinding ge e)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flags : BitVec 8)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument flags))
    (hop : le.get Arm64Program._op = some (.Vint 0))
    (decodeHeap : CC.Mem → Reference.AArch64.State) (cursor : BitVec 64)
    (s : Reference.AArch64.State)
    (hrep : Represents decodeHeap cursor m s) (herror : read_err s.machine = .None)
    (hfetch : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    CC.Star (CC.Step2 ge) (.State handler handler.fn_body k e le m) CC.E0
      (.State handler .Sskip k e (resultEnv le flags) m) ∧
    Reference.AArch64.step s = ⟨atCursor (cursor + (4#64)) (decodeHeap m), [], none⟩ := by
  refine ⟨body_returns ge e binding le m k flags hflags hop, ?_⟩
  rw [reference_step s herror hfetch]
  unfold Represents at hrep
  rw [hrep]
  simp [atCursor, read_pc, write_pc, r_of_w_same, w_of_w_shadow]

end KProgFormal.ClightRefinement.Arm64Nop
