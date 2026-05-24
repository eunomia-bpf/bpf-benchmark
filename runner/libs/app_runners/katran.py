from __future__ import annotations

import ctypes
import errno
import os
import platform
import shlex
import socket
import struct
import subprocess
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from ..kernel_modules import kernel_module_is_builtin, load_kernel_module
from ..workload import WorkloadResult, resolve_workload_tool
from .base import AppRunner
from .process_support import ManagedProcessSession
from .setup_support import repo_artifact_root

DEFAULT_KATRAN_STOP_TIMEOUT_S = 200.0
DEFAULT_KATRAN_STOP_SETTLE_S = 2.0
KATRAN_REQUIRED_MAP_NAMES = ("vip_map", "reals", "ch_rings", "ctl_array")
DEFAULT_IP_CANDIDATES = (
    "/usr/local/sbin/ip",
    "/usr/local/bin/ip",
    "/usr/sbin/ip",
    "/usr/bin/ip",
    "/sbin/ip",
    "/bin/ip",
)
TCP_PROTO = socket.IPPROTO_TCP
UDP_PROTO = socket.IPPROTO_UDP
F_LRU_BYPASS = 1 << 1
F_QUIC_VIP = 1 << 2
F_GLOBAL_LRU = 1 << 6
F_HASH_SRC_DST_PORT = 1 << 7
F_UDP_STABLE_ROUTING_VIP = 1 << 8
F_UDP_FLOW_MIGRATION = 1 << 9
KATRAN_PKTGEN_VIP_FLAGS = (
    F_QUIC_VIP
    | F_GLOBAL_LRU
    | F_HASH_SRC_DST_PORT
    | F_UDP_STABLE_ROUTING_VIP
    | F_UDP_FLOW_MIGRATION
)
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

TOPOLOGY_SETTLE_S = 2.0

DEFAULT_HC_V4_TUN_IFACE = "ipip0"
DEFAULT_HC_V6_TUN_IFACE = "ipip60"


def _map_show_records() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "map", "show"])
    if not isinstance(payload, list): raise RuntimeError("bpftool map show returned unexpected payload")
    return [dict(record) for record in payload if isinstance(record, dict)]


def _net_show_records(iface: str) -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "net", "show", "dev", str(iface)])
    if not isinstance(payload, list): raise RuntimeError(f"bpftool net show returned unexpected payload for {iface}")
    return [dict(record) for record in payload if isinstance(record, dict)]


def _attached_xdp_info(iface: str) -> dict[str, object]:
    return next((dict(r) for r in _net_show_records(iface) if r.get("xdp") or r.get("xdp_attached")), {})


def _attached_xdp_mode(attach_info: Mapping[str, object] | None) -> str | None:
    if not isinstance(attach_info, Mapping): return None
    if isinstance(xdp_records := attach_info.get("xdp"), list):
        for entry in xdp_records:
            if isinstance(entry, Mapping) and (mode := str(entry.get("mode") or "").strip().lower()): return mode
    mode = str(attach_info.get("attach_mode") or "").strip().lower()
    return mode or None


def _detach_all_xdp_modes(iface: str) -> None:
    for attach_type in ("xdpgeneric", "xdpdrv", "xdp", "xdpoffload"):
        run_command(
            [resolve_bpftool_binary(), "net", "detach", attach_type, "dev", str(iface)],
            check=False,
        )


def _namespace_exists(namespace: str) -> bool:
    return any(Path(root).joinpath(namespace).exists() for root in ("/run/netns", "/var/run/netns"))


def wait_for_katran_teardown(
    *,
    timeout_s: float = DEFAULT_KATRAN_STOP_TIMEOUT_S,
    settle_s: float = DEFAULT_KATRAN_STOP_SETTLE_S,
) -> None:
    deadline = time.monotonic() + max(0.1, float(timeout_s))
    settle = max(0.0, float(settle_s))
    _ns_triple = (ROUTER_NS, CLIENT_NS, REAL_NS)
    while time.monotonic() < deadline:
        if all(not _namespace_exists(ns) for ns in _ns_triple):
            if settle > 0.0:
                time.sleep(settle)
            return
        time.sleep(0.1)
    remaining = [ns for ns in _ns_triple if _namespace_exists(ns)]
    raise RuntimeError("Katran teardown did not quiesce before the next app start: "
                       + (", ".join(remaining) if remaining else "transient kernel/procfs state remained"))


def resolve_katran_server_binary(explicit: Path | str | None = None) -> Path:
    candidate = Path(explicit).expanduser().resolve() if (explicit is not None and str(explicit).strip()) else (repo_artifact_root() / "katran" / "bin" / "katran_server_grpc").resolve()
    if candidate.is_file() and os.access(candidate, os.X_OK): return candidate
    raise RuntimeError(f"Katran server binary not found or not executable; tried: {candidate}")


def katran_native_loader_env() -> dict[str, str]:
    enabled = os.environ.get("BPFREJIT_SHIM_NATIVE_LOADER", "").strip().lower()
    if enabled not in {"1", "true", "yes", "on"}:
        return {}
    explicit = os.environ.get("BPFREJIT_SHIM_NATIVE_OBJECT_DIR", "").strip()
    if explicit:
        native_dir = Path(explicit)
    else:
        arch = os.environ.get("RUN_TARGET_ARCH", "x86_64").strip() or "x86_64"
        native_dir = Path(f"/opt/bpf-benchmark/native-bpf/{arch}/katran")
    if not native_dir.is_dir():
        raise RuntimeError(f"Katran native object directory not found: {native_dir}")
    return {"BPFREJIT_SHIM_NATIVE_OBJECT_DIR": str(native_dir)}


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


def ip_command(command: list[str] | tuple[str, ...], *, check: bool = True) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), *_normalize_ip_command(command)], check=check)


def ns_exec_command(namespace: str, command: list[str] | tuple[str, ...], *, check: bool = True) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), "netns", "exec", namespace, *[str(part) for part in command]], check=check)


def ns_ip_command(namespace: str, command: list[str] | tuple[str, ...], *, check: bool = True) -> subprocess.CompletedProcess[str]:
    return ns_exec_command(namespace, [ip_binary(), *_normalize_ip_command(command)], check=check)


def link_exists(name: str) -> bool:
    return Path("/sys/class/net").joinpath(name).exists()


def module_loaded(name: str) -> bool:
    return Path("/sys/module").joinpath(name).exists()


def ensure_kernel_module_loaded(name: str) -> None:
    if module_loaded(name): return
    if kernel_module_is_builtin(name): return
    load_kernel_module(name)
    if module_loaded(name): return
    if kernel_module_is_builtin(name): return
    raise RuntimeError(f"kernel module {name} still is not resident after modprobe")


def set_ns_sysctl(namespace: str, key: str, value: int) -> None:
    ns_exec_command(namespace, ["sh", "-c", f"printf '%s' '{int(value)}' > /proc/sys/{key.replace('.', '/')}"])


def set_link_mac(namespace: str | None, iface: str, mac: str) -> None:
    cmd = ["link", "set", "dev", iface, "address", mac]
    (ip_command if namespace is None else lambda c, **kw: ns_ip_command(namespace, c, **kw))(cmd)


def pack_u32(value: int) -> bytes: return struct.pack("=I", int(value))
def pack_ctl_mac(mac: str) -> bytes: return bytes(int(p, 16) for p in mac.split(":")) + b"\x00\x00"
def pack_vip_definition(address: str, port: int, proto: int) -> bytes: return socket.inet_aton(address) + (b"\x00" * 12) + struct.pack("!HBB", int(port), int(proto), 0)
def pack_vip_meta(flags: int, vip_num: int) -> bytes: return struct.pack("=II", int(flags), int(vip_num))
def pack_real_definition(address: str, flags: int = 0) -> bytes: return socket.inet_aton(address) + (b"\x00" * 12) + bytes([int(flags) & 0xFF]) + (b"\x00" * 3)


_SYS_BPF = {"x86_64": 321, "amd64": 321, "aarch64": 280, "arm64": 280}.get(platform.machine())
_BPF_MAP_GET_FD_BY_ID = 14
_BPF_MAP_UPDATE_BATCH = 26
_LIBC = ctypes.CDLL("libc.so.6", use_errno=True)


class _BpfAttrGetFdById(ctypes.Structure):
    _pack_ = 8
    _fields_ = [("map_id", ctypes.c_uint32), ("next_id", ctypes.c_uint32), ("open_flags", ctypes.c_uint32)]


class _BpfAttrBatch(ctypes.Structure):
    _pack_ = 8
    _fields_ = [("in_batch", ctypes.c_uint64), ("out_batch", ctypes.c_uint64),
                ("keys", ctypes.c_uint64), ("values", ctypes.c_uint64),
                ("count", ctypes.c_uint32), ("map_fd", ctypes.c_uint32),
                ("elem_flags", ctypes.c_uint64), ("flags", ctypes.c_uint64)]


def _bpf_syscall(cmd: int, attr: ctypes.Structure) -> int:
    if _SYS_BPF is None:
        raise RuntimeError(f"unsupported architecture for BPF syscall: {platform.machine()!r}")
    rc = _LIBC.syscall(_SYS_BPF, cmd, ctypes.byref(attr), ctypes.sizeof(attr))
    if rc < 0:
        e = ctypes.get_errno()
        raise OSError(e, f"bpf(cmd={cmd}) failed: {errno.errorcode.get(e, e)} {os.strerror(e)}")
    return rc


def _bpf_map_update_batch(updates: list[tuple[int, bytes, bytes]]) -> None:
    if not updates: return
    by_map: dict[int, list[tuple[bytes, bytes]]] = {}
    for map_id, key, value in updates:
        by_map.setdefault(int(map_id), []).append((bytes(key), bytes(value)))
    for map_id, entries in by_map.items():
        fd = _bpf_syscall(_BPF_MAP_GET_FD_BY_ID, _BpfAttrGetFdById(map_id=map_id))
        try:
            key_size = len(entries[0][0]); value_size = len(entries[0][1])
            for k, v in entries:
                if len(k) != key_size or len(v) != value_size:
                    raise RuntimeError(f"inconsistent key/value sizes for map {map_id}")
            keys_blob = b"".join(k for k, _ in entries)
            values_blob = b"".join(v for _, v in entries)
            keys_buf = (ctypes.c_char * len(keys_blob)).from_buffer_copy(keys_blob)
            values_buf = (ctypes.c_char * len(values_blob)).from_buffer_copy(values_blob)
            attr = _BpfAttrBatch(map_fd=fd, count=len(entries),
                                 keys=ctypes.addressof(keys_buf),
                                 values=ctypes.addressof(values_buf))
            _bpf_syscall(_BPF_MAP_UPDATE_BATCH, attr)
            if attr.count != len(entries):
                raise RuntimeError(f"BPF_MAP_UPDATE_BATCH partial update for map {map_id}: {attr.count}/{len(entries)}")
        finally:
            os.close(fd)


class KatranDsrTopology:
    def __init__(self, iface: str, *, router_peer_iface: str | None = None) -> None:
        self.iface = iface
        self.router_peer_iface = router_peer_iface or None
        self.lb_ifindex = 0
        self.created_hc_ifaces: list[str] = []

    def __enter__(self) -> "KatranDsrTopology":
        self.cleanup()
        for mod in ("veth", "tunnel4", "ip_tunnel", "ipip", "ip6_tunnel"): ensure_kernel_module_loaded(mod)
        for ns in (ROUTER_NS, CLIENT_NS, REAL_NS): ip_command(["netns", "add", ns])
        if self.router_peer_iface is None:
            ip_command(["link", "add", self.iface, "type", "veth", "peer", "name", ROUTER_LB_IFACE])
            ip_command(["link", "set", ROUTER_LB_IFACE, "netns", ROUTER_NS])
        else:
            if self.router_peer_iface == self.iface: raise RuntimeError("router peer iface must differ from Katran ingress iface")
            if not link_exists(self.iface): raise RuntimeError(f"network interface does not exist: {self.iface}")
            if not link_exists(self.router_peer_iface): raise RuntimeError(f"router peer interface does not exist: {self.router_peer_iface}")
            ip_command(["link", "set", self.router_peer_iface, "netns", ROUTER_NS])
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", self.router_peer_iface, "name", ROUTER_LB_IFACE])
        _ipc = lambda *a: ip_command(list(a))
        _nsc = lambda ns, *a: ns_ip_command(ns, list(a))
        _ipc("link", "add", ROUTER_CLIENT_IFACE, "type", "veth", "peer", "name", CLIENT_IFACE)
        _ipc("link", "set", ROUTER_CLIENT_IFACE, "netns", ROUTER_NS)
        _ipc("link", "set", CLIENT_IFACE, "netns", CLIENT_NS)
        _ipc("link", "add", ROUTER_REAL_IFACE, "type", "veth", "peer", "name", REAL_IFACE)
        _ipc("link", "set", ROUTER_REAL_IFACE, "netns", ROUTER_NS)
        _ipc("link", "set", REAL_IFACE, "netns", REAL_NS)
        for hc_iface, hc_type in ((DEFAULT_HC_V4_TUN_IFACE, "ipip"), (DEFAULT_HC_V6_TUN_IFACE, "ip6tnl")):
            if not link_exists(hc_iface):
                _ipc("link", "add", "name", hc_iface, "type", hc_type, "external")
                self.created_hc_ifaces.append(hc_iface)
            _ipc("link", "set", "dev", hc_iface, "up")
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
            ip_command(["link", "del", self.iface], check=False)
        if self.router_peer_iface is not None:
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "netns", "1"], check=False)
        for hc_iface in self.created_hc_ifaces:
            if link_exists(hc_iface):
                ip_command(["link", "del", hc_iface], check=False)
        self.created_hc_ifaces = []
        for ns in (REAL_NS, CLIENT_NS, ROUTER_NS): ip_command(["netns", "del", ns], check=False)
        if self.router_peer_iface is not None and link_exists(ROUTER_LB_IFACE) and not link_exists(self.router_peer_iface):
            ip_command(["link", "set", "dev", ROUTER_LB_IFACE, "name", self.router_peer_iface], check=False)

    def metadata(self) -> dict[str, object]:
        return {"namespaces": {"router": ROUTER_NS, "client": CLIENT_NS, "real": REAL_NS},
                "iface": self.iface, "router_peer_iface": self.router_peer_iface, "lb_ifindex": self.lb_ifindex,
                "healthcheck_ifaces": list(self.created_hc_ifaces)}

    def close(self) -> None: self.cleanup()
    def __exit__(self, exc_type, exc, tb) -> None: self.close()


NAMESPACE_HTTP_SERVER_SCRIPT = """
import http.server
import socketserver
import sys

import socket as _sock

class Handler(http.server.BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"
    disable_nagle_algorithm = True
    def setup(self):
        super().setup()
        self.connection.setsockopt(_sock.IPPROTO_TCP, _sock.TCP_NODELAY, 1)
    def do_GET(self):
        body = b"katran-ok\\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        try:
            self.wfile.write(body)
            self.wfile.flush()
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, TimeoutError):
            return
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
        probe = "import socket, sys; s = socket.socket(); s.settimeout(0.2); rc = s.connect_ex((sys.argv[1], int(sys.argv[2]))); s.close(); raise SystemExit(0 if rc == 0 else 1)"
        while True:
            if self.process.poll() is not None:
                stdout, stderr = self.process.communicate()
                self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
                self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
                raise RuntimeError(f"http server exited early: {self.stderr_tail or self.stdout_tail}")
            if ns_exec_command(self.namespace, [remote_python_binary(), "-c", probe, self.bind_ip, str(self.port)], check=False).returncode == 0: return
            time.sleep(0.1)

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
    def __init__(
        self,
        *,
        server_binary: Path,
        balancer_prog_path: Path,
        healthchecking_prog_path: Path,
        iface: str,
        default_router_mac: str,
    ) -> None:
        self.server_binary = server_binary.resolve()
        self.balancer_prog_path = balancer_prog_path.resolve()
        self.healthchecking_prog_path = healthchecking_prog_path.resolve()
        self.iface = iface
        self.default_router_mac = default_router_mac
        self.session: ManagedProcessSession | None = None
        self.command_used: list[str] = []
        self.programs: list[dict[str, object]] = []
        self.maps_by_name: dict[str, dict[str, object]] = {}
        self.attach_info: dict[str, object] = {}
        self.attach_mode_before_rebind: str | None = None
        self.attach_info_before_rebind: dict[str, object] = {}
        self.ifindex = 0

    def __enter__(self) -> "KatranServerSession":
        if not link_exists(self.iface):
            raise RuntimeError(f"network interface does not exist: {self.iface}")
        for artifact_path, label in (
            (self.balancer_prog_path, "balancer"),
            (self.healthchecking_prog_path, "healthchecking"),
        ):
            if not artifact_path.exists():
                raise RuntimeError(f"Katran {label} program image not found: {artifact_path}")
        self.ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        before_map_ids = {int(r.get("id", -1)) for r in _map_show_records() if "id" in r}
        command = [
            str(self.server_binary),
            f"-balancer_prog={self.balancer_prog_path}",
            f"-healthchecker_prog={self.healthchecking_prog_path}",
            f"-default_mac={self.default_router_mac}",
            f"-intf={self.iface}",
            f"-ipip_intf={DEFAULT_HC_V4_TUN_IFACE}",
            f"-ipip6_intf={DEFAULT_HC_V6_TUN_IFACE}",
            "-hc_forwarding=false",
            "-logtostderr",
            "-alsologtostderr",
        ]
        env = os.environ.copy()
        env.update(katran_native_loader_env())
        session = ManagedProcessSession(command, cwd=ROOT_DIR, env=env)
        try:
            session.__enter__()
            self.session = session
            self.command_used = list(command)
            self.programs = []
            self.maps_by_name = self._discover_maps(before_map_ids)
            self.attach_info = self._wait_for_xdp_attach()
        except Exception:
            close_errors: list[str] = []
            try:
                session.close()
            except Exception as exc:
                close_errors.append(str(exc))
            self.session = None
            try:
                self.close()
            except Exception as exc:
                close_errors.append(str(exc))
            if close_errors:
                raise RuntimeError("; ".join(close_errors))
            raise
        return self

    @property
    def pid(self) -> int | None: return None if self.session is None else self.session.pid

    def map_id(self, name: str) -> int:
        record = self.maps_by_name.get(name)
        if record is None: raise RuntimeError(f"Katran server map is unavailable: {name}")
        return int(record.get("id", 0) or 0)

    def collector_snapshot(self) -> dict[str, object]:
        return {} if self.session is None else self.session.collector_snapshot()

    def _discover_maps(self, before_map_ids: set[int]) -> dict[str, dict[str, object]]:
        last_names: list[str] = []
        while True:
            new_records = [r for r in _map_show_records() if int(r.get("id", -1)) not in before_map_ids]
            maps_by_name = {str(r.get("name") or ""): dict(r) for r in new_records if str(r.get("name") or "").strip()}
            if not (missing := [n for n in KATRAN_REQUIRED_MAP_NAMES if n not in maps_by_name]):
                return {n: dict(maps_by_name[n]) for n in KATRAN_REQUIRED_MAP_NAMES}
            last_names = sorted(maps_by_name)
            if self.session is not None and self.session.process is not None and self.session.process.poll() is not None: break
            time.sleep(0.2)
        missing = [n for n in KATRAN_REQUIRED_MAP_NAMES if n not in last_names]
        raise RuntimeError(f"Katran server did not expose expected maps {missing}; discovered {last_names}")

    def _wait_for_xdp_attach(self) -> dict[str, object]:
        while True:
            attach_info = _attached_xdp_info(self.iface)
            if attach_info:
                return attach_info
            if self.session is not None and self.session.process is not None and self.session.process.poll() is not None:
                break
            time.sleep(0.2)
        raise RuntimeError(f"Katran server did not expose an attached XDP program on {self.iface}")

    def metadata(self) -> dict[str, object]:
        return {
            "server_binary": str(self.server_binary), "balancer_prog_path": str(self.balancer_prog_path),
            "healthchecking_prog_path": str(self.healthchecking_prog_path),
            "maps": {n: dict(r) for n, r in self.maps_by_name.items()},
            "iface": self.iface, "ifindex": self.ifindex,
            "attached": bool(self.attach_info), "attach_info": self.attach_info,
            "attach_mode": _attached_xdp_mode(self.attach_info),
            "attach_mode_before_rebind": self.attach_mode_before_rebind,
            "attach_info_before_rebind": dict(self.attach_info_before_rebind),
            "pid": self.pid, "command_used": list(self.command_used),
        }

    def close(self) -> None:
        errors: list[str] = []
        if self.session is not None:
            session, self.session = self.session, None
            try:
                session.close()
            except Exception as exc:
                errors.append(str(exc))
        try:
            _detach_all_xdp_modes(self.iface)
        except Exception as exc:
            errors.append(str(exc))
        if errors:
            raise RuntimeError("; ".join(errors))

    def __exit__(self, exc_type, exc, tb) -> None: self.close()


def configure_katran_maps(
    session: KatranServerSession,
    *,
    proto: int = TCP_PROTO,
    flags: int = F_LRU_BYPASS,
) -> dict[str, object]:
    vip_id = session.map_id("vip_map")
    reals_id = session.map_id("reals")
    rings_id = session.map_id("ch_rings")
    ctl_id = session.map_id("ctl_array")
    real_num_bytes = pack_u32(REAL_NUM)
    _bpf_map_update_batch(
        [
            (ctl_id, pack_u32(0), pack_ctl_mac(ROUTER_LB_MAC)),
            (vip_id, pack_vip_definition(VIP_IP, VIP_PORT, proto), pack_vip_meta(flags, VIP_NUM)),
            (reals_id, real_num_bytes, pack_real_definition(REAL_IP)),
            *[
                (rings_id, pack_u32((VIP_NUM * CH_RING_SIZE) + ring_pos), real_num_bytes)
                for ring_pos in range(CH_RING_SIZE)
            ],
        ]
    )
    return {"map_ids": {n: session.map_id(n) for n in KATRAN_REQUIRED_MAP_NAMES},
            "vip": {"address": VIP_IP, "port": VIP_PORT, "proto": proto, "vip_num": VIP_NUM, "flags": flags},
            "real": {"address": REAL_IP, "real_num": REAL_NUM}, "default_gateway_mac": ROUTER_LB_MAC, "ch_ring_size": CH_RING_SIZE}


DEFAULT_INTERFACE = "katran0"
DEFAULT_WRK_THREADS = 4
DEFAULT_WRK_CONNECTIONS = 10
DEFAULT_PKTGEN_PKT_SIZE = 64
DEFAULT_PKTGEN_CLONE_SKB = 0
PKTGEN_CTRL = "/proc/net/pktgen/pgctrl"
KATRAN_PKTGEN_THREAD_IDS = (0, 1, 2, 3)
KATRAN_WORKLOADS = {"xdp_traffic", "xdp_pktgen"}


def _resolve_katran_bpf_artifact(*relative_candidates: str) -> Path:
    katran_root = repo_artifact_root() / "katran"
    for candidate in relative_candidates:
        path = (katran_root / candidate).resolve()
        if path.is_file():
            return path
    raise RuntimeError(
        "Katran BPF artifact not found; tried: "
        + ", ".join(str((katran_root / candidate).resolve()) for candidate in relative_candidates)
    )


class KatranRunner(AppRunner):
    def __init__(self, *, loader_binary: Path | str | None = None, iface: str = DEFAULT_INTERFACE,
                 router_peer_iface: str | None = None,
                 wrk_threads: int = DEFAULT_WRK_THREADS, wrk_connections: int = DEFAULT_WRK_CONNECTIONS,
                 workload_spec: Mapping[str, object],
                 default_router_mac: str = ROUTER_LB_MAC) -> None:
        super().__init__()
        self.loader_binary = None if loader_binary is None else Path(loader_binary).resolve()
        self.balancer_prog_path = _resolve_katran_bpf_artifact("bpf/balancer.bpf.o", "balancer.bpf.o")
        self.healthchecking_prog_path = _resolve_katran_bpf_artifact(
            "bpf/healthchecking_ipip.bpf.o",
            "healthchecking_ipip.bpf.o",
            "bpf/healthchecking_ipip.o",
            "healthchecking_ipip.o",
        )
        self.iface = str(iface); self.router_peer_iface = None if router_peer_iface is None else str(router_peer_iface)
        self.wrk_threads = max(1, int(wrk_threads))
        self.wrk_connections = max(1, int(wrk_connections))
        self.workload_spec = dict(workload_spec)
        self.workload_kind = str(self.workload_spec.get("kind") or self.workload_spec.get("name") or "").strip().lower()
        if self.workload_kind not in KATRAN_WORKLOADS:
            raise RuntimeError(f"KatranRunner only supports workload_spec.kind in {sorted(KATRAN_WORKLOADS)!r}, got {self.workload_kind!r}")
        self.default_router_mac = str(default_router_mac)
        self.topology: Any | None = None; self.http_server: Any | None = None; self.session: KatranServerSession | None = None
        self.artifacts: dict[str, object] = {}

    @property
    def pid(self) -> int | None: return None if self.session is None else self.session.pid

    def start(self) -> list[int]:
        if self.session is not None: raise RuntimeError("KatranRunner is already running")
        topology = KatranDsrTopology(self.iface, router_peer_iface=self.router_peer_iface)
        http_server = NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT)
        server_binary = resolve_katran_server_binary(self.loader_binary)
        session = KatranServerSession(
            server_binary=server_binary,
            balancer_prog_path=self.balancer_prog_path,
            healthchecking_prog_path=self.healthchecking_prog_path,
            iface=self.iface,
            default_router_mac=self.default_router_mac,
        )
        try:
            topology.__enter__()
            http_server.__enter__()
            session.__enter__()
            self.artifacts = {
                "topology": topology.metadata(),
                "http_server": http_server.metadata(),
                "live_program": session.metadata(),
                "map_configuration": configure_katran_maps(
                    session,
                    proto=UDP_PROTO if self.workload_kind == "xdp_pktgen" else TCP_PROTO,
                    flags=KATRAN_PKTGEN_VIP_FLAGS if self.workload_kind == "xdp_pktgen" else F_LRU_BYPASS,
                ),
            }
            time.sleep(TOPOLOGY_SETTLE_S)
        except Exception:
            cleanup_errors: list[str] = []
            try:
                session.close()
            except Exception as exc:
                cleanup_errors.append(str(exc))
            try:
                http_server.close()
            except Exception as exc:
                cleanup_errors.append(str(exc))
            try:
                topology.close()
            except Exception as exc:
                cleanup_errors.append(str(exc))
            if cleanup_errors:
                raise RuntimeError("; ".join(cleanup_errors))
            raise
        self.topology = topology; self.http_server = http_server; self.session = session
        self.loader_binary = server_binary
        self.command_used = list(session.command_used)
        self.programs = []
        return []

    def _run_network_workload(self, seconds: float) -> WorkloadResult:
        duration_s = max(1, int(float(seconds)))
        wrk_binary = resolve_workload_tool("wrk")
        url = f"http://{VIP_IP}:{VIP_PORT}/"
        command = [
            "ip", "netns", "exec", CLIENT_NS,
            wrk_binary,
            f"-t{self.wrk_threads}",
            f"-c{self.wrk_connections}",
            f"-d{duration_s}s",
            "--latency",
            url,
        ]
        start = time.monotonic()
        completed = run_command(command, check=False)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            raise RuntimeError(
                f"Katran wrk workload failed: {tail_text(completed.stderr or completed.stdout)}"
            )
        return WorkloadResult(
            workload_name="katran_wrk_http",
            command=tuple(str(p) for p in command),
            returncode=completed.returncode,
            duration_s=elapsed,
            stdout=tail_text(completed.stdout or "", max_lines=200000, max_chars=8388608),
            stderr=tail_text(completed.stderr or "", max_lines=200000, max_chars=8388608),
            config={"tool": "wrk", "url": url, "threads": self.wrk_threads, "connections": self.wrk_connections},
        )

    def _run_pktgen_workload(self, seconds: float) -> WorkloadResult:
        duration_s = max(1, int(float(seconds)))
        ensure_kernel_module_loaded("pktgen")
        self._pktgen_write(PKTGEN_CTRL, "reset")
        aliases = tuple(f"{ROUTER_LB_IFACE}@{thread_id}" for thread_id in KATRAN_PKTGEN_THREAD_IDS)
        for thread_id, alias in zip(KATRAN_PKTGEN_THREAD_IDS, aliases, strict=True):
            thread_path = f"/proc/net/pktgen/kpktgend_{thread_id}"
            self._pktgen_write(thread_path, "rem_device_all")
            self._pktgen_write(thread_path, f"add_device {alias}")
        pktgen_commands = (
            "flag !SHARED",
            f"clone_skb {DEFAULT_PKTGEN_CLONE_SKB}",
            "burst 1",
            "count 0",
            "delay 0",
            "xmit_mode start_xmit",
            f"pkt_size {DEFAULT_PKTGEN_PKT_SIZE}",
            f"src_min {CLIENT_IP}",
            f"src_max {CLIENT_IP}",
            f"dst {VIP_IP}",
            f"dst_max {VIP_IP}",
            f"src_mac {ROUTER_LB_MAC}",
            f"dst_mac {LB_MAC}",
            f"udp_dst_min {VIP_PORT}",
            f"udp_dst_max {VIP_PORT}",
            "udp_src_min 1",
            "udp_src_max 65535",
            "flows 65535",
            "flowlen 1",
            "clear_counters",
        )
        for alias in aliases:
            device_path = f"/proc/net/pktgen/{alias}"
            for command in pktgen_commands:
                self._pktgen_write(device_path, command)
        command = [ip_binary(), "netns", "exec", ROUTER_NS, "sh", "-c", self._pktgen_write_script(PKTGEN_CTRL, "start")]
        start = time.monotonic()
        process = subprocess.Popen(command, cwd=ROOT_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        try:
            time.sleep(duration_s)
            self._pktgen_write(PKTGEN_CTRL, "stop")
            stdout, stderr = process.communicate()
        except BaseException:
            if process.poll() is None:
                try: self._pktgen_write(PKTGEN_CTRL, "stop")
                finally: process.kill()
            raise
        elapsed = time.monotonic() - start
        if process.returncode != 0:
            raise RuntimeError(f"Katran pktgen workload failed: {tail_text(stderr or stdout)}")
        components = tuple(
            WorkloadResult(
                workload_name="katran_kernel_pktgen_l2_udp_thread",
                command=tuple(str(p) for p in command),
                returncode=int(process.returncode or 0),
                duration_s=elapsed,
                stdout=tail_text(self._pktgen_read(f"/proc/net/pktgen/{alias}"), max_lines=200000, max_chars=8388608),
                stderr="",
                config={"tool": "kernel_pktgen", "namespace": ROUTER_NS, "iface": alias,
                        "thread_id": int(thread_id), "shared_skb": False,
                        "xmit_mode": "start_xmit", "pkt_size": DEFAULT_PKTGEN_PKT_SIZE,
                        "clone_skb": DEFAULT_PKTGEN_CLONE_SKB,
                        "src_ip": CLIENT_IP, "dst_ip": VIP_IP, "dst_port": VIP_PORT,
                        "proto": UDP_PROTO},
            )
            for thread_id, alias in zip(KATRAN_PKTGEN_THREAD_IDS, aliases, strict=True)
        )
        return WorkloadResult(
            workload_name="katran_kernel_pktgen_l2_udp",
            command=tuple(str(p) for p in command),
            returncode=int(process.returncode or 0),
            duration_s=elapsed,
            stdout="",
            stderr=tail_text(stderr or "", max_lines=200000, max_chars=8388608),
            config={"tool": "kernel_pktgen", "namespace": ROUTER_NS, "iface": ROUTER_LB_IFACE,
                    "shared_skb": False, "xmit_mode": "start_xmit",
                    "pkt_size": DEFAULT_PKTGEN_PKT_SIZE,
                    "clone_skb": DEFAULT_PKTGEN_CLONE_SKB,
                    "threads": list(KATRAN_PKTGEN_THREAD_IDS),
                    "src_ip": CLIENT_IP, "dst_ip": VIP_IP, "dst_port": VIP_PORT, "proto": UDP_PROTO},
            components=components,
        )

    @staticmethod
    def _pktgen_write_script(path: str, command: str) -> str:
        return f"printf '%s\\n' {shlex.quote(command)} > {shlex.quote(path)}"

    def _pktgen_write(self, path: str, command: str) -> None:
        ns_exec_command(ROUTER_NS, ["sh", "-c", self._pktgen_write_script(path, command)])

    def _pktgen_read(self, path: str) -> str:
        return ns_exec_command(ROUTER_NS, ["cat", path]).stdout or ""

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None: raise RuntimeError("KatranRunner is not running")
        if self.workload_kind == "xdp_pktgen":
            return self._run_pktgen_workload(seconds)
        return self._run_network_workload(seconds)

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or self.workload_kind).strip().lower()
        if requested_kind != self.workload_kind:
            raise RuntimeError(f"KatranRunner workload kind is fixed at start ({self.workload_kind}); requested {requested_kind}")
        return self.run_workload(seconds)

    def stop(self) -> None:
        errors: list[str] = []
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
            try: wait_for_katran_teardown(settle_s=DEFAULT_KATRAN_STOP_SETTLE_S)
            except Exception as exc: errors.append(str(exc))
        if errors: raise RuntimeError("; ".join(errors))


def run_katran_workload_without_app(
    kind: str,
    duration_s: int | float,
    *,
    iface: str = DEFAULT_INTERFACE,
    router_peer_iface: str | None = None,
) -> WorkloadResult:
    workload_kind = str(kind or "").strip().lower()
    if workload_kind != "xdp_pktgen":
        raise RuntimeError(f"Katran workload-only mode only supports xdp_pktgen, got {workload_kind!r}")
    topology = KatranDsrTopology(str(iface), router_peer_iface=router_peer_iface)
    runner = KatranRunner(workload_spec={"kind": workload_kind}, iface=str(iface), router_peer_iface=router_peer_iface)
    try:
        topology.__enter__()
        time.sleep(TOPOLOGY_SETTLE_S)
        return runner._run_pktgen_workload(duration_s)
    finally:
        errors: list[str] = []
        try:
            topology.close()
        except Exception as exc:
            errors.append(str(exc))
        try:
            wait_for_katran_teardown(settle_s=DEFAULT_KATRAN_STOP_SETTLE_S)
        except Exception as exc:
            errors.append(str(exc))
        if errors:
            raise RuntimeError("; ".join(errors))
