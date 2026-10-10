# Pinned Cilium native comparison on lab, 2026-10-09

Read [summary.md](summary.md) for the result and [tables.md](tables.md) for
the complete timing, inventory, verdict and host-load tables.
This directory contains only new measurements and task-local observation
scripts. Existing results and paper numbers were not modified.

## Protocol and source identity

`metadata.json` records the source/kernel commits, immutable runtime image
identities, binary hashes, CPU mapping and differences from the May 29
measurements. The historical checkout is a detached worktree at the audit's
leading candidate, not a certified identification of the original binary.
The current runtime image was frozen at `9be2b6a199d4`; later unrelated
Workspace changes are not in that image.

The same upstream Cilium `1.20.0-dev` source is used in both builds. The
unchanged corpus runner starts the real upstream application and allocates
fresh endpoint addresses after each restart. Traffic remains bidirectional
64-byte UDP, randomized ports 1–65535, 65535 flows, flow length 1 and
`clone_skb=0`. Durations are 30 seconds, one warmup and one measured sample
per phase; the historical runs had three 180-second measured samples.

Every measured invocation goes through `make corpus` with the repository's
KVM path. `command.json`, `make-input.txt` and `guest-command.txt` in each
case retain the actual commands and overrides. One guest runs at a time.
The guest has four vCPUs and 24 GiB, compared with the old default eight and
64 GiB. Guest vCPUs 0/1 (kernel pktgen) are pinned to host P-cores 1/4;
guest vCPUs 2/3 (application/control container) are pinned to host P-cores
0/3. The QEMU emulator uses host cores 6/7. Thread/process affinity snapshots
confirm these assignments.

Each source has five JIT/native pairs and five JIT/JIT restart controls in
each of two separate statistics modes. Each pair contains a JIT application
start followed by a stopped/restarted second application. The second arm
is native in treatment pairs and JIT in controls. The order for each cycle
is stats-on treatment, stats-on control, stats-off treatment, stats-off
control. The source series are serial, historical first.

The historical native command retains its original `SKIP_REJIT=norejit`
plus native-post setting. Current native mode uses its current native-only
policy with the native-post setting and no skip flag. No program is selected
out of ReJIT, no workload is changed, and no result is discarded for drops,
inventory mismatch, contention or a low run count.

## Observations and analysis

`sitecustomize.py` is loaded only for this task via a Make override. It
observes measurement boundaries, synchronously taking inventory, counters
and images after warmup immediately before timing and again after timing.
It does not edit corpus or runner source. `vng-audit.py` and `guest-audit.py`
implement the CPU and output-directory overrides; no host workspace is
bind-mounted into the runtime container. `run-series.py` records raw
framework output, commands, host load, affinity and host/container start
identity. `queue-current.py` keeps the two source series sequential.

Each case's `raw/` contains the framework's unmodified raw result files.
`observations.tar.gz` losslessly contains the two phases' `start/` and
`end/` observations, including every saved `*-jited.bin`/`*-xlated.bin`,
command/error log, program/map/attachment inventory, metrics-map dump,
namespace interface counters and affinity snapshot. Kernel inventory queries
can create transient iterator programs; startup regeneration can remove a
queried program before its dump. Such capture errors are retained. Coverage
for the actual shim-measured IDs is reported in `programs.csv`/`phases.csv`.
`image-manifest.csv` hashes the images before packaging.

`paper-native-artifacts.tar.gz` and `current-native-artifacts.tar.gz` save
the immutable images' native Cilium objects (and current proof objects),
loader, shim, native-link, kinsn modules and kernel offset header.
`native-artifact-manifest.json` hashes every saved file and the upstream
Cilium executable (the large executable itself remains in the runtime image).
The current native objects and proofs were prebuilt cache artifacts from
October 6; their upstream source pin matches, but this measurement is not a
fresh proof rebuild. Historical native objects and both kernels/loaders/shims
were built for this task. Build recipes and logs are retained.

`analyze.py` performs post-hoc calculations outside framework code. It keeps
every program, reports undefined ns/run when counts are zero, and emits
medians, min/max and interpolated Q1/Q3. Overall ratios divide arm medians;
paired-ratio distributions are separate. Name-grouped unbound rows may
contain multiple program instances; per-ID counters remain authoritative.
`report-tables.py` renders those outputs. No forwarding-speed claim is made
from the native generated-PPS measurement when receiver/verdict evidence
shows different packet processing.

To rerun analysis after packaging, from this directory:

```sh
for d in paper/pair-* current/pair-*; do
    tar -xzf "$d/observations.tar.gz" -C "$d"
done
python3 analyze.py
python3 report-tables.py
```

`paper-smoke*` retain packaging/preflight failures and a successful short
smoke test; they are not mixed into the scheduled series. `reboot-state.json`
and the per-case host samples preserve the reboot audit. A guest-only early
boot failure from the initial oversized command line was corrected by
passing the command in a file. Missing pktgen module indexes and missing
bpftool JIT support were corrected in the task images before the series.
