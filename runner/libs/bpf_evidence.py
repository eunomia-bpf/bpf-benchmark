from __future__ import annotations

import json
import re
import subprocess
import time
from collections import Counter, deque
from pathlib import Path
from typing import Mapping, Sequence

from . import resolve_bpftool_binary


_MAP_SNAPSHOT_ATTEMPTS = 120
_MAP_SNAPSHOT_RETRY_SECONDS = 0.1
_NATIVE_REPLACEMENT_RE = re.compile(
    r"\bnative-loader replaced\b.*?\bnative_id=(\d+)\b.*?\bsymbol=([A-Za-z0-9_.$]+)\b"
)


def native_program_name_overrides(log_path: Path) -> dict[int, str]:
    """Return the native program ID to full ELF symbol mapping from a shim log."""
    overrides: dict[int, str] = {}
    for match in _NATIVE_REPLACEMENT_RE.finditer(log_path.read_text(encoding="utf-8")):
        program_id = int(match.group(1))
        symbol = match.group(2)
        previous = overrides.get(program_id)
        if previous is not None and previous != symbol:
            raise RuntimeError(
                f"native program {program_id} has conflicting symbols in {log_path}: "
                f"{previous!r} and {symbol!r}"
            )
        overrides[program_id] = symbol
    if not overrides:
        raise RuntimeError(f"no native-loader replacement records found in {log_path}")
    return overrides


def _wait_native_program_name_overrides(
    log_path: Path, required_program_ids: Sequence[int]
) -> dict[int, str]:
    required = {int(program_id) for program_id in required_program_ids}
    missing = sorted(required)
    for _attempt in range(_MAP_SNAPSHOT_ATTEMPTS):
        try:
            overrides = native_program_name_overrides(log_path)
        except RuntimeError as exc:
            if "no native-loader replacement records found" not in str(exc):
                raise
            time.sleep(_MAP_SNAPSHOT_RETRY_SECONDS)
            continue
        missing = sorted(required - overrides.keys())
        if not missing:
            return overrides
        time.sleep(_MAP_SNAPSHOT_RETRY_SECONDS)
    raise RuntimeError(
        f"native-loader log {log_path} did not publish symbols for live programs {missing}"
    )


def _safe_name(value: str) -> str:
    return re.sub(r"[^A-Za-z0-9_.-]+", "_", value).strip("_") or "app"


def _capture(command: Sequence[str]) -> dict[str, object]:
    completed = subprocess.run(command, check=False, capture_output=True, text=True)
    return {
        "command": [str(part) for part in command],
        "returncode": int(completed.returncode),
        "stdout": completed.stdout,
        "stderr": completed.stderr,
    }


def _write_capture(path: Path, command: Sequence[str]) -> dict[str, object]:
    record = _capture(command)
    path.write_text(str(record["stdout"]), encoding="utf-8")
    path.with_suffix(path.suffix + ".stderr").write_text(
        str(record["stderr"]), encoding="utf-8"
    )
    return {"command": record["command"], "returncode": record["returncode"]}


def _write_binary_dump(path: Path, command: Sequence[str]) -> dict[str, object]:
    full_command = [str(part) for part in command] + ["file", str(path)]
    completed = subprocess.run(full_command, check=False, capture_output=True, text=True)
    path.with_suffix(path.suffix + ".stderr").write_text(
        completed.stderr, encoding="utf-8"
    )
    return {"command": full_command, "returncode": int(completed.returncode)}


def _json_payload(command: Sequence[str]) -> object:
    completed = subprocess.run(command, check=True, capture_output=True, text=True)
    return json.loads(completed.stdout)


def _map_inventory(bpftool: str) -> list[dict[str, object]]:
    payload = _json_payload([bpftool, "-j", "map", "show"])
    return [
        dict(record)
        for record in (payload if isinstance(payload, list) else [])
        if isinstance(record, Mapping) and int(record.get("id", 0) or 0) > 0
    ]


def _program_arrays(
    inventory: Sequence[Mapping[str, object]],
) -> list[dict[str, object]]:
    return [dict(record) for record in inventory if str(record.get("type") or "") == "prog_array"]


def _program_array_identity(
    inventory: Sequence[Mapping[str, object]],
) -> list[tuple[int, str]]:
    return sorted(
        (int(record["id"]), str(record.get("name") or ""))
        for record in _program_arrays(inventory)
    )


def _dump_program_arrays(
    bpftool: str,
    inventory: Sequence[Mapping[str, object]],
) -> dict[int, object]:
    return {
        int(record["id"]): _json_payload(
            [bpftool, "-j", "map", "dump", "id", str(int(record["id"]))]
        )
        for record in _program_arrays(inventory)
    }


def _stable_map_snapshot(bpftool: str) -> tuple[list[dict[str, object]], dict[int, object]]:
    last_error: Exception | None = None
    for _attempt in range(_MAP_SNAPSHOT_ATTEMPTS):
        try:
            before = _map_inventory(bpftool)
            before_dumps = _dump_program_arrays(bpftool, before)
            middle = _map_inventory(bpftool)
            if _program_array_identity(before) != _program_array_identity(middle):
                time.sleep(_MAP_SNAPSHOT_RETRY_SECONDS)
                continue
            after_dumps = _dump_program_arrays(bpftool, middle)
            after = _map_inventory(bpftool)
            if (
                _program_array_identity(middle) == _program_array_identity(after)
                and before_dumps == after_dumps
            ):
                return after, after_dumps
        except (subprocess.CalledProcessError, json.JSONDecodeError) as exc:
            last_error = exc
        time.sleep(_MAP_SNAPSHOT_RETRY_SECONDS)
    detail = f": {last_error}" if last_error is not None else ""
    raise RuntimeError(
        f"BPF prog_array maps did not stabilize after {_MAP_SNAPSHOT_ATTEMPTS} read-only snapshots{detail}"
    )


def _byte_array_u32(value: object) -> int:
    if not isinstance(value, list) or len(value) != 4:
        raise RuntimeError(f"unexpected bpftool prog-array value: {value!r}")
    return int.from_bytes(bytes(int(str(item), 16) for item in value), "little")


def _live_program_graph(
    inventory: Sequence[Mapping[str, object]],
    map_inventory: Sequence[Mapping[str, object]],
    program_array_payloads: Mapping[int, object],
    links: Sequence[Mapping[str, object]],
    program_name_overrides: Mapping[int, str] | None = None,
) -> dict[str, object]:
    programs = {int(record["id"]): dict(record) for record in inventory}
    canonical_names: dict[int, str] = {}
    for program_id, symbol in (program_name_overrides or {}).items():
        if program_id not in programs:
            continue
        kernel_name = str(programs[program_id].get("name") or "")
        if kernel_name != symbol[:15]:
            raise RuntimeError(
                f"native program {program_id} kernel name {kernel_name!r} is not the "
                f"15-byte truncation of loader symbol {symbol!r}"
            )
        canonical_names[program_id] = symbol

    def program_name(program_id: int) -> str:
        return canonical_names.get(
            program_id, str(programs[program_id].get("name") or "")
        )

    maps = {int(record["id"]): dict(record) for record in map_inventory}
    root_links = [
        dict(record)
        for record in links
        if str(record.get("type") or "") in {"xdp", "tcx"}
        and int(record.get("prog_id", 0) or 0) > 0
    ]
    root_ids = {int(record["prog_id"]) for record in root_links}
    missing_roots = sorted(root_ids - programs.keys())
    if missing_roots:
        raise RuntimeError(f"attached BPF programs vanished during evidence capture: {missing_roots}")

    reachable = set(root_ids)
    pending = deque(sorted(root_ids))
    tail_edges: list[dict[str, object]] = []
    while pending:
        program_id = pending.popleft()
        for map_id in programs[program_id].get("map_ids", []):
            numeric_map_id = int(map_id)
            payload = program_array_payloads.get(numeric_map_id)
            if not isinstance(payload, list):
                continue
            for item in payload:
                if not isinstance(item, Mapping):
                    raise RuntimeError(f"unexpected bpftool prog-array entry: {item!r}")
                child_id = _byte_array_u32(item.get("value"))
                if child_id <= 0:
                    continue
                if child_id not in programs:
                    raise RuntimeError(
                        f"prog-array map {numeric_map_id} references missing program {child_id}"
                    )
                tail_edges.append(
                    {
                        "map_id": numeric_map_id,
                        "map_name": str(maps.get(numeric_map_id, {}).get("name") or ""),
                        "key": _byte_array_u32(item.get("key")),
                        "program_id": child_id,
                        "program_name": program_name(child_id),
                    }
                )
                if child_id not in reachable:
                    reachable.add(child_id)
                    pending.append(child_id)

    live_programs = []
    for program_id in sorted(reachable):
        record = dict(programs[program_id])
        if program_id in canonical_names:
            record["kernel_name"] = str(record.get("name") or "")
            record["name"] = canonical_names[program_id]
        live_programs.append(record)
    inventory_signature = Counter(
        (str(record.get("type") or ""), str(record.get("name") or ""))
        for record in live_programs
    )
    attachment_signature = [
        {
            "type": str(link.get("type") or ""),
            "device": str(link.get("devname") or ""),
            "attach_type": str(link.get("attach_type") or link.get("type") or ""),
            "program_type": str(programs[int(link["prog_id"])].get("type") or ""),
            "program_name": program_name(int(link["prog_id"])),
        }
        for link in root_links
    ]
    attachment_signature.sort(
        key=lambda item: (
            item["device"], item["attach_type"], item["program_type"], item["program_name"]
        )
    )
    return {
        "root_program_ids": sorted(root_ids),
        "live_program_ids": sorted(reachable),
        "live_programs": live_programs,
        "inventory_signature": [
            {"type": type_name, "name": name, "count": count}
            for (type_name, name), count in sorted(inventory_signature.items())
        ],
        "attachment_signature": attachment_signature,
        "tail_call_edges": sorted(
            tail_edges,
            key=lambda edge: (
                str(edge["map_name"]), int(edge["key"]), str(edge["program_name"]),
                int(edge["map_id"]), int(edge["program_id"]),
            ),
        ),
        "canonical_name_overrides": {
            str(program_id): canonical_names[program_id]
            for program_id in sorted(canonical_names)
        },
    }


def capture_bpf_evidence(
    *,
    output_root: Path,
    app_name: str,
    phase: str,
    program_ids: Sequence[int],
    program_name_log: Path | None = None,
) -> Path:
    output_dir = output_root / _safe_name(app_name) / _safe_name(phase)
    output_dir.mkdir(parents=True, exist_ok=True)
    bpftool = resolve_bpftool_binary()
    selected_ids = sorted({int(program_id) for program_id in program_ids if int(program_id) > 0})
    map_inventory, stable_program_array_payloads = _stable_map_snapshot(bpftool)
    all_programs = _json_payload([bpftool, "-j", "prog", "show"])
    # The shim IDs identify the programs that are candidates for replacement,
    # but an application can deliberately attach auxiliary programs outside
    # the shim (for example Katran's peer-veth XDP_PASS program).  The runtime
    # container is dedicated to one application, so retain and dump the full
    # live inventory while separately recording the shim-tracked IDs.
    inventory = [
        dict(record)
        for record in (all_programs if isinstance(all_programs, list) else [])
        if isinstance(record, Mapping) and int(record.get("id", 0) or 0) > 0
    ]
    (output_dir / "program-inventory.json").write_text(
        json.dumps(inventory, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (output_dir / "map-inventory.json").write_text(
        json.dumps(map_inventory, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )

    program_array_dumps: dict[str, object] = {}
    for record in map_inventory:
        if str(record.get("type") or "") != "prog_array":
            continue
        map_id = int(record["id"])
        map_name = _safe_name(str(record.get("name") or "map"))
        filename = f"map-{map_id}-{map_name}.prog-array.json"
        payload = stable_program_array_payloads[map_id]
        (output_dir / filename).write_text(
            json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )
        program_array_dumps[str(map_id)] = {
            "name": str(record.get("name") or ""),
            "path": filename,
        }

    captures: dict[str, object] = {}
    link_command = [bpftool, "-j", "link", "show"]
    link_payload = _json_payload(link_command)
    if not isinstance(link_payload, list):
        raise RuntimeError("bpftool link show returned a non-list payload")
    (output_dir / "bpftool-link.json").write_text(
        json.dumps(link_payload, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    captures["bpftool-link"] = {"command": link_command, "returncode": 0}
    for label, command in {
        "bpftool-net": [bpftool, "-j", "net"],
        "ip-link": ["ip", "-details", "-statistics", "-j", "link", "show"],
    }.items():
        captures[label] = _write_capture(output_dir / f"{label}.json", command)

    raw_live_graph = _live_program_graph(
        inventory,
        map_inventory,
        stable_program_array_payloads,
        [record for record in link_payload if isinstance(record, Mapping)],
    )
    program_name_overrides = (
        _wait_native_program_name_overrides(
            program_name_log,
            [int(program_id) for program_id in raw_live_graph["live_program_ids"]],
        )
        if program_name_log is not None
        else {}
    )
    live_graph = _live_program_graph(
        inventory,
        map_inventory,
        stable_program_array_payloads,
        [record for record in link_payload if isinstance(record, Mapping)],
        program_name_overrides,
    )
    (output_dir / "live-program-graph.json").write_text(
        json.dumps(live_graph, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )

    links = _json_payload(["ip", "-j", "link", "show"])
    for link in links if isinstance(links, list) else []:
        if not isinstance(link, Mapping):
            continue
        iface = str(link.get("ifname") or "").split("@", 1)[0].strip()
        if not iface:
            continue
        for direction in ("ingress", "egress"):
            label = f"tc-{iface}-{direction}"
            captures[label] = _write_capture(
                output_dir / f"{_safe_name(label)}.json",
                ["tc", "-j", "filter", "show", "dev", iface, direction],
            )

    namespaces = _capture(["ip", "netns", "list"])
    (output_dir / "network-namespaces.txt").write_text(
        str(namespaces["stdout"]), encoding="utf-8"
    )
    for line in str(namespaces["stdout"]).splitlines():
        namespace = line.split(maxsplit=1)[0].strip()
        if not namespace:
            continue
        captures[f"ip-link-netns-{namespace}"] = _write_capture(
            output_dir / f"ip-link-netns-{_safe_name(namespace)}.json",
            ["ip", "netns", "exec", namespace, "ip", "-details", "-statistics", "-j", "link", "show"],
        )

    dumps: dict[str, object] = {}
    for record in inventory:
        program_id = int(record["id"])
        program_name = _safe_name(str(record.get("name") or "program"))
        stem = f"{program_id}-{program_name}"
        dumps[str(program_id)] = {
            "xlated": _write_capture(
                output_dir / f"{stem}.xlated.txt",
                [bpftool, "prog", "dump", "xlated", "id", str(program_id), "opcodes"],
            ),
            "jited": _write_binary_dump(
                output_dir / f"{stem}.jited.bin",
                [bpftool, "prog", "dump", "jited", "id", str(program_id)],
            ),
        }
    manifest = {
        "app": app_name,
        "phase": phase,
        "program_ids": selected_ids,
        "captures": captures,
        "program_dumps": dumps,
        "program_array_dumps": program_array_dumps,
        "program_name_overrides": {
            str(program_id): symbol
            for program_id, symbol in sorted((program_name_overrides or {}).items())
        },
    }
    (output_dir / "manifest.json").write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    return output_dir
