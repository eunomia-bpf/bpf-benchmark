# TCB source inventory after numeric-address repair

Every archived component/file row was independently recounted from
`counted-source.tar.gz`; all862 rows agree. Physical lines include
comments and blanks; nonblank lines include comments. These source counts do
not establish semantic safety or executable SLOC.

|Component|Files|Physical lines|Nonblank lines|
|---|---:|---:|---:|
|x86 simulator (including ISA-specific generated C)|69|6552|6278|
|arm64 simulator (including ISA-specific generated C)|70|6003|5783|
|shared simulator headers|2|43|37|
|x86 native-to-proof generator (including local imports)|9|2813|2631|
|arm64 native-to-proof generator (including local imports)|6|1725|1597|
|proof build/load orchestration|1|616|549|
|native shared loader/linker integration|13|8071|7618|
|native ELF linker (both ISAs)|2|10985|10339|
|standalone proof loader|1|1290|1196|
|application syscall shim|11|9953|9427|
|x86 native kernel module|1|988|887|
|arm64 native kernel module|1|1216|1107|
|shared native module support|1|204|185|
|x86 native module emitter support|1|206|177|
|shared binding and proof-input contracts|5|945|874|
|loader artifact-binding headers (overlap with loader)|4|345|319|
|vendored helper declarations (ABI input, not project-owned)|1|4785|4570|
|formal model, reference API and proofs (Lean, including generated)|355|40684|36275|
|formal contracts (JSON)|140|2690|2690|
|formal contract generators|140|28890|26183|
|translation-validation model, checker and proofs (Lean)|16|2362|2030|
|translation-validation source and ELF extraction|8|454|425|
|constant-op dispatch generator|1|97|90|
|native-proof kernel patch and application (patch text, not SLOC)|2|688|643|
|existing verifier context (not incremental kernel changes)|2|27873|24752|

The loader-binding header row and selected binding-function spans overlap with
the full loader/module scopes; do not add overlapping views into one total.
`binding-functions.json` retains exact selected function spans. Generator
counts include local project imports and simulator counts include ISA-specific
generated C; shared headers are shown separately. External libraries and the
compiler/toolchain/kernel/Lean trust dependencies remain separate.

Kernel differences against the recorded base span13 files:
1197 added and123 deleted lines. `kernel-changes.tsv` retains each
file, while the native-proof patch-text and existing verifier-context rows
show different scopes. All earlier inventories remain unchanged.

This is an exact captured working-source inventory, including concurrent lane
work and the uncommitted numeric repair at capture time. `provenance.txt`
retains repository/kernel revisions and dirty status; the counted-source
archive supplies the actual bytes, without implying they were all committed.
The count is neither a before/after LOC delta nor a whole-program proof claim.

```sh
taskset -c 16-23 python3 kprog/fidelity/tcb.py --out kprog/results/kprog_fidelity_20261106/tcb/after-numeric
```

`count.log.gz` retains the result and each archived byte count is validated.
