import KinsnLean4.X86.Semantics
import KinsnLean4.Util.Memory

namespace X86
abbrev State := Machine.State GPReg

inductive CC where
  | e | ne | b
  deriving DecidableEq, Repr

def CC.test (c : CC) (f : Machine.Flags) : Bool :=
  match c with
  | .e => f.z
  | .ne => !f.z
  | .b => f.c

def writeWidth (bits : Nat) (old v : BitVec 64) : BitVec 64 :=
  if bits = 64 then v
  else if bits = 32 then BitVec.setWidth 64 (BitVec.setWidth 32 v)
  else (old &&& ~~~(Bits.lowMask 64 bits)) ||| (v &&& Bits.lowMask 64 bits)

inductive MInsn where
  | core (i : Insn)
  | cmp (w32 : Bool) (left right : GPReg)
  | cmov (c : CC) (w32 : Bool) (dst src : GPReg)
  | load (bytes : Nat) (dst base : GPReg) (off : BitVec 64) (be : Bool := false)
  | store (bytes : Nat) (src base : GPReg) (off : BitVec 64)
  | prefetch (base : GPReg)
  | rorx32 (dst src : GPReg) (count : Nat)
  | rolW (dst : GPReg) (count : Nat)
  | bswap32 (dst : GPReg)
  | not (bits : Nat) (dst : GPReg)
  | imul (dst src : GPReg)
  | shift (bits : Nat) (left : Bool) (dst src count : GPReg)
  | bzhi (bits : Nat) (dst src count : GPReg)
  | blsi (dst src : GPReg)
  | blsr (dst src : GPReg)
  | aluMem (op : AluOp) (w32 : Bool) (dst base index : GPReg)
      (scale : Nat) (off : BitVec 64)
  | aluNarrow (op : AluOp) (bits : Nat) (dst src : GPReg)
  | aluImmNarrow (op : AluOp) (bits : Nat) (dst : GPReg) (imm : BitVec 64)
  | aluMemNarrow (op : AluOp) (bits : Nat) (dst base : GPReg) (off : BitVec 64)
  | inc (bits : Nat) (dst : GPReg)
  | shd (bits : Nat) (left : Bool) (dst src : GPReg) (count : Nat)
  | popcnt (dst src : GPReg)
  | mov32 (dst src : GPReg)
  | movzx (bits : Nat) (dst src : GPReg)
  | movswl (dst src : GPReg)
  | storeImm (bytes : Nat) (base : GPReg) (off value : BitVec 64)
  | loadIndex (bytes : Nat) (dst base index : GPReg) (scale : Nat)
      (off : BitVec 64) (be : Bool)
  | rolCL (bits : Nat) (dst : GPReg)
  | shiftImmWidth (bits : Nat) (op : ShiftOp) (dst : GPReg) (count : Nat)
  | shiftCLWidth (bits : Nat) (op : ShiftOp) (dst : GPReg)
  | lea (w32 : Bool) (dst : GPReg) (base index : Option GPReg)
      (scale : Nat) (disp : BitVec 64)
  deriving Repr

def reverseLoad (bytes : Nat) (v : BitVec 64) : BitVec 64 :=
  if bytes = 2 then BitVec.setWidth 64 (Bits.bswap16 (BitVec.setWidth 16 v))
  else if bytes = 4 then BitVec.setWidth 64 (Bits.bswap32 (BitVec.setWidth 32 v))
  else Bits.bswap64 v

def MInsn.step (i : MInsn) (s : State) : State :=
  match i with
  | .core i => { s with regs := i.step s.regs }
  | .cmp w l r =>
    let f := if w then Machine.subFlags (BitVec.setWidth 32 (s.regs l))
      (BitVec.setWidth 32 (s.regs r)) else Machine.subFlags (s.regs l) (s.regs r)
    { s with flags := { f with c := !f.c } }
  | .cmov c w dst src =>
    -- CMOV r32 clears the upper half even when its condition is false.
    let v := if c.test s.flags then s.regs src else s.regs dst
    s.set dst (if w then BitVec.setWidth 64 (BitVec.setWidth 32 v) else v)
  | .load n dst base off be =>
    let a := s.regs base + off
    let v := Machine.loadLE s.mem a n
    (s.read a n).set dst (if be then writeWidth (8 * n) (s.regs dst) (reverseLoad n v)
      else v)
  | .store n src base off => s.write (s.regs base + off) n (s.regs src)
  | .prefetch _ => s
  | .rorx32 dst src n => s.set dst (BitVec.setWidth 64
      ((BitVec.setWidth 32 (s.regs src)).rotateRight (n % 32)))
  | .rolW dst n => s.set dst (writeWidth 16 (s.regs dst) (BitVec.setWidth 64
      ((BitVec.setWidth 16 (s.regs dst)).rotateLeft (n % 16))))
  | .bswap32 dst => s.set dst (BitVec.setWidth 64
      (Bits.bswap32 (BitVec.setWidth 32 (s.regs dst))))
  | .not bits dst => s.set dst (writeWidth bits (s.regs dst) (~~~(s.regs dst)))
  | .imul dst src => s.set dst (s.regs dst * s.regs src)
  | .shift bits left dst src count =>
    let n := (s.regs count).toNat % bits
    let v := BitVec.setWidth bits (s.regs src)
    s.set dst (BitVec.setWidth 64 (if left then v <<< n else v >>> n))
  | .bzhi bits dst src count =>
    let n := (BitVec.setWidth 8 (s.regs count)).toNat
    s.set dst (BitVec.setWidth 64 ((BitVec.setWidth bits (s.regs src)) &&&
      Bits.lowMask bits n))
  | .blsi dst src => s.set dst (s.regs src &&& -(s.regs src))
  | .blsr dst src => s.set dst (s.regs src &&& (s.regs src - 1))
  | .aluMem op w dst base index scale off =>
    let n := if w then 4 else 8
    let a := s.regs base + (s.regs index <<< scale) + off
    let v := op.eval (s.regs dst) (Machine.loadLE s.mem a n)
    (s.read a n).set dst (if w then BitVec.setWidth 64 (BitVec.setWidth 32 v) else v)
  | .aluNarrow op bits dst src =>
    s.set dst (writeWidth bits (s.regs dst) (op.eval (s.regs dst) (s.regs src)))
  | .aluImmNarrow op bits dst imm =>
    s.set dst (writeWidth bits (s.regs dst) (op.eval (s.regs dst) imm))
  | .aluMemNarrow op bits dst base off =>
    let a := s.regs base + off
    (s.read a (bits / 8)).set dst
      (writeWidth bits (s.regs dst) (op.eval (s.regs dst) (Machine.loadLE s.mem a (bits / 8))))
  | .inc bits dst => s.set dst (writeWidth bits (s.regs dst) (s.regs dst + 1))
  | .shd bits left dst src count =>
    let n := count % bits
    let d := BitVec.setWidth bits (s.regs dst)
    let v := BitVec.setWidth bits (s.regs src)
    s.set dst (BitVec.setWidth 64 (if n = 0 then d
      else if left then (d <<< n) ||| (v >>> (bits - n))
      else (d >>> n) ||| (v <<< (bits - n))))
  | .popcnt dst src => s.set dst (BitVec.ofNat 64
      ((List.range 64).filter (fun i => (s.regs src).getLsbD i)).length)
  | .mov32 dst src => s.set dst (BitVec.setWidth 64 (BitVec.setWidth 32 (s.regs src)))
  | .movzx bits dst src => s.set dst (BitVec.setWidth 64 (BitVec.setWidth bits (s.regs src)))
  | .movswl dst src => s.set dst (BitVec.setWidth 64
      (BitVec.signExtend 32 (BitVec.setWidth 16 (s.regs src))))
  | .storeImm n base off v => s.write (s.regs base + off) n v
  | .loadIndex n dst base index scale off be =>
    let a := s.regs base + (s.regs index <<< scale) + off
    let v := Machine.loadLE s.mem a n
    (s.read a n).set dst (if be then writeWidth (8 * n) (s.regs dst) (reverseLoad n v)
      else v)
  | .rolCL bits dst => s.set dst (writeWidth bits (s.regs dst) (BitVec.setWidth 64
      ((BitVec.setWidth bits (s.regs dst)).rotateLeft ((s.regs .rcx).toNat % bits))))
  | .shiftImmWidth bits op dst count =>
    let v := BitVec.setWidth bits (s.regs dst)
    let n := count % (if bits = 64 then 64 else 32)
    s.set dst (writeWidth bits (s.regs dst) (BitVec.setWidth 64
      (match op with
       | .shl => v <<< n | .shr => v >>> n | .sar => v.sshiftRight n
       | .rol => v.rotateLeft n | .ror => v.rotateRight n)))
  | .shiftCLWidth bits op dst =>
    let v := BitVec.setWidth bits (s.regs dst)
    let n := (s.regs .rcx).toNat % (if bits = 64 then 64 else 32)
    s.set dst (writeWidth bits (s.regs dst) (BitVec.setWidth 64
      (match op with
       | .shl => v <<< n | .shr => v >>> n | .sar => v.sshiftRight n
       | .rol => v.rotateLeft n | .ror => v.rotateRight n)))
  | .lea w dst base index scale disp =>
    let a := (base.map s.regs).getD 0 + ((index.map s.regs).getD 0 <<< scale) + disp
    s.set dst (if w then BitVec.setWidth 64 (BitVec.setWidth 32 a) else a)

def MInsn.writes : MInsn → List GPReg
  | .core i => [i.dstReg]
  | .cmp .. | .store .. | .prefetch .. | .storeImm .. => []
  | .cmov _ _ d _ | .load _ d _ _ _ | .rorx32 d _ _ | .rolW d _
  | .bswap32 d | .not _ d | .imul d _ | .shift _ _ d _ _ | .bzhi _ d _ _
  | .blsi d _ | .blsr d _ | .lea _ d _ _ _ _ => [d]
  | .aluMem _ _ d _ _ _ _ | .aluNarrow _ _ d _ | .inc _ d
  | .aluImmNarrow _ _ d _ | .aluMemNarrow _ _ d _ _
  | .shd _ _ d _ _ | .popcnt d _ => [d]
  | .mov32 d _ | .movzx _ d _ | .movswl d _ | .loadIndex _ d _ _ _ _ _ | .rolCL _ d
  | .shiftCLWidth _ _ d | .shiftImmWidth _ _ d _ => [d]

def mexec (p : List MInsn) (s : State) : State := p.foldl (fun s i => i.step s) s
def mwrites (p : List MInsn) : List GPReg := p.flatMap MInsn.writes

@[simp] theorem mexec_nil (s : State) : mexec [] s = s := rfl
@[simp] theorem mexec_cons (i : MInsn) (p : List MInsn) (s : State) :
    mexec (i :: p) s = mexec p (i.step s) := rfl

theorem mstep_frame (i : MInsn) (s : State) (r : GPReg)
    (h : r ∉ i.writes) : (i.step s).regs r = s.regs r := by
  cases i <;> simp_all [MInsn.writes, MInsn.step, Machine.State.set,
    Machine.State.read, Machine.State.write, Insn.step_other]

theorem mexec_frame (p : List MInsn) (s : State) (r : GPReg)
    (h : r ∉ mwrites p) : (mexec p s).regs r = s.regs r := by
  induction p generalizing s with
  | nil => rfl
  | cons i rest ih =>
    simp only [mwrites, List.flatMap_cons, List.mem_append, not_or] at h
    rw [mexec_cons, ih _ h.2, mstep_frame _ _ _ h.1]

end X86
