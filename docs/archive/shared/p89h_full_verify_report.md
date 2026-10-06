# P89H Full Verify Report

Date: 2026-04-30

Corpus dump: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260430_193236_794969`

Daemon debug-mode commit: `1cff8f9b keep daemon workdirs in debug mode`. Host tool build for the dryrun matrix used a clean worktree at `cc70923d` (`origin/main` when this report was generated).

## Scope

- Programs dumped under `details/`: 519.
- `details/workdirs`: 510 successful ReJIT workdirs; `details/failures`: 9 failure workdirs.
- The KVM corpus command returned non-zero because tetragon had real ReJIT verifier failures, but the debug dump still covered every program the runner requested.
- The task prompt expected 600+ programs; this run requested 519 live programs. I did not filter programs. The runner emitted a cilium rediscovery warning and refreshed cilium to 16 live programs.

## Host Dryrun Protocol

- Matrix: 519 programs x 2 pass lists x 5 rounds = 5190 verdict attempts.
- Transformed host `bpfverify` invocations actually executed: 3085. Default11 attempts that could not produce verifier states or failed in `bpfopt` are recorded as `unverifiable`/`error`, not dropped.
- Pass lists: `kinsn5 = bulk_memory,rotate,cond_select,extract,endian_fusion`; `default11 = map_inline,const_prop,dce,skb_load_bytes_spec,bounds_check_merge,wide_mem,bulk_memory,rotate,cond_select,extract,endian_fusion`.
- Dummy maps: `bpfverify --dummy-map-fds --prog-info` was used for map FD relocation.
- `bpfopt` consumed non-empty `func_info.bin`/`line_info.bin` when present. Host `bpfverify` did not replay guest func/line BTF records or guest kinsn `fd_array` because those BTF IDs are not portable to the host kernel; kprobe dryruns used host vmlinux BTF id 1 only to satisfy the CLI metadata path.
- Default11 used verifier states generated from the original program on the host. Map-values input was metadata-only from `map_fds.json`; no map values were fabricated. Missing concrete map entries therefore surface as `map_inline` errors.

## Determinism

- 5-round verdict consistency: PASS. Inconsistent `(program, mode)` entries: 0.
- Raw matrix: `docs/tmp/p89h_full_verify_results.tsv`. Summary JSON: `docs/tmp/p89h_full_verify_summary.json`.

## Overall Verdicts

| Mode | Accepted | Rejected | Unverifiable | Error |
|---|---:|---:|---:|---:|
| `kinsn5` | 209 (40.3%) | 69 (13.3%) | 241 (46.4%) | 0 (0.0%) |
| `default11` | 93 (17.9%) | 5 (1.0%) | 303 (58.4%) | 118 (22.7%) |

## By App

| App | Programs | kinsn5 | default11 |
|---|---:|---|---|
| `bcc/bindsnoop` | 3 | A 1 (33.3%)<br>R 2 (66.7%)<br>U 0 (0.0%) | A 1 (33.3%)<br>R 2 (66.7%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/biosnoop` | 3 | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/capable` | 1 | A 0 (0.0%)<br>R 1 (100.0%)<br>U 0 (0.0%) | A 0 (0.0%)<br>R 1 (100.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/execsnoop` | 2 | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/opensnoop` | 3 | A 0 (0.0%)<br>R 3 (100.0%)<br>U 0 (0.0%) | A 0 (0.0%)<br>R 0 (0.0%)<br>U 3 (100.0%)<br>E 0 (0.0%) |
| `bcc/runqlat` | 3 | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/syscount` | 2 | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/tcpconnect` | 3 | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/tcplife` | 1 | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bcc/vfsstat` | 5 | A 1 (20.0%)<br>R 4 (80.0%)<br>U 0 (0.0%) | A 1 (20.0%)<br>R 0 (0.0%)<br>U 4 (80.0%)<br>E 0 (0.0%) |
| `bpftrace/biosnoop` | 2 | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 1 (50.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 1 (50.0%) |
| `bpftrace/capable` | 1 | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bpftrace/runqlat` | 3 | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 3 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bpftrace/tcplife` | 1 | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 0 (0.0%)<br>R 1 (100.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bpftrace/tcpretrans` | 1 | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 1 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `bpftrace/vfsstat` | 2 | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%) | A 2 (100.0%)<br>R 0 (0.0%)<br>U 0 (0.0%)<br>E 0 (0.0%) |
| `calico/felix` | 6 | A 5 (83.3%)<br>R 1 (16.7%)<br>U 0 (0.0%) | A 4 (66.7%)<br>R 0 (0.0%)<br>U 1 (16.7%)<br>E 1 (16.7%) |
| `cilium/agent` | 16 | A 4 (25.0%)<br>R 7 (43.8%)<br>U 5 (31.2%) | A 3 (18.8%)<br>R 0 (0.0%)<br>U 12 (75.0%)<br>E 1 (6.2%) |
| `katran` | 3 | A 2 (66.7%)<br>R 0 (0.0%)<br>U 1 (33.3%) | A 2 (66.7%)<br>R 0 (0.0%)<br>U 1 (33.3%)<br>E 0 (0.0%) |
| `otelcol-ebpf-profiler/profiling` | 13 | A 6 (46.2%)<br>R 0 (0.0%)<br>U 7 (53.8%) | A 0 (0.0%)<br>R 0 (0.0%)<br>U 7 (53.8%)<br>E 6 (46.2%) |
| `tetragon/observer` | 287 | A 125 (43.6%)<br>R 48 (16.7%)<br>U 114 (39.7%) | A 35 (12.2%)<br>R 0 (0.0%)<br>U 161 (56.1%)<br>E 91 (31.7%) |
| `tracee/monitor` | 158 | A 41 (25.9%)<br>R 3 (1.9%)<br>U 114 (72.2%) | A 25 (15.8%)<br>R 1 (0.6%)<br>U 114 (72.2%)<br>E 18 (11.4%) |

## Rejected Programs

### kinsn5

Unique rejected programs: 69.

| Prog ID | App | Program | Type | Sites | Verifier summary |
|---:|---|---|---|---:|---|
| 6 | `bcc/capable` | `cap_capable` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 3: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 4: (bf) r7 = r0 ; R0_w=scalar(id=1) R7_w=scala... |
| 14 | `bcc/bindsnoop` | `bindsnoop_v4_re` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=scalar(id=1) R8_w=scala... |
| 15 | `bcc/bindsnoop` | `bindsnoop_v6_re` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=scalar(id=1) R8_w=scala... |
| 23 | `bcc/vfsstat` | `vfs_create` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 25 | `bcc/vfsstat` | `vfs_open` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 26 | `bcc/vfsstat` | `vfs_read` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 27 | `bcc/vfsstat` | `vfs_write` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 30 | `bcc/opensnoop` | `__x64_sys_open` | `tracing` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (79) r1 = *(u64 *)(r6 +0) ; R1_w=scalar() R6_w=ctx() / 2: (79) r8 = *(u64 *)(r1 +112) / R1 invalid mem... |
| 31 | `bcc/opensnoop` | `__x64_sys_opena` | `tracing` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (79) r1 = *(u64 *)(r6 +0) / 2: R1_w=ptr_acpi_pci_id() R6_w=ctx() / 2: (79) r8 = *(u64 *)(r1 +104) / pr... |
| 32 | `bcc/opensnoop` | `__x64_sys_opena` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 102 | `calico/felix` | `conntrack_clean` | `sched_cls` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (7b) *(u64 *)(r10 -8) = r1 ; R1_w=0 R10=fp0 fp-8_w=0 / 3: (7b) *(u64 *)(r10 ... |
| 140 | `cilium/agent` | `dump_bpf_map` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 141 | `cilium/agent` | `dump_bpf_prog` | `tracing` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 214 | `cilium/agent` | `tail_drop_notif` | `sched_cls` | 0 | 0: R1=ctx() R10=fp0 / 1: (61) r2 = *(u32 *)(r1 +56) ; R1=ctx() R2_w=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) / 2: (63) *(u32 *)(r10 -56) = r2 ; R2... |
| 219 | `cilium/agent` | `cil_to_host` | `sched_cls` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 2: (18) r1 = 0xffff8c18861c0351 ; R1_w=map_value(map=.rodata.config,ks=4,vs=156,off=73) / 4: (71) r1 = *(... |
| 222 | `cilium/agent` | `tail_drop_notif` | `sched_cls` | 0 | 0: R1=ctx() R10=fp0 / 1: (61) r2 = *(u32 *)(r1 +56) ; R1=ctx() R2_w=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) / 2: (63) *(u32 *)(r10 -56) = r2 ; R2... |
| 226 | `cilium/agent` | `cil_to_host` | `sched_cls` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 2: (18) r1 = 0xffff8c2c659a0151 ; R1_w=map_value(map=.rodata.config,ks=4,vs=156,off=73) / 4: (71) r1 = *(... |
| 233 | `cilium/agent` | `tail_drop_notif` | `sched_cls` | 0 | 0: R1=ctx() R10=fp0 / 1: (61) r2 = *(u32 *)(r1 +56) ; R1=ctx() R2_w=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) / 2: (63) *(u32 *)(r10 -56) = r2 ; R2... |
| 253 | `tetragon/observer` | `event_wake_up_n` | `kprobe` | 2 | 0: R1=ctx() R10=fp0 / 0: (79) r7 = *(u64 *)(r1 +112) ; R1=ctx() R7_w=scalar() / 2: (7b) *(u64 *)(r10 -280) = r1 ; R1=ctx() R10=fp0 fp-280_w=ctx() / 6: (bf) r1 = r10 ; ... |
| 255 | `tetragon/observer` | `execve_send` | `tracepoint` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 2: (63) *(u32 *)(r10 -88) = r7 ; R7_w=0 R10=fp0 fp-88=????0 / 3: (bf) r2 = r10 ; R2_w=fp0 R10=fp0 / 5: (1... |
| 256 | `tetragon/observer` | `event_execve` | `tracepoint` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 258 | `tetragon/observer` | `execve_map_upda` | `socket_filter` | 0 | processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| 266 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 268 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 278 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 282 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 291 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 296 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 304 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 312 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 317 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 324 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 325 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 334 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 341 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 352 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 356 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 360 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 370 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 374 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 381 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 384 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 391 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 394 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 403 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 405 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 414 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 415 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 422 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 435 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 441 | `tetragon/observer` | `generic_tracepo` | `tracepoint` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -164) = r1 ; R1_w=0 R10=fp0 fp-168=0000???? / 3: (bf) r2 =... |
| 443 | `tetragon/observer` | `generic_rawtp_p` | `raw_tracepoint` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -164) = r1 ; R1_w=0 R10=fp0 fp-168=0000???? / 3: (bf) r2 =... |
| 450 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 457 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 466 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 470 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 479 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 487 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 489 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 500 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 506 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 510 | `tetragon/observer` | `generic_retkpro` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (79) r1 = *(u64 *)(r9 +80) ; R1_w=scalar() R9_w=ctx() / 2: (7b) *(u64 *)(r10 -128) = r1 ; R1_w=scalar(... |
| 515 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 521 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 533 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 535 | `tetragon/observer` | `generic_kprobe_` | `kprobe` | 0 | 0: R1=ctx() R10=fp0 / 0: (bf) r9 = r1 ; R1=ctx() R9_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -172) = r1 ; R1_w=0 R10=fp0 fp-176=0000???? / 3: (bf) r2 =... |
| 604 | `tracee/monitor` | `sched_process_e` | `raw_tracepoint` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -136) = r1 ; R1_w=0 R10=fp0 fp-136=????0 / 3: (bf) r2 = r1... |
| 702 | `tracee/monitor` | `process_execute` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -136) = r1 ; R1_w=0 R10=fp0 fp-136=????0 / 3: (bf) r2 = r1... |
| 719 | `tracee/monitor` | `cgroup_bpf_run_` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 1: (79) r3 = *(u64 *)(r1 +96) ; R1=ctx() R3_w=scalar() / 2: (79) r8 = *(u64 *)(r1 +104) ; R1=ctx() R8_w=scalar() / 3: (79) r7 = *(u64 *)(r1 +112)... |

### default11

Unique rejected programs: 5.

| Prog ID | App | Program | Type | Sites | Verifier summary |
|---:|---|---|---|---:|---|
| 6 | `bcc/capable` | `cap_capable` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 3: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 4: (bf) r7 = r0 ; R0_w=scalar(id=1) R7_w=scala... |
| 14 | `bcc/bindsnoop` | `bindsnoop_v4_re` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=scalar(id=1) R8_w=scala... |
| 15 | `bcc/bindsnoop` | `bindsnoop_v6_re` | `kprobe` | 1 | 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=scalar(id=1) R8_w=scala... |
| 702 | `tracee/monitor` | `process_execute` | `kprobe` | 66 | 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (b7) r1 = 0 ; R1_w=0 / 2: (63) *(u32 *)(r10 -136) = r1 ; R1_w=0 R10=fp0 fp-136=????0 / 3: (bf) r2 = r1... |
| 763 | `bpftrace/tcplife` | `tcp_set_state` | `kprobe` | 10 | 0: R1=ctx() R10=fp0 / 1: (63) *(u32 *)(r10 -112) = r2 ; R2_w=0 R10=fp0 fp-112=????0 / 2: (7b) *(u64 *)(r10 -120) = r2 ; R2_w=0 R10=fp0 fp-120_w=0 / 3: (63) *(u32 *)(r1... |

## Rejection Summary

| Mode | Category | Programs | Example |
|---|---|---:|---|
| `default11` | map-value pointer/context mismatch | 3 | prog 14 `bcc/bindsnoop`: 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=sca... |
| `default11` | other verifier reject | 2 | prog 6 `bcc/capable`: 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 3: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 4: (bf) r7 = r0 ; R0_w=sca... |
| `kinsn5` | invalid scalar/context memory access | 3 | prog 30 `bcc/opensnoop`: 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 1: (79) r1 = *(u64 *)(r6 +0) ; R1_w=scalar() R6_w=ctx() / 2: (79) r8 = *(u64 *)(r1 +1... |
| `kinsn5` | map-value pointer/context mismatch | 49 | prog 14 `bcc/bindsnoop`: 0: R1=ctx() R10=fp0 / 0: (bf) r7 = r1 ; R1=ctx() R7_w=ctx() / 2: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 3: (bf) r8 = r0 ; R0_w=sca... |
| `kinsn5` | other verifier reject | 8 | prog 6 `bcc/capable`: 0: R1=ctx() R10=fp0 / 0: (bf) r6 = r1 ; R1=ctx() R6_w=ctx() / 3: (85) call bpf_get_current_pid_tgid#14 ; R0_w=scalar() / 4: (bf) r7 = r0 ; R0_w=sca... |
| `kinsn5` | verifier rejected before instruction trace | 9 | prog 23 `bcc/vfsstat`: processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |

## Error And Unverifiable Summary

| Class | Mode | Category | Programs | Example |
|---|---|---|---:|---|
| unverifiable | `default11` | host dummy map creation failed for captured map fixture | 241 | prog 121 `otelcol-ebpf-profiler/profiling`: create dummy BPF map id 480 type 13 key_size 8 value_size 4 max_entries 65536 from /home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_co... |
| unverifiable | `default11` | original host verifier-state replay failed before default11 transform | 62 | prog 23 `bcc/vfsstat`: processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0 |
| unverifiable | `kinsn5` | host dummy map creation failed for captured map fixture | 241 | prog 121 `otelcol-ebpf-profiler/profiling`: create dummy BPF map id 480 type 13 key_size 8 value_size 4 max_entries 65536 from /home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_co... |
| error | `default11` | map_inline missing concrete map-values snapshot | 116 | prog 120 `otelcol-ebpf-profiler/profiling`: error: map_inline requires a concrete snapshot value for map 476 key 0x00000000 at lookup pc 7: map_values snapshot missing map 476 key 00000000 |
| error | `default11` | map_inline required side input absent | 2 | prog 105 `calico/felix`: error: map-inline requires --map-values and --map-ids |

## Bugs

- Non-deterministic verdicts across the 5 rounds: none.
- No kinsn pass code was changed by this task. Rejections/errors above are recorded for P89H-Root follow-up rather than fixed here.
