# ZERO_EXT_ELIDE deletion report

Date: 2026-03-20
Workspace: `/home/yunwei37/workspace/bpf-benchmark`

## Scope completed

Completed the remaining full-stack deletion of `ZERO_EXT_ELIDE` from maintained source:

- scanner family support, pattern matching, types, CLI/config parsing, and tests
- kernel selftest coverage and dedicated BPF program
- userspace corpus/generator bookkeeping
- kernel validator/emitter/internal-header support

Intentionally kept:

- shared x86 replay helpers used by `BRANCH_FLIP`
- UAPI enum slot `BPF_JIT_CF_ZERO_EXT_ELIDE = 6`, marked deprecated/reserved for ABI stability

## Reference check

The requested source grep now leaves only:

- deprecated `ZERO_EXT_ELIDE` UAPI/header markers in:
  - `vendor/linux-framework/include/uapi/linux/bpf.h`
  - `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- unrelated kernel/tooling `ZERO_EXTEND` symbols
- generated `vmlinux.h` artifacts under `corpus/build/`

No maintained scanner/tests/userspace/kernel implementation references to `ZERO_EXT_ELIDE` remain.

## Verification

Commands run:

- `make -C vendor/linux-framework -j$(nproc) bzImage`
- `make vm-selftest`
- `make scanner-tests`
- `make smoke`

Results:

- `bzImage`: passed after `make -C vendor/linux-framework clean` repaired a stale/corrupt `vmlinux.o` left in the build tree
- `vm-selftest`: passed, `PASS all 35 test(s)`
- `scanner-tests`: passed, `100% tests passed, 0 tests failed out of 1`
- `smoke`: passed, `SMOKE OK`

## LOC accounting

### Counting basis

The before-count uses the maintained-source line ranges already enumerated in `docs/tmp/zero_ext_elide_deletion_analysis_20260320.md`.

Shared replay helpers retained for `BRANCH_FLIP` are excluded from the `ZERO_EXT_ELIDE` implementation count.

### Before / after

Vendor kernel implementation LOC dedicated to `ZERO_EXT_ELIDE`:

- Before: `118 LOC`
- After: `0 LOC`
- Delta: `-118 LOC`

This `118 LOC` is the sum of:

- `arch/x86/net/bpf_jit_comp.c:2503-2516` = 14
- `arch/x86/net/bpf_jit_comp.c:3184-3189` = 6
- `kernel/bpf/jit_validators.c:1147-1232` = 86
- `kernel/bpf/jit_validators.c:1613-1617` = 5
- `include/linux/bpf_jit_directives.h:77-83` = 7

Deprecated ABI residue intentionally kept:

- `vendor/linux-framework/include/uapi/linux/bpf.h`: `5 LOC`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h`: `5 LOC`

So maintained-source `ZERO_EXT_ELIDE` references changed as follows:

- Vendor runtime tree only: `123 LOC -> 5 LOC`
- Vendor runtime tree plus tools mirror: `128 LOC -> 10 LOC`

### Requested kernel diff total

From `cd vendor/linux-framework && git diff --stat master | tail -3`:

```text
 kernel/bpf/verifier.c              |    2 +
 tools/include/uapi/linux/bpf.h     |   95 ++
 17 files changed, 6606 insertions(+), 263 deletions(-)
```
