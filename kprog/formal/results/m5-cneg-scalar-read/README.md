# CNEG scalar-reader composition

The original CNEG branch's eight-step call entry now composes with the
existing linked Clight reader and its genuine four-step return/value copy.
Tag0 executes 85 transitions; tag4 executes 103 and uses the reached warm
stack-origin cache. Both paths retain the exact full memory, environment and
pending condition/numeric/writer continuations. The actual CNEG operand equals
the existing M3 materialization of the original raw word and tag. All nine
original input temporaries and the computed width retain their observations.

The observations are actual pre-memory GPR loads. This component requires a
Vlong word with tag0 or tag4 and the selected warm cache for tag4; it does not
coerce arbitrary represented Vptr values into integers. Deriving those scalar
observations from the complete seven-call fixture prefix remains a separate
composition obligation. Top-level CNEG dispatch, condition/numeric body,
scalar writer, generic allocation/free and eighth source/native prefix remain
open. No root integration or whole-build/make-check success is claimed here.

Focused build251 and three public type/axiom queries pass at the original
200000-heartbeat/512-depth caps on CPU17, one worker, 32GiB and shared timing
lock. Initial attempts retained an unrecognized simplifier name and exposed
that the standalone export environment must not be unified with the original
linked caller environment. The accepted proof reuses the existing world-bound
reader/layout theorems directly; the remaining false-conditional normalization
is explicit. No caps, semantic premises or reader implementation were changed.
The return4 and ready statements also pass in the same focused module.

Axioms are standard logic plus the inherited CC.externalFunctionsSem and
CC.inlineAssemblySem for imported Clight execution. Previous DIV full-check
failure remains in V's receipt; V owns the next whole confirmation. M5, O1,
O2, O4 and M6 remain open, completed ISA families0.
Raw: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
