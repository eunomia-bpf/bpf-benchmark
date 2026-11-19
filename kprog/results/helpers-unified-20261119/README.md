# Image and six-app check after the helper unification (2026-11-19)

Coordinator batch: run.sh builds the sole image with the frozen recipe and runs the six-app check (kprog/perf/one-image/Makefile image, check) after ded33d751 and 5319f359d. Raw: /workspaces/kprog-raw/coordinator/helpers-unified-20261119.

## Results

| Image (source) | OTel | BCC | Cilium | Tetragon | Tracee | Katran |
|---|---|---|---|---|---|---|
| 8da10d1eb (first helper form) | 0 / 14 | 25 / 0 | 135 / 0 | 207 / 81 | 167 / 2 | 1 / 0 |
| 3e99eaa1e (OTel, Tetragon, inline-read fixes) | 14 / 0 | 25 / 0 | 135 / 0 | 288 / 0 | 169 / 0 | 1 / 0 |
| a0b2bbb7d (Katran by name, linker helper-id path removed) | 14 / 0 | 25 / 0 | 135 / 0 | 288 / 0 | 169 / 0 | 1 / 0 |

Cells are native replaced / native-loader failed, one-image check, all rc=0. Last batch: runs
x86_kvm_corpus_20261119_184017_830153 .. x86_kvm_corpus_20261119_185642_683924. The batch script is removed
after its last run (coordinator decision 2026-11-19, audit 20261119T15Z item 4).
