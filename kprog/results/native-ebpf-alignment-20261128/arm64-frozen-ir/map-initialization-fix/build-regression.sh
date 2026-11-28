#!/bin/bash
set -eu
cd /workspaces/repository
export GOTOOLCHAIN=auto GOCACHE=/workspaces/repository/.cache/go-build GOMODCACHE=/workspaces/repository/.cache/go-mod GOMAXPROCS=2 GOFLAGS='-p=2 -mod=readonly'
make -C vendor/repos/opentelemetry-ebpf-profiler integration-test-binaries -o generate -o ebpf -o pprof-execs TEST_INTEGRATION_BINARY_DIRS=tracer TARGET_ARCH=arm64 -j2
