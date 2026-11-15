# Continue the normal pipeline from completed LLVM

2026-11-15T10:49UTC. The expensive optimized frontend is measured separately
while diagnosing OTel. Continuing it should not repeat the same frontend.
06a15fa2f factors the normal bounds/MIR/all-pairs/llc commands into shared
functions. `compile_simulator` still calls those exact commands in the same
order, with the same normal flags. The diagnostic continuation calls the same
function after matching the completed frontend and source identities. It
does not introduce another B strategy or optimization switch.

The existing native-store suite passes512 CPU/shared-C cases and all16 normal
B allocated section hashes match the immediately preceding pipeline outputs.
f05269a4a then continues two actual optimized frontend files (one narrow
immediate/indexed store and one full-width register/indexed store) through
bounds lowering, MIR, sole all-pairs packing and llc. Both B allocated outputs
match normal compilation. Six incomplete/wrong-LLVM/wrong-source identity
cases fail before invoking any compiler and leave the B output unchanged.
The fixture identity records describe the real normal native-stores LLVM
files; they are not OTel frontend measurements. Exact commands, all positive
and expected-error results and hashes are retained here.

Use `make -r -f kprog/test/native-relocations.mk current-otel-backend`
with `OUTPUT` for logs. `FRONTEND_PROFILE` selects the completed raw frontend
record; the default is the queued current-store attempt's `result.json`.
The command uses the sole `otel-whole-word-checked` build, normal flags and
16GiBAS/CPUs8–11. It requires the actual matching completed LLVM product and
source, so replacing the canonical build cannot silently resume an old record.
It stops after B generation; kernel acceptance and application startup remain
separate work. Pure LLVM/backend processing needs no timing lock or guest.

At10:49UTC the width-only OTel frontend911032 is still running, and current
source frontend921682 remains queued behind its launcher ending. No actual
OTel backend continuation is claimed. Preserve both runs and inspect their
completion logs before using a completed matching frontend. No extra OTel
job, build, image or base was created; all LTO stays on together.

Raw: `/workspaces/kprog-raw/perf/20261115-frontend-resume` (launcher927027,
Make0). Only logs/results/identity records are archived here; all compiled
fixture products remain in their existing canonical `store-writeback` build.
