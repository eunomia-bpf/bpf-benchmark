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

2026-11-16T22:59:48Z: The publication controller now accepts an explicit persistent raw
directory, so a follow-up publication preserves this first build/check rather
than overwriting its logs. Script parsing and the result-local dry-run pass.
This changes only experiment bookkeeping, not the frozen recipe or entry.

For follow-up publications, the controller records Docker's actual image
inventory and removes the exact superseded object if it is still present.
An already absent object requires no deletion. Errors in inventory collection
or a required removal remain visible. This enforces the existing one-image
resource rule and does not add a benchmark admission condition.

Completed frozen check, 2026-11-16T23:05:09Z

Image sha256:96a677d6826f341f7d6557a5b2986680e17722e1d51d78d38ad7c6f0416284c9. Kernel source 83e0fabe355d6cf682ba9ce2bb575f1ee1214a16.
The six-app check completed; app statuses, rather than Make exit0, are:

| App | Status | Native replacement events | JIT/native installed B in window | JIT/native ns per call |
| --- | --- | ---: | ---: | ---: |
| otelcol-ebpf-profiler/profiling | error | 2 | native window unavailable | native window unavailable |
| bcc/set | ok | 25 | 7965/7962 | 144.191/145.304 |
| cilium/agent | error | 0 | native window unavailable | native window unavailable |
| tetragon/observer | error | 11 | native window unavailable | native window unavailable |
| tracee/monitor | ok | 169 | 2068774/1690844 | 367.539/319.616 |
| katran | ok | 1 | 13641/9442 | 174.749/172.907 |

Replacement events include loads before a measurement window and are not
the window program count. Tracee has169 replacements and167 records per arm.
The error arms have partial native loads, with no native timing window.
These one-sample10-second figures are diagnostic counters, not the official
three-sample performance claims. No PMU body/helper/map split was collected.

The two failed classes are fixed in source:3940c4bee conditional Jcc tails
for Tetragon; a53922beb retained LPM symbol for OTel/Cilium. Full host replay
475/239 and the canonical loader build pass. The next publication waits for
this check controller to exit and uses a fresh persistent raw directory:
/workspaces/kprog-raw/perf/20261116-native-load-corrections.
C starts its next breadth round after the corrected image check succeeds.

2026-11-16T23:35:30Z: Following coordinator23:27, future builds take timing SH before image EX; functional/timing check takes timing EX before image SH. Timing SH is released before the following check requests EX, avoiding a lock upgrade deadlock. Existing completed jobs are unchanged.
