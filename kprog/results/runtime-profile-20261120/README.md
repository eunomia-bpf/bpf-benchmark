# Runtime profiles and source helper work

The four captures use image revision `8f6ff5891`, the sole kernel and native
module, CPUs20–23, four vCPUs,32GiB, one60second workload sample per arm,
stats on and host `cycles:G` at199Hz. Both arms of each app share one guest.
These are diagnostic profiles; the coordinator's official timing continues
on CPUs0–7. `profile-result.json` and the four evidence archives retain the
actual counters, live JIT bytes/source metadata, symbols, clocks and samples.

| App | eBPF ns/call | Native ns/call | Main observation |
|---|---:|---:|---|
| OTel | 4258.9 | 5092.8 | LPM lookup and user nofault copy dominate guest roots; native unwind text also costs more. |
| BCC | 132.3 | 130.9 | sys_enter holds most inclusive runtime; its text itself is small. Clock reads, map updates and userspace map iteration dominate guest roots. |
| Katran | 204.8 | 196.2 | balancer_ingres text costs 209.4 versus 194.9 cycles/call; clock, hash and packet-generator work also appear. |
| Cilium | 869.5 | 880.1 | The busiest cil_from_container programs remain eBPF with 1093 JIT / 1720 translated bytes in both arms; endpoint constants do not match the prebuilt native programs. |

OTel's guest root cycles per application call change from baseline to native:
LPM lookup 3652.9→3838.8, user nofault copy 2612.0→3000.5,
`lookup_nulls_elem_raw` 806.9→1072.8, `htab_map_hash` 524.4→577.4,
array lookup 230.1→803.9 and generic lookup dispatch 167.9→429.7.
These are exclusive guest root samples normalized by application counters,
not caller-owned helper measurements. Program text includes inline helpers;
it is not a measurement of pure application bodies. Tail-called unwind
programs have zero run counters while their entry holds inclusive runtime.
The raw per-program text offsets remain available for further attribution.

The LBR probe records host-userspace branch addresses even on guest-kernel
root samples, so it does not supply the missing guest caller attribution.
No per-program helper ownership is inferred from it. This matters especially
for BCC's userspace map iteration and the packet generators. OTel's first
collector exits1 after both successful phases because it tried to parse the
final pretty result object as a compact progress event; `498cf2df4` fixes that
parser, and the later three collectors exit0. All four apps reportok and
both actual OTel recordings and counters remain retained.

`399f53f9b` removes seven private-arena/local-temporary volatile qualifiers
from the x86 simulator. CompCert `common/Globalenvs.v:219` and
`common/Events.v:566,579` give private allocated blocks ordinary Mem
load/store behavior and traceE0. External raw/context accesses, unspecified
inputs and atomics retain their behavior. The direct macro fixture passes
1368UBSan byte/width/untouched-neighbor cases, with O1 volatile accesses
24→0. Released-stack observations48, ordinary reads8 and protected-memory
fault cases8 pass, including false-condition CMOV reads. The existing
`recovery_host` test aborts before this change; its baseline log remains
separate and is not reported as passing. This is source cleanup, with no
measured runtime gain.

`94555f854` puts the user-probe wrapper in `vendor/bpf/native-helpers.h`.
It calls the existing kernel `copy_from_user_nofault`, preserving address
policy, NMI checks, pagefault state, SMAP and exception handling, and mirrors
`bpf_probe_read_user_common`'s error zeroing and return value. The existing
loader already binds that kernel symbol. Host ABI/provider controls pass
96copy/error/buffer cases plus two u32lengths and the compatibility control.
Both user8 and dynamic entries pass proof and kernel linking against actual
sole-kernel symbol addresses. Those checks do not execute the kernel copy or
establish new stock acceptance. `component-result.json` and its evidence
archive retain the exact scope and raw failures from initial test recipes.

The wrapper and volatile cleanup are not in the measured image. The next
combined publication must measure their actual app behavior and per-call
effect. The 20%/50% targets remain open. LPM traversal and exact helper caller
attribution remain the next runtime work; no hand-written linker helper or
benchmark definition changed in this step.
