# native-loader cleanup todo

Working rule: preserve app-level loader semantics for corpus. The shim may
intercept successful app `BPF_PROG_LOAD` calls and replace the returned fd, but
it must not become a second loader or hide native-loader failures behind
fallback lifetime handling.

## Current cleanup targets

- [ ] Delete confirmed dead code in `libnativeloader`:
  `htab_of_map_lookup_elem_kernel_addr()`,
  `kHtabOfMapLookupElemSymbol`, and `walk_map_helper_call_maps()`.
- [ ] Delete shim native-map close/close_range protection code that is now a
  no-op because both guard functions return false.
- [ ] Split `native_loader.cpp` by moving pure logic into internal header-only
  modules. Keep syscall, libbpf, debugfs, and C ABI code in `.cpp` files.
- [ ] Move source bytecode parsing/canonicalization responsibility out of the
  shim and into native-loader.
- [ ] Remove `retained_map_fds` and the shim fd-keeper path after native-loader
  verifies that loaded native stubs retain all relocated maps through kernel
  `prog_info.map_ids`.
- [ ] Change native stub dummy map refs so they do not force x86 host `r15`
  save/restore. Use a caller-saved BPF register and verify the resulting
  `used_maps` set.
- [ ] Make corpus helper target resolution use the original loaded program's
  JIT/xlated oracle only. Do not resolve BPF helper/kernel function targets from
  `/proc/kallsyms` in corpus mode.
- [ ] Keep micro companion-object loading valid, because micro is an experiment
  frontend, not a corpus app loader replacement.

## Verification gates

- [ ] Build `libnativeloader` and `native-link`.
- [ ] Run native-loader shim smoke through the Makefile-owned test target.
- [ ] Run `make micro` with native enabled and confirm native tests pass.
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
