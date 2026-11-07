# Real x86 CPU differential coverage for POPCNT memory operands

The existing1077-form matrix covers register POPCNT but not the supported
POPCNT_MEM path. Add16/32/64-bit memory-source forms through the same native
assembler, production encoder/macros, native observer and canonical reference.
No production simulator, ISA semantics or helper/memory safety policy changes.

```sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=x86
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-popcnt-memory/Makefile reference
```

The detached incremental build and real-CPU/canonical replay completed.
The preceding 1077 forms are retained. ARM hardware validation remains
separate; its core807 and control101 static handoffs are available.

## Completed result

The incremental build and canonical replay both exited 0. All **1080 forms**
ran **1024 cases each (1,105,920 states)** on the real x86-64 host CPU.
CPU versus production C, CPU versus the frozen canonical reference, and C
versus that reference each have **zero mismatches**; zero forms are unavailable.
The three new memory-source POPCNT forms (16/32/64-bit) each have 1024 cases
and zero differences. The preceding 1077 assembly/opcode rows are unchanged.

`forms.tsv` and `reference-forms.tsv` hold every form's exact count.
All three compressed mismatch/unavailable JSONL streams are empty. Any
mismatch would have included its register/flag/vector/stack and memory inputs
in those streams. `summary.json` records the complete trace size and SHA;
the original 2,008,350,744-byte state trace was removed after all replay
readers closed, as recorded below.
`compiled-inputs.json` and its independently checked archive preserve the
actual production-header/encoder snapshot, generated assembly/C and observer
inputs. `pins.json` identifies the static executable and the same c110b03a
canonical executable used by the preceding 1077-form replay; the exact static
x86 executable is compressed here. Later production edits do not change this
captured source attribution.

The native observer compares architectural registers, defined arithmetic
flags, vectors, stack bytes and data-memory writes. The reference adapter
uses canonical instruction steps and finite paths for existing branch/call
observers. This matrix does not replace the separate SP observer results,
helper/service safety suites, real ARM hardware runs, invocation/ABI/platform
transport proofs or universal O1–O4 obligations. No production simulator or
canonical semantics changed for these three additional forms.

## Raw trace cleanup, 2026-11-07

At the coordinator's explicit disk-cleanup request, the closed
`cpu-states.bin` (2,008,350,744 bytes, SHA256
`a6ee4572cdad33fa9c8c1d80449cd32f991888d8734f35dc46b7a99f92be3407`) was deleted after checking every
visible process's file descriptors and mappings: no users or inaccessible
processes. The summary and per-form tables were already committed and
published. Static executables, compiled input archives, logs, counterexample
streams and incremental build caches remain. Regenerate the trace with the
recorded run command before any future `--reuse-trace` replay.
