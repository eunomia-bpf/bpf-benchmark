#!/bin/sh
for cid in $(docker ps -q 2>/dev/null); do
    docker exec "$cid" sh -c 'command -v otelcol-ebpf-profiler >/dev/null' 2>/dev/null || continue
    docker exec "$cid" curl -s --max-time 3 localhost:8888/metrics 2>/dev/null | grep -E '^otelcol_' | sed -E 's/\{.*//' | sort -u
    exit 0
done
exit 1
