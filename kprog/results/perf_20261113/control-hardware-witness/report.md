# Hardware inputs for finite x86 control observations

2026-11-15. Sources ac64269b7 / 86237b0cd / 7c9d57c48; analysis
55ed52e4e. The prior explicit-zero environment produced 4,864 mismatches
among 8,960 cases. These were released stack bytes, not register, vector,
ISA-defined flag or external-memory differences. This experiment supplies
the released bytes through the existing environment-input interface.

The parent traces its own native observer with hardware execution breakpoints
and single-steps the unchanged instruction body. At each upward RSP transition
it reads the released bytes immediately from hardware memory, before any
simulator execution. A shared memfd carries the ordered words. The model uses
the production header's input entry; missing, extra or unconsumed body words
fail explicitly. Initialization choices are explicitly zero and subsequently
overwritten by the driver's complete input state. The final implementation
rejects unspecified draws outside initialization/body phases.

The 35-form smoke run passes. Both the initial full run and the final lifecycle
run pass **8,960 cases with zero mismatches**, including nested direct/indirect
CALL, finite target choices and reading the stack return address. The final
run supplies **5,376 hardware release words**. Separate raw-data analysis checks
that every event was a native RET, released exactly its eight-byte return
slot, supplied that RET's actual target, and agrees with the hardware bytes
at final observation. All 35 native instruction spans and addresses match
the earlier zero-input recording. All 4,864 earlier counterexample identities
are exercised in the passing corpus.

The existing comparator is unchanged: every register, vector and private
stack byte, external-memory output and ISA-defined flag bit is compared.
The complete raw flags remain recorded (native/simulator XOR 0x202 throughout
the final run, outside the existing arithmetic-flag mask 0x8d5). The tracer
clears its TF/RF debug machinery before returning to the original observation
wrapper. It installs no child signal handler and patches no instruction byte.

This constructs hardware input witnesses for this finite corpus. It does not
prove every environment choice, full ISA coverage, AST correspondence or
M4–M6. The parent host-input/formal task remains open. Production P, shared
headers, B compilation, optimization flags and all LTO are unchanged. No
performance number or application acceptance follows from this experiment.

Reproduce from the single checkout (reuse the canonical build):

```sh
make -C kprog/fidelity x86-control-run CASES=256 \
  X86_CONTROL_OUT=/workspaces/kprog-raw/perf/20261115-control-witness/lifecycle
make -r -f kprog/test/native-relocations.mk control-hardware-witness \
  CONTROL_WITNESS_RUN=/workspaces/kprog-raw/perf/20261115-control-witness/lifecycle \
  OUTPUT=/workspaces/kprog-raw/perf/20261115-control-witness/lifecycle-analysis
```

Recorded runs used setsid/nohup, CPUs16–19 and an 8GiB address-space bound;
analysis used 2GiB. No guest, timing or image lock was needed. The OTel frontend
continued separately on CPUs8–11. Raw commands, logs, timestamps, measurements
and source identities stay in `/workspaces/kprog-raw/perf/20261115-control-witness`.
Both full raw CPU recordings and hardware event streams are losslessly
archived here; no executable or generated compilation product is archived.
`raw-manifest.json` binds the persistent files. Previous results are preserved;
canonical control build products were replaced in place (cleanup log/manifest).
