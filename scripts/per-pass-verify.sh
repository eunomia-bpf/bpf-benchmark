#!/usr/bin/env bash
# shellcheck shell=bash
#
# Run the bpfopt-suite v3 per-pass verify loop for one live BPF program.
#
# Usage:
#   scripts/per-pass-verify.sh PROG_ID PROG_TYPE
#
# Examples:
#   scripts/per-pass-verify.sh 123 xdp
#   BPFOPT_PASSES=const-prop BPFOPT_VERIFIER_STATES=states.json scripts/per-pass-verify.sh 123 xdp
#   BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp
#
# Environment:
#   BPFOPT_PASSES           Comma-separated pass list. Defaults to the zero-side-input subset:
#                           dce,skb-load-bytes,bounds-check-merge,wide-mem.
#   BPFOPT_TARGET           target.json path passed to bpfopt --target.
#   BPFOPT_VERIFIER_STATES  verifier-states.json path passed to bpfopt --verifier-states.
#   BPFOPT_MAP_VALUES       map-values.json path passed to bpfopt --map-values.
#   BPFOPT_MAP_IDS          Comma-separated map IDs passed to bpfopt --map-ids.
#   BPFOPT_PROFILE          profile.json path passed to bpfopt --profile.
#   BPFOPT_DRY_RUN          Set to 1 to print commands without executing them.
#
# To run passes that require side inputs, set BPFOPT_PASSES explicitly and provide the
# corresponding BPFOPT_* environment variables above.
#
# Dependencies:
#   bash, diff, mktemp, cp, rm, bpfget, bpfopt, bpfverify, bpfrejit

set -euo pipefail

DEFAULT_PASSES="dce,skb-load-bytes,bounds-check-merge,wide-mem"
CURRENT=""
CANDIDATE=""
PASSES=()
BPFOPT_SIDE_INPUT_ARGS=()

usage() {
  cat <<'USAGE'
Usage:
  scripts/per-pass-verify.sh PROG_ID PROG_TYPE

Examples:
  scripts/per-pass-verify.sh 123 xdp
  BPFOPT_PASSES=const-prop BPFOPT_VERIFIER_STATES=states.json scripts/per-pass-verify.sh 123 xdp
  BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp
USAGE
}

warn() {
  printf 'warning: %s\n' "$*" >&2
}

die() {
  printf 'error: %s\n' "$*" >&2
  exit 1
}

trim_space() {
  local value=$1
  value=${value#"${value%%[![:space:]]*}"}
  value=${value%"${value##*[![:space:]]}"}
  printf '%s' "$value"
}

parse_passes() {
  local pass_csv=${BPFOPT_PASSES:-$DEFAULT_PASSES}
  local -a raw_passes=()
  local raw_pass trimmed

  IFS=',' read -r -a raw_passes <<<"$pass_csv"
  PASSES=()
  for raw_pass in "${raw_passes[@]}"; do
    trimmed=$(trim_space "$raw_pass")
    if [[ -n $trimmed ]]; then
      PASSES+=("$trimmed")
    fi
  done

  if [[ ${#PASSES[@]} -eq 0 ]]; then
    die "BPFOPT_PASSES did not contain any pass names"
  fi
}

append_bpfopt_arg_if_set() {
  local env_name=$1
  local flag=$2
  local value=${!env_name:-}

  if [[ -n $value ]]; then
    BPFOPT_SIDE_INPUT_ARGS+=("$flag" "$value")
  fi
}

build_bpfopt_side_input_args() {
  BPFOPT_SIDE_INPUT_ARGS=()
  append_bpfopt_arg_if_set BPFOPT_TARGET --target
  append_bpfopt_arg_if_set BPFOPT_VERIFIER_STATES --verifier-states
  append_bpfopt_arg_if_set BPFOPT_MAP_VALUES --map-values
  append_bpfopt_arg_if_set BPFOPT_MAP_IDS --map-ids
  append_bpfopt_arg_if_set BPFOPT_PROFILE --profile
}

print_cmd() {
  printf '+'
  printf ' %q' "$@"
  printf '\n'
}

print_bpfopt_cmd() {
  local pass=$1
  local input=$2
  local output=$3

  printf '+'
  printf ' %q' bpfopt "$pass" "${BPFOPT_SIDE_INPUT_ARGS[@]}"
  printf ' < %q > %q\n' "$input" "$output"
}

cleanup() {
  [[ -n ${CURRENT:-} ]] && rm -f "$CURRENT"
  [[ -n ${CANDIDATE:-} ]] && rm -f "$CANDIDATE"
}

run_dry_run() {
  local prog_id=$1
  local prog_type=$2
  local current="${TMPDIR:-/tmp}/bpfopt-current.${prog_id}.dry-run"
  local candidate="${TMPDIR:-/tmp}/bpfopt-candidate.${prog_id}.dry-run"
  local pass

  printf '# dry run: commands are printed, not executed\n'
  printf '+ CURRENT=$(mktemp)\n'
  printf '+ CANDIDATE=$(mktemp)\n'
  printf '+ trap cleanup EXIT\n'
  printf '+ bpfget %q > %q\n' "$prog_id" "$current"

  for pass in "${PASSES[@]}"; do
    print_bpfopt_cmd "$pass" "$current" "$candidate"
    print_cmd diff -q "$current" "$candidate"
    printf '+ bpfverify --prog-type %q < %q >/dev/null\n' "$prog_type" "$candidate"
    print_cmd cp "$candidate" "$current"
    printf 'pass %s: dry-run, skipped execution\n' "$pass"
  done

  print_cmd bpfrejit "$prog_id" "$current"
}

main() {
  if [[ ${1:-} == "-h" || ${1:-} == "--help" ]]; then
    usage
    exit 0
  fi

  if [[ $# -ne 2 ]]; then
    usage >&2
    exit 1
  fi

  local prog_id=$1
  local prog_type=$2
  local pass diff_status

  parse_passes
  build_bpfopt_side_input_args

  if [[ ${BPFOPT_DRY_RUN:-0} == "1" ]]; then
    run_dry_run "$prog_id" "$prog_type"
    exit 0
  fi

  trap cleanup EXIT

  CURRENT=$(mktemp)
  CANDIDATE=$(mktemp)

  if ! bpfget "$prog_id" >"$CURRENT"; then
    die "bpfget failed for program $prog_id"
  fi

  for pass in "${PASSES[@]}"; do
    if ! bpfopt "$pass" "${BPFOPT_SIDE_INPUT_ARGS[@]}" <"$CURRENT" >"$CANDIDATE"; then
      warn "pass $pass: bpfopt failed, rolled back"
      continue
    fi

    if diff -q "$CURRENT" "$CANDIDATE" >/dev/null 2>&1; then
      printf 'pass %s: no change\n' "$pass"
      continue
    fi

    diff_status=$?
    if [[ $diff_status -gt 1 ]]; then
      warn "pass $pass: diff failed, rolled back"
      continue
    fi

    if bpfverify --prog-type "$prog_type" <"$CANDIDATE" >/dev/null; then
      cp "$CANDIDATE" "$CURRENT"
      printf 'pass %s: accepted\n' "$pass"
    else
      warn "pass $pass: verify failed, rolled back"
    fi
  done

  if ! bpfrejit "$prog_id" "$CURRENT"; then
    die "bpfrejit failed for program $prog_id"
  fi
}

main "$@"
