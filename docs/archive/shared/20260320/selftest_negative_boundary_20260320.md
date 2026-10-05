# Selftest Negative/Boundary Coverage Update

Date: 2026-03-20

## Scope

Updated `tests/kernel/test_recompile.c` and added new test BPF fixtures under `tests/kernel/progs/` only.

New fixtures:

- `tests/kernel/progs/test_cross_subprog_boundary.bpf.c`
- `tests/kernel/progs/test_interior_edge.bpf.c`
- `tests/kernel/progs/test_struct_ops_tcp.bpf.c`
- `tests/kernel/progs/test_zero_applied_noop_select.bpf.c`

## Added Coverage

New or strengthened selftests now cover:

- overlapping rules rejected
- cross-subprog rule rejected
- invalid `native_choice` rejected
- unsupported arch/form rejection
- reserved policy flags rejected
- interior edge rejected
- blinded program rejected
- live `struct_ops` program rejected
- concurrent recompile robustness
  - existing `EBUSY` test now also verifies a follow-up recompile and post-race program result

Existing coverage retained and re-verified:

- site beyond program bounds (`test_site_out_of_bounds`)
- concurrent recompile (`test_concurrent_recompile`)

## Behavior Notes

### Blinded program rejection

In this VM, `bpf_jit_harden=1` does not blind CAP_BPF-capable loads. The selftest had to force:

- `/proc/sys/net/core/bpf_jit_harden = 2`

That reliably produces `prog->blinded` and the expected `-EOPNOTSUPP`.

### Zero-applied policy path

I added a best-effort probe for the `no rules applied; kept the pre-recompile image` path using a self-referential `COND_SELECT` candidate. On the current x86 kernel, that candidate is treated as applied, so the strict zero-applied kernel branch was not triggered in VM.

What the test does verify:

- the candidate policy succeeds
- program behavior is preserved
- the runtime log clearly shows whether the kernel took the true zero-applied path or actually applied the candidate

Observed in VM:

- `zero-applied candidate preserved 0x901 but applied on this kernel`

So item 10 is only covered as a best-effort probe, not as a deterministic reproduction of the kernel's `jit_recompile_num_applied == 0` branch.

### Rollback after staging failure

I did not find a deterministic tests-only trigger for the hard rollback path in `jit_directives.c` without modifying kernel implementation. In particular, I did not find a policy/program pair that:

1. passes parsing and validator normalization,
2. enters staged re-JIT,
3. fails hard enough to return syscall error rather than emitter fallback,
4. is reproducible from `tests/kernel/` alone.

The suite therefore still does not directly prove the mid-flight failure rollback path from item 8.

## Verification

Commands run:

```bash
make -C vendor/linux-framework -j"$(nproc)" bzImage
make kernel-tests
make vm-selftest
```

Results:

- `bzImage`: success
  - `Kernel: arch/x86/boot/bzImage is ready  (#76)`
- `make kernel-tests`: success
- `make vm-selftest`: success
  - `PASS all 36 test(s)`

## Net Result

The negative/boundary selftest suite grew from 27 to 36 passing VM tests and now directly covers the major parser/validator/rejection paths identified in the design review, with two explicit remaining gaps:

- deterministic `zero-applied` reproduction on current x86
- deterministic hard rollback-after-staging-failure reproduction
