# bpfrejit-shim

`libbpfrejit_shim.so` is the kernel-facing component of the active
stock-kernel speculative-optimization path. It runs inside the real upstream
application process, intercepts BPF-related syscalls, preserves loader-owned
state, executes runner-supplied `bpfopt` plans, and submits optimized bytecode
through the ordinary `BPF_PROG_LOAD` verifier/JIT path.

There is no `bpfrejit-daemon` and no project-specific ReJIT syscall in the
active architecture.

## Responsibilities

The shim intercepts `syscall(SYS_bpf, ...)`, `perf_event_open(2)`, `ioctl(2)`,
`close(2)`, and the netlink operations needed to observe program attachment.
For each application-loaded program it retains the original bytecode and the
load, map, link, perf-event, raw-tracepoint, program-array, and XDP state needed
to optimize the program without replacing the upstream loader.

The runner remains the policy owner. It reads
`runner/config/passes/<pass>/default.yaml` and gives the shim an ordered list
of opaque commands. The shim substitutes its runtime variables, executes each
command with `LD_PRELOAD` removed from the child environment, and treats
`bpfopt` output as a candidate only after the stock kernel accepts it.

`bpfopt` remains a pure bytecode CLI. It does not own application file
descriptors and does not issue BPF syscalls.

## Two Execution Paths

### Load-time plan

When `BPFREJIT_SHIM_LOADTIME_PLAN` is set, the shim intercepts each normal
`BPF_PROG_LOAD`, canonicalizes its map references, runs the configured passes,
probes verifier acceptance, and substitutes the accepted bytecode into that
same load operation. Reports are appended to
`BPFREJIT_SHIM_LOADTIME_REPORTS`.

The current corpus comparison uses this path. It runs and stops a baseline
application, then starts the same upstream application again with the
load-time plan enabled. Consequently, corpus results from this path are
load-time specialization results, not evidence of an in-place live swap.

### Running-process execute plan

Each shim instance exposes a per-process Unix socket:

```text
${BPFREJIT_SHIM_SOCK_DIR:-/var/run/bpfrejit}/shim-<pid>.sock
```

The `execute_plan` request runs passes against programs already tracked by the
shim. For every changed candidate, `reload_and_reattach()` performs a stock
`BPF_PROG_LOAD` and then updates each captured attachment using the applicable
stock-kernel mechanism. Implemented mechanisms include `BPF_LINK_UPDATE`, link
recreation, `BPF_PROG_ATTACH` replacement, perf-event replacement, raw
tracepoint reopen, program-array updates, and XDP netlink reattachment.

A verifier rejection leaves the old program installed. A partial attachment
replacement is reported as `RELOAD_PARTIAL_ATTACH`; it is not silently treated
as success. Results should be described as live-swap results only when their
lifecycle record shows this path was used.

## Socket Protocol

Requests and responses are newline-delimited JSON. The main commands are:

```json
{"cmd":"list_progs"}
{"cmd":"dump_state"}
{"cmd":"execute_plan","steps":[{"name":"noop","command":"bpfopt --pass noop --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE}","log_level":1}]}
```

The runner enumerates the per-process sockets directly. The removed daemon
socket `/var/tmp/bpfrejit-daemon.sock` is not part of the current protocol.

## Environment

| Variable | Default | Purpose |
|---|---|---|
| `BPFREJIT_SHIM_LOG` | `/tmp/bpfrejit_shim.log` | Structured shim log |
| `BPFREJIT_SHIM_DIR` | `/tmp` | Bytecode dumps and work directories |
| `BPFREJIT_SHIM_SOCK_DIR` | `/var/run/bpfrejit` | Per-process socket directory |
| `BPFREJIT_SHIM_SOCK_DISABLE` | unset | Disable the socket server when set to `1` |
| `BPFREJIT_SHIM_LOADTIME_PLAN` | unset | Runner-generated load-time plan JSON |
| `BPFREJIT_SHIM_LOADTIME_REPORTS` | unset | Load-time per-program report stream |
| `KEEP_WORKDIRS` | unset | Preserve failure workdirs when set to `1` |

Application runners select the appropriate injection mechanism for each of the
six supported corpus applications. Do not infer current coverage from the
binary's dynamic/static linkage alone; use the runner configuration and a
recorded corpus lifecycle.

## Build and Tests

Benchmark runs must use the root `make <target>` entrypoints. Component-local
development targets are:

```bash
make -C bpfopt/shim
make -C bpfopt/shim selftest-run
make -C bpfopt/shim host-selftest
```

`host-selftest` requires the privileges documented in the component Makefile.

## Source Map

| File | Responsibility |
|---|---|
| `libbpfrejit_shim.c` | Interposition entrypoints and captured application state |
| `shim_loadtime.h` | Load-time plan execution and candidate `BPF_PROG_LOAD` |
| `shim_execute_plan.h` | Per-process socket plan execution |
| `shim_reload.h` | Running-process reload and attachment replacement |
| `shim_snapshot.h` | Map/value and bytecode side-input preparation |
| `shim_state.h` | Program, map, link, perf, and attachment state |
| `shim_measure.h` | Raw measurement support |

The paper-line design hub is
`docs/rejit-speculative-optimization-ebpf_idea.md`. Historical daemon and early
shim PoCs under `docs/tmp/` are background records, not current specifications.
