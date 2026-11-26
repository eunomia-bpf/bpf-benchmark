# Detached stock-verifier replay

PERF 2026-11-26T16:12:48Z.

The existing cilium-headlen-20261119 archive-stock harness creates fresh maps
with request39's captured shapes and uses the production checked-loader
relocator on the compiled B. It loads the sole build-x86 kernel with2vCPUs
on host18–19 and2GiB guest memory under the image shared lock. This checks
stock verification, not application binding or native execution. It does not
use or rebuild a second kernel, image, base or application source tree.

The first harness build failed before a guest because relocation moved from
native_loader.cpp to native_loader_trusted.cpp and now returns subprogram
and BTF metadata. stock-probe-build-before.log retains that failure. The
harness now includes the current implementation, links the existing common
loader library, and supplies the same subprogram function-info records as
the normal checked loader. The rebuilt harness succeeds; no production
loader semantics or error policy changed.

The input links refer to the one canonical compiled B and the retained
metadata/facts. If the uncompressed compiler products are absent, extract
compiler-evidence.tar.zst into request-39, rather than making another build
tree. The actual replay commands from the checkout are:

```
make -f kprog/results/cilium-headlen-20261119/Makefile archive-probe
make -f kprog/results/cilium-headlen-20261119/Makefile archive-stock \
  OUT=/workspaces/repository/kprog/results/tetragon-tables-20261126/stock \
  INPUTS=/workspaces/repository/kprog/results/tetragon-tables-20261126/stock-index.json \
  REPLAY=/workspaces/repository/kprog/results/tetragon-tables-20261126/stock-replay
```

The stock-preview.log dry-run and probe build log are retained. The actual
guest outcome and verifier log will be recorded separately; the preceding
compiler success is not a verifier acceptance claim. All existing LTO pieces
stay enabled for the normal pipeline, and full timing remains frozen.
