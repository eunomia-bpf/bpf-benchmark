# Explicit x86 stack displacement representation

This private simulator candidate keeps explicit RSP displacements visible to Clang in10existing memory/address handler sites. Native address expressions, access widths, state updates and control flow retain their definitions. Other memory classes retain their displacement barriers. Constant stack alignment and byte ranges can therefore fold during compilation.

The actual BPF JIT, UBSan host implementation and independent byte model agree across45forms/184320observations. Five width codes cover the default64-bit route and8/16/32/64-bit accesses; eight fixed alignments plus indexed valid offsets exercise full arena bytes, readback, second reads and input retention. The mismatch stream has0bytes.

The complete original Tetragon execve_send source compiles with1355BPF instructions, compared with4826in the captured typed-read epoch. All10DWARF compiler-file entries match their MD5 and captured physical bytes. Whole-application verifier/runtime results follow the serial successor queue4152726. The full OTel compilation completes with exit0 and10439BPF instructions, compared with40034in the captured typed-read epoch. All13DWARF compiler-file entries match their checksums/current bytes; `whole-otel-compile.tar.gz` preserves the complete source/object/log and compiler-file snapshots. Complete application outcomes follow the serial runtime queue.

```sh
bash /workspaces/.agent-state/kprog-lanes/C/stack-fixed-offsets/run.sh
```

`component.tar.gz` contains exact candidate/before headers and diff, byte/JIT/host checker, executable bytecode, completed mechanism log, original Tetragon generated source/object and compiler-file snapshots. The initial fixture ABI-variable diagnostic remains with the corrected completed mechanism. The production simulator header retains its published epoch while complete applications exercise the private candidate.
