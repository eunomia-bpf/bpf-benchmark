# Actual OTel replay after byte-exact ARM readonly reader

Host status `False`; guest exit `1`; Make exit `2`. Service stages `{"bound_accepted": 1, "loader_rejected": 1}`; native identity errors `[]`. All individual failures, baseline/native program counters and raw phase workloads remain in coverage.json and the full archive. No program filtering or binder weakening was added; the same native-only service, kernel, modules, app and workload were reused. QEMU timing is functional only. This result does not establish all-six-app or remaining O1-O4 acceptance.
