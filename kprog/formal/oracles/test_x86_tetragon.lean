import KProgFormal.Clight.X86TetragonWake

-- Inspect the actual application export using mature layout and label lookup.
-- This is frontend/composition validation, not a refinement theorem.
private def checkTetragon : IO Unit := do
  let p := TetragonWake.prog
  let entry := TetragonWake.f_trusted_x86_x86_sim_xdp
  match CC.buildCompositeEnv p.prog_types with
  | .Error _ => throw (IO.userError "Tetragon composite environment failed")
  | .OK _ => pure ()
  unless p.sizeof (.Tunion (CC.identOfString "x86_sim_stack_mem") CC.noattr) == 336 do
    throw (IO.userError "Tetragon actual 336-byte private arena changed")
  for i in [:42] do
    unless entry.fn_vars.contains (CC.identOfString s!"__x86_stack_value_tag_{i}", CC.tuchar) &&
        entry.fn_vars.contains (CC.identOfString s!"__x86_stack_value_ptr_{i}", CC.tptr CC.tvoid) do
      throw (IO.userError "Tetragon named fact cell missing or mistyped")
  match (p.prog_defs.find? fun x => x.1 == CC.identOfString "kprog_x86_callee_bpf_probe_read_kernel").map Prod.snd with
  | some (.Gfun (.External (.EF_external name _) args result _)) =>
    unless name == "kprog_x86_callee_bpf_probe_read_kernel" &&
        args == [CC.tptr CC.tvoid, CC.tuint, CC.tptr CC.tvoid] && result == CC.tlong do
      throw (IO.userError "Tetragon probe-read external ABI changed")
  | _ => throw (IO.userError "Tetragon probe-read is not a typed external callee")
  for label in ["x86_l_ca4", "x86_l_d4c", "x86_l_cb1", "x86_l_d96", "x86_l_c8c"] do
    unless (CC.findLabel (CC.identOfString label) entry.fn_body .Kstop).isSome do
      throw (IO.userError s!"Tetragon actual control label missing: {label}")
  match CC.findLabel (CC.identOfString "x86_sim_ret_dispatch") entry.fn_body .Kstop with
  | some (.Ssequence (.Sset _ _) (.Sswitch _
      (.LScons (some 765) (.Sgoto a) (.LScons (some 1196) (.Sgoto b)
      (.LScons (some 1701) (.Sgoto c) (.LScons (some 2615) (.Sgoto d)
      (.LScons none _ .LSnil)))))), _) =>
    unless [a,b,c,d] == ["x86_l_2fd","x86_l_4ac","x86_l_6a5","x86_l_a37"].map CC.identOfString do
      throw (IO.userError "Tetragon actual return targets changed")
  | _ => throw (IO.userError "Tetragon four-case return dispatch changed")
  for name in ["cgroup_rate_map","cgroup_rate_options_map","execve_map","execve_map_stats",
      "execve_val","tcpmon_map","tg_cgtracker_map","tg_conf_map","tg_rb_events",
      "tg_stats_map","throttle_heap_map"] do
    unless (p.prog_defs.find? fun x => x.1 == CC.identOfString name).isSome do
      throw (IO.userError s!"Tetragon actual external map symbol missing: {name}")
  IO.println "Tetragon retained Clight: frame 336, 42 facts, actual loops, 11 map symbols and four return continuations"

#eval checkTetragon
