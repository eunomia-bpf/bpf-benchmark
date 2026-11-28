# Closed CO-RE census review

SAME launch1496738/process1496739 completed 2026-11-28T14:17:20.900374Z, status0,344 original EM_BPF objects, no resolver errors. collect_census.py rechecked every source ELF, actual target vmlinux, tool/source/library and output-record hash, then extracted actual native P embedded IR from six already-inventoried native objects (three per architecture). All114-object arithmetic inventory hashes for those selected evidence objects match; no P was compiled or replaced. This is a source/IR correctness diagnosis, not performance tuning or new guest execution.

Counts below are relocation records across retained object variants, including duplicate-content source paths. They are not numbers of distinct bugs, programs loaded, executed branches or failed native installs. A poisoned relocation can be guarded dead code; it is not a resolver error or proof of a runtime failure. Changed offsets mostly reflect original BPF source vs target layouts and do not automatically implicate native objects compiled from target-generated headers.

| Architecture / app | Objects | Existence records | False existence records | Changed byte-offset records | Poisoned records |
| --- | ---: | ---: | ---: | ---: | ---: |
| x86 BCC | 8 | 4 | 3 | 24 | 4 |
| arm64 BCC | 8 | 4 | 3 | 24 | 4 |
| x86 Katran | 4 | 0 | 0 | 0 | 0 |
| arm64 Katran | 4 | 0 | 0 | 0 | 0 |
| x86 Tracee | 3 | 4717 | 1976 | 20031 | 3055 |
| arm64 Tracee | 3 | 4595 | 1976 | 19565 | 3055 |
| x86 Tetragon | 157 | 2714 | 93 | 6881 | 924 |
| arm64 Tetragon | 157 | 2714 | 93 | 6830 | 924 |

Both Cilium and OTel have no retained original BPF ELF in the searched existing build roots for either architecture. These four groups remain explicit source gaps; not zero relocations, not six-app coverage. Only main vmlinux BTF is searched; module-BTF loading, actual loaded-program reachability and final installed-code behavior are not established. predicate-sites.json retains113 architecture/app/spec/value groups with every source path, exact example row and repeated-record counts.

## Confirmed frontend mismatches and limits

BCC biosnoop: original request___x.rq_disk existence resolves0 in both target kernels (three records each). Current source core_fixes.bpf.h:get_disk chooses BPF_CORE_READ(r,q,disk) when absent. Actual native P embedded IR get_disk on both architectures instead contains only a GEP of request___x field1 followed by __native_read_kernel; the q/disk branch has already disappeared. The native source layout is {ptr,ptr}, so field1 is byte8. This establishes an incorrect frontend branch/address construction; no actual returned pointer or dynamic biosnoop event is inferred. Returning the correct predicate later in runtime LTO cannot restore the removed branch in existing P.

Tetragon task_struct___local: matching field predicates alone do not solve synthetic-flavor accesses. Both kernels have thread_pid/loginuid. Original BPF CO-RE relocates thread_pid from96 to2904(x86)/2360(arm64), and loginuid.val from112 to3552(x86)/3008(arm64). Actual native P functions get_task_pid_vnr_by_task and __get_auid retain GEPs of the synthetic { [4 x pid_link], ptr, ptr, kuid_t } local struct fields1/3, not the real task_struct layout. Native-function-proofs.json preserves full function bodies, type layouts, original object SHA and embedded-IR SHA. This is a real native frontend layout discrepancy even when existence returns the right value; final linked instructions/actual field values and workload impact remain to be joined, not assumed.

Tetragon audit absence (nine records per architecture) is not by itself an executed mismatch: source __get_auid tests loginuid first; loginuid is present in the target and the native frontend already keeps that arm. The false audit predicate belongs to its alternate branch. The other84 false Tetragon records are kernfs_node___old.id.id, covered by the existing expression exception. Neither count establishes84+9 live defects.

Tetragon cgroup___new.ancestors is PRESENT on both targets; byte offset8 relocates to2304(x86)/2288(arm64). Existing native compatibility deliberately forces this expression false, and actual native cgroup_get_parent_id retains the self.parent fallback instead. Its output equivalence is not settled by this census. Simply removing the exception/selecting true would read synthetic byte8 unless accesses are relocated too. Preserve this result when replacing the expression exceptions with a general rule.

Tracee has14 normalized false existence specs per architecture: two absent types (pid_link and kernfs_node_id) and12 absent fields. Records are highly repeated across sections/inlined code. The existing four confirmed helper-mask defects remain open; this census does not claim every false predicate reaches live code or infer1976 additional bugs. Type existence and source-flavor layout must be handled along with field existence/size and enum facts. No app/program exception list is a correction.

The common defect class is loss of CO-RE semantics during native C compilation: native_compat.h suppresses preserve_access_index, replaces field/type/enum predicates with constants and uses source sizeof/addresses. A general fix must preserve enough source type/field identity before branch folding and use the actual target BTF for predicates AND accesses. It must apply to every app with one flag set per architecture. Existing P needs regeneration after the frontend correction; runtime LTO alone cannot recover discarded source arms. No production fix is claimed in this step.

## Complete evidence publication

census-records.tar.zst contains every690 closed run files (344JSON+344stderr+controller+inventory), job.log and the one query executable:692 regular members. census-archive.json records every member SHA/size, full archive SHA/size, and re-verification of every decompressed member AND original. All originals remain, with no cleanup. collection-review.json seals the actual controller and counts; native-function-proofs.json and source-anchors.json retain native function/source evidence. The Cilium/OTel source and live-work gaps stay open after archive verification.

Followed newest COORDINATOR2026-11-28T11:20Z after its ordered six-app check; 03:24Z alignment priority continues. OTel app2689a430/fixed-app activation HOLD, frozen image/benchmark/kernel/settings, STOP and FORMAL CPU17 remain untouched.
