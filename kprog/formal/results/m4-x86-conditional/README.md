# Conditional-handler C-subset checks

Four canonical selectors share their declaration/output/native expression
bodies. Actual CMOV/CMOV_MEM/SETCC/SETCC_MEM roots use the existing generic
arena/fact binding. The memory SETCC address reuses the established address-add
helper, retaining the original BPF pointer form. No new platform import or
alternate interpreter is introduced. Root arguments use the actual decoded
byte register/flags and32-bit AUX types; scalar selector roots retain raw64-bit
tests. Existing CMOV width evaluation is preserved and its comments corrected.

Historical2044b0c62/current native/CompCert host-adapter modes each pass78,336
CMOV,77,568 memory-CMOV,13,056 SETCC and13,056 memory-SETCC complete frames,
260 raw selector/capture groups and three fault/nonreturn probes. Independent
conditions include all16 codes/parity, rejected whole-word/byte encodings and
noncanonical flag bytes. Writer composition uses separately tested Pointer
roots, including RSP materialization/release, partial writes and complete
facts/bytes/state frames at capacities16/64/200/376. Protected false-CMOV reads
fault before destination32-bit zero extension; RSP recovery traps regardless
of the condition. Eight semantic mutations fail as intended. C observations
and composition checks do not prove native exception or Clight refinement.

`make clight` and the40-job targeted Lean build pass. Memory28 functions/
1,808,925B regenerates exactly; Pointer remains34 functions/988,925B. Eight
AST-root queries use only propext/Classical.choice/Quot.sound. BPF conditional
1008B/4 allocated relocations and ordinary1448B/11 are exact against historical
headers, with current replay equal to normal compilation. These are compile
fixtures, not whole-default program coverage or runtime measurements.

Header replay now follows supplied parents' include locations and replaces all
guarded occurrences. This matters because SETCC is first included through
full_condition before the redundant direct include. The actual nested fixture
exercises that path; absent include targets still fail explicitly. Historical
host replay also injects both occurrences. Initial harness location/include
errors and incorrect oracle expectations are retained in the raw directory;
neither the fixed-load release behavior nor full SETCC immediate was changed.

Full inline export with default frontend options now reaches ten struct-return
errors; the suggested `-fstruct-passing` diagnostic exports115 functions to one
19,550,502B artifact. That full export's Lean/build integration is a separate
step. Explicit-profile CPP is2,444,905B. M4 remains open, followed by all2,065
actual refinements/O1-O2-O4 recounts, M6 and whole-library acceptance. Full raw
commands, patches, mutation logs and failures: `/workspaces/kprog-raw/formal/m4-x86-conditional`.
