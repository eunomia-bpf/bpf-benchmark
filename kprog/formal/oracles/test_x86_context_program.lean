import KProgFormal.Clight.X86ContextXdp
import KProgFormal.Clight.X86ContextSkb

-- Actual producer entry declarations and mature composite layout calculation.
-- These computations do not prove context/kernel or handler refinements.
private def checkEntry (p : CC.Program) (entry : CC.Function) (skb : Bool) : IO Unit := do
  let context := CC.identOfString (if skb then "__sk_buff" else "xdp_md")
  let abi := CC.identOfString (if skb then "x86_sim_skb_abi" else "x86_sim_xdp_abi")
  let helper := if skb then "kprog_x86_callee_bpf_skb_pull_data" else "kprog_x86_callee_bpf_xdp_adjust_head"
  let ctxTy := CC.tptr (.Tstruct context CC.noattr)
  unless CC.compositesWellFormed p && entry.fn_params == [(CC.identOfString "ctx", ctxTy)] &&
      entry.fn_return == CC.tint do
    throw (IO.userError "x86 actual context entry ABI changed")
  unless p.sizeof (.Tunion (CC.identOfString "x86_sim_stack_mem") CC.noattr) == 48 &&
      p.sizeof (.Tstruct abi CC.noattr) == (if skb then 216 else 40) &&
      entry.fn_vars.contains (CC.identOfString "__x86_sim_abi", .Tstruct abi CC.noattr) do
    throw (IO.userError "x86 actual context/private declaration layout changed")
  for i in [:6] do
    unless entry.fn_vars.contains (CC.identOfString s!"__x86_stack_value_tag_{i}", CC.tuchar) &&
        entry.fn_vars.contains (CC.identOfString s!"__x86_stack_value_ptr_{i}", CC.tptr CC.tvoid) do
      throw (IO.userError "x86 context producer fact binding missing")
  match p.prog_defs.lookup (CC.identOfString helper) with
  | some (.Gfun (.External (.EF_external name _) args result _)) =>
    unless name == helper && args == [ctxTy, if skb then CC.tuint else CC.tint] && result == CC.tlong do
      throw (IO.userError "x86 actual context helper ABI changed")
  | _ => throw (IO.userError "x86 actual context helper is not a typed external")
  IO.println s!"x86 {if skb then "SKB" else "XDP"} producer: typed entry/helper, frame 48, six facts and actual ABI storage"

#eval checkEntry X86_context_xdp_bpf.prog X86_context_xdp_bpf.f_x86_context_xdp_x86_sim_xdp false
#eval checkEntry X86_context_skb_bpf.prog X86_context_skb_bpf.f_x86_context_skb_x86_sim_xdp true
