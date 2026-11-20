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
| `tetragon/observer` | — | — | see below | — |
| `tracee/monitor` | — | — | not yet captured | — |
| `katran` | — | — | not yet captured | — |

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

## Tetragon and the two failures before it

Two Tetragon attempts (`tetragon/`, `tetragon2/`) each served 3 and 4 requests, all `checked-sim-c`, then the
guest ended without writing `service.tar.gz`; both raw directories are kept. A third attempt
(`tetragon3/`, 32 GiB guest) was still running when this file was written. Tracee and Katran are not captured
yet.
