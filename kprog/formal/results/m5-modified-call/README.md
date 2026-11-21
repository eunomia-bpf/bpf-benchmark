# Actual complete modified scalar helper

`Arm64Modified.Call.execute` proves the actual five-argument helper for ordinary scalar GPRs/tag0/mod1/shift0 and W4/X8:119silent steps, consisting of actual entry+inlined read74, actual LSL0/width-mask loop41 and original outer exit/return/empty freeList4. It derives input/result/parameter observations from real table loads and exact source temp maps. Returned word is the actual W32 or X64 mask result; all memory and its frontier remain identical. Original CC.callCont handling and source return are retained.

`all_behaviors` proves every arbitrary relational finite execution is a silent prefix of that same unique terminal return at Kstop, and no infinite execution exists. No observed silence, callee-return/native-result or extra final-readback assumption is added. `return_bound` separately checks the actual4step exit/return.

Component237jobs and three public type/axiom queries passed CPU17/j1/32GiB/default caps/inherited logical+CompCert semantic axioms only. Exact hash/logs/timings/axioms are in validation.json. Scope is this actual helper's scalar W/X domain, not whole CMP or native instruction correspondence. Original caller flag_rhs/NZCV/source-native six-call composition remain next. M5/O1/O2/O4/M6 open/families0; no runtime application or measurement.
