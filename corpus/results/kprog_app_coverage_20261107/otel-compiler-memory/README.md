# Closed OTel compiler-memory diagnostic

This host diagnostic investigated the actual8GiB guest compiler OOM. It
finished before the12GiB guest compiled the unwinder and exposed its separate
pointer self-XOR verifier rejection. No preprocessing pipeline or compiler
flag change was adopted. Production compilation remains unchanged.

| Captured input / phase | Exit | Peak RSS KiB |
| --- | ---: | ---: |
| perf_unwind_stop, integrated compile |0|1391528|
| perf_unwind_stop, preprocess |0|262924|
| perf_unwind_stop, compile preprocessed |0|1081544|
| perf_unwind_native, preprocess |0|982284|
| perf_unwind_native, compile preprocessed |0|5205064|

All five use the same recorded Clang18 BPF flags, host20-23, captured real
request C, and pre-repair5ab header. Peak RSS is measured per child via
resource.getrusage(RUSAGE_CHILDREN), not guest memory or PMU counters. This
is one diagnostic window, not a speedup, universal equivalence, R timing or
app acceptance claim. The two expanded C inputs total328767479bytes.

Three ELF comparisons match ALL allocated sections and normalized
relocations: control integrated versus preprocessed; archived service control
versus integrated; actual12GiB unwinder object versus preprocessed unwinder.
Debug differences are outside that comparison. Complete expanded source,
original C, objects, commands, compiler version/input hashes, measurement
script and raw logs are in raw.tar.gz. Expanded inputs reproduce split
compilation without depending on the later canonical header. Direct-input
reproduction must use the frozen5ab header supplied in the archive.

The initial attempt to use an unavailable /usr/bin/time is retained as a
setup failure, followed by successful use of existing Python resource
measurement. No package was installed. Compilation alone does not establish
verifier or bound runtime success; those outcomes are recorded in the
separate native-only-runtime results.
