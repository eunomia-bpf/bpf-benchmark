# x86 store-selector C-subset checks

Six store selectors share declaration/output bodies with the existing native
expression forms. The native handler prefix retains the declaration and
initializer sequence; the CompCert prefix uses those same bodies and keeps
register reads inside the register-source branch. Seven actual roots bring
X86Pointer to33 functions.

Historical/native/host-adapter modes each pass260 width cases,320 scalar and
capture groups, and336,960 lazy prefix/frame cases. They cover raw width truth
and repeated capture, signed high32 displacement versus whole immediate,
low32 sign extension at width64, lazy register/AUX reads, shift operand counts
and complete prefix frames with unused state/arena references absent.
Shift counts at least64 keep the original undefined C behavior; no mask or
fallback is added. Nine semantic mutations fail as intended.

`make clight` and the targeted Pointer/Memory/Context Lean build pass40 jobs.
The Pointer export repeats exactly987,949B; seven root queries use only the
usual Lean axioms. Historical four-header replay preserves allocated sections
and relocations, equal to normal compilation: store2272B/13relocs,
memory1680B/5, ordinary1448B/11, contextXDP360B/TC760B/4. Fixtures were not
loaded or timed; whole-default byte identity is not inferred.

The queued validator acquired timing SH at19:44:34 UTC after Katran released
EX. All checks are terminal; original queue/commands/logs remain in raw.
Full inline export still exits2, now at a declaration directly after a default
label. CPP2,443,378B is extraction-profile size only. M4/full handlers/default
coverage, all2,065 Clight refinements/recounts, M6 and whole-library acceptance
remain pending.
