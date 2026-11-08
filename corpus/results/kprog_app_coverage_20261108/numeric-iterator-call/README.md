# Generic numeric iterator callable ABI

One standard libbpf numeric-iterator source compiles successfully for x86-64 native and BPF targets. The current native linker preserves all four named call relocations: iterator construction, two next calls and destruction. The linked stream contains 36 native instructions.

Fresh generation then reaches ABI flag definedness at native PC0x29, immediately after the external iterator-next call and TEST. The raw generator traceback and parsed call identities are retained. Typed named-kernel-call ABI modelling is the next mechanism in the common generator and binding path.

The Tetragon source uses the same numeric-iterator API. The existing native compatibility header expands bpf_for into an ordinary C loop; CONFIG_ITER_NUM selects its 2048 iterations, and the complete application's verifier reaches an8193-jump sequence. The retained source files connect those observations. Native inputs and the current verifier budget keep their existing contracts while the iterator callable path advances.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/numeric-iterator-call/run.sh
```

The archive contains identical-source native/BPF objects, linked native proof, full disassembly, compiler logs, exact source hashes and the generation frontier. This generic API control applies across applications; complete application loading supplies its runtime evidence.
