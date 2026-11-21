import KProgFormal.ClightRefinement.Deallocation
import KProgFormal.ClightRefinement.StepEquations

/-! Private frame ownership from the imported Clight allocator and real control
states. Slots belong to the current function's declared environment. Allocation
derives their distinct blocks, permissions and caller separation. The imported
memory operations derive exact saved-value retention through nested frames and
disjoint helper writes; actual return control restores the caller environment.
-/
namespace KProgFormal.ControlABI.PrivateFrame
open ClightRefinement

/-- A genuine Clight function entry supplies its allocation and all slot
ownership, rather than accepting an independent private-slot assignment. -/
theorem entry_slots (world : CC.CGenv) (function : CC.Function) (arguments : List CC.Val)
    (before after : CC.Mem) (locals : CC.Env) (temps : CC.TempEnv)
    (entry : CC.FunctionEntry2 world function arguments before locals temps after) :
    (∀ id ty, (id, ty) ∈ function.fn_vars → ∃ block,
      locals.get id = some (block, ty) ∧
      before.nextblock.toNat ≤ block.toNat ∧ block.toNat < after.nextblock.toNat ∧
      CC.Mem.rangePerm after block 0 (CC.sizeof world.genv_cenv ty) .Cur .Freeable = true) ∧
    (∀ id other v w, locals.get id = some v → locals.get other = some w →
      id ≠ other → v.1 ≠ w.1) ∧ FrameBelow before.nextblock before after := by
  cases entry with
  | intro names parameters separate allocation bound =>
    obtain ⟨storage, distinct⟩ := allocated_local_storage allocation
    refine ⟨?_, distinct, (FrameBelow.allocVariables allocation before.nextblock (Nat.le_refl _)).2⟩
    intro id ty member
    obtain ⟨block, binding⟩ := allocated_local_binding allocation names member
    have live := storage id (block, ty) binding
    exact ⟨block, binding, live.1, live.2.1, live.2.2⟩

/-- The actual call-entry transition reaches the function's own body and
retains the allocator-derived frame for every function and argument list. -/
theorem real_entry (world : CC.CGenv) (function : CC.Function) (arguments : List CC.Val)
    (continuation : CC.Cont) (before : CC.Mem) (locals : CC.Env) (temps : CC.TempEnv)
    (after : CC.Mem) (entry : CC.FunctionEntry2 world function arguments before locals temps after) :
    CC.Step2 world (.Callstate (.Internal function) arguments continuation before) CC.E0
      (.State function function.fn_body continuation locals temps after) ∧
    FrameBelow before.nextblock before after := by
  exact ⟨CC.Step.internal_function _ _ _ _ _ _ _ entry, (entry_slots _ _ _ _ _ _ _ entry).2.2⟩

/-- The update constructors are the actual imported memory operations.
Disjointness is an ownership/footprint premise for each write or nested free.
The relation carries the real intermediate memory, including all public effects. -/
inductive Update (savedChunk : CC.Chunk) (savedBlock : CC.Block) (savedOffset : CC.Z) :
    CC.Mem → CC.Mem → Prop
  | store {before after : CC.Mem} (chunk : CC.Chunk) (block : CC.Block)
      (offset : CC.Z) (value : CC.Val)
      (stored : CC.Mem.store chunk before block offset value = some after)
      (disjoint : savedBlock ≠ block ∨
        savedOffset + CC.sizeChunk savedChunk ≤ offset ∨ offset + CC.sizeChunk chunk ≤ savedOffset) :
      Update savedChunk savedBlock savedOffset before after
  | allocate (before : CC.Mem) (lo hi : CC.Z)
      (older : savedBlock.toNat < before.nextblock.toNat) :
      Update savedChunk savedBlock savedOffset before (CC.Mem.alloc before lo hi).1
  | free {before after : CC.Mem} (block : CC.Block) (lo hi : CC.Z)
      (freed : CC.Mem.free before block lo hi = some after) (different : savedBlock ≠ block) :
      Update savedChunk savedBlock savedOffset before after

/-- Saved loads, including refused or undefined loads, follow the actual
mature memory lemmas through every admitted update. -/
theorem update_load {savedChunk : CC.Chunk} {savedBlock : CC.Block} {savedOffset : CC.Z}
    {before after : CC.Mem} (update : Update savedChunk savedBlock savedOffset before after) :
    CC.Mem.load savedChunk after savedBlock savedOffset =
      CC.Mem.load savedChunk before savedBlock savedOffset := by
  cases update with
  | store chunk block offset value stored disjoint =>
    exact CC.Mem.load_store_other stored savedChunk savedBlock savedOffset disjoint
  | allocate lo hi older =>
    apply CC.Mem.load_alloc_other
    intro equal
    have same := congrArg CC.Positive.toNat equal
    omega
  | free block lo hi freed different =>
    rw [CC.Mem.free_result freed]
    exact CC.Mem.load_free_other _ block lo hi savedChunk savedBlock different savedOffset

inductive History (chunk : CC.Chunk) (block : CC.Block) (offset : CC.Z) :
    CC.Mem → CC.Mem → Prop
  | refl (memory) : History chunk block offset memory memory
  | next {first middle last} : Update chunk block offset first middle →
      History chunk block offset middle last → History chunk block offset first last

theorem history_load {chunk : CC.Chunk} {block : CC.Block} {offset : CC.Z}
    {first last : CC.Mem} (history : History chunk block offset first last) :
    CC.Mem.load chunk last block offset = CC.Mem.load chunk first block offset := by
  induction history with
  | refl => rfl
  | next update rest ih => exact ih.trans (update_load update)

/-- A real spill followed by arbitrary nested-frame/disjoint-write history
reloads the source value with the actual chunk's pointer/integer normalization. -/
theorem spill_body_reload {chunk : CC.Chunk} {block : CC.Block} {offset : CC.Z}
    {before spilled after : CC.Mem} {value : CC.Val}
    (spill : CC.Mem.store chunk before block offset value = some spilled)
    (body : History chunk block offset spilled after) :
    CC.Mem.load chunk after block offset = some (CC.Val.loadResult chunk value) :=
  (history_load body).trans (CC.Mem.load_store_same spill)

/-- The real helper-return transition restores the original caller environment
and continuation. Source address bindings keep their exact allocated block. -/
theorem helper_return_environment (world : CC.CGenv) (value : CC.Val) (result : Option CC.Ident)
    (caller : CC.Function) (locals : CC.Env) (temps : CC.TempEnv) (continuation : CC.Cont)
    (memory : CC.Mem) :
    CC.Step2 world (.Returnstate value (.Kcall result caller locals temps continuation) memory) CC.E0
      (.State caller .Sskip continuation locals (CC.setOpttemp result value temps) memory) :=
  CC.Step.returnstate _ _ _ _ _ _ _

/-- Every actual return expression takes the declared free-list and the
original call continuation, covering early returns in arbitrary source CFGs. -/
theorem return_releases_frame (world : CC.CGenv) (function : CC.Function)
    (arguments : List CC.Val) (original allocated before : CC.Mem)
    (locals : CC.Env) (entryTemps temps : CC.TempEnv) (continuation : CC.Cont)
    (expression : CC.Expr) (evaluated result : CC.Val)
    (entry : CC.FunctionEntry2 world function arguments original locals entryTemps allocated)
    (owned : ∀ id value, locals.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true)
    (evaluation : CC.doEvalExpr world locals temps before expression = some evaluated)
    (cast : CC.Cop.semCast evaluated (CC.typeof expression) function.fn_return before = some result) :
    ∃ after, CC.Step2 world (.State function (.Sreturn (some expression)) continuation locals temps before)
      CC.E0 (.Returnstate result (CC.callCont continuation) after) ∧
      FrameBelow original.nextblock before after ∧ after.contents = before.contents ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv locals, ∀ ofs,
        row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  cases entry with
  | intro names parameters separate allocation bound =>
    obtain ⟨after, freed, frame, contents, next, released⟩ := deallocate_live_locals allocation owned
    refine ⟨after, ?_, frame, contents, released⟩
    apply CC.doStep_sound
    simp only [CC.doStep, evaluation, cast, freed]

end KProgFormal.ControlABI.PrivateFrame

#print axioms KProgFormal.ControlABI.PrivateFrame.real_entry
#print axioms KProgFormal.ControlABI.PrivateFrame.spill_body_reload
#print axioms KProgFormal.ControlABI.PrivateFrame.return_releases_frame
