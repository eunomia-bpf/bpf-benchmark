# Verifier-invalid interpreter paths in native LTO

trusted_service.py:180-202 calls compile_checked_simulator only after successful
stock verification. Generation/verification failures return through load-direct
first. compile_sim_ir.cpp currently preserves two invalid B forms as native
llvm.trap: unresolved `call -1`, and the explicit null-store/exit fault. Stock
verification rejects either when reachable. After acceptance their infeasibility
is therefore part of the native compiler contract; keep B unchanged and expose
this fact with llvm.assume(false) so native optimization removes these checks.
Ordinary program returns/checks and recoverable helper errors retain semantics.

The fixture checks both exact forms and a normal program range check, and runs
only verifier-valid inputs for the two assumption contracts. It is a host
compiler test, not a stock-load result or support for unverified native IR.
The direct-native fallback does not invoke this converter and remains intact.

The coordinator investigates the remaining interpreter-folding issue; this
subset addresses item (3) of its 2026-11-19T07:01 note. BTF, helper policy,
program checks, packet lowering and stock bounds are not changed.

PERF 2026-11-19T07:46:41Z: Actual native compiler build and verified-domain/ordinary-check regression pass. All25 retained BCC production compile APIs/proof links pass with C helpers enabled, as do the ARRAY and retained OTel regressions. Raw /workspaces/kprog-raw/perf/native-verified-paths-20261119/candidate-20261119T074633Z-229351. This is host post-verification code generation, not new stock acceptance, installed code or app performance.

PERF 2026-11-19T07:47:52Z: The first candidate build succeeded, then the test stopped because
LLVM retained an icmp feeding llvm.assume. That predicate emits no runtime
branch. Test correction 3fba1b3f4 checks conditional branches and emitted native
instructions instead; resumed validation completed with status 0, without
rebuilding the already-built compiler. The initial output remains at
/workspaces/kprog-raw/perf/native-verified-paths-20261119/candidate-20261119T074539Z-228926.

Against the immediately preceding private-arena candidate (5be6df084), the same
25 retained BCC requests have total proof .text 47,645 -> 47,597 B. Three change:
sys_exit_open 6,928 -> 6,911, sys_exit_openat 6,928 -> 6,911, sched_switch
2,174 -> 2,160 B. These are host object sections, not installed bytes or a
runtime gain. This narrow change leaves the general interpreter-folding issue
open. The comparison uses the completed replay JSON at
/workspaces/kprog-raw/perf/native-private-stack-20261119/candidate-20261119T071020Z-219249/bcc-replay/replay.json
and this directory's bcc-replay.json. No additional workload or timing ran.
