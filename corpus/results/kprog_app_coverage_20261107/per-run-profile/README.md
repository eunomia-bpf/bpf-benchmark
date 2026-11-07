# Direct per-run cost experiment

The coordinator's second correction replaces the lookup OFF/ON experiment. Existing map lowering stays enabled. Measure the actual `balancer_ingress` and Tetragon `generic_kprobe_event` path, then compare the same inputs with compiler jump/switch tables and sibling-call optimization enabled.

## Established capabilities and inputs

- Private perf7.0.rc2 builds from `vendor/linux-framework/tools/perf`. The build uses `NO_JEVENTS=1` because no python-config interpreter is installed; the five requested generic events remain available. Earlier source-directory/python detection failures are retained.
- Actual KVM guest exposes no hardware cpu PMU: perf stat reports `cycles` unsupported. Host hardware PMU works. Host events use `cpu_core/.../G` (guest only) on the exact QMP-reported vCPU TID, pinned to host CPU0. Guest has one vCPU and8GiB. The image and kernel are frozen/matched, unlike the earlier module-mismatched attempt.
- Actual KPROBE program ops has no TEST_RUN handler in the project kernel (`kernel/trace/bpf_trace.c`). The guest script retains the actual syscall result. Tetragon is measured through fixed `/dev/null` open/close calls with real attached kprobes. This is not a KPROBE TEST_RUN result or a synthetic context execution.
- Katran uses the actual upstream server, its program loads and the corpus map initializer. A quiet veth replaces the network traffic topology for this direct-program experiment; it creates no NAPI busy-poll workers. Input is the existing64-byte TCP packet targeting10.100.1.1:8080. Each syscall uses TEST_RUN repeat1 and a fresh copy of that input; kernel repeat>1 would reuse the packet after Katran's encapsulation. Bypass and warm-LRU map configurations are both recorded. Every output within a window must have identical action and packet bytes; analysis requires XDP_TX and matching output hash across JIT/native.
- Baseline Tetragon IDs are selected using the actual first function's full BTF name. Native IDs come from exact `symbol=generic_kprobe_event` replacement records. Truncated kernel names alone are insufficient. Every measured ID, BTF function identity, JIT byte dump, source snapshot, kallsyms and run-count/time delta is retained.

## Collection and limits

`host.py` queues while another QEMU uses CPUs0-7 and rechecks before each window. FIFOs enable/disable host perf only around the fixed work. Stat collects cycles, instructions, branch misses, iTLB-load misses and L1 icache-load misses. Separate cycle sampling uses a1,000,000-cycle period and guest kallsyms. Stat counters include the guest TEST_RUN syscall/dispatch and measurement boundary; report these as **guest ROI events per input**, alongside actual **BPF ns/run**. Do not label all inclusive counters as program-body cost. Samples are used to separate map/helper functions, BPF/JIT code, tail-call code and syscall/dispatch overhead. Exact code offsets/JIT bytes are retained for entry/body inspection.

The first standalone setup failed before any measurement because artifact/module-root environment variables were absent; fixed explicitly. The initial vng QMP argument failure and a queued source reload before lease acquisition are also retained. No performance number has passed collection/analysis yet. A foreign R guest currently occupies0-7; the corrected baseline job is queued. The tables continuation runs only after baseline succeeds and `analyze.py` validates hardware counts and packet/action equivalence. No lookup OFF/ON job is queued.

## Compiler candidate

The PIC candidate removes `-fno-jump-tables`, `-switch-to-lookup=false` and `-fno-optimize-sibling-calls` together. Exact commands/native objects/proofs/manifests are in `table-candidate-inputs.tar.gz`. Every actual manifest entry in each changed object has a new canonical proof (Katran1, Tetragon1); unrelated objects/manifest entries are retained. Old proofs for changed objects are removed from the private image. An earlier attempt to treat arbitrary private helper functions as standalone application entries failed (`data_event_bytes` -> helper-register call); that attempt is preserved, and those helpers are still discovered normally from actual entries. The candidate image is `bpf-benchmark/kprog-perf-tables:c-20261107`; no shared image replacement.

Non-PIC failures from the prior experiment remain open and retained separately. No unsupported program is counted as passed.

## Reproduction

From repository root:

```
make -f corpus/results/kprog_app_coverage_20261107/Makefile perf-tool perf-profile-build frozen-kernel
setsid nohup make -f corpus/results/kprog_app_coverage_20261107/Makefile perf-profile > /workspaces/.agent-state/kprog-lanes/C/per-run-profile.job.log 2>&1 < /dev/null &
```

Inspect the completed run listed in `C/current-perf-run`, then run `analyze.py RUN_DIRECTORY`. `perf-tables-profile` uses the same protocol for the candidate. `tool-and-candidate-sha256.json` pins binaries/inputs. `preflight-and-setup.tar.gz` retains capability probes and failed setup logs. Completed private guest Docker disks are deleted after their logs/artifacts are retained. This is an unbound performance experiment, not proof of generation-bound application coverage.
