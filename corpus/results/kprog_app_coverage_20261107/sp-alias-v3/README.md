Retired diagnostic candidate; canonical SP work is owned by F. This is compressed historical counterexample/source evidence, not an active alternative implementation.

# Private copied-stack-address extension

This candidate extends the published direct-SP increment to numeric observations of copied STACK-tag addresses and narrow LEA. It keeps the typed memory pointer for memory operations, while numerical reads use the existing ABI2 NUMERIC pointer view and entry stack base. Native-address truncation occurs after materialization.

Four real CPU MOV/LEA forms,4entry bases,1024offset cases each:16,384checks,0candidate differences; the published header differs in11,264. The first before build omitted the stack-enable predefine and is retained separately; the corrected before build fixes that fixture setup. No native stack or unsafe memory is executed by the oracle.

This is **private and unpromoted**. Partial writes, pointer spills and subsequent pointer arithmetic still need the complete representation and regression checks. No FULL or verifier/bound-application claim is made for this extension. Exact before/candidate headers, generated contracts, CPU source and logs are in `private-source-and-cpu.tar.gz`; `candidate.patch` is for review/replay only. Production currently contains only the earlier direct-SP increment.
