OTel regression audit, 2026-11-16

The 18:24 coordinator notice requests a stage-compiler regression investigation.
Retained measurement-window program records give 330,814 installed native bytes
in 102445_806916 and 125155_179400, and 303,930 in 172620_968192. The reduction
is exactly eleven copies of 2,444 bytes, matching the removed custom hash
routine. Two programs keep their sizes. There are thirteen programs in each
measurement window; shim replacement counts include an additional temporary
feature-test program. Thus replacement counts and window inventories have
different scopes. The assumption of equal installed size needs correction.

The committed audit compares original counters, integer-loop sample series,
and current stage output against three retained pre-publication physical
objects. It compares instruction bytes and relocation identities, without
rebuilding old tools or creating source copies. These are host source/static
facts, not a conclusion about the throughput cause.

The diagnostic profile uses the existing profiling tool on CPUs 20-23 with
four vCPUs and 32 GiB guest RAM, under image SH and without the 0-7 timing lock.
It uses the profiling tool's one-sample 60-second two-arm workflow, not the
three-sample timing protocol. The timed image and C's baseline round remain
in place. Different CPU count, sampling overhead and concurrent host load are
caveats for this profile; its throughput is not a new official timing number.

Run the committed Makefile's audit/profile targets. Raw evidence remains under
`/workspaces/kprog-raw/perf/20261116-otel-regression`. Per-call counters alone
do not separate body, helpers and maps. The corresponding profile split and
an affected-app stats-on run after publication remain work in progress.
