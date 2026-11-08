# Generic call-context layout measurement

This private compiler experiment clones simulator labels by the existing ABI analysis context. Native CALL still writes its actual continuation to the modeled stack; SUB_RET reads the actual saved word and switches over the finite destinations recorded by the same analysis. Every native operation/address/value remains represented. The experiment targets Tetragon's compiler-frame capacity.

Three generic direct/nested/finite-indirect call profiles match actual CPU, UBSan host and BPF-JIT across196608observations. The offline JIT adapter supplies numeric SP0 and a rejected-edge test reporter; original verifier bytecode preserves the invalid-call dispatch guard. Exact sources, native objects, original/adapted bytecode and adapter records appear in `component.tar.gz`.

The complete original event_execve source compiles successfully:2438native instructions expand to3795analysis nodes/29contexts across7subroutines. Its BPF representation grows from11824instructions/frame1272 to29598instructions/frame1848. This measured layout increases register/stack pressure, so the current whole-application cohort continues with the previously captured generic typed-stack profile. The compiler-frame frontier remains active work.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/context-render/controls.sh
sh /workspaces/.agent-state/kprog-lanes/C/context-render/run.sh
```

The archive includes the original runtime capsule identity, generic generator/ABI before-candidate-diff, complete generated source/object, controls and compiler logs. These are mechanism/compiler observations; universal simulator laws and whole-application acceptance retain their own evidence domains.
