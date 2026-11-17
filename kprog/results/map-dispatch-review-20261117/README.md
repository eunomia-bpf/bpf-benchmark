# ARRAY and LPM dispatch frames

Read-only follow-up to LTO review finding 4 while the canonical linker rebuild
waits for the checked guest. No source, build, image or guest changes.

The current ARRAY routine (`x86_runtime_array.rs:35–43`) ends its non-ARRAY
path with `SUB RSP,8; CALL helper; ADD RSP,8; RET`. `share` redirects that
call to LPM (`x86.rs:1832–1868`). LPM's generic path has another such frame
(`x86_lpm_lookup.rs:79–83`). Both algorithms otherwise return directly.

The frozen direct module requires an exact E8/zero-displacement external
slot (`direct-native/bpf_x86_native_lab.c:222,250–257`). Existing E9 support
in `probe_read::redirect` is for local redirection and does not establish
external E9 relocation support. Preserve this ABI; no module/kernel edit or
new helper-pointer workaround is proposed.

A possible open-path optimization is to append the existing LPM body directly
to the ARRAY prefix, so the non-ARRAY branch enters LPM without its own CALL,
stack adjustment or RET. The final generic E8/aligned call remains. Both
prefixes would keep the same live map-type/shape reads, key semantics and
return values. A fused generic path would remove one internal call/return
pair and two stack adjustments; successful ARRAY work would stay the same.
The existing ARRAY fallback frame is 14 bytes. This is a static opportunity,
not a measured app or installed-code saving.

Implementation, after the current dead-ID build/replay finishes, should reuse
these existing emitters in the open native_link tree, with no new dispatcher
framework, type checks, switch, kernel ABI or app-specific rule. It needs
production-path tests for ARRAY/LPM/generic results, argument preservation,
CALL/JMP entry transfers and exact stack alignment at the final helper,
plus relocated load/branch metadata and per-app measurement with all LTO on.
Do not mutate Rust while the queued per-change main build is pending.

The actual retained byte inspection finds the full two-frame shape in
**162 of 295** request images. Every observed ARRAY fallback CALL points to
the appended LPM entry, and each LPM fallback retains the aligned E8 frame.
The other requests remain listed without this shape; absence of these ranges
is not absence of helper or map work.

| App | Captured requests | Both dispatch ranges | ARRAY frame bytes in those requests |
| --- | ---: | ---: | ---: |
| OTel | 14 | 3 | 42 |
| BCC | 25 | 0 | 0 |
| Cilium | 47 | 24 | 336 |
| Tetragon | 39 | 18 | 252 |
| Tracee | 169 | 116 | 1,624 |
| Katran | 1 | 1 | 14 |

The summed 2,268 bytes are the existing ARRAY fallback frames in this request
set, not an achieved saving or installed-size result. Per-call importance
needs dynamic helper-path data and the affected-app timing. All final
relocation records and raw bytes are retained in `dispatch.json` and the
referenced original output directories. No source transformation was applied.

The smallest implementation would reuse the ARRAY prefix and existing LPM
routine in one emitted sequence when both layouts are present. Preserve
standalone ARRAY-only and LPM-only facts handling; these are existing layout
availability cases, not a new user switch. Emit one final generic external
E8 slot and remap all existing load/branch/relocation offsets. Avoid letting
the later LPM sharing step wrap that same fallback again. Keep the first
entry label and both CALL/JMP source transfers correct. Tests should verify
that generic callback arguments/count and RSP alignment match the old chain,
with ARRAY/LPM live-value/bounds semantics unchanged. Actual source work waits
for the current per-change replay so its attribution remains separate.

## Functional ABI preflight

Recipe `370eea291` executes the actual retained Katran ARRAY/LPM byte
ranges with their captured kernel layout fields. The old chain's internal
call is relocated to a contiguous fragment; the candidate removes only its
14-byte ARRAY fallback frame. Both use the same LPM bytes and final external
E8 slot, patched to a nearby host test callback. No real kernel helper or
full application body is executed and no production source is changed.

Host job 2770937 completed successfully at 21:46:07Z: **6,832 cases pass**,
1,708 each for old/fused fragments through CALL/JMP entries. Cases cover live
ARRAY bounds/mask/wide products and guard-end u32 keys, LPM prefix/flags/
matching and invalid-prefix/root behavior, unaligned and guard-end keys,
and generic type/data-shape delegation before an inaccessible key is read.
Each form has 50 generic callbacks; their map/key arguments are unchanged,
the count is exactly one per delegated lookup, and entry RSP alignment is
8 modulo 16. The fused generic callback is 16 stack bytes shallower, with
one fewer internal call/return and stack-adjust pair.

The retained chain is 307 bytes; the test fragment is 293 bytes. These are
extracted functional test artifacts, not a production transformation,
installed-code reduction or per-call speedup. Raw old/fused bytes, test entry
bytes, actual input/layout record and output stay at `preflight-location.txt`.
The running canonical-linker job and checked guest were untouched.

The existing LPM production host test source is
`kprog/build/test-lpm-lookup.c`, not the guessed fixture path in the earlier
handoff; this preflight required no change or source copy of that file.
Production implementation and its Rust/kernel-relocation/whole-app checks
remain next, after the queued per-change rebuild/replay ends.
