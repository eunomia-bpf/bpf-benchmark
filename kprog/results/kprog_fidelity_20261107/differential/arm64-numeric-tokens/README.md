# ARM numeric immediate tokens: dispatch diagnosis and generic candidate

The declared ADD_IMM and SUB_IMM tokens select the default unsupported arm
in the captured production dispatcher. The native producer currently encodes
ADD/SUB immediate through ALU_IMM. The focused numeric-token replay exposed
this declared-token gap and prepared a private generic repair.

| Observation | Captured production | Private candidate |
| --- | --- | --- |
| Native/static build | Completed | Completed |
| Numeric ADD_IMM/SUB_IMM routing | Default body35 | Existing ALU body4 |
| Completed QEMU/C/reference states | 0 | 8192 |
| QEMU/C differences | Comparison pending | 0 |
| QEMU/reference differences | Comparison pending | 0 |
| C/reference differences | Comparison pending | 0 |
| Live production adoption | Captured baseline | A/V source and contract synchronization pending |

The baseline first simulated function compiles to an unconditional abort.
baseline-sim0.asm records that body. Its buffered trace has zero bytes; the
existing reference reader subsequently reports its short-header unpack error.
The preserved baseline archive includes the exact static binary, all source
inputs, native bytes, binding matrix and raw error log.

The candidate changes three headers inside F's private compilation snapshot:

- Add numeric3/4 to KPROG_ARM64_ALU_HANDLED.
- Select the immediate RHS for numeric3/4 through the existing selector.
- Regenerate direct dispatch with the existing generator and private headers.

candidate.patch.gz and candidate-changes.json retain the complete changes.
All generated direct body text remains identical; the two numeric mappings
move35 to4, and the other69 mappings retain their values. All live production
source hashes retain their baseline bytes. Production integration follows A's
source-epoch handoff and V's corresponding family/operand contracts and
universal handler laws. The source ledger's production replay totals keep
these two entries pending through that integration.

The unchanged native matrix has four ADD/SUB immediate127 forms at32/64bits.
Each runs through raw ARM64_SIM_RUN_OP3 and direct ARM64_SIM_RUN_KNOWN_OP3:
eight route/form groups,1,024 states each. Original destination/source,
src2/src3,width,AUX and immediate fields are preserved. Native bytes match
across all four raw/direct pairs. The existing observer and flag/register/
memory comparison logic use the original fixed-seed inputs; each three-way
comparison shares its captured initial state.

The candidate completed at20:04:05 UTC with exit0 and source drift0. All91
compilation inputs match the archived hashes. Of79 snapshot production files,
76 match launch commit c15b51f49f61acb502990bb579c528319eea32d0 and the remaining
three are the explicit candidate changes. The main simulator header remains
c21833dee58cbdbc85aa176289585f705f189743b1337adfa13908775d6c28c5.
The static AArch64 binary SHA256 is
59553e3a193181b52ca0d7acab11650a67b2a0ccbecb3f4250cd67672485d251.
The canonical reference remains
c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96.

This experiment executes QEMU user mode. The static artifact supports a later
coordinator hardware replay. The ordinary807-form hardware handoff retains
its existing default artifact. These observations support generic numeric-token
fidelity; universal simulator safety retains the formal lane's obligations.

From the repository root, reproduce the private snapshot check:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-numeric-tokens/Makefile reference
~~~

select.py uses the existing fidelity generator and overrides the selected
ARM statement with the bound raw/direct entry. apply-candidate.py applies
the three private snapshot changes and runs the existing direct generator.
The production tree, shared reference and other lanes' execution inputs retain
their recorded bytes. The recipe reuses the separate warm ARM build cache.

forms.tsv and reference-forms.tsv retain all8route counts. The compressed
difference streams each contain zero records. The14,876,696-byte raw trace
remains in the Workspace, SHA256
103219f5774a418eb0a55680ee513a5753125bc59cb0f1faa14973b9f9c11412.
baseline-attempts.tar.gz preserves the first adapter-semicolon compile failure
and the subsequent production-dispatch abort, together with preflight logs.
The baseline core was identified by PID3654048 and the mapped numeric-observer
binary, then retained privately in F state. Previous production observations
and their source epochs remain available.
