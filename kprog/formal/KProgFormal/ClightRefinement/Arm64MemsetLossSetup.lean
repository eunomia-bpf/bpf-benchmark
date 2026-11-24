import KProgFormal.ClightRefinement.Arm64MemsetPointerRoute

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetLossSetup

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  body : CC.Stmt
  offset : CC.Stmt
  rest1 : CC.Stmt
  width : CC.Stmt
  rest2 : CC.Stmt
  value : CC.Stmt
  rest3 : CC.Stmt
  store : CC.Stmt
  afterStore : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memset loss setup changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetPointerRoute.loss)) none) ``CC.Stmt.Sloop
    let body ← peel loop[0]! ``CC.Stmt.Ssequence
    let first ← peel body[1]! ``CC.Stmt.Ssequence
    let second ← peel first[1]! ``CC.Stmt.Ssequence
    let third ← peel second[1]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memset_loss_setup
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,body[0]!,body[1]!,first[0]!,first[1]!,second[0]!,second[1]!,third[0]!,third[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_loss_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def offset : CC.Stmt := by run_tac cachePart (← `(parts.offset))
private def rest1 : CC.Stmt := by run_tac cachePart (← `(parts.rest1))
private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def rest2 : CC.Stmt := by run_tac cachePart (← `(parts.rest2))
private def value : CC.Stmt := by run_tac cachePart (← `(parts.value))
private def rest3 : CC.Stmt := by run_tac cachePart (← `(parts.rest3))
def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
def afterStore : CC.Stmt := by run_tac cachePart (← `(parts.afterStore))

private theorem source : Arm64MemsetPointerRoute.loss = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence offset rest1 := rfl
private theorem rest1_source : rest1 = .Ssequence width rest2 := rfl
private theorem rest2_source : rest2 = .Ssequence value rest3 := rfl
private theorem rest3_source : rest3 = .Ssequence store afterStore := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kseq afterStore (.Kloop1 body .Sbreak k)

def temps (le : CC.TempEnv) (off : BitVec 64) (byte : BitVec 8) : CC.TempEnv :=
  ((le.set Arm64Program.___a64_loss_off (.Vlong off)).set Arm64Program.___a64_loss_width (.Vint 1)).set
    Arm64Program.___a64_loss_value (.Vlong (byte.setWidth 64))

private theorem widen_byte (byte : BitVec 8) :
    CC.Integers.Int64.repr (CC.Integers.Int.unsigned (byte.setWidth 32)) = byte.setWidth 64 := by
  have small32 : byte.toNat < 4294967296 := by have := byte.isLt; omega
  have small64 : byte.toNat < 18446744073709551616 := by have := byte.isLt; omega
  apply BitVec.eq_of_toNat_eq
  simp [CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    BitVec.toNat_setWidth,BitVec.toNat_ofInt,Nat.mod_eq_of_lt small32,Nat.mod_eq_of_lt small64]

/-- Execute the real loss-offset addition, width cast and source-byte cast,
with the original store loop and post-store work retained as continuations. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (raw off : BitVec 64) (byte : BitVec 8)
    (hbase : le.get Arm64Program.___a64_mwr_base = some (.Vlong raw))
    (hoff : le.get Arm64Program.___a64_mwr_off = some (.Vlong off))
    (hbyte : le.get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32))) :
    InternalRun world 11 (.State handler Arm64MemsetPointerRoute.loss k e le m)
      (.State handler store (continuation k) e (temps le (raw + off) byte) m) := by
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,source,body_source,rest1_source,rest2_source,rest3_source,offset,width,value,
      CC.doStep,CC.doEvalExpr,hbase,hoff,hbyte,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tlong,CC.tulong,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int64.add,CC.Integers.MI.add,widen_byte,CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext]
  · simp +decide [steps,temps,continuation,CC.E0,CC.Eapp,source,body_source,rest1_source,rest2_source,rest3_source,offset,width,value,
      CC.doStep,CC.doEvalExpr,hbase,hoff,hbyte,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tlong,CC.tulong,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int64.add,CC.Integers.MI.add,widen_byte,CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext]

/-- The byte is the exact low8 extraction performed by the original C read. -/
def byte (mark : BitVec 32) : BitVec 8 := (mark.setWidth 64).setWidth 8

def inputTemps (entry tagTable tagCell abi sp : CC.Block) (spValue : BitVec 64)
    (wordTable wordCell : CC.Block) (raw : BitVec 64) (mark : BitVec 32) : CC.TempEnv :=
  Arm64MemsetPointerRoute.temps (Arm64MemsetPointerRoute.readTemps
    (Arm64MemsetPointerRoute.regTemps (Arm64MemsetPointerRoute.inputTemps entry tagTable tagCell abi sp spValue mark))
    wordTable wordCell raw) raw

private theorem abi_inputs (entry table cell abi : CC.Block) (mark : BitVec 32) :
    (Arm64MemsetStackRoute.inputTemps entry table cell abi mark).get Arm64Program.___a64_mwr_off = some (.Vlong 0) ∧
    (Arm64MemsetStackRoute.inputTemps entry table cell abi mark).get Arm64Program.___a64_lib_byte =
      some (.Vint ((byte mark).setWidth 32)) := by
  change (((Arm64MemsetAbiOriginal.beforeTemps entry table cell mark).set Arm64Program._t'172 (.Vptr abi 0)).set
    Arm64Program._t'173 (.Vint 2) |>.set Arm64Program._t'67 (.Vint 0)).get Arm64Program.___a64_mwr_off = _ ∧
    (((Arm64MemsetAbiOriginal.beforeTemps entry table cell mark).set Arm64Program._t'172 (.Vptr abi 0)).set
      Arm64Program._t'173 (.Vint 2) |>.set Arm64Program._t'67 (.Vint 0)).get Arm64Program.___a64_lib_byte = _
  constructor
  · simp +decide only [CC.PTree.gso,Arm64MemsetAbiOriginal.beforeTemps,Arm64MemsetArmSelect.temps,
      Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps,Arm64MemsetStackSetup.temps,CC.PTree.gss]
  · simp +decide only [CC.PTree.gso,Arm64MemsetAbiOriginal.beforeTemps,Arm64MemsetArmSelect.temps,
      Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps]
    rw [Arm64MemsetStackSetup.byte_preserved]
    simp +decide only [Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,
      Arm64MemsetSource.byteTemps,CC.PTree.gso,CC.PTree.gss,byte]

/-- Actual reached base, offset0 and byte observations come from the original
source temporaries through the same ABI/SP/R0 route. -/
theorem inputs (entry tagTable tagCell abi sp : CC.Block) (spValue : BitVec 64)
    (wordTable wordCell : CC.Block) (raw : BitVec 64) (mark : BitVec 32) :
    (inputTemps entry tagTable tagCell abi sp spValue wordTable wordCell raw mark).get
      Arm64Program.___a64_mwr_base = some (.Vlong raw) ∧
    (inputTemps entry tagTable tagCell abi sp spValue wordTable wordCell raw mark).get
      Arm64Program.___a64_mwr_off = some (.Vlong 0) ∧
    (inputTemps entry tagTable tagCell abi sp spValue wordTable wordCell raw mark).get
      Arm64Program.___a64_lib_byte = some (.Vint ((byte mark).setWidth 32)) := by
  refine ⟨?_,?_,?_⟩
  · simp only [inputTemps,Arm64MemsetPointerRoute.temps,CC.PTree.gss]
  · simpa +decide only [inputTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,
      Arm64MemsetPointerRoute.regTemps,Arm64MemsetPointerRoute.inputTemps,Arm64MemsetStackRoute.temps,
      Arm64MemsetStackRoute.selectedTemps,CC.PTree.gso] using (abi_inputs entry tagTable tagCell abi mark).1
  · simpa +decide only [inputTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,
      Arm64MemsetPointerRoute.regTemps,Arm64MemsetPointerRoute.inputTemps,Arm64MemsetStackRoute.temps,
      Arm64MemsetStackRoute.selectedTemps,CC.PTree.gso] using (abi_inputs entry tagTable tagCell abi mark).2

/-- The SAME original memset call reaches its real stack-store loop in353
transitions, retaining actual heap/storage/input observations and continuations. -/
theorem original {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} (mark : BitVec 32)
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (abi : Arm64Producer.TailLocal initial 6)
    (header : CC.Mem.load CC.Mptr constantAfter entry.block 704 = some (.Vptr abi.block 0))
    (value : CC.Mem.load .Mint8unsigned constantAfter abi.block 0 = some (.Vint 2))
    (tags : ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
      CC.Mem.load .Mint8unsigned constantAfter tagsLocal.block (i.val : Int) = some (.Vint 0))
    (k : CC.Cont) :
    ∃ current : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry,
      InternalRun world 353 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
        (.State handler store
          (continuation (Arm64MemsetTagRead.continuation
            (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)))))
          (Arm64MemsetSource.allocation constantAfter).1
          (temps (inputTemps entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0)
            abi.block current.sp.block current.spValue (current.tables false).tableBlock
            ((current.tables false).cellBlock 0) raw mark) (raw + 0) (byte mark))
          (Arm64MemsetSource.allocation constantAfter).2) ∧
      Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
        (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0) ∧
      CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2) ∧
      ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 tagsLocal.block (i.val : Int) = some (.Vint 0) := by
  obtain ⟨current,run,r0,spPointer,spValue,abiPointer,abiValue,tagValues⟩ :=
    Arm64MemsetPointerRoute.original mark pointer bound first second abi header value tags k
  have values := inputs entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0)
    abi.block current.sp.block current.spValue (current.tables false).tableBlock ((current.tables false).cellBlock 0) raw mark
  have route := execute (Arm64MemsetSource.allocation constantAfter).1 _
    (Arm64MemsetSource.allocation constantAfter).2
    (Arm64MemsetTagRead.continuation
      (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
    raw 0 (byte mark) values.1 values.2.1 values.2.2
  exact ⟨current,run.trans route,r0,spPointer,spValue,abiPointer,abiValue,tagValues⟩

end KProgFormal.ClightRefinement.Arm64MemsetLossSetup
