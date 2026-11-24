import KProgFormal.ClightRefinement.Arm64ConditionBody

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ConditionAll

set_option hygiene false in
private theorem body1_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 1 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (1#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body1_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 1 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (1#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body1_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 1 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (1#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body1_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 1 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (1#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body1 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 1 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (1#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body1_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body1_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body1_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body1_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body2_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 2 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (2#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body2_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 2 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (2#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body2_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 2 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (2#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body2_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 2 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (2#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body2 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 2 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (2#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body2_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body2_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body2_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body2_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body3_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 3 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (3#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body3_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 3 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (3#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body3_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 3 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (3#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body3_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 3 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (3#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body3 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 3 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (3#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body3_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body3_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body3_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body3_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body4_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 4 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (4#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body4_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 4 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (4#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body4_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 4 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (4#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body4_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 4 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (4#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body4 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 4 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (4#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body4_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body4_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body4_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body4_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body5_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 5 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (5#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body5_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 5 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (5#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body5_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 5 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (5#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body5_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 5 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (5#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body5 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 5 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (5#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body5_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body5_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body5_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body5_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body6_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 6 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (6#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body6_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 6 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (6#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body6_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 6 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (6#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body6_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 6 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (6#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body6 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 6 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (6#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body6_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body6_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body6_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body6_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body7_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 7 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (7#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body7_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 7 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (7#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body7_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 7 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (7#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body7_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 7 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (7#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body7 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 7 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (7#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body7_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body7_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body7_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body7_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body8_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 8 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (8#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body8_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 8 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (8#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body8_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 8 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (8#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body8_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 8 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (8#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body8 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 8 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (8#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body8_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body8_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body8_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body8_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body9_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 9 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (9#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body9_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 9 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (9#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body9_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 9 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (9#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body9_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 9 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (9#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body9 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 9 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (9#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body9_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body9_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body9_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body9_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body10_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 10 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (10#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body10_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 10 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (10#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body10_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 10 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (10#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body10_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 10 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (10#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 10 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (10#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body10_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body10_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body10_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body10_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body11_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 11 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (11#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body11_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 11 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (11#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body11_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 11 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (11#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body11_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 11 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (11#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 11 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (11#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body11_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body11_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body11_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body11_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body12_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 12 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (12#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body12_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 12 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (12#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body12_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 12 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (12#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body12_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 12 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (12#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body12 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 12 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (12#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body12_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body12_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body12_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body12_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body13_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 13 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (13#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body13_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 13 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (13#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body13_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 13 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (13#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body13_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 13 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (13#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body13 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 13 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (13#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body13_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body13_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body13_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body13_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

set_option hygiene false in
private theorem body14_00 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 14 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (14#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body14_01 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((0#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (0#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 14 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (14#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body14_10 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((0#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (0#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 14 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (14#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body14_11 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint ((1#1).setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint ((1#1).setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = (1#1)) (nativeZ : read_flag .Z s.machine = (1#1))
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 14 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (14#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody

set_option hygiene false in
private theorem body14 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 14 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (14#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl
  · exact body14_00 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body14_01 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body14_10 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV
  · exact body14_11 world m k blocks s c v readN readZ readC readV nativeN nativeZ nativeC nativeV

/-- Every original condition value produced by priority modulo15 executes
its actual C call and returns the imported ConditionHolds truth value. -/
theorem internal (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (condition : Fin 15) (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State)
    (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count (.Callstate (.Internal handler) (arguments condition.val blocks) k m)
      (.Returnstate (.Vint (if ConditionHolds (BitVec.ofNat 4 condition.val) s.machine then 1#32 else 0#32))
        (CC.callCont k) m) := by
  obtain ⟨code,bound⟩ := condition
  have cases : code = 0 ∨ code = 1 ∨ code = 2 ∨ code = 3 ∨ code = 4 ∨ code = 5 ∨ code = 6 ∨
      code = 7 ∨ code = 8 ∨ code = 9 ∨ code = 10 ∨ code = 11 ∨ code = 12 ∨ code = 13 ∨ code = 14 := by omega
  rcases cases with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  · obtain ⟨count,run⟩ := body0 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 0 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body1 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 1 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body2 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 2 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body3 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 3 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body4 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 4 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body5 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 5 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body6 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 6 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body7 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 7 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body8 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 8 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body9 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 9 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body10 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 10 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body11 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 11 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body12 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 12 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body13 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 13 blocks).trans run⟩
  · obtain ⟨count,run⟩ := body14 world m k blocks s n z c v readN readZ readC readV nativeN nativeZ nativeC nativeV
    exact ⟨_,(enter world m k 14 blocks).trans run⟩

end KProgFormal.ClightRefinement.Arm64ConditionAll
