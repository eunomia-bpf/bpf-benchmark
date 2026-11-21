S3 stock-base kernel handoff, 2026-11-09

Status: partial. The published kernel branch contains the approved SMAP BPF exception-recovery change directly above the requested base. Its executed BPF path retains stock verification. Five-step native emission, the small native guest case, the NULL BTF guest case and the 38-case guest suite remain the runtime deliverables.

Kernel source: https://github.com/eunomia-bpf/linux/tree/kprog-no-kinsn

Kernel commit: `e25108bc9d73dfff2d27211792d7588768d47979`.
Direct parent: `c23719abc3308df7ed3ad35650ad211fb2d2003d`.
The branch adds one commit above that parent. The entire kernel delta is:

```text
 arch/x86/mm/fault.c | 6 ++++++
 1 file changed, 6 insertions(+)
```

`kernel/bpf/verifier.c` is byte-identical to the base, with SHA-256 `2bbb780a06e76719c97b8458f3560e3ab0bc37cfc2a773a3e0267ccf3cd7dd50` and Git blob `159b25f8269ddfd6f66edabbca06e3822e56a330`. Every other kernel path retains its base contents, including both JITs, BPF core, syscall, BTF and UAPI. The branch ancestry consists of the base plus the approved fault-recovery commit; the kinsn series stays on its existing branch.

The change carries the coordinator's 2026-11-09 SMAP approval: an existing BPF exception-table site receives the existing exception fixup within the SMAP fault branch. The branch retains the stock BPF exception-table lookup and ownership implementation. Native load-site table construction remains part of the native integration deliverable.

Focused validation passed: `git diff --check`, exact verifier byte comparison, the one-path whole-kernel diff, direct-parent ancestry, and an object build using the existing x86 configuration. The build ran `olddefconfig` followed by `make -j4 arch/x86/mm/fault.o`, with both invocations constrained to CPUs 8-23. Exit status was 0. `receipt.json` records config, object, source and log identities; `fault-object-build.log.gz` contains the actual build output. Validation covers the fault object and build prerequisites. Guest boots: 0. Small native five-step cases: 0. NULL BTF five-step cases: 0. Safety cases attempted: 0 of 38.

The initial shared kernel tree measured 15 changed files, +1238/-120, with `verifier.c` +527/-72 against the same base. Those measurements include the shared tree's existing working changes. They describe the starting architecture; the smaller published S3 branch remains a defensive source subset of the requested architecture.

Design interfaces observed in the current sources:

| Interface | Source evidence and remaining obligation |
| --- | --- |
| Ordinary B | `kprog/x86/x86_sim_local_bpf.h:10,388,447,1050` imports private inputs for unspecified values, entry stack and numeric pointer state. `kinsn/module/include/native_lab_input.h:9-17,27-44` supplies private instruction encodings. The stock MOV handler at base `kernel/bpf/verifier.c:16411` enforces its reserved-field rules. An ordinary-B representation and its universal input-state simulation argument remain required. |
| Subprograms | Stock subprogram JIT ownership lives in `kernel/bpf/verifier.c:22778` (`jit_subprogs`). Native entry, return, stack ownership, per-function images and call relocation semantics need a universal preservation argument while retaining this file's base contents. |
| Tail calls | Target-program lifetime, program-array updates, invocation ABI and tail-call control state must share the semantics of the accepted BPF path for every target and invocation. These are link-preservation obligations across programs and runtime map updates. |
| Relocation sources | `kinsn/module/include/native_lab_trusted.h:374-393,408-430` draws context from a source program and maps from its `used_maps` or submitted resources. `kinsn/module/x86/bpf_x86_native_lab.c:86-104,108-122` owns byte/relocation copies and map references. The ordinary-B architecture needs an explicit resource-ownership correspondence between that request, B's references and each resolved P relocation, covering helper/kfunc identity, map/value/read-only data, and lifetime. |
| NULL BTF | Existing context export at `native_lab_trusted.h:384-393` uses optional source and attachment BTF. The isolated branch preserves stock BTF handling. The requested native NULL BTF acceptance remains a guest integration result. |
| Exception tables | Base `kernel/bpf/core.c:783` supplies `search_bpf_extables`. Native load-site metadata and the resulting exception table need the generic read-fault preservation argument and guest evidence together with the approved SMAP recovery. |

These are architecture and universal-proof interfaces. The stock verifier acceptance of B and the faithful simulation/link argument for P remain the two safety facts. S3 retains stock verification of executed BPF code. A B-to-P execution substitution with open universal preservation premises would enable a kernel verifier bypass, so this lane's assistance boundary ends at defensive kernel isolation and review.

Existing kernel/module builds, active guests, the parent submodule pointer, frozen benchmark files, paper directories, formal coverage rows and other lanes' paths retain their owners and contents. S3 publishes this report to parent master, its kernel commit to `kprog-no-kinsn`, then retires its private outputs and creates its local STOP marker.


Resumption reconciliation, 2026-11-21. The operator removed the original time limit. Later CK/S17/S18 publications supply the implementation and finite guest evidence following S3's first partial handoff. `resumption-20261121.json` records independent source, archive and table readbacks. All 38 original x86 rows agree with their saved outcomes: 9 executed controls, 25 verifier rejections, 1 generation rejection and 3 accepted load-only findings. The x86 control records native retval 2. The ARM 2 GiB guest archive retains submitted native objects, service-generated B and JIT artifacts; the small program returns 2, and the NULL BTF control records ordinary/NULL values 4294967295/0 with two exception entries. Extended 48-case tables on each ISA also agree by case, stage and return code. Accepted load-only findings remain explicit; universal simulation, compiler and link-preservation obligations retain their formal owners.

The published acceptance kernel `35ea2cde39fc88b01f2f49b2a357e7cf7102e4c8` retains the base verifier blob `159b25f8269ddfd6f66edabbca06e3822e56a330`, with a whole-kernel diff of 8 files, +467/-1. It is an ancestor of the current `kprog-no-kinsn` line; its ancestry excludes the kinsn introduction commit. The later bring-up records armed-subprogram handling, tail-call frame/lifetime composition and relocation-source ownership as design interfaces; implementation and proof receipts remain in `kprog/stock-path/results/20261109` and the existing formal ledger.

Current sole kernel snapshot `83e0fabe355d6cf682ba9ce2bb575f1ee1214a16` has 13 files +423/-4 against the same base. Its verifier carries 4 added lines from `74d1097af561`: a native-image early return in `fixup_call_args` for architecture JIT/subprogram handling. Literal verifier byte identity belongs to the historical acceptance revision. S3 posted the present difference and its commit to the coordinator for disposition, preserving the current frozen kernel and active timing/ARM/formal owners. This reconciliation starts 0 guests, creates 0 source trees and changes 0 production paths. The original finite bring-up evidence is now linked to this handoff; present-source byte identity and universal proof closure retain their recorded owners.
