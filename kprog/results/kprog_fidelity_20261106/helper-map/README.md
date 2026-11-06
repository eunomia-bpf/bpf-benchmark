# Bound helper/map correctness, x86 KVM

All thirteen cases from `micro/config/micro_stage2.yaml` pass on the actual
generation-bound path. Each per-case log records the kernel result/return
value, the bound program ID and nonzero-generation sidecar count, then the
native result/return value. Both results match the unchanged suite's expected
value, and every return value is 2.

`x86/*.json` records each command/outcome; `x86/*.log` retains its output.
`proof-build.log.gz` and `make-kvm.log.gz` retain the build and guest logs.
`bound-stage2-artifacts.tar.gz` preserves the compiled proofs, production
header snapshot, native-link proof objects, source and build records.
The original BPF/native workload objects under `kprog/test/build-x86` are
unchanged; simulator declarations come from their real map definitions, and
T's production loader reuses their map identities before sealing the proof.

```sh
taskset -c 16-23 make -C kprog/fidelity stage2-build
taskset -c 16-23 make -C kprog/fidelity stage2-kvm
```

The test runs through Make and T's paired x86 kernel/module, pinned to host
CPUs 16-23, with two guest CPUs and 2 GiB. It changes no common runner, workload,
or runtime image. This is correctness testing, not a timing result; R still
owns the requested timed stage2 comparison and load-time confirmation.

The two preliminary failed attempts are retained in `x86-pre-name-fix` and
`x86-pre-info-fix`. They exposed test-driver defects: manifests initially
used names longer than the kernel's 15-byte name, and the second program-info
query reused returned JIT/map lengths without destination buffers. The driver
now uses the actual kernel name and requests only the translated instructions.
The final pass checks nonzero-generation native execution explicitly.

## Optional-symbol loader regression

`x86-symbol-guard/` independently repeats all13 configured cases after the
loader stopped resolving the optional kernel helper catalogue for pure bound
programs. All13 pass the original expected result, retval2 and nonzero-generation
checks. Helper/perCPU inputs continue through their required resolver. The
fresh proof build uses the current typed helper dispatch; it does not reuse
an earlier BPF object. `symbol-guard-build.log.gz` and
`symbol-guard-kvm.log.gz` retain complete build/guest output.

```sh
taskset -c 16-23 make -C kprog/fidelity stage2-build STAGE2_BUILD=build-x86/stage2-symbol-guard
taskset -c 16-23 make -C kprog/fidelity stage2-kvm STAGE2_BUILD=build-x86/stage2-symbol-guard STAGE2_OUT=../results/kprog_fidelity_20261106/helper-map/x86-symbol-guard
```
