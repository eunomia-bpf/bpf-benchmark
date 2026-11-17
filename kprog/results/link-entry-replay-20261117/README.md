# Replay the production link function without replacing a live CLI

The checked Tracee guest uses the canonical host CLI throughout its load batch.
At22:28 it had completed21 entries, with recent entries taking18–365seconds;
the exclusive image lease for a main rebuild remains queued. Preserve that guest.

The smallest change is a private link(Args) function containing the unchanged
former main body. Main delegates after the same Args::parse. One ignored
captured-input test accepts an argv JSON path and uses Args::try_parse_from,
then calls that exact production function. No production environment lookup,
new CLI flag, BPF behavior, argument semantics or benchmark change. This is a
regression/real-input execution entry, not another native-link executable.

The existing Cargo unit executable is built in the sole normal target directory;
no CLI build, second build tree, binary copy or native image is created. Replay
uses every original captured request/flag and redirects only its existing output
arguments to persistent raw. Every status and both test stdout/stderr remain.
The normal tests and all295 requests run under timingSH/imageSH, CPU19/oneworker/
AS32GiB. Main size/mtime are recorded before/after. The waiting canonical build
will still occur under imageEX; this step does not claim it completed.

Raw: /workspaces/kprog-raw/perf/link-entry-replay-20261117. The committed one-shot
run-host.sh applies only main.rs. Existing six queued workers and scripts stay
unchanged. Current x86.rs contains dead-ID2c46d5c52 and label10b79579a; fusion
and tail encodings are still unapplied. This supplies actual current emission
evidence while preserving the live guest's executable. Installed/time and
stock-proof claims remain separate; Omp owns later measured batches.

## Actual result, 2026-11-17T22:33:48Z

Host2788020 ended0 at22:31:25Z. Full suite58 passed/0failed/4ignored;
the fourth ignored entry requires captured argv and is invoked295 times by
this replay. All295 actual requests emit with zero index errors. Canonical
main size/mtime remains2978744/1794948232 before/after; the guest continues.
No second native-link binary or build tree was created.

The source change is main.rs only: production main delegates to the unchanged
body in private link(Args); the external-input test invokes the same parser/body.
Current x86 source remains2c46d5c52 plus the earlier label fix. Actual dead-ID
comparison uses the AFTER-label baseline, keeping source attribution separate.

| App | Requests/emit | Changed payloads | Neutral bytes before -> after |
| --- | ---: | ---: | ---: |
| bcc/set | 25/25 | 0 | 11028 -> 11028 |
| cilium/agent | 47/47 | 0 | 180945 -> 180945 |
| katran | 1/1 | 1 | 9550 -> 9255 |
| otelcol-ebpf-profiler/profiling | 14/14 | 14 | 132859 -> 130635 |
| tetragon/observer | 39/39 | 39 | 294145 -> 285911 |
| tracee/monitor | 169/169 | 0 | 1747558 -> 1747558 |

Dead-ID neutral reduction is10,753B across54 payloads; other241 payloads
are byte-identical. Every helper-target multiset, map-name count, callee mask
and recovery-shape count compares equal. These observations do not prove
full semantics, installed bytes, app per-call or throughput. Full original
helper argument/return, proof and tail-miss regressions pass in the58 tests.

The exclusive canonical build/publisher remains queued and is not reported
as completed. This result is from the production function in the existing
unit executable. Raw source/test/invocations/arguments/outputs remain at
/workspaces/kprog-raw/perf/link-entry-replay-20261117/host-20261117T223029Z-2788020.
The registered/helper-context ABI issue remains separate owner work.
