Host-validated lookup/map-ops batch publication, 2026-11-16

Coordinator 22:20 requests one image publication after C's 6641a7e1 baseline
round, then the frozen check. The batch is e4264fa35+35da4bdd4, 25ee76410,
e8960af11, 9bf2953a7 and f0add8697/4aa983499. Current master and its sole
kernel are built together; all existing LTO stays enabled. Entry extraction
475/475 and captured kernel emission 239/239 passed before publication.

The committed controller waits for C's already running old-image OTel counter
guest, then takes image EX and uses the unchanged one-image image recipe.
JOBS=8 is build parallelism only. The base is rebuilt in place, current tag and
canonical tar are replaced; the superseded image object was already absent
after this build.
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

Publication completed as image 96a677d6826f at 22:44 UTC. The controller then
stopped on an unnecessary explicit removal of the already absent old image.
Docker's image inventory contains only current; the actor that removed the
old object is not established by the build log. The redundant removal is
deleted forward, and the result-local check target resumes the unchanged
frozen check on this finished image. The first controller's failure and log
remain retained. No rebuild is needed to resume the check.

LPM target failure and forward correction, 2026-11-16T22:57:44Z

OTel 224734_587583 fails perf_unwind_native on named LPM map
pid_page_to_mapping_info. Cilium 225345_805000 fails cil_xdp_entry on
cilium_cidr_v4_dyn. Both name a Call target address of zero. The sole
kernel has trie_lookup_elem (System.map ffffffff814ced00), but the loader's
kallsyms_table only retains its explicit wanted names, and the new LPM
selection had omitted that function. Host replay plans had retained nonzero
addresses and did not exercise this live collection step.

One wanted-name entry now retains trie_lookup_elem in the same load-time
cache as the other map lookup functions. This applies to every LPM map,
adds no runtime check or refusal, and keeps link-time target selection.
The canonical loader build passes. The current image predates the correction;
actual new-image loads and per-call/installed effects remain pending.

BCC 225014_025710 finishes app ok, with all 25 measured programs replaced
by native. Its ten-second diagnostic sums are JIT/native 95437971/93825612
calls and 13761318318/13633217882 ns; installed 7965/7962 B. This is the
frozen functional check, not the next official three-sample timing result.
Tetragon 225559_070245 repeats the conditional-tail error at IP0x3a4, already
fixed in source by 3940c4bee. Tracee and Katran still follow in the check.
