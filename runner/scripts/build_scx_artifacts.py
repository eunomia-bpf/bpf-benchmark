#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
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


def release_dir(repo_dir: Path, target_triple: str | None) -> Path:
    if target_triple:
        return repo_dir / "target" / target_triple / "release"
    return repo_dir / "target" / "release"


def latest_artifact(repo_dir: Path, package: str, target_triple: str | None) -> Path:
    candidates = sorted((release_dir(repo_dir, target_triple) / "build").glob(f"{package}-*/out/bpf.bpf.o"))
    if not candidates:
        raise SystemExit(
            f"missing compiled BPF object for {package} under {release_dir(repo_dir, target_triple) / 'build'}/"
        )
    return max(candidates, key=lambda path: path.stat().st_mtime_ns)


def outputs_present(
    repo_dir: Path,
    promote_root: Path,
    target_triple: str | None,
    packages: list[str],
    promoted_objects: dict[str, str],
) -> bool:
    current_release_dir = release_dir(repo_dir, target_triple)
    if not all((current_release_dir / package).is_file() for package in packages):
        return False
    return all((promote_root / relative_path).is_file() for relative_path in promoted_objects.values())


def promote_objects(repo_dir: Path, promote_root: Path, promoted_objects: dict[str, str], target_triple: str | None) -> None:
    for package, relative_output in promoted_objects.items():
        source = latest_artifact(repo_dir, package, target_triple)
        destination = (promote_root / relative_output).resolve()
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, destination)
        print(f"[promote] {source} -> {destination}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build runner-managed scx userspace and BPF artifacts.")
    parser.add_argument("--manifest", default=str(DEFAULT_MANIFEST), help="Runner repo manifest.")
    parser.add_argument("--force", action="store_true", help="Rebuild even when promoted outputs already exist.")
    parser.add_argument(
        "--package",
        action="append",
        dest="packages",
        help="Only build selected scx cargo packages. May be repeated.",
    )
    parser.add_argument(
        "--target-triple",
        default=str(os.environ.get("SCX_TARGET_TRIPLE", "")).strip(),
        help="Optional Cargo target triple for cross-building scx artifacts.",
    )
    parser.add_argument(
        "--jobs",
        type=int,
        default=max(1, int(os.environ.get("SCX_BUILD_JOBS", "1") or "1")),
        help="Cargo build parallelism for scx artifacts.",
    )
    parser.add_argument(
        "--repo-root",
        default="",
        help="Optional runner/repos root to build from instead of the default checkout location.",
    )
    parser.add_argument(
        "--promote-root",
        default="",
        help="Optional root directory to receive promoted BPF objects instead of the repo root.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    manifest_path = Path(args.manifest).resolve()
    spec = load_scx_spec(manifest_path)
    repo_root = Path(args.repo_root).resolve() if str(args.repo_root).strip() else None
    promote_root = Path(args.promote_root).resolve() if str(args.promote_root).strip() else ROOT_DIR
    repo_dir = repo_checkout(SCX_NAME, repo_root)
    if not repo_dir.exists():
        raise SystemExit(f"scx checkout missing: {repo_dir}; run fetch_corpus_repos.py --repo scx first")

    manifest_packages = [str(name) for name in spec.get("cargo_packages", [])]
    all_promoted_objects = {str(key): str(value) for key, value in dict(spec.get("promoted_objects", {})).items()}
    if not manifest_packages or not all_promoted_objects:
        raise SystemExit(f"scx manifest entry in {manifest_path} is missing cargo_packages or promoted_objects")
    packages = [str(name) for name in (args.packages or manifest_packages)]
    unknown_packages = sorted(set(packages) - set(manifest_packages))
    if unknown_packages:
        raise SystemExit(f"unknown scx cargo packages requested: {', '.join(unknown_packages)}")
    promoted_objects = {package: all_promoted_objects[package] for package in packages if package in all_promoted_objects}
    if len(promoted_objects) != len(packages):
        missing_objects = [package for package in packages if package not in promoted_objects]
        raise SystemExit(f"missing promoted object mapping for packages: {', '.join(missing_objects)}")
    target_triple = str(args.target_triple or "").strip() or None

    if not args.force and outputs_present(repo_dir, promote_root, target_triple, packages, promoted_objects):
        print(f"[skip] scx artifacts already present under {release_dir(repo_dir, target_triple)} and corpus/build/scx/")
        return 0

    command = [
        "cargo",
        "build",
        "--release",
        "-j",
        str(max(1, args.jobs)),
    ]
    if target_triple is not None:
        command.extend(["--target", target_triple])
    command.extend(sum((["-p", package] for package in packages), start=[]))
    run(command, cwd=repo_dir)
    promote_objects(repo_dir, promote_root, promoted_objects, target_triple)

    current_release_dir = release_dir(repo_dir, target_triple)
    for package in packages:
        binary_path = current_release_dir / package
        if not binary_path.is_file():
            raise SystemExit(f"expected scx binary missing after build: {binary_path}")
        print(f"[done] scx binary ready at {binary_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
