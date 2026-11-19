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
