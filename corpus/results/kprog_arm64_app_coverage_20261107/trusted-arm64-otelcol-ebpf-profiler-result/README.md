# Native-only ARM otelcol-ebpf-profiler two-start replay

Host status `False`; guest exit `1`; driver exit `2`. Request stages: `{"loader_rejected": 1}`. Exact request/native identities, all failure causes/messages, baseline and native per-program work counters and complete phase measurements are in coverage.json and native-identity-audit.json.

All requests retain retries and errors. A generated proof or a bound load alone is not full application acceptance. See applications[].status/error and phases for the actual workload outcome. Manifest counts are not loaded-program denominators. This transport adds no program filters or workload checks and reuses the application source and kernel. Applications submit native ELF; the private kernel candidate is not adopted. QEMU timing is functional only.

Raw run-20261107T182921697243Z.tar.gz SHA256 `7813fe4ad89fbd34156991d201b91be45f2814e5b36b2aa13a322ba0f2d0a2a7`; identity errors `[]`. All six apps and remaining formal/hardware obligations are still open.
