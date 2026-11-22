import KProgFormal.ClightRefinement.X86AluEntry

namespace KProgFormal.ClightRefinement.X86AluDecode

private structure Pieces where
  aux : CC.Stmt
  operation : CC.Stmt
  dstShift : CC.Stmt
  srcShift : CC.Stmt
  lhs : CC.Stmt
  rhs : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86AluEntry.afterWidth with
  | .Ssequence aux (.Ssequence operation (.Ssequence dstShift
      (.Ssequence srcShift (.Ssequence lhs (.Ssequence rhs rest))))) =>
      ⟨aux, operation, dstShift, srcShift, lhs, rhs, rest⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_decode_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def auxStatement : CC.Stmt := by run_tac cachePart (← `(pieces.aux))
private def operation : CC.Stmt := by run_tac cachePart (← `(pieces.operation))
private def dstShift : CC.Stmt := by run_tac cachePart (← `(pieces.dstShift))
private def srcShift : CC.Stmt := by run_tac cachePart (← `(pieces.srcShift))
private def lhs : CC.Stmt := by run_tac cachePart (← `(pieces.lhs))
private def rhs : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))
def operandReads : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- The six decoded-field/zero assignments are the real post-width source. -/
theorem source : X86AluEntry.afterWidth =
    .Ssequence auxStatement (.Ssequence operation (.Ssequence dstShift
      (.Ssequence srcShift (.Ssequence lhs (.Ssequence rhs operandReads))))) := rfl

def field (aux : BitVec 32) (shift : Nat) : BitVec 32 :=
  (aux >>> shift) &&& (255#32)

def temps (le : CC.TempEnv) (aux : BitVec 32) : CC.TempEnv :=
  (((((le.set X86_program_profile_bpf.___x86_l_aux (.Vint aux)).set
    X86_program_profile_bpf.___x86_l_alu (.Vint (field aux 0))).set
    X86_program_profile_bpf.___x86_l_dst_shift (.Vint (field aux 8))).set
    X86_program_profile_bpf.___x86_l_src_shift (.Vint (field aux 16))).set
    X86_program_profile_bpf.___x86_l_lhs (.Vlong 0)).set
    X86_program_profile_bpf.___x86_l_rhs (.Vlong 0)

/-- Actual aux decoding and operand initialization execute in eighteen silent
transitions for every 32-bit aux word, retaining the complete source memory. -/
theorem decode (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (aux : BitVec 32)
    (observed : le.get X86_program_profile_bpf._aux = some (.Vint aux)) :
    InternalRun ge 18 (.State function X86AluEntry.afterWidth k e le m)
      (.State function operandReads k e (temps le aux) m) := by
  have zeroCast : CC.Cop.castIntLong .Signed (0#32) = (0#64) := rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      auxStatement, operation, dstShift, srcShift, lhs, rhs, temps, field,
      CC.doEvalExpr, observed, CC.PTree.gss, CC.PTree.gso, CC.typeof,
      CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semShr,
      CC.Cop.semShift, CC.Cop.classifyShift,
      CC.Cop.classifyBinarith, CC.Cop.semBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, zeroCast,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int.and, CC.Integers.MI.and,
      CC.Integers.Int.shru, CC.Integers.MI.shru,
      CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.tint, CC.tuint, CC.tuchar, CC.tulong, CC.typeconv, CC.removeAttributes, CC.tattr, CC.Eapp, CC.E0,
      BitVec.and_assoc, BitVec.and_self]

/-- Each C mask/cast extracts precisely the selected low byte. -/
theorem field_byte (aux : BitVec 32) (shift : Nat) :
    field aux shift = ((aux >>> shift).setWidth 8).setWidth 32 := by
  change (aux >>> shift) &&& (BitVec.allOnes 8).setWidth 32 = _
  apply BitVec.eq_of_getLsbD_eq
  intro bit
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_setWidth, BitVec.getLsbD_allOnes]
  by_cases low : bit < 8 <;> by_cases wide : bit < 32 <;> simp [low, wide, Bool.and_comm]

/-- The real assignments supply all five observations consumed by operand
selection and ALU routing, through the exact final temporary map. -/
theorem observations (le : CC.TempEnv) (aux : BitVec 32) :
    (temps le aux).get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint (field aux 0)) ∧
    (temps le aux).get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (field aux 8)) ∧
    (temps le aux).get X86_program_profile_bpf.___x86_l_src_shift =
      some (.Vint (field aux 16)) ∧
    (temps le aux).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong 0) ∧
    (temps le aux).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong 0) := by
  simp +decide [temps, CC.PTree.gss, CC.PTree.gso]

/-- Actual eight-argument function entry, width resolution and aux decoding
compose in thirty-seven silent transitions. The input aux word alone supplies
the operation and both lane shifts; the actual allocated memory is retained. -/
theorem from_call (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (binding op dst src imm : CC.Val) (aux : BitVec 32) (flags width : BitVec 8)
    (block : CC.Block)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective)) :
    let initial := X86RegisterView.writerInitialTemps binding op dst src
      (X86Width.argument flags) (.Vint aux) imm (X86Width.argument width)
    InternalRun ge 37
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, dst, src, X86Width.argument flags, .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG operandReads
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (temps (X86AluEntry.widthTemps (initial.set X86_program_profile_bpf.___x86_l_width
          (X86Width.argument width)) flags) aux)
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps binding op dst src
    (X86Width.argument flags) (.Vint aux) imm (X86Width.argument width)
  let ready := X86AluEntry.widthTemps (initial.set X86_program_profile_bpf.___x86_l_width
    (X86Width.argument width)) flags
  have observed : ready.get X86_program_profile_bpf._aux = some (.Vint aux) := by
    simp +decide [ready, initial, X86AluEntry.widthTemps, X86RegisterView.writerInitialTemps,
      CC.PTree.gss, CC.PTree.gso]
  exact (X86AluEntry.from_call ge caller k binding op dst src (.Vint aux) imm flags width
    block helper).trans (decode ge _ _ ready _ _ aux observed)

end KProgFormal.ClightRefinement.X86AluDecode
