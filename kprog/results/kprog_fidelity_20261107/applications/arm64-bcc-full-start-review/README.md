# Independent review of the closed ARM BCC full-start run

Reanalysis of the [original raw archive](../../../../../corpus/results/kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/run-20261107T172354861230Z.tar.gz) published in
5d6d067cfd55a627d7f367054decc72e09bb7e51. Its SHA256 is
70369c4760749672015fe1a8a1a6c2970e5a6d240c6a17eab42acf23148aeeda. The analyzer verifies the
physical archive against that exact Git blob, then reads the raw application
record and all 19 nested service archives, independently of A’s aggregate report.
No VM is launched and no application, kernel, simulator or runner is changed.

All **19** generated native inputs equal their immutable kernel copies and
recorded request hashes. Each load context matches the captured kernel facts.
All requests contain a generated proof. **16** have status 0 and distinct bound
program IDs, confirmed independently against each loader’s JSON stdout.
**3** have status -5 and actual stub-verifier loop diagnostics:

| Request | Native entry | Exact diagnostic | Verifier work |
| --- | --- | --- | --- |
| 1 | fentry_vfs_read | 4: (55) if r0 != 0x0 goto pc-3 infinite loop detected at insn 2 | processed 29 insns (limit 1000000) max_states_per_insn 0 total_states 2 peak_states 2 mark_read 0 |
| 10 | sys_exit | infinite loop detected at insn 203 | processed 166 insns (limit 1000000) max_states_per_insn 0 total_states 12 peak_states 12 mark_read 0 |
| 15 | sched_switch | infinite loop detected at insn 346 | processed 350 insns (limit 1000000) max_states_per_insn 0 total_states 22 peak_states 22 mark_read 0 |

The application result is **error**: BCC tool vfsstat exited with rc=97.
The raw guest exit is 1. Framework rejit_result.status=ok records the selected
mode, while the enclosing application fails and post_rejit is null. There is
**no completed native workload sample** for a same-work or performance comparison.
This does not establish zero native hook executions during partial startup.

The baseline contains **23** observed BPF programs and one successful four-stressor
workload. Its raw stress-ng bogo operations are syscall=507, cap=2536, set=217, sockfd=2039.
Every baseline program’s run count/time and code sizes are retained verbatim in
verification.json. The 23 baseline programs and 19 service requests belong to
different startups; this review does not turn them into a 16/23 acceptance rate
or omit the missing native workload. No latency, speedup, throughput ratio, full
BCC coverage or all-six-app completion is claimed.

The service source changed after launch; the original drift record is retained
verbatim, including distinct interpreter-start and later physical source hashes.
There are 5 request source-identity records with distinct hashes, not one asserted
immutable checkout. Guest timestamps start in 1970 and QEMU timing is functional
evidence. The private exclusive-convergence kernel candidate was not applied in
this owner run; these records do not validate that candidate.

~~~sh
python3 kprog/results/kprog_fidelity_20261107/applications/arm64-bcc-full-start-review/analyze.py > kprog/results/kprog_fidelity_20261107/applications/arm64-bcc-full-start-review/verification.json
~~~
