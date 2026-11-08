# Kernel selftest helper coverage on x86

The shared x86 simulator and native linker now represent Linux helper105 `bpf_strtol` and helper163 `bpf_check_mtu`. The upstream kernel selftests `verifier_const.c` and `verifier_mtu.c` exercise their writable globals, readonly globals and stack destinations. R's recorded generation frontiers identified both missing IDs. This change adds their ordinary public-ABI call bodies and ID mapping; the existing sparse dispatch mechanism now carries70helpers.

`bpf_strtol` forwards its buffer pointer, native-width length,64-bit flags and native-long result pointer. `bpf_check_mtu` forwards the original helper context, u32ifindex, u32output pointer, signed32length difference and64-bit flags. Both use the existing scalar-result and caller-clobber model. The kernel helper and stock verifier retain their normal memory-write behavior.

| Existing verification | Result |
| --- | --- |
| Linux ID/slot host oracle, UBSan | 4,100cases; exit0 |
| Typed ABI, register and caller/callee-frame oracle, UBSan | 19,458cases; exit0 |
| Generated and independent helper-dispatch Lean modules | both compile0 |
| Native-link unit tests | 89pass;0fail |
| Workload-derived29positive+1negative-native compiler batch | 30rows; make0 |

Commands use the retained Makefile:

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/helper-selftests/Makefile check lean micro linker-test
```

`observations.json` identifies every before/after source hash and actual compiler exit. `compiler-and-abi.tar.gz` retains sources, raw outputs, micro objects, existing helper oracle executables and the two Lean outputs. Its initial Lean search-path diagnostic accompanies the corrected namespace and successful component run. The tool's existing physical executable mode retains its shared-worktree owner; the private-index commit carries only the helper source lines and generated changes.

R owns the complete kernel annotation sweep and its direct native submissions. The updated release linker follows the currently captured Tracee guest, preserving that guest's existing binary/source epoch. Original readonly writes and uninitialized-memory cases continue through the same verifier helper prototypes; their actual accepted/rejected outcomes belong to the ensuing complete selftest receipts.
