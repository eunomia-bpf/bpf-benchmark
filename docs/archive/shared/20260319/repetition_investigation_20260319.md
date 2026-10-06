# Repetition Investigation (2026-03-19)

## Short answer

For the main micro `kernel` path and the packet-backed corpus `run-kernel` paths, repetition is already done inside the kernel with `bpf_prog_test_run_opts.repeat`, not by issuing one syscall per execution.

The main exceptions are:

- `micro_exec run-llvmbpf`: repetition is a userspace loop around the JIT'd function.
- `run-kernel` with `io_mode=context`: the runner forces `repeat=0/1`, so there is no kernel-side repetition.
- tracing/attach-style corpus drivers: repetition is a userspace workload loop, and timing comes from `bpf_prog_info.run_time_ns/run_cnt` or wall clock, not `bpf_prog_test_run`.

So the user's suspected "kernel path is repeating in userspace" is false for the normal micro `kernel` runner and for the packet-backed corpus perf/v5/production drivers. Ultra-short noise there comes from other causes, mainly 1ns quantization of kernel-reported average duration and, in some corpus drivers, lack of multiple outer iterations.

One important correction to the background: in the current vendored kernel checkout, `bpf_prog_test_run_opts.duration` is already the average per execution, not the total over all repeats. The kernel does `do_div(time_spent, repeat)` before returning `duration` (`vendor/linux-framework/net/bpf/test_run.c:50-60`), and bpftool prints `duration (average)` when `repeat > 1` (`vendor/linux-framework/tools/bpf/bpftool/prog.c:1478-1486`).

## 1. Micro: `micro_exec run-kernel`

### What the runner does

- One measured sample is one call to `bpf_prog_test_run_opts(...)` (`micro/runner/src/kernel_runner.cpp:266-303`).
- The runner writes `test_opts.repeat = effective_repeat` for non-`context` I/O modes (`micro/runner/src/kernel_runner.cpp:1412-1451`).
- It then calls `bpf_prog_test_run_opts` once, reads `test_opts.duration`, and stores it directly as `sample.exec_ns` (`micro/runner/src/kernel_runner.cpp:286-299`, `1498-1518`).

So for `staged`, `packet`, and `map` micro benchmarks, repetition is kernel-side.

### What `--repeat` means here

- `--repeat` is not "number of outer samples".
- It is the requested inner repeat count for one `bpf_prog_test_run_opts` syscall.
- But it is only a minimum for the kernel runner, because the runner may raise it with adaptive repeat.

Adaptive repeat logic:

- If `io_mode == context`, the runner hard-forces effective repeat to `1` (`micro/runner/src/kernel_runner.cpp:309-310`).
- Otherwise, if adaptive repeat is enabled, the runner does a 10-run probe and may increase repeat to reach a target timing window (`micro/runner/src/kernel_runner.cpp:317-335`).
- Default settings in `cli_options`: `adaptive_repeat=true`, `target_window_ns=100000` (`micro/runner/include/micro_exec.hpp:62-65`).

### Timing semantics

- `sample.exec_ns` is the kernel-returned average execution time per run.
- `sample.exec_cycles` and `sample.wall_exec_ns` are computed in userspace from the one syscall's total TSC delta divided by `effective_repeat` (`micro/runner/src/kernel_runner.cpp:289-299`).
- `phases_ns.prog_run_wall_ns` is the total wall time of the whole syscall, not divided by repeat (`micro/runner/src/kernel_runner.cpp:1508-1517`).

If kernel repeat were 1000 and the total steady-state execution time were 5000ns, the kernel would return `duration=5ns`, and `micro_exec` would report `exec_ns=5`. It does not divide `exec_ns` a second time.

### Surprising detail: internal warmups are separate from driver warmups

- The C++ runner has its own `warmup_repeat` field, default 5 (`micro/runner/include/micro_exec.hpp:63`).
- The Python micro driver does not pass `--warmup` to the runner.
- The kernel runner only uses this internal warmup loop when a recompile was actually applied (`micro/runner/src/kernel_runner.cpp:1453-1457`).

So:

- driver `WARMUPS` = extra whole-command invocations before measured samples;
- runner internal warmups = extra in-kernel test runs inside a single sample, only on applied recompile paths.

## 2. Micro: `micro_exec run-llvmbpf`

### What the runner does

`run-llvmbpf` uses a plain userspace loop:

- `repeat = options.repeat` (`micro/runner/src/llvmbpf_runner.cpp:745-746`)
- then `for (index = 0; index < repeat; ++index) vm.exec(...)` for map, packet, and skb paths (`micro/runner/src/llvmbpf_runner.cpp:758-795`).

There is no kernel batching here. This is a userspace loop around the JIT'd function.

### Timing semantics

- For each iteration, the runner does its own timing around `vm.exec(...)` with `rdtsc` or `clock_gettime` fallback (`micro/runner/src/llvmbpf_runner.cpp:758-795`).
- It sums those per-call deltas and reports `sample.exec_ns = total / repeat` (`micro/runner/src/llvmbpf_runner.cpp:883-896`).
- `sample.wall_exec_ns` is the outer wall time of the repeated loop divided by `repeat` (`micro/runner/src/llvmbpf_runner.cpp:896`).

This is exactly the kind of userspace-loop timing that becomes unreliable for 3-20ns code:

- every execution pays loop overhead;
- every execution pays timer/fence overhead in the `rdtsc` path;
- the timing method is asymmetric with the kernel path.

## 3. Micro driver: `ITERATIONS` vs `WARMUPS` vs `REPEAT`

Top-level Makefile defaults:

- `ITERATIONS ?= 10`
- `WARMUPS ?= 2`
- `REPEAT ?= 200`

and these are forwarded to the micro driver as `--iterations`, `--warmups`, `--repeat` (`Makefile:41-43`, `108`).

Python driver behavior:

- It resolves `repeat` per runtime and passes it to `build_micro_benchmark_command(...)` (`micro/_driver_impl_run_micro.py:520-545`).
- It performs `warmups` by re-running the entire command and discarding the result (`micro/_driver_impl_run_micro.py:547-548`).
- It performs `iterations` by re-running the entire command and recording one sample per invocation (`micro/_driver_impl_run_micro.py:557-576`).
- Final summaries are taken over the collected per-sample `exec_ns` values (`micro/_driver_impl_run_micro.py:579-609`).

Command construction:

- `build_runner_command(...)` appends `--repeat N` directly (`micro/orchestrator/commands.py:62-63`).
- `build_micro_benchmark_command(...)` uses `run-llvmbpf` for llvmbpf and `run-kernel` for kernel / kernel-recompile (`micro/orchestrator/commands.py:109-165`).

So, in micro:

- `ITERATIONS` = number of measured samples;
- `WARMUPS` = number of untimed whole-command warmup samples;
- `REPEAT` = inner repeat count inside each sample.

But the meaning of that inner repeat differs by runtime:

- kernel: one syscall with in-kernel repeat, and possibly adaptive up-scaling;
- llvmbpf: fixed userspace loop count.

## 4. Corpus exec-time paths

## 4.1 Packet-backed corpus perf/v5/production drivers

Shared helper:

- `corpus.common.build_run_kernel_command(...)` always builds `micro_exec run-kernel --repeat N` (`corpus/common.py:197-235`).

Packet-vs-context routing:

- `micro/orchestrator/corpus.py` chooses `io_mode="packet"` for `xdp`, `socket`, `classifier`, `tc`, `flow_dissector`, `sk_skb`, `sk_msg`; otherwise it falls back to `context` (`micro/orchestrator/corpus.py:288-306`).

Drivers:

- `corpus/_driver_impl_run_corpus_perf.py` does one baseline timed run and one recompile timed run, each via `run-kernel --repeat repeat` (`corpus/_driver_impl_run_corpus_perf.py:329-378`).
- `corpus/_driver_impl_run_corpus_v5_framework.py` does the same for the 40-program union (`corpus/_driver_impl_run_corpus_v5_framework.py:340-410`).
- `corpus/_driver_impl_run_production_corpus_v5_framework.py` does the same for the production corpus (`corpus/_driver_impl_run_production_corpus_v5_framework.py:529-595`).

Important consequence:

- These timed corpus drivers only measure the `perf_capable` / packet-backed subset.
- For those timed runs, repetition happens in the kernel through `bpf_prog_test_run_opts.repeat`.
- They do not take multiple outer timing samples per program; each variant is usually measured once. So they already fix intra-sample syscall-overhead problems, but they still have inter-sample jitter because there is no median over several measured invocations.

## 4.2 `corpus/run_real_world_exec_time.py`

This script is mixed:

- It builds `micro_exec run-kernel` or `run-llvmbpf` with `--repeat` (`corpus/run_real_world_exec_time.py:212-239`).
- It then runs that command `iterations` times and stores the median `exec_ns` across invocations (`corpus/run_real_world_exec_time.py:363-430`).

For packet-mode programs:

- kernel repetition is inside one syscall, same as micro kernel.

For context-mode programs:

- `run-kernel` disables kernel repeat internally, so each sample is effectively a single test run;
- only the outer `iterations` loop remains.

So this script gives:

- packet programs: kernel-side inner repeat + userspace outer iterations;
- context programs: no kernel repeat, only userspace outer iterations.

## 4.3 Tracing corpus drivers

Tracing is completely different from `bpf_prog_test_run`.

The tracing workload generators are explicit userspace loops, e.g. repeated syscalls, file ops, execs, TCP loopback, etc. (`corpus/_driver_impl_run_corpus_tracing.py:398-520`).

The VM tracing exec driver:

- optionally runs a warmup workload loop (`warmup_repeat`) (`corpus/_driver_impl_run_corpus_tracing_exec.py:1085-1099`);
- runs the workload loop `repeat` times (`1100-1102`);
- computes per-execution time as `run_time_ns_delta / run_cnt_delta` from `bpf_prog_info` (`1106-1123`);
- does baseline and recompile phases this way (`1157-1178`).

So tracing repetition is userspace workload repetition, not `bpf_prog_test_run`.

## 4.4 Macro corpus

Macro corpus has two relevant execution modes:

### `test_method: bpf_prog_test_run`

- Builds `micro_exec run-kernel --repeat N` (`corpus/_driver_impl_run_macro_corpus.py:450-481`).
- Parses `micro_exec` JSON and records `effective_repeat` (`484-510`).

So this mode uses the same kernel-repeat behavior as the normal kernel runner, with the same context-mode exception.

### `test_method: attach_trigger`

- Repeats a shell command in userspace `repeat` times (`corpus/_driver_impl_run_macro_corpus.py:630-649`).
- Reports `exec_ns = total_wall_ns / repeat` (`650-657`).
- Uses that for `attach_trigger` samples (`736-820`).

Driver-level `iterations` and `warmups` then wrap those samples externally (`997-1080`).

## 5. Why ultra-short noise still exists even when kernel repeat is already used

For packet/staged micro kernel runs and packet-backed corpus perf runs, the problem is not "wrongly repeating in userspace". The remaining noise comes from other effects:

### 1. Kernel `duration` is integer-ns average

The kernel stores average duration in a `u32` nanoseconds field after integer division (`vendor/linux-framework/net/bpf/test_run.c:55-59`).

That means:

- 3ns, 4ns, 5ns programs only have 1ns output granularity;
- even perfect repetition cannot remove that quantization;
- a 1ns step is 33% at 3ns, 20% at 5ns, 10% at 10ns.

So sub-10ns measurements will inherently look jumpy.

### 2. Some corpus drivers only take one measured sample

`corpus_perf`, `corpus_v5_framework`, and `production_corpus_v5_framework` typically do one timed baseline sample and one timed recompile sample per target.

Kernel repeat fixes per-execution syscall overhead inside that sample, but it does not eliminate run-to-run jitter across whole samples.

### 3. The llvmbpf comparison path is still a userspace timing loop

If the noise the user is seeing is in llvmbpf-vs-kernel characterization, that suspicion is partly correct:

- kernel path is batched in-kernel;
- llvmbpf path is a per-call userspace loop with per-call timers.

That asymmetry is real and will especially distort 3-20ns programs.

### 4. Context-mode kernel runs do not use kernel repeat

Any `run-kernel` sample that resolves to `io_mode=context` does not benefit from `test_opts.repeat`.

This matters for non-packet corpus programs measured through `run_real_world_exec_time.py` and for any macro-corpus `bpf_prog_test_run` entry that uses context mode.

### 5. Minor code issue: adaptive-repeat threshold is calibrated against the wrong unit

In the current runner, the adaptive probe compares `probe.exec_ns` against `50ns * 10` (`micro/runner/src/kernel_runner.cpp:324-327`).

But `probe.exec_ns` is already an average-per-run value on this kernel, not a 10-run total. So the threshold acts like `500ns average`, not `50ns average`.

This does not cause userspace-loop repetition, but it does mean the kernel runner's adaptive-repeat behavior is not using the intended threshold.

## 6. Recommendation

## Main conclusion

Do not switch the main micro kernel runner or the packet-backed corpus perf/v5/production drivers from userspace looping to kernel repeat. They already use kernel repeat.

## Recommended fixes / next steps

1. Treat the micro `llvmbpf` runner as the main repetition problem for ultra-short programs.
   - Its current timing is a userspace loop with per-call timer overhead.
   - If sub-20ns accuracy matters, measure a whole repeated loop with one timer pair, or add a batched wrapper path, instead of timing each `vm.exec()` separately.

2. Treat `run-kernel` context-mode measurements as a separate accuracy class.
   - They currently do not use `bpf_prog_test_run_opts.repeat`.
   - If those programs matter for ultra-short claims, they need a different measurement strategy.

3. For packet-backed corpus drivers, add outer iterations and use a median.
   - Kernel repeat already fixes the inner-loop problem.
   - What is missing there is multiple measured samples per program, not kernel-side batching.

4. Expose `effective_repeat` in the kernel runner JSON.
   - Right now adaptive repeat is invisible in normal `micro_exec` output.
   - That makes it harder to audit whether a 5/200 repeat request was actually turned into 1500/5000 effective repeats.

5. Fix the adaptive-repeat threshold check in `kernel_runner.cpp`.
   - Compare against average ns directly, not `threshold * probe_repeat`.

6. Be careful interpreting single-digit-ns kernel `exec_ns`.
   - Those numbers are already the best available averaged kernel-side metric in this harness.
   - But they still have 1ns quantization, so a few-ns delta is not a robust standalone signal.
