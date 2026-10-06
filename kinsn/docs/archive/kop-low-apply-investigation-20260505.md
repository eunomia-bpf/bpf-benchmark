# kop passes low-apply investigation - 2026-05-05

## TL;DR

- Live run strict matched/applied counts over `corpus/results/x86_kvm_corpus_20260505_080808_516617`: rotate `0/0`, cond_select `1/1`, extract `3/3`, endian_fusion `4/4`.
- Static source-pattern census over available selected-app objects found: rotate `0`, cond_select detector-shape `2179` but current applicable subset only `2`, extract source `51` / strict `49`, endian source `130` / strict `98`. Scanner: one-off `python3` + `pyelftools` over executable ELF sections, no repo script written.
- There is no evidence of pass-level skip cascades for these four passes in successful program records: every matched site applied and every `skip_reasons` map is empty. Example records: cond_select in `tracee__monitor` prog `602` has `sites_matched=1`, `sites_applied=1`, `sites_skipped=0` at `corpus/results/.../tracee__monitor.json:10777`; extract in `bcc__capable` prog `6` has `1/1/0` at `corpus/results/.../bcc__capable.json:96`; endian in Cilium prog `132` has `1/1/0` at `corpus/results/.../cilium__agent.json:1431`.
- There are 66 per-program errors; 52 fail at pass `rotate` after `0` committed passes, mostly Tetragon, so later passes never run for those programs. Example: `tetragon__observer.json:5701` reports `prog 185 pass rotate failed after 0 committed passes` and then `passes: []` at `:5716`.
- Root cause by pass: rotate source idiom is absent in available corpus objects; cond_select is dominated by immediate operands and non-zero/non-JEQ/JNE comparisons; extract/endian have many static object candidates, but the run artifacts do not store live bytecode PCs, and object section sizes differ from live `orig_insn_count`, so current low live applies cannot be attributed to pass skips.

## Per pass

### rotate

- Pass impl: `bpfopt/crates/bpfopt/src/passes/rotate.rs:32` checks `bpf_rotate64` availability, `:43` checks packed ABI, `:58` scans sites, and `:64` through `:100` applies only interior-branch, subprog/tail-call, and `tmp_reg live after site` safety checks.
- Pattern matched: exact adjacent provenance copy plus complementary shift pair plus OR:

```text
MOV64_X tmp, val
RSH64_K rA, s_rsh
LSH64_K rB, s_lsh
OR64_X or_dst, or_src
where s_rsh + s_lsh == 64, rA != rB, OR combines rA/rB, and MOV copies one shifted register from the other.
```

Pattern A is documented and implemented at `rotate.rs:242` through `:289`; Pattern B swaps shift order at `:297` through `:335`. The adjacent provenance requirement is explicit at `rotate.rs:215` through `:228`. Tests cover normal, reversed, clang-style, no-provenance, and non-adjacent provenance cases at `rotate.rs:363` through `:477`.

- Skip reasons enumeration: kfunc unavailable (`rotate.rs:32`), packed ABI unavailable (`:43`), interior branch target (`:64`), subprog/tail-call guard (`utils.rs:719` through `:785`), and live-out tmp register (`rotate.rs:88` through `:100`).
- Corpus candidate count: static scanner found `0` liberal shift/shift/or source cores and `0` strict rotate sites in selected available objects. This includes selected BCC objects, Tracee, Katran, and `corpus/build/cilium/*.bpf.o`. The broader available-object scan over 68 objects also found `0`.
- Found in: none. I also checked for the liberal core before requiring the adjacent MOV; still zero.
- Why 0 applied: not a verifier rejection or prog-type filter. The pass has no prog-type/hook check, and successful result entries have no rotate skips. The available bytecode simply does not contain the rotate idiom. Historical `701 sites, 15 applied` is not current-corpus evidence; it was introduced in the plan table by commit `e8764559` on 2026-03-24, and nearby historical docs describe synthetic micro `rotate_dense` as `256 sites` (`docs/tmp/20260318/micro_performance_improvement_analysis_20260318.md:92`, `docs/tmp/20260322/micro_analysis_v2_20260322.md:131`).
- Improvement opportunity: low priority. A broader matcher for non-adjacent provenance would not help this run because the shift/shift/or core itself is absent. If future bytecode shows 32-bit rotate idioms, add an ALU32 variant; otherwise leave rotate unchanged.

### cond_select

- Pass impl: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:131` checks CMOV, `:142` checks `bpf_select64`, `:171` checks packed ABI, and `:184` scans sites.
- Pattern matched:

```text
Pattern A:
Jcc +2
MOV64 dst, false_val
JA +1
MOV64 dst, true_val

Pattern C:
MOV64 dst, true_val
Jcc +1
MOV64 dst, false_val
```

Pattern A is implemented at `cond_select.rs:342` through `:365`; Pattern C at `:371` through `:415`. Current transformation only accepts simple zero tests: `JNE reg, 0` or `JEQ reg, 0` (`cond_select.rs:74` through `:83`) and packed ABI currently requires both true/false values to be registers (`cond_select.rs:107` through `:114`, checked at `:221`).

- Skip reasons enumeration: platform lacks CMOV (`cond_select.rs:131`), kfunc unavailable (`:142`), packed ABI unavailable (`:171`), non-simple zero test (`:189`), interior branch target (`:202`), immediate true/false operands (`:221`), and subprog/tail-call guard (`utils.rs:719` through `:785`).
- Corpus candidate count: static selected-object scan found `2179` detector-shaped branch+MOV sites but only `2` satisfy current side conditions. Classification: `1644` immediate-operand sites, `526` non-simple plus immediate sites, `7` non-simple register sites, `2` applicable.
- Found in:

```text
corpus/build/x86_64/tracee/tracee.bpf.o kretprobe/__register_chrdev pc 1313
1313: r2 = r4
1314: if r3 == 0x0 goto +1
1315: r2 = r1
```

This corresponds to the one live apply in `tracee__monitor` prog `602` (`trace_ret__register_chrdev` in baseline metadata at `tracee__monitor.json:2422`; pass result at `:10777`).

Another static applicable site appears in `corpus/build/cilium/bpf_lxc.bpf.o tc/tail tail_handle_ipv4_cont pc 26906`, but current Cilium has error records, including `cond_select` failures after one committed pass in the aggregate error distribution; the run artifact does not expose whether that exact static object/section was the live loaded bytecode.

- Why only 1 applied: pattern narrowness is real, but mostly from side conditions, not from bytecode absence. LLVM commonly emits the short conditional-move shape, but most are boolean/immediate selections such as:

```text
runqlat.bpf.o .text pc 144
144: r1 = 0x3e8
145: if r2 == 0x0 goto +1
146: r1 = 0xf4240
```

The detector sees these, but packed `bpf_select64` cannot encode immediate operands today. The next largest class uses comparisons such as `if r2 > 0xffff`, which `bpf_select64(a,b,cond != 0)` cannot represent without a compare-producing kop.
- Improvement opportunity: first broaden packed select to support small immediates in the sidecar or a proof sequence that materializes immediates without needing free caller-saved registers. Second, add a separate compare-select kop only if profiling shows non-zero-test compare sites are hot; otherwise this becomes a large semantic expansion for mostly cold boolean setup.

### extract

- Pass impl: `bpfopt/crates/bpfopt/src/passes/extract.rs:114` checks `bpf_extract64`, `:125` checks packed ABI, and `:138` scans sites.
- Pattern matched:

```text
RSH64_K dst, shift
AND64_K dst, mask
where mask is a low contiguous mask `(1 << len) - 1` and `shift + len <= 64`.
```

The scanner is at `extract.rs:58` through `:96`, with low-contiguous mask check at `:43` through `:55`. Tests cover contiguous masks, different regs, non-contiguous masks, width 1, sign-extended all-ones, and shift zero at `extract.rs:297` through `:735`.

- Skip reasons enumeration: kfunc unavailable (`extract.rs:114`), packed ABI unavailable (`:125`), interior branch target (`:143`), and subprog/tail-call guard (`utils.rs:719` through `:785`). One hidden correctness mismatch: the proof helper rejects `bit_len > 32` at `utils.rs:495` through `:502`, while the scanner can accept up to 64; no current run error points at this, but the scanner and proof contract should be aligned.
- Corpus candidate count: static selected-object scan found `51` source `RSH64; AND64` pairs and `49` strict extract sites. Two rejected source examples are non-low masks:

```text
tracee.bpf.o cgroup_skb/ingress pc 522: r2 >>= 2; r2 &= 0x3c
tracee.bpf.o cgroup_skb/egress pc 522: r2 >>= 2; r2 &= 0x3c
```

These are not equivalent to a low-aligned extract unless the replacement also shifts the result back.

- Found in:

```text
corpus/build/x86_64/bcc/libbpf-tools/.output/capable.bpf.o kretprobe/cap_capable pc 48
48: r2 >>= 2
49: r2 &= 0x1

corpus/build/x86_64/tracee/tracee.bpf.o raw_tracepoint/sched_process_exec pc 9115
9115: r1 >>= 21
9116: r1 &= 0x1

corpus/build/x86_64/tracee/tracee.bpf.o kprobe/process_execute_failed_tail pc 2016
2016: r1 >>= 21
2017: r1 &= 0x1
```

Live applies are `bcc__capable` prog `6` (`bcc__capable.json:96`), `tracee__monitor` prog `527` (`tracee__monitor.json:5310`), and `tracee__monitor` prog `625` (same JSON, program key at `:1193`).

- Why only 3 applied: not skip reasons; every live matched extract applied. Static objects show many strict candidates, but they are not a faithful byte-for-byte snapshot of live optimized programs. For example, static `tracee.bpf.o raw_tracepoint/sys_exit_submit` has `2553` insns, while live prog `498` reports `orig_insn_count=2469` in `tracee__monitor.json` output, and it has `extract sites_matched=0`. The current artifact does not store live bytecode PCs, so this cannot be reconciled post-hoc.
- Improvement opportunity: add ALU32/narrow-store extraction detection only if a standalone scanner over live `BPF_PROG_GET_ORIGINAL` dumps confirms those forms. Do not add non-low-mask support unless the kop semantics or replacement includes the required post-shift.

### endian_fusion

- Pass impl: `bpfopt/crates/bpfopt/src/passes/endian.rs:242` checks any endian kfunc, `:256` checks packed ABI availability, and `:275` scans sites.
- Pattern matched:

```text
LDX_MEM size, dst, [src + off]
END_TO_BE dst, bits
where dst matches and (size,bits) is (H,16), (W,32), or (DW,64).
```

The scanner is at `endian.rs:49` through `:103`; size-specific kfunc dispatch is at `:105` through `:122`; offset encoding and direct/fallback packed call emission are at `:131` through `:225`.

- Skip reasons enumeration: no endian kfunc (`endian.rs:242`), no packed ABI (`:256`), size kfunc unavailable (`:279`), interior branch target (`:298`), specific packed ABI unavailable (`:309`), and subprog/tail-call guard (`utils.rs:719` through `:785`).
- Corpus candidate count: static selected-object scan found `130` load+be source pairs and `98` strict sites. The `32` non-strict sites are all `LDXDW` followed by `be16` or `be32`:

```text
katran/balancer.bpf.o xdp pc 1047: r8 = *(u64 *)(r10 - 0x90); r8 = be16(r8)
cilium/bpf_host.bpf.o tc/tail pc 4229: r1 = *(u64 *)(r10 - 0xe0); r1 = be32(r1)
```

- Found in:

```text
corpus/build/cilium/bpf_host.bpf.o tc/entry cil_to_host pc 12434
12434: r4 = *(u16 *)(r10 - 0x50)
12435: r4 = be16(r4)

corpus/build/x86_64/katran/balancer.bpf.o xdp balancer_ingress pc 353
353: r1 = *(u32 *)(r8 + 0x3a)
354: r1 = be32(r1)
```

Live applies are all Cilium `cil_to_host` programs: ids `132`, `142`, `149`, and `158`; id `132` has `sites_matched=1`, `sites_applied=1`, `sites_skipped=0` at `cilium__agent.json:1431`.

- Why only 4 applied: again, not skip reasons. The strict pattern is common in static Cilium objects, but the current run only loaded or successfully processed four live programs with a strict endian site. Some Cilium programs also fail earlier or later in the per-pass pipeline; the run has seven Cilium per-program errors.
- Improvement opportunity: safely broaden `LDXDW + be16/be32` when the higher loaded bytes are provably unused. This requires a proof sequence or liveness/range condition because the current strict matcher intentionally requires load size and endian width to match.

## Cross-cutting issues

- The run directory contains 18 per-app JSON files, not 16: 8 BCC entries, 5 bpftrace entries, plus Cilium, Katran, otelcol-ebpf-profiler, Tetragon, and Tracee. The total per-program entries still match the puzzle number: 529 programs, with 463 `status=ok` and 66 `status=error`.
- No prog type or hook filter exists in these passes. The code checks platform/kfunc/packed ABI, then scans all bytecode. Current applies span kprobe (`cond_select`, `extract`), raw_tracepoint (`extract`), and Cilium sched_cls (`endian_fusion`), so prog type is not the cause.
- No map-related skip reasons appear for these four passes. Successful pass records have empty `skip_reasons`; failed records are kernel ReJIT errors, not pass skip decisions.
- The result JSON `sites_matched` field is not a raw detector count unless the daemon supplies it. Runner fallback computes `sites_matched = sites_applied + sites_skipped` at `runner/libs/rejit.py:276` through `:282`. Because these passes report no skipped sites, the run cannot tell us how many detector-shaped but unreported non-candidates existed inside bpfopt.
- Static object bytecode and live run bytecode are not identical enough for exact PC reconciliation. The requested `corpus/build/x86_64/cilium`, `bpftrace`, `tetragon`, and `otelcol-ebpf-profiler` object paths are absent; Cilium objects exist under `corpus/build/cilium`. Bpftrace appears to compile dynamic snippets, and no per-run BPF objects are present in the result directory.
- Historical counts are out of date/mixed. Plan §3.1 lines `205` through `209` were added by `e8764559` on 2026-03-24. Nearby historical docs tie rotate/endian counts to micro dense benchmarks, while `docs/tmp/20260323/kop_implementation_review_20260323.md:82` through `:91` says cond_select had `0` sites at that moment because only zero-test conditions were supported. `docs/tmp/20260329/rdtsc_adc_kop_research_20260329.md:57` through `:62` repeats those same numbers as plan evidence, not a fresh measurement. Treat the plan table as historical planning context, not current corpus ground truth.

## Recommendations

1. **Cond_select immediate operands** - medium effort, highest payoff. Extend packed select encoding or proof lowering for immediate true/false values. This attacks `1644/2179` static detector sites in selected objects.
2. **Endian DW-load narrowing** - medium effort. Add a guarded `LDXDW + be16/be32` matcher with proof that upper bytes are irrelevant. Static selected objects have `32` such source pairs.
3. **Live-bytecode research artifact** - low/medium effort, outside `result.json` metrics. For investigations, dump original bytecode to external debug artifacts or run a standalone scanner against `BPF_PROG_GET_ORIGINAL` output. Without this, static object PCs cannot be reconciled with live pass counts.
4. **Extract ALU32/narrow-store census first** - low effort research, implementation TBD. Do not broaden until live-bytecode census shows common safe forms.
5. **Rotate no action for this corpus** - low priority. Available bytecode has zero source rotate cores, so matcher broadening would not improve the current run.
