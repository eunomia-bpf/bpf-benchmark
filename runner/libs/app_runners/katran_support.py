from __future__ import annotations

import ctypes
import ctypes.util
import os
import shutil
import socket
import struct
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Any

from .. import ROOT_DIR, run_command, run_json_command, tail_text, which


DEFAULT_KATRAN_TEST_PACKET = ROOT_DIR / "corpus" / "inputs" / "katran_vip_packet_64.bin"
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

MODULE_FALLBACK_CANDIDATES: dict[str, tuple[Path, ...]] = {
    "veth": (ROOT_DIR / "vendor" / "linux-framework" / "drivers" / "net" / "veth.ko",),
    "tunnel4": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "tunnel4.ko",),
    "ip_tunnel": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "ip_tunnel.ko",),
    "ipip": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "ipip.ko",),
}

def ip_binary() -> str:
    for candidate in DEFAULT_IP_CANDIDATES:
        path = Path(candidate)
        if path.is_file() and os.access(path, os.X_OK):
            return str(path)
    resolved = which("ip")
    if resolved:
        return resolved
    raise RuntimeError("ip is required for the katran runner")


def _normalize_ip_command(command: list[str] | tuple[str, ...]) -> list[str]:
    args = [str(part) for part in command]
    if args and args[0] == "ip":
        return args[1:]
    return args


def ip_command(command: list[str] | tuple[str, ...], *, check: bool = True, timeout: int | float | None = 30) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), *_normalize_ip_command(command)], check=check, timeout=timeout)


def ns_exec_command(
    namespace: str,
    command: list[str] | tuple[str, ...],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), "netns", "exec", namespace, *[str(part) for part in command]], check=check, timeout=timeout)


def ns_ip_command(
    namespace: str,
    command: list[str] | tuple[str, ...],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return ns_exec_command(namespace, [ip_binary(), *_normalize_ip_command(command)], check=check, timeout=timeout)


def link_exists(name: str) -> bool:
    return Path("/sys/class/net").joinpath(name).exists()


def module_loaded(name: str) -> bool:
    return Path("/sys/module").joinpath(name).exists()


def ensure_kernel_module_loaded(name: str) -> None:
    if module_loaded(name):
        return
    attempts: list[str] = []
    modprobe = run_command(["modprobe", name], check=False, timeout=15)
    if modprobe.returncode == 0 and module_loaded(name):
        return
    detail = (modprobe.stderr or modprobe.stdout).strip()
    attempts.append(f"modprobe rc={modprobe.returncode}: {detail or 'no output'}")
    candidates = [candidate for candidate in MODULE_FALLBACK_CANDIDATES.get(name, ()) if candidate.exists()]
    for module_root in (Path("/lib/modules"), ROOT_DIR / "vendor" / "linux-framework" / ".virtme_mods" / "lib" / "modules"):
        if module_root.exists():
            candidates.extend(sorted(module_root.glob(f"**/{name}.ko")))
    for candidate in dict.fromkeys(candidates):
        insmod = run_command(["insmod", str(candidate)], check=False, timeout=15)
        if insmod.returncode == 0 and module_loaded(name):
            return
        detail = (insmod.stderr or insmod.stdout).strip()
        attempts.append(f"insmod {candidate} rc={insmod.returncode}: {detail or 'no output'}")
    raise RuntimeError(f"failed to load kernel module {name}: {'; '.join(attempts)}")


def set_ns_sysctl(namespace: str, key: str, value: int) -> None:
    proc_key = key.replace(".", "/")
    ns_exec_command(namespace, ["sh", "-c", f"printf '%s' '{int(value)}' > /proc/sys/{proc_key}"], timeout=15)


def set_link_mac(namespace: str | None, iface: str, mac: str) -> None:
    if namespace is None:
        ip_command(["link", "set", "dev", iface, "address", mac], timeout=15)
        return
    ns_ip_command(namespace, ["link", "set", "dev", iface, "address", mac], timeout=15)


class BpfTestRunOpts(ctypes.Structure):
    _fields_ = [
        ("sz", ctypes.c_size_t),
        ("data_in", ctypes.c_void_p),
        ("data_out", ctypes.c_void_p),
        ("data_size_in", ctypes.c_uint32),
        ("data_size_out", ctypes.c_uint32),
        ("ctx_in", ctypes.c_void_p),
        ("ctx_out", ctypes.c_void_p),
        ("ctx_size_in", ctypes.c_uint32),
        ("ctx_size_out", ctypes.c_uint32),
        ("retval", ctypes.c_uint32),
        ("repeat", ctypes.c_int),
        ("duration", ctypes.c_uint32),
        ("flags", ctypes.c_uint32),
        ("cpu", ctypes.c_uint32),
        ("batch_size", ctypes.c_uint32),
    ]


class LibbpfMapApi:
    def __init__(self) -> None:
        path = ctypes.util.find_library("bpf") or "libbpf.so.1"
        self.lib = ctypes.CDLL(path, use_errno=True)
        self.lib.bpf_obj_get.argtypes = [ctypes.c_char_p]
        self.lib.bpf_obj_get.restype = ctypes.c_int
        self.lib.bpf_map_update_elem.argtypes = [ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_uint64]
        self.lib.bpf_map_update_elem.restype = ctypes.c_int
        self.lib.bpf_prog_test_run_opts.argtypes = [ctypes.c_int, ctypes.POINTER(BpfTestRunOpts)]
        self.lib.bpf_prog_test_run_opts.restype = ctypes.c_int

    def obj_get(self, path: Path) -> int:
        fd = int(self.lib.bpf_obj_get(os.fsencode(str(path))))
        if fd >= 0:
            return fd
        err = ctypes.get_errno()
        raise RuntimeError(f"bpf_obj_get failed for {path}: {os.strerror(err)} (errno={err})")

    def update(self, fd: int, key: bytes, value: bytes, flags: int = 0) -> None:
        key_buf = (ctypes.c_ubyte * len(key)).from_buffer_copy(key)
        value_buf = (ctypes.c_ubyte * len(value)).from_buffer_copy(value)
        rc = int(self.lib.bpf_map_update_elem(int(fd), ctypes.byref(key_buf), ctypes.byref(value_buf), int(flags)))
        if rc == 0:
            return
        err = ctypes.get_errno()
        raise RuntimeError(f"bpf_map_update_elem failed: {os.strerror(err)} (errno={err})")

    def prog_test_run(self, prog_fd: int, packet: bytes, *, repeat: int = 1, data_out_size: int | None = None) -> dict[str, object]:
        in_buf = (ctypes.c_ubyte * len(packet)).from_buffer_copy(packet)
        out_size = max(1, int(data_out_size or len(packet)))
        out_buf = (ctypes.c_ubyte * out_size)()
        opts = BpfTestRunOpts()
        opts.sz = ctypes.sizeof(BpfTestRunOpts)
        opts.data_in = ctypes.cast(in_buf, ctypes.c_void_p)
        opts.data_size_in = len(packet)
        opts.data_out = ctypes.cast(out_buf, ctypes.c_void_p)
        opts.data_size_out = out_size
        opts.repeat = max(1, int(repeat))
        rc = int(self.lib.bpf_prog_test_run_opts(int(prog_fd), ctypes.byref(opts)))
        if rc != 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_prog_test_run_opts failed: {os.strerror(err)} (errno={err})")
        output_size = max(0, int(opts.data_size_out))
        return {
            "retval": int(opts.retval),
            "duration_ns": int(opts.duration),
            "repeat": int(opts.repeat),
            "data_size_in": len(packet),
            "data_size_out": output_size,
            "data_out_preview_hex": bytes(out_buf[: min(output_size, 32)]).hex(),
        }


def pack_u32(value: int) -> bytes:
    return struct.pack("=I", int(value))


def pack_mac(mac: str) -> bytes:
    return bytes(int(part, 16) for part in mac.split(":"))


def pack_ctl_mac(mac: str) -> bytes:
    return pack_mac(mac) + b"\x00\x00"


def pack_vip_definition(address: str, port: int, proto: int) -> bytes:
    return socket.inet_aton(address) + (b"\x00" * 12) + struct.pack("!HBB", int(port), int(proto), 0)


def pack_vip_meta(flags: int, vip_num: int) -> bytes:
    return struct.pack("=II", int(flags), int(vip_num))


def pack_real_definition(address: str, flags: int = 0) -> bytes:
    return socket.inet_aton(address) + (b"\x00" * 12) + bytes([int(flags) & 0xFF]) + (b"\x00" * 3)


def xdp_action_name(retval: int) -> str:
    return {0: "XDP_ABORTED", 1: "XDP_DROP", XDP_PASS: "XDP_PASS", XDP_TX: "XDP_TX", 4: "XDP_REDIRECT"}.get(int(retval), f"UNKNOWN({int(retval)})")


class KatranDsrTopology:
    def __init__(self, iface: str, *, router_peer_iface: str | None = None) -> None:
        self.iface = iface
        self.router_peer_iface = router_peer_iface or None
        self.lb_ifindex = 0

    def __enter__(self) -> "KatranDsrTopology":
        self.cleanup()
        for mod in ("veth", "tunnel4", "ip_tunnel", "ipip"):
            ensure_kernel_module_loaded(mod)
        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            ip_command(["netns", "add", namespace], timeout=15)
        if self.router_peer_iface is None:
            ip_command(["link", "add", self.iface, "type", "veth", "peer", "name", ROUTER_LB_IFACE], timeout=15)
            ip_command(["link", "set", ROUTER_LB_IFACE, "netns", ROUTER_NS], timeout=15)
        else:
            if self.router_peer_iface == self.iface:
                raise RuntimeError("router peer iface must differ from Katran ingress iface")
            if not link_exists(self.iface):
                raise RuntimeError(f"network interface does not exist: {self.iface}")
            if not link_exists(self.router_peer_iface):
                raise RuntimeError(f"router peer interface does not exist: {self.router_peer_iface}")
            ip_command(["link", "set", self.router_peer_iface, "netns", ROUTER_NS], timeout=15)
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", self.router_peer_iface, "name", ROUTER_LB_IFACE], timeout=15)
        ip_command(["link", "add", ROUTER_CLIENT_IFACE, "type", "veth", "peer", "name", CLIENT_IFACE], timeout=15)
        ip_command(["link", "set", ROUTER_CLIENT_IFACE, "netns", ROUTER_NS], timeout=15)
        ip_command(["link", "set", CLIENT_IFACE, "netns", CLIENT_NS], timeout=15)
        ip_command(["link", "add", ROUTER_REAL_IFACE, "type", "veth", "peer", "name", REAL_IFACE], timeout=15)
        ip_command(["link", "set", ROUTER_REAL_IFACE, "netns", ROUTER_NS], timeout=15)
        ip_command(["link", "set", REAL_IFACE, "netns", REAL_NS], timeout=15)
        set_link_mac(None, self.iface, LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_LB_IFACE, ROUTER_LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_CLIENT_IFACE, ROUTER_CLIENT_MAC)
        set_link_mac(CLIENT_NS, CLIENT_IFACE, CLIENT_MAC)
        set_link_mac(ROUTER_NS, ROUTER_REAL_IFACE, ROUTER_REAL_MAC)
        set_link_mac(REAL_NS, REAL_IFACE, REAL_MAC)
        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            ns_ip_command(namespace, ["link", "set", "lo", "up"], timeout=15)
        ip_command(["addr", "replace", f"{LB_IP}/24", "dev", self.iface], timeout=15)
        ip_command(["link", "set", "dev", self.iface, "up"], timeout=15)
        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_LB_IP}/24", "dev", ROUTER_LB_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_CLIENT_IP}/24", "dev", ROUTER_CLIENT_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_REAL_IP}/24", "dev", ROUTER_REAL_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "up"], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_CLIENT_IFACE, "up"], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_REAL_IFACE, "up"], timeout=15)
        ns_ip_command(CLIENT_NS, ["addr", "add", f"{CLIENT_IP}/24", "dev", CLIENT_IFACE], timeout=15)
        ns_ip_command(CLIENT_NS, ["link", "set", "dev", CLIENT_IFACE, "up"], timeout=15)
        ns_ip_command(REAL_NS, ["addr", "add", f"{REAL_IP}/24", "dev", REAL_IFACE], timeout=15)
        ns_ip_command(REAL_NS, ["link", "set", "dev", REAL_IFACE, "up"], timeout=15)
        ns_ip_command(REAL_NS, ["addr", "add", f"{VIP_IP}/32", "dev", "lo"], timeout=15)
        ns_ip_command(REAL_NS, ["link", "add", "name", "ipip0", "type", "ipip", "external"], timeout=15)
        ns_ip_command(REAL_NS, ["addr", "add", f"{IPIP_DUMMY_IP}/32", "dev", "ipip0"], timeout=15)
        ns_ip_command(REAL_NS, ["link", "set", "dev", "ipip0", "up"], timeout=15)
        ns_ip_command(CLIENT_NS, ["route", "add", "default", "via", ROUTER_CLIENT_IP, "dev", CLIENT_IFACE], timeout=15)
        ns_ip_command(REAL_NS, ["route", "add", "default", "via", ROUTER_REAL_IP, "dev", REAL_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["route", "add", f"{VIP_IP}/32", "via", LB_IP, "dev", ROUTER_LB_IFACE], timeout=15)
        ns_ip_command(CLIENT_NS, ["neigh", "replace", ROUTER_CLIENT_IP, "lladdr", ROUTER_CLIENT_MAC, "dev", CLIENT_IFACE, "nud", "permanent"], timeout=15)
        ns_ip_command(ROUTER_NS, ["neigh", "replace", LB_IP, "lladdr", LB_MAC, "dev", ROUTER_LB_IFACE, "nud", "permanent"], timeout=15)
        ns_ip_command(ROUTER_NS, ["neigh", "replace", REAL_IP, "lladdr", REAL_MAC, "dev", ROUTER_REAL_IFACE, "nud", "permanent"], timeout=15)
        ns_ip_command(REAL_NS, ["neigh", "replace", ROUTER_REAL_IP, "lladdr", ROUTER_REAL_MAC, "dev", REAL_IFACE, "nud", "permanent"], timeout=15)
        set_ns_sysctl(ROUTER_NS, "net.ipv4.ip_forward", 1)
        for namespace, keys in (
            (ROUTER_NS, ("net.ipv4.conf.all.rp_filter", "net.ipv4.conf.default.rp_filter", f"net.ipv4.conf.{ROUTER_LB_IFACE}.rp_filter", f"net.ipv4.conf.{ROUTER_CLIENT_IFACE}.rp_filter", f"net.ipv4.conf.{ROUTER_REAL_IFACE}.rp_filter")),
            (REAL_NS, ("net.ipv4.conf.all.rp_filter", "net.ipv4.conf.default.rp_filter", "net.ipv4.conf.lo.rp_filter", f"net.ipv4.conf.{REAL_IFACE}.rp_filter", "net.ipv4.conf.ipip0.rp_filter")),
        ):
            for key in keys:
                set_ns_sysctl(namespace, key, 0)
        self.lb_ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        return self

    def cleanup(self) -> None:
        if self.router_peer_iface is None and link_exists(self.iface):
            ip_command(["link", "del", self.iface], check=False, timeout=15)
        if self.router_peer_iface is not None:
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "netns", "1"], check=False, timeout=15)
        for namespace in (REAL_NS, CLIENT_NS, ROUTER_NS):
            ip_command(["netns", "del", namespace], check=False, timeout=15)
        if self.router_peer_iface is not None and link_exists(ROUTER_LB_IFACE) and not link_exists(self.router_peer_iface):
            ip_command(["link", "set", "dev", ROUTER_LB_IFACE, "name", self.router_peer_iface], check=False, timeout=15)

    def metadata(self) -> dict[str, object]:
        return {
            "namespaces": {"router": ROUTER_NS, "client": CLIENT_NS, "real": REAL_NS},
            "iface": self.iface,
            "router_peer_iface": self.router_peer_iface,
            "lb_ifindex": self.lb_ifindex,
        }

    def close(self) -> None:
        self.cleanup()

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


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
        self.namespace = namespace
        self.bind_ip = bind_ip
        self.port = int(port)
        self.process: subprocess.Popen[str] | None = None
        self.stdout_tail = ""
        self.stderr_tail = ""

    def __enter__(self) -> "NamespaceHttpServer":
        self.process = subprocess.Popen(
            [ip_binary(), "netns", "exec", self.namespace, "python3", "-u", "-c", NAMESPACE_HTTP_SERVER_SCRIPT, self.bind_ip, str(self.port)],
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        try:
            self._wait_until_ready()
        except Exception:
            self.close()
            raise
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
            completed = ns_exec_command(self.namespace, ["python3", "-c", probe, self.bind_ip, str(self.port)], check=False, timeout=5)
            if completed.returncode == 0:
                return
            time.sleep(0.1)
        raise RuntimeError("timed out waiting for namespace http server to start")

    def metadata(self) -> dict[str, object]:
        return {
            "namespace": self.namespace,
            "bind_ip": self.bind_ip,
            "port": self.port,
            "pid": None if self.process is None else self.process.pid,
            "stdout_tail": self.stdout_tail,
            "stderr_tail": self.stderr_tail,
        }

    def close(self) -> None:
        if self.process is None:
            return
        if self.process.poll() is None:
            self.process.terminate()
            try:
                stdout, stderr = self.process.communicate(timeout=10)
            except subprocess.TimeoutExpired:
                self.process.kill()
                stdout, stderr = self.process.communicate(timeout=10)
        else:
            stdout, stderr = self.process.communicate(timeout=10)
        self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
        self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
        self.process = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


class KatranDirectSession:
    def __init__(self, *, object_path: Path, program_name: str, iface: str, attach: bool, bpftool: str) -> None:
        self.object_path = object_path
        self.program_name = program_name
        self.iface = iface
        self.attach = attach
        self.bpftool = bpftool
        self.bpffs_dir: Path | None = None
        self.prog_dir: Path | None = None
        self.map_dir: Path | None = None
        self.pinned_prog: Path | None = None
        self.program: dict[str, object] = {}
        self.attach_info: dict[str, object] = {}
        self.attach_error = ""
        self.attach_mode: str | None = None
        self.ifindex = 0

    def __enter__(self) -> "KatranDirectSession":
        if not link_exists(self.iface):
            raise RuntimeError(f"network interface does not exist: {self.iface}")
        self.ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        self.bpffs_dir = Path(tempfile.mkdtemp(prefix="katrane2e-", dir="/sys/fs/bpf"))
        self.prog_dir = self.bpffs_dir / "progs"
        self.map_dir = self.bpffs_dir / "maps"
        self.prog_dir.mkdir(parents=True, exist_ok=True)
        self.map_dir.mkdir(parents=True, exist_ok=True)
        run_command([self.bpftool, "prog", "loadall", str(self.object_path), str(self.prog_dir), "type", "xdp", "pinmaps", str(self.map_dir)], timeout=90)
        self.pinned_prog = self.prog_dir / self.program_name
        if not self.pinned_prog.exists():
            raise RuntimeError(f"pinned program not found after load: {self.pinned_prog}")
        self.program = self._show_program()
        if self.attach:
            self._attempt_attach()
        return self

    @property
    def prog_id(self) -> int:
        return int(self.program.get("id", 0) or 0)

    def map_path(self, name: str) -> Path:
        if self.map_dir is None:
            raise RuntimeError("map directory is not initialized")
        return self.map_dir / name

    def _show_program(self) -> dict[str, object]:
        assert self.pinned_prog is not None
        payload = run_json_command([self.bpftool, "-j", "prog", "show", "pinned", str(self.pinned_prog)], timeout=30)
        if not isinstance(payload, dict):
            raise RuntimeError("bpftool prog show pinned returned unexpected payload")
        return dict(payload)

    def _attempt_attach(self) -> None:
        assert self.pinned_prog is not None
        errors: list[str] = []
        for mode in ("xdpgeneric", "xdp"):
            try:
                run_command([self.bpftool, "net", "attach", mode, "pinned", str(self.pinned_prog), "dev", self.iface, "overwrite"], timeout=30)
                self.attach_mode = mode
                payload = run_json_command([self.bpftool, "-j", "net", "show", "dev", self.iface], timeout=30)
                if isinstance(payload, list):
                    for record in payload:
                        if isinstance(record, dict) and (record.get("xdp") or record.get("xdp_attached")):
                            self.attach_info = dict(record)
                            break
                return
            except Exception as exc:
                errors.append(f"{mode}: {exc}")
        self.attach_error = "; ".join(errors)

    def metadata(self) -> dict[str, object]:
        return {
            "program": dict(self.program),
            "iface": self.iface,
            "ifindex": self.ifindex,
            "attached": bool(self.attach and not self.attach_error),
            "attach_mode": self.attach_mode,
            "attach_error": self.attach_error,
            "attach_info": self.attach_info,
            "bpffs_dir": None if self.bpffs_dir is None else str(self.bpffs_dir),
            "pinned_prog": None if self.pinned_prog is None else str(self.pinned_prog),
            "pinned_maps": [] if self.map_dir is None else sorted(path.name for path in self.map_dir.iterdir()),
        }

    def close(self) -> None:
        if self.attach and self.attach_mode:
            run_command([self.bpftool, "net", "detach", self.attach_mode, "dev", self.iface], check=False, timeout=15)
            self.attach_mode = None
        if self.bpffs_dir is not None:
            shutil.rmtree(self.bpffs_dir, ignore_errors=True)
            self.bpffs_dir = None
            self.prog_dir = None
            self.map_dir = None
            self.pinned_prog = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def configure_katran_maps(session: KatranDirectSession) -> dict[str, object]:
    api = LibbpfMapApi()
    vip_fd = api.obj_get(session.map_path("vip_map"))
    reals_fd = api.obj_get(session.map_path("reals"))
    rings_fd = api.obj_get(session.map_path("ch_rings"))
    ctl_fd = api.obj_get(session.map_path("ctl_array"))
    try:
        api.update(ctl_fd, pack_u32(0), pack_ctl_mac(ROUTER_LB_MAC))
        api.update(vip_fd, pack_vip_definition(VIP_IP, VIP_PORT, TCP_PROTO), pack_vip_meta(F_LRU_BYPASS, VIP_NUM))
        api.update(reals_fd, pack_u32(REAL_NUM), pack_real_definition(REAL_IP))
        for ring_pos in range(CH_RING_SIZE):
            api.update(rings_fd, pack_u32((VIP_NUM * CH_RING_SIZE) + ring_pos), pack_u32(REAL_NUM))
    finally:
        os.close(vip_fd)
        os.close(reals_fd)
        os.close(rings_fd)
        os.close(ctl_fd)
    return {
        "vip": {"address": VIP_IP, "port": VIP_PORT, "proto": TCP_PROTO, "vip_num": VIP_NUM, "flags": F_LRU_BYPASS},
        "real": {"address": REAL_IP, "real_num": REAL_NUM},
        "default_gateway_mac": ROUTER_LB_MAC,
        "ch_ring_size": CH_RING_SIZE,
    }


def run_katran_prog_test_run(
    session: KatranDirectSession,
    *,
    repeat: int = 1,
    require_xdp_tx: bool = True,
) -> dict[str, object]:
    if session.pinned_prog is None:
        raise RuntimeError("Katran pinned program path is unavailable")
    if not DEFAULT_KATRAN_TEST_PACKET.exists():
        raise RuntimeError(f"Katran test packet is missing: {DEFAULT_KATRAN_TEST_PACKET}")
    api = LibbpfMapApi()
    packet = DEFAULT_KATRAN_TEST_PACKET.read_bytes()
    prog_fd = api.obj_get(session.pinned_prog)
    try:
        result = api.prog_test_run(prog_fd, packet, repeat=max(1, int(repeat)), data_out_size=max(256, len(packet) + 64))
    finally:
        os.close(prog_fd)
    result.update(
        {
            "packet_path": str(DEFAULT_KATRAN_TEST_PACKET),
            "expected_retval": XDP_TX,
            "expected_action": xdp_action_name(XDP_TX),
            "action": xdp_action_name(int(result["retval"])),
            "ok": int(result["retval"]) == XDP_TX,
        }
    )
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
        [
            "ip",
            "netns",
            "exec",
            CLIENT_NS,
            "python3",
            "-c",
            PARALLEL_CLIENT_REQUEST_SCRIPT,
            VIP_IP,
            str(VIP_PORT),
            str(max(0.0, float(duration_s))),
            str(max(1, int(concurrency))),
            str(HTTP_TIMEOUT_S),
            str(REQUEST_FAILURE_PREVIEW_LIMIT),
        ],
        timeout=max(30, int(float(duration_s) * 4) + 10),
    )
    if not isinstance(payload, Mapping):
        raise RuntimeError("parallel client payload is not a JSON object")
    return dict(payload)


__all__ = [
    "CLIENT_NS",
    "KatranDirectSession",
    "KatranDsrTopology",
    "NamespaceHttpServer",
    "REAL_NS",
    "TOPOLOGY_SETTLE_S",
    "VIP_IP",
    "VIP_PORT",
    "XDP_TX",
    "configure_katran_maps",
    "run_katran_prog_test_run",
    "run_parallel_http_load",
]
