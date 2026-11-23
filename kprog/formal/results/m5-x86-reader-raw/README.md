# Raw-cell source loads and preserved scalar APIs

The original19-step register-cell load theorem now supports every raw Clight
value preserved by its three actual casts. The cast equations are explicit
pure operator premises. Both numeric `Vlong` and pointer `Vptr` values satisfy
these casts by reduction. Existing scalar `read_value` now instantiates this
shared execution proof, retaining its original public statement and all
existing width/lane/native and handler callers.

This factors source execution for the next genuine pointer-reader call
boundary. The current lane/native correspondence keeps its scalar domain;
concrete address projection remains a composition obligation. The original
source statement, C runtime and shared ISA specification retain their
existing definitions.

Focused acceptance includes the genuine XOR entry and its complete reader
dependencies; six public type/axiom queries cover the generic load, original
scalar load/call, complete native scalar reader and actual XOR entry.
Original200000/512 budgets,j1,32GiB and shared timing are retained.
See the validation metadata and outputs. The latest whole confirmation is
recorded separately in `m5-xor-full-20261123` with the DIV regression.
