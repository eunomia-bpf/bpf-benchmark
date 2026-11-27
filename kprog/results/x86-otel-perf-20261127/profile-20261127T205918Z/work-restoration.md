# Repaired shared-tail branch: guest work restored

This is the same repaired current image c103a86a, unchanged kernel/P/compiler inputs, and the frozen effective one-sample/10-second/stats-on/64GiB check. Both guest and corpus/app succeeded. Controller1164271 finished 2026-11-27T21:08:59Z, run `x86_kvm_corpus_20261127_210728_646166`. The earlier profile202908 never booted because the build cap leaked to QEMU; this retry recorded address-space limits [-1,-1]. Perf exit143 is the explicitly requested stop after guest completion, not a guest failure.

| Entry | Calls | Runtime ns | ns/call |
|---|---:|---:|---:|
| eBPF | 5971398 | 18144583281 | 3038.582135 |
| native | 8099989 | 24845566040 | 3067.357998 |

Diagnostic eBPF/native ratio **0.990618681x**. It does not meet the 1.20x per-call target, and this stats-on functional check does not establish the 1.30x throughput target or replace full timing. Keep the actual result; do not repeat until a favorable number appears.

Actual phase-matched observer records now show native unwinding, unlike the old broken 6e09 image:

| Phase/time | Attempts (metric5) | Frames (metric6) | Per-CPU stack lengths | Tail-call counts |
|---|---:|---:|---|---|
| baseline/101.4 (active) | 19530764 | 17916801 | [8, 14, 9, 15, 21, 8, 33, 1] | [3, 7, 5, 6, 9, 3, 10, 1] |
| baseline/105.97 (active) | 46116729 | 42247759 | [13, 11, 7, 7, 9, 9, 7, 12] | [6, 4, 5, 4, 5, 5, 5, 6] |
| post_rejit/132.59 (active) | 145547140 | 133923934 | [22, 11, 3, 12, 14, 15, 8, 15] | [6, 6, 2, 6, 6, 6, 5, 6] |
| post_rejit/138.54 (teardown) | 172364258 | 158734027 | [0, 0, 0, 1, 1, 0, 0, 0] | [1, 1, 1, 1, 1, 1, 1, 1] |

At the active native snapshot132.59, prog-array239 slot1 points to installed native unwinder28; metric map234 contains145,547,140 attempts and133,923,934 frames, all eight records have nonzero stacks (3–22 frames), and requested tails are2–6. Baseline active snapshots contain nonzero attempts/frames/stacks/tails as well. This directly shows that the previous complete skip is repaired in the guest. It does not assert identical dynamic call counts, stack payloads or lookup paths across two changing workload phases.

The native snapshot138.54 is inside the socket finish envelope but the attached entry is already absent: keep the row as teardown evidence, and do not treat its mostly zero stacks/tail1 as active skip evidence. Counters are cumulative per map, snapshots sparse/non-atomic, and the native map was populated before that active snapshot; do not compare its cumulative total directly with the baseline total as a workload gate.

Actual phase-matched unwinder images remain JIT21,868B/5,019 instructions versus native14,373B/3,435. Both retain72 map lookup,24 probe-read and4 trie call sites; native has no debug printk calls. This is the optimized native body retained after the branch-anchor correction, not a return to the old29,964B body. Native stack-operand instructions747 versus637 JIT are static operand counts, not measured spills or hot-path cost. PMU symbol resolution is a separate finite CPU19 analysis of this completed recording (launch1167058); collect it before selecting a common header/flag/linker optimization.

`map-path-analysis.json` retains actual source/DWARF layout and complete numbered map/record observations. `code-comparison.json`, code metrics and disassemblies retain exact dumped-code SHA/length and in-phase program identity. `corpus-app.json` is the exact frozen-run JSON, SHA256 a80ffd5572dfef65830f6a5fde31e2114c6dccbca09e60d73d8604dd8739500f. No program/count filter or historical functional-run exclusion is introduced. The full raw capture stays protected pending complete archive publication and every-file/Git verification; this partial report is not an archive completion receipt.
