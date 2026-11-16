# Actual x86 producer stack profiles

`make clight` assembles one 14-instruction native fixture at frame sizes 200 and
376, then runs the actual x86 parser, definedness analysis and renderer. The
producer derives 25 or 47 separately named stack fact cells. Its C output stays
in the normal build directory; the driver relocates only its relative header
include. Both actual program translation units, including all inline handler
bodies, export with the existing CompCert `-fstruct-passing -lean -normalize`
route. The preincluded section facade retains libbpf's section/used attributes
without declaration-splitting pragmas. No production simulator C or generator
is changed by this step.

Both exports contain 122 internal bodies: 24,688,374B at 200 bytes and
28,917,884B at 376 bytes. Re-exports are exact, including after reducing the
extraction facade to its used CompCert branch. All 15 earlier exports remain
byte-identical. `make clight`, all 17 Clight modules/54 Lean jobs, the actual
layout checks and eight standard-axiom queries pass without increasing limits.

The program spills a stack pointer to the first and last frame words, overwrites
the first slot, recovers through the last slot and another spill, then folds its
native numeric high bits into its return value. Independent expectations check
32 stack bases and every explicit input. A separate live-entry oracle compares
every bound reference with its actual named local, then recovers a distinct
pointer from every fact cell and clears facts without changing private bytes.
Private bytes are written before reads. Native and CompCert-adapter executions
use UBSan; their complete return/input captures are compared per profile.

Each mode passes 32 program cases and 800 or 1,504 live fact reads. The complete
program capture is 19,200B or 27,648B per mode, with 49 or 71 inputs per case.
All three negatives fail with the intended mismatch and the rebuilt normal
capture is exact. Default BPF fixture allocated sections/relocations match
historical inline header `b7d97f2a9` and ordinary current compilation: socket
4,832B or 5,184B, each with 24 allocated relocations. The source fixture is
current in all three compilations; this does not reconstruct historical app
objects. Formal preprocessing is 2,820,197B or 3,083,582B for generated sources
of 3,056B or 3,194B. These are extraction translation units, not application
compile-time, stock-verifier or performance results.

`results/m4-x86-producer-profile/compare.py --output <new-raw-directory>` repeats
the captures and three in-memory negatives: all fact references aliasing slot
zero, the handler reading pointer slot zero, and truncating the native stack
base. The normal executable is rebuilt and its capture rechecked afterward.
No edited source copy or additional interpreter is retained.

The Lean check `lake env lean -j1 oracles/test_x86_producer_profile.lean` uses the
mature library's composite-environment construction and size calculation, and
checks the actual entry's named-local types. It is a computation over exported
Clight data. It is not a handler refinement. The accompanying JSON records the
completed checks and exact export sizes; full logs and captures remain under
`/workspaces/kprog-raw/formal/m4-x86-producer-profile`.

These fixtures extend the earlier 64-byte inline export with two actual
producer capacities and their scalar-fact declarations. They do not establish
all programs, helper-callee effects, stack-disabled behavior, platform/memory
correspondence or whole-default compiled-byte coverage. M4 remains open. All
2,065 M5 refinements and O1/O2/O4 recounts, M6 retirement and final whole-library
`lake build` plus `make check` remain ordered work.
