# Historical best Cilium and Katran: actual installation receipts

Coordinator 2026-11-27 19:01 requested comparison of historical best loaded code with current code. This is a read-only examination of retained frozen runs, with no new timing. All functional historical results remain recorded under the existing best-numbers policy.

| Case | Run | Baseline/post ns per call | Ratio | Active target installation |
|---|---|---|---|---|
| cilium_best | 20261121_133941_317114 | 604.598236 / 448.412584 | 1.348308x | BPF fallback: 1093 JIT / 1720 xlated bytes |
| cilium_current | 20261124_054725_460151 | 743.686565 / 595.816170 | 1.248181x | native: 1686 / 16 bytes |
| katran_best | 20261116_145408_662903 | structured counters absent | 1.094x, existing best-numbers table | native: 12990 / 16 bytes |
| katran_current | 20261123_233751_015523 | 182.481459 / 175.118693 | 1.042044x | native: 9757 / 16 bytes |

Cilium best post-shim lines 1563–1564 and 1663–1664 explicitly fail both `cil_from_contai` replacements: instruction 32 has source immediate 0 and loaded immediate -559038242; the loader keeps the original BPF fds. App counters identify the active entries 351/369 as 1093/1720 bytes. Current lines 1675–1676 and 1759–1760 instead successfully install native entries 439/459 (1686/16). The historical 1093-to-current-1686 difference compares different execution modes. It does not show a native-body size regression, and there is no historical active native body from those failed installations to restore. The 1.348x remains a functional/hybrid result; this receipt supplies no reason to remove it.

Katran best lines 58–60 show an actual native replacement: 12990/16 versus current 9757/16, a 24.888% reduction. Both logs retain original BPF tag `90e1a12c30a4bce5`, native tag `59f4a931744dcdc6`, and source hash `0325eddd38cf33c9`. These identify the source/replacement path, not bytewise native equality. The best run's original host log, copied here byte-for-byte with SHA in comparison.json, confirms three 180-second samples, stats on, both arms/app ok, and the exact run directory. Its structured app JSON/metadata and installed byte payload are not yet located. The 1.094x is preserved from the existing best-numbers table; no counter values are invented.

The same-day shared/copy-hash diagnostic used runs 210136/210724 and native lengths 10546/12995. Those are not this best run. The May/Nov22 wrong-map call-order evidence also does not establish a defect in the Nov16 best run. Do not substitute either diagnostic for the missing historical payload.

`comparison.json` contains the full program lists (including zero-call and initialization programs), aggregate counters, source file SHA-256/size and numbered loader excerpts. No program/count filter or acceptance gate is used. Run `taskset -c 19 python3 kprog/results/best-code-comparison-20261127/compare.py` from the repository to reproduce it. The immediate remaining comparison is to recover the exact old Katran payload/proof and compare its helper/map path with current; code length and aggregate timing alone cannot assign causality to flags or the linker.
