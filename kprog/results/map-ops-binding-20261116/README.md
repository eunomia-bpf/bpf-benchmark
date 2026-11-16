Map update/delete binding, 2026-11-16

The loader queries actual operations for the original program's known map FDs
and the operations it uses. Link-plan facts use the existing loaded map ID to
bind each native symbol. The x86 linker selects the operation from the native
map argument's provenance, including resolved direct sibling transfers. Unknown
map arguments retain the generic helper. No source/native call ordinal is used.

The old small-array update emitters are removed on both architectures. Arm keeps
generic update/delete calls until it has sound native argument provenance.
The existing FD query is extended for delete in the direct and registered modules.
No map type catalogue or per-call check is introduced. Kernel ops preserve full
64-bit flags, error ordering, locking and map-specific side effects.

Run `make -f kprog/results/map-ops-binding-20261116/Makefile host` on CPUs 16-19.
The focused linker regression reverses map order and covers numeric, PLT and GOT
calls and direct sibling transfers. Indirect branches conservatively erase map facts.
The host batch also builds the production linker and loader and syntax-checks
the active direct and registered x86 modules with the sole canonical build's
compiler flags and the direct module's existing Kbuild include directory.
The historical kinsn modules receive the same query extension; their full builds
are outside this x86 host subset.

Image 6641a7e1 remains held for C's breadth round. Installed size, actual FD-query
guest behavior and per-call effects await coherent publication after that round.

Host result: 49 linker tests pass, with 3 existing ignored tests; production
linker and loader builds pass. Controller 1830756 completed at 18:12:40Z with
exit 0. The active registered module's saved-command syntax check passed in
that batch. Both active x86 module sources pass the extended syntax recipe in
`/workspaces/kprog-raw/perf/20261116-map-ops-binding/syntax-retry`.

Raw evidence is under `/workspaces/kprog-raw/perf/20261116-map-ops-binding`.
The initial controller 1829997 exited 2: 48 existing tests passed and the new
fixture's raw numeric sibling jump hit the existing unresolved-indirect-branch
refusal. The narrowed fixture covers numeric, PLT and GOT calls plus a direct
PLT sibling transfer, without bypassing the real proof route for indirect
sibling jumps. A separate syntax attempt omitted the direct module's Kbuild
include directory; its failed log is retained in retry1/module-syntax.log.
The final syntax retry adds that existing include. Neither diagnostic failure
changed production helper support or the frozen image.

The ten production/test source paths together remove 329 lines net, including
the new focused regression. This is a source-size delta, not an installed-byte
measurement. In registered loads without original source FD facts, and wherever
native map identity is unknown, update/delete remain generic; no address is
guessed from a truncated name or source call ordinal.
