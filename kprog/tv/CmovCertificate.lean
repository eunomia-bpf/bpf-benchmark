import CompiledBlocks
import KProgFormal.Reference.X86
import Std.Tactic.BVDecide
import BPFPath

namespace KProgTV.CmovCertificate
open KProgFormal.Reference
open KProgTV.BPF

def noExternals : Environment where
  unspecifiedInput := fun _ => .ok 0
  immediate := fun _ _ _ => .error "unexpected external BPF immediate"
  helperCall := fun _ _ => .error "unexpected helper in CMOV block"
  helper := fun _ _ _ => .error "unexpected helper in CMOV block"

def entry (native : X86.State) : State where
  regs := fun r => match r.val with
    | 1 => native.gpr 0
    | 2 => native.gpr 2
    | 3 => native.rflags
    | 10 => 0x10000
    | _ => 0
  memory := native.memory
  pc := 0

/-- Projection lemmas keep discarded input writes compact during byte execution. -/
@[simp] private theorem setReg_value (s : State) (r q : BPF.Register) (v : Word) :
    (setReg s r v).regs q = (if q = r then v else s.regs q) := rfl

@[simp] private theorem setReg_memory (s : State) (r : BPF.Register) (v : Word) :
    (setReg s r v).memory = s.memory := rfl

@[simp] private theorem setReg_pc (s : State) (r : BPF.Register) (v : Word) :
    (setReg s r v).pc = s.pc := rfl

@[simp] private theorem setReg_halted (s : State) (r : BPF.Register) (v : Word) :
    (setReg s r v).halted = s.halted := rfl

@[simp] private theorem setReg_exclusiveVisit (s : State) (r : BPF.Register) (v : Word) :
    (setReg s r v).exclusiveVisit = s.exclusiveVisit := rfl

@[simp] private theorem setReg_unspecifiedVisit (s : State) (r : BPF.Register) (v : Word) :
    (setReg s r v).unspecifiedVisit = s.unspecifiedVisit := rfl

open KProgTV.BPFPath.InputBurst

def cmovBytes : X86.CmovWidth → Array Byte
  | .w16 => #[0x66, 0x0f, 0x44, 0xc2]
  | .w32 => #[0x0f, 0x44, 0xc2]
  | .w64 => #[0x48, 0x0f, 0x44, 0xc2]

def compiled : X86.CmovWidth → Array Byte
  | .w16 => Compiled.tv_cmov16
  | .w32 => Compiled.tv_cmov32
  | .w64 => Compiled.tv_cmov64

/-- Every byte of native opcode/operands/length is decoded by V's reference. -/
theorem native_decode (width : X86.CmovWidth) (s : X86.State) :
    X86.decode (cmovBytes width) s =
      .ok (.cmov width 4 0 (.register 2) (s.pc + BitVec.ofNat 64 (cmovBytes width).size)) := by
  cases width <;> rfl

set_option maxRecDepth 100000
set_option maxHeartbeats 1600000

/-- Actual production CMOV units for each architectural condition. -/
def compiledCondition (width : X86.CmovWidth) (cc : Fin 16) : Array Byte :=
  match width, cc.val with
  | .w16, 0 => Compiled.tv_cmov16_c0
  | .w16, 1 => Compiled.tv_cmov16_c1
  | .w16, 2 => Compiled.tv_cmov16_c2
  | .w16, 3 => Compiled.tv_cmov16_c3
  | .w16, 4 => Compiled.tv_cmov16_c4
  | .w16, 5 => Compiled.tv_cmov16_c5
  | .w16, 6 => Compiled.tv_cmov16_c6
  | .w16, 7 => Compiled.tv_cmov16_c7
  | .w16, 8 => Compiled.tv_cmov16_c8
  | .w16, 9 => Compiled.tv_cmov16_c9
  | .w16, 10 => Compiled.tv_cmov16_c10
  | .w16, 11 => Compiled.tv_cmov16_c11
  | .w16, 12 => Compiled.tv_cmov16_c12
  | .w16, 13 => Compiled.tv_cmov16_c13
  | .w16, 14 => Compiled.tv_cmov16_c14
  | .w16, 15 => Compiled.tv_cmov16_c15
  | .w32, 0 => Compiled.tv_cmov32_c0
  | .w32, 1 => Compiled.tv_cmov32_c1
  | .w32, 2 => Compiled.tv_cmov32_c2
  | .w32, 3 => Compiled.tv_cmov32_c3
  | .w32, 4 => Compiled.tv_cmov32_c4
  | .w32, 5 => Compiled.tv_cmov32_c5
  | .w32, 6 => Compiled.tv_cmov32_c6
  | .w32, 7 => Compiled.tv_cmov32_c7
  | .w32, 8 => Compiled.tv_cmov32_c8
  | .w32, 9 => Compiled.tv_cmov32_c9
  | .w32, 10 => Compiled.tv_cmov32_c10
  | .w32, 11 => Compiled.tv_cmov32_c11
  | .w32, 12 => Compiled.tv_cmov32_c12
  | .w32, 13 => Compiled.tv_cmov32_c13
  | .w32, 14 => Compiled.tv_cmov32_c14
  | .w32, 15 => Compiled.tv_cmov32_c15
  | .w64, 0 => Compiled.tv_cmov64_c0
  | .w64, 1 => Compiled.tv_cmov64_c1
  | .w64, 2 => Compiled.tv_cmov64_c2
  | .w64, 3 => Compiled.tv_cmov64_c3
  | .w64, 4 => Compiled.tv_cmov64_c4
  | .w64, 5 => Compiled.tv_cmov64_c5
  | .w64, 6 => Compiled.tv_cmov64_c6
  | .w64, 7 => Compiled.tv_cmov64_c7
  | .w64, 8 => Compiled.tv_cmov64_c8
  | .w64, 9 => Compiled.tv_cmov64_c9
  | .w64, 10 => Compiled.tv_cmov64_c10
  | .w64, 11 => Compiled.tv_cmov64_c11
  | .w64, 12 => Compiled.tv_cmov64_c12
  | .w64, 13 => Compiled.tv_cmov64_c13
  | .w64, 14 => Compiled.tv_cmov64_c14
  | .w64, 15 => Compiled.tv_cmov64_c15
  | _, _ => #[]

def positionsCondition (width : X86.CmovWidth) (cc : Fin 16) (flags : Word) : List Nat :=
  match width, cc.val with
  | .w16, 0 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))
  | .w16, 1 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | .w16, 2 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))
  | .w16, 3 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | .w16, 4 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))
  | .w16, 5 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | .w16, 6 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))))
  | .w16, 7 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))))
  | .w16, 8 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))
  | .w16, 9 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | .w16, 10 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))
  | .w16, 11 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | .w16, 12 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 10 23 (33 :: (34 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: [])))))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 10 23 (33 :: (34 :: [])))))))))))
  | .w16, 13 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 11 23 (34 :: (35 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (inputPositions 11 23 (34 :: (35 :: []))))))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (inputPositions 11 23 (34 :: (35 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 11 23 (34 :: (35 :: [])))))))))))))))
  | .w16, 14 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: [])))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: [])))))))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: []))))))))))))))))
  | .w16, 15 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: [])))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: [])))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))))))))))
  | .w32, 0 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 1 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 2 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 3 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 4 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 5 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 6 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))))
  | .w32, 7 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))))
  | .w32, 8 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 9 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 10 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 11 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w32, 12 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))))
  | .w32, 13 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))))
  | .w32, 14 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))))))
  | .w32, 15 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: []))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))))))
  | .w64, 0 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 1 => (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 2 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 3 => (if flags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 4 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 5 => (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 6 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))))
  | .w64, 7 => (if flags.getLsbD 0 then (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))) else (if flags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))))
  | .w64, 8 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 9 => (if flags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 10 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 11 => (if flags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | .w64, 12 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))))
  | .w64, 13 => (if flags.getLsbD 7 then (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if flags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))))
  | .w64, 14 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: [])))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: [])))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: [])))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: [])))))))))))))))))
  | .w64, 15 => (if flags.getLsbD 6 then (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: []))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))))) else (if flags.getLsbD 7 then (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: []))))))))))))))) else (if flags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: [])))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: []))))))))))))))))
  | _, _ => []

def freshCount (_width : X86.CmovWidth) (_cc : Fin 16) : Nat := 23

def choiceEnvironment (choices : Nat → Word) : Environment :=
  { noExternals with unspecifiedInput := fun visit => .ok (choices visit) }

private theorem evaluate_inputs (choices : Nat → Word) (program : Array Byte)
    (start count : Nat) (rest : List Nat) (state : State)
    (active : state.halted = false) (position : state.pc = Int.ofNat start)
    (decoded : ∀ i : Fin count, decode program (start + i.val) = .ok marker) :
    BPFPath.evaluate (choiceEnvironment choices) program (inputPositions start count rest) state =
      BPFPath.evaluate (choiceEnvironment choices) program rest (afterInputs choices state count) :=
  evaluate_burst (choiceEnvironment choices) choices program start count rest state
    (fun _ => rfl) active position decoded

def conditionSummary (width : X86.CmovWidth) (cc : Fin 16)
    (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    Except String (Word × Memory × Nat × Bool × Option Fault × List Event) := do
  let result ← BPFPath.evaluate (choiceEnvironment choices) (compiledCondition width cc)
    (positionsCondition width cc s.rflags) { entry s with unspecifiedVisit := visit }
  pure (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
    result.state.halted, result.fault, result.events)

private theorem condition_branch_0 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (2048#64)) (0#64) = .ok ((!(s.rflags.getLsbD 11))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_1 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (1#64)) (0#64) = .ok ((!(s.rflags.getLsbD 0))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_2 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (64#64)) (0#64) = .ok ((!(s.rflags.getLsbD 6))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_3 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (65#64)) (0#64) = .ok ((!(s.rflags.getLsbD 0) && !(s.rflags.getLsbD 6))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_4 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (128#64)) (0#64) = .ok ((!(s.rflags.getLsbD 7))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_5 (s : X86.State) :
    BPF.comparison 64 1 (s.rflags &&& (4#64)) (0#64) = .ok ((!(s.rflags.getLsbD 2))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_6 (s : X86.State) :
    BPF.comparison 64 1 (((s.rflags >>> (7 : Nat)) ^^^ (s.rflags >>> (11 : Nat))) &&& (1#64)) (0#64) = .ok ((!(s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11)) || (!(s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && (s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && (s.rflags.getLsbD 11))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  simp only [BitVec.ushiftRight_eq_extractLsb'_of_lt (x := flags) (n := 7) (by decide),
    BitVec.ushiftRight_eq_extractLsb'_of_lt (x := flags) (n := 11) (by decide)]
  bv_decide

private theorem condition_branch_7 (s : X86.State) :
    BPF.comparison 64 5 (s.rflags &&& (64#64)) (0#64) = .ok (((s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && (s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && (s.rflags.getLsbD 11))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  bv_decide

private theorem condition_branch_8 (s : X86.State) :
    BPF.comparison 64 5 (((s.rflags >>> (7 : Nat)) ^^^ (s.rflags >>> (11 : Nat))) &&& (1#64)) (0#64) = .ok ((!(s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && (s.rflags.getLsbD 11)) || (!(s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && !(s.rflags.getLsbD 7) && (s.rflags.getLsbD 11)) || ((s.rflags.getLsbD 6) && (s.rflags.getLsbD 7) && !(s.rflags.getLsbD 11))) := by
  simp only [BPF.comparison, Except.ok.injEq, BitVec.getLsbD_eq_getElem]
  generalize s.rflags = flags
  simp only [BitVec.ushiftRight_eq_extractLsb'_of_lt (x := flags) (n := 7) (by decide),
    BitVec.ushiftRight_eq_extractLsb'_of_lt (x := flags) (n := 11) (by decide)]
  bv_decide

@[simp] private theorem burst_w16_c0_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c0
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c0 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c0 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c1_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c1
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c1 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c1 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c2_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c2
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c2 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c2 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c3_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c3
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c3 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c3 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c4_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c4
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c4 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c4 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c5_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c5
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c5 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c5 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c6_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c6
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c6 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c6 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c7_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c7
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c7 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c7 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c8_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c8
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c8 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c8 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c9_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c9
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c9 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c9 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c10_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c10
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c10 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 6
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c10 6 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c11_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c11
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c11 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c11 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c12_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c12
        (inputPositions 10 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c12 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c12 10 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c13_11 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c13
        (inputPositions 11 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 11 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c13 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 11
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c13 11 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c14_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c14
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c14 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c14 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c14_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c14
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c14 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c14 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c15_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c15
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c15 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c15 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w16_c15_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c15
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov16_c15 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov16_c15 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c0_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c0 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c0_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c0 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c0_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c0 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c0 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c1_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c1 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c1_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c1 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c1_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c1 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c1 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c2_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c2 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c2_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c2 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c2_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c2 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c2 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c3_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c3 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c3_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c3 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c3_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c3 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c3 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c4_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c4 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c4_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c4 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c4_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c4 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c4 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c5_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c5 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c5_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c5 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c5_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c5 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c5 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c6_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c6 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c6_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c6 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c6_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c6 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c6 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c7_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c7 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c7_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c7 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c7_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c7 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c7 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c8_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c8 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c8_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c8 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c8_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c8 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c8 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c9_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c9 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c9_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c9 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c9_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c9 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c9 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c10_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c10 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c10_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c10 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c10_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c10 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c10 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c11_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11
        (inputPositions 3 4 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11 rest
          (afterInputs choices state 4)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c11 3 4 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c11_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11
        (inputPositions 8 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 8
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c11 8 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c11_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c11 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 16
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c11 16 12 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c12_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12
        (inputPositions 7 6 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12 rest
          (afterInputs choices state 6)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c12 7 6 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c12_14 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12
        (inputPositions 14 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 14 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 14
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c12 14 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c12_22 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12
        (inputPositions 22 10 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 22 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c12 rest
          (afterInputs choices state 10)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 22
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c12 22 10 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c13_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13
        (inputPositions 7 6 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13 rest
          (afterInputs choices state 6)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c13 7 6 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c13_14 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13
        (inputPositions 14 7 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 14 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13 rest
          (afterInputs choices state 7)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 14
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c13 14 7 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c13_22 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13
        (inputPositions 22 10 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 22 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c13 rest
          (afterInputs choices state 10)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 22
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c13 22 10 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c14_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c14
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c14 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c14 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c14_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c14
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c14 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c14 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c15_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c15
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c15 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c15 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w32_c15_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c15
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov32_c15 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov32_c15 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c0_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c0
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c0 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c0 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c1_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c1
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c1 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c1 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c2_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c2
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c2 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c2 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c3_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c3
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c3 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c3 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c4_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c4
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c4 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c4 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c5_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c5
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c5 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c5 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c6_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c6
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c6 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c6 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c7_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c7
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c7 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c7 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c8_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c8
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c8 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c8 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c9_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c9
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c9 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c9 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c10_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c10
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c10 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c10 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c11_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c11
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c11 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 3
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c11 3 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c12_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c12
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c12 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c12 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c13_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c13
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c13 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 7
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c13 7 23 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c14_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c14
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c14 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c14 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c14_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c14
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c14 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c14 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c15_0 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c15
        (inputPositions 0 8 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 0 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c15 rest
          (afterInputs choices state 8)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 0
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c15 0 8 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]

@[simp] private theorem burst_w64_c15_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c15
        (inputPositions 10 15 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (choiceEnvironment choices) Compiled.tv_cmov64_c15 rest
          (afterInputs choices state 15)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
      by_cases pos : state.pc = 10
      · simpa [active, pos] using
          (evaluate_inputs choices Compiled.tv_cmov64_c15 10 15 rest state active pos
            (by simp [Fin.forall_fin_succ, marker]))
      · simp [inputPositions, BPFPath.evaluate, active, pos, List.range'_succ]
theorem compiled_w16_condition_0 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 0 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 0) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 0 = Compiled.tv_cmov16_c0 := rfl
  have route : positionsCondition .w16 0 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_1 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 1 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 1) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 1 = Compiled.tv_cmov16_c1 := rfl
  have route : positionsCondition .w16 1 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_2 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 2 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 2) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 2 = Compiled.tv_cmov16_c2 := rfl
  have route : positionsCondition .w16 2 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_3 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 3 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 3) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 3 = Compiled.tv_cmov16_c3 := rfl
  have route : positionsCondition .w16 3 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_4 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 4 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 4 = Compiled.tv_cmov16_c4 := rfl
  have route : positionsCondition .w16 4 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_5 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 5 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 5) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 5 = Compiled.tv_cmov16_c5 := rfl
  have route : positionsCondition .w16 5 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_6 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 6 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 6) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 6 = Compiled.tv_cmov16_c6 := rfl
  have route : positionsCondition .w16 6 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: []))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_7 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 7 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 7) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 7 = Compiled.tv_cmov16_c7 := rfl
  have route : positionsCondition .w16 7 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_8 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 8 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 8) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 8 = Compiled.tv_cmov16_c8 := rfl
  have route : positionsCondition .w16 8 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_9 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 9 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 9) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 9 = Compiled.tv_cmov16_c9 := rfl
  have route : positionsCondition .w16 9 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_10 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 10 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 10) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 10 = Compiled.tv_cmov16_c10 := rfl
  have route : positionsCondition .w16 10 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))) else (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_11 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 11 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 11) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 11 = Compiled.tv_cmov16_c11 := rfl
  have route : positionsCondition .w16 11 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_12 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 12 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 12) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 12 = Compiled.tv_cmov16_c12 := rfl
  have route : positionsCondition .w16 12 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 10 23 (33 :: (34 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: [])))))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 10 23 (33 :: (34 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_13 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 13 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 13) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 13 = Compiled.tv_cmov16_c13 := rfl
  have route : positionsCondition .w16 13 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 11 23 (34 :: (35 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (inputPositions 11 23 (34 :: (35 :: []))))))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (inputPositions 11 23 (34 :: (35 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 11 23 (34 :: (35 :: []))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_14 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 14 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 14) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 14 = Compiled.tv_cmov16_c14 := rfl
  have route : positionsCondition .w16 14 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: [])))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: [])))))))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: [])))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w16_condition_15 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w16 15 choices visit s = .ok
      (X86.cmovValue .w16 (X86.condition s.rflags 15) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w16 15 = Compiled.tv_cmov16_c15 := rfl
  have route : positionsCondition .w16 15 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: [])))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (36 :: (37 :: []))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: []))))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: [])))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (36 :: (37 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: (37 :: [])))))))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_0 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 0 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 0) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 0 = Compiled.tv_cmov32_c0 := rfl
  have route : positionsCondition .w32 0 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_1 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 1 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 1) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 1 = Compiled.tv_cmov32_c1 := rfl
  have route : positionsCondition .w32 1 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_2 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 2 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 2) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 2 = Compiled.tv_cmov32_c2 := rfl
  have route : positionsCondition .w32 2 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_3 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 3 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 3) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 3 = Compiled.tv_cmov32_c3 := rfl
  have route : positionsCondition .w32 3 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_4 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 4 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 4 = Compiled.tv_cmov32_c4 := rfl
  have route : positionsCondition .w32 4 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_5 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 5 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 5) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 5 = Compiled.tv_cmov32_c5 := rfl
  have route : positionsCondition .w32 5 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_6 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 6 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 6) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 6 = Compiled.tv_cmov32_c6 := rfl
  have route : positionsCondition .w32 6 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_7 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 7 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 7) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 7 = Compiled.tv_cmov32_c7 := rfl
  have route : positionsCondition .w32 7 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_8 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 8 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 8) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 8 = Compiled.tv_cmov32_c8 := rfl
  have route : positionsCondition .w32 8 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_9 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 9 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 9) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 9 = Compiled.tv_cmov32_c9 := rfl
  have route : positionsCondition .w32 9 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_10 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 10 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 10) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 10 = Compiled.tv_cmov32_c10 := rfl
  have route : positionsCondition .w32 10 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_11 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 11 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 11) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 11 = Compiled.tv_cmov32_c11 := rfl
  have route : positionsCondition .w32 11 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) else (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_12 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 12 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 12) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 12 = Compiled.tv_cmov32_c12 := rfl
  have route : positionsCondition .w32 12 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_13 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 13 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 13) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 13 = Compiled.tv_cmov32_c13 := rfl
  have route : positionsCondition .w32 13 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: [])))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 6 (13 :: (inputPositions 14 7 (21 :: (inputPositions 22 10 (32 :: (33 :: []))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_14 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 14 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 14) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 14 = Compiled.tv_cmov32_c14 := rfl
  have route : positionsCondition .w32 14 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: (35 :: (36 :: []))))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w32_condition_15 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w32 15 choices visit s = .ok
      (X86.cmovValue .w32 (X86.condition s.rflags 15) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w32 15 = Compiled.tv_cmov32_c15 := rfl
  have route : positionsCondition .w32 15 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: []))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: []))))))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: (35 :: (36 :: [])))))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_0 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 0 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 0) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 0 = Compiled.tv_cmov64_c0 := rfl
  have route : positionsCondition .w64 0 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_1 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 1 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 1) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 1 = Compiled.tv_cmov64_c1 := rfl
  have route : positionsCondition .w64 1 s.rflags = (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_2 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 2 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 2) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 2 = Compiled.tv_cmov64_c2 := rfl
  have route : positionsCondition .w64 2 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_3 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 3 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 3) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 3 = Compiled.tv_cmov64_c3 := rfl
  have route : positionsCondition .w64 3 s.rflags = (if s.rflags.getLsbD 0 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_4 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 4 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 4 = Compiled.tv_cmov64_c4 := rfl
  have route : positionsCondition .w64 4 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_5 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 5 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 5) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 5 = Compiled.tv_cmov64_c5 := rfl
  have route : positionsCondition .w64 5 s.rflags = (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_6 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 6 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 6) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 6 = Compiled.tv_cmov64_c6 := rfl
  have route : positionsCondition .w64 6 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_7 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 7 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 7) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 7 = Compiled.tv_cmov64_c7 := rfl
  have route : positionsCondition .w64 7 s.rflags = (if s.rflags.getLsbD 0 then (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))) else (if s.rflags.getLsbD 6 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: []))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag0 : s.rflags[0]
  all_goals cases flag6 : s.rflags[6]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag0, flag6] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_8 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 8 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 8) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 8 = Compiled.tv_cmov64_c8 := rfl
  have route : positionsCondition .w64 8 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_9 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 9 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 9) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 9 = Compiled.tv_cmov64_c9 := rfl
  have route : positionsCondition .w64 9 s.rflags = (if s.rflags.getLsbD 7 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_10 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 10 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 10) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 10 = Compiled.tv_cmov64_c10 := rfl
  have route : positionsCondition .w64 10 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_11 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 11 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 11) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 11 = Compiled.tv_cmov64_c11 := rfl
  have route : positionsCondition .w64 11 s.rflags = (if s.rflags.getLsbD 2 then (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) else (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag2 : s.rflags[2]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag2] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_12 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 12 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 12) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 12 = Compiled.tv_cmov64_c12 := rfl
  have route : positionsCondition .w64 12 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_13 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 13 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 13) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 13 = Compiled.tv_cmov64_c13 := rfl
  have route : positionsCondition .w64 13 s.rflags = (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) else (if s.rflags.getLsbD 11 then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_14 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 14 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 14) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 14 = Compiled.tv_cmov64_c14 := rfl
  have route : positionsCondition .w64 14 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: [])))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (33 :: (34 :: []))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: [])))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: [])))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: []))))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_w64_condition_15 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary .w64 15 choices visit s = .ok
      (X86.cmovValue .w64 (X86.condition s.rflags 15) (s.gpr 0) (s.gpr 2),
        s.memory, visit + 23, true, none, []) := by
  have block : compiledCondition .w64 15 = Compiled.tv_cmov64_c15 := rfl
  have route : positionsCondition .w64 15 s.rflags = (if s.rflags.getLsbD 6 then (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: []))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (32 :: (33 :: (34 :: [])))))))))) else (if s.rflags.getLsbD 7 then (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: []))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: []))))))))))))))) else (if s.rflags.getLsbD 11 then (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (32 :: (33 :: (34 :: [])))))))))))))) else (inputPositions 0 8 (8 :: (9 :: (inputPositions 10 15 (25 :: (26 :: (27 :: (28 :: (29 :: (30 :: (31 :: (33 :: (34 :: [])))))))))))))))) := rfl
  simp only [conditionSummary, block, route]
  cases flag6 : s.rflags[6]
  all_goals cases flag7 : s.rflags[7]
  all_goals cases flag11 : s.rflags[11]
  all_goals
    simp [afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc,
      condition_branch_0, condition_branch_1, condition_branch_2, condition_branch_3, condition_branch_4, condition_branch_5, condition_branch_6, condition_branch_7, condition_branch_8, flag6, flag7, flag11] <;>
      (try dsimp) <;> generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

theorem compiled_condition_0 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 0 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 0) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 0, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_0 choices visit s
  | w32 => exact compiled_w32_condition_0 choices visit s
  | w64 => exact compiled_w64_condition_0 choices visit s

theorem compiled_condition_1 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 1 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 1) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 1, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_1 choices visit s
  | w32 => exact compiled_w32_condition_1 choices visit s
  | w64 => exact compiled_w64_condition_1 choices visit s

theorem compiled_condition_2 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 2 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 2) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 2, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_2 choices visit s
  | w32 => exact compiled_w32_condition_2 choices visit s
  | w64 => exact compiled_w64_condition_2 choices visit s

theorem compiled_condition_3 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 3 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 3) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 3, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_3 choices visit s
  | w32 => exact compiled_w32_condition_3 choices visit s
  | w64 => exact compiled_w64_condition_3 choices visit s

theorem compiled_condition_4 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 4 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 4, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_4 choices visit s
  | w32 => exact compiled_w32_condition_4 choices visit s
  | w64 => exact compiled_w64_condition_4 choices visit s

theorem compiled_condition_5 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 5 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 5) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 5, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_5 choices visit s
  | w32 => exact compiled_w32_condition_5 choices visit s
  | w64 => exact compiled_w64_condition_5 choices visit s

theorem compiled_condition_6 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 6 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 6) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 6, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_6 choices visit s
  | w32 => exact compiled_w32_condition_6 choices visit s
  | w64 => exact compiled_w64_condition_6 choices visit s

theorem compiled_condition_7 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 7 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 7) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 7, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_7 choices visit s
  | w32 => exact compiled_w32_condition_7 choices visit s
  | w64 => exact compiled_w64_condition_7 choices visit s

theorem compiled_condition_8 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 8 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 8) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 8, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_8 choices visit s
  | w32 => exact compiled_w32_condition_8 choices visit s
  | w64 => exact compiled_w64_condition_8 choices visit s

theorem compiled_condition_9 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 9 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 9) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 9, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_9 choices visit s
  | w32 => exact compiled_w32_condition_9 choices visit s
  | w64 => exact compiled_w64_condition_9 choices visit s

theorem compiled_condition_10 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 10 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 10) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 10, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_10 choices visit s
  | w32 => exact compiled_w32_condition_10 choices visit s
  | w64 => exact compiled_w64_condition_10 choices visit s

theorem compiled_condition_11 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 11 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 11) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 11, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_11 choices visit s
  | w32 => exact compiled_w32_condition_11 choices visit s
  | w64 => exact compiled_w64_condition_11 choices visit s

theorem compiled_condition_12 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 12 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 12) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 12, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_12 choices visit s
  | w32 => exact compiled_w32_condition_12 choices visit s
  | w64 => exact compiled_w64_condition_12 choices visit s

theorem compiled_condition_13 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 13 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 13) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 13, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_13 choices visit s
  | w32 => exact compiled_w32_condition_13 choices visit s
  | w64 => exact compiled_w64_condition_13 choices visit s

theorem compiled_condition_14 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 14 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 14) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 14, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_14 choices visit s
  | w32 => exact compiled_w32_condition_14 choices visit s
  | w64 => exact compiled_w64_condition_14 choices visit s

theorem compiled_condition_15 (width : X86.CmovWidth) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    conditionSummary width 15 choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags 15) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width 15, true, none, []) := by
  cases width with
  | w16 => exact compiled_w16_condition_15 choices visit s
  | w32 => exact compiled_w32_condition_15 choices visit s
  | w64 => exact compiled_w64_condition_15 choices visit s

theorem compiled_all_conditions (width : X86.CmovWidth) (cc : Fin 16)
    (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary width cc choices visit s = .ok
      (X86.cmovValue width (X86.condition s.rflags cc) (s.gpr 0) (s.gpr 2),
        s.memory, visit + freshCount width cc, true, none, []) := by
  rcases cc with ⟨cc, bound⟩
  have cases : cc = 0 ∨ cc = 1 ∨ cc = 2 ∨ cc = 3 ∨ cc = 4 ∨ cc = 5 ∨ cc = 6 ∨ cc = 7 ∨ cc = 8 ∨ cc = 9 ∨ cc = 10 ∨ cc = 11 ∨ cc = 12 ∨ cc = 13 ∨ cc = 14 ∨ cc = 15 := by omega
  rcases cases with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact compiled_condition_0 width choices visit s
  · exact compiled_condition_1 width choices visit s
  · exact compiled_condition_2 width choices visit s
  · exact compiled_condition_3 width choices visit s
  · exact compiled_condition_4 width choices visit s
  · exact compiled_condition_5 width choices visit s
  · exact compiled_condition_6 width choices visit s
  · exact compiled_condition_7 width choices visit s
  · exact compiled_condition_8 width choices visit s
  · exact compiled_condition_9 width choices visit s
  · exact compiled_condition_10 width choices visit s
  · exact compiled_condition_11 width choices visit s
  · exact compiled_condition_12 width choices visit s
  · exact compiled_condition_13 width choices visit s
  · exact compiled_condition_14 width choices visit s
  · exact compiled_condition_15 width choices visit s

def positions : X86.CmovWidth → Bool → List Nat
  | .w16, false => (0 :: (1 :: (inputPositions 6 23 (29 :: (30 :: [])))))
  | .w16, true => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))))
  | .w32, false => (0 :: (1 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | .w32, true => (0 :: (1 :: (2 :: (inputPositions 3 4 (7 :: (inputPositions 8 7 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))))
  | .w64, false => (0 :: (1 :: (inputPositions 3 23 (26 :: (27 :: [])))))
  | .w64, true => (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))

def summary (width : X86.CmovWidth) (s : X86.State) :
    Except String (Word × Bool × Option Fault × List Event) := do
  let result ← BPFPath.evaluate noExternals (compiled width)
    (positions width (X86.condition s.rflags 4)) (entry s)
  pure (result.state.regs 0, result.state.halted, result.fault, result.events)

set_option maxRecDepth 100000
set_option maxHeartbeats 400000

theorem compiled_value (width : X86.CmovWidth) (s : X86.State) :
    summary width s = .ok
      (X86.cmovValue width (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2), true, none, []) := by
  have checked := compiled_all_conditions width 4 (fun _ => 0) 0 s
  have bytes : compiledCondition width 4 = compiled width := by cases width <;> rfl
  have path : positionsCondition width 4 s.rflags = positions width (X86.condition s.rflags 4) := by
    cases width <;>
      change (if s.rflags.getLsbD 6 then _ else _) = _
    all_goals
      cases flag : s.rflags.getLsbD 6 <;>
        simp only [positions, X86.condition, flag, Bool.false_eq_true, ↓reduceIte]
  have environment : choiceEnvironment (fun _ => 0) = noExternals := rfl
  simp only [conditionSummary, bytes, path, environment] at checked
  change (do
    let result ← BPFPath.evaluate noExternals (compiled width)
      (positions width (X86.condition s.rflags 4)) (entry s)
    pure (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
      result.state.halted, result.fault, result.events)) = _ at checked
  cases evaluated : BPFPath.evaluate noExternals (compiled width)
      (positions width (X86.condition s.rflags 4)) (entry s) with
  | error error => simp [evaluated, Except.map, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad] at checked
  | ok result =>
      simp [evaluated, Except.map, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad] at checked
      rcases checked with ⟨value, memory, visit, halted, fault, events⟩
      simp [summary, evaluated, value, halted, fault, events, Except.map, Except.bind,
        Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The scalar result comes from actual byte-decoded execution, not a forced
branch or a second implementation of the native condition/value semantics. -/
theorem compiled_execution (width : X86.CmovWidth) (s : X86.State) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep noExternals (compiled width))
        (entry s) result.events result.state ∧
      (result.state.regs 0, result.state.halted, result.fault, result.events) =
        (X86.cmovValue width (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2), true, none, []) := by
  have value := compiled_value width s
  cases evaluated : BPFPath.evaluate noExternals (compiled width)
      (positions width (X86.condition s.rflags 4)) (entry s) with
  | error error => simp [summary, evaluated, Except.bind, Except.pure, Except.map,
      Bind.bind, Pure.pure, Except.instMonad] at value
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [summary, evaluated, Except.bind, Except.pure, Except.map,
      Bind.bind, Pure.pure, Except.instMonad] using value

end KProgTV.CmovCertificate

#print axioms KProgTV.CmovCertificate.compiled_value
#print axioms KProgTV.CmovCertificate.compiled_execution

#print axioms KProgTV.CmovCertificate.compiled_all_conditions

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace KProgTV.SetccCertificate
open KProgFormal.Reference KProgTV.BPF
open KProgTV.BPFPath.InputBurst

def environment (choices : Nat → Word) : Environment where
  unspecifiedInput := fun visit => .ok (choices visit)
  immediate := fun _ _ _ => .error "external immediate"
  helperCall := fun _ _ => .error "external helper"
  helper := fun _ _ _ => .error "external helper"

def entry (s : X86.State) (visit : Nat) : State where
  regs := fun r => match r.val with
    | 1 => s.gpr 0
    | 2 => s.rflags
    | 10 => 0x10000
    | _ => 0
  memory := s.memory
  pc := 0
  unspecifiedVisit := visit

def summary (program : Array Byte) (positions : List Nat) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    Except String (Word × Memory × Nat × Bool × Option Fault × List Event) := do
  let result ← BPFPath.evaluate (environment choices) program positions (entry s visit)
  pure (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
    result.state.halted, result.fault, result.events)

@[simp] private theorem burst_lo_0_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c0
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c0 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c0 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_0 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c0 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 0 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_1_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c1
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c1 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c1 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_lo_1_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c1
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c1 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c1 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_1 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c1 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 1 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_2_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c2
        (inputPositions 3 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c2 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 3
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c2 3 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_2 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c2 (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: [])))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 2 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_3_3 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c3
        (inputPositions 3 10 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 3 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c3 rest
          (afterInputs choices state 10)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 3
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c3 3 10 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_lo_3_14 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c3
        (inputPositions 14 13 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 14 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c3 rest
          (afterInputs choices state 13)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 14
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c3 14 13 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_3 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c3 (0 :: (1 :: (2 :: (inputPositions 3 10 (13 :: (inputPositions 14 13 (27 :: (28 :: [])))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 3 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_4_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c4
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c4 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c4 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_4 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c4 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 4 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_5_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c5
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c5 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c5 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_lo_5_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c5
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c5 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c5 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_5 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c5 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 5 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_lo_6_0 (s : X86.State) : BPF.comparison 64 5 (s.rflags &&& (65#64)) (0#64) = .ok (decide ((s.rflags &&& (65#64)) ≠ (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_lo_6_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c6
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c6 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 6
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c6 6 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_6 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c6 (if ((s.rflags &&& (65#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 6 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((s.rflags &&& (65#64)) ≠ (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_lo_6_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_lo_7_0 (s : X86.State) : BPF.comparison 64 1 (s.rflags &&& (65#64)) (0#64) = .ok (decide ((s.rflags &&& (65#64)) = (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_lo_7_6 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c7
        (inputPositions 6 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 6 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c7 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 6
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c7 6 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_7 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c7 (if ((s.rflags &&& (65#64)) = (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 7 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((s.rflags &&& (65#64)) = (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_lo_7_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_8_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c8
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c8 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c8 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_8 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c8 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 8 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_9_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c9
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c9 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c9 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_lo_9_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c9
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c9 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c9 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_9 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c9 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 9 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_10_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c10
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c10 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c10 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_10 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c10 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 10 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_11_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c11
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c11 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c11 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_lo_11_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c11
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c11 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c11 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_11 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c11 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 11 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_12_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c12
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c12 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 7
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c12 7 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_12 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c12 (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 12 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_13_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c13
        (inputPositions 8 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c13 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 8
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c13 8 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_13 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c13 (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (inputPositions 8 23 (31 :: (32 :: []))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 13 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_lo_14_10 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c14
        (inputPositions 10 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 10 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c14 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 10
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c14 10 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_14 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c14 (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: []))))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 14 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_lo_15_0 (s : X86.State) : BPF.comparison 64 1 ((s.rflags &&& (64#64)) ||| (((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64))) (0#64) = .ok (decide (((s.rflags &&& (64#64)) ||| (((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64))) = (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_lo_15_13 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c15
        (inputPositions 13 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 13 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_lo_c15 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 13
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_lo_c15 13 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_lo_15 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_lo_c15 (if (((s.rflags &&& (64#64)) ||| (((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64))) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 15 then 1 else 0)
        .w8 (.low 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : (((s.rflags &&& (64#64)) ||| (((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64))) = (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_lo_15_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_0_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c0
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c0 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c0 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_0 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c0 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 0 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_1_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c1
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c1 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c1 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_hi_1_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c1
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c1 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c1 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_1 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c1 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 1 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_2_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c2
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c2 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c2 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_2 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c2 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 2 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_3_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c3
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c3 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c3 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_hi_3_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c3
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c3 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c3 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_3 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c3 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 3 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_4_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c4
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c4 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c4 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_4 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c4 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 4 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_5_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c5
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c5 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c5 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_hi_5_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c5
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c5 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c5 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_5 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c5 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 5 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_hi_6_0 (s : X86.State) : BPF.comparison 64 5 (s.rflags &&& (65#64)) (0#64) = .ok (decide ((s.rflags &&& (65#64)) ≠ (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_hi_6_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c6
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c6 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 7
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c6 7 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_6 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c6 (if ((s.rflags &&& (65#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 6 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((s.rflags &&& (65#64)) ≠ (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_hi_6_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_hi_7_0 (s : X86.State) : BPF.comparison 64 1 (s.rflags &&& (65#64)) (0#64) = .ok (decide ((s.rflags &&& (65#64)) = (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_hi_7_7 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c7
        (inputPositions 7 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 7 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c7 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 7
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c7 7 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_7 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c7 (if ((s.rflags &&& (65#64)) = (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 7 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((s.rflags &&& (65#64)) = (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_hi_7_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_8_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c8
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c8 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c8 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_8 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c8 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 8 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_9_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c9
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c9 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c9 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_hi_9_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c9
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c9 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c9 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_9 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c9 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 9 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_10_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c10
        (inputPositions 4 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c10 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c10 4 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_10 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c10 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: []))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 10 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_11_4 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c11
        (inputPositions 4 11 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 4 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c11 rest
          (afterInputs choices state 11)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 4
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c11 4 11 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

@[simp] private theorem burst_hi_11_16 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c11
        (inputPositions 16 12 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 16 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c11 rest
          (afterInputs choices state 12)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 16
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c11 16 12 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_11 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c11 (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: []))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 11 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_12_8 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c12
        (inputPositions 8 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 8 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c12 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 8
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c12 8 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_12 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c12 (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (inputPositions 8 23 (31 :: (32 :: []))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 12 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

@[simp] private theorem burst_hi_13_9 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c13
        (inputPositions 9 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 9 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c13 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 9
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c13 9 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_13 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c13 (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (inputPositions 9 23 (32 :: (33 :: [])))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 13 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_hi_14_0 (s : X86.State) : BPF.comparison 64 5 (s.rflags &&& (64#64)) (0#64) = .ok (decide ((s.rflags &&& (64#64)) ≠ (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_hi_14_13 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c14
        (inputPositions 13 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 13 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c14 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 13
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c14 13 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_14 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c14 (if ((s.rflags &&& (64#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (3 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 14 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((s.rflags &&& (64#64)) ≠ (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_hi_14_0, branch0] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

private theorem branch_hi_15_0 (s : X86.State) : BPF.comparison 64 1 (((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64)) (0#64) = .ok (decide ((((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64)) = (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

private theorem branch_hi_15_1 (s : X86.State) : BPF.comparison 64 1 (s.rflags &&& (64#64)) (0#64) = .ok (decide ((s.rflags &&& (64#64)) = (0#64))) := by
  simp [BPF.comparison] <;> bv_decide

@[simp] private theorem burst_hi_15_15 (choices : Nat → Word) (state : State) (rest : List Nat) :
    BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c15
        (inputPositions 15 23 rest) state =
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc = 15 then
        BPFPath.evaluate (environment choices) Compiled.tv_setcc_hi_c15 rest
          (afterInputs choices state 23)
      else .error "certificate BPF successor mismatch" := by
  cases active : state.halted with
  | true => simp [inputPositions, BPFPath.evaluate, active, List.range'_succ]
  | false =>
    by_cases position : state.pc = 15
    · simpa [active, position] using
        (evaluate_burst (environment choices) choices Compiled.tv_setcc_hi_c15 15 23 rest state
          (fun _ => rfl) active position (by simp [Fin.forall_fin_succ, marker]))
    · simp [inputPositions, BPFPath.evaluate, active, position, List.range'_succ]

theorem compiled_hi_15 (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    summary Compiled.tv_setcc_hi_c15 (if ((((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64)) = (0#64)) then (if ((s.rflags &&& (64#64)) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (9 :: (10 :: (11 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: [])))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (9 :: (10 :: (11 :: (12 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: [])))))))))))))))))) else (if ((s.rflags &&& (64#64)) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: []))))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: [])))))))))))))))))))) choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags 15 then 1 else 0)
        .w8 (.high 0), s.memory, visit + 23, true, none, []) := by
  all_goals by_cases branch0 : ((((s.rflags >>> 7) ^^^ (s.rflags >>> 11)) &&& (1#64)) = (0#64))
  all_goals by_cases branch1 : ((s.rflags &&& (64#64)) = (0#64))
  all_goals
    simp [summary, afterInputs, BPFPath.evaluate.eq_1, BPFPath.evaluate.eq_2,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, entry,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad,
      X86.scalarWriteValue, X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes,
      X86.condition, BitVec.getLsbD_eq_getElem, Nat.add_assoc, branch_hi_15_0, branch_hi_15_1, branch0, branch1] <;>
      (try dsimp) <;> generalize s.gpr 0 = old at * <;> generalize s.rflags = flags at * <;> unfold Word at * <;> bv_decide

/-- The unit ABI passes the old RAX value and flags in R1/R2; its scalar
result is returned in R0. This relation states the unit interface. -/
def compiledCondition (high : Bool) (cc : Nat) : Array Byte :=
  match high, cc with
  | false, 0 => Compiled.tv_setcc_lo_c0
  | false, 1 => Compiled.tv_setcc_lo_c1
  | false, 2 => Compiled.tv_setcc_lo_c2
  | false, 3 => Compiled.tv_setcc_lo_c3
  | false, 4 => Compiled.tv_setcc_lo_c4
  | false, 5 => Compiled.tv_setcc_lo_c5
  | false, 6 => Compiled.tv_setcc_lo_c6
  | false, 7 => Compiled.tv_setcc_lo_c7
  | false, 8 => Compiled.tv_setcc_lo_c8
  | false, 9 => Compiled.tv_setcc_lo_c9
  | false, 10 => Compiled.tv_setcc_lo_c10
  | false, 11 => Compiled.tv_setcc_lo_c11
  | false, 12 => Compiled.tv_setcc_lo_c12
  | false, 13 => Compiled.tv_setcc_lo_c13
  | false, 14 => Compiled.tv_setcc_lo_c14
  | false, 15 => Compiled.tv_setcc_lo_c15
  | true, 0 => Compiled.tv_setcc_hi_c0
  | true, 1 => Compiled.tv_setcc_hi_c1
  | true, 2 => Compiled.tv_setcc_hi_c2
  | true, 3 => Compiled.tv_setcc_hi_c3
  | true, 4 => Compiled.tv_setcc_hi_c4
  | true, 5 => Compiled.tv_setcc_hi_c5
  | true, 6 => Compiled.tv_setcc_hi_c6
  | true, 7 => Compiled.tv_setcc_hi_c7
  | true, 8 => Compiled.tv_setcc_hi_c8
  | true, 9 => Compiled.tv_setcc_hi_c9
  | true, 10 => Compiled.tv_setcc_hi_c10
  | true, 11 => Compiled.tv_setcc_hi_c11
  | true, 12 => Compiled.tv_setcc_hi_c12
  | true, 13 => Compiled.tv_setcc_hi_c13
  | true, 14 => Compiled.tv_setcc_hi_c14
  | true, 15 => Compiled.tv_setcc_hi_c15
  | _, _ => Compiled.tv_setcc_lo_c0

def positionsCondition (high : Bool) (cc : Nat) (flags : Word) : List Nat :=
  match high, cc with
  | false, 0 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | false, 1 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | false, 2 => (0 :: (1 :: (2 :: (inputPositions 3 23 (26 :: (27 :: []))))))
  | false, 3 => (0 :: (1 :: (2 :: (inputPositions 3 10 (13 :: (inputPositions 14 13 (27 :: (28 :: []))))))))
  | false, 4 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | false, 5 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | false, 6 => (if ((flags &&& (65#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))))
  | false, 7 => (if ((flags &&& (65#64)) = (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: [])))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (inputPositions 6 23 (29 :: (30 :: []))))))))))
  | false, 8 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | false, 9 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | false, 10 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | false, 11 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | false, 12 => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))))
  | false, 13 => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (inputPositions 8 23 (31 :: (32 :: [])))))))))))
  | false, 14 => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (inputPositions 10 23 (33 :: (34 :: [])))))))))))))
  | false, 15 => (if (((flags &&& (64#64)) ||| (((flags >>> 7) ^^^ (flags >>> 11)) &&& (1#64))) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: [])))))))))))))))))
  | true, 0 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | true, 1 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | true, 2 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | true, 3 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | true, 4 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | true, 5 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | true, 6 => (if ((flags &&& (65#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))))
  | true, 7 => (if ((flags &&& (65#64)) = (0#64)) then (0 :: (1 :: (2 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (inputPositions 7 23 (30 :: (31 :: [])))))))))))
  | true, 8 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | true, 9 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | true, 10 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 23 (27 :: (28 :: [])))))))
  | true, 11 => (0 :: (1 :: (2 :: (3 :: (inputPositions 4 11 (15 :: (inputPositions 16 12 (28 :: (29 :: [])))))))))
  | true, 12 => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (inputPositions 8 23 (31 :: (32 :: [])))))))))))
  | true, 13 => (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (inputPositions 9 23 (32 :: (33 :: []))))))))))))
  | true, 14 => (if ((flags &&& (64#64)) ≠ (0#64)) then (0 :: (1 :: (2 :: (3 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: []))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (inputPositions 13 23 (36 :: (37 :: [])))))))))))))))))
  | true, 15 => (if ((((flags >>> 7) ^^^ (flags >>> 11)) &&& (1#64)) = (0#64)) then (if ((flags &&& (64#64)) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (9 :: (10 :: (11 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: [])))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (9 :: (10 :: (11 :: (12 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: [])))))))))))))))))) else (if ((flags &&& (64#64)) = (0#64)) then (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: []))))))))))))))))) else (0 :: (1 :: (2 :: (3 :: (4 :: (5 :: (6 :: (7 :: (8 :: (9 :: (10 :: (11 :: (12 :: (13 :: (14 :: (inputPositions 15 23 (38 :: (39 :: []))))))))))))))))))))
  | _, _ => []

def targetSlice (high : Bool) : X86.RegisterSlice := if high then .high 0 else .low 0

def conditionSummary (high : Bool) (cc : Nat) (choices : Nat → Word)
    (visit : Nat) (s : X86.State) :
    Except String (Word × Memory × Nat × Bool × Option Fault × List Event) :=
  summary (compiledCondition high cc) (positionsCondition high cc s.rflags) choices visit s

/-- All 16 x86 conditions for both low and high byte destinations, decoded
from the actual compiled production-handler units. -/
theorem compiled_all_conditions (high : Bool) (cc : Fin 16)
    (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    conditionSummary high cc choices visit s = .ok
      (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags cc then 1 else 0)
        .w8 (targetSlice high), s.memory, visit + 23, true, none, []) := by
  rcases cc with ⟨cc, bound⟩
  have cases : cc = 0 ∨ cc = 1 ∨ cc = 2 ∨ cc = 3 ∨ cc = 4 ∨ cc = 5 ∨ cc = 6 ∨ cc = 7 ∨ cc = 8 ∨ cc = 9 ∨ cc = 10 ∨ cc = 11 ∨ cc = 12 ∨ cc = 13 ∨ cc = 14 ∨ cc = 15 := by omega
  rcases cases with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · cases high with
    | false => exact compiled_lo_0 choices visit s
    | true => exact compiled_hi_0 choices visit s
  · cases high with
    | false => exact compiled_lo_1 choices visit s
    | true => exact compiled_hi_1 choices visit s
  · cases high with
    | false => exact compiled_lo_2 choices visit s
    | true => exact compiled_hi_2 choices visit s
  · cases high with
    | false => exact compiled_lo_3 choices visit s
    | true => exact compiled_hi_3 choices visit s
  · cases high with
    | false => exact compiled_lo_4 choices visit s
    | true => exact compiled_hi_4 choices visit s
  · cases high with
    | false => exact compiled_lo_5 choices visit s
    | true => exact compiled_hi_5 choices visit s
  · cases high with
    | false => exact compiled_lo_6 choices visit s
    | true => exact compiled_hi_6 choices visit s
  · cases high with
    | false => exact compiled_lo_7 choices visit s
    | true => exact compiled_hi_7 choices visit s
  · cases high with
    | false => exact compiled_lo_8 choices visit s
    | true => exact compiled_hi_8 choices visit s
  · cases high with
    | false => exact compiled_lo_9 choices visit s
    | true => exact compiled_hi_9 choices visit s
  · cases high with
    | false => exact compiled_lo_10 choices visit s
    | true => exact compiled_hi_10 choices visit s
  · cases high with
    | false => exact compiled_lo_11 choices visit s
    | true => exact compiled_hi_11 choices visit s
  · cases high with
    | false => exact compiled_lo_12 choices visit s
    | true => exact compiled_hi_12 choices visit s
  · cases high with
    | false => exact compiled_lo_13 choices visit s
    | true => exact compiled_hi_13 choices visit s
  · cases high with
    | false => exact compiled_lo_14 choices visit s
    | true => exact compiled_hi_14 choices visit s
  · cases high with
    | false => exact compiled_lo_15 choices visit s
    | true => exact compiled_hi_15 choices visit s

/-- Each checked path is an execution of the byte decoder and BPF semantics;
branch choices are checked against the evolving machine state. -/
theorem compiled_execution (high : Bool) (cc : Fin 16)
    (choices : Nat → Word) (visit : Nat) (s : X86.State) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep (environment choices) (compiledCondition high cc))
        (entry s visit) result.events result.state ∧
      (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
        result.state.halted, result.fault, result.events) =
        (X86.scalarWriteValue (s.gpr 0) (if X86.condition s.rflags cc then 1 else 0)
          .w8 (targetSlice high), s.memory, visit + 23, true, none, []) := by
  have value := compiled_all_conditions high cc choices visit s
  cases evaluated : BPFPath.evaluate (environment choices) (compiledCondition high cc)
      (positionsCondition high cc s.rflags) (entry s visit) with
  | error error =>
      simp [conditionSummary, summary, evaluated, Except.bind, Except.pure,
        Except.map, Bind.bind, Pure.pure, Except.instMonad] at value
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [conditionSummary, summary, evaluated, Except.bind, Except.pure,
        Except.map, Bind.bind, Pure.pure, Except.instMonad] using value

end KProgTV.SetccCertificate

#print axioms KProgTV.SetccCertificate.compiled_all_conditions
#print axioms KProgTV.SetccCertificate.compiled_execution
