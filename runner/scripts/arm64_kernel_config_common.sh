#!/bin/bash

arm64_apply_repo_required_config() {
    local worktree="$1"
    local config_path="$2"

    "$worktree/scripts/config" --file "$config_path" \
        -e BPF -e BPF_SYSCALL -e BPF_JIT -e BPF_LSM \
        -e SCHED_CLASS_EXT \
        -e TRACEPOINTS -e EVENT_TRACING -e TRACING \
        -e FTRACE -e FUNCTION_TRACER \
        -e DYNAMIC_FTRACE -e DYNAMIC_FTRACE_WITH_REGS \
        -e DYNAMIC_FTRACE_WITH_DIRECT_CALLS -e DYNAMIC_FTRACE_WITH_ARGS \
        -e FTRACE_SYSCALLS \
        -e KPROBES -e KPROBES_ON_FTRACE -e KPROBE_EVENTS \
        -e UPROBE_EVENTS -e BPF_EVENTS -e TRACING_MAP \
        -e DEBUG_INFO -d DEBUG_INFO_REDUCED -d DEBUG_INFO_SPLIT \
        -e DEBUG_INFO_BTF -e DEBUG_INFO_BTF_MODULES \
        -e IPV6 -e MPTCP -e MPTCP_IPV6 \
        -e NET_SCH_FQ -e NET_SCH_BPF -m NET_CLS_BPF -m NET_ACT_BPF \
        -e NF_CONNTRACK_MARK
}

arm64_finalize_kernel_config() {
    local worktree="$1"
    local build_dir="$2"
    local cross_compile="${3:-aarch64-linux-gnu-}"

    set +o pipefail
    yes "" | make -C "$worktree" O="$build_dir" ARCH=arm64 CROSS_COMPILE="$cross_compile" olddefconfig
    set -o pipefail
}
