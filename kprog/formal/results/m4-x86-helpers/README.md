# Typed x86 helper C roots

`c/X86Helpers.c` expands all 81 canonical helper macros with caller-owned
register state, arena/fact references and capacity. Callee parameters use the
actual public libbpf signatures; the ABI oracle checks each against the pinned
declaration. There is no new helper implementation or runtime ID dispatcher.
Register observations reuse `X86Pointer.c`; tag reads use the canonical output
body. The three void ring-buffer forms retain their original native expression
expansion and use a statement adapter under CompCert, as on ARM.

The export has 83 internal functions/8,069,666B, including its private width and
tag functions. Exact re-export passes; all 17 earlier artifacts remain identical
to `768241403`. `make clight` and all 18 Clight modules/55 Lean jobs pass without
raising limits. The mature linker resolves the actual helper/read modules and
preserves all 117 internal bodies. Six axiom queries use only
`propext`, `Classical.choice` and `Quot.sound`. Parsing, linking and these finite
checks are not refinement theorems.

Native and CompCert-adapter executions each check 5,832 paired registry cases
across capacities 1/7/9/64/200/376, three SP positions and four seeds. Every
comparison includes the complete register/environment state, private bytes,
fact cells and guards, helper identity/arguments, result/tag and input stream.
Independent checks cover typed result truncation, caller-saved clobbers,
preserved registers and the exact released-word/byte input count. Existing
public-ABI capture functions provide helper observations; they do not model
kernel behavior.

Twenty additional output-alias/refusal executions form ten pairs. The callee
copies overlapping bytes, changes live argument cells after observing the
original arguments, and either returns or leaves through `longjmp`. Sizes
0/1/8/9/256 test zero-length, overlap and full u32 length capture. Complete state
and buffer comparisons check that invalidation uses pre-call arguments and
that a nonreturning call leaves the correct prefix. All private test storage
is initialized before reads. The first console summary combined executions
with paired comparisons; the final focused runs report the two counts separately.

Each mode retains 18,156,960B of raw registry frames. Comparisons occur within
each process at the same addresses; cross-process raw pointer bits are retained,
without masking or a claim of identical capture files. Six runtime negatives
catch fixed capacity, wrong fact references, low8 output lengths, wrong void
results, missing XMM clobber and swapped map-update arguments. A seventh negative
rejects the wrong callee return type at compilation. Normal products are rebuilt
and rechecked after mutations.

Historical/current default BPF allocated sections and relocations match, and
streamed current matches ordinary compilation: helper fixture socket 1,632B/
one relocation, inline fixture 1,448B/11 relocations and producer frame 376
fixture 5,184B/24 relocations. The header baseline is `768241403`; all phases use
the current fixture source. These are compile fixtures, not stock verification
or application performance. Extraction preprocessing is 1,257,141B. All raw
commands, failures and captures remain under `/workspaces/kprog-raw/formal/m4-x86-helpers`.

Reproduce with `make clight`, the Clight Lake targets, and
`lake env lean -j1 oracles/test_x86_helpers_link.lean`. Run
`results/m4-x86-helpers/compare.py --output <new-raw-directory>` for the complete
binding and mutation checks. Native replay uses `tools/compare_c_header.py`;
its exact commands and the nested-header retry are retained in raw data.

The real ID-selected kernel target, external effects and native/Clight memory
relation remain M5 obligations. These roots do not bind arbitrary producer
entries/return tables or establish whole-default byte coverage. M4 remains open;
all 2,065 M5 refinements and O1/O2/O4 recounts precede M6 retirement and final
whole-library `lake build` plus `make check`.
