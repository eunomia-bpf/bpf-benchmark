# Micro Kernel-Recompile Mismatch / Crash Diagnosis

## Scope

- Benchmarks:
  - `binary_search`
  - `switch_dispatch`
  - `branch_dense`
  - `bpf_call_chain`
  - `bounds_ladder`
  - `mixed_alu_mem`
- Guest: framework-kernel VM, `vendor/linux-framework/arch/x86/boot/bzImage`
- Primary diagnostic artifacts:
  - direct repro logs under `docs/tmp/micro_diag/*.log`
  - post-fix validation: `docs/tmp/micro_diag/validation_v2.json`, `docs/tmp/micro_diag/validation_v2.md`

## Executive Summary

| Benchmark | Symptom in blind all-apply | Root cause | Final policy |
| --- | --- | --- | --- |
| `binary_search` | `result-mismatch` | single `cmov` site is wrong-code | disable all sites |
| `switch_dispatch` | `result-mismatch` | single `cmov` site is wrong-code | disable all sites |
| `branch_dense` | `result-mismatch` | single `cmov` site is wrong-code; `wide` / `branch-flip` are not needed for recovery | disable all sites |
| `bpf_call_chain` | `result-mismatch` | single `cmov` site is wrong-code; `wide` sites are safe | keep `wide@11,15`, skip `cmov@85` |
| `bounds_ladder` | VM crash | `cmov@144` gives wrong result; `cmov@152` crashes at runtime; `wide@10,23` are safe | keep `wide@10,23`, skip both `cmov` sites |
| `mixed_alu_mem` | VM crash | `extract@228` crashes at runtime; `wide@10` and `extract@73` are safe | keep `wide@10` and `extract@73`, skip `extract@228` |

## Method

1. Reproduced stock and blind `kernel-recompile` in the framework VM with direct `micro_exec run-kernel` commands.
2. Used single-family probes (`--skip-families`) to isolate the failing family.
3. Used single-site v2 policies to isolate the failing site where a family still had multiple candidates.
4. Used `--compile-only` to distinguish:
   - recompile-path crash
   - runtime execution of recompiled native code

Important note:
- I could not get a full guest panic stack from `vng` serial output. Even with higher console verbosity, the VM exited with code `255` right after the last scanner line.
- The attribution below therefore relies on a stronger boundary test:
  - stock run succeeds
  - `compile-only` recompile succeeds and reports `applied=true`
  - runtime with the isolated bad family/site crashes
  - runtime with that family/site skipped succeeds and returns the correct result

## Site Inventory

Offline scanner site ids from `scanner/build/bpf-jit-scanner scan <obj> --program-name <prog> --json`:

| Benchmark | Sites |
| --- | --- |
| `binary_search` | `cmov@152`, `wide@10,23` |
| `switch_dispatch` | `cmov@50`, `wide@10,33` |
| `branch_dense` | `wide@10,23`, `branch-flip@75,90,114,127`, `cmov@152` |
| `bpf_call_chain` | `wide@11,15`, `cmov@85` |
| `bounds_ladder` | `wide@10,23`, `cmov@144,152` |
| `mixed_alu_mem` | `wide@10`, `extract@73,228` |

For these micro programs, offline ids matched the live policy path well enough to use directly:
- the earlier `bpf_call_chain` tuned policy already used `wide@11,15`
- the live repro counts matched the offline scanner counts for all six programs

## Result-Mismatch Diagnosis

### `binary_search`

- Stock result: `126`
- Blind all-apply result: `39`
- `cmov-only` result: `39`
- `wide-only` result: `126`
- Conclusion: the only `cmov` site, `cmov@152`, is the wrong-code source.
- Fix: keep `micro/policies/binary_search.yaml` as fail-close `sites: []`.

### `switch_dispatch`

- Stock result: `16`
- Blind all-apply result: `3`
- `cmov-only` result: `3`
- `wide-only` result: `16`
- Conclusion: the only `cmov` site, `cmov@50`, is the wrong-code source.
- Fix: keep `micro/policies/switch_dispatch.yaml` as fail-close `sites: []`.

### `branch_dense`

- Stock result: `15654347328787340782`
- Blind all-apply result: `17256919660339658752`
- `cmov-only` result: `17256919660339658752`
- `wide-only` result: `15654347328787340782`
- `branch-flip-only` was already valid in the earlier family sweep; the invalid path tracks `cmov`.
- Conclusion: the only `cmov` site, `cmov@152`, is the wrong-code source.
- Fix: keep `micro/policies/branch_dense.yaml` as fail-close `sites: []`.

### `bpf_call_chain`

- Stock result: `17813494880153753973`
- Blind all-apply result: `13335792585254919774`
- `cmov-only` result: `13335792585254919774`
- `wide-only` result: `17813494880153753973`
- Conclusion: the only `cmov` site, `cmov@85`, is the wrong-code source; `wide@11,15` are safe.
- Fix: keep `micro/policies/bpf_call_chain.yaml` as `wide@11,15` only.

## VM-Crash Diagnosis

### `bounds_ladder`

Family-level evidence:

- Stock run: OK, result `8686050057216939920`
- Blind all-apply runtime: VM exit `255`
- Blind all-apply `--compile-only`: OK, `applied=true`, `total_sites=4`
- `cmov-only` runtime: VM exit `255`
- `cmov-only` `--compile-only`: OK, `applied=true`, `total_sites=2`
- `wide-only` runtime: OK, result `8686050057216939920`
- Blind all-apply with `cmov` skipped: OK, result `8686050057216939920`

Site-level evidence:

- `cmov@144` alone: no crash, but wrong result `14514966260423319319`
- `cmov@152` alone: VM exit `255`

Conclusion:

- This is not a harness/input problem.
- Recompile itself succeeds; the guest dies only when executing recompiled CMOV code.
- `bounds_ladder` has two bad CMOV sites:
  - `cmov@144`: wrong-code
  - `cmov@152`: runtime crash
- `wide@10,23` are safe.

Fix:

- Added [`micro/policies/bounds_ladder.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/bounds_ladder.yaml) with:
  - `default: skip`
  - `apply wide@10`
  - `apply wide@23`

Interpretation:

- This is strong evidence of a `cmov` emitter / validator correctness bug on this program shape.
- I did not patch the kernel emitter in this change because the bug is localized behaviorally but not yet source-level rooted.

### `mixed_alu_mem`

Family-level evidence:

- Stock run: OK, result `5008154085265630854`
- Blind all-apply runtime: VM exit `255`
- Blind all-apply `--compile-only`: OK, `applied=true`, `total_sites=3`
- `extract-only` runtime: VM exit `255`
- `extract-only` `--compile-only`: OK, `applied=true`, `total_sites=2`
- `wide-only` runtime: OK, result `5008154085265630854`
- Blind all-apply with `extract` skipped: OK, result `5008154085265630854`

Site-level evidence:

- `extract@73` alone: OK, result `5008154085265630854`
- `extract@228` alone: VM exit `255`
- `wide@10 + extract@73`: OK, result `5008154085265630854`

Conclusion:

- This is not a harness/input problem.
- Recompile itself succeeds; the guest dies only when executing recompiled extract code.
- The crashing site is `extract@228`.
- Safe retained sites are:
  - `wide@10`
  - `extract@73`

Fix:

- Added [`micro/policies/mixed_alu_mem.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/mixed_alu_mem.yaml) with:
  - `default: skip`
  - `apply wide@10`
  - `apply extract@73`

Interpretation:

- This is strong evidence of a `bitfield_extract` emitter / validator correctness bug on this specific program shape.
- As with `bounds_ladder`, I did not patch the kernel emitter here because the behavioral isolation is clear but the exact kernel-side bug location still needs a separate source-level debug session.

## Files Changed

- Added [`micro/policies/bounds_ladder.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/bounds_ladder.yaml)
- Added [`micro/policies/mixed_alu_mem.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/mixed_alu_mem.yaml)
- Updated [`config/micro_pure_jit.yaml`](/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml) to wire both policies into `kernel-recompile`

Existing tuned policies left in place:

- [`micro/policies/binary_search.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/binary_search.yaml)
- [`micro/policies/switch_dispatch.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/switch_dispatch.yaml)
- [`micro/policies/branch_dense.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/branch_dense.yaml)
- [`micro/policies/bpf_call_chain.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/bpf_call_chain.yaml)

## Post-Fix Validation

Authoritative validation run:

```bash
python3 docs/tmp/kernel_recompile_micro_resume.py \
  --bench binary_search \
  --bench switch_dispatch \
  --bench branch_dense \
  --bench bpf_call_chain \
  --bench bounds_ladder \
  --bench mixed_alu_mem \
  --iterations 1 \
  --warmups 0 \
  --repeat 1 \
  --cpu 0 \
  --memory 4G \
  --cpus 2 \
  --timeout 180 \
  --output-json docs/tmp/micro_diag/validation_v2.json \
  --output-md docs/tmp/micro_diag/validation_v2.md \
  --per-bench-dir docs/tmp/micro_diag/per_bench_v2
```

Result summary from `docs/tmp/micro_diag/validation_v2.json`:

| Benchmark | Kernel result | Kernel-recompile result | Applied | Sites | Status |
| --- | --- | --- | ---: | ---: | --- |
| `binary_search` | `126` | `126` | no | `0` | ok |
| `switch_dispatch` | `16` | `16` | no | `0` | ok |
| `branch_dense` | `15654347328787340782` | `15654347328787340782` | no | `0` | ok |
| `bpf_call_chain` | `17813494880153753973` | `17813494880153753973` | yes | `2` | ok |
| `bounds_ladder` | `8686050057216939920` | `8686050057216939920` | yes | `2` | ok |
| `mixed_alu_mem` | `5008154085265630854` | `5008154085265630854` | yes | `2` | ok |

Bottom line:

- `6 / 6` are now valid.
- All six `kernel-recompile` runs return the same result as stock.
- The two former VM-crash rows now execute successfully with site-positive policies.
