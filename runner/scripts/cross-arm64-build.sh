#!/bin/bash
# Cross-build ARM64 micro_exec + daemon inside a Docker container.
# Called by `make cross-arm64` with /workspace mounted to repo root
# and /out mounted to the output directory.
#
# Environment variables (set by Docker run):
#   ARM64_CROSSBUILD_JOBS - parallel build jobs (default: 4)
set -euo pipefail

JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
build_root=/tmp/bpf-benchmark-arm64
runner_build="$build_root/runner"
daemon_target="$build_root/daemon-target"
cargo_home="$build_root/cargo-home"
home_dir="$build_root/home"

rm -rf "$build_root"
mkdir -p /out/runner/build /out/daemon/build /out/lib "$cargo_home" "$home_dir"

# Build runner
export CMAKE_BUILD_PARALLEL_LEVEL="$JOBS"
export HOME="$home_dir"
export CARGO_HOME="$cargo_home"
make -C /workspace/runner \
    BUILD_DIR="$runner_build" \
    JOBS="$JOBS" \
    MICRO_EXEC_ENABLE_LLVMBPF="${MICRO_EXEC_ENABLE_LLVMBPF:-ON}" \
    micro_exec >/dev/null

# Build daemon
CARGO_TARGET_DIR="$daemon_target" \
    cargo build --release -j "$JOBS" --manifest-path /workspace/daemon/Cargo.toml >/dev/null

# Copy binaries
cp "$runner_build/micro_exec" /out/runner/build/micro_exec.real
cp "$daemon_target/release/bpfrejit-daemon" /out/daemon/build/bpfrejit-daemon.real

# Copy runtime libraries
copy_runtime_libs() {
    local binary="$1"
    local lib
    while read -r lib; do
        case "$(basename "$lib")" in
            libyaml-cpp.so*|libelf.so*|libz.so*|libzstd.so*|libstdc++.so*|libgcc_s.so*|libbpf.so*|libtinfo.so*|libncurses.so*|libncursesw.so*)
                cp -L "$lib" /out/lib/ ;;
        esac
    done < <(ldd "$binary" | awk '/=> \// {print $3} /^\// {print $1}' | sort -u)
}
copy_runtime_libs /out/runner/build/micro_exec.real
copy_runtime_libs /out/daemon/build/bpfrejit-daemon.real

# Generate LD_LIBRARY_PATH wrapper scripts
for pair in "runner/build/micro_exec:micro_exec.real" "daemon/build/bpfrejit-daemon:bpfrejit-daemon.real"; do
    wrapper="/out/${pair%%:*}"
    real="${pair##*:}"
    cat > "$wrapper" <<'WRAPPER'
#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
LIB_DIR="$BUNDLE_ROOT/lib"
export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
WRAPPER
    echo "exec \"\$SCRIPT_DIR/$real\" \"\$@\"" >> "$wrapper"
    chmod +x "$wrapper"
done

file /out/runner/build/micro_exec.real
file /out/daemon/build/bpfrejit-daemon.real
