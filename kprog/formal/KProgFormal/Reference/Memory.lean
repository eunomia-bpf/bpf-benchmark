import Std

namespace KProgFormal.Reference

abbrev Word := BitVec 64
abbrev Byte := BitVec 8

/-- Memory contents are arbitrary, including initially unwritten native stack
bytes. `initialized` is ghost state for checking safety, never a source of
invented zero values. Permissions describe the mapped address space. -/
structure Memory where
  value : Word → Byte
  readable : Word → Bool
  writable : Word → Bool
  initialized : Word → Bool

inductive AccessKind
  | read | write | atomic
  deriving DecidableEq, Repr

inductive Fault
  | read (address : Word) (bytes : Nat)
  | write (address : Word) (bytes : Nat)
  | divide
  deriving DecidableEq, Repr

/-- Guest effects only. Simulator spills are private implementation state.
Read values retain their initialization status so an uninitialized native read
cannot be confused with a read of initialized zero. -/
inductive Event
  | memory (kind : AccessKind) (address : Word) (value : List Byte)
      (initialized : Bool)
  | helper (identity : Word) (arguments : List Word) (result : Word)
  | fault (reason : Fault)
  deriving DecidableEq, Repr

structure Transition (State : Type) where
  state : State
  events : List Event
  fault : Option Fault := none

/-- Little-endian bytes at wrapping architectural addresses. Permission is
checked separately, before any guest state change. -/
def bytesAt (m : Memory) (address : Word) (bytes : Nat) : List Byte :=
  (List.range bytes).map (fun i => m.value (address + BitVec.ofNat 64 i))

def permitted (permission : Word → Bool) (address : Word) (bytes : Nat) : Bool :=
  (List.range bytes).all (fun i => permission (address + BitVec.ofNat 64 i))

def initializedAt (m : Memory) (address : Word) (bytes : Nat) : Bool :=
  permitted m.initialized address bytes

/-- The first byte is least significant. Defined over lists to also support
128-bit SIMD and arbitrary-length memory helper effects. -/
def littleEndian (width : Nat) : List Byte → BitVec width
  | [] => 0
  | b :: rest => b.setWidth width + 256 * littleEndian width rest

def wordAt (m : Memory) (address : Word) (bytes : Nat) : Word :=
  littleEndian 64 (bytesAt m address bytes)

def readMemory (m : Memory) (address : Word) (bytes : Nat) :
    Except Fault (Word × Event) :=
  if permitted m.readable address bytes then
    .ok (wordAt m address bytes,
      .memory .read address (bytesAt m address bytes) (initializedAt m address bytes))
  else .error (.read address bytes)

end KProgFormal.Reference
