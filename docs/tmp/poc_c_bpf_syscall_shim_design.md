# PoC-C: unified BPF syscall shim design

Status: design only. No experiments were run for this note. The only output of
this task is this file.

This design replaces the project-fork `BPF_PROG_REJIT` control path with a
per-process userspace shim that observes the app's BPF control plane and performs
candidate program replacement from inside the app process. The current corpus
wiring does not contain a `corpus/apps/` directory; the active app list is
`corpus/config/macro_apps.yaml:4-13`, the app-to-runner mapping is
`runner/libs/benchmark_catalog.py:23-36`, and runner construction is dispatched
through `runner/libs/app_runners/__init__.py:78-86`.

## 1. Goal and non-goals

Goal: app-transparent program swap on a stock kernel. Each corpus app still
starts the real upstream loader binary or tool. The shim observes the program
loads and attachments the app already performs, preserves enough fd and metadata
state to reconstruct the same load/attach operation, and later lets
`bpfrejit-daemon` ask the shim to load an optimized candidate and swap traffic to
it. The app does not need source changes and the kernel does not need
`BPF_PROG_REJIT` or `BPF_PROG_GET_ORIGINAL`.

This keeps the paper-line direction in `docs/rejit-speculative-optimization-ebpf.md`
where BpfReJIT is runtime userspace-guided rewriting of already-loaded programs
(`docs/rejit-speculative-optimization-ebpf.md:21-26`), while replacing the
current in-place syscall assumption (`docs/rejit-speculative-optimization-ebpf.md:147-163`)
with stock `BPF_PROG_LOAD` plus stock attach replacement. It also respects the
app-level loader rule: apps must load BPF through real startup, not framework-side
`.bpf.o` loaders (`CLAUDE.md:12-13`).

Non-goals:

- Full atomicity. A microsecond-scale detach/re-attach gap is acceptable for
  benchmark measurement. Atomic link or map updates are used where available,
  but perf-event, raw tracepoint, tracing, LSM, and some legacy attach paths need
  a short replacement window.
- Beating in-kernel verifier time. Candidate load uses stock `BPF_PROG_LOAD`,
  so verifier/JIT cost remains in the swap path.
- Swap on every attach type. Some attach types have no stock update primitive.
  The shim must report unsupported attach classes as explicit errors, not hide
  them.
- Preserving the old `prog_id`. Stock candidate load creates a new program
  object. The daemon/shim protocol must report `old_prog_id -> new_prog_id`;
  old-id preservation is only possible with an in-kernel in-place primitive.
- Capturing programs loaded before the shim is installed. Missing original
  bytecode is fatal for that program; using verifier-rewritten
  `xlated_prog_insns` as if it were original bytecode is explicitly forbidden by
  the current userspace design (`docs/tmp/userspace_speculative_opt_design.md:72-80`).

## 2. Background: prior art

bpftime is the closest prior-art mechanism. Its project README describes a
userspace eBPF runtime with loader/verifier/helpers/maps and support for running
eBPF in userspace while keeping compatibility with existing clang/libbpf/bpftrace
toolchains; it specifically includes an `LD_PRELOAD` loader library
([bpftime README](https://github.com/eunomia-bpf/bpftime), lines 345-364). The
bpftime docs describe syscall hooks based on binary rewriting, plus ptrace /
frida-gum injection into running programs
([design doc](https://eunomia.dev/bpftime/documents/how-it-works/), lines
322-328). Its usage guide shows direct `LD_PRELOAD` deployment of
`libbpftime-syscall-server.so` and an agent library
([usage doc](https://eunomia.dev/bpftime/documents/usage/), lines 436-447).
The paper abstract frames bpftime as a userspace runtime that uses binary
rewriting for uprobe and syscall hook capabilities
([arXiv:2311.07923](https://arxiv.org/abs/2311.07923), lines 37-40).

The mechanism similarity is deliberate: both designs put a per-process shim in
the app's control plane and use LD_PRELOAD or binary rewriting where libc
interposition is insufficient.

The purpose is different:

- bpftime redirects eBPF execution into a userspace runtime, with userspace maps,
  helpers, verifier/JIT choices, and optional cooperation with kernel eBPF.
- This shim keeps kernel execution unchanged. It does not run BPF, emulate maps,
  or replace the verifier. It only captures original load metadata, records
  attachment ownership, and asks the stock kernel to load and attach optimized
  candidates.

## 3. Syscall surface to intercept

The mandatory UAPI command set is the BPF command enum in
`vendor/libbpf/include/uapi/linux/bpf.h:955-991`. The relevant attr layouts are
the map-create struct (`vendor/libbpf/include/uapi/linux/bpf.h:1511-1558`),
map element/batch structs (`vendor/libbpf/include/uapi/linux/bpf.h:1559-1585`),
program-load struct (`vendor/libbpf/include/uapi/linux/bpf.h:1586-1664`),
prog attach/detach struct (`vendor/libbpf/include/uapi/linux/bpf.h:1665-1680`),
test-run struct (`vendor/libbpf/include/uapi/linux/bpf.h:1681-1717`),
raw tracepoint struct (`vendor/libbpf/include/uapi/linux/bpf.h:1747-1787`),
link-create struct (`vendor/libbpf/include/uapi/linux/bpf.h:1788-1866`), and
link-update struct (`vendor/libbpf/include/uapi/linux/bpf.h:1867-1885`).
Perf-event ioctls are in `vendor/linux-framework/include/uapi/linux/perf_event.h:576-586`.

The shim has two interception modes:

- libc/dynamic mode: wrap `bpf()`, `syscall()`, `perf_event_open()`, `ioctl()`,
  `close()`, and BPF-adjacent `sendmsg()`/`setsockopt()` through LD_PRELOAD.
- raw-syscall mode: patch or trampoline the process's direct syscall stubs so
  Go/static binaries hit the same handler path. Go's runtime exposes
  `Syscall6`, documented as calling a system call number with six arguments
  ([Go docs](https://pkg.go.dev/runtime/internal/syscall), lines 218-222), and
  its Linux runtime assembly issues `SYSCALL` directly in syscall helpers
  ([Go source](https://go.dev/src/runtime/sys_linux_amd64.s), lines 597-607).
  LD_PRELOAD alone does not see those calls.

The required surface:

| Surface | What the shim records | What it may rewrite or synthesize |
| --- | --- | --- |
| `bpf(BPF_PROG_LOAD)` | Before the real syscall, deep-copy `union bpf_attr` and pointed-to user buffers: raw `struct bpf_insn[]`, license, BTF, func_info, line_info, `fd_array`, verifier log settings, `prog_type`, `expected_attach_type`, attach target fields, flags, name, and token fd. After success, query `BPF_OBJ_GET_INFO_BY_FD` for `prog_id`, tag, type, bytes, and name. Duplicate program/map/BTF/attach-target fds needed for later candidate load. | App-originated loads pass through unchanged. Daemon-originated candidate loads reuse the captured attr with candidate insns and same map/BTF fds. A recursion guard marks those internal loads so they do not create a second optimization request. |
| `BPF_PROG_GET_FD_BY_ID` / `BPF_MAP_GET_FD_BY_ID` / `BPF_OBJ_GET` | Map returned fds to object ids and object classes; preserve hidden duplicates when the fd may be needed for a future candidate load or replacement. | No app rewrite. The shim can use these commands internally when a hidden duplicate was not captured. |
| `BPF_MAP_CREATE` | Map fd, map id, type, key/value sizes, `max_entries`, flags, name, inner map template fd, BTF ids. | No app rewrite. Hidden duplicate is retained while any captured program may need the map for reload. |
| `BPF_MAP_UPDATE_ELEM`, `BPF_MAP_UPDATE_BATCH`, `BPF_MAP_DELETE_ELEM`, `BPF_MAP_LOOKUP_ELEM`, `BPF_MAP_LOOKUP_AND_DELETE_ELEM`, batch lookup/delete | For ordinary maps, record enough to keep fd/id state current. For `BPF_MAP_TYPE_PROG_ARRAY`, record `map_id/key -> prog_id` tail-call slots. For map-in-map, perf-event-array, sockmap, sockhash, and cgroup-array values, record fd-bearing values by map type. | For tail-call target swap, the shim issues `BPF_MAP_UPDATE_ELEM` with the candidate prog fd against the same map/key. |
| `BPF_PROG_ATTACH` / `BPF_PROG_DETACH` | Program fd/id, target fd/id where available, attach type, flags, replacement fd, and generation. Duplicate the target fd because cgroup/sockmap-style replacement needs it later. | For legacy attach classes with replace support, daemon swap may issue `BPF_PROG_ATTACH` with the candidate fd and `BPF_F_REPLACE`/`replace_bpf_fd`; otherwise detach+attach with a short gap. |
| `BPF_LINK_CREATE` | Returned link fd/id, link type, attached prog fd/id, target fd/ifindex, attach type, cookies, tracing target, perf event fd, cgroup/netns/sockmap target. | For update-capable links, daemon swap issues `BPF_LINK_UPDATE`. For non-update links, daemon swap recreates the link from captured attrs. |
| `BPF_LINK_UPDATE` / `BPF_LINK_DETACH` | App-driven updates change the active `link_fd -> prog_id` mapping. Detach removes the attachment. | Daemon swap uses `BPF_LINK_UPDATE` where `link->ops->update_prog` exists. Generic dispatch only calls `update_prog` if the link ops provide it (`vendor/linux-framework/kernel/bpf/syscall.c:5816-5858`). |
| `BPF_RAW_TRACEPOINT_OPEN` | Raw tracepoint name, prog fd/id, returned link fd, attach generation. | Daemon swap recreates the raw tracepoint open with the candidate after closing/detaching the old fd. |
| `BPF_PROG_TEST_RUN` | Test-run target fd/id, ctx/data sizes and flags. This catches loaders that validate programs before attach. | Usually no rewrite. A future policy could test candidates before attach, but verifier success from `BPF_PROG_LOAD` is the required safety gate. |
| `perf_event_open(2)` | Full `perf_event_attr`, pid, cpu, group fd, flags, returned fd, event id, enabled state, and whether it later receives a BPF program. | Daemon swap opens a same-target replacement perf event inside the process. |
| `ioctl(perf_fd, PERF_EVENT_IOC_SET_BPF)` | Event fd, BPF prog fd/id, event id, current enabled state. PoC-B found `PERF_EVENT_IOC_SET_BPF` returns `EEXIST` when replacing an already-attached event on the inspected stock kernel (`docs/tmp/poc_b_bcc_perf_event_swap.md:9-20`). | Do not call `SET_BPF` on an already-attached old event as a replacement. Instead create a fresh event, attach candidate to the empty event, and preserve the fd number with `dup3()`/`dup2()`. |
| `ioctl(perf_fd, PERF_EVENT_IOC_DISABLE/ENABLE/QUERY_BPF/ID)` | Enabled/disabled state and current attached BPF ids. | Used for swap sequencing and validation. |
| `close(2)` on tracked fds | App fd lifetime. Closing a link/perf fd may detach; closing a prog/map fd may require dropping or retaining hidden duplicates depending on active attachment references. | Internal hidden fds are not visible to the app. The shim releases them when the corresponding app object is detached/unloaded or when the process exits. |
| `dup`, `dup2`, `dup3`, `fcntl(F_DUPFD*)` | Fd aliases. This is an implementation requirement even though the conceptual API is `close(2)`: without alias tracking, an app can attach through a duplicated fd the shim no longer recognizes. | No app rewrite except daemon swap may use `dup3(new_fd, old_fd)` to preserve fd numbers. |
| `sendmsg()` / `recvmsg()` on `NETLINK_ROUTE` sockets | Legacy XDP and legacy TC are not represented by `bpf()` attach commands. Record `RTM_SETLINK` `IFLA_XDP` fields for Katran-style XDP and `RTM_NEWTFILTER`/`TCA_BPF` identity for Cilium-style legacy TC. | Daemon swap can synthesize `XDP_FLAGS_REPLACE` or `tc filter replace` netlink messages. This is required for Katran because PoC-A found upstream Katran attaches standalone XDP through legacy netlink, not a bpf-link fd (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`). |
| `setsockopt()` for `SO_ATTACH_BPF`, `SO_ATTACH_REUSEPORT_EBPF`, `SO_DETACH_BPF` | Socket-filter style attachments where the attach surface is a socket option, not `bpf()`. Record socket fd and prog fd/id. | Daemon swap can detach and reattach to the same socket fd with a short gap. This is needed for any `socket_filter` program observed in Tetragon-style workloads (`docs/tmp/userspace_speculative_opt_design.md:114`). |

The netlink and socket-option rows are intentionally outside the narrow
`bpf()` syscall. Without them, the design cannot honestly claim all-7-app
coverage because Katran's current XDP attach path is legacy netlink and Cilium
may use legacy TC.

## 4. Injection mechanism per loader-language

### C/C++ and dynamic-library loaders

Use `LD_PRELOAD=/usr/local/lib/libbpfrejit-shim.so` for dynamically linked apps
whose BPF control plane passes through libc, libbpf, libbcc, bpftrace, or
libbpf-adjacent C/C++ code. The wrapper exports:

- `int bpf(enum bpf_cmd, union bpf_attr *, unsigned int)` where available,
- `long syscall(long nr, ...)` for `SYS_bpf`, `SYS_perf_event_open`,
  `SYS_close`, `SYS_sendmsg`, and fd duplication calls,
- `int ioctl(int fd, unsigned long req, ...)`,
- `int close(int fd)`,
- `int setsockopt(...)`.

Concrete corpus recommendations:

- Katran: use LD_PRELOAD on the real `katran_server_grpc` process. The runner
  resolves that binary from repo artifacts (`runner/libs/app_runners/katran.py:193-196`),
  starts it with real `balancer.bpf.o` and `healthchecking_ipip.bpf.o`
  (`runner/libs/app_runners/katran.py:536-548`), and then currently rebinds the
  XDP program to generic mode (`runner/libs/app_runners/katran.py:631-633`,
  `runner/libs/app_runners/katran.py:731-777`). The shim must include the
  netlink observer because current upstream Katran does not expose a bpf-link
  fd (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`).
- bpftrace: use LD_PRELOAD on each `bpftrace -q <script>` child. The set runner
  starts five scripts (`runner/libs/app_runners/bpftrace_set.py:24-30`) with
  `start_agent(bpftrace, ["-q", script])` (`runner/libs/app_runners/bpftrace_set.py:131-139`).
  Scripts exercise kprobe and tracepoint attachments, e.g. `capable.bt`
  `kprobe:cap_capable` (`runner/assets/bpftrace_scripts/capable.bt:72-78`),
  `runqlat.bt` scheduler tracepoints (`runner/assets/bpftrace_scripts/runqlat.bt:44-50`),
  and `biosnoop.bt` block tracepoints (`runner/assets/bpftrace_scripts/biosnoop.bt:33-40`).
- BCC: use LD_PRELOAD on each Python/BCC tool process. `bcc/set` runs eight tools
  (`runner/libs/app_runners/bcc_set.py:34-43`) and spawns each resolved tool
  binary with `subprocess.Popen(command, env=tool_env, ...)`
  (`runner/libs/app_runners/bcc_set.py:144-167`). The actual loader path is
  CPython plus libbcc/libbpf C/C++ extension code, so libc interposition is the
  correct first path.

### Go and static/raw-syscall binaries

LD_PRELOAD is insufficient for Go binaries that issue raw `SYSCALL`
instructions through the Go runtime. The design options are:

- BPF-side uprobe at the Go syscall site. This is useful for observation and for
  validating symbol offsets, but by itself it cannot load a candidate or
  reattach from inside the process. It should be a diagnostic mode, not the
  production swap mechanism.
- Binary rewriting / hot-patching at app startup. Patch the Go syscall stubs for
  `bpf`, `perf_event_open`, `ioctl`, `close`, `sendmsg`, fd duplication, and
  `setsockopt` to branch into the same shim handler used by the LD_PRELOAD path.
  This is the recommended path for the Go corpus apps because it preserves the
  one-shim-per-process architecture.
- Ptrace/frida injection. This is viable prior art from bpftime's running-process
  injection model, but heavier and more brittle for benchmark runs.
- Library cooperation in cilium/ebpf, libbpfgo, or app loader code. This defeats
  the app-transparent requirement and is not the recommendation.

Concrete corpus recommendations:

- Tracee: use Go hotpatch/in-process agent. The runner starts the upstream Tracee
  binary with `--events *`, `--output none`, a health server, and a signatures dir
  (`runner/libs/app_runners/tracee.py:204-208`), then records newly loaded BPF
  programs (`runner/libs/app_runners/tracee.py:82-128`). The runtime image copies
  upstream `tracee` and `tracee-ebpf` artifacts (`runner/containers/runner-runtime.Dockerfile:215-221`).
  The shim must handle a possible helper process if `tracee` execs or spawns
  `tracee-ebpf`.
- Tetragon: use Go hotpatch/in-process agent. The runner starts the upstream
  `tetragon` binary with health/server addresses and the policy directory
  (`runner/libs/app_runners/tetragon.py:165-181`). The policies include kprobes
  (`runner/assets/tetragon_policies/security-socket-connect.yaml:6-13`), tracepoints
  (`runner/assets/tetragon_policies/raw_syscalls.yaml:6-12`), and raw tracepoint
  mode (`runner/assets/tetragon_policies/rawtp.yaml:6-12`).
- Cilium: use Go hotpatch/in-process agent plus netlink parsing. The runner
  resolves `cilium-agent` (`runner/libs/app_runners/cilium.py:246-257`) and starts
  it with XDP/datapath features enabled (`runner/libs/app_runners/cilium.py:284-337`).
  It then freezes userspace while TC/XDP datapath programs and pinned maps remain
  resident (`runner/libs/app_runners/cilium.py:549-557`). The local source checkout
  has `module github.com/cilium/cilium` and `go 1.25.0` (`runner/repos/cilium/go.mod:1-3`).
- otelcol-ebpf-profiler: use Go hotpatch/in-process agent. The runner generates
  a config that enables all interpreter tracers (`runner/libs/app_runners/otel_profiler.py:33-62`)
  and starts `otelcol-ebpf-profiler --feature-gates=... --config ...`
  (`runner/libs/app_runners/otel_profiler.py:123-130`). The local source checkout
  has `module go.opentelemetry.io/ebpf-profiler` and `go 1.25.0`
  (`runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`).

## 5. Cooperation protocol with `bpfrejit-daemon`

Use one Unix socket per shimmed process:

- Default path: `/run/bpfrejit/shim/$pid.sock`.
- Fallback: Linux abstract socket `@bpfrejit-shim.$pid.$boot_id`.
- Discovery: the shim announces itself to the daemon on startup, and the daemon
  can also scan `/proc/*/exe` plus `/proc/*/environ` for `BPFREJIT_SHIM=1`.

Wire format:

- Control plane: newline-delimited JSON for small records, matching the current
  daemon style of JSON-over-Unix-socket (`docs/tmp/userspace_speculative_opt_design.md:211-216`).
- Large blobs: pass sealed `memfd` fds over the Unix socket with `SCM_RIGHTS`.
  Raw bytecode, BTF, func_info, and line_info should not be base64 encoded.
- Every message carries `pid`, `start_time` or boot-scoped process cookie,
  `shim_generation`, and monotonic `event_seq`.

Core messages:

```json
{"op":"hello","pid":1234,"exe":"/usr/bin/cilium-agent","arch":"x86_64","injection":"go_hotpatch","caps":["bpf","perf","netlink","setsockopt"]}
{"op":"prog_load","load_cookie":17,"prog_id":530,"prog_type":"xdp","name":"balancer_ingress","attr_blob_fd":4,"insns_blob_fd":5}
{"op":"attach","attach_cookie":44,"prog_id":530,"method":"legacy_xdp_netlink","ifindex":12,"mode":"generic","fd_cookie":91}
{"op":"swap_request","request_id":9,"old_prog_id":530,"attach_cookie":44,"candidate_insns_fd":8,"expected_attach_generation":1}
{"op":"swap_reply","request_id":9,"status":"ok","old_prog_id":530,"new_prog_id":777,"attachments_swapped":[44]}
```

Per-process state machine:

1. `PROCESS_ANNOUNCED`: shim is loaded and connected.
2. `LOAD_CAPTURED`: `BPF_PROG_LOAD` attr and raw bytecode are copied before the
   verifier can rewrite instructions. This is required because stock
   `BPF_OBJ_GET_INFO_BY_FD` exposes xlated instructions, not original bytecode
   (`docs/tmp/userspace_speculative_opt_design.md:36-60`).
3. `PROG_LIVE`: real load succeeded and `prog_id` is known.
4. `ATTACH_LIVE`: at least one attachment, link, perf event, socket, netlink
   attach, or prog-array slot points at the program.
5. `CANDIDATE_READY`: daemon has optimized bytecode by running external
   `bpfopt` passes; the daemon remains the policy/orchestration owner.
6. `CANDIDATE_LOADED`: shim calls stock `BPF_PROG_LOAD` inside the app process,
   using captured attrs and hidden map/BTF fds.
7. `SWAPPED`: shim applies the per-attach recipe and reports the new `prog_id`.
8. `FAILED`: shim reports the syscall error and any rollback attempt result.

State keys:

```text
prog_id -> {
  load_cookie,
  hidden_prog_fd,
  load_attr_snapshot,
  original_insns_blob,
  map_fd_refs[],
  active_attachments[],
}

attach_cookie -> {
  method,
  generation,
  old_prog_id,
  active_prog_id,
  fd_cookie,          # link fd, perf fd, socket fd, map fd, or netlink identity
  target_identity,    # ifindex, cgroup fd, map/key, tracepoint name, perf attr...
  restore_recipe,
}
```

The daemon's optimization pipeline does not need to live in the shim. The shim
only needs capture, fd ownership, candidate load, attach replacement, and error
reporting.

## 6. Per-attach-type swap recipe inside the shim

| Attach type | Recipe | Atomicity and notes |
| --- | --- | --- |
| XDP bpf-link | Load candidate as `BPF_PROG_TYPE_XDP`, then `BPF_LINK_UPDATE(link_fd, new_prog_fd, BPF_F_REPLACE, old_prog_fd)`. | Atomic. XDP link update installs the new program and swaps `link->prog`; current design evidence is in `docs/tmp/userspace_speculative_opt_design.md:96`. |
| Legacy XDP netlink | Synthesize `RTM_SETLINK` with `IFLA_XDP_FD = new_prog_fd`, the original mode flag, `XDP_FLAGS_REPLACE`, and expected old fd/id. | Atomic under RTNL if the expected old program matches. Required for current Katran; current runner's helper detaches then attaches with bpftool (`runner/libs/app_runners/katran.py:122-138`), and PoC-A found upstream Katran is legacy netlink, not bpf-link (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`). |
| TCX link | `BPF_LINK_UPDATE` on the TCX link fd. | Atomic. Existing userspace design cites TCX update support in `docs/tmp/userspace_speculative_opt_design.md:98`. |
| Legacy TC `cls_bpf` | Reconstruct the filter identity from observed netlink: ifindex, ingress/egress, parent, chain, prio, handle, protocol, direct-action flag, and old prog id. Send `tc filter replace` equivalent with the candidate fd. | Replacement is under rtnl, but only works if the shim captured the exact filter identity. Cilium is the main risk because the runner notes TC attachments survive process death as interface-scoped state (`runner/libs/app_runners/cilium.py:614-618`). |
| perf-event attach for kprobe/uprobe/tracepoint/perf_event | Disable old event if enabled; open a new perf event with the captured `perf_event_attr`, pid, cpu, group, and flags; call `PERF_EVENT_IOC_SET_BPF` on the fresh event; enable it if old was enabled; use `dup3(new_event_fd, old_event_fd)` or close+dup2 to preserve the fd number; close the temporary fd. | Non-atomic. PoC-B found `PERF_EVENT_IOC_SET_BPF` cannot replace an event that already has a program on the inspected kernel (`docs/tmp/poc_b_bcc_perf_event_swap.md:9-20`), so the fresh-event path is mandatory. This path is only app-transparent if fd number and event state are preserved. |
| raw tracepoint | Close/detach the old raw tracepoint link fd, then issue `BPF_RAW_TRACEPOINT_OPEN` with the same name and candidate prog fd. Preserve fd number if the app keeps it. | Non-atomic gap. Raw tracepoint link ops lack update support in the current userspace design (`docs/tmp/userspace_speculative_opt_design.md:94`). |
| fentry/fexit/LSM/freplace/tracing link | Close/detach the old link fd, then `BPF_LINK_CREATE` again with captured target BTF/prog metadata and the candidate fd. | Non-atomic gap. Tracing link ops lack update support (`docs/tmp/userspace_speculative_opt_design.md:95`). Freplace needs the original target prog/BTF fd; missing target fd is fatal. |
| `PROG_ARRAY` tail-call slot | `BPF_MAP_UPDATE_ELEM(prog_array_fd, key, new_prog_fd, BPF_ANY)` on the same map/key. | Atomic per map slot. Existing design cites the prog-array update path and JIT poke update in `docs/tmp/userspace_speculative_opt_design.md:103`. Remember that tail targets often report zero `run_cnt`; caller counters measure the savings (`CLAUDE.md:60-62`). |
| cgroup link / netns link / sockmap link | Prefer `BPF_LINK_UPDATE` if the app used link-backed attachment. For legacy cgroup attach, use `BPF_PROG_ATTACH` with replace flags and captured target cgroup fd. | Link-backed path is atomic; legacy path depends on captured target fd and attach flags. Existing design covers cgroup, sockmap, and netns link update support (`docs/tmp/userspace_speculative_opt_design.md:100-104`). |
| socket filter / reuseport socket option | Use captured socket fd. Detach old filter with the matching detach option where available, then `setsockopt(... SO_ATTACH_BPF or SO_ATTACH_REUSEPORT_EBPF ..., new_prog_fd)`. | Non-atomic gap and socket-option-specific. Required for any `socket_filter` program in Tetragon-like workloads. |

Optional enhancement: install a tail-call indirection layer at first attach time.
The shim would attach a stable entry program that tail-calls through a
shim-owned `PROG_ARRAY`, then all future swaps become map updates. This can make
more replacements atomic, but it changes counters, adds a dispatch cost, and
requires first-attach intervention. It is not required for PoC-C and should not
be the default OSDI benchmark path.

## 7. 7-app coverage table

`katran` and `katran/wrk` are separate macro entries (`corpus/config/macro_apps.yaml:9-11`)
but share the same upstream Katran runner and count as one supported app here.

| App | Current launch path | Loader / injection | Attach types and swap plan | Expected limitations |
| --- | --- | --- | --- | --- |
| `katran` | Real `katran_server_grpc` with real balancer and healthchecking objects (`runner/libs/app_runners/katran.py:536-548`), started by `KatranRunner.start()` (`runner/libs/app_runners/katran.py:731-777`). | C++ upstream binary from Katran artifacts. LD_PRELOAD plus netlink observer. | XDP. If bpf-link exists, use `BPF_LINK_UPDATE`; current expected path is legacy XDP netlink replace because PoC-A found legacy netlink attach (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`). | Current runner calls `reattach_xdpgeneric()` after app startup (`runner/libs/app_runners/katran.py:748`); a stock-kernel shim benchmark should either observe this helper too or move the rebind into the shim/netlink path. |
| `cilium/agent` | `CiliumRunner` resolves `cilium-agent` (`runner/libs/app_runners/cilium.py:246-257`) and launches it with BPF/XDP datapath options (`runner/libs/app_runners/cilium.py:284-337`). | Go; local checkout says `go 1.25.0` (`runner/repos/cilium/go.mod:1-3`). Use Go syscall hotpatch plus netlink parser. | XDP, TC/sched_cls, tracing, tail-call prog arrays. Use XDP link/netlink replace, TCX link update or legacy TC replace, prog-array map update for tail calls. | Legacy TC identity reconstruction is the hardest part. The runner freezes Go userspace after endpoint setup while TC/XDP programs stay resident (`runner/libs/app_runners/cilium.py:549-557`), so swaps must occur while the app is stopped; the shim agent must keep running on a non-frozen control thread or the daemon must request swap before SIGSTOP. |
| `tracee/monitor` | Runner starts upstream Tracee with `--events *` and health server args (`runner/libs/app_runners/tracee.py:204-208`), then waits for new BPF programs (`runner/libs/app_runners/tracee.py:82-128`). | Go/hybrid upstream artifact; use Go hotpatch and propagate into helper process if `tracee-ebpf` is execed. | Observed classes include raw tracepoint, kprobe, cgroup_skb, and LSM in the current userspace design (`docs/tmp/userspace_speculative_opt_design.md:113`). Use raw_tp/tracing recreate, perf-event recreate, cgroup replace where captured. | LSM/tracing replacement is non-atomic and target-fd capture is mandatory. Multi-process helper ownership is an audit item. |
| `tetragon/observer` | Runner starts upstream `tetragon` with policy dir and optional BPF lib dir (`runner/libs/app_runners/tetragon.py:165-181`). | Go; use Go hotpatch. | Policies include kprobes (`runner/assets/tetragon_policies/security-socket-connect.yaml:6-13`), tracepoints (`runner/assets/tetragon_policies/raw_syscalls.yaml:6-12`), and raw tracepoint mode (`runner/assets/tetragon_policies/rawtp.yaml:6-12`). Use perf-event recreate, raw_tp/tracing recreate, prog-array updates for tail-call chains, and `setsockopt` if socket filters are present. | Generic kprobe/raw_tp chains are non-atomic. Socket filter replacement requires `setsockopt` capture, not just `bpf()` capture. |
| `bpftrace/set` | Runner starts each script with `bpftrace -q script` (`runner/libs/app_runners/bpftrace_set.py:131-139`). | C++ bpftrace from distro packages; LD_PRELOAD. | kprobe, tracepoint, interval/perf-event programs. Scripts cite kprobe and tracepoint use in `runner/assets/bpftrace_scripts/capable.bt:72-78`, `runner/assets/bpftrace_scripts/vfsstat.bt:33-42`, `runner/assets/bpftrace_scripts/runqlat.bt:44-50`, and `runner/assets/bpftrace_scripts/biosnoop.bt:33-40`. | Multiple BPF loads per process lifetime and multiple child processes. Perf-event replacement must preserve fd numbers so bpftrace's event bookkeeping stays valid. |
| `bcc/set` | Runner runs eight BCC tools (`runner/libs/app_runners/bcc_set.py:34-43`) and spawns each resolved command with the prepared environment (`runner/libs/app_runners/bcc_set.py:144-167`). | CPython plus libbcc/libbpf C/C++ extension; LD_PRELOAD. | Mostly kprobe, tracepoint, raw tracepoint, and tracing variants; existing design summarizes the observed classes at `docs/tmp/userspace_speculative_opt_design.md:116`. Use perf-event recreate, raw_tp/tracing recreate, and record any fentry/kfunc variants. | Eight independent processes mean eight shim sockets. PoC-B shows cross-process fd takeover is not enough; replacement must happen inside each BCC process (`docs/tmp/poc_b_bcc_perf_event_swap.md:1-20`). |
| `otelcol-ebpf-profiler/profiling` | Runner writes a minimal config enabling all tracers (`runner/libs/app_runners/otel_profiler.py:33-62`) and starts `otelcol-ebpf-profiler` with feature gates and config (`runner/libs/app_runners/otel_profiler.py:123-130`). | Go; local checkout says `go 1.25.0` (`runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`). Use Go syscall hotpatch. | Perf-event and tracepoint entries, plus tail-called `perf_unwind_*` programs. Use perf-event recreate for direct entries and `PROG_ARRAY` update for tail-call targets. | Tail-called programs report zero `run_cnt`; measurement must use caller counters (`runner/libs/app_runners/otel_profiler.py:21-30`, `CLAUDE.md:60-62`). Perf-event mmap/read behavior must be audited before fd replacement is considered transparent. |

## 8. Comparison vs alternatives

Versus modifying upstream apps: the shim keeps upstream Tracee, Tetragon, Cilium,
Katran, bpftrace, BCC, and OTel binaries unmodified. That avoids per-project
forks, loader API churn, and benchmark-specific source patches. The cost is
shim complexity and launch-control requirements.

Versus a minimal kernel patch: extending kernel link update support for missing
classes, or keeping a narrow in-place `BPF_PROG_REJIT` primitive, would simplify
userspace and cover static/Go binaries naturally. The shim has zero kernel UAPI
surface but pays for that with syscall interception, fd lifetime tracking,
netlink parsing, Go hotpatching, and per-attach fallback logic. It also requires
control over app launch through env vars or a wrapper.

Versus doing nothing: the current daemon path directly depends on fork-only
`BPF_PROG_REJIT` and original-bytecode fields. The current userspace design
lists those callsites in `daemon/src/syscall.rs`, `daemon/src/bpf.rs`, and
`daemon/src/commands.rs` (`docs/tmp/userspace_speculative_opt_design.md:158-180`).
This shim is the stock-kernel alternative: capture original bytecode before
verifier rewrite, load candidates with stock `BPF_PROG_LOAD`, and switch traffic
through existing attach mechanisms.

## 9. Implementation sketch

Primary shim language: C. It must work as an LD_PRELOAD library in CPython,
bpftrace, Katran, and other dynamically linked C/C++ paths. It should expose the
same internal handler ABI to the Go hotpatch path.

Suggested components:

- `libbpfrejit_shim.so`
  - `interpose.c`: libc wrappers for `bpf`, `syscall`, `ioctl`, `close`, fd dup,
    `sendmsg`, and `setsockopt`.
  - `bpf_attr_copy.c`: deep-copy and validate user pointers for each observed
    `bpf()` command.
  - `state.c`: fd table, object table, hidden duplicate registry, generation
    counters, and attach graph.
  - `protocol.c`: daemon socket, JSON control messages, `SCM_RIGHTS` blob fds.
  - `swap.c`: per-attach replacement recipes.
  - `netlink.c`: minimal `IFLA_XDP` and `TCA_BPF` parser/emitter.
  - `recursion_guard.c`: thread-local guard so shim-internal syscalls do not
    re-enter as app events.
- `bpfrejit-shimctl`
  - Launch wrapper for Go/static apps.
  - Resolves syscall stub symbols/patterns, validates build id, applies text
    patch/trampoline, starts the app, and rolls back on launch failure.
  - Optional uprobe-only diagnostic mode to discover Go syscall sites before
    enabling hotpatch mode.

Approximate LOC:

| Area | Estimate |
| --- | ---: |
| LD_PRELOAD wrappers for 10-12 functions | 700-1000 |
| BPF attr deep copy and object metadata | 900-1400 |
| fd/object/attach state machine | 1000-1600 |
| daemon protocol and blob fd passing | 500-800 |
| attach swap recipes | 1200-2200 |
| netlink and socket-option attach support | 800-1400 |
| Go syscall hotpatch launcher, x86_64 + arm64 | 1500-3000 |
| tests/fakes for attr copy and state transitions | 800-1400 |

Total first all-7-app implementation: roughly 7-12 KLOC. A C/C++-only PoC for
Katran, bpftrace, and BCC can be much smaller, roughly 3-5 KLOC.

Delivery:

- Developer PoC: bind-mount the `.so` into the container and set
  `LD_PRELOAD=/path/to/libbpfrejit_shim.so` for the target process.
- Benchmark image: do not bind-mount the host workspace. The repo rule forbids
  host workspace bind mounts in benchmark containers (`CLAUDE.md:170-171`), so
  production delivery should `COPY` the shim into the runtime image and set env
  through the suite entrypoint or per-runner environment.
- Go apps: invoke through `bpfrejit-shimctl -- <real app> ...` or have the daemon
  perform startup-time hotpatch before releasing the process. Uprobe-only mode is
  an audit aid; the swap-capable design needs an in-process agent.

## 10. Risks and open questions

- Go symbol stability across Go versions. Cilium and OTel local checkouts say
  Go 1.25.0 (`runner/repos/cilium/go.mod:1-3`,
  `runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`), but Tracee and
  Tetragon are pinned image artifacts (`runner/containers/runner-runtime.Dockerfile:2-4`,
  `runner/containers/runner-runtime.Dockerfile:215-224`). Exact compiler versions
  and syscall stub layouts must be audited before hotpatching.
- Static binaries. This note did not run `file` or `readelf -d`. If Katran,
  bpftrace, Python/libbcc, or any helper is static or ignores the dynamic loader,
  it must use the raw-syscall hotpatch path instead of LD_PRELOAD.
- Shim recursion. Candidate loads, internal `BPF_OBJ_GET_INFO_BY_FD`, hidden
  `BPF_MAP_GET_FD_BY_ID`, and replacement attaches must be guarded so they do not
  create infinite event loops or get optimized again as app-originated programs.
- Multi-process apps. `bcc/set` starts eight children; Tracee may involve a
  helper artifact; bpftrace/set starts one process per script. LD_PRELOAD
  propagates through normal `execve`, but Go hotpatch and per-process sockets
  need explicit coordination.
- SUID/SGID binaries. LD_PRELOAD is ignored in secure-execution mode. The corpus
  should audit executable mode bits before relying on the preload path.
- bpftrace ad-hoc scripts. The shim must handle repeated BPF loads, many maps,
  perf events, and script exit cleanup in a single process lifetime.
- Netlink correctness. Legacy XDP and TC replacement requires parsing enough
  route netlink to reconstruct exactly the app's attach identity. This is the
  main expansion beyond a pure `bpf()` shim.
- Hidden fd lifetime. Duplicating prog/map/link/target fds can extend object
  lifetime past the app's visible close. The shim must release hidden refs on
  detach/process exit and must document the residual lifetime difference during
  active optimization.
- Perf-event fd replacement. Preserving fd numbers with `dup3()` is necessary
  but may not preserve mmap rings or app-specific event state. OTel and bpftrace
  need explicit audit before treating this as transparent.
- Thread concurrency. Swap should run under a process-wide shim lock, but other
  app threads can still be executing BPF-triggering syscalls or reading fds. The
  design accepts a microsecond-scale gap but must avoid fd table corruption.
- Runner measurement mapping. Userspace swap creates new `prog_id`s. The shim
  reports the mapping, but the benchmark collector still needs to sample the new
  ids if this becomes an executable benchmark path; the existing userspace design
  explains why old-id sampling would be wrong (`docs/tmp/userspace_speculative_opt_design.md:219-242`).

Sequence diagram:

```text
app process                   shim                         daemon
-----------                   ----                         ------
exec real app
  |                           hello(pid, exe) ------------>
  | bpf(BPF_PROG_LOAD)
  |--------------------------> copy attr+insns
  |                           real bpf(PROG_LOAD)
  |<-------------------------- prog_fd
  |                           query prog_id
  |                           prog_load event ------------>
  | attach syscall/ioctl/netlink
  |--------------------------> record attach + dup fds
  |                           attach event --------------->
  |                                                        run bpfopt
  |                           <------------ swap_request(candidate bytecode)
  |                           bpf(PROG_LOAD candidate)
  |                           detach/update/reattach
  |                           swap_reply(new_prog_id) ---->
  | workload continues on candidate program
```

## 11. What this design explicitly does not solve

- It does not help if the app loaded the BPF program before shim injection, or if
  the program appears only as an already-pinned kernel object with no captured
  original load attr.
- It does not preserve old `prog_id`s on a stock kernel. Result collection must
  treat old and candidate ids as distinct raw counter objects linked by shim
  metadata.
- It does not eliminate verifier/JIT latency during swap. Candidate load still
  pays stock `BPF_PROG_LOAD` cost.
- It does not make all attach classes atomic. Perf-event, raw tracepoint,
  tracing, LSM, socket-filter, and some legacy netlink paths can have a short
  gap.
- It does not address concurrency between the app's own reload/swap behavior and
  a daemon-driven swap. The first implementation should reject a swap if the
  attachment generation changed after the daemon planned it.
- It does not fully recover from every partial swap. The shim needs an explicit
  rollback path using hidden old prog/target fds, but some classes may still
  fail after the old attachment has been detached. Those failures must surface as
  errors rather than being silently masked.
- It does not cover non-standard control planes that bypass the observed syscall
  surfaces. If an app uses an unobserved mechanism, the correct behavior is an
  unsupported-attach error with the captured evidence needed to add that surface.
