# CNEG/GE preparation — not yet checked

The next operation in the original fixture is CNEG X6,X5,GE. The proposed
caller proof extracts the actual successor of afterSelect, binds all nine
arguments (opcode 65, destination 6, source 5, two signed 255 sentinels,
width 8, condition 10 and immediate 0), and resumes the original successor.
The native proof binds the LNSym CSNEG X6,X5,X5,LT alias, including its actual
condition inversion, register write, PC advance, event history and fault state.
No independent ISA executor or runtime source is added.

These two modules and the seven public queries are **unverified work in
progress**. The focused command reached only the shared timing-lock waiter;
no Lake/Lean child started while the frozen rotate held the exclusive lock.
The lane ended that unstarted waiter for batching and retained its raw log.
No build success, query success, new refinement coverage or family completion
is claimed. The accepted predecessor remains the seven-call CSEL prefix.

Next, under the shared timing lock, CPU 17, one worker and 32 GiB, run:

```sh
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryCnegCall KProgFormal.ClightRefinement.Arm64CnegNative
lake env lean -j1 results/m5-cneg-preparation/Query.lean
```

Use the raw run.py wrapper to apply those resource limits and write fresh
terminal results. Original 200000-heartbeat and 512-depth limits stay in force.
Then prove the actual Clight GE condition helper and numeric CNEG reader/body,
retaining the reached source-5 scalar/stack-origin observations. Generic frame
allocation/free, eighth source/native composition and default-root integration
remain pending. V retains sole whole-build/make-check confirmation ownership;
its previously recorded DIV fault/assume(false) failure is unchanged by these
proof drafts. M5/O1/O2/O4/M6 remain open; completed ISA families: zero.

Raw: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
