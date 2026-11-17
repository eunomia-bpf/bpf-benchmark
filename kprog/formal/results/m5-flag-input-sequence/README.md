# Four flag calls, LR zero and all 64 vector calls

`Arm64ProducerFlagInputs.flag_inputs_initialized` traverses the four actual
n/z/c/v input declarations in source order and executes the following
three-transition `___a64_lr = 0` assignment. It reaches vectorStart before
any vector call has been consumed. Each flag byte follows from flagWord of
the full returned 64-bit word; earlier flag bytes and source locals survive
later framed provider outcomes and stores. The result retains the four traces,
actual local bindings, LR-zero readback and temporary updates.

The source-specific Provider condition supplies the actual kind-6 external
call in the linked Senv, its complete returned word, supplied post-memory and
required frame/access/nextblock facts. It is an uninstantiated invocation
condition. Supplied memory is not forced equal to input memory; all effects
must satisfy the stated frame obligations. No provider result is fixed to a
zero-or-one full word.

`flag_vector_inputs_and_raw_registers` composes this prefix with all 64 vector
visits and the 728-transition RAW suffix. Exactly 68 provider traces are
concatenated in source order. Both final flag bytes and vector-buffer contents
are now derived. Header flag indices 8/9/10/11 identify the actual declared
locals through allocation binding uniqueness. Matching native NZCV constrains
only each returned word's masked low bit; upper bits remain arbitrary. The
_ctx temporary survives the input returns, and caller contents, both permission
maps, access and nextblock remain framed.

The LR declaration is a separate local from x30's source payload and native
return origin. Executing it does not force a native return address of zero.
Earlier GPR data, ordinary tags and pointer-table contents remain source
premises. Actual provider availability, same-invocation native bits/origins,
physical pointer ABI/aliasing, architectural memory/events/fault/control and
the program continuation remain open. M5/M6 and O1/O2/O4 recount remain open;
complete ISA-handler refinement count is 0.

Focused Lake passes 169 jobs and full Lake passes 296 jobs. Two public
type/axiom queries and one source/high-bit query pass: actual flag stores match
the borrowed header fields, and words with bit63 set and low bytes ff/fe
produce flag bytes 1/0. Both theorems use ordinary
propext/Classical.choice/Quot.sound plus the already imported external/assembly
semantics. Every external return remains an explicit premise; no semantic axiom
or host outcome is added. All 23 exports (243488732 bytes) remain byte-identical
to 9c617740f. An initial focused attempt exposed a True branch, unsupported
choose tactic and excessive unfolding of the large source suffix; narrow stage
equalities and explicit Classical.choose fixed it at unchanged proof limits.
Full Lake ran once on final proof source; all failed logs are retained.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerFlagInputs
lake env lean -j1 results/m5-flag-input-sequence/Query.lean
lake env lean -j1 results/m5-flag-input-sequence/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-flag-input-sequence. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
