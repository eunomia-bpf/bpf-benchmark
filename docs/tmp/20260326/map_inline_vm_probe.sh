#!/usr/bin/env bash
set -euo pipefail

REPO_ROOT="/home/yunwei37/workspace/bpf-benchmark"
OUT_DIR="$REPO_ROOT/docs/tmp/20260326/probe_outputs"
DAEMON="$REPO_ROOT/daemon/target/release/bpfrejit-daemon"

mkdir -p "$OUT_DIR"

load_and_apply() {
    local label="$1"
    local obj="$2"
    local prog_type="$3"
    local map_name="$4"
    local map_update_value="$5"

    local pin_root="/sys/fs/bpf/${label}"
    local prog_pin
    local prog_id

    rm -rf "$pin_root"
    mkdir -p "$pin_root/progs" "$pin_root/maps"

    bpftool prog loadall "$obj" "$pin_root/progs" type "$prog_type" pinmaps "$pin_root/maps"

    if [[ -n "$map_name" ]]; then
        bpftool map update pinned "$pin_root/maps/$map_name" key hex 00 00 00 00 value hex $map_update_value
        bpftool map lookup pinned "$pin_root/maps/$map_name" key hex 00 00 00 00 \
            >"$OUT_DIR/${label}.map_lookup.txt"
    fi

    prog_pin="$(find "$pin_root/progs" -maxdepth 1 -type f | sort | head -n 1)"
    if [[ -z "$prog_pin" ]]; then
        echo "no pinned program found under $pin_root/progs" >&2
        exit 1
    fi

    prog_id="$(bpftool prog show pinned "$prog_pin" | awk -F: 'NR==1 { gsub(/^[[:space:]]+/, "", $1); print $1 }')"
    if [[ -z "$prog_id" ]]; then
        echo "failed to resolve prog_id for $prog_pin" >&2
        exit 1
    fi

    {
        echo "label=$label"
        echo "object=$obj"
        echo "prog_pin=$prog_pin"
        echo "prog_id=$prog_id"
    } >"$OUT_DIR/${label}.meta.txt"

    "$DAEMON" apply "$prog_id" >"$OUT_DIR/${label}.stdout" 2>"$OUT_DIR/${label}.stderr"

    bpftool prog show pinned "$prog_pin" >"$OUT_DIR/${label}.prog_show.txt"

    rm -rf "$pin_root"
}

load_and_apply_all() {
    local label="$1"
    local obj="$2"
    local prog_type="$3"
    local map_name="$4"
    local map_update_value="$5"

    local pin_root="/sys/fs/bpf/${label}"
    local prog_pin
    local prog_id
    local prog_name

    rm -rf "$pin_root"
    mkdir -p "$pin_root/progs" "$pin_root/maps"

    bpftool prog loadall "$obj" "$pin_root/progs" type "$prog_type" pinmaps "$pin_root/maps"

    if [[ -n "$map_name" ]]; then
        bpftool map update pinned "$pin_root/maps/$map_name" key hex 00 00 00 00 value hex $map_update_value
        bpftool map lookup pinned "$pin_root/maps/$map_name" key hex 00 00 00 00 \
            >"$OUT_DIR/${label}.map_lookup.txt"
    fi

    find "$pin_root/progs" -maxdepth 1 -type f | sort | while read -r prog_pin; do
        prog_name="$(basename "$prog_pin")"
        prog_id="$(bpftool prog show pinned "$prog_pin" | awk -F: 'NR==1 { gsub(/^[[:space:]]+/, "", $1); print $1 }')"
        if [[ -z "$prog_id" ]]; then
            echo "failed to resolve prog_id for $prog_pin" >&2
            exit 1
        fi

        {
            echo "label=$label"
            echo "object=$obj"
            echo "prog_pin=$prog_pin"
            echo "prog_name=$prog_name"
            echo "prog_id=$prog_id"
        } >"$OUT_DIR/${label}.${prog_name}.meta.txt"

        "$DAEMON" apply "$prog_id" \
            >"$OUT_DIR/${label}.${prog_name}.stdout" \
            2>"$OUT_DIR/${label}.${prog_name}.stderr"

        bpftool prog show pinned "$prog_pin" >"$OUT_DIR/${label}.${prog_name}.prog_show.txt"
    done

    rm -rf "$pin_root"
}

load_and_apply \
    "pktcntr_zero" \
    "$REPO_ROOT/corpus/build/katran/xdp_pktcntr.bpf.o" \
    "xdp" \
    "" \
    ""

load_and_apply \
    "pktcntr_one" \
    "$REPO_ROOT/corpus/build/katran/xdp_pktcntr.bpf.o" \
    "xdp" \
    "ctl_array" \
    "01 00 00 00"

load_and_apply_all \
    "redirect_cpumap_four" \
    "$REPO_ROOT/corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o" \
    "xdp" \
    "cpus_count" \
    "04 00 00 00"
