# ARM recovery review: H1, M1, M2, L1 and L3

The current assignment is published with concrete observations and named remaining forms. It keeps the decided SIMD fault behavior: preserve the SIMD register and base, then advance PC by four.

| Item | Result | Evidence |
| --- | --- | --- |
| H1 | Nonempty external memcpy with a SCALAR source reaches the existing architectural-fault arm before transfer. Typed and empty-copy controls retain their behavior. | Production-body probe: baseline 9 discrepancies; corrected 5,720 checks with zero discrepancies. |
| M1 | The existing full-effective-address rule forces recovery in the low 4 KiB page. | Current production-body zero-address and offset controls pass. |
| M2 | The existing DQ memory fault arm preserves V0 and the base before writeback. | Current SIMD/base/flags/memory frame and success controls pass. |
| L1 | Both kernel modules already carry the corrected CASP mask. The dropped ARM load-site collector is present again in native-link, with mask 0xbfa07c00. | Ten decoder words, code-range/literal exclusion, six words through each actual C pair-handler block, seven Rust tests and host/ARM builds pass. |
| L3 | Ten current-base native fixtures recover correctly: full-word, byte, half, word, three signed reads, LDP and pre/post-index reads. Each has two exception-table entries, live control 0xffffffff and NULL result zero. | Fourteen fixture receipts comprise ten physical recovery executions and four vector generation rejections. |

H1's explicit current assignment supersedes the older scalar-copy policy in c5ec29fed. This change leaves helper argument projection, clobbers and stack lifetime with their current definitions.

The four vector fixtures are D0, Q0 and their post-index forms. They stop at FMOV setup during generation, before installation. Commit dba3416ac deliberately removed SIMD generation under the coordinator's scalar-register production policy. The runtime rule and passing vector model controls remain intact. [The inventory](generator-inventory.json) records 40 named broader generator exclusions with exact diagnostics: non-temporal/sign-extending/exclusive pairs; acquire/RCpc and byte/half exclusive reads; unscaled-signed/unprivileged reads; CAS/CASP/SWP and other unimplemented LSE families; literal and broader SIMD/structure reads. Metadata recognition alone carries no generation claim.

The final host replay has 77 retained oracle compile/run pairs passing, including 6,144 protected-read states. Forty retired route sources produce exact missing-source diagnostics. The generator regression checks 156 accepted shapes and records 24 deliberate SIMD shape exclusions; LDADD/LDSET/LDCLR size, ordering and XZR aliases retain their fault continuations. All original 29+1 micro compile cases pass.

All 34 original safety assembly inputs reached terminal outcomes through one common HASH/XDP context and the current checked loader:

- 4 named positive controls executed successfully.
- 17 inputs were rejected by the stock verifier.
- 3 inputs were rejected during generation.
- 3 inputs reached pre-installation link-plan failures.
- 7 inputs were accepted and stayed load-only.

Negative native executions: zero. Both suite drivers retain exit 2: four deliberate vector generation exclusions in the read-fixture driver, and three pipeline outcomes in the safety driver. These receipts carry no all-pass safety claim.

The link-plan cases are map_value_oob, nullable_map_dereference and invalid_helper_argument; each retains the existing missing lookup_sites metadata diagnostic for A/coordinator. Accepted load-only cases are uninitialized_stack, four paired/unpaired STXR/STLXR failure paths, entry_return_address_flags and stack_base_flags. The latter six retain the earlier recovery-era category. The current acceptance of uninitialized_stack is new versus the historical suite: ldur x0,[sp,#-8];ret, request 12, native SHA256 a50aa1007ba884a8a4a1d12598c5a8d84a9ed25fcf3e73d68d0c07ca6768be04. Its native code stayed unexecuted. The coordinator/formal notice records that stack-model finding; S2 adds no production gate.

[The raw archive](terminal-raw.tar.gz) preserves 404 selected files, including all fourteen read-fixture receipts, all 34 safety receipts, exact input bytes, compiler/broker traces and bootstrap/retired-source diagnostics. [The manifest](manifest.json) records every member's length and SHA256; every member was reread and checked. Kernel/module/loader/linker/source hashes agree before and after both guests. The sole current kernel and root remain in use. [The cleanup record](cleanup.json) lists S2's retired rebuildable outputs and the persistent raw-directory relocation.

Production corrections: bf32780ac55d3799b7b264d371f3fef0111355f1. Common current-context fixture support: 0556b28f5c4f4f82bf2f94a7cea53b5075d2cc39. Finite replay/generator records: fc5e43b1807bbd9ea3610bac113fe0333f9f347c. Terminal receipt/archive publication: 1534d1025ffba30d85018e3ffa876190ac1063c6.

[The coverage proposal](coverage-proposal.tsv) supplies row text for V. Universal ISA, O2, compiled-B and physical fault correspondence remain explicit formal-lane obligations. The shared coverage table, full formal checker, frozen workload, papers and S1's probe work retain their owners.
