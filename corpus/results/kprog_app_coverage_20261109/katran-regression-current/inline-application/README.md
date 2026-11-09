# Complete Katran with inlined native P

Actual original application startup and both work arms complete with statusok. The native request generates and compiles; its verifier reaches the return/callee-state equality arm and rejects R0 scalar memory access. This follows the earlier non-inlined stack -520 frontier. The source eBPF program remains active through failure, with original workload counters preserved. Source20a06f5f87cae003d10263a37ba57cf0d5ca63b2 and complete payload32dadc6b67094203f2ccaa41091700625f22e95d identify this replay. Original38 independently retains9valid executions/26verifier rejections/1generation rejection/2benign protected-read load-only findings.

| Native requests | Generated | Compiled | Installed | Verifier rejected |
|---:|---:|---:|---:|---:|
|1|1|1|0|1|

The collector now uses each actual archive name in its scratch output path, preserving earlier complete run archives. service.tar.gz/result.tar.gz and coverage.json carry every raw source/native/compiler/verifier/work record.
