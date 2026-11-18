# All LTO since image 55c1c443, one batch (2026-11-18)

The coordinator runs this batch itself (operator goal: "接下来你来做, 不要叫其他人, 你来负责清理好并且自己去调性能参数").
run.sh holds locks/batch from image build to the last timing run.

## What the image carries beyond 55c1c443

- PERF LTO, each host-tested and replayed on the 295 captured requests: map-dispatch fusion (b44b673aa), tail short
  forms (795483604), named-map CFG (9cf2726e0), zero-tail sharing (a4d1e0588), trie addressing, prefix limit, flag byte
  and exact-LPM direct entry (bb8d5ed72, 90f2dda0a, 1baa33404, 79ece52c1, f98d0c87c), UID packed load (235f08262), clock
  field operands (046786855), runtime ARRAY operands and direct returns (d226f71d0, eecc7e859), dead helper IDs
  (2c46d5c52), inline helper labels (10b79579a), probe and LPM/clock short branches (d92c85898, 0ef3671ce), known-count
  error zeroing (a5bb61c40), known large memory (b1da87fe4), LPM XOR/disp8 (a9bfdebb7).
- core-compat.h evaluates helper arguments once (9be7e30be).
- Loader items 5a-5f (8dba0e0bd, 9b94b7c61, 23e75dcf7, 47491721e).
- Helper context: every native manifest entry carries kernel_helper_context, so the native program calls the kernel
  functions the original program uses (bpf_perf_event_output_tp and the like). Evidence:
  kprog/results/helper-context-query-20261117; opening line in kprog/docs/freeze-open.tsv.

## Order

1. The checked Tracee guest (verified path, kprog-raw/verified/20261117-checked-hot) yields the image at its next request
   boundary, 40 minutes at most; its raw data stays and the remaining requests continue on the new image.
2. Image, one-image check (native replacements and native-loader failures per app).
3. Six apps breadth-first through the frozen entry with its defaults (3 x 180 s, stats off): the 2026-05-29 floors.
4. Six apps again with stats on, 3 x 60 s: per call, throughput, installed native/JIT, per-program paths.

summary.txt grows one block per run; raw and hostload.log are in /workspaces/kprog-raw/lto-all-20261118.
