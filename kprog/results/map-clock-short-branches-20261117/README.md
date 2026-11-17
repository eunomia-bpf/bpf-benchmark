# LPM and clock routine-local branch sizing

Source `0ef3671ce`, committed recipe `a92176d1c`. Host job completed at
2026-11-17T16:47:47Z. This continues todo section 0 item 3 using the sizing
step already tested for probe routines. All existing LTO remains on.

The common sizing function now has sibling-module visibility. Clock passes
its existing helper relocations through it. LPM now passes its real helper
target into its builder and returns the mapped relocation, rather than
reconstructing the old CALL offset later. Each shared-leaf append adds its
final start offset once. No new layout framework, public schema or module
contract was introduced.

Every external CALL remains E8 plus four zero bytes until patched through
the existing relocation mechanism. Clock retains the two preemption-call
records and the original fast-clock target. LPM retains its generic helper
for the original map-type/data-size cases and the same stack alignment.
The sizing step changes local branch widths, preserving instruction order,
conditions, destinations, live memory reads, map work and fallback behavior.
It adds no per-call check, limit, refusal, flag, fact or option.

Actual local host bytes:

| Routine | Before | After | Saved |
| --- | ---: | ---: | ---: |
| clock | 341 | 306 | 35 |
| LPM | 284 | 243 | 41 |

See [sizes](local-sizes.txt). The LPM control already includes the prior
XOR/disp8 changes; this step measures the additional branch encoding only.
These are local fixture bodies, not application installed totals or a
measurement of per-call time. Instruction and map/helper call counts are
unchanged.

Validation under timing SH, image EX and one CPU-19 worker:

- Full canonical release linker suite: **54 passed**, zero failed, three
  existing ignored tests.
- LPM's **65,590** compressed-trie/prefix/guard/generic-ABI cases and
  **34,920** differing-bit/prefix/flag compact/wide-layout cases pass.
- Clock's **15** formula, latch, scaling, preemption and kernel-call vectors
  pass. Added slot checks verify all three real target records before
  execution and after adding the shared leaf's final offset.
- LPM slot checks verify the mapped generic helper target and the final
  global relocation offset exactly. Both modules retain incoming E8/E9
  shared-leaf call/tail semantics.
- The existing 24 synthetic sizing cases continue checking branch boundaries,
  mapped conditions/destinations, helper slots, protected loads, append
  offsets and sizing idempotence.
- **633** unrelated files compare byte-identical: 423 memory bodies and
  210 probe/metadata/LRU/ARRAY/UID/task files. This includes the 98 probe
  forms and their already remapped protected-load metadata.

[Host output](host-output.txt), [payload comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt) and [raw location](host-location.txt)
retain the evidence. All compiler, binary, source patch and publication
outputs remain under `/workspaces`.

The queued host job initially held timing SH while waiting for image EX
behind the batch-2 image build. It applied no source edits during that
wait, then tested and published under the locks. PERF started no image or
guest. Do not assume the ongoing batch-2 image includes this later source
commit merely because its summary reads a later Git HEAD; inspect its
actual shipped linker/build inputs when reporting the joined changes.

Per-call/throughput, equal work and installed native/JIT effects remain for
Omp's frozen-entry image/check/target-app batch. The frozen helper-prototype
wiring class remains with its owner. Next size work is the remaining shared
zero-tail opportunity and other eligible small helper encodings, after
checking their real caller/relocation contracts and current byte inventory.
