# Alignment-aware private stack representation

The generic candidate keeps the existing aligned64-bit qword route, uses native-width reads for aligned byte/word/dword addresses, and retains canonical little-endian byte assembly at every unaligned private-stack address. Both representations read exactly the same private bytes and preserve the architectural value. Memory accesses outside the private stack keep the existing instruction semantics.

Both existing private-stack route/lane host oracles pass under UBSan. The actual complete perf_unwind_stop source from batch000433 compiles through the revised representation; its previous8-byte access at offset-91 uses byte assembly. `observations.json` records exact case banners and source/object identities. The candidate remains captured as a whole-application trial.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/stack-aligned-width/Makefile check
```

`inputs.tar.gz` retains the candidate, actual generated C/BPF, commands, disassembly and both independent host tests. `checks.log.gz` keeps all outputs. Universal token and private-memory laws supply the safety interface; whole-application runtime receipts follow actual terminal requests.
