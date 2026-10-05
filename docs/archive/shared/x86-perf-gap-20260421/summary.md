# x86 KVM Perf Gap Diagnosis (2026-04-21)

## Scope

- Current run under investigation: `corpus/results/x86_kvm_corpus_20260421_232916_947372`
- Immediate pre-wave1 comparator: `corpus/results/x86_kvm_corpus_20260419_021913_955464`
- Historical x86 authority: `corpus/results/vm_corpus_20260403_035346`
- Planning baseline reference: `docs/kernel-jit-optimization-plan.md:24`

I used the on-disk x86 corpus artifacts above for exact comparisons. The plan doc's like-for-like x86 VM corpus authority is `1.033x` on 2026-04-03; the problem statement's `1.046x` paper-grade figure appears to refer to an older paper tracking number, not the current on-disk x86 corpus artifact.

## Baseline vs Current

| Run | Date | Applied-only geomean | All-comparable geomean | Applied samples | Discovered programs | Notes |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `vm_corpus_20260403_035346` | 2026-04-03 | `1.033x` | `1.033x` | `61` | `114` | x86 authority in `kernel-jit-optimization-plan.md` |
| `x86_kvm_corpus_20260419_021913_955464` | 2026-04-19 | `1.123x` | `1.123x` | `13` | `53` | immediate pre-wave1 x86 KVM run |
| `x86_kvm_corpus_20260421_232916_947372` | 2026-04-21 | `1.010x` | `1.010x` | `12` | `48` | current run |

## Pass Selection

The current run is **not** missing the global performance pass set.

- `runner/suites/corpus.py:84-88` only exports `BPFREJIT_BENCH_PASSES` when `--rejit-passes` is passed.
- `runner/libs/rejit.py:402-409` uses `BPFREJIT_BENCH_PASSES` if present, otherwise falls back to the benchmark config.
- `corpus/config/benchmark_config.yaml:16-29` defines the explicit default pass list:
  `wide_mem, rotate, cond_select, extract, endian_fusion, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory`
- `metadata.json` for the current run confirms the selected runtime pass list was exactly that 11-pass set, with provenance `effective_enabled_passes_by_program`.

Per-program policy is narrower for `struct_ops`:

- `corpus/config/benchmark_config.yaml:30-36` disables `map_inline` and `dce` for `prog_type: struct_ops`.
- `runner/libs/rejit.py:358-389` applies that rule dynamically.
- `scx/rusty` therefore had the full 11-pass set on 2026-04-03, but only 9 passes (`map_inline` and `dce` removed) in the current run.

That policy drift is real and predates wave1, but it does **not** explain the immediate Apr 19 to Apr 21 drop by itself.

## Per-pass Site Counts

### Immediate pre- vs post-wave1 (Apr 19 vs Apr 21)

| Scope | map_inline | const_prop | dce | wide_mem | bulk_memory | extract | endian_fusion |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Apr 19, all apps | 23 | 311 | 43 | 26 | 3 | 7 | 4 |
| Apr 21, all apps | 15 | 284 | 33 | 25 | 2 | 7 | 4 |
| Apr 19, excluding Tetragon | 8 | 283 | 33 | 25 | 2 | 7 | 4 |
| Apr 21, excluding Tetragon | 8 | 283 | 33 | 25 | 2 | 7 | 4 |

This is the key result: **outside Tetragon, Apr 19 and Apr 21 are identical.** The post-wave1 drop is not coming from a broad daemon/apply regression.

### Longer-term x86 drift (Apr 03 authority vs Apr 21)

| Pass | Apr 03 x86 | Apr 21 x86 | Delta |
| --- | ---: | ---: | ---: |
| map_inline | 358 | 15 | -343 |
| const_prop | 999 | 284 | -715 |
| dce | 754 | 33 | -721 |
| wide_mem | 28 | 25 | -3 |
| bulk_memory | 7 | 2 | -5 |
| extract | 13 | 7 | -6 |
| endian_fusion | 4 | 4 | 0 |
| rotate | 0 | 0 | 0 |
| cond_select | 0 | 0 | 0 |

The big long-term losses are mostly coverage drift in the suites, not wave1:

| App | Apr 03 total applied sites | Apr 21 total applied sites | Main loss |
| --- | ---: | ---: | --- |
| `tracee/default` | 729 | 174 | `const_prop` 504 -> 152, `dce` 209 -> 20 |
| `bcc/execsnoop` | 432 | 0 | full `map_inline/const_prop/dce` loss |
| `scx/rusty` | 359 | 124 | `map_inline` 145 -> 0, `dce` 57 -> 0 from `struct_ops` rule |
| `tetragon/default` | 64 | 8 | current wave due runner scope shrink |

## Root Cause

### Chosen bucket: `(d) workload / suite changed`

The immediate Apr 19 -> Apr 21 regression is **not** evidence that wave1's stricter `rejit.py` handling dropped valid wins. The strongest-supported root cause is that the **suite changed what Tetragon programs were in scope** for corpus measurement on 2026-04-21.

Evidence:

1. `tetragon/default` program scope collapsed from 6 measured programs on Apr 19 to 1 on Apr 21.
2. The missing Apr 19 Tetragon programs were strong wins:
   - `event_exit_acct_process`: `1.221x`
   - `event_wake_up_new_task`: `2.087x`
   - `tg_cgroup_rmdir`: `2.153x`
   - `generic_kprobe_event`: `0.976x`
3. Non-Tetragon per-pass totals are identical between Apr 19 and Apr 21.
4. Current same-size/no-loader-change programs are still represented as `applied=true, changed=false`, so wave1 did **not** silently drop them from the result payload. Example: current `tetragon/default:event_execve#89` still shows `map_inline=7,const_prop=1` and is excluded only because `comparison_exclusion_reason=no_programs_changed_in_loader`.

The concrete regression was introduced by commit `69b62b595011f36c03be77d105c4a306db5cb207` (`[tetragon] wait for expected programs to attach before snapshotting IDs`):

- `runner/libs/app_runners/tetragon.py:291-339` waits for and then filters to `expected_program_names`.
- That commit also made the runner default `expected_program_names` from the Tetragon config, even when the caller did not explicitly request filtering.
- Corpus program selection is then derived from `self.programs` via `runner/libs/app_runners/base.py:31-47`.
- The Tetragon config has long scoped `target_programs` to `execve_rate` and `event_execve`, so corpus measurement stopped seeing the extra attached Tetragon programs once the runner started importing that config implicitly.

This is why the wave looks like a post-wave1 perf regression even though the daemon-side site totals did not change outside Tetragon.

## Fix Landed

Commit: `7da026ad08d667b881eeb8693e84bb5748693854`  
Message: `[tetragon] restore corpus program discovery scope`

What changed:

- `runner/libs/app_runners/tetragon.py:264-272` no longer defaults `expected_program_names` from the config.
- The explicit wait/filter path remains intact when a caller deliberately passes `expected_program_names`.
- No silent fallback was reintroduced in `rejit.py`.

This restores the pre-2026-04-21 corpus behavior while keeping explicit E2E filtering available.

## Program-level Evidence

### `tetragon/default` current vs pre-wave1

| Run | Program | Applied | Changed | Passes with sites | bytes_jited | bytes_xlated | Exclusion / speedup |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Apr 19 | `event_exit_acct_process` | Y | Y | `map_inline=1,const_prop=2,dce=5` | `1012->764` | `1792->1352` | `1.221x` |
| Apr 19 | `event_wake_up_new_task` | Y | Y | `map_inline=5,const_prop=22,dce=1` | `7335->1800` | `11312->2528` | `2.087x` |
| Apr 19 | `event_execve` | Y | N | `map_inline=7,const_prop=1` | `11213->11213` | `20272->20272` | `no_programs_changed_in_loader` |
| Apr 19 | `tg_kp_bprm_committing_creds` | Y | N | `-` | `1533->1533` | `2560->2560` | `no_programs_changed_in_loader` |
| Apr 19 | `tg_cgroup_rmdir` | Y | Y | `const_prop=2,dce=3` | `137->132` | `240->224` | `2.153x` |
| Apr 19 | `generic_kprobe_event` | Y | Y | `map_inline=2,const_prop=1,dce=1,wide_mem=1,bulk_memory=1` | `1722->1445` | `3056->2544` | `0.976x` |
| Apr 21 | `event_execve` | Y | N | `map_inline=7,const_prop=1` | `11213->-` | `20272->-` | `no_programs_changed_in_loader` |

### Current run program inventory

```tsv
app	program	applied	changed	passes	bytes_jited	bytes_xlated	exclusion
bcc/bindsnoop	bindsnoop_entry	Y	N	-	75->75	120->120	no_programs_changed_in_loader
bcc/bindsnoop	bindsnoop_v4_return	Y	Y	endian_fusion=1,extract=1	721->719	1160->1160	-
bcc/bindsnoop	bindsnoop_v6_return	Y	Y	endian_fusion=1,extract=1	742->740	1184->1184	-
bcc/biosnoop	trace_pid_start_tp	Y	N	-	267->267	448->448	no_programs_changed_in_loader
bcc/biosnoop	trace_req_completion_tp	Y	Y	const_prop=2,dce=1	550->548	856->848	-
bcc/biosnoop	trace_req_start	Y	N	-	335->335	616->616	no_programs_changed_in_loader
bcc/capable	cap_capable	Y	Y	extract=1	203->206	344->344	-
bcc/execsnoop	do_ret_sys_execve	Y	N	-	492->-	704->-	no_programs_changed_in_loader
bcc/execsnoop	syscall__execve	Y	N	-	2677->-	4144->-	no_programs_changed_in_loader
bcc/opensnoop	kretfunc__vmlinux____x64_sys_openat	Y	N	-	517->-	600->-	no_programs_changed_in_loader
bcc/runqlat	raw_tracepoint__sched_wakeup_new	Y	N	-	149->149	248->248	no_programs_changed_in_loader
bcc/runqlat	sched_switch	Y	Y	const_prop=2,dce=4	662->645	1168->1136	-
bcc/runqlat	sched_wakeup	Y	N	-	149->149	248->248	no_programs_changed_in_loader
bcc/syscount	tracepoint__raw_syscalls__sys_enter	Y	N	-	72->-	112->-	no_programs_changed_in_loader
bcc/syscount	tracepoint__raw_syscalls__sys_exit	Y	N	-	236->-	400->-	no_programs_changed_in_loader
bcc/tcpconnect	trace_connect_entry	Y	N	-	75->-	120->-	no_programs_changed_in_loader
bcc/tcpconnect	trace_connect_v4_return	Y	N	-	480->-	720->-	no_programs_changed_in_loader
bcc/tcpconnect	trace_connect_v6_return	Y	N	-	477->-	712->-	no_programs_changed_in_loader
bcc/tcplife	tracepoint__sock__inet_sock_set_state	Y	N	-	1067->-	1672->-	no_programs_changed_in_loader
bcc/vfsstat	vfs_open	Y	N	-	90->-	144->-	no_programs_changed_in_loader
bcc/vfsstat	vfs_read	Y	N	-	87->-	136->-	no_programs_changed_in_loader
bcc/vfsstat	vfs_write	Y	N	-	90->-	144->-	no_programs_changed_in_loader
bpftrace/biosnoop	block_io_done	Y	Y	map_inline=1,wide_mem=4	931->845	1576->1416	-
bpftrace/biosnoop	block_io_start	Y	N	-	222->222	408->408	no_programs_changed_in_loader
bpftrace/capable	cap_capable	Y	Y	wide_mem=6	769->697	1360->1216	-
bpftrace/runqlat	sched_switch	Y	Y	const_prop=4,dce=3	515->506	896->872	-
bpftrace/runqlat	sched_wakeup	Y	N	-	86->86	136->136	no_programs_changed_in_loader
bpftrace/runqlat	tracepoint_sched_sched_wakeup_new	Y	N	-	86->86	136->136	no_programs_changed_in_loader
bpftrace/tcplife	tcp_set_state	Y	Y	const_prop=2,wide_mem=8	2017->2013	3384->3384	-
bpftrace/tcpretrans	kprobe_tcp_retransmit_skb	Y	Y	const_prop=2,wide_mem=3	968->924	1640->1568	-
bpftrace/vfsstat	1	Y	N	-	362->-	680->-	no_programs_changed_in_loader
bpftrace/vfsstat	vfs_create	Y	N	-	140->-	224->-	no_programs_changed_in_loader
katran	balancer_ingress	Y	N	dce=5,endian_fusion=2,map_inline=6,wide_mem=4	13629->-	23840->-	no_programs_changed_in_loader
scx/rusty	rusty_dispatch	Y	N	const_prop=11	712->712	1304->1304	no_programs_changed_in_loader
scx/rusty	rusty_enqueue	Y	N	-	1015->1015	13024->13024	no_programs_changed_in_loader
scx/rusty	rusty_exit_task	Y	Y	const_prop=4,extract=2	157->157	2792->2792	-
scx/rusty	rusty_init_task	Y	N	bulk_memory=1,const_prop=3,extract=2	528->528	8848->8848	no_programs_changed_in_loader
scx/rusty	rusty_quiescent	Y	N	const_prop=15	251->251	3808->3808	no_programs_changed_in_loader
scx/rusty	rusty_runnable	Y	N	const_prop=15	303->303	3656->3656	no_programs_changed_in_loader
scx/rusty	rusty_running	Y	N	const_prop=6	455->455	952->952	no_programs_changed_in_loader
scx/rusty	rusty_select_cpu	Y	N	const_prop=14	3063->3063	6624->6624	no_programs_changed_in_loader
scx/rusty	rusty_set_cpumask	Y	N	const_prop=47	156->156	10360->10360	no_programs_changed_in_loader
scx/rusty	rusty_set_weight	Y	N	const_prop=1	115->115	392->392	no_programs_changed_in_loader
scx/rusty	rusty_stopping	Y	N	const_prop=3	269->269	1840->1840	no_programs_changed_in_loader
tetragon/default	event_execve	Y	N	const_prop=1,map_inline=7	11213->-	20272->-	no_programs_changed_in_loader
tracee/default	tracepoint__raw_syscalls__sys_enter	Y	N	-	234->234	264->264	no_programs_changed_in_loader
tracee/default	tracepoint__raw_syscalls__sys_exit	Y	N	-	263->263	320->320	no_programs_changed_in_loader
tracee/default	tracepoint__sched__sched_process_fork	Y	Y	bulk_memory=1,const_prop=152,dce=20,map_inline=1	19722->19847	32248->32320	-
```

## Outstanding Follow-ups

1. Re-run the x86 KVM 30-sample corpus after the arm64 runtime-image rebuild finishes. This fix is Python-only, so no daemon image rebuild is required, but I deferred the actual KVM rerun to avoid fighting the active arm64 image build.
2. Expectation for the rerun: recover the missing Tetragon program coverage first; that should remove the fake post-wave1 regression signal. It will **not** by itself restore Apr 03's `1.033x` authority because older suite drift remains in `tracee/default`, multiple BCC apps, and `scx/rusty`.
3. Follow up separately on the pre-wave1 drift:
   - `tracee/default` program count fell from `44` on Apr 03 to `3` on Apr 21.
   - `bcc/execsnoop` lost all `map_inline/const_prop/dce` sites (`432 -> 0`).
   - `scx/rusty` lost `map_inline` and `dce` because of explicit `struct_ops` policy commit `12d510a36`.
