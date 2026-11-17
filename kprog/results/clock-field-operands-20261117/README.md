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
forward repair. App per-call,
body/helpers/maps, throughput and installed native/JIT remain for Omp's
all-LTO image/check/target batch. PERF starts no guest or image.

Completed 2026-11-17T18:21:23Z: source `046786855` is pushed. Host
2700640 exited 0. The release suite passed 56 tests, with 3 existing
ignored tests. All 102 register/width/displacement cases and the 15
existing clock execution vectors pass, including both latch copies,
pvclock scaling, preemption bracketing and kernel-call paths. The three
supplied target values are retained in their E8 slots after local
compaction and final shared placement. All 223 unrelated leaf/metadata
files and 423 memory bodies are byte-identical.

The actual clock fixture is **247 versus 306 bytes**. Five zero-offset
fields save four bytes each; the other thirteen fields save three each.
The 59-byte difference changes no instruction count. The existing
`tkr_size` ADD immediate, GS absolute operands, checks, live reads and
arithmetic are unchanged. In this fixture the two preemption calls move
to offsets 166/228 and the kernel fast-clock call to 237; these are
layout results verified by the relocation tests, not new ABI constants.

The production change adds one net line and replaces the old displacement
helper with a wrapper around the existing encoder. The focused test
covers the REX base/register and byte/dword/qword cases that a generic
low-register operand test would miss. No new fixture driver, layout
framework or runtime policy is introduced.

Evidence: [host output](host-output.txt), [sizes](local-sizes.txt),
[disassembly](clock-disassembly.txt),
[relocation fixture](clock-relocations.txt),
[leaf/metadata comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt), [raw location](host-location.txt).
Recipe `c5ed77145` and all raw compiler/execution/publication output remain
at `/workspaces/kprog-raw/perf/clock-field-operands-20261117/host-20261117T182038Z-2700640`.
This local size result does not establish a per-call or installed-size
gain. Fresh complete load facts are the next pipeline task: the retained
239 historical plans lack the current schema's `cpu_tlbstate` field and
cannot supply a current six-app host replay. That limit does not imply
current application load failures.
