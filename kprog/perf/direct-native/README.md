# Direct-native measurement module

Timing only. `bpf_x86_native_lab.c` here is a measurement-only variant of the
native lab kinsn: the native bytes it installs **skip verification** (the
verifier sees an `r0 = 0` stub), so it belongs only in a benchmark guest. The
owner asked for performance numbers first; this restores the path that
produces them.

## What it is

Commit `82f8e9e77` removed the debugfs `blob<N>` endpoints from
`kinsn/module/x86/bpf_x86_native_lab.c`. The benchmark shim's unbound path
(`BPFREJIT_SHIM_NATIVE_LOADER=post`, a manifest, and
`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF` unset) still uploads each 128-byte
chunk to `blob<N>` and its relocations to `blob<N>.relocs`, so the runs
`x86_kvm_corpus_20261109_142708_149898` and `..._150304_777612` replaced zero
programs. This module carries the same module name, debugfs directory and
kfunc as the trusted module and serves `blob<N>`, `blob<N>.relocs`, `map_ptr`,
`map_value_ptr` and `map_update_elem`. The trusted-path module and the verified
path stay as they are; a non-zero generation in the sidecar payload is refused
here (`-EOPNOTSUPP`).

## Build and overlay

Run from `/workspaces/repository` on the Workspace.

```
make -f kprog/perf/direct-native/Makefile image APP=katran \
    PAYLOAD=corpus/results/kprog_app_coverage_20261109/katran-regression-current/inline-producer/payload.tar.gz
make -f kprog/perf/direct-native/Makefile corpus \
    CPUS=0-7 VM_CPUS=8 VM_MEM=64G APPS=katran SAMPLES=3 WORKLOAD_DURATION=180
```

`image` builds the module against `kprog/tv/build-kernel-x86` (the kernel the
restored image boots) into `/var/tmp/kprog-tmp/direct-native/build/module`, then
overlays `bpf-benchmark/kprog-five-step-tracee:r-restored` as
`bpf-benchmark/kprog-direct-native:r-restored`, with
`/artifacts/kinsn/bpf_x86_native_lab.ko` replaced by this module and
`/artifacts/user/native-bpf/x86_64/<APP>/` overlaid from the payload's
`native/<APP>/`. `corpus` boots that kernel and runs the existing
`__runtime-vm-corpus` with the unbound environment and no trusted service; the
framework's module loader installs the overlaid module. Results land in
`corpus/results/x86_kvm_corpus_*` as usual.

## Functional check, 2026-11-09

One 2-second Katran run on CPUs 8-15 with the inline-producer payload:
`corpus/results/x86_kvm_corpus_20261109_160049_938907`, status `ok`.

- Shim log: `native-loader replaced prog=balancer_ingres ... original_id=34 native_id=35`, one replaced, zero failed.
- Post-rejit per-program stats: program 35 (`bytes_jited` 10161, `bytes_xlated` 1288, the stub) with `run_cnt_delta` 3,060,086.
- The shim's JIT dump of program 35 contains a 261-byte exact run of `balancer.native.o` code (object offset 928, JIT offset 979); the dump of the original eBPF program (id 34) matches none of the same 16-byte windows.

Functional only; the 2-second run says nothing about performance.

## Limits

- On the sole stock native-image kernel, optional `blob<N>.sites` uploads carry existing `native_lab_load_site` records (u32 chunk-relative offset, u16 instruction length, u16 recovery register; 0xffff means resume-only). The module rebases them into the whole image and the kernel emits its exception table. Reuploading a blob clears its old sites. The selected linker must explicitly emit `load_site` ABI records, for example with its existing `--abi-load-sites true` option; an empty/default ABI sends no sites and retains the original upload behavior. Module and loader deployment must both precede using recovery in an application.
- Native code per program is capped at 512 chunks of 128 bytes, the same limit as before `82f8e9e77`.
- The restored image's `libnative_loader.so` (from 2026-11-07) does the linking; the overlaid objects must work with it.
