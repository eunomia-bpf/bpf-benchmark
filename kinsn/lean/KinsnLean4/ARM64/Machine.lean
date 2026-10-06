import KinsnLean4.ARM64.Semantics
import KinsnLean4.Util.Memory

namespace ARM64
abbrev State := Machine.State GPReg

def _root_.Machine.State.armGet (s : State) (r : GPReg) : BitVec 64 := RegFile.get s.regs r

@[simp] theorem get_set (s : State) (r : GPReg) (v : BitVec 64) (h : r ≠ .xzr) :
    (s.set r v).armGet r = v := by simp [Machine.State.armGet, RegFile.get, h]

@[simp] theorem get_set_other (s : State) (r q : GPReg) (v : BitVec 64) (h : q ≠ r) :
    (s.set r v).armGet q = s.armGet q := by simp [Machine.State.armGet, RegFile.get, h]

inductive MInsn where
  | core (i : Insn)
  | load (bytes : Nat) (dst base : GPReg) (off : BitVec 64)
  | store (bytes : Nat) (src base : GPReg) (off : BitVec 64)
  | ldp (lo hi base : GPReg) (off : BitVec 64)
  | stp (lo hi base : GPReg) (off : BitVec 64)
  | prfm (base : GPReg)
  | tst (r : GPReg)
  | cmpZero (w32 : Bool) (r : GPReg)
  | ccmpZero (w32 failNE : Bool) (r : GPReg)
  | cselNE (dst yes no : GPReg)
  | cset (dst : GPReg) (ne : Bool)
  | extrW (dst src : GPReg) (lsb : BitVec 5)
  | rev16W (dst src : GPReg)
  deriving Repr

def MInsn.step (i : MInsn) (s : State) : State :=
  match i with
  | .core i => { s with regs := i.step s.regs }
  | .load n dst base off =>
    let a := s.armGet base + off
    (s.read a n).set dst (Machine.loadLE s.mem a n)
  | .store n src base off => s.write (s.armGet base + off) n (s.armGet src)
  | .ldp lo hi base off =>
    let a := s.armGet base + off
    ((s.read a 8).read (a + 8) 8).set lo (Machine.loadLE s.mem a 8)
      |>.set hi (Machine.loadLE s.mem (a + 8) 8)
  | .stp lo hi base off =>
    let a := s.armGet base + off
    (s.write a 8 (s.armGet lo)).write (a + 8) 8 (s.armGet hi)
  | .prfm _ => s
  | .tst r => { s with flags := Machine.tstFlags (s.armGet r) }
  | .cmpZero w r =>
    { s with flags := if w then Machine.subFlags (BitVec.setWidth 32 (s.armGet r)) 0
      else Machine.subFlags (s.armGet r) 0 }
  | .ccmpZero w failNE r =>
    let proceed := if failNE then s.flags.z else !s.flags.z
    { s with flags := if proceed then
        (if w then Machine.subFlags (BitVec.setWidth 32 (s.armGet r)) 0
         else Machine.subFlags (s.armGet r) 0)
      else { z := !failNE } }
  | .cselNE dst yes no => s.set dst (if !s.flags.z then s.armGet yes else s.armGet no)
  | .cset dst ne => s.set dst (if (if ne then !s.flags.z else s.flags.z) then 1 else 0)
  | .extrW dst src n => s.set dst (BitVec.setWidth 64
      ((BitVec.setWidth 32 (s.armGet src)).rotateRight n.toNat))
  | .rev16W dst src =>
    let v := BitVec.setWidth 32 (s.armGet src)
    s.set dst (BitVec.setWidth 64
      (((v &&& 0x00ff00ff) <<< 8) ||| ((v &&& 0xff00ff00) >>> 8)))

def MInsn.writes : MInsn → List GPReg
  | .core i => [i.dstReg]
  | .load _ d _ _ | .cselNE d _ _ | .cset d _ | .extrW d _ _ | .rev16W d _ => [d]
  | .ldp lo hi _ _ => [lo, hi]
  | _ => []

def mexec (p : List MInsn) (s : State) : State := p.foldl (fun s i => i.step s) s
def mwrites (p : List MInsn) : List GPReg := p.flatMap MInsn.writes

@[simp] theorem mexec_nil (s : State) : mexec [] s = s := rfl
@[simp] theorem mexec_cons (i : MInsn) (p : List MInsn) (s : State) :
    mexec (i :: p) s = mexec p (i.step s) := rfl

theorem mstep_frame (i : MInsn) (s : State) (r : GPReg)
    (h : r ∉ i.writes) : (i.step s).armGet r = s.armGet r := by
  cases i with
  | core i =>
    exact Insn.step_other i s.regs r (by simpa [MInsn.writes] using h)
  | _ => simp_all [MInsn.writes, MInsn.step, Machine.State.armGet, Machine.State.set,
      Machine.State.read, Machine.State.write, RegFile.get]

theorem mexec_frame (p : List MInsn) (s : State) (r : GPReg)
    (h : r ∉ mwrites p) : (mexec p s).armGet r = s.armGet r := by
  induction p generalizing s with
  | nil => rfl
  | cons i rest ih =>
    simp only [mwrites, List.flatMap_cons, List.mem_append, not_or] at h
    rw [mexec_cons, ih _ h.2, mstep_frame _ _ _ h.1]

end ARM64
