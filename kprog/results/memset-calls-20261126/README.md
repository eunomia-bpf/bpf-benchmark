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

The count gives the call sites; their weight comes from a host PMU profile of Tetragon and Tracee
(profile-host.sh, as for OTel in kprog/results/profile-20261123): the share of `memset`, `memset_orig` and
`__memset` in the native samples. Their profile comes next. Its guest needs 32 GiB, and it runs after the arm64 stage-1 compile pool, whose compiles hold that memory now
(COORDINATION 2026-11-26T04:38Z and 05:18Z).

## Host PMU captures available, 2026-11-26

Tetragon and Tracee host-cycle profiles on the unchanged P3 image fb53150e89ea
are captured in `../p3-attribution-20261126/collection-20261126T104107Z/`:
`tetragon-profile` has 11,446,569 samples, `tracee-profile` has 7,978,939.
Both guests completed with app status ok. Event cpu_core/cycles/, period
1,000,000, stats off, 60 s workload, 32 GiB guests; the existing shim measurement
messages identify the phase windows. Raw PMU data, symbols and linked-code
caches remain local and are committed as compressed parts. The wrapper's
nonzero status came from its intentional recorder stop (perf child 143),
not an app failure. The final phase-resolved memset weight and denominator
will be recorded here after the queued PMU summary; sample inventory alone
is not a memset weight or a performance conclusion.

## Workload-window weights, 2026-11-26

The completed analysis is in
`../p3-attribution-20261126/collection-20261126T104107Z/{tetragon,tracee}-profile/phase-summary.json`.
It uses the final 54 s of each workload (finish minus 55 s through finish
minus 1 s), following the earlier profile analysis. The native measurement
counter interval also contains delayed loading and is longer than the actual
60 s workload; the retained `phase-summary-initial.json` is not the workload
weight. `__pi_memset*` aliases are included below.

| app / phase | guest-kernel samples | memset samples | memset / guest kernel | P bodies | P3 hash routines | kernel hash lookup |
|---|---:|---:|---:|---:|---:|---:|
| Tetragon baseline | 1,066,792 | 541 | 0.0507% | 26,222 | 0 | 5,221 |
| Tetragon native | 1,017,494 | 125 | 0.0123% | 13,500 | 2,580 | 0 |
| Tracee baseline | 1,115,701 | 8,219 | 0.7367% | 91,132 | 0 | 94,944 |
| Tracee native | 1,074,961 | 14,366 | 1.3364% | 142,879 | 109,527 | 517 |

These are flat cycle samples, not call counts. Although recording requested
callchains, the guest samples contain context markers without actual chain
frames. Therefore the profile cannot distinguish memset called from P from
memset called elsewhere in the kernel. If every native memset sample were
assigned to P, its fraction of the known P-body + P3-hash + memset samples
would be 0.771% for Tetragon and 5.385% for Tracee. These are generous upper
bounds on sampled weight: other P-called kernel helpers are omitted from
those denominators. They are not exact P caller attribution or statistical
confidence bounds. The static call-site inventory alone does not justify a
memset lowering change.

Tetragon's native profile instead has 846,061 samples in
`resilient_queued_spin_lock_slowpath` (83.15% of guest-kernel samples), versus
807,186 in baseline (75.66%). P3 hash routines account for 0.254% of native
guest-kernel samples; Tracee's account for 10.189%. Without guest stack
frames the flat lock samples do not identify the locking caller. Raw data
and all initial analyses are retained; full timing remains frozen.
