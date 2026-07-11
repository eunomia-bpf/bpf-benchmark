# Rotate 0-Apply Investigation for KVM 5-KOperation Corpus

Date: 2026-05-05

Scope: read-only investigation of why `rotate` reported `sites_matched=0` and
`sites_applied=0` in
`corpus/results/x86_kvm_corpus_20260505_220116_564226/details/result.json`.
No benchmark rerun, app load, or code change was performed.

## Executive summary

- The latest 18-app / 507-program KVM run really had zero rotate candidates:
  every `rotate` `bpfopt_summary` has `sites_matched=0`, `sites_applied=0`,
  and `sites_skipped=0`. The 46 `rotate` `failed_rejit` records are no-op
  ReJIT failures after unchanged bytecode, not failed rotate rewrites.
- The older Tetragon table that showed 45 rotate failures did not mean 45
  rotate matches. The old schema had no `sites_matched`; the representative
  failure in `docs/tmp/rotate-tetragon-fix-20260505.md` had `changed=false` and
  `sites_applied=0`. Commit `b592a8bb` hid those no-op failures by skipping
  ReJIT when bpfopt reported unchanged output. Later changed-flag removal made
  no-op ReJIT reachable again.
- Offline bytecode census found no adjacent 64-bit `LSH/RSH + OR` rotate
  triplets in the available supported-app object artifacts. Relaxing the
  current 64-bit matcher's provenance, order, or result-register checks would
  unlock zero observed sites in this corpus evidence set.
- The missed opportunity is 32-bit rotate-like code, especially in Tetragon:
  available Tetragon objects contain 157 adjacent shift/shift/OR triplets where
  shift amounts sum to 32, including 39 with the same immediate-MOV provenance
  shape as the current rotate64 matcher. These are not safe to feed to
  `bpf_rotate64`; a legitimate optimization needs rotate32 semantics and an
  upper-32-zero proof or an exact equivalent 32-bit kop contract.
- Highest-ROI matcher work is: add a proven rotate32 path, then generalize
  provenance through a local reaching-definition/equivalence proof. Do not just
  remove the `dst_reg != tmp_reg` filter; it unlocked zero observed sites and is
  required by the current packed rotate kop ABI.

## Artifact inventory

### Latest retained result artifacts

Retained files under
`corpus/results/x86_kvm_corpus_20260505_220116_564226/details/`:

- `result.json`
- `progress.json`
- `daemon.stdout.log`
- `daemon.stderr.log`
- `apps/*.json`, one per runner/app:
  `bcc__*.json`, `bpftrace__*.json`, `cilium__agent.json`, `katran.json`,
  `otelcol-ebpf-profiler__profiling.json`, `tetragon__observer.json`,
  `tracee__monitor.json`

No retained files matched `*.tar.gz`, `*.report.json`, `*.bin`, verifier-log
names, or `failure-artifacts`.

Each per-app JSON contains:

- `app`, `runner`, `selected_workload`, `status`, `error`
- `baseline` and `post_rejit`, with raw BPF counter snapshots and workload
  stdout/stderr
- `rejit_result`, including current per-program pass records

The latest top-level result and per-app JSONs contain enough data to audit
current pass accounting because `rejit_result.per_program[].passes[]` embeds
each pass `bpfopt_summary` with `sites_matched`, `sites_applied`,
`sites_skipped`, `skip_reasons`, and instruction-count deltas.

Current pass totals from the latest 507-program result:

| pass | sites_matched | sites_applied | sites_skipped | pass statuses |
| --- | ---: | ---: | ---: | --- |
| `rotate` | 0 | 0 | 0 | 461 ok, 46 failed_rejit |
| `cond_select` | 2284 | 337 | 1947 | 459 ok, 48 failed_rejit |
| `bulk_memory` | 388 | 97 | 291 | 460 ok, 47 failed_rejit |
| `endian_fusion` | 248 | 2 | 246 | 461 ok, 46 failed_rejit |
| `extract` | 198 | 3 | 195 | 461 ok, 46 failed_rejit |

All non-ok `rotate` entries still had a no-op summary:
`insn_delta=0`, `sites_matched=0`, `sites_applied=0`, and
`sites_skipped=0`. They were concentrated in Tetragon and Cilium:

| app | rotate failed_rejit count | observed error class |
| --- | ---: | --- |
| `tetragon/observer` | 45 | mostly `ENOSPC` verifier-log/state explosion, plus the known Tetragon no-op ReJIT failures |
| `cilium/agent` | 1 | `EACCES` on `dump_bpf_prog` |

### Daemon-side files and cleanup behavior

Current daemon behavior in `daemon/src/commands.rs`:

- `WorkDir::new("bpfrejit-daemon-optimize")` creates a temp directory named
  like `bpfrejit-daemon-optimize-<pid>-<id>` under `std::env::temp_dir()`.
- `WorkDir::drop` removes that directory with `fs::remove_dir_all`.
- `try_apply_one` writes these transient files per program/pass:
  - `prog.bin`
  - `target.json` when kop target probing is needed
  - `verifier-states.json` when a stateful pass needs prior verifier states
  - `map-values.json` for map-inline side inputs
  - `pass-XX-<pass>.in.bin`
  - `pass-XX-<pass>.out.bin`
  - `pass-XX-<pass>.report.json`
  - `pass-XX-<pass>.verifier.log`

Verifier logs are written for both successful and failed ReJIT attempts:
`rejit_program()` writes `verifier_log_path` after `BPF_PROG_REJIT` returns,
including the error path. Successful logs are still only transient unless the
workdir is preserved through failure-artifact handling.

Failure workdirs can be serialized into `workdir_tar_b64` by the daemon when a
program has a failed pass. The runner then calls `_write_failure_workdir_tar`.
If `failure_artifacts_dir` is `None`, the tar is deliberately discarded.
`corpus/driver.py` sets that directory only when `--keep-failure-artifacts` is
used, which corresponds to `KEEP_FAILURE_ARTIFACTS=1` in the Makefile.

This latest run did not use `KEEP_FAILURE_ARTIFACTS=1`, so the transient
per-pass report/log/bin files were deleted or discarded. A filesystem check
also found no retained daemon optimize directories in `/tmp` and only:

```text
/var/tmp/bpfrejit-runtime
/var/tmp/bpfrejit-runtime/local_micro
```

### Live dump availability

`bpftool prog show` on the host failed with:

```text
Error: can't get next program: Operation not permitted
```

No BPF program was loaded manually. Ground-truth bytecode inspection therefore
used `llvm-objdump -d` on existing object artifacts under `corpus/build/...`
and `daemon/tests/fixtures/...`. The latest `result.json` remains definitive
for what the current rotate matcher reported on the live 507-program run, but
exact live-bytecode counts for a hypothetical relaxed matcher are not retained.

## Pre-fix -> post-fix reconciliation

The prior Tetragon-only result referenced by
`docs/tmp/rotate-tetragon-fix-20260505.md` is:

`corpus/results/x86_kvm_corpus_20260505_150239_039494`

The earlier full result used for the pre-fix comparison is:

`corpus/results/x86_kvm_corpus_20260505_091747_214593`

Those older results used an older schema. They have `error_programs`,
`applied`, and `changed`, but no per-pass `bpfopt_summary` and no
`sites_matched` field. The pass name has to be inferred from the error string.

Observed old accounting:

| result | app | requested | applied | not_applied | error pass counts |
| --- | --- | ---: | ---: | ---: | --- |
| pre-fix `091747` | `tetragon/observer` | 287 | 238 | 49 | `rotate` 45, `prefetch` 2, `cond_select` 1, `extract` 1 |
| post-fix `150239` | `tetragon/observer` | 287 | 238 | 49 | `prefetch` 46, `cond_select` 1, `map_inline` 2 |

The key reconciliation is that the 45 pre-fix `rotate` entries were failures
attributed to the rotate pass, not 45 successful matcher candidates.
`docs/tmp/rotate-tetragon-fix-20260505.md` explicitly records the representative
case as:

- `rotate changed=false`
- `sites_applied=0`
- bpfopt output bytecode was unchanged
- daemon nevertheless submitted that unchanged candidate to `BPF_PROG_REJIT`
  and hit the Tetragon verifier failure

Commit history confirms this:

- `b592a8bb Fix rotate no-op ReJIT blocker`
  - Added stricter rotate matching, including the `dst_reg != tmp_reg` filter.
  - Added daemon logic: if `report.changed` was false, verify output bytes were
    unchanged, record the report, and `continue` without ReJIT.
  - This changed where the first no-op failure surfaced; it did not prove that
    rotate had 45 matches.
- `35ed1536 Drop bpfopt unchanged-vs-bytecode sanity check`
  - Removed only the defensive byte-equality check for unchanged reports.
  - The no-op short-circuit still existed at that point.
- `c510c646` / `45c7a647` / `80d17034`
  - Removed the old changed/no-op reporting protocol and moved to opaque
    bpfopt pass-through summaries.
  - Current `daemon/src/commands.rs` reads `pass-XX.out.bin`, decodes it, and
    calls `rejit_program()` for every bpfopt-successful pass whose prerequisites
    are satisfied. There is no current no-op skip.
  - `80d17034`'s direct file-level diff in the inspected paths is small, but it
    is part of the changed-flag deletion series and the resulting current code
    has no `changed` gate.

The current `bpfopt/crates/bpfopt/src/passes/rotate.rs` matcher is semantically
the same as what `b592a8bb` left for matching. A diff from `b592a8bb` to current
`HEAD` shows removal of the old packed-availability check, the `changed` result
field, and tests tied to `PassManager`/`changed`; it does not loosen or tighten
`scan_rotate_sites` or `try_match_rotate`.

Conclusion: pre-fix "rotate failures = 45" became "rotate failures = 0" after
`b592a8bb` because no-op ReJIT was skipped. It did not mean "45 rotate matches
became 0." The latest run re-exposes no-op ReJIT failures because no-op
short-circuiting was later removed, and the current summaries prove rotate still
matched zero sites.

## Ground-truth triplet count

### Current matcher shape

Current `scan_rotate_sites` only considers three adjacent instructions and
delegates to `try_match_rotate`. The strict requirements are:

- instruction 2 must be `BPF_ALU64 | BPF_OR | BPF_X`
- the first two instructions must be adjacent 64-bit immediate shifts:
  - `RSH64_IMM` then `LSH64_IMM`, or
  - `LSH64_IMM` then `RSH64_IMM`
- shift amounts must sum to 64
- the two shift destination registers must differ
- the OR must combine exactly those two registers, in either source/destination
  order
- an immediate previous `MOV64_REG tmp, dst` must prove both shifted registers
  came from the same original value
- `dst_reg != tmp_reg`
- later safety checks reject interior branch targets, tail-call-helper-sensitive
  replacement windows, and `tmp_reg` live-out conflicts

### Object-artifact census

I scanned available object artifacts with `llvm-objdump -d`; no live programs
were loaded. The scanner counted adjacent shift/shift/OR triplets before
applying branch/liveness safety filters.

Root-level census:

| artifact root | objects | raw rot64 triplets | current-like rot64 matches | raw rot32 triplets | rot32 with immediate-MOV/result-not-tmp shape |
| --- | ---: | ---: | ---: | ---: | ---: |
| `corpus/build/x86_64/tetragon` | 94 | 0 | 0 | 157 | 39 |
| `corpus/build/x86_64/tracee` | 3 | 0 | 0 | 3 | 0 |
| `corpus/build/x86_64/katran` | 1 | 0 | 0 | 1 | 0 |
| `corpus/build/x86_64/bcc` | 57 | 0 | 0 | 0 | 0 |
| `corpus/build/opentelemetry-ebpf-profiler` | 3 | 0 | 0 | 0 | 0 |
| `daemon/tests/fixtures/cilium` | 3 | 0 | 0 | 0 | 0 |

Representative sampled programs/sections:

| sample | section | objdump insns | rot64 triplets | current-like rot64 | rot32 triplets | current-like rot32 |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `generic_kprobe_v61` | `.text` | 4689 | 0 | 0 | 2 | 0 |
| `generic_kprobe_v61` | `kprobe` | 6977 | 0 | 0 | 0 | 0 |
| `generic_kprobe_v511` | `kprobe` | 51811 | 0 | 0 | 4 | 1 |
| `generic_retkprobe_v61` | `.text` | 3882 | 0 | 0 | 1 | 0 |
| `generic_retkprobe_v61` | `kprobe/generic_retkprobe` | 3076 | 0 | 0 | 0 | 0 |
| `generic_tracepoint_v61` | `.text` | 4155 | 0 | 0 | 1 | 0 |
| `generic_tracepoint_v61` | `tracepoint` | 6521 | 0 | 0 | 0 | 0 |
| `generic_rawtp_v61` | `.text` | 4256 | 0 | 0 | 1 | 0 |
| `execve_event_v61` | `tracepoint` | 1463 | 0 | 0 | 0 | 0 |
| `tracee.bpf.o` | `.text` | 238 | 0 | 0 | 3 | 0 |
| `katran/balancer.bpf.o` | `xdp` | 2556 | 0 | 0 | 1 | 0 |

Two concrete Tetragon 32-bit examples:

```text
corpus/build/x86_64/tetragon/bpf_generic_kprobe.o, section kprobe
466: r2 = r1
467: r2 >>= 0x3
468: r1 <<= 0x1d
469: r1 |= r2
470: r1 <<= 0x20
471: r1 >>= 0x20
```

```text
corpus/build/x86_64/tetragon/bpf_generic_kprobe_v511.o, section kprobe
459: r1 = r2
460: r1 >>= 0x3
461: r2 <<= 0x1d
462: r2 |= r1
463: r1 = 0x0
464: r2 <<= 0x20
465: r2 >>= 0x20
```

These are not current rotate64 candidates because the shifts sum to 32, not 64.
The following zero-extension sequence is part of the semantics and cannot be
ignored.

Some raw rot32 triplets are not clean rotates. Example shape:

```text
r3 &= 0xffffff00
r3 >>= 0x8
r2 <<= 0x18
r2 |= r3
r2 <<= 0x20
r2 >>= 0x20
```

This looks like a byte-pack or masked field merge, not necessarily a rotate of
one original value. It must be rejected unless use-def analysis proves both
shifted registers are equivalent copies of the same source value and the high
bits satisfy the rotate32 admissibility condition.

## Matcher gap analysis

### 1. Shift width is 64-bit only

Current requirement: `BPF_ALU64` shifts with amounts summing to 64.

Observed impact:

- Raw adjacent 64-bit rotate triplets: 0 in all scanned supported-app object
  artifacts.
- Raw adjacent 32-bit rotate-like triplets: 161 total in scanned artifacts,
  157 of them in Tetragon.
- 39 Tetragon rot32 triplets already have the immediate-MOV/result-not-tmp
  syntactic shape analogous to the current rotate64 matcher.

This is the largest real gap. However, replacing these sites with
`bpf_rotate64` would be incorrect. For example:

```text
tmp = x
tmp >>= 3
x <<= 29
x |= tmp
x <<= 32
x >>= 32
```

If `x` has non-zero upper 32 bits, the lower 32 bits after the sequence can
include original bits 32..34. A native 32-bit rotate of `x`'s low word would not
preserve that unless the optimizer proves `x` is already zero-extended to 32
bits. The trailing `<<=32; >>=32` masks the result, but it does not by itself
prove the input upper half was zero.

Safety required:

- A distinct rotate32 kop contract, or a rotate kop payload width flag, not
  reuse of current `bpf_rotate64`.
- A proof that source upper 32 bits are zero at the site, either from a local
  syntactic zero-extension/use-def proof or verifier-state side input.
- Handling of the trailing zero-extension pair as part of the matched window or
  as a required postcondition.
- Existing branch-target, tail-call-sensitive-window, and live-out checks must
  still apply.

### 2. Immediate provenance MOV

Current requirement: the copy instruction must be exactly `shift_pc - 1` and
must be `MOV64_REG tmp, dst`.

Observed impact:

- For rotate64 in this corpus evidence set: zero. There are no raw 64-bit
  triplets for this requirement to reject.
- For rotate32: 39 of 157 Tetragon raw rot32 triplets have this current-like
  immediate-MOV shape. The remaining 118 include other shapes; many are masked
  byte-pack forms and are not automatically legitimate rotates.

The immediate-MOV rule is intentionally conservative. Its comment is correct:
if the pass starts the replacement at the MOV and allows arbitrary intervening
instructions, it can silently drop side effects.

Safety required for relaxation:

- Replace "immediate previous MOV" with a local reaching-definition/equivalence
  proof, not a broader regex.
- Prove both shifted registers derive from the same source value.
- Prove neither value is clobbered between the copy and its shift.
- Preserve any intervening instructions; do not replace a wide window that
  includes side effects.
- Either leave the provenance MOV in place and replace only the shift/OR window,
  or remove the MOV only when it is directly adjacent and provably dead.
- Keep the `tmp_reg` live-out check, because the original sequence destroys the
  tmp copy and the native kop path does not.

### 3. Fixed shift order and OR operand order

Current requirement: the matcher supports both shift orders:

- `RSH; LSH; OR`
- `LSH; RSH; OR`

It also supports either OR operand order as long as the OR combines the two
shift destination registers.

Observed impact:

- This is not a current gap for the sampled corpus. The scanner looked for both
  shift orders and both OR orders.
- There may be non-adjacent forms with instructions between the shifts and OR,
  but no retained live bytecode is available to quantify them. Matching those
  would require real dataflow and side-effect preservation, not an adjacency
  tweak.

### 4. Result register and `dst_reg != tmp_reg`

Current behavior: `result_reg` is the OR destination. The matcher does not
require the result to be written back to the original value register. It does,
however, reject sites where the OR destination is the copy/scratch register:

```rust
(dst_reg != tmp_reg).then_some(...)
```

Observed impact:

- For rotate64: unreachable in observed artifacts because raw rot64 triplets are
  zero.
- For the full rot32 object scan, immediate-MOV/result-in-tmp cases were also
  zero in the scanned Tetragon, Tracee, Katran, and BCC artifacts.

Removing the filter would not increase observed apply count. It would also be
unsafe for the current packed rotate kop ABI. The x86 module and bpfopt proof
length logic both reject `tmp_reg == dst_reg` or `tmp_reg == src_reg`; the kop
uses `tmp_reg` as verifier proof scratch. Supporting result-in-tmp would require
a different payload contract or a separate scratch-register allocation, not a
matcher-only deletion.

### 5. Branch, tail-call, and live-out safety checks

These checks are not responsible for the 0 apply result. The matcher found zero
sites before these safety filters could matter.

They remain necessary for any rotate32 or provenance-relaxed matcher:

- interior branch targets must not jump into the replaced window
- tail-call-helper-sensitive kop replacement windows must still be rejected
- `tmp_reg` must not be live after the site unless the new kop/proof contract
  explicitly preserves the original tmp destruction semantics

## Concrete relaxation proposals

### Priority 1: add a proven rotate32 path

This is the only change with evidence-backed upside in the current corpus.

Sketch:

```rust
enum RotateWidth {
    W64,
    W32ZeroExtended,
}

fn try_match_rotate32(insns, pc, analyses_or_states) -> Option<RotateSite> {
    let (left, right, or_insn) = adjacent_shift_shift_or(pc)?;
    require_shift_sum(left, right, 32)?;
    require_or_combines_shift_regs(or_insn, left.dst, right.dst)?;

    let provenance = prove_same_source_value(left.dst, right.dst, pc)?;
    let result = or_insn.dst_reg();
    let tmp = provenance.copy_reg;
    require(result != tmp)?;

    // Either include this pair in the replaced window or prove an equivalent
    // result-zero-extension postcondition.
    let zext = match_following_lsh32_rsh32(insns, pc + 3)?;

    // Needed for native rotate32 equivalence, not just verifier acceptance.
    prove_upper32_zero(provenance.source, pc, analyses_or_states)?;

    Some(RotateSite {
        width: RotateWidth::W32ZeroExtended,
        start_pc: provenance.removable_start_or_shift_pc,
        old_len: computed_window_len_including_zext_if_removed,
        dst_reg: result,
        val_reg: provenance.source,
        tmp_reg: tmp,
        shift_amount: left_shift_amount,
    })
}
```

Implementation notes:

- Prefer a new `bpf_rotate32` kop or an explicit width field in the rotate
  payload. The current `bpf_rotate64` name and contract are too specific.
- The proof sequence must preserve BPF semantics. If the native emitter wants to
  use `rol`/`ror` on a 32-bit register, the optimizer must prove source upper
  bits are zero. Otherwise the kop is not a legitimate replacement for the
  64-bit-shift-plus-mask sequence.
- Fold the trailing `<<= 32; >>= 32` pair only when it is part of the matched
  semantics and no branch target enters it.
- Initial conservative version should match only the immediate-MOV shape and
  explicit trailing zero-extension pair. That targets the 39 Tetragon
  current-like rot32 sites without trying to classify every masked byte-pack
  triplet.

Expected impact from retained artifacts:

- Conservative unique-object opportunity: up to 39 Tetragon sites before
  upper-zero and branch/liveness filters.
- Best available unique-object opportunity if later dataflow proves all raw
  rot32 triplets legitimate: 161 sites across Tetragon, Tracee, and Katran
  artifacts.

### Priority 2: generalize provenance with local use-def/equivalence

This should be second because it has no measured rotate64 upside in the current
artifacts, but it is needed to safely expand rotate32 beyond the immediate-MOV
subset.

Sketch:

```rust
fn prove_same_source_value(a: Reg, b: Reg, shift_pc: usize, cfg: &Cfg) -> Option<Provenance> {
    // Walk backward in the same straight-line block.
    // Stop at calls, memory loads to either candidate, branches, or writes to
    // either candidate that cannot be modeled.
    let def_a = reaching_def(a, shift_pc)?;
    let def_b = reaching_def(b, shift_pc)?;

    match (def_a, def_b) {
        (Mov { dst: a, src: b, pc }, CurrentReg { reg: b }) => Some(copy(a, b, pc)),
        (CurrentReg { reg: a }, Mov { dst: b, src: a, pc }) => Some(copy(b, a, pc)),
        (KnownEquivalent(x), KnownEquivalent(y)) if x == y => Some(...),
        _ => None,
    }
}
```

Rules:

- Stay in one straight-line region unless there is existing CFG-aware dominance
  support.
- Preserve intervening instructions. Do not widen the replacement window over
  arbitrary side effects.
- If the provenance MOV is not removed, keep its cost in mind; the transform is
  still useful only if the native rotate is cheaper enough to offset the extra
  surviving copy.
- Re-run liveness on the actual replacement window.

Expected impact:

- Rotate64: 0 in observed artifacts.
- Rotate32: could unlock some of the 118 non-immediate-MOV raw Tetragon
  triplets, but only a subset is likely legitimate because masked byte-pack
  forms are mixed in.

### Priority 3: support result-in-tmp only with a new kop ABI or scratch allocation

Do not remove `dst_reg != tmp_reg` as a standalone matcher relaxation.

If future bytecode shows real result-in-tmp sites, support them by changing the
representation:

```rust
struct RotateSite {
    dst_reg: Reg,
    val_reg: Reg,
    proof_tmp_reg: Reg,   // separate from dst and val
    original_copy_reg: Reg,
}
```

or by adding a separate payload variant whose proof sequence and native emitter
explicitly handle `dst == original_copy_reg`.

Expected impact now:

- 0 observed additional sites.

## Apply-rate ceiling estimate

For the current rotate64 pass and current matcher family:

- Conservative ceiling: 0 sites applied.
- Best case after relaxing only 64-bit provenance/order/result constraints: 0
  sites applied.

Reason: both the latest live-run summaries and the offline object census show
zero raw adjacent 64-bit rotate triplets in the corpus evidence available here.

For a new legitimate rotate32 optimization:

- Conservative evidence-backed ceiling: up to 39 unique static Tetragon sites,
  before upper-zero, branch-target, tail-call-window, and live-out filters. This
  is the count of rot32 triplets that already have current-like immediate-MOV
  provenance and result-not-tmp shape in available Tetragon objects.
- Best available static-artifact ceiling: 161 unique raw rot32 triplets across
  available supported-app artifacts: 157 Tetragon, 3 Tracee, 1 Katran.

These are static object-artifact counts, not exact live `sites_applied` counts
for the 507-program run. The live run loaded many duplicate Tetragon generic
programs, for example 231 `generic_kprobe_` programs and 36
`generic_retkpro` programs. If the same rot32-bearing code is replicated into
those live programs, run-level `sites_applied` could exceed the unique-object
counts. If only sections without rot32 patterns were loaded, it could be lower.
The retained artifacts do not contain the live `prog.bin` or per-pass input
bytecode needed to prove that mapping.

A single targeted rerun to capture better ground truth would be:

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer \
BPFREJIT_BENCH_PASSES=rotate \
SAMPLES=1 \
KEEP_FAILURE_ARTIFACTS=1 \
make vm-corpus
```

That would preserve current rotate failure workdirs, but it would still not
retain successful no-match programs. For an exact relaxed-matcher ceiling, add a
temporary read-only debug dump of all live program bytecode during the Tetragon
run, or run `bpftool prog dump xlated` with sufficient privileges while the app
is loaded. Without that, the defensible conclusion is: current rotate64 apply
ceiling is 0, and rotate32 is the only observed path to non-zero legitimate
coverage.
