# Exact readonly values in x86 memory loads

The private component represents loads from a known immutable native object by a finite C dispatch over its original bytes. Each case returns the same little-endian value at the same offset and width. A compile-time base-identity choice selects the object; the remaining addresses execute the original raw memory load. Native register values, flags and control flow retain their meanings. The canonical simulator and generator retain their published sources while the whole-application measurement runs.

| Measurement | Result |
| --- | --- |
| Host native-byte comparisons, UBSan | 18,650 reads; 0 differences |
| Widths and address domains | 1/2/4/8 bytes; every valid offset; shifted aliases; two distinct objects; accessible bytes beyond the constant extent; mutable memory |
| Captured whole Tracee `sys_exit_submit` compilation | make exit0; 11,445 BPF instructions |
| Existing29positive+1negative-native compiler batch | make exit0; 30 completed rows |
| Whole Tracee startup and workload | [terminal original-application receipt](whole-tracee/README.md) |

The earlier whole Tracee cohort reaches `bpf_probe_read` with an unbounded R2 after4310instructions/140states. The stock verifier reads an unknown u32 from the immutable80-byte table through a dynamic offset. This component preserves the exact bytes as finite C values. The function covers every starting offset and legal width, including unaligned reads. Its raw operation also preserves the original address behavior outside those cases.

Reproduce the captured compiler and byte observations using the archived Makefile and sources:

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/readonly-values/Makefile host component
```

`component.json` records the source/object identities and section size. `candidate-inputs.json` records the frozen compiler inputs and their repository epoch. `component.tar.gz` holds the C representation, generator experiment, source snapshot, actual object, commands, complete outputs and the initial fixture quoting diagnostic with its corrected run. The existing29positive+1negative-native compiler batch precedes the entire original Tracee application with its existing native7479850e input, workload and paired five-step runtime. Universal O1/O2 and readonly-link preservation remain laneV responsibilities; these component observations and the full-application receipt retain their own measured domains.

Compiler provenance: the initial30-row micro batch uses the canonical header because `run_micro_sim_batch.py` invokes literal `clang`. Its original commands and outcomes remain in `micro-canonical.log`/`.exit`. The private candidate batch uses a PATH-resolved wrapper and retains every rewritten source under laneC; its detached receipt follows. The captured full Tracee component uses the private header explicitly, and the generic emission candidate produces the same executable BPF bytes.

The generic generator integration candidate compiles the captured source with byte-identical executable BPF sections to the measured representation. `adoption-component.json` records both section hashes and `adoption-compiler.tar.gz` retains its source, patch and compiler observation. Canonical source adoption follows the complete application outcome and the shared generic proof work.

The PATH-routed private micro batch completes with make exit0 and30 result rows. `candidate-micro.json` records the actual object/source hashes and compiler DWARF directory observations; `candidate-micro.tar.gz` retains both compiler domains, source derivatives, objects and complete outputs.
