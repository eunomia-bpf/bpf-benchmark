All 71 recognized AArch64 helper macros now call their own Linux helper with
the types in vendored `bpf_helper_defs.h`. This removes zero-return bodies and
five aliases that called a different helper or omitted arguments. Five further
IDs observed in the corpus are included: 20, 54, 87, 99 and 155.

Validation passes: Lean table identity, unique names and increasing IDs;
independent libbpf ID comparison; 73 table/boundary checks; and 142 typed ABI
checks with high-bit argument canaries and native-stack pointer projection.
The ABI checks verify helper identity, all arguments, result width/tag and
the wrapper's writes to simulator state. They do not establish native
caller-clobber, callback, context projection or original-map correctness.
Those remain active integration defects assigned to lane A.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile helper-abi-update
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile helper-contract-check
```

`helper-abi.json` in this directory records each exact signature.
The frozen snapshot and compressed command logs retain the tested inputs.
