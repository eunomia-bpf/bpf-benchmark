# Katran Harness Fix Report

Date: `2026-03-20`  
Repo: `/home/yunwei37/workspace/bpf-benchmark`

## Summary

- The Katran E2E harness is now measuring a **same-image stock -> recompile pair** inside each cycle instead of the old tiny one-sample path.
- `duration_s` now drives a real timed request loop, each phase gets a **100-packet warmup**, and the harness clears mutable Katran maps before every timed phase.
- The case now supports **multiple paired cycles** and aggregates with **median-oriented summaries**.
- I could verify the finished harness with a VM smoke run. The old `+24.4%` regression disappeared there.
- I could **not** complete a clean full authoritative VM run after the harness fix, because sustained Katran HTTP traffic in this VM still develops request timeouts during warmup / repeated cycles. That looks like a separate guest transport/runtime issue, not the original BPF measurement artifact.

## Root Cause Recap

From [`docs/tmp/katran_regression_investigation_20260320.md`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_regression_investigation_20260320.md):

- old harness claimed `duration_s=10` but did not use it
- only `sample_count=1`, `packet_repeat=5`
- only about `30` BPF events per phase
- fixed stock-first order
- state carried across phases
- JIT image size actually shrank (`13412 -> 13364`)

So the `407.6 -> 507.0 ns` result in [`e2e/results/katran_authoritative_20260319.json`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/katran_authoritative_20260319.json) was not trustworthy as a paper-quality performance number.

## Code Changes

Main changes are in [`e2e/cases/katran/case.py`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py).

- Measurement defaults were changed to real volume:
  - timed phases now use `duration_s`
  - non-smoke defaults are `packet_repeat=25`, `sample_count=3`, `warmup_packet_count=100`, `min_measurement_requests=1000`
  - see lines [`62-73`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L62)
- Phase aggregation now keeps per-phase latency/event summaries and compares **median** BPF time, not the old single weak sample:
  - see lines [`149-296`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L149)
- Mutable Katran maps are reset before each phase:
  - reset helpers and map API are at lines [`594-779`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L594)
  - reset list currently covers `fallback_cache`, `reals_stats`, `lru_miss_stats`, `vip_miss_stats`, `stats`, `quic_stats_map`, `stable_rt_stats`, `decap_vip_stats`, `tpr_stats_map`, `server_id_stats`, `vip_to_down_reals_map`
- Warmup is now explicit and success-based, with bounded retry budget:
  - see lines [`1290-1318`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L1290)
- Timed measurement now runs batches until both the duration target and minimum request floor are met:
  - see lines [`1321-1403`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L1321)
- The case now executes **fresh topology + fresh HTTP server + fresh program load per cycle**, but keeps **same-image stock -> recompile** inside the cycle:
  - see lines [`1478-1575`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py#L1478)

## Same-Image Path

- Katran cannot directly reuse `micro_exec run-kernel` from `#262`.
- Reason: that path is built around `bpf_prog_test_run` on a runner-controlled program instance, while Katran needs a **live attached XDP datapath**, guest namespaces, pinned maps, and real HTTP/IPIP traffic.
- The Katran case now mirrors the `#262` methodology inside its own harness:
  1. warm stock
  2. timed stock
  3. recompile live program in place
  4. warm recompiled program
  5. timed recompiled pass

## State Reset Notes

- The current Katran config still sets `F_LRU_BYPASS`, so connection-table lookup/update is disabled for this VIP.
- Because of that, the important state to reset in the current harness is the mutable **stats/fallback** state, which is what the new reset path clears.
- If this case later switches to a non-bypass VIP, it would be worth extending reset coverage to the inner `lru_mapping` map-in-map state as well.

## VM Runs

### Final verified smoke run

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 e2e/run.py katran --vm \
  --kernel vendor/linux-framework/arch/x86/boot/bzImage \
  --smoke \
  --timeout 2400 \
  --output-json docs/tmp/katran_smoke_final_20260320.json \
  --output-md docs/tmp/katran_smoke_final_20260320.md
```

Artifact:

- [`docs/tmp/katran_smoke_final_20260320.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_smoke_final_20260320.json)
- [`docs/tmp/katran_smoke_final_20260320.md`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_smoke_final_20260320.md)

Observed:

- warmup: `100/100` successful on stock and recompile
- baseline BPF avg ns/run: `255.82`
- recompile BPF avg ns/run: `245.56`
- delta: `-4.01%`
- speedup ratio (`stock / reJIT`): `1.0418x`
- events: `1500 -> 1500`

### Before vs after

Old authoritative artifact:

- [`e2e/results/katran_authoritative_20260319.json`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/katran_authoritative_20260319.json)
- BPF avg ns/run: `407.6 -> 507.0`
- delta: `+24.4%`
- events: `30 -> 30`

Final verified post-fix smoke artifact:

- [`docs/tmp/katran_smoke_final_20260320.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_smoke_final_20260320.json)
- BPF avg ns/run: `255.82 -> 245.56`
- delta: `-4.01%`
- events: `1500 -> 1500`

These are **not directly apples-to-apples** because the new verified run is smoke-sized and the old artifact was the broken “authoritative” run. But the direction is the important point:

- once measurement volume and phase symmetry improve, the spurious `+24%` regression disappears
- event volume increased by about `50x`

## Full-Size VM Attempt Status

I attempted multiple non-smoke VM runs on the fixed harness, including:

- full in-harness `sample_count=3`
- fresh one-cycle fallback runs

These runs still hit guest-side HTTP request timeouts during warmup / sustained traffic, typically after the first few requests in a batch, for example:

```text
RuntimeError: Katran warmup validation failed: [{'index': 4, 'error': 'timed out', ...}]
```

This means:

- the **original BPF measurement artifact is fixed**
- but the VM still has a separate **sustained Katran traffic stability issue** that blocks a clean new authoritative number today

I did not save a new authoritative JSON because the full runs did not complete successfully.

## Conclusion

- The harness now has the right structure for reliable Katran measurement:
  - timed load
  - warmup
  - mutable-state reset
  - same-image stock/recompile pairing
  - repeated-cycle support
  - median-oriented reporting
- The verified smoke run supports the original RCA: the previous `+24.4%` regression was a harness problem.
- Remaining blocker for a new full authoritative Katran number is a runtime transport issue under sustained VM traffic, not the old BPF timing logic.
