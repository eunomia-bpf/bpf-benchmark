# Canonical native stack pointer spill representation

The x86 C model keeps native stack bytes and verifier-shaped pointer representatives in separate storage. Full-width MOV spill/reload transfers the saved pointer representation; every raw load/store still executes. Overlapping writes and opaque helpers discard ghost facts. Existing readonly helper1/map-lookup and helper9/skb-store-bytes retain allocated caller-frame facts and discard those below SP. The generator declares one named cell for each actual storage word, without per-program safety predicates. Metadata indices keep their values before the existing architectural address-opacity barriers; architectural addresses and barriers remain intact.

The existing two raw-stack-only routing fixtures now declare the auxiliary state needed by stack writers. Original inputs, loops and assertions are retained. Their initial declaration failure and the corrected raw logs remain in the archive.

| Existing evidence | Actual result |
| --- | --- |
| Canonical source contracts and29+1micro compiler batch | exit0, 30compile rows |
| Canonical38native safety cases | {"specialization_rejected": 2, "valid_executed": 9, "verifier_rejected": 27} |
| Original helper/call/MOV/ALU hosts against identical model bytes | 5passed; original observed counts in observations.json |
| Original raw-stack lanes/arms, declarations corrected | 1,519,436cases, exit0 |
| Earlier native pointer-byte/lifetime differential | 53,544 ASan/UBSan observations,0differences |
| Captured complete Cilium policy body | frame736->376;10,475->8,849instructions |

The complete Cilium successor retains its real72resident baseline and2requests/1installed. It then reaches the existing native #DE fault model when a fresh map-count read may be zero at DIV ECX; this is recorded separately in whole-cilium-retry and Notices. No denominator check was added. Fresh BCC/Katran functional replay and current Tetragon compilation retain independent controllers. The generic erasure/compiler and helper-frame obligations remain universal O2/O4 work for V. Production admission checks, limits and per-program proofs added0.
