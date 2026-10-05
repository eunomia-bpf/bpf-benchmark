# Scanner Cleanup Results

Date: 2026-03-10

## What was removed from `kernel_runner.cpp`

The runner no longer carries its own scanner/blob implementation. Relative to the pre-cleanup runner copy, the following duplicated code was removed:

| Removed block | Lines removed |
|---|---:|
| Duplicated `BPF_JIT_*` policy/UAPI constants | 32 |
| Local scanner scaffolding (`bpf_insn_raw`, `is_cond_jump_raw`, `is_simple_mov_raw`, `policy_rule`) | 47 |
| `find_cmov_select_sites_xlated()` | 61 |
| `find_wide_load_sites_xlated()` | 154 |
| `find_rotate_sites_xlated()` | 287 |
| `find_addr_calc_sites_xlated()` | 50 |
| `build_policy_blob_from_xlated()` | 59 |
| Obsolete main-subprog trim helper `load_func_info()` | 28 |

Totals:

- Duplicated scanner/blob logic removed: 658 lines
- Total removals directly tied to this cleanup: 718 lines
- Net `kernel_runner.cpp` diff versus the pre-cleanup baseline: 754 deletions, 91 insertions, net `-663` lines

## How the library integration works

### Scanner library

- `scanner/CMakeLists.txt` now exports the static library target `bpf_jit_scanner` as `libscanner.a`.
- A namespaced alias `bpf_jit_scanner::scanner` is available for consumers.
- Public headers are exported from `scanner/include/`.
- Install/export packaging now emits:
  - `lib/libscanner.a`
  - `include/bpf_jit_scanner/*.h*`
  - `lib/cmake/bpf_jit_scanner/bpf_jit_scannerTargets.cmake`
  - `lib/cmake/bpf_jit_scanner/bpf_jit_scannerConfig.cmake`
  - `lib/cmake/bpf_jit_scanner/bpf_jit_scannerConfigVersion.cmake`

### Micro runner

- `micro/runner/CMakeLists.txt` adds `scanner/` as a subdirectory and links `micro_exec` against `bpf_jit_scanner::scanner`.
- The embedded micro build disables scanner CLI/tests only for the runner build tree; standalone scanner builds still produce both.

### Runner call path

`micro/runner/src/kernel_runner.cpp` now:

- includes `<bpf_jit_scanner/scanner.h>` and `<bpf_jit_scanner/policy.h>`
- calls `bpf_jit_scan_cmov()`
- calls `bpf_jit_scan_wide_mem()`
- calls `bpf_jit_scan_rotate()`
- calls `bpf_jit_scan_addr_calc()`
- calls `bpf_jit_build_policy_blob()`
- calls `bpf_jit_patch_policy_blob()` for prebuilt blobs

The runner still owns:

- `--recompile-*` flag handling
- policy memfd creation/sealing
- raw `BPF_PROG_JIT_RECOMPILE` syscall issuance

`scanner/src/scanner.cpp` is now explicitly documented as the authoritative userspace matcher implementation.

## Build verification results

Verified on 2026-03-10:

1. Standalone scanner configure/build:
   - `cmake -S scanner -B scanner/build`
   - `cmake --build scanner/build -j`
   - Result: success, produced `libscanner.a`, `bpf-jit-scanner`, and `test_scanner`

2. Scanner tests:
   - `ctest --test-dir scanner/build --output-on-failure`
   - Result: `1/1` tests passed

3. Scanner install/export smoke test:
   - `cmake --install scanner/build --prefix scanner/build/install`
   - Result: success, installed `libscanner.a`, headers, CLI, and CMake package export files

4. Runner build:
   - `cd micro && make micro_exec`
   - Result: success, `micro_exec` compiled and linked with the scanner library in the micro build tree

## Remaining issues

- No live end-to-end `BPF_PROG_JIT_RECOMPILE` execution was run against a patched kernel in this cleanup pass. Verification here covers build, link, install/export, and scanner unit tests.
- `BPF_PROG_JIT_RECOMPILE` and `BPF_F_JIT_DIRECTIVES_FD` still rely on local numeric fallbacks in userspace because the host UAPI headers do not expose those fields/commands yet. That is separate from the duplicated scanner cleanup.
