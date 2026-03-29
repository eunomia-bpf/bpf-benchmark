# Unapplied Comparable Programs Analysis (2026-03-29)

## Scope

Target run: `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`

`summary` says:

- `comparable_pairs = 415`
- `applied_comparable_pairs = 212`
- therefore `203` comparable programs had `applied_passes == []`

Here "0 applied passes" means:

- baseline and REJIT both produced a runtime measurement (`speedup_ratio != null`)
- but none of the 11 enabled REJIT passes changed the program

The 11-pass pipeline visible in preserved raw results is:

`map_inline`, `const_prop`, `dce`, `skb_load_bytes_spec`, `bounds_check_merge`, `wide_mem`, `bulk_memory`, `rotate`, `cond_select`, `extract`, `endian_fusion`.

## Important Data Gap

`metadata.json` references this raw batch result:

- `docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-wzjd5pr6.json`

That file is no longer present in the tree. The matching target JSON
`corpus-rejit-vm-batch-s7ih7dzs.json` is also missing.

What is preserved:

- `docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-rlg7cu6g.json`
- smaller earlier/repro slices under `docs/tmp/20260329/corpus-rejit-batch/` and `docs/tmp/20260328/corpus-rejit-batch/`

I compared `rlg7cu6g` against `metadata.summary.by_object`:

- it matches the first `244` objects of the target run almost exactly
- `243/244` objects match `comparable_pairs` and `applied_comparable_pairs` exactly
- the only mismatch is `bcc:libbpf-tools/biostacks.bpf.o` (`raw 0/0` vs `summary 1/1`), so the `0-pass comparable` count is unchanged
- the raw slice therefore gives an exact reconstruction of the first `98/203` zero-pass comparable programs

For the remaining `105` zero-pass comparable programs:

- `52` are recoverable exactly from `summary.by_object` plus the batch input JSON, because their objects satisfy:
  - `programs == comparable_pairs`
  - `applied_comparable_pairs == 0`
- the last `53` programs are not recoverable exactly without `wzjd5pr6.json`

So the evidence tiers are:

- exact raw-backed: `98`
- exact object-resolved tail: `52`
- unresolved due to missing raw: `53`

## Repo And Program-Type Distribution

### Exact recovered/resolved subset: 150 / 203

This subset is exact for membership, but only the first 98 have full pass-level diagnostics.

Repo distribution:

- `linux-selftests`: `89`
- `bcc`: `21`
- `xdp-tutorial`: `14`
- `coroot-node-agent`: `11`
- `calico`: `5`
- `katran`: `3`
- `real_world_code_size`: `2`
- `xdp-tools`: `2`
- `libbpf-bootstrap`: `1`
- `suricata`: `1`
- `tetragon`: `1`

Program-type distribution:

- `tracing`: `29`
- `xdp`: `24`
- `tracepoint`: `23`
- `sched_cls`: `23`
- `kprobe`: `17`
- `raw_tracepoint`: `15`
- `lsm`: `13`
- `cgroup_skb`: `4`
- `cgroup_sock_addr`: `2`

Takeaway: the zero-pass comparable set is not dominated by one exotic type. It is mostly small tracing/XDP/TC/selftest programs, heavily concentrated in `linux-selftests`.

## Instruction Count Distribution

### Exact raw-backed subset: 98 / 203

For these 98 programs, I used daemon `pass_details[*].insns_before`, which is the strongest source available in preserved raw data.

- min: `2`
- median: `22`
- p90: `98.7`
- max: `359`

Bucketed:

- `<=16`: `33`
- `17-32`: `26`
- `33-64`: `18`
- `65-128`: `9`
- `129-256`: `4`
- `>256`: `2`

This subset is clearly small:

- `59/98 = 60.2%` are `<=32` insns
- `77/98 = 78.6%` are `<=64` insns

So for the preserved exact subset, "too small / too simple" is a real effect, not a guess.

### Tail note for the 52 exact object-resolved programs

Using `runner/build/micro_exec list-programs` for those objects also shows a mostly small tail, but with one giant outlier:

- `linux-selftests:tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress` at `14750` insns

Everything else in that exact tail stays in the same "mostly small, plus a few medium/large selftests/XDP programs" shape.

## Map Lookup / map_inline

### Exact raw-backed subset: 98 / 203

I cannot claim exact `bpf_map_lookup_elem` presence for all 203 because the target raw file is missing.
What I can say exactly for the preserved 98 is whether `map_inline` saw any candidate or skip-worthy lookup pattern.

Results:

- `26/98` had any `map_inline` site activity (`sites_found > 0` or `sites_skipped > 0`)
- `72/98` had `0` `map_inline` sites

So in the preserved exact subset, most zero-pass comparable programs do **not** even look like `map_inline` candidates.

When `map_inline` did see a lookup-like pattern but still changed nothing, the dominant blockers were:

- `lookup result is not consumed by fixed-offset scalar loads` (`33`)
- `lookup key is not a constant stack or pseudo-map-value materialization` (`25`)
- `mutable lookup result has non-load uses` (`4`)
- unsupported map kinds in v1:
  - `map type 5 not inlineable in v1` (`4`)
  - `map type 10/12/13 not inlineable in v1` (`1` each)

Interpretation:

- many zero-pass programs simply have no map-inlineable lookup at all
- when a lookup exists, the current matcher is strict about:
  - constant-key shape
  - fixed-offset scalar-only consumption
  - supported map type

## Conditional Branches / const_prop

### Exact raw-backed subset: 98 / 203

For the preserved 98:

- `const_prop` candidate count is `0/98`
- i.e. there is **no** program where the preserved daemon diagnostics report a `const_prop` site

So the answer is not "there are lots of obvious const-prop-able branches and we somehow missed them."
At least in the preserved exact subset, that is **not** what the data says.

There are still some branch-shaped patterns, but they show up under `cond_select`, not `const_prop`:

- `9/98` had `cond_select` skip activity

Top `cond_select` blockers:

- non-zero-test JCC forms such as:
  - `op=0x20 imm=15`
  - `op=0x20 imm=255`
  - `op=0x20 imm=65535`
  - `op=0x20 imm=3`
- `packed ABI requires register true/false operands`

Interpretation:

- some branches exist
- but they are mostly **not** in the narrow form that `const_prop` or `cond_select` currently wants

## Why Did All 11 Passes Miss?

### Exact raw-backed subset: 98 / 203

The cleanest split is:

- `68/98` programs have **zero sites in all 11 passes**
- `30/98` programs have some site activity, but every pass still ends in `changed = false`

This means the dominant reason is:

1. program too simple, or outside the current pass families

The secondary reason is:

2. matcher / eligibility limitations, mainly `map_inline`, then `cond_select`, then `rotate`

Per-pass blocker frequency among the 30 "pattern exists but nothing changed" programs:

- `map_inline`: `26`
- `cond_select`: `9`
- `rotate`: `5`

`rotate` failures are all:

- `subprog pseudo-calls not yet supported`

So for the preserved exact subset, the right answer is:

- mostly **program too simple / not in scope of these passes**
- secondarily **pattern matcher / legality limitations**
- **not** "const_prop missed a lot of obvious branches"

## What We Can Still Say About The Missing 53

The unresolved tail is small enough to list, and it is concentrated:

- `48/53` are from `linux-selftests`
- `3/53` are from `xdp-tutorial`
- `2/53` are from `systemd`

Objects that still need `wzjd5pr6.json` for exact program-level reconstruction:

| Object | Programs | Comparable | Applied Comparable | Zero-Pass Comparable |
| --- | --- | --- | --- | --- |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | 19 | 19 | 6 | 13 |
| `linux-selftests:tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o` | 16 | 4 | 0 | 4 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o` | 14 | 3 | 0 | 3 |
| `linux-selftests:tools/testing/selftests/bpf/progs/verifier_const.bpf.o` | 8 | 4 | 0 | 4 |
| `systemd:userns-restrict.bpf.o` | 7 | 2 | 0 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o` | 6 | 4 | 0 | 4 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o` | 5 | 3 | 1 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o` | 5 | 2 | 0 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o` | 5 | 5 | 1 | 4 |
| `xdp-tutorial:packet03-redirecting/xdp_prog_kern.bpf.o` | 5 | 5 | 2 | 3 |
| `linux-selftests:tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o` | 30 | 1 | 0 | 1 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_autoload.bpf.o` | 3 | 2 | 0 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o` | 3 | 2 | 0 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_d_path.bpf.o` | 3 | 2 | 0 | 2 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o` | 3 | 1 | 0 | 1 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o` | 3 | 1 | 0 | 1 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_migrate_reuseport.bpf.o` | 2 | 1 | 0 | 1 |
| `linux-selftests:tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o` | 2 | 1 | 0 | 1 |
| `linux-selftests:tools/testing/selftests/bpf/progs/timer_start_deadlock.bpf.o` | 2 | 1 | 0 | 1 |

These are mostly multi-program selftest objects where the object summary tells us how many comparable programs exist, but not which program IDs they are.

## Bottom Line

Even with the missing target raw result, the evidence is already strong:

- the `203` zero-pass comparable programs are dominated by `linux-selftests`, plus a smaller BCC/XDP/tutorial tail
- the preserved exact subset is mostly **small** programs
- most preserved zero-pass comparable programs do **not** expose any pass sites at all
- when a site exists, the dominant miss is `map_inline` shape/legality, not `const_prop`
- preserved data shows **zero** `const_prop` candidates in `98/98` exact raw-backed zero-pass comparable programs

So the current best explanation is:

- primary cause: **program too simple or outside the current 11-pass matcher families**
- secondary cause: **pattern matcher / legality limitations**, mainly `map_inline`, then `cond_select`, then `rotate`

To turn this from "strong partial reconstruction" into a full exact `203/203` program-level analysis, the missing file
`docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-wzjd5pr6.json`
needs to be restored.
