from __future__ import annotations

import platform
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

from . import ROOT_DIR, run_command


_KINSN_MODULE_ARCH_DIRS = {
    "x86_64": "x86",
    "aarch64": "arm64",
}


def relpath(path: Path | None) -> str | None:
    if path is None:
        return None
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


def expected_kinsn_modules() -> list[str]:
    module_dir = resolve_kinsn_module_dir()
    if not module_dir.is_dir():
        raise RuntimeError(f"kinsn module directory is missing: {module_dir}")
    modules = sorted(
        path.stem
        for path in module_dir.glob("bpf_*.ko")
        if path.is_file() and path.stem != "bpf_barrier"
    )
    if not modules:
        raise RuntimeError(f"no kinsn modules found under {module_dir}")
    return modules


def resolve_kinsn_module_dir(module_dir: Path | None = None) -> Path:
    if module_dir is not None:
        resolved = Path(module_dir).resolve()
        if not resolved.is_dir():
            raise RuntimeError(f"kinsn module directory is missing: {resolved}")
        return resolved
    arch_dir = _KINSN_MODULE_ARCH_DIRS.get(platform.machine())
    if arch_dir is None:
        raise RuntimeError(f"unsupported architecture for kinsn modules: {platform.machine()}")
    return ROOT_DIR / "module" / arch_dir


def _loaded_bpf_modules_from_lsmod() -> tuple[list[str], str] | None:
    completed = run_command(["lsmod"], timeout=10, check=False)
    if completed.returncode != 0:
        return None
    filtered_lines = [
        line.rstrip()
        for line in completed.stdout.splitlines()[1:]
        if line.startswith("bpf_")
    ]
    modules = sorted({line.split()[0] for line in filtered_lines if line.split()})
    return modules, "\n".join(filtered_lines)


def _loaded_bpf_modules_from_sysfs() -> tuple[list[str], str]:
    entries = sorted(path.name for path in Path("/sys/module").glob("bpf_*") if path.is_dir())
    return entries, "\n".join(entries)


def capture_kinsn_module_snapshot(expected_modules: Sequence[str]) -> dict[str, object]:
    snapshot = _loaded_bpf_modules_from_lsmod()
    source = "lsmod"
    if snapshot is None:
        snapshot = _loaded_bpf_modules_from_sysfs()
        source = "sysfs"

    loaded_modules, raw_output = snapshot
    expected = sorted({str(name) for name in expected_modules if str(name).strip()})
    resident_expected = [name for name in expected if name in loaded_modules]
    missing_expected = [name for name in expected if name not in resident_expected]
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "source": source,
        "raw_output": raw_output,
        "loaded_bpf_modules": loaded_modules,
        "expected_modules": expected,
        "resident_expected_modules": resident_expected,
        "missing_expected_modules": missing_expected,
    }


def _module_is_resident(module_name: str) -> bool:
    snapshot = _loaded_bpf_modules_from_lsmod()
    if snapshot is not None:
        return module_name in snapshot[0]
    return (Path("/sys/module") / module_name).is_dir()


def load_kinsn_modules(
    expected_modules: Sequence[str],
    *,
    module_dir: Path | None = None,
    before_snapshot: Mapping[str, object] | None = None,
) -> dict[str, object]:
    snapshot_before = dict(before_snapshot) if before_snapshot is not None else capture_kinsn_module_snapshot(expected_modules)
    resolved_module_dir = resolve_kinsn_module_dir(module_dir)
    loaded = 0
    total = 0
    for ko_path in sorted(resolved_module_dir.glob("*.ko")):
        if not ko_path.is_file():
            continue
        module_name = ko_path.stem
        if module_name == "bpf_barrier":
            continue
        total += 1
        if not _module_is_resident(module_name):
            completed = run_command(["insmod", str(ko_path)], timeout=120, check=False)
            if completed.returncode != 0:
                output = (completed.stderr or completed.stdout or "").strip()
                raise RuntimeError(f"failed to load {module_name}: {output}")
        if _module_is_resident(module_name):
            loaded += 1
    if total == 0:
        raise RuntimeError(f"no kinsn modules found in {resolved_module_dir}")

    after_snapshot = capture_kinsn_module_snapshot(expected_modules)

    expected = list(after_snapshot.get("expected_modules") or [])
    before_loaded = {
        str(name)
        for name in snapshot_before.get("resident_expected_modules") or []
        if str(name).strip()
    }
    after_loaded = {
        str(name)
        for name in after_snapshot.get("resident_expected_modules") or []
        if str(name).strip()
    }

    loaded_modules = [name for name in expected if name in after_loaded]
    newly_loaded_modules = [name for name in expected if name in after_loaded and name not in before_loaded]
    failed_modules = [name for name in expected if name not in after_loaded]
    if failed_modules:
        raise RuntimeError(
            "kinsn module loader did not load all expected modules: "
            + ", ".join(failed_modules)
        )

    return {
        "invoked_at": datetime.now(timezone.utc).isoformat(),
        "loader": "runner.libs.kinsn.load_kinsn_modules",
        "module_dir": relpath(resolved_module_dir),
        "status": "ok",
        "loaded_count": loaded,
        "total_count": total,
        "expected_modules": expected,
        "loaded_modules": loaded_modules,
        "newly_loaded_modules": newly_loaded_modules,
        "failed_modules": failed_modules,
        "snapshot_after": after_snapshot,
    }


def prepare_kinsn_modules() -> dict[str, object]:
    expected_modules = expected_kinsn_modules()
    before_snapshot = capture_kinsn_module_snapshot(expected_modules)
    module_load = load_kinsn_modules(
        expected_modules,
        before_snapshot=before_snapshot,
    )
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "expected_modules": expected_modules,
        "module_snapshot_before_daemon": before_snapshot,
        "module_load": module_load,
    }


def _read_text_file(path: Path | None) -> str:
    if path is None or not path.exists():
        return ""
    return path.read_text(encoding="utf-8", errors="replace")


def capture_daemon_kinsn_discovery(
    stdout_path: Path | None,
    stderr_path: Path | None,
    *,
    timeout_seconds: float = 5.0,
) -> dict[str, object]:
    deadline = time.monotonic() + max(0.0, float(timeout_seconds))
    stdout_text = ""
    stderr_text = ""
    while True:
        stdout_text = _read_text_file(stdout_path).strip()
        stderr_text = _read_text_file(stderr_path).strip()
        if "kinsn discovery:" in stderr_text:
            break
        if time.monotonic() >= deadline:
            raise RuntimeError(
                "daemon kinsn discovery log was not found in stderr output"
            )
        time.sleep(0.05)
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "status": "ok",
        "stdout_path": relpath(stdout_path),
        "stderr_path": relpath(stderr_path),
        "stdout": stdout_text,
        "stderr": stderr_text,
        "discovery_log": stderr_text,
    }
