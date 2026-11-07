# Native IMUL and XCHG against the published reference

All 16 existing IMUL/XCHG forms agree across the real x86-64 CPU, production
C simulator and V's canonical native-byte reference on 16,384 states.
Each form has 1,024 cases. No production code changed in this experiment.

| Family | Forms | Cases | CPU/C differences | CPU/reference differences | C/reference differences |
| --- | ---: | ---: | ---: | ---: | ---: |
| IMUL, register source | 3 | 3,072 | 0 | 0 | 0 |
| IMUL, memory source | 3 | 3,072 | 0 | 0 | 0 |
| IMUL, immediate with register source | 3 | 3,072 | 0 | 0 | 0 |
| IMUL, immediate with memory source | 3 | 3,072 | 0 | 0 | 0 |
| Register XCHG | 4 | 4,096 | 0 | 0 | 0 |

`forms.tsv` and `reference-forms.tsv` hold every form/count. IMUL covers
16/32/64-bit widths; XCHG covers 8/16/32/64-bit widths. The harness's 42
existing auxiliary observers also pass 43,008 CPU/C cases: 36 Jcc, JMP,
CALL and four REP MOVS blocks. Those observers were not replayed against
the reference here. Total CPU/C coverage is 58 forms and 59,392 cases.

The existing deterministic boundary/random stream cycles all 64 arithmetic
flag inputs. Comparisons include all 16 GPRs, XMM0, 64 stack bytes and
256 external-memory bytes. IMUL's defined CF/OF are compared; undefined
flags are excluded by the existing architecture-specific masks. XCHG must
preserve all six arithmetic flags. Memory-source requests use the actual
input bytes/addresses and compare all final bytes, faults, and next PC.
No additional instruction semantics are implemented in the serializer.

Both production and canonical snapshots are exact published revision
47de9665d, including V's signed multiply reference and earlier XCHG step.
Every production source in `production-files.json` was byte-checked against
that commit. This excludes C's concurrent SP prototype. Frozen sources,
generated CPU code, static CPU binary, reference executable and complete
logs are retained. The compiler emitted literal-immediate shift warnings
from existing macro branches; the full diagnostics are preserved in
`run.log.gz`. Compilation, CPU execution and canonical replay all exit 0.
No complete ISA or whole-program safety closure is claimed by this family
increment.

Commands from `/workspaces/repository`, through bws.sh:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-multiply-xchg build cpu reference
```

The recipe uses a new `fresh-run/` directory; set OUT to another absolute
path for a subsequent run. Canonical source/build log and `reference.gz`
are included. This run's raw trace is deleted after summary publication
and a no-reader check, per coordinator disk instruction. Its hash/size are
in `trace-retention.json`. Subsequent CPU execution generates a fresh run,
whose addresses can differ; it does not replay retired exact states.
