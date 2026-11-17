# Original-program helper target query

This phase-1 diagnostic exercises the existing loader query without changing
loader core, the manifest writer, production configuration, the image or the
frozen benchmark. It reuses the committed current-link capture adapter and
local Make entry. The only experimental switch is the already-supported
`kernel_helper_context` field in a diagnostic native manifest.

`prepare.py` reads BCC's actual manifest from the sole image archive. It retains
that manifest and creates control/query configurations in the existing corpus
results mount. Relative native object/source paths become absolute paths to
the same files in the image in both configurations. Every other field stays;
only the query configuration adds `kernel_helper_context: true` to each entry.
The script reports whether the shipped and staged manifests match.

`run.sh` holds batch EX, timing SH and image SH, pins its controller to CPU 19
and runs the two guests sequentially on CPUs 8–15, eight vCPUs/64 GiB. It uses
the existing functional-check settings (one 10-second sample, stats enabled),
the same base/STATE and the unchanged guest entry. Address-space limit is
96 GiB. These are functional diagnostics, not official speed measurements.
Every kernel-link invocation retains actual proof, plan, status and available
outputs, including failures. An app failure remains recorded and the second
configuration still runs. Existing successful-run cleanup removes only the
rebuildable guest Docker disk; all raw data stays under `/workspaces`.

Compare helper addresses relative to a common live helper in each plan and
to the sole kernel's symbol offsets, accounting for boot relocation. Identify
actual original program types and emitted argument setup before interpreting
any target mismatch as a context semantics difference. Link success alone is
not a B/stock verification result or evidence of output equivalence. Permanent
loader-core fixes remain with the coordinator under the freeze contract.
