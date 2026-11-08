# Vmlinux kfunc relocation in the trusted proof worker

The explicit-map proof path now separates R_BPF_64_32 function calls from R_BPF_64_64 map/data loads. A function call binds its exact strong external name to vmlinux BTF and uses the same pinned libbpf prototype compatibility routine as ordinary kfunc relocation. The actual BPF verifier receives the resolved BPF_PSEUDO_KFUNC_CALL. Existing map identity/extent checks retain their code paths.

The loader checks raw CALL opcode, source/destination registers, displacement, placeholder immediate, zero addend, external linkage and function prototype. Twenty actual-function BTF/site/prototype controls pass under UBSan. The complete original Cilium proof ELF and matching kernel BTF pass their exact bpf_cast_to_kern_ctx call at byte24. Both native loader binaries build;12existing trusted-service checks pass.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/proof-kfunc/Makefile check
sh /workspaces/.agent-state/kprog-lanes/C/proof-kfunc/check.sh
```

`inputs.tar.gz` carries the exact compiled-source snapshot, original ELF, kernel BTF, source-extracted routine, controls, commands and private DSO/worker. `observations.json` pins source/binary inputs. Full command logs include the corrected harness diagnostics. Whole Cilium uses this paired caller/worker in a serial application successor; the current native-only capsule and original native/application/workload bytes remain captured.
