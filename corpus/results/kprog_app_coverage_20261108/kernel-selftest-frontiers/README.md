# Current x86 kernel C selftest generation frontiers

The current canonical specializer and native linker replay the original native objects from R's selftest build. `make -f /workspaces/.agent-state/kprog-lanes/C/design-only/kernel-selftest-frontiers/Makefile component` records the commands. The kernel annotation sweep remains R's task; these are host generation and compiler observations. The four original native hashes accompany every row. Metadata uses the original program type and section; `global_func9` reaches its local ELF data diagnostic during native linking, before map declarations affect generation.

| Original kernel C program | Generation and compiler | BPF instructions | Maximum FP-relative extent |
| --- | --- | --- | --- |
| global_func2 | compiled | 1174 | 1128 |
| global_func4 | compiled | 28 | 0 |
| global_func9 | local .data section identity needs mutable resource lowering | 0 | 0 |
| global_func16 | compiled | 44 | 48 |

`global_func4` needs native tail-branch coverage: its original entry contains `E9 rel32` with a PLT32 reference to `f7`, followed by the chain f7/f6/f5/f4/f3/f2/f1. Current discovery follows E8 PLT32 calls; this entry retains only one symbol. Encoding shortens the unresolved JMP to two bytes while the four-byte relocation remains at offset1. The generated C interprets its target5 as entry fallthrough. The old kernel-stage rejection remains the available end-to-end receipt. This component establishes a link/generation frontier; stock-verifier acceptance and native execution retain their own evidence stages.

`global_func16` keeps the original C array declaration and stack read before a write. Its C compile and the stock-verifier initialized-memory judgment occupy separate stages. `global_func2` now measures the canonical representation's compiled frame beside the older stock stack rejection. `global_func9` retains its writable `.data` section identity in the original input; ordinary map/resource lowering is the next link operation for this class.

The corpus native compiler uses its native context ABI. R's current source objects use upstream BPF context structs (for example f1 reads `__sk_buff.len` at offset0). Context representation belongs in the sweep's native compile/entry-ABI triage before interpreting annotation differences. Canonical skb simulation exposes the actual kernel skb offsets. Original source, objects, generated C/BPF and diagnostics are in the archive. Runtime admission additions0; production source adoption0.
