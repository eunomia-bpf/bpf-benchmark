# True ALU handler entry through complete scalar operand reads

The original eight arguments enter the actual nine-local ALU_REG function.
Its real width call, aux decoding, non-XOR gates, both complete scalar reader
calls and assignments reach the original arithmetic dispatcher. Counts from
the genuine handler call are214/222/230/230 for byte/word/dword/qword.

Operation and both lane shifts come from the caller's32-bit aux word. Helper
scope and live parameter observations follow from the actual allocated
environment and temporary map. Post-entry header/word/tag loads follow from
the caller's observations through the existing allocation frame theorem.
The final heap is that actual allocation; all prior caller bytes and both
permission maps remain unchanged. This does not assume intermediate heap loads
or reader return results.

The domain retains the explicit non-XOR, non-RSP, scalar-word/non-stack-tag and
shift-range premises. Final arithmetic, flags, writer and native step composition
remain next; the whole handler has not yet returned.

Focused170 jobs pass in4.07s and the public type/axiom query passes. See
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original200000/512 budgets, one worker,32GiB
and shared timing are retained. Root integration follows this accepted batch.
Raw attempts remain under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
The recorded whole-check DIV fault correspondence defect remains open.
