#!/bin/bash
# Generate the AWS ARM64 kernel config from the stock AL2023 baseline and add
# only the repo-required BPF/tracing bits.
# Usage: aws_arm64_kernel_config.sh <WORKTREE> <BUILD_DIR> <CROSS_COMPILE>
set -eu -o pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# shellcheck source=runner/scripts/arm64_kernel_config_common.sh
source "$SCRIPT_DIR/arm64_kernel_config_common.sh"

WORKTREE="$1"
BUILD_DIR="$2"
CROSS_COMPILE="${3:-aarch64-linux-gnu-}"
BASE_CONFIG="${ARM64_BASE_CONFIG:-}"
ENA_MODE=""

if [ -z "$BASE_CONFIG" ] || [ ! -f "$BASE_CONFIG" ]; then
    echo "ARM64_BASE_CONFIG must point to a readable AL2023 baseline config for aws_arm64_kernel_config.sh" >&2
    exit 1
fi

mkdir -p "$BUILD_DIR"
cp "$BASE_CONFIG" "$BUILD_DIR/.config"

if grep -Eq '^CONFIG_AMAZON_ENA_ETHERNET=y$' "$BUILD_DIR/.config"; then
    ENA_MODE="y"
elif grep -Eq '^CONFIG_AMAZON_ENA_ETHERNET=m$' "$BUILD_DIR/.config"; then
    ENA_MODE="m"
fi

arm64_apply_repo_required_config "$WORKTREE" "$BUILD_DIR/.config"
"$WORKTREE/scripts/config" --file "$BUILD_DIR/.config" \
    -d LOCALVERSION_AUTO \
    -e NET_VENDOR_AMAZON -m ENA_ETHERNET

case "$ENA_MODE" in
    y)
        "$WORKTREE/scripts/config" --file "$BUILD_DIR/.config" -e NET_VENDOR_AMAZON -e ENA_ETHERNET
        ;;
    m)
        "$WORKTREE/scripts/config" --file "$BUILD_DIR/.config" -e NET_VENDOR_AMAZON -m ENA_ETHERNET
        ;;
esac

arm64_finalize_kernel_config "$WORKTREE" "$BUILD_DIR" "$CROSS_COMPILE"
