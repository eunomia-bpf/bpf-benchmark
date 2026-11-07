# Fresh actual BCC proof artifacts with exclusive markers

All23 captured real BCC entries generate and compile with the current ARM
simulator. The old syscount/sys_exit proof has zero exclusive-failure markers;
the fresh proof has exactly two, at source PCs0x148 and0x1a8, matching both
STLXR instructions. The original native object bytes are unchanged (SHA256
comparison retained). This repairs the concrete missing-marker artifact from
runtimev11, not a demonstrated verifier or application admission.

The stager now preflights all23 complete native/proof/simulator triples before
copying them and replaces only matching full-BTF/type/bytecode-length selectors.
Nine other startup selectors remain byte-for-byte unchanged, so the manifest
still contains32 entries. No program was removed to make the application run.
The prior manifest, current manifest and selector audit are retained.

The private runtimev12 image/root build and actual BCC two-start QEMU run
completed. The application still fails during startup: six loads replaced,
four verifier failures logged, no native workload phase. The exact sys_exit
load is not reached. Full raw result: ../bcc-runtime-v12/README.md.

Rebuild with the dated Makefile's bcc-real-generate, compile and
bcc-real-manifest PHASE=NEW_PHASE. The archive includes all23 native/proof/source
inputs, compiled objects, frozen simulator contracts, compiler outcomes and
both manifests. Workload/framework/ISA semantics were unchanged.
