#!/bin/bash
set -eu
cd /workspaces/repository/vendor/build/otelcol-ebpf-profiler-build-arm64
export GOTOOLCHAIN=auto GOCACHE=/workspaces/repository/.cache/go-build GOMODCACHE=/workspaces/repository/.cache/go-mod GOMAXPROCS=2 GOFLAGS='-p=2 -mod=readonly'
export GOOS=linux GOARCH=arm64 CGO_ENABLED=0 CC=aarch64-linux-gnu-gcc
go list -m -json github.com/cilium/ebpf go.opentelemetry.io/ebpf-profiler
go test -ldflags='-extldflags=-static' -trimpath -c -tags osusergo,netgo,static_build,integration -o /workspaces/repository/vendor/repos/opentelemetry-ebpf-profiler/support/tracer.test go.opentelemetry.io/ebpf-profiler/tracer
