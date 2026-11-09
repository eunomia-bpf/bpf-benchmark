# Native exit and stack lifetime contract

Lane S7 implements the outer-return and below-SP contracts in both production
simulator headers. At an outer return, x86-64 preserves entry RBX, RBP,
R12-R15 and RSP; AArch64 preserves entry X19-X29 and SP, alongside the existing
X30 return identity. A differing frame reaches the existing verifier-visible
fault arm. Stack observations below current SP draw fresh input; stores and
released bytes lose their value and pointer provenance. The original volatile
memory access remains visible to the stock verifier before this forgetting.
Stack aliases, calls, libc copies/fills and ARM atomic accesses share that
lifetime. Full-width SP ADD/SUB retains its relative coordinate and the existing
numeric result/flag semantics.

Source commits: `48eb036f5`, `98013a7f6`, `da42f496c`, `117eb020a`, `088a292b0`, `f7c517c0a`, `25a373adf`, `cc245743c`.
The changes use the five-step kernel-copy/service/verifier/JIT route. Admission
gate additions: 0. Frozen workload and paper path changes: 0.

The initial GCC host probes recorded changed-frame return success and a
below-SP write7/read7 on both C models. A benign x86 host CALL probe overwrote
the below-SP slot. AArch64 instructions under qemu-user reproduced the same
callee-frame overwrite. `source-and-host.tar.gz` retains source and output.
The map-pointer return fixtures remain load-only. The below-SP fixtures retain
the audit's push/pop/call shape and select an architectural fault on the arm
where the observed word differs from the stale constant.

The ABI references are AAPCS64 sections6.1.1 and6.4.5, the kernel x86 JIT
`pop_callee_regs; leave; ret` sequence, and the ARM JIT epilogue. The
[AAPCS64 specification](https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst)
defines integer callee-save and active/inactive stack regions. The
[kernel entry documentation](https://www.kernel.org/doc/html/latest/arch/x86/entry_64.html)
identifies interrupt/exception stack frames. Existing x86 native compile recipes include
`-mno-red-zone` at `micro/programs/Makefile:16` and `kprog/test/Makefile:31`.

The final GCC and Clang host runs pass the nineteen register/SP changes,
preserved frames, allocated/released/below-SP cells, cross-SP writes, ghost
provenance, helper outputs, ARM atomics/libc reads and the x86 RSP recovery
destination. Seven existing storage-geometry sweeps preserve their complete
case domains with an explicit allocated-frame environment; the geometry log in `source-and-host.tar.gz`
retains every banner. The two current standalone host oracles reproduce with:

```sh
# From the repository root, choose cc or clang and each oracle name.
taskset -c 8-23 cc -w -O2 -I. -Ivendor/libbpf/src \
  kprog/formal/oracles/test_invocation_exit_host.c -o /var/tmp/kprog-tmp/S7/exit-x86
taskset -c 8-23 /var/tmp/kprog-tmp/S7/exit-x86
taskset -c 8-23 cc -w -O2 -DTEST_ARM64 -I. -Ivendor/libbpf/src \
  kprog/formal/oracles/test_invocation_stack_host.c -o /var/tmp/kprog-tmp/S7/stack-arm64
taskset -c 8-23 /var/tmp/kprog-tmp/S7/stack-arm64
```

Final micro compilation is29 standard cases plus `unchecked_packet_read` on
each ISA, all30 compiled per ISA. The four tables in `micro.md` identify the
programs, compilation times and BPF instruction counts. These are compilation
results. The native-only guest suites separately exercise the production
registered service, stock verifier and positive TEST_RUN controls. Every
negative uses the existing load-only probe convention; negative TEST_RUN count0.

| ISA | Valid controls executed | New S7 cases rejected by verifier | Other negative outcomes |
| --- | ---: | ---: | --- |
| x86 | 9 | 7/7 | accepted_finding=2, specialization_rejected=1, verifier_rejected=26 |
| arm64 | 4 | 7/7 | accepted_finding=6, specialization_rejected=3, verifier_rejected=21 |

The x86 acceptance changes, `immediate_push_branch` and `stack_base_flags`,
select S9's approved known-zero read recovery. S9 retains the original expected
outcomes and owns the physical recovery/effective-address interpretation.
`summary.json` records every terminal stage and the exact acceptance changes;
the full compressed replay archives and source/runtime pins carry the request identities.
The earlier transient spilled-SP/CMOV precision diagnostics and the ARM loader,
Image pairing and compiler-sysroot setup diagnostics remain in the raw receipt.
Final paired ARM execution uses the retained recovery Image/module, current
runner bridge and the established host compiler broker with the runtime root
as its ARM sysroot.

The coordinator's07:25 decision closes the opaque-output boundary in B. Helper output arguments and libc destinations below the caller SP select the existing architectural-fault arm on both ISAs. Source routing covers26x86 and29ARM output helpers. Actual GCC and Clang host checks exercise their common output-pointer primitive, a helper destination, memcpy/memset and live-frame controls. Three additional load-only output cases perISA reach stock-verifier rejection. The earlier benign address-only observers remain in the host archive as reproduction evidence. S13/V retain universal typed-helper/frame and compiled-body composition.

AArch64 accepted original labels in this captured epoch: `unpaired_stxr_failure`, `unpaired_stlxr_failure`, `paired_stxr_failure`, `paired_stlxr_failure`, `entry_return_address_flags`, `stack_base_flags`. Every original expectation and measured stage remains in the receipts. Concurrent scalar-native policy can shift SIMD fixtures to generation rejection; protected-read recovery continues to account for the original NULL-load-trigger labels.

Generic C-to-Lean and compiled-body composition for the changed exit/stack
contracts remains under V. Four exact26-column RET row proposals appear in
`coverage-updates.tsv` and the coordination notices; V owns the ledger merge
and full check. Older whole-state host references retain their explicitly
reported stack/exit/helper lifetime alignment work. Successful native tail
transfer and its physical unwind relation remain with S11/S13. Finite host and
guest results support this source repair; the universal theorem interface
remains explicit.

All build trees, objects and guest temporaries use this lane's private var/tmp
area. Own guests run serially with2GiB; builds and guests use CPUs8-23. Initial
short standalone host probes inherited Workspace affinity; the final host
reruns are explicitly pinned, and R has that concurrency receipt. Final small
receipts are published here and the lane's own temporary outputs are retired.

The A07:35 whole-application receipt additionally identifies caller-frame equality precision for unchanged sys_enter and kprobe__cap_capable_entry. The source-and-host archive retains the precise scalar-alias equality/fault contexts and original archive paths. Current standalone spilled-SP/frame controls pass; this application-coverage integration remains explicit in summary.json.

The terminal source-captured replay records45x86 cases and the measured ARM count in summary.json. All14newS7 cases and the original stack_oob/uninitialized_stack cases reach stock-verifier rejection; all13positive controls execute, including both spilled-SP controls. Both30-case compile batches pass. Full suite diagnostic exit codes remain explicit in summary.json alongside accepted original fixtures. The requested exit/stack source repair and finite regression scope are complete; the universal proof and physical composition interfaces retain the owners recorded above.
