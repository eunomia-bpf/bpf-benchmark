# Complete original CNEG64 GE handler body

Body.execute starts at the actual generic handler body, runs the linked
width helper and original dispatch, executes scalar or warm-stack reading,
GE condition evaluation, width-8 arithmetic and genuine word/tag stores,
and leaves the actual outer loop in the original caller continuation.

Its premises are the reached pre-memory word/tag, selected cache, flag
representation, storage rights and actual source-call arguments. Every
intermediate helper result and post-memory state is derived. The output
retains all eight original argument observations and includes the actual
writer certificate with typed readback, caller frame, access and frontier.
Generic allocation/free and full native register matching are the next
composition steps, followed by the complete eighth source/native call.

Focused build 258 and one public type/axiom query pass at the original
200000-heartbeat/512-depth limits, using CPU 17, one worker, 32 GiB and shared
timing lock. The axiom query records standard logic and the inherited
external-function/assembly assumptions. The body composes existing proven
components and two ordinary Clight outer-loop exit transitions.
V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
