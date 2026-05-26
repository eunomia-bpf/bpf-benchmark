# native-loader cleanup todo

Working rule: preserve app-level loader semantics for corpus. The shim may
intercept successful app `BPF_PROG_LOAD` calls and replace the returned fd, but
it must not become a second loader or hide native-loader failures behind
fallback lifetime handling.

## Current cleanup targets

- [x] Delete confirmed dead code in `libnativeloader`:
  `htab_of_map_lookup_elem_kernel_addr()`,
  `kHtabOfMapLookupElemSymbol`, and `walk_map_helper_call_maps()`.
- [x] Delete shim native-map close/close_range protection code that is now a
  no-op because both guard functions return false.
- [x] Split `native_loader.cpp` by moving pure logic into internal header-only
  modules. Keep syscall, libbpf, debugfs, and C ABI code in `.cpp` files.
- [x] Move source bytecode parsing/canonicalization responsibility out of the
  shim and into native-loader.
- [x] Remove `retained_map_fds` and the shim fd-keeper path after native-loader
  verifies that loaded native stubs retain all relocated maps through kernel
  `prog_info.map_ids`.
- [x] Change native stub dummy map refs so they do not force x86 host `r15`
  save/restore. Use a caller-saved BPF register and verify the resulting
  `used_maps` set.
- [x] Make corpus helper target resolution use the original loaded program's
  JIT/xlated oracle only. Do not resolve BPF helper/kernel function targets from
  `/proc/kallsyms` in corpus mode.
- [x] Keep micro companion-object loading valid, because micro is an experiment
  frontend, not a corpus app loader replacement. The companion `.bpf.o` load now
  lives in the micro runner frontend, not in native-loader.

## Verification gates

- [x] Build `libnativeloader` and `native-link`.
- [x] Run native-loader shim smoke through the Makefile-owned test target.
- [x] Run `make micro` with native enabled and confirm native tests pass.
- [ ] Run corpus apps one at a time with native enabled: `bcc/set`,
  `tetragon/observer`, `tracee/monitor`, `katran`, `cilium/agent`, and
  `otelcol-ebpf-profiler`.
- [ ] After each app works individually, run full `make corpus` and `make micro`
  again.
- [ ] Record final correctness and performance with both configurations:
  BPF stats runcnt/run-time data, and workload metrics with BPF stats disabled.

## Notes

- If a corpus program cannot provide a complete helper-call oracle from its
  original `prog_fd`, native loading should fail-fast instead of falling back to
  `/proc/kallsyms` or returning the original fd.
- If native stub map retention does not show every relocated map id in
  `prog_info.map_ids`, native loading should fail-fast instead of asking the
  shim to keep extra fds alive.
- Current implementation note: native-loader has a single core path,
  `load_from_program_fd(original_prog_fd, source_insns, native_object_path)`.
  The micro runner frontend owns `.bpf.o` companion loading and passes the
  loaded program fd plus libbpf source bytecode. The corpus shim owns
  `BPF_PROG_LOAD` interception and passes the real app program fd plus captured
  source bytecode. After that boundary, both flows share the same native-loader
  logic.
- Kernel symbol lookup is removed from this path. Helper/map targets come from
  the original loaded program's JIT/xlated oracle and captured source bytecode;
  missing oracle data is a native-load failure, not a `/proc/kallsyms` fallback.
- The old shim fd-keeper child and retained-map C ABI are removed. Loader now
  reopens relocated map fds only for stub verification/load, validates
  `prog_info.map_ids` on the native program, and closes the temporary fds before
  returning to the shim.
- `append_dummy_map_refs()` already uses caller-saved BPF `r1` in this tree, so
  the earlier `r9`/x86 `r15` save/restore issue was stale. The retained-map
  verification added above is the guard that makes this path fail-fast.
- 2026-05-26 micro smoke:
  `SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 SUITE=micro/config/micro_stage2.yaml RUNTIMES="kernel native_kernel" make micro`
  passed all 13 stage2 benchmarks. Result path:
  `micro/results/x86_kvm_micro_20260526_040828_768796`. Kernel and
  `native_kernel` returned matching values for every benchmark.
- 2026-05-26 cleanup issue: removing kallsyms exposed an x86 helper-oracle skew
  in `combined_helper_map`. `bpf_get_smp_processor_id` needed special
  JIT-decoded `cpu_number`/`this_cpu_off` inputs; otherwise subsequent helper
  call sites consumed the wrong oracle target. The fix is fail-fast when those
  values cannot be decoded. Targeted verification:
  `SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 SUITE=micro/config/micro_stage2.yaml RUNTIMES="kernel native_kernel" BENCH="combined_helper_map" make micro`
  passed with result path
  `micro/results/x86_kvm_micro_20260526_045907_110344`.
- 2026-05-26 full micro re-run after the single-path/no-kallsyms cleanup:
  `SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 SUITE=micro/config/micro_stage2.yaml RUNTIMES="kernel native_kernel" make micro`
  passed all 13 stage2 benchmarks. Result path:
  `micro/results/x86_kvm_micro_20260526_050316_297141`. Kernel and
  `native_kernel` returned matching `result`/`retval` for every benchmark.
