# Six applications on the 2026-05-29 native path

Timing only. This recipe runs the operator's request "先把所有的都测试一遍了吗?
回到之前的数字了吗" from `/workspaces/repository` on master, the project's one
tree (operator 2026-11-09, "以后禁止切换branch 和开不同的 tree"; 2026-11-10,
"/paper-tree 是什么???? 又违规开了 worktree 了?").

## What runs

- **Framework**: the benchmark framework of the frozen commit `9f3855f6f`
  (`Makefile`, `runner/`, `corpus/driver.py`, `corpus/config`, `corpus/inputs`,
  `micro/config`, `vendor/bpfrejit_x86_defconfig`), read from this repository with
  `git archive` into the image build context. The whole `runner/` comes from that
  commit because the frozen `corpus/driver.py` imports `snapshot_app_maps` from
  `runner/libs/rejit.py`, and master's `rejit.py` has moved on since. The guest
  runs this tree's `__runtime-vm-corpus` (equal to the frozen one apart from the
  `native-sim`/`kprog` and `module`/`kinsn/module` renames), so results land in
  `corpus/results/x86_kvm_corpus_*`.
- **Build outputs** in `ART` (`/var/tmp/kprog-tmp/R/six`): the kernel built from
  `vendor/linux-framework` `8e116c79d` (`bzImage`, `modules/`, `kernel.config`,
  `kernel_offsets.h`), the 2026-05-29 kinsn modules, `libbpfrejit_shim.so`,
  `libnative_loader.so`, `native-link`, and the native objects under
  `native-bpf/x86_64/<app>/`. BCC, Cilium and Tracee objects come from the
  2026-05-29 build; Tetragon's come from the current tree's build, because the
  2026-05-29 Tetragon source targets an older `struct filename`.
- **Guest**: the native lab module, `kernel.bpf_stats_enabled` per
  `BPFREJIT_CORPUS_BPF_STATS`, and the unbound shim path
  (`BPFREJIT_SHIM_NATIVE_LOADER=post`, the app's manifest,
  `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF` unset, `SKIP_REJIT=norejit`).

## Run

```
make -f kprog/perf/may29-image/Makefile image
make -f kprog/perf/may29-image/Makefile six
```

`six` runs every entry of `RUNS` (application and stats mode) one at a time on
host CPUs 0-7 with `SAMPLES=3 WORKLOAD_DURATION=180` and `VM_MEM=64G`, the
2026-05-29 settings, and appends each start, end and run directory to
`$(STATE)/progress.log`. A `STOP` file in `STATE` ends the queue after the
current run. One run: `make -f kprog/perf/may29-image/Makefile corpus
APPS=bcc/set BPFREJIT_CORPUS_BPF_STATS=0`.

Each run directory goes through
`kprog/results/kprog_perf_attribution_20261108/tools/audit_native_arm.py`
before its numbers enter a table.

## Ratios

`ratio.py` computes each row with the parsing functions of
`kprog/docs/archive/native_eval_20260529.py`, the script behind the 2026-05-29
table in `kprog/docs/evaluation.md`: `off=<run>` gives workload throughput
native/eBPF from a stats-off run, `on=<run>` gives BPF ns per invocation from a
stats-on run. On the archived runs it returns BCC 1.005x and OTel 1.824x, the
published figures.
