# Native-only ARM tracee two-start replay

Host status `False`; guest exit `1`; driver exit `2`. Request stages: `{"loader_rejected": 1}`. Exact request/native identities, all failure causes/messages, baseline and native per-program work counters and complete phase measurements are in coverage.json and native-identity-audit.json.

All requests retain retries and errors. A generated proof or a bound load alone is not full application acceptance. See applications[].status/error and phases for the actual workload outcome. Manifest counts are not loaded-program denominators. This transport adds no program filters or workload checks and reuses the application source and kernel. Applications submit native ELF; the private kernel candidate is not adopted. QEMU timing is functional only.

Raw run-20261107T202335483042Z.tar.gz SHA256 `0834321bc7d5fbafe59b0d61afef55ffba012815dcadbf01a199cea562139b9a`; identity errors `[]`. All six apps and remaining formal/hardware obligations are still open.
