# Running A/A control

Started 2026-11-15T06:21:35Z. PID 838173 is the timing-lock controller,
838174 the recorded Make launcher. Raw output:
`/workspaces/kprog-raw/perf/20261115-isolated-aa/job/make.log`.

The existing one-image corpus target runs Katran with `SKIP_REJIT_MODE=all`,
which disables the shim for both arms. The frozen driver still stops the
baseline application and starts the post application. Both arms therefore
use the image's same eBPF objects, with three 180-second samples, stats on,
CPUs 0–7, 8 vCPUs and 64 GiB guest memory. Host AS cap is 80 GiB. The job
holds timing EX and image SH; other functional guests finished before start.
No benchmark source, workload, timing script or image was changed for this
control. The coordinator explicitly requested it at 06:06:55.

Protocol and exact command are retained here. This is setup provenance;
no completed A/A ratio or native performance gain is claimed. Read the raw
job's terminal status and framework result before reporting its outcome.
The temporary guest Docker disk is removed by the existing Make target on
success; inspect and remove any ended-run image copy if the job fails, keeping
all logs, measurements and framework result files.
