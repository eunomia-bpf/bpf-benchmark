# Actual x86 ALU_REG entry prefix

`X86AluEntry.source` and `width_source` identify the actual exported handler
body and its first width call. `enter` executes the first five loop/assignment
transitions for every byte width and arbitrary memory. `effective_width`
executes the real source call, linked helper and assignment in thirteen steps.
`from_call` composes genuine eight-parameter/nine-local function entry with
these stages: nineteen silent transitions from Callstate to the actual
post-width statement. Width and flags come from the real parameter bindings;
helper scope is derived from the actual allocated local list. All other
arguments are unrestricted. Complete memory equals the real allocated heap.

The exact source and five type/axiom queries passed in 2.45 seconds.
The canonical focused `lake build KProgFormal.ClightRefinement.X86AluEntry`
also passed, 160 jobs in 10.98 seconds, rebuilding current X86RegisterView.
One worker, original Lean proof budgets, 32 GiB process memory cap and shared
timing lock were used. Public output uses only the existing logical and
CompCert external/assembly semantic assumptions; no new axiom or admitted term.
See [the public output](public.txt). Raw commands, build output and all earlier
diagnostics remain in `/workspaces/kprog-raw/V/x86-entry-storage-20261122`.

This is the handler entry prefix. Aux decoding, source operand reads,
composition with ALU/flags/writeback, other writer branches and full dispatcher
refinement remain open. This does not complete M5/M6 or an ISA instruction family.
