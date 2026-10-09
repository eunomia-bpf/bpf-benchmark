# ATC'26 paper data and regeneration

This bundle preserves the data used by *BPF-Ext: Safely Extending the eBPF
Compilation Pipeline with Native Operations*, the ATC'26 camera-ready body
associated with arXiv 2606.24213 v1. It pins the current
[paper repository](https://github.com/yunwei37/atc26-kinsn-camera-ready) at
`22810b78eb2b24b1ad5cecfd9e07329f5af9ac10`; the supplied October 7 inventory
used `d6c50f83dca5298b0f5f7f639f66f6ed5d4e53fa`. Wording edits between those
snapshots are mapped to current file/line references in the generated report.

From the bpf-benchmark root, regenerate and verify everything with:

```sh
make -C kinsn/paper/atc26
```

From this directory, the command is `make`. It uses local inputs only and
runs no VM, application, benchmark, or data collector. Dependencies are Python
3.11+, the packages pinned in `requirements.txt`, and `pdflatex` with TikZ,
standalone, and Latin Modern. Install them once, for example:

```sh
python3 -m pip install -r requirements.txt
# Debian/Ubuntu:
sudo apt-get install texlive-latex-extra texlive-pictures texlive-fonts-recommended lmodern
```

`data/` holds exact copies of nine micro and eight corpus result directories:
**77 files, 15,224,080 bytes (14.52 MiB)**. Every file was compared byte for
byte with its original; the originals remain at their existing paths. Nothing
in `data/` is generated or edited by `make`. Historical metadata retains its
original paths, statuses, and unknown source/kernel commits.

`inputs/paper/` contains the pinned body, tables, figures, helpers, and the
separate October `revision/`. `inputs/audit-paper/` preserves the earlier
LaTeX snapshot used by the audit calculations. `inputs/inventory/` preserves
the supplied claim inventory, summary, dependency list, and recomputation
expectations. The full 4,526-run statistical inventory is outside this
17-directory paper bundle; it is not a paper performance input.
`inputs/idiom-disassembly/` holds the related March disassemblies needed for
the five-probe expansion calculation. The original plotting sources are
preserved as text under `scripts/upstream/`; `metrics.py` adapts the audit's
calculations to `data/`. The final 27-case and combined policy generators
were not retained upstream, so `plots.py` reconstructs those final populations
and verifies every bar against the published PDF geometry.

The command writes:

- `output/figures/`: four result PDFs (two-panel characterization, x86 and
  ARM64 micro, four-point Cilium/Katran policy) and three illustrations.
  The current design pipeline is compiled from its inline TikZ. The eBPF
  pipeline and JIT-dump illustration are re-emitted from authoritative PDF
  sources with identical rendered content; their original exporters/dumps
  are not retained. This reproduces the illustrations without asserting
  independent evidence for their instruction counts.
- `output/tables/`: all 11 retained body table sources, including the four
  active tables (workload list, ISA gap, operations, kernel LOC), the
  recomputed characterization summary and two retained evaluation tables.
  Authored lookup/count tables are source reproduction. The unused
  case-study ladder table remains an archived declaration: its extra data
  belongs to a different campaign and is not substituted for the body.
- [Numbers report](output/numbers.md), [CSV](output/numbers.csv), and
  [fresh metrics](output/metrics.json): printed values, fresh calculations,
  conventions, differences, and every missing-evidence claim, including all
  October EC2 numerical revision claims.
- [Provenance](output/provenance.md) and [JSON](output/provenance.json): for
  each directory, original path, first addition commit (following renames
  with `git log`), recorded date/platform/CPU/source/kernel, and claims with
  current paper files and lines. Use a full Git clone to regenerate history.
- [Figure comparison](output/figure-checks.md), its per-bar JSON, generated
  point arrays, and table checks. These compare content, not typography.

The raw-supported micro, code-size, Cilium, Katran, native, BPF-cost and
characterization results regenerate. Unsupported empirical claims remain
explicitly unsupported: site counts, loader object counts, the recognizer
load-time range, exact ISA/rotate counts, historical implementation LOC, and
all October EC2 measurements. Reproducing an authored table or PDF does not
turn those declarations into regenerated measurements. The paper and raw
data are never corrected by this bundle.

## Paper-to-data map

All names below retain their original spelling. The original location is
`micro/results/<name>` or `corpus/results/<name>`; the local copy is
`data/micro/<name>` or `data/corpus/<name>`. The generated provenance expands
this map into individual claims and exact file/line locations.

| Local directory | Use in the paper |
| --- | --- |
| `data/micro/x86_kvm_micro_20260526_210952_650695` | §3 x86 characterization; `sec-3-4config-percase.pdf`; summary table; 1.55/1.57/1.53x and faster-case counts |
| `data/micro/aws_arm64_micro_20260523_091516_610343` | §3 ARM kernel-native path; characterization figure; 1.88x and size ratio |
| `data/micro/aws_arm64_micro_20260520_052452_727433` | §3 ARM userspace native/LLVM paths; characterization figure; 1.98/1.92x |
| `data/micro/x86_kvm_micro_20260519_114214_364050` | §6 RQ1 x86 kinsn candidate; x86 micro figure; 1.241736x and 0.771807 size ratio |
| `data/micro/x86_kvm_micro_20260526_210351_224315` | §6 RQ1 x86 stock baseline, paired with candidate |
| `data/micro/aws_arm64_micro_20260606_001225_821028` | §6 RQ1 ARM micro figure; 1.222042x; 0.879116 size ratio; 308/308 and 924/924 sites |
| `data/micro/x86_kvm_micro_20260429_035938_203074` | The historical 62-program load-time population, not the 27-case runtime population |
| `data/micro/x86_kvm_micro_20260514_031744_210343` | §6 load-time comparison, first campaign |
| `data/micro/x86_kvm_micro_20260514_181806_133778` | §6 load-time comparison, second campaign |
| `data/corpus/x86_kvm_corpus_20260604_070210_639497` | §6 RQ2/RQ3 full Cilium counters; 1.009 paired BPF-cost ratio |
| `data/corpus/x86_kvm_corpus_20260604_100557_313063` | §6 RQ2/RQ3 full Cilium throughput; 1.074262x; policy figure/table |
| `data/corpus/x86_kvm_corpus_20260604_232313_992341` | §6 RQ3 tuned no-bulk Cilium counters; 1.062 paired BPF-cost ratio |
| `data/corpus/x86_kvm_corpus_20260605_004607_636479` | §6 RQ3 tuned no-bulk Cilium throughput; 1.113903x mean / 1.118935x median |
| `data/corpus/aws_arm64_corpus_20260605_080836_924256` | §6 RQ2/RQ3 conservative Katran; 1.072760x throughput / 0.941 BPF-cost ratio |
| `data/corpus/aws_arm64_corpus_20260605_094729_221231` | §6 RQ3 coverage-max Katran; 0.994743x throughput / 1.006 BPF-cost ratio |
| `data/corpus/x86_kvm_corpus_20260529_033517_489159` | §6 RQ4 Cilium native counters; 488.676 → 262.298 ns/run |
| `data/corpus/x86_kvm_corpus_20260529_040554_604387` | §6 RQ4 Cilium native throughput; 2.357974x and native-gap calculation |

The report explains the 0.99 load-time field mismatch, tuned mean/median
mismatch, 5.4% rounding, Core Ultra/Xeon mismatch, sampling and BPF-stat
conventions, missing report streams, and October revision evidence gaps.
Analysis stays here, outside the measurement framework.
