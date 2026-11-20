# Framed actual origin reader

`Arm64ProgramEntryCacheFrame.read_framed` composes the actual linked cold SP32 reader with its origin outcome and both cache stores. The return value equals the represented native state's SP. The theorem constructs post-provider borrowed storage, derives both stores from permissions, and retains the same producer storage and complete GPR/SP/vector/flag relation. Its combined frame preserves original caller bytes and both permission maps, every other producer-local load, the complete access map and the current frontier.

The input frame is explicit, following the existing framed entry-provider interface. It permits the selected cache cells to change and does not require whole-memory equality. Availability and production validity of that frame and the returned native STACK origin remain invocation ABI obligations. The host oracle chooses zero origins; it establishes no production-origin guarantee.

The cache resource uses canonical allocation bindings and retained header pointers to identify the actual cells. It needs canonical permissions only below the producer frontier, which may be smaller than the current frontier after generic-handler allocation. Thus it does not equate the whole access map with the original producer allocation or exclude the live caller frame. The two stores' freshness and separation follow from their actual allocation witnesses. Their footprint is proved from the real store equalities, with no post-register-relation premise.

The existing flag pointer-walk lemma is made public and reused, as were the existing GPR/vector observers. No observer, ISA interpreter or runtime C body is duplicated. The native step/caller dispatch, original-input/physical-memory admission, all-outcome and final-return obligations remain open.

Focused 220 jobs and 11 public type/axiom queries pass at the original 200000-heartbeat/512-recursion limits, CPU17, one worker and 32 GiB address space. Imported execution axioms remain explicit in validation.json. Raw logs retain the finite field-name normalization retry. Whole KProgFormal proof-library/root confirmation passes 272 jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space. Executable/tool native builds are excluded.

Next connect the actual MOV_IMM SRC32 callsite and suffix to this framed reader, preserving the actual returned-word temporaries and provider trace, then handle unrestricted mark/priority operands. M5/M6 and O1/O2/O4 recount remain open; completed ISA-family count is 0.
