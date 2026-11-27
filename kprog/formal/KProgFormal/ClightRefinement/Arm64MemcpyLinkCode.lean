import KProgFormal.ClightRefinement.Arm64MemcpyLinkOrdinary
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkNative
import KProgFormal.Reference.Provenance

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkCode
open Arm64MemcpyLinkProgram (ge entry)
open Arm64MemcpyLinkCall (Header slot)
abbrev Native := Arm64ProgramEntryLinkNative.after

/-- Actual captured cil_xdp_entry coordinates;artifact.json and its read-only
ELF/source inspector bind every row to its original CALL26 relocation. -/
private def pcs : Array (BitVec 64) := #[0x54#64, 0x8c#64, 0xa8#64, 0xf4#64, 0x108#64, 0x130#64, 0x148#64, 0x184#64]
private def tokens : Array (BitVec 64) := #[0x58#64, 0x90#64, 0xac#64, 0xf8#64, 0x10c#64, 0x134#64, 0x14c#64, 0x188#64]
private def returns : Array (BitVec 32) := #[0xb4000040#32, 0xb4000040#32, 0xb4000040#32, 0xb50000c0#32, 0xb40000a0#32, 0xb40000e0#32, 0x34000720#32, 0xb4fff6c0#32]

def sourcePC (i : Fin 8) : BitVec 64 := pcs[i.val]'(by exact i.isLt)
def sourceToken (i : Fin 8) : BitVec 64 := tokens[i.val]'(by exact i.isLt)
def returnWord (i : Fin 8) : BitVec 32 := returns[i.val]'(by exact i.isLt)
def objectPC (i : Fin 8) : BitVec 64 := 18128#64+sourcePC i

theorem coordinates : ∀ i : Fin 8,
    sourcePC i+4#64 = sourceToken i ∧
    objectPC i+4#64 = 18128#64+sourceToken i ∧
    (sourceToken i).toNat+4 ≤ 812 := by decide +kernel

/-- Section-relative ELF values and function-local C labels use distinct
origins. The actual loaded text/section placement is supplied by imageBase. -/
def functionOrigin (imageBase : BitVec 64) : BitVec 64 := imageBase+18128#64

theorem object_placement (imageBase : BitVec 64) (i : Fin 8) :
    imageBase+objectPC i = functionOrigin imageBase+sourcePC i ∧
    imageBase+(objectPC i+4#64) = functionOrigin imageBase+sourceToken i := by
  constructor
  · simp only [objectPC,functionOrigin,BitVec.add_assoc]
  · rw [(coordinates i).2.1]
    simp only [functionOrigin,BitVec.add_assoc]

theorem return_decodable : ∀ i : Fin 8, (decode_raw_inst (returnWord i)).isSome = true := by
  decide +kernel

def continuation (i : Fin 8) : Reference.AArch64.Instruction :=
  ⟨returnWord i,(decode_raw_inst (returnWord i)).get (return_decodable i),
    (Option.some_get (return_decodable i)).symm⟩

theorem unrelocated_call :
    decode_raw_inst (0x94000000#32) =
      some (.BR (.Uncond_branch_imm (Arm64ProgramEntryLinkNative.fields (0#26)))) := by
  decide +kernel

/-- Loaded code admission stays explicit. Input P's CALL26 immediate is not
mistaken for the patched branch displacement or a live loader receipt. -/
structure Code (origin : BitVec 64) (i : Fin 8) (s : Reference.AArch64.State) (offset : BitVec 26) where
  call : Reference.AArch64.Instruction
  decoded : call.decoded = .BR (.Uncond_branch_imm (Arm64ProgramEntryLinkNative.fields offset))
  callFetched : fetch_inst (origin+sourcePC i) s.machine = some call.encoding
  returnFetched : fetch_inst (origin+sourceToken i) s.machine = some (returnWord i)

/-- A code-coordinate observation of actual post-free source readbacks and
the actual native LR. CODE9's canonical numeric operation is unchanged. -/
structure Observation {m header offset} (h : Header m header offset)
    (i : Fin 8) (origin : BitVec 64) (source : CC.Mem) (current : Reference.AArch64.State) : Prop where
  sourceLink : CC.Mem.load .Mint64 source h.registers (slot h.registerOffset 240) = some (.Vlong (sourceToken i))
  sourceTag : CC.Mem.load .Mint8unsigned source h.tags (slot h.tagOffset 30) = some (.Vint (9#32))
  nativeLink : Reference.AArch64.gpr current 30 = origin+sourceToken i
  returnCode : fetch_inst (Reference.AArch64.gpr current 30) current.machine = some (returnWord i)

theorem native_control (s : Reference.AArch64.State) (origin : BitVec 64) (i : Fin 8)
    (offset : BitVec 26) (code : Code origin i s offset)
    (pc : read_pc s.machine = origin+sourcePC i) (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨Native s offset,[],none⟩ ∧
    read_pc (Native s offset).machine =
      BR.Uncond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryLinkNative.fields offset) (origin+sourcePC i) ∧
    Reference.AArch64.gpr (Native s offset) 30 = origin+sourceToken i ∧
    fetch_inst (Reference.AArch64.gpr (Native s offset) 30) (Native s offset).machine = some (returnWord i) ∧
    read_err (Native s offset).machine = .None := by
  have fetched : fetch_inst (read_pc s.machine) s.machine = some code.call.encoding := by
    rw [pc]
    exact code.callFetched
  have native := Arm64ProgramEntryLinkNative.reference_step s offset code.call code.decoded noError fetched
  have link : Reference.AArch64.gpr (Native s offset) 30 = origin+sourceToken i := by
    rw [Arm64ProgramEntryLinkNative.link,pc,BitVec.add_assoc,(coordinates i).1]
  have returnCode : fetch_inst (Reference.AArch64.gpr (Native s offset) 30) (Native s offset).machine =
      some (returnWord i) := by
    rw [link]
    have same := (Arm64ProgramEntryLinkNative.resources s offset).2.1
    simpa only [fetch_inst,same] using code.returnFetched
  exact ⟨native,(Arm64ProgramEntryLinkNative.pc s offset).trans (congrArg _ pc),link,returnCode,
    (Arm64ProgramEntryLinkNative.error s offset).trans noError⟩

/-- The old raw-numeric CODE9 comparison is available exactly at zero code
origin. A physical label mapping must remain explicit at other placements. -/
theorem Observation.numeric_iff {m header offset} {h : Header m header offset}
    {i origin source current} (observed : Observation h i origin source current)
    (origins : Reference.Provenance.AArch64.Origins) :
    Reference.AArch64.gpr current 30 =
      Reference.Provenance.AArch64.materialize origins (sourceToken i) (9#8) ↔ origin = 0#64 := by
  rw [observed.nativeLink]
  change origin+sourceToken i = sourceToken i ↔ origin = 0#64
  bv_omega

/-- One actual638-step source LINK and one mature fetched BL share the
captured emitter's continuation coordinate. No numeric source/physical-LR
equality or successful source store/free is assumed. Full caller/alias
composition and actual loaded text/relocation remain their own admission. -/
theorem execute {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (sp : BitVec 64) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 m h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordWritable : CC.Mem.validAccess m .Mint64 h.registers (slot h.registerOffset 240) .Writable = true)
    (tagWritable : CC.Mem.validAccess m .Mint8unsigned h.tags (slot h.tagOffset 30) .Writable = true)
    (separate : h.registers ≠ h.tags)
    (s : Reference.AArch64.State) (origin : BitVec 64) (i : Fin 8) (displacement : BitVec 26)
    (code : Code origin i s displacement) (pc : read_pc s.machine = origin+sourcePC i)
    (noError : read_err s.machine = .None) :
    ∃ (w : Arm64MemcpyLinkOrdinary.Written h (sourceToken i) sp k) (returned after : CC.Mem),
      InternalRun ge 638 (.Callstate (.Internal entry) [.Vptr header offset,.Vlong (sourceToken i)] k m)
        (.Returnstate (.Vlong (sourceToken i)) (CC.callCont k) after) ∧
      CC.Mem.freeList w.after (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkWriter.allocation w.entryMemory).1) = some returned ∧
      CC.Mem.freeList returned (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkSource.allocation m).1) = some after ∧
      FrameBelow w.entryMemory.nextblock w.after returned ∧ FrameBelow m.nextblock returned after ∧
      after.contents = w.after.contents ∧ after.nextblock = w.after.nextblock ∧
      Observation h i origin after (Native s displacement) ∧
      Reference.AArch64.step s = ⟨Native s displacement,[],none⟩ ∧
      read_pc (Native s displacement).machine =
        BR.Uncond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryLinkNative.fields displacement) (origin+sourcePC i) ∧
      read_err (Native s displacement).machine = .None ∧
      (∀ name : StateField, name ≠ .PC → name ≠ .GPR (30#5) →
        r name (Native s displacement).machine = r name s.machine) ∧
      (Native s displacement).machine.mem = s.machine.mem ∧
      (Native s displacement).machine.program = s.machine.program ∧
      (Native s displacement).machine.memoryProfile = s.machine.memoryProfile ∧
      (Native s displacement).machine.memoryAccesses = s.machine.memoryAccesses ∧
      (Native s displacement).machine.atomicAccesses = s.machine.atomicAccesses ∧
      (Native s displacement).machine.exclusive = s.machine.exclusive ∧
      (Native s displacement).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
      (Native s displacement).extraFlags = s.extraFlags ∧
      (∀ b, b.toNat < m.nextblock.toNat → CC.PMap.get b after.access = CC.PMap.get b m.access) ∧
      (∀ b, b.toNat < m.nextblock.toNat → b ≠ h.registers → b ≠ h.tags →
        CC.PMap.get b after.contents = CC.PMap.get b m.contents) := by
  obtain ⟨w,returned,after,sourceRun,innerFree,outerFree,innerFrame,outerFrame,contents,next,word,tag,access,raw⟩ :=
    Arm64MemcpyLinkOrdinary.link h old (sourceToken i) sp k spRead wordWritable tagWritable separate
  obtain ⟨native,atTarget,link,returnCode,error⟩ := native_control s origin i displacement code pc noError
  obtain ⟨memory,program,profile,accesses,atomic,exclusive,thread,extra⟩ :=
    Arm64ProgramEntryLinkNative.resources s displacement
  exact ⟨w,returned,after,sourceRun,innerFree,outerFree,innerFrame,outerFrame,contents,next,
    ⟨word,tag,link,returnCode⟩,native,atTarget,error,
    Arm64ProgramEntryLinkNative.field s displacement,memory,program,profile,accesses,atomic,exclusive,thread,extra,
    access,raw⟩

/-- The actual ELF-symbol coordinate instantiates the SAME coupled witness
once;it does not replace the source token by a physical return address. -/
theorem execute_object {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (sp : BitVec 64) (k : CC.Cont)
    (spRead : CC.Mem.load .Mint64 m h.coordinates (slot h.coordinateOffset 16) = some (.Vlong sp))
    (wordWritable : CC.Mem.validAccess m .Mint64 h.registers (slot h.registerOffset 240) .Writable = true)
    (tagWritable : CC.Mem.validAccess m .Mint8unsigned h.tags (slot h.tagOffset 30) .Writable = true)
    (separate : h.registers ≠ h.tags)
    (s : Reference.AArch64.State) (imageBase : BitVec 64) (i : Fin 8) (displacement : BitVec 26)
    (code : Code (functionOrigin imageBase) i s displacement) (pc : read_pc s.machine = imageBase+objectPC i)
    (noError : read_err s.machine = .None) :
    ∃ (w : Arm64MemcpyLinkOrdinary.Written h (sourceToken i) sp k) (returned after : CC.Mem),
      InternalRun ge 638 (.Callstate (.Internal entry) [.Vptr header offset,.Vlong (sourceToken i)] k m)
        (.Returnstate (.Vlong (sourceToken i)) (CC.callCont k) after) ∧
      CC.Mem.freeList w.after (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkWriter.allocation w.entryMemory).1) = some returned ∧
      CC.Mem.freeList returned (CC.blocksOfEnv ge.genv_cenv (Arm64MemcpyLinkSource.allocation m).1) = some after ∧
      FrameBelow w.entryMemory.nextblock w.after returned ∧ FrameBelow m.nextblock returned after ∧
      after.contents = w.after.contents ∧ after.nextblock = w.after.nextblock ∧
      Observation h i (functionOrigin imageBase) after (Native s displacement) ∧
      Reference.AArch64.step s = ⟨Native s displacement,[],none⟩ ∧
      read_pc (Native s displacement).machine =
        BR.Uncond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryLinkNative.fields displacement) ((functionOrigin imageBase)+sourcePC i) ∧
      read_err (Native s displacement).machine = .None ∧
      (∀ name : StateField, name ≠ .PC → name ≠ .GPR (30#5) →
        r name (Native s displacement).machine = r name s.machine) ∧
      (Native s displacement).machine.mem = s.machine.mem ∧
      (Native s displacement).machine.program = s.machine.program ∧
      (Native s displacement).machine.memoryProfile = s.machine.memoryProfile ∧
      (Native s displacement).machine.memoryAccesses = s.machine.memoryAccesses ∧
      (Native s displacement).machine.atomicAccesses = s.machine.atomicAccesses ∧
      (Native s displacement).machine.exclusive = s.machine.exclusive ∧
      (Native s displacement).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
      (Native s displacement).extraFlags = s.extraFlags ∧
      (∀ b, b.toNat < m.nextblock.toNat → CC.PMap.get b after.access = CC.PMap.get b m.access) ∧
      (∀ b, b.toNat < m.nextblock.toNat → b ≠ h.registers → b ≠ h.tags →
        CC.PMap.get b after.contents = CC.PMap.get b m.contents) := by
  exact execute h old sp k spRead wordWritable tagWritable separate s (functionOrigin imageBase) i displacement
    code (pc.trans (object_placement imageBase i).1) noError

end KProgFormal.ClightRefinement.Arm64MemcpyLinkCode
