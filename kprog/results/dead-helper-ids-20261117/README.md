# Adjacent helper-ID loads

Inventory actual current captured proof inputs before changing source. The
existing linker resolves numeric helper identities from CFG provenance and
replaces register-indirect calls with bound helper calls or native routines.
An immediately preceding `MOV EAX/RAX, helper-ID` can become redundant when
that call no longer consumes RAX as its target and defines the return value.

The reader records actual helper-site diagnostics, function/call/move offsets
and immediate bytes. It separates tail calls: their miss path can retain RAX
before a return value is assigned, so this work leaves their state alone.
Counts are static per captured request set, not runtime frequency or installed
code size. Proof mode, finite helper dispatches, other registers, partial
writes and nonadjacent definitions need to retain their semantics.

Production changes, if justified by the inventory, belong only in the open
native_link helper-call path. Reuse existing numeric helper provenance,
immediate decoding and original-label remapping. Add no runtime check, flag,
helper catalogue or DCE framework. Body/helper/map/per-call/throughput and
installed-size effects require the owner image batch with all LTO on.

The first host job (2758708) was stopped by its exact waiting flock PID
2758713 at 21:11:36Z, before source apply, after confirming the canonical
main is used by the active checked Tracee guest (run_checked_otel.sh:13).
Its raw directories and exit143 log remain. Source was unchanged.
The forward recipe runs source tests under timing SH/image SH: Cargo's
test executable and raw fixture outputs are separate from the live main
CLI. After tests and byte comparison, it releases image SH and waits image
EX before replacing that main and replaying requests. It records the
actual source commit and patch at main-build time. No checked guest or
other owner's process is stopped, and no build output or source tree is
copied. The recipe is stable while it runs.

The source/unit-test stage completed at 21:13:43Z. The baseline compiled
and failed on its retained dead ID (cargo status 101). The forward change
passes **58 tests**, with three existing ignored tests. Its new regression
executes **56** argument/return/helper-count cases and seven proof shapes,
covering 32-bit, full-width and sign-extended immediates, branches, preserved
label definitions, nonadjacent definitions and a different target register.
It separately executes a tail miss and preserves its existing RAX state.
All **647** unrelated payload/metadata files remain byte-identical.

The production change reuses the existing helper ID/name mapping and immediate
decoder, requiring an adjacent EAX/RAX definition that matches the resolved
helper and has no code-entry label or patch. It keeps direct/table labels.
Proof and finite dispatch return before this optimization; tail-call stubs
also keep their previous state. The generated kernel code loses an immediate
move on eligible calls; it adds no runtime check or instruction. No helper,
map operation, recovery, ABI, flag policy or source memory barrier changes.

The current main remains the prior built version (size 2,978,744 bytes,
mtime 1794948232); `live-main-after-tests.txt` records this after the shared-lock
test stage. The running host job now waits image EX before replacing it and
replaying 295 requests. **That replay and actual emitted-byte comparison are
pending**, as are image publication and app installed-size/per-call/body/helper/
map/throughput measurements. The static inventory has 59/444/1643 ordinary
sites in Katran/OTel/Tetragon; branch-label filtering can retain some of them,
so those counts are not actual removal or installed-size measurements.
