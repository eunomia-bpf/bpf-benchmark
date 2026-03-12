#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import platform
import shutil
import subprocess
import sys
import time
import traceback
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from e2e.common import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    ensure_root,
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    smoke_output_path,
    tail_text,
    which,
    write_json,
    write_text,
)
from e2e.common.metrics import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from e2e.common.recompile import (  # noqa: E402
    PolicyTarget,
    apply_recompile,
    resolve_policy_files,
    scan_programs,
)


DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "xdp_forwarding")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "xdp-forwarding-e2e.md"
DEFAULT_XDP_OBJECT = ROOT_DIR / "corpus" / "build" / "xdp-tools" / "xdp_forward.bpf.o"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_PROGRAM_NAME = "xdp_fwd_fib_full"
DEFAULT_ATTACH_TYPE = "xdp"
DEFAULT_TOPOLOGY_MODE = "veth"
DEFAULT_BPFTOOL = "/usr/local/sbin/bpftool"
DEFAULT_DURATION_S = 20
DEFAULT_SMOKE_DURATION_S = 5
DEFAULT_PACKET_SIZE = 64
DEFAULT_PARALLEL_STREAMS = 4
DEFAULT_SERVER_PORT = 5201


@dataclass(frozen=True, slots=True)
class Topology:
    run_id: str
    source_ns: str
    sink_ns: str
    source_if: str
    sink_if: str
    router_left_if: str
    router_right_if: str
    source_ip: str
    source_gateway: str
    router_left_ip: str
    sink_ip: str
    sink_gateway: str
    router_right_ip: str

    @property
    def source_host(self) -> str:
        return self.source_ip.split("/", 1)[0]

    @property
    def sink_host(self) -> str:
        return self.sink_ip.split("/", 1)[0]

    @property
    def router_left_host(self) -> str:
        return self.router_left_ip.split("/", 1)[0]

    @property
    def router_right_host(self) -> str:
        return self.router_right_ip.split("/", 1)[0]


def unique_suffix() -> str:
    return f"{os.getpid():x}"[-4:].rjust(4, "0")


def build_topology(
    *,
    source_if: str | None = None,
    sink_if: str | None = None,
    router_left_if: str | None = None,
    router_right_if: str | None = None,
) -> Topology:
    suffix = unique_suffix()
    return Topology(
        run_id=f"xdp-fwd-{suffix}",
        source_ns=f"xdp-src-{suffix}",
        sink_ns=f"xdp-dst-{suffix}",
        source_if=source_if or f"xfs{suffix}",
        sink_if=sink_if or f"xfd{suffix}",
        router_left_if=router_left_if or f"xfrl{suffix}",
        router_right_if=router_right_if or f"xfrr{suffix}",
        source_ip="10.201.0.2/24",
        source_gateway="10.201.0.1",
        router_left_ip="10.201.0.1/24",
        sink_ip="10.201.1.2/24",
        sink_gateway="10.201.1.1",
        router_right_ip="10.201.1.1/24",
    )


def host_metadata() -> dict[str, object]:
    try:
        git_sha = run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    except Exception:
        git_sha = "unknown"
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha,
    }


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def render_hex_u32(value: int) -> list[str]:
    raw = int(value).to_bytes(4, byteorder="little", signed=False)
    return [f"{byte:02x}" for byte in raw]


def ip_link_details(device: str, *, netns: str | None = None) -> dict[str, object]:
    command = ["ip", "-j", "link", "show", "dev", device]
    if netns:
        command = ["ip", "netns", "exec", netns, *command]
    payload = run_json_command(command, timeout=15)
    if not isinstance(payload, list) or not payload or not isinstance(payload[0], dict):
        raise RuntimeError(f"unexpected ip link payload for {device}")
    return payload[0]


def sysctl_get(key: str, *, netns: str | None = None) -> str:
    command = ["sysctl", "-n", key]
    if netns:
        command = ["ip", "netns", "exec", netns, *command]
    return run_command(command, timeout=15).stdout.strip()


def sysctl_set(key: str, value: str, *, netns: str | None = None) -> None:
    command = ["sysctl", "-w", f"{key}={value}"]
    if netns:
        command = ["ip", "netns", "exec", netns, *command]
    run_command(command, timeout=15)


def bpftool_prog_show(bpftool_binary: str, pinned_path: Path) -> dict[str, object]:
    payload = run_json_command(
        [bpftool_binary, "-j", "-p", "prog", "show", "pinned", str(pinned_path)],
        timeout=20,
    )
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected bpftool program payload for {pinned_path}")
    return payload


def parse_json_output(text: str, *, context: str) -> dict[str, object]:
    payload = text.strip()
    if not payload:
        raise RuntimeError(f"{context} produced no JSON output")
    try:
        parsed = json.loads(payload)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"{context} returned invalid JSON: {tail_text(payload)}") from exc
    if not isinstance(parsed, dict):
        raise RuntimeError(f"{context} returned unexpected payload")
    return parsed


def extract_iperf_udp_summary(payload: Mapping[str, object]) -> dict[str, object]:
    end = payload.get("end")
    if not isinstance(end, Mapping):
        raise RuntimeError("iperf3 JSON is missing the `end` section")
    candidates: list[Mapping[str, object]] = []
    for key in ("sum_received", "sum", "sum_sent"):
        value = end.get(key)
        if isinstance(value, Mapping):
            candidates.append(value)
    selected = next((item for item in candidates if "packets" in item), None)
    if selected is None:
        raise RuntimeError("iperf3 JSON does not expose UDP packet counters")
    seconds = float(selected.get("seconds", 0.0) or 0.0)
    packets = int(selected.get("packets", 0) or 0)
    return {
        "packets": packets,
        "seconds": seconds,
        "pps": (packets / seconds) if seconds > 0 else None,
        "bits_per_second": float(selected.get("bits_per_second", 0.0) or 0.0),
        "bytes": int(selected.get("bytes", 0) or 0),
        "lost_packets": int(selected.get("lost_packets", 0) or 0),
        "lost_percent": float(selected.get("lost_percent", 0.0) or 0.0),
        "jitter_ms": float(selected.get("jitter_ms", 0.0) or 0.0),
        "source": str(selected.get("source", "unknown")) if "source" in selected else None,
        "sender": bool(selected.get("sender", False)),
    }


def extract_client_brief(payload: Mapping[str, object]) -> dict[str, object]:
    start = payload.get("start") if isinstance(payload.get("start"), Mapping) else {}
    end = payload.get("end") if isinstance(payload.get("end"), Mapping) else {}
    test_start = start.get("test_start") if isinstance(start.get("test_start"), Mapping) else {}
    cpu = end.get("cpu_utilization_percent") if isinstance(end.get("cpu_utilization_percent"), Mapping) else {}
    return {
        "protocol": test_start.get("protocol"),
        "duration_s": test_start.get("duration"),
        "parallel_streams": test_start.get("num_streams"),
        "blksize": test_start.get("blksize"),
        "omit": test_start.get("omit"),
        "sender_cpu_utilization_pct": cpu.get("host_total"),
        "remote_cpu_utilization_pct": cpu.get("remote_total"),
    }


def probe_tools(bpftool_binary: str | None = None) -> dict[str, object]:
    if bpftool_binary:
        candidate = str(bpftool_binary)
        resolved_bpftool = str(Path(candidate).resolve()) if Path(candidate).exists() else which(candidate)
    else:
        resolved_bpftool = resolve_bpftool_binary()
    return {
        "ip": which("ip"),
        "bpftool": resolved_bpftool,
        "iperf3": which("iperf3"),
        "nping": which("nping"),
        "ping": which("ping"),
        "sysctl": which("sysctl"),
    }


def ensure_runtime_prerequisites(
    object_path: Path,
    scanner_binary: Path,
    bpftool_binary: str,
    tools: Mapping[str, object],
) -> None:
    if not object_path.exists():
        raise RuntimeError(f"XDP object not found: {object_path}")
    if not scanner_binary.exists():
        raise RuntimeError(f"bpf-jit-scanner not found: {scanner_binary}")
    if not Path(bpftool_binary).exists() and which(bpftool_binary) is None:
        raise RuntimeError(f"bpftool is required but not found: {bpftool_binary}")
    for required in ("ip", "iperf3", "sysctl"):
        if not tools.get(required):
            raise RuntimeError(f"{required} is required for the xdp_forwarding benchmark")


class XdpForwardingSession:
    def __init__(
        self,
        *,
        topology: Topology,
        topology_mode: str,
        object_path: Path,
        program_name: str,
        attach_type: str,
        bpftool_binary: str,
    ) -> None:
        self.topology = topology
        self.topology_mode = topology_mode
        self.object_path = object_path
        self.program_name = program_name
        self.attach_type = attach_type
        self.bpftool_binary = bpftool_binary
        self.pin_root = Path("/sys/fs/bpf") / topology.run_id
        self.prog_pin_dir = self.pin_root / "progs"
        self.map_pin_dir = self.pin_root / "maps"
        self.program_pin_path = self.prog_pin_dir / program_name
        self.map_pin_path = self.map_pin_dir / "xdp_tx_ports"
        self.program_info: dict[str, object] = {}
        self.original_sysctls: dict[tuple[str | None, str], str] = {}

    def __enter__(self) -> "XdpForwardingSession":
        try:
            self.create_topology()
            self.configure_router()
            self.load_program()
            self.attach_program()
        except Exception:
            self.cleanup()
            raise
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.cleanup()

    @property
    def program_id(self) -> int:
        return int(self.program_info.get("id", 0) or 0)

    def record_sysctl(self, key: str, *, netns: str | None = None) -> None:
        handle = (netns, key)
        if handle not in self.original_sysctls:
            self.original_sysctls[handle] = sysctl_get(key, netns=netns)

    def create_topology(self) -> None:
        run_command(["ip", "netns", "add", self.topology.source_ns], timeout=20)
        run_command(["ip", "netns", "add", self.topology.sink_ns], timeout=20)
        if self.topology_mode == "preexisting":
            self._prepare_preexisting_topology()
        else:
            self._create_veth_topology()

        run_command(["ip", "link", "set", "dev", self.topology.router_left_if, "up"], timeout=20)
        run_command(["ip", "link", "set", "dev", self.topology.router_right_if, "up"], timeout=20)
        run_command(
            ["ip", "addr", "replace", self.topology.router_left_ip, "dev", self.topology.router_left_if],
            timeout=20,
        )
        run_command(
            ["ip", "addr", "replace", self.topology.router_right_ip, "dev", self.topology.router_right_if],
            timeout=20,
        )

        for namespace in (self.topology.source_ns, self.topology.sink_ns):
            run_command(["ip", "netns", "exec", namespace, "ip", "link", "set", "dev", "lo", "up"], timeout=20)

        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.source_ns,
                "ip",
                "link",
                "set",
                "dev",
                self.topology.source_if,
                "up",
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.sink_ns,
                "ip",
                "link",
                "set",
                "dev",
                self.topology.sink_if,
                "up",
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.source_ns,
                "ip",
                "addr",
                "replace",
                self.topology.source_ip,
                "dev",
                self.topology.source_if,
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.sink_ns,
                "ip",
                "addr",
                "replace",
                self.topology.sink_ip,
                "dev",
                self.topology.sink_if,
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.source_ns,
                "ip",
                "route",
                "replace",
                "default",
                "via",
                self.topology.source_gateway,
                "dev",
                self.topology.source_if,
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.sink_ns,
                "ip",
                "route",
                "replace",
                "default",
                "via",
                self.topology.sink_gateway,
                "dev",
                self.topology.sink_if,
            ],
            timeout=20,
        )

    def _create_veth_topology(self) -> None:
        run_command(
            [
                "ip",
                "link",
                "add",
                self.topology.router_left_if,
                "type",
                "veth",
                "peer",
                "name",
                self.topology.source_if,
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "link",
                "add",
                self.topology.router_right_if,
                "type",
                "veth",
                "peer",
                "name",
                self.topology.sink_if,
            ],
            timeout=20,
        )
        run_command(
            ["ip", "link", "set", self.topology.source_if, "netns", self.topology.source_ns],
            timeout=20,
        )
        run_command(
            ["ip", "link", "set", self.topology.sink_if, "netns", self.topology.sink_ns],
            timeout=20,
        )

    def _prepare_preexisting_topology(self) -> None:
        for device in (
            self.topology.router_left_if,
            self.topology.source_if,
            self.topology.router_right_if,
            self.topology.sink_if,
        ):
            try:
                ip_link_details(device)
            except Exception as exc:
                raise RuntimeError(
                    f"preexisting topology requires root-netns interface {device!r}, but it was not found"
                ) from exc
        run_command(
            ["ip", "link", "set", self.topology.source_if, "netns", self.topology.source_ns],
            timeout=20,
        )
        run_command(
            ["ip", "link", "set", self.topology.sink_if, "netns", self.topology.sink_ns],
            timeout=20,
        )

    def configure_router(self) -> None:
        self.record_sysctl("net.ipv4.ip_forward")
        sysctl_set("net.ipv4.ip_forward", "1")

        source_link = ip_link_details(self.topology.source_if, netns=self.topology.source_ns)
        sink_link = ip_link_details(self.topology.sink_if, netns=self.topology.sink_ns)
        router_left_link = ip_link_details(self.topology.router_left_if)
        router_right_link = ip_link_details(self.topology.router_right_if)

        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.source_ns,
                "ip",
                "neigh",
                "replace",
                self.topology.source_gateway,
                "lladdr",
                str(router_left_link.get("address", "")),
                "dev",
                self.topology.source_if,
                "nud",
                "permanent",
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "neigh",
                "replace",
                self.topology.source_host,
                "lladdr",
                str(source_link.get("address", "")),
                "dev",
                self.topology.router_left_if,
                "nud",
                "permanent",
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "netns",
                "exec",
                self.topology.sink_ns,
                "ip",
                "neigh",
                "replace",
                self.topology.sink_gateway,
                "lladdr",
                str(router_right_link.get("address", "")),
                "dev",
                self.topology.sink_if,
                "nud",
                "permanent",
            ],
            timeout=20,
        )
        run_command(
            [
                "ip",
                "neigh",
                "replace",
                self.topology.sink_host,
                "lladdr",
                str(sink_link.get("address", "")),
                "dev",
                self.topology.router_right_if,
                "nud",
                "permanent",
            ],
            timeout=20,
        )

    def load_program(self) -> None:
        shutil.rmtree(self.pin_root, ignore_errors=True)
        self.prog_pin_dir.mkdir(parents=True, exist_ok=True)
        self.map_pin_dir.mkdir(parents=True, exist_ok=True)
        run_command(
            [
                self.bpftool_binary,
                "prog",
                "loadall",
                str(self.object_path),
                str(self.prog_pin_dir),
                "type",
                "xdp",
                "pinmaps",
                str(self.map_pin_dir),
            ],
            timeout=60,
        )
        if not self.program_pin_path.exists():
            available = sorted(path.name for path in self.prog_pin_dir.iterdir())
            raise RuntimeError(
                f"expected pinned program {self.program_name!r} under {self.prog_pin_dir}, found {available}"
            )
        if not self.map_pin_path.exists():
            raise RuntimeError(f"expected pinned devmap at {self.map_pin_path}")

        left_ifindex = int(ip_link_details(self.topology.router_left_if).get("ifindex", 0) or 0)
        right_ifindex = int(ip_link_details(self.topology.router_right_if).get("ifindex", 0) or 0)
        for ifindex in (left_ifindex, right_ifindex):
            run_command(
                [
                    self.bpftool_binary,
                    "map",
                    "update",
                    "pinned",
                    str(self.map_pin_path),
                    "key",
                    "hex",
                    *render_hex_u32(ifindex),
                    "value",
                    "hex",
                    *render_hex_u32(ifindex),
                ],
                timeout=20,
            )

        self.program_info = bpftool_prog_show(self.bpftool_binary, self.program_pin_path)

    def attach_program(self) -> None:
        for device in (self.topology.router_left_if, self.topology.router_right_if):
            run_command(
                [
                    self.bpftool_binary,
                    "net",
                    "attach",
                    self.attach_type,
                    "pinned",
                    str(self.program_pin_path),
                    "dev",
                    device,
                    "overwrite",
                ],
                timeout=30,
            )

    def snapshot(self) -> dict[str, object]:
        source_link = ip_link_details(self.topology.source_if, netns=self.topology.source_ns)
        sink_link = ip_link_details(self.topology.sink_if, netns=self.topology.sink_ns)
        router_left_link = ip_link_details(self.topology.router_left_if)
        router_right_link = ip_link_details(self.topology.router_right_if)
        return {
            "topology": asdict(self.topology),
            "pinned_program": str(self.program_pin_path),
            "pinned_map": str(self.map_pin_path),
            "program": dict(self.program_info),
            "interfaces": {
                self.topology.source_if: {
                    "netns": self.topology.source_ns,
                    "ifindex": source_link.get("ifindex"),
                    "mac": source_link.get("address"),
                    "addr": self.topology.source_ip,
                },
                self.topology.router_left_if: {
                    "netns": "root",
                    "ifindex": router_left_link.get("ifindex"),
                    "mac": router_left_link.get("address"),
                    "addr": self.topology.router_left_ip,
                },
                self.topology.router_right_if: {
                    "netns": "root",
                    "ifindex": router_right_link.get("ifindex"),
                    "mac": router_right_link.get("address"),
                    "addr": self.topology.router_right_ip,
                },
                self.topology.sink_if: {
                    "netns": self.topology.sink_ns,
                    "ifindex": sink_link.get("ifindex"),
                    "mac": sink_link.get("address"),
                    "addr": self.topology.sink_ip,
                },
            },
        }

    def cleanup(self) -> None:
        for device in (self.topology.router_left_if, self.topology.router_right_if):
            run_command(
                [self.bpftool_binary, "net", "detach", self.attach_type, "dev", device],
                check=False,
                timeout=15,
            )
        if self.topology_mode == "preexisting":
            for device in (self.topology.router_left_if, self.topology.router_right_if):
                run_command(["ip", "addr", "flush", "dev", device], check=False, timeout=15)
                run_command(["ip", "link", "set", "dev", device, "down"], check=False, timeout=15)
        else:
            run_command(["ip", "link", "del", self.topology.router_left_if], check=False, timeout=15)
            run_command(["ip", "link", "del", self.topology.router_right_if], check=False, timeout=15)
        run_command(["ip", "netns", "del", self.topology.source_ns], check=False, timeout=15)
        run_command(["ip", "netns", "del", self.topology.sink_ns], check=False, timeout=15)
        if self.topology_mode == "preexisting":
            for device in (self.topology.source_if, self.topology.sink_if):
                run_command(["ip", "addr", "flush", "dev", device], check=False, timeout=15)
                run_command(["ip", "link", "set", "dev", device, "down"], check=False, timeout=15)
        for (netns, key), value in reversed(list(self.original_sysctls.items())):
            try:
                sysctl_set(key, value, netns=netns)
            except Exception:
                continue
        shutil.rmtree(self.pin_root, ignore_errors=True)


def maybe_warmup_path(topology: Topology) -> dict[str, object]:
    ping = which("ping")
    if ping is None:
        return {"attempted": False, "available": False, "returncode": None}
    completed = run_command(
        [
            "ip",
            "netns",
            "exec",
            topology.source_ns,
            ping,
            "-c",
            "2",
            "-W",
            "1",
            topology.sink_host,
        ],
        check=False,
        timeout=10,
    )
    return {
        "attempted": True,
        "available": True,
        "returncode": completed.returncode,
        "stdout_tail": tail_text(completed.stdout or ""),
        "stderr_tail": tail_text(completed.stderr or ""),
    }


def terminate_process(proc: subprocess.Popen[str], *, timeout: float = 3.0) -> tuple[str, str]:
    if proc.poll() is None:
        proc.terminate()
        try:
            stdout, stderr = proc.communicate(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.kill()
            stdout, stderr = proc.communicate(timeout=timeout)
        return stdout, stderr
    return proc.communicate(timeout=timeout)


def run_iperf_measurement(
    topology: Topology,
    *,
    duration_s: int,
    packet_size: int,
    parallel_streams: int,
    port: int,
) -> dict[str, object]:
    server_command = [
        "ip",
        "netns",
        "exec",
        topology.sink_ns,
        "iperf3",
        "-s",
        "-1",
        "-p",
        str(port),
        "-J",
    ]
    client_command = [
        "ip",
        "netns",
        "exec",
        topology.source_ns,
        "iperf3",
        "-c",
        topology.sink_host,
        "-p",
        str(port),
        "-u",
        "-b",
        "0",
        "-l",
        str(packet_size),
        "-P",
        str(parallel_streams),
        "-t",
        str(duration_s),
        "-J",
    ]

    server = subprocess.Popen(
        server_command,
        cwd=ROOT_DIR,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    server_stdout = ""
    server_stderr = ""
    try:
        time.sleep(1.0)
        client_completed = run_command(client_command, timeout=max(30, duration_s + 30))
        try:
            server_stdout, server_stderr = server.communicate(timeout=max(30, duration_s + 30))
        except subprocess.TimeoutExpired:
            server_stdout, server_stderr = terminate_process(server, timeout=5.0)
    except Exception:
        if server.poll() is None:
            server_stdout, server_stderr = terminate_process(server, timeout=5.0)
        raise

    client_json = parse_json_output(client_completed.stdout, context="iperf3 client")
    server_json = parse_json_output(server_stdout, context="iperf3 server")
    receiver = extract_iperf_udp_summary(server_json)
    sender = extract_iperf_udp_summary(client_json)
    return {
        "port": port,
        "packet_size_bytes": packet_size,
        "parallel_streams": parallel_streams,
        "sender": sender,
        "receiver": receiver,
        "client": extract_client_brief(client_json),
        "server_returncode": int(server.returncode or 0),
        "client_command": client_command,
        "server_command": server_command,
        "client_stdout_tail": tail_text(client_completed.stdout or ""),
        "client_stderr_tail": tail_text(client_completed.stderr or ""),
        "server_stdout_tail": tail_text(server_stdout or "", max_lines=40),
        "server_stderr_tail": tail_text(server_stderr or "", max_lines=40),
    }


def run_phase(
    label: str,
    topology: Topology,
    prog_ids: Sequence[int],
    *,
    duration_s: int,
    packet_size: int,
    parallel_streams: int,
    port: int,
) -> dict[str, object]:
    warmup = maybe_warmup_path(topology)
    before = sample_bpf_stats(list(prog_ids))
    measurement = run_iperf_measurement(
        topology,
        duration_s=duration_s,
        packet_size=packet_size,
        parallel_streams=parallel_streams,
        port=port,
    )
    after = sample_bpf_stats(list(prog_ids))
    return {
        "label": label,
        "duration_s": duration_s,
        "warmup": warmup,
        "measurement": measurement,
        "bpf_stats_before": before,
        "bpf_stats_after": after,
        "bpf_delta": compute_delta(before, after),
        "pps": {
            "sender_pps": measurement["sender"].get("pps"),
            "receiver_pps": measurement["receiver"].get("pps"),
            "receiver_lost_percent": measurement["receiver"].get("lost_percent"),
            "receiver_bits_per_second": measurement["receiver"].get("bits_per_second"),
        },
    }


def compare_phases(baseline: Mapping[str, object] | None, post: Mapping[str, object] | None) -> dict[str, object] | None:
    if baseline is None or post is None:
        return None
    baseline_pps = ((baseline.get("pps") or {}).get("receiver_pps")) if isinstance(baseline.get("pps"), Mapping) else None
    post_pps = ((post.get("pps") or {}).get("receiver_pps")) if isinstance(post.get("pps"), Mapping) else None
    baseline_bps = (
        (baseline.get("pps") or {}).get("receiver_bits_per_second")
        if isinstance(baseline.get("pps"), Mapping)
        else None
    )
    post_bps = (
        (post.get("pps") or {}).get("receiver_bits_per_second")
        if isinstance(post.get("pps"), Mapping)
        else None
    )
    return {
        "baseline_receiver_pps": baseline_pps,
        "post_rejit_receiver_pps": post_pps,
        "receiver_pps_speedup_ratio": (float(post_pps) / float(baseline_pps))
        if baseline_pps not in (None, 0) and post_pps is not None
        else None,
        "receiver_pps_delta_pct": percent_delta(baseline_pps, post_pps),
        "baseline_receiver_bps": baseline_bps,
        "post_rejit_receiver_bps": post_bps,
        "receiver_bps_speedup_ratio": (float(post_bps) / float(baseline_bps))
        if baseline_bps not in (None, 0) and post_bps is not None
        else None,
        "receiver_bps_delta_pct": percent_delta(baseline_bps, post_bps),
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# XDP Forwarding E2E Results",
        "",
        f"- Generated at: `{payload.get('generated_at', 'unknown')}`",
        f"- Mode: `{payload.get('mode', 'unknown')}`",
        f"- Status: `{payload.get('status', 'unknown')}`",
        f"- XDP object: `{payload.get('xdp_object', 'unknown')}`",
        f"- Program: `{payload.get('xdp_program', 'unknown')}`",
        f"- Attach type: `{payload.get('attach_type', 'unknown')}`",
        f"- Topology mode: `{payload.get('topology_mode', 'unknown')}`",
        f"- Duration: `{payload.get('duration_s', 'unknown')}` s",
    ]
    comparison = payload.get("comparison")
    if isinstance(comparison, Mapping):
        lines.extend(
            [
                "",
                "## PPS Comparison",
                "",
                f"- Baseline receiver PPS: `{comparison.get('baseline_receiver_pps')}`",
                f"- Post-ReJIT receiver PPS: `{comparison.get('post_rejit_receiver_pps')}`",
                f"- Improvement: `{comparison.get('receiver_pps_delta_pct')}` %",
            ]
        )
    failure = payload.get("failure")
    if isinstance(failure, Mapping):
        lines.extend(
            [
                "",
                "## Failure",
                "",
                f"- Type: `{failure.get('type', 'unknown')}`",
                f"- Message: `{failure.get('message', 'unknown')}`",
            ]
        )
    limitations = payload.get("limitations")
    if isinstance(limitations, list) and limitations:
        lines.extend(["", "## Limitations", ""])
        for item in limitations:
            lines.append(f"- {item}")
    return "\n".join(lines) + "\n"


def persist_results(payload: Mapping[str, object], output_json: Path, output_md: Path) -> None:
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the XDP forwarding dataplane end-to-end benchmark.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--xdp-object", default=str(DEFAULT_XDP_OBJECT))
    parser.add_argument("--xdp-program", default=DEFAULT_PROGRAM_NAME)
    parser.add_argument("--attach-type", choices=("xdp", "xdpgeneric", "xdpdrv"), default=DEFAULT_ATTACH_TYPE)
    parser.add_argument("--topology-mode", choices=("veth", "preexisting"), default=DEFAULT_TOPOLOGY_MODE)
    parser.add_argument("--source-if")
    parser.add_argument("--sink-if")
    parser.add_argument("--router-left-if")
    parser.add_argument("--router-right-if")
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER))
    parser.add_argument("--bpftool-binary", default=DEFAULT_BPFTOOL)
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--packet-size", type=int, default=DEFAULT_PACKET_SIZE)
    parser.add_argument("--parallel-streams", type=int, default=DEFAULT_PARALLEL_STREAMS)
    parser.add_argument("--server-port", type=int, default=DEFAULT_SERVER_PORT)
    return parser


def dry_run_payload(
    args: argparse.Namespace,
    *,
    duration_s: int,
    object_path: Path,
    scanner_binary: Path,
    bpftool_binary: str,
    tools: Mapping[str, object],
    topology: Topology,
) -> dict[str, object]:
    policy_files = resolve_policy_files(
        [
            PolicyTarget(
                prog_id=1,
                object_path=object_path,
                program_name=args.xdp_program,
            )
        ]
    )
    notes: list[str] = []
    if tools.get("iperf3") is None:
        notes.append("`iperf3` is not available; a real run will fail until it is installed inside the host or virtme guest.")
    if tools.get("ip") is None:
        notes.append("`iproute2` is not available; namespace and veth setup cannot proceed.")
    if tools.get("bpftool") is None:
        notes.append("`bpftool` is not available; the case cannot load, pin, or attach the XDP object.")
    if not object_path.exists():
        notes.append("The default XDP forwarding object is missing.")
    if not scanner_binary.exists():
        notes.append("The scanner binary is missing; recompile cannot run.")
    if args.topology_mode == "preexisting":
        notes.append(
            "The preexisting topology mode expects four pre-provisioned interfaces (for example, eth0/eth1/eth2/eth3 from two `vng --network loop` pairs)."
        )
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "dry-run",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "xdp_object": str(object_path),
        "xdp_program": args.xdp_program,
        "attach_type": args.attach_type,
        "topology_mode": args.topology_mode,
        "packet_size": int(args.packet_size),
        "parallel_streams": int(args.parallel_streams),
        "server_port": int(args.server_port),
        "host": host_metadata(),
        "tooling": dict(tools),
        "scanner": str(scanner_binary),
        "bpftool_binary": bpftool_binary,
        "topology_plan": asdict(topology),
        "policy_matches": {str(key): value for key, value in policy_files.items()},
        "notes": notes,
        "setup_requirements": (
            [
                "Run inside a framework-kernel virtme-ng guest for actual BPF_PROG_JIT_RECOMPILE measurements.",
                "Launch the guest with two `vng --network loop` links (or another four-interface topology) before using `--topology-mode preexisting`.",
                "The case moves the endpoint interfaces into two netns instances, configures the remaining two interfaces as the root router, enables IPv4 forwarding, pins the XDP object under /sys/fs/bpf, and updates the xdp_tx_ports devmap.",
            ]
            if args.topology_mode == "preexisting"
            else [
                "Run inside a framework-kernel virtme-ng guest for actual BPF_PROG_JIT_RECOMPILE measurements.",
                "The guest needs `ip`, `bpftool`, `iperf3`, and the built `scanner/build/bpf-jit-scanner`.",
                "The case creates two netns endpoints plus two router-side veth interfaces, enables IPv4 forwarding, pins the XDP object under /sys/fs/bpf, and updates the xdp_tx_ports devmap.",
            ]
        ),
    }


def run_xdp_forwarding_case(args: argparse.Namespace) -> dict[str, object]:
    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
    topology_mode = str(args.topology_mode)
    if topology_mode == "preexisting":
        missing = [
            option
            for option, value in (
                ("--source-if", args.source_if),
                ("--sink-if", args.sink_if),
                ("--router-left-if", args.router_left_if),
                ("--router-right-if", args.router_right_if),
            )
            if not value
        ]
        if missing:
            raise RuntimeError(f"preexisting topology mode requires {', '.join(missing)}")
    topology = build_topology(
        source_if=args.source_if,
        sink_if=args.sink_if,
        router_left_if=args.router_left_if,
        router_right_if=args.router_right_if,
    )
    object_path = Path(args.xdp_object).resolve()
    scanner_binary = Path(args.scanner).resolve()
    bpftool_binary = (
        str(Path(args.bpftool_binary).resolve())
        if Path(args.bpftool_binary).exists()
        else (which(str(args.bpftool_binary)) or str(args.bpftool_binary))
    )
    tools = probe_tools(bpftool_binary)

    if args.dry_run:
        return dry_run_payload(
            args,
            duration_s=duration_s,
            object_path=object_path,
            scanner_binary=scanner_binary,
            bpftool_binary=bpftool_binary,
            tools=tools,
            topology=topology,
        )

    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])
    ensure_runtime_prerequisites(object_path, scanner_binary, bpftool_binary, tools)

    limitations: list[str] = []
    baseline: dict[str, object] | None = None
    post: dict[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    recompile_results: dict[int, dict[str, object]] = {}
    session_snapshot: dict[str, object] = {}
    policy_matches: dict[int, str] = {}
    failure: dict[str, object] | None = None

    if topology_mode == "preexisting":
        limitations.append(
            "This VM run used pre-provisioned virtio loop NIC pairs instead of guest-created veth pairs because the framework kernel is built without veth support (`CONFIG_VETH` is not set in `vendor/linux-framework/.config`)."
        )

    try:
        with enable_bpf_stats():
            with XdpForwardingSession(
                topology=topology,
                topology_mode=topology_mode,
                object_path=object_path,
                program_name=args.xdp_program,
                attach_type=args.attach_type,
                bpftool_binary=bpftool_binary,
            ) as session:
                session_snapshot = session.snapshot()
                prog_ids = [session.program_id]
                policy_matches = resolve_policy_files(
                    [
                        PolicyTarget(
                            prog_id=session.program_id,
                            object_path=object_path,
                            program_name=str(session.program_info.get("name", args.xdp_program)),
                        )
                    ]
                )
                baseline = run_phase(
                    "stock",
                    topology,
                    prog_ids,
                    duration_s=duration_s,
                    packet_size=int(args.packet_size),
                    parallel_streams=int(args.parallel_streams),
                    port=int(args.server_port),
                )
                scan_results = scan_programs(prog_ids, scanner_binary)
                recompile_results = apply_recompile(
                    prog_ids,
                    scanner_binary,
                    policy_files=policy_matches,
                )
                applied = sum(1 for record in recompile_results.values() if record.get("applied"))
                if applied == 0:
                    limitations.append(
                        "BPF_PROG_JIT_RECOMPILE did not apply on this kernel; the post-ReJIT PPS phase was skipped."
                    )
                else:
                    post = run_phase(
                        "bpfrejit",
                        topology,
                        prog_ids,
                        duration_s=duration_s,
                        packet_size=int(args.packet_size),
                        parallel_streams=int(args.parallel_streams),
                        port=int(args.server_port),
                    )
    except Exception as exc:
        failure = {
            "type": exc.__class__.__name__,
            "message": str(exc),
            "traceback_tail": tail_text(traceback.format_exc(), max_lines=40, max_chars=12000),
        }
        limitations.append(f"Live XDP forwarding benchmark failed: {exc}")

    status = "failed" if failure else ("partial" if baseline is None or post is None else "ok")
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "xdp_forwarding",
        "status": status,
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "xdp_object": str(object_path),
        "xdp_program": args.xdp_program,
        "attach_type": args.attach_type,
        "topology_mode": topology_mode,
        "packet_size": int(args.packet_size),
        "parallel_streams": int(args.parallel_streams),
        "server_port": int(args.server_port),
        "host": host_metadata(),
        "tooling": dict(tools),
        "scanner": str(scanner_binary),
        "bpftool_binary": bpftool_binary,
        "session": session_snapshot,
        "baseline": baseline,
        "policy_matches": {str(key): value for key, value in policy_matches.items()},
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "recompile_results": {str(key): value for key, value in recompile_results.items()},
        "post_rejit": post,
        "comparison": compare_phases(baseline, post),
        "failure": failure,
        "limitations": limitations,
    }
    return payload


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_xdp_forwarding_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "xdp_forwarding")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve())
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
