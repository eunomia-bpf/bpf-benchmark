import KProgFormal.ClightRefinement.Arm64MemcpyReadAbiContext

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadContextFlow

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

def temps (le : CC.TempEnv) (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block) : CC.TempEnv :=
  Arm64MemcpyReadAbiContext.temps (Arm64MemcpyReadContext.temps le flag flagValue) abi (2#8)

private def inputKey (j : Fin 6) : CC.Ident :=
  [Arm64Program._entry,Arm64Program._base,Arm64Program.___a64_memory_off,Arm64Program._width,
    Arm64Program.___a64_memory_tag,Arm64Program.___a64_memory_source][j.val]

private theorem separate : ∀ j : Fin 6,
    Arm64Program._t'62 ≠ inputKey j ∧ Arm64Program._t'117 ≠ inputKey j ∧ Arm64Program._t'116 ≠ inputKey j ∧
    Arm64Program._t'63 ≠ inputKey j ∧ Arm64Program._t'130 ≠ inputKey j ∧ Arm64Program._t'129 ≠ inputKey j := by decide +kernel

/-- Both actual context gates retain all six genuine reader inputs. -/
theorem input_kept (le : CC.TempEnv) (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block) (j : Fin 6) :
    (temps le flag flagValue abi).get (inputKey j) = le.get (inputKey j) :=
  (Arm64MemcpyReadAbiContext.kept _ abi (2#8) _ (separate j).1 (separate j).2.1 (separate j).2.2.1).trans
    (Arm64MemcpyReadContext.kept le flag flagValue _ (separate j).2.2.2.1
      (separate j).2.2.2.2.1 (separate j).2.2.2.2.2)

/-- The original is_xdp byte may have any actual unsigned value. Tag4 makes
both genuine context gates select their real fallback arms; the actual ABI
byte2 is loaded independently. All23 source transitions keep the same heap. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry flag abi : CC.Block) (flagValue : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (tagged : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)))
    (flagHeader : CC.Mem.load CC.Mptr m entry 696 = some (.Vptr flag 0))
    (flagByte : CC.Mem.load .Mint8unsigned m flag 0 = some (.Vint (flagValue.setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr m entry 704 = some (.Vptr abi 0))
    (abiByte : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint 2)) :
    InternalRun world 23 (.State reader Arm64MemcpyReadSelect.afterSelect k e le m)
      (.State reader Arm64MemcpyReadAbiContext.stack (.Kseq Arm64MemcpyReadContext.result k)
        e (temps le flag flagValue abi) m) := by
  have actualEntry := (Arm64MemcpyReadContext.kept le flag flagValue Arm64Program._entry
    (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans hentry
  have actualTag := (Arm64MemcpyReadContext.kept le flag flagValue Arm64Program.___a64_memory_tag
    (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans tagged
  have first := Arm64MemcpyReadContext.execute e le m k entry flag flagValue hentry tagged flagHeader flagByte
  have second := Arm64MemcpyReadAbiContext.execute e _ m (.Kseq Arm64MemcpyReadContext.result k)
    entry abi (2#8) actualEntry actualTag abiHeader abiByte
  exact first.trans second

/-- The original source0 selector reaches the actual switch after both
context gates, with its true current value retained from source selection. -/
theorem source_zero (le : CC.TempEnv) (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block)
    (source0 : le.get Arm64Program.___a64_memory_source = some (.Vint 0)) :
    (temps le flag flagValue abi).get Arm64Program.___a64_memory_source = some (.Vint 0) :=
  (input_kept le flag flagValue abi 5).trans source0

end KProgFormal.ClightRefinement.Arm64MemcpyReadContextFlow
