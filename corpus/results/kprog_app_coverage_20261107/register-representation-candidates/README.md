# Generic register representation candidates

Katran's first complete-register volatile candidate closes the original pointer
mask error and exposes scalar-range loss after a partial spill/reload. The new
partial-write candidate selects the ordinary representation for the existing
scalar tag and complete volatile storage for other tags. Low8/high8/16 writes
preserve all upper bits and produce the same scalar tag in both arms. The existing
MOV host oracle passes100448cases with UBSan. Production source remains its
published epoch while whole Katran uses the captured private include.

Tracee's exact native low-byte comparison bounds a masked register to15, while
LLVM strength-reduces the later indexed read using a fresh mask of its original
wide value. The verifier carries the comparison bound on the first value. The
private narrow-read candidate emits pure BPF AND255/65535 expressions, keeping
the same masked SSA value through that native comparison and indexed read.
The existing32-bit zero extension and64-bit value semantics stay intact.
Actual clang18/mcpuv4 assembly for low8/high8/16/32/64 and a generic guarded
index fixture is preserved; the guarded index uses the same bounded register.
The initial operand-modifier diagnostic is retained alongside the final output.

These candidates preserve native values, existing flags and native branch choices.
The register-read/write universal laws and BPF compiler correspondence supply
the safety argument. The host counts and compiler shape are supporting evidence;
F's independent compiled-BPF differential and whole application outcomes follow
with their captured sources. The serial whole Katran then helper-preserving
Tracee replay uses12GiB/eight guest vCPUs on20-23 and the existing workload.
The raw archive includes both exact candidate headers, original headers,
commands, host output, assembly and the actual whole-application queue source.
