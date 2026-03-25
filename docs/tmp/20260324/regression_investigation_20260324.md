# Regression Investigation (2026-03-24)

## Scope

- Repo context: `docs/kernel-jit-optimization-plan.md`
- Micro latest result: `micro/results/vm_micro_20260325_023400`
- Corpus latest result: `corpus/results/vm_corpus_20260325_023726`
- Katran e2e latest successful result: `e2e/results/katran_20260325_015121`
- Katran e2e latest directories on 2026-03-25:
  - `e2e/results/katran_20260325_012929`: failed
  - `e2e/results/katran_20260325_030103`: failed
  - so the latest usable Katran e2e data is `2026-03-25 01:51:21`
- Offline daemon pass replay used to recover per-pass detail that latest micro/corpus artifacts did not retain:
  - `/tmp/bpfrejit_offline_analysis_20260324/report.json`

Method note:

- Latest `vm_micro` and `vm_corpus` artifacts only keep summary `rejit` metadata, not full `daemon_debug` JSON.
- To recover per-pass `sites_applied / insns_before / insns_after`, I replayed the current daemon pass pipeline offline on the exact `.bpf.o` objects.
- For Katran e2e, the latest successful run already contains full live daemon JSON in `metadata.json`, so the offline replay is only a cross-check.

---

## Task 1: `code_clone_2` Regression (0.42x)

### 1. What `code_clone_2` does

Source: `micro/programs/code_clone_2.bpf.c`

- Reads `count=128`, `seed`, then 128 x `u64` values.
- Each loop iteration executes two cloned scalar blocks:
  - `acc += value ^ (...)`
  - `acc ^= acc >> k`
  - `acc = rotl64(acc, 4)`
- So the benchmark is a tiny hot loop with:
  - one hot 8-byte memory load per iteration
  - two cloned rotate-like scalar blocks per iteration
  - essentially no meaningful branch-prediction story in the steady-state loop

Important compiled-code fact:

- The current rotate matcher only rewrites one of the two cloned rotate idioms in the compiled BPF.
- `llvm-objdump -d micro/programs/code_clone_2.bpf.o` shows one clean rotate idiom in the loop, while the second clone is interleaved enough that it does not match the daemon's strict provenance rule.

### 2. Latest micro result data

From `micro/results/vm_micro_20260325_023400/details/result.json`:

| benchmark | stock ns | rejit ns | ratio | xlated bytes | native bytes | passes | total sites |
|---|---:|---:|---:|---:|---:|---|---:|
| `code_clone_2` | 281 | 670 | 0.419x | 912 -> 824 | 488 -> 440 | `wide_mem, rotate` | 2 |
| `branch_dense` | 652 | 799 | 0.816x | 1416 -> 1240 | 747 -> 653 | `wide_mem, rotate` | 4 |
| `mixed_alu_mem` | 540 | 666 | 0.811x | 2136 -> 2064 | 1101 -> 1069 | `wide_mem, extract` | 3 |
| `large_mixed_500` | 773 | 859 | 0.900x | 4384 -> 4200 | 2158 -> 2050 | `wide_mem, rotate` | 8 |

Key observation:

- All four regressions shrink both BPF bytecode and native code.
- So these are not code-size-bloat regressions.

### 3. Daemon per-pass breakdown (`code_clone_2.bpf.o`)

Offline replay on `micro/programs/code_clone_2.bpf.o:xdp`:

- Before: 114 insns
- After: 103 insns
- Total delta: -11 insns

Per pass:

- `wide_mem`: 1 site, `114 -> 105`, delta `-9`
- `rotate`: 1 site, `105 -> 103`, delta `-2`
- `cond_select`: 0
- `extract`: 0
- `endian_fusion`: 0
- `branch_flip`: 0, skipped due no PMU data

### 4. Root cause analysis (`code_clone_2`)

#### 4.1 `rotate` did not cause instruction bloat

It did the opposite:

- bytecode: `912 -> 824`
- native code: `488 -> 440`
- offline pass replay: `rotate` itself is only `-2 insns`

So the hypothesis "rotate kinsn replacement inflated code size" is falsified for `code_clone_2`.

#### 4.2 This is not an I-cache regression

`code_clone_2` is tiny, and it got smaller after REJIT.

- Native size shrank by 48 bytes.
- BPF size shrank by 88 bytes.

That does not fit an I-cache-pressure explanation.

#### 4.3 This is not a branch-prediction regression

`code_clone_2`'s hot loop is essentially straight-line scalar work.

- No `cond_select`
- No `branch_flip`
- No branch-layout mutation in the hot path

So branch prediction interference is not the explanation here.

#### 4.4 `rotate` is inline on x86, not an out-of-line function call

Current x86 lowering facts:

- `module/x86/bpf_rotate.c` emits inline native code: `mov` + `rol imm`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` calls `emit_kinsn_desc_call()`, which inlines `kinsn->emit_x86`

So the current x86 path is not paying a helper-style function call overhead for `rotate`.

This falsifies the hypothesis "rotate regressed because module-not-loaded fallback became a function call" for the measured x86 micro results.

#### 4.5 Most likely root cause: `wide_mem` on hot packet/data loads

`wide_mem` is the only pass family common to all four regressions:

- `code_clone_2`: `wide_mem + rotate`
- `branch_dense`: `wide_mem + rotate`
- `mixed_alu_mem`: `wide_mem + extract`
- `large_mixed_500`: `wide_mem + rotate`

Additional evidence from the same latest micro run:

- many `wide_mem`-only benchmarks also regress
  - `memory_pair_sum`: `0.80x`
  - `bitcount`: `0.83x`
  - `nested_loop_3`: `0.88x`
  - `load_byte_recompose`: `0.93x`

The current `wide_mem` pass:

- only checks structural byte-ladder shape, branch-target safety, and scratch-register liveness
- does **not** check pointer kind or alignment
- directly replaces the ladder with `BpfInsn::ldx_mem(size, dst, base, off)`

Source: `daemon/src/passes/wide_mem.rs`

Why this is plausible:

- The original byte ladder uses byte loads, which are always alignment-safe.
- `wide_mem` turns them into `LDX_MEM H/W/DW`.
- On XDP/packet-style data pointers, 4/8-byte loads can be legal but still slower than byte loads when alignment is poor.
- `code_clone_2` is exactly a tiny hot loop where one 8-byte load site executes every iteration; a single bad `wide_mem` choice can dominate total runtime.

#### 4.6 `rotate` may be a secondary contributor, but not the shared root cause

Why I do **not** think `rotate` is the primary shared cause:

- `mixed_alu_mem` regresses without any `rotate`
- `rotate64_hash` in the same latest micro run improves dramatically (`2.63x`)
- `mega_basic_block_2048` with `wide_mem + rotate` improves (`1.17x`)

So `rotate` is not inherently bad. At most:

- it can be neutral/slightly negative in low-site-count programs
- or partially matched cloned code can reduce expected upside

But the common regression signal is `wide_mem`, not `rotate`.

### 5. Same-root-cause check for related regressions

#### `branch_dense` (0.82x)

Per-pass replay:

- `wide_mem`: 2 sites, `177 -> 159`, delta `-18`
- `rotate`: 2 sites, `159 -> 155`, delta `-4`

Analysis:

- No `cond_select`
- No `branch_flip`
- So the benchmark's dense branches were not rewritten
- branch-prediction interference is therefore not the regression mechanism
- Same pattern as `code_clone_2`: code shrank, but `wide_mem` is present on hot loads

Conclusion:

- Same likely root cause: `wide_mem` primary, `rotate` secondary at most

#### `mixed_alu_mem` (0.81x)

Per-pass replay:

- `wide_mem`: 1 site, `267 -> 258`, delta `-9`
- `extract`: 2 sites, `258 -> 258`, delta `0`

Analysis:

- This is the strongest evidence against "rotate is the root cause", because there is no rotate here.
- `extract` on x86 currently emits `shr` + `and` in `module/x86/bpf_extract.c`; it is not a real `BEXTR` lowering yet.
- Since `extract` contributes zero bytecode delta and no real native fusion, it is likely neutral.

Conclusion:

- The regression is best explained by the single `wide_mem` site

#### `large_mixed_500` (0.90x)

Per-pass replay:

- `wide_mem`: 1 site, `548 -> 539`, delta `-9`
- `rotate`: 7 sites, `539 -> 525`, delta `-14`

Analysis:

- Still not code-size growth
- Still not branch-prediction or branch-layout
- Despite 7 rotate sites, the regression is modest (`0.90x`), not catastrophic
- This again points to "a generally questionable `wide_mem` policy, with rotate sometimes not paying off"

Conclusion:

- Same root cause family as above

### 6. Recommended fixes (`code_clone_2` cluster)

#### Recommendation 1: make `wide_mem` much more conservative

Best short-term fix:

- skip `wide_mem` for packet/XDP-style programs until we have pointer-kind/alignment awareness

Best longer-term fix:

- consume verifier-proven pointer/alignment metadata before merging byte ladders into `LDX_MEM W/DW`

If that metadata is not available yet, conservative heuristics are better than the current blind merge:

- disable 8-byte `wide_mem` on XDP programs
- or disable `wide_mem` entirely for low-site-count programs where upside is small and regressions are common

#### Recommendation 2: keep `rotate`, but do not blame it first

- do **not** globally disable `rotate`
- it clearly helps on some rotate-heavy benchmarks
- if needed, add a low-site-count / tiny-program policy guard so `rotate` only runs where ROI is likely positive

#### Recommendation 3: do not count `extract` as a real x86 optimization yet

- `module/x86/bpf_extract.c` emits `shr + and`, not `BEXTR`
- until real `BEXTR` lowering exists, `extract` should probably be opt-in or deprioritized in policy

#### Recommendation 4: improve result artifacts

- persist per-sample `daemon_debug` JSON in latest `vm_micro` / `vm_corpus`
- current summaries hide the actual per-pass breakdown and make regressions harder to diagnose

---

## Task 2: Katran `balancer_ingress` Regression

## 1. Latest corpus result (`balancer_ingress`)

From `corpus/results/vm_corpus_20260325_023726/details/result.json`:

- Program: `corpus/build/katran/balancer.bpf.o:balancer_ingress`
- Corpus speedup ratio: `0.40625x`
- Stock exec ns: `13`
- REJIT exec ns: `32`
- Stock xlated bytes: `23872`
- REJIT xlated bytes: `23776`
- Stock native bytes: `13654`
- REJIT native bytes: `13606`
- REJIT insn delta: `-12`

Inventory-side candidate counts in the same corpus result:

- `cmov_sites`: 5
- `wide_sites`: 4
- `rotate_sites`: 20
- `total_sites`: 29

But this inventory view is misleading for root cause, because it shows **eligible** families, not what the live daemon actually applied.

## 2. Latest successful Katran e2e result

From `e2e/results/katran_20260325_015121/metadata.json`:

- Comparison date: `2026-03-25 01:51:21`
- Latest two later Katran runs on `2026-03-25` failed and are not usable for performance
- BPF avg ns/run median:
  - stock: `233.20 ns`
  - REJIT: `249.29 ns`
  - delta: `+6.90%`
  - speedup ratio: `0.935x`
- Live program code size:
  - stock xlated/native: `23872 / 13654`
  - REJIT xlated/native: `23776 / 13606`
- Object inventory:
  - object insn count: `2322`
  - section: `xdp`
  - program: `balancer_ingress`

Again: the program got slightly smaller, but slower.

## 3. What the daemon actually did to `balancer_ingress`

### 3.1 Actual live daemon output (latest successful e2e)

From `e2e/results/katran_20260325_015121/metadata.json`:

- Original insns: `2546`
- Final insns: `2534`
- Total sites applied: `6`
- Verifier retries: `0`

Per pass:

- `wide_mem`: applied `4`, `2546 -> 2534`, delta `-12`
- `rotate`: applied `0`, skipped `1`
  - reason: `subprog pseudo-calls not yet supported`
- `cond_select`: applied `0`, skipped `5`
  - reason: `packed ABI requires register true/false operands`
- `extract`: applied `0`
- `endian_fusion`: applied `2`, `2534 -> 2534`, delta `0`
- `branch_flip`: applied `0`

### 3.2 Offline replay on the object file

Replay on `corpus/build/katran/balancer.bpf.o:xdp` matches the live daemon:

- Object before: `2322`
- Object after: `2310`
- Per pass:
  - `wide_mem`: 4 sites, `2322 -> 2310`, delta `-12`
  - `rotate`: 0 applied, 1 skipped (`subprog pseudo-calls not yet supported`)
  - `cond_select`: 0 applied, 5 skipped (`packed ABI requires register true/false operands`)
  - `endian_fusion`: 2 applied, delta `0`

### 3.3 Historical verifier fragility on the same program

An earlier Katran e2e run, `e2e/results/katran_20260324_043223`, shows:

- daemon found `6` sites and first rewrote `2546 -> 2538`
- then verifier rejected:
  - `endian_fusion` at PC `438`
  - then `wide_mem` at PC `436`
- final result after rollback: no transforms applied

So packet-pointer `wide_mem` / `endian_fusion` on `balancer_ingress` have already been fragile enough to cause verifier rollback in a recent run.

This is not the direct cause of the latest successful regression, but it is strong evidence that these transformations are exactly the risky area.

## 4. Root cause analysis (`balancer_ingress`)

### 4.1 `CMOV` is not the cause

The hypothesis "CMOV is slower than a highly predictable branch" does **not** explain the current Katran regression, because:

- `cond_select` applied `0` sites
- all 5 candidate sites were skipped

So there is no CMOV in the final REJITed `balancer_ingress`.

### 4.2 `rotate` call overhead is not the cause

Two independent reasons:

- `rotate` applied `0` sites on `balancer_ingress`
- even if it had applied, the x86 path is native inline emit, not a helper call

So the current Katran regression is not a rotate-call-overhead issue.

### 4.3 `wide_mem` is the main suspect

This is the only substantial transformation that definitely changed the program:

- `4` applied sites
- entire `-12` insn delta comes from `wide_mem`
- same family is common across the bad micro regressions

For `balancer_ingress`, the program is:

- large
- packet-data heavy
- XDP generic in the e2e run

This is exactly where blind byte-ladder -> wide-load fusion is most likely to be alignment-sensitive and workload-sensitive.

### 4.4 `endian_fusion` is at best neutral, not a likely source of upside

On x86, current `module/x86/bpf_endian.c` does **not** emit `MOVBE`.

It emits:

- load16 + `rol16 8`
- load32 + `bswap32`
- load64 + `bswap64`

So the current x86 "endian fusion" is not a true single-instruction fusion. That matches the measured pass behavior:

- `endian_fusion` applied `2` sites
- bytecode delta from the pass itself is `0`

This means:

- it is unlikely to provide meaningful speedup on x86 in its current form
- at best it is neutral
- if it perturbs codegen around packet loads, it can easily be slightly negative

### 4.5 This is not an I-cache-footprint regression

Both corpus and e2e show code size shrinking slightly:

- xlated: `23872 -> 23776`
- native: `13654 -> 13606`

That does not fit a footprint/I-cache expansion story.

For a program this large, I-cache is still a general concern, but the observed direction of code-size change argues against it being the primary cause here.

## 5. Recommended fixes (`balancer_ingress`)

### Recommendation 1: skip `wide_mem` on Katran/XDP packet programs for now

Short-term, highest-confidence fix:

- disable `wide_mem` for `xdp` packet programs, or at least for `balancer_ingress`

Rationale:

- it is the only applied family with clear negative evidence across both micro and Katran
- it has recent verifier-fragility evidence on the same program family

### Recommendation 2: disable `endian_fusion` on x86 until it emits a real native fusion

Current x86 lowering is not `MOVBE`; it is `load + bswap`.

So for x86 policy:

- skip `endian_fusion` by default
- only re-enable once it actually lowers to a better native sequence than the stock JIT already produces

### Recommendation 3: fix reporting so "eligible" and "applied" are not conflated

Today the corpus inventory for Katran says:

- candidate families: `cmov`, `wide`, `rotate`

But the actual applied live passes were:

- `wide_mem`, `endian_fusion`

This makes regression diagnosis harder and can point blame at the wrong family.

Needed fix:

- report both:
  - candidate/eligible families
  - actual applied families with per-pass site counts

### Recommendation 4: use PGO/guardrails before enabling packet-load rewrites globally

Best long-term policy:

- only apply packet-load rewrites when profiling proves a win
- otherwise keep stock JIT for packet-heavy XDP programs

---

## Bottom Line

### `code_clone_2`

- Detailed data:
  - stock `281 ns`, REJIT `670 ns`, `0.419x`
  - xlated `912 -> 824`
  - native `488 -> 440`
- Daemon transforms:
  - `wide_mem`: 1 site, `-9 insns`
  - `rotate`: 1 site, `-2 insns`
- Root cause:
  - not code-size inflation
  - not I-cache
  - not branch prediction
  - most likely `wide_mem` on hot packet/data loads, with `rotate` at most a secondary factor
- Fix:
  - skip or heavily gate `wide_mem` for packet/XDP-style loads

### `branch_dense`, `mixed_alu_mem`, `large_mixed_500`

- Shared signal:
  - all regressions include `wide_mem`
  - no branch-layout or CMOV rewrite was involved
- Root cause:
  - same `wide_mem` policy issue
  - `rotate` / `extract` are secondary or neutral depending on program
- Fix:
  - same as above: tighten `wide_mem` policy first

### Katran `balancer_ingress`

- Detailed data:
  - corpus: stock `13 ns`, REJIT `32 ns`, `0.406x`
  - e2e: stock median `233.20 ns/run`, REJIT median `249.29 ns/run`, `+6.90%`
  - xlated `23872 -> 23776`
  - native `13654 -> 13606`
- Daemon transforms:
  - actual applied: `wide_mem` 4 sites + `endian_fusion` 2 sites
  - `rotate` not applied
  - `cond_select` not applied
- Root cause:
  - not CMOV
  - not rotate call overhead
  - not code-size / I-cache expansion
  - most likely `wide_mem` on packet loads; `endian_fusion` is also not buying real x86 native improvement
- Fix:
  - skip `wide_mem` and `endian_fusion` for Katran/XDP packet paths until alignment-aware or PGO-guided policy exists
