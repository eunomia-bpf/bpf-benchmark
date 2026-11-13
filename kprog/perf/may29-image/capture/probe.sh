#!/bin/sh
# Print the profiler's own profile-export counters while the app runs.
# otelcol serves them at :8888; data_type="profiles" tags the profile pipeline.
# otelcol_exporter_queue_batch_send_size_sum is the total number of profiles the
# exporter has sent -- the "reported trace count" for this arm.
for cid in $(docker ps -q 2>/dev/null); do
    docker exec "$cid" sh -c 'command -v otelcol-ebpf-profiler >/dev/null' 2>/dev/null || continue
    docker exec "$cid" curl -s --max-time 3 localhost:8888/metrics 2>/dev/null \
        | grep -E '^otelcol_exporter_(sent|queue_batch_send_size_(sum|count))' \
        | sed -E 's/\{[^}]*\} / /'
    exit 0
done
exit 1
