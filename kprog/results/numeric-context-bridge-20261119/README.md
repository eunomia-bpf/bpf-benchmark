# Native numeric-context bridge fidelity

The private NUMERIC primitive preserves its input bits while dropping pointer
provenance (`native_lab_input.h:33`). The shared SKB reader uses it for narrow
reads of packet-pointer fields (`x86_sim_local_bpf.h:1396`). CompCert's view
also preserves the pointer bits.

The stock proof header instead discards the supplied value and reads the
ordinary unspecified-input map. That is a conservative proof abstraction,
but the native compiler reuses that frontend and turns the map read into
`freeze poison`. The original value may already be gone. This component
regression checks the concrete native result, including the narrow-lane
operation, rather than assuming a proof-only abstraction preserves it.

Use the actual stock wrapper, sole compile-sim-ir and native O3 code. Six
plain-value controls catch host-call ABI mistakes; 24 numeric cases compare
real native execution with the documented bit-preserving operation. The
Make assertion fails on a real mismatch and retains all rows/IR/commands.
It does not load a BPF program or change a benchmark, production input,
compiler, header, module or image. No effect on any corpus app is inferred.

The detached recipe holds timing SH/image SH, CPU18 and a 4 GiB address-space
bound. It waits behind the active image/check/timing batch. At preparation
time the suspected mismatch has not been executed or confirmed.
