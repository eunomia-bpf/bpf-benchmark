# Negative native-program suite, 2026-11-06

**AArch64 accepts an uninitialized native stack read.** The generated proof
returns the simulator's initialized stack bytes, so acceptance does not prove
that the native read is initialized. The accepted proof object and source are
retained. No simulator change was made to hide this result.

Eleven unsafe native assembly fixtures were tested per ISA. X86 KVM produced
8 verifier rejections, 2 compiler rejections, and 1 specialization rejection.
AArch64 full-system QEMU produced 7 verifier rejections, 2 specialization
rejections, 1 linker rejection, and 1 accepted finding. Compiler/linker failure
is reported at its actual stage; it is not counted as verifier safety evidence.

| Fixture | x86-64 | AArch64 |
| --- | --- | --- |
| Read at data_end | Verifier: `R2 pointer arithmetic on pkt_end prohibited` | Verifier: `R1 invalid mem access 'pkt_end'` |
| Write at data_end | Verifier: `R2 pointer arithmetic on pkt_end prohibited` | Verifier: `R1 invalid mem access 'pkt_end'` |
| Missing data_end check | Verifier: `invalid access to packet, off=0 size=1, R2(id=0,off=0,r=0)` | Verifier: `invalid access to packet, off=0 size=1, R1(id=0,off=0,r=0)` |
| Map value out of bounds | Verifier: `invalid access to map value, value_size=8 off=8 size=1` | Verifier: `invalid access to map value, value_size=8 off=8 size=1` |
| Possibly NULL map value | Verifier: `R1 pointer arithmetic on map_value_or_null prohibited, null-check it first` | Verifier: `R1 invalid mem access 'map_value_or_null'` |
| Invalid helper argument | Verifier: `R1 type=scalar expected=map_ptr` | Verifier: `R1 type=scalar expected=map_ptr` |
| Stack out of bounds | Compiler: `A call to built-in function 'abort' is not supported.` | Linker: `failed to find BTF for extern 'arm64_sim_unsupported_opcode' [9] section: -2` |
| Uninitialized stack read | Compiler: `A call to built-in function 'abort' is not supported.` | **Accepted**: `loaded object=/proofs/uninitialized_stack.bpf.o program=uninitialized_stack_arm64_sim_xdp fd=5` |
| Unbounded loop | Verifier: `infinite loop detected at insn 0` | Verifier: `infinite loop detected at insn 0` |
| Unbounded indirect jump | Verifier: `infinite loop detected at insn 0`; specialization defect below | Specializer: `unsupported arm64 instruction: br x1` |
| Unsupported instruction | Specializer: `unsupported mnemonic: ud2` | Specializer: `unsupported arm64 instruction: brk #0x0` |

X86's indirect-jump rejection is not faithful modeling: native `jmp rax` was
rendered as `X86_SIM_X86_JMP(0x3, 0x0, x86_l_0)`. The resulting fixed loop is
rejected, but that does not establish a correct indirect-jump translation.
The x86 stack cases also expose a practical gap: even the in-bounds
uninitialized read fails at compilation through a simulator trap. Their
rejections must not be presented as a verifier check of initialization.

Map fixtures use a checked four-byte packet region as their lookup key. This
avoids unrelated modeled-stack compilation failures while preserving the
unsafe map access. The array map has one eight-byte value; the out-of-bounds
case checks the lookup result for NULL, then reads at offset eight. The
nullable case omits that NULL check. Native assembly is retained, so the
compiler cannot silently remove the unsafe native operation as C undefined
behavior.

## Reproduce

All commands start in the repository root:

```sh
taskset -c 16-23 make -C kprog/fidelity negative-build
taskset -c 16-23 make -C kprog/fidelity ARCH=arm64 negative-build
taskset -c 16-23 make -C kprog/fidelity negative-kvm
taskset -c 16-23 make -C kprog/fidelity negative-qemu
```

X86 uses the existing framework `bzImage`, 8 vCPUs, 12 GiB, and the existing
`reversesim-loader --load-only` under virtme-ng/KVM. Its `outcomes.json`
records the guest's uname. Arm uses the existing framework `Image` (kernel
7.0.0-rc2+), QEMU's cortex-a57, 2 vCPUs and 2 GiB. A small static init driver
runs the existing cross-built proof loader in an initramfs containing its
shared libraries and these proof objects. This does not rebuild a shared
runtime image, kernel or module. Host affinity is CPUs 16–23.

The x86 final run exits 0. The Arm run exits 1 (make exits 2) because the suite
records the accepted finding. `arm64/guest-console.log` contains the entire
boot, per-case loader/verifier logs, exit statuses and completion marker.
`x86/*.log` and `arm64/*.log` contain exact case diagnostics, while each
`outcomes.json` records all 11 outcomes including build-stage failures.
`artifacts/<isa>/` retains native assembly/objects/disassembly, generated C,
BPF objects where compilation succeeded, compiler logs and build manifests.
These snapshots preserve the actual inputs from the shared dirty checkout.

The test loads verifier-facing simulator artifacts; it does not execute unsafe
native programs. It does not test native-generation binding or claim that a
proof rejection discharges whole-program fidelity. Binding is lane T's
separate obligation. No benchmark launcher or common workload was changed.


## Bound-path follow-up after the workspace restart

The original accepted AArch64 stack read above is retained as the baseline.
On the paired native-proof kernel/module, both fresh suites reject all eleven
fixtures: eight verifier rejections, one loader rejection, two specialization
rejections. There are no accepted cases or infrastructure errors.

- x86 KVM: `x86-bound-recovery/outcomes.json` and per-case logs.
- AArch64 full-system QEMU: `arm64-bound/outcomes.json`, per-case logs and
  the entire `guest-console.log`.

The eight verifier cases are packet read/write past data_end, absent packet
bounds check, out-of-bounds map value, nullable map dereference, invalid helper
argument, out-of-bounds stack and uninitialized stack. Both uninitialized
reads now fail with the native-proof region's strict initialized-stack policy;
privileged standalone simulator acceptance is not hidden or reinterpreted.
The unbounded direct loop produces a proof with no EXIT and the production
loader rejects it with `native_kernel bound proof contains no BPF exit`.
The unbounded indirect jump and unsupported opcode reject during
specialization. None of these rejection-stage outcomes counts as a successful
native program execution or as an application coverage result.

The static Arm probe uses the production manifest/loader, native-link, module
and proof seals. Its simulator is the actual compiled fixture, paired through
`simulator_object`/`simulator_program`; unsafe native programs are never run.
No shared kernel, module or runtime image is replaced by these tests.

```sh
taskset -c 16-23 make -C kprog/fidelity bound-probe-build
taskset -c 16-23 make -C kprog/fidelity negative-bound-kvm NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/x86-bound-recovery
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu
```

These commands consume T's paired `kprog/tv/build-kernel-{x86,arm64}` and
`kprog/tv/build-{x86,arm64}` module outputs. Arm builds its loader/probe in
`build-fidelity-arm64`/`build-arm64` and packages a separate initramfs.


## Expanded ABI negatives: open findings

The original eleven-case result is preserved. Three additional unsafe-arm
fixtures test an unspecified entry GPR, unspecified entry condition flags,
and a caller-clobbered GPR after a helper. On x86 KVM, **all three are
accepted on the real bound path**, including the refined helper fixture that
saves/restores RBX. Nonzero-generation sidecars are checked; unsafe native
code is never executed. The expanded 14-case suite exits nonzero for these
findings. `x86-abi/` preserves the initial attempt; `x86-abi-frames/` preserves
the refined fixture and every original rejection.

On Arm full-system QEMU, both entry GPR/flags candidates are also accepted.
The four helper-containing fixtures (including three old map/helper cases)
currently reject at link preparation with the surviving
`arm64_sim_unsupported_opcode` extern, after the actual-LR return changes.
This is a recorded linker rejection, not an infrastructure failure or evidence
that helper-clobber liveness has been fixed. `arm64-abi-frames/` retains the
exact messages. The helper candidate preserves X19/LR on its own stack frame.
The original pre-transition eleven-case verifier evidence remains separate.

These findings test the declared entry/call ABI: zero-initialized simulator
locals or a presumed preserved caller-saved register can hide an unsafe
native arm. C/A own the entry/helper-definedness fixes; condition flags must
be included. Any concrete stronger kernel entry/helper premise must be stated
and bound rather than inferred from the sampled arithmetic matrix. F will
rerun the complete suite against their repairs. Valid blind callee-save
traffic must continue to work for compiled applications.

```sh
taskset -c 16-23 make -C kprog/fidelity negative-build NEGATIVE_BUILD=build-x86/negative-abi-frames
taskset -c 16-23 make -C kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=build-x86/negative-abi-frames NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/x86-abi-frames
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-abi-frames ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-abi-frames
```

`abi-baseline-artifacts.tar.gz` and `abi-frame-artifacts.tar.gz` preserve all
native/proof source, objects and build logs. No program or failed case is
excluded, and no synthetic check was added to make these programs reject.

## Actual ABI rerun after effect analysis

`x86-definedness-frozen/` rejects **all14** cases:8 verifier,5 specialization,
1 loader (no BPF EXIT). The three previously accepted ABI fixtures now reject
for the exact undefined entry register/flags or helper-clobbered register.
This uses C's current generation-time effect analysis, whose exact source is
in `definedness-saved-lr-artifacts.tar.gz`; no runtime safety check or zeroed
native value was added. The UD2 fixture defines its later return value, so
its rejection specifically names the unsupported instruction. Intermediate
`x86-definedness/` and `x86-definedness-ud2/` runs are retained separately.

The corrected Arm fixtures save/restore real LR across helper calls, and
pair their map declaration name/layout with the original `neg_map` instead
of creating an invented map. `arm64-saved-lr-frozen/` gives **8 verifier,
1 loader,2 specialization rejections and3 accepted ABI findings**. There are
no infrastructure or unresolved-map failures in that final run. The three
accepted fixtures are the entry register, entry flags and helper-clobbered
register. A owns their generation-time definedness repair; this remains an
open safety defect. The earlier `arm64-saved-lr/` unresolved map outcomes and
successful `arm64-saved-lr-maps/` adapter correction are retained honestly.
Unsafe native code was never executed in any accepted finding.

Each frozen build copies its production include/import closure before
compilation; all generated proofs use that saved header snapshot. The artifact
archive contains sources, native/proof objects, checker sources and compile
logs for both ISAs. Each outcomes JSON retains exact rejection text and
per-case execution command; the compressed Make logs retain the full guest runs.

```sh
taskset -c 16-23 make -C kprog/fidelity negative-build ARCH=x86 NEGATIVE_BUILD=build-x86/negative-definedness-frozen
taskset -c 16-23 make -C kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=build-x86/negative-definedness-frozen NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/x86-definedness-frozen
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-saved-lr-frozen ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-saved-lr-frozen
```

## Stack-base flag noninterference: new accepted unsafe arm

V found a distinct address-abstraction defect after the14-case ABI repair.
The native CPU's absolute stack address is nonzero; the simulator starts its
stack offset at0. Balanced SUB/ADD on x86 therefore leaves actual ZF=0 but
simulated ZF=1. `check-stack-base-flags` reproduces this harmless SETE result
and exits nonzero. The copied V reproducer is now a permanent F regression.

A new15th fixture defines its return value, balances SP, then places a null
read behind that flag-dependent branch. On **x86 KVM it is accepted** with
nonzero-generation sidecars while all previous14reject. On **Arm full-system
QEMU the analogous CMP SP,#0 branch is also accepted**, in addition to the
three prior ABI accepts:4accepted total,8verifier/1loader/2specializer rejects.
Both final suites have zero infrastructure failures. The null address is formed
in a supported GPR, so an unsupported absolute-memory encoding cannot hide the
finding. Unsafe native code is never executed.

This is a native-address/state-relation safety defect, not an undefined-entry
liveness failure. C/A/T must preserve observable pointer arithmetic/flags under
a real base binding; the fix cannot be a fabricated fixed address or rejection
of all valid stack/pointer arithmetic. The15-case suites remain nonzero and
the defect is OPEN. `x86-stack-base/` and `arm64-stack-base/` retain exact logs,
all original-case outcomes, and the accepted program's nonzero-generation ID.
`stack-base-artifacts.tar.gz` retains both complete frozen source/object builds.

```sh
taskset -c 16-23 make -C kprog/fidelity check-stack-base-flags
taskset -c 16-23 make -C kprog/fidelity negative-build NEGATIVE_BUILD=build-x86/negative-stack-base
taskset -c 16-23 make -C kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=build-x86/negative-stack-base NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/x86-stack-base
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-stack-base ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-stack-base
```

## Current17-case bound replay after entry-provenance repairs

The new frozen suites retain all11 original negatives and add immediate-PUSH,
outer-return and ABI/address observations. **x86 rejects16/17; Arm rejects15/17**.
All11 original negatives reject on both ISAs. Exact stage/message/command for
every case is in `x86-current/outcomes.json` or `arm64-current/outcomes.json`;
the compressed logs preserve complete verifier diagnostics.

| Case group | x86 KVM | Arm full-system QEMU |
| --- | --- | --- |
| Packet read/write past end; missing end check | verifier rejects3 | verifier rejects3 |
| Map OOB; nullable result; invalid helper argument | verifier rejects3 | verifier rejects3 |
| Stack OOB; uninitialized stack | verifier rejects2 | verifier rejects2 |
| Unbounded loop | loader: `native_kernel bound proof contains no BPF exit` | same |
| Unbounded indirect jump; unsupported instruction | specialization rejects2 | specialization rejects2 |
| Undefined entry register/flags; helper-clobbered register | specialization rejects3 | specialization rejects3 |
| Immediate-PUSH unsafe branch / overwritten return register | verifier rejects PUSH branch | verifier rejects overwritten X30 |
| Overwritten entry return slot / entry return-address flags | specialization rejects return-slot overwrite | **accepted address-flags finding** |
| Balanced stack-base flags | **accepted finding** | **accepted finding** |

x86's return-slot case now reports
`native return address lacks call/entry provenance at 0xd: ret`, following
C's `ac10dbfab` repair. Its immediate-PUSH case reaches the real invalid-memory
verifier rejection instead of the earlier incorrect PUSH0 specialization.
Arm's return-register overwrite rejects with A's RETURN provenance; its
three previous undefined-ABI findings now reject with A's dependency checker.
The remaining three accepted outcomes across ISAs are still safety defects.
Unsafe native code is never executed; accepted bound loads record nonzero
generation only. A guessed stack/code base or a blanket instruction exclusion
would not repair these address-state relations.

```sh
taskset -c 16-23 make -C kprog/fidelity bound-probe-build negative-build NEGATIVE_BUILD=build-x86/negative-current
taskset -c 16-23 make -C kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=build-x86/negative-current NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/x86-current
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-current ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-current
```

Each VM has2vCPUs/2GiB and runs only on host CPUs16–23. Both suite commands
return nonzero for the retained findings, with zero infrastructure failures.
`current-negative-artifacts.tar.gz` preserves native/proof inputs, compiler
diagnostics and the exact production include/import snapshots for both ISAs.

## Arm SP alignment acceptance repaired

`arm64-sp-alignment/README.md` records a newly confirmed generation-bound
acceptance of a native SP-alignment fault and its production specializer fix.
The current18-case Arm rerun rejects16 cases, retaining only the two earlier
numeric-address findings. All11 original cases still reject. Five alignment
regressions and all40 real-encoding ABI checks pass; three legitimate
unaligned-address/preindex/postindex controls remain bound-load accepted.
The negative proof and all29 workload-derived positive proofs rebuild.

## LDP overlap repaired; both-ISA current negative replays

`arm64-ldp-overlap/README.md` records four generation-bound acceptances of
constrained-unpredictable duplicate-destination LDP encodings and their exact
specialization rejections after the source-validity repair. A distinct-register
LDP control remains bound-load accepted. The19-case Arm suite rejects17,
retaining the two earlier numeric-address findings. All40 ABI regressions and
all29 positive proof builds pass. `x86-post-ldp-matched/README.md` repeats all17
x86 cases with a matched current binding tuple:16 reject, one stack-base-flags
finding remains, zero infrastructure errors. The earlier mixed-tuple attempt
is retained as infrastructure evidence rather than counted as rejection.

## Writeback/base overlap repaired

`arm64-writeback-overlap/README.md` records11 additional generation-bound
acceptances of constrained-unpredictable load/store writeback encodings.
All11 now reject during specialization; five legitimate writeback controls
remain bound-load accepted. The permanent21-case Arm suite rejects19 and
retains the same two numeric-address findings. All40 ABI regressions and
all29 positive proof builds pass; exact before/after inputs and messages remain
in the dated result directory.

## Exclusive-store failure branches: four accepted safety findings

`arm64-exclusive/README.md` records four newly accepted generation-bound
programs with NULL reads on STXR/STLXR failure, both unpaired and paired with
exclusive loads. Two safe controls bind as well. The permanent25-case Arm
suite retains19 rejections and6 findings, with zero infrastructure errors.
The four new findings arise from constant-success store-exclusive semantics;
the independent CPU matrix records4096 actual failure/no-write differences.
Canonical monitor/environment semantics and the production repair are active.

## Exclusive status-register overlap repaired

`arm64-exclusive-overlap/README.md` records four generation-bound acceptances
of constrained-unpredictable status/data or status/base aliases, now rejected
by the production ABI checker. Two valid ZR/SP controls still bind. All40 ABI
regressions and all29 positive proof builds pass. The permanent29-case Arm
suite rejects23 and retains the same six safety findings, with zero
infrastructure errors. Its map fixtures now use the actual original source
prelude and reach the intended verifier checks; the stale adapter run is retained.

Latest permanent Arm run:30 cases,28 rejections(14 verifier/13 specialization/
1 loader) and2 existing numericSP/entryLR safety accepts. All4 exclusive
failure branches now reject on the actualnew#24 choice-capable kernel/module.
The new D0high-clear program wasGEN1accepted before the fidelity repair and
now rejects exactscalarNULLmemoryaccess. Per-case full messages, original
findings and matched artifacts are retained under arm64-current-choice/ and
arm64-vector-clear/. These do not count as application-program negatives.

Numeric Arm repair now rejects30/30 unsafe bound fixtures, with5 valid spill controls admitted; exact final and prototype evidence is in arm64-numeric/. The new x86 divide-fault item retains8 accepted native#DE programs (load only), plus the existing x86 stack-flags acceptance; see x86-divide-fault/.
