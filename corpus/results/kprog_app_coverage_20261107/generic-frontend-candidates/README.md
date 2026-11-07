# Generic frontend mechanism candidates

These observations exercise common ELF data extraction and stack-memory
semantics. The fixture objects hold data sections and symbol records. The
stack fixture exercises the common read/write helpers over the full valid
128-byte arena window. Universal simulator/token/link theorems carry the safety
argument; these finite measurements support the mechanism implementation.

| Mechanism | Observations | Candidate outcome | Runtime work remaining |
| --- | ---: | --- | --- |
| ELF readonly bytes and object symbols | 88 data fixtures, 22 lengths, four layouts | Exact section bytes and object payloads in every fixture | Adopt in the next source epoch and run application batches |
| Narrow stack-memory read/write | 636,928 width/offset/seed combinations under UBSan | Zero read differences and zero write-window differences | Complete the queued whole-OTel application run |

The existing text dump reader produces 40 differing outcomes across the 88
fixtures. Hexadecimal ASCII display text can add bytes to its section stream;
ordinary anchor symbols can enter its extent loop. The candidate consumes
binary ELF section bytes and STT_OBJECT records, using A's shared design and
the existing pyelftools dependency. A crossing object extent raises ValueError;
an object carrying another section produces an empty readonly dictionary.

The stack candidate retains the aligned 64-bit word path and the existing
64-bit byte path. Widths8/16/32 use the common width-specific memory load/store
primitives. The byte oracle covers widths0/8/16/32/64, every valid offset and
1024 deterministic seeds, and compares the entire write window and surrounding
bytes. The initial host build reports an include-directory error; the corrected
build uses /usr/include/bpf and passes. Both build histories are retained.

Production generator019e95d2 and simulator header47fb stay captured through R's
current registered-service epoch. The candidates remain in private state.
The module-refresh application queue3653317 runs first; the whole-OTel
candidate queue3653318 follows it, using12GiB and the existing two-start
workload through the common registered service. Application coverage, accepted
bindings and matching-work counters will come from that actual runtime batch.

raw.tar.gz retains both source versions, exact candidate patches, data fixture
objects, generic harnesses, commands and terminal outputs. observations.json
records the counts, source identities and archive SHA. The common source paths
retain their published production bytes at collection.


The binary ELF readonly reader is now the production x86 reader. Its complete
source SHA equals the candidate in the preserved88-fixture matrix and raw
archive. Section bytes and STT_OBJECT records provide the data and extents;
existing bounds errors remain explicit. The narrow-stack body candidate stays
private, with its whole-OTel outcome preserved separately. New whole Tetragon
and helper-preserving Tracee application batches capture this reader and the
affine stack-origin analysis at their actual start.
