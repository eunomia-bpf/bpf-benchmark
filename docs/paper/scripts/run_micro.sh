#!/usr/bin/env bash
# DEPRECATED: Use Makefile targets instead:
#   make smoke           → host llvmbpf-only smoke (replaces --llvmbpf-only)
#   make vm-micro        → VM full suite (replaces --vm)
#   make vm-micro-smoke  → VM quick smoke
#   make vm-micro BENCH="simple bitcount"  → specific benchmarks in VM
# This script is kept for backward compatibility but all entry points have been
# consolidated into the root Makefile calling micro/driver.py directly.
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
MICRO_DIR="$ROOT_DIR/micro"
RESULTS_DIR="$MICRO_DIR/results"
# Auto-detect virtualenv activate script across common locations.
_find_venv_activate() {
    local candidates=(
        "$HOME/workspace/.venv/bin/activate"
        "$HOME/.venv/bin/activate"
        "$ROOT_DIR/.venv/bin/activate"
        "$ROOT_DIR/venv/bin/activate"
    )
    for c in "${candidates[@]}"; do
        if [[ -f "$c" ]]; then
            echo "$c"
            return
        fi
    done
    # fall back to first candidate even if missing (error will be reported below)
    echo "${candidates[0]}"
}
VENV_ACTIVATE="$(_find_venv_activate)"
DEFAULT_KERNEL_IMAGE="$ROOT_DIR/vendor/linux-framework/arch/x86/boot/bzImage"

mode="host"
llvmbpf_only=0
kernel_image="$DEFAULT_KERNEL_IMAGE"
vng_bin="${VNG_BIN:-$(command -v vng || true)}"
explicit_output=0
extra_args=()

usage() {
    cat <<EOF
Usage: ./docs/paper/scripts/run_micro.sh [--vm] [--llvmbpf-only] [extra run_micro.py args]

DEPRECATED: Use Makefile targets instead (make smoke / make vm-micro / make vm-micro-smoke).

Modes:
  --vm             Run inside vng with $DEFAULT_KERNEL_IMAGE
  --llvmbpf-only   Run only the llvmbpf runtime

Examples:
  ./docs/paper/scripts/run_micro.sh
  ./docs/paper/scripts/run_micro.sh --vm
  ./docs/paper/scripts/run_micro.sh --llvmbpf-only
  ./docs/paper/scripts/run_micro.sh --bench simple --iterations 1 --warmups 0 --repeat 10
EOF
}

quote_command() {
    local quoted=()
    local part
    for part in "$@"; do
        local escaped
        printf -v escaped '%q' "$part"
        quoted+=("$escaped")
    done
    local IFS=' '
    printf '%s' "${quoted[*]}"
}

while (($# > 0)); do
    case "$1" in
        --vm)
            mode="vm"
            shift
            ;;
        --llvmbpf-only)
            llvmbpf_only=1
            shift
            ;;
        --kernel-image)
            if (($# < 2)); then
                echo "missing value for --kernel-image" >&2
                exit 2
            fi
            kernel_image="$2"
            shift 2
            ;;
        --vng)
            if (($# < 2)); then
                echo "missing value for --vng" >&2
                exit 2
            fi
            vng_bin="$2"
            shift 2
            ;;
        --output)
            if (($# < 2)); then
                echo "missing value for --output" >&2
                exit 2
            fi
            explicit_output=1
            extra_args+=("$1" "$2")
            shift 2
            ;;
        --runtime)
            echo "--runtime is managed by docs/paper/scripts/run_micro.sh; use --llvmbpf-only or the default dual-runtime mode." >&2
            exit 2
            ;;
        --help|-h)
            usage
            exit 0
            ;;
        *)
            extra_args+=("$1")
            shift
            ;;
    esac
done

if [[ ! -f "$VENV_ACTIVATE" ]]; then
    echo "missing virtualenv activate script: $VENV_ACTIVATE" >&2
    exit 1
fi

if [[ "$mode" == "host" && "$llvmbpf_only" -eq 0 && "$EUID" -ne 0 ]]; then
    if ! sudo -n true >/dev/null 2>&1; then
        echo "host kernel runs require passwordless sudo; use --llvmbpf-only or --vm if sudo -n is unavailable." >&2
        exit 1
    fi
fi

mkdir -p "$RESULTS_DIR"
make -C "$MICRO_DIR"

# shellcheck disable=SC1091
source "$VENV_ACTIVATE"

run_micro_cmd=(python3 "$MICRO_DIR/driver.py" suite)
if [[ "$llvmbpf_only" -eq 1 ]]; then
    run_micro_cmd+=(--runtime llvmbpf)
else
    run_micro_cmd+=(--runtime llvmbpf --runtime kernel)
fi

if [[ "$explicit_output" -eq 0 ]]; then
    if [[ "$mode" == "vm" ]]; then
        run_micro_cmd+=(--output "$RESULTS_DIR/pure_jit.vm.latest.json")
    elif [[ "$llvmbpf_only" -eq 1 ]]; then
        run_micro_cmd+=(--output "$RESULTS_DIR/pure_jit.llvmbpf_only.latest.json")
    else
        run_micro_cmd+=(--output "$RESULTS_DIR/pure_jit.latest.json")
    fi
fi

run_micro_cmd+=("${extra_args[@]}")

if [[ "$mode" == "vm" ]]; then
    if [[ -z "$vng_bin" ]]; then
        echo "vng is not available in PATH; cannot use --vm." >&2
        exit 1
    fi
    if [[ ! -f "$kernel_image" ]]; then
        echo "kernel image not found: $kernel_image" >&2
        exit 1
    fi

    guest_shell="source $(printf '%q' "$VENV_ACTIVATE") && $(quote_command "${run_micro_cmd[@]}")"
    exec "$vng_bin" \
        --run "$kernel_image" \
        --cwd "$ROOT_DIR" \
        --disable-monitor \
        --cpus 1 \
        --rwdir "$MICRO_DIR" \
        --exec "$(quote_command bash -lc "$guest_shell")"
fi

exec "${run_micro_cmd[@]}"
