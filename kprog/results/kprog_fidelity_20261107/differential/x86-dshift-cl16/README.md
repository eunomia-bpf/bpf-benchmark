# 16-bit SHLD/SHRD CL fidelity

The real x86-64 CPU, production C simulator and V canonical reference agree on
16 native CL-count forms through both raw and direct APIs. All 32 route/form
groups complete 32,768 shared-state observations with zero differences and zero
forms awaiting reference.

| Operation | Width | Route | Forms | Cases | CPU/C/reference differences |
| --- | ---: | --- | ---: | ---: | --- |
| SHLD | 16 | raw | 8 | 8,192 | 0 / 0 / 0 |
| SHLD | 16 | direct | 8 | 8,192 | 0 / 0 / 0 |
| SHRD | 16 | raw | 8 | 8,192 | 0 / 0 / 0 |
| SHRD | 16 | direct | 8 | 8,192 | 0 / 0 / 0 |

Each operation covers distinct registers, the same register, CX destination,
CX source, CX in both positions, SP destination, SP source and SP in both
positions. Both value operands and CL use the actual prestate. Each group
observes every architecturally defined count 0–16. Count 0 occurs 2,058 times
and count 1 occurs 1,959 times; all 32,768 memory observations retain their
original bytes. observations.tsv records every form and count histogram.

## Input domain and comparison

The private observer samples the low CL byte in the 16-bit double-shift
defined domain 0–16. It retains upper RCX bits and all other sampled state.
The first 128 cases cycle the 17 counts; subsequent cases reduce the existing
random byte modulo 17. driver-sample.c records the sole sampling assignment
immediately before capturing the shared input. The original production driver
is retained in the actual-compilation archive.

The existing state observer and flag masks compare GPRs, modeled vectors,
stack, defined arithmetic flags and memory. Canonical comparison checks final
PC and its defined-flag mask. Raw/direct groups retain the advancing fixed-seed
stream, with one shared CPU/C/reference input per tuple. The 32/64-bit companion
result is ../x86-dshift-cl/, published as e12bbe76.

## Source and artifacts

All 94 actual-compilation archive files match their SHA manifest. Its 82
production snapshot files equal launch Git e12bbe76b1d128fb3ea098ae271fef8e238641e8.
All encoded fields recreate the production encoder output; each of the 16
raw/direct native-byte pairs is identical. The source-drift map is empty.

| Artifact | SHA-256 |
| --- | --- |
| Static observer | 9f1fd9b686989143ad82dae6b5b22150deadd2c5af568edbffa23bb47ee02b26 |
| Canonical reference | c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96 |
| Full 59,506,712-byte trace | 0718185346c3e11c1fe0987ed369900bf810975f522f61550c268214e88a0199 |
| Original driver | 7cadcc3540eb1b8ad85e7fb7f2da411d43acfcaea485177aa757d1b7ccd6e762 |
| Sampled driver | 4570ae879fcd87b8e14b9d416ac43fee9e63e8885cb5f4af77114a136b065633 |

actual-compiled-inputs.tar.gz contains the complete compiled source/header
closure, sampled driver and original driver. launch-inputs.tar.gz retains
launch sources and the job wrapper. cpu-differential-x86.gz contains the static
executable; the full trace remains in the Workspace. Existing canonical
source/executable archives are shared with the c110b03a replay cohorts.
Detached job 3714297 exited 0 at 2026-11-07T20:28:12.474000+00:00.

## Commands

Run from /workspaces/repository:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-dshift-cl16/Makefile reference
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/differential/x86-dshift-cl16/review.py
~~~

The incremental build uses the existing generated-object target and links the
private sampled observer driver. review.py checks source archive hashes,
production Git identities, encoded fields, native bytes, the complete trace
and every per-form result. summary.json records its collected counts and pins.
