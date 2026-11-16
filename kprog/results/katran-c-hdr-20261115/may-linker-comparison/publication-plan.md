# Reference-linker timing after the breadth round

The unchanged corpus entry will compare the preserved May-build linker output
with current LTO after C completes its breadth round. Current imagefc408f64
contains linkerf7de4bfc and the helper-alias loader; C's Katran results supply
the current-LTO measurements where that version remains in use.

The build-only shared refresh now accepts the recorded reference executable
as its sole canonical linker. It replaces the current image and retains the
loader, native objects, kernel, modules and frozen image recipe. The input
archive stays in place; paths/hashes and replaced build output are recorded.
The source stays on master, with the current linker implementation intact.
This change was syntax-checked and Make-dry-run; imagefc408f64 remains current.

After the breadth round, publish the reference under the image writer lock:

```sh
flock -x /workspaces/.agent-state/kprog-lanes/locks/image \
  make -C kprog/libnativeloader shared-base-refresh \
  REFRESH_OPERATION=--linker-input \
  REFRESH_LINKER_INPUT=/workspaces/kprog-raw/paper-tree-untracked/native-sim/x86/native_lab/native_link/target/release/native-link \
  REFRESH_OUTPUT=/workspaces/kprog-raw/perf/katran-reference-image
```

Run the existing entry with its defaults and the permitted selections:

```sh
flock -x /workspaces/.agent-state/kprog-lanes/locks/timing \
  flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
  make -f kprog/perf/one-image/Makefile corpus APPS=katran BPFREJIT_CORPUS_BPF_STATS=0
flock -x /workspaces/.agent-state/kprog-lanes/locks/timing \
  flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
  make -f kprog/perf/one-image/Makefile corpus APPS=katran BPFREJIT_CORPUS_BPF_STATS=1
```

Then rebuild the current implementation into the same canonical output/image:

```sh
flock -x /workspaces/.agent-state/kprog-lanes/locks/image \
  make -C kprog/libnativeloader shared-base-refresh \
  REFRESH_OPERATION=--linker-rebuild \
  REFRESH_OUTPUT=/workspaces/kprog-raw/perf/katran-current-image
```

The explicit rebuild removes the replaced executable first, so Cargo recreates
its canonical output from the current source/cache. The experiment keeps one
image, base, kernel and checkout throughout. Original archives and every run
remain. Shell sessions record their exact launcher PIDs and redirect logs to
persistent /workspaces storage. Results retain the observed LRU work difference
from lru-reference.md and all application errors/counters. The native1.50x and
code-size goals remain open.

2026-11-16T01:29:01Z: committed job 9c01aa597/dc8110750 launched as PID1290695 (shell1290700), currently waiting on timing behind the breadth round. Logs and 96GiB address-space receipt are under /workspaces/kprog-raw/perf/20261116-reference-linker-timing. The script publishes under image EX, uses the unchanged entry at stats0/1, and rebuilds current source after both successful or failed timed Make invocations. queued-timing.json records the exact state; no reference timing has completed yet.

2026-11-16T02:41:17Z: the former waiting queue1290695 was superseded before publication by job1305713, raw /workspaces/kprog-raw/perf/20261116-post-round-data-fix. Coordinator02:03/02:19 added the BCC data regression and B-tool publication. The new order publishes B normalizer plus DATASEC loader, retries BCC0/1, times current Katran0/1, publishes the reference linker, times reference Katran0/1 and rebuilds current. All use the unchanged corpus defaults. Both Katran pairs now use the same fixed loader; the earlier breadth result remains an observation rather than the comparison denominator. See post-round-queued.json and perf_20261113/bcc-data-layout/.
