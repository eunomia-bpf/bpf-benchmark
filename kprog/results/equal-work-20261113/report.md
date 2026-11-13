# OTel / Tetragon equal-work investigation — 2026-11-13

## Verdict and limits

**The native arms do not faithfully implement all of the eBPF arms' behavior.**
OTel's native arm is demonstrably wrong: it reads the physical perf-event context
as an embedded public register structure, performs no user-stack unwinding, and
exports far fewer profile items. Tetragon's native build also contains a concrete
wrong-field-read defect: CO-RE flavor structures retain their declaration offsets
instead of the running kernel's offsets. There is additionally a startup/program
inventory race in the benchmark setup.

**This report does not completely localize Tetragon's hot-kprobe work collapse.**
The flavor defect proves incorrect native task metadata; the captured counters
prove a sharply different send-failure mix even after startup. They do not prove
that this particular defect explains the complete 15.9x timing gap. Successful
per-type event totals and exact BPF-helper return-value totals remain unmeasured.
Treating those missing observations as measured zeros, or claiming a complete
Tetragon causal diagnosis, would be incorrect. The measured workload throughput
and all original runs remain retained; throughput is not evidence of equivalent
observability behavior.

No native semantic fix, kernel/image rebuild, frozen runner change, or workload
change was made. The fixes below need native-producer/verified-lane integration.
The added diagnostic wrapper is inactive unless explicitly selected in PATH and
given `EQCODEX_OUT`; trace attempts additionally require `EQCODEX_TRACE=1`.

## Runs and provenance

One checkout, master, sole kernel `74d1097af561`, image
`bpf-benchmark/kprog:current`, existing base. Each guest ran alone for this job on
host CPUs 0–7, VM_CPUS=8, VM_MEM=32G, STATE=/var/tmp/kprog-tmp/eqcodex, SAMPLES=1.
Other lanes' processes were not stopped. The historical audit and lane notes
were read before running anything. Initial repository HEAD was `d528c508d`;
other lanes continued committing during this investigation.

All successful guest launches used:

```sh
PATH=/workspaces/repository/kprog/perf/may29-image/eqcodex-bin:$PATH \
EQCODEX_OUT=/workspaces/repository/kprog/results/equal-work-20261113/<capture> \
make -f kprog/perf/one-image/Makefile corpus APPS=<app> SAMPLES=1 \
  WORKLOAD_DURATION=<seconds> CPUS=0-7 VM_CPUS=8 VM_MEM=32G \
  STATE=/var/tmp/kprog-tmp/eqcodex LOGS=/workspaces/kprog-raw/eqcodex-20261113 \
  BPFREJIT_CORPUS_BPF_STATS=<stats>
```

| Capture | Application | Seconds | Stats | Corpus run under `corpus/results/` |
|---|---|---:|---:|---|
| raw-otel | otelcol-ebpf-profiler/profiling | 45 | 0 | x86_kvm_corpus_20261113_021528_529682 |
| raw-tetragon | tetragon/observer | 45 | 1 | x86_kvm_corpus_20261113_022036_110279 |
| raw-tetragon-jit | tetragon/observer | 120 | 1 | x86_kvm_corpus_20261113_022551_637848 |
| raw-tetragon-events | tetragon/observer | 60 | 1 | x86_kvm_corpus_20261113_023730_974136 |

The last run additionally set `EQCODEX_TRACE=1`. There is one frozen warmup per
phase, so `measurement_start` in the guest progress log precedes warmup, not the
shim's actual `measure_start` counter snapshot. The 120-second run gives a
complete-program observation after native loading finishes. These are diagnostic
runs, not replacement headline performance measurements.

Raw captures remain in this directory. `raw-evidence.tar.gz` publishes them, the
four runs' app JSON/shim logs/metadata, selected historical receipts, and host
launch logs. `evidence/sha256.txt` identifies the sole kernel/image and native
inputs. An initial launch failed because an output directory outside the guest's
writable repository mount was read-only; that log is retained. No failed raw data
was deleted. The image and kernel were reused throughout.

## OTel: native reads the wrong context and skips unwinding

The paired windows below belong to **one run**, not the previously confused
`otel-eq13` / `otel-eq14` pair. Counter files and collector scrapes are in the
named capture snapshots; `otel-snapshots.json` contains all decoded totals.

* eBPF: `raw-otel/baseline-0002` → `baseline-0010`, metrics map 61,
  02:15:43.892188 → 02:16:57.598960 UTC, 73.707 seconds.
* Native: `raw-otel/post_rejit-0013` → `post_rejit-0020`, metrics map 337,
  02:17:29.124895 → 02:18:33.231383 UTC, 64.106 seconds.

| Counter delta | eBPF | Native |
|---|---:|---:|
| UnwindNativeAttempts | 708,823,203 | 0 |
| UnwindNativeFrames | 652,697,726 | 0 |
| UnwindCallInterpreter | 158,594,652 | 0 |
| UnwindNativeErrReadKernelModeRegs | 412,516 | 50,517,835 |
| ErrEmptyStack | 18,319 | 43,106,360 |
| MaxTailCalls | 1,079 | 0 |
| Collector exporter queue batch-send-size sum | 72,145 | 1,787 |
| TraceCacheHit | 2,671,376 | series absent |
| TraceCacheMiss | 10,188 | series absent |

The exporter statistic counts exported pipeline items, **not an exact count of
raw kernel trace samples**: aggregation, error filtering and exporter batching
intervene. Its large decrease corroborates the unwinder failure; it must not be
renamed a trace-emission total. Missing collector series are reported as absent.
Native can still emit error/kernel-only material, so its exported count is not
zero despite zero native user frames.

`baseline-0011` spans restart and already sees the new native-generation maps.
It is preserved, but is not an eBPF counter continuation. Merely trusting the
last progress phase string would recreate the earlier lane's comparison error.

The earlier correctly paired `corpus/results/otel-phasesM/r2` (corpus run
`x86_kvm_corpus_20261113_011757_432921`) independently has end totals
913,099,438 → 0 attempts, 840,462,900 → 0 frames, 325,721 → 74,119,936 register
errors and 22,331 → 65,351,909 empty stacks. The new run reproduces that behavior.

### Tail calls and root cause

`raw-otel/baseline-0001/map-9-perf_progs.json` has slots 0–9 populated.
The native array, `post_rejit-0012/map-292-perf_progs.json`, also has every slot:

| Slot | eBPF target ID | Native target ID | Function family |
|---:|---:|---:|---|
| 0 | 6 | 26 | unwind_stop |
| 1 | 7 | 28 | unwind_native |
| 2 | 8 | 30 | Hotspot |
| 3 | 9 | 32 | Perl |
| 4 | 11 | 36 | Python |
| 5 | 10 | 34 | PHP |
| 6 | 12 | 38 | Ruby |
| 7 | 13 | 40 | V8 |
| 8 | 14 | 42 | .NET |
| 9 | 15 | 44 | Go labels |

These native targets have native-sized JIT images, not empty fallback bodies.
Native entry 48 and native unwinders 26/28/30 reference the same metrics map 337.
The native arm's large error increments show that replacing programs did **not**
erase metric writers. Zero attempts is not justified away by that explanation.
`MaxTailCalls` is a budget-exhaustion error metric, not a successful-tail-call
counter (`vendor/bpf/otel/support/ebpf/tracemgmt.h:543–553`). Its zero alone
does not establish that no tail call occurred. The error path can tail-call
slot 0 while never entering slot 1 or an interpreter.

The exact mismatch is:

1. `vendor/linux-framework/kernel/events/core.c:10591–10605` constructs
   `bpf_perf_event_data_kern`, with a **regs pointer**, and passes `&ctx`.
2. `vendor/linux-framework/kernel/trace/bpf_trace.c:1895–1900` converts each
   eBPF public register read into `*(ctx->regs + field_offset)`.
   The captured baseline entry, `baseline-0001/prog-17-xlated.txt`, instructions
   206/207, actually loads `*(r9+0)` followed by `*(result+160)` for SS.
3. `vendor/bpf/otel/support/ebpf/native_stack_trace.ebpf.c:678` passes
   `&ctx->regs` into `collect_trace`. In native C the public structure embeds
   registers at offset zero. `tracemgmt.h:656` consequently becomes a single
   `cmpq $0x2b,0xa0(%rbx)` at native-object offset **0x361**, with RBX holding
   the incoming physical context. It reads `ctx+160`, not `*(ctx+0)+160`.
4. The direct native JIT (`arch/x86/net/bpf_jit_comp.c:3800–3809`) emits the
   supplied image without the eBPF context-access conversion. The bad access
   already exists in the producer object, before linker ABI stripping.
5. Misclassification takes `get_usermode_regs`' task-stack fallback
   (`tracemgmt.h:683–691`); failures leave `has_usermode_regs=false`, and
   `collect_trace:758–781` selects STOP instead of unwinding.

The image's OTel input hash is
`590aa121e6b129ddf9e0549a0f072192f323458fefdbbd67835a4bb6304c4915`, identical to
the locally disassembled object and the earlier verified-lane receipt
`kprog/results/verified_20261112/otel-perf-event-context.json`.

Both phases' dumped `.rodata.var` offsets were zero, including task_stack_offset
and stack_ptregs_offset. This does not prove the task-stack fallback is healthy:
the actual task.stack offset is 32. It does rule out a *between-arm change in
those dumped values*. The eBPF arm still successfully unwinds user-mode samples;
the native arm misreads the entry context before that fallback. This report
does not certify that every baseline kernel-mode sample is handled correctly.
The error metric combines two nonzero probe returns and a zero resolved pointer;
it does not identify a particular errno or which read failed.

**Smallest general fix:** lower all PERF_EVENT public context accesses to the
physical kernel view in the native producer/link path, preserving the original
physical ctx for helpers and tail calls. Cover regs, sample_period and addr;
do not replace the incoming pointer globally with `ctx->regs`, or patch SS only.
This needs verified/native-producer coordination and a paired rerun. It was not
implemented in this report-only job.

## Tetragon: wrong native CO-RE flavor layout, plus incomplete startup

### Concrete native semantic defect

`vendor/bpf/tetragon/bpf/include/vmlinux.h:28–33` defines the CO-RE flavor
`task_struct___local`: four pid_link entries, then thread_pid, audit, loginuid.
Those are **description fields for CO-RE relocation**, not an ABI-compatible
layout of a running task_struct.

`vendor/bpf/tetragon/bpf/lib/bpf_task.h:50–60` casts a real task to this type and
reads its thread_pid; `process/bpf_process_event.h:20–33` similarly reads loginuid.
Native compatibility processing drops `__builtin_preserve_access_index`
(`vendor/bpf/native_compat.h:66–70`), mostly answers field-existence queries true
(`:309–326`), and uses C sizeof for field size (`:335–336`). Generating the main
vmlinux header does not resolve these separate flavor definitions.

| Field | Native flavor offset | Actual sole-kernel offset |
|---|---:|---:|
| task.thread_pid | 96 (0x60) | 2904 (0xb58) |
| task.loginuid | 112 (0x70) | 3552 (0xde0) |

This is present in the image input, not merely a hypothetical source defect.
`evidence/tetragon-fork-native.txt` shows native `event_wake_up_new_task` at
**0x2ff** forming `child_task+0x60` and calling helper 113. Later, its separately
implemented namespace reader correctly uses task+0xb58 at 0x4ce. Thus one native
handler uses two incompatible views of the same task field. The native fork
object hash recorded inside the guest is
`3c1db76f3a25d72a9d2d5882141a277f2a8dff0856f7d7f6933974c89c66b6a7`, matching
the inspected local input. `evidence/kernel-task-layout.txt` records the actual
kernel layout. A probe read can return success while reading the wrong task
field: checking return values alone cannot establish equivalence here.

This makes native namespace-PID/audit metadata incorrect. It is sufficient to
reject a claim that the two arms implement identical Tetragon behavior. It is
**not** sufficient to attribute every missing hot-kprobe event to this getter:
the frozen policy set does not generally filter on namespace PID, and the exact
first divergent hot-path branch was not captured.

Some fast native work is intentional and potentially legitimate:
`process/bpf_process_event.h:103,158,191` replaces namespace/credential probe
reads with direct reads under MICRO_NATIVE_TETRAGON. The captured native entry
JIT `raw-tetragon-jit/post_rejit-0027/prog-358-jited.bin` contains these direct
loads and a real tail jump; its original companion is program 357. A flat native
cost, by itself, is therefore not proof that the function became empty.

**Smallest general semantic fix:** resolve flavored type names, field existence,
field offsets, sizes and relevant enum/bitfield relocations against the running
kernel BTF before native C code generation. Resolve `type___flavor` against its
target type while respecting the flavor's queried fields. Fixing only the main
generated header, or adding another string-specific field-existence exception,
does not solve the class. A trial producer mode should be runtime-selected and
default off. No partial per-field workaround or rebuilt object set is installed
by this job; the producer/verified lane must implement and integrate this fix.

### What the program inventories actually establish

Historical run `x86_kvm_corpus_20261112_152929_580401` really records 171 eBPF
programs (20 executed) versus 106 native programs (16 executed). Names such as
generic_kprobe_ collapse entry, setup, filter, actions and output stages.
Matching by that truncated name cannot establish counterpart identity.

The source mechanism for an incomplete-start comparison is
`runner/libs/app_runners/tetragon.py:35–41`: zero stability wait and min_programs
100. `runner/libs/rejit.py:458–467` then runs one warmup and snapshots counters;
this is time-based warmup, not completed policy loading. The 45-second capture
shows 102 total programs initially, then 290 after baseline loading; native
starts around 100 replacements and continues loading during the run.

However, **do not use the old 171/106 inventory to explain round f's entire
15.9x gap**. Round f `x86_kvm_corpus_20261112_181317_831801` records 287 programs
and 32 with executions in each arm. Our 120-second run records 287 and 33 in
each arm. In guest-wide dumps the mature native phase has 578 programs, because
the original programs are retained alongside their replacements; this is not
578 attached native handlers versus 290 baseline handlers.

The native kprobe call arrays are populated and point to native-sized target
images. For the captured first chain, original entry 357 / native entry 358 and
original filter 361 / native filter 362 share process_call_heap. The native
entry tail jump uses the expected map slot 2 and callee bpf_func+12. This does
not count successful invocations of every target. Tail targets' zero run_cnt
does not prove non-execution because tail calls skip top-level accounting.

The benchmark-side correction belongs to the frozen runner's owner: use the
application's completed-policy-load state and retain full entry identities and
attachment membership. This is a real readiness defect, not a proposed new
measurement admission rule. It was not changed without the operator's consent.

### Events per type: measured failures, not successful emissions

In the mature run, `tetragon-mature-snapshots.json` gives these same-map deltas:

* eBPF: raw-tetragon-jit/baseline-0017 → baseline-0021, map 18,
  02:28:53.700442 → 02:29:33.403878 UTC (39.703 s).
* Native: raw-tetragon-jit/post_rejit-0040 → post_rejit-0044, map 3559,
  02:33:11.236567 → 02:33:51.786952 UTC (40.550 s); 578 programs throughout.

| Event / EAGAIN | eBPF | Native |
|---|---:|---:|
| GENERIC_KPROBE (13) | 10,489,275 | 13,546 |
| GENERIC_TRACEPOINT (14) | 31,839,295 | 54,679,347 |
| EXECVE (5) | 18 | 25 |
| EXIT (7) | 16 | 6 |
| CLONE (23) | 18 | 13 |
| DATA (24) | 0 | 0 |

`vendor/bpf/tetragon/bpf/lib/process.h:671–675` increments tg_stats_map only
after ringbuf_output returns an error. Slot 6 is EAGAIN, not slot 0. This table
is not a total-event table; native might have fewer send attempts, different
successful sends, or different ring occupancy at each type's send times.
The persistent mix change contradicts any claim of uniformly scaled observable
activity, but does not alone locate the first semantic divergence.

The lane's explanation that replacement automatically erases these writers is
unsupported: native is compiled from source containing event_output_metric and
references the shared map. Replacing an eBPF writer with a native implementation
does not inherently remove its writes. The rising native tracepoint counter is
also direct evidence that native-side writers can remain active.

The last run attempted direct successful-commit/per-type probes and nofault
read-return probes, preserving every command status and stderr. The kernel
rejected dynamic probe registration with EIO. Earlier helper probes were also
rejected; CONFIG_KPROBE_EVENTS_ON_NOTRACE and CONFIG_HIST_TRIGGERS are disabled.
The upstream Tetragon metrics endpoint on :2112 is not enabled by this frozen
launch. Consequently there is **no measured successful emission total** and no
exact BPF-helper errno distribution in this report. No rebuild, extra exporter
flag, modified launcher or silent substitute was used to manufacture them.

## Differential testing and validation

The repository's fixture/test-run path in `runner/src/kernel_runner.cpp` and
the native micro harness cover replayable inputs. The kernel's KPROBE and
PERF_EVENT program ops do not supply a general test_run implementation here.
Saved map snapshots also do not contain the interrupted task, its kernel/user
memory, perf context or a deterministic perf/ring-buffer consumer state.
The instruction-fidelity differential suite compares native instructions with
the simulator; it does not compare these whole application BPF/native executions.
Running it would not validate either context mapping or CO-RE metadata.
No whole-application same-captured-input differential pass is claimed.

The live eBPF context conversion, image-input hashes, native disassembly and
sole-kernel BTF layout localize concrete ABI defects without inventing such a
pass. The remaining Tetragon causal check is to compare captured helper-visible
effects/full event payloads through the relevant filter/output chains after
general context/CO-RE correction. Until then, do not call its 15.9x an equal-work
handler speedup or assert that the flavor fix alone restores it.

Validation performed: all four diagnostic corpus runs completed; C JIT reader
built with -Wall -Wextra -Werror and successfully captured actual program bytes;
both Python scripts compiled and decoded their raw captures; the wrapper's
default passthrough returned vng help; git diff --check passed. Failed bpftool
JIT-disassembly and tracing attempts remain in the evidence. No paper, design,
benchmark workload, application runner, kernel, linker, loader or shim was edited.
