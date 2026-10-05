# v6 tier-1 implementation

Date: 2026-03-11

## 1. Shape whitelist / generic site bound

Active v5 validation in `vendor/linux-framework/kernel/bpf/jit_directives.c:374-378` was already generic and only checked `site_len > 0`, `site_len <= BPF_JIT_MAX_PATTERN_LEN`, and canonical-form validity. The practical friction point was the global `BPF_JIT_MAX_PATTERN_LEN=24`, so v6 widens the generic site/pattern upper bound to 64 and keeps `pattern_count == site_len`.

- `vendor/linux-framework/include/uapi/linux/bpf.h:1531-1535`
  - `BPF_JIT_MAX_PATTERN_LEN` raised from `24` to `64`
  - tuple constants later raised from `12` to `16`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:374-378`
  - validator still enforces only the generic bound, not per-form fixed lengths
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp:26-31`
  - scanner ABI constants synced to `BPF_JIT_MAX_PATTERN_LEN=64`

## 2. `BPF_PROG_JIT_RECOMPILE` log buffer

- `vendor/linux-framework/include/uapi/linux/bpf.h:2117-2124`
  - `jit_recompile` now carries `log_level`, `log_size`, `log_buf`
- `vendor/linux-framework/include/linux/bpf.h:63,1710-1713`
  - added forward declaration + `jit_recompile_log` pointer in `bpf_prog_aux`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:65-82,100-105`
  - stored original `user_index` per rule and exported log helpers for JIT backends
- `vendor/linux-framework/kernel/bpf/jit_directives.c:20-166`
  - added kernel-side recompile log buffer allocation, append, copy-to-user, teardown
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1416-1874`
  - added diagnostics for pattern mismatch, constraint failure, binding failure, side-effect rejection, CPU-feature rejection, and subprog-boundary rejection
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2214-2364`
  - added policy-header / descriptor parse diagnostics
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2492-2585`
  - syscall entry now allocates log buffer when `log_level > 0 && log_buf != 0 && log_size > 0`, wires it into `main_aux`, and copies it back to userspace on exit
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3236-3317,3421-3466`
  - x86 canonical emitter now logs final-pass `applied successfully` and `emitter fallback (err=...)`
- `scanner/src/cli.cpp:259-314`
  - `scanner apply` now sends a 16 KiB recompile log buffer and prints kernel diagnostics on failure

## 3. Tuple limit raise: 12 -> 16

- `vendor/linux-framework/include/uapi/linux/bpf.h:1534-1535`
  - `BPF_JIT_MAX_BINDINGS=16`
  - `BPF_JIT_MAX_CANONICAL_PARAMS=16`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:7-9,42-45`
  - internal canonical-param array widened to 16
  - `present_mask` widened from `u16` to `u32`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1605-1655,1680-1746`
  - binding dedup mask widened to `u32`
  - param-present checks and binding extraction bit operations widened to `u32`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp:26-31`
  - scanner ABI constants synced to 16
- `scanner/tests/test_scanner.cpp:314-331`
  - added ABI limit assertions so future regressions fail tests

## 4. Build and test results

### Step 1: generic site bound 24 -> 64

1. `cd vendor/linux-framework && make -j$(nproc) bzImage 2>&1 | tail -20`
   - success: `Kernel: arch/x86/boot/bzImage is ready  (#18)`
2. `cd /home/yunwei37/workspace/bpf-benchmark && cmake -S scanner -B scanner/build && cmake --build scanner/build -j$(nproc) 2>&1 | tail -20`
   - success: `[100%] Built target bpf-jit-scanner`
3. `./scanner/build/test_scanner 2>&1 | tail -10`
   - success: `PASS 50`

### Step 2: `jit_recompile` log buffer

1. `cd vendor/linux-framework && make -j$(nproc) bzImage 2>&1 | tail -20`
   - success: `Kernel: arch/x86/boot/bzImage is ready  (#19)`
2. `cd /home/yunwei37/workspace/bpf-benchmark && cmake -S scanner -B scanner/build && cmake --build scanner/build -j$(nproc) 2>&1 | tail -20`
   - success: `[100%] Built target bpf-jit-scanner`
3. `./scanner/build/test_scanner 2>&1 | tail -10`
   - success: `PASS 50`

### Step 3: tuple/binding limits 12 -> 16

1. `cd vendor/linux-framework && make -j$(nproc) bzImage 2>&1 | tail -20`
   - success: `Kernel: arch/x86/boot/bzImage is ready  (#20)`
2. `cd /home/yunwei37/workspace/bpf-benchmark && cmake -S scanner -B scanner/build && cmake --build scanner/build -j$(nproc) 2>&1 | tail -20`
   - success: `[100%] Built target bpf-jit-scanner`
3. `./scanner/build/test_scanner 2>&1 | tail -10`
   - success: `PASS 53`

## 5. `log_buf` usage example

Raw syscall example:

```c
char log_buf[16384] = {};

struct {
    __u32 prog_fd;
    __s32 policy_fd;
    __u32 flags;
    __u32 log_level;
    __u32 log_size;
    __u64 log_buf;
} __attribute__((aligned(8))) attr = {
    .prog_fd = prog_fd,
    .policy_fd = policy_memfd,
    .flags = 0,
    .log_level = 1,
    .log_size = sizeof(log_buf),
    .log_buf = (uintptr_t)log_buf,
};

syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE, &attr, sizeof(attr));
fprintf(stderr, "%s\n", log_buf);
```

Typical kernel log lines now look like:

```text
rule 3: form 4 site 120-125: pattern match failed at insn 122
rule 5: form 1 site 220-225: constraint 2 failed
rule 7: form 2 site 300-307: applied successfully
```

`scanner/build/bpf-jit-scanner apply --prog-fd <fd> ...` now does this automatically and prints the returned kernel log when `BPF_PROG_JIT_RECOMPILE` fails.
