# v4 Deprecation Cleanup

## Summary

This change removes the active v4 and older legacy JIT policy paths from the
kernel and scanner so that BpfReJIT only supports the v5 declarative pattern
format.

## Kernel

- Removed the old `jit_directives_fd` / `BPF_PROG_LOAD` path and its internal
  `bpf_jit_directive_state` plumbing.
- Dropped policy version 1 parsing and made `bpf_jit_parse_policy()` accept
  only version 2 blobs.
- Narrowed policy validation and x86 emission to the v5
  `BPF_JIT_RK_PATTERN` path.
- Kept canonical forms and canonical emitters intact.
- Kept `BPF_PROG_JIT_RECOMPILE` intact.
- Confirmed `BPF_JIT_CF_BITFIELD_EXTRACT` is present in the x86 canonical-form
  dispatcher.

Additional kernel files touched beyond the original target list:

- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`

## Scanner

- Reworked the CLI to a single v5 scan/apply path.
- Removed the v4 engine/blob-builder sources and headers from the scanner tree.
- Reduced the scanner library build to `pattern_v5.cpp` only.
- Rewrote unit tests to cover the v5 builtin scanner/blob path only.
- Kept `--v5` as a compatibility no-op in the CLI so existing v5 automation
  does not need a simultaneous flag cleanup.

## Verification

Kernel build:

```bash
cd vendor/linux-framework
make -j$(nproc) bzImage
```

Result: success

Scanner build and tests:

```bash
cd scanner/build
cmake ..
make -j$(nproc)
ctest --output-on-failure
```

Result: success, `1/1` tests passed

VM smoke:

```bash
sudo vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --cwd /home/yunwei37/workspace/bpf-benchmark \
  --disable-monitor --cpus 2 --mem 4G \
  --exec 'PATH=/usr/local/sbin:$PATH micro/build/runner/micro_exec run-kernel --prog micro/build/programs/simple.bpf.o --repeat 3 --warmup 1'
```

Result: not run successfully in this environment because `vng` is not
installed (`sudo: vng: command not found`).
