# Complete missing ARM numeric instruction forms

Extend the existing single instruction matrix with CMP/CMN immediates at
W/X widths, the ZR-destination BICS test form and all existing D0 memory
addressing modes. Production encoder/macros and the same c110b03a canonical
reference are reused; no new ISA model or production semantics is introduced.
Earlier771-form results remain unchanged.

The Make-backed incremental build and canonical replay run detached on
CPUs16-19. Results and any exact counterexamples will be retained after
completion. These are emulated observations; real ARM hardware remains
required through the static handoff. The active34-case safety guest is
independent and remains unchanged.

```sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-form-completion
```

The native assembler accepts all805 instructions, but the production encoder
rejects two new valid forms: `ldur d0, [x4, #8]` and `stur d0, [x4, #8]`, each
with `unsupported register: d0`. Its existing D0 special cases select only
LDR/STR; unscaled LDUR/STUR enter the scalar-register parser instead. The
other32 added forms encode successfully. `decoder-forms.json` retains all34
added-form outcomes; no rejected form is silently removed.

The Make build exits2 before generating/linking the new C harness, so no805
CPU/canonical pass is claimed. The old771 binary was not run by this failed
driver. `build-failure-summary.json` and the compressed unaltered log retain
the failure; `attempt-inputs.tar.gz` preserves original native assembly,
object/disassembly, production include/encoder closure and exact generator.
The10-line matrix extension remains pending source work until the parser
repair and replay pass. Production code has not been edited while the
independent original34 safety guest still consumes it; that active source
input is preserved. This is an open encoder defect, not out-of-scope work.
