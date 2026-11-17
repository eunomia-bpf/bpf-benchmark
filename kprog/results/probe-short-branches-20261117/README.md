# Probe-local branch sizing and recovery offsets

Source `d92c85898`; initial recipe `b1dd73b62`; publication filename repair
`4cda301b1`. The existing iced-x86 encoder sizes the user/kernel scalar and
string routines before their builders return bytes and metadata. All
existing LTO stays on; no new option or default-off path was added.

The sizing step maps old instruction starts to the encoder's new offsets.
Nested helper relocations and protected source-load offsets use that map.
Existing append then applies the final blob-start shift once. Protected
instruction length and destination register are unchanged. External helper
CALL slots remain E8 plus four zero bytes for the existing kernel patcher.
Compat dispatch still constructs its external leaf jumps from the actual
final leaf positions; it is not passed through zero-origin sizing.

Instruction order, branch conditions and destinations, policy, source reads,
error codes, full error zeroing and caller ABI remain intact. This does not
remove a policy check or a branch instruction. It changes branch encodings
where the distance fits and retains long forms where necessary. No new
runtime check, refusal, limit, fact, flag, public schema, module, kernel or
benchmark change was introduced.

Actual local host bytes:

| Form | Before | After |
| --- | ---: | ---: |
| generic kernel, wide globals | 362 | 296 |
| generic kernel, compact globals | 351 | 285 |
| generic user, wide globals | 366 | 292 |
| generic user, compact globals | 355 | 281 |
| kernel string, compact globals | 267 | 221 |
| user string, compact globals | 385 | 313 |
| fixed 8-byte kernel, compact globals | 221 | 179 |
| fixed 8-byte user, compact globals | 225 | 179 |
| compat scalar pair and dispatch | 819 | 679 |
| compat string pair and dispatch | 765 | 647 |

These are complete local fixture payloads, including their RET, not installed
application totals. Compat savings come from its reused leaves; its dispatch
still performs the same domain selection. All 98 form sizes and protected
load mappings are in [sizes-and-loads.json](sizes-and-loads.json) and
[sizes.txt](sizes.txt). Per-call/throughput and installed native/JIT effects
remain for Omp's frozen-entry image/check/target-app batch.

Validation:

- Full canonical release linker suite: **54 passed**, zero failed, three
  existing ignored tests.
- **24** synthetic mixed-edge cases cover short-branch boundaries,
  forward/backward edges, helper relocation slots, protected loads and
  appending after zero or eleven existing bytes. They compare mapped branch
  destinations and condition codes, check sizing idempotence, and execute
  null and one/three-iteration paths through a patched helper CALL.
- The existing host read matrix executes the actual compacted builders:
  scalar/string, user/kernel, compat, 88 fixed-count combinations, policy,
  nesting, SMAP cleanup, partial faults, source-load recovery and full error
  zeroing, with both compact and wide live-global forms.
- All **98** old/new probe forms retain protected-load bytes, instruction
  lengths and recovery destination registers at their mapped offsets.
- **439** unrelated files remain byte-identical: 423 memory bodies and
  16 ARRAY/LPM/LRU/clock/UID/task payloads. Probe bytes and site offsets
  intentionally change; they are checked by mapped instruction identity
  and real execution rather than an obsolete byte-identity expectation.

See [host output](host-output.txt), [load comparisons](load-comparison.txt),
[other payloads](payload-comparison.txt), [memory](memory-comparison.txt) and
[raw location](host-location.txt). Source patch, binaries, metadata and all
compiler/publication logs remain under `/workspaces`.

The first host workflow exited 1 **after all tests and comparisons passed**:
its `git add` attempted an ignored `.log` receipt. That failed publication
is retained in the raw launcher/progress logs. The forward recipe repair
publishes the same receipt as `.txt`. `publish-tested.sh` committed/pushed
the already tested source at 16:32:50Z without changing code or repeating
the full tests. Existing staged peer files were preserved by explicit-path
commits. Timing SH, image EX and Git EX serialize source testing/publication;
CPU 19 and one worker were used. No image or guest was started by PERF.

The outstanding helper-prototype wiring class remains with its frozen-code
owner. Next independent size work can reuse the proven local sizing step
for other eligible generated helpers, while preserving their external call
and addressing contracts. Do not apply a zero-origin pass blindly to an
external-target dispatcher or infer app speed from local byte savings.
