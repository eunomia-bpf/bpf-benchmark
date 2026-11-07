# Observed ARM first-pass application coverage

All six first-pass application runs are closed. Load attempts retain probes, transients, retries and failures. Resident rows and service requests have separate denominators.

| App | Baseline loads / IDs / resident | Native loads | Requests | Compiled | Bound | Specialization error | Verifier error | Other loader error | Application |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc | 74 / 74 / 23 | 69 | 19 | 19 | 16 | 0 | 3 | 0 | error |
| otelcol-ebpf-profiler | 16 / 15 / 12 | 3 | 1 | 1 | 0 | 0 | 0 | 1 | error |
| cilium | 8 / 5 / 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| tetragon | 205 / 201 / 152 | 19 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| katran | 6 / 6 / 1 | 6 | 1 | 1 | 1 | 0 | 0 | 0 | ok |
| tracee | 162 / 162 / 151 | 9 | 1 | 1 | 0 | 0 | 0 | 1 | error |

Katran completes guest/application execution with one bound request. [Its work record](katran-two-start-work.json) retains matching packet/BPF/VIP/TX/receiver counts for both phases. Tracee records one generated and compiled request, followed by a native-link tail-map-plan rejection before verifier submission. The recorded ARM loader build predates the shared PROG_ARRAY identity repair at 3d0e584b5; the next source epoch consumes an updated ARM build. Original host status and shared-source drift flags remain in each raw result. Whole-application repairs and universal safety theorem work continue.
