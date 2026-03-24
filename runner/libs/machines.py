from __future__ import annotations

from dataclasses import dataclass
import math
import os
from pathlib import Path
from typing import Any

import yaml

from . import ROOT_DIR


MACHINES_CONFIG = ROOT_DIR / "runner" / "machines.yaml"
VM_LOCK_ROOT = ROOT_DIR / ".cache" / "runner" / "vm-locks"
VM_QUEUE_ROOT = ROOT_DIR / ".cache" / "runner" / "vm-queue"
TARGET_ENV_VAR = "TARGET"


@dataclass(frozen=True)
class MachineSpec:
    name: str
    backend: str
    arch: str
    executable: str
    cpus: int | None
    memory: str | None
    lock_scope: str


def _host_cpu_count() -> int:
    return max(1, os.cpu_count() or 1)


def _host_total_memory_gib() -> int:
    meminfo = Path("/proc/meminfo")
    try:
        for line in meminfo.read_text().splitlines():
            if not line.startswith("MemTotal:"):
                continue
            parts = line.split()
            if len(parts) < 2:
                break
            total_kib = int(parts[1])
            return max(1, total_kib // (1024 * 1024))
    except (OSError, ValueError):
        pass

    try:
        page_size = os.sysconf("SC_PAGE_SIZE")
        phys_pages = os.sysconf("SC_PHYS_PAGES")
        total_bytes = int(page_size) * int(phys_pages)
        return max(1, total_bytes // (1024 ** 3))
    except (AttributeError, OSError, ValueError):
        return 4


def _resolve_cpu_count(entry: dict[str, Any], defaults: dict[str, Any]) -> int | None:
    if entry.get("cpus") is not None:
        return max(1, int(entry["cpus"]))

    ratio_value = entry.get("cpus_auto_ratio", defaults.get("cpus_auto_ratio"))
    if ratio_value is None:
        return None

    ratio = float(ratio_value)
    return max(1, math.floor(_host_cpu_count() * ratio))


def _resolve_memory(entry: dict[str, Any], defaults: dict[str, Any]) -> str | None:
    if entry.get("memory") is not None:
        return str(entry["memory"])

    ratio_value = entry.get("memory_auto_ratio", defaults.get("memory_auto_ratio"))
    if ratio_value is None:
        return None

    ratio = float(ratio_value)
    minimum_gib = int(entry.get("memory_min_gib", defaults.get("memory_min_gib", 1)))
    resolved_gib = max(minimum_gib, math.floor(_host_total_memory_gib() * ratio))
    return f"{resolved_gib}G"


def _load_config(path: Path = MACHINES_CONFIG) -> dict[str, Any]:
    data = yaml.safe_load(path.read_text())
    if not isinstance(data, dict):
        raise ValueError(f"invalid machines config: {path}")
    return data


def _resolve_target_name(
    *,
    target: str | None = None,
    action: str | None = None,
    path: Path = MACHINES_CONFIG,
) -> str:
    data = _load_config(path)
    aliases = data.get("aliases") or {}
    defaults = data.get("defaults") or {}
    default_targets = data.get("default_targets") or {}

    selected = (target or "").strip()
    if selected.lower() == "auto":
        selected = ""
    if not selected:
        selected = os.environ.get(TARGET_ENV_VAR, "").strip()
    if selected.lower() == "auto":
        selected = ""
    if not selected and action:
        selected = default_targets.get(action)
    if not selected:
        selected = defaults.get("target")
    if not isinstance(selected, str) or not selected:
        raise ValueError(f"unable to resolve machine target from {path}")
    return str(aliases.get(selected, selected))


def resolve_machine(
    *,
    target: str | None = None,
    action: str | None = None,
    path: Path = MACHINES_CONFIG,
) -> MachineSpec:
    data = _load_config(path)
    selected = _resolve_target_name(target=target, action=action, path=path)
    targets = data.get("targets") or {}
    entry = targets.get(selected)
    if not isinstance(entry, dict):
        raise ValueError(f"machine target not found: {selected}")
    defaults = data.get("defaults") or {}
    lock_scope = str(entry.get("lock_scope") or defaults.get("lock_scope") or selected)
    executable = str(entry.get("executable", "")).strip()
    if not executable:
        raise ValueError(f"machine target missing executable: {selected}")
    return MachineSpec(
        name=selected,
        backend=str(entry.get("backend", "")).strip(),
        arch=str(entry.get("arch", "")).strip(),
        executable=executable,
        cpus=_resolve_cpu_count(entry, defaults),
        memory=_resolve_memory(entry, defaults),
        lock_scope=lock_scope,
    )


def resolve_machine_executable(
    *,
    target: str | None = None,
    action: str | None = None,
    path: Path = MACHINES_CONFIG,
) -> Path:
    machine = resolve_machine(target=target, action=action, path=path)
    executable = Path(machine.executable)
    if executable.is_absolute():
        return executable
    return (ROOT_DIR / executable).resolve()


def lock_path_for_machine(
    *,
    target: str | None = None,
    action: str | None = None,
    path: Path = MACHINES_CONFIG,
) -> Path:
    machine = resolve_machine(target=target, action=action, path=path)
    VM_LOCK_ROOT.mkdir(parents=True, exist_ok=True)
    return VM_LOCK_ROOT / f"{machine.lock_scope}.lock"


def queue_path_for_machine(
    *,
    target: str | None = None,
    action: str | None = None,
    path: Path = MACHINES_CONFIG,
) -> Path:
    machine = resolve_machine(target=target, action=action, path=path)
    VM_QUEUE_ROOT.mkdir(parents=True, exist_ok=True)
    return VM_QUEUE_ROOT / f"{machine.lock_scope}.json"


__all__ = [
    "MACHINES_CONFIG",
    "MachineSpec",
    "VM_LOCK_ROOT",
    "VM_QUEUE_ROOT",
    "TARGET_ENV_VAR",
    "lock_path_for_machine",
    "queue_path_for_machine",
    "resolve_machine",
    "resolve_machine_executable",
]
