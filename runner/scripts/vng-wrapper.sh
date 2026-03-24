#!/bin/bash
# Wrapper around vng that provides a PTY via script(1) when needed.
# vng requires /proc/self/fd/{0,1,2} to be O_RDWR (i.e., a real PTY).

# Sentinel: re-invoked under script with args saved in a temp file.
if [ "${__VNG_WRAP:-}" = "1" ]; then
    unset __VNG_WRAP
    mapfile -d '' -t args < "$1"
    rm -f "$1"
    if [ "${VNG_WRAPPER_DEBUG:-0}" = "1" ]; then
        printf 'vng-wrapper exec: vng' >&2
        printf ' %q' "${args[@]}" >&2
        printf '\n' >&2
    fi
    vng "${args[@]}"
    _rc=$?
    if [ "${VNG_WRAPPER_DEBUG:-0}" = "1" ]; then
        printf 'vng-wrapper exit: %s\n' "$_rc" >&2
    fi
    exit "$_rc"
fi

# If all three fds are ttys, just run vng directly.
if test -t 0 && test -t 1 && test -t 2; then
    exec vng "$@"
fi

# Save args as NUL-delimited to a temp file, then re-invoke under script(1).
# Capture the transcript so non-interactive callers still see virtme-ng output.
_tmpargs=$(mktemp /tmp/vng-wrapper.XXXXXX)
_tmplog=$(mktemp /tmp/vng-wrapper-log.XXXXXX)
printf '%s\0' "$@" > "$_tmpargs"
export __VNG_WRAP=1
_self="$(realpath "$0")"
script -qfec "$_self $_tmpargs" "$_tmplog"
_rc=$?
cat "$_tmplog"
rm -f "$_tmplog"
exit "$_rc"
