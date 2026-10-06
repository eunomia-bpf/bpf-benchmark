import KinsnLean4.Util.Bits

/-! Byte-addressed, little-endian architectural memory. Addresses wrap at 64 bits.
    The model describes successful ordinary accesses; faults, MMIO and concurrent
    interference are outside the original single-threaded equivalence model. -/
namespace Machine

variable {R S : Type}

abbrev Memory := BitVec 64 → BitVec 8

def loadLE (m : Memory) (a : BitVec 64) : Nat → BitVec 64
  | 0 => 0
  | n + 1 => BitVec.setWidth 64 (m a) ||| (loadLE m (a + 1) n <<< 8)

def storeLE (m : Memory) (a : BitVec 64) : Nat → BitVec 64 → Memory
  | 0, _ => m
  | n + 1, v => storeLE (fun p => if p = a then BitVec.setWidth 8 v else m p)
      (a + 1) n (v >>> 8)

def footprint (a : BitVec 64) : Nat → List (BitVec 64)
  | 0 => []
  | n + 1 => a :: footprint (a + 1) n

theorem storeLE_frame (m : Memory) (a : BitVec 64) (n : Nat) (v : BitVec 64)
    (p : BitVec 64) (h : p ∉ footprint a n) : storeLE m a n v p = m p := by
  induction n generalizing m a v with
  | zero => rfl
  | succ n ih =>
    simp only [footprint, List.mem_cons, not_or] at h
    rw [storeLE, ih _ _ _ h.2]
    simp [h.1]

inductive Access where
  | read (address : BitVec 64) (bytes : Nat) (value : BitVec 64)
  | write (address : BitVec 64) (bytes : Nat) (value : BitVec 64)
  deriving DecidableEq, Repr

/-- ARM NZCV and x86 CF/ZF/SF/OF, with x86's additional AF/PF. -/
structure Flags where
  n : Bool := false
  z : Bool := false
  c : Bool := false
  v : Bool := false
  af : Bool := false
  pf : Bool := false
  deriving DecidableEq, Repr

def parity (v : BitVec 8) : Bool :=
  ((List.range 8).filter (fun i => v.getLsbD i)).length % 2 == 0

def subFlags {w : Nat} (a b : BitVec w) : Flags :=
  let r := a - b
  { n := r.getLsbD (w - 1), z := r == 0, c := decide (b.toNat ≤ a.toNat),
    v := (a.getLsbD (w - 1) != b.getLsbD (w - 1)) &&
      (r.getLsbD (w - 1) != a.getLsbD (w - 1)),
    af := (a ^^^ b ^^^ r).getLsbD 4, pf := parity (BitVec.setWidth 8 r) }

def tstFlags (v : BitVec 64) : Flags :=
  { n := v.getLsbD 63, z := v == 0 }

structure State (R : Type) where
  regs : R → BitVec 64
  mem : Memory
  trace : List Access := []
  flags : Flags := {}

def State.set [DecidableEq R] (s : State R) (r : R) (v : BitVec 64) : State R :=
  { s with regs := fun q => if q = r then v else s.regs q }

@[simp] theorem set_same [DecidableEq R] (s : State R) (r : R) (v : BitVec 64) :
    (s.set r v).regs r = v := by simp [State.set]

@[simp] theorem set_other [DecidableEq R] (s : State R) (r q : R) (v : BitVec 64)
    (h : q ≠ r) : (s.set r v).regs q = s.regs q := by simp [State.set, h]

def State.read (s : State R) (a : BitVec 64) (bytes : Nat) : State R :=
  { s with trace := s.trace ++ [.read a bytes (loadLE s.mem a bytes)] }

def State.write (s : State R) (a : BitVec 64) (bytes : Nat) (v : BitVec 64) : State R :=
  { s with
    mem := storeLE s.mem a bytes v
    trace := s.trace ++ [.write a bytes (BitVec.setWidth 64
      (BitVec.setWidth (bytes * 8) v))] }

/-- Register agreement and *all* memory, including ordered access records.
    Native condition codes have no counterpart in the BPF architectural state. -/
def Sim (φ : R → S) (get : State S → S → BitVec 64)
    (scratch : List R) (b : State R) (a : State S) : Prop :=
  (∀ r, r ∉ scratch → b.regs r = get a (φ r)) ∧ b.mem = a.mem ∧ b.trace = a.trace

end Machine
