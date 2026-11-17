# Verified path on the hottest programs (2026-11-17, omp)

Todo item 4: for each application, the hottest program's B generation and stock verification, on the one
kernel, one image and one base. Entry point is the whole-app checked-sim-c target
(`make -C kprog/libnativeloader checked-corpus CHECKED_APP=<app>`), which runs the registered service in a
guest; the service generates B for each submitted P, the stock verifier checks B, and the frozen corpus runs
the app with natives installed at load.

## The base had to be refreshed first (two stale pieces, both in place)

Both were older than the loader core they must answer, so every replacement failed before any verification:
BCC's first run (`203012_406070`) installed **0** natives and logged 25 `native-loader failed
... error=native_kernel: invalid immutable-map metadata: 0xffffce9680e7e000`.

- **Loader**: `/workspaces/.agent-state/kprog-ck/verified-loader` was built 2026-11-16 09:03, before
  `4c32e2ac1`, `d6b4d335e`, `6066b311b` and `8b31e4533`. Rebuilt in place with
  `make -C kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader`
  (20:27Z, sha256 `430a337f…`).
- **Module**: `verified-module/bpf_x86_native_lab.ko` was 2026-11-15 12:23, before `e4cd3a12b` taught the
  loader to read the module's two-field `map_value_ptr` reply (`"0x%llx %u"`, frozen bit). The old module
  answers `"0x%llx"` only, so `lookup_native_lab_ptr_by_fd` (`native_loader.cpp:480`) rejected the trailing
  field. Rebuilt in place with
  `make -C kprog/stock-path/module MO=/workspaces/.agent-state/kprog-ck/verified-module`
  (20:44Z, sha256 `317e2e9a…`).
- The checked-sim-c compiler tools did not need a rebuild: their sources predate the 2026-11-16 16:21 build.

Raw runs live under `/workspaces/kprog-raw/verified/20261117-checked-hot/<app>/` (started, finished,
exit-code, `service.tar.gz`, per-request archives); each run's corpus data is under
`corpus/results/x86_kvm_corpus_*`. Running image `bpf-benchmark/kprog:current` = `55c1c443` (build input is
the working tree, unchanged by these runs).

## BCC (bcc/set)

Run `x86_kvm_corpus_20261117_204607_412064`, 1 sample × 10 s, stats on, exit code 0, 20:44:25–20:51:05Z.

- 25 submitted programs, **25 verified and installed**, 15 distinct native bodies, zero failures, zero
  fallbacks: every request journal line has `execution_path=checked-sim-c`, `b_generated=true`,
  `b_stock_passed=true`, `status=0` (`bcc-requests.json`). Verify+install time 207.1 s total, 3.1–8.5 s per
  program (`bcc-service-summary.json`).
- Both arms hold the same 25 programs / 21 distinct names, so this is equal work: baseline 39,990,223 runs
  against native 37,328,235 (0.934x; the native arm's window opens later because it spends the load-phase
  time above).
- Per-program, baseline vs native (runs, ns per run): `sys_exit` 17.91 M → 16.68 M, 81.5 → 76.1 ns
  (0.933x); `sys_enter` 17.91 M → 16.68 M, 117.7 → 128.1 ns (1.089x); `kprobe__cap_cap` (2 programs)
  1.43 M → 1.38 M, 287.1 → 336.6 ns; `tracepoint__sys` (4) 1.10 M → 1.05 M, 673.7 → 764.2 ns;
  `sched_switch` 699 k → 651 k, 252.4 → 319.4 ns; `fentry_vfs_open` 551 k → 526 k, 37.3 → 28.9 ns;
  `sched_wakeup` 360 k → 331 k, 139.8 → 154.0 ns. Small-count entries (n ≤ 214: `fentry_vfs_crea`,
  `block_rq_comple`, `block_rq_issue`, `sched_wakeup_ne`, `blk_account_io_`, `fentry_vfs_fsyn`) and the six
  zero-run entries are not ratios.
- Installed native bytes exceed JIT bytes here (59,674 vs 7,965 B across the arm) because these are the five
  helper calls each probe makes; this run is a verified-path check with 10 s of workload, not a timing run.

## Not yet run

Tracee, Tetragon, Cilium, Katran and OTel follow in that order; each gets its own section here.