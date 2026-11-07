# OTel native-local memset proof inputs

The OTel native object also contains an undefined memset call. The proven ARM
ELF preparation body used for BCC is now embedded in this object. Its machine
code object is byte-identical to the 8,257-case ARM CPU control; those checks
were not counted a second time.

All 14 retained OTel ELF/BTF candidates generate fresh simulator C with the
ordinary local native byte-loop included. Original map/global declarations,
full source-BTF selectors and feature-probe records remain. The prepared native
object can be supplied explicitly to the existing producer; its default input
and link/install modes are unchanged.

A single preclean compiler with 32 GiB address-space allowance is running on
the new frozen inputs. The previous v18 compiler remains running on its old
input. Outputs are separate and no old outcome is overwritten. Compilation,
verifier acceptance and application completion are not claimed for the new
inputs. The detached continuation will link/install/run the unchanged OTel
workload only after all candidates compile.

The completed old v15 census is retained separately: 5/14 compiled and
9/14 failed, with every raw compiler result. These are old-input counts,
not the fresh v36 result.

~~~sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile otel-memory-input
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile otel-real-generate PHASE=otel-memory-v36 OTEL_NATIVE_OBJECT=/workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/otel-memory-input-v36/native/otel.native.o
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile-preclean PHASE=otel-memory-v36 COMPILE_ARGS='0 14 3600 1 32768'
~~~

Preparation uses fresh phase directories. Complete frozen native/ELF/BTF/C/
header inputs and original LLVM diagnostic records are archived here.
