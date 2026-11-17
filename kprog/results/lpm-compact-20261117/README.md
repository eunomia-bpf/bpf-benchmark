# LPM prefix and displacement encoding

Source commit `a9bfdebb7`; committed recipe `d53dff9ca`. Successful host job
ended at 2026-11-17T15:40:24Z. The change follows todo section 0 item 1d and
the retained source/byte analysis in
[the LTO review](../lto-review-20261117/README.md).

On the existing nonzero 64-bit difference path, BSR/NEG/ADD becomes
BSR/XOR 63. On the nonzero 32-bit difference path it becomes BSR/XOR 95.
The BSR domains are 0..63 and 0..31 respectively; these compute the same
leading-prefix counts. The following clamp CMP supplies the later flags.
Equal keys, short prefixes and zero-difference branches retain their
existing handling. One instruction and two bytes disappear from each BSR
case; only the case actually taken gains an executed instruction.

The LPM memory emitter now selects disp8 for offsets through 127, including
zero, retaining disp32 outside that range and the same existing supported
offset range. Each call identifies its ModRM byte explicitly. Both indexed
forms preserve their SIB bytes, scale, index and base registers. Branch
positions and the remaining generic E8 helper relocation follow the final
emitted layout. No runtime check, fact, flag, switch, refusal, public schema,
module or kernel change was added.

The same host fixture layout emits **284 bytes**, previously **330 bytes**:
42 bytes saved across fourteen memory operands, and four across the two BSR
cases. See [local sizes](local-sizes.txt). This is a local routine comparison;
known LPM sites bound directly to the kernel operation do not execute this
routine, and no installed application size reduction is inferred.

Validation under timing SH, image EX and one CPU-19 worker:

- Full canonical release linker suite: **51 passed**, zero failed, three
  existing ignored tests.
- **98** decoder comparisons across all fourteen memory forms and seven
  displacement values. These check register identities, operand widths,
  displacement values, SIB addressing and the 127/128 boundary.
- **34,920** actual compact/wide-layout executions covering every first
  differing bit, equal keys, query/node prefix clamps, invalid query prefix,
  and normal/intermediate flags, against an independent bitwise reference.
- Existing C fixture: **65,590** compressed-trie, prefix, guard-page,
  unaligned-key, live-root and generic-helper stack-ABI cases.
- **203** prior probe/ARRAY/clock/UID payload and recovery files remain
  byte-identical. Shared E8/E9 bindings and the final generic E8 relocation
  are covered by the existing sharing test.

[Host output](host-output.txt), [payload comparison](payload-comparison.txt)
and [raw location](host-location.txt) retain the receipts. Raw binaries,
fixture output, source patch and publication logs remain on `/workspaces`.
No guest or image was started. Omp schedules the frozen-entry image/check/
target-app timing; per-call body/helper/map split, throughput and installed
native/JIT bytes remain pending. Next: preserve known counts above 512 for
compact memory loops without fully unrolling them.
