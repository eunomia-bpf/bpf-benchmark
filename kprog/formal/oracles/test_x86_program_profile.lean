import KProgFormal.Clight.X86ProgramProfile

-- Inspect actual exported calls and use the mature label lookup/layout code.
-- These computations do not prove a handler refinement.
mutual
private def directCalls : CC.Stmt → List CC.Ident
  | .Scall _ (.Evar id _) _ => [id]
  | .Ssequence a b | .Sifthenelse _ a b | .Sloop a b => directCalls a ++ directCalls b
  | .Sswitch _ cases => labeledCalls cases
  | .Slabel _ body => directCalls body
  | _ => []
private def labeledCalls : CC.LStmts → List CC.Ident
  | .LSnil => []
  | .LScons _ body rest => directCalls body ++ labeledCalls rest
end

private def checkProgram : IO Unit := do
  let p := X86_program_profile_bpf.prog
  let entry := X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp
  let clock := CC.identOfString "kprog_x86_callee_bpf_ktime_get_ns"
  unless CC.compositesWellFormed p &&
      p.sizeof (.Tunion (CC.identOfString "x86_sim_stack_mem") CC.noattr) == 48 do
    throw (IO.userError "x86 actual program frame/layout changed")
  match p.prog_defs.lookup clock with
  | some (.Gfun (.External (.EF_external name _) args result _)) =>
    unless name == "kprog_x86_callee_bpf_ktime_get_ns" && args.isEmpty && result == CC.tulong do
      throw (IO.userError "x86 actual program clock ABI changed")
  | _ => throw (IO.userError "x86 clock is not an explicit external callee")
  unless (directCalls X86_program_profile_bpf.f_x86_sim_inline_arm_CALL_HELPER.fn_body).contains clock do
    throw (IO.userError "x86 helper body does not call its typed platform callee")
  match CC.findLabel (CC.identOfString "x86_sim_ret_dispatch") entry.fn_body .Kstop with
  | some (.Ssequence (.Sset _ _) (.Sswitch _
      (.LScons (some 15) (.Sgoto first) (.LScons (some 24) (.Sgoto second)
        (.LScons none _ .LSnil)))), _) =>
    unless first == CC.identOfString "x86_l_f" && second == CC.identOfString "x86_l_18" do
      throw (IO.userError "x86 return cases select the wrong actual labels")
  | _ => throw (IO.userError "x86 actual producer return table changed")
  match CC.findLabel (CC.identOfString "x86_l_3a") entry.fn_body .Kstop with
  | some (.Scall none (.Evar helper _) args,
      .Kseq (.Ssequence (.Sloop (.Ssequence (.Scall none (.Evar subret _) _)
        (.Sgoto dispatch)) .Sbreak) _) _) =>
    let correctId := match args.getLast? with
      | some (.Ecast (.Econst_long value _) _) => value == CC.Integers.Int64.repr 5
      | _ => false
    unless helper == CC.identOfString "__x86_instruction_X86_OP_CALL_HELPER" && correctId &&
        subret == CC.identOfString "x86_sim_inline_subret" &&
        dispatch == CC.identOfString "x86_sim_ret_dispatch" do
      throw (IO.userError "x86 helper tail loses its clock or subroutine return")
  | _ => throw (IO.userError "x86 actual helper-tail call/return sequence changed")
  IO.println "x86 actual producer program: frame 48, typed clock, ordinary/tail helpers and two return continuations"

#eval checkProgram
