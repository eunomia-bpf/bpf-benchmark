# Complete Tetragon C graph with static CALL edge copies

The private mechanical representation has17 static native CALL edge copies. Copied labels erase to the original native PC. CALL and RET retain the original numeric address, raw stack operations and shared return dispatch; local/cross-body/fallthrough edges preserve their original native-PC destinations. Operation bodies and native P remain the canonical ones.

Actual compiler observations are in observations.json. The exact complete event_execve native object SHA25675318ea561e4c3ae7820a52871288cf57bb60a4111628b9988384ff4aa81f304 and original map metadata accompany the archive. Canonical baseline measures17118BPF instructions/frame1280. Kernel stock-verifier and whole-application outcomes retain their own stages. Host regressions and native safety replays occupy separate receipts. Source adoption0; runtime admission additions0.
