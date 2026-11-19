# Combined checked-native BCC timing batch

The cohort through ff02957cc passed the canonical BCC functional check:
25 programs/native/B-generated/B-stock, zero fallback/failure, app ok
(native-cohort-check-20261119). This batch measures those changes together.

Hold batch EX from the frozen one-image image recipe through its six-app
check and the final BCC timing. Build under timing SH/image EX; guests under
timing EX/image SH. The sole image/base is replaced in place. Source/helper
changes stay enabled together; no new producer, kernel or benchmark change.

BCC uses the coordinator's existing main-config guest entry
lto-config-20261119/run_lto.sh (checked-sim-c), with three 180-second samples
per arm, stats enabled, CPUs 0–7, eight vCPUs and 64 GiB, including the frozen
kvm-host-cpu step. Only the functional six-app check uses its existing 1x10s
definition. Direct-only corpus timing would not exercise the C helpers.

Each stage has its own log and completion status under the persistent raw
directory. Expect roughly 30–50 minutes depending on cached build/startup
work. Read the actual app/coverage results and sample series when complete;
no speed gain is claimed from the earlier functional run.

PERF 2026-11-19T08:23:26Z: Timing-wrapper dry run passed. The full image dry run entered
forced recursive kernel recipes despite make -n; only owned make244102 was
stopped (143), with no guest using the base. Its log stays at
/workspaces/kprog-raw/perf/native-cohort-timing-20261119/image-dry-run-20261119T0819Z.txt.
Normal batch254724 then started the frozen build under image EX at08:22:12Z,
raw batch-20261119T082212Z-254724. No source/kernel version or benchmark
setting changed during this correction.

PERF 2026-11-19T08:41:44Z: The frozen image build completed at08:30:25Z, publishing
5c974db3050f (full runtime identity and actual kernel revision/release in
image-publication.txt). Kernel83e0fabe355d and release7.0.0-rc2+ match the
single checkout/base; this build replaces the sole image in place.

The check is still running. Completed rows: OTel083228_600676 rc0,14 native
replacements/0 failures; BCC083553_975462 rc0,25 native/0 failures. Other apps
and the combined checked-native timing remain pending; no speed ratio is
claimed from these functional checks. Their small raw metadata/results are
committed next to the corpus run directories.

BTF regeneration changed two enum entries in each tracked generated header:
PT_TOP_PHYS_MASK___2 and ___3 exchange4503599627366400ULL and
18446744073709547520ULL in vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h and
vendor/bpf/tetragon/bpf/include/vmlinux_generated_x86.h. This is the same
kind of BTF dedup-order change previously recorded on11-16. The frozen
paths remain uncommitted build output; no source edit or native-byte
identity claim is made here.

PERF 2026-11-19T08:43:39Z: Cilium check083913_345166 also completed rc0 with113 native
replacements and0 loader failures. Remaining check rows and BCC timing are
still in progress. The installed compile-sim-ir remains the07:53:18 build
of the measured cohort. New unrelated source work in compile_sim_ir.cpp
(freezeUnspecifiedInputs) appeared at08:40:58; it has not replaced that base
binary. This run must not be attributed to that new source work.

PERF 2026-11-19T08:49:54Z: Further check rows complete: Tetragon084248_939825 rc0 with
288 native replacements/0 failures; Tracee084614_204635 rc0 with169 native/0
failures. Katran and the main checked-native BCC timing are still pending.
The small per-run raw metadata/results are committed; bulky shim details
remain in their original run directories.

PERF 2026-11-19T08:53:11Z: The six-app check completed at08:51:00Z, all rc0 and zero
native-loader failures. Native replacement counts in entry order are
14 /25 /113 /288 /169 /1. Katran084956_577247 is the final row; its small
raw metadata/results are committed. BCC checked-native timing has now
started; batch254724 retains its lease and no speed result exists yet.
