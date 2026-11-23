# Actual x86 register-cell value loads

Nineteen actual Clight transitions narrow the input shift, select any of the
sixteen architectural GPR cells, load its scalar word through the original
union-pointer member, and retain that word in the original reader temporaries.
The complete heap and continuation remain unchanged. The only layout premises
are the three actual binding/GPR/cell composite lookups; field offsets and the
sixteen-byte stride follow from their existing exported definitions.

`from_call` composes the actual four-argument entry and width helper with these
loads in41 transitions, using the original ALU call-site argument casts.
`native_word` relates an ordinary scalar row to the shared x86lean register bank
through `X86RegisterView.RegistersRepresent`. The actual tag load, RSP/stack
materialization, width extraction and final return are still open; the41-step
result stops before those statements.

Focused164 jobs pass in3.03s. Eight direct-import type/axiom queries pass; see
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Runs retain the original200000/512 proof caps,
one worker,32GiB and shared timing lock. This checkpoint has no new root import.
Raw attempts remain at `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
Full handler/dispatcher refinement and the existing full-check DIV fault
correspondence defect remain open.
