# 2026-05-05 KVM x86 5-kop Pass Error Analysis

Input result: `corpus/results/x86_kvm_corpus_20260505_220116_564226/details/result.json`

Run metadata: x86 KVM corpus, `SAMPLES=1`, 18 apps, 507 live BPF programs, enabled passes `rotate,cond_select,extract,endian_fusion,bulk_memory`.

This report parses only raw result payloads and error strings. It does not compute performance ratios, geomeans, weighted aggregates, or paper-grade metrics.

## Executive Summary

The 233 pass errors are mostly not optimizer-specific verifier rejections.

- `per_program.<id>.error` was empty for every program. All 233 errors came from `passes[].error`.
- 220 of 233 pass errors are `BPF_PROG_REJIT errno 28: No space left on device`. These are all Tetragon programs, and the verifier log is dominated by repeated `mark_precise` output before truncation. The daemon asks every per-pass ReJIT for `log_level=2`; `kernel-sys` grows the log buffer from 16 MiB up to 256 MiB, then returns ENOSPC. That points to verifier-log buffer exhaustion, not proof that the replacement bytecode was semantically rejected.
- 45 programs have errors in all five passes: 44 Tetragon generic programs with ENOSPC plus Cilium `dump_bpf_prog` with EACCES. This explains why pass error counts cluster at 46-48.
- `rotate` is not shown broken by this run. It matched 0 sites and applied 0 sites across all 507 programs. Its 46 errors are no-op ReJIT failures from the shared cascade set plus one Tetragon no-op EBUSY.
- `endian_fusion` is not globally broken. It matched 248 sites and applied 2. Most skipped endian sites were `bpf_endian_load16 kfunc not available`; its 46 pass errors are from the same no-op ReJIT failure modes, not from applied endian rewrites.

Relevant implementation points:

- `daemon/src/commands.rs:33` starts each ReJIT log buffer at 16 MiB.
- `daemon/src/commands.rs:198-220` always requests a verifier log and requires parseable states after every successful per-pass ReJIT.
- `bpfopt/crates/kernel-sys/src/lib.rs:43` caps ReJIT verifier logs at 256 MiB.
- `bpfopt/crates/kernel-sys/src/lib.rs:1334-1351` retries ENOSPC by growing the log buffer until that cap, then reports the failure.
- `vendor/linux-framework/kernel/bpf/syscall.c:3787-3789` rejects a replacement whose allocated `bpf_prog_size(tmp->len)` exceeds the original program allocation.
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:651-654` returns EBUSY when a text-poke site no longer contains the expected old bytes.

## Error Cluster Table

| Pattern | Count | Affected app/programs | Passes | Likely root cause | Class |
| --- | ---: | --- | --- | --- | --- |
| `errno 28 ENOSPC`, verifier log full of `mark_precise`, truncated | 220 | `tetragon/observer`: 33 `generic_kprobe_` kprobe, 9 `generic_retkpro` kprobe, 1 `generic_tracepo` tracepoint, 1 `generic_rawtp_f` raw_tracepoint | 44 per pass for all 5 passes | Verbose verifier log overflow during per-pass `BPF_PROG_REJIT(log_level=2)`. These candidates applied 0 sites; cond_select matched sites were all skipped. | B: daemon/kernel-sys protocol/log handling bug, with a kernel verifier log-volume trigger |
| `errno 13 EACCES`, `access beyond the end of member pages ... struct bpf_prog` | 5 | `cilium/agent` prog id 64, `dump_bpf_prog`, tracing | all 5 passes | No-op ReJIT of a BPF iterator/tracing program fails BTF struct access re-verification. This is not pass output: all five passes matched/applied 0 sites. | C: kernel ReJIT metadata/verifier replay limitation |
| `errno 16 EBUSY`, no sites applied | 6 | `cilium/agent`: `tail_drop_notif`, `tail_handle_ipv`; `tetragon/observer`: `generic_kprobe_`, `generic_retkpro` | rotate/cond_select/extract/endian_fusion/bulk_memory singletons | Post-verifier ReJIT refresh likely fails in tail-call/direct text-poke handling. Logs are truncated before a final verifier reason, and several candidates are no-op. | C: kernel ReJIT tail-call/text-poke limitation |
| `errno 16 EBUSY`, `cond_select` applied 2 sites | 1 | `cilium/agent` prog id 161, `tail_drop_notif`, sched_cls | cond_select | Same likely text-poke/tail-call refresh path, but after a real cond_select expansion from 96 to 102 insns. Needs failure artifacts to separate pass legality from kernel refresh. | C, possibly A if the transformed tail-call pattern is not preserved |
| `errno 7 E2BIG`, `cond_select` applied 4 sites | 1 | `tetragon/observer` prog id 203, `execve_send`, tracepoint | cond_select | Candidate grew from 936 to 946 insns. Kernel ReJIT rejects replacements that no longer fit the original program allocation. | B: daemon/bpfopt lacks a ReJIT size budget; kernel-side cap is the immediate reject |

Full affected program groups for ENOSPC:

- `tetragon/observer generic_kprobe_ kprobe`: ids `209,217,223,235,245,252,255,271,276,281,288,299,306,307,322,333,345,357,366,375,377,397,409,413,422,430,440,448,449,463,470,474,487`
- `tetragon/observer generic_retkpro kprobe`: ids `238,262,316,327,338,349,359,424,459`
- `tetragon/observer generic_tracepo tracepoint`: id `384`
- `tetragon/observer generic_rawtp_f raw_tracepoint`: id `392`

Non-ENOSPC singletons:

- `cilium/agent dump_bpf_prog tracing`: id `64`, EACCES on all five passes.
- `cilium/agent tail_drop_notif sched_cls`: id `161`, EBUSY on `cond_select` after 2 applied sites and EBUSY on `endian_fusion` with 0 sites.
- `cilium/agent tail_handle_ipv sched_cls`: id `162`, EBUSY on `extract` with 0 sites.
- `cilium/agent tail_drop_notif sched_cls`: id `178`, EBUSY on `bulk_memory` with 0 sites after an earlier successful cond_select.
- `tetragon/observer execve_send tracepoint`: id `203`, E2BIG on `cond_select` after 4 applied sites.
- `tetragon/observer generic_retkpro kprobe`: id `350`, EBUSY on `bulk_memory` with 0 sites.
- `tetragon/observer generic_kprobe_ kprobe`: id `352`, EBUSY on `cond_select` with 0 sites.
- `tetragon/observer generic_kprobe_ kprobe`: id `402`, EBUSY on `rotate` with 0 sites.

## Cross-Pass Cascade Check

The near-identical 46-48 pass error counts are the same core program set cascading across passes.

| Pass | Error count | Intersection with rotate-error program set | Extra programs beyond rotate set |
| --- | ---: | ---: | ---: |
| rotate | 46 | 46 | 0 |
| cond_select | 48 | 45 | 3 |
| extract | 46 | 45 | 1 |
| endian_fusion | 46 | 45 | 1 |
| bulk_memory | 47 | 45 | 2 |

Program multiplicity:

- 45 programs errored in all five passes.
- 6 programs errored in exactly one pass.
- 1 program errored in exactly two passes.

So `rotate`'s 46 errors do not imply a rotate-specific corpus failure. Rotate has no matched sites in this result, and 45 of its 46 errored programs are shared with every other pass.

## Per-Pass Diagnosis

| Pass | Matched sites | Applied sites | Pass errors | Diagnosis |
| --- | ---: | ---: | ---: | --- |
| rotate | 0 | 0 | 46 | No rotate patterns matched in this corpus run. All rotate failures are no-op ReJIT failures. Do not treat this as evidence that the rotate rewrite is corrupting bytecode. |
| cond_select | 2284 | 337 | 48 | The pass is active and applies sites. The dominant failures are 44 Tetragon ENOSPC no-op candidates where all matched sites were skipped, plus one Cilium EBUSY after 2 sites and one Tetragon E2BIG after 4 sites. |
| extract | 198 | 3 | 46 | The pass applies on a small number of programs. Its failures are 44 Tetragon ENOSPC no-op candidates plus Cilium `dump_bpf_prog` EACCES and Cilium `tail_handle_ipv` EBUSY. |
| endian_fusion | 248 | 2 | 46 | Not globally broken. Most skipped sites are 16-bit endian opportunities where `bpf_endian_load16` is not available. Errors are inherited no-op ReJIT failures. |
| bulk_memory | 388 | 97 | 47 | The pass is active and has the largest applied count among the five. Its failures are mostly the Tetragon ENOSPC no-op set plus Cilium/Tetragon EBUSY no-op cases and Cilium `dump_bpf_prog` EACCES. |

Top skip reasons by pass:

- `cond_select`: no dead register for immediate materialization, interior branch targets, and many tail-call-helper protected kop sites.
- `extract`: mostly tail-call-helper protected kop sites.
- `endian_fusion`: 232 skipped sites because `bpf_endian_load16 kfunc not available`, plus a small number of tail-call-helper protected sites.
- `bulk_memory`: aliasing not provably safe and tail-call-helper protected kop sites.
- `rotate`: no matches and no skips.

## Tetragon-Specific Diagnosis

Tetragon loaded 287 programs. It produced 224 pass errors across 48 unique programs.

Dominant mode:

- 220 of 224 Tetragon pass errors are ENOSPC from 44 generic programs.
- Every ENOSPC program failed in all five passes.
- No ENOSPC candidate applied any site.
- The ENOSPC verifier logs point at repeated precision-marking around nested frames and string/map-value loops, then truncation. The result string does not contain a semantic verifier rejection line.

The remaining Tetragon errors are:

- `execve_send` tracepoint id 203: `cond_select` applied 4 sites, grew by 10 insns, then returned E2BIG.
- `generic_retkpro` id 350: `bulk_memory` no-op EBUSY.
- `generic_kprobe_` id 352: `cond_select` no-op EBUSY.
- `generic_kprobe_` id 402: `rotate` no-op EBUSY.

Conclusion: Tetragon is exposing ReJIT infrastructure limits: huge `log_level=2` verifier output, allocation budget on growth, and tail-call/text-poke refresh behavior. It is not primarily exposing broken rotate, extract, endian, or bulk-memory transformations.

## Recommendations

1. Fix the ENOSPC/log path first. This single issue accounts for 220 of 233 errors. The daemon currently makes verbose verifier-state collection mandatory for every per-pass ReJIT. For kop-only pass lists that do not need later verifier-state side inputs, either avoid `log_level=2` by design or add a kernel-side/log-streaming mechanism that does not turn log overflow into a pass failure. Do not silently treat ENOSPC as success; preserve fail-fast semantics and make the design decision explicit.

2. Add a diagnostic no-op ReJIT canary outside the benchmark hot path. It should submit original bytecode per program and capture full failure artifacts. This must not filter benchmark programs. It would immediately separate "optimizer produced bad bytecode" from "ReJIT cannot re-verify/swap this already-loaded program class".

3. Fix Cilium `dump_bpf_prog` / BPF iterator ReJIT. A no-op ReJIT gets `access beyond the end of member pages ... struct bpf_prog`, so the replacement verifier context is not equivalent to original load for this tracing iterator. This needs kernel ReJIT metadata/verifier-state replay work, not a pass exclusion.

4. Fix or constrain tail-call direct-poke refresh. EBUSY appears in no-op and transformed cases and matches the x86 text-poke path that returns EBUSY when old bytes do not match. Capture full artifacts first, then decide whether the kernel refresh path needs to tolerate already-patched sites, retry, or preserve more poke metadata.

5. Add an explicit ReJIT size budget for growth passes. `cond_select` can expand bytecode; `execve_send` shows a +10 instruction candidate hitting the kernel allocation cap. Either the daemon should provide max replacement bytes/insns to `bpfopt`, or the kernel needs safe growth support. Until then, growth passes should be budget-aware and skip only individual over-budget sites with a structured skip reason.

6. Decide whether 16-bit endian fusion is expected on x86. `endian_fusion` skipped 232 sites because `bpf_endian_load16` was unavailable. If the 16-bit kfunc should exist, fix target probing/module registration. If not, this is expected low apply coverage, not a failure.

## Targeted Rerun Commands

I did not run these. The current app selector in code is `BPFREJIT_CORPUS_APPS`, not `BPFREJIT_BENCH_APPS` (`corpus/driver.py:51-76`). The commands below keep app-level loading and do not filter individual programs.

Capture the dominant Tetragon ENOSPC no-op case:

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer \
BPFREJIT_BENCH_PASSES=rotate \
SAMPLES=1 KEEP_FAILURE_ARTIFACTS=1 \
make vm-corpus
```

Capture the Cilium BPF iterator/BTF-access EACCES no-op case:

```bash
BPFREJIT_CORPUS_APPS=cilium/agent \
BPFREJIT_BENCH_PASSES=rotate \
SAMPLES=1 KEEP_FAILURE_ARTIFACTS=1 \
make vm-corpus
```

Capture applied-site failures for `cond_select` (`execve_send` E2BIG and `tail_drop_notif` EBUSY):

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer,cilium/agent \
BPFREJIT_BENCH_PASSES=cond_select \
SAMPLES=1 KEEP_FAILURE_ARTIFACTS=1 \
make vm-corpus
```
