# Generic x86 narrow register read identity

The private BPF representation expresses8/16-bit reads through exact masks and32-bit reads through the BPF w-register constraint with a self MOV32. Its full64/default-width and high-byte behavior follows the canonical register-read contract. The host arm uses the existing width/lane expression. The generated native instruction and comparison semantics retain their captured inputs.

Ten width/lane forms complete655360compiled BPF JIT/host/independent-byte observations with equal results and preserved input memory. Extracted BPF bytecode records the32-bit zero extension as one MOV32. The diagnostics retain the preceding typed-C and compiler-modifier attempts.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/typed-read-identity/Makefile shape check
```

`inputs.tar.gz` preserves exact mechanism sources/BPF/host/JIT executable, all case streams and the frozen whole-OTel C input. `checks.log.gz` covers completed mechanism commands. The full OTel source compile completed with exit0; its terminal evidence is in `whole-otel-compile.*`. Current Cilium runs first, then the queued entire OTel/Tetragon/Tracee trials consume this same generic representation serially. Production simulator headers retain their published epoch. The universal readAt value/lane interface remains the formal obligation.


The complete frozen perf_unwind_native source compile now exits0. The current proof has40034BPF instructions versus39550in the prior aligned-stack epoch. DWARF source MD5 values match all13recorded file entries; exact compiler-file snapshots, object/source SHA256 and full output are retained in `whole-otel-compile.*`. The queued whole-app execution supplies the ensuing verifier/runtime result.
