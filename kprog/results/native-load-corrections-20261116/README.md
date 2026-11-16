Corrected native-load publication, 2026-11-16T23:18:02Z

Image603cacfb442a replaces96a677d6826f through the frozen recipe. Docker
lists only current. Source4edcdadc2 includes conditional Jcc tail closure
3940c4bee and retained LPM target a53922beb, with all LTO enabled. Kernel
83e0fabe355d and the one base remain in place. Publication facts are in
publication.json; full raw root is /workspaces/kprog-raw/perf/20261116-native-load-corrections.

OTel231435_454436 completes app ok:14 native replacements, zero native-load
failures. Its measurement window has13 programs per arm. Installed JIT/native
bytes167504/134085; counters6080942/7708501 calls and14964334137/22631492367
ns. This confirms the LPM address binding loads correctly. The ten-second
functional check is not an official performance result, and no PMU split or
new unwind-counter equal-work claim is inferred. Remaining apps are running.

The next Cilium diagnostic can test the original and native programs of the
same app load: shim_native_loader.h:338-350 retains a shadow original FD.
Its original/native jit-info records pair kernel program IDs. Thus one actual
benchmark packet and the same live maps/config can be used for both tests,
without loading another BPF object or retaining a second image. This avoids
confounding a packet comparison with a later recreated endpoint/MAC/config.
Packet return, returned skb context and observed redirect target remain to run.

2026-11-16T23:24:48Z: BCC231828_394807 passes25 native replacements and no load errors.
Cilium232152_617481 passes113 replacements and no load errors. Both arms
have53 measurement-window programs; installed JIT/native233900/204607B.
The earlier per-packet host-path difference does not recur here: native
cil_to_host and cil_from_host have0 calls, while JIT has only two one-off
calls across those programs. The two cil_from_container records have
6043120/6108847 JIT calls and17859021/17929970 native calls; raw time and
all selected path records are in cilium.json. This is a diagnostic window,
not yet an official timing or proof that every packet takes equal work.
The same-load paired packet test is the next correctness check.

2026-11-16T23:30:36Z: Tetragon232540_669421 completes app ok with288 native replacement
events and zero native-load failures. The JIT/native measurement windows have287/225 records; they are not the same inventory.
This confirms the conditional-Jcc closure fix in the real policy/CEL load
context, which was absent from the earlier239 retained kernel plans. Raw
phase counters and installed bytes are retained in tetragon.json. B generation
and stock verification are separate and remain unmeasured in this check.

2026-11-16T23:46:29Z: The complete frozen check finishes with all six app statuses ok
on image603cacfb442a. Source4edcdadc2, kernel83e0fabe355d and full raw
phase/window counters are in summary.json. Native replacement events are
OTel14, BCC25, Cilium113, Tetragon288, Tracee169 and Katran1, with zero
native-load failures in these completed logs. This establishes successful
loads, not B-stock or whole-app equal-work proof.

Tetragon's corrected inventory audit finds288 unique native load IDs and225
IDs in its counter window; all225 are present in the load log. The63 absent
load IDs are event_exit_disa1, generic_retkpro6 and generic_kprobe_56. The
latter form seven repeated size families with eight copies each. This is
a structured inventory difference, not evidence that those calls were zero
or that attachments failed. Baseline/native positive-record counts are35/25.
The original-source info and ID pairs are retained in tetragon-inventory.json;
reproduce with make inventory. FD/program-array lifetimes and tracker/source
identity are next read-only leads, with no source change outside the freeze.

C's next breadth round now holds timing EX on0-7. Future heavy work takes
timing SH before image locks. Packet retry2103056 is queued on that shared
lock and has not started a VM; it uses fresh raw retry1 after the first
callback's capture timeout. The earlier diagnostic guest2099055 is terminal.
The kernel and frozen paths remain as the operator's23:42 freeze specifies;
production work is now confined to open LTO paths.
