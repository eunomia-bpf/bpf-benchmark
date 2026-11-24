import KProgFormal.ClightRefinement.X86ProducerGprExecute
import KProgFormal.ClightRefinement.X86ProducerRaxPrefix

namespace KProgFormal.ClightRefinement.X86ProducerGprStage
open X86ProducerGprSites
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- One original source site, including its actual trace and protected loads.
No raw-contents frame is inferred from the provider's typed-load frame. -/
structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (cache : SourceLocal ge.genv_cenv before 1) (i : Fin 16) where
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  value : BitVec 64
  run : CC.Star (CC.Step2 ge)
    (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory) trace
    (.State producer (site i).following k (allocation ge.genv_cenv before).1 output after)
  pointer : CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong value)
  tag : CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)
  others : ∀ row : Fin 32, row ≠ valueRow i → row ≠ tagRow i →
    CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
    CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)
  outside : ∀ c b ofs, b ≠ gprs.block → b ≠ cache.block →
    CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock
  temporary : ∀ name, (site i).savedName ≠ name → (site i).resultName ≠ name → output.get name = le.get name
  rsp : i = 4 → value = 0

theorem local_separate (before : CC.Mem) {name other : CC.Ident} {ty otherTy : CC.Ty}
    (left : Local ge.genv_cenv before name ty) (right : Local ge.genv_cenv before other otherTy)
    (different : name ≠ other) : left.block ≠ right.block := by
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  exact (allocated_local_storage allocated).2 _ _ _ _ left.binding right.binding different

/-- Availability remains exactly the explicit initial provider ABI already
used for RAX. Actual local bindings identify the SAME cache at every site. -/
theorem execute (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (cache : SourceLocal ge.genv_cenv before 1) (i : Fin 16)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k gprs cache i) := by
  by_cases rsp : i = 4
  · subst i
    obtain ⟨after, run, pointer, tag, others, outside, frame, rights, next⟩ :=
      X86ProducerGprExecute.rsp before memory le k gprs access
    refine ⟨⟨after, le.set (site 4).savedName (.Vlong 0), CC.E0, 0,
      run.sound, pointer, tag, others, ?_, rights, next, ?_, fun _ => rfl⟩⟩
    · intro c b ofs notGpr _
      exact outside c b ofs notGpr
    · intro name notSaved _
      exact CC.PTree.gso _ _ _ _ notSaved
  · obtain ⟨actualCache, ⟨outcome⟩⟩ := inputs memory access frontier
    have same : actualCache.block = cache.block := by
      have binding := actualCache.binding.symm.trans cache.binding
      exact congrArg Prod.fst (Option.some.inj binding)
    have separate := local_separate before gprs cache (by decide +kernel)
    obtain ⟨after, run, pointer, tag, others, outside, frame, rights, next⟩ :=
      X86ProducerGprExecute.ordinary before memory outcome.supplied le k i rsp outcome.value outcome.trace gprs
        outcome.call (outcome.access.trans access)
    refine ⟨⟨after, X86ProducerGprEnter.temps i le outcome.value, outcome.trace, outcome.value,
      run, pointer, tag, ?_, ?_, rights.trans outcome.access, next.trans outcome.frontier, ?_, ?_⟩⟩
    · intro row notValue notTag
      exact (others row notValue notTag).trans (outcome.frame _ _ _ (by simpa only [same] using separate))
    · intro c b ofs notGpr notCache
      exact (outside c b ofs notGpr).trans (outcome.frame c b ofs (by simpa only [same] using notCache))
    · intro name notSaved notResult
      unfold X86ProducerGprEnter.temps
      rw [CC.PTree.gso _ _ _ _ notSaved, CC.PTree.gso _ _ _ _ notResult]
    · exact fun equal => False.elim (rsp equal)

end KProgFormal.ClightRefinement.X86ProducerGprStage
