import KProgFormal.ClightRefinement.Arm64NumericProducerGprInputs
import KProgFormal.ClightRefinement.Arm64ProducerTables

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerTables

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer
open Arm64ProducerGprInputs (inputRegister)

/-- The actual x30 zero branch and both tables follow the 30 provider visits.
Every table pointer and all 31 pointed-to scalar values are derived. -/
theorem initialized_pointer_tables (ctx continuation : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64)
    (provider : Arm64ProducerGprInputs.ProviderAt Arm64NumericProgram.ge initialMemory values) :
    program.initMem = some initialMemory ∧
    ∃ words : TableLocals false initialMemory, ∃ tags : TableLocals true initialMemory,
    ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer afterPointerTables k
          (allocation initialMemory).1 finalLe after) ∧
      (∀ i, CC.Mem.load CC.Mptr after words.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (words.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load CC.Mptr after tags.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (tags.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load .Mint64 after (words.cellBlock i) 0 =
        some (.Vlong (if i = 30 then 0 else values i)) ∧
        CC.Mem.load .Mint8unsigned after (tags.cellBlock i) 0 = some (.Vint 0)) ∧
      (∀ returns, ∃ cache : CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._ctx = some ctx ∧
      finalLe.get Arm64Entry._continuation = some continuation := by
  obtain ⟨init, blocks, before, le, traces, length, bindings, visits, reads, caches,
      frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerGprInputs.initialized_gpr_inputs ctx continuation k values provider
  obtain ⟨xb, tb, after, wordBinding, tagBinding, pureRun, zeroWord, zeroTag,
      tables, other, pureFrame, pureAccess, pureNext⟩ :=
    register30_and_pointer_tables_bound Arm64NumericProgram.ge composites_same
      initialMemory before le k access
  change CC.Mem.load .Mint64 after xb 0 = some (.Vlong 0) at zeroWord
  change CC.Mem.load .Mint8unsigned after tb 0 = some (.Vint 0) at zeroTag
  obtain ⟨words, wordPointers⟩ := tables false
  obtain ⟨tags, tagPointers⟩ := tables true
  have wordBlocks : ∀ i : Fin 30, words.cellBlock (inputRegister i) = blocks false i := by
    intro i
    exact congrArg Prod.fst (Option.some.inj ((words.cellBinding (inputRegister i)).symm.trans
      (bindings false i)))
  have tagBlocks : ∀ i : Fin 30, tags.cellBlock (inputRegister i) = blocks true i := by
    intro i
    exact congrArg Prod.fst (Option.some.inj ((tags.cellBinding (inputRegister i)).symm.trans
      (bindings true i)))
  have lastWord : words.cellBlock 30 = xb :=
    congrArg Prod.fst (Option.some.inj ((words.cellBinding 30).symm.trans wordBinding))
  have lastTag : tags.cellBlock 30 = tb :=
    congrArg Prod.fst (Option.some.inj ((tags.cellBinding 30).symm.trans tagBinding))
  have separate : ∀ selected (i : Fin 30),
      tableCellName selected (inputRegister i) ≠ (registerDeclaration 30).word ∧
      tableCellName selected (inputRegister i) ≠ (registerDeclaration 30).tag ∧
      tableCellName selected (inputRegister i) ≠ tableName false ∧
      tableCellName selected (inputRegister i) ≠ tableName true := by
    intro selected; cases selected <;> decide +kernel
  have kept : ∀ i : Fin 30,
      CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (values (inputRegister i))) ∧
      CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0) := by
    intro i
    have w := separate false i
    have t := separate true i
    exact ⟨(other _ _ _ (bindings false i) w.1 w.2.1 w.2.2.1 w.2.2.2 .Mint64 0).trans (reads i).1,
      (other _ _ _ (bindings true i) t.1 t.2.1 t.2.2.1 t.2.2.2 .Mint8unsigned 0).trans (reads i).2⟩
  have finalFrame : FrameBelow (CC.Positive.ofNat 204) before after := by
    intro b below
    apply pureFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨init, words, tags, after, le.set (registerDeclaration 30).resultTemp (.Vlong (0#64)),
    traces, length, ?_, wordPointers, tagPointers, ?_, ?_, frame.trans finalFrame,
    pureAccess.trans access, pureNext.trans next, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans visits pureRun.sound
  · intro i
    by_cases last : i = 30
    · subst i
      simpa only [lastWord, lastTag, ↓reduceIte] using And.intro zeroWord zeroTag
    · have bound : i.val < 30 := by
        have ne : i.val ≠ 30 := fun eq => last (Fin.ext eq)
        have lt := i.isLt
        omega
      let j : Fin 30 := ⟨i.val, bound⟩
      have same : inputRegister j = i := Fin.ext rfl
      have wordEqual := wordBlocks j
      have tagEqual := tagBlocks j
      rw [same] at wordEqual tagEqual
      simpa only [same, wordEqual, tagEqual, ite_eq_right last] using kept j
  · intro returns
    obtain ⟨cache, base, valid⟩ := caches returns
    have baseSeparate : baseName returns ≠ (registerDeclaration 30).word ∧
        baseName returns ≠ (registerDeclaration 30).tag ∧
        baseName returns ≠ tableName false ∧ baseName returns ≠ tableName true := by
      cases returns <;> decide +kernel
    have validSeparate : validName returns ≠ (registerDeclaration 30).word ∧
        validName returns ≠ (registerDeclaration 30).tag ∧
        validName returns ≠ tableName false ∧ validName returns ≠ tableName true := by
      cases returns <;> decide +kernel
    exact ⟨cache,
      (other _ _ _ cache.baseBinding baseSeparate.1 baseSeparate.2.1
        baseSeparate.2.2.1 baseSeparate.2.2.2 .Mint64 0).trans base,
      (other _ _ _ cache.validBinding validSeparate.1 validSeparate.2.1
        validSeparate.2.2.1 validSeparate.2.2.2 .Mint8unsigned 0).trans valid⟩
  · constructor
    · rw [CC.PTree.gso _ _ _ _ (by decide +kernel : (registerDeclaration 30).resultTemp ≠ Arm64Entry._ctx)]
      exact ctxRead.1
    · rw [CC.PTree.gso _ _ _ _ (by decide +kernel : (registerDeclaration 30).resultTemp ≠ Arm64Entry._continuation)]
      exact ctxRead.2

end KProgFormal.ClightRefinement.Arm64NumericProducerTables
