# Dead-marked scalar reloads

OTel retry2 completes18:42:53Z, Make0/app error. read_task_struct and
perf_unwind_stop verify and checked-install. Both subsequent perf_unwind_native
attempts fail MIR lowering on `dead $w2 = LDW32 %stack.35, 0`; the complete
four-request outcome is otel-current-app/retry2-summary.json. Full service
archives stay under /workspaces/kprog-raw/perf/20261115-otel-current-app-retry2/.

whole_word_spills.py now accepts LLVM's `dead` destination marker in direct
scalar reloads and treats that destination as a definition during scratch
liveness. The load and packed-word extraction retain their existing semantics.
Two parser patterns change; source P, shared interpreter and LTO stay intact.

The regression adds a dead-marked reload to the existing independent-reference
fixture. All11 compile cases pass. On the sole kernel, the new case matches
1060 independent-reference executions with48B frame access depth. The complete
affected suite matches10600 executions; the original544B case retains its
expected stock rejection and the packed512B case passes. kernel.json and
compile.json retain every case. Whole-app native-entry compilation/verification
remains the follow-up after the dedicated Katran timing window.

Raw commands and verifier outputs:
/workspaces/kprog-raw/perf/20261115-dead-spill/{check,kernel}/.
