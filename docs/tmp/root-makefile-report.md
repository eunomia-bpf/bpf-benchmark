# Root Makefile Report

Date: 2026-03-13

## Summary

Created a root-level `Makefile` at `/home/yunwei37/workspace/bpf-benchmark/Makefile` that unifies:

- build targets: `all`, `micro`, `scanner`, `kernel`, `kernel-tests`, `clean`
- VM targets: `vm-selftest`, `vm-micro-smoke`, `vm-micro`, `vm-corpus`, `vm-e2e`, `vm-all`
- fast validation targets: `smoke`, `check`, `validate`

## Implementation Notes

- `micro` delegates to `make -C micro micro_exec programs`
- `scanner` uses CMake configure + build in `scanner/build`
- `kernel-tests` delegates to `make -C tests/kernel`
- `kernel` builds `vendor/linux-framework/arch/x86/boot/bzImage`
- all Python entrypoints activate `$(VENV)` first
- all direct VM targets use `vng --run ... --rwdir ... -- bash -lc '...'`
- `vm-corpus` is the only exception in spirit: it calls `corpus/run_corpus_v5_vm_batch.py`, and that harness already manages one `vng` boot per target internally
- `bzImage` is wired as an order-only prerequisite for VM targets so they do not force a kernel rebuild on every invocation
- smoke / VM smoke outputs are written to `docs/tmp/root-makefile-*.json` to avoid overwriting committed benchmark aliases

## Verification

### 1. `make --dry-run all`

Result: passed.

Representative expansion:

```text
echo "=== Running make all ==="
make micro
make scanner
make kernel-tests
```

The sub-makes expanded to the expected `micro`, `cmake`, and `tests/kernel` build commands.

### 2. `make scanner`

Result: passed.

Observed outcome:

- CMake configure succeeded in `scanner/build`
- `libscanner.a` built successfully
- `bpf-jit-scanner` linked successfully

### 3. `make smoke`

Result: passed.

Executed command:

```text
python3 micro/run_micro.py --runtime llvmbpf --bench simple --iterations 1 --warmups 0 --repeat 10 --output docs/tmp/root-makefile-smoke.json
```

Observed benchmark result:

- benchmark: `simple`
- runtime: `llvmbpf`
- compile median: `6.234 ms`
- exec median: `81 ns`
- result: `12345678`

Output written to:

- `docs/tmp/root-makefile-smoke.json`

### 4. `make --dry-run vm-selftest`

Result: passed.

Expanded command:

```text
vng --run "/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage" --rwdir "/home/yunwei37/workspace/bpf-benchmark" -- \
	bash -lc 'cd "/home/yunwei37/workspace/bpf-benchmark" && sudo -n "/home/yunwei37/workspace/bpf-benchmark/tests/kernel/build/test_recompile"'
```

This matches the required `vng --run $(BZIMAGE) --rwdir <dir> -- bash -lc '...'` shape.

### Additional Spot Check: `make scanner-tests`

Result: passed.

Observed outcome:

- `test_scanner` built successfully
- `ctest --test-dir scanner/build --output-on-failure` ran `1/1` test and passed

This confirms the `scanner-tests` step used by `make check` is runnable.

## Fixes Needed During Validation

None. The new `Makefile` passed the requested validations without further code changes.
