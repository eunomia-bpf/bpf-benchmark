# x86 store-selector source checkpoint

Status: source prepared; checks await the active18:52 Katran timing window.
No new Lean AST, test success or byte comparison is claimed in this checkpoint.
The queued recipe and its eventual outputs stay under
`/workspaces/kprog-raw/formal/m4-x86-store-selectors`.

Six store selectors share declaration/output bodies with their existing native
expression forms. The native handler prefix retains the declaration and
initializer sequence; the CompCert prefix uses those same bodies and keeps
register reads inside the register-source branch. Only decoded scalar fields
enter the inline source-shift/arm adapters. Seven C roots await Clight export.

The queued tests compare historical/native/CompCert bodies, raw width truth
and repeated capture, signed high32 displacement versus whole immediate,
low32 sign extension at width64, lazy register/AUX reads, shift operand counts
and prefix frames with unused state/arena references absent. Shift counts at
least64 keep the original undefined C behavior; no mask or fallback is added.
A native BPF fixture exercises immediate/register, source lanes, indexing,
private/aliased destinations and provenance. These are planned checks, not
results. Nine mutations, `make clight`, targeted Lean, deterministic export,
axiom queries and four-header byte/relocation comparisons are queued.

The checked-in Lean exports still describe the preceding validated checkpoint.
After the waiter finishes, inspect every result and commit the genuine updated
exports and measured receipts. M4/full handlers/default coverage, all2,065
Clight refinements/recounts, M6 and whole-library acceptance remain pending.
