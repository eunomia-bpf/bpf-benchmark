# Replays survive superseded runtime removal

Cilium architecture replay now reads the committed exact-input replay archive
instead of the removed app-runtime-v2 root. The unchanged captured configuration,
ABI overlay and compatibility header reproduce AArch64 compilation and all8
native function links, including the original tail_drop_notify failure.
Run `make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile cilium-native-arch-replay PHASE=NEW_NAME`.

The two cleanup inventories record only lane-A superseded rebuildable outputs.
After the matchedv5 root/image were built and v4 raw results/payload committed,
the oldv4 runtime tree was removed. Finished proof-test initrd build trees and
the completed private helper full-check export were also removed. Their raw
logs, compiled inputs and matched portable result archives remain. The current
runtime is kprog/arm64/build/app-runtime-v5; no other lane's output was removed.
