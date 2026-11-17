# Original-program helper target query

This phase-1 diagnostic exercises the existing loader query without changing
loader core, the manifest writer, production configuration, the image or the
frozen benchmark. It reuses the committed current-link capture adapter and
local Make entry. The only experimental switch is the already-supported
`kernel_helper_context` field in a diagnostic native manifest.

`prepare.py` reads BCC's actual manifest from the sole image archive. It retains
that manifest and creates control/query configurations in the existing corpus
results mount. Relative native object/source paths become absolute paths to
the same files in the image in both configurations. Every other field stays;
only the query configuration adds `kernel_helper_context: true` to each entry.
The script reports whether the shipped and staged manifests match.

`run.sh` holds batch EX, timing SH and image SH, pins its controller to CPU 19
and runs the two guests sequentially on CPUs 8–15, eight vCPUs/64 GiB. It uses
the existing functional-check settings (one 10-second sample, stats enabled),
the same base/STATE and the unchanged guest entry. Address-space limit is
96 GiB. These are functional diagnostics, not official speed measurements.
Every kernel-link invocation retains actual proof, plan, status and available
outputs, including failures. An app failure remains recorded and the second
configuration still runs. Existing successful-run cleanup removes only the
rebuildable guest Docker disk; all raw data stays under `/workspaces`.

Compare helper addresses relative to a common live helper in each plan and
to the sole kernel's symbol offsets, accounting for boot relocation. Identify
actual original program types and emitted argument setup before interpreting
any target mismatch as a context semantics difference. Link success alone is
not a B/stock verification result or evidence of output equivalence. Permanent
loader-core fixes remain with the coordinator under the freeze contract.

The first preparation attempt (PID 2735977, raw `batch-20261117T200653Z-2735977`)
stopped before a guest: its archive lookup used the runtime `/opt` path.
The frozen Dockerfile actually stores these files under
`artifacts/user/native-bpf/x86_64` and exposes them at `/opt` at runtime.
The forward recipe separates those paths. Its exit trap also now retains
the run path after the main function returns. Original errors remain in
`prepare.txt` and `launcher.log`; no capture or VM ran in that attempt.

## Completed result

Recipe `7d0155b71`, forward archive-path repair `9d9046754`, analysis
`9ac9ead08`/`af7070b7b`/`a583a3eea`. Worker 2736466 ended with status 0
at 2026-11-17T20:14:45Z and released its locks. Both app statuses are `ok`.
The shipped manifest matches the staged manifest across all 29 entries.

| Configuration | Corpus run suffix | Kernel requests passed | Installed native programs | JIT bytes | Native bytes |
| --- | --- | ---: | ---: | ---: | ---: |
| Control, query absent | `200918_730425` | 25/25 | 25 | 7,965 | 12,803 |
| Existing query enabled | `201313_668398` | 25/25 | 25 | 7,965 | 12,803 |

Both capture indexes have zero archive errors. The shim logs contain no
native-loader failures. Installed native/JIT remains **1.61x**, above the
0.5 target. No image rebuild, production code change or new optimization
is represented by this diagnostic; per-call body/helper/map and throughput
improvement remain unmeasured. No B-generation or stock-verification census
was performed. The short program call counts in `targets.json` are retained
as observations, without replacing the longer timing series or altering
another run's status.

The actual helper target differences at named PLT32 references are:

| Native entry | Helper | Control kernel function | Queried kernel function |
| --- | --- | --- | --- |
| `tracepoint__syscalls__sys_exit_open` | `bpf_get_stack` | `bpf_get_stack` | `bpf_get_stack_tp` |
| Same entry | `bpf_perf_event_output` | `bpf_perf_event_output` | `bpf_perf_event_output_tp` |
| `tracepoint__syscalls__sys_exit_openat` | `bpf_get_stack` | `bpf_get_stack` | `bpf_get_stack_tp` |
| Same entry | `bpf_perf_event_output` | `bpf_perf_event_output` | `bpf_perf_event_output_tp` |
| `inet_sock_set_state` | `bpf_perf_event_output` | `bpf_perf_event_output` | `bpf_perf_event_output_tp` |
| `block_rq_complete` | `bpf_perf_event_output` | `bpf_perf_event_output` | `bpf_perf_event_output_raw_tp` |

`targets.json` resolves each address by its offset from the live
`bpf_ktime_get_ns` address against the sole build's `System.map`. It also
reads the emitted little-endian relocation records (`u32 offset, u32 kind,
u64 target`), rather than assuming that every listed helper is called.
For example, openat emits actual helper CALL relocations (kind 1) at
payload offsets 167 and 221 in both configurations. Their targets change
to the TP implementations. The requests for all four entries in this table
have byte-identical proof ELFs across configurations. Overall, 24/25 proof
ELFs match; capable's entry differs by its normal process-specific `my_pid`
constant (`cmp 0x7a2` versus `cmp 0x7af`), consistent with
`vendor/bpf/bcc/libbpf-tools/capable.bpf.c:86`. The manifests do not change
that value. Full per-proof disassemblies remain in the raw batch.

## Context ABI and source chain

This is a concrete helper/context ABI mismatch in the current normal route,
separate from whether both arms execute the same named programs. It is not
a measured estimate of wrong events, lost events or a performance gain.

- `native_loader.cpp:4100,4124,4141–4142` assigns the absent manifest flag
  as false and conditionally invokes the already-existing original-FD query.
  `native_loader_manifest.hpp:652` defaults the field to false.
- `native_loader_link_schema.hpp:95–129` uses the queried targets when
  available and otherwise binds static implementation names. Its five
  contextual overrides omit these output/stack helpers.
- `native_lab_helper_query_impl.h:61–80` selects verifier ops from the
  original program (including EXT target ops) and calls its real
  `get_func_proto(id, prog)`. This preserves attach/aux metadata.
- `trace_syscalls.c:1518–1534` supplies the syscall tracepoint context
  with the `pt_regs` pointer in its first word. `bpf_trace.c:1442–1447`
  selects TP output/stack prototypes. The TP bodies at 1372 and 1416
  unwrap that first word; the ordinary helpers expect `pt_regs` directly.
- The captured openat proof saves incoming RDI in RBX at offset 7, restores
  RBX into RDI at offsets 0x93 and 0xcb, and calls `bpf_get_stack` and
  `bpf_perf_event_output` respectively. Thus it passes the physical TP
  context to the selected helper without unwrapping it first.
  `bpf_jit_comp.c:508–561,3790–3816` emits the native prologue and copies
  this body without a tracepoint RDI conversion.
- `biosnoop.bpf.c:180` passes its original context to output. The tracing
  verifier route at `bpf_trace.c:1762` delegates this helper to the raw-TP
  prototype. Its implementation at 1594 obtains the proper registers via
  `get_bpf_raw_tp_regs` and `perf_fetch_caller_regs`, unlike the ordinary
  output helper selected by control.

`opensnoop.bpf.c:109–117` actually requests user-stack data and emits the
result. This establishes why the context distinction matters, but this
capture does not compare emitted stack payloads. Native open/openat program
names truncate to the same `tracepoint__sys`; the raw per-ID counters stay
in the receipt rather than being assigned to a full symbol by name alone.
`block_rq_comple` has 132 native invocations in each diagnostic; that does
not establish that its output branch ran on every invocation.

The normal production direction remains the existing original-program
query followed by deleting the obsolete opt-in flag plumbing, with no new
per-call check or handwritten helper-name catalogue. Loader core and the
manifest writer remain frozen/coordinator-owned. The separate
`load_trusted_worker` route (`native_loader.cpp:3916–3929,4069`) also needs
an owner audit; it creates a companion without assigning `context_helpers`.
This BCC normal-FD diagnostic does not establish that route's behavior or
coverage of the other five apps. Keep all LTO pieces enabled when the owner
publishes and checks the corrected normal path.

Raw: `/workspaces/kprog-raw/perf/helper-context-query-20261117/batch-20261117T200750Z-2736466`.
The small raw corpus JSON for both runs is committed beside their original
results; full console, shim logs, captured proof/plan/relocations and both
failed-preparation logs remain under `/workspaces`. `targets-summary.txt`
and `installed.txt` are analysis outputs, not framework result fields.

The emitted openat blob confirms the same argument path after linking:
RDI is saved to RBX at offset 7, then restored at 0x9f and 0xda immediately
before the stack and output call setups (CALL slots 0xa7 and 0xdd).
`analyze.py` retains actual emitted-blob disassembly beside the proof
disassembly in the raw batch; relocations remain authoritative for external
targets because these captured blobs are neutral before kernel patching.
