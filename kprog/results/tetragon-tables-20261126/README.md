# Tetragon table-generation boundary

PERF 2026-11-26T15:53:59Z.

The section0 phase1 item lists14 relative-table liveness refusals and10
finite-indirect-target refusals. This replay uses the retained proof objects
and metadata from omp-five-20261120/tetragon/session-6f0mwwi2. It does not
change P, its flags, the image, kernel, workload or LTO selection.

`make reproduce` initially reproduces request12's live-result refusal and
request9's unresolved jmp-rax at0x3580. reproduction-before.json and
reproduce-before.log retain
those outcomes. Request12's first observation is the call at0x292 to
filter_inet, whose actual body starts at0x3c2 in the same proof. The old
analysis instead fabricates six arguments and arithmetic-flag inputs for
that known local call, rejecting private R8/RDX table results as observed.

The common x86_relative_tables.py analysis now visits a known direct callee's
actual instruction effects as well as its caller continuation. It preserves
the old private masks in the continuation, deliberately crediting no callee
kills. Local returns are checked through that continuation, while the
original function's return remains an RAX observation. The worklist keeps
those return contexts distinct. Unresolved calls retain their previous
conservative treatment. No private memory spill is erased and no runtime
check, per-app rule, new compiler option or alternate pipeline is added.

`make check-calls` assembles calls.S, links each selected entry with the
canonical native-link and reads its byte-bound instruction effects through
the normal generator. All9 cases pass: unused local inputs and discarded
local returns are accepted; callee/caller register observations, callee/caller
flag observations, an observed return and an unresolved external call are
rejected; the existing zero-argument helper treatment is unchanged.
`make check-calls REVISION=c47fa6a15` runs the same expectations against the
prior source loaded from Git into memory. It fails the two positive local
cases, as recorded in call-checks-before.json/log. No private source copy is
created. The initial seven-case and intermediate boundary records also stay.

The14-request breadth replay is:

```
make reproduce REQUESTS='12 16 23 33 38 39 41 49 58 62 64 71 75 80 9'
```

Requests39 and62 now pass table lowering, each4,252→4,244 instructions.
The other12 live-result cases reach a later original-function return with
live RAX bits (0x5e0, or0x588 in requests38/64). They remain refused. This
is not a claim that all14 requests generate B or pass the stock verifier.
Request9 remains refused: its table base is hoisted into R15 at0x3560
before a loop; the load/add/jump at0x3579..0x3580 no longer has the adjacent
base-LEA pattern the current lowering requires. Neither remaining condition
is bypassed by this fix. lowering-breadth.json and breadth.log retain every
outcome and the first actual observation.

Checks run under shared timing on CPUs16–17 with an8GiB address-space cap;
no guest or sole-image rebuild is needed for this B-analysis-only change.
Full B source generation/compilation and stock acceptance remain separate
next steps for the two advancing requests. Main-configuration coverage and
the Tetragon/OTel performance objective remain open. Full timing is frozen.

Full B source generation now also passes requests39 and62 through the normal
generator, including definedness, map annotation and instruction rendering.
Both sources have608,257 bytes and identical text. reproduction.json and
source-generation.log record that next boundary; the generated sources stay
beside their retained proof inputs. They are not stock-verifier acceptance.

The next `make compile` uses request39's source through the installed normal
stock-input wrapper, packet-bounds compiler, whole-word spill pass and BPF
backend, with their existing flags. It records each actual command/outcome,
the final object size and the equality to request62's source. This avoids a
duplicate compile of identical input, without a per-program production
policy. The finite job records its own result and wakes the lane on either
outcome. No compiler, base or image rebuild, new LTO setting or native flag
change is involved. Actual stock/app acceptance remains open.
