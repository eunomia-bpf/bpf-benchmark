# Current ARM core807 static handoff refresh

This completed run consumes the published b89015df9528fd5d3dcd4d2f451ba2a8e8b2dad9 ARM simulator snapshot. The old807 handoff captured c82c0832 at14:22 and predates the later b2b6/9004/b890 source changes. Its prior results remain historical in ../arm64-form-completion. Reuse the same incremental build-arm64 cache and unchanged807 form matrix; no production/reference source, mask, kernel/module/image or workload changes.

All executions here use QEMU user mode on the x86 host, NOT real ARM CPU evidence. The existing c110 canonical executable is frozen and reused without a root Lake build. Actual compiled inputs and the static ARM executable are captured after build; the terminal result and every per-form reference row are now reviewed below.

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-core
~~~

The reviewed static artifact is published; the coordinator can use the EXISTING hardware-only run script without changing its code:

~~~sh
ARM64_HANDOFF=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-core/cpu-differential-arm64.gz OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-current-hardware sh kprog/fidelity/run-arm64.sh
~~~

The existing script refuses non-AArch64 hosts and preserves per-form case counts and every mismatch input. Hardware results remain pending. The default Make handoff now selects this current artifact. The existing hardware-only
run-arm64.sh uses it without an override; ARM64_HANDOFF remains available for
reproducing a historical snapshot.

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
At that static-handoff review, the terminal canonical status had not yet been
examined. The final review below now establishes its outcome. This likewise
does not establish entry ABI projection, physical exclusive-monitor/order effects,
dynamic dispatch or all O1–O4 obligations. Existing full-register-bank and control
handoffs remain separately scoped. No new ISA model or oracle change is made.

## Completed canonical result

The reference Make job exits **0** at 2026-11-07T18:49:59.219562+00:00. Every one of
807 forms has 1024 canonical observations: **826,368 states**, with **zero
QEMU/C, QEMU/reference or C/reference differences** and **zero unavailable
forms**. reference-forms.tsv records every count. Complete compressed mismatch
and unavailable streams are empty. No CPU or QEMU rerun or oracle edit was needed.

The exact frozen canonical executable is c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96,
independently checked against the [already published archive](../x86-current-matrix/canonical-reference.gz).
This is reuse of that exact executable, not a rebuild of later canonical sources.
All previously published static/compiled-input artifacts are rechecked unchanged.
The original 1500684312-byte trace remains in this Workspace, with verified
layout/length and SHA256 799004447cbb13e7f803571316a2ffff45d5b1156b903ef0a8971792aceb7897.
summary.json records exact identities, source drift and terminal review time;
handoff-summary.json retains the earlier handoff timestamp plus this later review.

Real ARM hardware execution remains pending with the coordinator. The static
binary and existing hardware-only script command above are ready; QEMU and
reference agreement are not relabeled as real hardware validation.

## Default handoff selection

The existing fidelity Makefile now defaults to this reviewed b890/c218 static
artifact (2eb0d29a). The prior 14:22 artifact remains historical. The selection
changed after both builds captured their actual inputs; no active build cache
was overwritten. make -n ARCH=arm64 run-handoff resolves the new path, and
sh -n kprog/fidelity/run-arm64.sh passes. These checks do not execute ARM
instructions or claim a hardware result. On real ARM, the coordinator can now
run the original one-command script without an environment override:

~~~sh
sh kprog/fidelity/run-arm64.sh
~~~
