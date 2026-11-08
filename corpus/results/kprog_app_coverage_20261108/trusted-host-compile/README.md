# Fresh trusted compiler transport

Whole OTel binds the native unwinder and then reaches a Clang memory frontier in its12GiB guest. `kprog/trusted_compile.py` lets the same registered specializer send each fresh generated source to a compiler process on the Workspace host through its private shared request directory. The worker still generates from the kernel-owned native submission, and the same kernel verifies and binds the returned artifact.

The compiler command retains O3, BPFv4, debug info, the4096-byte compiler frame option, architecture selection and include paths. The transport admits canonical generated request paths within the configured private service scope, matching source/architecture identity and a fresh output. Jobs carry source/object hashes and measured compiler wall/CPU time and peak RSS. A file lock assigns one broker owner. The existing application producer continues to submit native programs.

Eight controls cover fresh Clang compilation and direct object-code equality, preserved existing outputs, source digest mismatch, scope, architecture, argument protocol, actual compiler errors and exclusive broker ownership. `component.tar.gz` captures source, controls, commands, responses, source/object identities and compiler measurements. Whole-application replay supplies the VM/application acceptance receipt.

```sh
python3 /workspaces/.agent-state/kprog-lanes/C/check-trusted-compile.py
python3 kprog/trusted_compile.py serve --scope PRIVATE_RUNTIME --state PRIVATE_RUNTIME/broker
python3 kprog/trusted_compile.py submit --state PRIVATE_RUNTIME/broker --source REQUEST/generated/trusted_x86.bpf.c --output REQUEST/generated/trusted_x86.bpf.o --arch x86
```
