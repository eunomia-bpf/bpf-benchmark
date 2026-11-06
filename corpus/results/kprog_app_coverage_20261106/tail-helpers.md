# External helper tail jumps

An actual captured coarse-clock startup probe exposed a native-link bug: the
unresolved external JMP shrank from rel32 to rel8 during proof encoding while
the ELF relocation still described a four-byte field. Its helper operation
and return value disappeared from the proof. The earlier specialization
failure is preserved in `coarse-tail-first-failure.log`.

Native-link now canonicalizes external helper tail jumps into a helper CALL
and a fragment return before encoding. Entry returns use the existing BPF
fragment epilogue; subprogram returns remain RET. Direct, GOT and finite
helper-register targets retain their identity. Code-target jumps keep their
existing path. Numeric helper160 resolves to the public coarse-clock helper.
A known external-helper jump has no local successor in the callee analysis;
unknown incoming paths remain conservative and cannot borrow a known ID.

Validation:

- All69 Rust tests pass. The immutable full formal check passes on the prior
  checked helper export with committed native-link sources plus only this
  x86 change; it includes no other lane's uncommitted ISA changes.
- Four actual ELF forms (direct PLT, GOT, numeric160 and a subprogram tail
  jump) produce valid CALL relocation fields, generate and compile proofs.
- Each form passes the real six-load libbpf object startup for source flags0
  and8 using the production strict shim and published attachment-aware loader.
  Every successful startup load is replaced; the main executes with generation1
  and return127 in all eight controls.
- A path with an unknown target joining a known helper ID fails specialization
  with `unresolved finite indirect target`. Its native code is never executed.

```sh
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk link-build test-link tail-build tail-negative tail-kvm
make -f corpus/results/kprog_app_coverage_20261106/readonly-layout.mk formal RO_SOURCE=/workspaces/.agent-state/kprog-lanes/C/tail-check-source
```

`tail-helper-artifacts.tar.gz` retains exact native/proof/SIM inputs, ELF
relocations, disassemblies, fresh bound-startup logs and frozen native-link
sources. This repair establishes the tail-call lowering on the generation-bound
path; full six-app coverage and matching-work timing remain unfinished.
