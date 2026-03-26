#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import platform
import shutil
import subprocess
import sys
import time
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

import yaml
from runner.libs import ensure_parent, latest_output_path, smoke_output_path  # noqa: E402
from runner.libs.repo_registry import DEFAULT_REPO_MANIFEST, DEFAULT_REPO_ROOT  # noqa: E402


SCRIPT_DIR = Path(__file__).resolve().parent
RUNNER_DIR = SCRIPT_DIR.parent
REPO_ROOT = RUNNER_DIR.parent
CORPUS_DIR = REPO_ROOT / "corpus"
DEFAULT_MACRO_CORPUS_YAML = CORPUS_DIR / "config" / "macro_corpus.yaml"
DEFAULT_BUILD_ROOT = CORPUS_DIR / "build"
DEFAULT_OUTPUT_JSON = latest_output_path(CORPUS_DIR / "results", "expanded_corpus_build")
DEFAULT_OUTPUT_MD = CORPUS_DIR / "results" / "expanded_corpus_build.md"
DEFAULT_TIMEOUT_SECONDS = 90
DEFAULT_MAX_WORKERS = min(8, (os.cpu_count() or 4))
GLOBAL_INCLUDE_DIRS = (
    REPO_ROOT / "vendor" / "linux-framework" / "tools" / "lib",
    REPO_ROOT / "vendor" / "linux-framework" / "tools" / "lib" / "bpf",
    REPO_ROOT / "vendor" / "linux-framework" / "tools" / "include",
    REPO_ROOT / "vendor" / "linux-framework" / "tools" / "include" / "uapi",
    REPO_ROOT / "vendor" / "linux-framework" / "include",
    REPO_ROOT / "vendor" / "linux-framework" / "include" / "uapi",
    REPO_ROOT / "vendor" / "libbpf" / "include" / "uapi",
    REPO_ROOT / "vendor" / "libbpf" / "include",
    REPO_ROOT / "vendor" / "libbpf" / "src",
)


@dataclass(frozen=True)
class RepoSpec:
    name: str
    repo_dir: Path
    harvest_globs: tuple[str, ...]
    exclude_globs: tuple[str, ...]
    compile_include_dirs: tuple[Path, ...]
    forced_includes: tuple[Path, ...]


@dataclass(frozen=True)
class WorkItem:
    repo_name: str
    repo_dir: Path
    relative_path: str
    source_path: Path
    output_path: Path
    temp_output_path: Path
    vmlinux_header: Path
    include_dirs: tuple[Path, ...]
    forced_includes: tuple[Path, ...]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compile source-backed corpus repos and emit a strict object availability report."
    )
    parser.add_argument("--manifest", default=str(DEFAULT_REPO_MANIFEST), help="Runner repo manifest path.")
    parser.add_argument("--repo-root", default=str(DEFAULT_REPO_ROOT), help="Runner repo checkout root.")
    parser.add_argument(
        "--macro-corpus-yaml",
        default=str(DEFAULT_MACRO_CORPUS_YAML),
        help="Macro corpus definition used to stage required prebuilt objects.",
    )
    parser.add_argument("--build-root", default=str(DEFAULT_BUILD_ROOT), help="Build output root.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON), help="Structured JSON output path.")
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD), help="Markdown summary output path.")
    parser.add_argument("--clang", default="clang", help="clang binary.")
    parser.add_argument("--bpftool", default="bpftool", help="bpftool binary.")
    parser.add_argument("--repo", action="append", dest="repos", help="Only process selected repo names.")
    parser.add_argument("--max-sources", type=int, help="Limit the number of source-backed objects processed.")
    parser.add_argument("--max-workers", type=int, default=DEFAULT_MAX_WORKERS, help="Parallel compile workers.")
    parser.add_argument(
        "--timeout-seconds",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-command timeout in seconds.",
    )
    return parser.parse_args()


def trim_text(value: str | None, limit: int = 8000) -> str:
    text = (value or "").strip()
    if len(text) <= limit:
        return text
    return text[: limit - 3] + "..."


def summarize_error(value: str | None) -> str:
    text = trim_text(value, 600)
    if not text:
        return "unknown error"
    lines = [line.strip() for line in text.splitlines() if line.strip()]
    return lines[-1] if lines else "unknown error"


def invoke_command(command: list[str], timeout_seconds: int, cwd: Path | None = None) -> dict[str, Any]:
    started_ns = time.perf_counter_ns()
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        return {
            "status": "timeout",
            "returncode": None,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": trim_text(exc.stdout),
            "stderr": trim_text(exc.stderr),
            "error": f"timed out after {timeout_seconds} seconds",
        }
    except OSError as exc:
        return {
            "status": "error",
            "returncode": None,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": "",
            "stderr": "",
            "error": str(exc),
        }

    stdout = trim_text(completed.stdout)
    stderr = trim_text(completed.stderr)
    if completed.returncode != 0:
        return {
            "status": "error",
            "returncode": completed.returncode,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": stdout,
            "stderr": stderr,
            "error": stderr or stdout or f"command failed with return code {completed.returncode}",
        }

    return {
        "status": "ok",
        "returncode": completed.returncode,
        "wall_time_ns": time.perf_counter_ns() - started_ns,
        "stdout": stdout,
        "stderr": stderr,
        "error": None,
    }


def capture(command: list[str], cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, cwd=cwd, text=True, capture_output=True)


def git_head(path: Path) -> str | None:
    completed = capture(["git", "rev-parse", "HEAD"], cwd=path)
    if completed.returncode != 0:
        return None
    return completed.stdout.strip() or None


def git_clean(path: Path) -> bool | None:
    completed = capture(["git", "status", "--porcelain"], cwd=path)
    if completed.returncode != 0:
        return None
    return not completed.stdout.strip()


def resolve_manifest_paths(repo_dir: Path, entries: list[str]) -> tuple[Path, ...]:
    resolved: list[Path] = []
    for value in entries:
        raw_path = Path(value)
        if raw_path.is_absolute():
            resolved.append(raw_path.resolve())
            continue
        repo_relative = (repo_dir / raw_path).resolve()
        root_relative = (REPO_ROOT / raw_path).resolve()
        resolved.append(repo_relative if repo_relative.exists() or not root_relative.exists() else root_relative)
    return tuple(resolved)


def load_manifest(path: Path, repo_root: Path) -> dict[str, RepoSpec]:
    data = yaml.safe_load(path.read_text())
    specs: dict[str, RepoSpec] = {}
    for entry in data["repos"]:
        name = str(entry["name"])
        repo_dir = (repo_root / name).resolve()
        specs[name] = RepoSpec(
            name=name,
            repo_dir=repo_dir,
            harvest_globs=tuple(str(pattern) for pattern in entry.get("harvest_globs", [])),
            exclude_globs=tuple(str(pattern) for pattern in entry.get("exclude_globs", [])),
            compile_include_dirs=resolve_manifest_paths(repo_dir, list(entry.get("compile_include_dirs", ["."]))),
            forced_includes=resolve_manifest_paths(repo_dir, list(entry.get("forced_includes", []))),
        )
    return specs


def collect_repo_sources(spec: RepoSpec) -> list[str]:
    if not spec.harvest_globs:
        return []
    if not spec.repo_dir.exists():
        raise SystemExit(f"repo checkout missing for {spec.name}: {spec.repo_dir} (run `make corpus-fetch`)")

    harvested: set[str] = set()
    excluded: set[str] = set()
    for pattern in spec.harvest_globs:
        harvested.update(
            str(path.relative_to(spec.repo_dir))
            for path in spec.repo_dir.glob(pattern)
            if path.is_file()
        )
    for pattern in spec.exclude_globs:
        excluded.update(
            str(path.relative_to(spec.repo_dir))
            for path in spec.repo_dir.glob(pattern)
            if path.is_file()
        )
    return sorted(harvested - excluded)


def infer_macro_repo_name(object_path: Path, build_root: Path) -> str:
    try:
        relative = object_path.resolve().relative_to(build_root.resolve())
    except ValueError:
        return "local"
    parts = relative.parts
    return parts[0] if parts else "local"


def macro_relative_path(object_path: Path, build_root: Path) -> str:
    repo_name = infer_macro_repo_name(object_path, build_root)
    repo_root = build_root / repo_name
    try:
        return object_path.resolve().relative_to(repo_root.resolve()).as_posix()
    except ValueError:
        try:
            return object_path.resolve().relative_to(REPO_ROOT).as_posix()
        except ValueError:
            return str(object_path.resolve())


def load_macro_object_paths(path: Path) -> dict[str, dict[str, str]]:
    payload = yaml.safe_load(path.read_text()) or {}
    objects: dict[str, dict[str, str]] = {}
    for program in payload.get("programs", []):
        raw_source = program.get("source")
        if not raw_source:
            continue
        source_path = Path(str(raw_source))
        object_path = source_path.resolve() if source_path.is_absolute() else (REPO_ROOT / source_path).resolve()
        objects[str(object_path)] = {
            "program_name": str(program.get("program_name") or program.get("name") or ""),
            "source": str(raw_source),
        }
    return objects


def target_arch_macro() -> str:
    machine = platform.machine().lower()
    mapping = {
        "x86_64": "x86",
        "amd64": "x86",
        "aarch64": "arm64",
        "arm64": "arm64",
        "armv7l": "arm",
        "armv8l": "arm",
        "ppc64le": "powerpc",
        "riscv64": "riscv",
        "loongarch64": "loongarch",
    }
    if machine in mapping:
        return mapping[machine]
    if machine.startswith("arm"):
        return "arm"
    if machine.startswith("mips"):
        return "mips"
    return machine


def ensure_vmlinux_header(bpftool: str, output_path: Path) -> None:
    if output_path.exists():
        return
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open("w") as handle:
        completed = subprocess.run(
            [bpftool, "btf", "dump", "file", "/sys/kernel/btf/vmlinux", "format", "c"],
            stdout=handle,
            stderr=subprocess.PIPE,
            text=True,
            check=False,
        )
    if completed.returncode == 0:
        return
    output_path.unlink(missing_ok=True)
    raise SystemExit(
        "unable to generate vmlinux.h: "
        + trim_text(completed.stderr or f"command failed with return code {completed.returncode}")
    )


def object_name_for_source(relative_path: str) -> str:
    path = Path(relative_path)
    name = path.name
    if name.endswith(".bpf.c"):
        object_name = name.removesuffix(".c")[:-4] + ".bpf.o"
    elif name.endswith(".c"):
        object_name = name.removesuffix(".c") + ".bpf.o"
    else:
        object_name = name + ".bpf.o"
    return str(path.with_name(object_name))


def build_work_items(
    manifest: dict[str, RepoSpec],
    build_root: Path,
    selected_repos: set[str],
    max_sources: int | None,
) -> tuple[list[WorkItem], dict[str, dict[str, Any]]]:
    items: list[WorkItem] = []
    repo_states: dict[str, dict[str, Any]] = {}

    for repo_name, spec in sorted(manifest.items()):
        if selected_repos and repo_name not in selected_repos:
            continue
        source_files = collect_repo_sources(spec)
        repo_states[repo_name] = {
            "repo_dir": str(spec.repo_dir),
            "present": spec.repo_dir.exists(),
            "head": git_head(spec.repo_dir) if spec.repo_dir.exists() else None,
            "clean": git_clean(spec.repo_dir) if spec.repo_dir.exists() else None,
            "source_files": len(source_files),
        }

        if not source_files:
            continue

        repo_build_root = (build_root / repo_name).resolve()
        vmlinux_header = repo_build_root / "vmlinux.h"
        include_dirs = tuple(path for path in spec.compile_include_dirs if path.exists())
        forced_includes = tuple(path for path in spec.forced_includes if path.exists())
        for relative_path in source_files:
            source_path = (spec.repo_dir / relative_path).resolve()
            object_rel = object_name_for_source(relative_path)
            output_path = (repo_build_root / object_rel).resolve()
            temp_output_path = output_path.with_suffix(".tmp.o")
            items.append(
                WorkItem(
                    repo_name=repo_name,
                    repo_dir=spec.repo_dir,
                    relative_path=relative_path,
                    source_path=source_path,
                    output_path=output_path,
                    temp_output_path=temp_output_path,
                    vmlinux_header=vmlinux_header,
                    include_dirs=include_dirs,
                    forced_includes=forced_includes,
                )
            )

    items.sort(key=lambda item: (item.repo_name, item.relative_path))
    if max_sources is not None:
        items = items[:max_sources]
    return items, repo_states


def compile_source(
    item: WorkItem,
    clang: str,
    bpftool: str,
    timeout_seconds: int,
) -> dict[str, Any]:
    ensure_parent(item.output_path)
    ensure_parent(item.temp_output_path)
    include_flags = [
        flag
        for include_dir in (item.vmlinux_header.parent, *GLOBAL_INCLUDE_DIRS, *item.include_dirs)
        if include_dir.exists()
        for flag in ("-I", str(include_dir))
    ]
    forced_include_flags = [
        flag
        for include_path in item.forced_includes
        for flag in ("-include", str(include_path))
    ]
    clang_command = [
        clang,
        "-O2",
        "-g",
        "-target",
        "bpf",
        f"-D__TARGET_ARCH_{target_arch_macro()}",
        *include_flags,
        *forced_include_flags,
        "-c",
        str(item.source_path),
        "-o",
        str(item.temp_output_path),
    ]
    clang_outcome = invoke_command(clang_command, timeout_seconds, cwd=item.repo_dir)
    if clang_outcome["status"] != "ok":
        return {
            "repo": item.repo_name,
            "relative_path": item.relative_path,
            "source_path": str(item.source_path),
            "object_path": str(item.output_path),
            "temp_object_path": str(item.temp_output_path),
            "status": "error",
            "stage": "clang",
            "compile_command": clang_command,
            "finalize_command": None,
            "vmlinux_header": str(item.vmlinux_header),
            **clang_outcome,
        }

    finalize_command = [bpftool, "gen", "object", str(item.output_path), str(item.temp_output_path)]
    finalize_outcome = invoke_command(finalize_command, timeout_seconds, cwd=item.repo_dir)
    if finalize_outcome["status"] != "ok":
        return {
            "repo": item.repo_name,
            "relative_path": item.relative_path,
            "source_path": str(item.source_path),
            "object_path": str(item.output_path),
            "temp_object_path": str(item.temp_output_path),
            "status": "error",
            "stage": "bpftool_gen_object",
            "compile_command": clang_command,
            "finalize_command": finalize_command,
            "vmlinux_header": str(item.vmlinux_header),
            "compile_stdout": clang_outcome["stdout"],
            "compile_stderr": clang_outcome["stderr"],
            "compile_wall_time_ns": clang_outcome["wall_time_ns"],
            **finalize_outcome,
        }

    return {
        "repo": item.repo_name,
        "relative_path": item.relative_path,
        "source_path": str(item.source_path),
        "object_path": str(item.output_path),
        "temp_object_path": str(item.temp_output_path),
        "status": "ok",
        "stage": "complete",
        "compile_command": clang_command,
        "finalize_command": finalize_command,
        "vmlinux_header": str(item.vmlinux_header),
        "compile_stdout": clang_outcome["stdout"],
        "compile_stderr": clang_outcome["stderr"],
        "compile_wall_time_ns": clang_outcome["wall_time_ns"],
        "finalize_stdout": finalize_outcome["stdout"],
        "finalize_stderr": finalize_outcome["stderr"],
        "finalize_wall_time_ns": finalize_outcome["wall_time_ns"],
        "stdout": finalize_outcome["stdout"],
        "stderr": finalize_outcome["stderr"],
        "returncode": 0,
        "wall_time_ns": clang_outcome["wall_time_ns"] + finalize_outcome["wall_time_ns"],
        "error": None,
    }


def stage_macro_objects(
    *,
    macro_corpus_yaml: Path,
    build_root: Path,
    selected_repos: set[str],
    compiled_objects: set[str],
) -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    for raw_path, metadata in sorted(load_macro_object_paths(macro_corpus_yaml).items()):
        object_path = Path(raw_path)
        repo_name = infer_macro_repo_name(object_path, build_root)
        if selected_repos and repo_name not in selected_repos:
            continue
        if raw_path in compiled_objects:
            continue
        exists = object_path.exists()
        records.append(
            {
                "repo": repo_name,
                "relative_path": macro_relative_path(object_path, build_root),
                "source_path": None,
                "object_path": str(object_path),
                "temp_object_path": None,
                "status": "existing" if exists else "error",
                "stage": "prebuilt" if exists else "missing_object",
                "compile_command": None,
                "finalize_command": None,
                "vmlinux_header": None,
                "compile_stdout": "",
                "compile_stderr": "",
                "compile_wall_time_ns": 0,
                "finalize_stdout": "",
                "finalize_stderr": "",
                "finalize_wall_time_ns": 0,
                "stdout": "",
                "stderr": "",
                "returncode": 0 if exists else None,
                "wall_time_ns": 0,
                "error": None if exists else f"macro corpus references missing object: {metadata['source']}",
                "macro_source": metadata["source"],
                "macro_program": metadata["program_name"],
            }
        )
    return records


def compute_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    by_repo: dict[str, Counter[str]] = defaultdict(Counter)
    stage_failures = Counter()
    error_breakdown = Counter()
    compiled_objects: list[str] = []
    available_objects: list[str] = []

    for record in records:
        status = str(record["status"])
        by_repo[str(record["repo"])][status] += 1
        if status == "ok":
            compiled_objects.append(str(record["object_path"]))
            available_objects.append(str(record["object_path"]))
            continue
        if status == "existing":
            available_objects.append(str(record["object_path"]))
            continue
        stage_failures[str(record.get("stage", "unknown"))] += 1
        error_breakdown[summarize_error(record.get("error"))] += 1

    return {
        "sources_total": len(records),
        "built_ok": len(compiled_objects),
        "staged_existing": len(available_objects) - len(compiled_objects),
        "available_total": len(available_objects),
        "compiled_failed": len(records) - len(available_objects),
        "compiled_objects": compiled_objects,
        "available_objects": available_objects,
        "per_repo": {repo: dict(counter) for repo, counter in sorted(by_repo.items())},
        "failure_stage_breakdown": dict(stage_failures),
        "failure_error_breakdown": dict(error_breakdown.most_common(20)),
    }


def render_report(payload: dict[str, Any], records: list[dict[str, Any]]) -> str:
    summary = payload["summary"]
    lines = [
        "# Expanded Corpus Build Results",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Manifest: `{payload['manifest']}`",
        f"- Repo root: `{payload['repo_root']}`",
        f"- Macro corpus: `{payload['macro_corpus_yaml']}`",
        f"- Build root: `{payload['build_root']}`",
        f"- Sources considered: {summary['sources_total']}",
        f"- Built from source: {summary['built_ok']}",
        f"- Staged existing objects: {summary['staged_existing']}",
        f"- Available objects: {summary['available_total']}",
        f"- Failures: {summary['compiled_failed']}",
        "",
        "## Per-Repo Summary",
        "",
        "| Repo | ok | existing | error | timeout |",
        "| --- | ---: | ---: | ---: | ---: |",
    ]

    for repo, counters in summary["per_repo"].items():
        lines.append(
            f"| {repo} | {counters.get('ok', 0)} | {counters.get('existing', 0)} |"
            f" {counters.get('error', 0)} | {counters.get('timeout', 0)} |"
        )

    if summary["failure_stage_breakdown"]:
        lines.extend(
            [
                "",
                "## Failure Stages",
                "",
                "| Stage | Count |",
                "| --- | ---: |",
            ]
        )
        for stage, count in sorted(summary["failure_stage_breakdown"].items()):
            lines.append(f"| {stage} | {count} |")

    if summary["failure_error_breakdown"]:
        lines.extend(
            [
                "",
                "## Top Errors",
                "",
                "| Error | Count |",
                "| --- | ---: |",
            ]
        )
        for error, count in summary["failure_error_breakdown"].items():
            lines.append(f"| {error} | {count} |")

    failed = [record for record in records if record["status"] not in {"ok", "existing"}]
    if failed:
        lines.extend(
            [
                "",
                "## Sample Failures",
                "",
                "| Repo | Path | Stage | Error |",
                "| --- | --- | --- | --- |",
            ]
        )
        for record in failed[:50]:
            lines.append(
                f"| {record['repo']} | {record['relative_path']} | {record.get('stage', '-')}"
                f" | {summarize_error(record.get('error'))} |"
            )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- The builder scans repo sources directly from `runner/repos.yaml`.",
            "- Global include paths are pinned to repo-managed libbpf and `vendor/linux-framework` headers; host `/usr/include` is not injected.",
            "- Macro-corpus objects that are already present under `corpus/build/` are recorded as `existing` so `vm-corpus` can validate one strict availability report.",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    manifest_path = Path(args.manifest).resolve()
    repo_root = Path(args.repo_root).resolve()
    macro_corpus_yaml = Path(args.macro_corpus_yaml).resolve()
    build_root = Path(args.build_root).resolve()
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_sources is not None:
        output_json = smoke_output_path(CORPUS_DIR / "results", "expanded_corpus_build")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    selected_repos = set(args.repos or [])

    manifest = load_manifest(manifest_path, repo_root)
    macro_repo_names = {
        infer_macro_repo_name(Path(path), build_root)
        for path in load_macro_object_paths(macro_corpus_yaml).keys()
    }
    known_repos = set(manifest.keys()) | macro_repo_names
    missing_selected = sorted(selected_repos - known_repos)
    if missing_selected:
        raise SystemExit(f"selected repos missing from manifest/macro corpus: {', '.join(missing_selected)}")

    clang_binary = shutil.which(args.clang)
    if clang_binary is None:
        raise SystemExit(f"clang not found: {args.clang}")
    bpftool_binary = shutil.which(args.bpftool)
    if bpftool_binary is None:
        raise SystemExit(f"bpftool not found: {args.bpftool}")

    work_items, repo_states = build_work_items(
        manifest=manifest,
        build_root=build_root,
        selected_repos=selected_repos,
        max_sources=args.max_sources,
    )

    for header in sorted({item.vmlinux_header for item in work_items}):
        ensure_vmlinux_header(bpftool_binary, header)

    records: list[dict[str, Any]] = []
    if work_items:
        with ThreadPoolExecutor(max_workers=max(1, args.max_workers)) as executor:
            futures = {
                executor.submit(
                    compile_source,
                    item,
                    clang_binary,
                    bpftool_binary,
                    args.timeout_seconds,
                ): item
                for item in work_items
            }
            for future in as_completed(futures):
                record = future.result()
                records.append(record)
                print(f"[{record['status']}] {record['repo']} {record['relative_path']}")
                if record["status"] not in {"ok", "existing"}:
                    print(f"        {summarize_error(record.get('error'))}")

    compiled_objects = {
        str(Path(record["object_path"]).resolve())
        for record in records
        if record["status"] == "ok" and record.get("object_path")
    }
    records.extend(
        stage_macro_objects(
            macro_corpus_yaml=macro_corpus_yaml,
            build_root=build_root,
            selected_repos=selected_repos,
            compiled_objects=compiled_objects,
        )
    )
    records.sort(key=lambda record: (str(record["repo"]), str(record["relative_path"])))

    summary = compute_summary(records)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(manifest_path),
        "repo_root": str(repo_root),
        "macro_corpus_yaml": str(macro_corpus_yaml),
        "build_root": str(build_root),
        "filters": {
            "repos": sorted(selected_repos) if selected_repos else sorted(known_repos),
            "max_sources": args.max_sources,
        },
        "toolchain": {
            "clang": clang_binary,
            "bpftool": bpftool_binary,
            "global_include_dirs": [str(path) for path in GLOBAL_INCLUDE_DIRS if path.exists()],
        },
        "repo_states": repo_states,
        "summary": summary,
        "records": records,
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2))
    output_md.write_text(render_report(payload, records))
    print(f"[done] wrote {output_json}")
    print(f"[done] wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
