# Known ARRAY arithmetic

Source commit: `8a5dc48a9`; committed host recipe: `875451b49`.
Recorded after the successful host job on 2026-11-17 at 15:33:22 UTC.

The linker now uses the 64-bit IMUL imm8 form for positive non-power-of-two
strides through 127. Other supported strides retain their existing multiply
or shift. After scaling outside the SIB scale set, a nonzero value offset
and map-pointer addition use one 64-bit LEA, with a signed disp8 when it
fits. Zero offset retains the shorter ADD. The existing SIB scale forms,
unsigned bounds, index handling and per-CPU loads stay unchanged. No new
runtime check, refusal, switch, map fact, compile flag or module change.

The retained Katran shapes in
[the review](../lto-review-20261117/README.md) use stride 24 and value offset
304. Their arithmetic now emits:

```text
48 6b c0 18                   imul rax, rax, 24
48 8d 84 07 30 01 00 00       lea rax, [rdi + rax + 304]
```

This is 12 bytes and two instructions against the previous 16 bytes and
three instructions. The retained historical replay had two such shared
routines, an eight-byte local opportunity across those two routines.
This is not a measurement of today's installed application size.

`known_array_arithmetic_preserves_wide_products_and_displacement_signs`
executes 600 combinations: 15 strides, eight displacements and five indices,
including the signed immediate boundaries, u32 maximum index, full-width
products and negative sign-extended displacement encodings. It also decodes
six representative arithmetic forms and executes ten complete stride-24
lookups around the existing bounds for three-entry and 4096-entry maps.
These cases catch truncated EAX products, sign-extended stride 128 and a
changed displacement when replacing ADDs with LEA.

The full canonical linker suite passed **49 tests**, with three existing
ignored tests. All **202** retained probe/clock/UID payload and recovery
files compared byte-identical with the prior scalar-read run. See
[host output](host-output.txt), [comparisons](payload-comparison.txt) and
[raw location](host-location.txt). Raw inputs, patch, fixture outputs,
compiler log and publication logs remain under `/workspaces/kprog-raw`.

Per-call time, body/helper/map split, throughput and installed native/JIT
bytes are pending Omp's frozen-entry image/check/target-app batch. No guest
or image was started by this host job. Timing SH, image EX and Git EX were
held in order, with the tested source committed and pushed before releasing
the image lock. Next item: LPM XOR and displacement encodings, then the
known-large memset count, in todo section 0 item 1d.
