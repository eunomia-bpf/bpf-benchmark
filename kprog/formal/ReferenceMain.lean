import Lean.Data.Json
import KProgFormal.Reference.X86

open Lean KProgFormal.Reference

private def fieldNat (j : Json) (name : String) : Except String Nat := do
  (← j.getObjVal? name).getNat?

private def fieldBool (j : Json) (name : String) : Except String Bool := do
  (← j.getObjVal? name).getBool?

private def fieldWord (j : Json) (name : String) : Except String Word := do
  let n ← fieldNat j name
  if n < 2^64 then pure (BitVec.ofNat 64 n)
  else throw s!"{name} is outside the 64-bit range"

private structure InputCell where
  address : Word
  value : Byte
  readable : Bool
  writable : Bool
  initialized : Bool

private def parseCells (j : Json) : Except String (Array InputCell) := do
  let rows ← j.getArr?
  let mut seen : Std.HashSet Nat := {}
  let mut parsed := #[]
  for row in rows do
    let address ← fieldWord row "address"
    if seen.contains address.toNat then throw "duplicate memory address"
    seen := seen.insert address.toNat
    let value ← fieldNat row "value"
    if value ≥ 256 then throw "memory value is outside the byte range"
    parsed := parsed.push ⟨address, BitVec.ofNat 8 value, ← fieldBool row "readable",
      ← fieldBool row "writable", ← fieldBool row "initialized"⟩
  pure parsed

/-- Absent cells are unmapped, never readable zero-filled memory. Every mapped
cell, including an uninitialized one, must provide its actual input value. -/
private def memoryOfCells (cells : Array InputCell) : Memory :=
  let table := cells.foldl (fun m cell => m.insert cell.address.toNat cell)
    ({} : Std.HashMap Nat InputCell)
  { value := fun a => match table[a.toNat]? with | some c => c.value | none => 0
    readable := fun a => match table[a.toNat]? with | some c => c.readable | none => false
    writable := fun a => match table[a.toNat]? with | some c => c.writable | none => false
    initialized := fun a => match table[a.toNat]? with | some c => c.initialized | none => false }

private def parseState (j : Json) (cells : Array InputCell) : Except String X86.State := do
  let registers ← (← j.getObjVal? "registers").getArr?
  let regs ← registers.mapM fun r => do
    let n ← r.getNat?
    if n < 2^64 then pure (BitVec.ofNat 64 n) else throw "register is outside the 64-bit range"
  if h : regs.size = 16 then
    let flags ← fieldWord j "flags"
    let pc ← fieldWord j "pc"
    let fs ← fieldWord j "fs_base"
    let gs ← fieldWord j "gs_base"
    let xmm ← fieldNat j "xmm0"
    if xmm ≥ 2^128 then throw "xmm0 is outside the 128-bit range"
    pure { gpr := fun r => regs[r.val]'(by omega)
           rflags := flags, xmm0 := BitVec.ofNat 128 xmm, memory := memoryOfCells cells, pc := pc, fsBase := fs, gsBase := gs }
  else throw "registers must contain exactly 16 words"

private def parseNativeBytes (j : Json) : Except String (Array Byte) := do
  (← j.getArr?).mapM fun value => do
    let n ← value.getNat?
    if n < 256 then pure (BitVec.ofNat 8 n) else throw "native byte is outside [0,256)"

private def number (n : Nat) : Json := toJson n

private def faultJson : Fault → Json
  | .read a n => Json.mkObj [("kind", toJson "read"), ("address", number a.toNat), ("bytes", number n)]
  | .write a n => Json.mkObj [("kind", toJson "write"), ("address", number a.toNat), ("bytes", number n)]
  | .divide => Json.mkObj [("kind", toJson "divide")]

private def eventJson : Event → Json
  | .fault f => Json.mkObj [("kind", toJson "fault"), ("fault", faultJson f)]
  | .helper identity args result => Json.mkObj [
      ("kind", toJson "helper"), ("identity", number identity.toNat),
      ("arguments", toJson (args.map BitVec.toNat)), ("result", number result.toNat)]
  | .memory kind address value initialized => Json.mkObj [
      ("kind", toJson (match kind with | .read => "read" | .write => "write" | .atomic => "atomic")),
      ("address", number address.toNat), ("value", toJson (value.map BitVec.toNat)),
      ("initialized", toJson initialized)]

private def execute (request : Json) : Except String Json := do
  let state ← request.getObjVal? "state"
  let cells ← parseCells (← state.getObjVal? "memory")
  let initial ← parseState state cells
  let bytes ← parseNativeBytes (← request.getObjVal? "native_bytes")
  let instruction ← X86.decodeCmov bytes initial
  let output := X86.step instruction initial
  let s := output.state
  pure <| Json.mkObj [
    ("registers", toJson ((List.finRange 16).map (fun r => (s.gpr r).toNat))),
    ("flags", number s.rflags.toNat), ("pc", number s.pc.toNat), ("xmm0", number s.xmm0.toNat),
    ("fs_base", number s.fsBase.toNat), ("gs_base", number s.gsBase.toNat),
    ("memory", Json.arr (cells.map fun c => Json.mkObj [
      ("address", number c.address.toNat), ("value", number (s.memory.value c.address).toNat),
      ("readable", toJson (s.memory.readable c.address)),
      ("writable", toJson (s.memory.writable c.address)),
      ("initialized", toJson (s.memory.initialized c.address))])),
    ("events", toJson (output.events.map eventJson)),
    ("fault", match output.fault with | none => Json.null | some f => faultJson f)]

def main : IO UInt32 := do
  let input ← IO.getStdin
  let output ← IO.getStdout
  let errors ← IO.getStderr
  repeat
    let line ← input.getLine
    if line.isEmpty then return 0
    match Json.parse line >>= execute with
    | .error message => errors.putStrLn s!"reference: {message}"; return 1
    | .ok response =>
        output.putStrLn response.compress
        output.flush
  return 0
