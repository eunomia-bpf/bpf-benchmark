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
- Workload component durations: `180.01315556400004`,
  `180.022090671`, `180.02132751200008`, `180.02906161000004`,
  `180.09303832800003`, `180.10309931799998`.

Performance payload parsed from the three saved workload stdout blobs:

- `pktgen_total_pps` samples: `1579206, 1566724, 1563584`.
- Mean: `1569838`.
- pktgen errors: `0`.
- vs clean-source baseline mean `1488103`: `+5.49%`.
- vs current Cilium phase3 base mean `1672664`: `-6.15%`.

Gate table:

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor cilium-x86` passed before the formal run. | pass |
| Load | Real `cilium-agent` started and loaded its datapath; app `status=ok`. | pass |
| Workload | Three `cilium_endpoint_pktgen` samples completed; component returncodes were all `0`. | pass |
| Result schema | `post_rejit=null` and `rejit_result.mode="skip_rejit_all"`. | pass |
| ABI | Only local control-flow reshaping around existing policy verdict handling plus the current base branch annotations; map layout, event payloads, tail-call keys, and attach points unchanged. | pass |
| Coverage | No policy, security, packet-bounds, event, rate-limit, or endpoint lookup check removed. | pass |
| Provenance | `source.diff`, `candidate-only.diff`, command, build logs, result path, and correctness notes are present. | pass |

Decision:

- Correctness passed.
- Performance regressed by 6.15% vs the current Cilium phase3 base, so this
  patch is not stacked.
- Source was restored with `patch -R`, `make -C vendor cilium-x86` passed, and
  `vendor/repos/cilium` had empty `status --short` and empty diff for
  `bpf/bpf_lxc.c` after restore.
