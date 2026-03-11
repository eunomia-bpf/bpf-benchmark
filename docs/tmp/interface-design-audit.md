# BpfReJIT Interface Design Audit

Date: 2026-03-11

Scope:

- UAPI and kernel recompile path: `vendor/linux-framework/include/uapi/linux/bpf.h:1471-1672`, `vendor/linux-framework/include/linux/bpf_jit_directives.h:17-138`, `vendor/linux-framework/kernel/bpf/syscall.c:6344-6345`, `vendor/linux-framework/kernel/bpf/jit_directives.c:487-2675`
- x86 JIT implementation: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2263-3506`
- Userspace scanner and policy generation: `scanner/src/scanner.cpp:169-985`, `scanner/src/pattern_v5.cpp:118-1375`, `scanner/src/engine.cpp:203-958`, `scanner/src/cli.cpp:330-669`, `scanner/src/policy.cpp:16-115`
- Design docs and benchmark harness: `docs/kernel-jit-optimization-plan.md:15-20`, `docs/kernel-jit-optimization-plan.md:77-98`, `docs/kernel-jit-optimization-plan.md:107-108`, `docs/kernel-jit-optimization-plan.md:383-388`, `docs/tmp/directive-gap-analysis.md:32-34`, `micro/orchestrator/rigorous.py:66-114`, `micro/runner/src/kernel_runner.cpp:817-990`, `e2e/common/recompile.py:58-187`, `corpus/run_corpus_runnability.py:153-157`, `corpus/run_corpus_runnability.py:356-364`, `corpus/run_corpus_runnability.py:367-451`, `corpus/run_corpus_runnability.py:455-565`, `corpus/_driver_impl_run_corpus_tracing.py:658-684`, `corpus/_driver_impl_run_corpus_tracing.py:929-933`, `corpus/config/macro_corpus.yaml:19-25`, `corpus/_driver_impl_run_macro_corpus.py:705-715`

## Executive Summary

1. The current UAPI is already sufficient for a large class of future work: any new userspace-discovered pattern that lowers to the existing canonical forms `COND_SELECT`, `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, or `BITFIELD_EXTRACT` can be added without touching `bpf.h`. That is the strongest part of the current design.
2. The UAPI is not sufficient for structurally different directives such as `branch_reorder` and `bounds_window`. Those are not local “pick one native lowering for this site” decisions; they need new kernel semantics, and likely a different safety contract.
3. `bitfield_extract` is half-finished in the current tree. The UAPI, userspace scanner, kernel parser, kernel validator, and x86 emitter helpers all exist, but x86 never dispatches that form: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208` omits `BPF_JIT_RK_BITFIELD_EXTRACT`, and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3265-3357` has no `BPF_JIT_CF_BITFIELD_EXTRACT` case. Such rules can validate and then silently fall back to stock emission via `do_jit()`’s `consumed <= 0` path at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3465-3505`.
4. v5 is the right long-term direction, but it does not yet fully subsume v4 operationally. v5 has the extensible transport; v4 still has the richer userspace decision layer (`PolicyEngine`, overlap arbitration, config/profile hooks) and simpler debugging model.
5. The benchmark framework does exercise the real `BPF_PROG_JIT_RECOMPILE` syscall, but coverage is fragmented. Default micro runs do not include recompile; most e2e and live-program flows are v5-only; explicit `--policy-blob` and load-time directive interfaces are effectively unbenchmarked.

## 1. Interface Completeness

### What the current interface can express

The recompile UAPI is a policy blob bound to a specific already-loaded program by `insn_cnt`, `prog_tag`, and `arch_id` (`vendor/linux-framework/include/uapi/linux/bpf.h:1480-1490`). The syscall itself only takes `prog_fd`, `policy_fd`, and `flags` (`vendor/linux-framework/include/uapi/linux/bpf.h:2169-2173`).

There are two policy encodings:

- Version 1: fixed rewrite records, `struct bpf_jit_rewrite_rule` (`vendor/linux-framework/include/uapi/linux/bpf.h:1543-1550`)
- Version 2: declarative pattern records, `struct bpf_jit_rewrite_rule_v2` plus inline pattern, constraints, and bindings (`vendor/linux-framework/include/uapi/linux/bpf.h:1552-1672`)

The important extensibility boundary is here:

- Rule kinds: `COND_SELECT`, `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `PATTERN` (`vendor/linux-framework/include/uapi/linux/bpf.h:1492-1499`)
- Canonical forms: `ROTATE`, `WIDE_MEM`, `ADDR_CALC`, `COND_SELECT`, `BITFIELD_EXTRACT` (`vendor/linux-framework/include/uapi/linux/bpf.h:1501-1507`)

That means the interface is already generic for “new pattern, existing canonical lowering”, but not for “new semantic class of lowering”.

### Per proposed directive

`bitfield_extract`

- UAPI: yes. It already has `BPF_JIT_RK_BITFIELD_EXTRACT`, `BPF_JIT_CF_BITFIELD_EXTRACT`, native-choice enum, and canonical params/order enums in `vendor/linux-framework/include/uapi/linux/bpf.h:1497`, `vendor/linux-framework/include/uapi/linux/bpf.h:1506`, `vendor/linux-framework/include/uapi/linux/bpf.h:1534-1537`, `vendor/linux-framework/include/uapi/linux/bpf.h:1627-1639`.
- Current blocker: implementation wiring, not UAPI. Kernel parsing/validation exists in `vendor/linux-framework/kernel/bpf/jit_directives.c:1339-1453`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1931-1948`, but x86 dispatch is incomplete as noted above.

`branch_reorder`

- Not expressible in the current interface.
- Current rules are site-local and choose among predeclared native lowerings for the same logical site. `bpf_jit_try_emit_rule()` is invoked at a single BPF insn index inside `do_jit()` and returns “how many BPF insns were consumed” (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3241-3357`).
- `branch_reorder` is a control-flow layout transform. It changes fallthrough structure and branch targets rather than only selecting a local emission. That conflicts with the current design constraint that directives “only change native code emission, not BPF instructions” and that `branch_reorder` is future scope needing verifier-level support (`docs/kernel-jit-optimization-plan.md:79-80`, `docs/kernel-jit-optimization-plan.md:101-108`, `docs/kernel-jit-optimization-plan.md:143-145`, `docs/kernel-jit-optimization-plan.md:386`).

`bounds_window`

- Not expressible in the current interface.
- Existing validation is purely local: exact pattern match, arithmetic constraints, side-effect screen, interior-edge check, subprog-bounds check (`vendor/linux-framework/kernel/bpf/jit_directives.c:1510-1539`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1955-2037`, `vendor/linux-framework/kernel/bpf/jit_directives.c:2040-2076`).
- `bounds_window` needs proof that an earlier dominating check makes a later window safe. That proof is verifier state, not a local peephole shape. The current canonical-param model has no way to bind retained verifier facts into a rule.

`packet_ctx_wide_load`

- In the current tree, this is more expressible than the planning docs assume.
- The generic wide emitter now supports widths `2..8` and big-endian assembly from chunks in `emit_wide_load_sequence()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2320-2357`) and the canonical wide path passes encoded width plus `BPF_JIT_WMEM_F_BIG_ENDIAN` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2729-2757`).
- The kernel canonical validator also accepts encoded widths/flags via `BPF_JIT_WMEM_PARAM_WIDTH` (`vendor/linux-framework/kernel/bpf/jit_directives.c:1869-1902`).
- Therefore, if `packet_ctx_wide_load` is “new byte-ladder patterns over packet/context pointers that still bind to `(dst_reg, base_reg, base_off, width)`”, it fits the existing interface and can be added in userspace. It only requires kernel work if you want a new safety proof beyond “this exact verified ladder is being lowered”.

### Verdict

The current UAPI is sufficient for:

- broader `cmov_select`
- `bitfield_extract` as a semantic interface
- `packet_ctx_wide_load`, if framed as more `WIDE_MEM` patterns
- any further rotate/lea/wide/select patterns that map to current canonical params

The current UAPI is not sufficient for:

- `branch_reorder`
- `bounds_window`
- any directive that needs non-local CFG edits, verifier facts, accepted-site introspection, or batching across programs

## 2. v4 vs v5 Path

### Exact difference

`v4` in this tree means policy version 1 on `BPF_PROG_JIT_RECOMPILE`:

- Userspace emits `struct bpf_jit_rewrite_rule` records with only `site_start`, `site_len`, `rule_kind`, `native_choice`, `priority`, and `cpu_features_required` (`vendor/linux-framework/include/uapi/linux/bpf.h:1543-1550`).
- Kernel parse path `bpf_jit_parse_policy_v1()` copies those fields, sets `canonical_form = 0`, and validates by legacy rule kind (`vendor/linux-framework/kernel/bpf/jit_directives.c:2165-2220`).
- x86 dispatch then uses legacy emitters for legacy kinds in `bpf_jit_try_emit_rule()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3265-3357`).

`v5` means policy version 2 with `rule_kind = BPF_JIT_RK_PATTERN`:

- Userspace emits inline pattern descriptors, arithmetic constraints, and canonical bindings using `V5RuleWire` and friends (`scanner/include/bpf_jit_scanner/pattern_v5.hpp:121-227`, `scanner/src/pattern_v5.cpp:1302-1375`).
- Kernel parse path `bpf_jit_parse_policy_v2()` validates descriptor structure and length, retains pointers to inline arrays, exact-matches the pattern against the loaded program, extracts canonical params into `rule->params`, and marks the rule active only if that succeeds (`vendor/linux-framework/kernel/bpf/jit_directives.c:2238-2338`).
- x86 dispatch uses the canonical emitter when `rule_kind == BPF_JIT_RK_PATTERN` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3274-3349`).

### Userspace behavior difference

The scanner behavior is also materially different:

- v4 CLI path uses `PolicyEngine`, family registry, overlap arbitration, config defaults/overrides, and rule materialization (`scanner/src/cli.cpp:606-669`, `scanner/src/engine.cpp:667-958`).
- v5 CLI path bypasses `PolicyEngine` completely. It runs `scan_v5_builtin()`, prints the builtin summary, builds a v5 blob, and optionally applies it (`scanner/src/cli.cpp:587-603`, `scanner/src/cli.cpp:630-649`).
- `scan_v5_builtin()` is greedy and first-match-wins. It walks `idx`, tries descriptors in order, appends the first match, then advances by the matched pattern length (`scanner/src/pattern_v5.cpp:1225-1299`).
- v5 builtin rules are emitted with `priority = 0` (`scanner/src/pattern_v5.cpp:118-130`).

### Can v5 subsume v4?

Semantically, mostly yes:

- The kernel-side v5 transport is strictly more general than v4. It can express exact legacy shapes and many more without new kernel parser code.
- The design doc explicitly positions v5 as “new BPF pattern only needs userspace; new canonical form needs kernel” (`docs/kernel-jit-optimization-plan.md:95-98`).

Operationally, not yet:

- v4 still has the better decision layer: config file, override semantics, profile hooks, and overlap arbitration (`scanner/src/engine.cpp:203-238`, `scanner/src/engine.cpp:846-958`, `scanner/src/cli.cpp:606-669`).
- v5 builtin scanning currently conflates discovery and policy through descriptor ordering and greedy matching (`scanner/src/pattern_v5.cpp:1235-1291`).
- v4 debugging is simpler because the kernel either validates a fixed rule or rejects it; v5 adds parser/constraint/binding complexity with no user-visible reject log.

### Should v4 be deprecated?

Not yet.

Recommended position:

- Make v5 the growth path for new pattern families and upstream story.
- Keep v4 until v5 gains a real policy layer and reject/introspection feedback.
- Once v5 can consume the same decision engine and has better diagnostics, v4 becomes mostly a compatibility/debug path.

Tradeoffs:

- v4 advantages: smaller blob, simpler mental model, explicit family choices, better current policy tooling.
- v5 advantages: userspace-only extensibility for new patterns, fewer kernel patches per new shape, better paper/upstream story.

## 3. Canonical Form Extensibility

### What kernel changes are required for a new canonical form

Adding a new canonical form is not a small leaf patch. At minimum it touches:

1. UAPI enums and params in `bpf.h`
   - `enum bpf_jit_canonical_form`
   - probably a new native-choice enum
   - probably a new canonical-param enum
   - possibly a new legacy `rule_kind` if v4 parity matters
   - reference points: `vendor/linux-framework/include/uapi/linux/bpf.h:1492-1639`
2. Kernel-neutral policy validation
   - `bpf_jit_rule_form()` (`vendor/linux-framework/kernel/bpf/jit_directives.c:504-523`)
   - `bpf_jit_native_choice_valid()` (`vendor/linux-framework/kernel/bpf/jit_directives.c:525-546`)
   - `bpf_jit_pattern_rule_shape_valid()` (`vendor/linux-framework/kernel/bpf/jit_directives.c:548-568`)
   - binding-param validation and canonical-param validation (`vendor/linux-framework/kernel/bpf/jit_directives.c:1732-1783`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1785-1953`)
   - `bpf_jit_validate_rule()` dispatch (`vendor/linux-framework/kernel/bpf/jit_directives.c:1987-2037`)
3. Arch-specific JIT support
   - x86 `bpf_jit_rule_form()` / dispatcher (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3248-3357`)
   - new canonical emitter
   - any arch-specific CPU gating

### Can we add a new emitter without touching `bpf.h`?

Two cases:

- New implementation for an existing canonical form/native choice on another architecture: yes, no UAPI change is needed.
- New selectable lowering option or new canonical form: no. `native_choice` and `canonical_form` are UAPI values, so a new choice visible to userspace requires `bpf.h` changes.

### Is the current switch-based dispatch the right design?

It is acceptable for a small, fail-closed menu. It is already showing maintenance strain.

The clearest evidence is the current bitfield split-brain:

- neutral validator knows `BITFIELD_EXTRACT` (`vendor/linux-framework/kernel/bpf/jit_directives.c:518-542`, `vendor/linux-framework/kernel/bpf/jit_directives.c:563-564`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1440-1453`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1931-1948`)
- x86 has emitter helpers (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3133-3190`)
- x86 dispatch forgot to wire it (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3265-3357`)

An ops-table design would reduce the number of duplicated switches and make this kind of drift less likely.

## 4. Scanner-Kernel Alignment

### Blob format alignment

The userspace on-wire structs match the kernel ABI:

- v4 scanner constants mirror the header and rule layout in `scanner/include/bpf_jit_scanner/types.h:44-135`
- v4 blob builder writes the exact 32-byte header and 16-byte records in `scanner/src/policy.cpp:16-98`
- v5 wire structs assert ABI sizes in `scanner/include/bpf_jit_scanner/pattern_v5.hpp:121-171`
- v5 builder serializes header + `V5RuleWire` + inline arrays in `scanner/src/pattern_v5.cpp:1302-1375`

The CLI also does the right program binding work:

- fetch loaded program metadata (`prog_tag`, `insn_cnt`) before blob generation
- apply the blob through a sealed memfd
- path: `scanner/src/cli.cpp:478-504`, `scanner/src/cli.cpp:587-669`

This matches kernel expectations in `bpf_jit_parse_policy()`:

- sealed memfd requirement (`vendor/linux-framework/kernel/bpf/jit_directives.c:2361-2366`)
- header/length checks (`vendor/linux-framework/kernel/bpf/jit_directives.c:2397-2412`)
- `insn_cnt` binding (`vendor/linux-framework/kernel/bpf/jit_directives.c:2414-2418`)
- `prog_tag` binding (`vendor/linux-framework/kernel/bpf/jit_directives.c:2420-2424`)
- `arch_id` binding (`vendor/linux-framework/kernel/bpf/jit_directives.c:2426-2435`)

### Acceptance/parsing mismatches

The main current mismatch is not parsing; it is “validated but not actually emitted”.

`bitfield_extract`

- Userspace v4 scanner exists: `scanner/src/scanner.cpp:169-247`, `scanner/src/scanner.cpp:903-938`
- Userspace v5 descriptors exist: `scanner/src/pattern_v5.cpp:1112-1223`
- CLI and engine expose the family: `scanner/src/cli.cpp:338-347`, `scanner/src/cli.cpp:434-440`, `scanner/src/cli.cpp:506-518`, `scanner/src/cli.cpp:521-537`, `scanner/src/engine.cpp:203-218`, `scanner/src/engine.cpp:667-728`
- Kernel validates it: `vendor/linux-framework/kernel/bpf/jit_directives.c:1339-1453`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1931-1948`
- x86 still fails to dispatch it: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3248-3357`

That means scanner-generated bitfield blobs are structurally correct and can be marked active, but the current x86 backend will not apply them.

### Overlap and priority semantics

v4 userspace has explicit overlap arbitration:

- family priority ranking: `scanner/src/engine.cpp:203-218`
- overlap detection and winner selection: `scanner/src/engine.cpp:221-239`, `scanner/src/engine.cpp:799-843`
- materialized v4 rules get arbitration priority copied into `rule.priority`: `scanner/src/engine.cpp:929-958`

Kernel-side semantics are weaker:

- rules are sorted by `(site_start, -priority)` only (`vendor/linux-framework/kernel/bpf/jit_directives.c:487-502`, `vendor/linux-framework/kernel/bpf/jit_directives.c:2458-2460`)
- lookup only returns a rule when `insn_idx == rule->site_start`; interior coverage is not enough (`vendor/linux-framework/kernel/bpf/jit_directives.c:2485-2522`)
- there is no separate overlap rejection pass

So the current system depends on userspace not emitting ambiguous overlaps. v4 largely does that; v5 builtin scanning also avoids most overlaps by greedy first-match advancement (`scanner/src/pattern_v5.cpp:1262-1291`), but the kernel contract itself is still underspecified.

### How v5 pattern + binding generation works

The current v5 pipeline is:

1. Build builtin descriptor libraries per family:
   - cmov: `scanner/src/pattern_v5.cpp:391-739`
   - wide: `scanner/src/pattern_v5.cpp:741-886`
   - rotate: `scanner/src/pattern_v5.cpp:888-1072`
   - lea: `scanner/src/pattern_v5.cpp:1074-1110`
   - bitfield: `scanner/src/pattern_v5.cpp:1112-1223`
2. Linear-scan xlated BPF and emit `V5PolicyRule`s from the first matching descriptor at each site: `scanner/src/pattern_v5.cpp:1225-1299`
3. Serialize `BPF_JIT_RK_PATTERN` wire rules with bindings and constraints: `scanner/src/pattern_v5.cpp:1302-1375`
4. Kernel re-validates the descriptor syntax, exact match, extracted bindings, and canonical params: `vendor/linux-framework/kernel/bpf/jit_directives.c:2238-2338`

This alignment is good. The gap is backend completion and observability, not basic wire compatibility.

## 5. Missing Interface Features

### No accepted/rejected-rule report

There is no log buffer or structured feedback in the recompile syscall ABI:

- UAPI attr has only `prog_fd`, `policy_fd`, `flags` (`vendor/linux-framework/include/uapi/linux/bpf.h:2169-2173`)
- kernel handler returns only `0` or `errno` (`vendor/linux-framework/kernel/bpf/jit_directives.c:2604-2675`)

Kernel does print per-rule debug lines internally:

- `pr_debug(... active/rejected ...)` in `vendor/linux-framework/kernel/bpf/jit_directives.c:2462-2471`

But that is not a user-visible interface and cannot support normal policy iteration.

### No site introspection

The kernel never reports:

- which candidate sites it found
- which rules matched
- which rules were active but later fell back during emission

That is particularly painful for the current bitfield gap, because x86 can accept the rule at parse time and still silently fall through to stock in `do_jit()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3465-3505`).

### No multi-program policy submission

The syscall is one-program-at-a-time by construction:

- one `prog_fd`
- one `policy_fd`
- no array form, no batch mode

See `vendor/linux-framework/include/uapi/linux/bpf.h:2169-2173` and `vendor/linux-framework/kernel/bpf/jit_directives.c:2617-2645`.

That forces userspace frameworks to loop:

- e2e live apply loops per program: `e2e/common/recompile.py:145-186`
- macro corpus live apply also loops per attached program: `corpus/_driver_impl_run_macro_corpus.py:705-715`

## 6. Design Alignment With The Thesis

The design doc’s thesis is explicit: kernel owns safety, userspace owns optimization policy (`docs/kernel-jit-optimization-plan.md:15-20`, `docs/kernel-jit-optimization-plan.md:44-46`, `docs/kernel-jit-optimization-plan.md:77-87`, `docs/kernel-jit-optimization-plan.md:166-188`).

### Where the current code matches that thesis

Kernel-owned safety is real:

- digest/program binding: `vendor/linux-framework/kernel/bpf/jit_directives.c:2414-2424`
- architecture binding: `vendor/linux-framework/kernel/bpf/jit_directives.c:2426-2435`
- CPU gating: `vendor/linux-framework/kernel/bpf/jit_directives.c:1541-1559`, `vendor/linux-framework/kernel/bpf/jit_directives.c:2005-2010`
- reject side-effectful sites: `vendor/linux-framework/kernel/bpf/jit_directives.c:1510-1539`
- exact pattern/constraint/binding validation: `vendor/linux-framework/kernel/bpf/jit_directives.c:1955-2037`, `vendor/linux-framework/kernel/bpf/jit_directives.c:2238-2338`
- subprog safety: `vendor/linux-framework/kernel/bpf/jit_directives.c:2040-2076`
- fail-closed stock fallback on emit failure: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3504-3505`

Userspace-owned optimization is also real on the v4 path:

- userspace scans candidate sites (`scanner/src/scanner.cpp:379-985`)
- userspace arbitrates overlaps (`scanner/src/engine.cpp:799-843`)
- userspace chooses native forms/config overrides/profile hooks (`scanner/src/engine.cpp:846-958`)

### Where the split is currently blurred

`v5` builtin path bakes policy into discovery order

- `scan_v5_builtin()` does first-match-wins based on descriptor ordering (`scanner/src/pattern_v5.cpp:1235-1291`)
- all emitted v5 rules get `priority = 0` (`scanner/src/pattern_v5.cpp:118-130`)

That means part of the optimization policy is currently encoded in the builtin descriptor list rather than in an explicit userspace policy layer.

`bounds_window` is exactly the kind of safety proof that should stay in kernel/verifier

- The current interface cannot express it, which is the correct pressure signal. If this directive is added, the retained-fact legality decision belongs in kernel land, not in the scanner.

The kernel currently hides some safety/application outcomes from userspace

- silent stock fallback on failed emit preserves safety
- but without feedback, userspace cannot tell whether its optimization request was realized

That is not a safety violation, but it weakens the “userspace controls optimization” story because userspace cannot observe the true applied optimization set.

## 7. What Can Be Added With Zero Kernel Changes

The honest answer is: new *patterns* can be added with zero kernel changes; new *safe variant classes* cannot.

### Strong zero-kernel-change candidates

`broader cmov_select`

- Any new shape that still binds to `(dst_reg, cond_op, cond_a, cond_b, true_val, false_val, width)` can be added in the scanner/pattern library only.
- The current v5 library already demonstrates this: one canonical `COND_SELECT` lowering is fed by basic diamonds, guarded updates, wide diamonds, and switch-chain patterns in `scanner/src/pattern_v5.cpp:391-739`.

`more rotate idioms`

- Any shift/or sequence that still binds to `(dst_reg, src_reg, amount, width)` can be added purely in userspace.
- Current evidence: multiple 4/5/6-insn rotate shapes all feed the same canonical form in `scanner/src/pattern_v5.cpp:888-1072`.

`more lea/address-calc idioms`

- Anything reducible to `(dst_reg, base_reg, index_reg, scale)` can be added purely in userspace.
- Current LEA canonical form is narrow but the transport is already sufficient (`scanner/src/pattern_v5.cpp:1074-1110`).

`packet_ctx_wide_load`, if kept as `WIDE_MEM`

- Because the x86 emitter already supports widths `2..8` and big-endian chunking (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2320-2357`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2729-2757`), new packet/context byte-ladder descriptors can likely be added without kernel changes.
- The limiting factor is descriptor work, not ABI work.

### Not actually zero-kernel-change today

`bitfield_extract`

- In principle the interface is ready.
- In this checkout it is not a zero-kernel-change addition because x86 dispatch is incomplete (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3248-3357`).

### Not zero-kernel-change by design

- `branch_reorder`
- `bounds_window`
- anything that needs verifier facts or non-local CFG rewriting

## 8. Directives #78-#83: Required Kernel Changes

The planning doc lists the next directives here: `docs/kernel-jit-optimization-plan.md:383-388`.

### Patch-surface estimate from the current checkout

| Item | Needs `bpf.h` UAPI change? | Needs kernel code change? | Needs userspace code change? | Likely delta from current tree |
| --- | --- | --- | --- | --- |
| `#78` broaden `cmov_select` recognition | No | No | Yes | userspace `~50-200` LOC |
| `#79` `bitfield_extract` | No | Yes | Small | kernel `~20-60` LOC, userspace `~0-50` LOC |
| `#80` `packet_ctx_wide_load` | No if expressed as `WIDE_MEM` | Usually no | Yes | userspace `~80-250` LOC |
| `#81` `branch_reorder` | Yes | Yes, substantial | Yes | kernel `~300-600+` LOC, userspace `~150-300` LOC |
| `#82` `bounds_window` | Probably yes | Yes, substantial | Yes | kernel `~250-500+` LOC, userspace `~100-250` LOC |
| `#83` kernel cleanup patches | No | Yes | No | kernel-only, `~20-150` LOC per patch |

### Notes per item

`#78` broaden `cmov_select`

- This is already mostly a userspace problem. v4 scanner has generalized diamonds and switch-style shapes (`scanner/src/scanner.cpp:395-519`), and v5 already has a broad descriptor library (`scanner/src/pattern_v5.cpp:391-739`).
- Remaining work is descriptor/scanner coverage and benchmarking, not kernel ABI.

`#79` `bitfield_extract`

- The transport and most implementation are already present.
- The required kernel fix is to wire x86 rule-form mapping and add a `CF_BITFIELD_EXTRACT` dispatch arm to `bpf_jit_try_emit_rule()`.
- The required userspace work is mostly testing plus updating reporting scripts that currently ignore extract counts (`e2e/common/recompile.py:58-77`, `corpus/run_corpus_runnability.py:367-401`).

`#80` `packet_ctx_wide_load`

- The docs assume a kernel emitter extension, but the current x86 emitter already handles the hard part: arbitrary widths `2..8` and endian-aware chunking.
- If the new directive is “new patterns that still canonicalize to `WIDE_MEM`”, this is userspace-only.
- Kernel work is only needed if you decide that packet/context widening requires an additional safety proof beyond exact ladder matching.

`#81` `branch_reorder`

- This is not a peephole. It does not fit the current site-local consume-and-emit interface.
- Expect new UAPI, new kernel legality logic, and likely a verifier-aware or CFG-aware rewrite contract.

`#82` `bounds_window`

- This is also not just another pattern descriptor.
- The legality question is about retained readable-window facts, not about local syntax. That belongs in kernel/verifier logic and likely needs a new interface concept.

`#83` cleanup patches

- These are orthogonal baseline improvements, exactly as the gap analysis says (`docs/tmp/directive-gap-analysis.md:32-34`).
- They do not belong in the recompile interface story and should not force UAPI changes.

## 9. Benchmark Framework Alignment

### What is covered today

The repo does exercise the real recompile syscall:

- rigorous micro defines both v4 and v5 recompile modes in `micro/orchestrator/rigorous.py:66-114`
- `micro_exec` auto-scans xlated BPF, builds a policy blob, seals a memfd, and issues raw `BPF_PROG_JIT_RECOMPILE` in `micro/runner/src/kernel_runner.cpp:817-990`
- e2e live-program flows shell out to `scanner apply --prog-fd ... --all --v5` in `e2e/common/recompile.py:137-186`
- runnability corpus probes v4/v5 recompile through `micro_exec run-kernel --compile-only` in `corpus/run_corpus_runnability.py:153-157`, `corpus/run_corpus_runnability.py:356-364`, `corpus/run_corpus_runnability.py:455-565`
- macro corpus has a `kernel_recompile_v5` runtime and live apply path in `corpus/config/macro_corpus.yaml:19-25`, `corpus/_driver_impl_run_macro_corpus.py:705-715`

### Gaps

Default micro runs do not cover recompile

- `micro/run_micro.py` is only a thin wrapper (`micro/run_micro.py:12-17`)
- suite defaults in `config/micro_pure_jit.yaml` are only `llvmbpf` and `kernel` (`config/micro_pure_jit.yaml:23-28`)

Most live/e2e coverage is v5-only

- `e2e/common/recompile.py` only invokes `--all --v5` (`e2e/common/recompile.py:110-124`, `e2e/common/recompile.py:162-176`)
- there is no matching v4 live-program harness

Explicit policy blobs are effectively unbenchmarked

- command plumbing exists for `--policy-blob` and `--directive-blob` in `micro/orchestrator/commands.py:66-67`
- but even the local demo notes that explicit `--policy-blob` currently returns `EINVAL` in this checkout (`micro/archive/scripts/demo_policy_iteration.py`)

Tracing corpus under-tests recompile

- tracing corpus only does a compile-only recompile probe (`corpus/_driver_impl_run_corpus_tracing.py:658-684`)
- the script explicitly states that attached re-JIT plus re-measure is not implemented (`corpus/_driver_impl_run_corpus_tracing.py:929-933`)

Reporting is missing `bitfield_extract`

- e2e parser only extracts total/cmov/wide/rotate/lea (`e2e/common/recompile.py:58-77`)
- runnability offline parser also omits extract (`corpus/run_corpus_runnability.py:367-401`)

No multi-program/shared-policy benchmark exists

- all current live-program harnesses loop one program at a time
- that means the interface question “how should one policy be applied to N programs?” is untested in practice

### Overall verdict

The benchmark framework is good enough to validate the existence of the recompile path and to measure syscall-backed end-to-end effects. It is not yet a complete interface evaluation harness. The biggest missing pieces are:

1. explicit-policy-blob coverage
2. load-time directive coverage
3. v4 live-program coverage
4. multi-program/shared-policy coverage
5. bitfield-aware reporting

## Recommended Next Patches

Priority order:

1. Finish `bitfield_extract` on x86 by wiring `BPF_JIT_RK_BITFIELD_EXTRACT` into `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3193-3208` and adding a `BPF_JIT_CF_BITFIELD_EXTRACT` arm beside the existing canonical cases in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3265-3357`.
2. Add a structured feedback channel to `BPF_PROG_JIT_RECOMPILE` so userspace can observe accepted, rejected, and emitted rules. The planning doc already tracks this gap at `docs/kernel-jit-optimization-plan.md:354-356`.
3. Move v5 off the builtin greedy path and onto the existing `PolicyEngine`, so discovery and policy become separate again.
4. Treat `packet_ctx_wide_load` as a userspace-first experiment under `CF_WIDE_MEM`. Only add kernel work if the desired patterns demand a stronger safety proof than exact-ladder matching.
5. Keep `branch_reorder` and `bounds_window` out of the current ABI until there is a verifier-aware safety story. Trying to squeeze them into the present local-site transport would weaken the thesis instead of strengthening it.
