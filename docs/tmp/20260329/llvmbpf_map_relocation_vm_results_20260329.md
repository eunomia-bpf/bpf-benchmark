# llvmbpf Map Relocation VM Results (2026-03-29)

## Summary

I validated the Round 2 guest-side map relocation repair in the VM through `make vm-shell` / `vng`.

The helper rebuilt successfully with:

```bash
cargo build --release --manifest-path docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/Cargo.toml
```

Round 2 exceeded the `>20%` verifier target.

- Round 1 verifier pass: `16/413` (`3.9%`)
- Round 2 verifier pass: `157/413` (`38.0%`)
- Net gain: `+141` newly passing round-trip programs

Host-side lift/lower counts were unchanged from Round 1, so the verifier gain comes from the new guest-side map repair path rather than host pipeline drift.

## Validation Commands

Smoke subset:

```bash
python3 docs/tmp/20260329/llvmbpf_bulk_roundtrip/llvmbpf_bulk_roundtrip.py run-vm-verify \
  --manifest docs/tmp/20260329/llvmbpf_bulk_roundtrip/map_repair_smoke_manifest_20260329.json \
  --guest-results docs/tmp/20260329/llvmbpf_bulk_roundtrip/map_repair_smoke_guest_results_20260329.json
```

Full sweep:

```bash
python3 docs/tmp/20260329/llvmbpf_bulk_roundtrip/llvmbpf_bulk_roundtrip.py run-vm-verify \
  --manifest docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_fix_manifest.json \
  --guest-results docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_map_repair_guest_results_20260329.json
```

## Smoke Subset

I used five previously map-related failures:

- `corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o`
- `corpus/build/bcc/libbpf-tools/biosnoop.bpf.o`
- `corpus/build/bcc/libbpf-tools/filelife.bpf.o`
- `corpus/build/bcc/libbpf-tools/syscount.bpf.o`
- `corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o`

Subset result:

- Round 1 subset verifier pass: `0/14`
- Round 2 subset verifier pass: `5/14`

New passes all had non-zero `map_repair` counters:

- `filelife.bpf.o / security_inode_`: `matched_helper_map_sites=1`, `inserted_ldimm64_pairs=1`
- `filelife.bpf.o / vfs_create`: `1`, `1`
- `filelife.bpf.o / vfs_open`: `1`, `1`
- `filelife.bpf.o / vfs_unlink`: `2`, `2`
- `bootstrap.bpf.o / handle_exit`: `2`, `2`

Representative non-pass cases:

- `syscount.bpf.o / sys_enter`: `matched=0`, still `R1 type=scalar expected=map_ptr`
- `syscount.bpf.o / sys_exit`: `matched=0`, still `R1 type=scalar expected=map_ptr`
- `bindsnoop.bpf.o / ipv4_bind_entry`: `matched=0`, still `R1 type=scalar expected=map_ptr`
- `filelife.bpf.o / vfs_unlink_ret`: `matched=3`, but a later helper site still fails with `R1 type=scalar expected=map_ptr`
- `bootstrap.bpf.o / handle_exec`: `matched=1`, but still fails with `R2 !read_ok`, so that one is not a map relocation issue

This was enough evidence to proceed to the full sweep.

## Full-Corpus Results

| Metric | Round 1 | Round 2 |
| --- | ---: | ---: |
| Objects selected | 170 | 170 |
| Programs discovered | 962 | 962 |
| Lift success | 779 / 962 (81.0%) | 779 / 962 (81.0%) |
| LLVM lower success | 413 / 779 (53.0%) | 413 / 779 (53.0%) |
| Verifier pass | 16 / 413 (3.9%) | 157 / 413 (38.0%) |
| End-to-end coverage | 16 / 962 (1.7%) | 157 / 962 (16.3%) |

Round 2 repair attribution:

- Programs with non-zero `matched_helper_map_sites`: `178/413`
- Programs passing with non-zero repair: `142/157`
- Programs still failing despite non-zero repair: `36`
- Newly passing programs versus Round 1: `141`
- Newly passing programs with zero repair matches: `0`
- Total `original_helper_map_sites`: `498`
- Total `matched_helper_map_sites`: `255`
- Total `inserted_ldimm64_pairs`: `255`

Interpretation:

- The large verifier jump is tightly coupled to the new repair path.
- Every newly passing program had a non-zero helper-map repair match.
- There was no comparable host-side lift/lower change in this round.

## Remaining Failures

There are `256` non-passing verifier attempts left. Top buckets:

- `program not pinned by bpftool prog loadall`: `166`
- `BPF_PROG_LOAD: Invalid argument` before real verifier body (`processed 0 insns`): `51`
- invalid ctx/register setup (`R? !read_ok`): `14`
- missing helper map pointer (`R1 type=scalar expected=map_ptr`): `10`
- invalid memory access: `10`
- small tail: `5`

What this means:

- The dominant blockers are now original-object materialization and other verifier issues, not the helper-map relocation path.
- Direct map-value load did not show up as the dominant remaining visible bucket in this run.
- Only `10` failures still clearly show the old helper-map symptom `R1 type=scalar expected=map_ptr`.

Those `10` residual helper-map failures are:

- `bindsnoop.bpf.o / ipv4_bind_entry` (`matched=0`)
- `bindsnoop.bpf.o / ipv6_bind_entry` (`matched=0`)
- `biosnoop.bpf.o / blk_account_io_` (`matched=0`)
- `execsnoop.bpf.o / tracepoint__sys` (`matched=0`)
- `filelife.bpf.o / vfs_unlink_ret` (`matched=3`)
- `hardirqs.bpf.o / irq_handler_ent` (`matched=0`)
- `runqlat.bpf.o / handle_sched_wa` (`matched=0`) x2
- `syscount.bpf.o / sys_enter` (`matched=0`)
- `syscount.bpf.o / sys_exit` (`matched=0`)

So the remaining map-related failures are mostly:

1. helper sites that the current matcher never matched at all (`matched=0`)
2. one partial-match case where earlier helper sites were repaired but a later one was still missed (`filelife / vfs_unlink_ret`)

I did not see evidence that a broad direct-map-value-load repair is the current dominant next step.

## Upside Estimate

Because the run already reached `157/413` (`38.0%`), additional map-only work now appears to have limited upside compared with the remaining infrastructure buckets.

If every residual `R1 type=scalar expected=map_ptr` case were fixed, the verifier pass rate would rise only to:

- `167/413` (`40.4%`)

So the next largest wins are more likely to come from:

- improving `bpftool prog loadall` pin coverage for the original objects
- understanding the `EINVAL / processed 0 insns` bucket
- cleaning up non-map verifier issues such as `R? !read_ok`

## Artifacts

- Full manifest: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_fix_manifest.json`
- Smoke manifest: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/map_repair_smoke_manifest_20260329.json`
- Smoke guest results: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/map_repair_smoke_guest_results_20260329.json`
- Full guest results: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_map_repair_guest_results_20260329.json`
- VM stdout log: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/vm_verify.stdout.log`
- VM stderr log: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/vm_verify.stderr.log`

## Conclusion

Round 2 map relocation repair is VM-validated and effective.

It turns the llvmbpf round-trip verifier result from `16/413` (`3.9%`) to `157/413` (`38.0%`) without changing host lift/lower coverage, and the newly passing set is fully explained by non-zero helper-map repair matches.

The repair should be considered successful for the OSDI evaluation target. Further map work may still recover a small tail of helper-map misses, but it is no longer the main blocker for this benchmark slice.
