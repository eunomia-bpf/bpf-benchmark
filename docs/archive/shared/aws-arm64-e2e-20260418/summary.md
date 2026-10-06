# AWS arm64 validation summary (2026-04-21)

## Landed fixes

- `668ddae9` prior landed bundle from Apr 20:
  - `vendor/bpfrejit_arm64_defconfig`: `CONFIG_DEBUG_INFO_BTF_MODULES=y`
  - `runner/containers/runner-runtime.Dockerfile`: `bsdextrautils`, `ausyscall` assertion
  - `runner/libs/aws_executor.py`: reuse runtime-image tar for arm64 kernel artifact extraction
  - `Makefile`: AWS e2e/corpus targets
- `69b62b59` `[tetragon] wait for expected programs to attach before snapshotting IDs`
- `0133184c` `refactor: streamline ARM64 kernel artifact extraction in AWS executor`
  - contains the real AWS arm64 module-format fix in `runner/libs/aws_executor.py`
  - also contains the daemon per-pass kinsn fd-array fix in `daemon/src/commands.rs` and `daemon/src/commands_tests.rs`

## Root cause and fix

- Root cause of `insmod ... bpf_bulk_memory.ko: Invalid module format`:
  - AWS host setup was reusing a stale locally extracted arm64 host-kernel/modules cache, while the runtime container always used the current runtime-image tar's `/artifacts/kinsn`.
  - That put the EC2 host on kernel artifacts from one extraction and tried to load kinsn modules from another image build.
- Fix:
  - stop reusing the stale arm64 host-artifact cache
  - always re-extract/install arm64 host kernel artifacts from the current `arm64-runner-runtime.image.tar`
- Corpus follow-up fix:
  - reserve fd-array slot 0 for per-pass `BPF_PROG_LOAD` verification too, matching the 1-based module-BTF kinsn call convention already used by REJIT

## AWS runs

- Region: `us-east-1`
- AZ for both validation instances: `us-east-1f`
- Instance type: `t4g.large`

### AWS arm64 e2e

- Run token: `run.aws-arm64.e2e.1ccd2b75`
- Remote stage dir: `/var/tmp/bpf-benchmark-aws-arm64/e2e/run.aws-arm64.e2e.1ccd2b75`
- Synced remote log: `.cache/aws-arm64/results/logs/e2e_run.aws-arm64.e2e.1ccd2b75_20260421_213438.remote.log`
- Result dirs:
  - `e2e/results/tracee_20260421_213441_559391`
  - `e2e/results/tetragon_20260421_214923_900333`
  - `e2e/results/bpftrace_20260421_215035_732158`
  - `e2e/results/scx_20260421_215653_274656`
  - `e2e/results/bcc_20260421_215834_734867`
  - `e2e/results/katran_20260421_220940_906295`
- Case status:
  - `tracee`: `ok`
  - `tetragon`: `ok`
  - `bpftrace`: `ok`
  - `scx`: `ok`
  - `bcc`: `ok`
  - `katran`: `ok`

### AWS arm64 corpus

- Run token: `run.aws-arm64.corpus.3be774c4`
- Remote stage dir: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.3be774c4`
- Synced remote log: `.cache/aws-arm64/results/logs/corpus_run.aws-arm64.corpus.3be774c4_20260421_213545.remote.log`
- Result dir: `corpus/results/aws_arm64_corpus_20260421_213547_871838`
- Overall status: `ok`
- `applied_sample_count`: `16`
- `sample_count`: `16`
- `selected_apps`: `20`

## Post-fix kinsn discovery

- `loaded_count=6`
- `loaded_modules=[bpf_bulk_memory, bpf_endian, bpf_extract, bpf_ldp, bpf_rotate, bpf_select]`
- Excerpt from `e2e/results/katran_20260421_220940_906295/result.json`:

```text
kinsn discovery:
  vmlinux BTF str_len=2287195 type_cnt=126294 type_id_bias=126293
  bpf_rotate64: function 'bpf_rotate64' found in 'bpf_rotate' btf_id=126314 fd=3
  bpf_select64: function 'bpf_select64' found in 'bpf_select' btf_id=126314 fd=4
  bpf_extract64: function 'bpf_extract64' found in 'bpf_extract' btf_id=126314 fd=5
  bpf_memcpy_bulk: function 'bpf_memcpy_bulk' found in 'bpf_bulk_memory' btf_id=126324 fd=6
  bpf_memset_bulk: function 'bpf_memset_bulk' found in 'bpf_bulk_memory' btf_id=126325 fd=6
  bpf_endian_load16: function 'bpf_endian_load16' found in 'bpf_endian' btf_id=126315 fd=7
  bpf_endian_load32: function 'bpf_endian_load32' found in 'bpf_endian' btf_id=126316 fd=7
  bpf_endian_load64: function 'bpf_endian_load64' found in 'bpf_endian' btf_id=126317 fd=7
```
