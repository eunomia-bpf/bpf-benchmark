import KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary

namespace KProgFormal.ClightRefinement.X86RegisterReadPointerCall

/-- Genuine four-argument entry, width helper, original pointer-cell/tag
loads and qword selectors reach the actual relationally stuck assignment.
Every intermediate word, tag and selector observation follows from the real
source executions and the initial heap observations. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (m : CC.Mem) (k : CC.Cont) (index : Fin 16) (shift tag : BitVec 8)
    (helperBlock bindingBlock cellsBlock pointerBlock : CC.Block)
    (bindingOffset cellsOffset pointerOffset : CC.Integers.Ptrofs)
    (notSp : index ≠ 4) (notStack : tag ≠ (4#8))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vptr pointerBlock pointerOffset))
    (tagRead : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    ∃ stopped, InternalRun ge 80
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset)
          (X86RegisterReadValue.registerByte index) (8#8) shift) k m) stopped ∧
      CC.doStep ge stopped = none ∧
      ∀ trace next, ¬ CC.Step2 ge stopped trace next := by
  let initial := X86RegisterReadEntry.initialTemps (.Vptr bindingBlock bindingOffset)
    (.Vlong ((X86RegisterReadValue.registerByte index).setWidth 64))
    (.Vlong (8#64)) (.Vlong (shift.setWidth 64))
  let ready := X86RegisterReadEntry.widthTemps
    (X86RegisterReadEntry.prefixTemps initial (X86RegisterReadValue.registerByte index) (8#8)) (8#8)
  let loaded := X86RegisterReadValue.rawTemps ready shift cellsBlock cellsOffset
    (.Vptr pointerBlock pointerOffset)
  let lanes := X86RegisterReadTag.tagTemps loaded index cellsBlock cellsOffset tag
  have binding : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have reg : ready.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [ready, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, CC.PTree.gss, CC.PTree.gso]
  have shiftRead : ready.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)) := by
    simp +decide [ready, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have loadedBinding : loaded.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [loaded, X86RegisterReadValue.rawTemps, CC.PTree.gso, binding]
  have loadedReg : loaded.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [loaded, X86RegisterReadValue.rawTemps, CC.PTree.gso, reg]
  have width : lanes.get X86_program_profile_bpf.___x86_rd_width =
      some (X86ShiftLeft.argument .q) := by
    rw [(X86RegisterReadTag.observations loaded index cellsBlock cellsOffset tag).2.1]
    simp +decide [loaded, ready, X86RegisterReadValue.rawTemps, X86RegisterReadEntry.widthTemps,
      X86Width.result, X86Width.argument, X86ShiftLeft.argument, X86.Size.bytes, CC.PTree.gss, CC.PTree.gso]
  have word : lanes.get X86_program_profile_bpf.___x86_rd_value =
      some (.Vptr pointerBlock pointerOffset) := by
    rw [(X86RegisterReadTag.observations loaded index cellsBlock cellsOffset tag).1]
    simp only [loaded, X86RegisterReadValue.rawTemps, CC.PTree.gss]
  have entry := X86RegisterReadEntry.from_call ge m k (.Vptr bindingBlock bindingOffset)
    (X86RegisterReadValue.registerByte index) (8#8) shift helperBlock helper
  have raw := X86RegisterReadValue.read_raw ge layout CC.emptyEnv ready
    (X86RegisterReadEntry.continuation k) m index shift bindingBlock cellsBlock
    bindingOffset cellsOffset (.Vptr pointerBlock pointerOffset)
    binding reg shiftRead cells current rfl rfl rfl
  have tagged := X86RegisterReadTag.ordinary ge layout CC.emptyEnv loaded
    (X86RegisterReadEntry.continuation k) m index bindingBlock cellsBlock
    bindingOffset cellsOffset tag notSp notStack loadedBinding loadedReg cells tagRead
  have suffix := X86RegisterReadPointerBoundary.qword_prefix ge CC.emptyEnv lanes
    (X86RegisterReadEntry.continuation k) m width
  refine ⟨_, ?_, X86RegisterReadPointerBoundary.pointer_assignment ge CC.emptyEnv lanes
    (X86RegisterReadEntry.continuation k) m pointerBlock pointerOffset word, ?_⟩
  · simpa only [X86RegisterReadEntry.arguments, initial, ready, loaded, lanes] using
      ((entry.trans raw).trans tagged).trans suffix
  · exact fun trace next => X86RegisterReadPointerBoundary.pointer_no_step ge CC.emptyEnv lanes
      (X86RegisterReadEntry.continuation k) m pointerBlock pointerOffset word trace next

end KProgFormal.ClightRefinement.X86RegisterReadPointerCall
