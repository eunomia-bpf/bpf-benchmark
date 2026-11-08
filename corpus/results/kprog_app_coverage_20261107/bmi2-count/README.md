# BMI2 count definedness

The ABI checker reads the architectural count bits: low8 for BZHI, low5/6 for SHLX/SHRX/SARX at32/64bits. The value operand retains its complete width dependency. This admits partial count-register initialization such as MOV r8b/SUB r8b before BZHI eax,eax,r8d. The C instruction implementation and native bytes retain their existing semantics.

The existing checker passes176encoder/ABI cases, both CL/parity packet directions and19rendered MOVX host/BPF programs. The complete original cil_to_host proof with758native instructions specializes to118975C bytes. Original refusal, native ELF, metadata and generated source remain in `inputs.tar.gz`; `checks.log.gz` retains the full command output. Whole-application replay follows the current serial OTel queue.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/bmi2-count/Makefile check
```

The33added checker cases cover count-byte initialization, exact bit masks, undefined count and value operands, and isolated high-byte initialization. Safety derives from the universal ISA/token/link interfaces and the unchanged instruction implementation.
