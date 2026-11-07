# Native-only ARM katran two-start replay

Host status `False`; guest exit `0`; driver exit `2`. Request stages: `{"bound_accepted": 1}`. Exact request/native identities, all failure causes/messages, baseline and native per-program work counters and complete phase measurements are in coverage.json and native-identity-audit.json.

All requests retain retries and errors. A generated proof or a bound load alone is not full application acceptance. See applications[].status/error and phases for the actual workload outcome. Manifest counts are not loaded-program denominators. This transport adds no program filters or workload checks and reuses the application source and kernel. Applications submit native ELF; the private kernel candidate is not adopted. QEMU timing is functional only.

Raw run-20261107T185947373335Z.tar.gz SHA256 `36631edd6c78c017533c13802d421386449241ef5e713d60c8eee07f625ef250`; identity errors `[]`. All six apps and remaining formal/hardware obligations are still open.
