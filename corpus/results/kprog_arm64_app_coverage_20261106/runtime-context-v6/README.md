# Strict BCC source-map runtime retry

Run arm64_qemu_corpus_19700101_000009_080977 used the unchanged two-start
BCC workload, one sample/two seconds, BPF stats on, eight vCPUs/4GiB. Baseline
completed with23 raw program-counter rows. All116 startup attempts remain
(108loaded, eight unfinished), with34 generation-bound replacements. Eight
runtime-FD map-value probes and the tracing zero probe now pass; the real
fentry_vfs_read program is replaced. Six anonymous tracepoint helper113
candidates reject with R1 scalar instead of a writable pointer. No native
workload measurement completes; the original app failure remains in raw JSON.

The native frontend allocated one byte for a source R10-8 helper destination
of eight bytes, overlapping the saved native return address. Separately,
ARM SUB discarded STACK provenance. The rejected helper artifact is retained
as failure evidence and must be regenerated after both repairs; it is not a
positive execution control. Lane C owns source-frame analysis; lane A's
stack-only SUB repair has separate formal and real QEMU controls.

The packaged manifest contains32 entries:23 resident source triples, eight
static startup selectors and one source-map selector. bcc-packaged-inputs.tar.gz
contains that exact payload, independently of later staging changes. The
kernel/stock modules/ten unchanged kinsn use6836f7d44; the source-map library
and native_lab module change together to T's published d25b4d7f4 bundle.
The strict shim is the pinned0bff849bf snapshot and the ARM linker includes
01e636c94. No program or startup probe is excluded. build.log/run.log retain
the exact Make commands; QEMU counters are functional measurements.

Only the current app-runtime-v6 root/image is retained. The previous v5 raw
run and exact payload were committed before its superseded root was retired.
