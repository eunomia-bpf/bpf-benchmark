# Cilium writable guest library directory

The first current native-only Cilium attempt exits in baseline startup before any resident counter or specialization request. Its recorded fatal error is inability to create `/var/lib/cilium/bpf/include/bpf/features.h` on the retained readonly root. This is a runtime filesystem error, not a verifier or generator rejection.

The prepared transport change clones the unchanged 1.7MiB Cilium library tree into guest tmpfs `/run/cilium-lib`, then binds that copy at its original `/var/lib/cilium` path before invoking the unchanged corpus protocol. Cilium can generate its ordinary feature headers there. The original retained root, upstream app source, native inputs, workload, kernel and modules are not rebuilt or edited. The existing app selector/Make entrypoint is reused.

Canonical transport not yet applied; one continuation waits for the current serial queue and readonly-data OTel repair/replay to finish before touching its pinned input, then publishes the three-line change and runs Cilium once. Candidate syntax passes; actual Cilium replay is pending. Original full failure evidence remains at the prior commit in diagnosis.json.
