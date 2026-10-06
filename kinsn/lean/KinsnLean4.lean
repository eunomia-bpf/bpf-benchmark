/-
  KinsnLean4: machine-checked equivalence between BPF kinsn expansions and
  the native code the JIT emits for them.

  Entry point; see `KinsnLean4/Kinsn/Catalog.lean` for the certified kinsns
  and `KinsnLean4/AxiomCheck.lean` for the trust-base audit.
-/
import KinsnLean4.Util.Bits
import KinsnLean4.BPF.Semantics
import KinsnLean4.ARM64.Semantics
import KinsnLean4.X86.Semantics
import KinsnLean4.Kinsn.Defs
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
import KinsnLean4.Kinsn.ModuleRev16
import KinsnLean4.Kinsn.ModuleCatalog
import KinsnLean4.Kinsn.Counterexamples
import KinsnLean4.AxiomCheck
