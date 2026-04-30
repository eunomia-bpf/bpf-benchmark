#!/usr/bin/env bash
set -euo pipefail

ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
WORKDIR=${WORKDIR:-/tmp/p88-branch-flip-pgo}
OUT=${WORKDIR}/programs
PROFILE=${WORKDIR}/profile.json
ORIG=${WORKDIR}/orig.bin
OPT=${WORKDIR}/opt.bin
VERIFIED=${WORKDIR}/verified.bin
REPORT=${WORKDIR}/branch-flip-report.json
VERIFY_REPORT=${WORKDIR}/verify-report.json
REJIT_REPORT=${WORKDIR}/rejit-report.json
BPFPROF=${BPFPROF:-${ROOT}/bpfopt/target/debug/bpfprof}
BPFOPT=${BPFOPT:-${ROOT}/bpfopt/target/debug/bpfopt}
BPFVERIFY=${BPFVERIFY:-${ROOT}/bpfopt/target/debug/bpfverify}
BPFREJIT=${BPFREJIT:-${ROOT}/bpfopt/target/debug/bpfrejit}
NETNS=${NETNS:-p88ns}
IFACE=${IFACE:-p88a}
PEER=${PEER:-p88b}
PIN=${PIN:-/sys/fs/bpf/p88_branch_flip_dense}

cleanup() {
  if [[ -n "${SCAPY_PID:-}" ]]; then
    sudo -n kill "${SCAPY_PID}" 2>/dev/null || true
  fi
  sudo -n ip link del "${IFACE}" 2>/dev/null || true
  sudo -n ip netns del "${NETNS}" 2>/dev/null || true
  sudo -n rm -f "${PIN}" 2>/dev/null || true
}
trap cleanup EXIT

require_cmd() {
  command -v "$1" >/dev/null || {
    echo "missing required command: $1" >&2
    exit 1
  }
}

require_cmd bpftool
require_cmd gcc
require_cmd jq
require_cmd llvm-objcopy
require_cmd make
require_cmd python3
require_cmd sudo

sudo -n true

cd "${ROOT}"
cargo build --manifest-path bpfopt/Cargo.toml -p bpfprof -p bpfopt -p bpfverify -p bpfrejit

rm -rf "${WORKDIR}"
mkdir -p "${OUT}"

MULTIARCH=$(gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null || true)
SYS_INCLUDE_FLAGS=
if [[ -n "${MULTIARCH}" ]]; then
  SYS_INCLUDE_FLAGS="-I/usr/include/${MULTIARCH}"
fi

make -C micro/programs \
  OUTPUT_DIR="${OUT}" \
  CFLAGS="-Wall -Wextra -O2 -g -target bpf ${SYS_INCLUDE_FLAGS} -MMD -MP -DBRANCH_FLIP_DENSE_GROUPS=1U -DBRANCH_FLIP_DENSE_LANES=4U" \
  "${OUT}/branch_flip_dense.bpf.o"

cleanup
sudo -n ip netns add "${NETNS}"
sudo -n ip link add "${IFACE}" type veth peer name "${PEER}"
sudo -n ip link set "${PEER}" netns "${NETNS}"
sudo -n ip link set "${IFACE}" mtu 9000
sudo -n ip netns exec "${NETNS}" ip link set "${PEER}" mtu 9000
sudo -n ip addr add 10.88.0.1/24 dev "${IFACE}"
sudo -n ip link set "${IFACE}" up
sudo -n ip netns exec "${NETNS}" ip addr add 10.88.0.2/24 dev "${PEER}"
sudo -n ip netns exec "${NETNS}" ip link set "${PEER}" up
sudo -n ip netns exec "${NETNS}" ip link set lo up
sudo -n ip link set dev "${IFACE}" xdpgeneric obj "${OUT}/branch_flip_dense.bpf.o" sec xdp

PROG_ID=$(sudo -n bpftool -j prog show | jq -r '.[] | select(.name=="branch_flip_dense_xdp") | .id' | tail -n 1)
if [[ -z "${PROG_ID}" ]]; then
  echo "failed to find live branch_flip_dense_xdp program" >&2
  exit 1
fi

P88A_MAC=$(cat "/sys/class/net/${IFACE}/address")
sudo -n ip netns exec "${NETNS}" python3 - "${P88A_MAC}" <<'PY' >"${WORKDIR}/scapy.log" 2>&1 &
import sys
import time
from scapy.all import Ether, Raw, sendp

p88a_mac = sys.argv[1]
frame = Ether(dst=p88a_mac, src="00:00:00:00:00:00", type=0) / Raw(bytes(256))
deadline = time.monotonic() + 7.0
while time.monotonic() < deadline:
    sendp(frame, iface="p88b", count=1000, inter=0, verbose=False)
PY
SCAPY_PID=$!
sleep 0.2

sudo -n "${BPFPROF}" --prog-id "${PROG_ID}" --per-site --duration 5000ms --output "${PROFILE}"
sudo -n kill "${SCAPY_PID}" 2>/dev/null || true
wait "${SCAPY_PID}" 2>/dev/null || true
unset SCAPY_PID

jq -e '.branch_miss_rate < 0.05 and (.per_site | has("13") and has("33") and has("50") and has("67"))' "${PROFILE}" >/dev/null

llvm-objcopy --dump-section xdp="${ORIG}" "${OUT}/branch_flip_dense.bpf.o"
"${BPFOPT}" branch-flip \
  --input "${ORIG}" \
  --output "${OPT}" \
  --profile "${PROFILE}" \
  --prog-type xdp \
  --report "${REPORT}"
jq -e '.changed == true and .sites_applied == 4' "${REPORT}" >/dev/null

cat >"${WORKDIR}/missing-site-profile.json" <<'JSON'
{
  "branch_miss_rate": 0.0,
  "per_site": {}
}
JSON
if "${BPFOPT}" branch-flip \
  --input "${ORIG}" \
  --output "${WORKDIR}/missing-out.bin" \
  --profile "${WORKDIR}/missing-site-profile.json" \
  --prog-type xdp >"${WORKDIR}/missing-profile.stdout" 2>"${WORKDIR}/missing-profile.stderr"; then
  echo "branch_flip unexpectedly accepted missing per-site profile data" >&2
  exit 1
fi
grep -q "no real per-site profile data" "${WORKDIR}/missing-profile.stderr"

if sudo -n "${BPFPROF}" --prog-id "${PROG_ID}" --duration 10ms --output "${WORKDIR}/no-pmu.json" >"${WORKDIR}/no-pmu.stdout" 2>"${WORKDIR}/no-pmu.stderr"; then
  echo "bpfprof unexpectedly accepted profile mode without --per-site" >&2
  exit 1
fi
grep -q "requires --per-site" "${WORKDIR}/no-pmu.stderr"

sudo -n "${BPFVERIFY}" \
  --prog-type xdp \
  --input "${OPT}" \
  --output "${VERIFIED}" \
  --report "${VERIFY_REPORT}"
jq -e '.status == "pass"' "${VERIFY_REPORT}" >/dev/null

if ! sudo -n "${BPFREJIT}" "${PROG_ID}" "${VERIFIED}" --output "${REJIT_REPORT}" 2>"${WORKDIR}/rejit.stderr"; then
  cat "${WORKDIR}/rejit.stderr" >&2
  if ! grep -Rqs "BPF_PROG_REJIT" /usr/include/linux/bpf.h "/usr/src/linux-headers-$(uname -r)/include/uapi/linux/bpf.h"; then
    echo "host kernel UAPI does not expose fork BPF_PROG_REJIT; bpfrejit cannot complete on this host" >&2
  fi
  exit 1
fi
jq -e '.status == "ok" and .prog_id == '"${PROG_ID}" "${REJIT_REPORT}" >/dev/null
