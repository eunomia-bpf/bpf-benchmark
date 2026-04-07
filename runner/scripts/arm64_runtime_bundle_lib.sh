#!/usr/bin/env bash
set -euo pipefail

# Shared ARM64 host-side runtime bundling helpers.
# Callers must define:
# - READELF_BIN
# - SYSROOT_USR_LIB_DIR
# - SYSROOT_LIB_DIR
# - SYSROOT_LEGACY_LIB_DIR
# - SYSROOT_ALT_LIB_DIR
# - die()

arm64_bundle_read_needed_libraries() {
    local binary="$1"
    "$READELF_BIN" -d "$binary" 2>/dev/null | sed -n 's/.*Shared library: \[\(.*\)\].*/\1/p' | sort -u
}

arm64_bundle_resolve_library_path() {
    local soname="$1"
    local candidate
    for candidate in \
        "$SYSROOT_USR_LIB_DIR/$soname" \
        "$SYSROOT_LIB_DIR/$soname" \
        "$SYSROOT_LEGACY_LIB_DIR/$soname" \
        "$SYSROOT_ALT_LIB_DIR/$soname"
    do
        [[ -e "$candidate" ]] && {
            printf '%s\n' "$candidate"
            return 0
        }
    done
    die "unable to resolve ARM64 shared library ${soname}"
}

arm64_bundle_copy_runtime_bundle() {
    local binary="$1"
    local output_lib_dir="$2"
    local current lib resolved resolved_base requested_base soname
    local -a queue=("$binary")
    declare -A seen=()

    mkdir -p "$output_lib_dir"
    while ((${#queue[@]})); do
        current="${queue[0]}"
        queue=("${queue[@]:1}")
        [[ -e "$current" ]] || continue
        [[ -z "${seen["$current"]:-}" ]] || continue
        seen["$current"]=1
        while IFS= read -r lib; do
            [[ -n "$lib" ]] || continue
            resolved="$(arm64_bundle_resolve_library_path "$lib")"
            resolved_base="$(basename "$resolved")"
            requested_base="$(basename "$lib")"
            case "$resolved_base" in
                ld-linux-aarch64.so.1|libc.so.6|libm.so.6|libpthread.so.0|librt.so.1|libdl.so.2|libresolv.so.2|libutil.so.1)
                    continue
                    ;;
            esac
            cp -L "$resolved" "$output_lib_dir/$resolved_base"
            if [[ "$requested_base" != "$resolved_base" ]]; then
                ln -sfn "$resolved_base" "$output_lib_dir/$requested_base"
            fi
            soname="$("$READELF_BIN" -d "$resolved" 2>/dev/null | sed -n 's/.*Library soname: \[\(.*\)\].*/\1/p' | head -n1)"
            if [[ -n "$soname" && "$soname" != "$resolved_base" ]]; then
                ln -sfn "$resolved_base" "$output_lib_dir/$soname"
            fi
            queue+=("$resolved")
        done < <(arm64_bundle_read_needed_libraries "$current")
    done
}
