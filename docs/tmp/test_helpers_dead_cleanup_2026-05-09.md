# test_helpers dead cleanup 2026-05-09

## Scope

- Edited only `bpfopt/crates/bpfopt/src/**` plus this report.
- Did not commit.
- Did not benchmark.
- Did not edit `runner/`, `corpus/`, `e2e/`, `micro/`, `vendor/linux-framework/`, or fork-only daemon syscall code.
- `bpfopt/crates/bpfopt/src/passes/rewrite.rs` was changed only for the requested 0-caller APIs/fields and the small panic-to-`anyhow` conversion.

## test_helpers wrapper deletion

Deleted from `bpfopt/crates/bpfopt/src/test_helpers.rs` and inlined call sites to direct `BpfInsn::new(...)`:

| Function | Before LOC | After LOC | Replacement |
|---|---:|---:|---|
| `add64_imm` | 3 | 0 | `BPF_ALU64 | BPF_ADD | BPF_K` |
| `jeq_imm` | 3 | 0 | `BPF_JMP | BPF_JEQ | BPF_K` |
| `jne_imm` | 3 | 0 | `BPF_JMP | BPF_JNE | BPF_K` |
| `jgt_reg` | 3 | 0 | `BPF_JMP | BPF_JGT | BPF_X` |

`rg -n '\b(add64_imm|jeq_imm|jne_imm|jgt_reg)\b' bpfopt/crates/bpfopt/src daemon/src` returns no matches.

## rewrite.rs dead deletion

Removed 0-caller speculative insertion/internal-branch support:

| Item | Before LOC | After LOC |
|---|---:|---:|
| `RewritePlan::insert_before` | 3 | 0 |
| `RewritePlan::add_internal_branch` | 9 | 0 |
| `RewritePlan.insertions` field | 1 | 0 |
| `RewritePlan.internal_branch_patches` field | 1 | 0 |
| `BranchPatch` alias | 1 | 0 |
| insertion commit/validation support | removed | 0 |
| `patch_internal_branches` support function | removed | 0 |

`rg -n 'insert_before|add_internal_branch|insertions|internal_branch_patches|BranchPatch|patch_internal_branches' bpfopt/crates/bpfopt/src/passes/rewrite.rs` returns no matches.

## BPF_REG_7/8

- Deleted `BPF_REG_7`.
- Deleted `BPF_REG_8`.
- Verified with `rg -n '\bBPF_REG_7\b|\bBPF_REG_8\b' bpfopt/crates/bpfopt/src daemon/src`: no matches.

## panic to anyhow

Done.

- `RewritePlan::replace_range` now returns `anyhow::Result<()>`.
- `RewritePlan::delete_range` now returns `anyhow::Result<()>`.
- Duplicate replacement/deletion and deletion overflow now return `anyhow` errors instead of `assert!` / `expect`.
- Updated all current call sites to use `?`: `bounds_check_merge`, `const_prop`, `skb_load_bytes`, `wide_mem`.
- `rg -n 'assert!|expect\(' bpfopt/crates/bpfopt/src/passes/rewrite.rs` returns no matches.

## wrapper / alias grep

Requested one-line `BpfInsn::new` wrapper grep:

```text
rg -n 'fn (\w+)\([^)]*\)\s*->\s*BpfInsn\s*\{[^}]*BpfInsn::new\([^)]+\)[^}]*\}' bpfopt/crates/bpfopt/src
```

Result: no matches.

Requested libbpf const alias grep:

```text
rg -n 'pub const \w+: \w+ = libbpf_sys::' bpfopt/crates/bpfopt/src daemon/src
```

Result: remaining matches are existing typed `u8 = libbpf_sys::* as u8` ABI aliases in `bpfopt/crates/bpfopt/src/insn.rs`; no daemon matches, no `BPF_REG_7/8`, and no same-type `u32 = libbpf_sys::*` production aliases in this scope.

## LOC delta

Local pre/post line counts for the files directly reduced in this task:

| File | Before | After | Delta |
|---|---:|---:|---:|
| `bpfopt/crates/bpfopt/src/test_helpers.rs` | 148 | 136 | -12 |
| `bpfopt/crates/bpfopt/src/passes/rewrite.rs` | 263 | 182 | -81 |
| `bpfopt/crates/bpfopt/src/insn.rs` | 365 | 363 | -2 |

Scoped shortstat requested by prompt:

```text
git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src
 36 files changed, 2134 insertions(+), 2415 deletions(-)
```

Net LOC: `-281`, further below the stated baseline `-184`.

## Verification

Commands run:

```text
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo test --workspace --locked 2>&1 | tail -40
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked 2>&1 | tail -20
```

Results:

- bpfopt build: pass.
- bpfopt tests: pass.
- daemon build: pass.
- daemon tests: pass, `25 passed`.
- Test listing count: bpfopt `356` + daemon `25` = `381`.

## CLAUDE.md compliance self-check

- No benchmark entrypoint was run.
- No framework-side metric aggregation, ratio, geomean, summary, or result payload logic was added.
- No ReJIT filtering or app loader behavior changed.
- No daemon syscall boundary or fork-only syscall code changed.
- No fallback or silenced-error pattern was added; `replace_range` / `delete_range` now fail through `anyhow::Result`.
- No new unit tests were added.
- `rg -n '#\[allow\(dead_code\)\]|unwrap_or_default|let _ = |\.ok\(\)' bpfopt/crates/bpfopt/src daemon/src` returns no matches.
- `git diff -U0 HEAD -- bpfopt/crates/bpfopt/src daemon/src | rg '^\+.*(#\[allow\(dead_code\)\]|unwrap_or_default|let _ = |\.ok\(\))'` returns no matches.
