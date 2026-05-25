"""Native-loader environment helpers for corpus app runners."""

from __future__ import annotations

import os
from pathlib import Path


def native_loader_enabled() -> bool:
    return os.environ.get("BPFREJIT_SHIM_NATIVE_LOADER", "").strip().lower() in {
        "1",
        "true",
        "yes",
        "on",
    }


def native_loader_manifest_env(app: str) -> dict[str, str]:
    if not native_loader_enabled():
        return {}

    explicit = os.environ.get("BPFREJIT_SHIM_NATIVE_MANIFEST", "").strip()
    if explicit:
        manifest = Path(explicit)
    else:
        arch = os.environ.get("RUN_TARGET_ARCH", "x86_64").strip() or "x86_64"
        manifest = Path(f"/opt/bpf-benchmark/native-bpf/{arch}/{app}/manifest.json")
    if not manifest.is_file():
        raise RuntimeError(f"{app} native-loader manifest not found: {manifest}")
    return {"BPFREJIT_SHIM_NATIVE_MANIFEST": str(manifest)}
