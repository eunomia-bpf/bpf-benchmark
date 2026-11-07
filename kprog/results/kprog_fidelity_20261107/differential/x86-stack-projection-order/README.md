# Preserve stack projection evaluation order

The actual BIOSNOOP native block at0xd6 compares RAX with the native address
represented by the private stack alias R14. Its trusted-service failure in
C's `run-20261107T104637164250Z.tar.gz`, request20, is preserved in
`biosnoop-original-verifier.log.gz`. Recompiling that exact generated C source
with the unchanged production header emits Bpc244 `r6 -= r1`, where r1 is
fp-72 and r6 is the scalar native entry-stack base. The verifier refuses
`math between fp pointer and register with unbounded min value is not allowed`.
This is not a reason to omit the CMP, change its flags, assume disjoint pointers
or bypass proof verification.

The numeric observation is `(private_pointer - arena_top) + native_base`.
LLVM had reassociated it to `(native_base - arena_top) + private_pointer`.
The production fix places the existing empty value barrier after the unsigned64
pointer difference and before adding the native entry base. Both compute the
same modular64 value; there is no new state, tag, branch, bound or assumption.
With that sole header change, the SAME archived BIOSNOOP C bytes emit the
relative offset plus native base at the comparison, without scalar-minus-fp.
The before/after source SHA256 is identical; compiler commands, full BPF
assembly, object hashes and both compiled objects/source are retained.
Actual application admission is a separate result: C's next complete BCC replay
uses the current header; no new BIOSNOOP application-pass claim is made here.

Validation on CPUs16-23:

- All47 existing stack/alias/CMOV sequences:48,128 real CPU/C/canonical cases,
  zero differences, with every form retained in `after/cpu/forms.tsv` and
  `reference-forms.tsv`.
- The native-only common service rejects29/29 unsafe entries (22verifier,
  6specialization,1loader noEXIT), and executes9/9 safe controls with result0,
  retval2. Unsafe native entries remain load-only. Exact receipts, complete
  errors and generated artifacts are in `after/safety/requests` and the
  compressed outcome JSON. Existing kernel/module/loader were reused; their
  before/after hashes are retained, with any concurrent rebuild drift recorded
  in `summary.json` rather than hidden.
- A small map-value/stack-alias CMP control executes correctly before AND
  after. It does not reproduce the compiler's problematic register schedule;
  the actual archived BIOSNOOP object is the code-generation reproducer.
- Six existing affected routing hosts are queued behind current full checks;
  their status is independent of the completed CPU/service results. No full
  post-barrier formal pass is claimed. The earlier whole source checkpoint
  passed and is separately archived under `x86-sp-current-integration`.

Commands from the repository root:

```sh
bash kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order/run-before.sh
bash kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order/run-after.sh
bash kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order/run-safety.sh
python3 kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order/check-focused.py
```

The codegen recipe uses the C source in the preserved artifact tar; extract it
to `kprog/formal/build/fidelity-projection-order/biosnoop.c` before a repeat.
Use a fresh request journal for repeat service runs. No image/kernel rebuild,
application workload edit, canonical ISA change or paper edit is part of this fix.
