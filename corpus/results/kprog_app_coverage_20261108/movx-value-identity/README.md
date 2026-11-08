# Generic MOVZX and MOVSX value identity

The shared register-extension handler carries its computed value through a pure compiler identity expression before native-width destination writeback. This preserves native register values, tags, flags and control flow while retaining a common value for repeated extensions.

The existing complete-state MOVX route oracle passes23761cases under UBSan. The complete original Tracee translation compiles successfully to3203BPF instructions. Every DWARF compiler-file checksum matches its captured source bytes; `observations.json` records the source/object hashes and stack-frame extent.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/movx-value-identity/run.sh
```

The archive contains the prior/candidate/diff, existing route-oracle source and executable, full Tracee generated C/BPF, compiler logs and exact compiler-file snapshots. It also captures the complete-application successor launch plan. That successor follows the current OTel cohort and the Cilium scalar-field trial, using original native bytes and the existing workload. Actual terminal archives supply verifier and runtime acceptance.

The current queued application profile uses [destination-width result identity](typed32/README.md): 23,761 complete-state checks pass and the complete Tracee translation compiles to 3,160 BPF instructions. Its 32-bit output keeps the checked byte and later index connected through the emitted register copies. The initial 3,203-instruction profile retains its captured source and measurement epoch.
