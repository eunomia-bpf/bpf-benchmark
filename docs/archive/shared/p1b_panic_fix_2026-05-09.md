# P1-B Tetragon Panic Regression Fix - 2026-05-09

## Root Cause

The P1-B redo changed kop runtime identity from the old `(btf_id, call_offset)` pair to `btf_id` alone.

The deleted `passes/utils.rs` code did not only centralize proof decoders. Its proof-sidecar path also matched a kop call with both:

- the BTF func id stored in the `BPF_PSEUDO_KFUNC_CALL` instruction immediate
- the module fd-array call offset stored in the same instruction's `off`

After the redo, `collect_kop_proof_regions()` called `kop_proof_len(registry, btf_id, payload)`, and `KopRegistry` indexed descriptors by `by_btf_id`. That made every kop BTF func id globally unique.

That assumption is wrong. The daemon loads multiple kop modules, and their BTF func ids are module-local. The corpus artifacts show real collisions:

```text
error: kop btf_id 128703 is already registered for bpf_endian_load16
```

This appeared repeatedly in `bcc`, `otel`, and `cilium` app results while running `bpfopt --pass rotate`. Tetragon then crashed after those apps in the full corpus sequence, while a standalone tetragon run passed, matching a prior-app state leak pattern.

The emit path itself was not byte-different. The bytecode comparison below shows the same optimized bytes as both the old centralized implementation and the P1-B redo stash. The regression was in kop target resolution and proof metadata remapping around those bytes: a sidecar proof can only be decoded correctly when the call's `off` participates in the lookup key.

Other checks:

- `KopRegistry::new()` still discovers all 11 v3 targets from `PASS_REGISTRY`: `rotate64`, `rotate32`, `select64`, `ccmp64`, `extract64`, `endian_load16`, `endian_load32`, `endian_load64`, `bulk_memcpy`, `bulk_memset`, `prefetch`.
- CLI alias canonicalization covered the existing aliases, and is now explicitly regression-tested for all v3 aliases including `bulk_memcpy`, `memcpy_bulk`, and `bpf_memcpy_bulk`.
- `map_inline`, `const_prop`, `dce`, and `bounds_check_merge` did not depend on the deleted proof decoder helpers.

## Fix

Changed `KopRegistry` to index runtime calls by `(btf_id, call_off)` instead of only `btf_id`.

Files changed:

- `bpfopt/crates/bpfopt/src/pass.rs`
  - replaced `by_btf_id` with `by_call: HashMap<KopCallKey, ...>`
  - added `lookup_by_kop_call(btf_id, call_off)`
  - kept fail-fast duplicate detection for the exact same `(btf_id, call_off)` owned by different targets
  - synchronized the index from both `set_btf_id_for_target_name()` and `set_call_off_for_target_name()`
- `bpfopt/crates/bpfopt/src/passes/utils.rs`
  - restored call-offset-aware proof dispatch by reading `insns[pc + 1].off`
  - added a regression test showing two descriptors can share a BTF func id and still decode the correct proof through different call offsets
- `bpfopt/crates/bpfopt/src/main.rs`
  - added regression tests for all v3 kop aliases
  - added target JSON tests proving duplicate module-local BTF ids are allowed when call offsets differ and rejected when the full call key collides

This keeps the pass-owned descriptor design from P1-B redo. It does not reintroduce centralized proof-layout dispatch.

## Byte-Identical Verification

I compared the same direct host bytecode input through the old centralized implementation (`HEAD~5`) and the fixed tree.

Input program bytes:

```text
bf 12 00 00 00 00 00 00 77 02 00 00 08 00 00 00
67 01 00 00 38 00 00 00 4f 21 00 00 00 00 00 00
95 00 00 00 00 00 00 00
```

Target JSON:

```json
{"arch":"x86_64","features":["rorx"],"koperation":{"bpf_rotate64":{"btf_func_id":101,"btf_id":1001,"call_offset":7},"bpf_rotate32":{"btf_func_id":102,"btf_id":1001,"call_offset":7}}}
```

Command shape:

```sh
bpfopt --pass rotate --input input.bin --output output.bin --target target.json
```

Results:

```text
HEAD~5 output sha256:   3b53765beeba7b457b12f4439f394921f0f578e744c55fc99c7fdd9b126ec6a7
fixed output sha256:    3b53765beeba7b457b12f4439f394921f0f578e744c55fc99c7fdd9b126ec6a7
output size:            24 bytes in both trees
cmp result:             identical
```

I also compared the P1-B redo pre-fix stash against the fixed tree for the same case. It produced the same 24-byte output and same SHA-256. The fix does not change the pass emit bytes.

## Tests

Commands run:

```sh
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo test --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked
```

Results:

```text
bpfopt cargo build: pass
bpfopt cargo test:  pass
  lib tests:        332 passed
  main tests:       15 passed
  cli tests:        12 passed
daemon cargo build: pass
daemon cargo test:  25 passed
```

The current observed total is 384 Rust tests because this fix adds three bpfopt regression tests. All observed tests pass.

I did not run `make corpus`; per task constraints, the KVM corpus rerun is left to Claude.
