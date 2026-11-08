# Destination-width MOVZX and MOVSX value identity

The generic register-extension handler uses a 32-bit compiler result for a 32-bit destination and a full-width result for other destinations. Its source extension, native-width writeback, tags, flags and control flow retain their existing values. The four-line increment preserves the actual destination width through the pure compiler identity.

The existing complete-state MOVX route oracle passes 23,761 cases under UBSan. The complete original Tracee translation compiles to 3,160 BPF instructions with deepest direct frame offset -304. Every DWARF compiler-file checksum matches its captured source snapshot.

The resulting bytecode checks one masked byte in w1 and copies that value into w4 for subsequent use. The earlier compiler profile carries a 64-to-32 shift pair between those uses. The full assembly and both source representations are archived. Complete application loading supplies kernel acceptance and runtime evidence.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/movx-value-identity/typed32/run.sh
```

The queued whole-Tracee cohort adopts this completed profile before its initial application/source capture. Its original native ELF hash, narrow-read header, upstream workload, module and paired loader retain their captured identities. `component.tar.gz` includes the exact source/object/logs, compiler files, old queued header and adoption record.
