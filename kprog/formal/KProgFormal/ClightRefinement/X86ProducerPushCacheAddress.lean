import KProgFormal.ClightRefinement.X86ProducerPushStorageSource

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheAddress
open X86ProducerLayout (ge)

def headerType : CC.Ty := X86ProducerHeaderSource.headerType
def stackType : CC.Ty := .Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr
def readExpression : CC.Expr := .Efield (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType)
  X86_program_profile_bpf._stack (CC.tptr stackType)
def words : CC.Expr := .Efield (.Ederef (.Etempvar X86_program_profile_bpf._t'211 (CC.tptr stackType)) stackType)
  X86_program_profile_bpf._q (CC.tarray CC.tulong 6)
def index : CC.Expr := .Ebinop .Oshr (.Ecast (.Etempvar X86_program_profile_bpf.___x86_stw_index CC.tulong) CC.tulong)
  (.Econst_int (CC.Integers.Int.repr 3) CC.tint) CC.tulong
def target : CC.Expr := .Ederef (.Ebinop .Oadd words index (CC.tptr CC.tulong)) CC.tulong
def rhs : CC.Expr := .Etempvar X86_program_profile_bpf.___x86_loss_value CC.tulong

theorem source : X86ProducerPushStorageSource.cacheRead = .Sset X86_program_profile_bpf._t'211 readExpression ∧
    X86ProducerPushStorageSource.cacheStore = .Sassign target rhs := ⟨rfl,rfl⟩

private theorem stack_field (binding : CC.Block) :
    CC.lvalOfField ge headerType X86_program_profile_bpf._stack (.Vptr binding 0) = some (binding, (8#64), .Full) := by
  have offset : CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._stack X86ShiftLeftCarry.bindingsRecord.co_members = .OK (8, .Full) :=
    X86ProducerHeaderAddress.direct_offset ge X86ProducerLayout.layouts.2.1 1 (by decide +kernel)
  simp only [headerType, X86ProducerHeaderSource.headerType, CC.lvalOfField, X86ProducerLayout.layouts.1, offset]
  rfl

private theorem words_field (cache : CC.Block) :
    CC.lvalOfField ge stackType X86_program_profile_bpf._q (.Vptr cache 0) = some (cache, (0#64), .Full) := by
  have offset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._q X86RegisterWriteRspReleaseWord.stackRecord.co_members = .OK (0, .Full) := rfl
  simp only [stackType, CC.lvalOfField, X86ProducerLayout.layouts.2.2.1, offset]
  rfl

/-- Original header.stack load uses the actual complete-source layout and
current cache view's pointer at byte8. -/
theorem read_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (binding cache : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (read : CC.Mem.load CC.Mptr memory binding 8 = some (.Vptr cache 0)) :
    CC.doEvalExpr ge e le memory readExpression = some (.Vptr cache 0) := by
  have base : CC.doEvalExpr ge e le memory
      (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType) = some (.Vptr binding 0) := by
    simp only [CC.doEvalExpr, bound]
    rfl
  rw [readExpression, CC.doEvalExpr, base]
  change (match CC.lvalOfField ge headerType X86_program_profile_bpf._stack (.Vptr binding 0) with
    | some (b,ofs,bf) => CC.doDerefLoc (CC.tptr stackType) memory b ofs bf
    | none => none) = _
  rw [stack_field]
  exact read

private theorem words_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cache : CC.Block)
    (read : le.get X86_program_profile_bpf._t'211 = some (.Vptr cache 0)) :
    CC.doEvalExpr ge e le memory words = some (.Vptr cache 0) := by
  have base : CC.doEvalExpr ge e le memory (.Ederef (.Etempvar X86_program_profile_bpf._t'211 (CC.tptr stackType)) stackType) = some (.Vptr cache 0) := by
    simp only [CC.doEvalExpr, read]
    rfl
  rw [words, CC.doEvalExpr, base]
  change (match CC.lvalOfField ge stackType X86_program_profile_bpf._q (.Vptr cache 0) with
    | some (b,ofs,bf) => CC.doDerefLoc (CC.tarray CC.tulong 6) memory b ofs bf
    | none => none) = _
  rw [words_field]
  rfl

theorem address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cache : CC.Block)
    (read : le.get X86_program_profile_bpf._t'211 = some (.Vptr cache 0))
    (at40 : le.get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64))) :
    CC.doEvalLvalue ge e le memory target = some (cache, (40#64), .Full) := by
  have selected : CC.doEvalExpr ge e le memory index = some (.Vlong (5#64)) := by
    simp only [index, CC.doEvalExpr, at40]
    rfl
  rw [target, CC.doEvalLvalue, CC.doEvalExpr, words_value e le memory cache read, selected]
  rfl

end KProgFormal.ClightRefinement.X86ProducerPushCacheAddress
