Resident x86-64 static census

The 549-instance resident cohort contains BCC 25, Katran 1, Cilium 72, OTel 13, Tracee 151 and Tetragon 287. Every instance retains its original program ID, load context and available inventory/map records. The first five baseline cohorts come from coherent-six-app-runtime; Tetragon uses its retained 287-instance baseline.

The [ranked actual stock table](ranked-failures.md), [complete rows](stock-results.json), stock-raw.tar.gz and requests/ contain the completed initial pass, published in a45526c7d. Its actual stages are 275 manifest selection gaps, 153 maps/BTF prepare outcomes, 85 source ELF open outcomes, 23 ELF symbol-grammar outcomes, 7 installed, 4 verifier scalar-memory rejections, 1 compilation outcome and 1 context-lowering outcome. Totals: 12 generated, 11 compiled, 7 verifier accepted and 4 verifier rejected. Source maps/BTF use declared ELF resources and autoload=false on the common source-zero path. Native execution requests: 0.

The largest initial class, 275 Tetragon selection gaps, closes through three generic producer/input steps:
* [Actual resident-reference ELF metadata](reference-manifest/README.md), 271ddeee9, closes 241 gaps.
* [Credential-commit source-family completion](bprm-producer/README.md), 5dbd5d481, compiles the existing source incrementally.
* [Linked source-library metadata](linked-source-manifest/README.md), 8922e4bde, includes the loader's eight observed default CEL bodies, 128 bytes, through bpftool linking before the existing reachable-function scan.

All 549 instances now select a unique native entry. The existing three manifest tests pass; incremental credential-commit and CEL-library compilation both finish with exit 0. Source selection and compiler receipts retain their own stages.

[The static continuation](linked-static/README.md), 6d6c21f53, submits the 275 newly selected instances and retains the other 274 initial actual rows. It reuses the immutable 4f5b7ae6d model and completed S17/S18 stock runtime. Its successor table, complete rows and raw requests publish in linked-static/ on completion. The original table remains available above.

Run/build/cache data live under /var/tmp/kprog-tmp/A. The deferred ARM application successor was cancelled before launch; existing ARM work finishes its current cohort. First-attempt stock setup and preparatory compiler records retain their separate archives. Closed initial stock request/compiler copies were retired after matching their published raw archives; the shared model and runtime remain available to the continuation.

Resource and metadata follow-up: [local entry compatibility](resource-local-entries/README.md), [maps/BTF resource view](resource-maps-only/README.md), [Cilium source references](cilium-reference-rebuild/README.md) and [numeric ELF identities](elf-numeric-names/README.md). Each receipt states its reached phase; initial kernel outcomes retain their source epoch above. Failure labels in the ranked table are refined from the same captured initial diagnostics, with every initial stage/count retained.
