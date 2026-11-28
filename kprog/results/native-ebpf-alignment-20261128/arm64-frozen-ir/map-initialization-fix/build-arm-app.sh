#!/bin/bash
set -eu
cd /workspaces/repository
export GOMAXPROCS=2 GOFLAGS='-p=2 -mod=readonly'
make -C vendor otel-arm64 JOBS=2
