# Production x86 CPU, simulator and canonical replay

The existing default matrix completes **1144 forms ×256 states =292,864 cases**
on the real x86-64 host CPU. Every form has256 CPU/C and256 canonical cases.
CPU/C, CPU/canonical and C/canonical comparisons each report **0 differences**.
All1144 forms receive canonical replay; the reference-pending count is0.
The initial command exits2 at 2026-11-07T22:29:37.606830+00:00 while awaiting38 control
forms. The saved-state control replay exits0 at 2026-11-07T22:35:38.573565+00:00.
The combined observation covers all292,864 canonical cases.

This epoch captures production source be2bbfbb3798cadd2827c30c8fe016346ad903ae, following C's tagged-register-write
adoption9b0aa2b09c1188ede61fea3c0a9d0d3acbebded1. The compiled simulator header is
6b3f31731d9d127a36183e3e35cd6b39335d8b5865649a8282fc503a7be0dc11; its register-write header is
cf27e323c885cdf8258974a8800907af2f6ee56093d7721822b9e75360e72994. Each of the
82 copied production sources matches that
launch Git commit exactly. All90 captured inputs
match their archive hashes; derived source caches have their own literal pins.

forms.tsv preserves each real CPU/C count. reference-forms.tsv preserves each
canonical count, and observations.tsv joins them with the exact assembly/opcode
and changed-memory count. coverage.json records the generated form inventory.
The complete compressed diagnostic streams preserve each difference input.
Their zero-length decompressed streams agree with the observed totals.

## Observation domain

The original generator, native wrappers, driver and flag masks supply this run.
Each form receives128 boundary-seeded states and128 randomized states, with
random register/flag/vector/stack/memory initialization and the driver's original
operand-domain setup. The stored architectural comparison covers32 scalar cells
(including16 architectural GPRs), the six arithmetic flags under the original
definedness masks, XMM0,64 private-stack bytes and256 memory-window bytes.
Stack forms retain their original relative-RSP setup and hardware projection.
Existing branch, CALL/RET and REP composites retain their actual wrapper paths.

The256-byte memory window changes in
35530 native cases. Every resulting byte is
compared with its simulator value; private-stack bytes receive their independent
full comparison. The stream reader recomputes CPU/C differences with the same
dynamic shift/rotate masks as the original driver, reconciles every row and
checks the entire trace length and SHA256.

These sampled instruction and composite executions support the current
enumerated domains. The universal simulator/token/native-link, helper, private
arena, ABI, definedness and compiler correspondence interfaces remain with V/T.
The global numeric-token coverage ledger maintains its own token domains.

## Captured execution and state

The captured executable SHA256 is 5188ecdedc827345a010d08d837a2aabf92870f9ddf5660d9d9f7130131fe1f7.
The sole canonical executable is the frozen published c110 reference:
c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96.
Its bytes match ../x86-current-matrix/canonical-reference.gz.

actual-compiled-inputs.tar.gz preserves generated C, native assembly, instruction
assembly/disassembly, driver/build inputs and the actual source snapshot.
launch-inputs.tar.gz preserves the initial source vector and detached job script.
The reviewer reads generated descriptors from the compiled archive, including the
eleven signed POP setup descriptors, and retains all1144 rows independently of
the warm build directory's lifetime.

The complete Workspace state stream is cpu-states.bin.zst:
171671350 compressed bytes, SHA256
1c82434a89495198043ccbf733df03c87d944b2355c4a6b7bc30275c67bbf0bf. Its decompressed identity is
531841048 bytes, SHA256 420dcc8529b88e42a3830f09b8e12222a844551ccdd82aabff0557ac5bc9d740.
The compressed stream stays with this Workspace's raw results. The published
tables, sources, executable and full diagnostic streams retain reproducible
observation identities. The trace archive supports every recorded input and
successor. Warm incremental build objects remain in the owning F cache.

## Canonical control-interface completion

The initial command records283,136 canonical cases across1106 forms and38
pending branch/CALL composites. initial-canonical-attempt.tar.gz preserves that
report, its exit2, diagnostic streams and original command source. The existing
reference interface accepts --control-paths; its saved-state replay checks
the38 pending forms and9,728 cases with exit0 and zero differences.
The finite-path interface consumes the same actual native instruction bytes,
canonical executable and original full state stream.

The final reference table retains all1106 prior checked rows exactly and
replaces only the38 pending rows. replay-interface.json records both table
hashes, selected form IDs, original state/binary identities and the exact replay
command. control-reference/ retains its38 per-form rows, status and compressed
diagnostic streams. The native observer, compiled simulator, flags masks and
reference semantics retain their original bytes. The corrected Make command
supplies the existing control option for full future replays.

## Commands

Run from /workspaces/repository through bws.sh against the captured source epoch:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-production-current/Makefile reference
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/differential/x86-production-current/review.py
~~~

The Make target uses the existing build-x86-production-current cache and frozen
reference-control-frozen executable. For archived observation review, restore the
full compressed trace beside the published metadata and run review.py.
The actual source and binary remain fixed while other owners advance the root
checkout. status.json records the exact later source differences:

~~~json
{}
~~~
