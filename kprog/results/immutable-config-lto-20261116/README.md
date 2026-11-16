Immutable scalar configuration in trusted LTO, 2026-11-16

The direct and registered modules report an immutability bit alongside their
existing direct-value pointer response. It uses the same condition as the sole
kernel's bpf_map_is_rdonly: RDONLY_PROG, frozen, and no active writers. This is
optimization eligibility; a mutable map keeps its memory loads.

The loader snapshots key zero of eligible singleton ARRAY data maps, binds
symbols with the existing loaded-map identity and BTF DATASEC offsets, then
supplies scalar-sized values to the existing trusted LLVM stage. The stage folds
complete integer loads up to 64 bits using those bytes, including volatile
configuration reads. Aggregate layouts and atomic loads retain their semantics.
The compiler does not substitute the original ELF initializer for loaded data.

Data binding precedes LTO, and final entry extraction/binding follows it when the
object changes. Final data-reference names replace the initial closure's names.
Context conversion, generated functions and all existing helper/map LTO remain
in the pipeline. Compilation flags, applications and frozen launchers stay as
they are. This adds no application-specific constant or runtime feature switch.

The committed host recipe builds the canonical stage tool through vendor/bpf,
checks two contrary scalar snapshots, mutable/aggregate/atomic boundaries, and
replays real BCC sys_exit with the workload's source-derived count_by_process=0.
That BCC fact is a diagnostic input, not a guest map capture or performance run.
Raw entry extraction covers OTel sampling and custom__generic, Tetragon execve
and Cilium cil_from_container to exercise the changed phase order.

Run `make -f kprog/results/immutable-config-lto-20261116/Makefile host`, on
CPUs 16-19. Raw data stays under
`/workspaces/kprog-raw/perf/20261116-immutable-config-lto`; build artifacts are
retained by the recipe's archive target. The initial fixture incorrectly used
a C const atomic object whose load LLVM independently folded. Its failed run
and artifacts stay; the corrected test uses a writable atomic object.

Actual kernel eligibility, loaded BCC values, installed bytes, body/helper/map
profiles and per-call effects await coherent publication after C's baseline
round on image 6641a7e1. Registered loads that bypass this ordinary LTO path and
aggregate configuration fields remain outside this scalar optimization.

Host receipt: retry2 controller 1837219 completed with exit zero. Both contrary
scalar snapshots pass, and mutable/aggregate/atomic reads remain. Real sys_exit
proof text is 418 to 305 bytes with source-derived count_by_process=0; the stage
reports two scalar loads folded. All four raw entry extractions pass. Compiler
and loader builds and both active x86 module syntax checks pass. The earlier
retry1 controller 1836739 also passed before the phase-order checks were added.
Controller 1836404 is the retained initial atomic-fixture failure. All logs and
artifact archives stay in their individual raw directories.
