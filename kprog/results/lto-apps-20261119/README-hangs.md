# Two arms hang after a `list_progs` round-trip (OMP 2026-11-20)

Two arms on the 3b5fa4b40 image stalled the same way: Tetragon at 19:14Z (5 replacements) and Tracee at 20:40Z
(29 replacements). Both baseline arms finished normally; both post arms stopped growing their shim log within one
line of `socket: cmd=list_progs len=22`, and the guest stayed at ~100 % of CPUs 0-7 for 70-90 minutes. Neither
logged `kept on eBPF`, `failed`, or a panic.

Evidence against the obvious candidates:

- **Not the image code.** The coordinator's check of the same image replaced all six apps' programs (Tetragon
  288/288 with 33 `list_progs`, Tracee 169/169 with 77). `docker run bpf-benchmark/kprog:current strings
  /usr/local/lib/bpfrejit/libnative_loader.so` shows no `current_task`, i.e. the image carries 3b5fa4b40's
  library.
- **Not the base `trusted-native-loader`.** It was rebuilt at 19:14Z from HEAD (post-3b5fa4b40) and shows 0
  `current_task` strings; its md5 equals `kprog/libnativeloader/build/trusted-native-loader`.
- **Not the shim**, which is a frozen path and the same binary the healthy check ran.
- **Not CPU contention from the arm64 work**: the coordinator's arm64 QEMU guests are pinned to CPUs 8-23, these
  arms to 0-7.

The base's `libnative_loader.so` is still the 11-19 11:59 build (its strings lack `current_task` and
`jiffies_64`, which the HEAD build has), but the guest is told to load the image's
`/usr/local/lib/bpfrejit/libnative_loader.so`, so it plays no part unless a path uses it.

So the hang is a blocking read in the supervisor/service round-trip that a fast healthy run does not hit. Both hangs
are kept: `/workspaces/kprog-raw/omp/lto-tetragon-hang-20261120T1916Z` and
`/workspaces/kprog-raw/omp/lto-tracee-hang-20261120T2041Z`. Tracee's arm is re-queued after Tetragon's retry; if
the retry hangs at the same line the next step is a service-side stack, not another re-run.
