# Scale kernel outcomes and status correction

The verifier-only replay on the sole kernel completed all 16 case records:
eight larger cases retain their compiler failures; all eight compiled100/1K
cases fail actual stock loading with `BPF_MOV uses reserved fields`, before
execution. No successful execution is recorded. Full small verifier logs and
per-case timing/memory observations are retained here; raw traces, loader logs
and commands stay in `/workspaces/kprog-raw/perf/20261114-scale-current/retry3`.

The preceding `kernel-trace` attempt mislabeled those same load failures as
passed because `trace-cmd record` returned zero after the child loader failed.
The loader logs already contained EINVAL. That pass label and the brief lane
commentary claiming eight passes are incorrect.628a831a9 records the child
status independently and traces its descendants. All eight corrected records
now show loader1/recorder0 and `load_or_execution_failed`. Three regression
tests cover resource sidecars, malformed real records and real child exit
status preservation. The original false-label files are preserved unchanged.

The old scale compiler invokes plain clang rather than the production stock
wrapper. Its B starts with the legacy private-input encoding (`b7 src9 off6`),
which the sole stock kernel correctly rejects. This differs from production's
forced ordinary-input header and chunked preprocessing; the prior compiler
capacity results therefore remain measurements of the legacy scale path,
not a completed production V3 result. The next work is to run this scale
harness through the existing production B compiler with its real input map
binding, preserving native instructions and the arithmetic reference.

Recorded outcomes: eight stock rejections, two compiler SIG9 and six
preprocessor source-location failures. Verifier allocation intervals include
libbpf's feature probes; the final interval corresponds to the fixture load.
Those rejection costs do not describe successful verifier complexity.
