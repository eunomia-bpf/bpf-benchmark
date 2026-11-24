import KProgFormal.ClightRefinement.X86ProducerPushBoundary

namespace KProgFormal.ClightRefinement.X86ProducerPushDecode

/-- The concrete53 qword-RBX PUSH byte decodes through the SAME
canonical decoder, including its real one-byte fall-through at any origin. -/
theorem decode (state : Reference.X86.State) :
    Reference.X86.decode #[(0x53 : Reference.Byte)] state = .ok (.push .w64 3 (state.pc + 1)) := by
  canonical_x86_decode

/-- Execute the actual decoded operand/next-PC rather than a supplied ISA
instruction constructor. Binding the byte array to native code storage and
the C program counter remains a separate artifact/fetch obligation. -/
theorem step (state : Reference.X86.State) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true) :
    (do let instruction ← Reference.X86.decode #[(0x53 : Reference.Byte)] state
        pure (Reference.X86.step instruction state)) =
      Except.ok (⟨{state with
        gpr := fun reg => ((X86LogicReference.input state).setReg .q .rsp (state.gpr 4 - (8#64))).regs.get (X86.GPR.ofIndex reg),
        memory := Reference.storeMemory state.memory (state.gpr 4 - (8#64)) (state.gpr 3) 8,
        pc := state.pc + 1},
        [.memory .write (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8) true],none⟩ : Reference.Transition Reference.X86.State) := by
  rw [decode]
  exact congrArg Except.ok (X86PushReference.step state (state.pc + 1) running canonical writable)

private structure Successor where
  call : CC.Stmt
  tail : CC.Stmt

private def successor : Successor := by
  run_tac do
    let original ← Lean.Elab.Term.elabTerm (← `(X86ProducerContextSource.followingCalls)) none
    let sequence ← Lean.Meta.withTransparency .all (Lean.Meta.whnf original)
    unless sequence.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original next producer sequence changed"
    let label ← Lean.Meta.withTransparency .all (Lean.Meta.whnf sequence.getAppArgs[0]!)
    unless label.isAppOfArity ``CC.Stmt.Slabel 2 do throwError "original next producer label missing"
    let name ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf._x86_l_1)) none
    unless ← Lean.Meta.isDefEq label.getAppArgs[0]! name do throwError "original next producer label changed"
    Lean.Elab.Tactic.closeMainGoal `original_push_successor
      (← Lean.Meta.mkAppM ``Successor.mk #[label.getAppArgs[1]!,sequence.getAppArgs[1]!])

/-- Original Clight control returns to its genuine next source label1.
The byte-array/ELF/native-PC artifact binding remains a separate goal. -/
theorem source_successor : ∃ call tail, X86ProducerContextSource.followingCalls =
    .Ssequence (.Slabel X86_program_profile_bpf._x86_l_1 call) tail := by
  exact ⟨successor.call,successor.tail,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushDecode
