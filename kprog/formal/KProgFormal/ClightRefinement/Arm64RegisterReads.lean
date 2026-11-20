import KProgFormal.ClightRefinement.StepEquations
import KProgFormal.ClightRefinement.Arm64Registers
import KProgFormal.ClightRefinement.Arm64OriginCache

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64RegisterReads

def ge : CC.CGenv := Arm64Program.prog.globalenv

def reader (tags : Bool) : CC.Function :=
  if tags then Arm64Program.f_kprog_arm64_program_tag else Arm64Program.f_kprog_arm64_program_raw

private def selected (tags pointers : Bool) : CC.Function :=
  if tags then reader true else if pointers then Arm64Program.f_kprog_arm64_program_pointer
  else reader false

private def entryComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private def cellComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Program._arm64_sim_gpr).get (by decide +kernel)

private theorem layouts :
    ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    ge.genv_cenv.get Arm64Program._arm64_sim_gpr = some cellComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Program._cells entryComposite.co_members = .OK (0, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Program._tag_cells entryComposite.co_members = .OK (8, .Full) ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Program._x cellComposite.co_members = .OK (0, .Full) := by
  decide +kernel

/-- Only the actual layout lookups used by the ordinary combined reader.
Other composites, function bodies and symbol tables may differ. -/
structure GprLayout (world : CC.CGenv) : Prop where
  entry : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite
  cell : world.genv_cenv.get Arm64Program._arm64_sim_gpr = some cellComposite
  cells : CC.fieldOffset world.genv_cenv Arm64Program._cells entryComposite.co_members = .OK (0, .Full)
  tags : CC.fieldOffset world.genv_cenv Arm64Program._tag_cells entryComposite.co_members = .OK (8, .Full)
  payload : CC.unionFieldOffset world.genv_cenv Arm64Program._x cellComposite.co_members = .OK (0, .Full)

/-- The existing standalone export supplies the same layout contract. -/
theorem program_layout : GprLayout ge :=
  ⟨layouts.1, layouts.2.1, layouts.2.2.1, layouts.2.2.2.1, layouts.2.2.2.2⟩

private theorem pointer_offset :
    CC.unionFieldOffset ge.genv_cenv Arm64Program._ptr cellComposite.co_members = .OK (0, .Full) := by
  decide +kernel

private theorem sp_offset :
    CC.fieldOffset ge.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40, .Full) := by
  decide +kernel

private theorem index_nat (i : Fin 31) : (BitVec.ofNat 64 i.val).toNat = i.val := by
  simp only [BitVec.toNat_ofNat]
  exact Nat.mod_eq_of_lt (by have := i.isLt; omega)

private theorem index_cast (i : Fin 31) (m : CC.Mem) :
    CC.Cop.semCast (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong CC.tuchar m =
      some (.Vint (BitVec.ofNat 32 i.val)) := by
  have small : i.val < 2 ^ 8 := by have := i.isLt; omega
  change some (CC.Val.Vint (CC.Cop.castIntInt .I8 .Unsigned
    (CC.Integers.Int.repr ((BitVec.ofNat 64 i.val).toNat : Int)))) = _
  rw [index_nat]
  change some (CC.Val.Vint (BitVec.ofInt 32 (i.val : Int) &&& (255#32))) = _
  rw [BitVec.ofInt_natCast,
    ← BitVec.setWidth_ofNat_of_le_of_lt (by decide : 8 ≤ 32) small]
  congr 2
  change (BitVec.ofNat 8 i.val).setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = _
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

private theorem index_offset (i : Fin 31) :
    CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Integers.Ptrofs.of_ints (BitVec.ofNat 32 i.val)) =
    CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z)) := by
  have bound := i.isLt
  have norm : (BitVec.ofNat 32 i.val).toNat = i.val := by
    simp only [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by omega)
  have signed : (BitVec.ofNat 32 i.val).toInt = (i.val : Int) := by
    rw [BitVec.toInt_eq_toNat_of_lt (by rw [norm]; omega), norm]
  change (8#64) * BitVec.ofInt 64 (BitVec.ofNat 32 i.val).toInt =
    BitVec.ofInt 64 (8 * (i.val : Int))
  simp only [signed, BitVec.ofInt_natCast, ← BitVec.ofNat_mul]
  rw [show (8 : Int) * (i.val : Int) = ((8 * i.val : Nat) : Int) by omega,
    BitVec.ofInt_natCast]

private theorem offset_zero (ofs : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 0) = ofs := BitVec.add_zero ofs

private theorem checked_load {frontier : CC.Block} {chunk : CC.Chunk} {m : CC.Mem}
    {address value : CC.Val} (read : Arm64EntryMemory.load frontier chunk m address = some value) :
    CC.Mem.loadv chunk m address = some value := by
  obtain ⟨_, _, rfl, _, actual⟩ := Arm64EntryMemory.load_pointer read
  exact actual

private theorem field_load (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (name : CC.Ident) (delta : CC.Z) (value : CC.Val)
    (offset : CC.fieldOffset ge.genv_cenv name entryComposite.co_members = .OK (delta, .Full))
    (read : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs) name = some value) :
    CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr delta))) = some value := by
  have address : Arm64EntryMemory.fieldAddress (.Vptr b ofs) name =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr delta))) := by
    have binding : Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry =
        some entryComposite := layouts.1
    change CC.fieldOffset Arm64EntryMemory.composites name entryComposite.co_members = _ at offset
    simp only [Arm64EntryMemory.fieldAddress, binding, bind, pure, Option.bind_some,
      offset, CC.Val.offsetPtr]
  exact checked_load (by simpa only [Arm64EntryMemory.field, address, bind, Option.bind_some] using read)

private theorem gpr_executes (tags pointers : Bool) (i : Fin 31)
    (b cb vb : CC.Block) (ofs co vo : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (tag : BitVec 8)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr (if tags then 8 else 0)))) = some (.Vptr cb co))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (cell : CC.Mem.loadv (if tags then .Mint8unsigned else .Mint64) m (.Vptr vb vo) =
      some (if tags then .Vint (tag.setWidth 32) else value))
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps ge 28 (.Callstate (.Internal (selected tags pointers))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) =
      some (CC.E0, .Returnstate (if tags then .Vint (tag.setWidth 32) else value)
        (CC.callCont k) m) ∧
    InternalPath ge 28 (.Callstate (.Internal (selected tags pointers))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) := by
  have bound := i.isLt
  have ne : BitVec.ofNat 64 i.val ≠ (32#64) := by
    intro h
    have eq := congrArg BitVec.toNat h
    rw [index_nat] at eq
    simp only [BitVec.toNat_ofNat] at eq
    omega
  have lt : (BitVec.ofNat 64 i.val).ult (31#64) = true := by
    rw [BitVec.ult_eq_decide, index_nat]
    simp only [BitVec.toNat_ofNat]
    simp [bound]
  have cast := index_cast i m
  simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tulong, CC.tuchar, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    BitVec.toNat_ofNat, Int.natCast_emod, Option.some.injEq, CC.Val.Vint.injEq] at cast
  simp only [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
    ↓reduceIte] at valueCast
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header slot cell
  cases pointers <;> cases tags <;> simp only [Bool.false_eq_true, ite_false, ite_true, offset_zero] at header cell
  all_goals
    simp +decide [selected, reader, steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      Arm64Program.f_kprog_arm64_program_raw, Arm64Program.f_kprog_arm64_program_tag,
      Arm64Program.f_kprog_arm64_program_pointer, pointer_offset,
      CC.doAllocVariables, CC.bindParameterTemps,
      CC.createUndefTemps, CC.PTree.gso, CC.doEvalExpr, CC.lvalOfField,
      CC.doDerefLoc, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
      layouts.1, layouts.2.1, layouts.2.2.1, layouts.2.2.2.1, layouts.2.2.2.2,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt, index_offset, cast,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
      CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq, CC.Integers.MI.ltu, ne, lt,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.unsigned,
      CC.Integers.Int.unsigned,
      CC.Integers.MI.unsigned,
      offset_zero,
      CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tvoid, CC.sizeof, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
      CC.blocksOfEnv, CC.Mem.freeList,
      CC.emptyEnv, CC.E0, CC.Eapp, header, slot, cell, valueCast, empty]

private theorem gpr_calls (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw) :
    InternalRun ge 28 (.Callstate (.Internal (reader false))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) ∧
    InternalRun ge 28 (.Callstate (.Internal (reader true))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate (.Vint (tag.setWidth 32)) (CC.callCont k) m) ∧
    InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) := by
  have valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value := by
    cases value <;> try contradiction
    all_goals rfl
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have rawExec := gpr_executes false false i b cb vb ofs co vo m k value tag
    (field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells) slot cell valueCast
  have tagExec := gpr_executes true false i b tb kb ofs to ko m k value tag
    (field_load frontier b ofs m _ 8 _ layouts.2.2.2.1 tags) tagSlot kind valueCast
  have pointerExec := gpr_executes false true i b cb vb ofs co vo m k value tag
    (field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells) slot cell valueCast
  exact ⟨internalRun_of_steps rawExec.2 rawExec.1, internalRun_of_steps tagExec.2 tagExec.1,
    internalRun_of_steps pointerExec.2 pointerExec.1⟩

/-- Both real exported readers follow the same cells observed by gpr.
Pointers keep their identity; ValueRep excludes undefined/invented values. -/
theorem gpr_returns (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw) :
    InternalRun ge 28 (.Callstate (.Internal (reader false))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) ∧
    InternalRun ge 28 (.Callstate (.Internal (reader true))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate (.Vint (tag.setWidth 32)) (CC.callCont k) m) := by
  have calls := gpr_calls addresses frontier b ofs i m k value raw tag observed represented
  exact ⟨calls.1, calls.2.1⟩

/-- The pointer view reads the same union cell with the actual pointer-field
layout. Vptr and Vlong representatives remain exact, including null/offset bits. -/
theorem gpr_pointer_returns (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw) :
    InternalRun ge 28 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) :=
  (gpr_calls addresses frontier b ofs i m k value raw tag observed represented).2.2

/-- Every pair of Kstop returns from the actual raw/tag functions agrees
with the full-register relation and its M3 native materialization. The cell
index is proved by the actual default export; compact source profiles still
need their own producer map binding. -/
theorem register_return_corresponds (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Reference.AArch64.Gpr)
    (m : CC.Mem) (native : Reference.AArch64.State)
    (rep : Arm64Registers.Represents addresses origins (fun reg => reg.val)
      frontier m (.Vptr b ofs) native)
    (rawTrace tagTrace : CC.Trace) (rawValue tagValue : CC.Val) (rawMemory tagMemory : CC.Mem)
    (rawReturn : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal (reader false)) [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] .Kstop m)
      rawTrace (.Returnstate rawValue .Kstop rawMemory))
    (tagReturn : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal (reader true)) [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] .Kstop m)
      tagTrace (.Returnstate tagValue .Kstop tagMemory)) :
    rawTrace = CC.E0 ∧ tagTrace = CC.E0 ∧ rawMemory = m ∧ tagMemory = m ∧
      ∃ bits tag, Arm64Registers.ValueRep addresses rawValue bits ∧
        tagValue = .Vint (tag.setWidth 32) ∧
        Reference.AArch64.gpr native i =
          Reference.Provenance.AArch64.materialize origins bits tag := by
  obtain ⟨value, bits, tag, read, binding, nativeBits⟩ := rep.gpr i
  obtain ⟨rawRun, tagRun⟩ := gpr_returns addresses frontier b ofs i m .Kstop
    value bits tag read binding
  have stop : ∀ (v : CC.Val) (memory : CC.Mem) trace next,
      ¬ CC.Step2 ge (.Returnstate v .Kstop memory) trace next := by
    intro v memory trace next step
    cases step
  obtain ⟨rawSilent, rawSame⟩ := rawRun.endpoint_unique (stop _ _) rawReturn (stop _ _)
  obtain ⟨tagSilent, tagSame⟩ := tagRun.endpoint_unique (stop _ _) tagReturn (stop _ _)
  cases rawSame
  cases tagSame
  exact ⟨rawSilent, tagSilent, rfl, rfl, bits, tag, binding, rfl, nativeBits⟩

private theorem sp_executes (pointers : Bool) (b sb : CC.Block)
    (ofs so : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 40))) = some (.Vptr sb so))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr sb so) = some (.Vlong offset)) :
    steps ge 21 (.Callstate (.Internal (selected false pointers))
      [.Vptr b ofs, .Vlong (32#64)] k m) =
      some (CC.E0, .Returnstate (.Vlong offset) (CC.callCont k) m) ∧
    InternalPath ge 21 (.Callstate (.Internal (selected false pointers))
      [.Vptr b ofs, .Vlong (32#64)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header
  cases pointers <;>
    simp +decide [selected, reader, steps, InternalPath, InternalState, CC.doStep,
      CC.doFunctionEntry2, Arm64Program.f_kprog_arm64_program_raw,
      Arm64Program.f_kprog_arm64_program_pointer,
      CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps, CC.PTree.gso,
      CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.typeconv,
      CC.removeAttributes, CC.tattr, CC.accessMode, layouts.1, sp_offset,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
      CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tvoid, CC.tint, CC.tuint, CC.tlong, CC.tulong,
      CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, header, cell, empty]

/-- The real SP tag branch needs no memory read or validity assumption on
its entry argument. Its constant is the C STACK tag, not a native SP value. -/
theorem sp_tag_executes (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    steps ge 15 (.Callstate (.Internal (reader true)) [entry, .Vlong (32#64)] k m) =
      some (CC.E0, .Returnstate (.Vint (4#32)) (CC.callCont k) m) ∧
    InternalPath ge 15 (.Callstate (.Internal (reader true)) [entry, .Vlong (32#64)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp +decide [reader, steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
    Arm64Program.f_kprog_arm64_program_tag, CC.doAllocVariables, CC.bindParameterTemps,
    CC.createUndefTemps, CC.PTree.gso, CC.doEvalExpr, CC.typeof, CC.typeconv,
    CC.removeAttributes, CC.tattr,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.tptr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty]

/-- Complete SP tag call for any entry value, memory and continuation. -/
theorem sp_tag_returns (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    InternalRun ge 15 (.Callstate (.Internal (reader true)) [entry, .Vlong (32#64)] k m)
      (.Returnstate (.Vint (4#32)) (CC.callCont k) m) := by
  have run := sp_tag_executes entry m k
  exact internalRun_of_steps run.2 run.1

/-- Both SP value views read the actual borrowed signed-long slot. A pointer
cast of its Vlong offset remains that offset, not a fabricated native address. -/
theorem sp_returns (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64)
    (read : Arm64EntryMemory.borrowed frontier .Mint64 m (.Vptr b ofs) Arm64Program._sp =
      some (.Vlong offset)) :
    InternalRun ge 21 (.Callstate (.Internal (reader false)) [.Vptr b ofs, .Vlong (32#64)] k m)
      (.Returnstate (.Vlong offset) (CC.callCont k) m) ∧
    InternalRun ge 21 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
      [.Vptr b ofs, .Vlong (32#64)] k m)
      (.Returnstate (.Vlong offset) (CC.callCont k) m) ∧
    InternalRun ge 15 (.Callstate (.Internal (reader true)) [.Vptr b ofs, .Vlong (32#64)] k m)
      (.Returnstate (.Vint (4#32)) (CC.callCont k) m) := by
  simp only [Arm64EntryMemory.borrowed, bind, Option.bind_eq_some_iff] at read
  obtain ⟨sp, header, cell⟩ := read
  obtain ⟨sb, so, rfl, _, cell⟩ := Arm64EntryMemory.load_pointer cell
  have actualHeader := field_load frontier b ofs m _ 40 _ sp_offset header
  have raw := sp_executes false b sb ofs so m k offset actualHeader cell
  have pointer := sp_executes true b sb ofs so m k offset actualHeader cell
  exact ⟨internalRun_of_steps raw.2 raw.1, internalRun_of_steps pointer.2 pointer.1,
    sp_tag_returns (.Vptr b ofs) m k⟩

private theorem stopped_return {n : Nat} {initial : CC.State} {value result : CC.Val}
    {m after : CC.Mem} {trace : CC.Trace}
    (run : InternalRun ge n initial (.Returnstate value .Kstop m))
    (observed : CC.Star (CC.Step2 ge) initial trace (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ result = value ∧ after = m := by
  have stop : ∀ (v : CC.Val) (memory : CC.Mem) t next,
      ¬ CC.Step2 ge (.Returnstate v .Kstop memory) t next := by
    intro v memory t next step
    cases step
  obtain ⟨silent, same⟩ := run.endpoint_unique (stop _ _) observed (stop _ _)
  cases same
  exact ⟨silent, rfl, rfl⟩

/-- Every pointer-view return agrees with the represented native GPR through
its original tag and M3 materialization. Relative words remain relative here. -/
theorem pointer_return_corresponds (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Reference.AArch64.Gpr)
    (m : CC.Mem) (native : Reference.AArch64.State)
    (rep : Arm64Registers.Represents addresses origins (fun reg => reg.val)
      frontier m (.Vptr b ofs) native)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_pointer)
        [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] .Kstop m) trace
      (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ after = m ∧ ∃ bits tag,
      Arm64Registers.ValueRep addresses result bits ∧
      Reference.AArch64.gpr native i =
        Reference.Provenance.AArch64.materialize origins bits tag := by
  obtain ⟨value, bits, tag, read, binding, nativeBits⟩ := rep.gpr i
  have run := gpr_pointer_returns addresses frontier b ofs i m .Kstop value bits tag read binding
  obtain ⟨silent, sameValue, sameMemory⟩ := stopped_return run observed
  refine ⟨silent, sameMemory, bits, tag, ?_, nativeBits⟩
  rw [sameValue]
  exact binding

/-- Native SP uses source offset plus the actual invocation stack origin.
The C pointer view returns that same offset, not the native physical address. -/
theorem sp_return_corresponds (pointers : Bool) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (native : Reference.AArch64.State)
    (rep : Arm64Registers.Represents addresses origins cells frontier m (.Vptr b ofs) native)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal (if pointers then Arm64Program.f_kprog_arm64_program_pointer
        else reader false)) [.Vptr b ofs, .Vlong (32#64)] .Kstop m) trace
      (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ after = m ∧ ∃ offset,
      result = .Vlong offset ∧ Reference.AArch64.sp native = offset + origins.stack := by
  obtain ⟨offset, read, nativeBits⟩ := rep.sp
  have calls := sp_returns frontier b ofs m .Kstop offset read
  have run : InternalRun ge 21
      (.Callstate (.Internal (if pointers then Arm64Program.f_kprog_arm64_program_pointer
        else reader false)) [.Vptr b ofs, .Vlong (32#64)] .Kstop m)
      (.Returnstate (.Vlong offset) .Kstop m) := by
    cases pointers
    · exact calls.1
    · exact calls.2.1
  obtain ⟨silent, sameValue, sameMemory⟩ := stopped_return run observed
  exact ⟨silent, sameMemory, offset, sameValue, nativeBits⟩

/-- Every top-level SP tag return is STACK, with exact complete-memory
preservation, for every entry value and proposed result/trace/memory. -/
theorem sp_tag_return_unique (entry : CC.Val) (m : CC.Mem)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal (reader true)) [entry, .Vlong (32#64)] .Kstop m) trace
      (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ result = .Vint (4#32) ∧ after = m :=
  stopped_return (sp_tag_returns entry m .Kstop) observed

private def readHandler := Arm64Program.f_kprog_arm64_program_read

private structure ReadParts where
  outer : CC.Stmt
  raw : CC.Stmt
  tags : CC.Stmt
  materialize : CC.Stmt
  ret : CC.Stmt

private def unpackRead : Option ReadParts :=
  match readHandler.fn_body with
  | .Ssequence (.Sloop (outer@(.Ssequence raw (.Ssequence tags materialize))) .Sbreak) ret =>
      some ⟨outer, raw, tags, materialize, ret⟩
  | _ => none

private def readParts : ReadParts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(unpackRead.get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `read_body value

private def readTemps (entry : CC.Val) (reg : BitVec 64) : CC.TempEnv :=
  ((CC.createUndefTemps readHandler.fn_temps).set Arm64Program._entry entry).set
    Arm64Program._reg (.Vlong reg)

private theorem read_names :
    CC.listNorepet (CC.varNames readHandler.fn_vars) ∧
    CC.listNorepet (CC.varNames readHandler.fn_params) ∧
    CC.listDisjoint (CC.varNames readHandler.fn_params) (CC.varNames readHandler.fn_temps) := by
  decide +kernel

private theorem read_entry_bound (world : CC.CGenv) (m : CC.Mem) (entry : CC.Val) (reg : BitVec 64) :
    CC.doFunctionEntry2 world readHandler [entry, .Vlong reg] m =
      some (CC.emptyEnv, readTemps entry reg, m) := by
  unfold CC.doFunctionEntry2
  rw [ite_eq_left read_names]
  rfl

private theorem step_read_bound (world : CC.CGenv) (entry : CC.Val) (reg : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.Callstate (.Internal readHandler) [entry, .Vlong reg] k m) =
      some (CC.E0, .State readHandler
        (.Ssequence (.Sloop readParts.outer .Sbreak) readParts.ret) k CC.emptyEnv
        (readTemps entry reg) m) := by
  simp only [CC.doStep, read_entry_bound]
  rfl

private theorem step_read (entry : CC.Val) (reg : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep ge (.Callstate (.Internal readHandler) [entry, .Vlong reg] k m) =
      some (CC.E0, .State readHandler
        (.Ssequence (.Sloop readParts.outer .Sbreak) readParts.ret) k CC.emptyEnv
        (readTemps entry reg) m) :=
  step_read_bound ge entry reg m k

private def readCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 readParts.outer .Sbreak (.Kseq readParts.ret k)

private def gprReadTemps (entry cells cell tags tagCell value : CC.Val)
    (reg : BitVec 64) (tag : BitVec 8) : CC.TempEnv :=
  let vtag := CC.Val.Vint (tag.setWidth 32)
  ((((((((((((((readTemps entry reg).set Arm64Program.___a64_l_reg (.Vlong reg)).set
    Arm64Program._t'18 cells).set Arm64Program._t'19 cell).set Arm64Program._t'20 value).set
    Arm64Program._t'1 value).set Arm64Program._t'1 value).set Arm64Program.___a64_read_value value).set
    Arm64Program.___a64_l_reg__1 (.Vlong reg)).set Arm64Program._t'15 tags).set
    Arm64Program._t'16 tagCell).set Arm64Program._t'17 vtag).set Arm64Program._t'2 vtag).set
    Arm64Program._t'2 vtag).set Arm64Program.___a64_read_tag vtag

private theorem read_tag_mask (tag : BitVec 8) :
    tag.setWidth 32 &&& (255#32) = tag.setWidth 32 := by
  change tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = tag.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- The actual combined reader reaches its materialization stage after 55 internal
transitions, with the raw value and tag loaded from the supplied entry tables.
This prefix does not claim a complete handler refinement. -/
theorem gpr_read_prefix_bound (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont)
    (value : CC.Val) (tag : BitVec 8)
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some value)
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint (tag.setWidth 32)))
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps world 55 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) =
      some (CC.E0, .State readHandler readParts.materialize (readCont k) CC.emptyEnv
        (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
          value (BitVec.ofNat 64 i.val) tag) m) ∧
    InternalPath world 55 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) := by
  have bound := i.isLt
  have ne : BitVec.ofNat 64 i.val ≠ (32#64) := by
    intro h
    have eq := congrArg BitVec.toNat h
    rw [index_nat] at eq
    simp only [BitVec.toNat_ofNat] at eq
    omega
  have lt : (BitVec.ofNat 64 i.val).ult (31#64) = true := by
    rw [BitVec.ult_eq_decide, index_nat]
    simp only [BitVec.toNat_ofNat]
    simp [bound]
  have cast := index_cast i m
  simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tulong, CC.tuchar, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    BitVec.toNat_ofNat, Int.natCast_emod, Option.some.injEq, CC.Val.Vint.injEq] at cast
  simp only [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
    ↓reduceIte] at valueCast
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at cells cellSlot tags tagSlot
  simp +decide [steps, InternalPath, InternalState, step_read_bound, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    readTemps, gprReadTemps, CC.PTree.gso, CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc,
    CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
    layout.entry, layout.cell, layout.cells, layout.tags, layout.payload,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt, index_offset, cast,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq, CC.Integers.MI.ltu, ne, lt,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.unsigned,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, offset_zero, read_tag_mask,
    CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.sizeof, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.emptyEnv, CC.E0, CC.Eapp, cells, cellSlot, tags, tagSlot, cell, kind, valueCast]

theorem gpr_read_prefix (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont)
    (value : CC.Val) (tag : BitVec 8)
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some value)
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint (tag.setWidth 32)))
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps ge 55 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) =
      some (CC.E0, .State readHandler readParts.materialize (readCont k) CC.emptyEnv
        (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
          value (BitVec.ofNat 64 i.val) tag) m) ∧
    InternalPath ge 55 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) :=
  gpr_read_prefix_bound ge program_layout i b cb vb tb kb ofs co vo to ko m k value tag
    cells cellSlot tags tagSlot cell kind valueCast

private theorem read_return_type : readHandler.fn_return = CC.tulong := rfl

private theorem read_inert_tail_bound (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value : CC.Val) (tag : BitVec 8)
    (valueRead : le.get Arm64Program.___a64_read_value = some value)
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (tag.setWidth 32)))
    (hs : tag ≠ 4) (hr : tag ≠ 10)
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps world 18 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate value (CC.callCont k) m) ∧
    InternalPath world 18 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  have notStack : tag.setWidth 32 ≠ (4#32) := by
    intro h; apply hs
    simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
  have notReturn : tag.setWidth 32 ≠ (10#32) := by
    intro h; apply hr
    simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
    ↓reduceIte] at valueCast
  simp +decide [steps, InternalPath, InternalState, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    step_return, read_return_type, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
    CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, read_tag_mask,
    CC.tuchar, CC.tint, CC.tuint, CC.tulong, CC.Archi.ptr64,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp,
    valueRead, tagRead, valueCast, notStack, notReturn, empty]


/-- The complete exported combined reader returns the same scalar or bound
pointer for every non-relative tag. It executes 73 internal transitions and
preserves all memory, without any cache/provider premise. -/
theorem gpr_read_nonrelative_bound (world : CC.CGenv) (layout : GprLayout world) (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (notStack : tag ≠ 4) (notReturn : tag ≠ 10) :
    InternalRun world 73 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) := by
  have valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value := by
    cases value <;> try contradiction
    all_goals rfl
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells
  simp only [offset_zero] at cellsLoad
  have beforeCall := gpr_read_prefix_bound world layout i b cb vb tb kb ofs co vo to ko m k value tag
    cellsLoad slot
    (field_load frontier b ofs m _ 8 _ layouts.2.2.2.1 tags) tagSlot cell kind valueCast
  have valueRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) value (BitVec.ofNat 64 i.val) tag).get
      Arm64Program.___a64_read_value = some value := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  have tagRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) value (BitVec.ofNat 64 i.val) tag).get
      Arm64Program.___a64_read_tag = some (.Vint (tag.setWidth 32)) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  have afterRead := read_inert_tail_bound world m k _ value tag valueRead tagRead notStack notReturn valueCast
  exact (internalRun_of_steps beforeCall.2 beforeCall.1).trans
    (internalRun_of_steps afterRead.2 afterRead.1)


theorem gpr_read_nonrelative (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (notStack : tag ≠ 4) (notReturn : tag ≠ 10) :
    InternalRun ge 73 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) :=
  gpr_read_nonrelative_bound ge program_layout addresses frontier b ofs i m k value raw tag
    observed represented notStack notReturn

/-- Every Kstop return of the actual combined reader has the represented M3
materialized bits for the 254 non-relative tags. Undefined and unbound values
remain outside ValueRep; this law supplies no native origin or cache binding. -/
theorem gpr_read_return_corresponds (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (notStack : tag ≠ 4) (notReturn : tag ≠ 10)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (returned : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] .Kstop m)
      trace (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ after = m ∧ Arm64Registers.ValueRep addresses result
      (Reference.Provenance.AArch64.materialize origins raw tag) := by
  have run := gpr_read_nonrelative addresses frontier b ofs i m .Kstop value raw tag
    observed represented notStack notReturn
  obtain ⟨rfl, rfl, rfl⟩ := stopped_return run returned
  refine ⟨rfl, rfl, ?_⟩
  simpa only [Reference.Provenance.AArch64.materialize,
    ite_eq_right notStack, ite_eq_right notReturn] using represented

/-- Warm caller-owned cache cells of the actual Program entry. The header
contains pointers to each cell; no flat cache layout or alias exclusion is
assumed for this read-only path. -/
def WarmEntryCache (returns : Bool) (frontier : CC.Block) (m : CC.Mem)
    (entry : CC.Val) (base : BitVec 64) : Prop :=
  ∃ valid : BitVec 8, valid ≠ 0 ∧
    Arm64EntryMemory.borrowed frontier .Mint8unsigned m entry
      (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) =
        some (.Vint (valid.setWidth 32)) ∧
    Arm64EntryMemory.borrowed frontier .Mint64 m entry
      (if returns then Arm64Program._return_base else Arm64Program._sp_base) = some (.Vlong base)

private theorem cache_offsets (returns : Bool) :
    CC.fieldOffset ge.genv_cenv
      (if returns then Arm64Program._return_valid else Arm64Program._sp_valid)
      entryComposite.co_members = .OK ((if returns then 56 else 48), .Full) ∧
    CC.fieldOffset ge.genv_cenv
      (if returns then Arm64Program._return_base else Arm64Program._sp_base)
      entryComposite.co_members = .OK ((if returns then 24 else 16), .Full) := by
  cases returns <;> decide +kernel

/-- Only the header lookups used by the STACK reader and its cold cache.
Other composites and global definitions remain unconstrained. -/
structure StackLayout (world : CC.CGenv) : Prop where
  entry : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite
  sp : CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40, .Full)
  valid : CC.fieldOffset world.genv_cenv Arm64Program._sp_valid entryComposite.co_members = .OK (48, .Full)
  base : CC.fieldOffset world.genv_cenv Arm64Program._sp_base entryComposite.co_members = .OK (16, .Full)

theorem program_stack_layout : StackLayout ge :=
  ⟨layouts.1, sp_offset, (cache_offsets false).1, (cache_offsets false).2⟩

private theorem borrowed_loads {frontier : CC.Block} {chunk : CC.Chunk} {m : CC.Mem}
    {entry value : CC.Val} {name : CC.Ident}
    (read : Arm64EntryMemory.borrowed frontier chunk m entry name = some value) :
    ∃ block offset,
      Arm64EntryMemory.field frontier CC.Mptr m entry name = some (.Vptr block offset) ∧
      CC.Mem.loadv chunk m (.Vptr block offset) = some value := by
  unfold Arm64EntryMemory.borrowed at read
  obtain ⟨pointer, header, cell⟩ := Option.bind_eq_some_iff.mp read
  obtain ⟨block, offset, rfl, _, actual⟩ := Arm64EntryMemory.load_pointer cell
  exact ⟨block, offset, header, actual⟩

private theorem read_warm_tail_stack_bound (world : CC.CGenv) (layout : StackLayout world) (b vb bb : CC.Block)
    (ofs vo bo : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (valid : BitVec 8) (nonzero : valid ≠ 0)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag =
      some (.Vint 4#32))
    (validHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (validRead : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (valid.setWidth 32)))
    (baseHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 16))) = some (.Vptr bb bo))
    (baseRead : CC.Mem.loadv .Mint64 m (.Vptr bb bo) = some (.Vlong base)) :
    steps world 36
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) m) ∧
    InternalPath world 36
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  have widened : valid.setWidth 32 ≠ (0#32) := by
    intro h; apply nonzero
    simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at validHeader baseHeader
  simp +decide [steps, InternalPath, InternalState, readParts, readCont,
      step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set,
      step_if, step_return, read_return_type, CC.PTree.gso,
      Arm64Program.s_kprog_arm64_program_read_1, Arm64Program.s_kprog_arm64_program_read_2,
      CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.typeconv,
      CC.removeAttributes, CC.tattr, CC.accessMode, layout.entry, layout.valid, layout.base,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int64.add, CC.tuchar, CC.tint, CC.tuint, CC.tulong,
      CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv,
      CC.E0, CC.Eapp, empty, widened, entryRead, valueRead, tagRead,
      validHeader, validRead, baseHeader, baseRead] <;> rfl

private theorem read_warm_tail_stack (b vb bb : CC.Block)
    (ofs vo bo : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (valid : BitVec 8) (nonzero : valid ≠ 0)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag =
      some (.Vint 4#32))
    (validHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (validRead : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (valid.setWidth 32)))
    (baseHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 16))) = some (.Vptr bb bo))
    (baseRead : CC.Mem.loadv .Mint64 m (.Vptr bb bo) = some (.Vlong base)) :
    steps ge 36
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) m) ∧
    InternalPath ge 36
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) :=
  read_warm_tail_stack_bound ge program_stack_layout b vb bb ofs vo bo m k le value base valid nonzero
    entryRead valueRead tagRead validHeader validRead baseHeader baseRead

private theorem read_warm_tail_return (b vb bb : CC.Block)
    (ofs vo bo : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (valid : BitVec 8) (nonzero : valid ≠ 0)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag =
      some (.Vint 10#32))
    (validHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 56))) = some (.Vptr vb vo))
    (validRead : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (valid.setWidth 32)))
    (baseHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 24))) = some (.Vptr bb bo))
    (baseRead : CC.Mem.loadv .Mint64 m (.Vptr bb bo) = some (.Vlong base)) :
    steps ge 37
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) m) ∧
    InternalPath ge 37
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  have widened : valid.setWidth 32 ≠ (0#32) := by
    intro h; apply nonzero
    simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have offsets := cache_offsets true
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at validHeader baseHeader
  try simp only [Bool.false_eq_true, ↓reduceIte] at offsets validHeader baseHeader tagRead
  simp +decide [steps, InternalPath, InternalState, readParts, readCont,
      step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set,
      step_if, step_return, read_return_type, CC.PTree.gso,
      Arm64Program.s_kprog_arm64_program_read_1, Arm64Program.s_kprog_arm64_program_read_2,
      CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.typeconv,
      CC.removeAttributes, CC.tattr, CC.accessMode, layouts.1, offsets.1, offsets.2,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int64.add, CC.tuchar, CC.tint, CC.tuint, CC.tulong,
      CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv,
      CC.E0, CC.Eapp, empty, widened, entryRead, valueRead, tagRead,
      validHeader, validRead, baseHeader, baseRead] <;> rfl

private theorem read_warm_tail (returns : Bool) (b vb bb : CC.Block)
    (ofs vo bo : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (valid : BitVec 8) (nonzero : valid ≠ 0)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag =
      some (.Vint (if returns then 10#32 else 4#32)))
    (validHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr (if returns then 56 else 48)))) = some (.Vptr vb vo))
    (validRead : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (valid.setWidth 32)))
    (baseHeader : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr (if returns then 24 else 16)))) = some (.Vptr bb bo))
    (baseRead : CC.Mem.loadv .Mint64 m (.Vptr bb bo) = some (.Vlong base)) :
    steps ge (if returns then 37 else 36)
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) m) ∧
    InternalPath ge (if returns then 37 else 36)
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  cases returns
  · exact read_warm_tail_stack b vb bb ofs vo bo m k le value base valid nonzero
      entryRead valueRead tagRead validHeader validRead baseHeader baseRead
  · exact read_warm_tail_return b vb bb ofs vo bo m k le value base valid nonzero
      entryRead valueRead tagRead validHeader validRead baseHeader baseRead

private theorem warm_entry_finishes (returns : Bool) (frontier b : CC.Block)
    (ofs : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag =
      some (.Vint (if returns then 10#32 else 4#32)))
    (cache : WarmEntryCache returns frontier m (.Vptr b ofs) base) :
    InternalRun ge (if returns then 37 else 36)
      (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m)
      (.Returnstate (.Vlong (value + base)) (CC.callCont k) m) := by
  obtain ⟨valid, nz, validObserved, baseObserved⟩ := cache
  obtain ⟨vb, vo, validHeader, validRead⟩ := borrowed_loads validObserved
  obtain ⟨bb, bo, baseHeader, baseRead⟩ := borrowed_loads baseObserved
  have offsets := cache_offsets returns
  have exec := read_warm_tail returns b vb bb ofs vo bo m k le value base valid nz
    entryRead valueRead tagRead
    (field_load frontier b ofs m _ _ _ offsets.1 validHeader) validRead
    (field_load frontier b ofs m _ _ _ offsets.2 baseHeader) baseRead
  exact internalRun_of_steps exec.2 exec.1

/-- The complete actual combined reader materializes a relative GPR word
through its selected borrowed warm cache. STACK takes 91 transitions and RETURN
92. All header/cell loads are imported Clight loads; the entire memory is kept. -/
theorem gpr_read_warm (returns : Bool) (frontier b : CC.Block)
    (ofs : CC.Integers.Ptrofs) (i : Fin 31) (m : CC.Mem) (k : CC.Cont)
    (value base : BitVec 64)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (.Vlong value, .Vint ((if returns then 10#8 else 4#8).setWidth 32)))
    (cache : WarmEntryCache returns frontier m (.Vptr b ofs) base) :
    InternalRun ge (if returns then 92 else 91)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate (.Vlong (value + base)) (CC.callCont k) m) := by
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells
  simp only [offset_zero] at cellsLoad
  have beforeCall := gpr_read_prefix i b cb vb tb kb ofs co vo to ko m k (.Vlong value)
    (if returns then 10#8 else 4#8) cellsLoad slot
    (field_load frontier b ofs m _ 8 _ layouts.2.2.2.1 tags) tagSlot cell kind rfl
  have entryRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val)
      (if returns then 10#8 else 4#8)).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide [gprReadTemps, readTemps, CC.PTree.gso]
  have valueRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val)
      (if returns then 10#8 else 4#8)).get Arm64Program.___a64_read_value = some (.Vlong value) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  have tagRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val)
      (if returns then 10#8 else 4#8)).get Arm64Program.___a64_read_tag =
      some (.Vint (if returns then 10#32 else 4#32)) := by
    cases returns <;> simp +decide [gprReadTemps, CC.PTree.gso]
  have afterRead := warm_entry_finishes returns frontier b ofs m k _ value base
    entryRead valueRead tagRead cache
  have run := (internalRun_of_steps beforeCall.2 beforeCall.1).trans afterRead
  cases returns <;> exact run

/-- Every represented GPR tag follows the actual combined reader. Relative
payloads must be scalar and the selected cache must already contain its bound
invocation origin. These are producer obligations, not inferred from a tag. -/
theorem gpr_read_materializes (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (relativeScalar : tag = 4 ∨ tag = 10 → value = .Vlong raw)
    (stack : tag = 4 → WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (ret : tag = 10 → WarmEntryCache true frontier m (.Vptr b ofs) origins.returnAddress) :
    ∃ result,
      InternalRun ge (if tag = 4 then 91 else if tag = 10 then 92 else 73)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
        (.Returnstate result (CC.callCont k) m) ∧
      Arm64Registers.ValueRep addresses result
        (Reference.Provenance.AArch64.materialize origins raw tag) := by
  by_cases hs : tag = 4
  · have scalar := relativeScalar (.inl hs)
    subst value
    have run := gpr_read_warm false frontier b ofs i m k raw origins.stack
      (by simpa [hs] using observed) (stack hs)
    refine ⟨.Vlong (raw + origins.stack), ?_, ?_⟩
    · simpa [hs] using run
    · simp [Arm64Registers.ValueRep, Reference.Provenance.AArch64.materialize, hs]
  · by_cases hr : tag = 10
    · have scalar := relativeScalar (.inr hr)
      subst value
      have run := gpr_read_warm true frontier b ofs i m k raw origins.returnAddress
        (by simpa [hr] using observed) (ret hr)
      refine ⟨.Vlong (raw + origins.returnAddress), ?_, ?_⟩
      · simpa [hs, hr] using run
      · simp [Arm64Registers.ValueRep, Reference.Provenance.AArch64.materialize, hs, hr]
    · refine ⟨value, ?_, ?_⟩
      · simpa only [ite_eq_right hs, ite_eq_right hr] using gpr_read_nonrelative addresses frontier b ofs i m k
          value raw tag observed represented hs hr
      · simpa only [Reference.Provenance.AArch64.materialize,
          ite_eq_right hs, ite_eq_right hr] using represented

/-- Every actual Kstop return agrees with M3 materialization for every tag,
under the stated producer/scalar and selected warm-cache bindings. The run
cannot emit a trace or change any memory; no provider outcome is assumed. -/
theorem gpr_read_all_tags_return_corresponds (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (relativeScalar : tag = 4 ∨ tag = 10 → value = .Vlong raw)
    (stack : tag = 4 → WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (ret : tag = 10 → WarmEntryCache true frontier m (.Vptr b ofs) origins.returnAddress)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (returned : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] .Kstop m)
      trace (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ after = m ∧ Arm64Registers.ValueRep addresses result
      (Reference.Provenance.AArch64.materialize origins raw tag) := by
  obtain ⟨expected, run, rep⟩ := gpr_read_materializes addresses origins frontier b ofs i m
    .Kstop value raw tag observed represented relativeScalar stack ret
  obtain ⟨rfl, rfl, rfl⟩ := stopped_return run returned
  exact ⟨rfl, rfl, rep⟩

private def spReadTemps (entry pointer : CC.Val) (offset : BitVec 64) : CC.TempEnv :=
  ((((((((readTemps entry (32#64)).set Arm64Program.___a64_l_reg (.Vlong (32#64))).set
    Arm64Program._t'21 pointer).set Arm64Program._t'22 (.Vlong offset)).set
    Arm64Program._t'1 (.Vlong offset)).set Arm64Program.___a64_read_value (.Vlong offset)).set
    Arm64Program.___a64_l_reg__1 (.Vlong (32#64))).set Arm64Program._t'2 (.Vint (4#32))).set
    Arm64Program.___a64_read_tag (.Vint (4#32))

/-- The actual combined SP reader reaches the same materializer with its
borrowed signed-long offset and constant STACK tag. No GPR tables are read. -/
theorem sp_read_prefix_bound (world : CC.CGenv) (layout : StackLayout world) (b sb : CC.Block) (ofs so : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 40))) = some (.Vptr sb so))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr sb so) = some (.Vlong offset)) :
    steps world 35 (.Callstate (.Internal readHandler) [.Vptr b ofs, .Vlong (32#64)] k m) =
      some (CC.E0, .State readHandler readParts.materialize (readCont k) CC.emptyEnv
        (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset) m) ∧
    InternalPath world 35 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (32#64)] k m) := by
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header
  simp +decide [steps, InternalPath, InternalState, step_read_bound, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    readTemps, spReadTemps, CC.PTree.gso, CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc,
    CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode, layout.entry, layout.sp,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.emptyEnv, CC.E0, CC.Eapp, header, cell]

theorem sp_read_prefix (b sb : CC.Block) (ofs so : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (offset : BitVec 64)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 40))) = some (.Vptr sb so))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr sb so) = some (.Vlong offset)) :
    steps ge 35 (.Callstate (.Internal readHandler) [.Vptr b ofs, .Vlong (32#64)] k m) =
      some (CC.E0, .State readHandler readParts.materialize (readCont k) CC.emptyEnv
        (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset) m) ∧
    InternalPath ge 35 (.Callstate (.Internal readHandler)
      [.Vptr b ofs, .Vlong (32#64)] k m) :=
  sp_read_prefix_bound ge program_stack_layout b sb ofs so m k offset header cell

/-- The same actual warm SP reader in a linked world, using only its four
required layout facts. No helper call, external outcome or memory change. -/
theorem sp_read_warm_bound (world : CC.CGenv) (layout : StackLayout world)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (offset base : BitVec 64)
    (observed : Arm64EntryMemory.borrowed frontier .Mint64 m (.Vptr b ofs) Arm64Program._sp =
      some (.Vlong offset))
    (cache : WarmEntryCache false frontier m (.Vptr b ofs) base) :
    InternalRun world 71 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [.Vptr b ofs, .Vlong (32#64)] k m)
      (.Returnstate (.Vlong (offset + base)) (CC.callCont k) m) := by
  obtain ⟨sb, so, header, cell⟩ := borrowed_loads observed
  have beforeCall := sp_read_prefix_bound world layout b sb ofs so m k offset
    (field_load frontier b ofs m _ 40 _ sp_offset header) cell
  have entryRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide [spReadTemps, readTemps, CC.PTree.gso]
  have valueRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program.___a64_read_value = some (.Vlong offset) := by
    simp +decide [spReadTemps, CC.PTree.gso]
  have tagRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program.___a64_read_tag = some (.Vint (4#32)) := by
    simp +decide [spReadTemps, CC.PTree.gso]
  obtain ⟨valid, nonzero, validObserved, baseObserved⟩ := cache
  obtain ⟨vb, vo, validHeader, validRead⟩ := borrowed_loads validObserved
  obtain ⟨bb, bo, baseHeader, baseRead⟩ := borrowed_loads baseObserved
  have offsets := cache_offsets false
  have finish := read_warm_tail_stack_bound world layout b vb bb ofs vo bo m k _ offset base valid nonzero
    entryRead valueRead tagRead
    (field_load frontier b ofs m _ _ _ offsets.1 validHeader) validRead
    (field_load frontier b ofs m _ _ _ offsets.2 baseHeader) baseRead
  exact (internalRun_of_steps beforeCall.2 beforeCall.1).trans (internalRun_of_steps finish.2 finish.1)

/-- SP materialization reads the actual offset and selected warm STACK cache,
returning their wrapped sum while preserving the complete memory. -/
theorem sp_read_warm (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (offset base : BitVec 64)
    (observed : Arm64EntryMemory.borrowed frontier .Mint64 m (.Vptr b ofs) Arm64Program._sp =
      some (.Vlong offset))
    (cache : WarmEntryCache false frontier m (.Vptr b ofs) base) :
    InternalRun ge 71 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [.Vptr b ofs, .Vlong (32#64)] k m)
      (.Returnstate (.Vlong (offset + base)) (CC.callCont k) m) :=
  sp_read_warm_bound ge program_stack_layout frontier b ofs m k offset base observed cache

/-- Every actual Kstop SP read returns the native SP from the concrete register
relation, under an explicit warm invocation stack-origin binding. -/
theorem sp_read_return_corresponds (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (native : Reference.AArch64.State)
    (rep : Arm64Registers.Represents addresses origins cells frontier m (.Vptr b ofs) native)
    (cache : WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (trace : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (returned : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (32#64)] .Kstop m)
      trace (.Returnstate result .Kstop after)) :
    trace = CC.E0 ∧ after = m ∧ result = .Vlong (Reference.AArch64.sp native) := by
  obtain ⟨offset, observed, bits⟩ := rep.sp
  have run := sp_read_warm frontier b ofs m .Kstop offset origins.stack observed cache
  obtain ⟨rfl, rfl, rfl⟩ := stopped_return run returned
  exact ⟨rfl, rfl, congrArg CC.Val.Vlong bits.symm⟩

private def inputBefore := Arm64Program.global_definitions.take 63
private def inputAfter := Arm64Program.global_definitions.drop 64
private def inputGlobal : CC.Ident × CC.GlobDef CC.FunDef CC.Ty :=
  (Arm64Program._native_lab_entry_input, .Gfun Arm64OriginCache.inputFunction)
private def inputBeforeEnv : CC.Genv CC.FunDef CC.Ty :=
  CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public) inputBefore

/-- Bind the actual Program export's native/host input symbol and full type.
The stock BPF mutable-map provider remains a distinct ABI. -/
theorem program_input_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._native_lab_entry_input =
      some (CC.Positive.ofNat 64) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 64) =
      some Arm64OriginCache.inputFunction := by
  have globals : Arm64Program.global_definitions = inputBefore ++ inputGlobal :: inputAfter := rfl
  have next : inputBeforeEnv.genv_next = CC.Positive.ofNat 64 := rfl
  have environment : ge.genv_genv =
      CC.Genv.addGlobals (CC.Genv.addGlobal inputBeforeEnv inputGlobal) inputAfter := by
    change CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public)
      Arm64Program.global_definitions = _
    rw [globals, addGlobals_append]
    exact addGlobals_cons _ _ _
  constructor
  · decide +kernel
  · rw [environment, ← next]
    exact findFunctPtr_next inputBeforeEnv _ Arm64OriginCache.inputFunction inputAfter

private def sequenceParts : CC.Stmt → Option (CC.Stmt × CC.Stmt)
  | .Ssequence a b => some (a, b)
  | _ => none
private def loopParts : CC.Stmt → Option (CC.Stmt × CC.Stmt)
  | .Sloop a b => some (a, b)
  | _ => none
private def branchParts : CC.Stmt → Option (CC.Stmt × CC.Stmt)
  | .Sifthenelse _ a b => some (a, b)
  | _ => none

private structure CacheColdParts where
  materializeBody : CC.Stmt
  cacheBody : CC.Stmt
  storeBase : CC.Stmt
  storeValid : CC.Stmt
  readBase : CC.Stmt
  add : CC.Stmt
  result : CC.Stmt

private def unpackColdParts (returns : Bool) : Option CacheColdParts := do
  let (body, _) ← loopParts readParts.materialize
  let (_, rest) ← sequenceParts body
  let (_, rest) ← sequenceParts rest
  let (branch, result) ← sequenceParts rest
  let (stack, rest) ← branchParts branch
  let selected ← if returns then do
    let (ret, _) ← branchParts rest
    pure ret
  else pure stack
  let (loop, add) ← sequenceParts selected
  let (cacheBody, _) ← loopParts loop
  let (guard, readBase) ← sequenceParts cacheBody
  let (_, guardRest) ← sequenceParts guard
  let (_, check) ← sequenceParts guardRest
  let (cold, _) ← branchParts check
  let (callBase, storeValid) ← sequenceParts cold
  let (_, storeBase) ← sequenceParts callBase
  pure ⟨body, cacheBody, storeBase, storeValid, readBase, add, result⟩

private def stackColdParts : CacheColdParts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `((unpackColdParts false).get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `stack_cold_parts value

private def stackColdTemps (le : CC.TempEnv) (value : BitVec 64) (valid : CC.Val) : CC.TempEnv :=
  (((le.set Arm64Program.___a64_mat_value (.Vlong value)).set
    Arm64Program.___a64_mat_tag (.Vint (4#32))).set Arm64Program._t'11 valid).set
    Arm64Program._t'12 (.Vint (0#32))

private def stackInputContinuation (le : CC.TempEnv) (value : BitVec 64)
    (valid : CC.Val) (k : CC.Cont) : CC.Cont :=
  let p := stackColdParts
  .Kcall (some Arm64Program._t'3) readHandler CC.emptyEnv (stackColdTemps le value valid)
    (.Kseq p.storeBase (.Kseq p.storeValid (.Kseq p.readBase
      (.Kloop1 p.cacheBody .Sbreak (.Kseq p.add (.Kseq p.result
        (.Kloop1 p.materializeBody .Sbreak (readCont k))))))))

private def returnColdParts : CacheColdParts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `((unpackColdParts true).get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `return_cold_parts value

private def returnColdTemps (le : CC.TempEnv) (value : BitVec 64) (valid : CC.Val) : CC.TempEnv :=
  (((le.set Arm64Program.___a64_mat_value (.Vlong value)).set
    Arm64Program.___a64_mat_tag (.Vint (10#32))).set Arm64Program._t'6 valid).set
    Arm64Program._t'7 (.Vint (0#32))

private def returnInputContinuation (le : CC.TempEnv) (value : BitVec 64)
    (valid : CC.Val) (k : CC.Cont) : CC.Cont :=
  let p := returnColdParts
  .Kcall (some Arm64Program._t'4) readHandler CC.emptyEnv (returnColdTemps le value valid)
    (.Kseq p.storeBase (.Kseq p.storeValid (.Kseq p.readBase
      (.Kloop1 p.cacheBody .Sbreak (.Kseq p.add (.Kseq p.result
        (.Kloop1 p.materializeBody .Sbreak (readCont k))))))))

/-- The cold STACK branch reaches the actual native-input external boundary.
It retains the exact pending stores and both enclosing loops. -/
theorem stack_read_cold_prefix_bound (world : CC.CGenv) (layout : StackLayout world) (inputBlock : CC.Block)
    (input : CC.Genv.findSymbol world.genv_genv Arm64Program._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction) (b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (4#32)))
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (0#32))) :
    steps world 22 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (1#32)]
        (stackInputContinuation le value (.Vptr vb vo) k) m) ∧
    InternalPath world 22 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header
  simp +decide [steps, InternalPath, InternalState, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    CC.doStep, Arm64Program.s_kprog_arm64_program_read_0,
    CC.doEvalExpr, CC.doEvalLvalue, CC.doEvalExprlist, CC.lvalOfField, CC.lvalOfVar,
    CC.doDerefLoc, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
    layout.entry, layout.valid, CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
    input.1, input.2, CC.Genv.findFunct, CC.typeOfFundef,
    Arm64OriginCache.inputFunction, Arm64OriginCache.inputEF, CC.Cop.classifyFun,
    CC.PTree.gso, CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tuchar, CC.tint, CC.tuint, CC.tulong,
    CC.emptyEnv, CC.E0, CC.Eapp, entryRead, valueRead, tagRead, header, cold,
    stackInputContinuation, stackColdTemps, stackColdParts]

theorem stack_read_cold_prefix (b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (4#32)))
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (0#32))) :
    steps ge 22 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (1#32)]
        (stackInputContinuation le value (.Vptr vb vo) k) m) ∧
    InternalPath ge 22 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) :=
  stack_read_cold_prefix_bound ge program_stack_layout (CC.Positive.ofNat 64) program_input_binding b vb ofs vo m k le value entryRead valueRead tagRead header cold

private theorem field_store_distinct (frontier b wb : CC.Block) (ofs : CC.Integers.Ptrofs)
    (name : CC.Ident) (delta : CC.Z) (chunk : CC.Chunk) (wo : CC.Z)
    (before after : CC.Mem) (value : CC.Val)
    (offset : CC.fieldOffset ge.genv_cenv name entryComposite.co_members = .OK (delta, .Full))
    (distinct : b ≠ wb) (stored : CC.Mem.store chunk before wb wo value = some after) :
    Arm64EntryMemory.field frontier CC.Mptr after (.Vptr b ofs) name =
      Arm64EntryMemory.field frontier CC.Mptr before (.Vptr b ofs) name := by
  have binding : Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry =
      some entryComposite := layouts.1
  change CC.fieldOffset Arm64EntryMemory.composites name entryComposite.co_members = _ at offset
  simp only [Arm64EntryMemory.field, Arm64EntryMemory.fieldAddress, binding,
    offset, CC.Val.offsetPtr, bind, pure, Option.bind_some, Arm64EntryMemory.load]
  split
  · exact CC.Mem.load_store_other stored CC.Mptr b _ (.inl distinct)
  · rfl

private theorem borrowed_of_load (frontier block : CC.Block) (offset : CC.Integers.Ptrofs)
    (chunk : CC.Chunk) (m : CC.Mem) (entry value : CC.Val) (name : CC.Ident)
    (header : Arm64EntryMemory.field frontier CC.Mptr m entry name = some (.Vptr block offset))
    (owned : block.toNat < frontier.toNat)
    (read : CC.Mem.loadv chunk m (.Vptr block offset) = some value) :
    Arm64EntryMemory.borrowed frontier chunk m entry name = some value := by
  simpa only [Arm64EntryMemory.borrowed, header, bind, Option.bind_some,
    Arm64EntryMemory.load, if_pos owned, CC.Mem.loadv] using read

/-- Construct the actual selected borrowed cache stores. The cells may share a
block when their byte ranges are disjoint; the entry has a distinct block so
its pointer fields survive. These are explicit storage/producer bindings. -/
theorem entry_cache_stores (returns : Bool) (frontier b vb bb : CC.Block) (ofs vo bo : CC.Integers.Ptrofs)
    (m : CC.Mem) (base : BitVec 64)
    (validHeader : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs)
      (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) = some (.Vptr vb vo))
    (baseHeader : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs)
      (if returns then Arm64Program._return_base else Arm64Program._sp_base) = some (.Vptr bb bo))
    (validOwned : vb.toNat < frontier.toNat) (baseOwned : bb.toNat < frontier.toNat)
    (entryValid : b ≠ vb) (entryBase : b ≠ bb)
    (separate : bb ≠ vb ∨ CC.Integers.Ptrofs.unsigned bo + 8 ≤ CC.Integers.Ptrofs.unsigned vo ∨
      CC.Integers.Ptrofs.unsigned vo + 1 ≤ CC.Integers.Ptrofs.unsigned bo)
    (baseWritable : CC.Mem.validAccess m .Mint64 bb (CC.Integers.Ptrofs.unsigned bo) .Writable = true)
    (validWritable : CC.Mem.validAccess m .Mint8unsigned vb (CC.Integers.Ptrofs.unsigned vo)
      .Writable = true) :
    ∃ middle after,
      CC.Mem.storev .Mint64 m (.Vptr bb bo) (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr vb vo) (.Vint (1#32)) = some after ∧
      WarmEntryCache returns frontier after (.Vptr b ofs) base ∧
      Arm64EntryMemory.field frontier CC.Mptr middle (.Vptr b ofs) (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) =
        some (.Vptr vb vo) ∧
      Arm64EntryMemory.field frontier CC.Mptr after (.Vptr b ofs) (if returns then Arm64Program._return_base else Arm64Program._sp_base) =
        some (.Vptr bb bo) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have create : ∀ (chunk : CC.Chunk) (memory : CC.Mem) block offset value,
      CC.Mem.validAccess memory chunk block offset .Writable = true →
      ∃ after, CC.Mem.store chunk memory block offset value = some after := by
    intro chunk memory block offset value writable
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨middle, storeBase⟩ := create .Mint64 m bb _ (.Vlong base) baseWritable
  have validMiddle := (CC.Mem.validAccess_store_eq storeBase .Mint8unsigned vb _ .Writable).trans
    validWritable
  obtain ⟨after, storeValid⟩ := create .Mint8unsigned middle vb _ (.Vint (1#32)) validMiddle
  have offsets := cache_offsets returns
  have fieldFrame := field_store_distinct frontier b bb ofs _ (if returns then 56 else 48) .Mint64 _ m middle
    (.Vlong base) offsets.1 entryBase storeBase
  have validMiddleHeader := fieldFrame.trans validHeader
  have validAfterHeader := (field_store_distinct frontier b vb ofs _ (if returns then 56 else 48) .Mint8unsigned _
    middle after (.Vint (1#32)) offsets.1 entryValid storeValid).trans validMiddleHeader
  have baseMiddleHeader := (field_store_distinct frontier b bb ofs _ (if returns then 24 else 16) .Mint64 _ m middle
    (.Vlong base) offsets.2 entryBase storeBase).trans baseHeader
  have baseAfterHeader := (field_store_distinct frontier b vb ofs _ (if returns then 24 else 16) .Mint8unsigned _
    middle after (.Vint (1#32)) offsets.2 entryValid storeValid).trans baseMiddleHeader
  have validRead : CC.Mem.loadv .Mint8unsigned after (.Vptr vb vo) = some (.Vint (1#32)) := by
    simpa [CC.Mem.loadv, CC.Val.loadResult, CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext] using CC.Mem.load_store_same storeValid
  have baseRead : CC.Mem.loadv .Mint64 after (.Vptr bb bo) = some (.Vlong base) := by
    have same := CC.Mem.load_store_other storeValid .Mint64 bb (CC.Integers.Ptrofs.unsigned bo)
      (by simpa only [CC.sizeChunk] using separate)
    simpa only [CC.Mem.loadv, CC.Val.loadResult] using
      same.trans (CC.Mem.load_store_same storeBase)
  refine ⟨middle, after, storeBase, storeValid, ?_, validMiddleHeader, baseAfterHeader,
    (CC.Mem.store_access storeValid).trans (CC.Mem.store_access storeBase),
    (CC.Mem.store_nextblock storeValid).trans (CC.Mem.store_nextblock storeBase)⟩
  refine ⟨1#8, by decide, ?_, ?_⟩
  · exact borrowed_of_load frontier vb vo .Mint8unsigned after _ _ _ validAfterHeader validOwned validRead
  · exact borrowed_of_load frontier bb bo .Mint64 after _ _ _ baseAfterHeader baseOwned baseRead

private theorem stack_read_cold_suffix_bound (world : CC.CGenv) (layout : StackLayout world) (b vb bb : CC.Block) (ofs vo bo : CC.Integers.Ptrofs)
    (supplied middle after : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (oldValid : CC.Val)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (baseHeader : CC.Mem.loadv CC.Mptr supplied (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 16))) = some (.Vptr bb bo))
    (validHeader : CC.Mem.loadv CC.Mptr middle (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (baseHeaderAfter : CC.Mem.loadv CC.Mptr after (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 16))) = some (.Vptr bb bo))
    (storeBase : CC.Mem.storev .Mint64 supplied (.Vptr bb bo) (.Vlong base) = some middle)
    (storeValid : CC.Mem.storev .Mint8unsigned middle (.Vptr vb vo) (.Vint (1#32)) = some after)
    (readBase : CC.Mem.loadv .Mint64 after (.Vptr bb bo) = some (.Vlong base)) :
    steps world 28 (.Returnstate (.Vlong base) (stackInputContinuation le value oldValid k) supplied) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
    InternalPath world 28
      (.Returnstate (.Vlong base) (stackInputContinuation le value oldValid k) supplied) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at baseHeader validHeader baseHeaderAfter
  simp +decide [steps, InternalPath, InternalState, CC.doStep, read_return_type,
    stackInputContinuation, stackColdTemps, stackColdParts, readParts, readCont,
    CC.setOpttemp, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc,
    CC.doAssignLoc, CC.lvalOfField, CC.typeof, CC.accessMode, layout.entry, layout.valid, layout.base,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Int64.add, CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tuchar, CC.tint, CC.tulong,
    CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty,
    entryRead, baseHeader, validHeader, baseHeaderAfter, storeBase, storeValid, readBase] <;> rfl

/-- Actual post-provider storage binding for one selected borrowed cache.
The entry is separate from the writable cells, whose ranges are disjoint.
A provider may change their addresses; no pre/post provider purity is assumed. -/
structure BorrowedCacheStorage (returns : Bool) (frontier b : CC.Block)
    (ofs : CC.Integers.Ptrofs) (m : CC.Mem) where
  validBlock : CC.Block
  baseBlock : CC.Block
  validOffset : CC.Integers.Ptrofs
  baseOffset : CC.Integers.Ptrofs
  validHeader : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs)
    (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) =
      some (.Vptr validBlock validOffset)
  baseHeader : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs)
    (if returns then Arm64Program._return_base else Arm64Program._sp_base) =
      some (.Vptr baseBlock baseOffset)
  validOwned : validBlock.toNat < frontier.toNat
  baseOwned : baseBlock.toNat < frontier.toNat
  entryValid : b ≠ validBlock
  entryBase : b ≠ baseBlock
  separate : baseBlock ≠ validBlock ∨
    CC.Integers.Ptrofs.unsigned baseOffset + 8 ≤ CC.Integers.Ptrofs.unsigned validOffset ∨
    CC.Integers.Ptrofs.unsigned validOffset + 1 ≤ CC.Integers.Ptrofs.unsigned baseOffset
  baseWritable : CC.Mem.validAccess m .Mint64 baseBlock (CC.Integers.Ptrofs.unsigned baseOffset)
    .Writable = true
  validWritable : CC.Mem.validAccess m .Mint8unsigned validBlock
    (CC.Integers.Ptrofs.unsigned validOffset) .Writable = true

/-- The full cold STACK materializer follows the actual external outcome,
constructs both stores from writable storage, and preserves its trace and
post-memory except for those stores. Establishing the storage/native-origin
binding from the real producer remains a separate obligation. -/
theorem stack_materialize_cold_bound (world : CC.CGenv) (layout : StackLayout world) (inputBlock : CC.Block)
    (input : CC.Genv.findSymbol world.genv_genv Arm64Program._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction) (frontier b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (trace : CC.Trace)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (4#32)))
    (header : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned before (.Vptr vb vo) = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (1#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 world)
        (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le before) trace
        (.Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨middle, after, storeBase, storeValid, warm, validHeader, baseHeader,
      permissions, allocations⟩ := entry_cache_stores false frontier b storage.validBlock
    storage.baseBlock ofs storage.validOffset storage.baseOffset supplied base
    storage.validHeader storage.baseHeader storage.validOwned storage.baseOwned storage.entryValid
    storage.entryBase storage.separate storage.baseWritable storage.validWritable
  have offsets := cache_offsets false
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  have beforeCall := stack_read_cold_prefix_bound world layout inputBlock input b vb ofs vo before k le value
    entryRead valueRead tagRead header cold
  have readBack := (borrowed_loads warm.choose_spec.2.2)
  obtain ⟨block, offset, baseHeader', baseRead⟩ := readBack
  rw [baseHeader] at baseHeader'
  cases baseHeader'
  have suffix := stack_read_cold_suffix_bound world layout b storage.validBlock storage.baseBlock ofs
    storage.validOffset storage.baseOffset supplied middle after k le value base (.Vptr vb vo)
    entryRead (field_load frontier b ofs supplied _ 16 _ offsets.2 storage.baseHeader)
    (field_load frontier b ofs middle _ 48 _ offsets.1 validHeader)
    (field_load frontier b ofs after _ 16 _ offsets.2 baseHeader) storeBase storeValid baseRead
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (1#32)]
        (stackInputContinuation le value (.Vptr vb vo) k) before)
      trace (.Returnstate (.Vlong base) (stackInputContinuation le value (.Vptr vb vo) k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.Eapp, CC.E0])
  refine ⟨middle, after, ?_, storeBase, storeValid, warm, permissions, allocations⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans (internalRun_of_steps beforeCall.2 beforeCall.1).sound call)
      (internalRun_of_steps suffix.2 suffix.1).sound

theorem stack_materialize_cold (frontier b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (trace : CC.Trace)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (4#32)))
    (header : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 48))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned before (.Vptr vb vo) = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (1#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le before) trace
        (.Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock :=
  stack_materialize_cold_bound ge program_stack_layout (CC.Positive.ofNat 64) program_input_binding frontier b vb ofs vo before supplied k le value base trace entryRead valueRead tagRead header cold provider storage

/-- The complete actual GPR reader's cold STACK path, for every actual
provider outcome admitted by the imported external relation. The only memory
changes after that outcome are the two constructed cache stores. -/
theorem gpr_read_stack_cold (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (before supplied : CC.Mem) (k : CC.Cont) (value base : BitVec 64) (trace : CC.Trace)
    (observed : Arm64EntryMemory.gpr frontier before (.Vptr b ofs) i.val =
      some (.Vlong value, .Vint (4#32)))
    (cold : Arm64EntryMemory.borrowed frontier .Mint8unsigned before (.Vptr b ofs)
      Arm64Program._sp_valid = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (1#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k before) trace
        (.Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load frontier b ofs before _ 0 _ layouts.2.2.1 cells
  simp only [offset_zero] at cellsLoad
  have beforeCall := gpr_read_prefix i b cb vb tb kb ofs co vo to ko before k (.Vlong value)
    (4#8) cellsLoad slot (field_load frontier b ofs before _ 8 _ layouts.2.2.2.1 tags)
    tagSlot cell kind rfl
  have entryRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (4#8)).get
      Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide [gprReadTemps, readTemps, CC.PTree.gso]
  have valueRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (4#8)).get
      Arm64Program.___a64_read_value = some (.Vlong value) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  have tagRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (4#8)).get
      Arm64Program.___a64_read_tag = some (.Vint (4#32)) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  obtain ⟨validBlock, validOffset, validHeader, validRead⟩ := borrowed_loads cold
  have offsets := cache_offsets false
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  obtain ⟨middle, after, run, facts⟩ := stack_materialize_cold frontier b validBlock ofs validOffset
    before supplied k _ value base trace entryRead valueRead tagRead
    (field_load frontier b ofs before _ 48 _ offsets.1 validHeader) validRead provider storage
  refine ⟨middle, after, ?_, facts⟩
  simpa only [readHandler, CC.E0, CC.Eapp, List.nil_append] using
    star_trans (internalRun_of_steps beforeCall.2 beforeCall.1).sound run

/-- The complete actual SP reader follows the same cold STACK provider and
cache stores. Its offset is read before the provider, not from its post-memory. -/
theorem sp_read_cold_bound (world : CC.CGenv) (layout : StackLayout world) (inputBlock : CC.Block)
    (input : CC.Genv.findSymbol world.genv_genv Arm64Program._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction) (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (offset base : BitVec 64) (trace : CC.Trace)
    (observed : Arm64EntryMemory.borrowed frontier .Mint64 before (.Vptr b ofs)
      Arm64Program._sp = some (.Vlong offset))
    (cold : Arm64EntryMemory.borrowed frontier .Mint8unsigned before (.Vptr b ofs)
      Arm64Program._sp_valid = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (1#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr b ofs, .Vlong (32#64)] k before) trace
        (.Returnstate (.Vlong (offset + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨sb, so, header, cell⟩ := borrowed_loads observed
  have beforeCall := sp_read_prefix_bound world layout b sb ofs so before k offset
    (field_load frontier b ofs before _ 40 _ sp_offset header) cell
  have entryRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide [spReadTemps, readTemps, CC.PTree.gso]
  have valueRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program.___a64_read_value = some (.Vlong offset) := by
    simp +decide [spReadTemps, CC.PTree.gso]
  have tagRead : (spReadTemps (.Vptr b ofs) (.Vptr sb so) offset).get
      Arm64Program.___a64_read_tag = some (.Vint (4#32)) := by
    simp +decide [spReadTemps, CC.PTree.gso]
  obtain ⟨validBlock, validOffset, validHeader, validRead⟩ := borrowed_loads cold
  have offsets := cache_offsets false
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  obtain ⟨middle, after, run, facts⟩ := stack_materialize_cold_bound world layout inputBlock input frontier b validBlock ofs validOffset
    before supplied k _ offset base trace entryRead valueRead tagRead
    (field_load frontier b ofs before _ 48 _ offsets.1 validHeader) validRead provider storage
  refine ⟨middle, after, ?_, facts⟩
  simpa only [readHandler, CC.E0, CC.Eapp, List.nil_append] using
    star_trans (internalRun_of_steps beforeCall.2 beforeCall.1).sound run

theorem sp_read_cold (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (offset base : BitVec 64) (trace : CC.Trace)
    (observed : Arm64EntryMemory.borrowed frontier .Mint64 before (.Vptr b ofs)
      Arm64Program._sp = some (.Vlong offset))
    (cold : Arm64EntryMemory.borrowed frontier .Mint8unsigned before (.Vptr b ofs)
      Arm64Program._sp_valid = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (1#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr b ofs, .Vlong (32#64)] k before) trace
        (.Returnstate (.Vlong (offset + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock :=
  sp_read_cold_bound ge program_stack_layout (CC.Positive.ofNat 64) program_input_binding frontier b ofs before supplied k offset base trace observed cold provider storage

/-- The cold RETURN branch reaches the actual native-input external boundary.
It retains the exact pending stores and both enclosing loops. -/
theorem return_read_cold_prefix (b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (10#32)))
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 56))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned m (.Vptr vb vo) = some (.Vint (0#32))) :
    steps ge 23 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
        (returnInputContinuation le value (.Vptr vb vo) k) m) ∧
    InternalPath ge 23 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
  have offsets := cache_offsets true
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at header
  simp +decide [steps, InternalPath, InternalState, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    CC.doStep, Arm64Program.s_kprog_arm64_program_read_1, Arm64Program.s_kprog_arm64_program_read_2,
    CC.doEvalExpr, CC.doEvalLvalue, CC.doEvalExprlist, CC.lvalOfField, CC.lvalOfVar,
    CC.doDerefLoc, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
    layouts.1, offsets.1, CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
    program_input_binding.1, program_input_binding.2, CC.Genv.findFunct, CC.typeOfFundef,
    Arm64OriginCache.inputFunction, Arm64OriginCache.inputEF, CC.Cop.classifyFun,
    CC.PTree.gso, CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tuchar, CC.tint, CC.tuint, CC.tulong,
    CC.emptyEnv, CC.E0, CC.Eapp, entryRead, valueRead, tagRead, header, cold,
    returnInputContinuation, returnColdTemps, returnColdParts]

private theorem return_read_cold_suffix (b vb bb : CC.Block) (ofs vo bo : CC.Integers.Ptrofs)
    (supplied middle after : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (oldValid : CC.Val)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (baseHeader : CC.Mem.loadv CC.Mptr supplied (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 24))) = some (.Vptr bb bo))
    (validHeader : CC.Mem.loadv CC.Mptr middle (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 56))) = some (.Vptr vb vo))
    (baseHeaderAfter : CC.Mem.loadv CC.Mptr after (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 24))) = some (.Vptr bb bo))
    (storeBase : CC.Mem.storev .Mint64 supplied (.Vptr bb bo) (.Vlong base) = some middle)
    (storeValid : CC.Mem.storev .Mint8unsigned middle (.Vptr vb vo) (.Vint (1#32)) = some after)
    (readBase : CC.Mem.loadv .Mint64 after (.Vptr bb bo) = some (.Vlong base)) :
    steps ge 28 (.Returnstate (.Vlong base) (returnInputContinuation le value oldValid k) supplied) =
      some (CC.E0, .Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
    InternalPath ge 28
      (.Returnstate (.Vlong base) (returnInputContinuation le value oldValid k) supplied) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have offsets := cache_offsets true
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at baseHeader validHeader baseHeaderAfter
  simp +decide [steps, InternalPath, InternalState, CC.doStep, read_return_type,
    returnInputContinuation, returnColdTemps, returnColdParts, Arm64Program.s_kprog_arm64_program_read_2, readParts, readCont,
    CC.setOpttemp, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc,
    CC.doAssignLoc, CC.lvalOfField, CC.typeof, CC.accessMode, layouts.1, offsets.1, offsets.2,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Int64.add, CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.tuchar, CC.tint, CC.tulong,
    CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty,
    entryRead, baseHeader, validHeader, baseHeaderAfter, storeBase, storeValid, readBase] <;> rfl

/-- The full cold RETURN materializer follows the actual external outcome,
constructs both stores from writable storage, and preserves its trace and
post-memory except for those stores. Establishing the storage/native-origin
binding from the real producer remains a separate obligation. -/
theorem return_materialize_cold (frontier b vb : CC.Block) (ofs vo : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value base : BitVec 64) (trace : CC.Trace)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (10#32)))
    (header : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 56))) = some (.Vptr vb vo))
    (cold : CC.Mem.loadv .Mint8unsigned before (.Vptr vb vo) = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (3#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage true frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le before) trace
        (.Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache true frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨middle, after, storeBase, storeValid, warm, validHeader, baseHeader,
      permissions, allocations⟩ := entry_cache_stores true frontier b storage.validBlock
    storage.baseBlock ofs storage.validOffset storage.baseOffset supplied base
    storage.validHeader storage.baseHeader storage.validOwned storage.baseOwned storage.entryValid
    storage.entryBase storage.separate storage.baseWritable storage.validWritable
  have offsets := cache_offsets true
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  have beforeCall := return_read_cold_prefix b vb ofs vo before k le value
    entryRead valueRead tagRead header cold
  have readBack := (borrowed_loads warm.choose_spec.2.2)
  obtain ⟨block, offset, baseHeader', baseRead⟩ := readBack
  rw [baseHeader] at baseHeader'
  cases baseHeader'
  have suffix := return_read_cold_suffix b storage.validBlock storage.baseBlock ofs
    storage.validOffset storage.baseOffset supplied middle after k le value base (.Vptr vb vo)
    entryRead (field_load frontier b ofs supplied _ 24 _ offsets.2 storage.baseHeader)
    (field_load frontier b ofs middle _ 56 _ offsets.1 validHeader)
    (field_load frontier b ofs after _ 24 _ offsets.2 baseHeader) storeBase storeValid baseRead
  have call : CC.Star (CC.Step2 ge)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
        (returnInputContinuation le value (.Vptr vb vo) k) before)
      trace (.Returnstate (.Vlong base) (returnInputContinuation le value (.Vptr vb vo) k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.Eapp, CC.E0])
  refine ⟨middle, after, ?_, storeBase, storeValid, warm, permissions, allocations⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans (internalRun_of_steps beforeCall.2 beforeCall.1).sound call)
      (internalRun_of_steps suffix.2 suffix.1).sound

/-- The complete actual GPR reader's cold RETURN path, for every actual
provider outcome admitted by the imported external relation. The only memory
changes after that outcome are the two constructed cache stores. -/
theorem gpr_read_return_cold (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (before supplied : CC.Mem) (k : CC.Cont) (value base : BitVec 64) (trace : CC.Trace)
    (observed : Arm64EntryMemory.gpr frontier before (.Vptr b ofs) i.val =
      some (.Vlong value, .Vint (10#32)))
    (cold : Arm64EntryMemory.borrowed frontier .Mint8unsigned before (.Vptr b ofs)
      Arm64Program._return_valid = some (.Vint (0#32)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (3#32)] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage true frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k before) trace
        (.Returnstate (.Vlong (value + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset)
        (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset)
        (.Vint (1#32)) = some after ∧
      WarmEntryCache true frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load frontier b ofs before _ 0 _ layouts.2.2.1 cells
  simp only [offset_zero] at cellsLoad
  have beforeCall := gpr_read_prefix i b cb vb tb kb ofs co vo to ko before k (.Vlong value)
    (10#8) cellsLoad slot (field_load frontier b ofs before _ 8 _ layouts.2.2.2.1 tags)
    tagSlot cell kind rfl
  have entryRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (10#8)).get
      Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide [gprReadTemps, readTemps, CC.PTree.gso]
  have valueRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (10#8)).get
      Arm64Program.___a64_read_value = some (.Vlong value) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  have tagRead : (gprReadTemps (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
      (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) (10#8)).get
      Arm64Program.___a64_read_tag = some (.Vint (10#32)) := by
    simp +decide [gprReadTemps, CC.PTree.gso]
  obtain ⟨validBlock, validOffset, validHeader, validRead⟩ := borrowed_loads cold
  have offsets := cache_offsets true
  simp only [Bool.false_eq_true, ↓reduceIte] at offsets
  obtain ⟨middle, after, run, facts⟩ := return_materialize_cold frontier b validBlock ofs validOffset
    before supplied k _ value base trace entryRead valueRead tagRead
    (field_load frontier b ofs before _ 56 _ offsets.1 validHeader) validRead provider storage
  refine ⟨middle, after, ?_, facts⟩
  simpa only [readHandler, CC.E0, CC.Eapp, List.nil_append] using
    star_trans (internalRun_of_steps beforeCall.2 beforeCall.1).sound run

end KProgFormal.ClightRefinement.Arm64RegisterReads
