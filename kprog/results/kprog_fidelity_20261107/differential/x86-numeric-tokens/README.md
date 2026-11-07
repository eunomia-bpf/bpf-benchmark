# Four numeric x86 tokens: raw and direct CPU replay

ADD_IMM, ADD_REG, XOR_REG and MOV_LOAD_SCALAR cover 32 route/form groups
and 32,768 captured states. Real x86 CPU, compiled production C and canonical
reference comparisons all report zero differences and zero pending forms.

| Token | Widths | Raw cases | Direct cases | CPU/C/reference differences |
| --- | --- | ---: | ---: | ---: |
| X86_OP_ADD_IMM | 8/16/32/64 | 4096 | 4096 | 0 |
| X86_OP_ADD_REG | 8/16/32/64 | 4096 | 4096 | 0 |
| X86_OP_XOR_REG | 8/16/32/64 | 4096 | 4096 | 0 |
| X86_OP_MOV_LOAD_SCALAR | 8/16/32/64 | 4096 | 4096 | 0 |

The original fidelity generator supplies 16 existing native forms: ADD
immediate127, ADD register, XOR register and scalar memory MOV at four widths.
A single inserted matrix-binding block selects these forms, substitutes the
equivalent numeric token, and emits each through the production raw dispatcher
and direct macro. All operand, width, AUX and immediate fields retain their
original encoder values. Each native instruction's two routes have identical
instruction bytes. numeric-bindings.json records every original and bound field.

The existing fixed-seed stream supplies 1,024 states for each route/form.
Every CPU/C/reference comparison uses the same captured input state. The
native observer, register/stack/memory preparation and defined-flag comparison
masks retain their original implementation. selection-review.json records the
exact insertion and both generator hashes. This is sampled instruction/token
fidelity evidence. The formal lanes develop universal O1/O2 and binding laws.

Actual compiled simulator header: 47fb55656f2951df3581f5fa1695f720138ae0ab1881ec1a21d359d0587fd34a.
Generated memory header: 3ba4bc7881f88de413811befef9113c48f2591ecab77bfde88d6041eba4d0d7e.
All 93 archived compilation files match their recorded hashes; all 82
production source files match launch commit 6029a8009341f74667f1ce2e185f54818b5432ec.
status.json records source drift0 and successful exit0 at19:51:33 UTC.
The static binary hash is 51b7b4172dfdf90caca657d978123a0db8dc38df8033d7c673c2150d8cdc72a0.
The canonical binary hash is c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96;
its already published gzip is linked by the replay-input collection.

From the repository root:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-numeric-tokens/Makefile reference
~~~

The Makefile uses the existing fidelity build/reader targets, a separate small
build-x86-numeric-tokens cache, and F's frozen canonical executable.
actual-compiled-inputs.tar.gz, launch-inputs.tar.gz and the compressed static
executable preserve the actual test materials. forms.tsv and reference-forms.tsv
record all 32 form groups. The three compressed mismatch/unavailable streams
each contain zero records. The complete 59,506,712-byte trace remains in the
Workspace, SHA256 094ffa64d75ddcdcf15753d908ac0e1111453405e45b8aacecfc5436e9ab2697.

Two initial attempts ended during Python generation: nested newline quoting,
then the fidelity helper import path. initial-attempts.tar.gz preserves both
attempts' source, selection and control records plus the successful generation
preflight. The final adapter uses raw-string insertion and the existing
fidelity helper module path. The executed matrix, production source, state
observer and masks retain the same intended bindings. The live simulator,
generator, ISA reference, kernel and service continue through their owning
lanes; this result uses the captured source snapshot.
