#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
CACHED_BINARY="${REPO_ROOT}/e2e/cases/tracee/bin/tracee"
PATCHED_SOURCE_TAG="v0.24.1"
PATCHED_VERSION="v0.24.1-kernel7-patch1"
ALLOW_PATCHED_BUILD="${TRACEE_ALLOW_PATCHED_BUILD:-0}"

tracee_version() {
  local bin="$1"
  local output=""
  if [[ ! -x "${bin}" ]]; then
    return 1
  fi
  output="$("${bin}" --version 2>/dev/null || "${bin}" version 2>/dev/null || true)"
  awk '
    match($0, /(v[0-9][^[:space:]]*)/, match_value) {
      print match_value[1]
      exit
    }
  ' <<<"${output}"
}

cache_tracee_binary() {
  local source_bin="$1"
  local tmp_binary="/tmp/tracee-bin/tracee"
  mkdir -p "$(dirname "${CACHED_BINARY}")"
  mkdir -p /tmp/tracee-bin
  if [[ "$(readlink -f "${source_bin}")" != "$(readlink -f "${CACHED_BINARY}")" ]]; then
    cp "${source_bin}" "${CACHED_BINARY}"
  fi
  if [[ "$(readlink -f "${source_bin}")" != "$(readlink -f "${tmp_binary}")" ]]; then
    cp "${source_bin}" "${tmp_binary}"
  fi
  chmod +x "${CACHED_BINARY}" "${tmp_binary}"
}

build_patched_tracee_binary() {
  local build_root=""
  local build_log=""
  local jobs="1"

  for tool in git make clang go pkg-config; do
    if ! command -v "${tool}" >/dev/null 2>&1; then
      return 1
    fi
  done

  if command -v nproc >/dev/null 2>&1; then
    jobs="$(nproc)"
  fi

  build_root=$(mktemp -d /tmp/tracee-src-XXXXXX)
  build_log="${build_root}/build.log"
  if ! git clone --branch "${PATCHED_SOURCE_TAG}" --depth=1 https://github.com/aquasecurity/tracee.git "${build_root}" >/dev/null 2>&1; then
    return 1
  fi

  perl -0pi -e '
    s@statfunc struct in6_addr get_sock_v6_rcv_saddr\(struct sock \*sock\)\n\{\n    return BPF_CORE_READ\(sock, sk_v6_rcv_saddr\);\n\}@statfunc struct in6_addr get_sock_v6_rcv_saddr(struct sock *sock)\n{\n    struct in6_addr addr = {};\n\n    if (bpf_core_field_exists(sock->sk_v6_rcv_saddr)) {\n        addr = BPF_CORE_READ(sock, sk_v6_rcv_saddr);\n    }\n\n    return addr;\n}@;
    s@statfunc struct in6_addr get_ipv6_pinfo_saddr\(struct ipv6_pinfo \*np\)\n\{\n    return BPF_CORE_READ\(np, saddr\);\n\}@statfunc struct in6_addr get_ipv6_pinfo_saddr(struct ipv6_pinfo *np)\n{\n    struct in6_addr addr = {};\n\n    if (np != NULL && bpf_core_field_exists(np->saddr)) {\n        addr = BPF_CORE_READ(np, saddr);\n    }\n\n    return addr;\n}@;
    s@statfunc struct in6_addr get_sock_v6_daddr\(struct sock \*sock\)\n\{\n    return BPF_CORE_READ\(sock, sk_v6_daddr\);\n\}@statfunc struct in6_addr get_sock_v6_daddr(struct sock *sock)\n{\n    struct in6_addr addr = {};\n\n    if (bpf_core_field_exists(sock->sk_v6_daddr)) {\n        addr = BPF_CORE_READ(sock, sk_v6_daddr);\n    }\n\n    return addr;\n}@;
    s@statfunc struct ipv6_pinfo \*get_inet_pinet6\(struct inet_sock \*inet\)\n\{\n    struct ipv6_pinfo \*pinet6_own_impl;\n    bpf_core_read\(&pinet6_own_impl, sizeof\(struct ipv6_pinfo \*\), &inet->pinet6\);\n    return pinet6_own_impl;\n\}@statfunc struct ipv6_pinfo *get_inet_pinet6(struct inet_sock *inet)\n{\n    struct ipv6_pinfo *pinet6_own_impl = NULL;\n\n    if (bpf_core_field_exists(inet->pinet6)) {\n        bpf_core_read(&pinet6_own_impl, sizeof(struct ipv6_pinfo *), &inet->pinet6);\n    }\n\n    return pinet6_own_impl;\n}@;
  ' "${build_root}/pkg/ebpf/c/common/network.h"

  if ! make -C "${build_root}" -j"${jobs}" tracee RELEASE_VERSION="${PATCHED_VERSION}" >"${build_log}" 2>&1; then
    tail -n 60 "${build_log}" >&2 || true
    return 1
  fi

  cache_tracee_binary "${build_root}/dist/tracee"
  printf '%s\n' "${CACHED_BINARY}"
}

allow_patched_build() {
  [[ "${ALLOW_PATCHED_BUILD}" == "1" ]]
}

select_tracee_binary() {
  local candidate="${1:-}"
  local version=""
  local patched_version=""
  local patched_binary=""

  if [[ -n "${candidate}" ]] && [[ ! -x "${candidate}" ]]; then
    candidate=""
  fi

  if [[ -n "${candidate}" ]]; then
    version="$(tracee_version "${candidate}")"
    if [[ "${version}" != "${PATCHED_VERSION}" ]]; then
      printf '%s\n' "${candidate}"
      return 0
    fi
  fi

  if ! allow_patched_build; then
    return 0
  fi

  if [[ -x "${CACHED_BINARY}" ]]; then
    patched_version="$(tracee_version "${CACHED_BINARY}")"
    if [[ "${patched_version}" == "${PATCHED_VERSION}" ]]; then
      printf '%s\n' "${CACHED_BINARY}"
      return 0
    fi
  fi

  patched_binary="$(build_patched_tracee_binary || true)"
  if [[ -n "${patched_binary}" ]]; then
    printf '%s\n' "${patched_binary}"
    return 0
  fi

  if [[ -n "${candidate}" ]]; then
    printf '%s\n' "${candidate}"
  fi
}

tracee_bin=""
if command -v tracee >/dev/null 2>&1; then
  tracee_bin="$(command -v tracee)"
elif command -v tracee-ebpf >/dev/null 2>&1; then
  tracee_bin="$(command -v tracee-ebpf)"
elif [[ -x "${CACHED_BINARY}" ]]; then
  tracee_bin="${CACHED_BINARY}"
elif [[ -x /tmp/tracee-bin/tracee ]]; then
  tracee_bin="/tmp/tracee-bin/tracee"
fi

apt_install() {
  if ! command -v apt-get >/dev/null 2>&1; then
    return 1
  fi
  DEBIAN_FRONTEND=noninteractive apt-get update -y >/dev/null 2>&1 || true
  DEBIAN_FRONTEND=noninteractive apt-get install -y "$@"
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

tracee_bin="$(select_tracee_binary "${tracee_bin}" || true)"

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

tracee_bin="$(select_tracee_binary "${tracee_bin}" || true)"

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
        cache_tracee_binary "${install_dir}/tracee"
      fi
    fi
  fi
fi

tracee_bin="$(select_tracee_binary "${tracee_bin}" || true)"

if [[ -n "${tracee_bin}" ]]; then
  if ! "${tracee_bin}" --version >/dev/null 2>&1; then
    "${tracee_bin}" version >/dev/null 2>&1 || true
  fi
  cache_tracee_binary "${tracee_bin}" 2>/dev/null || true
fi

echo "TRACEE_BINARY=${tracee_bin}"
if [[ -n "${tracee_bin}" ]]; then
  "${tracee_bin}" --version 2>/dev/null || "${tracee_bin}" version 2>/dev/null || true
  exit 0
fi

echo "Tracee was not installed. apt candidate may be unavailable and GitHub download may have failed." >&2
exit 1
