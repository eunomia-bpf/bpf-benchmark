import KProgFormal.ClightRefinement.StepEquations
import KProgFormal.ClightRefinement.Arm64Registers

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

private theorem read_entry (m : CC.Mem) (entry : CC.Val) (reg : BitVec 64) :
    CC.doFunctionEntry2 ge readHandler [entry, .Vlong reg] m =
      some (CC.emptyEnv, readTemps entry reg, m) := by
  unfold CC.doFunctionEntry2
  rw [ite_eq_left read_names]
  rfl

private theorem step_read (entry : CC.Val) (reg : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep ge (.Callstate (.Internal readHandler) [entry, .Vlong reg] k m) =
      some (CC.E0, .State readHandler
        (.Ssequence (.Sloop readParts.outer .Sbreak) readParts.ret) k CC.emptyEnv
        (readTemps entry reg) m) := by
  simp only [CC.doStep, read_entry]
  rfl

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
  simp +decide [steps, InternalPath, InternalState, step_read, readParts, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    readTemps, gprReadTemps, CC.PTree.gso, CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc,
    CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
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
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, offset_zero, read_tag_mask,
    CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.sizeof, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.emptyEnv, CC.E0, CC.Eapp, cells, cellSlot, tags, tagSlot, cell, kind, valueCast]

private theorem read_return_type : readHandler.fn_return = CC.tulong := rfl

private theorem read_inert_tail (m : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (value : CC.Val) (tag : BitVec 8)
    (valueRead : le.get Arm64Program.___a64_read_value = some value)
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint (tag.setWidth 32)))
    (hs : tag ≠ 4) (hr : tag ≠ 10)
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps ge 18 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) =
      some (CC.E0, .Returnstate value (CC.callCont k) m) ∧
    InternalPath ge 18 (.State readHandler readParts.materialize (readCont k) CC.emptyEnv le m) := by
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
theorem gpr_read_nonrelative (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (notStack : tag ≠ 4) (notReturn : tag ≠ 10) :
    InternalRun ge 73 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m)
      (.Returnstate value (CC.callCont k) m) := by
  have valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value := by
    cases value <;> try contradiction
    all_goals rfl
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells
  simp only [offset_zero] at cellsLoad
  have beforeCall := gpr_read_prefix i b cb vb tb kb ofs co vo to ko m k value tag
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
  have afterRead := read_inert_tail m k _ value tag valueRead tagRead notStack notReturn valueCast
  exact (internalRun_of_steps beforeCall.2 beforeCall.1).trans
    (internalRun_of_steps afterRead.2 afterRead.1)

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

end KProgFormal.ClightRefinement.Arm64RegisterReads
