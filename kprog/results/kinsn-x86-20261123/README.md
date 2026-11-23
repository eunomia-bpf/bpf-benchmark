# kinsn on x86 with the frozen benchmark, 2026-11-23

Operator 2026-11-23: "kinsn 的也跑一下?", "唯一内核、唯一镜像 可以保留一个 kinsn 的也保留一个 kprog 的".

`kinsn-chain.sh` builds kinsn's own kernel, modules and image with the frozen recipe targets at kinsn's
locations, then runs the frozen corpus command on six apps (function check, then timing). What it took:

- Kernel: the kinsn line 24cd6e63ce91 (2026-10-06, the struct bpf_kinsn the kinsn modules use), exported
  once to /workspaces/.agent-state/kinsn-ck/src, built in kinsn-ck/build-x86.
- Modules: the fourteen kinsn modules of kinsn/module/x86. The directory also holds kprog's
  bpf_x86_native_lab.c, which reads the kprog kernel's bpf_prog_aux fields (native_trusted_*), so the
  kinsn kernel takes the recipe's own kbuild command with obj-m naming the fourteen.
- Image: bpf-benchmark/kinsn:current. Its kernel-dependent parts (micro and stage2 programs,
  kernel_offsets.h) are built against the kinsn kernel in kinsn-ck; kprog's copies are frozen. The
  kernel-independent parts are kprog's builds as they are.
- Passes: the frozen framework (runner/ as of 2026-05-29) has no `kinsn` umbrella pass; its kinsn group
  without prefetch is `kinsn-5` (rotate, cond_select, extract, endian_fusion, bulk_memory), the x86 default
  of kinsn/docs/evaluation.md.
- bpfopt: the 2026-11-06 binary passed `-bpf-enable-kinsn-select` to an LLVM BPF backend library built on
  2026-09-16 with the pre-rename names (`-bpf-enable-kop-select`), so every step failed. The backend
  libraries were rebuilt from the llvm-backend submodule source (7f56eafab, the rename) and bpfopt relinked
  (`cmake --build bpfopt/llvm/build-kinsn`); `--pass rotate` then runs on a saved input.

Function check with kinsn-5 (one 10 s sample per app, stats on), 2026-11-23T16:13–16:45Z:

| App | Status | Cause |
|---|---|---|
| Cilium | ok | 25 programs rewritten at load: cond_select 334, bulk_memory 322, endian_fusion 138, extract 2 calls |
| OTel | error | perf_unwind_dotnet after cond_select: the verifier refuses it ("R1 unbounded memory access") |
| BCC | error | biosnoop block_rq_issue after bulk_memory: the verifier refuses it |
| Tetragon | error | Tetragon exits before its programs load |
| Tracee | error | Tracee exits before its programs load |
| Katran | error | the main program fails to load |

The 2026-05-29 shim fails a program load when its load-time optimization fails, so an app whose rewritten
program the verifier refuses does not start. The timing pass was stopped at 16:54Z (it was re-measuring
the eBPF arm of apps that end in error). Runs: corpus/results x86_kvm_corpus_20261123_161347_866368 (OTel),
_162412_766945 (BCC), _162707_991543 (Cilium), _163155_904164 (Tetragon), _164012_618607 (Tracee),
_164458_307500 (Katran).
