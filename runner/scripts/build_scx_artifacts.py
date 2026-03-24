#!/usr/bin/env python3
from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ROOT_DIR  # noqa: E402
from runner.libs.repo_registry import load_repo_manifest, repo_checkout  # noqa: E402


RUNNER_DIR = ROOT_DIR / "runner"
DEFAULT_MANIFEST = RUNNER_DIR / "repos.yaml"
SCX_NAME = "scx"


def run(command: list[str], cwd: Path | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, text=True, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def load_scx_spec(manifest_path: Path) -> dict[str, object]:
    for entry in load_repo_manifest(manifest_path):
        if str(entry.get("name")) == SCX_NAME:
            return entry
    raise SystemExit(f"repo `{SCX_NAME}` not found in {manifest_path}")


def latest_artifact(repo_dir: Path, package: str) -> Path:
    candidates = sorted(repo_dir.glob(f"target/release/build/{package}-*/out/bpf.bpf.o"))
    if not candidates:
        raise SystemExit(f"missing compiled BPF object for {package} under {repo_dir}/target/release/build/")
    return max(candidates, key=lambda path: path.stat().st_mtime_ns)


def outputs_present(repo_dir: Path, promoted_objects: dict[str, str]) -> bool:
    binary_path = repo_dir / "target" / "release" / "scx_rusty"
    if not binary_path.is_file():
        return False
    return all((ROOT_DIR / relative_path).is_file() for relative_path in promoted_objects.values())


def promote_objects(repo_dir: Path, promoted_objects: dict[str, str]) -> None:
    for package, relative_output in promoted_objects.items():
        source = latest_artifact(repo_dir, package)
        destination = (ROOT_DIR / relative_output).resolve()
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, destination)
        print(f"[promote] {source} -> {destination}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build runner-managed scx userspace and BPF artifacts.")
    parser.add_argument("--manifest", default=str(DEFAULT_MANIFEST), help="Runner repo manifest.")
    parser.add_argument("--force", action="store_true", help="Rebuild even when promoted outputs already exist.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    manifest_path = Path(args.manifest).resolve()
    spec = load_scx_spec(manifest_path)
    repo_dir = repo_checkout(SCX_NAME)
    if not repo_dir.exists():
        raise SystemExit(f"scx checkout missing: {repo_dir}; run fetch_corpus_repos.py --repo scx first")

    packages = [str(name) for name in spec.get("cargo_packages", [])]
    promoted_objects = {str(key): str(value) for key, value in dict(spec.get("promoted_objects", {})).items()}
    if not packages or not promoted_objects:
        raise SystemExit(f"scx manifest entry in {manifest_path} is missing cargo_packages or promoted_objects")

    if not args.force and outputs_present(repo_dir, promoted_objects):
        print(f"[skip] scx artifacts already present under {repo_dir} and corpus/build/scx/")
        return 0

    run(["cargo", "build", "--release", *sum((["-p", package] for package in packages), start=[])], cwd=repo_dir)
    promote_objects(repo_dir, promoted_objects)

    binary_path = repo_dir / "target" / "release" / "scx_rusty"
    if not binary_path.is_file():
        raise SystemExit(f"expected scx binary missing after build: {binary_path}")
    print(f"[done] scx binary ready at {binary_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
