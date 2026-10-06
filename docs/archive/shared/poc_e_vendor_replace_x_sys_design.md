# PoC-E: Go vendor-replace hook for x/sys/unix

This is a design-only document. It is based on static source inspection and does not report a build or runtime experiment.

## 1. Goal and non-goals

Goal: cover the three static Go corpus binaries that are not reached by the current LD_PRELOAD shim path:

- `cilium-agent`
- `tetragon`
- `otelcol-ebpf-profiler`

These are part of the active macro app suite (`corpus/config/macro_apps.yaml:4-13`). The current C shim README reports 5 of 7 corpus apps observable through LD_PRELOAD and calls out `tetragon` and `cilium-agent` as static Go binaries that are physically incompatible with LD_PRELOAD (`bpfopt/shim/README.md:43-68`). OTel is also a Go binary in the current runtime image, downloaded as `otelcol-ebpf-profiler` in `runner/containers/runner-runtime.Dockerfile:275-286`, so PoC-E treats it as the third Go-static target even though the Phase 1 survey table did not list it separately.

The functional goal is the same Phase 2 swap path planned for the C shim: observe program loads and attach surfaces, dump original bytecode, run `bpfopt`, load the candidate, swap the attachment, and record the logical old/new program mapping. The C shim README defines that Phase 2 pipeline in `bpfopt/shim/README.md:113-124`, and the paper-line hub describes the stock-kernel direction as userspace-guided BPF-to-BPF rewriting of already-loaded programs (`docs/rejit-speculative-optimization-ebpf.md:21-26`).

Non-goals:

- Covering `bpftrace`, `bcc`, `tracee`, or `katran`. They are already in the LD_PRELOAD lane for this PoC. The shim survey reports bpftrace, BCC examples, Tracee, and Katran as dynamic or preload-compatible in `bpfopt/shim/README.md:50-68`.
- Fully atomic swap. The existing shim design accepts a microsecond-scale detach/reattach gap (`bpfopt/shim/README.md:132-138`).
- Preserving kernel `prog_id`. Stock userspace candidate loads create new program ids, and runner/result mapping must use logical ids (`docs/tmp/userspace_speculative_opt_design.md:221-230`).
- Covering pre-built upstream binaries. PoC-E requires rebuilding each Go app from source with a replaced `golang.org/x/sys` module. It cannot instrument an opaque static binary without ptrace, binary rewriting, Frida, or a similar runtime injection mechanism.

## 2. Why vendor-replace over ptrace, e9patch, or Frida

Vendor-replace means the app still starts as the real upstream application, but its module graph points `golang.org/x/sys` at a small fork with a syscall hook. That is a source-level instrumentation patch, not a loader replacement.

Benefits:

- One code path for x86_64 and arm64. The hook lives in Go and in a tiny per-architecture `x/sys/unix` syscall wrapper patch. e9patch-style binary rewriting is x86_64-centered and would need a separate arm64 strategy.
- No syscall-instruction scanning. The current PoC-C v1 design listed raw-syscall hotpatching as the old Go path (`docs/tmp/poc_c_bpf_syscall_shim_design.md:172-189`). PoC-E avoids symbol-offset and instruction-pattern discovery.
- Better tolerance of Go runtime ABI changes. The x/sys public syscall declarations are stable at the level this design needs: `Syscall`, `Syscall6`, `RawSyscall`, and `RawSyscall6` are declared with uintptr arguments and `syscall.Errno` return in x/sys v0.42.0 (`golang.org/x/sys/unix/syscall_unix_gc.go:11-14`, upstream: https://github.com/golang/sys/blob/v0.42.0/unix/syscall_unix_gc.go#L11-L14). The amd64 and arm64 assembly currently just jump to the standard library syscall implementations (`asm_linux_amd64.s:13-20`, https://github.com/golang/sys/blob/v0.42.0/unix/asm_linux_amd64.s#L13-L20; `asm_linux_arm64.s:9-16`, https://github.com/golang/sys/blob/v0.42.0/unix/asm_linux_arm64.s#L9-L16).
- Auditable patch surface. The fork can be a small, rebased delta on top of an upstream x/sys tag. Reviewers can inspect the exact hook and the few generated wrappers it touches.

Gray area against the app-level loader rule:

- The repository rule says benchmark apps must load BPF through real app startup and must not be replaced by custom loader binaries (`CLAUDE.md:12-13`). PoC-E does not load `.bpf.o` files from the framework and does not introduce a replacement loader binary.
- It does rebuild the real app with an instrumentation dependency, so it is not identical to the upstream image. This is closer to an observability/instrumentation build than a custom loader, but it must be documented in any paper artifact. The rebuilt binary sha256 will differ from quay/GitHub release binaries, and source access is required.

## 3. Fork design for golang.org/x/sys/unix

Patch target: fork `golang.org/x/sys` at the exact version used by each app, then add a syscall hook around the exported Linux syscall entry points.

Current versions:

- Cilium local checkout: `github.com/cilium/ebpf v0.21.0` and `golang.org/x/sys v0.42.0` in `runner/repos/cilium/go.mod:22,117`; matching checksums are in `runner/repos/cilium/go.sum:126-127,915-916`.
- OTel local checkout: `github.com/cilium/ebpf v0.21.0` and `golang.org/x/sys v0.42.0` in `runner/repos/opentelemetry-ebpf-profiler/go.mod:17,48`; matching checksums are in `runner/repos/opentelemetry-ebpf-profiler/go.sum:41-42,224-225`.
- Tetragon v1.6.1: `github.com/cilium/ebpf v0.20.0` and `golang.org/x/sys v0.39.0` in upstream `go.mod` (https://github.com/cilium/tetragon/blob/v1.6.1/go.mod#L1-L44). Its upstream `go.sum` pins those modules at lines 37-38 and 463-464 in the raw v1.6.1 file.

Files to patch:

- Primary hook files: replace the assembly jump-only definitions of `Syscall` and `Syscall6` for Linux gc builds on `amd64` and `arm64`. Today they are in `unix/asm_linux_amd64.s` and `unix/asm_linux_arm64.s` and jump directly to `syscall.Syscall` / `syscall.Syscall6` (`asm_linux_amd64.s:16-20`, `asm_linux_arm64.s:12-16`).
- Optional generated-wrapper audit: `zsyscall_linux_amd64.go`, `zsyscall_linux_arm64.go`, and shared `zsyscall_linux.go`. Generated wrappers already call `Syscall` or `Syscall6`, for example amd64 and arm64 `fanotifyMark` call `Syscall6` at lines 17-18 of their generated files, `ioctl` calls `Syscall` in shared `zsyscall_linux.go:55-67`, and `PerfEventOpen` calls `Syscall6` in `zsyscall_linux.go:1335-1341`. Because wrappers already funnel through `Syscall`/`Syscall6`, the minimal patch should not edit all generated files. The audit exists to catch any direct raw syscall escape.
- Raw syscall policy: do not hook `RawSyscall` / `RawSyscall6` at first unless an app audit finds a BPF-relevant path using them. OTel has a ptrace `RawSyscall6` in `runner/repos/opentelemetry-ebpf-profiler/process/debug_linux.go:32`, which is not a BPF load/attach path. If a BPF path uses raw syscalls, PoC-E must either hook raw syscall too or declare the app unsupported by this approach.

Hook entry point:

```go
package unix

import "sync/atomic"

var syscallHook atomic.Pointer[func(
    num uintptr,
    a1, a2, a3, a4, a5, a6 uintptr,
) (r1, r2 uintptr, intercept bool)]
```

Semantics:

- `intercept=false`: fall through to the real syscall.
- `intercept=true`: return `(r1, r2)` to the caller without issuing the real syscall.

The requested ABI has no errno return. That is enough for pass-through observation and for interception paths that return successful synthetic results, but active failure synthesis would need an extended ABI:

```go
var syscallHookV2 atomic.Pointer[func(
    num uintptr,
    a1, a2, a3, a4, a5, a6 uintptr,
) (r1, r2 uintptr, errno syscall.Errno, intercept bool)]
```

PoC-E should start with the requested ABI and keep interception conservative. If the hook needs to reject or emulate failed syscalls, promote to the errno-carrying ABI before implementation.

Hot path:

- Use `atomic.Pointer` so the normal app path is a load, nil check, and branch.
- Do not lock in `Syscall`/`Syscall6`.
- The handler must use a recursion guard before it performs internal syscalls, mirroring the C shim's `in_shim` behavior around syscall interception (`bpfopt/shim/libbpfrejit_shim.c:491-535`).

Fork naming and replacement:

- Preferred fork module path: `github.com/bpfrejit/sys` with module path kept as `golang.org/x/sys` only if the fork repository supports that. Go `replace` can map the module path to a fork URL:

```go
replace golang.org/x/sys => github.com/bpfrejit/sys v0.42.0-bpfrejit.1
```

- Alternative monorepo local replace during development:

```go
replace golang.org/x/sys => ../../bpfopt/go-forks/sys
```

Tag strategy:

- Cilium and OTel use one fork tag based on x/sys v0.42.0, for example `v0.42.0-bpfrejit.1`.
- Tetragon v1.6.1 either uses a second fork tag based on x/sys v0.39.0, for example `v0.39.0-bpfrejit.1`, or first updates Tetragon's module graph to v0.42.0 and vendors that change. The safer first PoC is a v0.39.0 fork for Tetragon, because it minimizes unrelated dependency churn.
- Every rebase must be a tiny patch on top of a specific upstream tag, with a changelog entry listing changed files.

## 4. Hook handler library — thin cgo forwarding to the C shim (decided)

**Decision**: the Go hook package is a thin cgo wrapper that forwards every
intercepted call to the existing C shim under `bpfopt/shim/`. No state tables,
no bytecode hashing, no JSON serialization, no socket serving in Go. Single
source of truth for all handler logic stays in C.

This avoids:
- duplicating 1000+ lines of state machinery in Go
- behavior drift between the LD_PRELOAD path and the Go vendor-replace path
- maintaining two implementations of the same swap recipe

Cost paid: each app that pulls in the Go hook package gets cgo, which forces
a libc dependency on the resulting binary. Tetragon and otel-profiler are
currently linked dynamically against glibc/musl (verify per app); cilium-agent
is statically linked but cgo support is preserved through static-pie or
internal libc. Each per-app integration must validate that the build chain
allows cgo.

### Package layout

```
bpfopt/go-hook/
  bpfrejit-go-hook.go    # cgo wrapper, ~50-100 LOC
  cgo.go                 # build tags + cgo directives
  go.mod
```

The package depends at link time on a static library produced by the C shim:

```
bpfopt/shim/
  libbpfrejit_shim_handler.a   # static archive built by `make handler-static`
  bpfrejit_shim_export.h       # exported entry signatures, ~30 LOC
```

### Exported C ABI (declared in `bpfrejit_shim_export.h`)

```c
/* Single entry point. Internally dispatches by syscall number and on success
 * runs the same handler that the LD_PRELOAD `syscall()` interposer runs. */
void bpfrejit_handle_syscall(
    long num,
    long a1, long a2, long a3, long a4, long a5, long a6,
    long *out_r1,        /* primary return value */
    long *out_r2,        /* secondary return value (typically 0) */
    int  *out_errno,     /* errno from the real syscall when applicable */
    int  *out_intercept  /* always 1 for the Go path: C did the syscall */
);

/* One-shot init from cgo, called from Go init(). Resolves real_syscall via
 * dlsym(RTLD_NEXT, ...) the same way the LD_PRELOAD path does. Idempotent. */
void bpfrejit_handle_init(void);

/* Optional: explicit ioctl entry, for the SYS_IOCTL path. */
void bpfrejit_handle_ioctl(
    int fd, unsigned long request, void *arg,
    int *out_ret, int *out_errno, int *out_intercept);
```

The Go path always sets `*out_intercept = 1` because the C handler issues the
underlying syscall itself via the `real_syscall` function pointer that
`libbpfrejit_shim.c` already maintains (`bpfopt/shim/libbpfrejit_shim.c:51-66`).
The forked `x/sys/unix` honors `intercept=true` and skips its own syscall.

### Go side (~50 LOC, all of it)

```go
package bpfrejitgohook

/*
#cgo CFLAGS: -I${SRCDIR}/../shim
#cgo LDFLAGS: -L${SRCDIR}/../shim -lbpfrejit_shim_handler -lpthread -ldl
#include "bpfrejit_shim_export.h"
*/
import "C"

import (
    "syscall"
    "golang.org/x/sys/unix"
)

func init() {
    C.bpfrejit_handle_init()
    unix.SetSyscallHook(forward)
}

func forward(
    num, a1, a2, a3, a4, a5, a6 uintptr,
) (r1, r2 uintptr, err syscall.Errno, intercept bool) {
    var cr1, cr2 C.long
    var cerrno, cintercept C.int
    C.bpfrejit_handle_syscall(
        C.long(num),
        C.long(a1), C.long(a2), C.long(a3),
        C.long(a4), C.long(a5), C.long(a6),
        &cr1, &cr2, &cerrno, &cintercept,
    )
    return uintptr(cr1), uintptr(cr2),
        syscall.Errno(cerrno), cintercept != 0
}
```

### Required C shim refactor

The existing libc interposer (`bpfopt/shim/libbpfrejit_shim.c:247-321` and the
ioctl interposer at `:323-352`) contains all the dispatch + state logic
inlined into the `syscall()` / `ioctl()` wrappers. Refactor so the internal
logic is in a function that does NOT depend on `va_list`:

```c
/* New internal entry — no va_list. Both LD_PRELOAD interposer and Go path
 * call this directly. */
static void handle_bpf_syscall_internal(
    long n, long a0, long a1, long a2, long a3, long a4, long a5,
    long *out_r1, long *out_r2, int *out_errno);

/* LD_PRELOAD interposer (existing function) — now thin: */
long syscall(long n, ...) {
    /* va_arg extract a0..a5 (existing code) */
    long r1, r2; int err;
    handle_bpf_syscall_internal(n, a0, a1, a2, a3, a4, a5, &r1, &r2, &err);
    errno = err;
    return r1;
}

/* Exported entry for the Go cgo wrapper. */
void bpfrejit_handle_syscall(
    long n, long a1, long a2, long a3, long a4, long a5, long a6,
    long *out_r1, long *out_r2, int *out_errno, int *out_intercept) {
    handle_bpf_syscall_internal(n, a1, a2, a3, a4, a5, a6,
                                out_r1, out_r2, out_errno);
    *out_intercept = 1;
}
```

The internal function inherits the existing pre-call capture, real-syscall
invocation, post-call resolve, and `obj_insert` logic; the move is mechanical.

### Required Makefile changes in `bpfopt/shim/`

```makefile
# Existing target: libbpfrejit_shim.so (LD_PRELOAD library)
# New target: static archive for cgo linkage
libbpfrejit_shim_handler.a: libbpfrejit_shim.o
	$(AR) rcs $@ $<

libbpfrejit_shim.o: libbpfrejit_shim.c
	$(CC) $(CFLAGS) -c $< -o $@
```

### Coverage of intercepted surfaces

The C shim already recognizes (`bpfopt/shim/libbpfrejit_shim.c:289-300`):

- `SYS_BPF` with `BPF_PROG_LOAD`, `BPF_MAP_CREATE`, `BPF_MAP_UPDATE_ELEM`,
  `BPF_LINK_CREATE`, `BPF_LINK_UPDATE`, `BPF_PROG_ATTACH`,
  `BPF_RAW_TRACEPOINT_OPEN`.
- `SYS_PERF_EVENT_OPEN`.
- `SYS_IOCTL` for perf event `PERF_EVENT_IOC_SET_BPF`, enable, disable, query.

Through the Go forwarding wrapper, all of these are equally captured for
vendor-replaced Go binaries.

### Outstanding surfaces still to add to the C shim (regardless of Go path)

- Netlink socket operations used for legacy XDP/TC. PoC-C surface lists this
  as required (`docs/tmp/poc_c_bpf_syscall_shim_design.md:125-130`). Adding
  the netlink decoder benefits both LD_PRELOAD path and Go vendor-replace
  path. In Go libraries it surfaces through `unix.Sendto`/`Recvfrom`;
  vishvananda/netlink creates AF_NETLINK sockets with `unix.Socket` and
  `unix.Bind`, then sends serialized requests with `unix.Sendto`
  (`github.com/vishvananda/netlink@v1.3.1/nl/nl_linux.go:698-717,843-862`).
- Socket filter `setsockopt` surfaces (`SO_ATTACH_BPF`-style), already listed
  in PoC-C (`docs/tmp/poc_c_bpf_syscall_shim_design.md:126`).

### Why this works for static Go binaries

cgo in a static Go binary embeds the linked `.a` archive symbols directly,
including the C shim's `real_syscall = dlsym(RTLD_NEXT, "syscall")` resolution
step. For statically-linked Go binaries that bundle libc internally (musl
static or glibc with `-static-pie`), `dlsym(RTLD_NEXT, "syscall")` resolves to
the bundled libc's `syscall` function — exactly what we want, since x/sys's
syscall sites do not go through libc's `syscall()` (Go uses raw SYSCALL
instructions). The C shim's `real_syscall` here is effectively a labeled
trampoline to the real kernel entry; in static Go it can also fall back to a
direct `SYSCALL` instruction inline-assembly path if `dlsym` returns NULL.

## 5. Per-app integration: cilium-agent

Current corpus behavior:

- `cilium-agent` is an active macro app (`corpus/config/macro_apps.yaml:7`).
- The runner resolves it from repo artifacts, corpus build output, `runner/repos/cilium/bin/cilium-agent`, `/usr/bin/cilium-agent`, or `/usr/local/bin/cilium-agent` (`runner/libs/app_runners/cilium.py:246-257`).
- The runner launches the real agent with Cilium flags that enable XDP, BPF masquerade, endpoint BPF, and related datapath features (`runner/libs/app_runners/cilium.py:276-337`).
- After endpoint setup, it freezes userspace with SIGSTOP while datapath programs remain resident (`runner/libs/app_runners/cilium.py:549-594`).
- Process env forwarding is already available through `ManagedProcessSession`, which merges per-runner env with `os.environ` before `subprocess.Popen` (`runner/libs/app_runners/process_support.py:202-219`).

Module patch:

File: `runner/repos/cilium/go.mod`.

Add:

```go
require github.com/bpfrejit/bpfrejit-go-hook v0.0.0

replace golang.org/x/sys => github.com/bpfrejit/sys v0.42.0-bpfrejit.1
replace github.com/bpfrejit/bpfrejit-go-hook => ../../bpfopt/go-hook
```

If the hook library is published as a normal module, omit the local `replace github.com/bpfrejit/bpfrejit-go-hook` line. Cilium's build flags currently force `-mod=vendor` (`runner/repos/cilium/Makefile.defs:199-200`), so an implementation must either update `vendor/` in the app checkout or override the build to use module mode in the local artifact stage. Do not silently ignore this: if the replaced module is not actually selected, the binary is uninstrumented.

Side-effect import:

Add one import to `runner/repos/cilium/daemon/main.go`, whose import block is small and close to the real `main()` (`runner/repos/cilium/daemon/main.go:4-16`):

```go
import (
    _ "github.com/bpfrejit/bpfrejit-go-hook"

    "github.com/cilium/cilium/daemon/cmd"
    "github.com/cilium/cilium/pkg/hive"
)
```

Build command:

- Minimal binary build: `make -C runner/repos/cilium/daemon cilium-agent`. The daemon Makefile defines `TARGET := cilium-agent` and builds it with `$(GO_BUILD) -o $(TARGET)` (`runner/repos/cilium/daemon/Makefile:14-23`), so the binary lands at `runner/repos/cilium/daemon/cilium-agent`.
- Runtime image artifact build: use the root install target so BPF assets are installed too. `make -C runner/repos/cilium install-container-binary DESTDIR=/out` runs `install-bpf` and installs container binaries (`runner/repos/cilium/Makefile:186-201`). In a Docker build stage, copy `/out/usr/local/bin/cilium-agent` to `/usr/local/bin/cilium-agent`, and keep `/out/var/lib/cilium/` as `/var/lib/cilium/`.

Why x/sys catches Cilium's BPF path:

- Cilium imports `github.com/cilium/ebpf v0.21.0` (`runner/repos/cilium/go.mod:22`).
- cilium/ebpf aliases `golang.org/x/sys/unix` in its internal unix package (`github.com/cilium/ebpf@v0.21.0/internal/unix/types_linux.go:9-10`).
- Program loads call `sys.BPF(BPF_PROG_LOAD, ...)` (`github.com/cilium/ebpf@v0.21.0/internal/sys/types.go:1500-1505`), and `BPF` calls `unix.Syscall(unix.SYS_BPF, ...)` (`github.com/cilium/ebpf@v0.21.0/internal/sys/syscall_other.go:16-29`, upstream: https://github.com/cilium/ebpf/blob/v0.21.0/internal/sys/syscall_other.go#L16-L29).
- BPF links and map updates also route through the same `BPF` wrapper: `LinkCreate` calls `BPF_LINK_CREATE` (`github.com/cilium/ebpf@v0.21.0/internal/sys/types.go:933-934`) and `MapUpdateElem` calls `BPF_MAP_UPDATE_ELEM` (`github.com/cilium/ebpf@v0.21.0/internal/sys/types.go:1349-1350`).
- Perf attach paths call `unix.IoctlSetInt(... PERF_EVENT_IOC_SET_BPF ...)` and `unix.PerfEventOpen` (`github.com/cilium/ebpf@v0.21.0/link/perf_event.go:300-312,341-362`), which reach x/sys `ioctl` and `PerfEventOpen` wrappers (`golang.org/x/sys/unix/zsyscall_linux.go:55-67,1335-1341`).

Docker integration:

Replace the Dockerfile stage that copies Cilium from `quay.io/cilium/cilium` (`runner/containers/runner-runtime.Dockerfile:4,200,228-237`) with a local build stage that copies `runner/repos/cilium`, applies the module/import patch, runs the install target, and exports the same file layout.

## 6. Per-app integration: opentelemetry-ebpf-profiler

Current corpus behavior:

- OTel is an active macro app (`corpus/config/macro_apps.yaml:6`).
- The runner resolves `otelcol-ebpf-profiler` from repo artifacts, local source output, or `/usr/local/bin/otelcol-ebpf-profiler` (`runner/libs/app_runners/otel_profiler.py:99-111`).
- The runner writes a local collector config and launches the real binary with optional feature gates and `--config` (`runner/libs/app_runners/otel_profiler.py:113-130`).
- The app runner documents the tail-call accounting caveat for `perf_unwind_*` programs, which matters when interpreting post-swap counters (`runner/libs/app_runners/otel_profiler.py:21-30`).

Module/build-chain notes:

- `runner/repos/opentelemetry-ebpf-profiler/go.mod` explicitly says it is not used for official binaries and points to the collector release manifests (`runner/repos/opentelemetry-ebpf-profiler/go.mod:3-9`).
- The local corpus build target does use a generated collector manifest under `cmd/otelcol-ebpf-profiler/manifest.yaml`. That manifest defines the local distribution name and imports `go.opentelemetry.io/ebpf-profiler/collector` (`runner/repos/opentelemetry-ebpf-profiler/cmd/otelcol-ebpf-profiler/manifest.yaml:9-18`), then replaces `go.opentelemetry.io/ebpf-profiler => ../../` (`runner/repos/opentelemetry-ebpf-profiler/cmd/otelcol-ebpf-profiler/manifest.yaml:30-31`).
- The local Makefile generates the collector and builds `otelcol-ebpf-profiler` into the repository root (`runner/repos/opentelemetry-ebpf-profiler/Makefile:76-86`).

Module patch:

File: `runner/repos/opentelemetry-ebpf-profiler/go.mod`.

Add:

```go
require github.com/bpfrejit/bpfrejit-go-hook v0.0.0

replace golang.org/x/sys => github.com/bpfrejit/sys v0.42.0-bpfrejit.1
replace github.com/bpfrejit/bpfrejit-go-hook => ../../bpfopt/go-hook
```

Side-effect import:

Patch `runner/repos/opentelemetry-ebpf-profiler/collector/factory.go`. The generated collector imports this package via the manifest, and `factory.go` is not generated (`runner/repos/opentelemetry-ebpf-profiler/collector/factory.go:4-18`).

```go
import (
    _ "github.com/bpfrejit/bpfrejit-go-hook"

    "errors"
    "time"
    ...
)
```

Build command:

```bash
make -C runner/repos/opentelemetry-ebpf-profiler otelcol-ebpf-profiler TARGET_ARCH=amd64
```

Use `TARGET_ARCH=arm64` for arm64. The Makefile exports `GOARCH=$(TARGET_ARCH)` and `CGO_ENABLED=0` (`runner/repos/opentelemetry-ebpf-profiler/Makefile:20-34`). The output is `runner/repos/opentelemetry-ebpf-profiler/otelcol-ebpf-profiler` because the target runs `go build ... -o ../../$@` from `cmd/otelcol-ebpf-profiler/` (`runner/repos/opentelemetry-ebpf-profiler/Makefile:85-86`).

Why x/sys catches OTel's BPF path:

- OTel imports `github.com/cilium/ebpf v0.21.0` (`runner/repos/opentelemetry-ebpf-profiler/go.mod:17`) and the tracer imports `github.com/cilium/ebpf`, `asm`, and `link` (`runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:21-23`).
- The cilium/ebpf path routes through x/sys as described in section 5.
- OTel also directly probes the BPF syscall with `golang.org/x/sys/unix.Syscall(unix.SYS_BPF, ...)` (`runner/repos/opentelemetry-ebpf-profiler/internal/linux/probe_linux.go:31-37`), which the replacement hook catches.

Docker integration:

Replace the current GitHub release download in the runtime image (`runner/containers/runner-runtime.Dockerfile:275-286`) with a local OTel build stage and copy its `otelcol-ebpf-profiler` output to `/usr/local/bin/otelcol-ebpf-profiler`.

## 7. Per-app integration: tetragon

Current corpus behavior:

- Tetragon is an active macro app (`corpus/config/macro_apps.yaml:8`).
- The runtime image currently copies `/usr/bin/tetragon` and `/var/lib/tetragon/` from `quay.io/cilium/tetragon:v1.6.1` (`runner/containers/runner-runtime.Dockerfile:3,198,223-224`).
- The Tetragon runner expects the artifact layout `/repo-artifacts/<arch>/tetragon/bin/tetragon` plus BPF object files under the same artifact root (`runner/libs/app_runners/tetragon.py:83-101`).
- The runner launches the real `tetragon` binary with server, health, policy-dir, and optional `--bpf-lib` arguments (`runner/libs/app_runners/tetragon.py:165-181`).

Source checkout:

- Tetragon is listed in repository metadata (`runner/repos.yaml:80-94`) but is not checked out under `runner/repos/` in this workspace. Add a source checkout at `runner/repos/tetragon/`.
- Clone upstream `https://github.com/cilium/tetragon.git` at tag `v1.6.1`, matching the current runtime image tag in `runner/containers/runner-runtime.Dockerfile:3`.

Module patch:

File after checkout: `runner/repos/tetragon/go.mod`.

Tetragon v1.6.1 uses `go 1.25.0`, `github.com/cilium/ebpf v0.20.0`, and `golang.org/x/sys v0.39.0` (https://github.com/cilium/tetragon/blob/v1.6.1/go.mod#L1-L44). Add:

```go
require github.com/bpfrejit/bpfrejit-go-hook v0.0.0

replace golang.org/x/sys => github.com/bpfrejit/sys v0.39.0-bpfrejit.1
replace github.com/bpfrejit/bpfrejit-go-hook => ../../bpfopt/go-hook
```

Side-effect import:

Patch `runner/repos/tetragon/cmd/tetragon/main.go`. Upstream `cmd/tetragon/main.go` is package `main` and already has a side-effect import block for sensor initialization (https://github.com/cilium/tetragon/blob/v1.6.1/cmd/tetragon/main.go#L4-L74).

```go
import (
    _ "github.com/bpfrejit/bpfrejit-go-hook"

    "context"
    ...
)
```

Build command:

```bash
make -C runner/repos/tetragon tetragon tetragon-bpf LOCAL_CLANG=1 TARGET_ARCH=amd64
```

Use `TARGET_ARCH=arm64` for arm64. Upstream v1.6.1 detects `TARGET_ARCH` and maps it to `GOARCH` and `BPF_TARGET_ARCH` (https://github.com/cilium/tetragon/blob/v1.6.1/Makefile#L30-L55). The `tetragon` target runs `$(GO_BUILD) ./cmd/tetragon/` (https://github.com/cilium/tetragon/blob/v1.6.1/Makefile#L107-L110), so the binary lands at `runner/repos/tetragon/tetragon`. The BPF target builds objects under `bpf/objs` through `make -C ./bpf` when `LOCAL_CLANG=1` (https://github.com/cilium/tetragon/blob/v1.6.1/Makefile#L119-L134). The `install` target installs `./tetragon` into `$(DESTDIR)$(BINDIR)` (https://github.com/cilium/tetragon/blob/v1.6.1/Makefile#L161-L166).

Docker integration:

Replace the `quay.io/cilium/tetragon` artifact stage with a local build stage that:

- copies `runner/repos/tetragon`,
- applies the module/import patch,
- runs the build,
- copies the rebuilt binary to `/artifacts/tetragon/bin/tetragon`,
- copies the BPF object directory to `/artifacts/tetragon/` so the runner's existing `--bpf-lib` path still works.

## 8. Docker build pipeline changes

The current runtime Dockerfile imports upstream Tetragon and Cilium images as stages (`runner/containers/runner-runtime.Dockerfile:196-200`), copies their artifacts into `runner-runtime-app-artifacts` (`runner/containers/runner-runtime.Dockerfile:215-237`), then downloads OTel from GitHub release tarballs (`runner/containers/runner-runtime.Dockerfile:275-286`). PoC-E replaces only the three Go app artifact sources.

Concrete Dockerfile diff sketch:

```diff
 ARG CILIUM_IMAGE=quay.io/cilium/cilium:v1.19.3@sha256:...
@@
-FROM ${TETRAGON_IMAGE} AS runner-runtime-tetragon-upstream
-
-FROM ${CILIUM_IMAGE} AS runner-runtime-cilium-upstream
+FROM runner-runtime-build-base AS runner-runtime-cilium-local-build
+ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
+ARG RUN_TARGET_ARCH=x86_64
+COPY --link runner/repos/cilium ${IMAGE_WORKSPACE}/runner/repos/cilium
+COPY --link bpfopt/go-hook ${IMAGE_WORKSPACE}/bpfopt/go-hook
+COPY --link bpfopt/go-forks/sys-v0.42.0 ${IMAGE_WORKSPACE}/bpfopt/go-forks/sys
+RUN set -eux; \
+    case "${RUN_TARGET_ARCH}" in x86_64) target=amd64 ;; arm64) target=arm64 ;; *) exit 1 ;; esac; \
+    make -C ${IMAGE_WORKSPACE}/runner/repos/cilium install-container-binary \
+      DESTDIR=/out GOARCH="${target}" EXTRA_GO_BUILD_FLAGS=-mod=mod
+
+FROM runner-runtime-build-base AS runner-runtime-tetragon-local-build
+ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
+ARG RUN_TARGET_ARCH=x86_64
+COPY --link runner/repos/tetragon ${IMAGE_WORKSPACE}/runner/repos/tetragon
+COPY --link bpfopt/go-hook ${IMAGE_WORKSPACE}/bpfopt/go-hook
+COPY --link bpfopt/go-forks/sys-v0.39.0 ${IMAGE_WORKSPACE}/bpfopt/go-forks/sys
+RUN set -eux; \
+    case "${RUN_TARGET_ARCH}" in x86_64) target=amd64 ;; arm64) target=arm64 ;; *) exit 1 ;; esac; \
+    make -C ${IMAGE_WORKSPACE}/runner/repos/tetragon tetragon tetragon-bpf \
+      LOCAL_CLANG=1 TARGET_ARCH="${target}" EXTRA_GO_BUILD_FLAGS=-mod=mod; \
+    mkdir -p /out/artifacts/tetragon/bin; \
+    install -m 0755 ${IMAGE_WORKSPACE}/runner/repos/tetragon/tetragon /out/artifacts/tetragon/bin/tetragon; \
+    cp -a ${IMAGE_WORKSPACE}/runner/repos/tetragon/bpf/objs/. /out/artifacts/tetragon/
+
+FROM runner-runtime-build-base AS runner-runtime-otelprof-local-build
+ARG IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
+ARG RUN_TARGET_ARCH=x86_64
+COPY --link runner/repos/opentelemetry-ebpf-profiler ${IMAGE_WORKSPACE}/runner/repos/opentelemetry-ebpf-profiler
+COPY --link bpfopt/go-hook ${IMAGE_WORKSPACE}/bpfopt/go-hook
+COPY --link bpfopt/go-forks/sys-v0.42.0 ${IMAGE_WORKSPACE}/bpfopt/go-forks/sys
+RUN set -eux; \
+    case "${RUN_TARGET_ARCH}" in x86_64) target=amd64 ;; arm64) target=arm64 ;; *) exit 1 ;; esac; \
+    make -C ${IMAGE_WORKSPACE}/runner/repos/opentelemetry-ebpf-profiler \
+      otelcol-ebpf-profiler TARGET_ARCH="${target}"; \
+    install -D -m 0755 ${IMAGE_WORKSPACE}/runner/repos/opentelemetry-ebpf-profiler/otelcol-ebpf-profiler \
+      /out/usr/local/bin/otelcol-ebpf-profiler
@@
-COPY --link --from=runner-runtime-tetragon-upstream --chmod=0755 /usr/bin/tetragon /artifacts/tetragon/bin/tetragon
-COPY --link --from=runner-runtime-tetragon-upstream /var/lib/tetragon/ /artifacts/tetragon/
+COPY --link --from=runner-runtime-tetragon-local-build /out/artifacts/tetragon/ /artifacts/tetragon/
@@
-COPY --link --from=runner-runtime-cilium-upstream --chmod=0755 /usr/bin/cilium-agent /usr/local/bin/cilium-agent
+COPY --link --from=runner-runtime-cilium-local-build --chmod=0755 /out/usr/local/bin/cilium-agent /usr/local/bin/cilium-agent
 ...
-COPY --link --from=runner-runtime-cilium-upstream /var/lib/cilium/ /var/lib/cilium/
+COPY --link --from=runner-runtime-cilium-local-build /out/var/lib/cilium/ /var/lib/cilium/
@@
-    otel_tar="/tmp/otelcol-ebpf-profiler_${OTELCOL_EBPF_PROFILER_VERSION}_linux_${otel_arch}.tar.gz"; \
-    curl -fsSL "https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v${OTELCOL_EBPF_PROFILER_VERSION}/otelcol-ebpf-profiler_${OTELCOL_EBPF_PROFILER_VERSION}_linux_${otel_arch}.tar.gz" -o "${otel_tar}"; \
-    tar -C /usr/local/bin -xzf "${otel_tar}" otelcol-ebpf-profiler; \
-    rm -f "${otel_tar}"; \
+COPY --link --from=runner-runtime-otelprof-local-build --chmod=0755 /out/usr/local/bin/otelcol-ebpf-profiler /usr/local/bin/otelcol-ebpf-profiler
```

The exact implementation should avoid shell-patching Go source inside the Dockerfile if possible. Prefer preparing the app patches in the source tree or generating patched artifact images in a separate controlled stage. The diff above is a layout sketch, not a request to edit the Dockerfile in this design task.

Layering tradeoff:

- The repo rule says app artifacts belong in Docker layer #2, below kernel/modules, runner, daemon, and Python (`CLAUDE.md:173-182`). Rebuilt Cilium/Tetragon/OTel still belong there because they are app artifacts.
- They will change more often than upstream image pulls while the hook evolves. That makes layer #2 less stable during PoC-E development, but moving them above daemon/Python would violate the image layering contract and make benchmark image contents less predictable.
- The runtime image currently copies Python/config data last (`runner/containers/runner-runtime.Dockerfile:451-463`), so Python changes do not rebuild app artifacts. Keep that property.

GHCR cache:

- Current cache docs mirror slow stable artifact images for kernel and Katran only, and explicitly do not push `runner-runtime` because it changes with daemon, optimizer, runner, Python, or benchmark data (`docs/ghcr-image-cache.md:3-13`).
- PoC-E should add optional GHCR-cached artifact images for the three rebuilt Go apps if build time becomes material, for example `bpf-benchmark/cilium-vendor-artifacts:<arch>-<cilium_commit>-<sys_tag>`, `tetragon-vendor-artifacts:<arch>-v1.6.1-<sys_tag>`, and `otelprof-vendor-artifacts:<arch>-<otel_commit>-<sys_tag>`.
- Do not cache only the final `runner-runtime` image; cache the stable app-artifact stages so Python and daemon work still rebuild quickly.

Build time impact:

- Cilium full source rebuild plus BPF install is the expensive step and should be budgeted at several minutes on a small VM when caches are warm, longer cold.
- Tetragon and OTel are smaller but still include BPF or collector generation. Expect roughly low single-digit minutes each on warm caches.
- AWS instance-size policy should not be relaxed for this. The repository caps benchmark instances at small/medium and says variance/throughput problems must be solved by code and workload tuning, not larger instances (`CLAUDE.md:156-167`).

## 9. Socket protocol reuse

PoC-E keeps the runner-facing protocol shape unified with the LD_PRELOAD shim path:

- Per-process shim socket: `/var/run/bpfrejit-shim-<pid>.sock`.
- Compatibility router: `/var/tmp/bpfrejit-daemon.sock`.
- Payload: same newline-delimited JSON protocol as the current daemon boundary. Existing notes say the daemon socket path is fixed and the runner sends JSON requests over it (`docs/tmp/userspace_speculative_opt_design.md:21-24,211-217`).
- The router receives current-style requests, selects the app shim by pid/program ownership, forwards to the per-pid socket, and returns the same response shape.
- Both implementations expose the same protocol: C/LD_PRELOAD for dynamic apps and Go/vendor-replace for static Go apps.

This is intentionally different from the shim-only v2 recommendation that removed the daemon boundary and had the runner read swap JSONL directly (`docs/tmp/poc_c_v2_shim_only_design.md:257-299`). Socket Plan A preserves runner Python during PoC-E and fits the v3 boundary rule that runner Python stays on the daemon socket and JSON protocol (`docs/rejit-speculative-optimization-ebpf.md:451-466`).

## 10. Open questions and risks

- Bytecode dump format: pure Go can reimplement the C shim's FNV-1a hash and raw `struct bpf_insn[]` dump in a small amount of code. A cgo bridge keeps exact behavior but weakens static portability.
- Concurrency: Go apps have many goroutines. The hook pointer must be lock-free, and handler state needs its own mutexes or sharded maps. `sync/atomic.Pointer` covers registration; it does not make the handler state safe by itself.
- cilium/ebpf path audit: cilium/ebpf v0.21.0 routes BPF syscalls through `unix.Syscall` (`github.com/cilium/ebpf@v0.21.0/internal/sys/syscall_other.go:16-29`), and perf attach through x/sys wrappers (`github.com/cilium/ebpf@v0.21.0/link/perf_event.go:300-312,341-362`). If an app bypasses x/sys with `syscall.RawSyscall6`, PoC-E misses that path unless the fork hooks raw syscall too.
- Non-BPF syscall bypasses: Cilium has at least one direct stdlib `syscall.Syscall(SYS_IOCTL, ...)` for network multicast address management (`runner/repos/cilium/pkg/datapath/l2responder/l2responder.go:506-515`). That example is not a BPF attach syscall, but it proves app audits must distinguish harmless direct syscalls from missed BPF-relevant paths.
- Netlink attach parsing: Cilium XDP/TC paths can involve legacy netlink. cilium/ebpf `AttachXDP` first uses `BPF_LINK_CREATE` via `AttachRawLink` (`github.com/cilium/ebpf@v0.21.0/link/xdp.go:39-60`), while Cilium's own fallback code can use vishvananda/netlink. The Go hook must capture x/sys netlink send/recv syscalls if a legacy attach path is active.
- Build reproducibility: rebuilt binaries will not match upstream image or release sha256. The paper and artifact manifest must state the source commit/tag, Go version, x/sys fork tag, hook tag, and resulting sha256.
- Go versions: Cilium and OTel local checkouts declare `go 1.25.0` (`runner/repos/cilium/go.mod:1-3`, `runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`), and Tetragon v1.6.1 also declares `go 1.25.0` (https://github.com/cilium/tetragon/blob/v1.6.1/go.mod#L1-L4). The runtime Dockerfile currently defaults to `GO_VERSION=1.26.0` (`runner/containers/runner-runtime.Dockerfile:110-194`). PoC-E should pin the builder to Go 1.25.x for these app stages unless a deliberate upgrade is documented.
- CLAUDE.md loader-rule tension: this is an instrumentation rebuild, not a custom loader, but it is still a source modification. Treat it as a documented artifact variant and do not claim bit-for-bit upstream binary equivalence.
- Maintenance: every x/sys release or kernel UAPI addition may require rebasing the fork and extending the handler's command/attr decoder.
- Failure mode: if the module replacement is lost because of vendoring or generated collector module files, the app will build and run uninstrumented. Add a build-time symbol check or `go list -m golang.org/x/sys` assertion in the app artifact stage.

## 11. Comparison with the LD_PRELOAD shim

Coverage matrix:

| App | Current LD_PRELOAD path | PoC-E vendor-replace path | Notes |
| --- | --- | --- | --- |
| `bpftrace` | Yes | No | Already preload-compatible (`bpfopt/shim/README.md:50-54`). |
| `bcc/set` | Yes | No | BCC Python/libbcc path is preload-compatible (`bpfopt/shim/README.md:53-56`). |
| `tracee` | Yes, musl shim | No | Tracee survey shows BPF loads and links via the musl shim (`bpfopt/shim/README.md:57`). |
| `katran` | Yes for dynamic process | No | Non-goal for PoC-E; BPF workload coverage is handled by LD_PRELOAD plus netlink attach parsing. |
| `cilium-agent` | No for static Go | Yes | PoC-E adds Tier 4 in-process capture/swap capability; Cilium may also have limited external daemon-side swap cases, but vendor-replace is the app-internal path. |
| `tetragon` | No for static Go | Yes | Requires adding `runner/repos/tetragon/` source checkout and local artifact build. |
| `otelcol-ebpf-profiler` | Not covered by the survey table | Yes | Go static collector binary; local source build exists and uses cilium/ebpf. |

Overlap:

- The wire protocol, bytecode dumps, state JSON, and swap records should be shared between both paths.
- The handler implementation can share tests and serialized state schemas even if one implementation is C and the other is Go.

LOC budget:

- x/sys fork: approximately 100-200 LOC per upstream version if the hook is centralized in `Syscall`/`Syscall6`, plus tests.
- Go hook package: approximately 1000-2000 LOC for syscall decoding, state tracking, bytecode dumps, socket serving, and swap orchestration if it mirrors the C shim.
- Per app: one `go.mod` replacement block and one side-effect import. Tetragon also needs the source checkout and artifact-build wiring. Docker changes are larger than app source changes.

## 12. What this design explicitly does not solve

- Pre-built upstream binaries that cannot be rebuilt from source. PoC-E requires source access and a module graph that can be replaced.
- Apps that bypass `golang.org/x/sys/unix` for BPF-relevant syscalls. If Cilium, Tetragon, or OTel uses raw stdlib syscalls for BPF load/attach in an active path, this approach fails for that path unless the hook is extended.
- `bpftrace` and `bcc`; those stay in the LD_PRELOAD shim path.
- Full cross-architecture validation. The design is intended to be architecture-neutral across x86_64 and arm64, but implementation should validate x86_64 first, then arm64.
- Atomic replacement for all attach classes. Legacy TC, legacy XDP, perf event replacement, and socket filters may still require a short gap, consistent with the Phase 2 non-goal.
- Keeping result interpretation in the framework. Any logical-id mapping must preserve raw counters only; aggregation and performance interpretation remain outside framework code per repository rules.
