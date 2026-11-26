# memset and memcpy calls in P, 2026-11-26

The BPF backend expands each constant-size memset and memcpy into stores, so B and the kernel's eBPF path
contain these as plain stores. P is compiled with `-O3 -march=native -mno-red-zone -mgeneral-regs-only`
(vendor/bpf/Makefile:53-60, last changed in 6cdde0600). With general registers only, LLVM's x86 lowering
expands up to 16 stores (128 bytes) and calls `memset`/`memcpy` above that. The loader binds those calls to the
kernel's functions. On x86 the kernel's memset is `rep stosb` when the CPU has FSRS, and memset_orig otherwise
(vendor/linux-framework arch/x86/lib/memset_64.S:33-48).

## Count

`memsz.py <app>`, run inside vendor/build/native-bpf/x86/7.0.0-rc2+/native (the x86 P objects, built
2026-11-25 13:23Z), counts `R_X86_64_PLT32 memset|memcpy` relocations. It reads each call's size from the
last immediate moved into edx/rdx before the call. That is a heuristic: a few small values such as 0 or 3 come
from an earlier, unrelated move.

| app | objects | memset calls | memcpy calls | sizes |
|---|---|---|---|---|
| BCC | 8 | 2 | 0 | 312 B (sys_exit_open, sys_exit_openat) |
| Cilium | 8 | 0 | 0 | |
| Katran | 4 | 0 | 0 | |
| OTel | 16 | 10 | 0 | 668 B (native_tracer_entry, custom__generic, uprobe__generic, finish_task_switch) |
| Tetragon | 88 | 5905 | 13 | 5423 take the length from a register; constant: 100 up to 128 B, 211 up to 512 B, 70 up to 4 KiB, 101 above |
| Tracee | 3 | 818 | 15 | 149 from a register; constant: 260 at 4096 B, 119 at 200 B, 118 at 256 B, 112 at 368 B |

Tetragon's count is spread over its 88 objects, which share the generic kprobe, uprobe and usdt code. One
object, bpf_generic_kprobe.native.o, has 15 call sites in generic_kprobe_process_event. Several of the
register-length sites there come a few instructions after a bpf_probe_read_user call (memset of
the remaining length). Tracee's biggest groups are in lkm_seeker_* (32, 31, 30), which runs on demand, and in
trace_security_task_prctl (18).

## Weight on the hot path

A count of call sites gives no weight. The weight comes from a host PMU profile of Tetragon and Tracee
(profile-host.sh, as for OTel in kprog/results/profile-20261123): the share of `memset`, `memset_orig` and
`__memset` in the native samples. These two apps have no host profile yet. Their profile guest needs 32 GiB, and
it runs after the arm64 stage-1 compile pool, whose compiles hold that memory now
(COORDINATION 2026-11-26T04:38Z and 05:18Z).
