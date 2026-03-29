# Pass Coverage Investigation (2026-03-28)

## Scope

Investigate why corpus/static-verify reported only `345 / 1241 = 27.8%`, identify the real blocker, fix it, and rerun static verification.

## What Static Verify Actually Runs

`make vm-static-test` runs [`daemon/tests/static_verify.py`](/home/yunwei37/workspace/bpf-benchmark/daemon/tests/static_verify.py), which dispatches `static_verify_object` jobs through the C++ batch runner. It does not pass `--enabled-passes`, so the daemon default pipeline is used.

Current default pipeline in source order:

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

So static verify is not running a reduced subset. It is running the full default performance pipeline.

## Const Prop And Verifier Logs

The current `const_prop` implementation in [`daemon/src/passes/const_prop.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs) is CFG/dataflow based. It does not read verifier logs.

Verifier-log capture does exist in [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs), but it is only attached opportunistically for programs containing `bpf_map_lookup_elem()`, and is consumed by verifier-guided key extraction in [`daemon/src/passes/map_inline.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs). So "const_prop is blocked because static verify forgot to fetch verifier logs" is not the root cause on the current tree.

## Root Cause Of The Reported 27.8%

The old summary in `daemon/tests/results/static_verify.json` was:

- `531` objects
- `1241` programs
- `345` `programs_applied`
- `345` verifier accepted

That looked like a global pass-coverage failure, but it was misleading in two independent ways:

1. `programs_applied` in [`daemon/tests/static_verify.py`](/home/yunwei37/workspace/bpf-benchmark/daemon/tests/static_verify.py) counts every daemon-`ok` record whose `applied` bit is true. In practice that includes identity REJITs, so it is not the same thing as "program changed by at least one pass".
2. The daemon died partway through the run, so most of the apparent "misses" were actually never processed successfully.

Old record breakdown from the preserved backup [`docs/tmp/20260328/static_verify_old_20260328.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/static_verify_old_20260328.json):

- `345` `ok`
- `275` truly changed
- `70` `ok` but unchanged
- `896` `error`
- `159` `skip_load`

Top old error causes:

- `886` `connect() failed: Connection refused`
- `7` `read() failed: Connection reset by peer`
- `1` `daemon closed connection before responding`
- `1` `BPF_PROG_REJIT: Bad address (os error 14)`

That is a daemon survivability failure, not a corpus-wide pattern miss.

The crash boundary was in `corpus/build/calico/from_hep_debug.bpf.o`:

- `calico_tc_main`: `ok`
- `calico_tc_skb_a`: `ok`
- `calico_tc_skb_n`: `ok`
- `calico_tc_skb_i`: `read() failed: Connection reset by peer`
- next program: first `connect() failed: Connection refused`

Before the first `ECONNREFUSED`, the run had:

- `324` daemon-`ok` programs
- `260` truly changed programs
- `64` daemon-`ok` but unchanged programs
- `3` real daemon errors
- `18` `skip_load`

So among successfully processed programs before the daemon died, true rewrite coverage was already `260 / 324 = 80.2%`.

## Fixes Applied

### 1. Shrink Daemon Failure-Path Logging

In [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs):

- removed the failure-path full-JSON stderr emission of `OptimizeOneResult`
- replaced it with a one-line headline containing only `prog id`, `prog name`, and the first error line

This keeps REJIT failures visible without flooding stderr with giant serialized debug blobs during batch runs.

### 2. Shrink Verifier-Log Capture Warnings

Also in [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs):

- changed verifier-log capture warnings from printing full `{:#}` error payloads
- now log only the first headline line

This matters because verifier-guided map-inline key capture is attempted for programs with `bpf_map_lookup_elem()`. When those captures fail repeatedly, dumping the full nested error chain and embedded verifier output causes the daemon log to balloon.

### 3. Fix Kernel/Hostfs Module Inconsistency During Rebuilds

While rerunning static verify, a separate build-system bug surfaced: `bzImage` and hostfs modules could be built against different incremental kernel states inside one top-level `make` pipeline.

Root cause in [`Makefile`](/home/yunwei37/workspace/bpf-benchmark/Makefile):

- `kernel-build` was phony
- `$(BZIMAGE_PATH)` depended on phony `kernel-build`
- later `kinsn-modules` / `virtme-hostfs-modules` dependencies could trigger another `kernel-build`
- the second rebuild changed the kernel build number / modversion CRCs
- VM then booted a newer `bzImage` while initramfs tried to load hostfs modules built against the earlier kernel image

Observed symptom:

- VM boot failed before guest commands ran
- `virtme` initramfs reported many `disagrees about version of symbol ... (err -22)` errors, starting with `netfs`

Fix in [`Makefile`](/home/yunwei37/workspace/bpf-benchmark/Makefile):

- introduced `KERNEL_BUILD_STAMP := $(KERNEL_DIR)/.bpfrejit_kernel_build.stamp`
- made `kernel-build` depend on that stamp instead of staying effectively phony
- made `$(BZIMAGE_PATH)` and `$(KERNEL_SYMVERS_PATH)` depend on the stamp
- kept the existing `flock`-based serialized kernel build path

This makes one top-level VM/static-verify invocation reuse one consistent kernel build instead of rebuilding midway.

## Validation Of The Daemon Fix

Local host-side validation after the daemon logging change:

- `make daemon-tests`: passed
- `make daemon`: passed
- `make runner`: passed

## Old Vs New Static-Verify Results

One full rerun completed successfully after the daemon logging fix. Its result is the current [`daemon/tests/results/static_verify.json`](/home/yunwei37/workspace/bpf-benchmark/daemon/tests/results/static_verify.json).

Summary comparison:

| Metric | Old reported run | Fresh full rerun |
| --- | ---: | ---: |
| programs total | 1241 | 1241 |
| daemon-`ok` programs | 345 | 1208 |
| truly changed programs | 275 | 595 |
| true changed coverage | 22.2% | 47.9% |
| `programs_applied` summary field | 345 | 1208 |
| errors | 896 | 33 |
| `skip_load` | 159 | 159 |

Takeaways:

- the reported `27.8%` was not real pass coverage; it was just the fraction of programs processed before the daemon died
- after fixing daemon survivability, static verify succeeds on `1208 / 1241 = 97.3%` loadable programs
- true rewrite coverage rises from `275 / 1241 = 22.2%` to `595 / 1241 = 47.9%`

## Per-Pass Coverage On The Fresh Full Rerun

Program counts below use `daemon_pass_details[].changed`, not `passes_applied`, so they count programs each pass actually rewrote at least once.

| Pass | Programs changed | Share of all 1241 programs | Sites applied |
| --- | ---: | ---: | ---: |
| `const_prop` | 489 | 39.4% | 8052 |
| `dce` | 404 | 32.6% | 5083 |
| `map_inline` | 294 | 23.7% | 1698 |
| `bulk_memory` | 103 | 8.3% | 160 |
| `wide_mem` | 97 | 7.8% | 1003 |
| `endian_fusion` | 97 | 7.8% | 1108 |
| `extract` | 45 | 3.6% | 703 |
| `cond_select` | 20 | 1.6% | 51 |
| `rotate` | 13 | 1.0% | 688 |
| `bounds_check_merge` | 2 | 0.2% | 2 |
| `skb_load_bytes_spec` | 1 | 0.1% | 1 |
| `branch_flip` | 0 | 0.0% | 0 |

For comparison, old pre-fix run per-pass counts were:

| Pass | Old programs changed | Old sites applied |
| --- | ---: | ---: |
| `const_prop` | 221 | 875 |
| `dce` | 203 | 5857 |
| `map_inline` | 190 | 988 |
| `wide_mem` | 57 | 176 |
| `endian_fusion` | 22 | 631 |
| `rotate` | 13 | 688 |
| `cond_select` | 7 | 10 |
| `extract` | 6 | 528 |
| `bounds_check_merge` | 2 | 2 |
| `skb_load_bytes_spec` | 0 | 0 |
| `bulk_memory` | 0 | 0 |
| `branch_flip` | 0 | 0 |

## What Still Does Not Change

Fresh rerun unchanged-program bucket:

- `613` programs were daemon-`ok` but unchanged
- top prog types: `kprobe 189`, `tracing 119`, `tracepoint 62`, `xdp 41`, `syscall 32`, `raw_tracepoint 31`, `sched_cls 30`, `struct_ops 30`, `lsm 28`
- instruction-count stats: min `1`, p25 `9`, median `24`, p75 `57`, p90 `248.2`, max `14750`, mean `356.95`

Structural features of those `613` unchanged programs:

- `22 / 613` contain `bpf_map_lookup_elem`
- `397 / 613` contain conditional branches
- `21 / 613` contain both

Interpretation:

- `map_inline` is not the main remaining blocker; only a small fraction of unchanged programs even contain `map_lookup_elem`
- many unchanged programs do have branches, but most do not satisfy the exact conditions needed by current branch-oriented transforms

## Main Reasons Programs Still Miss

The strongest recurring skip reasons on unchanged programs are:

### `map_inline`

- `106` programs: `lookup key is not a constant stack or pseudo-map-value materialization`
- `69` programs: `lookup result is not consumed by fixed-offset scalar loads`
- `31` programs: `map type 13 not inlineable in v1`
- `30` programs: `mutable lookup result has non-load uses`

### `cond_select`

- `50` programs: `packed ABI requires register true/false operands`
- `15` programs: `interior branch target`
- many others: `JCC condition not a simple zero test`

### `skb_load_bytes_spec`

- implemented, not a stub
- only `1` site matched in the fresh rerun
- most skips are `len > 8`

### `bulk_memory`

- primary blocker is alias-safety proof failure on different-base memcpy patterns

### `wide_mem`

- blocker is mostly safety filtering around likely packet pointers in XDP/TC or scratch-register liveness

## Residual Error Bucket In The Fresh Full Rerun

The remaining `33` errors are much smaller and more specific:

- `23` `BPF_PROG_REJIT EINVAL: missing btf func_info`
- `9` `read() timed out after 30s`
- `1` huge `scx_rusty_main.bpf.o` case (`Argument list too long` / very large verifier processing)

These are no longer evidence of a general pass-coverage outage.

## Conclusion

The reported `345 / 1241 = 27.8%` was not caused by `const_prop` being disabled, nor by static verify running only a subset of passes. It was primarily a daemon crash that stopped processing after 345 programs.

After fixing the daemon failure-path logging, static verify completes across `1208` programs and true rewrite coverage rises to `595 / 1241 = 47.9%`.

The remaining uncovered programs are mostly ordinary pattern gaps:

- many are very small
- few contain `map_lookup_elem`
- many branchy programs still fail current matcher preconditions
- `skb_load_bytes_spec` exists but currently matches a very narrow subset

## Final Rerun Status

The successful full rerun above was completed after the daemon logging fix.

After that rerun, a second rerun exposed the separate `Makefile` kernel/hostfs mismatch bug described above, and that bug has now been fixed as well. The final post-`Makefile` `make vm-static-test` confirmation is pending a shared kernel-build lock held by another in-repo task at the time of writing; once that rerun completes, this section should be updated with the final confirmation summary.
