from __future__ import annotations

import json
import re
import subprocess
import time
from pathlib import Path
from typing import Mapping, Sequence

from . import resolve_bpftool_binary


_MAP_SNAPSHOT_ATTEMPTS = 120
_MAP_SNAPSHOT_RETRY_SECONDS = 0.1


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


def capture_bpf_evidence(
    *,
    output_root: Path,
    app_name: str,
    phase: str,
    program_ids: Sequence[int],
) -> Path:
    output_dir = output_root / _safe_name(app_name) / _safe_name(phase)
    output_dir.mkdir(parents=True, exist_ok=True)
    bpftool = resolve_bpftool_binary()
    selected_ids = sorted({int(program_id) for program_id in program_ids if int(program_id) > 0})
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
    map_inventory, stable_program_array_payloads = _stable_map_snapshot(bpftool)
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
    for label, command in {
        "bpftool-link": [bpftool, "-j", "link", "show"],
        "bpftool-net": [bpftool, "-j", "net"],
        "ip-link": ["ip", "-details", "-statistics", "-j", "link", "show"],
    }.items():
        captures[label] = _write_capture(output_dir / f"{label}.json", command)

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
    }
    (output_dir / "manifest.json").write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    return output_dir
