# Local proof calls do not request kernel symbols

The loader classified every proof BPF_CALL as a reason to resolve the kernel
helper catalogue. BPF_PSEUDO_CALL instead targets another BPF function in the
same proof. The new predicate excludes those local calls while preserving
empty/unbound proofs, real helper calls and kfunc calls. Actual source helpers,
perCPU maps and native undefined-symbol requirements remain separate inputs;
their resolver is unchanged. There is no persisted address cache.

The real scanner regression compiles the production loader and checks five
classification boundaries: empty proof, no call, local call, local plus helper,
and kfunc. It then checks that a pure linker requests no callable/CPU symbol
and compares all 114 currently present requested kernel symbol names/addresses
with an independent stream parser. All pass.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity check-loader-kallsyms
```

`check.log.gz` preserves the command output. This is a code-level redundant-work
fix with branch regression evidence, not a measured speedup. The timed stage2
workloads use helpers/maps and legitimately retain their resolution needs;
packet_5tuple_classify also has a map helper and is not a pure example. The
matched15-sample pure simple timing remains a separate request to R.
