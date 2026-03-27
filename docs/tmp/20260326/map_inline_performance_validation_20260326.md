# Map Inline Performance Validation 2026-03-26

## Scope

Goal: validate whether current `map_inline` produces measurable runtime wins on representative corpus programs with real `bpf_map_lookup_elem` sites, using VM-only execution.

This run used:

- VM entry: `python3 runner/scripts/run_vm_shell.py --action vm-corpus --kernel-image vendor/linux-framework/arch/x86/boot/bzImage`
- Performance pass set: `map_inline,const_prop,dce,wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory,bounds_check_merge,skb_load_bytes,branch_flip`
- Test-run measurements: `micro_exec run-kernel`, `repeat=100`, `warmup=1`, `5` outer iterations, median `exec_ns`
- Attach screening: compile-only `run-kernel` on attachable objects, plus a follow-up attach batch (`run-kernel-attach`) for broad-trigger programs

Artifacts:

- Primary raw results: `docs/tmp/20260326/map_inline_perf_validation_20260326.json`
- Attach follow-up raw results: `docs/tmp/20260326/map_inline_perf_validation_attach_20260326.json`
- Primary daemon log: `docs/tmp/20260326/map_inline_perf_validation_20260326.daemon.stderr.log`
- Attach daemon log: `docs/tmp/20260326/map_inline_perf_validation_attach_20260326.daemon.stderr.log`

## Headline Result

Current corpus coverage produced only `3` real `map_inline` hits in the tested VM subset:

1. `katran:xdp_pktcntr.bpf.o:pktcntr`
2. `tracee:tracee.bpf.o:cgroup_skb_ingress`
3. `tracee:tracee.bpf.o:cgroup_skb_egress`

At `repeat=100`, none of the measured hits showed a runtime speedup. All three were slower after REJIT, despite real `map_inline` application and large instruction-count reductions on the Tracee cases.

## Measured Programs

| Program | map_inline sites found | map_inline inlined | Stock median `exec_ns` | ReJIT median `exec_ns` | Speedup ratio (`stock/rejit`) | Other applied passes |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `katran:xdp_pktcntr.bpf.o:pktcntr` | 2 | 1 | 15 | 16 | 0.938x | `const_prop,dce` |
| `tracee:tracee.bpf.o:cgroup_skb_ingress` | 56 | 9 | 13 | 16 | 0.813x | `const_prop,dce,wide_mem` |
| `tracee:tracee.bpf.o:cgroup_skb_egress` | 56 | 9 | 13 | 18 | 0.722x | `const_prop,dce,wide_mem` |

Notes:

- `sites found` here means `map_inline.sites_applied + map_inline.sites_skipped` from the daemon pass record for that specific program.
- `katran:xdp_pktcntr` had `insn_delta = -10`.
- Both Tracee cgroup-skb programs had `insn_delta = -399`.
- Total transformed sites across all passes were much larger than the `map_inline` sites because `const_prop`, `dce`, and `wide_mem` cascaded after the inline.

Per-iteration `exec_ns` samples:

- `katran:xdp_pktcntr`: stock `[15, 17, 7, 10, 18]`, rejit `[16, 7, 17, 7, 16]`
- `tracee:cgroup_skb_ingress`: stock `[15, 13, 13, 13, 14]`, rejit `[40, 16, 15, 14, 23]`
- `tracee:cgroup_skb_egress`: stock `[13, 13, 15, 14, 13]`, rejit `[22, 15, 17, 18, 18]`

Interpretation:

- `pktcntr` is effectively noise-level at this scale.
- The Tracee cgroup-skb programs clearly shrink, but the measured median runtime still regresses at `repeat=100`.

## Screening Summary

### Test-run candidate batch

Screened `11` test-run candidates. Only `3` applied `map_inline`.

Representative zero-hit cases:

| Program | map_inline applied | map_inline skipped | Dominant skip reasons |
| --- | ---: | ---: | --- |
| `katran:balancer.bpf.o:balancer_ingress` | 0 | 64 | `map type 6 not inlineable in v1` x42; `lookup key is not a constant stack materialization` x14 |
| `katran:healthchecking.bpf.o:healthcheck_encap` | 0 | 9 | `lookup result is not consumed by fixed-offset scalar loads` x4; `lookup key is not a constant stack materialization` x3 |
| `calico:xdp_no_log.bpf.o:calico_xdp_main` | 0 | 7 | `map type 11 not inlineable in v1` x4; `map type 6 not inlineable in v1` x2 |
| `calico:from_hep_debug.bpf.o:calico_tc_main` | 0 | 29 | `map type 11 not inlineable in v1` x15; `lookup key is not a constant stack materialization` x7; `key width 4 is smaller than map key size 8` x2 |
| `suricata:xdp_filter.bpf.o:xdp_hashfilter` | 0 | 8 | `lookup result is not consumed by fixed-offset scalar loads` x4; `lookup key is not a constant stack materialization` x2; `map type 5 not inlineable in v1` x2 |

Tracee hit-but-partial cases:

- `tracee:cgroup_skb_ingress`: `9` applied, `47` skipped
  Dominant skips: `map type 13 not inlineable in v1` x38, `lookup key is not a constant stack materialization` x7, `speculative map inline requires an immediate null check` x2
- `tracee:cgroup_skb_egress`: same distribution as ingress

### Attach-oriented follow-up

Screened `9` attach-oriented candidates. `0` additional `map_inline` hits.

Representative attach skip reasons:

| Program | map_inline applied | map_inline skipped | Dominant skip reasons |
| --- | ---: | ---: | --- |
| `tracee:tracee.bpf.o:tracepoint__raw_syscalls__sys_enter` | 0 | 1 | `lookup key is not a constant stack materialization` x1 |
| `tracee:tracee.bpf.o:tracepoint__raw_syscalls__sys_exit` | 0 | 1 | `lookup key is not a constant stack materialization` x1 |
| `tracee:tracee.bpf.o:tracepoint__sched__sched_switch` | 0 | 20 | `map type 13 not inlineable in v1` x10; `lookup key is not a constant stack materialization` x6 |
| `bcc:libbpf-tools:syscount.bpf.o:sys_exit` | 0 | 3 | `lookup key is not a constant stack materialization` x2; `map type 8 not inlineable in v1` x1 |
| `bcc:libbpf-tools:execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve` | 0 | 1 | `map type 8 not inlineable in v1` x1 |

Attach-screen load failures worth noting:

- `bcc:libbpf-tools/cpudist.bpf.o:sched_switch_tp`
  `bpf_object__load failed: Invalid argument`
- `tetragon:bpf_execve_event.bpf.o:event_execve`
  `bpf_object__load failed: Bad file descriptor`

## Conclusion

This VM run does confirm that current corpus programs can hit `map_inline` on real objects:

- `katran:xdp_pktcntr`
- `tracee:cgroup_skb_ingress`
- `tracee:cgroup_skb_egress`

But it does **not** validate the intended performance story yet. At `repeat=100`, the measured median runtime does not improve on any of the hit programs.

The main blockers visible in the skip diagnostics are:

1. Unsupported map types in the current implementation path, especially types `5`, `6`, `8`, `11`, `12`, and `13`
2. Real corpus keys often are not recognized as constant stack materializations
3. Many lookup results are not consumed in the exact fixed-offset scalar-load form the pass expects
4. Some speculative hash-style cases are rejected because the required immediate null-check pattern is absent

If the next goal is to recover the expected runtime improvement, the most promising immediate follow-ups are:

1. Extend map-type coverage beyond the currently inlineable subset
2. Relax the key-materialization matcher for real corpus codegen patterns
3. Broaden post-lookup use matching beyond fixed-offset scalar loads
4. Re-check heavier corpus programs after those matcher/type changes, because the current successful hit set is too small and too latency-light to demonstrate a reliable win at `repeat=100`
