#!/usr/bin/env bash
set -euo pipefail

SUDO=""
if [[ "${EUID}" -ne 0 ]]; then
  if ! sudo -n true >/dev/null 2>&1; then
    echo "passwordless sudo is required for Tracee setup" >&2
    exit 1
  fi
  SUDO="sudo -n"
fi

tracee_bin=""
if command -v tracee >/dev/null 2>&1; then
  tracee_bin="$(command -v tracee)"
elif command -v tracee-ebpf >/dev/null 2>&1; then
  tracee_bin="$(command -v tracee-ebpf)"
elif [[ -x /tmp/tracee-bin/tracee ]]; then
  tracee_bin="/tmp/tracee-bin/tracee"
fi

apt_install() {
  if ! command -v apt-get >/dev/null 2>&1; then
    return 1
  fi
  DEBIAN_FRONTEND=noninteractive ${SUDO} apt-get update -y >/dev/null 2>&1 || true
  DEBIAN_FRONTEND=noninteractive ${SUDO} apt-get install -y "$@"
}

missing_pkgs=()
for tool in stress-ng fio curl; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    missing_pkgs+=("${tool}")
  fi
done
if ! command -v wrk >/dev/null 2>&1; then
  missing_pkgs+=("wrk")
fi
if ! command -v hackbench >/dev/null 2>&1; then
  missing_pkgs+=("rt-tests")
fi
if [[ "${#missing_pkgs[@]}" -gt 0 ]]; then
  for pkg in "${missing_pkgs[@]}"; do
    apt_install "${pkg}" >/dev/null 2>&1 || true
  done
fi

if [[ -z "${tracee_bin}" ]]; then
  apt_candidate=""
  if command -v apt-cache >/dev/null 2>&1; then
    apt_candidate="$(apt-cache policy tracee 2>/dev/null | awk '/Candidate:/ {print $2; exit}')"
  fi
  if [[ -n "${apt_candidate}" && "${apt_candidate}" != "(none)" ]]; then
    apt_install tracee >/dev/null 2>&1 || true
    if command -v tracee >/dev/null 2>&1; then
      tracee_bin="$(command -v tracee)"
    fi
  fi
fi

if [[ -z "${tracee_bin}" ]]; then
  release_url="$(
    python3 - <<'PY'
import json
import platform
import urllib.request

arch = platform.machine()
if arch in ("x86_64", "amd64"):
    suffix = "x86_64"
elif arch in ("aarch64", "arm64"):
    suffix = "aarch64"
else:
    print("")
    raise SystemExit(0)

payload = json.load(urllib.request.urlopen("https://api.github.com/repos/aquasecurity/tracee/releases/latest"))
for asset in payload.get("assets", []):
    name = asset.get("name", "")
    if name.startswith(f"tracee-{suffix}.") and name.endswith(".tar.gz"):
        print(asset.get("browser_download_url", ""))
        break
else:
    print("")
PY
  )"
  if [[ -n "${release_url}" ]] && command -v curl >/dev/null 2>&1; then
    archive="/tmp/tracee-release.tar.gz"
    extract_dir="/tmp/tracee-release"
    install_dir="/tmp/tracee-bin"
    rm -f "${archive}" /tmp/tracee
    rm -rf "${extract_dir}"
    rm -rf "${install_dir}"
    mkdir -p "${extract_dir}"
    mkdir -p "${install_dir}"
    curl -fsSL -o "${archive}" "${release_url}" || true
    if [[ -f "${archive}" ]]; then
      tar -xzf "${archive}" -C "${extract_dir}" ./dist/tracee >/dev/null 2>&1 || true
      if [[ -x "${extract_dir}/dist/tracee" ]]; then
        cp "${extract_dir}/dist/tracee" "${install_dir}/tracee"
        chmod +x "${install_dir}/tracee"
        tracee_bin="${install_dir}/tracee"
      fi
    fi
  fi
fi

if [[ -n "${tracee_bin}" ]]; then
  if ! "${tracee_bin}" --version >/dev/null 2>&1; then
    "${tracee_bin}" version >/dev/null 2>&1 || true
  fi
fi

echo "TRACEE_BINARY=${tracee_bin}"
if [[ -n "${tracee_bin}" ]]; then
  "${tracee_bin}" --version 2>/dev/null || "${tracee_bin}" version 2>/dev/null || true
  exit 0
fi

echo "Tracee was not installed. apt candidate may be unavailable and GitHub download may have failed." >&2
exit 1
