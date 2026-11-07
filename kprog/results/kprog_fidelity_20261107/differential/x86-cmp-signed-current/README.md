# Current signed-CMP CPU and canonical replay

This detached run consumes published b46de606ccde1165966e8d9fc0d19e881bcfe00e
production CMP flag expression using the existing 1144-form matrix and frozen
c110 canonical executable. The preceding d30 result remains separately published
at ../x86-self-xor-current. The terminal status and every per-form row have now been reviewed below. No production/reference/oracle change is made.

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=x86
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-popcnt-memory/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/x86-cmp-signed-current
~~~

The same incremental build-x86 cache is reused after the preceding readers
closed; no root Lake/kernel/module/image rebuild is involved. launch.json and
launch-inputs.tar.gz preserve the prelaunch identities. The actual compiled
production snapshot, generated C/assembly and static binary are captured after
build completion, separately from these prelaunch observations.

## Completed real-CPU/C phase

The incremental build exits 0. All **1144 forms x 1024 = 1,171,456 states**
complete on the real x86-64 host CPU with **zero CPU/C differences**. The
23 explicit CMP forms have 23552 states and zero differences; cmp-cpu-forms.tsv
extracts their per-form counts. Every preceding1144 assembly/opcode row and
the observer driver/build rules are unchanged. No flag mask is relaxed.

The actual compiled header matches published b46de606c/4fe6817 exactly.
All 90 captured compilation inputs match their archive hashes; all 82 copied
production source files match launch commit 1d0a11029e706a9e51cb8b9ce15bf0410468d875.
The static executable SHA256 is 2057b385f3b982fc38adf9486f5025ab1b07b9cbd8deff038ad843fe9a4de924.
The exact launch archive/generator bytes and all source identities are verified;
physical source drift after capture is recorded without changing this snapshot.
In particular, later C RORX edits are not relabeled as tested by this result.

forms.tsv and the compressed empty mismatch stream retain the full CPU/C
outcome. At that CPU-phase review, the terminal canonical status had not yet been
examined. The completed canonical review below supersedes that pending status.
The original trace remains intact; its reference reader has now closed. This is enumerated-form
sampling, not every encoding, whole ABI, invocation/transport or O1–O4 closure.

## Completed full canonical result

The reference Make job exits **0** at 2026-11-07T19:09:39.877448+00:00. All **1144
forms x 1024 = 1,171,456 states** have **zero CPU/C, CPU/reference and
C/reference differences**, with **zero unavailable forms**. The23 explicit
CMP forms contribute23,552 states and zero differences in all comparisons.
reference-forms.tsv and cmp-reference-forms.tsv retain every count; complete
compressed mismatch and unavailable streams are empty.

The frozen c110 canonical executable is independently verified against the
[already published archive](../x86-current-matrix/canonical-reference.gz).
The previously published static binary and all90 compiled input files remain unchanged.
The original 2127364120-byte trace is retained in this Workspace, its full
layout/length and SHA256 d8cde036e7544a4c1dcb96f7354d0712ebd32b24842d67fbf06de88083e77022 verified.
summary.json retains the exact terminal times and all observed root-source drift.
Those later root edits do not alter the frozen4fe/b46 production source used here.

The later published RORX shared handler has its own
[focused real-CPU/C/canonical result](../x86-rorx-current/README.md): four existing
register/memory forms,4096 states, zero differences. It is not relabeled as
being part of this1144-form4fe snapshot. No CPU rerun, flag/memory oracle change,
new ISA model or source relaxation was needed to complete this full result.
