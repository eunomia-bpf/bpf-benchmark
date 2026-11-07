# Independent current-CMP micro and ordinary-PATH review

This review reads the raw result JSON and every nested registered-service
request from C's published archives, independently of runtime.json aggregates.
All four archive blobs match their exact owner Git commits. Original native
inputs are recovered separately from the older 5004364f validation archive.

| Run | JIT samples | Bound native samples | Remaining native failures |
| --- | ---: | ---: | --- |
| Full pure suite, 12 GiB, 25db0cb43 | 29 correct | 27 correct | SipHash compiler OOM; Socket LB verifier rejection |
| Ordinary outer PATH, 4 GiB, a07627419 | 1 correct | 1 correct | None |

All 29 full-suite native ELF payloads remain byte-identical to the original
pre-fix R inputs, their immutable kernel copies and the generation inputs.
The ordinary-PATH control also uses the same original simple ELF.
Every returned sample matches both the configured 64-bit result and return
action. Each successful request has a complete terminal archive, all-zero
compiler command returns and a bound program ID matching loader stdout.
Those IDs are distinct within each guest; IDs from different VMs are not merged.
All request source records pin the published 4fe6817 CMP header.

Trace switch now returns 16/action 2 through a successful fresh bound load.
The older 26-pass record remains historical; this full run also changes guest
memory and terminal draining, so its improvement alone is not an isolated
measurement of the CMP change. F's independent instruction replay is separate.

The two full-suite failures are retained:

- siphash_rotate64_mixer has compiler return -9. Unlike the earlier records
  that only showed SIGKILL, this guest's kernel log explicitly reports an OOM
  kill of clang PID1822 with anon-rss 10,299,508 KiB. The recorded kernel line
  is retained verbatim in verification.json. This does not retroactively
  establish an OOM cause for older SIGKILL-only runs.
- cilium_socket_lb_service_select compiles, then the loader/verifier reports
  R0 invalid mem access 'scalar'; its exact diagnostic and 105-instruction
  verifier summary are retained. No native result is invented for either failure.

The full-suite driver exits 2 and metadata status is error. The ordinary-PATH
driver exits 0 and metadata status is completed; simple returns 12345678/action 2
under both runtimes. The raw launcher explicitly gives Make only
PATH=/usr/sbin:/usr/bin:/sbin:/bin, with no manual LLVM prefix. The standard Make
recipe's compiler bootstrap therefore has an actual VM/container success
control. The 29-case run supplies LLVM PATH itself and cannot establish that
bootstrap fix. These are distinct runs, with separate sample denominators.

No VM was launched for this analysis. No benchmark, source, flags, instruction
oracle, verifier limit or loader policy was changed, and no raw archive was
duplicated. These one-sample/one-repeat functional controls do not establish
timing, all-29 acceptance, full ISA fidelity or six-application completion.

The exact executed commands, immutable raw data and current failure ownership
remain with the [full-suite evidence](../../../../../corpus/results/kprog_app_coverage_20261107/micro-cmp-12g/README.md)
and [ordinary-PATH control](../../../../../corpus/results/kprog_app_coverage_20261107/micro-compiler-path/normal/README.md).
The standard reproduction request after the incremental runtime refresh is:

~~~sh
make micro PLATFORM=kvm ARCH=x86 SUITE=micro/config/micro_pure_jit.yaml RUNTIMES="kernel native_proof" SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
~~~

Use BENCH=simple for the one-program ordinary-PATH control. These owner runs
use CPUs20-23 and their archived cached image/kernel/module inputs. Actual
timing remains with lane R; the two full-suite failures remain with lane C.
