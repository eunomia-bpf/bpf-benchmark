#!/usr/bin/env bash
set -euo pipefail

# Shared local-prep helpers.
# Callers must define:
# - die()

require_local_path() {
    local path="$1"
    local description="$2"
    [[ -e "$path" ]] || die "${description} not found: ${path}"
}

require_nonempty_dir() {
    local path="$1"
    local description="$2"
    [[ -d "$path" ]] || die "${description} is not a directory: ${path}"
    find "$path" -mindepth 1 -print -quit 2>/dev/null | grep -q . || die "${description} is empty: ${path}"
}

git_path_is_clean() {
    local repo_root="$1"
    local pathspec="${2:-}"
    if [[ -n "$pathspec" ]]; then
        git -C "$repo_root" diff --quiet -- "$pathspec" || return 1
        git -C "$repo_root" diff --cached --quiet -- "$pathspec" || return 1
    else
        git -C "$repo_root" diff --quiet || return 1
        git -C "$repo_root" diff --cached --quiet || return 1
    fi
}

snapshot_git_subtree() {
    local repo_root="$1"
    local src_rel="$2"
    local dest="$3"
    local strip_components=0
    git -C "$repo_root" rev-parse --verify HEAD >/dev/null 2>&1 \
        || die "expected git checkout for promoted snapshot: ${repo_root}"
    if [[ -n "$src_rel" ]]; then
        git_path_is_clean "$repo_root" "$src_rel" \
            || die "git subtree has local modifications and cannot be promoted: ${repo_root}/${src_rel}"
        strip_components="$(awk -F/ '{print NF}' <<<"$src_rel")"
    else
        git_path_is_clean "$repo_root" \
            || die "git checkout has local modifications and cannot be promoted: ${repo_root}"
    fi
    mkdir -p "$dest"
    if [[ -n "$src_rel" ]]; then
        git -C "$repo_root" archive --format=tar HEAD -- "$src_rel" \
            | tar -xf - -C "$dest" --strip-components="$strip_components"
    else
        git -C "$repo_root" archive --format=tar HEAD | tar -xf - -C "$dest"
    fi
    find "$dest" -mindepth 1 -print -quit 2>/dev/null | grep -q . \
        || die "promoted snapshot is empty: ${repo_root}${src_rel:+/${src_rel}}"
}

write_bundle_input_var() {
    local output_path="$1"
    local key="$2"
    local value="${3-}"
    printf '%s=%q\n' "$key" "$value" >>"$output_path"
}

dir_has_entries() {
    local path="$1"
    [[ -d "$path" ]] || return 1
    find "$path" -mindepth 1 -maxdepth 1 -print -quit 2>/dev/null | grep -q .
}

csv_append_unique() {
    local csv="$1"
    local token="$2"
    case ",${csv}," in
        *,"${token}",*) printf '%s\n' "$csv" ;;
        ,,) printf '%s\n' "$token" ;;
        *) printf '%s,%s\n' "$csv" "$token" ;;
    esac
}

stage_module_binaries() {
    local source_dir="$1"
    local stage_dir="$2"
    local ko_count
    require_local_path "$source_dir" "kinsn module source dir"
    rm -rf "$stage_dir"
    mkdir -p "$stage_dir"
    find "$source_dir" -maxdepth 1 -type f -name '*.ko' -exec cp '{}' "$stage_dir/" \;
    ko_count="$(find "$stage_dir" -maxdepth 1 -name '*.ko' | wc -l | tr -d ' ')"
    [[ "$ko_count" -gt 0 ]] || die "no kinsn modules staged under ${stage_dir}"
}
