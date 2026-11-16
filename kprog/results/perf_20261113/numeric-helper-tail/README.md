2026-11-16T08:27:53Z

Numeric BPF helper sibling exits now resolve through the same helper identity
analysis and direct-tail linker machinery as symbolic helpers. A finite join
emits compare/branch dispatch without changing helper argument registers. Entry
wrapping preserves the JIT epilogue; subprogram exits return to their caller.
No native compiler flags or benchmark settings changed.

Production proof extraction leaves symbolic helper JMP relocations. The shared
simulator renderer executes the existing helper operation and then the current
return operation. ABI analysis applies existing helper clobbers and follows the
saved return address, populating the generated return dispatcher.

Validation:

- `make -r -f kprog/test/native-relocations.mk check CHECK_CPUS=16`: 49 passed,
  zero failures, one existing ignored test. New native execution covers 48
  singleton/join, entry/subprogram, source/new-proof/legacy-proof cases. Helpers
  observe both arguments and SysV stack alignment; an observable JIT epilogue
  and caller continuation detect premature returns. Unknown and partial-register
  writes do not acquire a helper identity.
- A real clang fixture, compiled with the native target flags, produces helper
  7/8 tail exits. `numeric-tail-b` passes through production proof parsing,
  shared I and the B compiler. `numeric-tail-stock` accepts its B on kernel
  099357174783 with the original kprobe context and map shapes. The test cancels
  after verification; this is not application installation or timing evidence.
- The first B attempt followed the ELF placeholder and faulted. After the
  renderer fix, the missing ABI return edge reached an unresolved return.
  Both verifier failures and the final acceptance are retained here and in raw.

Full raw: `/workspaces/kprog-raw/perf/20261116-numeric-helper-tail`.
Build output: `/var/tmp/kprog-tmp/perf/helper-cfg`.
Normal release/native-link and the sole image remain unchanged pending the
coherent publication. Full-app coverage, helper-tail-call-specific semantics,
equal work and performance targets remain separate open work.

The ordinary CALL/RET copy-loop regression also passes 64 inputs in both native
and shared-simulator host executions, retaining its 72-byte stack extent and
one return continuation. See loop-regression.json.
