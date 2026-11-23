# Actual ALU RHS reader call and resume

The original second reader call enters its linked four-parameter helper in two
silent Clight transitions. Its binding, source-register byte, effective width
and source-lane shift are evaluated from the actual caller temporaries.
The genuine return, original RHS assignment and sequence exit reach the
arithmetic dispatcher in four transitions, retaining the returned raw value,
the incoming LHS observation and the entire heap.

Focused168 jobs pass in2.16s and four direct-import type/axiom queries pass;
see [Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original proof caps200000/512, one worker,
32GiB and shared timing remain unchanged. This call-site theorem does not assume
or establish a helper result; complete operand composition uses the separately
proved actual scalar-reader execution. No new root import at this checkpoint.
Raw attempts remain under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
Full handlers/dispatchers and the existing full-check DIV fault correspondence
regression remain open.
