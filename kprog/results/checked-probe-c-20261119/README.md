# Probe-read wrappers as C in checked-sim-c LTO

Inline the kernel's bpf_probe_read_user/kernel common wrappers around its own
copy_from_user_nofault/copy_from_kernel_nofault. Preserve u32 size, int result
sign extension, and full destination zeroing on a negative result. Address
policy, SMAP, pagefault state, fault recovery and user/NMI restrictions remain
inside those existing kernel copy functions. Compat and string helpers retain
their existing calls. B and its helper calls remain unchanged.

The compiler records the selected C helper names. The native compilation links
only a needed C module before O3; the loader binds the two copy symbols through
its existing kallsyms/link-plan mechanism. No runtime selector or new check.

run.sh replaces the sole checked compiler tools and loader in place under
timing SH/image EX on CPU19. The local Makefile tests native wrapper execution,
u32 truncation, partial-copy error zeroing and surrounding bytes, retained
compat calls, and four actual proof/kernel links using the one kernel's symbols.
Host callbacks test the wrapper contract; they do not execute kernel copy code.
App performance and actual kernel copies await OMP's combined LTO batch.

PERF 2026-11-19T06:19:32Z: The sole tools and loader build pass. Wrapper execution
passes 96 copy/error/guard cases plus u32-size and compat retention cases;
all four constant/dynamic user/kernel proof and kernel links pass against the
one kernel's System.map. The nofault functions themselves are not executed
on the host; their policy and exception handling remain kernel-owned.

All 25 retained checked BCC frontends pass the production compile API and
proof link with original frontend reuse. The C class selects 37 kernel-probe
sites across inet_sock_set_state (19), tcp_v4_connect_ret (3), block_rq_insert
(4), sched_switch (4), block_rq_issue (4) and tcp_v6_connect_ret (3). No user
probe is selected in that capture. These are static sites, not run counts.
The ARRAY 1008-case regression and retained OTel production API also pass with
both C classes enabled. No B is regenerated and no new stock acceptance is
claimed. Per-call body/helpers/maps, throughput and installed bytes await
OMP's combined checked-sim-c batch, targeting BCC and OTel.

Raw successful host/replay outputs: `/workspaces/kprog-raw/perf/checked-probe-c-20261119/host-20261119T061250Z-proof`.
The initial worker `host-20261119T061033Z-201185` exits 2 because Clang's
UBSan runtime is absent, after both production builds succeed. GCC's installed
sanitizer runtime now links the driver; Clang O3 still compiles production C.
The following `host-20261119T061213Z-gcc` passes execution but its kernel-link
command incorrectly supplies native.o rather than the canonical proof.o.
Recipe e3a3bbd62 fixes that command; both failures stay in raw. The first
attempt to commit that recipe also encountered a peer's transient git index
lock; the retry committed without deleting any lock or altering peer files.

Ktime review: bpf/helpers.c:178-181 only calls ktime_get_mono_fast_ns, already
bound directly by native_link/src/x86.rs:22-30. A C wrapper alone removes no
further call. timekeeping.c:442-455 reads the latch and calls the current
clocksource through tk_clock_read:291-296; deeper C inlining must preserve
that dynamic callback and sequence behavior. It is not replaced by a fixed
clock guess or a new hot-path guard in this change.
