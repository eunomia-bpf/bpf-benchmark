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
