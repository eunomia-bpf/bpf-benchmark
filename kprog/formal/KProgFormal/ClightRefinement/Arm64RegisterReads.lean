import KProgFormal.ClightRefinement.Arm64Registers

namespace KProgFormal.ClightRefinement.Arm64RegisterReads

def ge : CC.CGenv := Arm64Program.prog.globalenv

def reader (tags : Bool) : CC.Function :=
  if tags then Arm64Program.f_kprog_arm64_program_tag else Arm64Program.f_kprog_arm64_program_raw

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

private theorem gpr_executes (tags : Bool) (i : Fin 31)
    (b cb vb : CC.Block) (ofs co vo : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (value : CC.Val) (tag : BitVec 8)
    (header : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr (if tags then 8 else 0)))) = some (.Vptr cb co))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (cell : CC.Mem.loadv (if tags then .Mint8unsigned else .Mint64) m (.Vptr vb vo) =
      some (if tags then .Vint (tag.setWidth 32) else value))
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps ge 28 (.Callstate (.Internal (reader tags))
      [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k m) =
      some (CC.E0, .Returnstate (if tags then .Vint (tag.setWidth 32) else value)
        (CC.callCont k) m) ∧
    InternalPath ge 28 (.Callstate (.Internal (reader tags))
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
  cases tags <;> simp only [Bool.false_eq_true, ite_false, ite_true, offset_zero] at header cell
  all_goals
    simp +decide [reader, steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      Arm64Program.f_kprog_arm64_program_raw, Arm64Program.f_kprog_arm64_program_tag,
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
      CC.tptr, CC.sizeof, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
      CC.blocksOfEnv, CC.Mem.freeList,
      CC.emptyEnv, CC.E0, CC.Eapp, header, slot, cell, valueCast, empty]

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
  have valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value := by
    cases value <;> try contradiction
    all_goals rfl
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have rawExec := gpr_executes false i b cb vb ofs co vo m k value tag
    (field_load frontier b ofs m _ 0 _ layouts.2.2.1 cells) slot cell valueCast
  have tagExec := gpr_executes true i b tb kb ofs to ko m k value tag
    (field_load frontier b ofs m _ 8 _ layouts.2.2.2.1 tags) tagSlot kind valueCast
  exact ⟨internalRun_of_steps rawExec.2 rawExec.1, internalRun_of_steps tagExec.2 tagExec.1⟩

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

end KProgFormal.ClightRefinement.Arm64RegisterReads
