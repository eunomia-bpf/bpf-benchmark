# B private-stack access normalization

OTel main retains a408-byte private arena in addition to its spill frame;
constant folding alone leaves784 bytes. The simulator declares its private
union volatile, which keeps otherwise dead private loads/stores allocated.

The B IR compiler now clears the volatile marker only on non-atomic accesses
whose every LLVM underlying object is a local alloca of the interpreter's
union.x86_sim_stack_mem. Context/global/mixed/unknown roots, other local types
and atomic accesses retain their annotations. LLVM's ordinary optimization
then handles scalar replacement and aliasing with helper calls. The shared
C interpreter, native P, flags and combined LTO configuration are unchanged.

The checked Clight model's VolatileLoad.nonvol and VolatileStore.nonvol in
formal/external/clean/export/CCLib/Events.lean use ordinary Mem operations with
traceE0 for blocks outside volatile globals; Globalenvs.blockIsVolatile returns
false for local allocations. This is the interpretation used for this private
storage normalization, rather than a claim about arbitrary LLVM volatile C.
FORMAL has the exact source note for its O2 scope; no new formal theorem is
claimed by these compiler tests.

Real host execution passes20 private helper mutations,20 mixed aliases and
30 preserved other-local/global/atomic cases. IR checks retain the five memory
boundaries. Existing20 constant/60identity/30equality and normal B backend
checks pass. Actual retained main frame and stock/whole-app acceptance follow.
Production base compiler/image remain unchanged during these checks.
