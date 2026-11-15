# x86 memory-read source C-subset checks

The selector shares one declaration body between its native expression facade
and standard statement output. The CompCert inline adapter passes the binding
itself and reads cells inside that body, after the stack test. The scalar
extraction root brings X86Pointer to23 functions.

Historical and current native/adapter runs each pass338,000 full-operand cases.
Both facade/output forms preserve stack/tag/width evaluation order and counts.
The actual inline binding passes48,384 additional frame cases with unused
references absent, retaining its prior580,608 register/profile cases. Five
mutations detect tag/width byte truncation, lost stack priority, width-before-tag
and an eager cell read. The latter faults on an intentionally absent reference.

`make clight` and `lake build KProgFormal.Clight.X86Pointer` pass. Re-export is
deterministic (883,116B); the root has only the usual three Lean axioms.
Historical replay covers inline/local/simulator/selector headers together.
The first recipe omitted the intermediate simulator header and stopped before
compilation; its failure stays in raw. Corrected replay preserves allocated
sections and relocations: ordinary1448B/11relocs and XDP360B/TC760B/4relocs,
with current replay equal to normal compilation. These fixtures were not loaded
or timed; whole-application identity and performance are not measured here.

Full inline export still exits2, now at STACK_READ/STACK_READ_OWNED GNU
expressions. CPP2,674,873B describes the extraction TU only. M4 is incomplete;
all2,065 Clight refinements/recounts, native-memory/platform interpretation,
M6 retirement and whole-library acceptance remain pending.
