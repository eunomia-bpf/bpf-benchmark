# Generic narrow read value identity

The generic private profile represents8/16-bit register reads with exact C unsigned-width casts. Its32-bit zero extension,64-bit route and high-byte shift retain their existing semantics. This lets the compiler share repeated reads and idempotent masks across native comparisons and subsequent uses.

Ten width/lane forms match BPF-JIT, UBSan host and independent byte results across655360observations. The complete original Tracee source compiles successfully; instruction/frame values and every DWARF compiler-file checksum appear in `observations.json`, with exact source/object hashes and snapshots in `component.tar.gz`.

The actual whole-Tracee predecessor reaches an80-byte table after checking a byte index against15. Redundant masking on the comparison copy separates its verifier scalar ID from the indexed value. This candidate preserves native operations and bounds while changing their C representation. Complete Tracee replay follows the current serial Tetragon, native-only safety and Cilium cohorts; the OTel host-compiler successor follows that Tracee replay.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/narrow-c-mask/run.sh
```

The archive captures before/candidate/diff, generic controls, BPF/host objects and bytecode, completed logs, the full original generated source and compiler inputs. Whole-application verifier results remain a separate outcome domain.
