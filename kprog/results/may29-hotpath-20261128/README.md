# Actual May29 / Nov28 hot-program diagnosis

This follows todo section 0, coordinator 2026-11-28T15:52Z re-plan (the earlier 16:2x label was corrected at 15:54Z). Item 1 precedes restoring the CO-RE headers. No production change, new app compilation, image rebuild, timing run, benchmark/kernel/paper modification or app/program selection is made here.

Run the offline comparison with:
python3 kprog/results/may29-hotpath-20261128/compare.py

It reads the actual May29 stats-on runs 033517_489159 (Cilium) and 045551_393389 (Tetragon), and actual Nov28 runs 091645_012670 and 094333_560478. Per-program.tsv retains EVERY record, including zero/below100, with IDs, raw calls/time, ns/call, type and code sizes. The aggregate reproduces the May29 parser's >=100 rule, without pairing cross-run instances by truncated name or load order. Counter-analysis.json records source SHA/size and complete group arithmetic.

| Application / phase | May29 eBPF ns | May29 native ns | May29 ratio | Nov28 eBPF ns | Nov28 native ns | Nov28 ratio |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Cilium | 488.676 | 262.298 | 1.863055 | 713.843 | 578.687 | 1.233556 |
| Tetragon | 695.192 | 311.794 | 2.229653 | 732.176 | 579.994 | 1.262385 |

Cilium's retained hot records are two cil_from_container instances in each arm/run. Tetragon native's 17 generic_kprobe records change from group56.127 to678.536 ns; their contribution to the whole aggregate changes23.099 to271.902 ns (+248.804 of the total268.201ns increase). The hot generic_tracepoint itself changes662.401 to668.828 ns, return kprobes47.931 to49.340 ns. This localizes the change; aggregation is not a branch-hit observation.

## Cilium executable finding

Both complete disassemblies plus a line-by-line diff are retained, including every ELF relocation. The specified reference bpf_lxc.native.o has cil_from_container1268B, current staged P1843B. The reference entry has no perf_event_output call (numbered or named); current P has one bpf_perf_event_output relocation at0x3a9, following trace-notification construction. Source bpf_lxc.c:1816 calls send_trace_notify(TRACE_FROM_LXC); lib/trace.h:181 returns false for this observation when MONITOR_AGGREGATION>=TRACE_AGGREGATE_RX. The old build options set3; current agent-aligned options set0. The existing cilium-config-20261125 record documents the same original mismatch and its6cdde0600 correction.

Thus the retained reference native entry omits notification work that current native restores. This is a concrete skipped-work defect in the old configuration; restoring that omission would not be an equal-work speed fix. The existing current six-app/check records show matching packet entry engagement and actual tail targets, but do not establish all dynamic helper/event work equality. No newly demonstrated native-only extra work is claimed.

Important provenance limit: the specified reference object's DWARF comp_dir names the October09 paper-tree reproduction, not the May29 execution. Neither actual May29 corpus run retains tracked shim logs/installed bytes. The static object comparison is exactly against the requested retained build; it does NOT establish exact May29 installed-byte identity or attribute every316.389ns of native increase to the missing notification. The eBPF side itself also changes488.676->713.843ns.

## Tetragon executable evidence and remaining question

No Tetragon native object exists in the specified paper-tree-untracked build (a recursive generic-name search finds only two OTel proof objects). The May29 corpus retains counters/metadata but no installed native capture. It is incorrect to present a recompiled or later cached body as the original May29 run's bytes.

The exact May29 source at82ec89cb4 already has the branch-origin defect fixed by2d006f5d8: push_x86_synthetic assigns synthetic addresses and u64::MAX origins; x86_new_offset_for_local_target selects the next surviving original instruction, allowing a jump into a replaced helper to skip its expansion. Focused source excerpts are retained. The already-published tetragon-regression-20261128/replay-review.json demonstrates the consequence on exact Nov26 filter inputs: PFILTER_CONTINUE/index2 branches past the tail block to return; the current linker preserves the tail entry. That is a proven skipped-work defect class, but not an observation of the May29 installed branch or its dynamic hits.

The next finite job uses the retained reference linker executable on those SAME four original Nov26 proofs/plans, with no source rebuild or substituted plan. It saves raw commands/status/logs/blob disassembly, including incompatibility errors if any. This can test whether the requested reference executable reproduces the established omission; it cannot recreate missing May29 execution evidence. Recipe: replay_reference.py; execution pinnedCPU16/48GiB, sequential. Collect the SAME detached job on the next turn before interpreting it. Item1 remains open until that result and the current native/eBPF excess-work leads are reviewed. Items2/3/5 have not started in this fresh session.
