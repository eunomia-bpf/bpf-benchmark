#!/bin/sh
# OTel's native unwinder retires as many instructions as the eBPF one but takes more cycles (README-otel.md);
# sample last-level cache misses after the coordinator's Cilium rerun (kdata4) ends, on the current image.
until test -f /workspaces/kprog-raw/verified/checked-corpus-20261125-kdata4.done; do sleep 60; done
cd /workspaces/repository
EVENT=cpu_core/cache-misses/ PERIOD=2000 bash kprog/results/profile-20261123/profile-host.sh otelcol-ebpf-profiler/profiling /workspaces/kprog-raw/coordinator/profile-20261123/otel-host-cachemiss-20261125 native_tracer_e > /workspaces/kprog-raw/coordinator/profile-20261123/otel-host-cachemiss-20261125.log 2>&1
echo $? > /workspaces/kprog-raw/coordinator/profile-20261123/otel-host-cachemiss-20261125.done
