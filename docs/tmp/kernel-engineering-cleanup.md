# Kernel Engineering Cleanup

Date: 2026-03-13

## Scope

Reviewed and cleaned the BpfReJIT kernel changes in:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/include/trace/events/bpf.h`

Also reviewed:

- `docs/tmp/kernel-code-review.md`
- `docs/tmp/kernel-safety-fixes.md`

This pass intentionally stayed in the "engineering cleanup" lane: no
functionality was removed, and the fixes are limited to correctness,
maintainability, API clarity, logging, and code hygiene.

## Changes Made

### 1. Clarified policy-format version naming

Files:

- `vendor/linux-framework/include/uapi/linux/bpf.h`

Changes:

- Added `BPF_JIT_POLICY_FORMAT_VERSION` as the canonical name for the on-wire
  policy format version.
- Kept `BPF_JIT_POLICY_VERSION_2` as a compatibility alias.
- Kept `BPF_JIT_POLICY_VERSION` pointing at the canonical format macro.

Why:

- The tree refers to the declarative rewrite format as "v5", while the blob
  header still uses version `2`. The new naming and comment make that mapping
  explicit without breaking existing userspace code.

### 2. Tightened internal header consistency and documentation

Files:

- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`

Changes:

- Added a compile-time consistency check for `BPF_JIT_MAX_CANONICAL_PARAMS`
  instead of silently accepting mismatched redefinitions.
- Updated rule-lookup comments to state the real contract: lookup is by
  absolute `site_start`, not by any instruction covered by a rule.
- Renamed the parser helper from `bpf_jit_parse_policy_v2()` to
  `bpf_jit_parse_policy_format_v2()` to match the format-version language.

Why:

- The old names and comments made the API easier to misuse and harder to
  review.

### 3. Fixed same-site rule lookup behavior

Files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`

Changes:

- Reworked `bpf_jit_rule_lookup()` to lower-bound on `site_start` and then scan
  forward through rules at the same site until it finds the first active one.

Why:

- The previous binary search could land on an arbitrary rule among multiple
  same-site entries. That made the "highest priority active rule wins" rule
  unreliable when multiple rules shared one `site_start`.

### 4. Removed duplicate interior-edge validation

Files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`

Changes:

- Removed repeated `bpf_jit_has_interior_edge()` checks from the
  form-specific canonical validators.
- Kept the check in the central pattern-validation path.

Why:

- Interior-edge rejection is a generic rule property, not a per-form detail.
  Keeping it in one place makes validation easier to reason about and avoids
  drift between validators.

### 5. Demoted noisy validation printk

Files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`

Changes:

- Changed the global log in `bpf_jit_canonical_site_fail()` from `pr_info()` to
  `pr_debug()`.

Why:

- Invalid or non-applicable user policies should stay in the recompile log and
  not spam the global kernel log at info level.

### 6. Cleaned stale annotations and comments

Files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Removed stale `__maybe_unused` annotations from live validators and emitters.
- Updated the masked-rotate comment to match the actual validator
  (`AND_K` only).
- Updated the x86 dispatcher comment to describe start-site lookup and errno
  returns correctly.

Why:

- The annotations and comments no longer matched the live code paths.

### 7. Fixed x86 canonical rotate `RORX` emission

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Fixed `emit_canonical_rotate()` so the `BPF_JIT_ROT_RORX` path writes back the
  advanced `prog` pointer to `*pprog`.

Why:

- Without the write-back, the emitted bytes could be overwritten by subsequent
  emission. This was a real backend correctness bug.

### 8. Tightened x86 branch-flip emission validation

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Added an explicit `site_len` check in `emit_canonical_branch_flip()` to
  ensure the two bodies plus the guard jump exactly match the claimed rewrite
  span.
- Extended the x86 condition inversion helper to handle `BPF_JSET` by mapping
  the inverted `test` condition to `je`.

Why:

- The emitter should not trust canonical body lengths without confirming they
  match the site it is about to rewrite.
- The validator already accepts `BPF_JSET` in branch-flip rules, so the x86
  backend now handles the inverted condition explicitly instead of always
  falling back.

### 9. Tightened x86 bitfield-extract canonical params

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Made `emit_canonical_bitfield_extract()` reject unknown ordering values
  instead of silently treating them as shift-then-mask.

Why:

- Policy-driven canonical parameters should be validated strictly, not
  permissively.

### 10. Factored x86 rule application bookkeeping

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Kept rule lookup in `bpf_jit_rule_lookup_prog()` / `bpf_jit_try_emit_prog_rule()`.
- Added `bpf_jit_commit_rule_region()` for emitted-region copy/address
  bookkeeping.
- Added `bpf_jit_apply_prog_rule()` so `do_jit()` no longer inlines lookup,
  fallback logging, image copy, and address updates in one large block.

Why:

- The old open-coded dispatch block was hard to audit and easy to break.
  This cleanup keeps the JIT loop readable and localizes the rule-application
  mechanics.

### 11. Removed dead x86 legacy emitters

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Removed unused legacy helpers that were no longer referenced by the live
  canonical-form path:
  - old wide-load shape parsing/emitter
  - old rotate emitter
  - old LEA fusion emitter
  - old bitfield-extract parser/emitter

Why:

- These paths were dead after the canonical-form dispatcher landed. Keeping two
  implementations for the same rewrite families only increased review and
  maintenance cost.

### 12. De-duplicated LEA encoding logic

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Added `emit_lea_base_index()` and switched the canonical LEA path to use it.
- Reused the named `x86_base_needs_disp()` helper instead of open-coding the
  `reg2hex == 5` check.

Why:

- This removes duplicated ModRM/SIB logic and replaces a magic register test
  with the existing named helper.

### 13. Removed unused FineIBT recompile shadow state

Files:

- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/core.c`

Changes:

- Removed the unused `jit_recompile_ksym_prefix` field and its list-head
  initialization.

Why:

- The field was never referenced after allocation. Keeping unused state in
  `bpf_prog_aux` adds noise and invites confusion about unsupported behavior.

### 14. Fixed minor x86 logging typo

Files:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Changes:

- Fixed the private-stack guard log format string from `"prog %sx"` to
  `"prog %s"`.

Why:

- Pure log-hygiene cleanup.

### 15. Tracked the trace-events header in git

Files:

- `vendor/linux-framework/include/trace/events/bpf.h`

Changes:

- Added the file to the git index with `git add`.

Why:

- The header is included directly by `kernel/bpf/jit_directives.c`; leaving it
  untracked made the patch set incomplete.

## Validation

Build:

```sh
make -C vendor/linux-framework -j$(nproc) bzImage
```

Result:

- Success
- Built image: `vendor/linux-framework/arch/x86/boot/bzImage`

VM smoke:

```sh
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "uname -r && dmesg | tail -5"
```

Result:

- `7.0.0-rc2-g05a1845490ed-dirty`
- Tail of `dmesg`:
  - `virtme-ng-init: Starting systemd-udevd version 255.4-1ubuntu8.11`
  - `virtme-ng-init: triggering udev coldplug`
  - `virtme-ng-init: waiting for udev to settle`
  - `virtme-ng-init: udev is done`
  - `virtme-ng-init: initialization done`

Notes:

- `vng` printed the expected `modules.order not found` warning because kernel
  modules are disabled in this build.

## Outcome

The tree now has:

- the earlier safety fixes still intact,
- the x86 `RORX` emission bug fixed,
- stricter canonical parameter handling,
- cleaner rule lookup and dispatch,
- less dead code,
- quieter logging,
- clearer version naming and API comments,
- and the trace-events header properly tracked in git.
