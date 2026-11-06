# A vector load hid an unsafe native branch

**Before:** the actual generation-bound loader accepted this program, one
chunk/nonzero generation1 (program8). **After:** the same native source and
original companion reject in the proof verifier:

```text
R1 invalid mem access 'scalar'
processed 27 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
```

The program allocates32 stack bytes, initializes Q0 with high64 bits1, loads
D0 from its low word, stores Q0 and branches away from a NULL read if the high
word is nonzero. Real D0 clears the high word, so native reaches the unsafe
branch. The old simulator preserved1 and hid it. The DQ contract/handler now
clear the upper half, exposing the NULL read to the verifier. Unsafe native
code was never executed. The255-form QEMU/reference memory replay separately
checks valid programs and shows no remaining mismatch.

before/outcomes.json and after/outcomes.json retain the exact messages, input
assembly and stages; all per-case/guest logs remain. Both runs used the same
#23 kernel (2026-11-06 13:38:07); artifacts.tar.gz preserves its Image, the
exact before/after native/proof objects and production snapshots, and the
post-fix initramfs containing the module/probe/linker. Later builds use the
new#24 exclusive-choice kernel separately; no mixed run is relabeled here.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/results/kprog_fidelity_20261106/negative/arm64-vector-clear build package run
# Repeat after the handler fix in a fresh artifact directory:
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/results/kprog_fidelity_20261106/negative/arm64-vector-clear build package run BUILD=/workspaces/repository/kprog/fidelity/build-arm64/vector-clear/after OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261106/negative/arm64-vector-clear/after
```

The first command initially returned1 for the accepted finding; the after-fix
command returns0 for rejection. Rebuilding now uses the repaired handler;
use the archived before objects to reproduce the historical acceptance.
The new fixture is also in the permanent full Arm negative suite.
