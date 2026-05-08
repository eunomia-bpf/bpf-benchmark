# Prefetch deep-dive: tracee zero-speedup plus tetragon errors

Date: 2026-05-06

Run under analysis: `corpus/results/x86_kvm_corpus_20260506_023522_768608/`.

Scope: read-only investigation of existing result JSON, bpfopt prefetch source, kinsn modules, daemon ReJIT orchestration, and recent prefetch design notes.

No benchmarks were run. No source code was changed. The only write is this report.

Definitions used below:

- `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; lower than 1.0 means faster after ReJIT.
- `B` is Method B, the per-program geomean over retained programs with `min_runs >= 100`.
- Raw framework outputs are not modified; all aggregation in this report is post-hoc analysis-side.
- The pass list in the run was `rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch`; per-program ratios are final post-ReJIT ratios, so they are not a pure prefetch-only ablation.

## Executive Summary

1. Tracee absorbed 1,770 prefetch sites across 128 programs, but 1,033 of those sites landed on programs with `min_runs < 100`, and 795 landed on programs with zero observed runs. Among retained tracee programs, sites split almost evenly between winners and losers, giving B=1.0071, effectively no speedup.
2. The current prefetch pass is structural when PMU data is absent. That directly contradicts the older design note that said no profile should mean no prefetch. The current paper plan acknowledges this PrefetchV2 behavior, but the tracee result is exactly the failure mode the older note predicted.
3. Tetragon has 35 failed pass entries total, but only 9 are the prefetch step. Prefetch failures cluster into 7 EBUSY kernel-side busy races and 2 E2BIG kernel-side capacity failures. There are no observed bpfopt prefetch emit errors in this run.
4. Cilium B=0.8144 is driven by one retained program, `cil_from_netdev`, with only 1,230 min_runs and 14 prefetch sites. It is plausible because it is a hot `sched_cls` ingress path, but the retained-program coverage is too small to call it stable without replication.
5. The highest-impact fix is to make prefetch admission PMU-driven or at least hotness-gated, then add site-detail observability and a small per-program/site budget. Do not implement benchmark-level program filtering or per-prog_type exclusions.

## Required Reading Cross-Check

- Paper plan: `docs/kernel-jit-optimization-plan.md:247` says PrefetchV2 is implemented as a default Paper A pass, using x86 `PREFETCHT0` and ARM64 `PRFM`, with structural packet/map-value recognition and optional PMU filtering.
- Historical design note: `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:9` says prefetch must be runtime-guided rather than static blanket insertion.
- The same design note says missing profile should default to no insertion at `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:24` and `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:395`.
- PrefetchV2 implementation note explicitly changed that policy: missing PMU data now emits structural candidates (`docs/tmp/p89_prefetchv2_impl.md:5`).
- CLAUDE design rules prohibit in-framework perf aggregation and program-level ReJIT filtering; this report keeps calculations post-hoc and recommends pass-local site selection only, not runner filtering.

## Source Behavior Audit

The current pass behavior is visible in source:

- `PrefetchPass` documents structural default behavior at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:35`.
- It checks only that `bpf_prefetch` is registered and packed ABI is available before scanning (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:124`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:134`).
- It scans map-value sites first, then packet sites for packet-capable program types (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:246`).
- It uses PMU data only if present; absent PMU data falls through to `default_site_score()` (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:154`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:166`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:275`).
- PMU admission rejects only zero execution, impossible counters, zero references, or zero misses (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:282`).
- It inserts exactly one packed kinsn pair for each retained candidate (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:200`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:211`).
- The pass logs only `sites_applied`; it does not report target register, target PC, target kind, target address, prefetch distance, or whether PMU was present (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:233`).
- `PassResult` summary records aggregate pass counters but not per-site detail; tracee JSON confirms only `diagnostics`, instruction counts, site counters, and skip reasons are present.

Map-value site detection:

- It looks for `bpf_map_lookup_elem` calls (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:311`).
- It tracks `R0` and aliases through moves and constant add/sub until the first memory dereference (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:328`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:343`).
- It stops the scan at calls, exits, pseudo function loads, and non-zero unconditional jumps (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:365`).
- Therefore the prefetched pointer is the map value pointer or an alias of the map value pointer returned by lookup, not the map key or internal hash bucket.

Packet site detection:

- Packet scanning is enabled only when `packet_ctx_layout()` recognizes XDP or skb-like program types (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:443`).
- For `SCHED_CLS`, `SCHED_ACT`, `SK_SKB`, and LWT types, it uses skb `data` and `data_end` offsets (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:449`).
- It tracks `ctx->data` loads and propagates packet pointers through moves and constant add/sub (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:503`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:524`).
- It emits prefetch before direct packet memory accesses when the base register is tracked as packet data (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:424`).

Insertion policy:

- Current target distance is 8 BPF instructions, max distance is 16 (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:18`).
- The historical design recommended 20-50 instruction windows and target distance 32 (`docs/tmp/20260329/prefetch_kinsn_design_20260329.md:466`).
- Current insertion can be much closer than the historical design intended, which supports the late-prefetch/redundant-prefetch hypothesis.
- It rejects windows crossing subprogram/basic-block constraints, control-flow instructions, or pointer-register redefinitions (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:564`).
- It does not cap candidates per program, does not model code-size budget, and does not record site kind in the report.

Kernel kinsn behavior:

- x86 module `module/x86/bpf_prefetch.c:3` implements `PREFETCHT0`.
- x86 payload decoder rejects non-zero hint kind, reserved bits, invalid BPF registers, and invalid x86 register mappings (`module/x86/bpf_prefetch.c:16`).
- x86 proof sequence is a single `BPF_JMP_A(0)` no-op (`module/x86/bpf_prefetch.c:34`).
- x86 native emitter writes opcode `0f 18 /1` and handles SIB/disp cases (`module/x86/bpf_prefetch.c:58`).
- x86 kinsn descriptor sets `max_insn_cnt = 1` and `max_emit_bytes = 6` (`module/x86/bpf_prefetch.c:108`).
- ARM64 module emits `PRFM PLDL1KEEP` (`module/arm64/bpf_prefetch.c:3`, `module/arm64/bpf_prefetch.c:45`).
- Shared register mappings are in `module/include/kinsn_common.h:46` for x86 and `module/include/kinsn_common.h:92` for ARM64.
- The checked-in modules live under repo `module/`, not under `vendor/linux-framework`; vendor kernel sources provide the kinsn hook points.

Daemon behavior:

- The daemon runs every requested pass in order, writes pass input, invokes bpfopt, decodes output, then calls `BPF_PROG_REJIT` (`daemon/src/commands.rs:530`, `daemon/src/commands.rs:566`, `daemon/src/commands.rs:617`).
- ReJIT failures are recorded as `failed_rejit` pass details and the chain continues (`daemon/src/commands.rs:625`).
- Kernel-sys formats errno and verifier-log summary in the error string (`bpfopt/crates/kernel-sys/src/lib.rs:430`).
- This is compliant with No ReJIT Filtering: failed ReJIT is visible in result JSON instead of filtered away.

Design-rule flags from this audit:

- No forbidden in-framework performance aggregation was found in the prefetch pass or daemon prefetch path.
- `analysis/corpus_analyze.py` computes wins/losses and ratios, but that is analysis-side, not framework output.
- The main pass-code policy issue is fallback-like behavior: absent PMU data becomes structural insertion via `default_site_score`, which is a heuristic default and is the opposite of the older runtime-guided design.
- Do not fix this by excluding programs from ReJIT. Fix it by making the pass produce fewer or no candidate sites while preserving visible pass records and ReJIT attempts where appropriate.

## Q1: Tracee 1770 Apply But No Speedup

Data source: `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json`.

- Programs in tracee detail file: 158.
- Programs with at least one prefetch site: 128.
- Total prefetch sites applied by bpfopt summaries: 1770.
- Prefetch step failures: 2.
- Retained programs for Method B (`min_runs >= 100`): 70.
- Retained min_runs sum: 164,054,984.
- Method B from raw JSON: 1.007135.

Cold-path distribution:

- Sites on programs with `min_runs < 1`: 795 across 63 prefetch-touched programs.
- Sites on programs with `min_runs < 100`: 1,033 across 73 prefetch-touched programs.
- Sites on programs with `min_runs < 1,000`: 1,104 across 78 prefetch-touched programs.
- Sites on programs with `min_runs < 10,000`: 1,308 across 92 prefetch-touched programs.
- Sites on programs with `min_runs < 100,000`: 1,361 across 96 prefetch-touched programs.
- Sites on programs with `min_runs < 1,000,000`: 1,640 across 116 prefetch-touched programs.

This is the strongest evidence for H1: 1,033 of 1,770 tracee sites are below the paper-grade `min_runs >= 100` threshold, and 795 are on programs with zero observed runs.

Top 10 tracee programs by prefetch apply count:

| prog_id | name | type | sites | prefetch status | baseline bytes_jited | post bytes_jited | delta_jit_size | baseline_runs | post_runs | ratio | data |
| --- | --- | --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 649 | `tracepoint__exec_test` | raw_tracepoint | 111 | ok | 58,693 | 59,223 | 530 | 2 | 2 | 1.1178 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1400; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2836; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:20334` |
| 518 | `tracepoint__sched__sched_process_fork` | raw_tracepoint | 36 | failed_rejit | 19,722 | 19,734 | 12 | 6,590 | 6,773 | 1.0722 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:230; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1666; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5729` |
| 635 | `syscall_checker` | kprobe | 31 | ok | 14,930 | 15,008 | 78 | 0 | 0 |  | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1283; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2719; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18900` |
| 535 | `uprobe_syscall_table_check` | kprobe | 29 | ok | 56,303 | 56,360 | 57 | 0 | 0 |  | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:383; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1819; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7631` |
| 586 | `trace_security_mmap_file` | kprobe | 28 | ok | 36,984 | 37,083 | 99 | 536,138 | 324,018 | 1.1400 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:842; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2278; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13374` |
| 522 | `lkm_seeker_kset_tail` | kprobe | 27 | ok | 62,309 | 62,384 | 75 | 0 | 0 |  | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:266; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1702; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6178` |
| 587 | `trace_security_file_mprotect` | kprobe | 24 | ok | 34,612 | 34,684 | 72 | 3,410,599 | 2,233,605 | 0.9948 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:851; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2287; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13486` |
| 589 | `trace_security_bpf` | kprobe | 24 | ok | 15,620 | 15,692 | 72 | 7,386 | 7,386 | 0.9938 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:869; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2305; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13721` |
| 606 | `trace_ret_do_init_module` | kprobe | 24 | ok | 14,587 | 14,674 | 87 | 0 | 0 |  | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1022; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2458; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15639` |
| 526 | `tracepoint__sched__sched_process_exec` | raw_tracepoint | 23 | ok | 20,556 | 20,625 | 69 | 2 | 2 | 1.4250 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:302; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1738; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6618` |

Observations from the top-apply rows:

- The largest apply site, `tracepoint__exec_test`, has only 2 baseline and 2 post runs. It cannot explain an app-level speedup.
- Several high-apply kprobe programs have zero runs in both phases, so those prefetches are dead for this workload.
- `trace_security_mmap_file` is a real retained high-apply program and regresses by about 14 percent despite 28 prefetch sites.
- `trace_security_file_mprotect` and `trace_security_bpf` are near 1.0 despite 24 sites each.
- `tracepoint__sched__sched_process_fork` failed prefetch ReJIT but still has final bytecode from earlier successful passes; the prefetch step failure is visible and not filtered.

Tracee retained ratio distribution:

- Retained programs: 70.
- Wins/losses/ties: 34/36/0.
- Median retained ratio: 1.002920.
- Min retained ratio: 0.656102.
- Max retained ratio: 1.817010.
- Retained prefetch sites on winners: 375.
- Retained prefetch sites on losers: 362.

This supports cancellation rather than uniform no-op behavior: there are strong local winners and strong local losers, but the retained site count is almost balanced and the median is almost exactly 1.0.

Strong retained tracee winners with prefetch sites:

| prog_id | name | sites | min_runs | ratio | delta_jit_size | data |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| 508 | `trace_ret_dup` | 13 | 3,746 | 0.6561 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:140; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1576; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4588` |
| 638 | `trace_ret_sock_alloc_file` | 12 | 145,544 | 0.8175 | -62 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1310; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2746; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19234` |
| 512 | `trace_ret_dup3` | 13 | 5,116 | 0.8195 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:176; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1612; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5054` |
| 645 | `cgroup_skb_egress` | 10 | 1,452,582 | 0.8534 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1364; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2800; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19894` |
| 617 | `trace_fd_install` | 13 | 646,236 | 0.8623 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1121; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2557; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16875` |
| 510 | `trace_ret_dup2` | 13 | 4,852 | 0.8875 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:158; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1594; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4821` |
| 544 | `trace_security_file_open` | 17 | 433,171 | 0.8906 | 44 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:464; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1900; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8641` |
| 581 | `trace_ret_vfs_readv` | 13 | 106 | 0.8987 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:797; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2233; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12808` |
| 531 | `tracepoint__sched__sched_switch` | 13 | 610,402 | 0.9025 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:347; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1783; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7183` |
| 640 | `trace_security_socket_recvmsg` | 12 | 565,211 | 0.9105 | -56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1328; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2764; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19454` |
| 641 | `trace_security_socket_sendmsg` | 12 | 1,615,198 | 0.9128 | -56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1337; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2773; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19564` |
| 569 | `trace_ret_vfs_writev` | 13 | 106 | 0.9261 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:689; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2125; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11445` |

Strong retained tracee losers with prefetch sites:

| prog_id | name | sites | min_runs | ratio | delta_jit_size | data |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| 608 | `trace_security_file_permission` | 13 | 1,893,843 | 1.1925 | 46 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1040; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2476; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15865` |
| 564 | `trace_ret_vfs_write` | 13 | 192,169 | 1.1920 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:644; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2080; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10881` |
| 583 | `trace_mmap_alert` | 13 | 431,720 | 1.1763 | -19 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:815; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2251; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13040` |
| 586 | `trace_security_mmap_file` | 28 | 324,018 | 1.1400 | 99 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:842; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2278; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13374` |
| 578 | `trace_ret_vfs_read` | 13 | 1,045,463 | 1.1321 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:770; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2206; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12466` |
| 565 | `vfs_write_magic_return` | 17 | 192,169 | 1.1134 | 55 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:653; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2089; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10998` |
| 547 | `trace_commit_creds` | 13 | 113,977 | 1.1025 | 29 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:491; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1927; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8977` |
| 593 | `trace_security_bpf_prog` | 15 | 161 | 1.0732 | 38 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:905; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2341; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14178` |
| 518 | `tracepoint__sched__sched_process_fork` | 36 | 6,590 | 1.0722 | 12 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:230; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1666; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5729` |
| 642 | `cgroup_bpf_run_filter_skb` | 2 | 2,368,329 | 1.0651 | -105 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1346; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2782; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19674` |
| 570 | `vfs_writev_magic_return` | 17 | 106 | 1.0611 | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:698; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2134; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11562` |
| 559 | `trace_security_socket_setsockopt` | 13 | 230,351 | 1.0607 | -20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:599; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2035; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10329` |

JIT size findings:

- Across all tracee programs with prefetch sites, final `bytes_jited` delta sums to 4,133 bytes over 1,770 sites.
- Average final `bytes_jited` delta per site is 2.335 bytes/site.
- `insn_delta` is exactly 2 BPF instructions per prefetch site, matching the packed sidecar plus kinsn call path.
- The final native JIT delta is not a pure prefetch-only delta because other passes also ran, but high-apply tracee rows mostly show positive code growth.

Per-site target observability:

- The tracee app JSON has no `sites_detail`, no target PC list, no target register list, no kind counts, and no target address list in `bpfopt_summary`.
- Therefore this run cannot answer which concrete address each prefetch targeted.
- From source, tracee kprobe/raw_tracepoint programs can only use the map-value scanner, because packet scanning is gated to packet program types (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:443`).
- For tracee, the target is therefore the first dereference of a map value pointer returned by `bpf_map_lookup_elem`, or an alias, not packet bytes.

Hypothesis evaluation for tracee:

| Hypothesis | Verdict | Evidence |
| --- | --- | --- |
| H1 cold path | Strongly supported | 1,033/1,770 sites are below `min_runs >= 100`; 795 sites are on zero-run programs. |
| H2 redundant or late prefetch | Plausible | Current target distance is 8 instructions, far closer than the historical 20-50 instruction design. No per-site target/timing data exists to prove redundancy. |
| H3 cache pollution | Possible but unproven | Balanced retained winners/losers and some regressions fit pollution, but there are no cache PMU counters in the result JSON. |
| H4 code bloat | Partly supported | Tracee site programs add 4,133 final JIT bytes and 3,540 BPF instructions before proof lowering; retained losers include high-run programs with positive JIT growth. |
| H5 PMU-driven versus heuristic | Heuristic default confirmed | Missing PMU data falls through to structural `default_site_score`, so tracee was not PMU-gated. |

## Q2: Tetragon 35 Errors And Prefetch Failure Clusters

Data source: `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json`.

- Programs in tetragon detail file: 287.
- Total failed pass entries in tetragon: 35.
- Prefetch-step failed entries: 9.
- Prefetch sites applied in bpfopt summaries, including candidates later rejected by ReJIT: 1526.
- Prefetch sites on successful prefetch ReJIT steps: 1459.

Prefetch-step root-cause clusters:

- EBUSY: kernel object busy during ReJIT: 7.
- E2BIG: replacement program exceeded kernel ReJIT capacity: 2.

All-pass tetragon failure clusters, explaining the reference count 35:

- EBUSY: kernel object busy during ReJIT: 32.
- E2BIG: replacement program exceeded kernel ReJIT capacity: 3.

Prefetch-step failures:

| prog_id | name | type | pass step | sites | insns before -> after | root cause | error | data |
| --- | --- | --- | ---: | ---: | --- | --- | --- | --- |
| 177 | `execve_send` | tracepoint | 6 | 12 | 936 -> 960 | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:23; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2620; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:5421` |
| 178 | `event_execve` | tracepoint | 6 | 18 | 2,468 -> 2,504 | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:32; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2629; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:5531` |
| 218 | `generic_kprobe_process_event` | kprobe | 6 | 8 | 3,582 -> 3,598 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:374; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2971; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:9933` |
| 275 | `generic_kprobe_output` | kprobe | 6 | 2 | 380 -> 384 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:887; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3484; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:16582` |
| 276 | `generic_kprobe_actions` | kprobe | 6 | 10 | 1,021 -> 1,041 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:896; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3493; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:16692` |
| 279 | `generic_kprobe_filter_arg` | kprobe | 6 | 3 | 2,109 -> 2,115 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:923; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3520; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:17036` |
| 281 | `generic_kprobe_output` | kprobe | 6 | 2 | 380 -> 384 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:941; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3538; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:17284` |
| 314 | `generic_retkprobe_output` | kprobe | 6 | 2 | 128 -> 132 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:1238; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3835; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:21150` |
| 351 | `generic_kprobe_actions` | kprobe | 6 | 10 | 1,021 -> 1,041 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:1571; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:4168; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:25493` |

Error interpretation:

- EBUSY is kernel-side `BPF_PROG_REJIT` rejection for a live program object that is busy. It is not a bpfopt emit error, and the same root cause appears on other passes with zero sites applied.
- E2BIG is kernel-side capacity rejection after bpfopt emitted a larger bytecode sequence. In tetragon, prefetch adds 24 instructions to `execve_send` and 36 instructions to `event_execve`.
- No tetragon prefetch failure has `failed_bpfopt`, invalid payload, unsupported instruction class, or source-level bpfopt exception.
- The daemon records these as `failed_rejit`, which is the intended visible error path (`daemon/src/commands.rs:625`).

Top error-cluster source citations:

1. EBUSY kernel ReJIT rejection: error strings are generated after `kernel_sys::prog_rejit` returns an error in `daemon/src/commands.rs:211`, then wrapped as `kernel rejected BPF_PROG_REJIT` at `daemon/src/commands.rs:221`; errno formatting comes from `bpfopt/crates/kernel-sys/src/lib.rs:430`.
2. E2BIG capacity rejection: same daemon/kernel-sys error path; prefetch contributes size growth by appending two BPF instructions per candidate at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:200` and `bpfopt/crates/bpfopt/src/passes/prefetch.rs:211`.
3. No bpfopt emit-error cluster exists in this run. The bpfopt prefetch code paths that could emit errors are kinsn availability checks (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:124`), invalid PMU data bails (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:289`), and insertion-window skips (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:564`), but tetragon failures did not hit those as fatal bpfopt errors.

All tetragon failed pass entries:

| prog_id | name | step | pass | sites | root cause | error |
| --- | --- | ---: | --- | ---: | --- | --- |
| 177 | `execve_send` | 2 | cond_select | 4 | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` |
| 177 | `execve_send` | 6 | prefetch | 12 | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` |
| 178 | `event_execve` | 6 | prefetch | 18 | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` |
| 218 | `generic_kprobe_process_event` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 218 | `generic_kprobe_process_event` | 6 | prefetch | 8 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 275 | `generic_kprobe_output` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 275 | `generic_kprobe_output` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 275 | `generic_kprobe_output` | 6 | prefetch | 2 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 276 | `generic_kprobe_actions` | 6 | prefetch | 10 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 278 | `generic_kprobe_process_event` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 279 | `generic_kprobe_filter_arg` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 279 | `generic_kprobe_filter_arg` | 6 | prefetch | 3 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 2 | cond_select | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 3 | extract | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 4 | endian_fusion | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | 6 | prefetch | 2 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 296 | `generic_kprobe_filter_arg` | 3 | extract | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 310 | `generic_kprobe_process_filter` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 2 | cond_select | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 3 | extract | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 4 | endian_fusion | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | 6 | prefetch | 2 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 317 | `generic_kprobe_process_event` | 3 | extract | 1 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 351 | `generic_kprobe_actions` | 6 | prefetch | 10 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 386 | `generic_kprobe_process_event` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 407 | `generic_kprobe_process_event` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 407 | `generic_kprobe_process_event` | 2 | cond_select | 1 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 424 | `generic_kprobe_process_event` | 1 | rotate | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 427 | `generic_kprobe_output` | 2 | cond_select | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 457 | `generic_kprobe_output` | 5 | bulk_memory | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 459 | `generic_kprobe_filter_arg` | 2 | cond_select | 0 | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |

## Q3: Why Cilium B=0.8144 With Only 118 Apply

Data source: `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json`.

- Programs in cilium detail file: 25.
- Programs with prefetch sites: 20.
- Total prefetch sites: 118.
- Retained programs for Method B: 1.
- Retained min_runs sum: 1,230.
- Method B from raw JSON: 0.814420.

Cilium ratio drivers:

| prog_id | name | type | sites | baseline_runs | post_runs | min_runs | ratio | delta_jit_size | data |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 156 | `cil_from_netdev` | sched_cls | 14 | 1,230 | 1,564 | 1,230 | 0.8144 | 24 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:194; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:433; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:2853` |
| 151 | `cil_to_host` | sched_cls | 4 | 1 | 1 | 1 | 0.8463 | 20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:158; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:397; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:2401` |
| 138 | `cil_from_host` | sched_cls | 13 | 1 | 1 | 1 | 1.0959 | 21 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:41; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:280; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:925` |

Interpretation:

- The entire paper-grade Cilium result is driven by `cil_from_netdev`, because it is the only Cilium program in this app with `min_runs >= 100`.
- `cil_from_netdev` is `sched_cls`, so it is eligible for packet prefetch scanning through the skb context layout (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:449`).
- It is also eligible for map-value prefetch scanning if it calls `bpf_map_lookup_elem` and dereferences the returned value (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:311`).
- The result JSON does not include per-site target kind, so this run cannot distinguish packet bytes from map values for the 14 sites.
- The name `cil_from_netdev` and type `sched_cls` make a hot ingress-path packet-prefetch explanation plausible, but not proven by the available observability.
- Because min_runs is only 1,230 and retained coverage is one program, the result is noise-sensitive even though it passes the paper-grade threshold.

All Cilium programs with prefetch sites:

| prog_id | name | type | sites | status | min_runs | ratio | delta_jit_size |
| --- | --- | --- | ---: | --- | ---: | ---: | ---: |
| 156 | `cil_from_netdev` | sched_cls | 14 | ok | 1,230 | 0.8144 | 24 |
| 143 | `cil_from_netdev` | sched_cls | 14 | ok | 0 |  | 24 |
| 150 | `cil_from_netdev` | sched_cls | 14 | ok | 0 |  | 24 |
| 138 | `cil_from_host` | sched_cls | 13 | ok | 1 | 1.0959 | 21 |
| 148 | `cil_from_host` | sched_cls | 13 | ok | 0 |  | 21 |
| 154 | `cil_from_host` | sched_cls | 13 | ok | 0 |  | 21 |
| 137 | `cil_to_netdev` | sched_cls | 5 | ok | 0 |  | 6 |
| 147 | `cil_to_netdev` | sched_cls | 5 | ok | 0 |  | 6 |
| 151 | `cil_to_host` | sched_cls | 4 | ok | 1 | 0.8463 | 20 |
| 141 | `cil_to_host` | sched_cls | 4 | ok | 0 |  | 20 |
| 157 | `cil_to_host` | sched_cls | 4 | ok | 0 |  | 20 |
| 139 | `tail_handle_ipv4_from_host` | sched_cls | 3 | ok | 0 |  | 9 |
| 145 | `tail_handle_ipv4_from_host` | sched_cls | 3 | ok | 0 |  | 9 |
| 152 | `tail_handle_ipv4_from_host` | sched_cls | 3 | ok | 0 |  | 9 |
| 136 | `tail_drop_notify` | sched_cls | 1 | failed_rejit | 0 |  | 24 |
| 140 | `tail_handle_ipv4_from_netdev` | sched_cls | 1 | ok | 0 |  | 3 |
| 144 | `tail_drop_notify` | sched_cls | 1 | failed_rejit | 0 |  | 0 |
| 149 | `tail_handle_ipv4_from_netdev` | sched_cls | 1 | ok | 0 |  | 3 |
| 155 | `tail_handle_ipv4_from_netdev` | sched_cls | 1 | ok | 0 |  | 3 |
| 158 | `tail_drop_notify` | sched_cls | 1 | ok | 0 |  | 24 |

## Q4: Tracee vs OTel vs Cilium Apply Density

| App | progs_with_prefetch | total_prefetch_sites | sites/prog avg | B | C | min_runs | Hypothesis |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| tracee/monitor | 128 | 1770 | 13.83 | 1.0071 | 1.0061 | 164,054,984 | cold-bound plus cancellation; many structural map-value sites on non-hot tracing paths |
| tetragon/observer | 285 | 1526 | 5.35 | 0.8954 | 1.0142 | 43,883,075 | mixed: many cold sites, a few hot ret/kprobe winners, EBUSY/E2BIG errors visible |
| otelcol-profiling | 13 | 415 | 31.92 | 0.9722 | 0.9722 | 7,952 | noise-bound: high apply density but only one retained measured program |
| cilium/agent | 20 | 118 | 5.90 | 0.8144 | 0.8144 | 1,230 | noise-bound but plausible hot ingress packet/map-value path |
| katran | 2 | 43 | 21.50 | 0.9995 | 0.9995 | 107,232 | mostly not measured for prefetch; active ratio comes from xdp_root with zero prefetch sites |
| bpftrace/runqlat | 1 | 1 | 1.00 | 1.0572 | 1.0561 | 42,101,850 | single hot site, regression; too few programs for policy conclusion |

Classification:

- Noise-bound: cilium, otelcol, katran, bpftrace/runqlat. They have too few retained programs or too small retained min_runs to decide policy alone.
- Cold-bound: tracee. Most applied sites are not reached by the workload, and retained sites split evenly between winners and losers.
- Bloat-bound: tracee and tetragon are candidates. Both have high site counts and positive final JIT growth; tetragon also has E2BIG failures.
- Error-bound: tetragon prefetch has 9 visible failures, mostly EBUSY. This is not silent, but it reduces applied coverage.

Per-pass site context for the six apps:

| App | pass | sites_applied | programs_with_sites | failures |
| --- | --- | ---: | ---: | ---: |
| tracee/monitor | rotate | 0 | 0 | 1 |
| tracee/monitor | cond_select | 306 | 91 | 1 |
| tracee/monitor | extract | 2 | 2 | 1 |
| tracee/monitor | endian_fusion | 4 | 2 | 2 |
| tracee/monitor | bulk_memory | 95 | 85 | 1 |
| tracee/monitor | prefetch | 1770 | 128 | 2 |
| tetragon/observer | rotate | 0 | 0 | 7 |
| tetragon/observer | cond_select | 84 | 81 | 6 |
| tetragon/observer | extract | 105 | 70 | 4 |
| tetragon/observer | endian_fusion | 193 | 44 | 2 |
| tetragon/observer | bulk_memory | 2 | 1 | 7 |
| tetragon/observer | prefetch | 1526 | 285 | 9 |
| otelcol-profiling | rotate | 0 | 0 | 0 |
| otelcol-profiling | cond_select | 0 | 0 | 0 |
| otelcol-profiling | extract | 12 | 1 | 0 |
| otelcol-profiling | endian_fusion | 0 | 0 | 0 |
| otelcol-profiling | bulk_memory | 0 | 0 | 0 |
| otelcol-profiling | prefetch | 415 | 13 | 0 |
| cilium/agent | rotate | 0 | 0 | 1 |
| cilium/agent | cond_select | 9 | 6 | 3 |
| cilium/agent | extract | 0 | 0 | 2 |
| cilium/agent | endian_fusion | 21 | 8 | 1 |
| cilium/agent | bulk_memory | 0 | 0 | 2 |
| cilium/agent | prefetch | 118 | 20 | 3 |
| katran | rotate | 0 | 0 | 1 |
| katran | cond_select | 7 | 1 | 0 |
| katran | extract | 0 | 0 | 1 |
| katran | endian_fusion | 6 | 1 | 0 |
| katran | bulk_memory | 0 | 0 | 0 |
| katran | prefetch | 43 | 2 | 1 |
| bpftrace/runqlat | rotate | 0 | 0 | 0 |
| bpftrace/runqlat | cond_select | 4 | 1 | 0 |
| bpftrace/runqlat | extract | 0 | 0 | 0 |
| bpftrace/runqlat | endian_fusion | 0 | 0 | 0 |
| bpftrace/runqlat | bulk_memory | 0 | 0 | 0 |
| bpftrace/runqlat | prefetch | 1 | 1 | 0 |

## Q5: Ranked Improvement Directions

1. Restore PMU/hotness gating for prefetch admission.

- Expected impact: highest.
- Current source makes PMU optional and structural insertion default (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:166`).
- Historical design explicitly said no profile should skip prefetch (`docs/tmp/20260329/prefetch_kinsn_design_20260329.md:529`).
- Tracee shows why: 1,033 sites are below the retained threshold and 795 are on zero-run programs.
- Minimal change: add a pass option or default policy that requires per-site prefetch PMU unless explicitly running a structural experiment.
- Do not hide failures or filter programs; produce unchanged/no-site pass reports when no site is admitted.

2. Add site-detail observability to bpfopt reports.

- Expected impact: highest for debugging and policy iteration.
- Needed fields: target_pc, insert_pc, ptr_reg, kind (`map_value` or `packet`), profile_present, execution_count, cache_references, cache_misses, miss_rate, and chosen distance.
- This is not performance aggregation; it is raw per-site metadata. It belongs in bpfopt pass report artifacts, not framework summary metrics.
- It would answer the task question about exact target addresses or at least target register/kind.

3. Increase or tune prefetch distance before adding more sites.

- Expected impact: high if H2 is real.
- Current target distance is 8 BPF instructions (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:18`).
- Historical design recommended 20-50 with target 32 (`docs/tmp/20260329/prefetch_kinsn_design_20260329.md:466`).
- A prefetch immediately before the first dereference is likely too late for L1 miss latency.
- Implementation should keep existing same-block and register-stability checks.

4. Add a small per-program candidate cap, selected by PMU score.

- Expected impact: medium to high for tracee/tetragon code bloat.
- Historical design already recommended a per-program budget (`docs/tmp/20260329/prefetch_kinsn_design_20260329.md:390`) and top-N site selection (`docs/tmp/20260329/prefetch_kinsn_design_20260329.md:500`).
- Cap should be a pass-local site budget, not a benchmark-level program exclusion.
- With no PMU data, cap alone is weaker because it still chooses structurally convenient sites rather than hot/missy sites.

5. Restrict site families by target value, not by benchmark app or global prog_type exclusions.

- Expected impact: medium.
- High-value candidates are likely map-value dereferences after lookup and packet pointer dereferences on hot ingress paths.
- Stack or arbitrary memory-base prefetch is not in current pass source; keep it that way unless profile proves it.
- Avoid per-prog_type pass exclusions in benchmark config because those are forbidden by No ReJIT Filtering.
- A pass-local scanner can still naturally produce zero sites for unsupported program shapes.

6. Add code-size or instruction-growth budget as a candidate limiter, not as a ReJIT filter.

- Expected impact: medium for E2BIG and bloat-bound apps.
- Each site inserts two BPF instructions before proof lowering (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:211`).
- E2BIG is a real kernel-side capacity limit and should continue surfacing if hit.
- A pure bytecode pass does not currently know the kernel page capacity, so a hard kernel-capacity guard would require new side input.
- A simple max-sites or max-insn-growth budget is less exact but keeps the CLI boundary smaller.

7. Treat EBUSY as visible kernel contention, not a prefetch codegen bug.

- Expected impact: low for prefetch source changes.
- Tetragon EBUSY also appears on zero-site passes, so it is not specific to prefetch emission.
- The daemon already records EBUSY as `failed_rejit`; do not add filtering or silent retry loops unless the benchmark methodology explicitly changes.

8. Do not implement app-level or program-name exclusion lists.

- This would violate the No ReJIT Filtering rule.
- It would also hide exactly the E2BIG/EBUSY behavior this run usefully exposes.
- Policy should be expressed as candidate admission inside the pass, with raw errors still recorded.

## Appendix A: Tracee Programs With Prefetch Sites

This appendix lists every tracee program that bpfopt reported with at least one prefetch site. Data refs point to baseline, post, and ReJIT per-program entries in the raw JSON.

| prog_id | name | type | sites | prefetch status | min_runs | ratio | delta_jit_size | data |
| --- | --- | --- | ---: | --- | ---: | ---: | ---: | --- |
| 649 | `tracepoint__exec_test` | raw_tracepoint | 111 | ok | 2 | 1.1178 | 530 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1400; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2836; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:20334` |
| 518 | `tracepoint__sched__sched_process_fork` | raw_tracepoint | 36 | failed_rejit | 6,590 | 1.0722 | 12 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:230; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1666; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5729` |
| 635 | `syscall_checker` | kprobe | 31 | ok | 0 |  | 78 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1283; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2719; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18900` |
| 535 | `uprobe_syscall_table_check` | kprobe | 29 | ok | 0 |  | 57 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:383; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1819; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7631` |
| 586 | `trace_security_mmap_file` | kprobe | 28 | ok | 324,018 | 1.1400 | 99 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:842; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2278; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13374` |
| 522 | `lkm_seeker_kset_tail` | kprobe | 27 | ok | 0 |  | 75 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:266; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1702; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6178` |
| 587 | `trace_security_file_mprotect` | kprobe | 24 | ok | 2,233,605 | 0.9948 | 72 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:851; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2287; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13486` |
| 589 | `trace_security_bpf` | kprobe | 24 | ok | 7,386 | 0.9938 | 72 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:869; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2305; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13721` |
| 606 | `trace_ret_do_init_module` | kprobe | 24 | ok | 0 |  | 87 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1022; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2458; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15639` |
| 526 | `tracepoint__sched__sched_process_exec` | raw_tracepoint | 23 | ok | 2 | 1.4250 | 69 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:302; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1738; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6618` |
| 576 | `trace_ret_kernel_write_tail` | kprobe | 23 | ok | 0 |  | 69 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:752; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2188; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12241` |
| 571 | `trace_ret_vfs_writev_tail` | kprobe | 23 | ok | 0 |  | 68 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:707; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2143; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11674` |
| 566 | `trace_ret_vfs_write_tail` | kprobe | 23 | ok | 0 |  | 69 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:662; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2098; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11110` |
| 519 | `lkm_seeker_modtree_loop` | kprobe | 23 | ok | 0 |  | 69 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:239; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1675; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5841` |
| 544 | `trace_security_file_open` | kprobe | 17 | ok | 433,171 | 0.8906 | 44 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:464; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1900; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8641` |
| 565 | `vfs_write_magic_return` | kprobe | 17 | ok | 192,169 | 1.1134 | 55 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:653; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2089; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10998` |
| 570 | `vfs_writev_magic_return` | kprobe | 17 | ok | 106 | 1.0611 | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:698; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2134; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11562` |
| 575 | `kernel_write_magic_return` | kprobe | 17 | ok | 0 |  | 55 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:743; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2179; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12129` |
| 593 | `trace_security_bpf_prog` | kprobe | 15 | ok | 161 | 1.0732 | 38 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:905; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2341; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14178` |
| 500 | `trace_sys_exit` | raw_tracepoint | 14 | ok | 34,628,297 | 1.0211 | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:68; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1504; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3667` |
| 499 | `trace_sys_enter` | raw_tracepoint | 14 | ok | 34,627,992 | 1.0207 | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:59; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1495; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3555` |
| 622 | `trace_ret_file_modified` | kprobe | 14 | ok | 216,961 | 0.9653 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1166; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2602; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:17431` |
| 620 | `trace_ret_file_update_time` | kprobe | 14 | ok | 16,397 | 0.9941 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1148; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2584; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:17209` |
| 596 | `trace_check_helper_call` | kprobe | 14 | ok | 0 |  | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:932; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2368; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14514` |
| 595 | `trace_check_map_func_compatibility` | kprobe | 14 | ok | 0 |  | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:923; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2359; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14402` |
| 538 | `trace_security_file_ioctl` | kprobe | 13 | ok | 2,163,725 | 0.9724 | 34 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:410; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1846; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7967` |
| 608 | `trace_security_file_permission` | kprobe | 13 | ok | 1,893,843 | 1.1925 | 46 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1040; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2476; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15865` |
| 549 | `trace_cap_capable` | kprobe | 13 | ok | 1,830,871 | 0.9747 | 20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:509; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1945; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9203` |
| 578 | `trace_ret_vfs_read` | kprobe | 13 | ok | 1,045,463 | 1.1321 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:770; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2206; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12466` |
| 506 | `trace_ret_arch_prctl` | kprobe | 13 | ok | 880,263 | 0.9898 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:122; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1558; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4355` |
| 617 | `trace_fd_install` | kprobe | 13 | ok | 646,236 | 0.8623 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1121; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2557; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16875` |
| 531 | `tracepoint__sched__sched_switch` | raw_tracepoint | 13 | ok | 610,402 | 0.9025 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:347; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1783; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7183` |
| 650 | `lsm_file_open_test` | lsm | 13 | ok | 433,171 | 0.9611 | 29 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1409; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2845; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:20446` |
| 583 | `trace_mmap_alert` | kprobe | 13 | ok | 431,720 | 1.1763 | -19 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:815; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2251; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13040` |
| 585 | `trace_ret_do_mmap` | kprobe | 13 | ok | 324,022 | 1.0524 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:833; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2269; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13262` |
| 634 | `trace_security_task_prctl` | kprobe | 13 | ok | 310,118 | 0.9724 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1274; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2710; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18786` |
| 618 | `trace_filp_close` | kprobe | 13 | ok | 286,928 | 1.0029 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1130; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2566; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16987` |
| 631 | `trace_security_task_setrlimit` | kprobe | 13 | ok | 243,634 | 1.0188 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1247; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2683; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18448` |
| 559 | `trace_security_socket_setsockopt` | kprobe | 13 | ok | 230,351 | 1.0607 | -20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:599; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2035; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10329` |
| 532 | `trace_filldir64` | kprobe | 13 | ok | 207,570 | 1.0433 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:356; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1792; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7295` |
| 564 | `trace_ret_vfs_write` | kprobe | 13 | ok | 192,169 | 1.1920 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:644; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2080; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10881` |
| 547 | `trace_commit_creds` | kprobe | 13 | ok | 113,977 | 1.1025 | 29 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:491; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1927; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8977` |
| 550 | `trace_security_socket_create` | kprobe | 13 | ok | 80,497 | 0.9301 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:518; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1954; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9317` |
| 556 | `trace_security_socket_connect` | kprobe | 13 | ok | 43,498 | 1.0565 | 17 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:572; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2008; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9991` |
| 557 | `trace_security_socket_accept` | kprobe | 13 | ok | 42,662 | 0.9534 | -15 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:581; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2017; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10105` |
| 613 | `trace_do_sigaction` | kprobe | 13 | ok | 8,563 | 0.9840 | 34 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1085; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2521; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16423` |
| 548 | `trace_switch_task_namespaces` | kprobe | 13 | ok | 6,595 | 1.0267 | 20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:500; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1936; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9089` |
| 534 | `trace_do_exit` | kprobe | 13 | ok | 6,595 | 0.9996 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:374; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1810; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7519` |
| 528 | `tracepoint__sched__sched_process_exit` | raw_tracepoint | 13 | ok | 6,595 | 1.0105 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:320; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1756; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6849` |
| 512 | `trace_ret_dup3` | kprobe | 13 | ok | 5,116 | 0.8195 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:176; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1612; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5054` |
| 510 | `trace_ret_dup2` | kprobe | 13 | ok | 4,852 | 0.8875 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:158; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1594; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4821` |
| 609 | `tracepoint__task__task_rename` | raw_tracepoint | 13 | ok | 4,297 | 0.9495 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1049; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2485; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15977` |
| 508 | `trace_ret_dup` | kprobe | 13 | ok | 3,746 | 0.6561 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:140; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1576; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4588` |
| 592 | `trace_security_bpf_map` | kprobe | 13 | ok | 2,608 | 1.0253 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:896; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2332; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14066` |
| 546 | `trace_security_inode_unlink` | kprobe | 13 | ok | 2,562 | 1.0029 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:482; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1918; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8865` |
| 599 | `trace_security_inode_mknod` | kprobe | 13 | ok | 2,294 | 0.9460 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:959; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2395; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14857` |
| 616 | `trace_do_truncate` | kprobe | 13 | ok | 409 | 1.0490 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1112; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2548; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16763` |
| 581 | `trace_ret_vfs_readv` | kprobe | 13 | ok | 106 | 0.8987 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:797; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2233; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12808` |
| 569 | `trace_ret_vfs_writev` | kprobe | 13 | ok | 106 | 0.9261 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:689; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2125; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:11445` |
| 558 | `trace_security_socket_bind` | kprobe | 13 | ok | 24 | 1.0879 | 29 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:590; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2026; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10217` |
| 555 | `trace_security_socket_listen` | kprobe | 13 | ok | 20 | 1.1727 | -29 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:563; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1999; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9877` |
| 607 | `trace_load_elf_phdrs` | kprobe | 13 | ok | 4 | 1.3843 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1031; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2467; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15751` |
| 630 | `trace_set_fs_pwd` | kprobe | 13 | ok | 2 | 1.2330 | 23 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1238; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2674; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18334` |
| 628 | `trace_execute_finished` | kprobe | 13 | ok | 2 | 1.2712 | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1220; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2656; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18110` |
| 627 | `trace_security_bprm_creds_for_exec` | kprobe | 13 | ok | 2 | 1.1173 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1211; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2647; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:17994` |
| 626 | `trace_exec_binprm` | kprobe | 13 | ok | 2 | 1.1938 | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1202; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2638; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:17877` |
| 543 | `trace_security_bprm_check` | kprobe | 13 | ok | 2 | 1.2766 | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:455; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1891; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8529` |
| 636 | `trace_security_sb_umount` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1292; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2728; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19012` |
| 633 | `trace_chmod_common` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1265; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2701; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18672` |
| 632 | `trace_security_settime64` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1256; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2692; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18560` |
| 629 | `trace_security_path_notify` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1229; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2665; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:18222` |
| 624 | `trace_ret_inotify_find_inode` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1184; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2620; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:17653` |
| 615 | `trace_utimes_common` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1103; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2539; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16649` |
| 614 | `trace_vfs_utimes` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1094; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2530; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16535` |
| 612 | `trace_ret_kallsyms_lookup_name` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1076; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2512; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16311` |
| 610 | `trace_security_inode_rename` | kprobe | 13 | ok | 0 |  | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1058; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2494; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:16089` |
| 604 | `tracepoint__module__module_free` | raw_tracepoint | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1004; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2440; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15417` |
| 603 | `tracepoint__module__module_load` | raw_tracepoint | 13 | ok | 0 |  | 35 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:995; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2431; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15303` |
| 602 | `trace_ret__register_chrdev` | kprobe | 13 | ok | 0 |  | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:986; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2422; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15191` |
| 600 | `trace_device_add` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:968; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2404; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14969` |
| 598 | `trace_security_kernel_post_read_file` | kprobe | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:950; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2386; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14738` |
| 597 | `trace_security_kernel_read_file` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:941; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2377; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14626` |
| 594 | `trace_bpf_check` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:914; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2350; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14290` |
| 591 | `trace_ret_register_kprobe` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:887; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2323; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13954` |
| 574 | `trace_ret_kernel_write` | kprobe | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:734; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2170; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12012` |
| 554 | `trace_debugfs_create_dir` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:554; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1990; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9765` |
| 553 | `trace_debugfs_create_file` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:545; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1981; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9653` |
| 552 | `trace_proc_create` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:536; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1972; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9541` |
| 551 | `trace_security_inode_symlink` | kprobe | 13 | ok | 0 |  | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:527; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1963; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:9429` |
| 545 | `trace_security_sb_mount` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:473; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1909; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8753` |
| 542 | `tracepoint__cgroup__cgroup_rmdir` | raw_tracepoint | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:446; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1882; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8417` |
| 541 | `tracepoint__cgroup__cgroup_mkdir` | raw_tracepoint | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:437; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1873; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8305` |
| 540 | `tracepoint__cgroup__cgroup_attach_task` | raw_tracepoint | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:428; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1864; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8193` |
| 539 | `trace_tracepoint_probe_register_prio_may_exist` | kprobe | 13 | ok | 0 |  | 20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:419; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1855; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:8079` |
| 533 | `trace_call_usermodehelper` | kprobe | 13 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:365; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1801; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7407` |
| 504 | `trace_ret_process_vm_writev` | kprobe | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:104; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1540; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:4122` |
| 502 | `trace_ret_ptrace` | kprobe | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:86; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1522; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3889` |
| 498 | `sys_exit_submit` | raw_tracepoint | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:50; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1486; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3433` |
| 495 | `sys_enter_submit` | raw_tracepoint | 13 | ok | 0 |  | 39 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:23; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1459; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3097` |
| 641 | `trace_security_socket_sendmsg` | kprobe | 12 | ok | 1,615,198 | 0.9128 | -56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1337; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2773; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19564` |
| 640 | `trace_security_socket_recvmsg` | kprobe | 12 | ok | 565,211 | 0.9105 | -56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1328; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2764; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19454` |
| 638 | `trace_ret_sock_alloc_file` | kprobe | 12 | ok | 145,544 | 0.8175 | -62 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1310; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2746; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19234` |
| 582 | `trace_ret_vfs_readv_tail` | kprobe | 12 | ok | 0 |  | 32 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:806; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2242; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12925` |
| 579 | `trace_ret_vfs_read_tail` | kprobe | 12 | ok | 0 |  | 34 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:779; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2215; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:12583` |
| 530 | `syscall__accept4` | raw_tracepoint | 11 | ok | 0 |  | -38 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:338; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1774; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7071` |
| 517 | `sys_dup_exit_tail` | kprobe | 11 | failed_rejit | 0 |  | 13 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:221; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1657; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5617` |
| 516 | `syscall__execveat_exit` | raw_tracepoint | 11 | ok | 0 |  | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:212; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1648; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5507` |
| 515 | `syscall__execveat_enter` | raw_tracepoint | 11 | ok | 0 |  | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:203; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1639; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5397` |
| 514 | `syscall__execve_exit` | raw_tracepoint | 11 | ok | 0 |  | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:194; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1630; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5287` |
| 513 | `syscall__execve_enter` | raw_tracepoint | 11 | ok | 0 |  | 56 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:185; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1621; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5177` |
| 645 | `cgroup_skb_egress` | cgroup_skb | 10 | ok | 1,452,582 | 0.8534 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1364; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2800; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19894` |
| 644 | `cgroup_skb_ingress` | cgroup_skb | 10 | ok | 824,054 | 1.0265 | 31 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1355; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2791; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19784` |
| 521 | `uprobe_lkm_seeker` | kprobe | 8 | ok | 0 |  | 20 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:257; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1693; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6063` |
| 537 | `uprobe_mem_dump_trigger` | kprobe | 5 | ok | 0 |  | -13 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:401; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1837; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7855` |
| 525 | `lkm_seeker_new_mod_only_tail` | kprobe | 5 | ok | 0 |  | 11 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:293; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1729; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6508` |
| 524 | `lkm_seeker_proc_tail` | kprobe | 5 | ok | 0 |  | 11 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:284; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1720; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6398` |
| 520 | `uprobe_lkm_seeker_submitter` | kprobe | 5 | ok | 0 |  | -21 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:248; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1684; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5951` |
| 651 | `uprobe__features_fallback_arena` | kprobe | 3 | ok | 0 |  | -21 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1418; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2854; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:20558` |
| 536 | `uprobe_seq_ops_trigger` | kprobe | 3 | ok | 0 |  | -21 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:392; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1828; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:7743` |
| 523 | `lkm_seeker_mod_tree_tail` | kprobe | 3 | ok | 0 |  | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:275; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1711; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6288` |
| 642 | `cgroup_bpf_run_filter_skb` | kprobe | 2 | ok | 2,368,329 | 1.0651 | -105 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1346; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2782; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19674` |
| 496 | `tracepoint__raw_syscalls__sys_exit` | raw_tracepoint | 1 | ok | 34,628,297 | 1.0064 | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:32; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1468; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3213` |
| 493 | `tracepoint__raw_syscalls__sys_enter` | raw_tracepoint | 1 | ok | 34,627,992 | 0.9738 | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1441; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2877` |
| 529 | `tracepoint__sched__sched_process_free` | raw_tracepoint | 1 | ok | 6,598 | 0.9917 | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:329; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1765; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:6961` |
| 561 | `send_bin_tp` | raw_tracepoint | 1 | ok | 0 |  | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:617; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2053; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10551` |
| 560 | `send_bin` | kprobe | 1 | ok | 0 |  | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:608; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2044; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:10441` |
| 497 | `sys_exit_init` | raw_tracepoint | 1 | ok | 0 |  | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:41; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1477; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3323` |
| 494 | `sys_enter_init` | raw_tracepoint | 1 | ok | 0 |  | 3 | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:14; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1450; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2987` |

## Appendix B: Retained Tracee Programs

Retained means `min_runs >= 100`. Rows include programs with zero prefetch sites because final app-level B/C includes all comparable retained programs, not only changed programs.

| prog_id | name | sites | min_runs | ratio | baseline avg ns | post avg ns |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| 496 | `tracepoint__raw_syscalls__sys_exit` | 1 | 34,628,297 | 1.0064 | 304.96 | 306.92 |
| 500 | `trace_sys_exit` | 14 | 34,628,297 | 1.0211 | 254.26 | 259.64 |
| 493 | `tracepoint__raw_syscalls__sys_enter` | 1 | 34,627,992 | 0.9738 | 164.12 | 159.82 |
| 499 | `trace_sys_enter` | 14 | 34,627,992 | 1.0207 | 254.88 | 260.17 |
| 642 | `cgroup_bpf_run_filter_skb` | 2 | 2,368,329 | 1.0651 | 238.14 | 253.65 |
| 587 | `trace_security_file_mprotect` | 24 | 2,233,605 | 0.9948 | 411.80 | 409.68 |
| 538 | `trace_security_file_ioctl` | 13 | 2,163,725 | 0.9724 | 99.16 | 96.42 |
| 608 | `trace_security_file_permission` | 13 | 1,893,843 | 1.1925 | 39.76 | 47.41 |
| 549 | `trace_cap_capable` | 13 | 1,830,871 | 0.9747 | 129.05 | 125.78 |
| 641 | `trace_security_socket_sendmsg` | 12 | 1,615,198 | 0.9128 | 303.53 | 277.07 |
| 645 | `cgroup_skb_egress` | 10 | 1,452,582 | 0.8534 | 352.66 | 300.96 |
| 577 | `trace_vfs_read` | 0 | 1,045,463 | 1.0097 | 66.00 | 66.64 |
| 578 | `trace_ret_vfs_read` | 13 | 1,045,463 | 1.1321 | 726.45 | 822.45 |
| 505 | `trace_arch_prctl` | 0 | 880,263 | 1.0106 | 67.61 | 68.33 |
| 506 | `trace_ret_arch_prctl` | 13 | 880,263 | 0.9898 | 260.16 | 257.51 |
| 644 | `cgroup_skb_ingress` | 10 | 824,054 | 1.0265 | 263.90 | 270.90 |
| 617 | `trace_fd_install` | 13 | 646,236 | 0.8623 | 306.93 | 264.68 |
| 531 | `tracepoint__sched__sched_switch` | 13 | 610,402 | 0.9025 | 458.08 | 413.43 |
| 640 | `trace_security_socket_recvmsg` | 12 | 565,211 | 0.9105 | 279.78 | 254.75 |
| 544 | `trace_security_file_open` | 17 | 433,171 | 0.8906 | 633.68 | 564.36 |
| 650 | `lsm_file_open_test` | 13 | 433,171 | 0.9611 | 277.18 | 266.40 |
| 583 | `trace_mmap_alert` | 13 | 431,720 | 1.1763 | 119.65 | 140.74 |
| 584 | `trace_do_mmap` | 0 | 324,022 | 1.2312 | 61.85 | 76.15 |
| 585 | `trace_ret_do_mmap` | 13 | 324,022 | 1.0524 | 332.24 | 349.63 |
| 586 | `trace_security_mmap_file` | 28 | 324,018 | 1.1400 | 111.27 | 126.85 |
| 634 | `trace_security_task_prctl` | 13 | 310,118 | 0.9724 | 331.74 | 322.59 |
| 618 | `trace_filp_close` | 13 | 286,928 | 1.0029 | 308.38 | 309.28 |
| 631 | `trace_security_task_setrlimit` | 13 | 243,634 | 1.0188 | 282.91 | 288.24 |
| 559 | `trace_security_socket_setsockopt` | 13 | 230,351 | 1.0607 | 318.79 | 338.13 |
| 621 | `trace_file_modified` | 0 | 216,961 | 0.9120 | 106.06 | 96.72 |
| 622 | `trace_ret_file_modified` | 14 | 216,961 | 0.9653 | 451.77 | 436.08 |
| 532 | `trace_filldir64` | 13 | 207,570 | 1.0433 | 17.01 | 17.75 |
| 562 | `trace_vfs_write` | 0 | 192,169 | 1.0645 | 70.80 | 75.37 |
| 563 | `vfs_write_magic_enter` | 0 | 192,169 | 1.8170 | 31.11 | 56.52 |
| 564 | `trace_ret_vfs_write` | 13 | 192,169 | 1.1920 | 537.34 | 640.53 |
| 565 | `vfs_write_magic_return` | 17 | 192,169 | 1.1134 | 60.05 | 66.86 |
| 637 | `trace_sock_alloc_file` | 0 | 145,544 | 0.7790 | 67.38 | 52.49 |
| 638 | `trace_ret_sock_alloc_file` | 12 | 145,544 | 0.8175 | 378.66 | 309.55 |
| 547 | `trace_commit_creds` | 13 | 113,977 | 1.1025 | 250.42 | 276.08 |
| 550 | `trace_security_socket_create` | 13 | 80,497 | 0.9301 | 363.42 | 338.02 |
| 556 | `trace_security_socket_connect` | 13 | 43,498 | 1.0565 | 406.99 | 429.97 |
| 557 | `trace_security_socket_accept` | 13 | 42,662 | 0.9534 | 552.65 | 526.87 |
| 639 | `trace_security_sk_clone` | 0 | 41,742 | 1.0936 | 759.80 | 830.93 |
| 619 | `trace_file_update_time` | 0 | 16,397 | 1.0089 | 229.45 | 231.49 |
| 620 | `trace_ret_file_update_time` | 14 | 16,397 | 0.9941 | 871.21 | 866.05 |
| 613 | `trace_do_sigaction` | 13 | 8,563 | 0.9840 | 846.95 | 833.44 |
| 589 | `trace_security_bpf` | 24 | 7,386 | 0.9938 | 232.73 | 231.28 |
| 529 | `tracepoint__sched__sched_process_free` | 1 | 6,598 | 0.9917 | 854.52 | 847.42 |
| 528 | `tracepoint__sched__sched_process_exit` | 13 | 6,595 | 1.0105 | 1071.80 | 1083.07 |
| 534 | `trace_do_exit` | 13 | 6,595 | 0.9996 | 671.68 | 671.40 |
| 548 | `trace_switch_task_namespaces` | 13 | 6,595 | 1.0267 | 627.68 | 644.45 |
| 518 | `tracepoint__sched__sched_process_fork` | 36 | 6,590 | 1.0722 | 2565.97 | 2751.34 |
| 511 | `trace_dup3` | 0 | 5,116 | 0.9856 | 112.43 | 110.82 |
| 512 | `trace_ret_dup3` | 13 | 5,116 | 0.8195 | 540.90 | 443.27 |
| 509 | `trace_dup2` | 0 | 4,852 | 1.0208 | 135.29 | 138.10 |
| 510 | `trace_ret_dup2` | 13 | 4,852 | 0.8875 | 620.28 | 550.47 |
| 609 | `tracepoint__task__task_rename` | 13 | 4,297 | 0.9495 | 842.67 | 800.11 |
| 507 | `trace_dup` | 0 | 3,746 | 0.8603 | 272.79 | 234.67 |
| 508 | `trace_ret_dup` | 13 | 3,746 | 0.6561 | 1022.32 | 670.75 |
| 592 | `trace_security_bpf_map` | 13 | 2,608 | 1.0253 | 239.68 | 245.73 |
| 546 | `trace_security_inode_unlink` | 13 | 2,562 | 1.0029 | 1229.46 | 1233.08 |
| 599 | `trace_security_inode_mknod` | 13 | 2,294 | 0.9460 | 1111.23 | 1051.26 |
| 616 | `trace_do_truncate` | 13 | 409 | 1.0490 | 2019.98 | 2118.88 |
| 593 | `trace_security_bpf_prog` | 15 | 161 | 1.0732 | 623.59 | 669.22 |
| 567 | `trace_vfs_writev` | 0 | 106 | 1.7704 | 279.58 | 494.95 |
| 568 | `vfs_writev_magic_enter` | 0 | 106 | 0.9763 | 513.02 | 500.88 |
| 569 | `trace_ret_vfs_writev` | 13 | 106 | 0.9261 | 4236.81 | 3923.77 |
| 570 | `vfs_writev_magic_return` | 17 | 106 | 1.0611 | 2963.19 | 3144.37 |
| 580 | `trace_vfs_readv` | 0 | 106 | 1.1009 | 327.59 | 360.64 |
| 581 | `trace_ret_vfs_readv` | 13 | 106 | 0.8987 | 2363.75 | 2124.39 |

## Appendix C: Tetragon Prefetch Failures

| prog_id | name | type | sites | status | root cause | full first-line error |
| --- | --- | --- | ---: | --- | --- | --- |
| 177 | `execve_send` | tracepoint | 12 | failed_rejit | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` |
| 178 | `event_execve` | tracepoint | 18 | failed_rejit | E2BIG: replacement program exceeded kernel ReJIT capacity | `BPF_PROG_REJIT errno 7: Argument list too long (os error 7)` |
| 218 | `generic_kprobe_process_event` | kprobe | 8 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 275 | `generic_kprobe_output` | kprobe | 2 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 276 | `generic_kprobe_actions` | kprobe | 10 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 279 | `generic_kprobe_filter_arg` | kprobe | 3 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 281 | `generic_kprobe_output` | kprobe | 2 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 314 | `generic_retkprobe_output` | kprobe | 2 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |
| 351 | `generic_kprobe_actions` | kprobe | 10 | failed_rejit | EBUSY: kernel object busy during ReJIT | `BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)` |

## Appendix D: Source Citation Index

| Topic | Citation |
| --- | --- |
| Paper plan current prefetch status | `docs/kernel-jit-optimization-plan.md:247` |
| Historical runtime-guided warning | `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:9` |
| Historical missing-profile skip | `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:24` |
| Historical profile-gated rule | `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:395` |
| Historical distance recommendation | `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:466` |
| Historical top-N budget | `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:500` |
| PrefetchV2 structural default note | `docs/tmp/p89_prefetchv2_impl.md:5` |
| Prefetch pass structural doc comment | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:35` |
| Prefetch constants | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:17` |
| Kfunc availability skip | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:124` |
| Packed ABI availability skip | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:134` |
| Site scan loop and PMU/default choice | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:154` |
| Default score on missing PMU | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:166` |
| Candidate insertion and packed kinsn emit | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:200` |
| Pass result site counters only | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:237` |
| Map-value scanner | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:311` |
| Packet scanner | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:408` |
| Packet prog type layout | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:443` |
| Insertion-window checks | `bpfopt/crates/bpfopt/src/passes/prefetch.rs:564` |
| Prefetch proof length validator | `bpfopt/crates/bpfopt/src/passes/utils.rs:575` |
| x86 prefetch module | `module/x86/bpf_prefetch.c:3` |
| x86 payload decoder | `module/x86/bpf_prefetch.c:16` |
| x86 proof no-op | `module/x86/bpf_prefetch.c:34` |
| x86 PREFETCHT0 emitter | `module/x86/bpf_prefetch.c:58` |
| x86 kinsn descriptor | `module/x86/bpf_prefetch.c:108` |
| ARM64 prefetch module | `module/arm64/bpf_prefetch.c:3` |
| ARM64 PRFM encoding | `module/arm64/bpf_prefetch.c:45` |
| Shared x86 BPF register mapping | `module/include/kinsn_common.h:46` |
| Shared ARM64 BPF register mapping | `module/include/kinsn_common.h:92` |
| Kernel x86 kinsn JIT call hook | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579` |
| Kernel ARM64 kinsn JIT call hook | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1201` |
| Kernel verifier kinsn proof lowering | `vendor/linux-framework/kernel/bpf/verifier.c:3669` |
| Daemon per-pass loop | `daemon/src/commands.rs:530` |
| Daemon bpfopt pass invocation | `daemon/src/commands.rs:566` |
| Daemon ReJIT call | `daemon/src/commands.rs:617` |
| Daemon failed_rejit pass detail | `daemon/src/commands.rs:625` |
| Kernel-sys ReJIT error formatting | `bpfopt/crates/kernel-sys/src/lib.rs:430` |
| Kernel-sys prog_rejit API | `bpfopt/crates/kernel-sys/src/lib.rs:1298` |
| Benchmark default x86 prefetch entry | `corpus/config/benchmark_config.yaml:16` |
| Benchmark default arm64 prefetch entry | `corpus/config/benchmark_config.yaml:30` |

## Appendix E: Raw Data Citation Index

| App | raw detail file |
| --- | --- |
| tracee/monitor | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json` |
| tetragon/observer | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json` |
| otelcol-profiling | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/otelcol-ebpf-profiler__profiling.json` |
| cilium/agent | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json` |
| katran | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/katran.json` |
| bpftrace/runqlat | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/bpftrace__runqlat.json` |

Representative raw-data entry line refs:

| App | prog_id | meaning | line refs |
| --- | ---: | --- | --- |
| tracee/monitor | 649 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1400; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2836; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:20334` |
| tracee/monitor | 518 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:230; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1666; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5729` |
| tracee/monitor | 586 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:842; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2278; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:13374` |
| tracee/monitor | 608 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1040; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2476; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:15865` |
| tracee/monitor | 645 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1364; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2800; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:19894` |
| tracee/monitor | 493 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:5; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1441; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:2877` |
| tracee/monitor | 500 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:68; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:1504; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tracee__monitor.json:3667` |
| tetragon/observer | 177 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:23; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2620; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:5421` |
| tetragon/observer | 178 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:32; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2629; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:5531` |
| tetragon/observer | 218 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:374; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2971; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:9933` |
| tetragon/observer | 275 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:887; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3484; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:16582` |
| tetragon/observer | 276 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:896; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3493; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:16692` |
| tetragon/observer | 279 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:923; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3520; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:17036` |
| tetragon/observer | 281 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:941; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3538; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:17284` |
| tetragon/observer | 314 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:1238; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:3835; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:21150` |
| tetragon/observer | 351 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:1571; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:4168; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:25493` |
| tetragon/observer | 364 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:1688; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:4285; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:27004` |
| tetragon/observer | 403 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:2039; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:4636; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/tetragon__observer.json:31535` |
| cilium/agent | 156 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:194; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:433; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:2853` |
| cilium/agent | 151 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:158; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:397; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:2401` |
| cilium/agent | 138 | baseline/post/rejit program entry starts | `corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:41; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:280; corpus/results/x86_kvm_corpus_20260506_023522_768608/details/apps/cilium__agent.json:925` |
