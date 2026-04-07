#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
OUTPUT_ROOT="${1:?usage: build-x86-portable-libbpf.sh <output_root>}"

die() {
    printf '[build-x86-portable-libbpf][ERROR] %s\n' "$*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "required command is missing: $1"
}

require_cmd docker
mkdir -p "$OUTPUT_ROOT/lib"
rm -rf "$OUTPUT_ROOT/lib"
mkdir -p "$OUTPUT_ROOT/lib"

docker run --rm \
    -v "$ROOT_DIR:/workspace:ro" \
    -v "$OUTPUT_ROOT:/out" \
    amazonlinux:2023 \
    bash -lc '
set -euo pipefail
dnf -y install gcc make elfutils-libelf-devel binutils >/dev/null 2>&1
rm -rf /tmp/libbpf-obj /tmp/libbpf-stage
make -C /workspace/vendor/libbpf/src -j"$(nproc)" \
    OBJDIR=/tmp/libbpf-obj \
    DESTDIR=/tmp/libbpf-stage \
    prefix= install >/dev/null
lib_dir=/tmp/libbpf-stage/usr/lib64
real_so="$(find "$lib_dir" -maxdepth 1 -type f -name "libbpf.so.*" | sort | tail -n1)"
test -n "$real_so"
cp -L "$real_so" /out/lib/
real_name="$(basename "$real_so")"
soname="$(readelf -d "$real_so" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"
if [[ -n "$soname" && "$soname" != "$real_name" ]]; then
    ln -sfn "$real_name" "/out/lib/$soname"
fi
'

find "$OUTPUT_ROOT/lib" -maxdepth 1 -type f -name 'libbpf.so.*' -print -quit 2>/dev/null | grep -q . \
    || die "portable x86 libbpf build did not produce libbpf.so.* under $OUTPUT_ROOT/lib"
file "$OUTPUT_ROOT/lib/"libbpf.so.* | grep -F "x86-64" >/dev/null \
    || die "portable x86 libbpf output is not x86_64"
