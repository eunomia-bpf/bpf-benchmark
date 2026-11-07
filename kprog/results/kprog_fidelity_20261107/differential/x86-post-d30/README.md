# Current d30 production x86 CPU differential

The detached existing Make build/run exited 0. Completed=True; 1080 forms, 1105920 cases, 0 CPU/C mismatches. Per-form counts are in forms.tsv; mismatches.jsonl.gz retains every counterexample with input/output states and memory.

The actual compiled header SHA256 is d30d4ff18738cc24ab19776b986bc340fe8a4b8d6a539f4e0bb3008de3895327. The executable, generated C/assembly, production include/import snapshot and observer source are preserved losslessly with hashes. This is the existing 1080-form matrix on the owner d30 header snapshot; the source was not yet published when captured. Root-source drift is retained separately: F added 64 same-register XOR forms after this generation completed. The actual pre-change generator is in compiled-inputs.tar.gz. This run contains no self-XOR forms and cannot independently validate the new self-zero gate. A separate follow-up covers them.

The observer compares all captured GPRs, XMM0, 64 stack bytes, 256 external memory bytes and every defined arithmetic flag. Undefined flags follow the unchanged existing masks. No fresh canonical comparison, complete O1-O4 proof or invocation/ABI claim is made here.

~~~sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=x86
taskset -c 16-19 make -C kprog/fidelity run-built ARCH=x86 CASES=1024 OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/x86-post-d30
~~~


## Source publication and independent result review

All1080 per-form rows contain1024 cases and0 mismatches; total1,105,920.
The compressed counterexample stream is empty, and the decompressed static
executable matches the recorded SHA256. Every actual compilation archive
member matches its independently recorded hash. All82 copied production
header/import sources match published commit af2f58c899d99f4092a710734ceb4cdac2b5e6df
byte for byte. verification.json lists those exact source identities.

The source was uncommitted at capture time; this later publication comparison
does not rewrite that history. The sole surrounding source drift is F's
subsequent addition of64 same-register XOR forms. The original generator
bytes are independently verified in the pre-build archive. The new forms
are handled by a separate serial replay and are absent from this result.
