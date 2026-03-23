#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import platform
import shutil
import subprocess
import time
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

import yaml
from runner.libs import authoritative_output_path, maybe_refresh_latest_alias, smoke_output_path


ROOT = Path(__file__).resolve().parent
REPO_ROOT = ROOT.parent
DEFAULT_CONFIG = ROOT / "config" / "macro_corpus.yaml"
DEFAULT_MANIFEST = ROOT / "repos.yaml"
DEFAULT_INVENTORY = ROOT / "inventory.json"
DEFAULT_BUILD_ROOT = ROOT / "build"
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT / "results", "expanded_corpus_build")
DEFAULT_OUTPUT_MD = ROOT / "results" / "expanded_corpus_build.md"
DEFAULT_TIMEOUT_SECONDS = 90
DEFAULT_MAX_WORKERS = min(8, (os.cpu_count() or 4))


@dataclass(frozen=True)
class RepoSpec:
    name: str
    repo_dir: Path
    compile_include_dirs: tuple[Path, ...]


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


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compile the expanded real-world BPF corpus into corpus/build/<repo>/."
    )
    parser.add_argument("--config", default=str(DEFAULT_CONFIG), help="Macro corpus config path.")
    parser.add_argument("--manifest", default=str(DEFAULT_MANIFEST), help="Corpus repo manifest path.")
    parser.add_argument("--inventory", default=str(DEFAULT_INVENTORY), help="Fetched inventory.json path.")
    parser.add_argument("--build-root", default=str(DEFAULT_BUILD_ROOT), help="Build output root.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON), help="Structured JSON output path.")
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD), help="Markdown summary output path.")
    parser.add_argument("--clang", default="clang", help="clang binary.")
    parser.add_argument("--bpftool", default="bpftool", help="bpftool binary.")
    parser.add_argument("--repo", action="append", dest="repos", help="Only compile selected repos.")
    parser.add_argument("--max-sources", type=int, help="Limit the number of sources processed.")
    parser.add_argument("--max-workers", type=int, default=DEFAULT_MAX_WORKERS, help="Parallel compile workers.")
    parser.add_argument(
        "--timeout-seconds",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-command timeout in seconds.",
    )
    return parser.parse_args()


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


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


def load_corpus_config(path: Path) -> dict[str, Path]:
    data = yaml.safe_load(path.read_text())
    corpus = data["corpus"]
    return {
        "manifest": (REPO_ROOT / corpus["manifest"]).resolve(),
        "local_repos": (REPO_ROOT / corpus["local_repos"]).resolve(),
        "inventory": (REPO_ROOT / corpus["inventory"]).resolve(),
    }


def load_manifest(path: Path, local_repos: Path) -> dict[str, RepoSpec]:
    data = yaml.safe_load(path.read_text())
    specs: dict[str, RepoSpec] = {}
    for entry in data["repos"]:
        repo_dir = (local_repos / str(entry["name"])).resolve()
        include_dirs = tuple(
            (repo_dir / rel).resolve() for rel in entry.get("compile_include_dirs", ["."])
        )
        specs[str(entry["name"])] = RepoSpec(
            name=str(entry["name"]),
            repo_dir=repo_dir,
            compile_include_dirs=include_dirs,
        )
    return specs


def load_inventory(path: Path) -> dict[str, Any]:
    if not path.exists():
        raise SystemExit(f"inventory not found: {path}")
    payload = json.loads(path.read_text())
    if "repos" not in payload:
        raise SystemExit(f"unexpected inventory schema: {path}")
    return payload


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


def clang_sys_include_flags(clang: str) -> list[str]:
    completed = subprocess.run(
        [clang, "-v", "-E", "-"],
        input="",
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(f"unable to query system include paths via `{clang} -v -E -`")

    flags: list[str] = []
    collecting = False
    for line in completed.stderr.splitlines():
        if "<...> search starts here:" in line:
            collecting = True
            continue
        if "End of search list." in line:
            break
        if not collecting:
            continue
        include_path = line.strip()
        if include_path:
            flags.extend(["-idirafter", include_path])
    return flags


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
    inventory: dict[str, Any],
    manifest: dict[str, RepoSpec],
    build_root: Path,
    selected_repos: set[str],
    max_sources: int | None,
) -> list[WorkItem]:
    items: list[WorkItem] = []
    for repo in inventory["repos"]:
        repo_name = str(repo["name"])
        if selected_repos and repo_name not in selected_repos:
            continue
        spec = manifest.get(repo_name)
        if spec is None:
            continue

        repo_build_root = (build_root / repo_name).resolve()
        vmlinux_header = repo_build_root / "vmlinux.h"
        include_dirs = tuple(path for path in spec.compile_include_dirs if path.exists())
        for relative_path in repo.get("files", []):
            source_path = (spec.repo_dir / relative_path).resolve()
            object_rel = object_name_for_source(str(relative_path))
            output_path = (repo_build_root / object_rel).resolve()
            temp_output_path = output_path.with_suffix(".tmp.o")
            items.append(
                WorkItem(
                    repo_name=repo_name,
                    repo_dir=spec.repo_dir,
                    relative_path=str(relative_path),
                    source_path=source_path,
                    output_path=output_path,
                    temp_output_path=temp_output_path,
                    vmlinux_header=vmlinux_header,
                    include_dirs=include_dirs,
                )
            )
    items.sort(key=lambda item: (item.repo_name, item.relative_path))
    if max_sources is not None:
        return items[:max_sources]
    return items


def compile_source(
    item: WorkItem,
    clang: str,
    bpftool: str,
    sys_include_flags: list[str],
    timeout_seconds: int,
) -> dict[str, Any]:
    ensure_parent(item.output_path)
    ensure_parent(item.temp_output_path)
    include_flags = [
        flag
        for include_dir in (item.vmlinux_header.parent, *item.include_dirs)
        for flag in ("-I", str(include_dir))
    ]
    clang_command = [
        clang,
        "-O2",
        "-g",
        "-target",
        "bpf",
        f"-D__TARGET_ARCH_{target_arch_macro()}",
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "include" / "uapi"),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "include"),
        "-I",
        str(REPO_ROOT / "vendor" / "libbpf" / "src"),
        *include_flags,
        *sys_include_flags,
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


def compute_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    by_repo: dict[str, Counter[str]] = defaultdict(Counter)
    stage_failures = Counter()
    error_breakdown = Counter()
    compiled_objects: list[str] = []

    for record in records:
        by_repo[record["repo"]][record["status"]] += 1
        if record["status"] == "ok":
            compiled_objects.append(record["object_path"])
            continue
        stage_failures[str(record.get("stage", "unknown"))] += 1
        error_breakdown[summarize_error(record.get("error"))] += 1

    return {
        "sources_total": len(records),
        "compiled_ok": len(compiled_objects),
        "compiled_failed": len(records) - len(compiled_objects),
        "compiled_objects": compiled_objects,
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
        f"- Inventory: `{payload['inventory']}`",
        f"- Build root: `{payload['build_root']}`",
        f"- Sources considered: {summary['sources_total']}",
        f"- Compiled successfully: {summary['compiled_ok']}",
        f"- Compile failures: {summary['compiled_failed']}",
        "",
        "## Per-Repo Summary",
        "",
        "| Repo | ok | error | timeout |",
        "| --- | ---: | ---: | ---: |",
    ]

    for repo, counters in summary["per_repo"].items():
        lines.append(
            f"| {repo} | {counters.get('ok', 0)} | {counters.get('error', 0)} | {counters.get('timeout', 0)} |"
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

    failed = [record for record in records if record["status"] != "ok"]
    if failed:
        lines.extend(
            [
                "",
                "## Sample Failures",
                "",
                "| Repo | Source | Stage | Error |",
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
            "- The builder keeps going across compile failures and records both `clang` and `bpftool gen object` errors.",
            "- Output objects are written under `corpus/build/<repo>/...` and keep the source-relative path to avoid filename collisions.",
            "- Include paths are intentionally broad; many upstream programs still fail due to repo-specific build systems, generated headers, or kernel feature assumptions.",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    config = load_corpus_config(Path(args.config).resolve())
    manifest_path = Path(args.manifest).resolve()
    inventory_path = Path(args.inventory).resolve()
    build_root = Path(args.build_root).resolve()
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_sources is not None:
        output_json = smoke_output_path(ROOT / "results", "expanded_corpus_build")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    selected_repos = set(args.repos or [])

    clang_binary = shutil.which(args.clang)
    if clang_binary is None:
        raise SystemExit(f"clang not found: {args.clang}")
    bpftool_binary = shutil.which(args.bpftool)
    if bpftool_binary is None:
        raise SystemExit(f"bpftool not found: {args.bpftool}")

    manifest = load_manifest(manifest_path, config["local_repos"])
    inventory = load_inventory(inventory_path)
    work_items = build_work_items(
        inventory=inventory,
        manifest=manifest,
        build_root=build_root,
        selected_repos=selected_repos,
        max_sources=args.max_sources,
    )
    if not work_items:
        raise SystemExit("no source files matched the selected repos")

    sys_include_flags = clang_sys_include_flags(clang_binary)
    for header in sorted({item.vmlinux_header for item in work_items}):
        ensure_vmlinux_header(bpftool_binary, header)

    records: list[dict[str, Any]] = []
    with ThreadPoolExecutor(max_workers=max(1, args.max_workers)) as executor:
        futures = {
            executor.submit(
                compile_source,
                item,
                clang_binary,
                bpftool_binary,
                sys_include_flags,
                args.timeout_seconds,
            ): item
            for item in work_items
        }
        for future in as_completed(futures):
            record = future.result()
            records.append(record)
            print(f"[{record['status']}] {record['repo']} {record['relative_path']}")
            if record["status"] != "ok":
                print(f"        {summarize_error(record.get('error'))}")

    records.sort(key=lambda record: (record["repo"], record["relative_path"]))
    summary = compute_summary(records)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(manifest_path),
        "inventory": str(inventory_path),
        "build_root": str(build_root),
        "filters": {
            "repos": sorted(selected_repos) if selected_repos else sorted(manifest.keys()),
            "max_sources": args.max_sources,
        },
        "toolchain": {
            "clang": clang_binary,
            "bpftool": bpftool_binary,
            "clang_sys_include_flags": sys_include_flags,
        },
        "summary": summary,
        "records": records,
    }

    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2))
    maybe_refresh_latest_alias(output_json)
    output_md.write_text(render_report(payload, records))
    print(f"[done] wrote {output_json}")
    print(f"[done] wrote {output_md}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
