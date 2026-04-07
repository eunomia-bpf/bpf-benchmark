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

write_bundle_input_var_if_set() {
    local output_path="$1"
    local key="$2"
    local value="${3-}"
    [[ -n "$value" ]] || return 0
    write_bundle_input_var "$output_path" "$key" "$value"
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

csv_merge_unique() {
    local merged="" csv token
    for csv in "$@"; do
        [[ -n "$csv" ]] || continue
        IFS=',' read -r -a _csv_merge_tokens <<<"$csv"
        for token in "${_csv_merge_tokens[@]}"; do
            [[ -n "$token" ]] || continue
            merged="$(csv_append_unique "$merged" "$token")"
        done
    done
    printf '%s\n' "$merged"
}

local_prep_fetch_selected_repos() {
    local repo_root="$1"
    local repo_csv="$2"
    local host_python_bin="$3"
    local project_root="$4"
    local repo
    local args=()
    [[ -n "$repo_csv" ]] || return 0
    mkdir -p "$repo_root"
    IFS=',' read -r -a _local_prep_fetch_repos <<<"$repo_csv"
    for repo in "${_local_prep_fetch_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    "$host_python_bin" "$project_root/runner/scripts/fetch_corpus_repos.py" \
        --repo-root "$repo_root" \
        "${args[@]}" >/dev/null
}

x86_tool_should_be_bundled() {
    case "$1" in
        wrk|sysbench|hackbench|stress-ng|fio|bpftrace) return 0 ;;
    esac
    return 1
}

local_prep_stage_x86_workload_tools() {
    local requested_csv="$1"
    local output_root="$2"
    local csv_output_var="$3"
    local root_output_var="$4"
    local bundled_csv="" tool tool_path
    local -n csv_output_ref="$csv_output_var"
    local -n root_output_ref="$root_output_var"

    csv_output_ref=""
    root_output_ref=""
    [[ -n "$requested_csv" ]] || return 0

    IFS=',' read -r -a _x86_workload_tools <<<"$requested_csv"
    for tool in "${_x86_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        x86_tool_should_be_bundled "$tool" || continue
        bundled_csv="$(csv_append_unique "$bundled_csv" "$tool")"
    done

    [[ -n "$bundled_csv" ]] || return 0
    rm -rf "$output_root"
    mkdir -p "$output_root/bin"
    for tool in "${_x86_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        x86_tool_should_be_bundled "$tool" || continue
        tool_path="$(command -v "$tool" 2>/dev/null || true)"
        [[ -n "$tool_path" && -x "$tool_path" ]] \
            || die "required x86 bundled workload tool is missing on the host: ${tool}"
        cp -L "$tool_path" "$output_root/bin/$tool"
        chmod 0755 "$output_root/bin/$tool"
        require_local_path "$output_root/bin/$tool" "x86 bundled workload tool ${tool}"
    done

    csv_output_ref="$bundled_csv"
    root_output_ref="$output_root"
}

local_prep_stage_matching_micro_sidecars() {
    local output_dir="$1"
    local source_dir="$2"
    local generated_file program_name source_name staged_name
    [[ -d "$output_dir" ]] || return 0
    [[ -d "$source_dir" ]] || return 0
    while IFS= read -r -d '' generated_file; do
        program_name="$(basename "$generated_file" .bpf.o)"
        for source_name in directive.bin policy.bin; do
            [[ -f "$source_dir/${program_name}.${source_name}" ]] || continue
            staged_name="${program_name}.${source_name}"
            cp -a "$source_dir/${program_name}.${source_name}" "$output_dir/$staged_name"
        done
    done < <(find "$output_dir" -maxdepth 1 -type f -name '*.bpf.o' -print0)
}

local_prep_stage_katran_source_bundle() {
    local project_root="$1"
    local katran_input_root="$2"
    rm -rf "$katran_input_root"
    mkdir -p "$katran_input_root/bin" "$katran_input_root/lib"
    snapshot_git_subtree "$project_root" "e2e/cases/katran/bin" "$katran_input_root/bin"
    snapshot_git_subtree "$project_root" "e2e/cases/katran/lib" "$katran_input_root/lib"
    require_local_path "$katran_input_root/bin/katran_server_grpc" "sealed Katran server source bundle"
    require_nonempty_dir "$katran_input_root/lib" "sealed Katran lib dir"
}

local_prep_build_native_repo_artifacts() {
    local repo_root="$1"
    local build_root="$2"
    local native_repo_csv="$3"
    local host_python_bin="$4"
    local project_root="$5"
    local katran_input_root="$build_root/.inputs/katran"
    local repo
    local args=()
    [[ -n "$native_repo_csv" ]] || return 0
    [[ -d "$repo_root" ]] || die "repo root missing for native repo build: ${repo_root}"
    IFS=',' read -r -a _local_prep_native_repos <<<"$native_repo_csv"
    for repo in "${_local_prep_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    if [[ ",${native_repo_csv}," == *",katran,"* ]]; then
        local_prep_stage_katran_source_bundle "$project_root" "$katran_input_root"
        KATRAN_SERVER_BINARY="$katran_input_root/bin/katran_server_grpc" \
            KATRAN_SERVER_LIB_DIR="$katran_input_root/lib" \
            "$host_python_bin" "$project_root/runner/scripts/build_corpus_native.py" \
                --jobs "$(nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)" \
                --repo-root "$repo_root" \
                --build-root "$build_root/corpus/build" \
                "${args[@]}" >/dev/null
        return 0
    fi
    "$host_python_bin" "$project_root/runner/scripts/build_corpus_native.py" \
        --jobs "$(nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)" \
        --repo-root "$repo_root" \
        --build-root "$build_root/corpus/build" \
        "${args[@]}" >/dev/null
}

local_prep_build_scx_artifacts() {
    local repo_root="$1"
    local promote_root="$2"
    local package_csv="$3"
    local host_python_bin="$4"
    local project_root="$5"
    local package
    local scx_args=()
    [[ -n "$package_csv" ]] || return 0
    IFS=',' read -r -a _local_prep_scx_packages <<<"$package_csv"
    for package in "${_local_prep_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        scx_args+=(--package "$package")
    done
    [[ "${#scx_args[@]}" -gt 0 ]] || die "manifest scx package contract is empty"
    "$host_python_bin" "$project_root/runner/scripts/build_scx_artifacts.py" \
        --force \
        --repo-root "$repo_root" \
        --promote-root "$promote_root" \
        "${scx_args[@]}" >/dev/null
}

local_prep_build_x86_repo_tests() {
    local runner_dir="$1"
    local unittest_build_dir="$2"
    local negative_build_dir="$3"
    make -C "$runner_dir" \
        UNITTEST_BUILD_DIR="$unittest_build_dir" \
        NEGATIVE_BUILD_DIR="$negative_build_dir" \
        unittest-build negative-build >/dev/null
}

local_prep_build_x86_upstream_selftests() {
    local runner_dir="$1"
    local output_dir="$2"
    local vmlinux_btf="$3"
    local host_python_bin="$4"
    local llvm_suffix="${5:-}"
    make -C "$runner_dir" \
        PYTHON="$host_python_bin" \
        VMLINUX_BTF="$vmlinux_btf" \
        UPSTREAM_SELFTEST_OUTPUT_DIR="$output_dir" \
        UPSTREAM_SELFTEST_HOST_PYTHON_BIN="$host_python_bin" \
        UPSTREAM_SELFTEST_LLVM_SUFFIX="$llvm_suffix" \
        upstream-selftests-build >/dev/null
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
