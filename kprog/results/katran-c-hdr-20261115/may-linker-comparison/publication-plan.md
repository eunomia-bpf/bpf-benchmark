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
