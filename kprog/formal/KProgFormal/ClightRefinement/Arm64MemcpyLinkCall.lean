import KProgFormal.ClightRefinement.Arm64MemcpyLinkSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkCall
open Arm64MemcpyLinkProgram (ge entry writer)
open Arm64MemcpyLinkSource (allocation afterTables)

def slot (offset : CC.Integers.Ptrofs) (delta : Int) : Int :=
  CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr delta))

/-- Typed observations of the ORIGINAL caller header. The reached heap's
loads are derived through the actual preceding initialization frame. -/
structure Header (m : CC.Mem) (header : CC.Block) (offset : CC.Integers.Ptrofs) where
  coordinates : CC.Block
  coordinateOffset : CC.Integers.Ptrofs
  registers : CC.Block
  registerOffset : CC.Integers.Ptrofs
  tags : CC.Block
  tagOffset : CC.Integers.Ptrofs
  bytes : CC.Block
  byteOffset : CC.Integers.Ptrofs
  stackTags : CC.Block
  stackTagOffset : CC.Integers.Ptrofs
  capacity : BitVec 32
  bias : BitVec 64
  coordinatesRead : CC.Mem.load CC.Mptr m header (slot offset 0) = some (.Vptr coordinates coordinateOffset)
  registersRead : CC.Mem.load CC.Mptr m header (slot offset 8) = some (.Vptr registers registerOffset)
  tagsRead : CC.Mem.load CC.Mptr m header (slot offset 16) = some (.Vptr tags tagOffset)
  bytesRead : CC.Mem.load CC.Mptr m header (slot offset 24) = some (.Vptr bytes byteOffset)
  stackTagsRead : CC.Mem.load CC.Mptr m header (slot offset 32) = some (.Vptr stackTags stackTagOffset)
  capacityRead : CC.Mem.load .Mint32 m header (slot offset 48) = some (.Vint capacity)
  biasRead : CC.Mem.load .Mint64 m header (slot offset 56) = some (.Vlong bias)

private def parts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let tail ← Lean.Elab.Term.elabTerm (← `(afterTables)) none
    let tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail)
    unless tail.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "LINK tail sequence changed"
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail.getAppArgs[0]!)
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "LINK tail loop changed"
    let body := loop.getAppArgs[0]!
    let mut rest := body
    for _ in [:8] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "LINK setup sequence changed"
      let set ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[0]!)
      unless set.isAppOfArity ``CC.Stmt.Sset 2 do throwError "LINK setup assignment changed"
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    unless rest.isAppOfArity ``CC.Stmt.Scall 3 do throwError "LINK writer call changed"
    let tailPair ← Lean.Meta.mkAppM ``Prod.mk #[tail.getAppArgs[1]!,rest]
    Lean.Elab.Tactic.closeMainGoal `actual_link_call_parts (← Lean.Meta.mkAppM ``Prod.mk #[body,tailPair])

def body : CC.Stmt := parts.1
def returnStmt : CC.Stmt := parts.2.1
def callStmt : CC.Stmt := parts.2.2

theorem tail_source : afterTables = .Ssequence (.Sloop body .Sbreak) returnStmt := rfl

def types : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64Addressing._kprog_arm64_coordinates CC.noattr),
   CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr),CC.tptr CC.tuchar,
   CC.tptr (CC.tvolatile CC.tuchar),CC.tptr CC.tuchar,CC.tuint,CC.tlong,
   CC.tulong,CC.tptr CC.tvoid,CC.tuchar]

theorem call_source : callStmt = .Scall none
    (.Evar Arm64Addressing._kprog_arm64_write_ptr (.Tfunction types CC.tvoid CC.cc_default))
    [.Etempvar Arm64Addressing._t'1 (CC.tptr (.Tstruct Arm64Addressing._kprog_arm64_coordinates CC.noattr)),
     .Etempvar Arm64Addressing._t'2 (CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr)),
     .Etempvar Arm64Addressing._t'3 (CC.tptr CC.tuchar),
     .Etempvar Arm64Addressing._t'4 (CC.tptr (CC.tvolatile CC.tuchar)),
     .Etempvar Arm64Addressing._t'5 (CC.tptr CC.tuchar),
     .Etempvar Arm64Addressing._t'6 CC.tuint,.Etempvar Arm64Addressing._t'7 CC.tlong,
     .Econst_int (30#32) CC.tuint,
     .Ecast (.Ecast (.Etempvar Arm64Addressing.___a64_lr CC.tulong) CC.tlong) (CC.tptr CC.tvoid),
     .Econst_int (9#32) CC.tuint] := rfl

def callTemps {m header offset} (h : Header m header offset) (address : BitVec 64) (le : CC.TempEnv) : CC.TempEnv :=
  let lr := le.set Arm64Addressing.___a64_lr (CC.Val.Vlong address)
  let coords := lr.set Arm64Addressing._t'1 (CC.Val.Vptr h.coordinates h.coordinateOffset)
  let regs := coords.set Arm64Addressing._t'2 (CC.Val.Vptr h.registers h.registerOffset)
  let tags := regs.set Arm64Addressing._t'3 (CC.Val.Vptr h.tags h.tagOffset)
  let bytes := tags.set Arm64Addressing._t'4 (CC.Val.Vptr h.bytes h.byteOffset)
  let stack := bytes.set Arm64Addressing._t'5 (CC.Val.Vptr h.stackTags h.stackTagOffset)
  let capacity := stack.set Arm64Addressing._t'6 (CC.Val.Vint h.capacity)
  capacity.set Arm64Addressing._t'7 (CC.Val.Vlong h.bias)

def arguments {m header offset} (h : Header m header offset) (address : BitVec 64) : List CC.Val :=
  [.Vptr h.coordinates h.coordinateOffset,.Vptr h.registers h.registerOffset,
   .Vptr h.tags h.tagOffset,.Vptr h.bytes h.byteOffset,.Vptr h.stackTags h.stackTagOffset,
   .Vint h.capacity,.Vlong h.bias,.Vlong (30#64),.Vlong address,.Vint (9#32)]

def inner (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq returnStmt k)

def writerCont {m header offset} (h : Header m header offset) (address : BitVec 64)
    (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none entry (allocation m).1 (callTemps h address le) (inner k)

/-- Split the real mature-linker resolution into its actual symbol and body. -/
theorem writer_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv Arm64Addressing._kprog_arm64_write_ptr = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some (.Internal writer) := by
  exact (Option.bind_eq_some_iff
    (x := CC.Genv.findSymbol ge.genv_genv Arm64Addressing._kprog_arm64_write_ptr)
    (f := CC.Genv.findFunctPtr ge.genv_genv) (b := CC.FunDef.Internal writer)).mp
      Arm64MemcpyLinkProgram.writer_binding

private theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get Arm64Addressing._kprog_arm64_write_ptr = none := by
  have absent : Arm64Addressing._kprog_arm64_write_ptr ∉ CC.varNames entry.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MemcpyLinkSource.allocated m) absent

set_option hygiene false in
/-- Genuine LR assignment and all seven header reads on the SAME reached
heap. Current loads are consequences of the original caller observations. -/
theorem setup {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (before : CC.Mem)
    (old : header.toNat < m.nextblock.toNat) (frame : FrameBelow m.nextblock m before)
    (address : BitVec 64) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get Arm64Addressing._addressing = some (.Vptr header offset))
    (nextAddress : le.get Arm64Addressing._address = some (.Vlong address)) :
    InternalRun ge 26
      (.State entry afterTables k (allocation m).1 le before)
      (.State entry callStmt (inner k) (allocation m).1 (callTemps h address le) before) := by
  have coordinatesRead := (frame.load CC.Mptr header (slot offset 0) old).trans h.coordinatesRead
  have registersRead := (frame.load CC.Mptr header (slot offset 8) old).trans h.registersRead
  have tagsRead := (frame.load CC.Mptr header (slot offset 16) old).trans h.tagsRead
  have bytesRead := (frame.load CC.Mptr header (slot offset 24) old).trans h.bytesRead
  have stackTagsRead := (frame.load CC.Mptr header (slot offset 32) old).trans h.stackTagsRead
  have capacityRead := (frame.load .Mint32 header (slot offset 48) old).trans h.capacityRead
  have biasRead := (frame.load .Mint64 header (slot offset 56) old).trans h.biasRead
  simp only [slot,CC.Mptr,CC.Archi.ptr64,ite_true] at coordinatesRead registersRead tagsRead bytesRead stackTagsRead capacityRead biasRead
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [tail_source,body,parts,inner,returnStmt,callTemps,callStmt,
        CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.lvalOfField,CC.accessMode,
        CC.typeof,CC.Mem.loadv,CC.PTree.gss,CC.PTree.gso,input,nextAddress,
        Arm64MemcpyLinkSource.header_layout.1,Arm64MemcpyLinkSource.header_layout.2.1,
        Arm64MemcpyLinkSource.header_layout.2.2.1,Arm64MemcpyLinkSource.header_layout.2.2.2.1,
        Arm64MemcpyLinkSource.header_layout.2.2.2.2.1,Arm64MemcpyLinkSource.header_layout.2.2.2.2.2.1,
        Arm64MemcpyLinkSource.header_layout.2.2.2.2.2.2.1,Arm64MemcpyLinkSource.header_layout.2.2.2.2.2.2.2.1,
        coordinatesRead,registersRead,tagsRead,bytesRead,stackTagsRead,capacityRead,biasRead,
        CC.tptr,CC.tuchar,CC.tuint,CC.tlong,CC.tulong,CC.Mptr,CC.Archi.ptr64,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self,
        Bool.false_eq_true,Bool.true_eq_false] <;> try rfl)
    for _ in [:26] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Complete actual C CALL evaluation retains all ten original argument
casts, the real renamed writer,reg30/tag9 and the SAME saved caller. -/
theorem call_step {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (address : BitVec 64) (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem) :
    CC.Step2 ge
      (.State entry callStmt (inner k) (allocation m).1 (callTemps h address le) before) CC.E0
      (.Callstate (.Internal writer) (arguments h address) (writerCont h address le k) before) := by
  obtain ⟨b,symbol,funct⟩ := writer_lookup
  rw [call_source]
  apply CC.Step.call (tyargs := types) (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr b 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed m,symbol,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp +decide only [types,arguments,callTemps,CC.doEvalExprlist,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.typeof,
      CC.tptr,CC.tvoid,CC.tuchar,CC.tuint,CC.tlong,CC.tulong,CC.Archi.ptr64,
      ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using funct
  · rfl

theorem continue_after_tables {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (before : CC.Mem)
    (old : header.toNat < m.nextblock.toNat) (frame : FrameBelow m.nextblock m before)
    (address : BitVec 64) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get Arm64Addressing._addressing = some (.Vptr header offset))
    (nextAddress : le.get Arm64Addressing._address = some (.Vlong address)) :
    InternalRun ge 27
      (.State entry afterTables k (allocation m).1 le before)
      (.Callstate (.Internal writer) (arguments h address) (writerCont h address le k) before) :=
  (setup h before old frame address le k input nextAddress).trans
    (InternalRun.step trivial (call_step h address le k before) (InternalRun.refl _))

def initializedTemps {m header offset} (h : Header m header offset) (address : BitVec 64) : CC.TempEnv :=
  Arm64MemcpyLinkSource.tableTemps true (List.finRange 31) (.Vptr h.tags h.tagOffset)
    (Arm64MemcpyLinkSource.tableTemps false (List.finRange 31) (.Vptr h.registers h.registerOffset)
      (Arm64MemcpyLinkSource.temps (.Vptr header offset) address))

theorem initialized_parameters {m header offset} (h : Header m header offset) (address : BitVec 64) :
    (initializedTemps h address).get Arm64Addressing._addressing = some (.Vptr header offset) ∧
    (initializedTemps h address).get Arm64Addressing._address = some (.Vlong address) := by
  have words := Arm64MemcpyLinkSource.tableTemps_parameters false (List.finRange 31)
    (.Vptr h.registers h.registerOffset) (Arm64MemcpyLinkSource.temps (.Vptr header offset) address)
  have tags := Arm64MemcpyLinkSource.tableTemps_parameters true (List.finRange 31)
    (.Vptr h.tags h.tagOffset)
    (Arm64MemcpyLinkSource.tableTemps false (List.finRange 31) (.Vptr h.registers h.registerOffset)
      (Arm64MemcpyLinkSource.temps (.Vptr header offset) address))
  refine ⟨(tags.1.trans words.1).trans ?_,(tags.2.trans words.2).trans ?_⟩
  all_goals simp +decide only [Arm64MemcpyLinkSource.temps,CC.PTree.gss,CC.PTree.gso]

theorem lr_readback {m header offset} (h : Header m header offset) (address : BitVec 64) (le : CC.TempEnv) :
    (callTemps h address le).get Arm64Addressing.___a64_lr = some (.Vlong address) := by
  simp +decide only [callTemps,CC.PTree.gss,CC.PTree.gso]

/-- Original function entry and both actual table initializations feed the
SAME reached heap to LR/header setup and genuine ten-argument writer CALL.
The prefix is executed once and its true tables/frame/permissions remain. -/
theorem execute {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (address : BitVec 64) (k : CC.Cont) :
    ∃ (words : Arm64MemcpyLinkSource.Table false m)
      (tags : Arm64MemcpyLinkSource.Table true m) (before : CC.Mem),
      InternalRun ge 400 (.Callstate (.Internal entry) [.Vptr header offset,.Vlong address] k m)
        (.Callstate (.Internal writer) (arguments h address)
          (writerCont h address (initializedTemps h address) k) before) ∧
      (∀ i, CC.Mem.load CC.Mptr before words.block (8 * (i.val : Int)) =
        some (.Vptr h.registers
          (CC.Integers.Ptrofs.add h.registerOffset (Arm64MemcpyLinkSource.cellOffset false i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr before tags.block (8 * (i.val : Int)) =
        some (.Vptr h.tags
          (CC.Integers.Ptrofs.add h.tagOffset (Arm64MemcpyLinkSource.cellOffset true i)))) ∧
      FrameBelow m.nextblock m before ∧
      before.access = (allocation m).2.access ∧ before.nextblock = (allocation m).2.nextblock := by
  obtain ⟨words,tags,before,entered,wordSlots,tagSlots,frame,access,next⟩ :=
    Arm64MemcpyLinkSource.initialize_tables m header h.registers h.tags offset h.registerOffset h.tagOffset
      address k old h.registersRead h.tagsRead
  have inputs := initialized_parameters h address
  have called := continue_after_tables h before old frame address (initializedTemps h address) k inputs.1 inputs.2
  exact ⟨words,tags,before,entered.trans called,wordSlots,tagSlots,frame,access,next⟩

end KProgFormal.ClightRefinement.Arm64MemcpyLinkCall
