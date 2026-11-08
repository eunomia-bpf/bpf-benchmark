# Direct native P program context

A native request can now set source_prog_id=0 and supply its object-derived load_context in the metadata that the kernel copies with P. The existing Request64 and Submission80 layouts stay the same. The kernel retains actual resource map descriptors through SUBMIT_RESOURCES; the service queries those maps and generates B from its kernel-owned P copy. The worker creates the program with the same context, the stock verifier checks B, and the JIT emits that P. A loaded original eBPF program remains a valid context source for application requests.

This removes the original-program-load dependency that prevented upstream __failure selftests from submitting their native P. R owns upstream extraction, compilation and annotation comparison. The original eBPF verdict and the actual native outcome retain separate records.

Raw load_context carries prog_type, expected_attach_type, prog_flags, prog_ifindex, attach_btf_id, attach_btf_obj_id, attach_prog_id, gpl_compatible, source_btf_id and token_present. An optional source_func_type_id supplies the original object entry BTF prototype. The original source-ID worker argument layout stays17fixed fields; raw context uses21. Metadata permits additional fields. Map records retain native symbol, map_id and value_offset; the submitting process passes its map FDs in the existing resource array. C++ callers can supply FdLoadOptions.native_context, native_entry_function and actual trusted_maps directly.

| Component | Actual outcome |
| --- | --- |
| x86 module against shared five-step kernel | build0 |
| static/shared loader and worker | build0 |
| Existing trusted-service component cases | 8pass |
| Existing native-only producer with direct P context | builds0 |
| Existing38-case native-only suite | detached, terminal outcomes follow |

```sh
G=/workspaces/.agent-state/kprog-lanes/C/design-only/native-context
make -f "$G/Makefile" module loader probe
make -f "$G/Makefile" replay
```

The replay uses all38existing native objects and the existing ARRAY/HASH resource objects. It marks original programs autoload=false before creating their maps, then submits P with source_prog_id0. Positive controls retain their original TEST_RUN expectations; unsafe inputs are load-only. The current complete application guest retains its owner; raw replay follows it on CPUs20-23 with4GiB. The shared R module and existing active guest binaries retain their captured epochs.

`component.tar.gz` retains the exact source patch/baselines/current files, module, worker, producer, compiler commands/logs/exits and replay source. components.json records all binary identities and the unchanged shared kernel. Additional runtime admission predicates total0.
