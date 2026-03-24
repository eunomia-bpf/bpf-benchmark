from __future__ import annotations

from pathlib import Path
from typing import Any

import yaml

from . import ROOT_DIR


RUNNER_DIR = ROOT_DIR / "runner"
DEFAULT_REPO_MANIFEST = RUNNER_DIR / "repos.yaml"
DEFAULT_REPO_ROOT = RUNNER_DIR / "repos"
DEFAULT_REPO_INVENTORY = RUNNER_DIR / "inventory.json"


def resolve_repo_manifest(path: str | Path | None = None) -> Path:
    return Path(path or DEFAULT_REPO_MANIFEST).resolve()


def resolve_repo_root(path: str | Path | None = None) -> Path:
    return Path(path or DEFAULT_REPO_ROOT).resolve()


def resolve_repo_inventory(path: str | Path | None = None) -> Path:
    return Path(path or DEFAULT_REPO_INVENTORY).resolve()


def load_repo_manifest(path: str | Path | None = None) -> list[dict[str, Any]]:
    manifest_path = resolve_repo_manifest(path)
    data = yaml.safe_load(manifest_path.read_text())
    repos = data.get("repos")
    if not isinstance(repos, list):
        raise ValueError(f"invalid repo manifest schema: {manifest_path}")
    return list(repos)


def repo_checkout(name: str, root: str | Path | None = None) -> Path:
    return resolve_repo_root(root) / name


__all__ = [
    "DEFAULT_REPO_INVENTORY",
    "DEFAULT_REPO_MANIFEST",
    "DEFAULT_REPO_ROOT",
    "RUNNER_DIR",
    "load_repo_manifest",
    "repo_checkout",
    "resolve_repo_inventory",
    "resolve_repo_manifest",
    "resolve_repo_root",
]
