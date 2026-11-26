import KProgFormal.ClightRefinement.Arm64MemcpyReadContextFlow
import KProgFormal.ClightRefinement.Arm64MemcpyReadPointer

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadInputs

/-- Actual reader arguments used by its original R1/width1 path. -/
structure Params (entry : CC.Block) (le : CC.TempEnv) : Prop where
  entryRead : le.get Arm64Program._entry = some (.Vptr entry 0)
  base : le.get Arm64Program._base = some (.Vlong 1)
  width : le.get Arm64Program._width = some (.Vint 1)

structure Inputs (entry : CC.Block) (off : BitVec 64) (le : CC.TempEnv) : Prop extends Params entry le where
  offsetRead : le.get Arm64Program.___a64_memory_off = some (.Vlong off)

structure Selected (entry : CC.Block) (off : BitVec 64) (le : CC.TempEnv) : Prop extends Inputs entry off le where
  tag : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32))
  source0 : le.get Arm64Program.___a64_memory_source = some (.Vint 0)

/-- Read the actual seven-setter FunctionEntry2 environment, retaining its
original undefined temporary chunks and actual parameter values. -/
theorem initial (entry : CC.Block) (extra : BitVec 64) :
    Params entry (Arm64MemcpyReadSource.initialTemps entry extra) := by
  constructor <;> simp +decide only [Arm64MemcpyReadSource.initialTemps,CC.PTree.gso,CC.PTree.gss]

/-- The actual offset extra setter follows the original numerical temps.
The numerical kept lemma alone describes offsetTemps, so the real final
memory_off setter is retained explicitly in this transport. -/
theorem offset {entry : CC.Block} (le : CC.TempEnv) (off : BitVec 64) (actual : Params entry le) :
    Inputs entry off (Arm64MemcpyReadOffset.temps le off) := by
  have entryKept := Arm64MemcpyReadOffset.kept le Arm64Program._entry (by decide +kernel)
  have baseKept := Arm64MemcpyReadOffset.kept le Arm64Program._base (by decide +kernel)
  have widthKept := Arm64MemcpyReadOffset.kept le Arm64Program._width (by decide +kernel)
  refine {entryRead := ?_,base := ?_,width := ?_,offsetRead := CC.PTree.gss _ _ _}
  · simpa +decide only [Arm64MemcpyReadOffset.temps,CC.PTree.gso] using entryKept.trans actual.entryRead
  · simpa +decide only [Arm64MemcpyReadOffset.temps,CC.PTree.gso] using baseKept.trans actual.base
  · simpa +decide only [Arm64MemcpyReadOffset.temps,CC.PTree.gso] using widthKept.trans actual.width

/-- The genuine R1 tag setters retain each original call input and offset. -/
theorem tagged {entry : CC.Block} {off : BitVec 64} (le : CC.TempEnv) (table cell : CC.Block)
    (actual : Inputs entry off le) :
    Inputs entry off (Arm64MemcpyReadTag.finalTemps le table cell (4#8)) := by
  refine {entryRead := ?_,base := ?_,width := ?_,offsetRead := ?_}
  · exact (Arm64MemcpyReadTag.kept le table cell (4#8) _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans actual.entryRead
  · exact (Arm64MemcpyReadTag.kept le table cell (4#8) _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans actual.base
  · exact (Arm64MemcpyReadTag.kept le table cell (4#8) _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans actual.width
  · exact (Arm64MemcpyReadTag.kept le table cell (4#8) _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)).trans actual.offsetRead

/-- Original source selection retains all call data and its actual tag,
while its true source0 setter supplies the switch's selected value. -/
theorem selected {entry : CC.Block} {off : BitVec 64} (le : CC.TempEnv)
    (actual : Inputs entry off le)
    (tag : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32))) :
    Selected entry off (Arm64MemcpyReadSelect.temps le) := by
  refine {entryRead := ?_,base := ?_,width := ?_,offsetRead := ?_,tag := ?_,source0 := Arm64MemcpyReadSelect.output le}
  · exact (Arm64MemcpyReadSelect.kept le _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.entryRead
  · exact (Arm64MemcpyReadSelect.kept le _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.base
  · exact (Arm64MemcpyReadSelect.kept le _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.width
  · exact (Arm64MemcpyReadSelect.kept le _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.offsetRead
  · exact (Arm64MemcpyReadSelect.kept le _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans tag

/-- All six real reader inputs survive both original context gates. -/
theorem contexts {entry : CC.Block} {off : BitVec 64} (le : CC.TempEnv)
    (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block) (actual : Selected entry off le) :
    Selected entry off (Arm64MemcpyReadContextFlow.temps le flag flagValue abi) := by
  refine {entryRead := ?_,base := ?_,width := ?_,offsetRead := ?_,tag := ?_,source0 := ?_}
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 0).trans actual.entryRead
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 1).trans actual.base
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 3).trans actual.width
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 2).trans actual.offsetRead
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 4).trans actual.tag
  · exact (Arm64MemcpyReadContextFlow.input_kept le flag flagValue abi 5).trans actual.source0


/-- The actual R1 pointer-path setters preserve the original
entry/base/width/offset inputs; its genuine pointer-to-long copy supplies the actual base. -/
theorem pointer {entry : CC.Block} {off : BitVec 64} (le : CC.TempEnv)
    (table cell : CC.Block) (raw : BitVec 64) (actual : Inputs entry off le) :
    Inputs entry off (Arm64MemcpyReadPointer.temps
      (Arm64MemcpyReadPointer.readTemps (Arm64MemcpyReadPointer.regTemps le) table cell raw) raw) ∧
    (Arm64MemcpyReadPointer.temps
      (Arm64MemcpyReadPointer.readTemps (Arm64MemcpyReadPointer.regTemps le) table cell raw) raw).get
        Arm64Program.___a64_mrd_base = some (.Vlong raw) := by
  refine ⟨{entryRead := ?_,base := ?_,width := ?_,offsetRead := ?_},CC.PTree.gss _ _ _⟩
  · exact (Arm64MemcpyReadPointer.kept le table cell raw _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.entryRead
  · exact (Arm64MemcpyReadPointer.kept le table cell raw _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.base
  · exact (Arm64MemcpyReadPointer.kept le table cell raw _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.width
  · exact (Arm64MemcpyReadPointer.kept le table cell raw _
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans actual.offsetRead

end KProgFormal.ClightRefinement.Arm64MemcpyReadInputs
