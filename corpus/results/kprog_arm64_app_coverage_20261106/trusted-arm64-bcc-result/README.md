# Canonical ARM BCC trusted-service replay

Application status: **error** (`post_rejit_start` timed out after900 seconds).
The shell/transport exit0 and reported host status below record orchestration
completion; they are not application acceptance. The raw summary is preserved.

Host reported status: `True`; guest exit: `0`. Service completed counts: `{"service_accepted": 5, "service_refused": 1}`. Native identity errors: `[]`.

The canonical ARM worker receives kernel-copied native bytes. The existing readonly v35 standard `/qemu-run.sh` runs corpus.driver/BCC set with its eight tools, two starts and four existing stressors. The native application manifest contains no proof filenames. Existing current kernel,11 matching kinsn modules, module tree and loader are reused. Raw corpus results, counters, logs, kernel/memory evidence and each available closed service request are in `run-20261107T163609924222Z.tar.gz` (SHA256 `2eff867c2a71c15794d7ae3a229a132b5057d7a149d7b0500165a01a9a07cd85`). QEMU timing is functional only.

The preceding two zero-request startup failures and module CRC diagnosis are retained beside this run. The application inventory/work-counter review below records the actual error; this does not establish all-six-application or whole O1-O4 acceptance.

## Application coverage review

| Observed baseline programs | C generated | BPF compiled | Accepted/bound | Specialization failure | Verifier rejection | Compile interrupted | No native request recorded |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 23 | 7 | 6 | 5 | 0 | 1 | 1 | 16 |

`vfsstat/fentry_vfs_read` rejects its LDXR/STXR retry loop. `inet_sock_set_state`
had generated C/native proof but no completed BPF compile when the standard900s
native-start deadline expired. The other16 baseline programs have no native
request in this partial run; no unsupported-program classification is implied.
There is no native workload measurement. `application-review.json` records every
completed request, the unfinished request and all raw baseline counters/workload.
The five accepted entries are opensnoop enter, sched_wakeup, biosnoop merge,
sys_enter and tcp_v4_connect. All six closed native byte identities match the
kernel copy; the partial tcplife generator input also matches its kernel copy.

The corpus driver deliberately returns0 for per-app errors while recording
metadata.status=error. The ARM transport now propagates that recorded status in
future replays. The existing BPFREJIT_CORPUS_REJIT_TIMEOUT knob supports0; the BCC transport now uses0 so
QEMU's serialized trusted compiler queue can finish without
changing the workload, sample/duration or simulator. This does not repair the
exclusive retry rejection, whose proposed kernel candidate remains unbooted.
