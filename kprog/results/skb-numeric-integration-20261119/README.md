# Shared SKB field and NUMERIC integration

The NUMERIC component repair0dfa23814 preserves an already supplied value.
This regression tests the preceding public-to-physical context conversion
as well, using the real shared X86_SIM_L_SKB_FIELD and CTX_NUMERIC macros.
The smallest scope is those two compiler stages; no guest or new runtime
validation is involved.

The normal stock frontend feeds compile-sim-ir, then the sole context-lower
with its public/physical layouts, then native O3 execution. Twenty-eight
cases cover data/data_end full bits and low/high lanes, plus a mark-field
control. Actual physical fields are populated in host buffers, with canary
bytes elsewhere. No packet pointer is dereferenced. Both intermediate IRs,
layouts, tool stderr and every executed row are retained.

Source review found an interaction to test: native memory lowering inserts
an opaque register barrier, while context lowering recognizes roots through
LLVM pointer-origin analysis. This is a hypothesis, not a confirmed defect.
A compiler/setup error must be distinguished from an executed mismatch.
The test establishes no corpus path hit, stock-B load or performance result.

The detached recipe waits timing SH/image SH, on CPU18 with4GiB AS. It
changes no production input and starts no image or guest. Heavy work waits
for the coordinator's active Tracee timing to release the lock.
