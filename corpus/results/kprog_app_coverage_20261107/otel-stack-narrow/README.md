# Whole OTel application on the generic narrow-stack candidate

Actual `x86_kvm_corpus_20261107_202331_180002`, original whole-application startup and
workload through the common native-only generation/verifier/binding service.
The private header uses width-specific common memory primitives for8/16/32-bit
stack reads and writes. Aligned64-bit pointer storage and the existing
64-bit byte path retain their prior bodies. The production header remains47fb.

| Baseline application loads | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Further app entries remaining |
| ---: | ---: | ---: | ---: | ---: | --- | ---: |
| 14 | 3 | 3 | 2 | 0 | 1: exploration limit | 11 |

The candidate reaches1,000,001 explored verifier instructions against the
1,000,000 limit; max_states_per_insn46, total_states75,937 and peak_states2,460.
The earlier production header batch also binds two entries and reaches the
exploration limit. The candidate therefore stays private and the common
representation repair queue continues. All14 application entries remain in the
required completion set, and native matching-work measurement follows startup.

The636,928-case generic byte oracle passes under UBSan. Every actual request
source-identity record carries candidate header `369210a17590754be8c7061864f68d706b9cd8703490b30cc2c52bb169fb58d8`. The outer source pins
retain their production bytes; candidate.h and the inside hash record describe
the private guest mount. All three terminal archives and kernel-owned input
identities are preserved. Bootdf7a92936b41 and image1ead525666cc carry the
coherent BTF epoch. Four guest vCPUs/12GiB on20–23, one sample and duration two
seconds retain the original application/workload/native input/Clang flags.
App/metadata status is error and the outer driver records exit0.

coverage.json preserves raw work/counters, request outcomes and launch pins.
service.tar.gz and result.tar.gz preserve the original complete service/kernel
and corpus trees. launch.tar.gz and collection-evidence.tar.gz preserve private
header/source/command/byte-oracle and collector histories. Closed experiment
image tar and guest disk are retired. Universal simulator/token/link laws carry
the safety argument; these files record generic-mechanism runtime observations.
