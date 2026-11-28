# Cilium active-program difference

The same-image6b88 frozen10s check has app status ok and135 native replacements/zero native failures. The apparent5-vs2 active-program difference does not mean three hot packet-processing programs disappeared. Both arms have two cil_from_container entries; baseline's extra cil_from_host,cil_to_host,cil_to_netdev each ran exactly once. They remain part of the record rather than being excluded by an activity threshold.

| Arm | Directional packets sent | Hot entry calls | Difference |
|---|---|---|---|
| eBPF | 6874255 / 6874341 | 6874267 / 6874353 | +12 / +12 |
| native | 7105001 / 7098878 | 7105012 / 7098890 | +11 / +12 |

Both pktgen directions returned0 and reported zero send errors,64-byte packets,65535 randomized flows and clone_skb0 for the same bidirectional endpoint workload. Endpoint IP/MAC allocations differ between the independently started application instances, and are retained in the JSON; literal address equality is not assumed. Send output and entry counts establish packet-path engagement, not end-to-end reception or identical packet fate.

Phase-matched baseline133.25/135.59/137.93/140.29 snapshots have increasing counts on entries149/172. Native189.18 has active replacements441/461 (the original440/460 have zero cumulative run count). Endpoint prog-array slot7 points to tail_handle_ipv in both phases: baseline map84->151 and88->170, native260->437 and280->465. The native194.24 snapshot is during teardown with no endpoint entries; retain it explicitly rather than calling it an active skip-work sample.

This resolves the active-count lead narrowly and provides actual work/target evidence. Only array keys0-7 were sampled: later tail slots, dynamic tail invocations, hash contents, packet delivery and full path equivalence are not proved by these snapshots. A stronger equality claim would be unsupported. Full per-program reports, workload outputs and phase windows are in cilium-work-alignment.json; complete plans/RAW/corpus are preserved for the final six-app report. No new measurement, source fix, workload change, count gate or tuning follows from the5-vs2 count alone.
