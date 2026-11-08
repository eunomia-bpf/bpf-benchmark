Cilium endpoint creation through the existing readiness waiter

The captured five-step replay142681d1f reaches Cilium API endpoint creation during the JIT baseline. Its synchronous API request expires while the agent continues compiling BPF: the saved log records4m13s for the host template and reports the endpoint-generation deadline at9m52s. Native service requests total0 for this cohort.

The runner now requests asynchronous endpoint creation and uses its existing _wait_endpoint_ready loop before workload setup. The same endpoint fields, program-loading path, workload and agent-exit handling remain active. The current source parses successfully; the next complete QEMU cohort supplies runtime results.
