# Production Recompile `EINVAL` Debug

Date: 2026-03-10

## Summary

The `BPF_PROG_JIT_RECOMPILE` `EINVAL` on the production corpus was not caused by a production-only validator bug.

The actual blocker was an in-repo kernel/userspace ABI split:

- `scanner/` and `micro_exec --recompile-v5` emit **v5 policy blobs**:
  - `version = 2`
  - variable-length `bpf_jit_rewrite_rule_v2`
  - `rule_kind = BPF_JIT_RK_PATTERN`
- `vendor/linux` on branch `jit-fixed-baselines` was still a **v4-only parser/emitter tree**:
  - only `BPF_JIT_POLICY_VERSION = 1`
  - only fixed-size `struct bpf_jit_rewrite_rule`
  - no `BPF_JIT_RK_PATTERN` / canonical-form v5 support

So any program with at least one v5 site produced a non-empty v5 blob and hit `-EINVAL` in `bpf_jit_parse_policy()` before meaningful rule validation. Programs with zero sites never issued the syscall, which is why they did not fail.

This also explains the apparent contradiction with the earlier micro-benchmark v5 results: those 2026-03-10 results were produced against `vendor/linux-framework`, which already had the v5 parser/emitter path, not against the current `vendor/linux` tree.

## Evidence

- `vendor/linux` before the fix:
  - `include/uapi/linux/bpf.h` only defined `BPF_JIT_POLICY_VERSION = 1`
  - `kernel/bpf/jit_directives.c` hard-rejected any `hdr->version != BPF_JIT_POLICY_VERSION`
  - `kernel/bpf/jit_directives.c` expected `sizeof(hdr) + rule_cnt * sizeof(struct bpf_jit_rewrite_rule)`
- `vendor/linux-framework` already contained:
  - `BPF_JIT_POLICY_VERSION_2`
  - `BPF_JIT_RK_PATTERN`
  - `struct bpf_jit_rewrite_rule_v2`
  - v2 parsing in `bpf_jit_parse_policy()`
  - x86 canonical emitters for v5 rules

Working-vs-failing blob comparison after dumping live xlated programs:

| Program | Xlated insns | Sites | Policy bytes | Notes |
| --- | ---: | --- | ---: | --- |
| `log2_fold` | 139 | `cmov=6` | `824` | known-working micro v5 case |
| `balancer_ingress` | 2984 | `cmov=5, wide=4` | `1252` | formerly failing production case |

Both are valid v5 blobs. The former production failure was not caused by a malformed `prog_tag`, `insn_cnt`, or a special Katran-only shape; it was caused by sending a valid v5 blob to a kernel tree that only understood v1/v4 blobs.

## Fix

Synced the v5-capable kernel pieces from `vendor/linux-framework` into `vendor/linux`:

- `vendor/linux/include/uapi/linux/bpf.h`
- `vendor/linux/include/linux/bpf_jit_directives.h`
- `vendor/linux/kernel/bpf/jit_directives.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`

Then added explicit validation logging in `vendor/linux/kernel/bpf/jit_directives.c`:

- `pr_warn()` for header/version/length/tag/arch parse failures
- `pr_warn()` for v2 rule-format failures
- `pr_info()` for per-rule rejection during activation
- `pr_warn()` when `policy->active_cnt == 0`

## Build

- `make -C vendor/linux -j$(nproc) bzImage` : success
- `make -C micro micro_exec` : success

## Retest

Validated one micro v5 case plus three production programs that previously failed with `EINVAL`.

| Program | Sites found | Policy bytes | Recompile applied | JIT bytes after recompile | Result |
| --- | --- | ---: | --- | ---: | --- |
| `micro/programs/log2_fold.bpf.o:log2_fold_xdp` | `cmov=6` | `824` | `yes` | `682` | pass |
| `corpus/build/katran/balancer.bpf.o:balancer_ingress` | `cmov=5, wide=4` | `1252` | `yes` | `13626` | pass |
| `corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct` | `cmov=1` | `164` | `yes` | `708` | pass |
| `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func` | `cmov=2` | `296` | `yes` | `549` | pass |

Observed behavior after the fix:

- `recompile.syscall_attempted = true`
- `recompile.applied = true`
- `recompile.error = ""`
- no validation warnings were emitted in guest `dmesg` for these successful cases

## Conclusion

The production-corpus `EINVAL` was caused by `vendor/linux` lagging behind the v5 userspace ABI, not by a production-only `prog_tag`, `insn_cnt`, subprog-boundary, or site-range bug.

The blocker is resolved for the tested cases. The next sensible step is rerunning the full production v5 corpus on the rebuilt `vendor/linux` tree.
