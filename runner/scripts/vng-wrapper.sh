#!/bin/bash
# Wrapper around vng that provides a PTY via script(1) when needed.
# vng requires /proc/self/fd/{0,1,2} to be O_RDWR (i.e., a real PTY).

# Sentinel: re-invoked under script with args saved in a temp file.
if [ "${__VNG_WRAP:-}" = "1" ]; then
    unset __VNG_WRAP
    mapfile -d '' -t args < "$1"
    rm -f "$1"
    exec vng "${args[@]}"
fi

# If all three fds are ttys, just run vng directly.
if test -t 0 && test -t 1 && test -t 2; then
    exec vng "$@"
fi

# Save args as NUL-delimited to a temp file, then re-invoke under script(1).
_tmpargs=$(mktemp /tmp/vng-wrapper.XXXXXX)
printf '%s\0' "$@" > "$_tmpargs"
export __VNG_WRAP=1
_self="$(realpath "$0")"
exec script -qfec "$_self $_tmpargs" /dev/null
