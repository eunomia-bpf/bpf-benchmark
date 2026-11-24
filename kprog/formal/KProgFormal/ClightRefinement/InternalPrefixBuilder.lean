import Lean
import KProgFormal.ClightRefinement.InternalExecution

namespace KProgFormal.ClightRefinement.InternalPrefixBuilder

/-- Untrusted elaborator output: the caller embeds the proof into its own
original-source certificate, and Lean's kernel checks that complete term. -/
structure Built where
  count : Nat
  output : Lean.Expr
  continuation : Lean.Expr
  proof : Lean.Expr

/-- Construct a silent prefix to one specified original statement using the
EXISTING Clight doStep and soundness theorem. No interpreter, semantics or
logical axiom is added. Unknown successors, other callees, changed memory
and incompatible source boundaries fail instead of manufacturing a path. -/
def buildTo (world initial originalHandler target originalEnv originalMem : Lean.Expr) : Lean.Meta.MetaM Built := do
  let silent ← Lean.Meta.mkAppM ``CC.E0 #[]
  let mut current := initial
  let mut frames : Array Lean.Expr := #[]
  while true do
    let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
    unless state.isAppOfArity ``CC.State.State 6 do throwError "source prefix left an internal statement state"
    let args := state.getAppArgs
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf args[1]!)
    if ← Lean.Meta.isDefEq stmt target then
      unless ← Lean.Meta.isDefEq args[0]! originalHandler do throwError "source prefix changed function"
      unless ← Lean.Meta.isDefEq args[3]! originalEnv do throwError "source prefix changed local environment"
      unless ← Lean.Meta.isDefEq args[5]! originalMem do throwError "source prefix changed memory"
      let mut proof ← Lean.Meta.mkAppOptM ``InternalRun.refl #[some world, some current]
      for transition in frames.toList.reverse do
        let transitionType ← Lean.Meta.inferType transition
        let restType ← Lean.Meta.inferType proof
        unless transitionType.isAppOfArity ``CC.Step 5 && restType.isAppOfArity ``InternalRun 4 do
          throwError "source prefix transition/certificate type changed"
        let stepArgs := transitionType.getAppArgs
        let restArgs := restType.getAppArgs
        proof ← Lean.Meta.mkAppOptM ``InternalRun.step
          #[some world, some restArgs[1]!, some stepArgs[2]!, some stepArgs[4]!, some restArgs[3]!,
            some (Lean.mkConst ``True.intro), some transition, some proof]
      return ⟨frames.size,args[4]!,args[2]!,proof⟩
    if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
      throwError "original source prefix selected a different callee"
    let application ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf application)
    unless result.isAppOfArity ``Option.some 2 do throwError "original source prefix has no executable successor"
    let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
    unless pair.isAppOfArity ``Prod.mk 4 do throwError "original source successor changed shape"
    unless ← Lean.Meta.isDefEq pair.getAppArgs[2]! silent do throwError "source prefix emitted a trace"
    let successor := pair.getAppArgs[3]!
    let equation ← Lean.Meta.mkEqRefl result
    let transition ← Lean.Meta.mkAppM ``CC.doStep_sound #[world,current,silent,successor,equation]
    frames := frames.push transition
    current := successor
  throwError "source prefix ended without its target"

/-- The existing caller interface retains its specified Scall target and
rejects every earlier different call. Both interfaces use the same kernel
proof construction and the unchanged imported transition semantics. -/
def build (world initial originalHandler target originalEnv originalMem : Lean.Expr) : Lean.Meta.MetaM Built := do
  let targetShape ← Lean.Meta.withTransparency .all (Lean.Meta.whnf target)
  unless targetShape.isAppOfArity ``CC.Stmt.Scall 3 do throwError "expected original source Scall target"
  buildTo world initial originalHandler target originalEnv originalMem

end KProgFormal.ClightRefinement.InternalPrefixBuilder
