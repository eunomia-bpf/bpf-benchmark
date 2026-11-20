# Actual entry Numeric support and MOV_IMM dispatch

The sole `Arm64ProgramEntryLinked.program/ge` now links all three complete
existing exports: Arm64ProgramFixture, Arm64Program and Arm64Numeric, through
Clean's imported linker. The cached lists contain only original source-row
references. The kernel checks the complete nested link, including signatures
and composites; no helper body or external-call return is postulated.

The resulting world has 210 definitions and global frontier 211. It retains
14 composites, every original fixture identifier in order, and all fixture
composite layouts. The complete support merge appends 13 definitions and
resolves matching external declarations. In particular, selector 98 is now
the real `Arm64Numeric.f_kprog_arm64_mov_path`. Initial memory and production
native input admission remain separate from the global frontier.

The shared MOV_IMM dispatch proof takes only its actual world, width binding
and selector binding. Its old Numeric-world APIs instantiate the same proof.
The actual entry instance uses width 97 and selector 98, allocates the real
generic locals, and reaches the scalar branch in 54 internal transitions.
It retains the original caller frame and derives the actual read/write
input temporaries. Its operand template has destination 1, SRC32, NONE for
both secondary sources, FLAGS8, AUX0 and an unrestricted widened uint32 mark.

The cold-SP suffix and previous linked MOVK call are rechecked in this same
world. The previous suffix receipt keeps its historical source/validation
checkpoint; its runnable query now checks the internal selector binding.
Joining the dispatch and framed cold-SP suffix at their allocation frontier,
freeing the actual generic frame, and extracting the fixture callsite and
successor remain M5 work. No complete fetched ISA family is closed. Production
provider availability/frame, physical-memory/ABI admission, unrestricted
native MOV_IMM/MOVK instruction composition and other families also remain.

Validation: source link/bindings 43 jobs, shared dispatch 180 jobs and actual
entry 224 jobs pass. Thirteen public type/axiom queries and the previous
suffix receipt's six public queries plus its updated closed binding query pass.
Records are in validation.json. Focused checks use CPU 17, nice 0,
one worker, 32 GiB address space and original proof caps. The whole `lake build KProgFormal` proof
library/root passes 273 jobs on CPUs 16–23, nice 19, one worker and 32 GiB
address space. Executable/tool builds are excluded under the current directive. Raw logs remain in
`/workspaces/kprog-raw/formal/m5-entry-support`. M5 and M6 remain open;
completed ISA-family count is zero.
