# test-others — kprobe / uprobe / raw_tracepoint POC

Standalone test folder. **Does not use the bench micro framework** — no
`make micro`, no yaml suite, no `driver.py`. Just clang + libbpf + a
single C harness that loads each `.bpf.o`, attaches the probe, triggers
it, and reads back the count from a single-slot `count_map`.

## Programs

| program | section | trigger |
|---|---|---|
| `kprobe_getpid` | `kprobe/__x64_sys_getpid` | harness calls `getpid()` 100× |
| `uprobe_self` | `uprobe` (attached to `uprobe_target` in `runner` binary) | harness calls `uprobe_target(i)` 100× |
| `tracepoint_sched_switch` | `raw_tp/sched_switch` | harness calls `sched_yield()` 100× (count is >=100, other CPUs add to it) |

Each program counts entries into a 1-slot `BPF_MAP_TYPE_HASH` keyed by 0.

## Build + run

```
cd ebpf-vm/test-others
make             # produces build/{kprobe_getpid,uprobe_self,tracepoint_sched_switch}.{bpf,native}.o + build/runner
sudo make test   # runs all three; needs root for kprobe / uprobe / raw_tp attach
```

Or invoke directly:

```
sudo ./build/runner build/kprobe_getpid.bpf.o            kprobe
sudo ./build/runner build/uprobe_self.bpf.o              uprobe
sudo ./build/runner build/tracepoint_sched_switch.bpf.o  raw_tp
```

Expected output:

```
kprobe_getpid    kernel: count=100 expected=100  OK
uprobe_self      kernel: count=100 expected=100  OK
raw_tp_sched_sw  kernel: count=N>=100 expected>=100  OK
```

## native_lab status

Each `.bpf.c` is compiled twice by the Makefile: once with
`-target bpf` (the canonical kernel-JIT input, what libbpf consumes
above) and once with `-target x86_64 -fno-plt -DMICRO_NATIVE` (the
input that `native-link` and the `bpf_x86_native_lab` kinsn would
splat into the JIT image to run as native x86). The runner above only
exercises the kernel-JIT side; running these on native_lab would need
two pieces:

- **Attach pipeline.** The current `runner/src/native_lab_runner.cpp`
  only wires up `BPF_PROG_TEST_RUN` for `xdp` / `sched_cls` /
  `cgroup_skb`. kprobe / uprobe / raw_tp programs are not driven by
  `TEST_RUN`; they are attached to a kernel event via
  `perf_event_open(PERF_TYPE_TRACEPOINT, ...)` followed by
  `PERF_EVENT_IOC_SET_BPF`, or via `bpf_raw_tracepoint_open(2)`.
  Adding this path is a runner change, not a kinsn-module change —
  the kinsn doesn't care about how the program got attached, only
  about what `prog_type` was passed to `BPF_PROG_LOAD`.

- **`prog_type_from_option` plumbing.** Extend the enum in
  `native_lab_runner.cpp` (currently `xdp | sched_cls | cgroup_skb`)
  to accept `kprobe | uprobe | raw_tracepoint`, and gate the
  `bpf_test_run` invocation off when the prog_type is event-driven.

Both pieces are mechanical extensions of the existing Stage 2 pipeline
and intentionally scoped out of this POC, which only answers the
upstream question: do the source programs themselves compile and run
under the kernel JIT? See the runner output above for the answer.
