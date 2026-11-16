Host-validated lookup/map-ops batch publication, 2026-11-16

Coordinator 22:20 requests one image publication after C's 6641a7e1 baseline
round, then the frozen check. The batch is e4264fa35+35da4bdd4, 25ee76410,
e8960af11, 9bf2953a7 and f0add8697/4aa983499. Current master and its sole
kernel are built together; all existing LTO stays enabled. Entry extraction
475/475 and captured kernel emission 239/239 passed before publication.

The committed controller waits for C's already running old-image OTel counter
guest, then takes image EX and uses the unchanged one-image image recipe.
JOBS=8 is build parallelism only. The base is rebuilt in place, current tag and
canonical tar are replaced, and only the superseded image object is removed.
Raw data stays. No alternate source/build/image/base is kept.

After publication, the exact one-image check entry runs under image SH and
timing EX on its default CPUs 0-7. LOGS only selects the persistent output
directory. Its defined one-sample/10-second/stats-on settings stay unchanged.
No benchmark workload, launcher, compiler flag set or frozen Makefile is edited.

The summary reads each app's raw status/error and counter inventory because
the frozen Make loop can return zero after recording an app failure. It adds
no framework gate or new result.json fields. A diagnostic check is distinct
from C's next official three-sample breadth round. Source status is retained;
peer WIP is preserved and a clean checkout is not an admission condition.

The first dry-run recursively called the frozen image Makefile with -n. A
recursive recipe executed module/BTF build commands despite that option. PERF
stopped only that process tree at 22:31 UTC. The vmlinux and bzImage timestamps
remained 16:21 UTC, and the current image remained 6641a7e1. Its output stays in
the raw directory. Preflight now parses the shell/Python and prints only the
result-local publish command; it does not recurse into the kernel recipe.
The real rebuild runs after the existing guest exits, under image EX.
