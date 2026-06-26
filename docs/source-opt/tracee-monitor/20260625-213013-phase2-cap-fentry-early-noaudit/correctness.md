# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | Real Tracee app started and loaded the modified BPF object; app `status=ok`, `error=""` | pass |
| Workload | 3 formal workload samples all returned 0 | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, and 3 baseline workload payloads were recorded | pass |
| ABI | Event id, argument payload, scope filtering for submitted events, and perf submit path are unchanged | pass |
| Coverage | `trace_cap_capable` still hooks `cap_capable()`; `CAP_OPT_NOAUDIT` events were already suppressed | pass |
| Provenance | `source.diff`, run command, and attempt rationale recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 755G 115G 87% /`; Docker images
`78.19GB`, containers `29.73GB`, build cache `79.3GB`; no Docker cleanup
needed before this attempt.

Formal run:

- Result path: `corpus/results/x86_kvm_corpus_20260626_043813_884875`
- App result: `corpus/results/x86_kvm_corpus_20260626_043813_884875/details/apps/tracee__monitor.json`
- Correctness query:

```json
{
  "status": "ok",
  "error": "",
  "post_rejit": null,
  "mode": "skip_rejit_all",
  "baseline_workloads": 3,
  "baseline_rcs": [0, 0, 0]
}
```

Restoration:

- Reversed `source.diff` with `patch -d vendor/repos/tracee -p1 -R`.
- Rebuilt with `make -C vendor tracee-x86`; restore build log saved in
  `restore-build.log`.
- `git -C vendor/repos/tracee status --short` produced no output after restore.

Disk after run: `/dev/nvme0n1p2 915G 757G 112G 88% /`; Docker images
`79.35GB`, containers `29.73GB`, build cache `81.36GB`; no Docker cleanup was
needed after this attempt.
