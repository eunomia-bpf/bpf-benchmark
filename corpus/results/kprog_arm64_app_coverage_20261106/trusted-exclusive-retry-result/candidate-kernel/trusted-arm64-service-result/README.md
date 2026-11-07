# Private ARM exclusive-convergence candidate admission diagnostic

Completed 9/9 cases. All commands were load-only (`argc=3`); native executions: zero. Stages: `{"accepted_load_only": 2, "loader_rejected": 1, "verifier_rejected": 6}`. Negative fixtures accepted at load: `[]`. This is a diagnostic result, not a safety pass; the broad candidate is not adopted.

The two private retry fixtures are admission positives only. Four memory-safety negatives examine delayed failure/success branches and pointer state; the marker-free infinite loop and two marker-bearing cycles examine termination policy. The marker-bearing fixtures contain syntactic BPF exits so the loader no-exit check alone cannot establish rejection. Original per-case commands, native bytes, generated proofs, compiler/verifier logs, source identities and exact kernel build inputs are retained. `admission-review.json` records incomplete or unexpected outcomes explicitly.

Host reported ok: `False`; guest exit: `0`. Host ok means the diagnostic finished, irrespective of findings. Native identity errors: `[]`. Archive `run-20261107T173627261151Z.tar.gz`, SHA256 `aec599921ac9410fd8ceddf3cf384472fe09203f74e6317c2fecc64b8dc014a1`. Shared canonical kernel and modules were not replaced: the guest used the namespace-private incrementally built candidate. No O3/termination or six-application completion claim follows.
