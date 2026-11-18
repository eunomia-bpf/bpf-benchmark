# M5: ordinary MOVK reader in its actual linked world

The combined reader executes 73 actual Clight transitions: 55 to load the
raw word and tag, then 18 through non-relative materialization and return.
Those proofs now accept an arbitrary world with the five actual GPR-layout
facts used by this path. Existing public standalone statements remain their
projections. Two unused private standalone wrappers are removed.

`GprLayout` requires only the actual entry/GPR composite lookups, cells/tag
field offsets0/8 and union payload offset0. `Arm64MovKeep.reader_layout`
kernel-checks those facts for `Arm64NumericProgram.ge`. The complete composite
environments were not identified by the initial source-equality probe;
no equality of composite tables, Genv, symbol tables or initialized memories
is assumed. The arbitrary reader continuation was already supported and is
retained. The actual generic caller still resolves its reader symbol/body.

`read_nonrelative` transports the complete 73-step execution to that world,
including both scalar and bound pointer values, for all non-relative tags.
Its complete memory is unchanged. `read_scalar` derives the actual observation
from the same producer storage and explicit Mint64 word/Mint8 tag loads:
the word is genuinely `Vlong bits` and the tag is0. Neither a tag nor ValueRep
is treated as evidence that a pointer is an integer.

`read_after_write` supplies those loads from the actual scalar writer's
successful word store/tag clear and its retained storage. `scalar_native_bits`
uses the actual observation and complete register relation to identify the
native input bits; `read_scalar_corresponds` returns those native bits from
the same reached memory. Relative origin/cache cases retain their separate
execution and post-memory obligations.

`scalar_writer_call` composes the real DST call, 73-step read and existing
merge/writer edge in 105 transitions, using both genuine Kcall contexts.
The source branch ends at the actual internal writer call with the merged
value and exact same memory. Its real reader continuation is now public so
this composition names the actual continuation rather than substituting one.

These are reader and branch contracts. The complete ordinary MOVK stores,
local-frame free, final register relation and checked W32/X64 native-step
composition remain next. The already proved complete WZR/XZR path is retained.
The source insertion covers all four columns; native W32 permits only0/16.
A 64-bit insertion/low-word relation and upper-word clearing still need proof.

Validation is recorded in `validation.json`: focused builds, ten public
type/axiom queries (including the preserved standalone API), one final full
Lake build and all23 exports directly compared with reference `9c617740f`.
One worker uses CPU17 (build) or18 (query/edit), 32 GiB address space,
normal200000 heartbeats/512 recursion, with every host command under timing SH.
C/runtime remain unchanged; native `make check` is not repeated for Lean-only
changes (last complete PASS `5236c0e9677f635526fdd515cde5195b2ba0810c`).

M5 and M6 remain open; complete ISA-handler/family count is **0**. Actual
frontend/provider/producer/caller admission, native physical memory/alias/origin,
Numeric initialization204 distinct from old189, source control and all-family
O1/O2/O4 recount remain before M6 and fresh final Lake/native checks.

Raw: `/workspaces/kprog-raw/formal/m5-arm64-mov-keep-read`.
