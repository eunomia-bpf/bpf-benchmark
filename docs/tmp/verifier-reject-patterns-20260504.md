# Verifier Reject Patterns

Date: 2026-05-04

Scope: read-only analysis of saved corpus results. No VM corpus run, source edit,
or build was performed.

## Data Selection

The newest result,
`corpus/results/x86_kvm_corpus_20260504_003830_701212/`, is contaminated by the
ROFS/ENOSPC failure. It is useful for the ROFS timeline, but not for clean
verifier reject statistics after the first few failures.

The newest top-level `status=ok` results after May 3 are small subset runs and
do not contain the tracee/cilium failure patterns. For verifier patterns below I
used the latest completed per-app result files that contain the relevant
programs and a saved `result.json`:

- tracee all-pass result:
  `corpus/results/x86_kvm_corpus_20260503_191451_231040/details/apps/tracee__monitor.json`
- tracee prefetch-only E2BIG result:
  `corpus/results/x86_kvm_corpus_20260503_151957_102566/details/apps/tracee__monitor.json`
- cilium all-pass result:
  `corpus/results/x86_kvm_corpus_20260503_164524_101015/details/apps/cilium__agent.json`

The current ROFS run is mentioned only for two pre-ROFS tetragon E2BIG
observations.

## Per-App and Per-Pass Summary

Clean all-pass cilium source
`x86_kvm_corpus_20260503_164524_101015`:

| app | failed programs | notes |
| --- | ---: | --- |
| bcc/capable | 0 | completed |
| bcc/execsnoop | 0 | completed |
| bcc/bindsnoop | 0 | completed |
| bcc/biosnoop | 0 | completed |
| bcc/vfsstat | 0 | completed |
| bcc/opensnoop | 0 | completed |
| bcc/syscount | 0 | completed |
| bcc/tcpconnect | 0 | completed |
| bcc/tcplife | 0 | completed |
| bcc/runqlat | 0 | completed |
| calico/felix | 0 | completed |
| otelcol-ebpf-profiler/profiling | 0 | completed |
| cilium/agent | 1 | prog 141 `wide_mem`, errno 13 |

Tracee all-pass source `x86_kvm_corpus_20260503_191451_231040`:

| app | failed programs | notes |
| --- | ---: | --- |
| tracee/monitor | 34 | 5 verifier/kernel rejects, 29 map snapshot failures |

Tracee verifier/kernel rejects from that source:

| prog | name | type | pass | errno | bytes_xlated |
| ---: | --- | --- | --- | ---: | ---: |
| 51 | tracepoint__sched__sched_process_exec | raw_tracepoint | const_prop | 22 | 35424 |
| 52 | sched_process_exec_event_submit_tail | raw_tracepoint | dce | 13 | 38432 |
| 150 | process_execute_failed_tail | kprobe | dce | 13 | 20216 |
| 151 | trace_exec_binprm | kprobe | const_prop | 22 | 28960 |
| 152 | trace_security_bprm_creds_for_exec | kprobe | const_prop | 22 | 29144 |

Tracee map snapshot failures from that source:

- 29 programs failed before a pass-specific verifier reject while building the
  `map_inline` live map snapshot.
- Most errors are `map 155 returned more than max_entries=10240`.
- Two errors are `map 175 returned more than max_entries=5`.
- Affected programs: 55, 82, 87, 88, 89, 90, 91, 92, 94, 95, 96, 98, 99, 101,
  103, 104, 105, 106, 107, 109, 110, 115, 126, 130, 137, 144, 145, 147, 149.

Tracee prefetch E2BIG source `x86_kvm_corpus_20260503_151957_102566`:

| prog | name | type | pass | errno | bytes_xlated |
| ---: | --- | --- | --- | ---: | ---: |
| 43 | tracepoint__sched__sched_process_fork | raw_tracepoint | prefetch | 7 | 32248 |

Current ROFS run pre-ROFS signal:

| app | prog | name | pass | errno | note |
| --- | ---: | --- | --- | ---: | --- |
| tetragon/observer | 37 | execve_send | prefetch | 7 | before EROFS cascade |
| tetragon/observer | 38 | event_execve | prefetch | 7 | before EROFS cascade |

Other tetragon failures in the 20260504 result include errno 28 and errno 30
after loop0 space allocation failed; those are filesystem fallout, not clean pass
rejects.

## Failure Classes

### errno 7 / E2BIG

Observed:

- tracee prog 43, `prefetch`, after 5 committed passes
- tetragon progs 37 and 38, `prefetch`, after 11 committed passes, before ROFS

Kernel-side relevant return points:

- `vendor/linux-framework/kernel/bpf/syscall.c:3624-3628`: rejects invalid or
  too-large `BPF_PROG_REJIT` instruction/fd-array inputs with `-E2BIG`.
- `vendor/linux-framework/kernel/bpf/syscall.c:3789-3791`: rejects replacement
  program size if it exceeds the original program's allocated page budget.
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:594-595`: rejects a kop
  descriptor whose `max_emit_bytes` exceeds `BPF_MAX_INSN_SIZE`.

Classification: limitation/capacity class, not the first pass implementation bug
to chase. `prefetch` increases instruction count, and these programs are already
large.

Recommendation:

- Document as a current limitation.
- Add warning-only diagnostics that report projected instruction/page growth
  before ReJIT. Do not silently filter or skip ReJIT unless the benchmark policy
  explicitly changes.

### errno 13 / EACCES

Observed:

- cilium prog 141 `dump_bpf_prog`, `wide_mem`, after 0 committed passes
- tracee progs 52 and 150, `dce`, after 7 committed passes

The cilium failure has a clear verifier reason in the saved artifact:

`access beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8`

The rejected instruction is a wide load from a BTF-typed `struct bpf_prog`
pointer:

`r7 = *(u64 *)(r1 +0)`

The original byte-ladder was verifier-accepted; `wide_mem` rewrote it into a
single 8-byte typed load. Current `wide_mem` has alignment checks and packet
pointer heuristics, but the BTF/typed-pointer guard only exists indirectly for
XDP/TC packet pointers:

- pattern and emit: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:78-315`
- packet-pointer skip block: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:491-523`
- final rewrite/remap: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:548-582`

Classification for cilium 141: pass implementation bug. `wide_mem` must not
turn byte loads into wide typed loads unless it can prove the verifier will
accept the full member range and size for BTF pointers.

Recommended fix for cilium 141:

- Extend the safety filter near `wide_mem.rs:491-523` to skip ctx-derived
  BTF/typed pointers in tracing programs, or add a verifier-state/BTF member
  oracle that proves `base_off..base_off+width` stays inside a single allowed
  member range.
- Add a regression test for the `bpf_iter_bpf_prog`/`struct bpf_prog` pattern.
- Prefer conservative skip over a broad rewrite; one missed optimization is much
  cheaper than a verifier reject.

Tracee dce failures do not have enough final verifier text in the bounded saved
artifact to name the exact verifier rule. The likely code area is:

- `bpfopt/crates/bpfopt/src/passes/dce.rs:44-74`
- `bpfopt/crates/bpfopt/src/passes/utils.rs:943-1001`

Notably `eliminate_dead_register_defs()` can remove `BPF_LDX` and other dead
definitions when liveness says the destination is unused. That may be correct,
but for these tracee programs it needs a targeted full-log reproduction before
changing behavior.

Recommended fix for tracee dce:

- Reproduce only progs 52 and 150 with full verifier logs retained.
- Compare the pre-dce and post-dce bytecode around the first verifier error.
- If the failing site comes from dead-def removal, make `DcePass` conservative
  for memory loads, helper-adjacent register setup, or any instruction whose
  verifier state is consumed even when the BPF register liveness result is dead.

### errno 22 / EINVAL

Observed:

- tracee prog 51, `const_prop`, after 6 committed passes
- tracee prog 151, `const_prop`, after 6 committed passes
- tracee prog 152, `const_prop`, after 6 committed passes

The saved artifacts contain bounded verifier summaries, not the final full
verifier reason. Classification is therefore "likely pass implementation bug,
exact rule unknown".

Relevant code area:

- verifier exact-constant oracle: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:120-165`
- replacement collection and protected prefix filter:
  `bpfopt/crates/bpfopt/src/passes/const_prop.rs:190-210`
- ALU fold: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:410-428`
- branch fold: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:430-443`
- BTF/line remap after rewriting:
  `bpfopt/crates/bpfopt/src/passes/const_prop.rs:249-270`

Recommended fix:

- Reproduce progs 51, 151, and 152 with full logs retained, but only for this
  targeted triage.
- Check whether `const_prop` folds branch/control-flow or expands a MOV into
  `LD_IMM64` in a way that invalidates verifier-derived facts, BTF metadata, or
  helper-dependent state.
- Add a conservative guard for replacements that change instruction width or
  control flow when the exact value came only from verifier observations rather
  than local dataflow.

### Map Snapshot Failures

Observed:

- 29 tracee programs fail while building live values for `map_inline`.
- Error shape:
  `scan live keys for map <id>: BPF_MAP_GET_NEXT_KEY ... more than max_entries=<n>`.

Relevant daemon code:

- `daemon/src/commands.rs:560-586`: `live_bpf_map_keys()` bails when the key scan
  exceeds `map.max_entries`.
- `daemon/src/commands.rs:1145-1175`: `write_live_map_values()` propagates that
  scan error.

Classification: daemon snapshot robustness/design gap, not a verifier reject.
It currently converts volatile-map scan behavior into a whole-program failure
before the pass pipeline has a chance to continue.

Recommended fix:

- Treat map scan overflow as "map_inline unavailable for this map/program" and
  continue without inlining, or cap the scan and emit a warning.
- Consider a retry/seen-key guard for active maps, because live maps can mutate
  while `BPF_MAP_GET_NEXT_KEY` is walking them.
- Keep this as warning-only if preserving "No ReJIT Filtering" semantics is
  required; do not hide that map_inline was skipped or degraded.

### errno 28 / ENOSPC and errno 30 / EROFS

Observed heavily in `x86_kvm_corpus_20260504_003830_701212`, especially
tetragon after the loop0 journal abort.

Classification: infrastructure fallout from ROFS, not pass reject data.

## Prioritized Repair List

1. Fix `wide_mem` BTF/typed-pointer safety for cilium prog 141. This has the
   clearest verifier reason and a narrow code area.
2. Make map-inline live map snapshot overflow non-fatal. This accounts for 29
   tracee program failures in one run and is daemon-side, not kernel semantics.
3. Triage tracee `const_prop` and `dce` with full logs for only the five known
   program IDs, then add conservative guards in the identified pass areas.
4. Document `prefetch` E2BIG as a current limitation and add warning-only growth
   diagnostics. It is not the highest-value correctness fix.

## Notes on Evidence Quality

The bounded failure artifacts are sufficient to classify pass/errno/program
patterns, but not sufficient to diagnose the exact final verifier rule for the
tracee `const_prop` and `dce` failures. The cilium `wide_mem` failure is the
exception: its saved verifier summary includes the decisive BTF member-bound
message.
