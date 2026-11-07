# Independent CPU coverage for same-register XOR

The preceding 1080-form matrix contains no same-register XOR operand form.
It therefore cannot independently test the new production self-zero gate.
The existing F generator now includes all 16 general registers at
8/16/32/64-bit widths: 64 new real native instruction forms, 1144 total.

The existing Make generation target has assembled and production-encoded all
1144 forms successfully. Removing the 64 new forms leaves the preceding 1080
assembly rows in exactly their original order. All new forms select the
production ALU_REG operation; encoding-preflight.json records every form.
The source snapshot's d30 header matches published commit af2f58c89 exactly.

This preflight establishes assembly/encoding coverage only. Real CPU/C and
canonical-reference comparisons are pending in the detached follow-up.
The existing observer restores native RSP through a RIP-relative saved base
before touching the stack, allowing SPL/SP/ESP/RSP zeroing to be observed.
No producer, simulator, reference semantics, flag mask or runtime policy changes.

The queued real validation command is:

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=x86
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-popcnt-memory/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/x86-self-xor-current
~~~

The follow-up waits for the already running base-matrix build before using the
same incremental build cache. Its canonical executable is the existing frozen
F/reference-control-frozen; it does not rebuild another lane's Lake cache.
