# Common LPM type consumer validation

The common LLVM compiler and native-link release build succeeded on the current source. All14 native-link tests pass, including no frozen scalar, actual15-byte map identity, retained map/ABI and exact15/long-prefix collision fallback. The fixture and re-proof use the normal helper link plan. Current-source hashes are in build-launch-20261128T031635Z.json; build.log/build.exit are the successful receipts.

The compiler/linker consumes the actual lpm_trie map kind using the existing C LPM implementation and boot BTF. Generic/ambiguous map bindings keep their helper; no app/program name or flag policy selects this lowering. Legacy lpm12 input names the same internal kind. The separate loader-header producer change remains under validation with the actual loader target.

The independent oracle has not run yet in attempt3: Clang rejected direct -fembed-bitcode with -mno-red-zone/-mllvm while compiling its fixture. Failure logs/controller are preserved. Its runner now uses the existing vendor/previous LPM recipe's -Xclang -fembed-bitcode=all form. Only the incomplete oracle/loader stage is retried; successful builds/tests and measurements are not repeated.

Current runtime image remains c103a86a, and its OTel diagnostic remains0.990618681x. This source validation is not installed performance acceptance. The next boundary is oracle/actual-loader validation, sole-image replacement and one frozen10-second work-observed check.
