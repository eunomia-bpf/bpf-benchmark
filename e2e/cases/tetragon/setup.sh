#!/usr/bin/env bash
set -euo pipefail

SUDO=""
if [[ "${EUID}" -ne 0 ]]; then
  if sudo -n true >/dev/null 2>&1; then
    SUDO="sudo -n"
  else
    echo "passwordless sudo is required for tetragon setup" >&2
    exit 1
  fi
fi

apt_install() {
  if ! command -v apt-get >/dev/null 2>&1; then
    return 1
  fi
  DEBIAN_FRONTEND=noninteractive ${SUDO} apt-get update -y >/dev/null 2>&1 || true
  DEBIAN_FRONTEND=noninteractive ${SUDO} apt-get install -y "$@"
}

find_binary() {
  local name="$1"
  shift
  if command -v "${name}" >/dev/null 2>&1; then
    command -v "${name}"
    return 0
  fi
  local candidate
  for candidate in "$@"; do
    if [[ -x "${candidate}" ]]; then
      printf '%s\n' "${candidate}"
      return 0
    fi
  done
  return 1
}

missing_pkgs=()
for tool in stress-ng fio curl tar; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    missing_pkgs+=("${tool}")
  fi
done
if [[ "${#missing_pkgs[@]}" -gt 0 ]]; then
  apt_install "${missing_pkgs[@]}" >/dev/null 2>&1 || true
fi

if ! command -v stress-ng >/dev/null 2>&1; then
  echo "stress-ng is required for the tetragon benchmark" >&2
  exit 1
fi

install_dir="/tmp/tetragon-e2e"
tetragon_bin="$(find_binary tetragon \
  /usr/local/bin/tetragon \
  /tmp/tetragon/tetragon \
  ${install_dir}/tetragon || true)"
tetra_bin="$(find_binary tetra \
  /usr/local/bin/tetra \
  /tmp/tetragon/tetra \
  ${install_dir}/tetra || true)"

if [[ -z "${tetragon_bin}" ]] && command -v curl >/dev/null 2>&1; then
  rm -rf "${install_dir}"
  mkdir -p "${install_dir}"
  # Determine the latest release tag for the correct archive name
  latest_tag="$(curl -sfL -o /dev/null -w '%{url_effective}' https://github.com/cilium/tetragon/releases/latest | grep -oP 'tag/\K.*')"
  latest_tag="${latest_tag:-v1.6.0}"
  archive_name="tetragon-${latest_tag}-amd64.tar.gz"
  archive_path="${install_dir}/${archive_name}"
  if curl --retry 3 --retry-delay 1 --retry-connrefused -sfL \
    -o "${archive_path}" \
    "https://github.com/cilium/tetragon/releases/download/${latest_tag}/${archive_name}" &&
    tar -xzf "${archive_path}" -C "${install_dir}"; then
    found_tetragon="$(find "${install_dir}" -maxdepth 2 -type f -name tetragon -perm -u+x | head -n1 || true)"
    found_tetra="$(find "${install_dir}" -maxdepth 2 -type f -name tetra -perm -u+x | head -n1 || true)"
    if [[ -n "${found_tetragon}" ]]; then
      tetragon_bin="${found_tetragon}"
    fi
    if [[ -n "${found_tetra}" ]]; then
      tetra_bin="${found_tetra}"
    fi
  fi
fi

echo "TETRAGON_BINARY=${tetragon_bin}"
echo "TETRA_BINARY=${tetra_bin}"
echo "STRESS_NG_BINARY=$(command -v stress-ng || true)"

if [[ -n "${tetragon_bin}" ]]; then
  "${tetragon_bin}" version >/dev/null 2>&1 || "${tetragon_bin}" --version >/dev/null 2>&1 || true
fi
