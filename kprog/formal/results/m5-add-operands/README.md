# Actual linked ALU operand readers

Arm64AddOperandReads proves the original raw SP pointer reader in 21 internal
transitions, the SP tag reader in 15, and the complete combined reader for
XZR31 and NONE255 in 55. The SP pointer result retains the signed-relative
raw bits; the tag is STACK4. The sentinel paths follow no entry/cache pointer.
Every result retains exactly the same memory and the actual callCont.

Linked.bindings checks the genuine pointer/tag/combined definitions at
blocks 104/65/66. Linked.sp_reads applies the existing actual merged layout and
derived Storage reads. Linked.sp_native identifies the stored relative offset
with the already established native SP relation; no separate address premise
or second producer/provider run is introduced.

Source inspection corrects the preceding handoff: exported generic statement
s_kprog_arm64_program_execute_15 calls the ALU source selector and conditionally
chooses IMM versus the SRC2 reader/modification loop. ADD_IMM takes IMM and
skips SRC2. The runtime macro argument list alone did not establish exported
control flow. The exported ALU result is also an inline switch in statement17,
not a call to the separate Numeric result wrapper. The next RHS proof follows
these actual statements. The zero-reader certificate supports the general
register/sentinel path; it is not a claim that ADD_IMM calls that reader.

Focused checking passes 226 Lake jobs and six public type/axiom queries at the
original 200000-heartbeat/512-depth caps, CPU17, nice0, one worker, 32GiB address
space. Whole `lake build KProgFormal` confirmation passes 290 jobs including the root,
on CPUs16–23, nice19, one worker and 32GiB address space. Count.lean
records exploratory execution counts; theorem statements/proofs independently
check the exact paths. All failures and timings remain under
/workspaces/kprog-raw/formal/m5-add-operands.

Complete ADD dispatch, arithmetic, writing, allocation/free, original source
continuation and fetched LNSym composition remain M5 work. O1/O2/O4 and M6
remain open; completed ISA-family count is zero.
