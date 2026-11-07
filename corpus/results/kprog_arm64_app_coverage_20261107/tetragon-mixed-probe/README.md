# Tetragon mixed BPF-call/tail-call startup selector

The closed 9421a4ad9 run has 152 baseline resident counter rows, no native specialization requests and no native measurement. Its first missing manifest entry is an anonymous11-instruction raw-tracepoint program. Exact upstream revision8ca052908 defines it in pkg/bpf/detect_linux.go::detectMixBpfAndTailCalls. A reconstructed instruction stream with the observed mapFD6 matches BOTH rawca47d4f26feca335 and normalized7f60b6fbd3faebcf hashes. The original raw bytecode was not retained in that first run; these matching hashes corroborate the reconstruction but are not treated as cryptographic byte-identity proof.

The existing generic llvmbpf frontend emits LLVM, normal LLVM optimization/backend emits AArch64, and the production native-link/generator compiles its proof. No handwritten native renderer, helper special case, probe skip, simulator, loader, kernel or verifier change is added. The runtime manifest compares the full source bytecode, neutralizing only the validated mapFD immediate at source instruction3; its source-map binding points to that exact runtime instruction. The staged new entry submits only native ELF and supplies no simulator/proof path. All prior245 selectors remain unchanged.

Build frontend once with its existing Make target if absent, then build the probe:

```sh
make -f corpus/results/kprog_app_coverage_20261106/Makefile lift-bpf-ir-build
make -f corpus/results/kprog_arm64_app_coverage_20261107/tetragon-mixed-probe/Makefile build
```

summary.json retains compiler/source/ELF hashes and the exact stage delta; artifacts.tar.gz includes original/reconstructed bytes, IR, native ELF, compiled proof, full commands and before/after manifests. This is generation/compilation evidence only. Actual selector matching, kernel admission and full Tetragon work remain pending. The existing Katran/Tracee queue uses different manifests and is preserved; the Tetragon replay follows the queued readonly and Cilium repairs. QEMU timing is functional only.
