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
#   BPFOPT_PASSES=map-inline,const-prop,dce scripts/per-pass-verify.sh 123 xdp
#   BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp
#
# Environment:
#   BPFOPT_PASSES   Comma-separated pass list. Defaults to the v3 section 5 order.
#   BPFOPT_DRY_RUN  Set to 1 to print commands without executing them.
#
# Dependencies:
#   bash, diff, mktemp, cp, rm, bpfget, bpfopt, bpfverify, bpfrejit

set -euo pipefail

DEFAULT_PASSES="map-inline,const-prop,dce,skb-load-bytes,bounds-check-merge,wide-mem,bulk-memory,rotate,cond-select,extract,endian,branch-flip"
CURRENT=""
CANDIDATE=""
PASSES=()

usage() {
  cat <<'USAGE'
Usage:
  scripts/per-pass-verify.sh PROG_ID PROG_TYPE

Examples:
  scripts/per-pass-verify.sh 123 xdp
  BPFOPT_PASSES=map-inline,const-prop,dce scripts/per-pass-verify.sh 123 xdp
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

print_cmd() {
  printf '+'
  printf ' %q' "$@"
  printf '\n'
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
    printf '+ bpfopt %q < %q > %q 2>/dev/null\n' "$pass" "$current" "$candidate"
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
    if ! bpfopt "$pass" <"$CURRENT" >"$CANDIDATE" 2>/dev/null; then
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
