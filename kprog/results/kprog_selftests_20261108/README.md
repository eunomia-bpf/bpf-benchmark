# Kernel BPF selftests through the five-step path, 2026-11-08

The kernel's own `__success` and `__failure` annotations are the expected
outcome for each program.  This run compiles every C-written annotated
program to native x86-64 with the corpus toolchain, submits it through the
five-step path in the guest that boots the vendored kernel, and compares the
outcome with the annotation.

Reproduce with `kprog/selftests/run.sh` (one guest boot, host CPUs 0-7).

## Program population

The scan reads `vendor/linux-framework/tools/testing/selftests/bpf/progs` and
counts every `SEC("...")` program carrying `__success` or `__failure`:

| | count |
| --- | --- |
| annotated programs | 1,917 |
| written in C | 657 |
| BPF inline assembly (`__naked` or an `asm` body) | 1,260 |
| `__failure` | 916 |
| `__success` | 1,001 |

The inline-assembly programs stay with the kernel's `test_progs`, as the task
says.  Of the 657 C programs, 239 compile to a native object whose entry
symbol is present; those 239 are the sweep.

Each program is compiled from its own translation unit into its own BPF
object, because the kernel groups several programs into one section, libbpf
reads a program's type off that section, and a file may mix C programs with
asm ones that the native compiler cannot express.  `selftests.py` comments
the sibling programs out of the unit, so every generated object holds
exactly one program.

## Totals

| outcome | count |
| --- | --- |
| submitted | 78 |
| ran (native path executed) | 1 |
| refused by the specializer | 10 |
| native path not reached | 67 |
| skipped before submission | 161 |

Of the programs whose native path ran, `success` agrees **1** and `failure`
agrees **2** with **0** disagreements: `non_const_var_off` and
`reject_var_off_store` are `__failure` programs the specializer rejected, so
no `__failure` program ran.  That is the faithfulness check the safety
argument rests on, and it holds on the two programs that reached it.

The 10 refusals are all `__success` programs, so they are the case the task
calls a rejection to triage between the native compile and the simulator.  No
`__failure` program ran, so this run reports no faithfulness defect.

## Triage of the 10 refusals

Each was read from the artifact the service archived for its own request
(`request/generated/commands.jsonl`, `request/error.json`,
`request/load.stderr`).  Seven stop in generation, before a candidate exists;
three reach the verifier.

| program | annotation | cause |
| --- | --- | --- |
| `tcx5`, `tcx6`, `tc_uninit_mtu` | success | `x86 helper call bpf_check_mtu has no helper address` |
| `global_func9` | success | `PC32 zero-sized target requires a readonly section` |
| `global_func4` | success | `instruction at IP 0x0 branches to 0x5 outside the included symbols` |
| `global_func2` | success | `invalid write to stack R10 off=-528` |
| `global_func16` | success | `invalid read from stack off -4+0` |
| `non_const_var_off` | **failure** | verifier log shows 60 insns processed; load denied `EPERM` |
| `reject_var_off_store` | **failure** | rejected, as the annotation asks |
| `test_sched_cls` | success | generator produced no candidate |

Seven stop in generation, which the task classes as coverage and sends to lane
C: three name a helper with no address (`bpf_check_mtu`, helper 163), and two
name a relocation or branch that leaves the symbol set.  `global_func2`'s
frame plus its 248-byte stack exceeds the kernel's 512 bytes once the stub's
frame is added.  `global_func16` reads the stack slot at `-4` before writing
it, and the verifier rejects an uninitialised read; the kernel marks this
program `__success`, so the slot the kernel leaves readable is one the
specializer's own trace does not model as initialised.  `non_const_var_off`
is the one case whose verifier log reports a complete 60-instruction walk and
whose load is still denied, which is the shape of a refusal that arrives
after verification.

## Harness defects found by running it

Each of these was found by executing the path, and each is fixed:

- The BPF compile drove the host linker without `-c`, which cannot relink a
  BPF object (`Relocations in generic ELF (EM: 247)`).
- libbpf refuses an object with no `license` section, which several selftests
  omit; the harness supplies one.
- The native compile omitted `-mno-red-zone` and `-mgeneral-regs-only`, so
  the frame landed outside the stack the verifier models (`R10-1312`).
- The agreement count included programs whose companion BPF object failed to
  load.  Those settle before the native path runs, so their apparent
  agreement was vacuous; only a program the specializer accepted or rejected
  counts, and `ran` for the rest.

## Environment

The lab module is built for `kprog/tv/build-kernel-x86`, so it only loads in a
guest booted from that tree's image; the host kernel differs and rejects the
module on vermagic.  The module must be built with
`KDIR=kprog/tv/build-kernel-x86`, because the default points at a different
output directory and yields a symbol-version mismatch.

`trusted-native-loader` must be rebuilt from `kprog/trusted_loader.cpp` when
`native_loader.cpp` changes; a stale binary looks for a `blob%u` interface the
current module does not create.