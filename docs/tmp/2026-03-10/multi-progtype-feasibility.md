# Multi-Program-Type Benchmark Feasibility

Generated: 2026-03-11

## Executive Summary

- `tc` is the easiest non-XDP expansion. The current `run-kernel` path already executes real `tc/ingress` programs via `bpf_prog_test_run_opts()` when invoked in `packet` mode.
- `cgroup_skb` is also feasible now. The current kernel runner can already execute a real `cgroup_skb/ingress` direct-packet-access program in `packet` mode on this machine. The bigger gap is that the benchmark macros, config defaults, and corpus scripts still assume XDP conventions.
- `fentry` is not a drop-in extension of the XDP harness. `BPF_PROG_TEST_RUN` for tracing programs does not behave like packet test-run: no packet/context IO, no kernel-reported duration, and meaningful execution only for programs attached to the kernel’s `bpf_fentry_test*` / `bpf_modify_return_test` targets.
- For the paper’s paired `llvmbpf` vs kernel suite, kernel-side support is not the only blocker. The userspace JIT runner still hardcodes an `xdp_md` packet context, so non-XDP paired execution needs extra work even if `run-kernel` is ready.

## Context From The Current Repo

The current micro suite is XDP-shaped in three separate layers:

1. The benchmark wrappers in `micro/programs/common.h` are all `SEC("xdp")`, take `struct xdp_md *`, and use XDP return codes. They also assume result extraction through packet bytes or `result_map`.
2. The suite manifest says the default benchmark `io_mode` is `staged`, and the manifest header explicitly describes “result returned via XDP packet”.
3. The benchmark catalog only models `io_mode` and `kernel_input_size`; there is no `result_mode`, `ctx_mode`, or explicit `prog_type` hint in the suite schema.
4. The kernel runner accepts generic ELF program types, but its execution/result plumbing still assumes four generic modes (`map`, `staged`, `packet`, `context`) rather than program-type-aware semantics.

Important local details:

- `load_program_image()` already records `prog_type` and `expected_attach_type`, and falls back to `libbpf_prog_type_by_name()` if needed. This means the loader is not XDP-only.
- `run_kernel()` does not branch on `prog_type` when building `bpf_test_run_opts`; it only branches on `io_mode`.
- `packet` and `staged` modes always read the benchmark result from the first 8 bytes of `data_out`.
- `context` mode forces `repeat = 0` in the kernel API and treats `retval` as the benchmark result.
- `parse_args()` only recognizes those four `io_mode` values, so any cleaner skb- or tracing-specific mode will require a small CLI/schema extension.

## 1. Current Runner Limitations

### 1.1 What already works

The current kernel runner is more general than the current benchmark suite:

- Load path: already generic. `program_image.prog_type` and `expected_attach_type` are preserved and used for both normal load and manual `BPF_PROG_LOAD`.
- Execution path: `bpf_prog_test_run_opts()` will dispatch by program type inside the kernel, so `run-kernel` is not intrinsically tied to XDP.

That means `kernel_runner.cpp` does not need a new loader for `tc` or `cgroup_skb`.

### 1.2 What is still XDP-centric

The limitations are in setup and result extraction, not program loading:

| Area | Current behavior | Why it is a problem beyond XDP |
| --- | --- | --- |
| Result path | `packet`/`staged` always read `u64` from the first 8 bytes of `packet_out` | This is an XDP benchmark convention, not a generic skb/tracing convention |
| Mode selection | Only `io_mode` controls behavior | The right setup depends on `prog_type`, not only on whether the caller said `packet` or `context` |
| `context` repeat handling | `io_mode == "context"` forces `effective_repeat = 1` and `test_opts.repeat = 0` | This is wrong for any future context-carrying program type that still supports kernel repeat |
| skb metadata | No first-class support for building `struct __sk_buff` `ctx_in`/`ctx_out` in packet modes | Needed for benchmarks that intentionally read or mutate skb metadata |
| Corpus orchestration | `cgroup_skb` is not classified as packet-based in `run_corpus_perf.py` or `run_production_corpus_v5_framework.py` | Existing scripts will incorrectly choose `context` mode and report false failures |

### 1.3 What `bpf_prog_test_run` does for each relevant program type

| Program type | Kernel handler | Userspace inputs | Repeat / duration | Practical meaning for this repo |
| --- | --- | --- | --- | --- |
| XDP | `bpf_prog_test_run_xdp()` | `data_in` packet, optional `ctx_in` as `struct xdp_md` | Yes / yes | Matches the current XDP micro suite |
| `tc` (`BPF_PROG_TYPE_SCHED_CLS` / `SCHED_ACT`) | `bpf_prog_test_run_skb()` | `data_in` packet, optional `ctx_in` as `struct __sk_buff`, optional `ctx_out` | Yes / yes | Already works with `packet` mode |
| `cgroup_skb` | `bpf_prog_test_run_skb()` | Same userspace API shape as `tc`: `data_in` packet, optional `ctx_in`/`ctx_out` `struct __sk_buff` | Yes / yes | Already works with `packet` mode on this machine |
| `fentry` / `fexit` / `fmod_ret` | `bpf_prog_test_run_tracing()` | No useful packet/context input path | No meaningful kernel timing / no meaningful repeat | Needs a dedicated measurement strategy |

Kernel-source notes:

- `bpf_prog_test_run_skb()` constructs an skb from `data_in`, optionally converts a user `struct __sk_buff`, runs `repeat`, and returns packet bytes plus `retval` and `duration`.
- For `tc`, the kernel test-run path explicitly enables L2 framing and direct packet access setup.
- `bpf_prog_test_run_tracing()` does not call the program on arbitrary hook targets. It triggers the built-in `bpf_fentry_test1..8` or `bpf_modify_return_test` helpers and only copies out `retval`.

### 1.4 Concrete local smoke tests

I ran the current runner against existing in-repo selftest objects on kernel `6.15.11-061511-generic`.

#### `cgroup_skb`

Program:

- Object: `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.tmp.o`
- Program: `direct_packet_access`
- Section: `cgroup_skb/ingress`

Observed behavior:

- `run-kernel --io-mode packet --raw-packet` succeeds.
- `run-kernel --io-mode context` fails with `EINVAL`.

Implication:

- `cgroup_skb` is not blocked by `kernel_runner.cpp`.
- The current corpus scripts are choosing the wrong mode for `cgroup_skb`.

#### `tc`

Program:

- Object: `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.tmp.o`
- Program: `change_tail`
- Section: `tc/ingress`

Observed behavior:

- `run-kernel --io-mode packet --raw-packet` succeeds.

Implication:

- `tc` is already runnable through the current kernel runner.

### 1.5 Minimum `kernel_runner.cpp` changes

Strictly speaking, the minimum change for basic `tc` / `cgroup_skb` execution is:

- No load-path change.
- Possibly no execution-path change if the new benchmarks use `result_map` or the existing packet-prefix result convention.

But for clean first-class support, the minimum worthwhile patch is:

1. Make result extraction explicit instead of coupling it to `io_mode`.
   Suggested modes: `packet_u64_prefix`, `result_map`, `retval`.
2. Make repeat handling program-type-aware.
   Only tracing-like paths should bypass kernel repeat.
3. Add optional skb metadata buffers.
   Support `ctx_in` and `ctx_out` in packet modes for `__sk_buff` programs.
4. Update corpus execution-plan helpers so `cgroup_skb` is treated like packet-backed skb, not like generic context-only.
5. Extend the suite schema if we want first-class multi-hook manifests.
   The cleanest additions are `result_mode` and either `ctx_mode` or `program_family`.

## 2. `cgroup_skb` Feasibility

### 2.1 Can we use the same `DEFINE_STAGED_INPUT_XDP_BENCH` pattern with `SEC("cgroup_skb/egress")`?

Conceptually yes. Textually as-is, no.

The reusable part is the benchmark body:

- `BENCH_FN(input->data, INPUT_SIZE, &result)`
- `input_map` lookup
- optional `result_map` writeback

The XDP-specific parts that must change are:

- section: `SEC("xdp")` -> `SEC("cgroup_skb/egress")` or `SEC("cgroup_skb/ingress")`
- context type: `struct xdp_md *` -> `struct __sk_buff *`
- return codes: `XDP_PASS` / `XDP_ABORTED` are wrong for `cgroup_skb`
- packet result channel: writing the result into `ctx->data` is optional, not required

Practical recommendation:

- Do not reuse the XDP macro by search-and-replace.
- Introduce a new `DEFINE_STAGED_INPUT_CGROUP_SKB_BENCH(...)` macro family that shares the `BENCH_FN` contract and `input_map` layout but uses `struct __sk_buff *` and a non-XDP return convention.

### 2.2 What `ctx_in` / `ctx_size` changes are needed?

For a staged map-backed compute benchmark that only uses `input_map`:

- None are required.
- `bpf_prog_test_run_skb()` is happy with `ctx_in = NULL` when the program does not need skb metadata.

For a benchmark that intentionally reads skb metadata:

- Provide `ctx_in` as a zeroed `struct __sk_buff`.
- Size it to at least the last field you want to populate.
- Leave all unsupported fields zero.

Important kernel constraint:

- The skb test-run path only accepts a narrow set of user-initialized `__sk_buff` fields: `mark`, `priority`, `ifindex`, `cb[]`, `tstamp`, `wire_len`, `gso_segs`, `gso_size`.
- Everything else in `ctx_in` must remain zero or the kernel will reject the test run with `-EINVAL`.

What comes from `data_in` versus `ctx_in`:

- Packet bytes come from `data_in`.
- skb metadata comes from `ctx_in`.
- So a simple staged-input benchmark can ignore `ctx_in` entirely.

### 2.3 Is input staging via map still possible?

Yes.

This is the cleanest part of the whole port:

- `input_map` lookup is program-type-agnostic.
- `bpf_map_lookup_elem(&input_map, &key)` works exactly the same for `cgroup_skb`.
- `result_map` is also program-type-agnostic.

In fact, for `cgroup_skb`, map-backed result output is the safest design:

- It avoids depending on packet-byte writeback as a result channel.
- It avoids overloading skb packet access just to report a 64-bit synthetic benchmark result.
- It makes the wrapper look almost identical to `DEFINE_MAP_BACKED_XDP_BENCH`, except for context type and return value.

### 2.4 Recommended `cgroup_skb` wrapper shape

Recommended pattern:

1. Keep the current `BENCH_FN(const u8 *data, u32 len, u64 *result)` functions unchanged.
2. Reuse the same `input_map` layout.
3. Use `result_map` for output.
4. Return the hook’s normal allow/drop value.

Pseudo-shape:

```c
SEC("cgroup_skb/egress")
int bench_name(struct __sk_buff *skb)
{
    struct input_value *input;
    __u32 key = 0;
    __u64 result = 0;

    input = bpf_map_lookup_elem(&input_map, &key);
    if (!input)
        return 0;
    if (BENCH_FN(input->data, INPUT_SIZE, &result) < 0)
        return 0;

    bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);
    return 1;
}
```

This is the lowest-risk path for `cgroup_skb`.

## 3. `fentry` Feasibility

### 3.1 What `BPF_PROG_TEST_RUN` actually does for `fentry`

`fentry` / `fexit` / `fmod_ret` use the tracing test-run path, which is fundamentally different from packet test-run:

- no useful `data_in` / `data_out`
- no useful `ctx_in` / `ctx_out`
- no kernel-populated `duration`
- no kernel-side `repeat`
- meaningful execution only for programs attached to the kernel’s `bpf_fentry_test*` or `bpf_modify_return_test` targets

This is also how the kernel selftests use it:

- the selftest BPF programs attach to `fentry/bpf_fentry_test1`, `...test2`, etc.
- the selftest user code calls `bpf_prog_test_run()` and then checks BSS side effects

### 3.2 Can we still measure execution time?

Yes, but not with the current XDP-style assumption that `test_opts.duration` is the answer.

Current repo behavior:

- `run_kernel()` uses `test_opts.duration` first.
- If `duration == 0`, it falls back to wall-clock TSC timing around the whole syscall.
- Because `context` mode forces `repeat = 1`, a tracing run currently reports only one syscall-sized wall-time sample.

So the current runner can produce a nonzero number for `fentry`, but that number is:

- not pure kernel BPF execution time
- not averaged over many kernel repetitions
- and, for arbitrary targets like `fentry/do_unlinkat`, not evidence that the intended program body ran under test-run at all

### 3.3 Recommended workarounds

There are three realistic options.

#### Option A: userspace repeat loop around `bpf_prog_test_run_opts()`

How it works:

- call tracing `test_run` N times in a loop in `kernel_runner.cpp`
- time the full loop with TSC or `steady_clock`
- divide by N

Pros:

- minimal code change
- stays inside `micro_exec run-kernel`

Cons:

- includes syscall overhead and test-run framework overhead
- still only makes sense for programs attached to `bpf_fentry_test*`

How to make it defensible:

- pair each benchmark with a trivial baseline `fentry` program on the same target
- subtract the baseline to isolate the benchmark body as much as possible

#### Option B: attach + trigger + read `run_cnt` / `run_time_ns`

How it works:

- load and attach the `fentry` program normally
- trigger the target function many times
- read `run_cnt` and `run_time_ns` from `bpf_prog_info`

Pros:

- measures real attached execution
- already matches the repo’s tracing strategy in `micro/run_corpus_tracing.py`

Cons:

- more harness work
- less “isolated microbench” than XDP test-run

This is the cleanest measurement path if the paper wants a strong tracing story.

#### Option C: patch the kernel tracing test-run path

How it works:

- extend `bpf_prog_test_run_tracing()` to support repeat and duration

Pros:

- best microbenchmark semantics

Cons:

- kernel patch required
- evaluation is no longer “stock kernel test-run”

### 3.4 What would a `fentry` benchmark program look like?

It should not look like an XDP or skb wrapper.

Recommended shape:

- target the selftest hooks: `SEC("fentry/bpf_fentry_test1")`, etc.
- use `BPF_PROG(...)` to get typed function arguments
- use `input_map` and `result_map`
- ignore the hook arguments unless the benchmark is intentionally about BTF argument access

Example shape:

```c
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} result_map SEC(".maps");

SEC("fentry/bpf_fentry_test1")
int BPF_PROG(fentry_bench, int a)
{
    __u32 key = 0;
    struct input_value *input = bpf_map_lookup_elem(&input_map, &key);
    __u64 result = 0;

    if (!input)
        return 0;
    if (bench_fn(input->data, INPUT_SIZE, &result) < 0)
        return 0;

    bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);
    return 0;
}
```

This shares the compute core and map layout with the XDP suite, but not the wrapper macro.

## 4. `tc` Feasibility

### 4.1 How similar is `tc` to `cgroup_skb`?

Very similar at the syscall interface:

- both use `struct __sk_buff`
- both run through `bpf_prog_test_run_skb()`
- both use `data_in` packet bytes and optional skb metadata in `ctx_in`

`tc` is actually easier than `cgroup_skb` for this repo because the kernel test-run path explicitly handles tc as:

- L2-framed
- direct-packet-access enabled

That makes tc the closest non-XDP analogue to the current XDP microbench harness.

### 4.2 Can tc reuse the staged-input macro structure?

Yes, with minimal changes.

A new `DEFINE_STAGED_INPUT_TC_BENCH(...)` wrapper can reuse:

- the same `BENCH_FN`
- the same `input_map`
- optionally the same packet-prefix result trick

Needed changes:

- `SEC("xdp")` -> `SEC("tc")` or `SEC("tc/ingress")`
- `struct xdp_md *` -> `struct __sk_buff *`
- XDP return codes -> `TC_ACT_OK` or another tc return code

If we want the least-risk design, tc should also use `result_map` output instead of packet-prefix output. But unlike `cgroup_skb`, tc can keep the packet-prefix output model if we want to stay close to the current staged XDP harness.

### 4.3 Test-run interface summary

For tc:

- `data_in`: packet bytes starting at Ethernet header
- `data_out`: mutated packet bytes
- `ctx_in`: optional `struct __sk_buff`
- `ctx_out`: optional updated `struct __sk_buff`
- `retval`: tc action code
- `duration`: average per-repeat runtime from the kernel

So tc is the best first extension if the goal is “minimal framework disturbance”.

## 5. Recommended Implementation Plan

### 5.1 Which program types can share the existing macro infrastructure with minimal changes?

| Program type | Share `BENCH_FN`? | Share `input_map` / `result_map`? | Share wrapper style? | Recommendation |
| --- | --- | --- | --- | --- |
| `tc` | Yes | Yes | Mostly | Add a `__sk_buff` tc wrapper family |
| `cgroup_skb` | Yes | Yes | Mostly | Add a `__sk_buff` cgroup wrapper family, prefer `result_map` output |
| `fentry` | Yes | Yes | No | Add a tracing-specific wrapper family based on `BPF_PROG(...)` |

### 5.2 Minimum change to `kernel_runner.cpp` for a new program type

There are two different answers depending on how strict “support” means.

#### Absolute minimum

For `tc` and `cgroup_skb`:

- no loader change
- maybe no runner change if the benchmark uses `result_map` and the caller chooses `io_mode=packet` or `io_mode=map` correctly

This is already enough to run real `tc` and `cgroup_skb` objects today.

#### Minimum worthwhile change

To make the system maintainable and paper-ready:

1. Add `result_mode`.
   Values: `packet_u64_prefix`, `result_map`, `retval`.
2. Stop using `io_mode == "context"` as a proxy for “kernel repeat unsupported”.
   Gate that behavior by program type or by a new execution mode.
3. Add optional `ctx_in` / `ctx_out` support for skb packet modes.
4. Make `run_corpus_perf.py` and `run_production_corpus_v5_framework.py` classify `cgroup_skb` as packet-backed skb, not generic context.

### 5.3 Priority order

#### Priority 1: `tc`

Why first:

- already runnable in the current kernel runner
- same `bpf_prog_test_run_skb()` path as `cgroup_skb`
- best fit with current packet-oriented methodology
- lowest implementation risk

Concrete deliverable:

- add 2 to 4 tc microbenchmarks
- either packet-backed or staged-input-map with `result_map`

#### Priority 2: `cgroup_skb`

Why second:

- also already runnable in the current kernel runner
- same compute bodies and map layouts as tc
- good reviewer-facing breadth win because it is clearly not XDP

Concrete deliverable:

- add 2 `cgroup_skb` benchmarks
- prefer staged-input-map + `result_map`
- update corpus execution plans so `cgroup_skb` stops being misclassified

#### Priority 3: `fentry`

Why third:

- strongest non-networking breadth signal
- but requires a dedicated measurement story

Concrete deliverable:

- build synthetic `fentry/bpf_fentry_test*` benchmarks
- measure either with attach+trigger plus `run_cnt` / `run_time_ns`, or with a runner-side userspace repeat loop

### 5.4 Suggested staged rollout

#### Phase A: low-risk breadth win

1. Add new wrapper macros:
   `DEFINE_STAGED_INPUT_TC_BENCH`
   `DEFINE_MAP_BACKED_TC_BENCH`
   `DEFINE_STAGED_INPUT_CGROUP_SKB_BENCH`
   `DEFINE_MAP_BACKED_CGROUP_SKB_BENCH`
2. Add a few `tc` and `cgroup_skb` programs that reuse existing `BENCH_FN` bodies.
3. Fix `cgroup_skb` handling in corpus scripts.
4. Decide whether to add `result_mode` to `micro/benchmark_catalog.py` or keep separate manifests per hook family.

This is enough to answer “all 62 benchmarks are XDP” with real additional program types.

#### Phase B: tracing expansion

1. Add tracing-specific wrapper macros for `fentry`.
2. Use `bpf_fentry_test*` targets.
3. Reuse the tracing measurement approach already present in `micro/run_corpus_tracing.py`, or teach `run-kernel` an explicit tracing-repeat mode.

#### Phase C: full paired suite

If the paper still wants paired `llvmbpf` vs kernel execution numbers for non-XDP types:

1. extend `micro/runner/src/llvmbpf_runner.cpp` with a `__sk_buff` context model for `tc` / `cgroup_skb`
2. decide whether tracing stays kernel-only or gains a synthetic userspace-side trampoline model

## 6. Important Constraint Outside The Asked Questions

Even if `run-kernel` is ready, the current `llvmbpf` runtime is still XDP-centric.

Why this matters:

- `llvmbpf_runner.cpp` defines only an `xdp_md_ctx` packet context.
- All packet-mode execution in the userspace JIT runner passes that XDP-shaped context to the VM.
- There is no `__sk_buff` model and no tracing-call model.

Implication:

- `tc` / `cgroup_skb` / `fentry` can be added to the kernel-side benchmark suite now.
- But a fully paired `llvmbpf` vs kernel execution benchmark across those program types needs additional userspace-runner work.

For the paper, this suggests two acceptable near-term strategies:

1. Add kernel-only breadth benchmarks for new program types, while keeping the main paired execution story centered on XDP.
2. Extend `llvmbpf_runner.cpp` for `__sk_buff` and treat `fentry` as a separate tracing-evaluation track.

## 7. Bottom Line

### Direct answers

1. `kernel_runner.cpp` does not need a new loader for `tc` or `cgroup_skb`; it already carries `prog_type` through. The real changes are result-mode cleanup, skb metadata plumbing, and fixing `cgroup_skb` mode selection in higher-level scripts.
2. `cgroup_skb` can reuse the current benchmark compute cores and map-staging pattern, but not the XDP wrapper macro verbatim. Use a new `__sk_buff` wrapper and prefer `result_map` output.
3. `fentry` is feasible only with a dedicated tracing benchmark shape and measurement method. `BPF_PROG_TEST_RUN` there is useful for `bpf_fentry_test*`-attached synthetic programs, not as a generic arbitrary-hook microbenchmark facility.
4. `tc` is the easiest next hook family and should be implemented first.
5. Best priority order: `tc` -> `cgroup_skb` -> `fentry`.

## External Kernel Sources Consulted

- Linux kernel docs, `Running BPF programs from userspace`:
  `https://docs.kernel.org/6.2/bpf/bpf_prog_run.html`
- Linux kernel source, `net/bpf/test_run.c`:
  `https://android.googlesource.com/kernel/common/+/201d5f4a3ec1/net/bpf/test_run.c`
- Linux kernel source, `net/core/filter.c`:
  `https://android.googlesource.com/kernel/common/+/refs/tags/android14-6.1-2025-05_r7/net/core/filter.c`
- Linux kernel selftest tracing program:
  `https://android.googlesource.com/kernel/common/+/201d5f4a3ec1/tools/testing/selftests/bpf/progs/fentry_test.c`
- Linux kernel selftest tracing test runner:
  `https://android.googlesource.com/kernel/common/+/201d5f4a3ec1/tools/testing/selftests/bpf/prog_tests/fentry_fexit.c`
