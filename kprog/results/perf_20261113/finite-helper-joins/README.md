2026-11-16T03:13:03Z

Cilium `tail_ipv4_policy` selects helper 23 (`bpf_redirect`) or 155 (`bpf_redirect_peer`) and tail-merges at CALL RAX +0x16bd. Singleton CFG provenance discarded this finite set and rejected the whole application.

Provenance now unions known helper values at CFG joins while an unknown incoming value still removes the fact. Proof mode retains the original register call. Installed code dispatches over proven numeric IDs into direct helper calls without changing argument registers or observed IDs. The existing helper ABI leaves condition flags unspecified. There is no new value-set cap or lexical guess. All LTO settings stay enabled.

Validation: 47 active Rust tests pass, one existing test is ignored. Actual Cilium production proof succeeds (7,365 bytes); its CFG records both helpers. A machine-code execution regression checks both branches, the zero argument and helper ID observed after the call. Existing unknown-path and call-clobber regressions pass. Raw attempts and logs: `/workspaces/kprog-raw/perf/20261116-finite-helper-joins`. Application load, B stock verification and timing follow the combined publication; no performance gain is claimed here.
