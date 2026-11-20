# Verified-path coverage, measured app by app (OMP 2026-11-20)

Item 4 of the multi-day list: how much of each app's BPF population actually verifies and installs through the
checked path, rather than falling back to direct-native. One capture per app with the frozen entry:

```
make -C kprog/libnativeloader checked-corpus CHECKED_APP=<app> CHECKED_OUTPUT=<dir> CHECKED_HOST_CPUS=<cpus>
```

Base: `/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds`, 478,096 B, built 2026-11-19T23:47Z,
byte-identical to a build of `19d32566c`. Every run exited 0.

| app | requests | programs | installed (checked-sim-c) | fallback (direct-native) |
|---|---|---|---|---|
| `cilium/agent` | 12 | 4 | **12** | 0 |
| `otelcol-ebpf-profiler/profiling` | 14 | 5 | 4 | **10** |
| `bcc/set` | 25 | 15 | 22 | **3** |
| `tetragon/observer` | 95 (3 attempts) | 15 | **95** | 0 |
| `tracee/monitor` | 35 | 3 | **35** | 0 |
| `katran` | 1 | 1 | **1** | 0 |

Capture size varies with the app and the run (12/14/25 here from one command), so only per-program figures
compare; the raw `service.tar.gz` of each capture is kept at the path in `coverage.json`.

## The fallbacks are four separate defect classes, not one

Each rejection below is the verifier's own last two lines from `request/verify.stderr`.

| class | occurrences | verifier message |
|---|---|---|
| stack-pointer arithmetic with no lower bound | 5 (OTel) | `math between fp pointer and register with unbounded min value is not allowed` |
| load/store through a scalar | 4 (OTel), 2 (BCC) | `R1 invalid mem access 'scalar'` |
| context pointer advanced before dereference | 1 (BCC) | `dereference of modified ctx ptr R2 off=30 disallowed` |
| unbounded probe_read | 1 (OTel) | `R1 unbounded memory access, make sure to bounds check any such access` |

Cilium's packet-bounds class, closed on 2026-11-20, does not appear here at all — it is a fifth class and the
only one fixed so far.

## What the stack-pointer class is, and why the existing pass does not cover it

Request 7 of the OTel capture (`526c5a5b`) fails at instruction 3137:

```
3134: r2 = r10            ; R2=fp0
3135: r2 += -128          ; R2=fp-128
3136: r1 = *(u64 *)(r10 - 152)   ; R1=scalar(id=105)
3137: r1 -= r2
      math between fp pointer and register with unbounded min value is not allowed
```

In the retained IR that is `%2027 = sub i64 (ptrtoint %2017), (ptrtoint %13)` followed by
`%2030 = sub i64 24, %2027` (`/tmp` copy: `/tmp/pbt/otel7.ll`, lines 4677-4690). The compiler's existing
`anchor_pointer_differences()` pass does fire on this module (354 differences anchored) and rewrites `%2027` into
an asm `pointer_difference`, but **`sub i64 24, %pointer_difference` is left as an ordinary `sub`**, and that is
the instruction the verifier turns into `r1 -= r2` with `r1` a scalar and `r2` the frame pointer. So the
occurrences the pass does not reach are the ones whose pointer difference feeds a *constant minus difference*.

Not verified: whether anchoring that second form is sufficient to accept, and whether it changes the emitted B at
all for programs that already install. That belongs to whoever owns `kprog/x86/packet_bounds_ir.cpp` (PERF), and
is written to its resume message rather than edited here.

## Tetragon: 95 requests, 95 installed, no guest finished

No Tetragon guest ever wrote `service.tar.gz` (three attempts: `tetragon/`, `tetragon2/`, `tetragon3/`, all raw
directories kept). The service log in each is still complete for what it served, and reading
`state/session-*/service.log` gives: attempt 1 **86 requests / 15 distinct programs**, attempt 2 4/3, attempt 3
5/4 — **95 requests, all `checked-sim-c`, zero fallbacks**. Attempt 1 is the useful one; it is also the reason
this table says "95" and not a per-run number: one attempt reached 15 programs, which is more than any other
app's whole capture here.

The attempts stalled rather than crashed: attempt 3 sat at 0% CPU for 49 minutes after its 5th request. I killed
two *orphaned* guests from attempts 1 and 2 that were still holding 48 GiB and 32 GiB of host memory with their
parent shells gone — worth knowing, since three concurrent Tetragon guests is what made the host thrash.

## Tracee: 35 requests, 35 installed

`tracee/monitor` served 35 requests over 3 distinct programs (`2c83395d`, `4b28662f`, `f0436342`), every one
`checked-sim-c`, zero fallbacks. Its guest hit the same stall as Tetragon — the driver finished, nothing wrote
`service.tar.gz` — so the count is read from `state/session-*/service.log` and the raw directory is kept.

## Katran: one program, installed; the frozen workload needs more than 2 vCPUs

The first attempt errored before any BPF program loaded — the frozen `xdp_pktgen` workload writes
`/proc/net/pktgen/kpktgend_2`, which exists only when the guest has at least 3 vCPUs, and `checked-corpus`
defaults to `CHECKED_VM_CPUS=2`. With `CHECKED_VM_CPUS=8` the capture completes: **1 request, 1 program
(`32c9af3a`), installed via `checked-sim-c`**. Katran loads a single XDP program in this configuration, so one
request is its whole population, not a truncated capture.

That is a real constraint on how this recipe is used, worth recording: any app whose runner needs more vCPUs than
`CHECKED_VM_CPUS` silently produces a capture of zero BPF programs with `exit-code` 0. Katran is the second app
(Tetragon and Tracee were the others) whose guest did not write its archive on its own.

## Summary across the six apps

| app | requests | installed | rate |
|---|---|---|---|
| `cilium/agent` | 12 | 12 | 100 % |
| `tetragon/observer` | 95 | 95 | 100 % |
| `tracee/monitor` | 35 | 35 | 100 % |
| `katran` | 1 | 1 | 100 % |
| `bcc/set` | 25 | 22 | 88 % |
| `otelcol-ebpf-profiler/profiling` | 14 | 4 | 29 % |
| **total** | **182** | **169** | **93 %** |

Every fallback in the whole set belongs to two apps (OTel 10, BCC 3) and to the four classes listed above.
