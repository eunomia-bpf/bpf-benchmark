# Recovery-aware native safety fixtures

The current captured scalar domain records eight accepted original labels with benign protected-read effects: two x86 and six AArch64. Their selected zero-address reads recover, preserve the return frame and reach a valid return. The retained SIMD generation domain adds the historical AArch64 vector label with the same benign classification. Observed safety-violating acceptances:0. These finite fixture verdicts support regression coverage; universal recovery, O2, compiled-body and physical exception-table composition retain V/S13 ownership.

Nine scalar-store companions preserve each original instruction sequence and replace its failure read with a store at the same scalar address. Current results give eight stock-verifier rejections and one existing SIMD generation rejection. The two-case retained-SIMD replay uses the primary ARM replay's exact recovery C/runtime plus the pre-dba3416ac generator file: its original vector label is accepted and its store companion reaches stock-verifier rejection. Production additions:0. Original fixture bytes and historical annotations remain preserved.

| ISA and domain | Cases | Valid executed | Verifier rejected | Generation rejected | Benign protected-read accepted | Safety-violating accepted |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| x86 current scalar | 47 | 9 | 35 | 1 | 2 | 0 |
| arm64 current scalar | 48 | 4 | 34 | 4 | 6 | 0 |
| arm64 retained SIMD companion pair | 2 | 0 | 1 | 0 | 1 | 0 |

S7 captured baselines: x86 45=9 valid+33 verifier+1 generation+2 accepted; ARM 41=4 valid+28 verifier+3 generation+6 accepted. S10 dd43bc633 retains ARM 34=4 valid+21 verifier+2 generation+7 accepted. Companion exclusion reproduces both S7 stage counts. SIMD policy accounts for the vector-label transition between the S10 and S7 epochs.

| ISA | Accepted original label | Current stage | Verdict and effect | Request evidence |
| --- | --- | --- | --- | --- |
| x86 | `immediate_push_branch` | `accepted_finding` | benign_protected_read: PUSH/POP produces RCX=1; the fallthrough zero-address dword load recovers with RAX=0 and RET consumes the preserved return slot. | `x86-raw.tar.gz/run/requests/21.success.tar.gz`, request 21, prog 154 |
| x86 | `stack_base_flags` | `accepted_finding` | benign_protected_read: Restored native RSP supplies the branch flags; each selected zero-address dword load recovers with RAX=0, followed by the preserved RET. | `x86-raw.tar.gz/run/requests/31.success.tar.gz`, request 31, prog 215 |
| arm64 | `unpaired_stxr_failure` | `accepted_finding` | benign_protected_read: The exclusive-status failure arm selects a zero-address W0 load; recovery clears X0, followed by SP restoration, W0=2 and RET. | `arm64-raw.tar.gz/run/requests/22.success.tar.gz`, request 22, prog 145 |
| arm64 | `unpaired_stlxr_failure` | `accepted_finding` | benign_protected_read: The release-exclusive-status failure arm selects a zero-address W0 load; recovery clears X0, followed by SP restoration, W0=2 and RET. | `arm64-raw.tar.gz/run/requests/24.success.tar.gz`, request 24, prog 158 |
| arm64 | `paired_stxr_failure` | `accepted_finding` | benign_protected_read: Either exclusive-store status is safe: success returns directly; failure selects a zero-address W0 load and recovery, then restores SP and returns2. | `arm64-raw.tar.gz/run/requests/26.success.tar.gz`, request 26, prog 171 |
| arm64 | `paired_stlxr_failure` | `accepted_finding` | benign_protected_read: Either acquire/release-exclusive-store status is safe: success returns directly; failure selects a zero-address W0 load and recovery, then restores SP and returns2. | `arm64-raw.tar.gz/run/requests/28.success.tar.gz`, request 28, prog 184 |
| arm64 | `entry_return_address_flags` | `accepted_finding` | benign_protected_read: The LR-dependent arm selects a zero-address W0 load; recovery clears X0 and preserves X30 for RET. The other arm returns2. | `arm64-raw.tar.gz/run/requests/34.success.tar.gz`, request 34, prog 221 |
| arm64 | `stack_base_flags` | `accepted_finding` | benign_protected_read: The restored-SP comparison selects a zero-address W0 load; recovery clears X0 and preserves SP/X30 for RET. The other arm returns2. | `arm64-raw.tar.gz/run/requests/44.success.tar.gz`, request 44, prog 282 |
| arm64 | `scalar_vector_load_clear_high` | `specialization_rejected` | benign_protected_read: The scalar D0 load clears the upper vector half; its selected zero-address X0 load recovers with X0=0, then W0=2 and RET preserve the entry frame. | `retained-vector-raw.tar.gz/run/requests/1.success.tar.gz`, request 1, prog 7 |

The TSV and JSON tables carry every accepted label, native SHA256, service request/status, loaded program ID, archive identity and generated C/B artifact SHA256. The store table carries every companion result and the corresponding verifier diagnostics. Complete request, compilation and verifier logs accompany the raw archives. summary.json carries the captured source/runtime hashes and all original-stage counts.

Execution reuses S7 runtime recipes with one serial2GiB guest at a time, CPU8-23, and private mount namespaces. Each negative producer has argc3 and performs load only; positive controls carry TEST_RUN arguments. Negative native executions:0. Both ARM transport receipts record QEMU0 and unchanged inputs. Make/guest diagnostic exits preserve the suite convention for accepted original labels; every selected case has a terminal receipt.

Numeric SP/LR observations use the invocation-stable native entry inputs through `ARM64_SIM_L_MATERIALIZE`; the relative stack/return payloads retain their indexing role. The S7-to-S16 source comparison records matching captured source/runtime hashes on every shared identity key.

Source predicates: `X86_SIM_L_READ_RECOVERY_AT` and `ARM64_SIM_L_READ_FAULT` select protected-read recovery for scalar effective addresses in the low4KiB page; their store bodies perform the ordinary verifier-visible write. The retained vector epoch changes the generator domain only and preserves primary ARM header/runtime hashes. Actual service/kernel receipts establish the tested route; safety claims retain the universal proof boundary above.
