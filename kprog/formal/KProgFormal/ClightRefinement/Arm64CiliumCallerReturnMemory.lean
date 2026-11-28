import KProgFormal.ClightRefinement.Arm64CiliumCallerReturnProvider

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMemory
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)

structure Store {m supplied : CC.Mem} (locals : Locals m) (base : BitVec 64) where
  middle : CC.Mem
  after : CC.Mem
  storedReturn : CC.Mem.store .Mint64 supplied (locals.block 3) 0 (.Vlong base) = some middle
  storedValid : CC.Mem.store .Mint8unsigned middle (locals.block 5) 0 (.Vint (1#32)) = some after
  returnRead : CC.Mem.load .Mint64 after (locals.block 3) 0 = some (.Vlong base)
  validRead : CC.Mem.load .Mint8unsigned after (locals.block 5) 0 = some (.Vint (1#32))
  otherBlocks : ∀ b,b ≠ locals.block 3 → b ≠ locals.block 5 →
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c supplied b o
  caller : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Both original cache stores derive from current real allocation rights, with no successful-store premise. -/
theorem write {m supplied : CC.Mem} (locals : Locals m) (base : BitVec 64)
    (access : supplied.access = (allocation m).2.access) : Nonempty (Store (supplied := supplied) locals base) := by
  have baseWritable : CC.Mem.validAccess supplied .Mint64 (locals.block 3) 0 .Writable = true :=
    Arm64CiliumCallerDefaults.writable locals 3 access
  obtain ⟨middle,storedReturn⟩ : ∃ middle,CC.Mem.store .Mint64 supplied (locals.block 3) 0
      (.Vlong base) = some middle := by
    simp only [CC.Mem.store,baseWritable,ite_true]
    exact ⟨_,rfl⟩
  have validWritable : CC.Mem.validAccess middle .Mint8unsigned (locals.block 5) 0 .Writable = true :=
    Arm64CiliumCallerDefaults.writable locals 5 ((CC.Mem.store_access storedReturn).trans access)
  obtain ⟨after,storedValid⟩ : ∃ after,CC.Mem.store .Mint8unsigned middle (locals.block 5) 0
      (.Vint (1#32)) = some after := by
    simp only [CC.Mem.store,validWritable,ite_true]
    exact ⟨_,rfl⟩
  have returnRead : CC.Mem.load .Mint64 after (locals.block 3) 0 = some (.Vlong base) :=
    (CC.Mem.load_store_other storedValid .Mint64 (locals.block 3) 0
      (.inl (Arm64CiliumCallerDefaults.locals_separate locals (by decide : (3 : Fin 9) ≠ 5)))).trans
      (CC.Mem.load_store_same storedReturn)
  have validRead : CC.Mem.load .Mint8unsigned after (locals.block 5) 0 = some (.Vint (1#32)) := by
    have read := CC.Mem.load_store_same storedValid
    have normalized : CC.Val.loadResult .Mint8unsigned (.Vint (1#32)) = .Vint (1#32) := rfl
    rw [normalized] at read
    exact read
  have freshReturn := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (locals.binding 3)).1
  have freshValid := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (locals.binding 5)).1
  exact ⟨⟨middle,after,storedReturn,storedValid,returnRead,validRead,
    (fun b differentReturn differentValid c o =>
      (CC.Mem.load_store_other storedValid c b o (.inl differentValid)).trans
        (CC.Mem.load_store_other storedReturn c b o (.inl differentReturn))),
    (FrameBelow.store freshReturn storedReturn).trans (FrameBelow.store freshValid storedValid),
    (CC.Mem.store_access storedValid).trans (CC.Mem.store_access storedReturn),
    (CC.Mem.store_nextblock storedValid).trans (CC.Mem.store_nextblock storedReturn)⟩⟩

/-- Every other actual allocated local retains its supplied-memory reads. -/
theorem bound_frame {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base)
    {id : CC.Ident} {ty : CC.Ty} {block : CC.Block}
    (binding : (allocation m).1.get id = some (block,ty))
    (notReturn : id ≠ Arm64CiliumCallerDefaults.name 3)
    (notValid : id ≠ Arm64CiliumCallerDefaults.name 5) :
    ∀ c o,CC.Mem.load c result.after block o = CC.Mem.load c supplied block o :=
  result.otherBlocks block
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding (locals.binding 3) notReturn)
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding (locals.binding 5) notValid)

theorem return_value {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base) (le : CC.TempEnv) :
    CC.doEvalExpr ge (allocation m).1 le result.after (.Evar ___a64_numeric_return CC.tulong) =
      some (.Vlong base) := by
  have binding : (allocation m).1.get ___a64_numeric_return = some (locals.block 3,CC.tulong) :=
    locals.binding 3
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change CC.Mem.load .Mint64 result.after (locals.block 3) 0 = _
  exact result.returnRead

theorem valid_value {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base) (le : CC.TempEnv) :
    CC.doEvalExpr ge (allocation m).1 le result.after (.Evar ___a64_numeric_return_valid CC.tuchar) =
      some (.Vint (1#32)) := by
  have binding : (allocation m).1.get ___a64_numeric_return_valid = some (locals.block 5,CC.tuchar) :=
    locals.binding 5
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change CC.Mem.load .Mint8unsigned result.after (locals.block 5) 0 = _
  exact result.validRead

noncomputable def resultEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  CC.PTree.set _t'157 (CC.Val.Vlong base) le
noncomputable def afterContinuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 Arm64CiliumCallerReturnProvider.returnBody .Sbreak
    (.Kseq Arm64CiliumCallerReturnProvider.addValue
      (.Kseq Arm64CiliumCallerReturnProvider.storeValue
        (.Kloop1 Arm64CiliumCallerReturnProvider.body .Sbreak k)))

private theorem cast_return (memory : CC.Mem) (base : BitVec 64) :
    CC.Cop.semCast (.Vlong base) CC.tulong CC.tulong memory = some (.Vlong base) := rfl
private theorem cast_valid (memory : CC.Mem) :
    CC.Cop.semCast (.Vint (CC.Integers.Int.repr 1)) CC.tint CC.tuchar memory = some (.Vint (1#32)) := rfl
/-- Resume the actual original Kcall and perform its two actual cache assignments.
The external-call result is not invented here: this suffix starts at Returnstate
with its arbitrary scalar and complete supplied heap, whose current rights suffice. -/
theorem execute {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 6
      (.Returnstate (.Vlong base)
        (.Kcall (some _t'157) procedure (allocation m).1 le
          (Arm64CiliumCallerReturnProvider.continuation k)) supplied)
      (.State procedure Arm64CiliumCallerReturnProvider.setBase (afterContinuation k)
        (allocation m).1 (resultEnv le base) result.after) := by
  have returnBinding : (allocation m).1.get ___a64_numeric_return = some (locals.block 3,CC.tulong) :=
    locals.binding 3
  have validBinding : (allocation m).1.get ___a64_numeric_return_valid = some (locals.block 5,CC.tuchar) :=
    locals.binding 5
  have returnAssigned : CC.doAssignLoc ge.genv_cenv CC.tulong supplied (locals.block 3) 0 .Full
      (.Vlong base) = some result.middle := by
    change CC.Mem.store .Mint64 supplied (locals.block 3) 0 (.Vlong base) = _
    exact result.storedReturn
  have validAssigned : CC.doAssignLoc ge.genv_cenv CC.tuchar result.middle (locals.block 5) 0 .Full
      (.Vint (1#32)) = some result.after := by
    change CC.Mem.store .Mint8unsigned result.middle (locals.block 5) 0 (.Vint (1#32)) = _
    exact result.storedValid
  let cacheCont := CC.Cont.Kseq Arm64CiliumCallerReturnProvider.assignValid
    (.Kseq Arm64CiliumCallerReturnProvider.setBase (afterContinuation k))
  have returnStep : CC.Step2 ge
      (.State procedure Arm64CiliumCallerReturnProvider.assignReturn cacheCont
        (allocation m).1 (resultEnv le base) supplied) CC.E0
      (.State procedure .Sskip cacheCont (allocation m).1 (resultEnv le base) result.middle) := by
    apply CC.Step.assign
    · exact .Evar_local _ _ _ returnBinding
    · exact .Etempvar _ _ _ (CC.PTree.gss _ _ _)
    · exact cast_return supplied base
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ returnAssigned
  have validStep : CC.Step2 ge
      (.State procedure Arm64CiliumCallerReturnProvider.assignValid
        (.Kseq Arm64CiliumCallerReturnProvider.setBase (afterContinuation k))
        (allocation m).1 (resultEnv le base) result.middle) CC.E0
      (.State procedure .Sskip
        (.Kseq Arm64CiliumCallerReturnProvider.setBase (afterContinuation k))
        (allocation m).1 (resultEnv le base) result.after) := by
    apply CC.Step.assign
    · exact .Evar_local _ _ _ validBinding
    · exact .Econst_int _ _
    · exact cast_valid result.middle
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ validAssigned
  refine .step trivial (CC.Step.returnstate _ _ _ _ _ _ _) ?_
  refine .step trivial (CC.Step.skip_seq _ _ _ _ _ _) ?_
  refine .step trivial returnStep ?_
  refine .step trivial (CC.Step.skip_seq _ _ _ _ _ _) ?_
  refine .step trivial validStep ?_
  exact .step trivial (CC.Step.skip_seq _ _ _ _ _ _) (.refl _)

end KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMemory
