/-
  Walks every declaration this project adds to the environment, collects the
  axioms each transitively depends on, and fails the build if anything outside
  Lean's three standard axioms shows up — `sorryAx` included.
-/
import KinsnLean4.Kinsn.Extract
import KinsnLean4.Kinsn.Rotate
import KinsnLean4.Kinsn.SignExtend
import KinsnLean4.Kinsn.Bswap
import KinsnLean4.Kinsn.LoadImm
import KinsnLean4.Kinsn.Insert
import KinsnLean4.Kinsn.Catalog
import KinsnLean4.Kinsn.ModuleCsel
import KinsnLean4.Kinsn.ModuleCset
import KinsnLean4.Kinsn.ModuleCmov
import KinsnLean4.Kinsn.ModuleByteorder
import KinsnLean4.Kinsn.ModuleNot
import KinsnLean4.Kinsn.ModuleImul
import KinsnLean4.Kinsn.ModuleBextr
import KinsnLean4.Kinsn.ModuleLowBit
import KinsnLean4.Kinsn.ModuleX86Rotate
import KinsnLean4.Kinsn.ModuleMovWide
import KinsnLean4.Kinsn.ModuleMovStore
import KinsnLean4.Kinsn.ModuleMovsxd
import KinsnLean4.Kinsn.ModuleMovzx
import KinsnLean4.Kinsn.ModuleMovswl
import KinsnLean4.Kinsn.ModuleNarrowLogic
import KinsnLean4.Kinsn.ModuleAluWide
import KinsnLean4.Kinsn.ModuleAluShift
import KinsnLean4.Kinsn.ModuleMovbe16
import KinsnLean4.Kinsn.ModuleMovbeWide
import KinsnLean4.Kinsn.ModuleBzhi
import KinsnLean4.Kinsn.ModuleBmiShift
import KinsnLean4.Kinsn.ModuleInc
import KinsnLean4.Kinsn.ModuleRev16
import KinsnLean4.Kinsn.ModuleCatalog
import KinsnLean4.Kinsn.Counterexamples

open Lean Elab Command

namespace AxiomCheck

/-- Declarations contributed by modules under `KinsnLean4`. -/
def projectDecls (env : Environment) : Array Name := Id.run do
  let mods := env.header.moduleNames
  let mut out : Array Name := #[]
  for (n, _) in env.constants.toList do
    if n.isInternal then continue
    if let some idx := env.getModuleIdxFor? n then
      if let some m := mods[idx.toNat]? then
        if (`KinsnLean4).isPrefixOf m then
          out := out.push n
  return out.qsort Name.lt

/-- What Lean's own standard library is built on. -/
def standardAxioms : List Name := [``propext, ``Classical.choice, ``Quot.sound]

end AxiomCheck

open AxiomCheck in
run_cmd do
  let env ← getEnv
  let decls := projectDecls env
  let mut used : Array Name := #[]
  let mut offenders : Array (Name × Name) := #[]
  for d in decls do
    for a in ← collectAxioms d do
      if !used.contains a then used := used.push a
      if !standardAxioms.contains a then offenders := offenders.push (d, a)
  let mut msg := "KinsnLean4 axiom audit"
  msg := msg ++ "\n  declarations checked : " ++ toString decls.size
  msg := msg ++ "\n  axioms used          : " ++ toString (used.map toString).toList
  msg := msg ++ "\n  non-standard axioms  : " ++ toString offenders.size
  for (d, a) in offenders do
    msg := msg ++ "\n  ! " ++ toString d ++ " depends on " ++ toString a
  logInfo msg
  unless offenders.isEmpty do
    throwError "project depends on non-standard axioms (including any use of sorry)"
