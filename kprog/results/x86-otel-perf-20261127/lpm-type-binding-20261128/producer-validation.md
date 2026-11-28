# Actual LPM map-kind producer and complete host validation

Compiler/linker consumer cff33039a passed14 tests. The actual loaded MapMeta type now serializes `lpm_trie` into the existing lookup-map plan. This applies to every LPM map, with no app/program name or flag selection. The loader's existing map/helper target binding remains intact.

Current-source worker1223735 completed0. The existing independent bitwise oracle executed2,191,656 cases against C-imported machine code and the shared source, with sole-kernel BTF layout. Cases cover fixed/dynamic/mixed/unknown map facts, empty roots, prefix limits, intermediate flags, byte order and guarded payload boundaries. Actual `native_loader_shared` compiled both source units and linked/stripped successfully; exact compiler/linker/SO sizes and SHA are in oracle-loader-controller.json and were rechecked against the current products.

| Shape | Cases | Generic calls |
|---|---:|---:|
| fixed | 112917 | 0 |
| dynamic | 692913 | 0 |
| mixed | 692913 | 692913 |
| unknown | 692913 | 1385826 |

The successful14-test build and consumer files were unchanged. The final retry fixed only the fixture's Clang driver invocation to the existing vendor `-Xclang -fembed-bitcode=all` form; earlier setup failures remain recorded. No successful guest/test run was repeated to seek a better number.

The complete host RAW, including14 fixture products, reports, generated facts, assembly and logs, is archived in host-validation-raw.tar.gz with full file/SHA/size/fileset verification. Publish first, verify Git blobs and original files again before removing the redundant RAW copy. This is host semantics and loader build acceptance; current image c103 and its0.990618681x diagnostic are unchanged. The next step is a sole-image replacement with unchanged kernel/P inputs and one frozen10-second work-observed application check.
