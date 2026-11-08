# Generic typed private-stack representation

The captured generic simulator uses exact-width volatile private-stack union members for aligned8/16/32-bit accesses, preserving the qword pointer route and the unaligned byte ladder. Scalar32 register reads and LEA arithmetic expose native zero extension; explicit RSP displacements remain visible to the compiler. The profile includes the published MOV_LOAD signed-stack/RSP fidelity correction.

The completed checks compare184320stack BPF-JIT/UBSan-host/independent-byte observations,655360register-read observations and163840LEA/CMP hardware/BPF-JIT/host/integer observations. Existing route/lane controls cover117782and1401654cases. The MOV memory-frame oracle covers3657728real-CPU/UBSan cases plus2432live-XDP-RSP cases;713MOV routing controls also pass. Every check completes with matching outputs.

All four complete original generated sources compile successfully. Their instruction/frame measurements and every DWARF source checksum appear in `observations.json`; exact compiler-file snapshots join the source/object hashes. Tetragon event_execve continues to require a larger compiler frame, preserving that open whole-application frontier. Whole OTel, Tracee and Tetragon trials run serially with this captured profile and the original native inputs/workloads.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/stack-typed-volatile-current/run.sh
```

`component.tar.gz` captures the exact before/candidate/diff, source/input epochs, BPF and host binaries, independent oracles, command logs, full generated sources, completed compiler measurements and compiler-input snapshots. Universal simulator/token laws retain their common ownership; whole-application verifier and timing receipts follow their actual outcomes.
