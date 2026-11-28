#!/bin/sh
set -eu
mount -t tmpfs tmpfs /tmp
mkdir /tmp/perf-source
mount -t 9p -o trans=virtio,version=9p2000.L,ro perf-source /tmp/perf-source
uname -a
sha256sum /tmp/perf-source/vendor/repos/opentelemetry-ebpf-profiler/support/tracer.test
exec /tmp/perf-source/vendor/repos/opentelemetry-ebpf-profiler/support/tracer.test -test.v -test.run '^TestLoadAllMapsInitializesConfiguredVariables$'
