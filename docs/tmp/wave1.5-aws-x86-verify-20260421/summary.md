# Wave 1.5 AWS x86 verification

Date: 2026-04-21 America/Vancouver

## HEAD

- Start HEAD under test: `0df38b7f994a7523d2c552e47d0aea4d65baf7ee`
- End HEAD under test: `0df38b7f994a7523d2c552e47d0aea4d65baf7ee`
- Code changes during verification: none

## AWS x86 e2e

Command:

```sh
make aws-e2e RUN_TARGET_ARCH=x86_64
```

Result: pass, `e2e: ALL PASSED`

Run details:

- Run token: `run.aws-x86.e2e.d05bb7e6`
- AWS instance: `i-0a63c89de162234e4`
- Instance type: `t3.large`
- Region: `us-east-1`
- AZ: `us-east-1f`
- Final state: terminated
- Synced authoritative log: `.cache/aws-x86/results/logs/e2e_run.aws-x86.e2e.d05bb7e6_20260422_003505.remote.log`

Result session directories:

- `e2e/results/tracee_20260422_003508_793984`
- `e2e/results/tetragon_20260422_004349_157309`
- `e2e/results/bpftrace_20260422_004501_540400`
- `e2e/results/scx_20260422_005120_581005`
- `e2e/results/bcc_20260422_005302_046969`
- `e2e/results/katran_20260422_010404_198581`

## AWS x86 corpus

Command:

```sh
make aws-corpus RUN_TARGET_ARCH=x86_64
```

Result: pass, corpus status `ok`

Run details:

- Run token: `run.aws-x86.corpus.103432bb`
- AWS instance: `i-03cd0c68044f20278`
- Instance type: `t3.large`
- Region: `us-east-1`
- AZ: `us-east-1f`
- Final state: terminated
- Synced authoritative log: `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.103432bb_20260422_011958.remote.log`
- Result session dir: `corpus/results/aws_x86_corpus_20260422_012001_472335`
- App status count: `20/20 ok`

## Corpus delta vs pre-wave1 baseline

Baseline session: `corpus/results/aws_x86_corpus_20260421_200048_542429`

- `applied_sample_count`: `8 -> 10`
- `sample_count`: `8 -> 10`
- `no_programs_changed_in_loader`: `39 -> 36`
- Direction vs KVM wave1 rerun: matched (`applied` increased, exclusion count decreased)

## Fixes landed

- None. No daemon schema drift or AWS executor fallback-removal regression surfaced on AWS x86.

## Outstanding issues

- None for this AWS x86 verification pass.
