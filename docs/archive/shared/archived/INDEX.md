# Archived docs/tmp reports

These files were moved here because `docs/tmp/bpfopt_design_v3.md` is now the
only authoritative bpfopt-suite design.

| File | Reason |
| --- | --- |
| `bpfopt-design-review-20260428.md` | Conflicts with v3 by recommending daemon-only pass ownership and an internal daemon pipeline as the source of truth. |
| `bpfopt-pass-design-gap-20260429.md` | Conflicts with v3 by extracting daemon-owned policy, profiling, bytecode rewriting, per-pass verify, and REJIT as design requirements. |
| `bpfopt_design.md` | Superseded v1 design with public Rust API and daemon kernel-driver responsibilities now replaced by the v3 CLI/file pipeline. |
| `bpfopt_design_v2.md` | Superseded v2 CLI-first draft; v3 replaces its daemon orchestration model and expands the six-tool suite contract. |
| `daemon-bpfopt-status-20260428.md` | Superseded daemon/bpfopt status snapshot describing the pre-v3 daemon-centric runtime and duplicated pass implementation state. |
| `daemon-bpfopt-unification-20260428.md` | Superseded intermediate unification note where daemon still owns the live REJIT runtime, profiler, verifier callback, and pass pipeline. |
| `runner_business_logic_audit.md` | Superseded runner audit that treats daemon socket optimization, benchmark pass policy, and daemon profiling as active runner architecture. |
| `runner_complexity_analysis.md` | Superseded runner complexity report centered on the v1/v2 daemon socket and policy path rather than v3 CLI orchestration. |
| `runner_post_refactor_review.md` | Superseded post-refactor review that identifies `rejit.py` and `DaemonSession` as the v2 core interface. |
| `runner_python_audit.md` | Superseded Python audit recommending daemon-communication refactors instead of the v3 direct CLI/tool split. |
