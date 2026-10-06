# Corpus Round 3 (2026-03-28)

## Command

```bash
make daemon && make runner
make vm-corpus TARGET=x86 REPEAT=50
```

Host log:

```text
docs/tmp/20260328/vm_corpus_round3_host.log
```

Result metadata:

```text
runner/corpus/results/vm_corpus_20260329_075032/metadata.json
```

## Repo-side changes exercised in this round

- `runner/scripts/vng-wrapper.sh`
  - Rebuild hostfs modules when they are stale relative to the repo kernel image.
- `Makefile`
  - Default `KALLSYMS_EXTRA_PASS=1` so the repo kernel rebuild stays bootable.
- `corpus/modes.py`
  - Scope the guest daemon lifecycle to one object chunk instead of reusing one daemon across the full corpus batch.
  - Snapshot `micro_exec`, `bpfrejit-daemon`, `vmlinux`, and `module/` into the run artifact directory.
  - Emit host-side corpus progress and heartbeat lines during the long VM run.
- `runner/libs/vm.py`
  - Support a snapped `load_all.sh` path for guest startup.
  - Emit a 60s host heartbeat while the guest batch is running.

## Outcome

- The run advanced past both earlier failure points:
  - past `25 objects` / `169 programs`
  - past the earlier abrupt early-batch deaths
- Partial metrics at failure:
  - completed objects: `26 / 469`
  - completed programs: `173 / 2009`
  - measured pairs: `49`
  - comparable pairs: `16`
  - applied comparable pairs: `16`
  - applied programs: `66`
  - applied-only exec geomean: `1.0155944196905835`

Early per-repo state:

- `bcc`
  - comparable pairs: `16`
  - applied comparable pairs: `16`
  - applied-only exec geomean: `1.0155944196905835`
- `KubeArmor`
  - still no comparable data at this point

## Failure

The guest did not crash internally. QEMU was externally terminated:

```text
vm guest batch failed: qemu-system-x86_64: terminating on signal 15 from pid 1171424 (/bin/bash) (exit=255)
```

Relevant artifacts:

```text
docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-jdrmzsx7.json
docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-jfy3o8d6.json
docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-jfy3o8d6.json.stdout_log.txt
docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-jfy3o8d6.json.diagnostic_stdout_log.txt
```

The host log shows normal progress through `bcc:libbpf-tools/hardirqs.bpf.o`, then immediate external termination. There is no repo traceback from inside the guest batch before the QEMU SIGTERM line.

## Current hypothesis

- The repo-side stability fixes are working:
  - no hostfs module mismatch
  - no early reused-daemon crash
  - no early `exit=-15` due to long host silence
- The remaining failure is most likely host-session interference:
  - this round used a long-lived PTY session for `make vm-corpus`
  - while that PTY session was active, additional host-side `exec_command` calls were made to inspect metadata and processes
  - shortly after those extra host commands, QEMU was killed by `SIGTERM` from a `/bin/bash` process

## Next step

Rerun the full corpus benchmark again, but while it is active:

- use exactly one host session
- do not issue parallel host `exec_command` calls
- observe progress only from the benchmark's own heartbeat/progress lines
