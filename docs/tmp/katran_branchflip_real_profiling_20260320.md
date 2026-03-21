# Katran branch-flip real profiling report (2026-03-20)

## Decision

Do **not** add any branch-flip sites to Katran today.

The responsible policy for March 20, 2026 is:

- keep the existing safe base policy only: `docs/tmp/katran_branchflip_policies/katran_branchflip_safe6.policy.yaml`
- branch-flip additions: `[]`

This is intentionally a negative result. I did not repeat the previous mistake of testing arbitrary branch groups without first identifying hot or mispredicted branches from runtime evidence.

## What was actually profiled

### Phase 1: live VM profiling attempt

I brought up a real Katran VM topology and used a stable serial HTTP traffic path instead of the current flaky benchmark wrapper. The live probe artifact is:

- `docs/tmp/katran_branchflip_perf_probe_20260320.json`

Observed facts from that artifact:

- Katran warmup requests succeeded: `20 / 20`
- serial live requests during the probe succeeded: `6 / 6`
- live XDP program was active:
  - `prog_id = 7`
  - `run_cnt_delta = 156`
  - `run_time_ns_delta = 82478`

So the program was definitely executing under real traffic in the guest.

### Method A: perf branch profiling

The preferred method was attempted through the live program-level perf path in `runner/libs/profiler.py`, using:

```bash
/bin/perf stat -x, --no-big-num --bpf-prog 7 -e branches,branch-misses -- sleep 5.0
```

This failed immediately with return code `2`. The guest only has a mismatched generic `/bin/perf`, which reports:

```text
WARNING: perf not found for kernel 7.0.0-rc2
```

and asks for kernel-matched `linux-tools-7.0.0-rc2-gc3aad315df09-dirty`.

Result: no `branches`, no `branch-misses`, no branch-miss rate, and no instruction-level annotate data were collected. The blocker is tooling, not traffic generation.

### Method B: synthetic BPF_PROG_TEST_RUN microbench

I investigated the test-run fallback, but I did **not** use it to choose policy:

- custom `bpf_prog_test_run_opts()` calls worked on the loaded Katran program
- the crafted packets I tried only exercised `XDP_PASS`
- they did not reproduce the real Katran load-balancing/encapsulation path

Because that replay was not faithful to the live datapath, using its timing deltas to rank branch sites would have been another form of blind testing.

## Phase 2: candidate identification

With Method A blocked and Method B not trustworthy, I used Method C as the only defensible fallback:

- artifact: `docs/tmp/katran_branchflip_structural_analysis_20260320.json`
- input sources:
  - `docs/tmp/katran_storepair_stock_xlated_20260320.txt`
  - `docs/tmp/katran_wide_load_vm_20260320/scanner.enumerate.stdout.json`

The structural analysis built a CFG from the xlated instructions, computed immediate postdominators for each branch-flip site, and counted the instruction nodes reachable from:

- the fallthrough successor before reconvergence
- the taken successor before reconvergence

This gives a much better answer than the previous "group and try it" approach for the specific fallback question: is the larger body already on fallthrough?

### Structural result

- total branch-flip sites: `56`
- sites with `fallthrough_body_nodes < taken_body_nodes`: `0`
- sites with `fallthrough_body_nodes > taken_body_nodes`: `56`

Pattern summary:

- `32` sites: `if r0 >= 0x400 goto pc+5`, fallthrough body `5`, taken body `1`
- `6` sites: `if r0 >= 0x1000 goto pc+3`, fallthrough body `3`, taken body `1`
- `4` sites: `if r0 >= 0x1000 goto pc+5`, fallthrough body `5`, taken body `1`
- `4` sites: `if r0 >= 0x200 goto pc+5`, fallthrough body `5`, taken body `1`
- remaining `10` sites are the same shape class: fallthrough body `3` or `5`, taken body `1`

Interpretation:

- every discovered branch-flip site is a small taken-side guard
- the larger body is already on fallthrough
- Method C therefore nominates **no** site as a plausible branch-flip candidate

## Phase 3: candidate validation

No `safe6 + branch-flip-candidates` policy was generated, because there were no candidates supported by real profiling or by the structural fallback.

I therefore did **not** run the requested `safe6-only` vs `safe6+candidates` comparison. Doing so with an arbitrary candidate set would have recreated the exact methodological error called out in the task description.

## Why the negative result matters

This outcome is still useful for the paper and for the Katran policy:

1. The live workload itself is not the blocker.
   The serial probe shows real guest traffic reaches the Katran XDP program and drives `run_cnt` upward.

2. The missing branch profile is a tooling problem.
   The guest does not currently have a kernel-matched perf binary for `7.0.0-rc2-gc3aad315df09-dirty`, so the preferred runtime branch-miss measurement path cannot run.

3. The synthetic microbench fallback is not yet semantically valid.
   A replay path that only returns `XDP_PASS` is not measuring the same hot path as the live Katran datapath.

4. The static fallback points in the same direction anyway.
   All 56 branch-flip sites already place the larger arm on fallthrough, so there is no structural evidence that branch-flipping should help this workload.

5. VM behavior can erase marginal branch wins.
   Even if some site were slightly better on bare metal, guest branch prediction behavior, virtualization noise, and front-end effects can dominate such a small local change.

## Final policy answer

For March 20, 2026, the Katran branch-flip policy should be:

```yaml
policy_base: safe6
branch_flip_sites: []
reason: no trustworthy hot/mispredicted branch evidence; structural fallback found zero candidates
```

## Next step required before revisiting this decision

To make a real branch-flip decision later, the next run must first fix Method A:

1. install or build a kernel-matched `perf` inside the guest for `7.0.0-rc2-gc3aad315df09-dirty`
2. rerun live Katran traffic and collect `branches` / `branch-misses`
3. only if top branch-miss hotspots can be mapped back to specific sites, generate `safe6 + top-N` candidate policies
4. then run the paired E2E validation

Until that is done, the correct engineering choice is to leave Katran branch-flip disabled.
