# Project decisions moved from the server manager

These records were moved from the server-manager repository (spark-manage, `docs/configuration-decisions/`) on 2026-11-14 under the operator rule "尽可能检查都是在 workspace 里面, 除非需要跨 workspace; workspace 里面的规则不能扩散到别的地方, 也不需要 servermanager 里面记录." Each file is the unchanged record as it stood there; spark-manage keeps only the infrastructure facts and the operator's verbatim words.

- 2026-09-06: [BPF benchmark devcontainer and Codex continuation](2026-09-06-bpf-benchmark-devcontainer-and-codex.md)
- 2026-10-01: [BPF benchmark duty prioritizes NativeSim proof](2026-10-01-bpf-native-sim-priority.md)
- 2026-10-09: [Katran/Cilium native rerun driven from the lab host, measured on AWS](2026-10-09-lab-host-katran-cilium-aws-rerun.md)
- 2026-11-05: [BPF NativeSim duty no longer edits papers](2026-11-05-bpf-kprog-no-paper-edits.md)
- 2026-11-05: [BPF NativeSim duty reproduces the early native numbers first](2026-11-05-bpf-kprog-reproduce-native-numbers.md)
- 2026-11-06: [kprog hourly check, R redirected to the reproduction, Workspace disk freed](2026-11-06-bpf-kprog-hourly-check.md)
- 2026-11-06: [kprog Codex lanes moved from the Workspace to the local Codex](2026-11-06-bpf-kprog-local-codex-lanes.md)
- 2026-11-06: [kprog paper push: three lanes in bpf-benchmark-dev, split by CPU](2026-11-06-bpf-kprog-parallel-lanes.md)
- 2026-11-06: [kprog: performance numbers first, self-imposed requirements removed](2026-11-06-bpf-kprog-performance-first.md)
- 2026-11-06: [kprog push widened: six apps on the verified path, O1-O4 end to end, six lanes](2026-11-06-bpf-kprog-six-lanes-complete.md)
- 2026-11-07: [kprog: lane R commits named paths, not the shared index](2026-11-07-bpf-kprog-r-commit-paths.md)
- 2026-11-07: [kprog: lane R moves from reproduction to the verified arm](2026-11-07-bpf-kprog-r-verified-arm.md)
- 2026-11-07: [kprog: lane R times an application once lane C reports it bound](2026-11-07-bpf-kprog-r-wait-for-c.md)
- 2026-11-08: [kprog: performance work starts ahead of the six-application milestone](2026-11-08-bpf-kprog-performance-first.md)
- 2026-11-08: [kprog: lane R ports the kernel BPF selftests and measures performance attribution](2026-11-08-bpf-kprog-r-selftests-profiling.md)
