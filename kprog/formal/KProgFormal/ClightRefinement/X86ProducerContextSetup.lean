import KProgFormal.ClightRefinement.X86ProducerStackBaseReturn
import KProgFormal.ClightRefinement.X86ProducerHeaderBound

namespace KProgFormal.ClightRefinement.X86ProducerContextSetup
open X86ProducerHeaderSource (producer headerStart)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def helperCtx : CC.Stmt := .Sset X86_program_profile_bpf.___x86_sim_helper_ctx
  (.Ecast (.Etempvar X86_program_profile_bpf._ctx (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid))
def helperAbi : CC.Stmt := .Sset X86_program_profile_bpf.___x86_sim_helper_abi_base
  (.Ecast (.Etempvar X86_program_profile_bpf._ctx (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid))
def chunk (i : Fin 2) : CC.Chunk := if i.val = 0 then CC.Mptr else .Mint8unsigned
def offset (i : Fin 2) : Int := if i.val = 0 then 112 else 120
def target (i : Fin 2) : CC.Expr := if i.val = 0 then
  X86ProducerGprAddress.pointerTarget 7 else X86ProducerGprAddress.tagTarget 7
def rhs (i : Fin 2) : CC.Expr := if i.val = 0 then
  .Ecast (.Etempvar X86_program_profile_bpf._ctx (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)
  else .Econst_int (CC.Integers.Int.repr 1) CC.tuint
def assignment (i : Fin 2) : CC.Stmt := .Sassign (target i) (rhs i)
def value (i : Fin 2) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) : CC.Val :=
  if i.val = 0 then .Vptr ctxBlock ctxOffset else .Vint (1#32)
def pointerStart : CC.Stmt := .Ssequence (assignment 0) (.Ssequence (assignment 1) headerStart)
def following (i : Fin 2) : CC.Stmt := if i.val = 0 then .Ssequence (assignment 1) headerStart else headerStart
def temps (le : CC.TempEnv) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_sim_helper_ctx (.Vptr ctxBlock ctxOffset)).set
    X86_program_profile_bpf.___x86_sim_helper_abi_base (.Vptr ctxBlock ctxOffset)

/-- The exact original final-context and RDI pointer/tag1 sequence precedes the
already proved header suffix. No scalarizing RDI tag0 store is substituted. -/
theorem source_setup : X86ProducerStackBaseSource.finalSetup =
    .Ssequence helperCtx (.Ssequence helperAbi pointerStart) := by rfl

private theorem cases2 : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
private theorem bounds : ∀ i : Fin 2,
    0 ≤ offset i ∧ offset i + CC.sizeChunk (chunk i) ≤ 256 ∧
    offset i % CC.alignChunk (chunk i) = 0 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i := by decide +kernel
private theorem target_access : ∀ i : Fin 2, CC.accessMode (CC.typeof (target i)) = .By_value (chunk i) := by decide +kernel
private theorem row_offset : ∀ i : Fin 2, ∀ row : Fin 32, row.val ≠ 14 + i.val →
    X86ProducerGprStore.offset row + CC.sizeChunk (X86ProducerGprStore.chunk row) ≤ offset i ∨
    offset i + CC.sizeChunk (chunk i) ≤ X86ProducerGprStore.offset row := by decide +kernel

/-- Both real helper-context temporary assignments execute on the original
context pointer and leave the complete memory unchanged. -/
theorem helpers (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset)) :
    InternalRun ge 6 (.State producer X86ProducerStackBaseSource.finalSetup k e le memory)
      (.State producer pointerStart k e (temps le ctxBlock ctxOffset) memory) := by
  have different : X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86_program_profile_bpf._ctx := by decide +kernel
  have first : CC.doStep ge (.State producer helperCtx (.Kseq (.Ssequence helperAbi pointerStart) k) e le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq (.Ssequence helperAbi pointerStart) k) e
        (le.set X86_program_profile_bpf.___x86_sim_helper_ctx (.Vptr ctxBlock ctxOffset)) memory) := by
    simp only [helperCtx, CC.doStep, CC.doEvalExpr, read, CC.typeof]
    rfl
  have second : CC.doStep ge (.State producer helperAbi (.Kseq pointerStart k) e
      (le.set X86_program_profile_bpf.___x86_sim_helper_ctx (.Vptr ctxBlock ctxOffset)) memory) =
      some (CC.E0, .State producer .Sskip (.Kseq pointerStart k) e (temps le ctxBlock ctxOffset) memory) := by
    simp only [helperAbi, CC.doStep, CC.doEvalExpr, CC.PTree.gso _ _ _ _ different, read, CC.typeof, temps]
    rfl
  rw [source_setup]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ first)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ second)
            (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))))))

private theorem source_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (i : Fin 2)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset)) :
    CC.doEvalExpr ge e le memory (rhs i) = some (value i ctxBlock ctxOffset) ∧
    CC.Cop.semCast (value i ctxBlock ctxOffset) (CC.typeof (rhs i)) (CC.typeof (target i)) memory = some (value i ctxBlock ctxOffset) ∧
    CC.Val.loadResult (chunk i) (value i ctxBlock ctxOffset) = value i ctxBlock ctxOffset := by
  rcases cases2 i with rfl | rfl
  all_goals simp only [rhs, value, target, chunk, Fin.val_zero, Fin.val_one, Nat.reduceEqDiff,
    ↓reduceIte, CC.doEvalExpr, CC.typeof, read]
  all_goals constructor
  all_goals first | rfl | (constructor <;> rfl)

/-- Actual GPR-object rights construct the RDI pointer and tag1 stores. All
other GPR rows and blocks survive; the pointer's block/offset remain intact. -/
theorem write (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 2)
    (gprs : SourceLocal ge.genv_cenv before 0) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer (.Ssequence (assignment i) (following i)) k (allocation ge.genv_cenv before).1 le memory)
      (.State producer (following i) k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory gprs.block (offset i) (value i ctxBlock ctxOffset) = some after ∧
    CC.Mem.load (chunk i) after gprs.block (offset i) = some (value i ctxBlock ctxOffset) ∧
    (∀ row : Fin 32, row.val ≠ 14 + i.val → CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have interval := bounds i
  have size : CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24)) = 256 := by
    change CC.sizeof ge.genv_cenv X86ProducerGprAddress.registersType = 256
    simpa only [X86ProducerGprAddress.registersType, CC.sizeof, X86ProducerLayout.layouts.2.2.2]
      using X86ProducerLayout.registers_layout.1
  have writableRange := CC.Mem.rangePerm_implies gprs.range (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk i) gprs.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 gprs.block 0
        (CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24))) .Cur .Writable writableRange ofs
        (by omega) (by rw [size]; omega)
      simpa only [CC.Mem.perm, access] using permission
    · simpa only [beq_iff_eq] using interval.2.2.1
  obtain ⟨after, stored⟩ : ∃ after, CC.Mem.store (chunk i) memory gprs.block (offset i) (value i ctxBlock ctxOffset) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  have address : CC.doEvalLvalue ge (allocation ge.genv_cenv before).1 le memory (target i) =
      some (gprs.block, CC.Integers.Ptrofs.repr (offset i), .Full) := by
    rcases cases2 i with rfl | rfl
    · exact X86ProducerGprAddress.pointer_address _ _ _ gprs.block 7 gprs.binding
    · exact X86ProducerGprAddress.tag_address _ _ _ gprs.block 7 gprs.binding
  have source := source_value (allocation ge.genv_cenv before).1 le memory i ctxBlock ctxOffset read
  have storev : CC.Mem.storev (chunk i) memory (.Vptr gprs.block (CC.Integers.Ptrofs.repr (offset i))) (value i ctxBlock ctxOffset) = some after := by
    simpa only [CC.Mem.storev, interval.2.2.2] using stored
  have assigned : CC.doStep ge (.State producer (assignment i) (.Kseq (following i) k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq (following i) k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, address, source.1, source.2.1, CC.doAssignLoc, target_access]
    change (match CC.Mem.storev (chunk i) memory (.Vptr gprs.block (CC.Integers.Ptrofs.repr (offset i))) (value i ctxBlock ctxOffset) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq (following i) k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [storev]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, FrameBelow.store gprs.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ assigned)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))
  · simpa only [source.2.2] using CC.Mem.load_store_same stored
  · intro row different
    exact CC.Mem.load_store_other stored _ _ _ (.inr (row_offset i row different))
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

/-- The two helper writes do not overwrite the original context argument. -/
theorem context_preserved (le : CC.TempEnv) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) :
    (temps le ctxBlock ctxOffset).get X86_program_profile_bpf._ctx = le.get X86_program_profile_bpf._ctx := by
  have names : X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86_program_profile_bpf._ctx ∧
      X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf._ctx := by decide +kernel
  unfold temps
  rw [CC.PTree.gso _ _ _ _ names.2, CC.PTree.gso _ _ _ _ names.1]

/-- All four original context/RDI statements execute in12 transitions. RDI
keeps the real context block/offset and tag1; every other GPR/tag row, other
block, raw source caller frame and current right/frontier is preserved. -/
theorem initialized (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ middle after, InternalRun ge 12
      (.State producer X86ProducerStackBaseSource.finalSetup k (allocation ge.genv_cenv before).1 le memory)
      (.State producer headerStart k (allocation ge.genv_cenv before).1 (temps le ctxBlock ctxOffset) after) ∧
    CC.Mem.store CC.Mptr memory gprs.block 112 (.Vptr ctxBlock ctxOffset) = some middle ∧
    CC.Mem.store .Mint8unsigned middle gprs.block 120 (.Vint (1#32)) = some after ∧
    CC.Mem.load CC.Mptr after gprs.block 112 = some (.Vptr ctxBlock ctxOffset) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 120 = some (.Vint (1#32)) ∧
    (∀ row : Fin 32, row ≠ 14 → row ≠ 15 → CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have currentRead := (context_preserved le ctxBlock ctxOffset).trans read
  obtain ⟨middle, valueRun, valueStored, valueRead, valueOther, valueOutside, valueFrame, valueAccess, valueNext⟩ :=
    write before memory (temps le ctxBlock ctxOffset) k 0 gprs ctxBlock ctxOffset currentRead access
  obtain ⟨after, tagRun, tagStored, tagRead, tagOther, tagOutside, tagFrame, tagAccess, tagNext⟩ :=
    write before middle (temps le ctxBlock ctxOffset) k 1 gprs ctxBlock ctxOffset currentRead (valueAccess.trans access)
  have pointerRead := (tagOther (14 : Fin 32) (by decide +kernel)).trans valueRead
  refine ⟨middle, after, (helpers _ _ _ k ctxBlock ctxOffset read).trans (valueRun.trans tagRun),
    valueStored, tagStored, pointerRead, tagRead, ?_, ?_, valueFrame.trans tagFrame,
    tagAccess.trans valueAccess, tagNext.trans valueNext⟩
  · intro row notPointer notTag
    have notPointerVal : row.val ≠ 14 := fun equal => notPointer (Fin.ext equal)
    have notTagVal : row.val ≠ 15 := fun equal => notTag (Fin.ext equal)
    exact (tagOther row notTagVal).trans (valueOther row notPointerVal)
  · intro c b ofs different
    exact (tagOutside c b ofs different).trans (valueOutside c b ofs different)

def contextValues (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (i : Fin 5) : CC.Val :=
  if i.val < 2 then .Vptr ctxBlock ctxOffset else X86ProducerInitialPrefix.contextValues i

/-- The actual current context values supply the existing header theorem,
with the two real pointer-valued helper inputs and all three old ABI inputs. -/
theorem context_inputs (le : CC.TempEnv) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (inputs : ∀ i : Fin 5, le.get (X86ProducerContextSource.tempName i) = some (X86ProducerInitialPrefix.contextValues i)) :
    X86ProducerContextSource.Typed (contextValues ctxBlock ctxOffset) ∧
    ∀ i, (temps le ctxBlock ctxOffset).get (X86ProducerContextSource.tempName i) = some (contextValues ctxBlock ctxOffset i) := by
  have cases : ∀ i : Fin 5, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 := by decide +kernel
  constructor
  · intro i
    rcases cases i with rfl | rfl | rfl | rfl | rfl
    · exact Or.inl ⟨ctxBlock, ctxOffset, rfl⟩
    · exact Or.inl ⟨ctxBlock, ctxOffset, rfl⟩
    · exact Or.inr ⟨0, rfl⟩
    · exact ⟨(0#8), rfl⟩
    · exact ⟨(2#8), rfl⟩
  · intro i
    rcases cases i with rfl | rfl | rfl | rfl | rfl
    · change (temps le ctxBlock ctxOffset).get X86_program_profile_bpf.___x86_sim_helper_ctx = some (.Vptr ctxBlock ctxOffset)
      have different : X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf.___x86_sim_helper_ctx := by decide +kernel
      unfold temps
      rw [CC.PTree.gso _ _ _ _ different, CC.PTree.gss]
    · exact CC.PTree.gss _ _ _
    · have names : X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86ProducerContextSource.tempName 2 ∧
          X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86ProducerContextSource.tempName 2 := by decide +kernel
      unfold temps
      rw [CC.PTree.gso _ _ _ _ names.1, CC.PTree.gso _ _ _ _ names.2]
      exact inputs 2
    · have names : X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86ProducerContextSource.tempName 3 ∧
          X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86ProducerContextSource.tempName 3 := by decide +kernel
      unfold temps
      rw [CC.PTree.gso _ _ _ _ names.1, CC.PTree.gso _ _ _ _ names.2]
      exact inputs 3
    · have names : X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86ProducerContextSource.tempName 4 ∧
          X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86ProducerContextSource.tempName 4 := by decide +kernel
      unfold temps
      rw [CC.PTree.gso _ _ _ _ names.1, CC.PTree.gso _ _ _ _ names.2]
      exact inputs 4

/-- The SAME real context/RDI run composes the existing94-step full header,
bind-loop and label suffix. Current context values, real RDI pointer/tag1,
other GPR rows, resource Views and source caller frame all survive to PUSH.
The preceding kind1 provider memory/native-memory binding remains separate. -/
theorem to_first_call_with_reads (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset))
    (inputs : ∀ i : Fin 5, le.get (X86ProducerContextSource.tempName i) = some (X86ProducerInitialPrefix.contextValues i))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : X86ProducerHeaderLocals.HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 106 (.State producer X86ProducerStackBaseSource.finalSetup k (allocation ge.genv_cenv before).1 le memory)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls k)
        (allocation ge.genv_cenv before).1 (temps le ctxBlock ctxOffset) after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (X86ProducerHeaderViews.ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    (∀ i, CC.Mem.load (X86ProducerContextSource.chunk i) after entry.block (X86ProducerContextSource.offset i) = some (contextValues ctxBlock ctxOffset i)) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (X86ProducerHeaderViews.ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (X86ProducerHeaderViews.ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, (((X86ProducerHeaderViews.ghosts sources).tag slot).1).toNat < after.nextblock.toNat ∧
      (((X86ProducerHeaderViews.ghosts sources).pointer slot).1).toNat < after.nextblock.toNat) ∧
    CC.Mem.load CC.Mptr after gprs.block 112 = some (.Vptr ctxBlock ctxOffset) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 120 = some (.Vint (1#32)) ∧
    (∀ row : Fin 32, row ≠ 14 → row ≠ 15 → CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ entry.block → b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    (∀ i : Fin 24, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (sources i).block 0)) := by
  obtain ⟨middle, current, contextRun, pointerStored, tagStored, pointerRead, tagRead, otherRows, outside,
    frame, rights, next⟩ := initialized before memory le k gprs ctxBlock ctxOffset read access
  have currentInputs := context_inputs le ctxBlock ctxOffset inputs
  obtain ⟨entry, sources, after, headerRun, cacheView, ghostView, cellsRead, contextReads, entryCache,
    cacheOutsideGhosts, ghostSeparated, cacheLive, ghostsLive, headerOutside, headerFrame, headerAccess, headerNext, headerReads⟩ :=
    X86ProducerHeaderBound.to_first_call_with_reads before current (temps le ctxBlock ctxOffset) k
      (contextValues ctxBlock ctxOffset) currentInputs.1 currentInputs.2 (rights.trans access)
  have gprEntry := X86ProducerHeaderLocals.source_separate ge.genv_cenv before 0 entry gprs
  refine ⟨entry, sources, after, contextRun.trans headerRun, cacheView, ghostView, cellsRead, contextReads,
    entryCache, cacheOutsideGhosts, ghostSeparated, cacheLive, ghostsLive,
    (headerOutside _ _ _ gprEntry).trans pointerRead, (headerOutside _ _ _ gprEntry).trans tagRead,
    ?_, ?_, frame.trans headerFrame, headerAccess.trans rights, headerNext.trans next, headerReads⟩
  · intro row notPointer notTag
    exact (headerOutside _ _ _ gprEntry).trans (otherRows row notPointer notTag)
  · intro c b ofs notHeader notGpr
    exact (headerOutside c b ofs notHeader).trans (outside c b ofs notGpr)

/-- Compatibility interface: all original premises and conclusions are retained. -/
theorem to_first_call (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (read : le.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset))
    (inputs : ∀ i : Fin 5, le.get (X86ProducerContextSource.tempName i) = some (X86ProducerInitialPrefix.contextValues i))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : X86ProducerHeaderLocals.HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 106 (.State producer X86ProducerStackBaseSource.finalSetup k (allocation ge.genv_cenv before).1 le memory)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls k)
        (allocation ge.genv_cenv before).1 (temps le ctxBlock ctxOffset) after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (X86ProducerHeaderViews.ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    (∀ i, CC.Mem.load (X86ProducerContextSource.chunk i) after entry.block (X86ProducerContextSource.offset i) = some (contextValues ctxBlock ctxOffset i)) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (X86ProducerHeaderViews.ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (X86ProducerHeaderViews.ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, (((X86ProducerHeaderViews.ghosts sources).tag slot).1).toNat < after.nextblock.toNat ∧
      (((X86ProducerHeaderViews.ghosts sources).pointer slot).1).toNat < after.nextblock.toNat) ∧
    CC.Mem.load CC.Mptr after gprs.block 112 = some (.Vptr ctxBlock ctxOffset) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 120 = some (.Vint (1#32)) ∧
    (∀ row : Fin 32, row ≠ 14 → row ≠ 15 → CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ entry.block → b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨entry, sources, after, run, cacheView, ghostView, cells, contextReads, bindingCache, outsideGhosts, separated, cacheLive, ghostsLive, rdiRead, rdiTag, otherRows, outside, frame, finalAccess, frontier, headerReads⟩ :=
    to_first_call_with_reads before memory le k gprs ctxBlock ctxOffset read inputs access
  exact ⟨entry, sources, after, run, cacheView, ghostView, cells, contextReads, bindingCache, outsideGhosts, separated, cacheLive, ghostsLive, rdiRead, rdiTag, otherRows, outside, frame, finalAccess, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerContextSetup
