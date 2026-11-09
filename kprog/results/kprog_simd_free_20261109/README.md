# Scalar native programs on x86-64 and AArch64

S14, 2026-11-09. The scalar native scope, compile evidence and paired safety
replay are complete and published. The lane retires its private outputs after
Git archive and remote-ancestry readback.

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

The FP-state instruction audit covers all 318 micro/corpus native objects,
including implicit x87, MXCSR, XSAVE/XRSTOR, MMX/AVX state operations and ARM
FP control registers alongside explicit SIMD operands. Observed FP-state
instruction hits: 0. All seven actual rejection ELF inputs provide positive
detection controls, including the implicit x87 FLDZ form. Exact disassembly
hashes and controls are in `fp-state-audit.json`; the scanner joins the final
safety command archive.

The paired safety recipe captures common model/service/kernel/bridge inputs and
uses one 2 GiB guest at a time on CPUs 20-23. Complete observed stage counts:

| Epoch/ISA | Observed stages |
| --- | --- |
| control/x86 | valid_executed=9, verifier_rejected=33, specialization_rejected=1, accepted_finding=2 |
| control/arm64 | valid_executed=4, verifier_rejected=28, specialization_rejected=2, accepted_finding=7 |
| scalar/x86 | valid_executed=9, verifier_rejected=33, specialization_rejected=1, accepted_finding=2 |
| scalar/arm64 | valid_executed=4, verifier_rejected=28, specialization_rejected=3, accepted_finding=6 |

Every positive control executes with its expected result. Negative native
executions: 0. Integer-case stages remain paired. SIMD/FP generation-domain
changes: [{"arch": "arm64", "control": "accepted_finding", "name": "scalar_vector_load_clear_high", "scalar": "specialization_rejected", "scalar_handler_domain": true}].

Load-only accepted findings remain recorded by epoch/ISA: {"control/arm64": ["scalar_vector_load_clear_high", "unpaired_stxr_failure", "unpaired_stlxr_failure", "paired_stxr_failure", "paired_stlxr_failure", "entry_return_address_flags", "stack_base_flags"], "control/x86": ["immediate_push_branch", "stack_base_flags"], "scalar/arm64": ["unpaired_stxr_failure", "unpaired_stlxr_failure", "paired_stxr_failure", "paired_stlxr_failure", "entry_return_address_flags", "stack_base_flags"], "scalar/x86": ["immediate_push_branch", "stack_base_flags"]}. These preserved model findings retain their C/A/S7 owners.
`safety-raw.tar.gz` retains all source-pinned inputs, requests, generated B,
stock verifier logs and actual outcomes. V retains universal compiled-B and
physical-composition ownership.

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
