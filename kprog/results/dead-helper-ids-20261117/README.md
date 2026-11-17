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
