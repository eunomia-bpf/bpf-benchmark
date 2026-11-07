# Real-CPU LEAVE64 canonical-boundary and wrap evidence

One instruction form, C9 LEAVE64, was run in33 boundary/input classes of1024
random GPR/flag states each, on this host and in KVM. Each profile completed
33792 cases; the unchanged default8-class interface also passed8192 cases.
All75776 cases preserve the expected16 GPRs and full flags, after removing
exception-delivery RF on fault only, and produce no mapped-page writes.
Faults retain the incoming RSP/RBP and fault PC. Valid frame plus a
noncanonical old RSP succeeds. Raw inputs/outputs/traps/errors are retained.

| Input | Host with LASS exposed | KVM without LASS exposed |
|---|---:|---:|
| Last8 bytes below the48-bit positive canonical gap |1024 #PF|1024 #PF|
| Starts1 through7 bytes later, spanning that gap |7x1024 #SS|7x1024 #SS|
| First upper canonical address ffff800000000000 |1024 #SS|1024 #PF|
| Last word before64-bit wrap |1024 #SS|1024 #PF|
| Starts1 through7 bytes later, wrapping across zero |7x1024 #SS|7x1024 #PF|

The KVM wrap cases report #PF, including each crossing case. A rule that
rejects wrapping ranges with #SS would differ from these native observations.
This demonstrates fault outcomes, not successful loads across wrap; the
addresses are inaccessible at CPL3. The positive canonical-gap crossings
fault with #SS before the unmapped/protected-page read could report #PF.

Independent ordinary loads through RDI (default DS) and RBP (default SS)
ran2048 cases per profile,4096 total. Their same-address controls agree with
the profile distinction: an upper canonical address gets #GP for DS and #SS
for SS on the host, versus #PF for both in KVM. `control-traps.tsv` and
`traps.tsv` give all per-class counts, derived directly from the raw records.

Both profiles report48 linear address bits and no LA57 support. The numeric
57-bit boundary inputs are therefore noncanonical48-bit tests, not evidence
for active57-bit execution. CPUID LASS support and the Linux `lass` feature
are present on the host and absent in the guest. CR4 was not directly read.
The observed distinction is consistent with Intel's LASS specification,
which gives user accesses to upper-half addresses #GP, or #SS for stack
accesses, before paging. See [Intel's programming reference, chapter9,
pages9-1/9-2](https://cdrdv2-public.intel.com/819680/architecture-instruction-set-extensions-programming-reference.pdf).
These CPL3 profiles must not be turned into a user-only address guard in a
kernel-payload ISA. No CPL0/full-JIT-ABI or canonical comparison is claimed.

The KVM run reuses the cached7.0.0-rc2+ TV kernel and exact same static
observer binaries. No kernel, module or image was rebuilt; no native BPF
payload was submitted. The guest boot requested `clearcpuid=lass`, and the
actual guest CPUID/feature reports and control outcomes are recorded rather
than assuming the parameter was effective. The runtime host report records the KVM hypervisor.
`launch-dry-run.txt` reconstructs the same vng invocation after completion;
it is a dry-run command record, not a captured actual-process argument list.

```sh
taskset -c16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries/Makefile run control default
taskset -c16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries/Makefile kvm
taskset -c16-19 python3 kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries/collect.py
```

The harness adds an optional boundary mode; its old default and assembly
observer remain available. The original8192-case static binary and previous
1024 canonical fault-type counterexamples remain unchanged. The initial
boundary build had a generated C newline/argument-edit error; its failure
log and exact failed source closure are retained as `initial-*`. The final
builds used `-Werror` and all four run targets exited0. `compiled-inputs.*`
retain the final C/assembly/control/build/collector source closure; compressed
static executables, disassembly and every raw CPU record are included.
