# Complete actual XOR operand selection

The three XOR selector cases execute the original source gates. Different
register bytes enter the actual operand-read statements in10 steps without
evaluating either shift. Equal registers with different lane bytes also enter
that sequence in10 steps, retaining the actual first-test value1. Equal
register and lane bytes take the previously proved11-step zero shortcut.
`all_cases` combines these source proofs for every four input bytes, retaining
the exact case-dependent temporary map and the complete memory.

The original gate definitions are shared with the self-XOR module. This does
not define another ISA model; arithmetic and native register views continue to
use the existing shared x86lean specification. Reader-call composition for the
two XOR read cases is next work.

Focused172 jobs and three direct-import type/axiom queries pass. See
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original200000/512 budgets, one worker,32GiB
and shared timing are retained. Root integration follows this component batch.
Raw evidence remains under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
The latest complete check stops at the concurrent ARM numeric proof; the
earlier DIV correspondence defect remains unrechecked and its assertion intact.
