# Current ARM core807 static handoff refresh

This detached run consumes the published b89015df9528fd5d3dcd4d2f451ba2a8e8b2dad9 ARM simulator snapshot. The old807 handoff captured c82c0832 at14:22 and predates the later b2b6/9004/b890 source changes. Its prior results remain historical in ../arm64-form-completion. Reuse the same incremental build-arm64 cache and unchanged807 form matrix; no production/reference source, mask, kernel/module/image or workload changes.

All executions here use QEMU user mode on the x86 host, NOT real ARM CPU evidence. The existing c110 canonical executable is frozen and reused without a root Lake build. Actual compiled inputs and the static ARM executable are captured after build; terminal results require independent review before publication.

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-core
~~~

After the static artifact is reviewed and published, the coordinator can use the EXISTING hardware-only run script without changing its code:

~~~sh
ARM64_HANDOFF=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-core/cpu-differential-arm64.gz OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-hardware sh kprog/fidelity/run-arm64.sh
~~~

The existing script refuses non-AArch64 hosts and preserves per-form case counts and every mismatch input. Hardware results remain pending. Default handoff still points to the earlier validated artifact until this refresh completes.

## Reviewed static handoff and QEMU/C phase

The incremental cross-build exits 0. All **807 forms x 1024 = 826,368**
QEMU/C architectural-state observations have **zero differences**. forms.tsv
records every form; mismatches.jsonl.gz retains the empty counterexample stream.
This matrix and both native-observer driver sources are unchanged from the
preceding 807 run. It is emulated execution, not ARM hardware evidence.

The static AArch64 executable SHA256 is 2eb0d29a3dab3cb433cccbf42774eda9dd3c902905dd90f3044d87471c626f8d.
Its file/ELF metadata is retained in static-elf.txt.gz. All 87 actual compilation
files match their archive hashes; all 79 copied production sources match launch
commit d3301d48f9c73af834217aecd001c98b8353681e. The compiled ARM header
matches published b89015df9/c21833de exactly. The launch source archive is
independently verified, including the generator bytes published in 820ef1f.
Any physical source drift at review is retained in handoff-summary.json.

The static artifact and hardware command above are ready for coordinator use.
This handoff snapshot does not claim a completed canonical comparison: that
terminal status and every reference row require their own review. It likewise
does not establish entry ABI projection, physical exclusive-monitor/order effects,
dynamic dispatch or all O1–O4 obligations. Existing full-register-bank and control
handoffs remain separately scoped. No new ISA model or oracle change is made.
