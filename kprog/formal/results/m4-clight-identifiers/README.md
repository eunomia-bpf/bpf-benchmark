# Clight identifier freshness repair

M5's attempt to prove real function entry exposed an M4 frontend defect in
`dec7e3a19`: the generic ARM dispatcher declared `op` both as a parameter and
as a temporary in chunk 98. A kernel-checked theorem proves the required
`FunctionEntry2` disjointness proposition false for that actual export. The
successful historical query and its input remain under the raw path below.
There was no valid C procedure entry to assume for that export.

CompCert's canonical atom mode reserved only numeric IDs 128 through 4095 for
fresh temporaries. The handler has 11,870 temporaries. Allocation continued
past the gap and hit real named atoms: `op` is 5720, `sp` 5724, `lr` 5845,
`sk` 5404 and `cb` 4812. The normalizer also ignored pre-existing locals outside
that reserved interval when choosing its next ID. A larger arbitrary fixed
interval would retain this defect for larger functions.

The existing clean fork now maintains an exclusive upper bound over actual
named atoms, starts canonical fresh allocation there, and starts normalization
after every existing parameter/local/temporary. The obsolete fixed interval
and its filtering logic are removed. This uses the original CompCert positive
identifier space and preserves named canonical IDs across translation units.

The Lean identifier encoder also used an alternate general escaped encoding
for all characters. That was self-consistent for named identifiers alone but
did not retain the CompCert values alongside numeric temporaries. It now uses
the canonical compact ASCII classes from `Camlcoq.pos_of_string`, retaining
six-bit letters/digits/underscore and the escaped byte case. The exporter can
keep its existing named definitions while retaining the actual CompCert IDs.
The fork's `CanonicalIdentifiers.lean` pins all encoding classes and the five
real overflow aliases to independent numeric values, using kernel decisions.

`make clight` regenerates all 23 exports in place and passes the existing
host, ABI, producer and compile subsets. Their temporary values intentionally
change; the historical unchanged-AST receipts describe their own earlier
comment-only step. The canonical simulator C and frozen benchmark paths do
not change. The largest export remains below 50 MB. No image, base, kernel,
PERF tool or native compiler route is published by this repair.

The next M5 call proof checks the actual new dispatcher declarations and proves
entry for arbitrary memory, ignored argument values and flags bytes. Its
successful entry is the positive regression for the old refusal, rather than
an extra assumption. The actual body and checked LNSym NOP correspondence are
rebuilt against the regenerated program. This repair adds no complete handler
refinement or O1/O2/O4 migration count.

Final build, existing Lean layout/link oracle, codec and axiom commands are
recorded with this receipt. Raw diagnostics and all earlier bounded failures
stay at `/workspaces/kprog-raw/formal/m5-arm64-procedure`. M5 representation,
free-list, control and remaining theorem obligations continue before M6 and
the final whole-package checks.

Final validation passes all 23 Clight exports and seven proof modules (140
Lake jobs), all seven existing Lean metadata/layout/link oracles, the canonical
codec regression and 15 actual axiom queries. The ARM links each retain 136
internal bodies; x86 helper/read composition retains 117. All queries use only
standard Lean axioms, with the procedure relations additionally exposing the
existing opaque `CC.externalFunctionsSem` and `CC.inlineAssemblySem`. No new
axiom, admission, native checker or external determinism assumption. Source
comparison against `dec7e3a19` confirms canonical C and frozen paths unchanged.
Checks ran on CPUs 17–19, Lean -j1/32 GiB AS/default proof limits.
