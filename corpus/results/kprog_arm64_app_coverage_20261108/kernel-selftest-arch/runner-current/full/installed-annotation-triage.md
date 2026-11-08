Installed ARM kernel annotation triage

The historical d0ec5ac77 epoch contains six installed __failure programs. Each kernel request reports status0 and a native program id. Their clients then return warmup TEST_RUN EINVAL. Installation is the annotation comparison stage; actual execution retains the separate client outcome. All original streams, native P, generated C/B and request metadata remain in the referenced service archive.

| Annotation | Reached verifier/install | Installed | Stock verifier rejected | Agreement |
| --- | ---: | ---: | ---: | ---: |
| __failure | 8 | 6 | 2 | 2 |
| __success | 7 | 2 | 5 | 2 |

Twenty service requests generated and compiled B; five additional native-link failures are coverage outcomes. The original client counts remain alongside this service-stage join.

| Program | eBPF annotation rule | Native P | Generated B |
| --- | --- | --- | --- |
| size_not_bpf_dw | A kptr slot uses an aligned eight-byte BPF_DW access. The annotation requires kptr access size must be BPF_DW. | After a successful array lookup, str wzr,[x0,#8] writes four zero bytes at value offsets8..11. | B203 adds8 to the map value and B205 performs a u32 zero store. |
| misaligned_access_write | The eight-byte kptr slot begins at offset8; an access overlapping that slot uses its exact field offset. The annotation expects expected=8 off=7. | stur xzr,[x0,#7] writes eight zero bytes at offsets7..14. AArch64 ordinary Normal-memory unaligned access permits this address; the kptr field rule is an eBPF type/ownership rule. | B203 adds7 and B205 writes u64 zero through that address. |
| misaligned_access_read | The source u64 read at offset1 overlaps the kptr at offset8, and its annotation requires expected=8 off=1. The companion BPF object retains a u64 load at offset1. | Native clang narrows the int-returning expression to ldur w0,[x0,#1], reading only offsets1..4 within buf[8]. | B204 reads u32 at map-value offset1, matching the native four-byte read. |
| reject_bad_type_match | A stored unreferenced kptr matches its pointee BTF type at the fixed pointer offset. Adding4 to prog_test_ref_kfunc makes the stored value an interior pointer; annotation expects invalid kptr access with untrusted_ptr_prog_test_ref_kfunc. | ldr x8,[x0,#8]; cbz x8; add x8,x8,#4; str x8,[x0,#8] loads, offsets and stores the pointer bits. | B203 loads u64 at8; B206 adds4; B207 stores u64 through map+8 after the branch. |
| reject_untrusted_store_to_ref | A referenced kptr slot changes through the ownership-aware kptr exchange interface. A plain BPF_STX store to that slot triggers store to referenced kptr disallowed, even when it stores the value just read. | ldr x8,[x0,#16]; cbz x8; str x8,[x0,#16] performs the volatile source round-trip to ref_ptr. | B203 reads u64 at16 and B206 writes the same value to map+16 after the branch. |
| reject_indirect_global_func_access | The global write_func(int *) receives map+5 and writes four bytes42 at offsets5..8, overlapping the kptr field at8. The annotation enforces kptr cannot be accessed indirectly by helper for the global-call memory argument. | add x0,x0,#5; bl write_func; callee stores w0=42 through its argument and returns42. | B210 adds5 and B213 writes u32 42 after modeling the local native call. |

The narrowed misaligned_access_read native load touches buf bytes1..4. Its original companion keeps an eight-byte load touching bytes1..8. The annotation comparison therefore records a finding while source-to-native access-range interpretation stays explicit. The other five cases retain their concrete access widths and offsets in P/B, with kptr type and ownership semantics at the resource/verifier interface.

The captured source P and B use the retained array_map resource ids. Each is an ARRAY(key4,value32,max1). The producer metadata records map shape and ids; kernel facts retain source BTF ids. The current companion ELF BTF has map_value offsets0/8/16/24, with kptr_untrusted and kptr TYPE_TAG references to forward pointee declarations. The historical companion load itself succeeded. Exact kernel map BTF field records remain an investigation item; installed outcomes and actual P/B operations are established by the archived bytes.

installed-annotation-triage.json records exact request/native identities. installed-annotation-disassembly.tar.gz contains the read-only disassemblies and source. The full direct source0 catalog runs from2e9a11f3d with fresh object-created resources; its outcomes will provide the next resource-context epoch. Runtime admission additions:0.
