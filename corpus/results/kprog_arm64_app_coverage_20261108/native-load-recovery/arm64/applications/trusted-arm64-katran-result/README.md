Katran on the ARM native-load recovery runtime

Whole application9a8d5d925 completes generation, compilation, stock verification and native installation1/1, with Make/guest/QEMU/compiler exits0. Both workload phases complete. Exact private f1/e5Image/module/worker/linker and original native bytes accompany the raw archive.

| Phase | pktgen packets | BPF calls / total | TX / VIP / LRU | PASS | Receiver packets |
| --- | ---: | ---: | ---: | ---: | ---: |
| JIT | 22881 | 22881 | 22881 | 0 | 22881 |
| Native | 18288 | 18289 | 18288 | 1 | 18289 |

Native total18289 equals18288TX+1PASS; the PASS counter carries70bytes. Each phase records lru_miss packets0 and interface drop/error counters0. Complete LRU field pairs, timer fields, per-real counters and before/after snapshots remain in work-counters.json. Duration-driven phase totals retain their measured values. The captured cohort uses one pktgen worker/flows0/SHARED; R owns the restored05-29four-worker/65535flows/!SHARED performance workload. This QEMU record supplies functional observations at its captured recipe. Runtime admission additions:0.
