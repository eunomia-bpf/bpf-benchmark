2026-11-16T06:33:59Z

Focused checked BCC confirmation is running as PID 1386206. It uses the tested BTF IR compiler and the normal scalar spill pass with the existing production recovery bridge. These two binaries are pinned until the job ends. Canonical base and timing image remain unchanged. The functional configuration is one 10-second sample with stats on, CPU 16, two guest vCPUs, 8 GiB guest memory and 16 GiB address space. No timing lock is taken.

Both previously failing BCC bodies pass isolated stock replay, but the latest completed whole-app observation remains 25 native / 25 B generated / 23 stock accepted until this check finishes. Full logs and service archive stay at /workspaces/kprog-raw/perf/20261116-bcc-all-stock. queue.json records the launch.
