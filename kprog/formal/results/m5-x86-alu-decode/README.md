# Actual x86 ALU_REG aux decoding

The source theorem identifies the actual six post-width assignments.
`decode` executes them in eighteen silent transitions for every32-bit aux word,
retaining the complete input memory. `field_byte` proves the operation and
lane-shift masks/casts equal byte extraction at the original0/8/16 offsets.
`observations` derives the decoded operation, both byte shifts and both initial
zero operands from the exact resulting temporary map.

`from_call` composes the real eight-argument/nine-local function entry and width
helper with decoding: thirty-seven transitions reach the actual operand-read
statement. The caller's aux argument supplies all three fields. The linked
width-helper identity is the sole helper premise; its local scope, parameter
observations and helper return follow from actual execution. The final memory
is the actual allocated heap. Operand reads, surrounding flag/writeback
composition, remaining forms and dispatcher refinement remain next work.

Canonical focused build:161 jobs, exit0,59.92s including the existing automatic
Clight-source generation. Five public type/axiom queries: exit0,1.67s.
Both used one worker, original proof budgets,32GiB memory cap and shared timing
lock. Query output records the existing logical and CompCert external/assembly
semantic axioms. See [the public output](public.txt), [query](Query.lean) and
[invocation results](validation.json). All earlier diagnostic attempts and full
build output remain at `/workspaces/kprog-raw/V/x86-alu-decode-20261122`.

The prior whole-check attempt ended with a partial434/484 log and its terminal
result absent; that raw evidence remains at
`/workspaces/kprog-raw/V/x86-entry-storage-20261122/make-check1.txt`.
A complete batch confirmation follows this accepted increment. M5/M6 and the
complete O1/O2/O4 obligations remain open; instruction-family completion stays0.
