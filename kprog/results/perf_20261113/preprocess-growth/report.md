# Current scale preprocessing attribution

Measured 2026-11-15 with the current generator, ordinary-input header and real stock-path Clang `-E` flags. Eight cases completed successfully under an 8 GiB address-space limit on CPUs 8–11 while the isolated A/A guest used 0–7. Canonical products replace `/var/tmp/kprog-tmp/perf/scale`; commands, resource records, disassembly and logs remain in `/workspaces/kprog-raw/perf/20261115-preprocess-growth/baseline`.

| Case | Generated C bytes | Preprocessed bytes | Expansion | Switch tokens |
|---|---:|---:|---:|---:|
| n100_scalar_direct | 12,266 | 3,965,651 | 323.30x | 1,055 |
| n100_scalar_indirect | 13,479 | 4,026,273 | 298.71x | 1,075 |
| n100_ptr_direct | 16,499 | 9,859,911 | 597.61x | 3,005 |
| n100_ptr_indirect | 17,712 | 9,925,749 | 560.40x | 3,025 |
| n1000_scalar_direct | 106,317 | 30,517,198 | 287.04x | 8,705 |
| n1000_scalar_indirect | 107,530 | 30,599,504 | 284.57x | 8,725 |
| n1000_ptr_direct | 148,688 | 89,515,778 | 602.04x | 28,205 |
| n1000_ptr_indirect | 149,901 | 89,650,200 | 598.06x | 28,225 |

The scale cases do not expand a helper dispatcher per instruction. Each has the same five background helper-like names: one declaration each of tail-call and three numeric-iterator helpers, and two context-cast occurrences. The current generator already selects static helper calls. This corrects the proposed helper-dispatch attribution for these inputs; the older OTel helper-expansion observation remains a separate historical measurement.

For 1K scalar/direct, ALU_IMM contributes 23,220,849 bytes and IMUL_IMM 5,536,500 bytes. For 1K pointer/direct, MOV_LOAD contributes 57,596,255 bytes and ALU_REG 28,947,757 bytes. A single MOV_LOAD expands to 114,508 bytes. Repeated GPR read/tag/write dispatch is a concrete next reduction target.

Scope: fresh generation and preprocessing only. No B backend compilation or kernel submission was performed, and existing canonical `.bpf.o` files were not rebuilt. These small sources fit a single production piece; the measurement does not include the joined-piece pragma. This does not establish a repaired 10K/100K compilation, stack acceptance, native speedup or capacity. The stopped large jobs remain stopped.
