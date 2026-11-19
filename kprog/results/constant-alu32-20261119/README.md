# Constant ALU32 folding in B

Tetragon request 6 retains opaque ALU32 self moves of constant sizes and
helper IDs. The compiler cannot fold their subsequent dispatch branches;
the retained stack-pressure evidence is in `../tetragon-stack-liveness-20261119`.

The smallest fix extends the existing constant-identity pass to exact i32
`$0 = $0` templates with `=w,0` constraints and constant input. Live inputs,
memory clobbers, other widths, throwing and stack-aligned templates keep
their instructions. Shared I, native conversion, B flags, compiler/stock
stack limits and the frozen benchmark are unchanged. No new runtime check.

PERF 2026-11-19T11:31:24Z: The actual old compiler preserves all four constant
templates in the regression. After the fix, the sole checked-sim tools rebuild
through `make -C kprog/libnativeloader checked-sim-stage` under timing SH/image
EX. All four constants (8, 4, -1, INT32_MIN) fold to their exact i32 results;
live input, memory clobber and wide controls retain their asm. Both versions
emit a real BPF object. Raw baseline/candidate and build log are under
`/workspaces/kprog-raw/perf/constant-alu32-20261119/` with suffixes
`baseline-20261119T1130Z`, `candidate-20261119T1131Z`, and
`build-20261119T1131Z.log`. These checks establish the narrow compiler
contract, not new stock acceptance, native installation or runtime speed.

`run.sh` replays only Tetragon's retained O1 frontend through the new bounds
pass and unchanged O1 backend/packer/llc. It does not repeat the frontend or
the previous failed O3 hypothesis. Its input predates the recent shared-I
repairs, so successful emission would still require fresh app confirmation.
