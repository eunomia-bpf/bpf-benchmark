# Original ELF BTF for proof kfunc declarations

The trusted proof worker reads the kfunc declaration from the same original ELF byte snapshot as its validated instructions and relocations. libbpf opening normalizes .ksyms function linkage to GLOBAL, while the original ELF retains EXTERN. The loader now checks original linkage and the unchanged kernel prototype matcher together. The raw BTF reader checks exact section identity, extent, uniqueness and parse result.

Both actual complete Cilium proof ELFs exercise libbpf opening, observe its linkage normalization, retain the strict refusal on the normalized BTF input, then resolve the original ELF declaration correctly. Each ELF passes21actual-function BTF/site/prototype controls under UBSan; its call is at16or24bytes respectively. The private DSO/worker build exits0 and12existing service checks pass. Existing map identity and relocation code paths retain their behavior.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/proof-kfunc-original-btf/Makefile check
sh /workspaces/.agent-state/kprog-lanes/C/proof-kfunc-original-btf/check.sh
```

`inputs.tar.gz` retains both original ELF patterns, matching kernel BTF, exact production/extracted-source snapshots, regression controls, commands and paired private binaries. Full command output is in `build.log.gz`/`check.log.gz`; source/binary identities are in `observations.json`. A whole Cilium successor consumes the paired binaries after the current serial OTel/Tetragon/Tracee queue.
