# Phase 4 KVM x86 Smoke Verbose - 2026-04-29

Requested diagnostic baseline: `3e6439af`
(`fix(daemon): preserve failure workdirs + capture verifier log + replay load context`).
The local branch advanced to `f45a0f0f` while this report was written; no source code or
v3 design document changes were made for this KVM rerun.

Overall result: **FAIL**, but with materially better evidence than the `70e2fb26`
KVM smoke. `vm-corpus` and all five `vm-e2e` cases still returned nonzero because
ReJIT/verifier errors surfaced in result artifacts. `vm-micro` passed. Compared
with `70e2fb26`, the main improvement is diagnostic: result payloads now contain
preserved guest workdir paths and verifier summaries/snippets instead of only
high-level failures.

## Commands

| Step | Command | Exit | Result | Artifact |
| --- | --- | ---: | --- | --- |
| corpus | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-corpus SAMPLES=1` | 2 | FAIL, result produced | `corpus/results/x86_kvm_corpus_20260429_132210_378665` |
| e2e | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-e2e SAMPLES=1` | 2 | FAIL, five case results produced | `e2e/results/{tracee,tetragon,bpftrace,bcc,katran}_20260429_13*` |
| micro | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro SAMPLES=3` | 0 | PASS | `micro/results/x86_kvm_micro_20260429_140315_265872` |

## Rebuild Evidence

The smoke rebuilt the KVM runtime image with the daemon diagnostic fix:

| Check | Evidence |
| --- | --- |
| runtime image | `bpf-benchmark/runner-runtime:x86_64` |
| image digest | `sha256:a49596f55ed1b53e9bb201e8a0a9426e16abfc4ca53f7e5ab0ebf034899162fd` |
| image tar | `.cache/container-images/x86_64-runner-runtime.image.tar`, 9.3 GiB, timestamp `2026-04-29 06:13` |
| rebuilt components | daemon and bpfopt CLI suite were rebuilt into the image |
| kinsn modules | `bpf_bulk_memory`, `bpf_endian`, `bpf_extract`, `bpf_rotate`, `bpf_select` loaded, `failed_modules=[]` |

## Diagnostic Capture

The daemon did preserve failure workdir **paths** in the guest/container namespace,
for example `/var/lib/bpfrejit-daemon/failures/6_1777469260_498433616_1`.
However, the actual workdir files were not available on the host after KVM/docker
cleanup. Host checks found no `/var/lib/bpfrejit-daemon/failures`, no copied
`*/failures/*`, and no host-visible `verifier.log`, `bpfverify_report.json`, or
`bpfopt_report.json`.

| Requested diagnostic artifact | Status in this run |
| --- | --- |
| failure workdir path | **yes**, embedded in `result.json` and `metadata.json` error strings |
| verifier log summary/snippet | **yes**, embedded in result strings, often with `... verifier log truncated ...` |
| full `verifier.log` file | **not host-visible** after guest/container cleanup |
| `prog.bin`, `opt.bin` | **not host-visible** after guest/container cleanup |
| `bpfopt_report.json`, `bpfverify_report.json` | **not host-visible** after guest/container cleanup |

This is still a diagnostic improvement over `70e2fb26`: the run now records enough
context to classify failures, but not enough to replay or diff `prog.bin` versus
`opt.bin` from the host. The next diagnostic fix should copy or bind-mount
`/var/lib/bpfrejit-daemon/failures` into the benchmark result artifact.

## Corpus

Corpus status: `error`.

| Metric | Value |
| --- | ---: |
| per_program_geomean | `0.9368303398259213` |
| program_count | `128` |
| wins | `64` |
| losses | `64` |
| ratio min | `0.06704733264573211` |
| ratio max | `1.808264579074983` |
| apps ok/error | `11 / 11` |
| requested ReJIT programs | `519` |
| applied ReJIT programs | `28` |
| not_applied ReJIT programs | `491` |

Corpus app ReJIT counts:

| App | Status | Requested | Applied | Not Applied |
| --- | --- | ---: | ---: | ---: |
| bcc/capable | error | 1 | 0 | 1 |
| bcc/execsnoop | ok | 2 | 0 | 2 |
| bcc/bindsnoop | error | 3 | 0 | 3 |
| bcc/biosnoop | ok | 3 | 1 | 2 |
| bcc/vfsstat | error | 5 | 0 | 5 |
| bcc/opensnoop | error | 3 | 0 | 3 |
| bcc/syscount | ok | 2 | 0 | 2 |
| bcc/tcpconnect | ok | 3 | 0 | 3 |
| bcc/tcplife | ok | 1 | 1 | 0 |
| bcc/runqlat | ok | 3 | 1 | 2 |
| calico/felix | error | 6 | 0 | 6 |
| otelcol-ebpf-profiler/profiling | error | 13 | 0 | 13 |
| cilium/agent | error | 16 | 6 | 10 |
| tetragon/observer | error | 287 | 2 | 285 |
| katran | error | 3 | 0 | 3 |
| tracee/monitor | error | 158 | 13 | 145 |
| bpftrace/capable | ok | 1 | 1 | 0 |
| bpftrace/biosnoop | ok | 2 | 1 | 1 |
| bpftrace/vfsstat | ok | 2 | 0 | 2 |
| bpftrace/runqlat | ok | 3 | 1 | 2 |
| bpftrace/tcplife | error | 1 | 0 | 1 |
| bpftrace/tcpretrans | ok | 1 | 1 | 0 |

## E2E

All five e2e cases produced result artifacts. Ratio is `post_rejit / baseline`
throughput. For bpftrace and bcc, ratio is the geomean across tool records.

| Case | Status | Baseline | Post-ReJIT | Ratio | Applied / Requested | Main failure |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| tracee | error | `4374.602924` | `4393.267684` | `1.004267` | `26 / 316` across two cycles | BTF id replay errors plus errno 13 map-heavy verifier logs |
| tetragon | error | `1978.431992` | `1602.532799` | `0.810001` | `2 / 287` | kprobe/tracepoint verifier failures, many map-value snippets |
| bpftrace | error | n/a | n/a | `0.993816` | `4 / 10` | `tcplife` error, mixed tool ratios |
| bcc | error | n/a | n/a | `1.113195` | `3 / 26` | `opensnoop`, `capable`, `vfsstat`, `bindsnoop` errors |
| katran | error | `8648.363164` | `8375.215371` | `0.968416` | `0 / 3` | XDP tail-call verifier-state capture, sched_cls final verifier failure |

Nested e2e ReJIT records summed to `35` applied out of `642` requested
program attempts. Tracee contributes two ReJIT cycles in its result payload.

## Failure Workdir Samples

The following workdirs were selected from the preserved result strings. Each row
has a guest path and embedded verifier summary; none has host-visible
`prog.bin`/`opt.bin`/full-report files after cleanup.

| Suite | Prog | Type | Name | Workdir | Error class |
| --- | ---: | --- | --- | --- | --- |
| corpus | 6 | kprobe | `cap_capable` | `/var/lib/bpfrejit-daemon/failures/6_1777469260_498433616_1` | final verify, errno 22, BTF id |
| corpus | 23 | tracing | `vfs_create` | `/var/lib/bpfrejit-daemon/failures/23_1777469261_770996230_13` | original verifier-states |
| corpus | 120 | perf_event | `perf_unwind_stop` | `/var/lib/bpfrejit-daemon/failures/120_1777469264_644410030_49` | final verify, errno 13, map-heavy |
| tetragon | 1806 | kprobe | `event_exit_acct_process` | `/var/lib/bpfrejit-daemon/failures/1806_1777470513_490477527_563` | final verify, errno 13, map-heavy |
| tetragon | 1808 | kprobe | `event_wake_up_new_task` | `/var/lib/bpfrejit-daemon/failures/1808_1777470513_863274619_565` | final verify, errno 22, BTF id |
| katran | 3252 | xdp | `xdp_root` | `/var/lib/bpfrejit-daemon/failures/3252_1777471039_186979768_1182` | original verifier-states, tail_call |
| katran | 3260 | sched_cls | `healthcheck_encap` | `/var/lib/bpfrejit-daemon/failures/3260_1777471039_816016049_1186` | final verify, errno 13 |
| corpus | 665 | raw_tracepoint | `syscall__init_module` | `/var/lib/bpfrejit-daemon/failures/665_1777469525_782596562_839` | `bpfrejit failed`, map-heavy summary |

## Verifier Pattern Counts

Counts below are de-duplicated by preserved failure workdir. Category flags are
not mutually exclusive.

| Pattern | Workdirs | Interpretation |
| --- | ---: | --- |
| `bpfverify final verification failed` | 578 | optimized/final bytecode rejected |
| `bpfverify original verifier-states failed` | 409 | original program could not be replayed for verifier-state capture |
| `kernel btf_id ... is not a function` | 377 | BTF attach/load-context replay failure |
| `Live regs before insn` summaries | 301 | verifier context captured, final reason often truncated |
| `tail_call` context | 5 | XDP/program-array tail-call replay context |
| `invalid mem access` | 0 | not observed in preserved summaries |
| `not a valid type` / `BPF_REG...` | 0 | not observed in preserved summaries |
| `jump out of range` | 0 | not observed in preserved summaries |
| `kfunc not found` / `fd_array mismatch` | 0 | not observed in preserved summaries |

Program type distribution, using explicit `bpfverify --prog-type` when present
and otherwise inferring from result program metadata:

| Program type | Workdirs |
| --- | ---: |
| kprobe | 843 |
| raw_tracepoint | 77 |
| tracing | 18 |
| tracepoint | 17 |
| sched_cls | 14 |
| perf_event | 9 |
| cgroup_skb | 6 |
| xdp | 4 |
| lsm | 3 |

## Representative Snippets

### BTF id replay

`corpus` prog 6 (`kprobe`, `cap_capable`):

```text
bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22):
verifier log summary:
kernel btf_id 129873 is not a function
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
```

This fails before instruction processing, so it is much more likely a load-context
or BTF id replay issue than an optimization-pass bug.

### Original verifier-state replay

`corpus` prog 23 (`tracing`, `vfs_create`):

```text
bpfverify --verifier-states-out failed for prog 23:
subprocess "bpfverify" "--prog-type" "tracing" ... "--prog-btf-id" "12"
"--attach-btf-id" "123739" "--attach-btf-obj-id" "1":
func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
```

Because the original bytecode fails verifier-state capture, these records should
not be attributed to `map_inline`, `const_prop`, `dce`, or kinsn passes.

### Map-heavy errno 13 final verifier logs

`tetragon` prog 1806 (`kprobe`, `event_exit_acct_process`):

```text
bpfverify final verification rejected bytecode (... errno 13):
func#0 @0
Live regs before insn:
      0: .1........ (bf) r7 = r1
      1: .......7.. (85) call bpf_get_current_pid_tgid#14
      5: ......67.. (bf) r2 = r10
      7: ..2...67.. (18) r1 = 0xffff898390763400
      9: .12...67.. (85) call bpf_map_lookup_elem#1
     10: 0.....67.. (15) if r0 == 0x0 goto pc+113
     11: 0.....67.. (79) r1 = *(u64 *)(r0 +8)
...
... verifier log truncated ...
```

These are the only failures where `map_inline` remains a plausible suspect,
because the snippets show map lookup/value state after final verification.
The truncated summaries are not enough to prove the pass without the full workdir.

### Tail-call replay

`katran` prog 3252 (`xdp`, `xdp_root`):

```text
bpfverify original verifier-states failed ... "--prog-type" "xdp" ... "--prog-btf-id" "3639":
func#0 @0
Live regs before insn:
      0: .1........ (bf) r6 = r1
      1: .1....6... (18) r2 = 0xffff898288011200
      3: .12...6... (b7) r3 = 0
      4: .123..6... (85) call bpf_tail_call#12
...
1: (18) r2 = 0xffff898288011200       ; R2=map_ptr(map=root_array,ks=4,vs=4)
```

This points at tail-call/program-array replay or verifier-state capture around
Katran's root XDP chain, not at a normal bytecode rewrite pass.

## Suspect Pass Attribution

| Error pattern | Suspect | Confidence | Notes |
| --- | --- | --- | --- |
| `kernel btf_id ... is not a function` before any processed insn | `bpfverify` load-context/BTF replay | high | Fails at load setup, not transformed instruction semantics. |
| original `--verifier-states-out` failure | `bpfverify` original replay/state capture | high | Original bytecode fails before optimization attribution is meaningful. |
| final verifier errno 13 with map lookup/value snippets | `map_inline` possible, load-context still possible | medium | Needs full `bpfopt_report.json` and `verifier.log` to prove whether an inlined map value changed verifier type/range state. |
| XDP `tail_call` context | tail-call/program-array replay or original verifier-state capture | medium-high | Katran `xdp_root` fails during original verifier-state capture. |
| invalid type, jump out of range, kfunc/fd_array | no current evidence | low | These signatures were not present in the preserved summaries. |

Comparison with `5fbe934b`: that fix made hash null lookups a legitimate skip
and expanded scan-map-keys to cover live `LD_IMM64 PSEUDO_MAP_VALUE` cases. The
current dominant failure groups do not look like the exact bug fixed there:
hundreds fail before instruction processing or during original verifier-state
capture. The map-heavy final verifier failures are the remaining overlap with
`map_inline` live values, but the available summaries are truncated and full
workdirs were not exported.

## 12 Pass Coverage

The bpfopt registry has 12 passes:

`map_inline`, `const_prop`, `dce`, `skb_load_bytes_spec`,
`bounds_check_merge`, `wide_mem`, `bulk_memory`, `rotate`, `cond_select`,
`extract`, `endian_fusion`, `branch_flip`.

The benchmark default enabled 11 of them. `branch_flip` is registered and present
as a micro benchmark family (`branch_flip_dense`), but it is not in
`corpus/config/benchmark_config.yaml` default/experimental KVM pass lists.

| Pass | Registry | Enabled in corpus/e2e config | Evidence in this smoke |
| --- | --- | --- | --- |
| map_inline | yes | yes | enabled, aggregate ReJIT application positive |
| const_prop | yes | yes | enabled |
| dce | yes | yes | enabled |
| skb_load_bytes_spec | yes | yes | enabled |
| bounds_check_merge | yes | yes | enabled |
| wide_mem | yes | yes | enabled |
| bulk_memory | yes | yes | enabled, kinsn module loaded |
| rotate | yes | yes | enabled, kinsn module loaded |
| cond_select | yes | yes | enabled, kinsn module loaded |
| extract | yes | yes | enabled, kinsn module loaded |
| endian_fusion | yes | yes | enabled, kinsn module loaded |
| branch_flip | yes | no | covered by micro benchmark family, not daemon default |

Saved pass summaries in the result JSON only retain no-op style per-program
details; they do not preserve per-pass applied-site counts for changed programs.
Aggregate application is still positive: corpus applied `28/519` requested
programs, and e2e nested records applied `35/642` program attempts.

## Micro

`vm-micro SAMPLES=3` passed.

| Metric | Value |
| --- | ---: |
| suite | `micro_staged_codegen` |
| benchmarks | `62` |
| runtimes | `kernel`, `llvmbpf` |
| runs | `124` |
| samples per run | `3` |
| correctness mismatches | `0` |
| llvmbpf/kernel adjusted exec ratio geomean | `0.5024269349732582` |
| ratio min | `0.11830357142857142` |
| ratio max | `3.005385996409336` |

Measurement warnings were environment-related: CPU governor `unknown`, turbo
enabled, `perf_event_paranoid=2`, and no CPU affinity.

## Fix Recommendations

1. Export preserved failure workdirs into result artifacts. Either bind-mount
   `/var/lib/bpfrejit-daemon/failures` out of the KVM/container runtime or copy
   selected failure dirs under `details/failures/` before cleanup.
2. Split triage between original verifier-state replay failures and final
   verification failures. The original replay failures should be fixed before
   attributing pass bugs.
3. For `kernel btf_id ... is not a function`, audit `bpfverify` replay of
   `prog_btf_id`, `attach_btf_id`, and `attach_btf_obj_id` for kprobe/tracing/LSM
   contexts.
4. For errno 13 map-heavy final failures, replay the exported workdirs and compare
   `bpfopt_report.json` map_inline records against `verifier.log` register state.
5. For Katran XDP, audit program-array/tail-call map replay and original
   verifier-state capture around `xdp_root`.

No source fixes were made in this smoke run.
