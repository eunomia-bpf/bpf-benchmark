# Clock field operand widths

Eighteen field operands in the shared fast-clock routine use fixed disp32.
The same encoder used for memory, UID, LPM and runtime ARRAY can encode
their actual zero/short offsets. The old displacement helper becomes a
field wrapper; the existing signed-offset conversion remains. The one
nonmemory immediate (`tkr_size`) stays separate, with its original bytes.

The minimal change reuses that encoder for the existing ModRM operands.
GS absolute operands, addresses, loads, arithmetic, latch/version loops,
preemption handling, stable/cycle checks and real kernel helper calls
retain their semantics. There is no new encoder, layout fact, per-call
check, flag, limit, helper identity or ABI.

A focused decoder test covers 17 distinct opcode/register/width forms
through R8/R9/R10/R11, at offsets 0/1/127/128/4096/i32::MAX.
The existing 15 clock formula/preemption/fallback execution vectors run,
and all three actual-target external E8 slots are checked both before
and after sharing. Existing branch compaction moves the relocations;
append adds the global offset once. No new driver or test framework.

`run-host.sh` takes timing SH then image EX before source apply/build on
CPU 19 with one worker and 32 GiB address space. Actual outputs go to
`/workspaces/kprog-raw/perf/clock-field-operands-20261117` and survive any
failure. The applier is one-shot; an applied-source failure needs a new
forward repair. Host results and local sizes are pending. App per-call,
body/helpers/maps, throughput and installed native/JIT remain for Omp's
all-LTO image/check/target batch. PERF starts no guest or image.
