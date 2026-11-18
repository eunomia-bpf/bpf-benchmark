## Base state at 2026-11-18T03:36Z (after the in-place loader rebuild)

| piece | sha256 (16) | note |
|---|---|---|
| verified-loader/trusted-native-loader | `aaa5e34038b8f5b5` | rebuilt 03:32Z; carries items 5(a) kallsyms fast path, 5(b) whole verifier log, 5(c) uncovered data symbols, 5(d) private readonly symbols. Previous `430a337f2c316c4e` (11-17 20:27Z) predated all four. |
| verified-module/bpf_x86_native_lab.ko | `317e2e9ad8337126` | 11-17 20:44Z, unchanged by this rebuild; still the two-field `map_value_ptr` module. |
| bpfopt/shim/libbpfrejit_shim.so | `6bebf558481c5902` | carries item 5(f): `native_loads_inflight`, `native_bound_completed`, the `verified program kept on eBPF` log line. |
| bpfopt/shim/build-x86/libbpfrejit_shim.so | `6bebf558481c5902` | the copy the image ships; refreshed by `make host-shim-x86` so the next image build carries 5(f). It was `39a64d07bfe28ee2` (11-17 03:06) before. |
| image bpf-benchmark/kprog:current | `55c1c443202c` | still the 11-17 16:46 build; its shipped shim predates 5(f). Rebuild pending the batch lock. |

Checks on the rebuilt loader, all four passing (`taskset -c 20-21 make -C kprog/fidelity ...`):
`check-loader-kallsyms` (115 symbols, names and addresses agree), `check-loader-data-symbols`,
`check-loader-verifier-log`, `check-loader-data-layout`. Shim: `make host-selftest` PASS 5/5, including
`t4_list_progs_json`, which requires both 5(f) fields in the response.
