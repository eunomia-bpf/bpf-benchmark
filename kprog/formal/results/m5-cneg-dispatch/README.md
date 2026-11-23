# Actual CNEG dispatch

The source identity decomposes the original generic handler loop into its
width call and the first nine actual gates, with the ninth gate selecting
the original CNEG branch. The rest of the source stays as its original
alternative. The proof executes the real linked width helper and dispatch
conditions for opcode 65 and width 8.

The constructed prefix has four entry/call transitions, six callee
transitions and 69 return/dispatch transitions, totaling 79. The public count
is existential. It retains the entire heap, caller environment and original
eight argument observations, and exposes the computed width and actual
pending outer-loop continuation.

Focused build 257 and two public type/axiom queries pass at original proof
caps (200000 heartbeats, depth 512), CPU 17, one worker, 32 GiB and shared
timing lock. The code reuses the proven Clight width semantics and original
source decomposition pattern. Standard logic and inherited external-function
and assembly assumptions appear in the axiom query.

The next component composes this real dispatch with the accepted CNEG path
and outer-loop exit. Generic allocation/free and the original eighth call
and native step follow in M5. V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
