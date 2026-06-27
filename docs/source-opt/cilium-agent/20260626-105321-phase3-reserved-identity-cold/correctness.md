# Correctness

Formal command:

```sh
SKIP_REJIT=all BPFREJIT_CORPUS_APPS='cilium/agent' BPFREJIT_CORPUS_BPF_STATS=0 SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus
```

Result:

- Suite status: `ok`.
- App status: `ok`.
- App error: `""`.
- `post_rejit == null`: true.
- `rejit_result.mode`: `skip_rejit_all`.
- Baseline workload samples: 3.
- Workload component returncodes: `0`.
- Workload component durations: `180.09968969199997`,
  `180.01795541`, `180.05336791500002`, `180.10080233200006`,
  `180.10300225900005`, `180.00955515299995`.

Performance payload parsed from the three saved workload stdout blobs:

- `pktgen_total_pps` samples: `1683410, 1662935, 1671646`.
- Mean: `1672664`.
- vs clean-source baseline mean `1488103`: `+12.40%`.
- vs previous Cilium best mean `1672124`: `+0.03%`.

Gate table:

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor cilium-x86` passed before the formal run. | pass |
| Load | Real `cilium-agent` started and loaded its datapath; app `status=ok`. | pass |
| Workload | Three `cilium_endpoint_pktgen` samples completed; component returncodes were all `0`. | pass |
| Result schema | `post_rejit=null` and `rejit_result.mode="skip_rejit_all"`. | pass |
| ABI | Only local branch annotations in `bpf/bpf_lxc.c`; map layout, event payloads, tail-call keys, and attach points unchanged. | pass |
| Coverage | No policy, security, packet-bounds, or endpoint lookup check removed. | pass |
| Provenance | `source.diff`, command, build logs, diagnostics, result path, and correctness notes are present. | pass |

Decision:

- Correctness passed.
- Performance is a marginal positive result over the previous Cilium best, so
  this patch is selected as the current Cilium phase3 base.
- Source was restored with `patch -R`, `make -C vendor cilium-x86` passed, and
  `vendor/repos/cilium` had empty `status --short` and empty diff for
  `bpf/bpf_lxc.c` after restore.
