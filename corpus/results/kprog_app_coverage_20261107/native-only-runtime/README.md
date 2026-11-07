# Native-only trusted service with the standard corpus framework

The guest registers the trusted specializer outside the application container.
Applications in the container submit only native programs through the kernel;
the service reads the retained kernel input and produces fresh bound proofs.
The normal corpus driver owns the JIT baseline, stop/restart, native arm,
unchanged workload and counters. No upstream runner/workload/framework source
was changed for this bridge.

The image overlays the existing application image with current loader/shim,
native linker, six-app native artifacts and current clean corpus/runner sources.
All15 kinsn modules match the existing TV kernel. Network/system modules are
exported from that kernel's current cached build using modules_install; no
kernel recompile or guessing among historical installation directories.
The Docker disk lives in the lane-owned host-backed var-tmp directory.

## Completed package validation

Incremental15-module build, cached-module export, package and Docker build/save
all completed. `package-inputs.json` pins1546 source/artifact inputs and the base
image. `image.json` records the image/tar hashes and verifies its layer ancestry.
Five critical files extracted from the actual image match the built loader,
shim, linker, native module and corpus driver byte for byte. The first package
attempt's ambiguous historical-module-cache error is retained; the corrected
export uses current kbuild outputs directly.

```
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile image
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus
```

`SAMPLES`, `WORKLOAD_DURATION` and `APPS` select the ordinary corpus inputs;
defaults are one2second BCC functional sample. This is not a timing recipe yet.
The mutable build context and large image tar remain in lane C state, while
source recipes, exact hashes and completed build logs are committed here.
Package reruns refuse to overwrite existing compiled module inputs silently.

## Runtime status

The first standard-corpus BCC guest is running. Completed startup evidence is
separately [25/25 native-only BCC](../trusted-service-bcc-set/native-only-complete.json).
No standard corpus success, JIT/native work equivalence or timing is claimed
from the image build. The guest archives service requests and corpus output;
its summary records raw make return code and actual corpus metadata statuses
separately, since process exit0 does not establish application success.
Do not stage active .live directories or incomplete runtime logs.
