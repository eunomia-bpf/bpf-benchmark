# Current signed-CMP CPU and canonical replay

This detached run consumes published b46de606ccde1165966e8d9fc0d19e881bcfe00e
production CMP flag expression using the existing 1144-form matrix and frozen
c110 canonical executable. The preceding d30 result remains separately published
at ../x86-self-xor-current. Results remain pending until the terminal status and
all per-form rows are reviewed. No production/reference/oracle change is made.

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
outcome. The canonical terminal status has not yet been independently reviewed
in this CPU snapshot; no reference pass is inferred from active empty streams.
The active trace and reference reader remain intact. This is enumerated-form
sampling, not every encoding, whole ABI, invocation/transport or O1–O4 closure.
