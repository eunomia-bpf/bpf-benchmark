# Real-CPU partial-register storage observations

The C partial-register storage candidate from52e83e021 passes32,768 real x86-64 CPU,
C simulator and canonical-reference comparisons:16 native MOV forms, each through
the numeric raw dispatcher and direct specialized entry, with1,024 input states
per route. All32 groups receive canonical replay. Registers, vector state,
modeled stack bytes, architectural MOV flags and all256 memory bytes agree.
All32,768 memory observations preserve their incoming bytes.

| Native form | Raw cases | Direct cases | CPU/C / CPU/reference / C/reference differences |
| --- | ---: | ---: | ---: |
| mov al, bl | 1024 | 1024 | 0 / 0 / 0 |
| mov ah, bl | 1024 | 1024 | 0 / 0 / 0 |
| mov al, ah | 1024 | 1024 | 0 / 0 / 0 |
| mov ah, al | 1024 | 1024 | 0 / 0 / 0 |
| mov ax, bx | 1024 | 1024 | 0 / 0 / 0 |
| mov r8b, r9b | 1024 | 1024 | 0 / 0 / 0 |
| mov r8w, r9w | 1024 | 1024 | 0 / 0 / 0 |
| mov dil, sil | 1024 | 1024 | 0 / 0 / 0 |
| mov bpl, dl | 1024 | 1024 | 0 / 0 / 0 |
| mov spl, al | 1024 | 1024 | 0 / 0 / 0 |
| mov sp, ax | 1024 | 1024 | 0 / 0 / 0 |
| mov eax, ebx | 1024 | 1024 | 0 / 0 / 0 |
| mov rax, rbx | 1024 | 1024 | 0 / 0 / 0 |
| mov al, 0x7f | 1024 | 1024 | 0 / 0 / 0 |
| mov ah, 0x7f | 1024 | 1024 | 0 / 0 / 0 |
| mov ax, 0x7fff | 1024 | 1024 | 0 / 0 / 0 |

The first128 states use the common boundary sampler and the remaining896 use its
fixed random stream. High-byte cross-lanes, SPL/SP, extended registers and32/64-bit
controls share the existing observer and comparison masks. The complete per-route
counts are in forms.tsv, reference-forms.tsv and observations.tsv. Every mismatch
stream is retained as gzip; each contains zero records.

## Source and execution identity

The source epoch is da3f2f1e4ff7f7a6c6e263a4ae6c6fbe0f440c0e. The captured compilation has94
input files. Its82 simulator/import snapshot files comprise81 exact published
production files and the single C candidate kprog/formal/generated/x86_reg_write.h.
The launch's explicit source vector independently pins78 of those production
files; the transitive snapshot files match the same launch Git tree. The selected
producer reproduces all16 encoded field sets, and each raw/direct pair has equal
native instruction bytes. Captured source drift is empty.

The candidate copies the complete register representation into a volatile local
union, updates its selected byte or word and reloads all64 bits. The existing
32/64-bit write bodies retain their source. candidate-inputs.tar.gz is byte-equal
to C's published archive. The candidate stays in this harness's captured include
tree; C owns the whole Katran runtime adoption. These finite instruction
observations support the generic mechanism; V/T own the universal O1/O2/O4 laws.

| Artifact | SHA256 |
| --- | --- |
| Candidate header | ad3b3e39ea65e459dc5d3a20902d33738457e965c3c16c56c9c790e4134562d3 |
| Production header | 7d76ebfeb14bd54acccb5598f8ef3feb03dfc354c44789fedd46f9b7dd5b0279 |
| Static x86-64 observer | c83041ed74ad7c159a76d9590d7f084fadf067a0988fae7e49cfc943239584a1 |
| Frozen canonical reference | c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96 |
| Raw architectural stream | 2f26899de510265652f346c13c17374b2a0c146018d40a298db742de977c3bed |
| Compressed architectural stream | bf117f5787df4bf4594532c12bb216c16c7a9da8b7a14627c34b3a286fa90ecd |

The architectural stream occupies59,506,712 raw-equivalent bytes and19,461,286
compressed bytes. trace-storage.json records the verified decompressed identity.
The compressed full-state stream stays in the Workspace result directory.
The source archives, static observer, tables, diagnostics and collection scripts
are published here. The compiler's raw-chain narrowing diagnostics remain in
run.log.gz. The shared CPU observer and canonical replay both exit0.

## Commands

Run from /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-partial-gpr-candidate/Makefile reference
python3 kprog/results/kprog_fidelity_20261107/differential/x86-partial-gpr-candidate/review.py
~~~

The Make command creates the raw trace; the detached wrapper captured in
launch-inputs.tar.gz performs source/static collection and verified compression.
For a saved stream, zstd -d -k cpu-states.bin.zst restores cpu-states.bin.
The reviewer reads the compressed stream directly.

The first collection attempt reached a KeyError for a transitive shared Python
import outside the explicit launch vector. review-initial.json and its gzip log
preserve that diagnostic. The collector now checks explicit launch pins and all
production snapshots against the launch Git tree, and its final exit is0.
The observed execution and architectural streams retain their original bytes.
