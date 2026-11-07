# LEA real-CPU index, scale and width matrix

The captured LEA implementation passes196,608 real x86-64 CPU, C simulator and
canonical-reference comparisons:384 native forms, each through the numeric raw
dispatcher and direct specialized entry, with256 input states per route.
All768 groups receive canonical replay. Registers, vector state, modeled stack
bytes, architectural LEA flags and all256 memory bytes agree. All196,608 memory
observations preserve their incoming bytes.

| Address bits | Destination bits | Native forms | Route groups | Cases | CPU/C / CPU/reference / C/reference differences |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 32 | 16 | 64 | 128 | 32768 | 0 / 0 / 0 |
| 32 | 32 | 64 | 128 | 32768 | 0 / 0 / 0 |
| 32 | 64 | 64 | 128 | 32768 | 0 / 0 / 0 |
| 64 | 16 | 64 | 128 | 32768 | 0 / 0 / 0 |
| 64 | 32 | 64 | 128 | 32768 | 0 / 0 / 0 |
| 64 | 64 | 64 | 128 | 32768 | 0 / 0 / 0 |

The matrix contains360 index-only forms:15 legal SIB index registers, four scales
(1,2,4,8), two address widths and three destination widths (AX/EAX/RAX).
A further24 forms exercise a base plus index, RSP/ESP base, unit RCX/ECX base and
an aliased RAX/EAX base. Per-form and per-route counts appear in forms.tsv,
reference-forms.tsv and observations.tsv. Every mismatch stream is retained as
gzip; each contains zero records.

Each group uses the common128 boundary states and128 fixed-stream pseudorandom
states. The shared driver initializes memory-bearing registers for its observed
memory region and abstract RSP at0. RSP/ESP controls use that captured wrapper
frame. The original observer, full state layout and comparison masks retain
their source. Each of384 raw/direct pairs has identical native instruction bytes,
and the immutable captured encoder reproduces every encoded field set.

## Captured correction and production correspondence

Execution begins at source815df5cb2eb7b37f40151ab8ec878045cbc7ab12, with V's exact
154955ad9 four-file correction applied in a private source tree. Its producer
normalizes unit RCX indexing into the ordinary base encoding; its effective
offset helper uses unsigned64-bit addition before signed representation.
Two corrected files participate in the compilation snapshot: the encoder and
generated offset header. The other80 snapshot source files match the launch
Git tree exactly. The reviewer reapplies the exact archived correction and
reproduces all four resulting source hashes.

actual-compiled-inputs.tar.gz captures108 files and its JSON manifest pins each
byte identity. Ten derived Python cache files retain separate classification
from the82 source inputs. Source archives include generated C, native observer
assembly, decoded native instructions, selection logic and correction metadata.
The static x86-64 observer is published as cpu-differential-x86.gz.

C subsequently integrates the correction at afc178f46e725fe96f85694d76fcf4c45c842914.
production-interface.json establishes byte identity for all72 compiled C headers
and equality of all384 encoded forms and384 direct statement strings. Nine of the
ten captured Python modules match that production epoch; the producer's integrated
readonly ELF reader has its distinct full-source hash. This finite instruction
interface correspondence retains the actual launch/compilation epoch.

The launch-time production_adoption=owner_sync_pending field remains an original
run record. The later afc178f46 production correspondence appears in a separate
summary field. During compilation the live tree advances four paths: the main
simulator header, ABI analysis, producer and generated offset header. status.json
and summary.json retain both hashes for every live source change. The compiled
snapshot stays fixed at the captured identities above.

The later C main header6b3f31731d9d adds V's unsigned RSP rebinding sum. V's
8,192 full-frame wrapping observations and that later source adoption retain
their own provenance. This matrix observes the original47fb55656f29 main header
and its sampled stack-frame domain. Universal LEA/token/link laws remain with V/T;
these observations support the generic simulator mechanisms.

| Artifact | SHA256 |
| --- | --- |
| Main simulator header | 47fb55656f2951df3581f5fa1695f720138ae0ab1881ec1a21d359d0587fd34a |
| Captured encoder | 8a182de2e9cbb586d277edb97f6f1926b888648948bffb7347ece74f851724ad |
| Captured offset header | 6360c8f4ab21446bcb444d934a80986b9e205e5a6ba58e3d68eb7fd2fa68b190 |
| Correction gzip | 81ab3448a939d772b11418dff6ed3def8f46c8a34a60e452c7e3776ec70f64fc |
| Static observer | 30ee2c8aefa441024fd744c1d214c5c82e594cf7afa5317defecd886c5786dc4 |
| Frozen canonical reference | c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96 |
| Raw architectural stream | 10209ab817b40002d4c9327b80fd15ee34a669c23bb2eb821e79419d8bd22f78 |
| Compressed architectural stream | 41cb07c56165a730586453873d6558f9afc1da1c29906f86cbca83973408ee8a |

## Commands and archival

Original launch and collection commands, executed from /workspaces/repository
through bws.sh against the captured source epoch:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-lea-address-matrix/Makefile reference
python3 kprog/results/kprog_fidelity_20261107/differential/x86-lea-address-matrix/review.py
~~~

The detached wrapper in launch-inputs.tar.gz captures launch inputs, runs the
Make recipe and preserves the static observer and actual compilation sources.
Its final comparison exits0 at2026-11-07T21:27:30.097607Z. The long GCC build
retains its original process and sources throughout compilation. run.log.gz
preserves all raw-chain constant-narrowing diagnostics and final CPU/reference
counts. Final collection exits0.

The architectural stream occupies357,040,152 raw-equivalent bytes and115,004,060
compressed bytes. The wrapper verifies the decompressed SHA before retiring its
raw duplicate. trace-storage.json pins both identities. The compressed full-state
stream stays in the Workspace result directory. The source/static archives,
tables, diagnostics and scripts are published here.

The Make recipe uses the original producer/correction epoch and creates a raw
trace. The captured static observer provides direct instruction replay on an
x86-64 CPU; the retained source archives provide its exact compiler inputs.
The wrapper performs verified compression;
zstd -d -k cpu-states.bin.zst restores the saved raw stream when desired.
The reviewer reads the compressed stream directly and independently reconciles
all196,608 CPU/C state and memory observations against the per-form tables.
