from __future__ import annotations

import os
import socket
import struct
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Any, Mapping

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from ..kernel_modules import load_kernel_module
from ..workload import WorkloadResult
from .base import AppRunner
from .process_support import ManagedProcessSession
from .setup_support import repo_artifact_root

DEFAULT_KATRAN_PROGRAM_NAME = "balancer_ingress"
DEFAULT_KATRAN_TEST_PACKET = ROOT_DIR / "corpus" / "inputs" / "katran_vip_packet_64.bin"
DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S = 30
DEFAULT_KATRAN_STOP_TIMEOUT_S = 10.0
DEFAULT_KATRAN_STOP_SETTLE_S = 2.0
KATRAN_REQUIRED_MAP_NAMES = ("vip_map", "reals", "ch_rings", "ctl_array")
BPF_OBJECT_NAME_LIMIT = 15
DEFAULT_IP_CANDIDATES = (
    "/usr/local/sbin/ip",
    "/usr/local/bin/ip",
    "/usr/sbin/ip",
    "/usr/bin/ip",
    "/sbin/ip",
    "/bin/ip",
)
REQUEST_FAILURE_PREVIEW_LIMIT = 5
TCP_PROTO = socket.IPPROTO_TCP
XDP_PASS = 2
XDP_TX = 3
F_LRU_BYPASS = 1 << 1
CH_RING_SIZE = 65537
VIP_NUM = 0
REAL_NUM = 1

ROUTER_NS = "katran-router"
CLIENT_NS = "katran-client"
REAL_NS = "katran-real"
ROUTER_LB_IFACE = "rtlb0"
ROUTER_CLIENT_IFACE = "rtcl0"
CLIENT_IFACE = "client0"
ROUTER_REAL_IFACE = "rtreal0"
REAL_IFACE = "real0"

LB_IP = "192.0.2.2"
ROUTER_LB_IP = "192.0.2.1"
CLIENT_IP = "10.0.0.2"
ROUTER_CLIENT_IP = "10.0.0.1"
REAL_IP = "10.200.0.2"
ROUTER_REAL_IP = "10.200.0.1"
VIP_IP = "10.100.1.1"
VIP_PORT = 8080
IPIP_DUMMY_IP = "127.0.0.42"

LB_MAC = "02:00:00:00:00:0a"
ROUTER_LB_MAC = "02:00:00:00:00:0b"
ROUTER_CLIENT_MAC = "02:00:00:00:00:1b"
CLIENT_MAC = "02:00:00:00:00:1c"
ROUTER_REAL_MAC = "02:00:00:00:00:2b"
REAL_MAC = "02:00:00:00:00:2c"

HTTP_TIMEOUT_S = 5.0
SERVER_START_TIMEOUT_S = 15.0
TOPOLOGY_SETTLE_S = 2.0


def default_katran_balancer_prog_path() -> Path:
    return repo_artifact_root() / "katran" / "bpf" / "balancer.bpf.o"


def default_katran_server_binary_path() -> Path:
    return repo_artifact_root() / "katran" / "bin" / "katran_server_grpc"


def _map_show_records() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "map", "show"], timeout=30)
    if not isinstance(payload, list): raise RuntimeError("bpftool map show returned unexpected payload")
    return [dict(record) for record in payload if isinstance(record, dict)]


def _net_show_records(iface: str) -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "net", "show", "dev", str(iface)], timeout=30)
    if not isinstance(payload, list): raise RuntimeError(f"bpftool net show returned unexpected payload for {iface}")
    return [dict(record) for record in payload if isinstance(record, dict)]


def _program_name_variants(name: str) -> set[str]:
    normalized = str(name or "").strip()
    return set() if not normalized else {normalized, normalized[:BPF_OBJECT_NAME_LIMIT]}


def _attached_xdp_info(iface: str) -> dict[str, object]:
    return next((dict(r) for r in _net_show_records(iface) if r.get("xdp") or r.get("xdp_attached")), {})


def _attached_xdp_mode(attach_info: Mapping[str, object] | None) -> str | None:
    if not isinstance(attach_info, Mapping): return None
    if isinstance(xdp_records := attach_info.get("xdp"), list):
        for entry in xdp_records:
            if isinstance(entry, Mapping) and (mode := str(entry.get("mode") or "").strip().lower()): return mode
    mode = str(attach_info.get("attach_mode") or "").strip().lower()
    return mode or None


def _bpftool_attach_token(mode: str) -> str:
    normalized = str(mode or "").strip().lower()
    token = {"driver": "xdp", "native": "xdp", "generic": "xdpgeneric", "skb": "xdpgeneric", "offload": "xdpoffload"}.get(normalized)
    if token is None: raise RuntimeError(f"unsupported XDP attach mode for bpftool transition: {mode!r}")
    return token


def reattach_xdp_program(iface: str, prog_id: int, *, target_mode: str) -> dict[str, object]:
    prog_id = int(prog_id)
    if prog_id <= 0: raise RuntimeError(f"invalid prog_id for XDP reattach: {prog_id}")
    current_attach = _attached_xdp_info(iface); current_mode = _attached_xdp_mode(current_attach)
    target_token = _bpftool_attach_token(target_mode)
    if current_mode == str(target_mode).strip().lower(): return current_attach
    if current_mode is not None:
        run_command([resolve_bpftool_binary(), "net", "detach", _bpftool_attach_token(current_mode), "dev", str(iface)], check=False, timeout=15)
    run_command([resolve_bpftool_binary(), "net", "attach", target_token, "id", str(prog_id), "dev", str(iface), "overwrite"], timeout=30)
    attach_info = _attached_xdp_info(iface)
    if (attached_mode := _attached_xdp_mode(attach_info)) != str(target_mode).strip().lower():
        raise RuntimeError(f"expected XDP attach mode {target_mode!r} on {iface}, got {attached_mode!r}: {attach_info}")
    return attach_info


def _current_prog_ids() -> set[int]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list): raise RuntimeError("bpftool prog show returned unexpected payload")
    return {int(r["id"]) for r in payload if isinstance(r, dict) and "id" in r}


def _namespace_exists(namespace: str) -> bool:
    return any(Path(root).joinpath(namespace).exists() for root in ("/run/netns", "/var/run/netns"))


def wait_for_katran_teardown(
    prog_id: int | None,
    *,
    timeout_s: float = DEFAULT_KATRAN_STOP_TIMEOUT_S,
    settle_s: float = DEFAULT_KATRAN_STOP_SETTLE_S,
) -> None:
    deadline = time.monotonic() + max(0.1, float(timeout_s))
    settle = max(0.0, float(settle_s))
    _ns_triple = (ROUTER_NS, CLIENT_NS, REAL_NS)
    while time.monotonic() < deadline:
        if (prog_id in (None, 0) or int(prog_id) not in _current_prog_ids()) and \
                all(not _namespace_exists(ns) for ns in _ns_triple):
            if settle > 0.0:
                time.sleep(settle)
            return
        time.sleep(0.1)
    remaining = ([f"prog_id={int(prog_id)}"] if prog_id not in (None, 0) and int(prog_id) in _current_prog_ids() else [])
    remaining.extend(ns for ns in _ns_triple if _namespace_exists(ns))
    raise RuntimeError("Katran teardown did not quiesce before the next app start: "
                       + (", ".join(remaining) if remaining else "transient kernel/procfs state remained"))


def resolve_katran_server_binary(explicit: Path | str | None = None) -> Path:
    candidate = Path(explicit).expanduser().resolve() if (explicit is not None and str(explicit).strip()) else default_katran_server_binary_path().resolve()
    if candidate.is_file() and os.access(candidate, os.X_OK): return candidate
    raise RuntimeError(f"Katran server binary not found or not executable; tried: {candidate}")


def ip_binary() -> str:
    for candidate in DEFAULT_IP_CANDIDATES:
        path = Path(candidate)
        if path.is_file() and os.access(path, os.X_OK): return str(path)
    resolved = which("ip")
    if resolved: return resolved
    raise RuntimeError("ip is required for the katran runner")


def remote_python_binary() -> str:
    configured = os.environ.get("BPFREJIT_REMOTE_PYTHON_BIN", "").strip()
    if not configured: raise RuntimeError("BPFREJIT_REMOTE_PYTHON_BIN is required for the Katran runner")
    return configured


def _normalize_ip_command(command: list[str] | tuple[str, ...]) -> list[str]:
    args = [str(part) for part in command]
    return args[1:] if args and args[0] == "ip" else args


def ip_command(command: list[str] | tuple[str, ...], *, check: bool = True, timeout: int | float | None = 30) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), *_normalize_ip_command(command)], check=check, timeout=timeout)


def ns_exec_command(namespace: str, command: list[str] | tuple[str, ...], *, check: bool = True, timeout: int | float | None = 30) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), "netns", "exec", namespace, *[str(part) for part in command]], check=check, timeout=timeout)


def ns_ip_command(namespace: str, command: list[str] | tuple[str, ...], *, check: bool = True, timeout: int | float | None = 30) -> subprocess.CompletedProcess[str]:
    return ns_exec_command(namespace, [ip_binary(), *_normalize_ip_command(command)], check=check, timeout=timeout)


def link_exists(name: str) -> bool:
    return Path("/sys/class/net").joinpath(name).exists()


def module_loaded(name: str) -> bool:
    return Path("/sys/module").joinpath(name).exists()


def ensure_kernel_module_loaded(name: str) -> None:
    if module_loaded(name): return
    load_kernel_module(name, timeout=15)
    if module_loaded(name): return
    raise RuntimeError(f"kernel module {name} still is not resident after modprobe")


def set_ns_sysctl(namespace: str, key: str, value: int) -> None:
    ns_exec_command(namespace, ["sh", "-c", f"printf '%s' '{int(value)}' > /proc/sys/{key.replace('.', '/')}"], timeout=15)


def set_link_mac(namespace: str | None, iface: str, mac: str) -> None:
    cmd = ["link", "set", "dev", iface, "address", mac]
    (ip_command if namespace is None else lambda c, **kw: ns_ip_command(namespace, c, **kw))(cmd, timeout=15)


def pack_u32(value: int) -> bytes: return struct.pack("=I", int(value))
def pack_mac(mac: str) -> bytes: return bytes(int(p, 16) for p in mac.split(":"))
def pack_ctl_mac(mac: str) -> bytes: return pack_mac(mac) + b"\x00\x00"
def pack_vip_definition(address: str, port: int, proto: int) -> bytes: return socket.inet_aton(address) + (b"\x00" * 12) + struct.pack("!HBB", int(port), int(proto), 0)
def pack_vip_meta(flags: int, vip_num: int) -> bytes: return struct.pack("=II", int(flags), int(vip_num))
def pack_real_definition(address: str, flags: int = 0) -> bytes: return socket.inet_aton(address) + (b"\x00" * 12) + bytes([int(flags) & 0xFF]) + (b"\x00" * 3)
def xdp_action_name(retval: int) -> str: return {0: "XDP_ABORTED", 1: "XDP_DROP", XDP_PASS: "XDP_PASS", XDP_TX: "XDP_TX", 4: "XDP_REDIRECT"}.get(int(retval), f"UNKNOWN({int(retval)})")


def _bytes_to_hex_args(data: bytes) -> list[str]: return [f"{b:02x}" for b in data]


def _bpftool_map_update_args(map_id: int, key: bytes, value: bytes) -> list[str]:
    return ["map", "update", "id", str(map_id), "key", "hex", *_bytes_to_hex_args(key), "value", "hex", *_bytes_to_hex_args(value)]


def _bpftool_map_update_batch(updates: list[tuple[int, bytes, bytes]]) -> None:
    if not updates: return
    with tempfile.NamedTemporaryFile("w", prefix="katran_maps_", suffix=".bpftool", delete=False) as batch:
        for map_id, key, value in updates: batch.write(" ".join(_bpftool_map_update_args(map_id, key, value)) + "\n")
        batch_path = batch.name
    try:
        run_command([resolve_bpftool_binary(), "batch", "file", batch_path], timeout=max(60, (len(updates) // 500) + 30))
    finally:
        try: os.unlink(batch_path)
        except FileNotFoundError: pass


def _bpftool_prog_test_run(prog_id: int, packet: bytes, *, repeat: int = 1) -> dict[str, object]:
    with tempfile.NamedTemporaryFile(prefix="katran_in_", suffix=".bin", delete=False) as fin:
        fin.write(packet); in_path = fin.name
    out_path = in_path.replace("_in_", "_out_")
    try:
        result = run_json_command([resolve_bpftool_binary(), "-j", "prog", "run", "id", str(prog_id),
             "data_in", in_path, "data_out", out_path, "repeat", str(max(1, int(repeat)))], timeout=max(30, repeat // 100 + 30))
        if not isinstance(result, dict): raise RuntimeError(f"bpftool prog run returned unexpected payload: {result!r}")
        try: out_data = Path(out_path).read_bytes()
        except FileNotFoundError: out_data = b""
        return {"retval": int(result.get("retval", -1)), "duration_ns": int(result.get("duration", 0)),
                "repeat": max(1, int(repeat)), "data_size_in": len(packet),
                "data_size_out": len(out_data), "data_out_preview_hex": out_data[:32].hex()}
    finally:
        for path in (in_path, out_path):
            try: os.unlink(path)
            except FileNotFoundError: pass


class KatranDsrTopology:
    def __init__(self, iface: str, *, router_peer_iface: str | None = None) -> None:
        self.iface = iface
        self.router_peer_iface = router_peer_iface or None
        self.lb_ifindex = 0

    def __enter__(self) -> "KatranDsrTopology":
        self.cleanup()
        for mod in ("veth", "tunnel4", "ip_tunnel", "ipip"): ensure_kernel_module_loaded(mod)
        for ns in (ROUTER_NS, CLIENT_NS, REAL_NS): ip_command(["netns", "add", ns], timeout=15)
        if self.router_peer_iface is None:
            ip_command(["link", "add", self.iface, "type", "veth", "peer", "name", ROUTER_LB_IFACE], timeout=15)
            ip_command(["link", "set", ROUTER_LB_IFACE, "netns", ROUTER_NS], timeout=15)
        else:
            if self.router_peer_iface == self.iface: raise RuntimeError("router peer iface must differ from Katran ingress iface")
            if not link_exists(self.iface): raise RuntimeError(f"network interface does not exist: {self.iface}")
            if not link_exists(self.router_peer_iface): raise RuntimeError(f"router peer interface does not exist: {self.router_peer_iface}")
            ip_command(["link", "set", self.router_peer_iface, "netns", ROUTER_NS], timeout=15)
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", self.router_peer_iface, "name", ROUTER_LB_IFACE], timeout=15)
        _ipc = lambda *a: ip_command(list(a), timeout=15)
        _nsc = lambda ns, *a: ns_ip_command(ns, list(a), timeout=15)
        _ipc("link", "add", ROUTER_CLIENT_IFACE, "type", "veth", "peer", "name", CLIENT_IFACE)
        _ipc("link", "set", ROUTER_CLIENT_IFACE, "netns", ROUTER_NS)
        _ipc("link", "set", CLIENT_IFACE, "netns", CLIENT_NS)
        _ipc("link", "add", ROUTER_REAL_IFACE, "type", "veth", "peer", "name", REAL_IFACE)
        _ipc("link", "set", ROUTER_REAL_IFACE, "netns", ROUTER_NS)
        _ipc("link", "set", REAL_IFACE, "netns", REAL_NS)
        for ns_mac in ((None, self.iface, LB_MAC), (ROUTER_NS, ROUTER_LB_IFACE, ROUTER_LB_MAC),
                       (ROUTER_NS, ROUTER_CLIENT_IFACE, ROUTER_CLIENT_MAC), (CLIENT_NS, CLIENT_IFACE, CLIENT_MAC),
                       (ROUTER_NS, ROUTER_REAL_IFACE, ROUTER_REAL_MAC), (REAL_NS, REAL_IFACE, REAL_MAC)):
            set_link_mac(*ns_mac)
        for ns in (ROUTER_NS, CLIENT_NS, REAL_NS): _nsc(ns, "link", "set", "lo", "up")
        _ipc("addr", "replace", f"{LB_IP}/24", "dev", self.iface)
        _ipc("link", "set", "dev", self.iface, "up")
        _nsc(ROUTER_NS, "addr", "add", f"{ROUTER_LB_IP}/24", "dev", ROUTER_LB_IFACE)
        _nsc(ROUTER_NS, "addr", "add", f"{ROUTER_CLIENT_IP}/24", "dev", ROUTER_CLIENT_IFACE)
        _nsc(ROUTER_NS, "addr", "add", f"{ROUTER_REAL_IP}/24", "dev", ROUTER_REAL_IFACE)
        _nsc(ROUTER_NS, "link", "set", "dev", ROUTER_LB_IFACE, "up")
        _nsc(ROUTER_NS, "link", "set", "dev", ROUTER_CLIENT_IFACE, "up")
        _nsc(ROUTER_NS, "link", "set", "dev", ROUTER_REAL_IFACE, "up")
        _nsc(CLIENT_NS, "addr", "add", f"{CLIENT_IP}/24", "dev", CLIENT_IFACE)
        _nsc(CLIENT_NS, "link", "set", "dev", CLIENT_IFACE, "up")
        _nsc(REAL_NS, "addr", "add", f"{REAL_IP}/24", "dev", REAL_IFACE)
        _nsc(REAL_NS, "link", "set", "dev", REAL_IFACE, "up")
        _nsc(REAL_NS, "addr", "add", f"{VIP_IP}/32", "dev", "lo")
        _nsc(REAL_NS, "link", "add", "name", "ipip0", "type", "ipip", "external")
        _nsc(REAL_NS, "addr", "add", f"{IPIP_DUMMY_IP}/32", "dev", "ipip0")
        _nsc(REAL_NS, "link", "set", "dev", "ipip0", "up")
        _nsc(CLIENT_NS, "route", "add", "default", "via", ROUTER_CLIENT_IP, "dev", CLIENT_IFACE)
        _nsc(REAL_NS, "route", "add", "default", "via", ROUTER_REAL_IP, "dev", REAL_IFACE)
        _nsc(ROUTER_NS, "route", "add", f"{VIP_IP}/32", "via", LB_IP, "dev", ROUTER_LB_IFACE)
        _nsc(CLIENT_NS, "neigh", "replace", ROUTER_CLIENT_IP, "lladdr", ROUTER_CLIENT_MAC, "dev", CLIENT_IFACE, "nud", "permanent")
        _nsc(ROUTER_NS, "neigh", "replace", LB_IP, "lladdr", LB_MAC, "dev", ROUTER_LB_IFACE, "nud", "permanent")
        _nsc(ROUTER_NS, "neigh", "replace", REAL_IP, "lladdr", REAL_MAC, "dev", ROUTER_REAL_IFACE, "nud", "permanent")
        _nsc(REAL_NS, "neigh", "replace", ROUTER_REAL_IP, "lladdr", ROUTER_REAL_MAC, "dev", REAL_IFACE, "nud", "permanent")
        set_ns_sysctl(ROUTER_NS, "net.ipv4.ip_forward", 1)
        rp_router = ("net.ipv4.conf.all.rp_filter", "net.ipv4.conf.default.rp_filter",
                     f"net.ipv4.conf.{ROUTER_LB_IFACE}.rp_filter", f"net.ipv4.conf.{ROUTER_CLIENT_IFACE}.rp_filter", f"net.ipv4.conf.{ROUTER_REAL_IFACE}.rp_filter")
        rp_real = ("net.ipv4.conf.all.rp_filter", "net.ipv4.conf.default.rp_filter", "net.ipv4.conf.lo.rp_filter",
                   f"net.ipv4.conf.{REAL_IFACE}.rp_filter", "net.ipv4.conf.ipip0.rp_filter")
        for ns, keys in ((ROUTER_NS, rp_router), (REAL_NS, rp_real)):
            for key in keys: set_ns_sysctl(ns, key, 0)
        self.lb_ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        return self

    def cleanup(self) -> None:
        if self.router_peer_iface is None and link_exists(self.iface):
            ip_command(["link", "del", self.iface], check=False, timeout=15)
        if self.router_peer_iface is not None:
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "netns", "1"], check=False, timeout=15)
        for ns in (REAL_NS, CLIENT_NS, ROUTER_NS): ip_command(["netns", "del", ns], check=False, timeout=15)
        if self.router_peer_iface is not None and link_exists(ROUTER_LB_IFACE) and not link_exists(self.router_peer_iface):
            ip_command(["link", "set", "dev", ROUTER_LB_IFACE, "name", self.router_peer_iface], check=False, timeout=15)

    def metadata(self) -> dict[str, object]:
        return {"namespaces": {"router": ROUTER_NS, "client": CLIENT_NS, "real": REAL_NS},
                "iface": self.iface, "router_peer_iface": self.router_peer_iface, "lb_ifindex": self.lb_ifindex}

    def close(self) -> None: self.cleanup()
    def __exit__(self, exc_type, exc, tb) -> None: self.close()


NAMESPACE_HTTP_SERVER_SCRIPT = """
import http.server
import socketserver
import sys

class Handler(http.server.BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.0"
    def do_GET(self):
        body = b"katran-ok\\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Connection", "close")
        self.end_headers()
        try:
            self.wfile.write(body)
            self.wfile.flush()
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, TimeoutError):
            return
        self.close_connection = True
    def log_message(self, fmt, *args):
        pass

class Server(socketserver.ThreadingMixIn, http.server.HTTPServer):
    daemon_threads = True
    allow_reuse_address = True
    request_queue_size = 128

server = Server((sys.argv[1], int(sys.argv[2])), Handler)
server.serve_forever()
"""


class NamespaceHttpServer:
    def __init__(self, namespace: str, bind_ip: str, port: int) -> None:
        self.namespace = namespace; self.bind_ip = bind_ip; self.port = int(port)
        self.process: subprocess.Popen[str] | None = None; self.stdout_tail = ""; self.stderr_tail = ""

    def __enter__(self) -> "NamespaceHttpServer":
        self.process = subprocess.Popen(
            [ip_binary(), "netns", "exec", self.namespace, remote_python_binary(), "-u", "-c", NAMESPACE_HTTP_SERVER_SCRIPT, self.bind_ip, str(self.port)],
            cwd=ROOT_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
        )
        try: self._wait_until_ready()
        except Exception: self.close(); raise
        return self

    def _wait_until_ready(self) -> None:
        assert self.process is not None
        deadline = time.monotonic() + SERVER_START_TIMEOUT_S
        probe = "import socket, sys; s = socket.socket(); s.settimeout(0.2); rc = s.connect_ex((sys.argv[1], int(sys.argv[2]))); s.close(); raise SystemExit(0 if rc == 0 else 1)"
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                stdout, stderr = self.process.communicate(timeout=5)
                self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
                self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
                raise RuntimeError(f"http server exited early: {self.stderr_tail or self.stdout_tail}")
            if ns_exec_command(self.namespace, [remote_python_binary(), "-c", probe, self.bind_ip, str(self.port)], check=False, timeout=5).returncode == 0: return
            time.sleep(0.1)
        raise RuntimeError("timed out waiting for namespace http server to start")

    def metadata(self) -> dict[str, object]:
        return {"namespace": self.namespace, "bind_ip": self.bind_ip, "port": self.port,
                "pid": None if self.process is None else self.process.pid,
                "stdout_tail": self.stdout_tail, "stderr_tail": self.stderr_tail}

    def close(self) -> None:
        if self.process is None: return
        if self.process.poll() is None:
            self.process.terminate()
            try: stdout, stderr = self.process.communicate(timeout=10)
            except subprocess.TimeoutExpired: self.process.kill(); stdout, stderr = self.process.communicate(timeout=10)
        else:
            stdout, stderr = self.process.communicate(timeout=10)
        self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
        self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
        self.process = None

    def __exit__(self, exc_type, exc, tb) -> None: self.close()


class KatranServerSession:
    def __init__(self, *, server_binary: Path, balancer_prog_path: Path, iface: str, default_router_mac: str,
                 load_timeout_s: int = DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S) -> None:
        self.server_binary = server_binary.resolve(); self.balancer_prog_path = balancer_prog_path.resolve()
        self.iface = iface; self.default_router_mac = default_router_mac; self.load_timeout_s = int(load_timeout_s)
        self.session: ManagedProcessSession | None = None; self.command_used: list[str] = []
        self.programs: list[dict[str, object]] = []; self.program: dict[str, object] = {}
        self.maps_by_name: dict[str, dict[str, object]] = {}; self.attach_info: dict[str, object] = {}
        self.attach_mode_before_rebind: str | None = None; self.attach_info_before_rebind: dict[str, object] = {}
        self.ifindex = 0

    def __enter__(self) -> "KatranServerSession":
        if not link_exists(self.iface): raise RuntimeError(f"network interface does not exist: {self.iface}")
        if not self.balancer_prog_path.exists(): raise RuntimeError(f"Katran balancer program image not found: {self.balancer_prog_path}")
        self.ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        command = [str(self.server_binary), f"-balancer_prog={self.balancer_prog_path}", f"-default_mac={self.default_router_mac}",
                   f"-intf={self.iface}", "-hc_forwarding=false", "-logtostderr", "-alsologtostderr"]
        before_map_ids = {int(r.get("id", -1)) for r in _map_show_records() if "id" in r}
        session = ManagedProcessSession(command, load_timeout_s=self.load_timeout_s, cwd=ROOT_DIR, env=os.environ.copy())
        try:
            session.__enter__(); self.session = session; self.command_used = list(command)
            self.programs = [dict(p) for p in session.programs]; self.program = self._select_program(self.programs)
            self.maps_by_name = self._discover_maps(before_map_ids); self.attach_info = _attached_xdp_info(self.iface)
        except Exception:
            session.close(); self.session = None; raise
        if not self.attach_info:
            self.close(); raise RuntimeError(f"Katran server did not expose an attached XDP program on {self.iface}")
        return self

    @property
    def prog_id(self) -> int: return int(self.program.get("id", 0) or 0)

    @property
    def pid(self) -> int | None: return None if self.session is None else self.session.pid

    def map_id(self, name: str) -> int:
        record = self.maps_by_name.get(name)
        if record is None: raise RuntimeError(f"Katran server map is unavailable: {name}")
        return int(record.get("id", 0) or 0)

    def collector_snapshot(self) -> dict[str, object]:
        return {} if self.session is None else self.session.collector_snapshot()

    def _select_program(self, programs: list[dict[str, object]]) -> dict[str, object]:
        if not programs: raise RuntimeError("Katran server did not expose any BPF programs")
        expected_names = _program_name_variants(DEFAULT_KATRAN_PROGRAM_NAME)
        matching = [dict(p) for p in programs if str(p.get("name") or "") in expected_names]
        if len(matching) == 1: return matching[0]
        xdp_programs = [dict(p) for p in programs if str(p.get("type") or "") == "xdp"]
        if len(xdp_programs) == 1: return xdp_programs[0]
        attached = sorted(f"{p.get('name') or '<unnamed>'}:{p.get('type') or '<unknown>'}" for p in programs)
        raise RuntimeError(f"could not determine Katran balancer program from attached set: {attached}")

    def _discover_maps(self, before_map_ids: set[int]) -> dict[str, dict[str, object]]:
        deadline = time.monotonic() + float(self.load_timeout_s); last_names: list[str] = []
        while time.monotonic() < deadline:
            new_records = [r for r in _map_show_records() if int(r.get("id", -1)) not in before_map_ids]
            maps_by_name = {str(r.get("name") or ""): dict(r) for r in new_records if str(r.get("name") or "").strip()}
            if not (missing := [n for n in KATRAN_REQUIRED_MAP_NAMES if n not in maps_by_name]):
                return {n: dict(maps_by_name[n]) for n in KATRAN_REQUIRED_MAP_NAMES}
            last_names = sorted(maps_by_name)
            if self.session is not None and self.session.process is not None and self.session.process.poll() is not None: break
            time.sleep(0.2)
        missing = [n for n in KATRAN_REQUIRED_MAP_NAMES if n not in last_names]
        raise RuntimeError(f"Katran server did not expose expected maps {missing}; discovered {last_names}")

    def metadata(self) -> dict[str, object]:
        return {
            "server_binary": str(self.server_binary), "balancer_prog_path": str(self.balancer_prog_path),
            "program": dict(self.program), "programs": [dict(p) for p in self.programs],
            "maps": {n: dict(r) for n, r in self.maps_by_name.items()},
            "iface": self.iface, "ifindex": self.ifindex,
            "attached": bool(self.attach_info), "attach_info": self.attach_info,
            "attach_mode": _attached_xdp_mode(self.attach_info),
            "attach_mode_before_rebind": self.attach_mode_before_rebind,
            "attach_info_before_rebind": dict(self.attach_info_before_rebind),
            "pid": self.pid, "command_used": list(self.command_used),
        }

    def reattach_xdpgeneric(self) -> None:
        self.attach_info_before_rebind = dict(self.attach_info); self.attach_mode_before_rebind = _attached_xdp_mode(self.attach_info)
        self.attach_info = reattach_xdp_program(self.iface, self.prog_id, target_mode="generic")

    def close(self) -> None:
        if self.session is None: return
        session, self.session = self.session, None; session.close()

    def __exit__(self, exc_type, exc, tb) -> None: self.close()


def configure_katran_maps(session: KatranServerSession) -> dict[str, object]:
    vip_id = session.map_id("vip_map")
    reals_id = session.map_id("reals")
    rings_id = session.map_id("ch_rings")
    ctl_id = session.map_id("ctl_array")
    real_num_bytes = pack_u32(REAL_NUM)
    _bpftool_map_update_batch(
        [
            (ctl_id, pack_u32(0), pack_ctl_mac(ROUTER_LB_MAC)),
            (vip_id, pack_vip_definition(VIP_IP, VIP_PORT, TCP_PROTO), pack_vip_meta(F_LRU_BYPASS, VIP_NUM)),
            (reals_id, real_num_bytes, pack_real_definition(REAL_IP)),
            *[
                (rings_id, pack_u32((VIP_NUM * CH_RING_SIZE) + ring_pos), real_num_bytes)
                for ring_pos in range(CH_RING_SIZE)
            ],
        ]
    )
    return {"map_ids": {n: session.map_id(n) for n in KATRAN_REQUIRED_MAP_NAMES},
            "vip": {"address": VIP_IP, "port": VIP_PORT, "proto": TCP_PROTO, "vip_num": VIP_NUM, "flags": F_LRU_BYPASS},
            "real": {"address": REAL_IP, "real_num": REAL_NUM}, "default_gateway_mac": ROUTER_LB_MAC, "ch_ring_size": CH_RING_SIZE}


def run_katran_prog_test_run(session: KatranServerSession, *, repeat: int = 1, require_xdp_tx: bool = True) -> dict[str, object]:
    if not DEFAULT_KATRAN_TEST_PACKET.exists():
        raise RuntimeError(f"Katran test packet is missing: {DEFAULT_KATRAN_TEST_PACKET}")
    packet = DEFAULT_KATRAN_TEST_PACKET.read_bytes()
    result = _bpftool_prog_test_run(session.prog_id, packet, repeat=max(1, int(repeat)))
    result.update({"packet_path": str(DEFAULT_KATRAN_TEST_PACKET), "expected_retval": XDP_TX,
                   "expected_action": xdp_action_name(XDP_TX), "action": xdp_action_name(int(result["retval"])),
                   "ok": int(result["retval"]) == XDP_TX})
    if require_xdp_tx and not bool(result["ok"]):
        raise RuntimeError(f"Katran BPF_PROG_TEST_RUN expected XDP_TX, got {result['action']} ({result['retval']})")
    return result


PARALLEL_CLIENT_REQUEST_SCRIPT = """
import json
import socket
import statistics
import sys
import threading
import time

host = sys.argv[1]
port = int(sys.argv[2])
duration_s = float(sys.argv[3])
concurrency = max(1, int(sys.argv[4]))
timeout = float(sys.argv[5])
preview_limit = max(1, int(sys.argv[6]))
payload = b"GET / HTTP/1.0\\r\\nHost: katran\\r\\nConnection: close\\r\\n\\r\\n"

latencies = []
failure_preview = []
request_count = 0
success_count = 0
bytes_total = 0
lock = threading.Lock()

def percentile(values, pct):
    if not values:
        return None
    if len(values) == 1:
        return float(values[0])
    ordered = sorted(float(value) for value in values)
    rank = max(0.0, min(1.0, float(pct) / 100.0)) * (len(ordered) - 1)
    lower = int(rank)
    upper = min(len(ordered) - 1, lower + 1)
    weight = rank - lower
    return ordered[lower] * (1.0 - weight) + ordered[upper] * weight

def worker(worker_id, deadline):
    global request_count, success_count, bytes_total
    local_latencies = []
    local_failures = []
    local_requests = 0
    local_successes = 0
    local_bytes = 0
    while time.monotonic() < deadline:
        started = time.monotonic()
        local_requests += 1
        try:
            with socket.create_connection((host, port), timeout=timeout) as sock:
                sock.settimeout(timeout)
                sock.sendall(payload)
                chunks = []
                while True:
                    chunk = sock.recv(4096)
                    if not chunk:
                        break
                    chunks.append(chunk)
            data = b"".join(chunks)
            text = data.decode("latin1", "replace")
            if text.startswith("HTTP/1.0 200 OK") or text.startswith("HTTP/1.1 200 OK"):
                local_successes += 1
                local_bytes += len(data)
                local_latencies.append((time.monotonic() - started) * 1000.0)
            elif len(local_failures) < preview_limit:
                local_failures.append({"worker": worker_id, "error": "non-200 response", "snippet": text[:200]})
        except Exception as exc:
            if len(local_failures) < preview_limit:
                local_failures.append({"worker": worker_id, "error": str(exc), "snippet": ""})
    with lock:
        request_count += local_requests
        success_count += local_successes
        bytes_total += local_bytes
        latencies.extend(local_latencies)
        for item in local_failures:
            if len(failure_preview) >= preview_limit:
                break
            failure_preview.append(item)

started = time.monotonic()
deadline = started + max(0.0, duration_s)
threads = [threading.Thread(target=worker, args=(index, deadline), daemon=True) for index in range(concurrency)]
for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
elapsed = max(0.000001, time.monotonic() - started)
latency_summary = {
    "count": len(latencies),
    "mean": statistics.mean(latencies) if latencies else None,
    "median": statistics.median(latencies) if latencies else None,
    "min": min(latencies) if latencies else None,
    "max": max(latencies) if latencies else None,
    "p50": percentile(latencies, 50.0),
    "p90": percentile(latencies, 90.0),
    "p99": percentile(latencies, 99.0),
}
print(json.dumps({"driver": "python_parallel", "request_count": request_count, "success_count": success_count, "ops_per_sec": (success_count / elapsed) if elapsed > 0 else None, "duration_s": elapsed, "bytes_total": bytes_total, "latency_ms": latency_summary, "failure_preview": failure_preview, "concurrency": concurrency}))
"""


def run_parallel_http_load(*, duration_s: int | float, concurrency: int) -> dict[str, object]:
    payload = run_json_command(
        ["ip", "netns", "exec", CLIENT_NS, remote_python_binary(), "-c", PARALLEL_CLIENT_REQUEST_SCRIPT,
         VIP_IP, str(VIP_PORT), str(max(0.0, float(duration_s))), str(max(1, int(concurrency))),
         str(HTTP_TIMEOUT_S), str(REQUEST_FAILURE_PREVIEW_LIMIT)],
        timeout=max(30, int(float(duration_s) * 4) + 10),
    )
    if not isinstance(payload, Mapping):
        raise RuntimeError("parallel client payload is not a JSON object")
    return dict(payload)


DEFAULT_INTERFACE = "katran0"
DEFAULT_CONCURRENCY = 4
DEFAULT_TEST_RUN_BATCH_REPEAT = 128
DEFAULT_WORKLOAD_KIND = "network"
DEFAULT_LOAD_TIMEOUT_S = DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S


class KatranRunner(AppRunner):
    def __init__(self, *, loader_binary: Path | str | None = None, iface: str = DEFAULT_INTERFACE,
                 router_peer_iface: str | None = None, load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
                 concurrency: int = DEFAULT_CONCURRENCY, workload_kind: str = DEFAULT_WORKLOAD_KIND,
                 test_run_batch_repeat: int = DEFAULT_TEST_RUN_BATCH_REPEAT, default_router_mac: str = ROUTER_LB_MAC) -> None:
        super().__init__()
        self.loader_binary = None if loader_binary is None else Path(loader_binary).resolve()
        self.balancer_prog_path = default_katran_balancer_prog_path().resolve()
        self.iface = str(iface); self.router_peer_iface = None if router_peer_iface is None else str(router_peer_iface)
        self.load_timeout_s = int(load_timeout_s); self.concurrency = max(1, int(concurrency))
        self.workload_kind = str(workload_kind or DEFAULT_WORKLOAD_KIND).strip().lower()
        self.test_run_batch_repeat = max(1, int(test_run_batch_repeat)); self.default_router_mac = str(default_router_mac)
        self.topology: Any | None = None; self.http_server: Any | None = None; self.session: KatranServerSession | None = None
        self.artifacts: dict[str, object] = {}; self.last_request_summary: dict[str, object] = {}

    @property
    def prog_id(self) -> int | None: return None if self.session is None else int(self.session.prog_id)

    @property
    def pid(self) -> int | None: return None if self.session is None else self.session.pid

    @property
    def last_workload_details(self) -> Mapping[str, object]: return dict(self.last_request_summary)

    def start(self) -> list[int]:
        if self.session is not None: raise RuntimeError("KatranRunner is already running")
        topology = KatranDsrTopology(self.iface, router_peer_iface=self.router_peer_iface)
        http_server = None if self.workload_kind == "test_run" else NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT)
        server_binary = resolve_katran_server_binary(self.loader_binary)
        session = KatranServerSession(server_binary=server_binary, balancer_prog_path=self.balancer_prog_path,
                                      iface=self.iface, default_router_mac=self.default_router_mac, load_timeout_s=self.load_timeout_s)
        try:
            topology.__enter__()
            if http_server is not None: http_server.__enter__()
            session.__enter__()
            if self.workload_kind == "network": session.reattach_xdpgeneric()
            self.artifacts = {"topology": topology.metadata(), "http_server": {} if http_server is None else http_server.metadata(),
                               "live_program": session.metadata(), "map_configuration": configure_katran_maps(session),
                               "test_run_validation": run_katran_prog_test_run(session, repeat=1, require_xdp_tx=False)}
            time.sleep(TOPOLOGY_SETTLE_S)
        except Exception:
            session.close()
            if http_server is not None: http_server.close()
            topology.close(); raise
        self.topology = topology; self.http_server = http_server; self.session = session
        self.loader_binary = server_binary; self.command_used = list(session.command_used); self.programs = [dict(session.program)]
        return [int(session.prog_id)]

    def _run_test_run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None: raise RuntimeError("KatranRunner is not running")
        deadline = time.monotonic() + max(0.1, float(seconds))
        batches = 0; total_packets = 0; last_summary: dict[str, object] = {}; started_at = time.monotonic()
        while time.monotonic() < deadline or batches == 0:
            last_summary = run_katran_prog_test_run(self.session, repeat=self.test_run_batch_repeat, require_xdp_tx=False)
            total_packets += int(last_summary.get("repeat", 0) or 0); batches += 1
        elapsed = max(0.000001, time.monotonic() - started_at)
        self.last_request_summary = {"driver": "prog_test_run", "batches": batches, "packet_count": total_packets,
                                      "duration_s": elapsed, "last_result": dict(last_summary), "namespace": CLIENT_NS}
        return WorkloadResult(ops_total=float(total_packets), ops_per_sec=float(total_packets) / elapsed,
                              duration_s=elapsed, stdout="", stderr=tail_text(str(last_summary)))

    def _run_network_workload(self, seconds: float) -> WorkloadResult:
        summary = run_parallel_http_load(duration_s=max(1.0, float(seconds)), concurrency=self.concurrency)
        self.last_request_summary = dict(summary)
        request_count, success_count = int(summary.get("request_count", 0) or 0), int(summary.get("success_count", 0) or 0)
        if request_count <= 0: raise RuntimeError(f"Katran workload produced zero requests: {summary.get('failure_preview')}")
        if success_count != request_count: raise RuntimeError(f"Katran workload observed failures: {summary.get('failure_preview')}")
        return WorkloadResult(ops_total=float(request_count),
                              ops_per_sec=float(summary["ops_per_sec"]) if summary.get("ops_per_sec") is not None else None,
                              duration_s=float(summary.get("duration_s") or seconds),
                              stdout="", stderr=tail_text(str(summary.get("failure_preview") or "")))

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None: raise RuntimeError("KatranRunner is not running")
        if self.workload_kind == "test_run": return self._run_test_run_workload(seconds)
        if self.workload_kind != "network": raise RuntimeError(f"unsupported Katran workload kind: {self.workload_kind}")
        return self._run_network_workload(seconds)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or self.workload_kind).strip().lower()
        if requested_kind != self.workload_kind:
            raise RuntimeError(f"KatranRunner workload kind is fixed at start ({self.workload_kind}); requested {requested_kind}")
        return self.run_workload(seconds)

    def stop(self) -> None:
        errors: list[str] = []; prog_id = self.prog_id
        if self.session is not None:
            session, self.session = self.session, None
            process = None if session.session is None else session.session.process
            snapshot = session.collector_snapshot()
            try: session.close()
            except Exception as exc: errors.append(str(exc))
            self.process_output = {"returncode": None if process is None else process.returncode,
                                    "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
                                    "stderr_tail": "\n".join(snapshot.get("stderr_tail") or [])}
        for attr in ("http_server", "topology"):
            obj = getattr(self, attr, None)
            if obj is not None:
                try: obj.close()
                except Exception as exc: errors.append(str(exc))
                setattr(self, attr, None)
        if not errors:
            try: wait_for_katran_teardown(prog_id, settle_s=DEFAULT_KATRAN_STOP_SETTLE_S)
            except Exception as exc: errors.append(str(exc))
        if errors: raise RuntimeError("; ".join(errors))
