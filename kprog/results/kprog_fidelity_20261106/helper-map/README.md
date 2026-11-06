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

## Arm full-system QEMU: actual bound execution

All13 original workloads were independently generated/compiled from their
Arm native objects and original map declarations. **12 pass** exact kernel
and bound-native64-bit result, retval2 and nonzero-generation checks under
full-system QEMU. **map_hash_str_key fails** load preparation with
`simulator proof contains an unresolved map/kfunc relocation`; the original
kernel BPF result is correct. All13 commands/outcomes remain under `arm64/`;
the suite exits nonzero rather than dropping this program.

The generator now reuses actual declarations from the supplied original source
prelude, preserving name, type, key/value layout and capacity. It fails clearly
if a relocation lacks an original declaration; it does not invent an ARRAY
with a different ABI for these real source objects. This fixes actual hash,
perCPU and multi-map pairing. The generalized test adapter also repeats all13
x86 cases successfully (`x86-arch-adapter/`). Neither workload nor common
runner/launcher was changed.

The remaining Arm failure is native readonly data: the16-byte string-key table
becomes a simulator internal `.rodata` map, while the original BPF stores
constants directly and has no such map. The current loader correctly refuses
an unpaired proof map. T owns its byte/immutability/native-address binding;
we did not relax map identities, replace the real map, change the key, or
move immutable memory into a writable stack surrogate to manufacture a pass.
The failure remains open. Complete build/guest logs and exact original/proof
objects/header+encoder snapshots are retained in the accompanying archive.

```sh
taskset -c 16-23 make -C kprog/fidelity stage2-arm64-build
taskset -c 16-23 make -C kprog/fidelity stage2-arm64-qemu
```

The initramfs uses T's paired Arm kernel/module and the production manifest,
loader and linker. Twelve successful native executions are emulation evidence;
they are neither hardware timing nor an application-program coverage claim.

## Readonly-data binding repair: all13 Arm cases pass

After T's immutable native-data binding repair `f272b2b02`, the same frozen
13 proof/native inputs pass the actual bound full-system QEMU path in
`arm64-readonly-bound/`. Every original expected64-bit result and retval2
matches; every case records a nonzero generation. In particular,
`map_hash_str_key` now returns **18369614221520256751**, with retval2 and
one bound chunk. The previous12/13 outcome remains above and in `arm64/`.
No workload or proof source changed to obtain this pass.

```sh
taskset -c 16-23 make -C kprog/fidelity bound-probe-build-arm64
taskset -c 16-23 make -C kprog/fidelity stage2-arm64-qemu ARM_STAGE2_OUT=../results/kprog_fidelity_20261106/helper-map/arm64-readonly-bound
```

The complete guest console and13 individual JSON/log pairs retain all checks.
This is correctness evidence under emulation; lane R's timing request remains
separate, and no per-program translation-validation certificate is inferred.

The requested R timed replay is complete: all13 programs on allthree
runtimes,117 raw samples, exact expected64-bit results and retval2 throughout.
Per-program execution/load medians and the unmodified raw result are in
`timed-x86/README.md`; timing resolution and missing guest git/generation-count
fields remain explicit. The separate pure simple15 load-time repeat is pending.
