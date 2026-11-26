# ARM64 common compiler investigation

2026-11-26T20:46:23Z: todo0 coordinator18:09/18:28 asks for BCC/Katran/Cilium differences
after Tetragon generation. Run8 used Cortex-X925 timing CPUs15-19; the
common production flags select neoverse-n1. The installed Ubuntu Clang18.1.3
accepts the current tune but rejects cortex-x925. compiler-probe.json/log
retain exact stdin source, flags, return codes and diagnostic. This is
capability evidence only, not a performance cause or gain; no alternate
tune sweep, compiler upgrade, nativeP build, image or runtime setting change.
Full x86 timing stays frozen.
