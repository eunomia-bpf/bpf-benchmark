# Equality-edge PHI folding

Fresh OTel perf_unwind_stop reaches stock verification with a nullable
apm_int_procs lookup result. The frontend computes its sign before testing for
NULL, preserving that sign only through the NULL incoming edge of a later PHI.
The stock verifier rejects the eager right shift of this pointer.

The normal B compiler now substitutes the exact branch equality while
simplifying each PHI incoming expression. LLVM's strict simplifier supplies
the constant; the original predicate and other incoming edges stay intact.
This applies to integer constants and NULL pointers, for equality's true edge
and inequality's false edge. A conditional branch sharing both successors
keeps its original value. Shared interpreter C and checked-native frontend
semantics stay as recorded by their original inputs.

The old published compiler fails the focused regression (control.txt). The
candidate passes30 host boundary comparisons across five functions, alongside
the existing60 packet/identity observations, context width/provenance checks
and the normal whole-word backend comparison. The actual archived OTel
frontend folds one incoming expression (archived-frontend.json). Actual stock
acceptance and whole-app output remain the next observations.

Production change31lines; regression52lines. The regression covers both
comparison directions, a nonzero integer equality, the opposite edge and
coincident successors. Raw commands and all outcomes stay under
/workspaces/kprog-raw/perf/20261115-equality-edges/.

Published18:34:22Z through bounds-single-publish under imageEX, replacing the
sole base packet-bounds with a7d9ab49. Current imagefc5336c2 and kernel099 stay
installed; the external registered service selects this base compiler for B
generation. The image's bundled compiler remains its recorded1965 version.
Fresh checked OTel retry2 launcher1155245 started18:34:45Z on16-19/imageSH,
2vCPU16GiB/32GiBAS, using the existing checked-corpus target. Full raw evidence
is /workspaces/kprog-raw/perf/20261115-otel-current-app-retry2/.

Actual retry2 perf_unwind_stop now verifies as program31 and checked-installs34
at18:36:33Z. Its B has202088 executable bytes, and the real compiler folds one
incoming expression. read_task_struct verifies24/installs27. Startup advances
to perf_unwind_native; both attempts stop at MIR spill lowering's handling of
`dead $w2 = LDW32 %stack.35, 0`. The full run then completes Make0/app error.
Closed-request observations are in otel-current-app/retry2-progress.json;
application output/equal-work/performance remain open.
