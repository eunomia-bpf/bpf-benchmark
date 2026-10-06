import KinsnLean4.BPF.Semantics
import KinsnLean4.Util.Memory

namespace BPF
abbrev State := Machine.State Reg

inductive Cond where
  | eq | ne | ge | gt
  deriving DecidableEq, Repr

def Cond.eval {w : Nat} (c : Cond) (a b : BitVec w) : Bool :=
  match c with
  | .eq => a == b
  | .ne => !(a == b)
  | .ge => decide (b.toNat ≤ a.toNat)
  | .gt => decide (b.toNat < a.toNat)

def Cond.test (c : Cond) (w : Width) (a b : BitVec 64) : Bool :=
  match w with
  | .w32 => c.eval (BitVec.setWidth 32 a) (BitVec.setWidth 32 b)
  | .w64 => c.eval a b

/-- Extension of Hao's ALU fragment. Jump offsets are forward offsets relative
    to the next instruction, just as in the module expansions. -/
inductive MInsn where
  | core (i : Insn)
  | load (bytes : Nat) (dst base : Reg) (off : BitVec 64)
  | store (bytes : Nat) (base : Reg) (src : Src) (off : BitVec 64)
  | ja (off : Nat)
  | branch (c : Cond) (w : Width) (lhs : Reg) (rhs : Src) (off : Nat)
  | divide (remainder : Bool) (dst src : Reg)
  deriving Repr

def MInsn.step (i : MInsn) (s : State) : State :=
  match i with
  | .core i => { s with regs := i.step s.regs }
  | .load bytes dst base off =>
    let a := s.regs base + off
    (s.read a bytes).set dst (Machine.loadLE s.mem a bytes)
  | .store bytes base src off => s.write (s.regs base + off) bytes (src.eval s.regs)
  | .ja _ | .branch .. => s
  | .divide rem dst src =>
    let d := s.regs dst
    let v := s.regs src
    s.set dst (if v = 0 then (if rem then d else 0)
      else if rem then BitVec.umod d v else BitVec.udiv d v)

def MInsn.writes : MInsn → List Reg
  | .core i => [i.dstReg]
  | .load _ dst _ _ => [dst]
  | .divide _ dst _ => [dst]
  | _ => []

def mexec (p : List MInsn) (s : State) : State :=
  match p with
  | [] => s
  | i :: rest =>
    match i with
    | .ja off => mexec (rest.drop off) s
    | .branch c w lhs rhs off =>
      if c.test w (s.regs lhs) (rhs.eval s.regs) then mexec (rest.drop off) s
      else mexec rest s
    | .core j => mexec rest ((MInsn.core j).step s)
    | .load n d b o => mexec rest ((MInsn.load n d b o).step s)
    | .store n b v o => mexec rest ((MInsn.store n b v o).step s)
    | .divide rem d v => mexec rest ((MInsn.divide rem d v).step s)
termination_by p.length
decreasing_by all_goals simp_wf <;> omega

def mwrites (p : List MInsn) : List Reg := p.flatMap MInsn.writes

theorem mstep_frame (i : MInsn) (s : State) (r : Reg)
    (h : r ∉ i.writes) : (i.step s).regs r = s.regs r := by
  cases i <;> simp_all [MInsn.writes, MInsn.step, Machine.State.set,
    Machine.State.read, Machine.State.write, Insn.step_other]

theorem mexec_frame (p : List MInsn) (s : State) (r : Reg)
    (h : r ∉ mwrites p) : (mexec p s).regs r = s.regs r := by
  match p with
  | [] => simp [mexec]
  | i :: rest =>
    have hr : r ∉ mwrites rest := by simp_all [mwrites]
    have hd (n : Nat) : r ∉ mwrites (rest.drop n) := by
      intro hm
      apply hr
      simp only [mwrites, List.mem_flatMap] at hm ⊢
      obtain ⟨j, hj, h⟩ := hm
      exact ⟨j, List.mem_of_mem_drop hj, h⟩
    have hi : r ∉ i.writes := by
      simpa only [mwrites, List.flatMap_cons, List.mem_append, not_or] using
        (show r ∉ i.writes ∧ r ∉ mwrites rest from by
          simpa only [mwrites, List.flatMap_cons, List.mem_append, not_or] using h).1
    cases i with
    | ja n => simpa [mexec] using mexec_frame (rest.drop n) s r (hd n)
    | branch c w l v n =>
      simp only [mexec]
      split
      · exact mexec_frame _ _ _ (hd n)
      · exact mexec_frame _ _ _ hr
    | core i =>
      rw [mexec, mexec_frame rest _ r hr]
      exact mstep_frame _ _ _ hi
    | load n d b o =>
      rw [mexec, mexec_frame rest _ r hr]
      exact mstep_frame _ _ _ hi
    | store n b v o =>
      rw [mexec, mexec_frame rest _ r hr]
      rfl
    | divide rem d v =>
      rw [mexec, mexec_frame rest _ r hr]
      exact mstep_frame _ _ _ hi
termination_by p.length
decreasing_by all_goals simp_wf <;> omega

end BPF
