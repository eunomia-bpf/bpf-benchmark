# Observed ARM first-pass application coverage

Load attempts retain probes, transients, retries and failures. Resident rows and service requests have separate denominators. Closed application outcomes preserve startup errors and measured work.

| App | Baseline loads / IDs / resident | Native loads | Requests | Compiled | Bound | Specialization error | Verifier error | Other loader error | Application |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc | 74 / 74 / 23 | 69 | 19 | 19 | 16 | 0 | 3 | 0 | error |
| otelcol-ebpf-profiler | 16 / 15 / 12 | 3 | 1 | 1 | 0 | 0 | 0 | 1 | error |
| cilium | 8 / 5 / 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| tetragon | 205 / 201 / 152 | 19 | 0 | 0 | 0 | 0 | 0 | 0 | error |

Katran guest and application complete with exit0 and one bound service request. [The two-start work record](katran-two-start-work.json) retains 26,197 baseline packets and 23,208 native packets, each with matching BPF, VIP, TX and receiver counts and one LRU miss. Original host metadata keeps its shared-source drift flag; observed analysis-time change is the published x86 memory-access header. First-pass corpus and universal safety work continue.
