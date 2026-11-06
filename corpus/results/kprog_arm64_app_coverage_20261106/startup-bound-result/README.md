# Strict generation-bound ARM application startup

The actual application-linked libbpf startup issues six programs: coarse-time
probe, anonymous zero, name test, function-IP context probe, cgroup-socket
probe and main. Both flags0 and flags8 complete with six loads and six native
replacements, no probe/name bypass, main return127 and nonzero generation1.
The shim is the published strict0bff849bf; loader is T context-v2-func-ip,
with matched6836f7d44 kernel/modules. Every captured source/name/type selector
and the raw logs remain. Original flags are checked for all six loads.

ARM native-link previously dropped R_AARCH64_JUMP26 helper tail relocations,
turning the coarse-time probe into a self-loop. The repair retains the caller
LR through a16-byte frame around the normal helper call in proof and kernel
modes, then returns through the appropriate continuation. Direct cross-symbol
tail branches now discover and retain transitive callees. The nested test
caught a native PAC crash caused by omitting a resolved tail-branch callee;
the complete failed run remains. Both direct-helper and local-tail-to-helper
source/simulator/bound comparisons now produce37, retval2, generation1.
All73 Rust tests and both release builds pass. Final startup rerun passes.

Early diagnosis incorrectly assumed the first anonymous request was the zero
probe. Stage diagnostics established that it was the coarse-time probe and
selected its exact captured source correctly. There is no demonstrated source
capture or libbpf EXIT corruption; no consumer or shim requirement was weakened.

Replay: extract replay.tar.gz, then `make -C runtime run`. On DGX Spark use
`make -C runtime run ACCEL=kvm CPU=host`. The matched kernel/initrd and all
source/native/proof/simulator inputs are built into the bundle. Rebuild in the
repository with the dated Makefile's startup-arm64-build PHASE=NEW_NAME,
then startup-arm64-check PHASE=NEW_NAME. The five startup probe triples are
installed into all six stage manifests via startup-arm64-install. This closes
the demonstrated common startup path; full application native workloads and
all additional app-specific programs are still being implemented and run.
