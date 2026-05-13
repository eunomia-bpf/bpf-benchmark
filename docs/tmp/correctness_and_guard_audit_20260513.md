# Correctness + Guard Audit (2026-05-13)

## Verdict summary table

| file:line | class | severity | description | recommended action |
|---|---|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/rotate.rs:18` | A | med | `bpf_rotate{32,64}` claims uses `{src}` and defs `{dst}`, but the payload also carries `tmp_reg` and the kernel instantiate path writes it. | Add payload offset 16 to `register_defs`, or remove the verifier-visible tmp operand from the rotate kinsn semantics and module instantiate path. |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:13` | A | med | `bpf_bulk_memcpy` claims uses `{dst_base, src_base}` and empty defs, but both module instantiate paths write `tmp_reg` from payload offset 48. | Add `tmp_reg` offset 48 to memcpy `register_defs`; keep the existing live-out check until native/module semantics are changed to preserve tmp. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1399` | A | med | Linear lifted facts treat every kinsn call as a generic helper call and clear `r0..r5` plus packet facts, ignoring descriptor defs/uses. | Make `advance_lifted_regs` kinsn-aware: read the packed sidecar and descriptor, clear only descriptor defs, preserve unaffected facts, and fail if the descriptor is unavailable. |
| `bpfopt/crates/bpfopt/src/pass.rs:647` | A | med | Empty/missing verifier state is explicitly accepted and consumers fall back to unknown reg classification. | Add a pass-level verifier-state requirement for verifier-guided passes and fail the pass when log-level/state data is missing. |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:31` | A | med | `const_prop` reads `reg_kind()` and `reg_known_constant()`; absent verifier state turns into `None` and silently disables the optimization. | Treat missing verifier state as a pass error for `const_prop`; keep `None` only for a present state that proves no constant. |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:187` | C | med | Same-base overlap guard still rejects bulk memcpy candidates, while the module does not reject overlap and Tier B policy trusts LLVM/app byte-ladders. | Delete the guard and the alias-skip test, or move overlap rejection to a documented semantic check with corpus evidence. |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:95` | C | med | `skb_load_bytes_spec` rejects constant helper lengths greater than 8 even though it emits bytewise copies and the original helper is commonly used for larger headers. | Remove the 8-byte cap; bound only by branch-offset/code-size limits and stack destination validity. |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:303` | C | med | Ladder extension requires identical physical `root_reg` and `data_end_reg` even though `root_ptr_def` already proves packet-pointer identity. | Drop the register-number equality checks and use `root_ptr_def`/packet-end identity plus the existing interleave safety check. |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:7` | C | med | `MAX_LADDER_WINDOW_GROWTH = 24` is a hard optimization cap, not a semantic verifier limit. | Remove the cap or replace it with a documented instruction-offset/code-size bound. |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:608` | C | high | Writer-helper discovery continues when the map pointer in `r1` cannot be resolved; that leaves an unknown mutable map unmarked. | Fail the pass or conservatively mark all candidate maps mutable when a writer helper map argument is unresolved. |
| `bpfopt/crates/bpfopt/src/verifier_log.rs:166` | C | high | Verifier-log parser warns and skips malformed state tokens/attributes, which can erase register or stack facts consumed by verifier-guided passes. | Return a parse error for malformed state-like tokens; do not warning-and-continue inside verifier state lines. |
| `bpfopt/crates/bpfopt/src/insn.rs:7` | B | low | `insn.rs` publicly re-exports many upstream `libbpf_sys` UAPI constants as local constants. | Import upstream constants directly where possible; keep only project-only pseudo tags and ABI offsets. |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs:5` | B | low | Helper-id wrapper constants duplicate `libbpf_sys` values (`HELPER_MAP_LOOKUP_ELEM`, `HELPER_XDP_ADJUST_HEAD`, and `BPF_FUNC_SKB_LOAD_BYTES`). | Inline `libbpf_sys::BPF_FUNC_* as i32` at the comparison sites or centralize helper names in one non-public helper module. |
| `bpfopt/crates/bpfopt/src/verifier_log.rs:100` | B | low | `parse_verifier_log` and `parse_verifier_log_result` have zero non-test callers. | Move them to test helpers or keep them private under tests only. |
| `bpfopt/crates/bpfopt/src/insn.rs:290` | B | low | Test-only `BpfInsn` helpers/constructors have zero non-test callers (`as_kernel`, `pseudo_call_to`, `jeq_imm`, `add64_imm`, `alu32_reg`). | Move these helpers into test helper modules or keep them strictly `#[cfg(test)]` with no production API exposure. |

## Class A: dataflow correctness

### A1. `rotate` descriptor omits the tmp-register def

- File: `bpfopt/crates/bpfopt/src/passes/rotate.rs:18`
- Claimed uses/defs: `rotate_register_uses()` reads payload offset 4 only; `rotate_register_defs()` writes payload offset 0 only.
- Actual emission:
  - Payload packs `dst` at 0, `src` at 4, shift at 8, and `tmp_reg` at 16 (`rotate.rs:70`).
  - x86 instantiate writes `tmp_reg` with `BPF_MOV{32,64}_REG(tmp_reg, src_reg)` and shifts it (`module/x86/bpf_rotate.c:71`, `module/x86/bpf_rotate.c:95`).
  - arm64 instantiate does the same (`module/arm64/bpf_rotate.c:71`, `module/arm64/bpf_rotate.c:95`).
  - Native x86/arm64 emit ignores `tmp_reg` and writes only `dst`, but the verifier/fallback expansion is still a valid semantic model for liveness.
- Impact: liveness after an existing rotate kinsn believes `tmp_reg` survives. The pass has a pre-rewrite live-out guard (`rotate.rs:47`) that prevents the immediate replacement from clobbering a live tmp, so this is not an obvious current miscompile, but later use-def/liveness consumers will have the wrong fact for programs already containing rotate kinsns.
- Proposed fix: add payload offset 16 to `register_defs`, or redesign the rotate kinsn so both native and instantiate semantics preserve/no longer expose `tmp_reg`.

### A2. `bulk_memory` memcpy descriptor omits the tmp-register def

- File: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:13`
- Claimed uses/defs: memcpy uses payload offsets 0 and 4 (`dst_base`, `src_base`) and has `register_defs: no_regs`.
- Actual emission:
  - Payload packs `temp_reg` at offset 48 (`bulk_memory.rs:394`).
  - x86 instantiate writes `tmp_reg` for every byte load (`module/x86/bpf_bulk_memory.c:144`), and native x86 leaves the last copied byte in `tmp_reg` (`module/x86/bpf_bulk_memory.c:383`).
  - arm64 instantiate writes `tmp_reg` (`module/arm64/bpf_bulk_memory.c:148`), and native arm64 writes the mapped temp register in the tail path (`module/arm64/bpf_bulk_memory.c:482`).
- Impact: same shape as rotate. The pass checks tmp live-out for the replacement window (`bulk_memory.rs:195`), but any subsequent liveness/use-def pass sees an existing `bpf_bulk_memcpy` call as preserving the tmp register.
- Proposed fix: add offset 48 to memcpy `register_defs`.

### A3. Lifted reg facts are not kinsn-aware

- File: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1399`
- Claimed behavior: `ProgramCFG` has a `KinsnRegistry`, and use-def facts already call `descriptor.register_uses` and `descriptor.register_defs` (`bbprogram_use_def.rs:185`).
- Actual behavior: `advance_lifted_regs()` treats any `insn.is_call()` as an opaque helper, clearing `r0..r5`, packet facts, and `last_data_load` (`bbprogram.rs:1399`).
- Impact: after an earlier pass inserts a kinsn, later passes that use `reg_fact_at()` (`bounds_check_merge`, `skb_load_bytes_spec`, `map_inline` alias recovery) lose facts across the kinsn even when the descriptor says the kinsn only writes one destination register. This silently rejects legitimate follow-on optimizations.
- Proposed fix: split normal helper calls from `is_call_kinsn()`. For kinsn calls, decode the preceding sidecar, look up the descriptor, set descriptor defs to `Unknown`, preserve non-def facts, and fail on missing sidecar/descriptor.

### A4. Verifier-state absence is modeled as “unknown” instead of a pass error

- Files: `bpfopt/crates/bpfopt/src/pass.rs:647`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:348`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:31`
- Claimed behavior: comments say empty verifier states are legitimate and consumers fall back to unknown classification.
- Actual behavior: `reg_kind()` and `reg_known_constant()` return `None` when there is no verifier state. `const_prop` then skips materialization without an error.
- Impact: a daemon/log-level bug can reduce `const_prop`, `map_inline`, and other verifier-guided passes to no-op behavior while still returning success. This is the same failure mode as stale/missing dataflow facts: measurable apply-count loss is hidden as normal “no candidate” behavior.
- Proposed fix: add explicit pass metadata such as `requires_verifier_states()`. If a pass requires verifier states and none were parsed, exit 1 with a clear error. Preserve site-level skip reasons only when verifier states exist but do not prove the needed fact.

### Kinsn descriptors checked with no mismatch found

- `cond_select`: uses offsets 4/8/12 and def offset 0 (`cond_select.rs:17`). x86/arm64 instantiate reads `cond`, `true`, `false` and writes `dst` (`module/x86/bpf_select.c:48`, `module/arm64/bpf_select.c:48`). The x86 native path skips `cond` when `true == false`, but the instantiate semantics still read it, so the descriptor is conservative and correct.
- `endian`: uses base offset 4 and def offset 0 (`endian.rs:34`). x86/arm64 instantiate loads from base and bswaps/writes dst.
- `extract`: read-modify-write of dst at offset 0 (`extract.rs:10`). x86/arm64 instantiate/native both read and write dst.
- `prefetch`: uses ptr offset 0 and no defs (`prefetch.rs:16`). Instantiate is a NOP, but native x86/arm64 reads the pointer for the prefetch instruction, so the descriptor correctly models the native side effect.
- `ccmp`: arm64-only, uses the counted operand regs and defs dst (`ccmp.rs:16`). The module rejects dst aliasing any source and writes dst in instantiate/native (`module/arm64/bpf_ccmp.c:64`, `module/arm64/bpf_ccmp.c:86`, `module/arm64/bpf_ccmp.c:181`).
- `lea`: conditional base/index uses and dst def match the x86 module payload flags (`lea.rs:19`, `module/x86/bpf_lea.c:26`).
- `bpf_ldp.c`: arm64 module has `bpf_ldp128`/`bpf_stp128` semantics, but there is no current bpfopt pass descriptor consuming it. This is documented in the pass-list notes, so no bpfopt use-def mismatch exists today.
- `wide_mem`, `dce`, and `branch_flip`: no direct use-def API misuse found. Their main guards are addressed under Class C only where the guard has no semantic basis.

## Class B: dead code

### B1. No `#[allow(dead_code)]` occurrences found

- Command: `rg -n "#\\[allow\\(dead_code\\)\\]|allow\\(dead_code\\)" bpfopt daemon -S`
- Result: no matches.

### B2. Upstream UAPI constant wrappers in `insn.rs`

- File: `bpfopt/crates/bpfopt/src/insn.rs:7`
- What it is: local public constants re-export upstream `libbpf_sys` constants (`BPF_LD`, `BPF_ALU64`, `BPF_JEQ`, `BPF_REG_0..10`, pseudo tags, etc.).
- Why it is dead/legacy: these wrappers are used, but they are compatibility aliases around upstream UAPI values. The design rule says to use `libbpf-rs`/`libbpf-sys` and not re-wrap upstream APIs.
- Action: replace public upstream aliases with direct `libbpf_sys::*` imports or private local aliases. Keep only project-specific pseudo constants (`BPF_PSEUDO_KINSN_SIDECAR`, `BPF_PSEUDO_KINSN_CALL`) and values not exposed upstream.

### B3. Helper-id wrappers duplicate `libbpf_sys`

- Files:
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:5`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:6`
  - `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:8`
- What it is: `HELPER_MAP_LOOKUP_ELEM`, `HELPER_XDP_ADJUST_HEAD`, and `BPF_FUNC_SKB_LOAD_BYTES` simply rename `libbpf_sys::BPF_FUNC_*`.
- Why it is dead/legacy: they are not abstractions; they are one-line compatibility aliases.
- Action: inline the upstream constants at the comparisons/call emission sites, or centralize helper naming in one private module if readability needs a local name.

### B4. Test-only verifier-log wrappers

- File: `bpfopt/crates/bpfopt/src/verifier_log.rs:100`
- What it is: `parse_verifier_log()` and `parse_verifier_log_result()` are `#[cfg(test)]` and have zero non-test callers. Production uses `verifier_states_from_log()`.
- Why it is dead: they are test helpers sitting in the production module namespace.
- Action: move them to `verifier_log_tests.rs` or a test helper module. If kept in the production file, keep them strictly `#[cfg(test)]`.

### B5. Test-only `BpfInsn` constructors and ABI helper

- Files:
  - `bpfopt/crates/bpfopt/src/insn.rs:290` (`as_kernel`)
  - `bpfopt/crates/bpfopt/src/insn.rs:474` (`pseudo_call_to`)
  - `bpfopt/crates/bpfopt/src/insn.rs:487` (`jeq_imm`)
  - `bpfopt/crates/bpfopt/src/insn.rs:569` (`add64_imm`)
  - `bpfopt/crates/bpfopt/src/insn.rs:582` (`alu32_reg`)
- What it is: convenience constructors/helpers with zero non-test callers.
- Why it is dead: they are not production APIs. They are currently protected by `#[cfg(test)]` except `jeq_imm`, which is production-visible despite only being used by tests in the checked references.
- Action: move them into `test_helpers.rs` or gate the remaining test-only constructor with `#[cfg(test)]`.

## Class C: false guards

### C1. Same-base memcpy alias guard still rejects candidates

- File: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:187`
- Guard predicate: `if first.src_base == first.dst_base && ranges_overlap(...) { skip "alias overlap in same-base memcpy run" }`.
- Evidence:
  - The x86 and arm64 modules decode and reject invalid registers/length/offsets, but neither rejects source/destination overlap (`module/x86/bpf_bulk_memory.c:60`, `module/arm64/bpf_bulk_memory.c:66`).
  - The app corpus has many LLVM/app memcpy sites, including Katran, Cilium, bpftrace, bcc, and Tracee (`rg "memcpy|__builtin_memcpy" bpfopt/testccode`).
  - The only direct skip evidence found is the synthetic unit assertion `bulk_memory_tests.rs:194`.
- Impact: under the current Tier B policy described in the prompt, this guard is the same class as the deleted `memcpy_alias_skip_reason`: it rejects a legitimate byte-ladder shape before the module/verifier can decide.
- Proposed action: delete the guard and its alias-skip test. If overlap must be rejected for semantics, move it to an explicit documented semantic proof rather than an LLVM-paranoia guard.

### C2. `skb_load_bytes_spec` has an unsupported 8-byte cap

- File: `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:95`
- Guard predicate: `if len > 8 { skip "len > 8" }`.
- Evidence:
  - The emitted fast path is bytewise (`LDX B`/`STX B`) and therefore does not introduce unaligned wide packet loads (`skb_load_bytes.rs:141`).
  - Tracee uses `bpf_skb_load_bytes()` / `_relative()` for IP/TCP/UDP/HTTP header-size copies, including `struct iphdr`, `struct ipv6hdr`, `struct tcphdr`, and `http_min_len` patterns (`bpfopt/testccode/tracee_tracee.bpf.c:6690`, `:6694`, `:6821`, `:6825`, `:6946`).
  - There is no kernel module for this pass that rejects larger lengths; this is pure bytecode rewriting.
- Impact: every constant helper length above 8 is silently skipped even when the same bytewise fast path would be verifier-equivalent. This can materially reduce Tracee coverage.
- Proposed action: remove the fixed cap. Keep only a branch-offset/code-size limit, e.g. ensure `(3 + 2 * len)` fits the `i16` branch offset and any pass policy cap is documented as code-size policy, not safety.

### C3. `bounds_check_merge` requires identical physical registers

- File: `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:303`
- Guard predicate: `prev.root_reg != next.root_reg || prev.data_end_reg != next.data_end_reg`.
- Evidence:
  - `GuardSite` already stores `root_ptr_def`, and `detect_guard_candidate()` proves `cursor_ptr_def == root_ptr_def == end_ptr_def` (`bounds_check_merge.rs:222`).
  - Cilium and Katran test sources contain many packet `data`/`data_end` guard idioms around IPv4/IPv6/TCP/UDP parsing (`bpfopt/testccode/cilium_bpf_lxc.bpf.c:528`, `bpfopt/testccode/katran_balancer.bpf.c:312`, `:445`), where LLVM register allocation can legitimately copy the same packet roots through different physical registers.
  - No module rejects this, because the pass emits ordinary bytecode.
- Impact: equivalent adjacent bounds checks are not merged when LLVM uses different registers for the same proven packet root/end.
- Proposed action: delete the physical register equality requirements; retain `root_ptr_def`, packet-end identity, compare kind, slow target, monotonic window, and interleave safety.

### C4. `bounds_check_merge` hard-caps ladder growth at 24 bytes

- File: `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:7`
- Guard predicate: `next.window_end - prev.window_end > MAX_LADDER_WINDOW_GROWTH`.
- Evidence:
  - The cap is not a verifier semantic condition. The emitted rewrite widens one dominant guard to the max observed window (`bounds_check_merge.rs:373`).
  - Real packet parsers check windows larger than 24 bytes, e.g. Ethernet+IPv6+UDP and encapsulation paths in Katran/Cilium (`bpfopt/testccode/katran_balancer.bpf.c:445`, `bpfopt/testccode/cilium_bpf_xdp.bpf.c:217`).
- Impact: valid ladders are split solely by a magic number, reducing apply counts for header parsers.
- Proposed action: remove the cap or replace it with a documented code-size/branch-distance bound. If a noise/compile-time reason exists, make it a benchmark policy knob, not a correctness guard.

### C5. `map_inline` ignores unresolved writer-helper map arguments

- File: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:608`
- Guard/fallback predicate: when a writer helper call is found but `find_direct_map_load_for_reg_before_site(..., r1)` returns `None`, the scanner `continue`s.
- Evidence:
  - Corpus source has many map update/delete/push/pop calls, including indirect map arguments in Tracee/Katran (`rg "bpf_map_(update|delete|push|pop)_elem" bpfopt/testccode`).
  - The same function otherwise marks resolved writer maps as kernel-mutable (`map_inline.rs:630`).
- Impact: a map mutated through an unresolved pointer can remain eligible for inline snapshots. That is worse than a missed optimization: it can inline stale map contents after an untracked writer helper.
- Proposed action: fail `map_inline` on unresolved writer-helper map args, or conservatively mark all snapshot candidate maps mutable and skip inlining with a site diagnostic.

### C6. Verifier-log parser warning-and-continue loses facts

- Files:
  - `bpfopt/crates/bpfopt/src/verifier_log.rs:166`
  - `bpfopt/crates/bpfopt/src/verifier_log.rs:310`
  - `bpfopt/crates/bpfopt/src/verifier_log.rs:528`
- Guard/fallback predicate: malformed register/stack state tokens call `warn_verifier_log()` and return `None`; invalid attributes also warn and continue.
- Evidence:
  - `parse_state_line()` only fails if the whole line has no state; individual malformed tokens can be dropped while the line still returns a `VerifierInsn`.
  - Verifier-guided passes use these parsed facts to prove constants, pointer kinds, and stack bytes.
- Impact: a verifier-log grammar drift can silently erase the exact fact needed by `const_prop`, `map_inline`, or `skb_load_bytes_spec`, causing false skips. In the worst case it can make map-inline safety reasoning incomplete.
- Proposed action: make malformed state-like tokens and invalid attributes hard parse errors. Only ignore tokens that are explicitly recognized as non-state verifier text.

### Guards reviewed and kept

- `wide_mem` natural-alignment and scratch-live guards: keep. They avoid verifier rejection or clobbering a scratch register that remains live.
- `ccmp` max-term, subprogram-boundary, and dead-dst guards: keep. The arm64 module rejects excess terms, dst aliases, and dst > `r9`.
- `lea` register validity and conditional base/index handling: keep. They match module decode rules.
- `branch_flip` PGO-required fields and branch-miss gates: keep. They are policy/profile requirements, not stale dataflow fallbacks.
- `prefetch` control-flow/window guards: keep for now. They are conservative but tied to preserving pointer validity and execution path; no corpus evidence in this pass showed a deleted-guard-level false rejection.

## Methodology + commands run

- Read the plan context once: `sed -n '1,220p' docs/kernel-jit-optimization-plan.md`.
- Checked worktree status read-only: `git status --short`.
- Enumerated relevant files: `rg --files`, `rg --files bpfopt daemon module`, and `find module -maxdepth 2 -type f`.
- Searched descriptors and use-def wiring:
  - `rg -n "register_uses|register_defs|KINSN_TARGETS" bpfopt/crates/bpfopt/src/passes/{cond_select,rotate,endian,extract,bulk_memory,prefetch,ccmp,lea}.rs -S`
  - `nl -ba bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs | sed -n '150,205p'`
  - `nl -ba bpfopt/crates/bpfopt/src/analysis/bbprogram.rs | sed -n '285,420p;1385,1480p'`
- Cross-checked module emission under `module/x86/*.c` and `module/arm64/*.c` with `nl -ba ... | sed ...` for `bpf_select`, `bpf_rotate`, `bpf_endian`, `bpf_extract`, `bpf_bulk_memory`, `bpf_prefetch`, `bpf_ccmp`, `bpf_lea`, and `bpf_ldp`.
- Searched skip guards and fallbacks:
  - `rg -n "external_join_predecessor|skip_reason|is_safe|blocked|window|len > 8|MAX_LADDER|root_reg|data_end_reg|unwrap_or\\(|\\.ok\\(\\)|unwrap_or_default\\(|let _ =" bpfopt/crates/bpfopt/src/passes bpfopt/crates/bpfopt/src/analysis bpfopt/crates/bpfopt/src/pass.rs -S`
  - `rg -n "unwrap_or_default\\(|unwrap_or\\(|\\.ok\\(\\)|let _ =" bpfopt/crates/bpfopt/src daemon/src -S --glob '!target/**'`
- Searched dead-code markers: `rg -n "#\\[allow\\(dead_code\\)\\]|allow\\(dead_code\\)" bpfopt daemon -S`.
- Cross-checked zero non-test callers:
  - `rg -n "parse_verifier_log\\(|parse_verifier_log_result\\(|as_kernel\\(|pseudo_call_to\\(|jeq_imm\\(|add64_imm\\(|alu32_reg\\(" bpfopt/crates/bpfopt/src --glob '!**/*_tests.rs' -S`
  - `rg -n "parse_verifier_log\\(|parse_verifier_log_result\\(|as_kernel\\(|pseudo_call_to\\(|jeq_imm\\(|add64_imm\\(|alu32_reg\\(" bpfopt/crates/bpfopt/src -S`
- Searched corpus evidence:
  - `rg -n "skb_load_bytes|bpf_skb_load_bytes|load_bytes" bpfopt/testccode bpfopt/testbin bpfopt/testobject -S`
  - `rg -n "memcpy|__builtin_memcpy|memmove|__builtin_memmove|alias overlap|memcpy_alias" bpfopt/testccode bpfopt/testbin bpfopt/testobject bpfopt/crates/bpfopt/src/passes/bulk_memory.rs -S`
  - `rg -n "bpf_map_(update|delete|push|pop)_elem" bpfopt/testccode -S`
  - `rg -n "data_end|ctx_data_end|\\+ 24|\\+ 34|\\+ 40|sizeof\\(struct iphdr\\)|sizeof\\(struct ipv6hdr\\)|ipv6hdr|ethhdr" bpfopt/testccode/cilium_bpf_lxc.bpf.c bpfopt/testccode/cilium_bpf_xdp.bpf.c bpfopt/testccode/katran_balancer.bpf.c bpfopt/testccode/tracee_tracee.bpf.c -S`
- Formatting checks:
  - `cargo fmt --all --check` from repo root failed because `/home/yunwei37/workspace/bpf-benchmark` has no `Cargo.toml`.
  - `cargo fmt --all --check --manifest-path bpfopt/Cargo.toml` passed.
  - `cargo fmt --all --check --manifest-path daemon/Cargo.toml` passed.

