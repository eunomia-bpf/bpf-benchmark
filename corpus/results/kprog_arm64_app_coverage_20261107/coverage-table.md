# Observed ARM first-pass coverage

Snapshot: 2026-11-07T19:21:29.828642+00:00. These are actual closed startup cohorts, not manifest counts. Baseline load attempts and unique positive program IDs include probes/transients; resident rows are the measurement inventory. Native requests are only the prefix that reached the trusted service. An early failed application does not establish coverage of programs it never reached.

| App | Baseline loads / IDs / resident | Native load attempts | Trusted requests | Proofs compiled | Bound | Specialization failed | Verifier rejected | Other load refused | App |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc | 74 / 74 / 23 | 69 | 19 | 19 | 16 | 0 | 3 | 0 | error |
| otelcol-ebpf-profiler | 16 / 15 / 12 | 3 | 1 | 1 | 0 | 0 | 0 | 1 | error |
| cilium | 8 / 5 / 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| tetragon | 205 / 201 / 152 | 19 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| katran | Open at snapshot | — | — | — | — | — | — | — | Running |
| tracee | Not yet closed at snapshot | — | — | — | — | — | — | — | Pending |

BCC: all three verifier failures are unbounded exclusive retries (vfsstat/syscount/runqlat); native workload never starts. OTel: first proof compiled, then readonly byte mismatch before the verifier. Cilium: readonly features.h startup failure before any specialization request. Tetragon:152resident baseline rows, then missing exact anonymous mixed-call selector before any trusted request. Zero service requests in failed startup are not zero application programs.

startup-loads.jsonl retains every parsed load attempt, including unfinished records and any unmatched result. Full raw shim/compiler/verifier/app logs remain in the referenced archives; coverage-table.json retains stage counts and archive hashes. The two remaining first-pass jobs and queued repairs/replays continue without changing these historical results. No timings or all-six-app/O1-O4 completion claim.
