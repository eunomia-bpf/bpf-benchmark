# LRU reference-byte operand encoding

Source `26fc730d5`, committed host recipe `7b94f17df`. The host job ended
successfully at 2026-11-17T16:17:25Z. This is the independent open-linker
encoding follow-up from the retained LTO review, under todo items 1e/3.
The helper-context frozen-class finding remains with its coordinator owner.

One common emitter replaces the separate CMP and MOV emitters. It chooses
no displacement for zero, signed disp8 when fitting, otherwise the original
disp32 representation. The u32 field retains the same signed-displacement
interpretation, including negative representations. The opcode, CMP flags,
operand width, RAX base and immediate byte remain identical.

Both instructions execute the same live LRU reference-byte operation:
check for zero, then store one only when it was zero. The existing lookup
null guard and value-pointer adjustment remain. No map lookup or reference
write was removed, no nonzero value is normalized, and the instruction
count is unchanged. No new per-call check, flag, fact, limit, public schema,
module, kernel or benchmark change was introduced. All LTO stays on.

With the retained Katran reference offset 35, the two operands together
shrink 14 to 8 bytes. The complete same-shape host postprocess with value
pointer offset 24 shrinks **25 to 19 bytes**. A zero reference offset gives
17 bytes; offsets 128 and 255 retain 25 bytes. See [sizes](local-sizes.txt).
These are local generated-region sizes, not installed application totals.
The retained pre-f45 Katran blob used generic LRU dispatch, so it is not
evidence this typed postprocess executed at every historical lookup.

Validation under timing SH, image EX and one CPU-19 worker:

- Full canonical release linker suite: **53 passed**, zero failed, three
  existing ignored tests.
- **60** decoder comparisons cover CMP/MOV, three immediate values,
  zero/small/large displacements and signed 32-bit representations. They
  check address, immediate and flags against the original disp32 form.
- **32** executable reference-state cases cover eight offsets and four
  initial reference values. Each checks null return, exact value pointer,
  mutation of only a zero reference byte, and idempotence.
- The existing typed-map test additionally makes a nonzero-reference node
  read-only. A redundant same-value store would fault; the test passed.
- **204** prior probe/ARRAY/LPM/clock/UID payload/recovery files and **423**
  small, dynamic and known-large memory bodies compare byte-identical.

[Host output](host-output.txt), [payload comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt) and [raw location](host-location.txt)
retain the evidence. Raw source patch, generated binaries, compiler and
publication logs stay under `/workspaces`. No guest or image was started.

Per-call time, throughput, invocation mix and installed native/JIT bytes
await Omp's image/check/target-app batch. A six-byte local encoding saving
is not presented as a measured speedup or a reduction in intrinsic map
work. The remaining size priorities are per-program leaf needs, local
short branches and shared zero tails; actual helper-prototype parity stays
ahead of further event-helper specialization.
