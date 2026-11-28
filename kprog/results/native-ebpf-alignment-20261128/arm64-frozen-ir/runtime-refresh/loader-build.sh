#!/bin/bash
set -euo pipefail
cd /workspaces/repository
cmake --build runner/build-arm64-llvmbpf --target native_loader_shared -j2
aarch64-linux-gnu-strip --strip-unneeded runner/build-arm64-llvmbpf/native_loader/libnative_loader.so
