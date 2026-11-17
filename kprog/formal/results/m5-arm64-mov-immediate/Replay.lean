-- Metadata only; this concrete interpreter replay is not a symbolic proof.
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame
import KProgFormal.Clight.Arm64Numeric
import CCLib.Linking
open KProgFormal.ClightRefinement
open KProgFormal.ClightRefinement.Arm64Producer

def countMemory : Option (CC.Mem × CC.Block) := do
  let (m, entry) := CC.Mem.alloc CC.Mem.empty 0 (CC.sizeof ge.genv_cenv headerType)
  let (m, words) := CC.Mem.alloc m 0 248
  let (m, tags) := CC.Mem.alloc m 0 248
  let (m, word) := CC.Mem.alloc m 0 8
  let (m, tag) := CC.Mem.alloc m 0 1
  let (m, sp) := CC.Mem.alloc m 0 8
  let m ← CC.Mem.store CC.Mptr m entry 0 (.Vptr words 0)
  let m ← CC.Mem.store CC.Mptr m entry 8 (.Vptr tags 0)
  let m ← CC.Mem.store CC.Mptr m entry 40 (.Vptr sp 0)
  let m ← CC.Mem.store CC.Mptr m words 0 (.Vptr word 0)
  let m ← CC.Mem.store CC.Mptr m tags 0 (.Vptr tag 0)
  let m ← CC.Mem.store .Mint64 m sp 0 (.Vlong 0)
  return (m, entry)

def names : List (CC.Ident × String) :=
  [(Arm64Program._entry,"entry"),(Arm64Program._op,"op"),(Arm64Program._dst,"dst"),
   (Arm64Program._imm,"imm"),(Arm64Program.___a64_l_width,"width")]
def stateLabel : CC.State → String
  | .State _ stmt _ _ _ _ => match stmt with
    | .Sset name _ => "set " ++ toString name.toNat
    | .Sassign _ _ => "assign"
    | .Ssequence _ _ => "seq"
    | .Sifthenelse _ _ _ => "if"
    | .Sloop _ _ => "loop"
    | .Sskip => "skip"
    | .Sbreak => "break"
    | _ => "other"
  | .Callstate _ _ _ _ => "call"
  | .Returnstate _ _ _ => "return"

def countSteps (world : CC.CGenv) : Nat → Nat → CC.State → Except String (Nat × List String)
  | 0, count, _ => .error ("count fuel exhausted at " ++ toString count)
  | fuel + 1, count, state =>
    match state with
    | .Returnstate _ .Kstop _ => .ok (count, [])
    | _ => match CC.doStep world state with
      | none => .error ("actual handler stuck at " ++ toString count ++ " " ++ stateLabel state)
      | some (_, next) => do
        let (total, labels) ← countSteps world fuel (count+1) next
        pure (total, (toString count ++ ": " ++ stateLabel state)::labels)

def countWidth (width : Nat) : Except String (Nat × List String) := do
  let some (m, entry) := countMemory | .error "count storage initialization failed"
  let some linked := CC.Link.linkProgram Binding.program Arm64Numeric.prog | .error "Numeric link failed"
  countSteps linked.globalenv 500 0 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_execute)
    [.Vptr entry 0, .Vint 1, .Vlong 0, .Vlong 255, .Vundef, .Vundef,
      .Vint (BitVec.ofNat 32 width), .Vundef, .Vlong (0x12345678ffffffff#64)] .Kstop m)
#eval (countWidth 4).map Prod.fst
#eval (countWidth 8).map Prod.fst

def countSelector : Except String (Nat × List String) := do
  let some linked := CC.Link.linkProgram Binding.program Arm64Numeric.prog | .error "Numeric link failed"
  countSteps linked.globalenv 100 0 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_mov_path)
    [.Vlong 1, .Vlong 8] .Kstop CC.Mem.empty)
#eval countSelector.map Prod.fst
