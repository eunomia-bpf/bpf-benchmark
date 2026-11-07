# LEAVE64 canonical replay of saved real-CPU states

Independent replay uses the same8192 captured C9 LEAVE64 states from the
parent result: one instruction form, eight classes of1024 cases. No CPU
rerun and no second ISA semantics. The adapter only serializes native inputs
and compares outputs. It checks all16 GPRs, full RFLAGS after removing
exception-delivery RF only on a fault, PC, captured operand memory bytes and
permissions, and modeled fault presence/kind/address/width. SIMD and segment
state were not measured by this native fixture and are not claimed.

The exact single-reference source snapshot is pinned in source-pins-before.json
and archived with the adapter, Makefile and configuration. At capture, the
LEAVE file was V-owned uncommitted work; publication identity must be checked
separately. The isolated reference cache is seeded from the earlier build;
the historical f1 reference cache and canonical-before refusals are untouched.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64/canonical-current/Makefile reference-build
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64/canonical-current/Makefile reference
```

## Completed candidate result

The independent reference build passed. Replay compared all8192 cases:
7168 exact matches,1024 mismatches,0 unavailable classes; replay Make exited2.
All mismatches are the noncanonical_frame class. Real CPU trap12/#SS/SIGBUS7
requires the modeled non_canonical fault, but this candidate reports
read(address=incoming_RBP,bytes=8). All16 GPRs, normalized full flags, PC and
captured memory match in every case, including the1024 fault-kind mismatches.
The seven other classes have1024 cases and zero differences each.

mismatches.jsonl.gz retains all1024 complete inputs, CPU observations and
canonical answers. This is a failing candidate receipt, not a pass or a
published-rule claim. V remains the only canonical writer and has the exact
fault-class counterexample; the observer/adapter comparison was not weakened.
The original canonical-before eight decoder refusals remain intact.

Source SHA is9fca3291b55b8ef0bfdfa8fab8afe8935210e5fd30f6c0314f7db53661b7afa8;
reference binary SHA is19ce57b4a4cd897ee24713031de64cfb5f79b4734dce2d47529cb57cfb1e1ae6.
The archived canonical-reference.gz is that exact failing executable. This is
not a whole-JIT return certificate or a production simulator support claim.
