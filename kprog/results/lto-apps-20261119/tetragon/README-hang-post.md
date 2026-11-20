# Tetragon arm on the 3b5fa4b40 image hung in the post arm (2026-11-20T19:14Z)

Run x86_kvm_corpus_20261120_191627_291842, `APP=tetragon/observer`, 3 x 180 s per arm, stats on, the
3b5fa4b40 image with the base loader rebuilt to HEAD. The baseline arm completed normally
(`measurement_done ... status ok`), the post arm loaded programs and stopped:

- `native-loader replaced prog=` 5 times, then 27 `BPF_PROG_LOAD` records and a `socket: cmd=list_progs len=22`
  line at 19:29, after which the shim log did not grow for 70 minutes while the guest held CPUs 0-7 at ~100 %.
- No `kept on eBPF`, no `failed`, no panic: the arm is waiting on a service round-trip, not rejecting work.
- The healthy check run of the same image and app (`x86_kvm_corpus_20261120_184037_355453`) replaced all 288
  programs and issued 33 `list_progs` commands, so the image itself is fine; this arm hung.
- No contention cause: the coordinator's arm64 QEMU guests are pinned to CPUs 8-23 and mine to 0-7. Load was
  10-13 while the guest idled, which is the host's own work, not a boundary crossed by the guest.

The guest was stopped (SIGTERM, then SIGKILL on the QEMU process to release CPUs 0-7 before Tracee's arm started),
and the arm is re-run. Raw: /workspaces/kprog-raw/omp/lto-tetragon-hang-20261120T1916Z (run log, the 557-line post shim log ending at
the `list_progs` line, and `state.tar.gz` with the hung session's capsules). The 200 MB `state/` directory is not
committed - it is preserved in that archive instead, since one of its generated MIR files alone is 150 MB.
