# Katran: private complete-register storage epoch

Actual `x86_kvm_corpus_20261107_212000_496498`, whole Katran startup with the existing workload,
registered native-only producer, kernel-owned original native inputba252e0372d1,
12GiB/eight guest vCPUs on20-23, one sample/two-second workload.

| Baseline app loads | Feature probes | Generated | Compiled | Bound | Specialization errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 5 | 1 | 1 | 0 | 0 | 1 |

The captured private volatile low8/high8/16 register-write include passes100448MOV
host/UBSan cases. Its actual trusted compiler command uses the captured CLANG
wrapper and include SHAad3b3e39ea65e459dc5d3a20902d33738457e965c3c16c56c9c790e4134562d3.
The earlier partial pointer-register mask rejection closes. The next verifier
error reaches instruction5920: a variable offset added to a map-value pointer
has an unbounded minimum. The log records3089processed instructions, maxstates2,
total/peak111. A known-zero scalar register's partial byte store and full-width
reload lose the verifier's numeric range in this representation. The next generic
candidate selects the existing scalar write representation using the existing tag
and reserves the complete volatile representation for pointer-tagged values.

Production register-write source retains its captured body. This private result
records app status error and source drift[]; coverage.json keeps
all work/request/source identities. service/result/launch archives preserve the
whole application and exact compiler/include sources. Collection evidence retains
all baseline PID/TID receipts and the existing feature classifier. Closed image
export and guest disk are retired. Matching-work timing follows full startup;
universal simulator/token/link laws retain the safety responsibility.
