# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | Tracee exited during BPF object load; verifier rejected `sys_exit_submit` | fail |
| Workload | No formal workload samples ran because Tracee did not load | fail |
| Result schema | App result recorded `status=error`, `post_rejit=null`, and 0 baseline workloads | fail |
| ABI | Simple-value fast path keeps the same argument index, size, and `save_to_submit_buf()` behavior; non-simple types use the original path | pass |
| Coverage | Does not disable events, maps, tail calls, scope filters, or perf submit | pass |
| Provenance | `source.diff`, run command, and attempt rationale recorded before formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 757G 112G 88% /`; Docker images
`79.35GB`, containers `29.73GB`, build cache `81.36GB`; no Docker cleanup
needed before this attempt.

Formal run:

- Result path: `corpus/results/x86_kvm_corpus_20260626_050351_616916`
- App result: `corpus/results/x86_kvm_corpus_20260626_050351_616916/details/apps/tracee__monitor.json`
- Correctness query:

```json
{
  "status": "error",
  "post_rejit": null,
  "mode": null,
  "baseline_workloads": 0,
  "baseline_rcs": []
}
```

Verifier failure excerpt:

```text
prog 'sys_exit_submit': failed to load: -13
invalid access to map value, value_size=72 off=1028 size=4
R2 max value is outside of the allowed memory range
```

Restoration:

- Reversed `source.diff` with `patch -d vendor/repos/tracee -p1 -R`.
- Rebuilt with `make -C vendor tracee-x86`; restore build log saved in
  `restore-build.log`.
- `git -C vendor/repos/tracee status --short` produced no output after restore.

Disk after run: `/dev/nvme0n1p2 915G 758G 112G 88% /`; Docker images
`80.51GB`, containers `29.73GB`, build cache `83.42GB`; no Docker cleanup was
needed after this attempt.
