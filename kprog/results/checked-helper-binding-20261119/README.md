# Actual helper bindings in checked-native BCC

Read the archived installed kernel-link plans and 16-byte call relocation
records from the last completed BCC checked-native functional run. Resolve
kernel addresses by the retained monotonic-clock anchor and the sole kernel's
System.map. Keep all programs and plans. This is static binding evidence,
not a new profiler, runtime share or performance result.

The audit targets phase-1 original-context helper selection and item 1e's
map-write binding. It changes no request input while the current BCC guest
and Tetragon backend run. Execute the local Make target under timing SH on
CPU 18. Full capsules remain in their original persistent raw archive.

PERF 2026-11-19T11:43:27Z: Both the prior b77 header check (105515_135901,
raw bcc-20261119T105336Z-344181) and the completed constant-ALU32 check
(113739_128860, raw bcc-20261119T113557Z-354948) have 25/25 checked programs.
Their installed relocation inventories agree: five tracepoint output/stack
calls bind the generic functions, zero of 25 plans contain map_ops, and 17
update plus 10 delete call sites bind generic wrappers. These are static
sites, not invocation counts or a new helper-time profile.

The five tracepoint sites in the current run are inet_sock_set_state output
at blob offset 1569; sys_exit_open get_stack/output at 836/899; and
sys_exit_openat get_stack/output at 836/899. Actual targets are
bpf_perf_event_output/bpf_get_stack, while the kernel's tracepoint verifier
ops choose their _tp variants. The tracing-type block_rq_complete output
also needs the original program's aux-aware query; type 26 alone does not
identify its correct helper family, so the audit assigns no expected name.

The source cause is still present: native_loader.cpp:3990 calls
load_from_loaded_program_fd for the trusted worker, but that common function
does not set context_helpers (:3037). The only query assignment is in the
normal manifest route (:4208), behind kernel_helper_context. The old draft
in helper-fd-boundary-20261118 already describes moving the existing query
into the common original-FD function. The current stock provider exposes
helper_targets; a new module API is unnecessary. Apply that class once the
running request inputs are released; source-ID-zero/context-only remains
a separate obligation.

Map writes have a second cause. The trusted route supplies no original
source_insns (:3990), so load_from_loaded_program_fd reads translated B
(:3065) and leaves meta_by_source_fd empty (:3073). map_ops is populated
only after matching a source map FD (:3146). The sole kernel exports map
IDs in translated LD_IMM64 (`syscall.c:4972`), while helper CALL immediates
are already fixed up. These translated values are not process FDs or
original helper IDs. Reusing the pre-verifier scanner without recovering
those identities cannot populate the map-operation plan. This audit does
not change that path or infer that every map supports both operations.

PERF 2026-11-19T11:47:45Z: Applied the common-query fix: one assignment in
load_from_loaded_program_fd now obtains the original program's actual helper
prototypes for both callers. Removed the duplicate normal-route query,
temporary flag, manifest parser field and producer field (+1/-7 source lines).
The existing wire format/provider and original FD lifetime are unchanged.
Source-ID-zero/context-only remains an explicit separate obligation.

Canonical `make -C kprog/libnativeloader trusted-service` builds the loader
libraries, worker and client successfully into the sole verified-loader base,
under timing SH/image EX on CPU18 with a 16 GiB address-space bound. Full log:
`/workspaces/kprog-raw/perf/constant-alu32-20261119/helper-loader-build-20261119T1147Z.log`.
This is compilation, not yet evidence of new installed helper targets or
per-call gains. The next canonical BCC functional run will supply actual
stock/native coverage and archived relocation targets. No image or module
change is needed for that functional entry.
