#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
from pathlib import Path

import yaml


ROOT = Path(__file__).resolve().parent
REPO_ROOT = ROOT.parent
DEFAULT_CONFIG = ROOT / "config" / "macro_corpus.yaml"


def run(command: list[str], cwd: Path | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, text=True)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def capture(command: list[str], cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, cwd=cwd, text=True, capture_output=True)


def load_corpus_config(path: Path) -> dict[str, Path]:
    data = yaml.safe_load(path.read_text())
    corpus = data["corpus"]
    return {
        "manifest": (REPO_ROOT / corpus["manifest"]).resolve(),
        "local_repos": (REPO_ROOT / corpus["local_repos"]).resolve(),
        "inventory": (REPO_ROOT / corpus["inventory"]).resolve(),
    }


def load_manifest(manifest_path: Path) -> list[dict[str, object]]:
    data = yaml.safe_load(manifest_path.read_text())
    return list(data["repos"])


def ensure_repo(spec: dict[str, object], local_repos: Path) -> Path:
    name = str(spec["name"])
    url = str(spec["url"])
    branch = str(spec.get("branch", "main"))
    sparse_paths = [str(path) for path in spec.get("sparse_paths", [])]
    repo_dir = local_repos / name

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
        status = capture(["git", "status", "--porcelain"], cwd=repo_dir)
        if status.returncode != 0:
            raise SystemExit(status.returncode)
        if status.stdout.strip():
            run(["git", "checkout", branch], cwd=repo_dir)
            run(["git", "pull", "--ff-only", "--depth", "1", "origin", branch], cwd=repo_dir)
        else:
            # Generated corpus clones are safe to realign when clean, which also
            # handles force-pushed shallow branches that can't be fast-forwarded.
            run(["git", "checkout", "-B", branch, f"origin/{branch}"], cwd=repo_dir)

    if sparse_paths:
        run(["git", "sparse-checkout", "set", *sparse_paths], cwd=repo_dir)
    else:
        run(["git", "sparse-checkout", "disable"], cwd=repo_dir)

    return repo_dir


def harvest_repo(spec: dict[str, object], repo_dir: Path) -> dict[str, object]:
    globs = [str(pattern) for pattern in spec.get("harvest_globs", [])]
    exclude_globs = [str(pattern) for pattern in spec.get("exclude_globs", [])]
    harvested: set[str] = set()
    excluded: set[str] = set()

    for pattern in globs:
        harvested.update(
            str(path.relative_to(repo_dir))
            for path in repo_dir.glob(pattern)
            if path.is_file()
        )
    for pattern in exclude_globs:
        excluded.update(
            str(path.relative_to(repo_dir))
            for path in repo_dir.glob(pattern)
            if path.is_file()
        )

    files = sorted(harvested - excluded)

    return {
        "name": spec["name"],
        "url": spec["url"],
        "branch": spec.get("branch", "main"),
        "repo_dir": str(repo_dir),
        "sparse_paths": list(spec.get("sparse_paths", [])),
        "harvest_globs": globs,
        "exclude_globs": exclude_globs,
        "num_program_sources": len(files),
        "num_bpf_c": len(files),
        "files": files,
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Fetch and inventory real-world eBPF testcase repos.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG), help="Path to macro corpus config.")
    parser.add_argument("--repo", action="append", dest="repos", help="Only fetch selected repo names.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    config = load_corpus_config(Path(args.config).resolve())
    manifest_path = config["manifest"]
    local_repos = config["local_repos"]
    inventory_path = config["inventory"]

    local_repos.mkdir(parents=True, exist_ok=True)

    selected = set(args.repos or [])
    manifest = load_manifest(manifest_path)
    records = []
    for spec in manifest:
        name = str(spec["name"])
        if selected and name not in selected:
            continue
        repo_dir = ensure_repo(spec, local_repos)
        records.append(harvest_repo(spec, repo_dir))

    output = {
        "config": str(Path(args.config).resolve()),
        "manifest": str(manifest_path),
        "repos": records,
        "total_program_sources": sum(int(record["num_program_sources"]) for record in records),
        "total_bpf_c": sum(int(record["num_bpf_c"]) for record in records),
    }
    inventory_path.write_text(json.dumps(output, indent=2))
    print(f"[done] wrote {inventory_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
