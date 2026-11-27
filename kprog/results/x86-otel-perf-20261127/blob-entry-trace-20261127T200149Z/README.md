# Entry path diagnostic

The original native P and frozen-fact re-emission produced identical helper calls, network-order PID/PC mapping keys and return values in deterministic missing/present mapping paths. The actual captured linked blob was also executed through those early paths, with its per-CPU array ABI modeled on an isolated host thread. Mapping keys and returns matched; inline array/metric accesses and lowered tail failure explain the differences in callback logs.

This tests specific early paths only. The program-array was deliberately empty in the linked-code host model, so it does not test successful tail transfers or establish whole-program/guest equivalence. Intermediate missing-symbol failures and the initial unmodeled kernel-GS fault are preserved. They are host harness failures, not new application failures. The pending guest observer must resolve actual map targets/counters and path work before explaining the diagnostic ratio.
