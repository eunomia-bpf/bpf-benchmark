# Optimizer-stage evidence and immutable decoded constants

2026-11-15. The actual OTel optimized frontend remains running, not accepted
as a completed compilation. Three snapshots at09:27 show
SROA → PromoteMemToReg → IDFCalculator. Three more at09:58 still show
SROA/PromoteMemToReg. Thus the remaining cost reaches SSA construction,
after the prior CPP reductions; another preprocessing-byte reduction alone
would not establish that the pipeline is fixed. These snapshots do not
measure a percentage of total compiler CPU time.

The owned original compiler898194/launcher898093 uses its original captured
289,568,784-byte CPP and16GiB address-space cap. Its input/build is preserved.
The host debugger was absent;98f85f74d installs gdb15.1 and eight dependencies
without upgrades, then samples that exact PID. No kernel, runtime image or
base build changed. Package activity and debugger pauses are disclosed here;
the run's wall time is not used as an uninstrumented compiler-speed claim.
All raw tool/package/sampling logs remain available.

The input-capture imageSH lock was unnecessarily held during this host-only
optimization. f3e42017f duplicated the owned launcher's existing FD9 with
pidfd_getfd, checked its device/inode against the image lock, and unlocked
that same open-file description. The before/after fdinfo proves release;
the compiler/log pipeline continued without restart. Shared native/linker/
kernel inputs had already been consumed; this stage reads only its canonical
CPP and system toolchain. C was informed that imageEX and CPUs0–7 were free.
4dbf6d71d now scopes future profile locks to input capture automatically;
queued frontend jobs use no outer whole-run image lock.

The pre-optimizer diagnostic09b6d187f/46228cee1 exposes why ordinary local
width bindings are costly: the static byte helper is not a C constant
expression, and mutable locals hide fixed decoded facts until SSA promotion.
Const qualification alone around that function call leaves the graph intact.
Using the existing generated width contract with immutable captures permits
C code generation to omit the fixed-width branches before SROA.

| Diagnostic, before LLVM passes | Branches | IR body bytes |
|---|---:|---:|
| Function width helper, ordinary bindings | 25 | 5,726 |
| Function helper, const bindings | 25 | 5,667 |
| Contract, ordinary bindings | 28 | 6,211 |
| Contract with const bindings | 0 | 688 |
| Contract with single-evaluation byte capture | 0 | 1,129 |
| Real register write, before | 78 | 44,473 |
| Real write, width captures3f27add92 | 17 | 26,401 |
| Real write, including read/selector capturesa7b399a9a | 12 | 25,195 |

The last row is **84.62% fewer branches** for this small real handler;
it is not a full OTel branch count, elapsed-time gain or runtime speedup.
The diagnostic retains normal-O3 flags but explicitly stops LLVM passes to
observe their input; that stop is never used by the production B compiler.

Production change3f27add92/c25ed3354/a7b399a9a evaluates EFFECTIVE_WIDTH
through the same generated contract with exactly one byte argument capture
and a byte result. Instruction/read/write widths and decoded register
selectors that are immutable retain const qualification. Mutable output
widths remain mutable. The IMUL memory-width default is resolved in its
initializer: the first version incorrectly made its later-assigned value
const, caught by both the store oracle and generic BMI2 frontend compilation.
Those failed attempts are retained; no failing case was filtered. No P,
ISA token, producer option, optimizer level/pass or runtime switch changed.
All native LTO and the sole all-pairs B backend policy remain enabled.

Final validation:

- 65,538 width cases check single evaluation, byte narrowing before absent-code
  resolution, result type and unary integer promotion.
- Complete scoped suite exits0: load713, stack117,782, pointer/RSP/recovery14,
  store1,292,621, output-lifetime200 cases per ISA, and the width cases.
- Actual CPU/shared-C memory/flag comparisons pass for512 store cases and
  4,032 BMI2 cases; all32 fixtures compile through the normal B backend.
- New generic/direct BMI2 allocated sections match16/16. Against pre-change
  output, instruction sections changed for all16 stores and six32-bit shift
  fixtures (ten BMI2 fixtures retain identical allocated sections). These are
  real code differences, not debug-only differences. CPU/shared-C checks pass;
  actual B execution/verification for these changed fixtures is not claimed.

The revised actual OTel frontend is queued as launcher910213 behind the
owned original launcher898093, with no dependency-success requirement. This
preserves both the running job and the single canonical build. It will
capture actual source/header/native/proof identities at start and release
its input lock before optimization. No second full OTel build is created.
Until that run completes there is no full-frontend improvement, actual B
stack/stock acceptance, application equal-work or runtime-performance claim.

Raw: `/workspaces/kprog-raw/perf/20261115-current-otel-frontend`
(`stacks`, `stacks-late`, `debug-tools`, `image-release`, `constants-before`,
`constants-after`) and `/workspaces/kprog-raw/perf/20261115-width-constants`
(failed/intermediate/final subsets, `constants-final`, `otel-frontend` queue).
Canonical OTel build remains `otel-whole-word-checked`; diagnostic IR uses
`frontend-constants`, and the existing store/BMI2/oracle fixtures reuse their
one canonical build each under `/var/tmp/kprog-tmp/perf`. Only logs/results/
hashes are archived here; all raw data and the active job remain intact.

Committed Make targets in `kprog/test/native-relocations.mk` reproduce
`frontend-stacks` with an explicitly owned COMPILER_PID, `frontend-constants`,
`load-oracles`, `native-stores`, `bmi2-specialization`, and
`current-otel-frontend`. Input lock release is operational resource ordering,
not an admission or success condition for measurements.
