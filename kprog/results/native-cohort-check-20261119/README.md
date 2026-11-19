# Combined checked-native BCC functional check

Run the canonical `make -C kprog/libnativeloader checked-corpus` entry for
BCC with the current C ARRAY/probe helpers and native private-arena,
verified-path and integer-identity changes enabled together. The entry
defines its existing one-sample, ten-second functional workload. This is
stock/native coverage validation, not timing evidence.

The committed worker holds batch EX and timing SH; the entry acquires
image SH and starts its two-vCPU guest on CPUs 20–21. It uses the sole
base/compiler/loader and changes no image, kernel or benchmark setting.
All outputs and the registered-service request archive remain under
`/workspaces/kprog-raw/perf/native-cohort-check-20261119/`.

PERF 2026-11-19T08:17:44Z: Worker239817 completed with host/app status0/ok. The retained
service archive reports25 distinct source programs,25 native installations,
25 B generated,25 B passing stock,25 checked-sim-c executions,0 direct-native
fallbacks and0 failed requests. See coverage.json. Both workload phases complete.
The existing installed-code reader reports25 program pairs: JIT7,965B,
installed native20,043B. These functional1x10s counters are not an official
speed measurement.

Raw /workspaces/kprog-raw/perf/native-cohort-check-20261119/bcc-20261119T080830Z-239817;
corpus run x86_kvm_corpus_20261119_081018_746542. The supervisor removes its
temporary session after archiving; the reader uses service.tar.gz, preserving
all request capsules. Source7e7447fdd/7889e4740 provides that reader. All current
C helpers and native normalization/verified-path/integer pieces were enabled.
No image or benchmark setting changed. The guest and its leases are finished.

PERF 2026-11-19T14:59:03Z: Coverage reporting follows c3960d089. A failed service
request keeps the original eBPF program and contributes to kept_on_ebpf,
not native_installed. Explicit older direct-native successes remain in
direct_native; they are never retrospectively counted as verified. B counts
include recorded true values; a failure with missing B fields does not prove
that no object was generated. Counts are service requests except the distinct
source-program total. A completed BCC archive replay is queued on timing SH
to confirm the existing 25 checked records are preserved. This reader changes
analysis only; the base trusted loader rebuild follows the current batch.
