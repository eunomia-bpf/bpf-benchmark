import KProgFormal.Clight.X86ReadonlyProfile

-- Actual object initialization and memory come from the mature Clight library.
-- This computation does not establish a handler or native memory refinement.
private def checkReadonly : IO Unit := do
  let p := X86_readonly_profile_bpf.prog
  let entry := X86_readonly_profile_bpf.f_x86_readonly_profile_x86_sim_xdp
  unless CC.compositesWellFormed p &&
      p.sizeof (.Tunion (CC.identOfString "x86_sim_stack_mem") CC.noattr) == 8 &&
      entry.fn_vars.contains (CC.identOfString "__x86_stack_value_tag_0", CC.tuchar) &&
      entry.fn_vars.contains (CC.identOfString "__x86_stack_value_ptr_0", CC.tptr CC.tvoid) do
    throw (IO.userError "readonly actual stack/fact layout changed")
  match p.prog_defs.lookup (CC.identOfString "__x86_rodata_0") with
  | some (.Gvar v) =>
    unless v.gvar_readonly && v.gvar_init.length == 16 do
      throw (IO.userError "actual immutable readonly object changed")
  | _ => throw (IO.userError "readonly object missing")
  let fn := X86_readonly_profile_bpf.f_x86_sim_inline_native_data_load
  unless fn.fn_return == CC.tulong && fn.fn_params ==
      [(CC.identOfString "base", CC.tptr CC.tvoid),
       (CC.identOfString "offset", CC.tulong),
       (CC.identOfString "width", CC.tuchar)] do
    throw (IO.userError "readonly adapter operand ABI changed")
  let some memory := p.initMem | throw (IO.userError "readonly initial memory failed")
  let some block := CC.Genv.findSymbol p.globalenv.genv_genv (CC.identOfString "__x86_rodata_0")
    | throw (IO.userError "readonly symbol resolution failed")
  unless CC.Mem.load .Mint64 memory block 0 == some (.Vlong (CC.Integers.Int64.repr 0xcdab896745fe8312)) do
    throw (IO.userError "actual readonly global bytes or endian layout changed")
  IO.println "readonly Clight: immutable 16-byte object, exact initial memory, frame 8 and shared selector ABI"

#eval checkReadonly
