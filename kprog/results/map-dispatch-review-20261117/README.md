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
