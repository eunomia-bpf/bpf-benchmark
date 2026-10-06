# Wave 1.5 AWS arm64 verification

Date: 2026-04-21 America/Vancouver

## HEAD

- Start HEAD observed at verification start: `1c11427ded35ca5e643bda331f2f6adc53e21491`
- End HEAD observed before this summary commit: `1e63da721f05e3f81bc0db6136d4e355ebf65c61`
- Code changes during this AWS arm64 verification: none
- Note: `main` advanced concurrently during this verification. The arm64 runtime tar was rebuilt once, then the successful AWS runs were launched via generated run-configs and `runner.libs.aws_executor run` to avoid a redundant rebuild after `runner/libs/workspace_layout.py` became newer than the rebuilt tar.

## Arm64 runtime image rebuild

Command:

```sh
make image-runner-runtime-image-tar RUN_TARGET_ARCH=arm64
```

Runtime tar: `.cache/container-images/arm64-runner-runtime.image.tar`

- Pre-rebuild mtime: `2026-04-21 14:20:01.920003371 -0700`
- Post-rebuild mtime: `2026-04-21 20:36:35.674697 -0700`
- Rebuild duration: `2:05:37`

## AWS arm64 e2e

Verification target command:

```sh
make aws-e2e RUN_TARGET_ARCH=arm64
```

Result: pass, `e2e: ALL PASSED`

Run details:

- Run token: `run.aws-arm64.e2e.6b6fe67c`
- AWS instance: `i-02d43b7c81cc66d46`
- Instance type: `t4g.large`
- Region: `us-east-1`
- AZ: `us-east-1f`
- Final state: terminated
- Synced authoritative log: `.cache/aws-arm64/results/logs/e2e_run.aws-arm64.e2e.6b6fe67c_20260422_035604.remote.log`

Result session directories:

- `e2e/results/tracee_20260422_035607_446491`
- `e2e/results/tetragon_20260422_040630_172201`
- `e2e/results/bpftrace_20260422_040742_059596`
- `e2e/results/scx_20260422_041359_784456`
- `e2e/results/bcc_20260422_041541_495393`
- `e2e/results/katran_20260422_042647_372435`

## AWS arm64 corpus

Verification target command:

```sh
make aws-corpus RUN_TARGET_ARCH=arm64
```

Result: pass, corpus status `ok`

Run details:

- Run token: `run.aws-arm64.corpus.0b8c49b9`
- AWS instance: `i-02ec97e7545abf5d8`
- Instance type: `t4g.large`
- Region: `us-east-1`
- AZ: `us-east-1f`
- Final state: terminated
- Synced authoritative log: `.cache/aws-arm64/results/logs/corpus_run.aws-arm64.corpus.0b8c49b9_20260422_044301.remote.log`
- Result session dir: `corpus/results/aws_arm64_corpus_20260422_044304_037607`
- App status count: `20/20 ok`

## Corpus delta vs pre-wave1 baseline

Baseline session: `corpus/results/aws_arm64_corpus_20260421_213547_871838`

- `applied_sample_count`: `16 -> 10`
- `sample_count`: `16 -> 10`
- `no_programs_changed_in_loader`: `37 -> 36`
- Direction vs KVM wave1 rerun and AWS x86 rerun: `no_programs_changed_in_loader` matched (decreased), `applied_sample_count` did not
- The entire `applied_sample_count` drop came from `tracee/default`: the baseline run requested 9 tracee programs and had 6 changed comparable tracee programs, while the post-wave1 arm64 run reported only the two raw-syscall tracee programs and both were excluded as `no_programs_changed_in_loader`
- Current AWS arm64 matches current AWS x86 tracee scope: the post-wave1 AWS x86 corpus also reported only the two raw-syscall tracee programs for `tracee/default`

## Fixes landed

- None. No daemon schema drift or no-fallback regression required code changes on AWS arm64.

## Outstanding issues

- No pass/fail gating issue remains for AWS arm64 e2e or corpus.
- The `tracee/default` comparable program set is narrower than the pre-wave1 AWS arm64 baseline, which is why `applied_sample_count` dropped even though the exclusion count improved.
