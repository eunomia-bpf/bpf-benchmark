# Generation-bound load-time attribution and scanner fix

The archived run's reported medians are reproduced exactly by taking each
benchmark's median over its 15 samples, then the median across 29 benchmarks:

| Phase | Median of benchmark medians, ms |
| --- | ---: |
| Kernel object open/load total | 1.869295 |
| Generation-bound native load total | 116.191654 |
| Companion lookup specification | **107.020773** |
| Companion + proof open/load block | 4.986088 |
| Proof verifier load, inside that block | 2.528611 |
| Native stub program load | 2.549634 |
| Native-link cache lookup | 0.087154 |
| Blob upload | 0.057808 |
| Native-link output read | 0.023321 |
| Native-link subprocess | 0 |

Source: `micro/results/x86_kvm_micro_20260909_121208_577260/metadata.json`.
There are 435 samples per runtime. `samples.csv` retains their phase values;
`phase-medians.json` records the aggregation. Medians of different phases are
not additive; proof verifier time is nested inside the companion/proof block.
No raw benchmark output or summary logic in the framework was changed.

The large lookup phase calls `kallsyms_lookup("this_cpu_off")`, which initializes
`kallsyms_table()`. The old scanner uses `sscanf` to parse every kernel symbol,
then linearly compares its name against every requested helper/runtime/map
symbol. Optional or duplicate requested names can prevent its early stop.
Thus a pure-compute program still pays this scan, even with a warm native-link
cache. The linker and kernel upload are not the missing 100 ms.

The loader fix uses an unordered set of string views, removes names as they
are found, and parses a numeric address only for a requested name. It retains
first-definition behavior, deduplicates requests, and reports malformed records
and read/parse failures. It introduces no persistent cache or stale-address
reuse. `test_kallsyms.cpp` compares the production scanner's complete output
against an independent stream parser of the real `/proc/kallsyms`; all 109
present requested symbols agree in both name and address.

Validation:

```sh
taskset -c 16-23 make -C kprog/libnativeloader BUILD_DIR=build-fidelity
taskset -c 16-23 make -C kprog/fidelity check-loader-kallsyms
python3 kprog/results/kprog_fidelity_20261106/load-time/analyze.py
```

The isolated static/shared library build and symbol comparison passed.
`loader-build.log.gz` and `symbol-check.log.gz` retain the output. These checks
establish symbol lookup preservation, not an after-fix timing result.
Lane R owns timing; the exact root `make micro` reproduction command is under
"Timing requests" in COORDINATION.md. Its after-fix run must rebuild the runner
and runtime image from the fixed loader. The performance confirmation remains
an active item until that result arrives; it must not use an old statically
linked runner or claim the old result measured this patch.

## Repeat and elimination of the remaining pure-program scan

Lane R completed the same15-sample simple workload with the faster scanner:
`micro/results/x86_kvm_micro_20261106_101146_092448/metadata.json`.
Native load is46.076ms median (45.656–49.000), including45.240ms in
`companion_lookup_spec_ns`; proof verifier load is0.058ms. Kernel object load
is0.216ms. This is a single workload and must not be ratio-compared with the
older29-benchmark median. `simple-after-scanner-samples.csv` retains every
phase; `simple-after-scanner-phases.json` gives medians/ranges from those15
samples. These analyses are outside framework raw result generation.

The scanner fix preserves symbols but still eagerly scans the entire table
for the optional helper catalogue. The second fix classifies actual needs:
source helper calls, proof CALLs, undefined native symbols and perCPU maps
retain the resolver; unbound loads retain their existing behavior. Pure bound
programs without these requirements skip the catalogue, and the diagnostic
link summary no longer triggers a new scan for an absent perf-event helper.
Fixed ABI offsets and map/link handling remain active.

The isolated loader build and updated real-kallsyms regression pass. The new
pure-link test rejects any callable or CPU-address catalogue entry, catching
accidental restoration of the eager resolver. All13 freshly compiled
helper/map proofs pass the actual bound KVM path again (see
`../helper-map/x86-symbol-guard/`), including perCPU cases. Full logs are
`loader-symbol-guard-build.log.gz` and `pure-symbol-regression.log.gz`.
Lane R has the same15-sample root command for measurement after rebuilding
from this second fix; no after-second-fix timing is inferred yet.

Proof-call classification follow-up: local BPF subprogram calls no longer
request the optional kernel catalogue; actual helper/kfunc calls and empty
proofs retain it. Five boundary regressions, pure-link regression and independent
114-symbol name/address comparison pass. See local-proof-calls/README.md.
This fix has no timing claim; the pending pure simple15 repeat remains separate.
