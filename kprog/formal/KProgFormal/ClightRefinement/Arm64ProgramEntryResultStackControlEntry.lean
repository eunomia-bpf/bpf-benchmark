import KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackControl
import KProgFormal.ClightRefinement.Arm64ProgramEntryControlAdmission
import KProgFormal.ClightRefinement.Arm64ProgramEntryCodeOrigin

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackControlEntry
open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps)
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)
open Arm64ProgramEntryMulAdmission (afterFour)
open Arm64ProgramEntryCompareAdmission (afterFive)
open Arm64ProgramEntrySelectAdmission (afterSix)

open Arm64ProgramEntryCnegAdmission (afterSeven)
open Arm64ProgramEntryOrnAdmission (afterEight)
open Arm64ProgramEntryFmovAdmission (afterNine)
open Arm64ProgramEntryCntAdmission (afterTen)
open Arm64ProgramEntryUaddlvAdmission (afterEleven)

open Arm64ProgramEntryResultStackRights (Reached resultTemps)

open Lean Meta in
private partial def collect (value : Expr) : MetaM (Array Expr) := do
  let type ← whnf (← inferType value)
  if type.isAppOfArity ``And 2 then
    return #[value] ++ (← collect (← mkAppM ``And.left #[value])) ++ (← collect (← mkAppM ``And.right #[value]))
  if type.isAppOfArity ``Nonempty 1 then
    return #[value,← mkAppM ``Classical.choice #[value]]
  return #[value]

open Lean Meta in
private def finish (target : Expr) (facts : Array Expr) : MetaM Expr := do
  let localValue (name : Name) : MetaM Expr := do
    let some decl := (← getLCtx).findFromUserName? name | throwError "actual prefix local missing: {name}"
    return decl.toExpr
  let function ← mkConstWithFreshMVarLevels ``Arm64ProgramEntryResultStackControl.compose
  let (args,_,result) ← forallMetaTelescopeReducing (← inferType function)
  let renames := #[(`fields,`fields),(`pointer,`pointerEffect),(`bound,`pointerBound),
    (`first,`repeatResult),(`second,`constantResult),(`abi,`abiLocal),(`reached,`reached),
    (`cell,`cell),(`ready,`ready),(`providers,`providers),(`le,`temps),(`k,`k),
    (`ctxBlock,`ctxBlock),(`ctxOffset,`ctxOfs),(`old,`old),(`reads,`reads),
    (`branch,`branch),
    (`conditionOffset,`conditionOffset),(`branchDecoded,`branchDecoded)]
  for arg in args do
    let name := (← arg.mvarId!.getDecl).userName
    if let some (_,actual) := renames.find? (fun pair => pair.1 == name) then
      let value ← localValue actual
      unless ← isDefEq (← inferType arg) (← inferType value) do
        throwError "actual prefix argument differs: {name}"
      arg.mvarId!.assign value
  let setup := mkApp3 (mkConst ``Arm64ProgramEntryBodyView.nativeSetup)
    (← localValue `s) (← localValue `origins) (← localValue `fields)
  let prefixNative := mkApp (mkConst ``Arm64ProgramEntryRepeatMovAdmission.afterTwelve) setup
  let control ← localValue `control
  let pc ← mkAppM ``And.left #[control]
  let tail ← mkAppM ``And.right #[control]
  let noError ← mkAppM ``And.left #[tail]
  let program ← mkAppM ``And.right #[tail]
  let initial ← localValue `s
  let origins ← localValue `origins
  let fields ← localValue `fields
  let cmpWord ← mkAppM ``Reference.AArch64.Instruction.encoding #[mkConst ``Arm64ProgramEntryCmpNative.instruction]
  let branchWord ← mkAppM ``Reference.AArch64.Instruction.encoding #[← localValue `branch]
  let cmpFetched ← mkAppM ``Arm64ProgramEntryControlAdmission.fetch_current
    #[initial,origins,fields,pc,program,cmpWord,← localValue `cmpFetched]
  let branchFetched ← mkAppM ``Arm64ProgramEntryControlAdmission.fetch_next
    #[initial,origins,fields,pc,program,branchWord,← localValue `branchFetched]
  let currentSites ← mkAppM ``Arm64ProgramEntryCodeOrigin.sites
    #[← localValue `code,← localValue `conditionOffset,← localValue `sites]
  let prefixTrace ← mkAppM ``CC.Eapp #[← mkAppM ``List.flatten #[← localValue `traces],← localValue `trace]
  for arg in args do
    let name := (← arg.mvarId!.getDecl).userName
    if name == `native then arg.mvarId!.assign prefixNative
    if name == `prefixTrace then arg.mvarId!.assign prefixTrace
    if name == `noError then arg.mvarId!.assign noError
    if name == `cmpFetched then arg.mvarId!.assign cmpFetched
    if name == `branchFetched then arg.mvarId!.assign branchFetched
    if name == `sites then arg.mvarId!.assign currentSites
  unless ← isDefEq result target do throwError "actual reached caller result differs"
  let mut candidates := #[]
  for decl in ← getLCtx do
    unless decl.isImplementationDetail || decl.userName == `actualPrefix do
      candidates := candidates ++ (← collect decl.toExpr)
  for fact in facts do candidates := candidates ++ (← collect fact)
  for arg in args do
    let actual ← instantiateMVars arg
    if actual.isMVar then
      let type ← instantiateMVars (← inferType actual)
      let head := type.getAppFn.constName?
      for candidate in candidates do
        let candidateType ← inferType candidate
        if candidateType.getAppFn.constName? == head then
          if head == some ``CC.Star then
            let expectedEnd := type.getAppArgs.back!
            let actualEnd := candidateType.getAppArgs.back!
            if !actualEnd.isAppOfArity ``CC.State.State 6 then continue
            if expectedEnd.getAppArgs[1]! != actualEnd.getAppArgs[1]! then continue
            if expectedEnd.getAppArgs[5]! != actualEnd.getAppArgs[5]! then continue
          let saved ← Meta.saveState
          if ← isDefEq candidateType type then
            actual.mvarId!.assign candidate
            break
          else saved.restore
  let proof ← instantiateMVars (mkAppN function args)
  if proof.hasExprMVar then
    let mut missing := #[]
    for arg in args do
      let arg ← instantiateMVars arg
      if arg.hasExprMVar then missing := missing.push m!"{arg} : {← inferType arg}"
    throwError "actual prefix evidence missing: {missing}"
  return proof

open Lean Meta in
/-- Walk original existential/conjunction witnesses iteratively; reuse every
unchanged head proof and construct only the new final continuation. -/
private def mapPrefix (target oldProof : Expr) (facts : Array Expr) : MetaM Expr := do
  let result ← mkFreshExprMVar target
  let mut pending := #[(result.mvarId!, oldProof, facts)]
  while !pending.isEmpty do
    let (goal, original, observations) := pending.back!
    pending := pending.pop
    let next ← goal.withContext do
      let target ← goal.getType
      if (← getLCtx).findFromUserName? `sites |>.isSome then
        goal.assign (← finish target observations)
        return none
      let oldType ← inferType original
      if target == oldType then
        goal.assign original
        return none
      let newType ← whnf target
      let oldType ← whnf oldType
      if newType == oldType then
        goal.assign original
        return none
      if newType.isForall then
        let (input, child) ← goal.intro1P
        let oldNext := if oldType.isForall then mkApp original (mkFVar input) else original
        return some (child, oldNext, observations)
      if newType.isAppOfArity ``Exists 2 && oldType.isAppOfArity ``Exists 2 then
        let domain := newType.getAppArgs[0]!
        let newPred := newType.getAppArgs[1]!
        let oldPred := oldType.getAppArgs[1]!
        let name := if let .lam name _ _ _ := newPred then name else `witness
        let caseType ← withLocalDeclD name domain fun witness =>
          withLocalDeclD `actualPrefix (mkApp oldPred witness) fun body =>
            mkForallFVars #[witness,body] target
        let caseProof ← mkFreshExprMVar caseType
        let elimination ← mkAppOptM ``Exists.elim
          #[some domain,some oldPred,some target,some original,some caseProof]
        goal.assign elimination
        let (witness, bodyGoal) ← caseProof.mvarId!.intro1P
        let (body, caseGoal) ← bodyGoal.intro1P
        caseGoal.withContext do
          let child ← mkFreshExprMVar (mkApp newPred (mkFVar witness))
          caseGoal.assign (← mkAppOptM ``Exists.intro
            #[some domain,some newPred,some (mkFVar witness),some child])
          return some (child.mvarId!,mkFVar body,observations)
      else if newType.isAppOfArity ``And 2 && oldType.isAppOfArity ``And 2 then
        let first := mkApp3 (mkConst ``And.left) oldType.getAppArgs[0]! oldType.getAppArgs[1]! original
        let rest := mkApp3 (mkConst ``And.right) oldType.getAppArgs[0]! oldType.getAppArgs[1]! original
        unless ← isDefEq newType.getAppArgs[0]! oldType.getAppArgs[0]! do
          throwError "original left prefix observation changed"
        let child ← mkFreshExprMVar newType.getAppArgs[1]!
        goal.assign (mkApp4 (mkConst ``And.intro) newType.getAppArgs[0]! newType.getAppArgs[1]! first child)
        return some (child.mvarId!,rest,observations.push first)
      else if ← isDefEq target oldType then
        goal.assign original
        return none
      else throwError "original prefix shape differs before native continuation: {target}"
    if let some item := next then pending := pending.push item
  return ← instantiateMVars result

/-- One complete original prefix contract, sharing all actual witnesses and
source/native/effect/frame/cache observations across physical code origins. -/
def Result (initial : CC.Mem) (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (abiLocal : TailLocal initial 6) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (fields : Fin 3 → BitVec 32) (code : Arm64ProgramEntryCodeOrigin.Origin (Arm64ProgramEntryControlAdmission.afterFourteen s origins fields)) : Prop :=
    ∃ entry : HeaderLocal initial, ∃ header : (j : Fin 12) → HeaderSourceLocal initial j,
    ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      ready.nextblock = (Arm64Producer.allocation initial).2.nextblock ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
      (setupTemps temps fields).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      Nonempty (Arm64MemsetHeaderView.Ready initial ready entry) ∧
      ∀ (supplied : CC.Mem) (trace : CC.Trace),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
          [.Vint 1] (Arm64Nop.allocation world ready).2 trace (.Vlong origins.stack) supplied →
        Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world ready).2 supplied →
    ∃ firstWritten middle secondWritten pairAfter, ∃ pairStorage : Storage initial pairAfter entry,
    ∃ thirdWritten thirdAfter, ∃ thirdStorage : Storage initial thirdAfter entry,
      (      CC.Mem.load .Mint64 pairAfter ((pairStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned pairAfter ((pairStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Mem.load .Mint64 thirdAfter ((thirdStorage.tables false).cellBlock 2) 0 = some (.Vlong (pairStorage.spValue + (16#64))) ∧
      CC.Mem.load .Mint8unsigned thirdAfter ((thirdStorage.tables true).cellBlock 2) 0 = some (.Vint (4#32)) ∧
      CC.Mem.load .Mint64 thirdAfter ((thirdStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned thirdAfter ((thirdStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddCall.afterAdd k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) thirdAfter) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock thirdAfter (.Vptr entry.block 0)
        (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (nativeSetup s origins fields)).events = [] ∧
      (Reference.AArch64.step (nativeSetup s origins fields)).fault = none ∧
      (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).events = [] ∧
      (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).fault = none ∧
      (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial thirdAfter ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1) = some middle ∧
      FrameBelow ready.nextblock firstWritten middle ∧ middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world ready).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some pairAfter ∧
      FrameBelow middle.nextblock secondWritten pairAfter ∧ pairAfter.contents = secondWritten.contents ∧
      pairAfter.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm pairAfter row.1 ofs kind permission = false) ∧
      CC.Mem.freeList thirdWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world pairAfter).1) = some thirdAfter ∧
      FrameBelow pairAfter.nextblock thirdWritten thirdAfter ∧ thirdAfter.contents = thirdWritten.contents ∧
      thirdAfter.nextblock = thirdWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world pairAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm thirdAfter row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial pairAfter thirdAfter 2 ∧
      (∀ j, CC.Mem.load CC.Mptr thirdAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock thirdAfter (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ thirdAfter.nextblock.toNat) ∧
    ∃ fourthWritten fourthAfter, ∃ fourthStorage : Storage initial fourthAfter entry,
      (CC.Mem.load .Mint64 fourthAfter ((fourthStorage.tables false).cellBlock 3) 0 = some (.Vlong ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack))) ∧
      CC.Mem.load .Mint8unsigned fourthAfter ((fourthStorage.tables true).cellBlock 3) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddRegisterCall.afterRegister k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) fourthAfter) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock fourthAfter (.Vptr entry.block 0)
        (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial fourthAfter ∧
      CC.Mem.freeList fourthWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1) = some fourthAfter ∧
      FrameBelow thirdAfter.nextblock fourthWritten fourthAfter ∧
      fourthAfter.contents = fourthWritten.contents ∧ fourthAfter.nextblock = fourthWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm fourthAfter row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial thirdAfter fourthAfter 3 ∧
      (∀ j, CC.Mem.load CC.Mptr fourthAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock fourthAfter (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ fourthAfter.nextblock.toNat) ∧
    ∃ fifthWritten after, ∃ finalStorage : Storage initial after entry,
      (CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 4) 0 = some (.Vlong ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) * ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack)))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 4) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial after ∧
      CC.Mem.freeList fifthWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world fourthAfter).1) = some after ∧
      FrameBelow fourthAfter.nextblock fifthWritten after ∧
      after.contents = fifthWritten.contents ∧ after.nextblock = fifthWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world fourthAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial fourthAfter after 4 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat) ∧
    ∃ sixthWritten final, ∃ compareStorage : Storage initial final entry,
      (Arm64Compare.Call.Result finalStorage ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) * ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack))) (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)
        (Arm64ProgramEntryCompareCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        sixthWritten final compareStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock final (.Vptr entry.block 0)
        (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial final ∧
      (∀ j, CC.Mem.load CC.Mptr final entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock final (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ final.nextblock.toNat) ∧
    ∃ count value raw tag seventhWritten selected, ∃ selectedStorage : Storage initial selected entry,
      (Arm64Select.Call.Result compareStorage addresses origins (afterSix (nativeSetup s origins fields))
        (Arm64ProgramEntrySelectCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count value raw tag seventhWritten selected selectedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySelectCall.afterSelect k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) selected) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock selected (.Vptr entry.block 0)
        (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial selected ∧
      (∀ j, CC.Mem.load CC.Mptr selected entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock selected (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ selected.nextblock.toNat ) ∧
    ∃ count8 eighthWritten negated, ∃ negatedStorage : Storage initial negated entry,
      (Arm64Cneg.Call.Result selectedStorage addresses origins (afterSeven (nativeSetup s origins fields))
        (Arm64ProgramEntryCnegCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count8 eighthWritten negated negatedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCnegCall.afterCneg k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) negated) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock negated (.Vptr entry.block 0)
        (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial negated ∧
      (∀ j, CC.Mem.load CC.Mptr negated entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock negated (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ negated.nextblock.toNat ) ∧
    ∃ count9 ninthWritten combined, ∃ combinedStorage : Storage initial combined entry,
      ( Arm64Orn.Call.Result negatedStorage addresses origins (afterEight (nativeSetup s origins fields))
        (Arm64ProgramEntryOrnCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count9 ninthWritten combined combinedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrnCall.afterOrn k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) combined) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock combined (.Vptr entry.block 0)
        (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial combined ∧
      (∀ j, CC.Mem.load CC.Mptr combined entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock combined (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ combined.nextblock.toNat ) ∧
    ∃ count10 tenthWritten final, ∃ finalStorage : Storage initial final entry,
      (      Arm64Fmov.Call.Result combinedStorage
        (Arm64RegisterWrite.written true (Arm64Orn.Call.nativeResult (afterEight (nativeSetup s origins fields))))
        addresses origins (afterNine (nativeSetup s origins fields))
        (Arm64ProgramEntryFmovCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count10 tenthWritten final finalStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryFmovCall.afterFmov k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock final (.Vptr entry.block 0)
        (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial final ∧
      (∀ j, CC.Mem.load CC.Mptr final entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock final (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ final.nextblock.toNat ) ∧
    ∃ count11 eleventhWritten completed, ∃ completedStorage : Storage initial completed entry,
      (Arm64Cnt.Call.Result finalStorage addresses origins (afterTen (nativeSetup s origins fields))
        (Arm64ProgramEntryCntCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count11 eleventhWritten completed completedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCntCall.afterCnt k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) completed) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock completed (.Vptr entry.block 0)
        (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial completed ∧
      (∀ j, CC.Mem.load CC.Mptr completed entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock completed (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ completed.nextblock.toNat ) ∧
    ∃ count12 twelfthWritten summed, ∃ summedStorage : Storage initial summed entry,
      (Arm64Uaddlv.Call.Result completedStorage addresses origins (afterEleven (nativeSetup s origins fields))
        (Arm64ProgramEntryUaddlvCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count12 twelfthWritten summed summedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock summed (.Vptr entry.block 0)
        (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial summed ∧
      (∀ j, CC.Mem.load CC.Mptr summed entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock summed (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ summed.nextblock.toNat ) ∧
    ∃ readCount, InternalRun world readCount
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryResultRead.afterReads k
        (Arm64ProgramEntryAllocation.allocation initial).1
        (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64)) summed) ∧
      (Arm64ProgramEntryResultVector.temps
        (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
        (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
        (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
        ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
        ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64)).get
        Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      ∃ conditionCount, InternalRun world conditionCount
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryResultCondition.afterCondition k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) summed) ∧
      ∃ pointerWritten, ∃ pointerEffect : Arm64PointerWrite.Result summedStorage 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8) pointerWritten,
        InternalRun world (conditionCount + 57)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
            (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
            (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) pointerWritten) ∧
        Arm64Registers.Represents addresses origins (fun r => r.val) summed.nextblock pointerWritten (.Vptr entry.block 0)
          (Arm64PointerWrite.nativeUpdate origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8)) ∧
        FrameBelow initial.nextblock initial pointerWritten ∧
        Arm64RegisterReads.WarmEntryCache false summed.nextblock pointerWritten (.Vptr entry.block 0) origins.stack ∧
        (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
        ∃ repeatWritten repeatAfter, ∃ repeatResult : Arm64MovImmediate.OrdinaryCall.Result pointerEffect.storage
          1 ((fields 0).setWidth 64) addresses origins (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))
          (Arm64ProgramEntryOrdinaryMovePath.callCont initial (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) k (fields 0)) repeatWritten repeatAfter,
          InternalRun world (conditionCount + 57 + 210)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
              (Arm64ProgramEntryAllocation.allocation initial).1
              (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
              (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) repeatAfter) ∧
          Arm64Registers.Represents addresses origins (fun r => r.val) pointerWritten.nextblock repeatAfter (.Vptr entry.block 0)
            (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).state ∧
          (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).events = [] ∧ (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).fault = none ∧
          FrameBelow initial.nextblock initial repeatAfter ∧
          (∀ j, CC.Mem.load CC.Mptr repeatAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
          Arm64RegisterReads.WarmEntryCache false pointerWritten.nextblock repeatAfter (.Vptr entry.block 0) origins.stack ∧
          (Arm64Producer.allocation initial).2.nextblock.toNat ≤ repeatAfter.nextblock.toNat ∧
          (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
          CC.Star (CC.Step2 world)
            (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
            (CC.Eapp traces.flatten trace)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
              (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) repeatAfter) ∧
          ∃ pointerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat,
          ∃ constantWritten constantAfter, ∃ constantResult : Arm64MovImmediate.OrdinaryCall.Result
            (repeatResult.storage pointerBound) 2 (16#64) addresses origins (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))
            (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1
              (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterSecond k)) constantWritten constantAfter,
            InternalRun world (conditionCount + 57 + 210 + 207)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
                (Arm64ProgramEntryAllocation.allocation initial).1
                (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
                (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) constantAfter) ∧
            Arm64Registers.Represents addresses origins (fun r => r.val) constantAfter.nextblock constantAfter (.Vptr entry.block 0)
              (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state ∧
            (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).fault = none ∧
            FrameBelow initial.nextblock initial constantAfter ∧
            (∀ j, CC.Mem.load CC.Mptr constantAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
            Arm64RegisterReads.WarmEntryCache false constantAfter.nextblock constantAfter (.Vptr entry.block 0) origins.stack ∧
            (Arm64Producer.allocation initial).2.nextblock.toNat ≤ constantAfter.nextblock.toNat ∧
            CC.Star (CC.Step2 world)
              (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
              (CC.Eapp traces.flatten trace)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
                (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) constantAfter) ∧
            Arm64ProducerTailFrame.Frame initial entry ready constantAfter ∧
            CC.Mem.load .Mint8unsigned constantAfter abiLocal.block 0 = some (.Vint 2) ∧
            CC.Mem.load CC.Mptr constantAfter entry.block 704 = some (.Vptr abiLocal.block 0) ∧
            (∀ (tags : StackTagLocal initial) (i : Fin 24),
              CC.Mem.load .Mint8unsigned constantAfter tags.block (i.val : Int) = some (.Vint 0)) ∧
      Nonempty (Arm64MemsetHeaderView.View initial summed entry) ∧
      Nonempty (Arm64MemsetHeaderView.View initial constantAfter entry) ∧
      ∃ reached : Reached summedStorage abiLocal,
      ∀ (cell : TailLocal initial 5)
        (providers : Arm64ProgramEntryMemoryPacket.Providers
          (Arm64ProgramEntryMemoryPacket.prepare pointerEffect pointerBound repeatResult constantResult
            reached.view reached.resources reached.spAtBase abiLocal reached.abiHeader reached.abiKind reached.tagBytes).view
          abiLocal (fields 0) constantAfter cell),
      CC.isCallCont k = true →
      let sourceState := (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state
      ∀ (cmpFetched : fetch_inst (read_pc s.machine + 56#64) s.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
        (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
        (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
        (branchFetched : fetch_inst (read_pc s.machine + 60#64) s.machine = some branch.encoding)
        (sites : Arm64ProgramEntryPostMemoryBranchSites.Sites code.state conditionOffset),
      let currentSites := Arm64ProgramEntryCodeOrigin.sites code conditionOffset sites
      ∃ gprs helperFlags helperVectors trace live, ∃ lr : HeaderSourceLocal initial 4, ∃ stored returned,
        Arm64ProgramEntryTerminalFree.FreeResult initial stored returned ∧
        CC.Star (CC.Step2 world)
          (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial) trace
          (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord
            (Arm64ProgramEntryComplete.sourceResult fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0) sourceState
            gprs helperFlags helperVectors (Arm64MemsetLossSetup.byte (fields 0)))) k returned) ∧
        FrameBelow initial.nextblock initial returned ∧
        Arm64ProgramEntrySourceReturnNative.Facts (Arm64ProgramEntryPostMemoryCmpView.native sourceState gprs helperFlags)
          conditionOffset (Arm64ProgramEntryPostMemoryBranchSites.chosenOffset sourceState gprs helperFlags conditionOffset currentSites)
          (Arm64ProgramEntryPostMemoryBranchSites.admission sourceState gprs helperFlags conditionOffset currentSites)
          live (.Vptr entry.block 0) lr.block

/-- Consume one original prefix and the same reached helper/source execution,
resolving both real code sites at the actual target from one code origin. -/
theorem entry_with_code (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (abiLocal : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i)))
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
    (thirteenthDecoded : thirteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (fourteenthDecoded : fourteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 2 (16#16) 0 false false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding)
    (fourteenthFetched : fetch_inst (read_pc s.machine + 52#64) s.machine = some fourteenth.encoding)
    (code : Arm64ProgramEntryCodeOrigin.Origin (Arm64ProgramEntryControlAdmission.afterFourteen s origins fields)) :
    Result initial ctxBlock ctxOfs k abiLocal addresses origins s fields code := by
  have control := Arm64ProgramEntryControlAdmission.admission s origins fields
    first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
    imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded
    seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded
    noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
    eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched fourteenthFetched
  have original := Arm64ProgramEntryResultStackRights.entry_corresponds initial ctxBlock ctxOfs k abiLocal addresses ctxWord context values provider flags flagProvider vectors vectorProvider
      origins s native fields old reads first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
      imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded
      ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded noError firstFetched keepFetched
      thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
      thirteenthFetched fourteenthFetched
  run_tac Lean.Elab.Tactic.withMainContext do
    let some evidence := (← Lean.getLCtx).findFromUserName? `original | throwError "original prefix witness missing"
    let proof ← mapPrefix (← Lean.Elab.Tactic.getMainTarget) evidence.toExpr #[]
    (← Lean.Elab.Tactic.getMainGoal).assign proof
    Lean.Elab.Tactic.setGoals []


/-- Preserve the previous current-code interface and its exact prefix contract. -/
theorem entry_corresponds (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (abiLocal : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i)))
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
    (thirteenthDecoded : thirteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (fourteenthDecoded : fourteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 2 (16#16) 0 false false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding)
    (fourteenthFetched : fetch_inst (read_pc s.machine + 52#64) s.machine = some fourteenth.encoding) :
    Result initial ctxBlock ctxOfs k abiLocal addresses origins s fields (Arm64ProgramEntryCodeOrigin.current _) := by
  exact entry_with_code initial ctxBlock ctxOfs k abiLocal addresses ctxWord context values provider flags flagProvider vectors vectorProvider
      origins s native fields old reads first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
      imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded
      ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded noError firstFetched keepFetched
      thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
      thirteenthFetched fourteenthFetched
    (Arm64ProgramEntryCodeOrigin.current _)

/-- Bind both genuine successor BL/RET/continuation sites to the original
program anchor; actual fourteen-word admission supplies their target transport. -/
theorem original_code_entry (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (abiLocal : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i)))
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
    (thirteenthDecoded : thirteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (fourteenthDecoded : fourteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 2 (16#16) 0 false false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding)
    (fourteenthFetched : fetch_inst (read_pc s.machine + 52#64) s.machine = some fourteenth.encoding) :
    let control := Arm64ProgramEntryControlAdmission.admission s origins fields
      first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
      imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded
      seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded
      noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
      eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched fourteenthFetched
    Result initial ctxBlock ctxOfs k abiLocal addresses origins s fields (Arm64ProgramEntryCodeOrigin.original s origins fields control.1 control.2.2) := by
  have control := Arm64ProgramEntryControlAdmission.admission s origins fields
    first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
    imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded
    seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded
    noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
    eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched fourteenthFetched
  exact entry_with_code initial ctxBlock ctxOfs k abiLocal addresses ctxWord context values provider flags flagProvider vectors vectorProvider
      origins s native fields old reads first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
      imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded
      ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded fourteenthDecoded noError firstFetched keepFetched
      thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
      thirteenthFetched fourteenthFetched
    (Arm64ProgramEntryCodeOrigin.original s origins fields control.1 control.2.2)

end KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackControlEntry
