# x86 memory-intrinsic count repair

The simulator now processes the complete native 64-bit memcpy/memset count.
Immediate-count and RDX-count forms no longer stop at a separate 1024-byte
limit. The mechanical generator emits the native count without imposing a
synthetic cap; register-count forms have no unused immediate bound.
The generated contract, Lean byte-buffer composition and existing host oracles
use the same count selection. No runtime guard or instruction omission was added.

Validation: `lake build KProgFormal.X86CallMemHandler`, the existing formal
Makefile's callmem host oracle (875 cases) and production-macro route oracle
(50 cases), including complete 2000-byte operations, passed on resume.
`python3 kprog/formal/tools/generate_x86_callmem_spec.py --check` passed.
The earlier `make -C kprog/x86 micro-proofs-build` completed all 29 positive
builds plus its negative fixture; this was compilation, not verifier acceptance.
Logs are compressed alongside this report. `sources.json` pins this increment.

The kernel call-target admission policy is unchanged. The attempted memset
admission was withdrawn after an existing load-only context regression was
accepted; no unsafe native execution occurred. This count repair alone does
not establish context projection, whole-program fidelity, memcpy overlap
behavior, or six-application acceptance. Context identity is the next repair.
