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
