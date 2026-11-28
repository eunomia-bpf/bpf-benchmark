#!/bin/sh
# Start a read-only observer alongside the original frozen init; no corpus setting changes.
# Operator compile address-space cap, inside the 8GiB guest only; host QEMU remains unlimited.
ulimit -v 50331648
(
 while [ ! -r /proc/uptime ] || [ ! -r /sys/devices/system/cpu/possible ]; do sleep 1; done
 exec python3 /perf-observe/observe_guest.py /perf-observe/data
) > /perf-observe/observer.log 2>&1 &
exec /qemu-original-init
