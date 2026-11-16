import KProgFormal.Clight.X86StackProfile200
import KProgFormal.Clight.X86StackProfile376

-- Check the actual frontend declarations and mature C layout calculation.
-- This computation does not establish a handler refinement.
private def checkProfile (p : CC.Program) (entry : CC.Function) (frame : Int) : IO Unit := do
  match CC.buildCompositeEnv p.prog_types with
  | .Error _ => throw (IO.userError "x86 producer composite environment failed")
  | .OK _ => pure ()
  let arena := CC.identOfString "x86_sim_stack_mem"
  unless p.sizeof (.Tunion arena CC.noattr) == frame do
    throw (IO.userError "x86 producer arena bound changed")
  let words := frame.toNat / 8
  for i in [:words] do
    let tag := CC.identOfString s!"__x86_stack_value_tag_{i}"
    let ptr := CC.identOfString s!"__x86_stack_value_ptr_{i}"
    unless entry.fn_vars.contains (tag, CC.tuchar) &&
        entry.fn_vars.contains (ptr, CC.tptr CC.tvoid) do
      throw (IO.userError s!"x86 producer named fact {i} is missing or mistyped")
  let internal := p.prog_defs.filter fun (_, gd) =>
    match gd with
    | .Gfun (.Internal _) => true
    | _ => false
  IO.println s!"x86 producer frame {frame}: {words} typed named facts; {internal.length} internal bodies"

#eval checkProfile X86_stack_profile_200_bpf.prog
  X86_stack_profile_200_bpf.f_x86_stack_profile_200_x86_sim_xdp 200
#eval checkProfile X86_stack_profile_376_bpf.prog
  X86_stack_profile_376_bpf.f_x86_stack_profile_376_x86_sim_xdp 376
