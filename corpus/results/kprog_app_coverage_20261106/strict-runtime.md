# Strict generation-bound startup

The production shim now sends every successful application startup program,
including anonymous feature probes, through the required bound-proof loader.
It no longer treats the name `native_lab_stub` as evidence that a load came
from the framework. A thread-local scope around the NativeLoader call identifies
nested framework loads. The existing unbound comparison arm keeps its feature
probe behavior.

Actual KVM tests use lane T's published `context-v2-func-ip` library and the
immutable context-v2 kernel/module pair, with a freshly compiled production
shim. A real libbpf object load produces six successful BPF loads: coarse clock,
anonymous zero, name probe, local-call/function-IP probe, cgroup socket probe,
and the XDP main program. **All six are replaced**, for both actual source load
flags0 and8. The main program executes with nonzero generation1 and return127.
No probe is silently passed through. The prototype source-call regressions and
anonymous/name-collision controls are retained in the earlier helper checkpoint.

```sh
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk build kvm
```

`strict-runtime-artifacts.tar.gz` contains the exact published library, shim,
kernel/module, manifests, captured input bytecode, complete shim logs and test
outcomes. This establishes the startup mechanism; it does not establish complete
BCC or six-application coverage. BCC's actual startup has further dynamic-map
and tracing probes, which remain required work before a complete app can be
measured or handed to lane R for timing.
