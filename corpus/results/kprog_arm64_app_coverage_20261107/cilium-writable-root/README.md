# Cilium writable guest library directory

The first current native-only Cilium attempt exits in baseline startup before any resident counter or specialization request. Its recorded fatal error is inability to create `/var/lib/cilium/bpf/include/bpf/features.h` on the retained readonly root. This is a runtime filesystem error, not a verifier or generator rejection.

The prepared transport change clones the unchanged 1.7MiB Cilium library tree into guest tmpfs `/run/cilium-lib`, then binds that copy at its original `/var/lib/cilium` path before invoking the unchanged corpus protocol. Cilium can generate its ordinary feature headers there. The original retained root, upstream app source, native inputs, workload, kernel and modules are not rebuilt or edited. The existing app selector/Make entrypoint is reused.

The complete Cilium baseline/native recipe starts in a private source mount on16-19 with4GiB while the existing OTel8GiB guest continues. Total A guest allocation is12GiB. Workload, samples, native inputs and generation-bound requirements retain their recipe. Kernel-owned map capability and readonly-label builds are pinned at340a4ea5e. Canonical transport publication follows actual OTel closure; Tetragon and Tracee retain their successor order. Runtime outcomes and launch resource settings remain in the complete archives.
