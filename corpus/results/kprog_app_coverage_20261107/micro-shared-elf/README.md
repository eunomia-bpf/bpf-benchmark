# Existing micro shared ELF on the native-only service

R actual174513_760828 attempted29 pure micro native programs. The registered
service rejected ALL29 before generation because their unchanged .native.so
inputs are ET_DYN and validate_native accepted only ET_REL. Full original
micro results and all29 actual kernel-copied requests are retained. This is
a specialization input-format failure, not a verifier rejection or proof
upload exemption. The older stage2 application-proof error is a separate
runner integration issue already repaired by aaf7b9dc4/Tfd1b65560.

Validation now accepts little-endian64-bit ET_REL and ET_DYN for the expected
ISA. Entry bounds use st_value minus executable-section sh_addr, as the
existing native linker already does. It still requires exactly one defined
nonempty named function wholly inside executable bytes; wrongISA/ET_EXEC/
missingentry/belowsection/outsideentry fail. No native bytes, compiler flags,
programs, proof-upload rejection or capability authorization change.

All29 exact original ELF payloads validate and produce proof objects with
the unchanged native-link --mode proof --preserve-entry-abi command.
12 metadata/lifecycle/real-ELF checks pass, including actual REL+DYN inputs
and malformed entry addresses. These are host format/link checks, not kernel
acceptance. A new standard all29 kernel/native_proof guest is running on
C20-23/8GiB with the same cached TV kernel and matching module bundle, current
T native-only runner and the existing cached native programs. Actual runtime
results remain pending. validation-raw.tar.gz holds exact commands, inputs,
original failures, proof objects, source snapshots and checks; hashes in
checks.json.


## Actual standard29-case run after format repair

Actual175810_925495 attempts ALL29 cases through the standard VM/container
micro driver and kernel-owned native-only service.26 programs are generated,
compiled, accepted/bound and return exact expected results; all29 JIT results
also match (55 successful measured samples in total). There are29 native
requests/29 generated/28 compiled, with1 compiler SIGKILL and2 verifier
rejections. No request is rejected for ET_DYN format. All launch pins remain
unchanged; guest8GiB/4vCPUs/C20-23/1sample1repeat is functional evidence only.

| Failed program | Generated | Compiled | Actual failure |
| --- | ---: | ---: | --- |
| trace_event_type_switch_dispatch |1|1|verifier complexity:1000001 instructions, limit1000000|
| siphash_rotate64_mixer |1|0|Clang SIGKILL; OOM not established by this receipt|
| cilium_socket_lb_service_select |1|1|verifier R0 invalid mem access scalar,118 instructions processed|

The other26 cases pass, including tc_packet_checksum_fold and
cgroup_skb_hash_chain. This is not all29 acceptance, same-work performance,
or an ISA-wide safety theorem. No failed program is omitted or waived.
Full per-program results, actual commands, image/current-runner binary and
launch source identities are in runtime-raw.tar.gz; runtime-service.tar.gz
contains the complete original29-request service archive. runtime.json holds
all source/bound IDs and classified failures. The closed guest disk/exported
image tar are absent.

The first collector expected a success-only [done] line and failed to locate
metadata for this failed suite. Its original receipt/log are preserved. The
corrected collector uses the unique actual result path already present in
the error commands; it does not guess a directory or read a mutable latest
summary. collection-evidence.tar.gz retains this parser and the successful
offline compilation of the identical trace ELF. A separate4GiB two-case
diagnostic reproduces trace complexity and siphash SIGKILL; it is not proof
that the8GiB kill was OOM. Subsequent simulator changes need a fresh run.
