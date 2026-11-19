# Actual register declarations and full GPR input traversal

All 31 production register declarations now have kernel-checked body equations,
real successor links and mapped input/result temporary names. The certificate
extracts successors from the actual production spine and checks each complete
body against the existing declaration schema. Named word/tag metadata, local
declarations, distinctness, context separation and the x30 branch index are
checked for the entire family. The first declaration agrees with the previously
proved actual first-input boundary; the final successor is `afterRegisters`.

The actual execution instantiates the existing generic call, store-witness,
return and zero-branch proofs. Each x0–x29 visit uses the real input block 59,
the actual function/environment/continuation, five internal call steps, the
stated provider outcome and nine internal writeback steps. The x30 declaration
uses ten internal steps with no provider visit and writes zero. All stored tags
are zero at this stage; later RAW/return-tag setup remains separate.

`Arm64ProducerGprInputs.run_suffix_body` is the original induction parameterized
by function, environment, declaration/stage families, named-cell correspondence,
checked successor links and per-input execution. The original source wrapper
retains its interface and uses that same induction. The production instance
therefore shares the store construction and traversal proof with the source.
There is no second producer, memory interpreter or provider replay.

`initialized` retains 30 ordered traces, all 31 word/tag readbacks, earlier-cell
and other-local loads, unmodified temporaries and caller/access/frontier frames.
`entry_initialized` composes the actual 589-step setup prefix with the complete
traversal and x30 branch. It derives all actual production word/tag bindings,
preserves both cache words/validity bytes and the original context temporary,
and reaches the actual post-register successor. Provider availability, returned
words, trace/post-memory preservation and native/original-context correspondence
remain explicit invocation obligations. This is a relational `Star` composition;
external steps are kept separate from internal step counts.

The remaining pointer-table, flag, vector, stack and context initialization must
execute before the separately proved header/body suffix can be joined. Full
native/all-outcome admission, the signed32 wrapper/borrowed uint32 return bridge,
ISA refinements and the O1/O2/O4 recount remain M5 work. Complete ISA-family count
is zero; M6 follows M5.

Public type/axiom queries are in `Query.lean`; commands/exits, source hashes and
all attempted checks are in `validation.json`. Raw data remains under
`/workspaces/kprog-raw/formal/m5-program-entry-gpr-inputs`. Checks use CPU17,
one worker, 32 GiB address space and original 200000-heartbeat/512-recursion
caps with `Elab.async false`; controls run on CPU16. Host checks follow the
2026-11-19 18:18:59 coordination rule without a timing lock. No C/runtime,
compiler, kernel, image/base, benchmark, paper or design source changes here.
Fresh final Lake and `make check` remain required at M1–M6 closure.

The final focused build passed 189 jobs; the declaration metadata build passed
176 jobs. All 18 public type and axiom queries passed, followed by one full Lake
build of 352 jobs. Repaired construction, Fin equality, parser and local-binding
attempts remain in the raw logs and receipt. Pure metadata/storage bindings use
standard logic; relational execution retains the imported Step2 external and
assembly semantic models. No new axioms or proof-limit changes were added.
