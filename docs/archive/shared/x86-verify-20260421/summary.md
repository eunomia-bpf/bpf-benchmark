# x86 Verification Summary (2026-04-21)

## Final commits

```text
69b62b59 [tetragon] wait for expected programs to attach before snapshotting IDs
668ddae9 [aws-x86] add AWS e2e and corpus test targets to Makefile; implement test commands in aws_executor.py
b3cc3bd8 docs: record AWS x86 runtime verification
1c8da845 [runtime-image] mirror tracee musl libs into loader path
94da7880 [bcc-kheaders] share cache across runs, clean per-run scratch
6099e04e [aws-x86] bundle tracee musl runtime libraries
00bf247b [aws-x86] include musl for tracee runtime
7e282720 [e2e-kvm-x86] drain bpftrace output pipes
e30c18fe [e2e-kvm-x86] align bindsnoop program count
1f2bd417 [e2e-kvm-x86] inject BCC compat header into source
```

## Runtime image

- Rebuilt `.cache/container-images/x86_64-runner-runtime.image.tar` on 2026-04-21 to pick up committed Dockerfile changes through `668ddae9`.

## Suite status

- KVM e2e: pass (`make vm-e2e`, final status `e2e: ALL PASSED`)
- KVM corpus: pass (`make vm-corpus`, final status `corpus status: ok`)
- AWS x86 e2e: pass (`make aws-e2e RUN_TARGET_ARCH=x86_64`, run token `run.aws-x86.e2e.ee678527`, final status `e2e: ALL PASSED`)
- AWS x86 corpus: pass (`make aws-corpus RUN_TARGET_ARCH=x86_64`, run token `run.aws-x86.corpus.e54d2938`, final status `corpus status: ok`)

## Result session directories

- KVM e2e: `e2e/results/tracee_20260421_174241_711844`
- KVM e2e: `e2e/results/tetragon_20260421_175158_482093`
- KVM e2e: `e2e/results/bpftrace_20260421_175310_560795`
- KVM e2e: `e2e/results/scx_20260421_180044_697713`
- KVM e2e: `e2e/results/bcc_20260421_180159_394489`
- KVM e2e: `e2e/results/katran_20260421_181255_477764`
- KVM corpus: `corpus/results/x86_kvm_corpus_20260421_181829_750236`
- AWS x86 e2e: `e2e/results/tracee_20260421_191414_976716`
- AWS x86 e2e: `e2e/results/tetragon_20260421_192413_242415`
- AWS x86 e2e: `e2e/results/bpftrace_20260421_192525_224955`
- AWS x86 e2e: `e2e/results/scx_20260421_193144_923229`
- AWS x86 e2e: `e2e/results/bcc_20260421_193325_660177`
- AWS x86 e2e: `e2e/results/katran_20260421_194427_765530`
- AWS x86 corpus: `corpus/results/aws_x86_corpus_20260421_200048_542429`

## AWS execution details

- AWS x86 e2e: instance `i-0b6ffa431f5818068`, type `t3.large`, region `us-east-1`, AZ `us-east-1f`
- AWS x86 corpus: instance `i-07fbbe5977765e934`, type `t3.large`, region `us-east-1`, AZ `us-east-1f`
- AWS x86 e2e authoritative synced log: `.cache/aws-x86/results/logs/e2e_run.aws-x86.e2e.ee678527_20260421_191411.remote.log`
- AWS x86 corpus authoritative synced log: `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.e54d2938_20260421_200045.remote.log`

## Outstanding issues

- No blocking x86 issues remain after this verification pass.
- The shared local `e2e/results/` tree was also receiving concurrent arm64 writes during the same window. AWS x86 result attribution above was validated against the x86 run tokens and the synced remote logs, not by assuming the newest local directory belonged to x86.
