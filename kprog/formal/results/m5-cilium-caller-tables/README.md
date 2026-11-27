# Actual caller pointer tables and original slot30 initializers

The complete caller's actual795-local allocation supplies the two31-pointer
arrays and X30 union/tag locals. Both arrays have248Freeable bytes;the
arrays and cell blocks are distinct by original local identities. Their
slot30(offset240) write permission follows from the reached access map
and same actual allocated range.

The original word/tag initializer statements are extracted uniquely from
exported source parts9294/9292. Kernel equality checks each complete typed
statement. Existing CompCert EvalExpr/EvalLvalue/Step.assign execute each
initializer with its exact supplied continuation and unchanged temporary
environment. Same-store pointer readback,caller frame,all non-table block
loads,access and allocation frontier are derived. No successful-reader or
successful-store premise is supplied;no source fixture or new interpreter
is used.

These are independently checked actual statement fragments. Full62-row
initialization,program-order composition through the real prologue,entry
reachability and ordinary LINK table reads/word/tag stores remain work.
The separate borrowed cells are never identified with dense Addressing
memory. No initializedSP/native/universal O1/O2/O4/M6 claim is made.

Validation.json and compressed direct/focused/default-root/7query logs retain
original CPU17/j1/nice0/32GiB/SH timing/heartbeat200000/recursion512. The real
relational CompCert rules avoid an interpreter-expression unification depth
failure without raising limits. Full also uses EX formal-full-check.
V owns makecheck;all earlier attempts remain raw.
