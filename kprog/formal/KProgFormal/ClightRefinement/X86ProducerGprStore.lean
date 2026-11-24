import KProgFormal.ClightRefinement.X86ProducerGprAddress

namespace KProgFormal.ClightRefinement.X86ProducerGprStore
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def register (row : Fin 32) : Fin 16 := ⟨row.val / 2, by omega⟩
def chunk (row : Fin 32) : CC.Chunk := if row.val % 2 = 1 then .Mint8unsigned else CC.Mptr
def offset (row : Fin 32) : Int := 16 * ((register row).val : Int) + (if row.val % 2 = 1 then 8 else 0)
def target (row : Fin 32) : CC.Expr := if row.val % 2 = 1 then
  X86ProducerGprAddress.tagTarget (register row) else X86ProducerGprAddress.pointerTarget (register row)
def rhs (row : Fin 32) (temporary : CC.Ident) : CC.Expr := if row.val % 2 = 1 then
  .Econst_int (CC.Integers.Int.repr 0) CC.tuint else .Etempvar temporary (CC.tptr CC.tvoid)
def value (row : Fin 32) (word : BitVec 64) : CC.Val := if row.val % 2 = 1 then .Vint 0 else .Vlong word
def assignment (row : Fin 32) (temporary : CC.Ident) : CC.Stmt := .Sassign (target row) (rhs row temporary)

private theorem target_access : ∀ row : Fin 32,
    CC.accessMode (CC.typeof (target row)) = .By_value (chunk row) := by decide +kernel
private theorem bounds : ∀ row : Fin 32,
    0 ≤ offset row ∧ offset row + CC.sizeChunk (chunk row) ≤ 256 ∧
    offset row % CC.alignChunk (chunk row) = 0 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset row)) = offset row := by decide +kernel
private theorem disjoint : ∀ i j : Fin 32, j ≠ i →
    offset j + CC.sizeChunk (chunk j) ≤ offset i ∨ offset i + CC.sizeChunk (chunk i) ≤ offset j := by decide +kernel

private theorem source_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (row : Fin 32)
    (temporary : CC.Ident) (word : BitVec 64) (read : le.get temporary = some (.Vlong word)) :
    CC.doEvalExpr ge e le memory (rhs row temporary) = some (value row word) ∧
    CC.Cop.semCast (value row word) (CC.typeof (rhs row temporary)) (CC.typeof (target row)) memory = some (value row word) ∧
    CC.Val.loadResult (chunk row) (value row word) = value row word := by
  refine ⟨?_, ?_, ?_⟩
  all_goals by_cases tag : row.val % 2 = 1
  all_goals simp only [rhs, target, value, chunk, tag, ite_true, ite_false, CC.doEvalExpr,
    CC.typeof, X86ProducerGprAddress.pointerTarget, X86ProducerGprAddress.tagTarget, read]
  all_goals rfl

/-- The real declared256-byte GPR object provides every typed initializer store.
The row selects a pointer value or its scalarizing tag byte. Stores/readbacks,
all other GPR/tag rows and other blocks follow actual permissions and disjoint
intervals, rather than a supplied successful store or output-frame premise. -/
theorem write (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (gprs : SourceLocal ge.genv_cenv before 0) (row : Fin 32) (temporary : CC.Ident) (word : BitVec 64)
    (read : le.get temporary = some (.Vlong word))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 2
      (.State producer (assignment row temporary) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk row) memory gprs.block (offset row) (value row word) = some after ∧
    CC.Mem.load (chunk row) after gprs.block (offset row) = some (value row word) ∧
    (∀ j : Fin 32, j ≠ row → CC.Mem.load (chunk j) after gprs.block (offset j) = CC.Mem.load (chunk j) memory gprs.block (offset j)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have rowBounds := bounds row
  have size : CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24)) = 256 := by
    change CC.sizeof ge.genv_cenv X86ProducerGprAddress.registersType = 256
    simpa only [X86ProducerGprAddress.registersType, CC.sizeof, X86ProducerLayout.layouts.2.2.2]
      using X86ProducerLayout.registers_layout.1
  have rangeWritable := CC.Mem.rangePerm_implies gprs.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk row) gprs.block (offset row) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 gprs.block 0
        (CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24))) .Cur .Writable rangeWritable ofs
          (by omega) (by rw [size]; omega)
      simpa only [CC.Mem.perm, access] using permission
    · simpa only [beq_iff_eq] using rowBounds.2.2.1
  obtain ⟨after, stored⟩ : ∃ after, CC.Mem.store (chunk row) memory gprs.block (offset row) (value row word) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  have storev : CC.Mem.storev (chunk row) memory (.Vptr gprs.block (CC.Integers.Ptrofs.repr (offset row))) (value row word) = some after := by
    simpa only [CC.Mem.storev, rowBounds.2.2.2] using stored
  have address : CC.doEvalLvalue ge (allocation ge.genv_cenv before).1 le memory (target row) =
      some (gprs.block, CC.Integers.Ptrofs.repr (offset row), .Full) := by
    by_cases tag : row.val % 2 = 1
    · simpa only [target, offset, tag, ite_true] using
        X86ProducerGprAddress.tag_address (allocation ge.genv_cenv before).1 le memory gprs.block (register row) gprs.binding
    · simpa only [target, offset, tag, ite_false, Int.add_zero] using
        X86ProducerGprAddress.pointer_address (allocation ge.genv_cenv before).1 le memory gprs.block (register row) gprs.binding
  have source := source_value (allocation ge.genv_cenv before).1 le memory row temporary word read
  have assigned : CC.doStep ge
      (.State producer (assignment row temporary) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, address, source.1, source.2.1, CC.doAssignLoc, target_access]
    change (match CC.Mem.storev (chunk row) memory (.Vptr gprs.block (CC.Integers.Ptrofs.repr (offset row))) (value row word) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [storev]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, FrameBelow.store gprs.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ assigned)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))
  · simpa only [source.2.2] using CC.Mem.load_store_same stored
  · intro j different
    exact CC.Mem.load_store_other stored (chunk j) gprs.block (offset j) (.inr (disjoint row j different))
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerGprStore
