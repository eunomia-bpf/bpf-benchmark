# Tetragon native increment: retained-run localization

Followed newest **COORDINATOR 2026-11-28T11:20Z**: investigate Tetragon first as an alignment bug, then BCC stats-off, then rebuild/check the common fixes. OTel remains at2689a430; no application, image or timing entry change here.

**249.202 ns of the261.898 ns aggregate increase is in the17retained generic_kprobe entry instances**, not the hottest generic_tracepo program. This is localization, not a proven cause or a claim that restoring the historical shorter path is correct.

`compare_runs.py` reads the actual11-23 stats-on3x180s run `x86_kvm_corpus_20261123_120320_002937` and the new rotate's `x86_kvm_corpus_20261128_094333_560478`. Both app status values are ok. The exact05-29 parser retention rule is run_cnt_delta>=100, giving24retained native programs in both runs. Old/current positive-program counts (including below-threshold) differ; all counter sums and input SHA256s are preserved in comparison.json. No new measurement was run.

| Native group | Retained instances old/new | Group ns/call old/new | Contribution to aggregate ns old/new | Change ns |
|---|---|---|---|---|
| generic_kprobe_ | 17/17 | 55.291/678.536 | 22.700/271.902 | +249.202 |
| generic_tracepo | 1/1 | 675.077/668.828 | 287.431/300.707 | +13.276 |
| event_exit_acct | 1/1 | 1344.954/1368.729 | 0.000/0.000 | +0.000 |
| generic_retkpro | 5/5 | 48.662/49.340 | 7.965/7.385 | -0.579 |

The native aggregate is318.096->579.994ns/call. The generic_kprobe group is55.291->678.536ns/call, with call fraction0.4106->0.4007. A symmetric accounting decomposition assigns+252.812ns to this group's per-call change and-3.609ns to its weight change. These terms sum to+249.202ns; they describe the counters, not an independent causal experiment. generic_tracepo itself is675.077->668.828ns/call; its aggregate contribution rises13.276ns because its call fraction rises.

Actual per-run loader receipts join every retained native program ID/name/JIT length to the original/native records from that same loader thread. The17generic_kprobe instances have original BPF tag93c5f592a9cdde6a/JIT1879 in both runs, while installed native length changes1329->1401. generic_tracepo original tagd9601a7cf35a5c65/JIT14942 stays, native13483->13625. The return-kprobe original tags differ; the report keeps them explicit. IDs, fds, truncated names and load order are **not** used to pair program instances across runs. Same BPF tag or native length does not establish equal native instructions, map contents, attach target or work.

The source entry `generic_kprobe_event` calls `generic_start_process_filter`: process_call_heap lookup, config_map lookup/policy check, task namespace/capability reads, then a tail call. A55ns historical average versus679ns now makes the early-exit/deeper-work distinction important; it does not prove which path either run took. The common helper-expansion branch repair2d006f5d8 and helper/hash/LTO changes are investigation candidates, not established causes. The code/history list is not a replacement for actual installed instructions and link plans.

The requested11-23 installed native byte/link-plan capture has not been located. Its retained corpus run has structured counters and original/native installation receipts; the listed historical linkcache directories found under the coordinator profile tree are OTel captures. Do not rebuild/rerun an old benchmark and label that as the original long-run code.

Reuse the committed03:56 same-image Tetragon check archive for current candidate code instead of running another guest. runtime-plan-audit already resolves generic_kprobe_event keys14c39eec84e8b216/90f202a84992a835 to equal1355Bcanonical blobs and constants CONFIG_ITER_NUM1/PARENTS_MAP_ENABLED0. `inspect_current.py` streams that existing archive once, verifies14exact selected members, preserves both plans/ABI/map patches and decodes the blobs through an in-memory fd. It does not treat1355Bplus a wrapper-length difference as installed-code identity. Its prepared finite inspection runs detached onCPU19 under48GiB; collect the same job next turn before any rerun. The recipe and preparation are committed; current-code-controller.json and the raw records are collected and published separately after actual completion.

Next: read/review that same inspection, bind the relevant current branch/helper/map/tail targets, and continue locating original11-23 code or make the historical capture gap explicit in the causal result. Then diagnose BCC stats-off and rebuild the current x86 image with ee7f45f55/6c8fdc70f for the six-app10s check, as ordered. Tracee's confirmed field-existence bug remains separately recorded and unfixed (f4a918e0e). No speculative performance edit or historical short-path restoration.

Published 2026-11-28T11:37:28Z. Metadata CPU19; no compiler, guest, PMU, new timing, production-source/P/root/image/app/kernel/flag/benchmark/paper change.

## Completed current-code collection (2026-11-28T11:51:25Z)

Consumed the same inspection1444133, finished11:39:27Z rc0. It verified all14selected archive members; both canonical generic_kprobe_event blobs are1355B, SHA34c212ca21ad07fd25ec83c26ee7b5b69c6d4b9ca5686a205e75352153b4617b. Full untruncated raw plan/blob/disassembly/ABI/map-patch records and log are in current-code-records.tar.zst (10897B, SHA64772edb576736f489e65978879f64dbbf89e0837a56c71fd461da2b46b18940), everymember verified against its original. current-code-archive.json indexes each SHA/size/originalpath; original raw records/log and all older captures remain. This inspection was not rerun.

`review_current.py` joined the actual side-band relocations to captured symbols. The initial pre-module kallsyms lacked shared-C hash targets, so the first join failed; its exact recipe and receipt are preserved. The corrected join adds the recorded272.08module/BPF snapshot and resolves all7calls in each blob:0xb0/0x512 ->kprog_htab_elem_k4;0x135/0x530 ->kprog_htab_elem_k8;0x224/0x4f1 ->generic bpf_map_lookup_elem;0x10e ->bpf_get_current_cgroup_id. Initial call0displacements are relocation placeholders, not self-calls. The plan's desired inner-hash forms do not prove the actual calls were specialized; two actual inner calls remain generic. Runtime bound map pointers, invocation frequency and matching traditional BPF gen_lookup remain separate evidence questions.

Both canonical bodies inline3array/percpu-array lookups,2current-task reads and the index2tail transfer; body-relative ranges and mapliteral patchslots are recorded in current-review.json. They retain CONFIG_ITER_NUM1/PARENTS_MAP_ENABLED0. These static observations do not bind the1355Bbody to either long-run installed code by length or prove live paths.

Found retained11-26 proof/plan/canonical code in cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile (image68655f5c6c0d, sourcec3c019be2). The two root canonical blobs there are1413B. compare_call_bindings.py verifies their same7target-name sequence and same2scalar values; there is no added root hash call site in this pair. This is11-26 evidence, not the still-missing11-23 installed byte capture. Same symbol names do not prove identical callee bytes or dynamic work.

The retained root proof has a direct jump to bpf_get_current_task; the filter proof has direct jumps to lookup/tail calls. These are relevant to already-landed2d006f5d8's preservation of branch destinations on expanded calls, but static candidates alone do not establish the250ns cause. ONE detached replay1447799 now uses the current common linker on4exact historical proof/plan inputs (two roots/two filters), CPU16/48GiB, no compiler, branch/worktree/source export, guest or timing. replay_retained.py and sealed replay-launch.json preserve it. **Collect this SAME job next turn**; no replay result/causal acceptance is claimed here.

No source fix or image rebuild this step. Continue Tetragon cause, then BCC stats-off, then the ordered ee7f45f55/6c8fdc70f image plus six-app10s check. OTel2689 and STOP remain.
