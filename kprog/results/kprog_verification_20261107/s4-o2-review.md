# S4 O2 classification and S5/S6 handoff review

S4 `8438520f5` adds valid universal equalities. Its helper results quantify
`run : String -> State -> Outcome` and `readRegister` without a relation to an
implemented C frame transformer. `helperBody` and `helperSwitch` select body
names from the generated sparse table and apply the same interpretation.
This proves shared-macro routing substitution for every ID and default, for
any outcomes assigned by that interpretation. It does not identify or prove
those interpretations' argument, memory, tag, clobber or control effects.

The existing 72-token category uses concrete numerical/tagged state models,
field decoding and modeled updates, memory/fault traces and control steps;
see `Refinement/X86Dispatcher.specialized_register_body_matches` and
`register_token_body_matches`. That category also retains C/compiler and
physical correspondence premises: it is not verified compilation. The
contract-generated helper table (`_ARMED`/`EXPECTED` and its generated C
selector) does not extract every helper macro's state semantics.

`ret_body_matches` adds the modeled invocation uint32 result and composes
the existing internal RET/default with its tagged postframe. Its return mode
is a formal argument. Actual renderer mode selection, C register/stack/frame
realization, physical invocation/read-fault and compiler transport remain.
The production outer macro does return uint32 READ_REG(RAX); this review does
not allege a counterexample to the valid model equality.

Retain `returning-helper-interface-proved` for the two helper rows and
`partial-C-model` for RET, adding explicit component labels
`parametric-macro-routing` and `modeled-return-control-equality`. Keep every
S4 theorem on both operation and specialization rows. The complete C-model
count remains 72/75. Promotion requires a concrete source-to-model macro
interpretation and producer/branch binding at the existing model boundary.
This is a proof obligation, not a proposed runtime check. Native helper
effects and compiled B remain separate O1/O4 obligations.

S5 `be8c79913` and S6 `2ec166375` contribute nine O4 operational-model
components: kinds5-8/layout and spill control/helper ABI/tail/entry. All nine
remain `partial-universal-component`, retaining their actual Rust/iced/C/JIT,
physical ownership/lifetime/RCU, successful B tail transfer, helper effects,
compiler CFG/slots and native/B ABI goals. Preserve existing evidence and
publication epochs when adding the new components.

The existing six focused module builds pass, resolving S4's noted shared-cache
dependency. Source bytes match the three published commits. The
[original proposals, source epochs and build output](s4-s6-coverage-review.log.gz)
retain the proposed stronger S4 labels and the reviewed decisions. This is not
a second full check; the sole full and compiled-unit pipelines retain their
own immutable source epochs. No runtime gate is added.
