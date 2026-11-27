import KProgFormal.ClightRefinement.Arm64CiliumCallerInitializers

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerContext
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def abiType : CC.Ty := .Tstruct _arm64_sim_xdp_abi CC.noattr
noncomputable def contextType : CC.Ty := CC.tptr (.Tstruct _xdp_md CC.noattr)
noncomputable def pointerType : CC.Ty := CC.tptr CC.tvoid
noncomputable def argTypes : List CC.Ty := [pointerType,CC.tuchar,CC.tuint]
noncomputable def functionType : CC.Ty := .Tfunction argTypes pointerType CC.cc_default
noncomputable def effect : CC.ExtFun := .EF_external "kprog_c_context_pointer"
  (CC.mksignature [.Xptr,.Xint8unsigned,.Xint] .Xptr CC.cc_default)
noncomputable def callee : CC.FunDef := .External effect argTypes pointerType CC.cc_default
noncomputable def field (endPointer : Bool) : CC.Ident := if endPointer then _data_end else _data
noncomputable def temp (endPointer : Bool) : CC.Ident := if endPointer then _t'2 else _t'1
def offset (endPointer : Bool) : Int := if endPointer then 8 else 0
def inputOffset (endPointer : Bool) : Int := if endPointer then 4 else 0
noncomputable def call (endPointer : Bool) : CC.Stmt :=
  .Scall (some (temp endPointer)) (.Evar _kprog_c_context_pointer functionType)
    [.Etempvar _ctx contextType,.Econst_int (CC.Integers.Int.repr 0) CC.tuint,
      .Econst_long (CC.Integers.Int64.repr (inputOffset endPointer)) CC.tulong]
noncomputable def assign (endPointer : Bool) : CC.Stmt :=
  .Sassign (.Efield (.Evar ___a64_sim_abi abiType) (field endPointer) pointerType)
    (.Etempvar (temp endPointer) pointerType)
noncomputable def pair (endPointer : Bool) : CC.Stmt := .Ssequence (call endPointer) (assign endPointer)

private noncomputable def sourceTails : Array CC.Stmt := by
  run_tac do
    let source ← Lean.Elab.Term.elabTerm (← `(procedure.fn_body)) none
    let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source)
    unless first.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first ABI pair absent"
    let second ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first.getAppArgs[1]!)
    unless second.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original second ABI pair absent"
    Lean.Elab.Tactic.closeMainGoal `original_context_tails
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``CC.Stmt) [first.getAppArgs[1]!,second.getAppArgs[1]!])

noncomputable def next (endPointer : Bool) : CC.Stmt :=
  if endPointer then sourceTails[1]'(by decide) else sourceTails[0]'(by decide)
noncomputable def stage (endPointer : Bool) : CC.Stmt :=
  if endPointer then next false else procedure.fn_body

theorem first_stage : stage false = procedure.fn_body := rfl

theorem source (endPointer : Bool) : stage endPointer =
    .Ssequence (pair endPointer) (next endPointer) := by cases endPointer <;> rfl

private noncomputable def abiComposite : CC.Composite :=
  (ge.genv_cenv.get _arm64_sim_xdp_abi).get (by decide +kernel)
theorem layout :
    ge.genv_cenv.get _arm64_sim_xdp_abi = some abiComposite ∧
    CC.sizeof ge.genv_cenv abiType = 40 ∧
    (∀ endPointer,CC.fieldOffset ge.genv_cenv (field endPointer) abiComposite.co_members =
      .OK (offset endPointer,.Full)) ∧
    CC.fieldOffset ge.genv_cenv _cb abiComposite.co_members = .OK (16,.Full) := by
  refine ⟨rfl,rfl,?_,rfl⟩
  intro endPointer;cases endPointer <;> rfl

structure ABI (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get ___a64_sim_abi = some (block,abiType)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : CC.Mem.rangePerm (allocation m).2 block 0 40 .Cur .Freeable = true

theorem abi_storage (m : CC.Mem) : Nonempty (ABI m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have member : (___a64_sim_abi,abiType) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) names member
  have live := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  exact ⟨⟨block,binding,live.1,by simpa only [layout.2.1] using live.2.2⟩⟩

private theorem resolved :
    (CC.Genv.findSymbol ge.genv_genv _kprog_c_context_pointer).bind
      (CC.Genv.findFunctPtr ge.genv_genv) = some callee := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem callee_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv _kprog_c_context_pointer = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some callee :=
  (Option.bind_eq_some_iff (x := CC.Genv.findSymbol ge.genv_genv _kprog_c_context_pointer)
    (f := CC.Genv.findFunctPtr ge.genv_genv) (b := callee)).mp resolved

private theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get _kprog_c_context_pointer = none := by
  have absent : _kprog_c_context_pointer ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent

noncomputable def continuation (endPointer : Bool) (k : CC.Cont) : CC.Cont :=
  .Kseq (assign endPointer) (.Kseq (next endPointer) k)
noncomputable def callContinuation {m : CC.Mem} (endPointer : Bool)
    (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (temp endPointer)) procedure (allocation m).1 le (continuation endPointer k)

/-- Exact original context-argument casts,including long0/4 to declared uint. -/
theorem call_ready {m before : CC.Mem} (endPointer : Bool) (ctx : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get _ctx = some (.Vptr ctx ctxOfs)) :
    InternalRun ge 3
      (.State procedure (stage endPointer) k (allocation m).1 le before)
      (.Callstate callee [.Vptr ctx ctxOfs,.Vint (0#32),
        .Vint (CC.Integers.Int.repr (inputOffset endPointer))]
        (callContinuation (m := m) endPointer le k) before) := by
  obtain ⟨b,symbol,found⟩ := callee_lookup
  have fn : CC.doEvalExpr ge (allocation m).1 le before
      (.Evar _kprog_c_context_pointer functionType) = some (.Vptr b 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed m,symbol]
    rfl
  have args : CC.doEvalExprlist ge (allocation m).1 le before
      [.Etempvar _ctx contextType,.Econst_int (CC.Integers.Int.repr 0) CC.tuint,
        .Econst_long (CC.Integers.Int64.repr (inputOffset endPointer)) CC.tulong]
      argTypes = some [.Vptr ctx ctxOfs,.Vint (0#32),
        .Vint (CC.Integers.Int.repr (inputOffset endPointer))] := by
    simp only [CC.doEvalExprlist,CC.doEvalExpr,input,argTypes]
    cases endPointer <;> rfl
  have step : CC.Step2 ge
      (.State procedure (call endPointer) (continuation endPointer k) (allocation m).1 le before) CC.E0
      (.Callstate callee [.Vptr ctx ctxOfs,.Vint (0#32),
        .Vint (CC.Integers.Int.repr (inputOffset endPointer))]
        (callContinuation (m := m) endPointer le k) before) := by
    apply CC.Step.call
    · rfl
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ fn
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ args
    · exact found
    · rfl
  rw [source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial step (.refl _)))


theorem pointer_writable {m supplied : CC.Mem} (abi : ABI m) (endPointer : Bool)
    (access : supplied.access = (allocation m).2.access) :
    CC.Mem.validAccess supplied .Mint64 abi.block (offset endPointer) .Writable = true := by
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have bounds : 0 ≤ offset endPointer ∧ offset endPointer+8 ≤ 40 := by cases endPointer <;> decide
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ abi.owned o (by omega)
        (by change o < offset endPointer+8 at upper;omega))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · cases endPointer <;> decide

/-- The real callback RETURN and original ABI assignment execute4internal
steps. The successful store/readback comes from actual ABI allocation. -/
theorem writeback {m supplied : CC.Mem} (abi : ABI m) (endPointer : Bool)
    (result : CC.Block) (resultOfs : CC.Integers.Ptrofs)
    (access : supplied.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 4
        (.Returnstate (.Vptr result resultOfs) (callContinuation (m := m) endPointer le k) supplied)
        (.State procedure (next endPointer) k (allocation m).1
          (le.set (temp endPointer) (.Vptr result resultOfs)) after) ∧
      CC.Mem.store .Mint64 supplied abi.block (offset endPointer)
        (.Vptr result resultOfs) = some after ∧
      CC.Mem.load .Mint64 after abi.block (offset endPointer) =
        some (.Vptr result resultOfs) ∧
      (∀ b,b ≠ abi.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c supplied b o) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  have valid := pointer_writable abi endPointer access
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store .Mint64 supplied abi.block (offset endPointer)
        (.Vptr result resultOfs) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let updated := le.set (temp endPointer) (.Vptr result resultOfs)
  have target : CC.doEvalLvalue ge (allocation m).1 updated supplied
      (.Efield (.Evar ___a64_sim_abi abiType) (field endPointer) pointerType) =
      some (abi.block,CC.Integers.Ptrofs.repr (offset endPointer),.Full) := by
    simp only [CC.doEvalLvalue,CC.doEvalExpr,CC.lvalOfVar,abi.binding,
      CC.doDerefLoc,abiType,CC.accessMode,CC.typeof,CC.lvalOfField,
      layout.1,layout.2.2.1 endPointer]
    cases endPointer <;> rfl
  have value : CC.doEvalExpr ge (allocation m).1 updated supplied
      (.Etempvar (temp endPointer) pointerType) = some (.Vptr result resultOfs) :=
    CC.PTree.gss _ _ _
  have cast : CC.Cop.semCast (.Vptr result resultOfs) pointerType pointerType supplied =
      some (.Vptr result resultOfs) := rfl
  have assigned : CC.doAssignLoc ge.genv_cenv pointerType supplied abi.block
      (CC.Integers.Ptrofs.repr (offset endPointer)) .Full (.Vptr result resultOfs) = some after := by
    cases endPointer <;> exact stored
  have step : CC.Step2 ge
      (.State procedure (assign endPointer) (.Kseq (next endPointer) k) (allocation m).1 updated supplied) CC.E0
      (.State procedure .Sskip (.Kseq (next endPointer) k) (allocation m).1 updated after) := by
    apply CC.doStep_sound
    simp only [assign,CC.doStep,target,value,CC.typeof,cast,assigned]
  have run : InternalRun ge 4
      (.Returnstate (.Vptr result resultOfs) (callContinuation (m := m) endPointer le k) supplied)
      (.State procedure (next endPointer) k (allocation m).1 updated after) := by
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))
  exact ⟨after,run,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store abi.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

/-- One actual exported context call with its real external semantic outcome.
Trace and supplied heap remain explicit;writeback is the same invocation. -/
theorem execute_pair {m before supplied : CC.Mem} (abi : ABI m) (endPointer : Bool)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (result : CC.Block) (resultOfs : CC.Integers.Ptrofs) (trace : CC.Trace)
    (provider : CC.externalCall effect ge.genv_genv.toSenv
      [.Vptr ctx ctxOfs,.Vint (0#32),.Vint (CC.Integers.Int.repr (inputOffset endPointer))]
      before trace (.Vptr result resultOfs) supplied)
    (access : supplied.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (input : le.get _ctx = some (.Vptr ctx ctxOfs)) :
    ∃ after,
      CC.Star (CC.Step2 ge)
        (.State procedure (stage endPointer) k (allocation m).1 le before)
        trace (.State procedure (next endPointer) k (allocation m).1
          (le.set (temp endPointer) (.Vptr result resultOfs)) after) ∧
      CC.Mem.store .Mint64 supplied abi.block (offset endPointer) (.Vptr result resultOfs) = some after ∧
      CC.Mem.load .Mint64 after abi.block (offset endPointer) = some (.Vptr result resultOfs) ∧
      (∀ b,b ≠ abi.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c supplied b o) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  obtain ⟨after,suffix,stored,read,other,frame,access,next⟩ :=
    writeback abi endPointer result resultOfs access le k
  have externalStep : CC.Star (CC.Step2 ge)
      (.Callstate callee [.Vptr ctx ctxOfs,.Vint (0#32),
        .Vint (CC.Integers.Int.repr (inputOffset endPointer))]
        (callContinuation (m := m) endPointer le k) before)
      trace (.Returnstate (.Vptr result resultOfs)
        (callContinuation (m := m) endPointer le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0,CC.Eapp])
  refine ⟨after,?_,stored,read,other,frame,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (call_ready endPointer ctx ctxOfs le k input).sound (star_trans externalStep suffix.sound)



end KProgFormal.ClightRefinement.Arm64CiliumCallerContext
