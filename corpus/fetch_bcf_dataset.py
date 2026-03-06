#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import tempfile
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parent
REPO_ROOT = ROOT.parent
OUTPUT_DIR = ROOT / "bcf"
MANIFEST_PATH = OUTPUT_DIR / "manifest.json"
DEFAULT_REPO_URL = "https://github.com/SunHao-0/BCF"
DEFAULT_BRANCH = "main"
SPARSE_PATH = "bpf-progs"
COMPATIBLE_PROG_TYPES = {"xdp", "classifier"}


def run(command: list[str], cwd: Path | None = None, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=cwd,
        text=True,
        capture_output=capture_output,
    )
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise SystemExit(
            f"command failed ({completed.returncode}): {' '.join(command)}\n{details}"
        )
    return completed


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Fetch the BCF BPF object corpus and build a local manifest.")
    parser.add_argument("--repo-url", default=DEFAULT_REPO_URL, help="BCF Git remote URL.")
    parser.add_argument("--branch", default=DEFAULT_BRANCH, help="Git branch or ref to clone.")
    return parser.parse_args()


def parse_filename(name: str) -> dict[str, str | None]:
    if not name.startswith("clang-"):
        return {
            "compiler": None,
            "clang_version": None,
            "optimization_level": None,
            "canonical_name": name,
        }

    compiler, separator, remainder = name.partition("_")
    if not separator:
        return {
            "compiler": None,
            "clang_version": None,
            "optimization_level": None,
            "canonical_name": name,
        }
    opt_token, separator, canonical_name = remainder.partition("_")
    if not separator or not opt_token.startswith("-O"):
        return {
            "compiler": None,
            "clang_version": None,
            "optimization_level": None,
            "canonical_name": name,
        }

    return {
        "compiler": compiler,
        "clang_version": compiler.removeprefix("clang-"),
        "optimization_level": opt_token.removeprefix("-"),
        "canonical_name": canonical_name,
    }


def flatten_index(index: dict[str, dict[str, list[str]]]) -> dict[str, dict[str, str]]:
    records: dict[str, dict[str, str]] = {}
    for source_project, groups in index.items():
        for source_group, variants in groups.items():
            for variant_name in variants:
                records[variant_name] = {
                    "source_project": source_project,
                    "source_group": source_group,
                }
    return records


def load_json(path: Path) -> Any:
    return json.loads(path.read_text())


def clean_output_dir(output_dir: Path) -> None:
    if not output_dir.exists():
        return
    for path in output_dir.rglob("*.o"):
        path.unlink()
    manifest = output_dir / "manifest.json"
    if manifest.exists():
        manifest.unlink()


def main() -> int:
    args = parse_args()
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    clean_output_dir(OUTPUT_DIR)

    with tempfile.TemporaryDirectory(prefix="bcf-fetch-") as tempdir:
        checkout_dir = Path(tempdir) / "repo"
        run(
            [
                "git",
                "clone",
                "--depth",
                "1",
                "--filter=blob:none",
                "--sparse",
                "--branch",
                args.branch,
                args.repo_url,
                str(checkout_dir),
            ],
            cwd=REPO_ROOT,
        )
        run(["git", "sparse-checkout", "set", SPARSE_PATH], cwd=checkout_dir)

        commit = run(
            ["git", "rev-parse", "HEAD"],
            cwd=checkout_dir,
            capture_output=True,
        ).stdout.strip()

        bpf_root = checkout_dir / SPARSE_PATH
        prog_index = load_json(bpf_root / "prog_index.json")
        accepted_index = load_json(bpf_root / "accepted_prog_index.json")
        obj_prog_type = load_json(bpf_root / "obj_prog_type.json")

        variant_index = flatten_index(prog_index)
        accepted_variants = set(flatten_index(accepted_index))

        programs: list[dict[str, Any]] = []
        by_source_variants: Counter[str] = Counter()
        by_source_compatible: Counter[str] = Counter()
        by_source_accepted: Counter[str] = Counter()
        compatible_source_groups: defaultdict[str, set[str]] = defaultdict(set)

        object_files = sorted(
            path for path in bpf_root.rglob("*.o")
            if path.is_file()
        )

        for src_path in object_files:
            relpath = src_path.relative_to(bpf_root)
            source_project = relpath.parts[0]
            filename_meta = parse_filename(src_path.name)
            index_meta = variant_index.get(src_path.name, {})
            source_group = str(index_meta.get("source_group", filename_meta["canonical_name"]))
            program_type = obj_prog_type.get(src_path.name)
            compatible = program_type in COMPATIBLE_PROG_TYPES
            accepted = src_path.name in accepted_variants

            dst_path = OUTPUT_DIR / relpath
            dst_path.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src_path, dst_path)

            record = {
                "file_name": src_path.name,
                "relative_path": str(relpath),
                "source_project": source_project,
                "source_group": source_group,
                "canonical_name": filename_meta["canonical_name"],
                "compiler": filename_meta["compiler"],
                "clang_version": filename_meta["clang_version"],
                "optimization_level": filename_meta["optimization_level"],
                "program_type": program_type,
                "test_run_compatible": compatible,
                "accepted_by_bcf": accepted,
                "original_relpath": str(Path(SPARSE_PATH) / relpath),
            }
            programs.append(record)

            by_source_variants[source_project] += 1
            if compatible:
                by_source_compatible[source_project] += 1
                compatible_source_groups[source_project].add(source_group)
            if accepted:
                by_source_accepted[source_project] += 1

        bpf_suffix_count = sum(1 for path in object_files if path.name.endswith(".bpf.o"))

        source_breakdown: dict[str, dict[str, int]] = {}
        total_unique = 0
        total_accepted_unique = 0
        for source_project, groups in prog_index.items():
            variants = by_source_variants[source_project]
            unique_programs = len(groups)
            accepted_groups = accepted_index.get(source_project, {})
            total_unique += unique_programs
            total_accepted_unique += len(accepted_groups)
            source_breakdown[source_project] = {
                "variants": variants,
                "unique_programs": unique_programs,
                "accepted_variants": by_source_accepted[source_project],
                "accepted_unique_programs": len(accepted_groups),
                "test_run_compatible_variants": by_source_compatible[source_project],
                "test_run_compatible_unique_programs": len(compatible_source_groups[source_project]),
            }

        compatible_variant_count = sum(1 for program in programs if program["test_run_compatible"])
        manifest = {
            "dataset": "bcf",
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "source_repo": {
                "url": args.repo_url,
                "branch": args.branch,
                "commit": commit,
                "sparse_paths": [SPARSE_PATH],
            },
            "paths": {
                "root": str(OUTPUT_DIR),
                "manifest": str(MANIFEST_PATH),
            },
            "counts": {
                "total_variants": len(programs),
                "total_unique_programs": total_unique,
                "total_accepted_variants": len(accepted_variants),
                "total_accepted_unique_programs": total_accepted_unique,
                "test_run_compatible_variants": compatible_variant_count,
                "test_run_compatible_unique_programs": sum(
                    len(groups) for groups in compatible_source_groups.values()
                ),
                "by_source": source_breakdown,
            },
            "compatible_prog_types": sorted(COMPATIBLE_PROG_TYPES),
            "programs": programs,
        }

    MANIFEST_PATH.write_text(json.dumps(manifest, indent=2))

    print(f"[done] copied {len(programs)} BPF object files into {OUTPUT_DIR}")
    print(f"[done] wrote {MANIFEST_PATH}")
    print(
        f"[summary] variants={manifest['counts']['total_variants']} "
        f"unique={manifest['counts']['total_unique_programs']} "
        f"compatible={manifest['counts']['test_run_compatible_variants']}"
    )
    if bpf_suffix_count != len(programs):
        print(
            "[note] the BCF corpus stores nearly all variants as *.o, not *.bpf.o; "
            f"the fetch step copied all {len(programs)} object files ({bpf_suffix_count} end with .bpf.o)."
        )
    for source_project, stats in sorted(source_breakdown.items()):
        print(
            f"  {source_project:18} "
            f"variants={stats['variants']:4} "
            f"unique={stats['unique_programs']:3} "
            f"compatible={stats['test_run_compatible_variants']:3}"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
