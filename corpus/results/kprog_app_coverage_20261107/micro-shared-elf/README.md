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
