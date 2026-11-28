#!/bin/bash
set -eu
cd /workspaces/repository
export GOTOOLCHAIN=auto GOCACHE=/workspaces/repository/.cache/go-build GOMODCACHE=/workspaces/repository/.cache/go-mod GOMAXPROCS=2
go -C vendor/build/otelcol-ebpf-profiler-build-arm64 run -p 2 -mod=readonly /workspaces/repository/kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/constant-origin/reproduce_variable_map_split.go /workspaces/repository/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.arm64 /workspaces/repository/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64
