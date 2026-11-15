# Retained OTel hotspot: all-pairs MIR result

2026-11-15. Source replay script `076c9465c`; original failed request is
`service/requests/5.failure.tar.gz` inside the retained whole-app service
archive. It is streamed directly into the canonical compiler build, without
copying the nested archive or repeating the C frontend.

The existing all-scalar-pairs mode compiles with machine-instruction verification.
Actual deepest direct stack access is **552 bytes**, still beyond the stock
512-byte frame. The original request failed at fp-576. This is a 24-byte frame
reduction, not a fix or a runtime improvement. Codegen completed in 359.08 s
with CPU 19 and a 24 GiB address-space cap. Resulting B SHA256:
`2d43efc7ae4815a8a4fc14a8c2ea29fae943fa30598880f17ef26189f29d40ac`.

The original frame has a 376-byte modeled-stack object, another 8-byte object,
and 25 aligned spill slots, ten of which store four-byte scalars. Five scalar
pairs were selected; 18 store sites required saving live scratch registers.
The independent conservative spill-lifetime analysis covers 19,809 CFG blocks,
finds a maximum of 25 live slots and **no noninterfering slot pairs**. It does
not supply a slot-reuse transformation.

The archived command invokes its bounds compiler without today's explicit
`--canonical-ctx-loads --strict-identities` arguments. These measurements are
about that retained MIR; they do not establish current normal-B failure or
acceptance. A fresh normal-pipeline replay remains necessary. Production
compiler behavior and the optional mode default were unchanged.

No new stock load, checked installation, application execution, throughput or
per-call speed is claimed. Raw data, commands, hashes and the original failure
remain in `/workspaces/kprog-raw/perf/20261115-otel-hotspot-spills` and the
existing whole-app service archive. The one canonical compiler build remains
`/var/tmp/kprog-tmp/perf/otel-whole-word-checked`.
