# Phase 1.6 live minimal pipeline validation (2026-04-28)

Task: validate the live `bpfget | bpfopt | bpfverify | bpfrejit` pipeline on KVM x86 with the fork kernel.

Environment:

- KVM: `virtme-ng`
- Kernel: `Linux virtme-ng 7.0.0-rc2 #1 SMP PREEMPT_DYNAMIC Wed Apr 29 03:13:41 UTC 2026 x86_64`
- Runtime image tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- Runtime image: `bpf-benchmark/runner-runtime:x86_64`
- Raw run log: `.cache/phase1-minimal-pipeline-live-20260428/vm-output.log`

## Packaging observation

The exact `vm-micro` / `vm-corpus` runtime image was loaded successfully, but the Phase 1 CLI tools are not installed on `PATH` in that image:

```text
Loaded image: bpf-benchmark/runner-runtime:x86_64
bpfget=MISSING
bpfopt=MISSING
bpfverify=MISSING
bpfprof=MISSING
bpfrejit=MISSING
bpfrejit-daemon=MISSING
jq=MISSING
daemon/target/release/bpfrejit-daemon exists, but is not on PATH.
```

To separate packaging from functional validation, I built a temporary validation image layer from the same runtime image and copied in the already-built release CLI binaries plus `jq` and `scripts/per-pass-verify.sh`:

```text
Successfully tagged bpf-benchmark/runner-runtime:x86_64-phase1-cli
bpfget 0.1.0
bpfopt 0.1.0
bpfverify 0.1.0
bpfprof 0.1.0
bpfrejit 0.1.0
jq-1.7
bpftrace v0.20.2
```

This is a packaging blocker for claiming the exact runtime image is ready for #41, even though the CLI pipeline itself works once the binaries are present.

## Live program setup

Loaded two live tracepoint programs with bpftrace:

```bash
bpftrace -e 'tracepoint:syscalls:sys_enter_getpid { } tracepoint:syscalls:sys_exit_getpid { }'
```

`bpfget --list` output:

```text
12  cgroup_device
15 sys_enter_getpi tracepoint
16 sys_exit_getpid tracepoint
```

Selected `PROG_ID=15`, using `jq -r '.type.name'` because current `bpfget --info` emits `type` as an object.

```json
{
  "id": 15,
  "name": "sys_enter_getpi",
  "type": {
    "name": "tracepoint",
    "numeric": 5
  },
  "insn_cnt": 2,
  "map_ids": [],
  "xlated_prog_len": 16,
  "orig_prog_len": 16,
  "jited_prog_len": 19
}
```

## Case A: single pass dry-run

Commands:

```bash
bpfget 15 > /tmp/orig.bin
bpfopt wide-mem < /tmp/orig.bin > /tmp/wide.bin
diff /tmp/orig.bin /tmp/wide.bin
ls -l /tmp/wide.bin
bpfrejit 15 /tmp/wide.bin --dry-run
```

Output:

```text
diff exit code: 0
-rw-r--r-- 1 root root 16 Apr 29 05:36 /tmp/wide.bin
wide.bin size: 16
{"status":"dry-run pass","prog_id":15,"insn_count_before":2,"insn_count_after":2,"dry_run":true}
```

Status: PASS

## Case B: optimize pipeline

Commands:

```bash
bpfget 15 > /tmp/orig.bin
bpfopt optimize --report /tmp/r.json < /tmp/orig.bin > /tmp/opt.bin
cat /tmp/r.json
jq . /tmp/r.json
bpfrejit 15 /tmp/opt.bin --dry-run
```

Output:

```json
{
  "passes": [
    {"pass": "dce", "changed": false, "sites_applied": 0, "insn_count_before": 2, "insn_count_after": 2, "insn_delta": 0},
    {"pass": "skb_load_bytes_spec", "changed": false, "sites_applied": 0, "insn_count_before": 2, "insn_count_after": 2, "insn_delta": 0},
    {"pass": "bounds_check_merge", "changed": false, "sites_applied": 0, "insn_count_before": 2, "insn_count_after": 2, "insn_delta": 0},
    {"pass": "wide_mem", "changed": false, "sites_applied": 0, "insn_count_before": 2, "insn_count_after": 2, "insn_delta": 0}
  ]
}
```

```text
{"status":"dry-run pass","prog_id":15,"insn_count_before":2,"insn_count_after":2,"dry_run":true}
```

Status: PASS

## Case C: bpfverify in pipeline

Command:

```bash
PROG_TYPE=$(bpfget 15 --info | jq -r '.type.name')
bpfget 15 | bpfopt wide-mem | bpfverify --prog-type tracepoint | bpfrejit 15 --dry-run
```

Output:

```text
PROG_TYPE=tracepoint
{"status":"dry-run pass","prog_id":15,"insn_count_before":2,"insn_count_after":2,"dry_run":true}
Exit code: 0
```

Status: PASS

## Case D: bpfget --full + multi-pass optimize

Commands:

```bash
bpfget 15 --full --outdir /tmp/prog/
ls -l /tmp/prog/
cat /tmp/prog/prog_info.json
cat /tmp/prog/map_fds.json
bpfopt optimize --report /tmp/prog/r.json < /tmp/prog/prog.bin > /tmp/prog/opt.bin
jq . /tmp/prog/r.json
```

Output:

```text
total 12
-rw-r--r-- 1 root root   3 Apr 29 05:36 map_fds.json
-rw-r--r-- 1 root root  16 Apr 29 05:36 prog.bin
-rw-r--r-- 1 root root 284 Apr 29 05:36 prog_info.json
```

```json
[]
```

The optimize report was valid JSON and matched Case B's unchanged four-pass report.

Status: PASS

## Case E: bpfprof collection

Command:

```bash
bpfprof --prog-id 15 --duration 500ms --output /tmp/profile.json
```

Output:

```text
open PMU branch counters: open branch-instructions PMU counter: perf_event_open: No such file or directory (os error 2)
Exit code: 1
```

Status: SKIPPED

Reason: the KVM VM did not expose the hardware branch PMU needed by the current `bpfprof` implementation.

## Case F: per-pass verify bash

Command:

```bash
PROG_TYPE=$(bpfget 15 --info | jq -r '.type.name')
BPFOPT_DRY_RUN=0 bash scripts/per-pass-verify.sh 15 tracepoint
```

Output:

```text
pass dce: no change
pass skb-load-bytes: no change
pass bounds-check-merge: no change
pass wide-mem: no change
{"status":"ok","prog_id":15,"insn_count_before":2,"insn_count_after":2,"dry_run":false}
Exit code: 0
```

Status: PASS

## Real ReJIT

Command:

```bash
bpfget 15 > /tmp/rejit.bin
bpfrejit 15 /tmp/rejit.bin --output /tmp/rejit-summary.json
bpfget 15 --info
```

Output:

```json
{
  "status": "ok",
  "prog_id": 15,
  "insn_count_before": 2,
  "insn_count_after": 2,
  "dry_run": false
}
```

Post-ReJIT `bpfget --info` still succeeded for program 15 while the bpftrace workload process remained alive:

```json
{
  "id": 15,
  "name": "sys_enter_getpi",
  "type": {
    "name": "tracepoint",
    "numeric": 5
  },
  "insn_cnt": 2,
  "map_ids": [],
  "xlated_prog_len": 16,
  "orig_prog_len": 16,
  "jited_prog_len": 19
}
```

Status: PASS

## Summary

Functional result with CLI binaries present: 5 PASS, 0 FAIL, 1 SKIPPED across cases A-F. Real non-dry-run ReJIT succeeded.

Phase 1 CLI interop is functionally working on the fork kernel for the minimal live tracepoint pipeline:

```text
bpfget 15 | bpfopt wide-mem | bpfverify --prog-type tracepoint | bpfrejit 15 --dry-run
```

Blocking issue before closing #41 against the canonical VM image: `bpfget`, `bpfopt`, `bpfverify`, `bpfprof`, `bpfrejit`, `jq`, and PATH-installed `bpfrejit-daemon` are missing from `bpf-benchmark/runner-runtime:x86_64`.

No panic observed. No kernel ReJIT rejection observed. The only skipped case was `bpfprof`, due to missing branch PMU support in this KVM environment.
