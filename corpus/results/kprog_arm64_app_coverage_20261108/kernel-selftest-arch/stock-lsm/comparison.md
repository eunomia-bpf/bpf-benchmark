Original LSM load comparison on paired kernels

| ISA | Path | Program | Stage | Target BTF | First argument |
| --- | --- | --- | --- | ---: | --- |
| ARM64 | original stock BPF | no_null_check | installed | 70008 | file |
| ARM64 | original stock BPF | null_check | installed | 70008 | file |
| ARM64 | native source0 | no_null_check | installed | 70008 | file |
| ARM64 | native source0 | null_check | installed | 70008 | file |
| x86-64 | original stock BPF | no_null_check | load_rejected | 71327 | file__nullable |
| x86-64 | original stock BPF | null_check | installed | 71327 | file__nullable |
| x86-64 | native source0 | no_null_check | verifier_rejected | 71327 | file__nullable |
| x86-64 | native source0 | null_check | installed | 71327 | file__nullable |

Original annotations remain the expectation, so ARM no_null_check keeps its installed-disagreement stage. The ARM stock baseline now independently observes the same installation, at5instructions; null_check installs at7instructions. Both cases use original object62eb52c9 and target70008. Matched x86 stock/native source a3e3e0f9 uses target71327/file__nullable and rejects the same failure annotation. Each captured Image/BTF epoch retains its own scope. The generic P/B physical memory-fault relation remains an independent design obligation.

All rows are load-only. Original kernel selftest source and runtime qualifiers retain their published bytes. The metadata-alignment case in the adjacent probe-memory report awaits coordinator/operator disposition.
