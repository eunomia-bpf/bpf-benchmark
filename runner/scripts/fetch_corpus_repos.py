#!/usr/bin/env python3
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.repo_registry import (  # noqa: E402
    DEFAULT_REPO_MANIFEST,
    DEFAULT_REPO_ROOT,
    load_repo_manifest,
)


SCRIPT_DIR = Path(__file__).resolve().parent
RUNNER_DIR = SCRIPT_DIR.parent
REPO_ROOT = RUNNER_DIR.parent


def run(command: list[str], cwd: Path | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, text=True)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def capture(command: list[str], cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, cwd=cwd, text=True, capture_output=True)


def git_head(path: Path) -> str | None:
    completed = capture(["git", "rev-parse", "HEAD"], cwd=path)
    if completed.returncode != 0:
        return None
    return completed.stdout.strip() or None


def ensure_repo(spec: dict[str, object], repo_root: Path) -> Path:
    name = str(spec["name"])
    url = str(spec["url"])
    branch = str(spec.get("branch", "main"))
    sparse_paths = [str(path) for path in spec.get("sparse_paths", [])]
    repo_dir = repo_root / name

    if not repo_dir.exists():
        run(
            [
                "git",
                "clone",
                "--depth",
                "1",
                "--filter=blob:none",
                "--sparse",
                "--branch",
                branch,
                url,
                str(repo_dir),
            ],
            cwd=REPO_ROOT,
        )
    else:
        run(["git", "fetch", "--depth", "1", "origin", branch], cwd=repo_dir)
        status = capture(["git", "status", "--porcelain", "--untracked-files=no"], cwd=repo_dir)
        if status.returncode != 0:
            raise SystemExit(status.returncode)
        if status.stdout.strip():
            run(["git", "checkout", branch], cwd=repo_dir)
            run(["git", "pull", "--ff-only", "--depth", "1", "origin", branch], cwd=repo_dir)
        else:
            run(["git", "checkout", "-B", branch, f"origin/{branch}"], cwd=repo_dir)

    if sparse_paths:
        run(["git", "sparse-checkout", "set", *sparse_paths], cwd=repo_dir)
    else:
        run(["git", "sparse-checkout", "disable"], cwd=repo_dir)

    return repo_dir


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Fetch or refresh third-party BPF repos under runner/repos/.")
    parser.add_argument("--manifest", default=str(DEFAULT_REPO_MANIFEST), help="Repo manifest path.")
    parser.add_argument("--repo-root", default=str(DEFAULT_REPO_ROOT), help="Checkout directory root.")
    parser.add_argument("--repo", action="append", dest="repos", help="Only fetch selected repo names.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    manifest_path = Path(args.manifest).resolve()
    repo_root = Path(args.repo_root).resolve()
    selected = set(args.repos or [])

    manifest = load_repo_manifest(manifest_path)
    known_repos = {str(spec["name"]) for spec in manifest}
    missing_selected = sorted(selected - known_repos)
    if missing_selected:
        raise SystemExit(f"unknown repos in {manifest_path}: {', '.join(missing_selected)}")

    repo_root.mkdir(parents=True, exist_ok=True)

    for spec in manifest:
        name = str(spec["name"])
        if selected and name not in selected:
            continue
        repo_dir = ensure_repo(spec, repo_root)
        print(f"[ready] {name} {git_head(repo_dir) or 'unknown'} {repo_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
