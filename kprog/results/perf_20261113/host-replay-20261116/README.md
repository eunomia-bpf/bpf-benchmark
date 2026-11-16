All 475 canonical native entries pass proof extraction. Kernel emission passes 70 of 76 retained load plans. All six failures are older Tracee plans missing `kernel_layout`; those plans have only version/helpers/maps/lookup_sites/lookup_maps/update_sites. They predate the current loader layout metadata. The failures and original plans stay in the raw directory. No missing facts were guessed.

| App | Entries / proof passes | Plans / emission passes |
| --- | ---: | ---: |
| BCC | 34 / 34 | 25 / 25 |
| Cilium | 80 / 80 | 28 / 28 |
| Katran | 3 / 3 | 1 / 1 |
| OTel | 30 / 30 | 14 / 14 |
| Tetragon | 154 / 154 | 2 / 2 |
| Tracee | 174 / 174 | 6 / 0 |

Command: `make -r -f kprog/test/native-corpus-replay.mk replay OUTPUT=/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication`. Controller 1501560 is terminal, Make 2. Source tools and current producer P were used on CPU 16 with 16 GiB AS under imageSH; the published image was unchanged. Every same-name captured request is retained separately, and Cilium plans from other translation units are listed separately.

This is host extraction/emission, without kernel execution or B stock acceptance. Only 69 entries have a retained same-source emission plan. In particular, Tetragon's two retained requests do not cover generated CEL callees, and old captures do not contain the new original-func-info sidecars. Whole-app install and fresh Tracee load facts remain to check; 475 static proofs do not establish them.
