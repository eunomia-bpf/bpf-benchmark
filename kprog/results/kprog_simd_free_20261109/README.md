# Scalar native programs on x86-64 and AArch64

S14, 2026-11-09. Implementation and compile evidence are published; the paired
safety replay remains active under `/var/tmp/kprog-tmp/S14/safety.sh`.

Native P uses scalar registers in both corpus producer routes. x86-64 combines
`-mgeneral-regs-only` with the kernel-family `-mno-sse -mno-mmx -mno-sse2
-mno-3dnow -mno-avx -mno-sse4a -msoft-float` flags. AArch64 retains
`-mgeneral-regs-only`. The native build flags live in `vendor/bpf/Makefile` and
`runner/libs/cilium_native_build.py`.

The generator's x86 MOVAPS/MOVUPS handlers and ARM D/Q load/store,
FMOV/CNT/UADDLV handlers are retired. Existing generation errors carry submitted
SIMD/FP operations. The kernel-copy, service, stock-verifier and same-copy JIT
path retains its design. Additional production admission mechanisms: 0.
Commits: dba3416ac and 4f40432f1.

| Measurement | x86-64 | AArch64 |
| --- | ---: | ---: |
| Native micro control/scalar pairs | 30 | 30 |
| Control executable bytes | 17,208 | 16,252 |
| Scalar executable bytes | 17,208 | 16,252 |
| Changed executable-byte objects | 0 | 0 |
| Scalar B micro compiles | 30/30 | 30/30 |
| Rebuilt native corpus objects | 99 | 99 |
| SIMD/FP register operand occurrences | 0 | 0 |

The micro set comprises the frozen 29 programs and the unchecked packet-read
fixture. Both native epochs have identical executable bytes, including internal
functions. The complete 120-object micro census has zero SIMD/FP operands.
Corpus compilation covers BCC, Katran, Cilium, OTel, Tracee and Tetragon using
the corpus Make recipes, captured scalar flags and architecture-specific 7.0
headers. The static Cilium builds use its retained source/config headers;
its runtime compile adapter additionally passes all 13 component tests.
The earlier corpus census covers 638 existing object paths and also records
zero SIMD/FP operands. These are compilation measurements.

The focused regression has 24 SIMD/FP error forms and two scalar controls.
Actual native ELF submissions through the trusted specializers produce seven
generation failures: three x86 forms and four ARM forms. Native executions of
these cases: 0. Executable bytes, disassemblies, generated B, commands, source
snapshots and hashes are retained in `compile-raw.tar.gz`. The corpus export
contains 198 debug-stripped native objects and their disassemblies, with original
object hashes, executable-section hashes and DWARF source-file tables.

The paired safety recipe captures common model/service/kernel/bridge inputs and
uses one 2 GiB guest at a time on CPUs 20-23. The x86 control completes 45 cases:
9 valid executions, 33 verifier rejections, one generation failure and two
load-only findings, `immediate_push_branch` and `stack_base_flags`. ARM control
and the scalar epochs continue through the detached serial recipe. Negative
cases use the harness's existing load-only route. Final counts and paired
stage differences follow completion.

The initial corpus invocation inherited the host BTF default and regenerated
four shared generated headers. Recovery matched each S14-generated live hash,
then recovered the exact retained architecture-7.0 bytes, with index/HEAD/source
agreement. The four paths are clean. A captured-micro forced-make attempt also
entered an implicit vmlinux link. The original `.vmlinux.cmd` objcopy recipe
reproduced the canonical 408,973,592-byte image from `vmlinux.unstripped`, SHA256
49f030ed2cf248042a00da4070e959add351cf66696bbaaa646c2cd816259baf.
Both shared kernel-offset files retain their original timestamps and hashes.
Final builds use private offsets and private architecture-header mounts.
Initial Clang shared-header diagnostics and the harness-path diagnostic remain
in the command records alongside the successful captured-header repeat.

Production code changes: +5/-56 lines; focused regression: +52 lines. The
change retires handlers and retains the existing error route. The frozen
workload and paper paths retain their ownership. S15 owns indirect-branch
hardening. Eighteen coverage-row amendments retain historical vector model
laws while recording the scalar native generation domain; V owns their merge
and universal compiled-B/physical composition. S14 full Lean checks: 0.
