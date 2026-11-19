# M5: actual Numeric producer prefix and first input boundary

The existing raw-producer proof now executes in an explicit world. Its actual
allocation uses the proved composite-layout equality; the 189 source
assignments reuse their existing AST extraction, chunks and ready-assignment
induction. The original standalone entry, prefix and cache APIs remain
projections of these stronger laws. No source statements or C bodies are copied.

`initialized_prefix` starts from the actual Numeric program's derived initial
memory and executes 580 transitions: allocation 1, the 189 assignments in 567
transitions, and four actual cache initializers in 12. Both selected cache
base words and validity bytes read back zero. Actual allocation permissions
and nextblock remain, with every global's raw contents and both permission
maps preserved below the ORIGINAL frontier 204. No prefix or cache outcome
is supplied by the caller.

The RAW setup's three stores execute nine more transitions, preserving every
other declared local load. `input_binding` proves the actual Numeric symbol
and typed external function at block 64; composite equality alone is not used
to infer this binding. The real call setup takes five transitions and retains
the source's actual Kcall context. `initialized_first_input` therefore reaches
the genuine kind 6 provider call after 594 transitions, with caches still cold
and the same global frame. No external-call outcome is assumed or fabricated.

The shared exact-source equality tactic is reused by making the existing
Numeric helper public. NumericMemory's function-entry proof now projects the
same general entry rule, removing its repeated constructor proof. Private
source continuation data becomes public only to name the reached actual call.

This is a real execution prefix ending BEFORE the first provider executes.
The 98 provider outcomes/traces/post-memory and remaining producer/caller
admission, relative caches, native physical memory/alias/origin, source control
and all-family O1/O2/O4 remain M5. Complete ISA-handler/family count remains 0;
M6 follows M5. C/runtime and frozen benchmark paths remain unchanged.

Focused/full/query/export results and retained failed attempts are recorded
in validation.json. Raw: /workspaces/kprog-raw/formal/m5-numeric-producer-prefix.
One worker uses CPU 17; queries/edits/Git use 18; every command runs under timing
SH with 32 GiB AS and normal 200000 heartbeats / 512 recursion. No new trusted
axioms, unsafe/reflected proof or increased limit is introduced.

Final result: focused 179 jobs, full Lake 323 jobs, all 14 public queries and
all 23 direct export comparisons pass. Pure lookup/entry facts use standard
axioms; relational execution additionally retains the existing Clight
external-function and inline-assembly parameters. All attempts are retained.
