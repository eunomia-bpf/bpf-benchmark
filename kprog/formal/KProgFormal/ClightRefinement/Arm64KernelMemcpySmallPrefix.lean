import KProgFormal.ClightRefinement.Arm64KernelMemcpySmallGates

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpySmallPrefix
open Arm64KernelMemcpyCode (Code instruction)
abbrev Prologue := Arm64KernelMemcpyPrologue.after
abbrev Gate := Arm64KernelMemcpySmallGates.after
abbrev Compare := Arm64KernelMemcpySmallGates.first

def after128 (s : Reference.AArch64.State) := Gate (Prologue s) 0
def after32 (s : Reference.AArch64.State) := Gate (after128 s) 1
def after (s : Reference.AArch64.State) := Gate (after32 s) 2

/-- All eight actual native steps and complete reached observations share
one original physical code certificate, count and machine. -/
structure Result (s : Reference.AArch64.State) (origin : BitVec 64) : Prop where
  addSource : Reference.AArch64.step s = ⟨Arm64KernelMemcpyPrologue.first s,[],none⟩
  addDestination : Reference.AArch64.step (Arm64KernelMemcpyPrologue.first s) = ⟨Prologue s,[],none⟩
  compare128 : Reference.AArch64.step (Prologue s) = ⟨Compare (Prologue s) 0,[],none⟩
  branch128 : Reference.AArch64.step (Compare (Prologue s) 0) = ⟨after128 s,[],none⟩
  compare32 : Reference.AArch64.step (after128 s) = ⟨Compare (after128 s) 1,[],none⟩
  branch32 : Reference.AArch64.step (Compare (after128 s) 1) = ⟨after32 s,[],none⟩
  compare16 : Reference.AArch64.step (after32 s) = ⟨Compare (after32 s) 2,[],none⟩
  branch16 : Reference.AArch64.step (Compare (after32 s) 2) = ⟨after s,[],none⟩
  pc : read_pc (after s).machine = origin+36#64
  noError : read_err (after s).machine = .None
  sourceEnd : Reference.AArch64.gpr (after s) 4 = Reference.AArch64.gpr s 1+16#64
  destinationEnd : Reference.AArch64.gpr (after s) 5 = Reference.AArch64.gpr s 0+16#64
  fields : ∀ field : StateField, field ≠ .PC → field ≠ .GPR (4#5) → field ≠ .GPR (5#5) →
    (∀ flag, field ≠ .FLAG flag) → r field (after s).machine = r field s.machine
  flags : read_pstate (after s).machine = Arm64KernelMemcpySmallGates.flags 2
  memory : (after s).machine.mem = s.machine.mem
  profile : (after s).machine.memoryProfile = s.machine.memoryProfile
  history : read_memory_accesses (after s).machine = read_memory_accesses s.machine
  program : (after s).machine.program = s.machine.program
  exclusive : (after s).machine.exclusive = s.machine.exclusive
  atomic : (after s).machine.atomicAccesses = s.machine.atomicAccesses
  thread : (after s).machine.threadPointerInputs = s.machine.threadPointerInputs
  extra : (after s).extraFlags = s.extraFlags
  code : Code origin (after s).machine
  firstLoad : fetch_inst (read_pc (after s).machine) (after s).machine = some (instruction 9).encoding

private theorem branch_address : ∀ i : Fin 3,
    BitVec.ofNat 64 (4*(3+2*i.val))+4#64 = BitVec.ofNat 64 (4*(4+2*i.val)) := by decide +kernel

private theorem fetch_compare (s : Reference.AArch64.State) (origin : BitVec 64) (i : Fin 3)
    (code : Code origin s.machine)
    (pc : read_pc s.machine = origin+BitVec.ofNat 64 (4*(3+2*i.val))) :
    fetch_inst (read_pc s.machine) s.machine = some (instruction (Arm64KernelMemcpySmallGates.compareIndex i)).encoding := by
  rw [pc]
  exact code (Arm64KernelMemcpySmallGates.compareIndex i)

private theorem fetch_branch (s : Reference.AArch64.State) (origin : BitVec 64) (i : Fin 3)
    (code : Code origin s.machine)
    (pc : read_pc s.machine = origin+BitVec.ofNat 64 (4*(3+2*i.val))) :
    fetch_inst (read_pc s.machine+4#64) s.machine = some (instruction (Arm64KernelMemcpySmallGates.branchIndex i)).encoding := by
  rw [pc,BitVec.add_assoc,branch_address]
  exact code (Arm64KernelMemcpySmallGates.branchIndex i)

/-- Execute the actual two ADDs and all three real CMP/branch pairs in order.
Every current count/error/fetch follows from the SAME previous native step;
the final PC reaches the captured kernel first LDP, after the BTI domain. -/
theorem execute (s : Reference.AArch64.State) (origin : BitVec 64)
    (code : Code origin s.machine) (pc : read_pc s.machine = origin+4#64)
    (count : Reference.AArch64.gpr s 2 = 16#64) (noError : read_err s.machine = .None) : Result s origin := by
  obtain ⟨addSource,addDestination,endSource,endDestination,pcP,errorP,fieldsP,memP,profileP,
    historyP,programP,exclusiveP,atomicP,threadP,extraP⟩ := Arm64KernelMemcpyPrologue.execute s origin code pc noError
  have countP : Reference.AArch64.gpr (Prologue s) 2 = 16#64 :=
    (fieldsP (.GPR (2#5)) (by decide) (by decide) (by decide)).trans count
  have codeP : Code origin (Prologue s).machine := Arm64KernelMemcpyCode.transport code programP
  obtain ⟨cmp128,br128,pc128,error128,fields128,flags128,mem128,profile128,history128,program128,
    exclusive128,atomic128,thread128,extra128⟩ := Arm64KernelMemcpySmallGates.execute (Prologue s) 0 countP errorP
      (fetch_compare _ origin 0 codeP pcP) (fetch_branch _ origin 0 codeP pcP)
  change read_pc (after128 s).machine = read_pc (Prologue s).machine+8#64 at pc128
  have at128 : read_pc (after128 s).machine = origin+20#64 := by
    simpa only [pcP,BitVec.add_assoc,show (12#64)+(8#64) = 20#64 by decide] using pc128
  have count128 : Reference.AArch64.gpr (after128 s) 2 = 16#64 :=
    (fields128 (.GPR (2#5)) (by decide) (by intro f; cases f <;> decide)).trans countP
  have code128 : Code origin (after128 s).machine := Arm64KernelMemcpyCode.transport codeP program128
  obtain ⟨cmp32,br32,pc32,error32,fields32,flags32,mem32,profile32,history32,program32,
    exclusive32,atomic32,thread32,extra32⟩ := Arm64KernelMemcpySmallGates.execute (after128 s) 1 count128 error128
      (fetch_compare _ origin 1 code128 at128) (fetch_branch _ origin 1 code128 at128)
  change read_pc (after32 s).machine = read_pc (after128 s).machine+8#64 at pc32
  have at32 : read_pc (after32 s).machine = origin+28#64 := by
    simpa only [at128,BitVec.add_assoc,show (20#64)+(8#64) = 28#64 by decide] using pc32
  have count32 : Reference.AArch64.gpr (after32 s) 2 = 16#64 :=
    (fields32 (.GPR (2#5)) (by decide) (by intro f; cases f <;> decide)).trans count128
  have code32 : Code origin (after32 s).machine := Arm64KernelMemcpyCode.transport code128 program32
  obtain ⟨cmp16,br16,pc16,error16,fields16,flags16,mem16,profile16,history16,program16,
    exclusive16,atomic16,thread16,extra16⟩ := Arm64KernelMemcpySmallGates.execute (after32 s) 2 count32 error32
      (fetch_compare _ origin 2 code32 at32) (fetch_branch _ origin 2 code32 at32)
  change read_pc (after s).machine = read_pc (after32 s).machine+8#64 at pc16
  have at16 : read_pc (after s).machine = origin+36#64 := by
    simpa only [at32,BitVec.add_assoc,show (28#64)+(8#64) = 36#64 by decide] using pc16
  have gateFields (field : StateField) (otherPC : field ≠ .PC) (otherFlags : ∀ flag, field ≠ .FLAG flag) :
      r field (after s).machine = r field (Prologue s).machine :=
    (fields16 field otherPC otherFlags).trans ((fields32 field otherPC otherFlags).trans (fields128 field otherPC otherFlags))
  have finalProgram : (after s).machine.program = s.machine.program :=
    program16.trans (program32.trans (program128.trans programP))
  have finalCode := Arm64KernelMemcpyCode.transport code finalProgram
  refine {
    addSource := addSource
    addDestination := addDestination
    compare128 := cmp128
    branch128 := br128
    compare32 := cmp32
    branch32 := br32
    compare16 := cmp16
    branch16 := br16
    pc := at16
    noError := error16
    sourceEnd := ?_
    destinationEnd := ?_
    fields := ?_
    flags := flags16
    memory := mem16.trans (mem32.trans (mem128.trans memP))
    profile := profile16.trans (profile32.trans (profile128.trans profileP))
    history := history16.trans (history32.trans (history128.trans historyP))
    program := finalProgram
    exclusive := exclusive16.trans (exclusive32.trans (exclusive128.trans exclusiveP))
    atomic := atomic16.trans (atomic32.trans (atomic128.trans atomicP))
    thread := thread16.trans (thread32.trans (thread128.trans threadP))
    extra := extra16.trans (extra32.trans (extra128.trans extraP))
    code := finalCode
    firstLoad := ?_ }
  · change r (.GPR (4#5)) (after s).machine = _
    rw [gateFields (.GPR (4#5)) (by decide) (by intro f; cases f <;> decide)]
    change r (.GPR (4#5)) (Prologue s).machine = Reference.AArch64.gpr s 1+Reference.AArch64.gpr s 2 at endSource
    simpa only [count] using endSource
  · change r (.GPR (5#5)) (after s).machine = _
    rw [gateFields (.GPR (5#5)) (by decide) (by intro f; cases f <;> decide)]
    change r (.GPR (5#5)) (Prologue s).machine = Reference.AArch64.gpr s 0+Reference.AArch64.gpr s 2 at endDestination
    simpa only [count] using endDestination
  · intro field notPC not4 not5 notFlag
    exact (gateFields field notPC notFlag).trans (fieldsP field notPC not4 not5)
  · rw [at16]
    exact finalCode 9

end KProgFormal.ClightRefinement.Arm64KernelMemcpySmallPrefix
