# Bound checks after the LEA encoder and linker repairs

Final artifacts use the exact frozen producer and private native-link from
final treef57ab4a4e1de16ebe04108306ab0b59759cf24a5. No shared CLI, kernel,
module or runtime image was replaced. Runtime/build hashes are retained.

The original25-program LOAD-ONLY safety suite remains:
17verifier rejects,6specialization rejects,1loader reject, and1accepted
`stack_base_flags` finding. All eight DIV fault cases still verifier-reject.
Exact messages and manifests are in `published/outcomes.json` and its logs.

All ten legal LEA controls are generation1 bound-admitted and execute with
return2/packet0, matching original BPF. Six check absolute address values
through AX/EAX/RAX/R8W/R8D/R8, including preserved upper bits for16-bit writes.
Four check address-size32 with nonzero high register bits and wrapped low
addresses through64-bit RAX/R8 writes. They use caller-save registers only.
The native body checks its result before returning; logs retain native and
source-BPF returns and the nonzero binding generation.

All29 micro proof programs and the existing unchecked-packet-read negative
proof compile successfully from preserved native proof objects and the frozen
encoder/header. This is a compile regression, not a new29-program runtime
claim. `published/micro-build.json` and its input/source/object archive retain
every command and outcome. Both formal FULL checks pass; all78 native-link
Rust tests pass, including paired absolute LEA/LOAD admission.

An additional ABI-boundary observation remains an active safety finding:
a bare native RBX clobber is accepted with generation1 while its linked ABI
states `callee_saved_mask=0`. The module contract requires preservation of
such host nonvolatile registers. `published/abi-observation/` contains exact
load-only outcomes; `abi-inputs-source.tar.gz` includes assembly, native/proof
objects, linked bytes and ABI. This new case was never executed natively.
C/T have been notified for the production linker/binding repair. Accepting
these bytes with zero preservation metadata is not declared safe merely
because the local simulator returns2.

The initial positive fixture changed RBX without restoring it; its guest
ended255 before producing a complete outcome. The final controls use EAX
instead, and complete all10. That test correction does not close the separate
ABI finding above. First ROOT and first published-source attempts, exact old
assembly/objects and logs are retained in two archives. Absolute controls
also initially hit the linker's false absolute-memory rejection, now fixed.
The proof-build helper's first moved include path and inactive-native-header
snapshot errors are retained; final BPF compilation reads the proper frozen
helper header. No failed attempt was recounted as a successful run.

Commands through bws.sh, from `/workspaces/repository`, with the existing
matching lab kernel/module and loader build:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-addressing-fixed -f published.mk source
taskset -c 22-23 make -C kprog/results/kprog_fidelity_20261107/negative/x86-lea-addressing-fixed -f published.mk link-build link-test probe-build build positive-build
taskset -c 22-23 make -C kprog/results/kprog_fidelity_20261107/negative/x86-lea-addressing-fixed -f published.mk run
taskset -c 22-23 make -C kprog/results/kprog_fidelity_20261107/negative/x86-lea-addressing-fixed -f published.mk positive-kvm micro-build
taskset -c 22-23 make -C kprog/results/kprog_fidelity_20261107/negative/x86-lea-addressing-fixed -f published.mk abi-build abi-kvm
```

The negative and ABI observations exit2 for real accepted findings. Guests
run sequentially with2vCPUs/2GiB. Unsafe candidates are LOAD-ONLY; the ten
corrected legal controls are the native execution checks.
