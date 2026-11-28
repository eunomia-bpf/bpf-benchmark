# Tracee shift controls and field-existence mismatch

The two actual native frontend objects contain **20** previously unresolved shifts (10 per ISA). Sixteen amounts are locally bounded; four of those produce the **wrong kernel flag masks** because the common native header folds CO-RE field existence to true. Four remaining shifts need kernel-input/relocation evidence. This is a bug/alignment audit, not timing or a full parity result.

Newest order followed: **COORDINATOR 2026-11-28T11:20Z**. It arrived during this audit and prioritizes Tetragon's installed-code regression, then BCC stats-off. This completed evidence is published before switching tasks. OTel remains frozen at2689a430. No common fix, image or guest change was made here.

## Confirmed defect (both architectures)

`send_bpf_perf_attach` starts with KPROBE/UPROBE bits5/6, switching to6/7 only if BOTH `trace_event_call.filter` and `.module` exist. Current x86 and arm64 kernel BTF has **no filter**, and has module in an anonymous union. Both BTF flag enums are KPROBE32/UPROBE64. The common `native_compat.h` non-Tetragon `bpf_core_field_exists` is constant1. Actual native mem2reg IR therefore contains `shl i32 1, 6` and `shl i32 1, 7`, masks64/128 instead of32/64. These amounts are in range; the error is the selected masks, not an oversized shift.

The expected CO-RE branch follows the target BTF and matches the actual kernel enum. This confirms a native frontend configuration error. We have **not** claimed that this helper was exercised, that an installed native machine instruction was observed, or that a corresponding loaded traditional BPF instruction was decoded in this step. The objects and both full kernel hashes are in preparation/controller records. No application-specific guard or flag patch was introduced.

A common repair must resolve field-existence probes from target BTF before optimization. The existing Tetragon exceptions also compensate synthetic flavor layouts; replacing them blindly with BTF booleans could activate wrong field offsets. That general resolution/relocation work is still unimplemented. `--kernel-btf` already supplies the target to the shared compiler, so no per-app policy or new architecture flag is justified.

## Twenty-site accounting

Per architecture, two buffer shifts use i0..5 or type<=TIMESPEC_T15, one get-num-fields shift uses i0..5, two fd-filter shifts use0..2/16..18, one standard-fd shift uses0..2, and two perf-flag shifts are literal6/7. These give8locally bounded sites per ISA, including the2wrong flag selections.

One socket shift per ISA uses a volatile byte from `get_sock_state`. Normal TCP states1..13 would bound it, but the native frontend DWARF puts skc_state at byte14 while the target BTF puts it at18. The full helper IR is retained. Final linker relocation and the installed read must be checked before treating it as the right kernel field or asserting a live layout bug.

One helper-ID shift per ISA takes signed int from kprobe registers or `insn->imm`. The local code subtracts64 in a4iteration loop and rejects only `arr_idx>=64`; it provides no lower-bound proof. Kernel verifier input admissibility and the matching traditional BPF operation remain open. No speculative mask, guard or application change was added.

## Evidence and reproducibility

`make inspect` describes the original inspection; it is not a request to rerun already completed commands. Controller1437155 completed 2026-11-28T11:18:27Z rc0: two mem2reg-only commands onCPU16 with48GiB AS, plus two BTF reads onCPU19. No code generation or guest. `inspect_consumers.executed.py` is the original recipe. Its BTF closure missed bpftool's named `(anon)` members, so original partial facts incorrectly omitted module; do not use that omission. `inspect_consumers.py` is the corrected reader. `resolve_btf.executed.sh` preserves the exact correction and BTF-only reread; each reread's full raw BTF SHA equals the original. The `*-btf-anonymous-addendum.json` records are authoritative for anonymous fields and enums. Native inspection was not rerun.

`collection-review.json` gives exact per-function categories and native shift IR. `source-anchors.json` preserves numbered source excerpts and SHA256s, including compatibility macro, masks, callers, constants and target kernel declarations. All11original inputs and both native object hashes were rechecked before publication.

All12raw records are preserved in `tracee-index-records.tar.zst` (28,152B, SHA256 `268eb6a7ba8fc156dabac77b487b56f5b8a5c0f0516b76aba8f127fb5ba3541a`), indexed with every member SHA/size in `tracee-index-archive.json`. Read a member with `tar --zstd -xOf ARCHIVE MEMBER`. Loose output duplicates remain at publication; only later verified cleanup may remove them. Original114object census records, native/source/kernel files, source recipes and peer inputs remain untouched.

Published 2026-11-28T11:29:20Z. No installed-code, runtime equal-work, timing or whole-system acceptance claim.
