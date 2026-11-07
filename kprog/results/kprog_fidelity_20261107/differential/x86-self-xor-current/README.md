# Independent CPU coverage for same-register XOR

The preceding 1080-form matrix contains no same-register XOR operand form.
It therefore cannot independently test the new production self-zero gate.
The existing F generator now includes all 16 general registers at
8/16/32/64-bit widths: 64 new real native instruction forms, 1144 total.

The existing Make generation target has assembled and production-encoded all
1144 forms successfully. Removing the 64 new forms leaves the preceding 1080
assembly rows in exactly their original order. All new forms select the
production ALU_REG operation; encoding-preflight.json records every form.
The source snapshot's d30 header matches published commit af2f58c89 exactly.

The preflight established assembly/encoding coverage. The real CPU/C phase
has now completed: 1144 forms x 1024 cases = 1,171,456 states, with zero
CPU/C differences. The 64 new self-XOR forms cover 65,536 states, including
4096 SPL/SP/ESP/RSP states, all with zero differences. forms.tsv records all
per-form counts; self-xor-cpu-forms.tsv extracts the 64 additions.
Canonical-reference replay has also completed with zero CPU/reference and
C/reference differences, and zero unavailable forms.
The existing observer restores native RSP through a RIP-relative saved base
before touching the stack, allowing SPL/SP/ESP/RSP zeroing to be observed.
No producer, simulator, reference semantics, flag mask or runtime policy changes.

The queued real validation command is:

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=x86
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-popcnt-memory/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/x86-self-xor-current
~~~

The follow-up waits for the already running base-matrix build before using the
same incremental build cache. Its canonical executable is the existing frozen
F/reference-control-frozen; it does not rebuild another lane's Lake cache.

## Completed CPU phase

The exact compiled static binary SHA256 is 02bec25ed8c300a99ee52d5af41a0fd057aeec9bdaee2f3706a426c249a7598f.
All 90 captured compilation files match their archive hashes; all 82
copied production sources match af2f58c899d99f4092a710734ceb4cdac2b5e6df.
The generator matches 820ef1f034a479261500069b70aab93512c93eae. Removing the
64 additions preserves all preceding 1080 assembly rows in order. These
identities describe the d30 snapshot, irrespective of subsequent owner edits.

The unchanged observer compares captured GPRs, XMM0, 64 stack bytes, 256
external-memory bytes and defined arithmetic flags. XOR AF is architecturally
undefined and retains the existing mask. The empty CPU counterexample stream
is retained losslessly in mismatches.jsonl.gz. This is enumerated form and
sample evidence; it does not establish every possible encoding, whole ABI,
application behavior, or O1–O4 theorem closure. No fresh CPU rerun was needed.

The earlier CPU-only review did not inspect the terminal replay files and
incorrectly described the job as still running. The replay actually finished
at 2026-11-07T18:26:02.451104+00:00, before that review. This final review checks
the actual exit and every reference row; it supersedes the pending status,
while preserving the earlier CPU observation time in cpu-verification.json.

## Completed canonical replay

The enclosing Make/reference job exited 0. Every one of the 1144 forms has
1024 canonical cases: 1,171,456 total. CPU versus canonical and production C
versus canonical both have zero differences; zero forms are unavailable.
The 64 self-XOR forms have 65,536 checked states, including 4096 for SP-family
registers. reference-forms.tsv and self-xor-reference-forms.tsv hold the counts;
both compressed canonical mismatch/unavailable streams are empty.

The frozen reference SHA256 is c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96.
Its exact bytes match the already published
[canonical executable](../x86-current-matrix/canonical-reference.gz), independently
checked against its Git blob; summary.json records the publication and hashes.
This reuses the existing reference executable; it does not claim to rebuild
later canonical source changes. replay-controls.tar.gz retains the review-time
adapter (identical to its prelaunch published version), Make command and F
control script. It is a retrospective control copy, not a new import-time capture.

The original 2127364120-byte CPU trace remains in this Workspace
(SHA256 aca046e4889c8e66ec007ed14a6c2dc1ddc91cb5b05cbb6fede841e641fc1341). Its binary layout and full
length match all 1144 x 1024 records. The actual static CPU binary and compiled
input closure were published in 18c2c062957954413589e7e1a4780b484909dc40 and
are rechecked unchanged here. No CPU rerun, oracle relaxation, production or
reference edit was required for this completed result.
