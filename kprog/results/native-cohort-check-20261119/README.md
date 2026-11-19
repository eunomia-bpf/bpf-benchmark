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

PERF 2026-11-19T15:12:40Z: The service's new failure branch raises before returning
B flags to the completion record (trusted_service.py:194-199). The reader
therefore supplements absent flags only from an actual retained simulator
object named by artifacts.json or a checked-simulator-verification.json
receipt. Explicit flags are preserved. simulator-failure.json supplies
the actual failing stage. An early failed request without kernel.facts.json
retains its source ID/error and a null program type; a successful request
still requires its facts. These are archive-analysis changes only. The
completed-BCC reader worker433910 remains queued; no host pass yet.

PERF 2026-11-19T15:44:16Z: Operator's newer instruction, recorded in user-instruction.md
and implemented by0a993eb37, restores direct-native execution when B fails:
"恢复这个, 吧 verify 和运行分开看". This supersedes the earlier c3960d089
policy above. Coverage counts actual execution_path/status independently of
B-generation/stock acceptance: a successful direct-native request remains
native even if B fails; only a failed request contributes to kept_on_ebpf.
The current Tracee batch's direct-native results therefore agree with the
restored policy, and are still never called stock-verified. No rebuild
targeting the superseded c3960d089 policy is queued. Future base/image
batches use current HEAD normally. Reader replay433910 remains pending.

PERF 2026-11-19T16:39:41Z: Recovered host reader16653 completes the actual completed-BCC archive replay. All25 source programs/native/B-generated/B-stock/checked records remain, with0direct/failed/kept requests. Full recovery-coverage.json is committed. This is the earlier1x10functional archive, not a new guest or timing. Raw /workspaces/kprog-raw/perf/coverage-reader-20261119/recovery.
