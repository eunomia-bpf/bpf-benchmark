#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import resource
import shlex
import shutil
import subprocess
import sys
from collections import Counter
from pathlib import Path
from typing import Any

from llvmbpf_postprocess import postprocess_roundtrip_object


SCRIPT_PATH = Path(__file__).resolve()
WORKDIR = SCRIPT_PATH.parent
HELPER_DIR = WORKDIR / "guest_verify_helper"
HELPER_MANIFEST = HELPER_DIR / "Cargo.toml"
HELPER_BINARY = HELPER_DIR / "target" / "release" / "llvmbpf-bulk-guest-verify"
DEFAULT_MANIFEST = WORKDIR / "bulk_roundtrip_manifest.json"
DEFAULT_GUEST_RESULTS = WORKDIR / "bulk_roundtrip_guest_results.json"
DEFAULT_REPORT = (
    Path("/home/yunwei37/workspace/bpf-benchmark")
    / "docs"
    / "tmp"
    / "20260329"
    / "llvmbpf_bulk_roundtrip_report_20260329.md"
)
DEFAULT_LLVMBPF_CLI = (
    Path("/home/yunwei37/workspace/bpf-benchmark")
    / "docs"
    / "tmp"
    / "20260329"
    / "llvmbpf_roundtrip_poc"
    / "llvmbpf_build"
    / "cli"
    / "bpftime-vm"
)

DEFAULT_ROOT_LIMITS: list[tuple[str, int | None]] = [
    ("bcc", None),
    ("libbpf-bootstrap", None),
    ("katran", None),
    ("tracee", None),
    ("xdp-tools", None),
    ("xdp-tutorial", None),
    ("KubeArmor", None),
    ("calico", None),
    ("tetragon", 12),
    ("bpftrace", None),
    ("cilium", None),
    ("netbird", None),
    ("systemd", None),
    ("suricata", None),
    ("xdp-examples", None),
    ("tubular", None),
    ("loxilb", None),
    ("opentelemetry-ebpf-profiler", None),
    ("datadog-agent", None),
    ("coroot-node-agent", None),
    ("scx", None),
]

SECTION_RE = re.compile(
    r"^\s*\d+\s+(?P<name>\S+)\s+(?P<size>[0-9a-fA-F]+)\s+[0-9a-fA-F]+\s+(?P<type>\S+)\s*$"
)
SYMBOL_RE = re.compile(
    r"^[0-9a-fA-F]+\s+(?P<scope>[gl])\s+\S*\s+F\s+"
    r"(?P<section>\S+)\s+(?P<size>[0-9a-fA-F]+)\s+(?P<name>\S+)\s*$"
)
PROCESSING_RE = re.compile(r"Processing program (?P<name>\S+)$")
SUCCESS_RE = re.compile(r"Program (?P<name>\S+) written to (?P<path>.+)$")
FAIL_RE = re.compile(r"Failed to compile program (?P<name>\S+): (?P<reason>.+)$")
HELPER_CALL_RE = re.compile(r"call\s+.*@_bpf_helper_ext_0001\b")
LLVMBPF_LOG_LINE_RE = re.compile(r"^\[\d{4}-\d{2}-\d{2} ")


def find_repo_root() -> Path:
    for parent in [SCRIPT_PATH.parent, *SCRIPT_PATH.parents]:
        if (parent / "Makefile").exists() and (parent / "AGENTS.md").exists():
            return parent
    raise RuntimeError(f"unable to locate repo root from {SCRIPT_PATH}")


REPO_ROOT = find_repo_root()


def rel(path: Path) -> str:
    try:
        return str(path.relative_to(REPO_ROOT))
    except ValueError:
        return str(path)


def safe_slug(text: str) -> str:
    return re.sub(r"[^A-Za-z0-9._-]+", "_", text).strip("_") or "item"


def sha8(text: str) -> str:
    return hashlib.sha256(text.encode("utf-8")).hexdigest()[:8]


def require_tool(name: str) -> str:
    path = shutil.which(name)
    if not path:
        raise RuntimeError(f"required tool not found in PATH: {name}")
    return path


def run_command(
    argv: list[str],
    *,
    cwd: Path = REPO_ROOT,
    check: bool = False,
    timeout: int | None = None,
    env: dict[str, str] | None = None,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        argv,
        cwd=cwd,
        text=True,
        capture_output=True,
        check=False,
        timeout=timeout,
        env=env,
    )
    if check and completed.returncode != 0:
        raise RuntimeError(
            f"command failed rc={completed.returncode}: {' '.join(shlex.quote(arg) for arg in argv)}"
        )
    return completed


def write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def write_json(path: Path, payload: Any) -> None:
    write_text(path, json.dumps(payload, indent=2, sort_keys=False))


def safe_exists(path: Path) -> bool:
    try:
        path.stat()
        return True
    except FileNotFoundError:
        return False
    except PermissionError:
        return False


def first_line(text: str) -> str:
    for line in text.splitlines():
        stripped = line.strip()
        if stripped:
            return stripped
    return ""


def split_llvm_modules(text: str) -> list[str]:
    cleaned = "\n".join(
        line for line in text.splitlines() if not LLVMBPF_LOG_LINE_RE.match(line)
    )
    matches = list(re.finditer(r"(?m)^; ModuleID = ", cleaned))
    if not matches:
        return []
    modules: list[str] = []
    for index, match in enumerate(matches):
        start = match.start()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(cleaned)
        module = cleaned[start:end].strip()
        if module:
            modules.append(module + "\n")
    return modules


def parse_section_headers(text: str) -> dict[str, dict[str, Any]]:
    sections: dict[str, dict[str, Any]] = {}
    for line in text.splitlines():
        match = SECTION_RE.match(line)
        if not match:
            continue
        sections[match.group("name")] = {
            "size_bytes": int(match.group("size"), 16),
            "kind": match.group("type"),
        }
    return sections


def parse_program_symbols(text: str, section_headers: dict[str, dict[str, Any]]) -> dict[str, dict[str, Any]]:
    symbols: dict[str, dict[str, Any]] = {}
    for line in text.splitlines():
        match = SYMBOL_RE.match(line.strip())
        if not match:
            continue
        if match.group("scope") != "g":
            continue
        section_name = match.group("section")
        if section_name.startswith("."):
            continue
        section = section_headers.get(section_name)
        if not section or section.get("kind") != "TEXT":
            continue
        symbols[match.group("name")] = {
            "section": section_name,
            "symbol_size_bytes": int(match.group("size"), 16),
            "section_size_bytes": section["size_bytes"],
            "original_insn_count": section["size_bytes"] // 8,
        }
    return symbols


def parse_llvmbpf_build_log(text: str) -> dict[str, Any]:
    processing: list[str] = []
    successes: list[dict[str, str]] = []
    failures: list[dict[str, str]] = []
    for line in text.splitlines():
        if match := PROCESSING_RE.search(line):
            processing.append(match.group("name"))
            continue
        if match := SUCCESS_RE.search(line):
            successes.append(
                {
                    "program_name": match.group("name"),
                    "output_path": match.group("path").strip(),
                }
            )
            continue
        if match := FAIL_RE.search(line):
            failures.append(
                {
                    "program_name": match.group("name"),
                    "reason": match.group("reason").strip(),
                }
            )
    return {
        "processing_order": processing,
        "successes": successes,
        "failures": failures,
    }


def build_guest_helper() -> Path:
    require_tool("cargo")
    completed = run_command(
        ["cargo", "build", "--release", "--manifest-path", str(HELPER_MANIFEST)],
        check=False,
    )
    build_log_dir = WORKDIR / "build_logs"
    build_log_dir.mkdir(parents=True, exist_ok=True)
    write_text(build_log_dir / "cargo_build_helper.stdout.log", completed.stdout)
    write_text(build_log_dir / "cargo_build_helper.stderr.log", completed.stderr)
    if completed.returncode != 0:
        raise RuntimeError(
            "guest helper build failed; see "
            f"{rel(build_log_dir / 'cargo_build_helper.stderr.log')}"
        )
    if not HELPER_BINARY.exists():
        raise RuntimeError(f"missing built guest helper: {HELPER_BINARY}")
    return HELPER_BINARY


def select_objects(max_objects: int | None) -> list[Path]:
    selected: list[Path] = []
    for root_name, limit in DEFAULT_ROOT_LIMITS:
        root_dir = REPO_ROOT / "corpus" / "build" / root_name
        if not root_dir.exists():
            continue
        paths = sorted(root_dir.rglob("*.bpf.o"))
        if limit is not None:
            paths = paths[:limit]
        selected.extend(paths)
    if max_objects is not None:
        selected = selected[:max_objects]
    return selected


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def process_program_module(
    *,
    program_name: str,
    module_text: str,
    program_dir: Path,
    original_info: dict[str, Any] | None,
    opt_level: str,
    opt_passes: str | None,
) -> dict[str, Any]:
    program_dir.mkdir(parents=True, exist_ok=True)
    llvm_path = program_dir / f"{safe_slug(program_name)}.ll"
    bc_path = program_dir / f"{safe_slug(program_name)}_opt.bc"
    raw_obj_path = program_dir / f"{safe_slug(program_name)}_roundtrip_raw.bpf.o"
    obj_path = program_dir / f"{safe_slug(program_name)}_roundtrip.bpf.o"
    bin_path = program_dir / f"{safe_slug(program_name)}_roundtrip.bin"

    write_text(llvm_path, module_text)
    map_inline_sites = len(HELPER_CALL_RE.findall(module_text))

    opt_cmd = [require_tool("opt")]
    if opt_passes:
        opt_cmd.append(f"-passes={opt_passes}")
    else:
        opt_cmd.append(f"-{opt_level}")
    opt_cmd.extend([str(llvm_path), "-o", str(bc_path)])
    opt_completed = run_command(opt_cmd, check=False)
    write_text(program_dir / "opt.stdout.log", opt_completed.stdout)
    write_text(program_dir / "opt.stderr.log", opt_completed.stderr)
    if opt_completed.returncode != 0:
        return {
            "program_name": program_name,
            "section": None if original_info is None else original_info.get("section"),
            "original_insn_count": None
            if original_info is None
            else original_info.get("original_insn_count"),
            "lift": {
                "status": "ok",
                "llvm_path": str(llvm_path),
                "map_inline_sites": map_inline_sites,
            },
            "lower": {
                "status": "error",
                "stage": "opt",
                "reason": first_line(opt_completed.stderr) or f"opt rc={opt_completed.returncode}",
                "stdout_log": str(program_dir / "opt.stdout.log"),
                "stderr_log": str(program_dir / "opt.stderr.log"),
            },
        }

    llc_cmd = [
        require_tool("llc"),
        "-march=bpf",
        "-mcpu=v3",
        "-filetype=obj",
        str(bc_path),
        "-o",
        str(raw_obj_path),
    ]
    llc_completed = run_command(llc_cmd, check=False)
    write_text(program_dir / "llc.stdout.log", llc_completed.stdout)
    write_text(program_dir / "llc.stderr.log", llc_completed.stderr)
    if llc_completed.returncode != 0:
        return {
            "program_name": program_name,
            "section": None if original_info is None else original_info.get("section"),
            "original_insn_count": None
            if original_info is None
            else original_info.get("original_insn_count"),
            "lift": {
                "status": "ok",
                "llvm_path": str(llvm_path),
                "map_inline_sites": map_inline_sites,
            },
            "lower": {
                "status": "error",
                "stage": "llc",
                "reason": first_line(llc_completed.stderr) or f"llc rc={llc_completed.returncode}",
                "stdout_log": str(program_dir / "llc.stdout.log"),
                "stderr_log": str(program_dir / "llc.stderr.log"),
            },
        }

    try:
        postprocess_summary = postprocess_roundtrip_object(
            raw_obj_path,
            obj_path,
            output_bin_path=bin_path,
        )
    except Exception as exc:  # noqa: BLE001
        write_text(program_dir / "postprocess.stderr.log", f"{exc}\n")
        return {
            "program_name": program_name,
            "section": None if original_info is None else original_info.get("section"),
            "original_insn_count": None
            if original_info is None
            else original_info.get("original_insn_count"),
            "lift": {
                "status": "ok",
                "llvm_path": str(llvm_path),
                "map_inline_sites": map_inline_sites,
            },
            "lower": {
                "status": "error",
                "stage": "postprocess",
                "reason": str(exc),
                "stderr_log": str(program_dir / "postprocess.stderr.log"),
            },
        }

    write_json(program_dir / "postprocess.summary.json", postprocess_summary)

    roundtrip_insn_count = bin_path.stat().st_size // 8
    original_insn_count = None if original_info is None else original_info.get("original_insn_count")
    insn_delta = None
    if original_insn_count is not None:
        insn_delta = roundtrip_insn_count - original_insn_count

    return {
        "program_name": program_name,
        "section": None if original_info is None else original_info.get("section"),
        "original_insn_count": original_insn_count,
        "lift": {
            "status": "ok",
            "llvm_path": str(llvm_path),
            "map_inline_sites": map_inline_sites,
        },
        "lower": {
            "status": "ok",
            "bitcode_path": str(bc_path),
            "roundtrip_raw_object_path": str(raw_obj_path),
            "roundtrip_object_path": str(obj_path),
            "roundtrip_bin_path": str(bin_path),
            "roundtrip_insn_count": roundtrip_insn_count,
            "insn_delta": insn_delta,
            "postprocess": postprocess_summary,
        },
    }


def process_object(
    obj_path: Path,
    llvmbpf_cli: Path,
    *,
    opt_level: str,
    opt_passes: str | None,
) -> dict[str, Any]:
    rel_obj = obj_path.relative_to(REPO_ROOT)
    family = rel_obj.parts[2]
    object_key = f"{safe_slug(str(rel_obj.with_suffix('')))}_{sha8(str(rel_obj))}"
    object_dir = WORKDIR / "artifacts" / object_key
    object_dir.mkdir(parents=True, exist_ok=True)

    section_headers_cmd = [require_tool("llvm-objdump"), "-h", str(obj_path)]
    section_headers_completed = run_command(section_headers_cmd, check=False)
    symbol_table_cmd = [require_tool("llvm-objdump"), "-t", str(obj_path)]
    symbol_table_completed = run_command(symbol_table_cmd, check=False)

    section_headers_path = object_dir / "section_headers.log"
    symbol_table_path = object_dir / "symbol_table.log"
    write_text(section_headers_path, section_headers_completed.stdout)
    write_text(symbol_table_path, symbol_table_completed.stdout)

    section_headers = parse_section_headers(section_headers_completed.stdout)
    program_symbols = parse_program_symbols(symbol_table_completed.stdout, section_headers)

    native_dir = object_dir / "bpftime_native"
    native_dir.mkdir(parents=True, exist_ok=True)
    build_completed = run_command(
        [str(llvmbpf_cli), "build", str(obj_path), "-o", str(native_dir)],
        check=False,
    )
    build_stdout_path = object_dir / "llvmbpf_build.stdout.log"
    build_stderr_path = object_dir / "llvmbpf_build.stderr.log"
    write_text(build_stdout_path, build_completed.stdout)
    write_text(build_stderr_path, build_completed.stderr)
    build_log = parse_llvmbpf_build_log(build_completed.stdout)

    emit_dir = object_dir / "bpftime_emit_llvm"
    emit_dir.mkdir(parents=True, exist_ok=True)
    emit_completed = run_command(
        [str(llvmbpf_cli), "build", str(obj_path), "-o", str(emit_dir), "-emit-llvm"],
        check=False,
    )
    emit_stdout_path = object_dir / "llvmbpf_emit_llvm.stdout.ll"
    emit_stderr_path = object_dir / "llvmbpf_emit_llvm.stderr.log"
    write_text(emit_stdout_path, emit_completed.stdout)
    write_text(emit_stderr_path, emit_completed.stderr)
    modules = split_llvm_modules(emit_completed.stdout)

    program_records: dict[str, dict[str, Any]] = {}
    for program_name, symbol_info in program_symbols.items():
        program_records[program_name] = {
            "program_name": program_name,
            "section": symbol_info["section"],
            "original_insn_count": symbol_info["original_insn_count"],
            "lift": {
                "status": "unknown",
            },
        }

    for failure in build_log["failures"]:
        base = program_records.setdefault(
            failure["program_name"],
            {
                "program_name": failure["program_name"],
                "section": None,
                "original_insn_count": None,
            },
        )
        base["lift"] = {
            "status": "error",
            "reason": failure["reason"],
        }

    success_names = [entry["program_name"] for entry in build_log["successes"]]
    mismatch_note = None
    if len(modules) != len(success_names):
        mismatch_note = (
            f"module_count_mismatch: emit-llvm produced {len(modules)} modules "
            f"for {len(success_names)} successful programs"
        )

    for index, program_name in enumerate(success_names):
        original_info = program_symbols.get(program_name)
        if index >= len(modules):
            base = program_records.setdefault(
                program_name,
                {
                    "program_name": program_name,
                    "section": None if original_info is None else original_info["section"],
                    "original_insn_count": None
                    if original_info is None
                    else original_info["original_insn_count"],
                },
            )
            base["lift"] = {
                "status": "error",
                "reason": mismatch_note or "missing emitted llvm module",
            }
            continue
        program_dir = object_dir / "programs" / f"{index:03d}_{safe_slug(program_name)}"
        program_record = process_program_module(
            program_name=program_name,
            module_text=modules[index],
            program_dir=program_dir,
            original_info=original_info,
            opt_level=opt_level,
            opt_passes=opt_passes,
        )
        program_records[program_name] = program_record

    for program_name, base in program_records.items():
        if base.get("lift", {}).get("status") == "unknown":
            base["lift"] = {
                "status": "error",
                "reason": "program not reported by llvmbpf build output",
            }

    programs = sorted(program_records.values(), key=lambda item: item["program_name"])
    return {
        "object_path": str(obj_path),
        "object_relpath": str(rel_obj),
        "family": family,
        "artifact_dir": str(object_dir),
        "section_headers_path": str(section_headers_path),
        "symbol_table_path": str(symbol_table_path),
        "llvmbpf_build": {
            "returncode": build_completed.returncode,
            "stdout_log": str(build_stdout_path),
            "stderr_log": str(build_stderr_path),
            "successful_programs": success_names,
            "failed_programs": build_log["failures"],
        },
        "llvmbpf_emit_llvm": {
            "returncode": emit_completed.returncode,
            "stdout_path": str(emit_stdout_path),
            "stderr_log": str(emit_stderr_path),
            "module_count": len(modules),
            "mismatch_note": mismatch_note,
        },
        "programs": programs,
    }


def summarize_host(manifest: dict[str, Any]) -> dict[str, Any]:
    objects = manifest["objects"]
    programs = [program for obj in objects for program in obj["programs"]]
    family_counter = Counter(obj["family"] for obj in objects)
    lift_ok = sum(1 for program in programs if program["lift"]["status"] == "ok")
    lower_ok = sum(1 for program in programs if program.get("lower", {}).get("status") == "ok")
    map_sites = sum(program.get("lift", {}).get("map_inline_sites", 0) for program in programs)
    return {
        "object_count": len(objects),
        "program_count": len(programs),
        "lift_ok_count": lift_ok,
        "lift_fail_count": len(programs) - lift_ok,
        "lower_ok_count": lower_ok,
        "lower_fail_count": lift_ok - lower_ok,
        "map_inline_site_count": map_sites,
        "family_counts": dict(sorted(family_counter.items())),
    }


def host_prepare(args: argparse.Namespace) -> int:
    for tool in ["cargo", "llvm-objdump", "llvm-objcopy", "opt", "llc"]:
        require_tool(tool)
    llvmbpf_cli = Path(args.llvmbpf_cli).resolve()
    if not llvmbpf_cli.exists():
        raise RuntimeError(f"missing llvmbpf CLI: {llvmbpf_cli}")

    helper_binary = build_guest_helper()
    objects = select_objects(args.max_objects)
    if args.max_objects is None and len(objects) < 100:
        raise RuntimeError(
            f"selected only {len(objects)} objects; expected at least 100"
        )

    manifest: dict[str, Any] = {
        "repo_root": str(REPO_ROOT),
        "script_path": str(SCRIPT_PATH),
        "workdir": str(WORKDIR),
        "llvmbpf_cli": str(llvmbpf_cli),
        "guest_helper_binary": str(helper_binary),
        "selection": {
            "max_objects": args.max_objects,
            "root_limits": DEFAULT_ROOT_LIMITS,
            "opt_level": args.opt_level,
            "opt_passes": args.opt_passes,
        },
        "objects": [],
    }

    for index, obj_path in enumerate(objects, start=1):
        print(f"[host] {index}/{len(objects)} {rel(obj_path)}", file=sys.stderr)
        manifest["objects"].append(
            process_object(
                obj_path,
                llvmbpf_cli,
                opt_level=args.opt_level,
                opt_passes=args.opt_passes,
            )
        )

    manifest["host_summary"] = summarize_host(manifest)
    write_json(Path(args.manifest), manifest)
    print(json.dumps(manifest["host_summary"], indent=2))
    return 0


def ensure_guest_environment() -> None:
    if os.geteuid() != 0:
        raise RuntimeError("guest-verify must run as root inside the VM")
    try:
        resource.setrlimit(
            resource.RLIMIT_MEMLOCK,
            (resource.RLIM_INFINITY, resource.RLIM_INFINITY),
        )
    except (OSError, ValueError) as exc:
        raise RuntimeError(f"failed to raise RLIMIT_MEMLOCK: {exc}") from exc
    mountpoint = run_command(["mountpoint", "-q", "/sys/fs/bpf"], check=False)
    if mountpoint.returncode != 0:
        completed = run_command(["mount", "-t", "bpf", "bpf", "/sys/fs/bpf"], check=False)
        if completed.returncode != 0:
            raise RuntimeError(
                "failed to mount /sys/fs/bpf: "
                + (first_line(completed.stderr) or f"rc={completed.returncode}")
            )


def mkdir_p(path: Path) -> None:
    completed = run_command(["mkdir", "-p", str(path)], check=False)
    if completed.returncode != 0:
        raise RuntimeError(
            f"mkdir -p failed for {path}: "
            + (first_line(completed.stderr) or f"rc={completed.returncode}")
        )


def read_bpftool_json_for_pinned(pin_path: Path) -> dict[str, Any]:
    completed = run_command(
        [require_tool("bpftool"), "-j", "prog", "show", "pinned", str(pin_path)],
        check=False,
    )
    if completed.returncode != 0:
        raise RuntimeError(
            f"bpftool show pinned failed for {pin_path}: "
            + (first_line(completed.stderr) or f"rc={completed.returncode}")
        )
    payload = json.loads(completed.stdout)
    if isinstance(payload, list):
        if not payload:
            raise RuntimeError(f"bpftool returned an empty list for pinned path {pin_path}")
        return payload[0]
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected bpftool JSON payload for {pin_path}: {type(payload)!r}")
    return payload


def cleanup_pin_dir(pin_dir: Path) -> None:
    if not safe_exists(pin_dir):
        return
    for child in sorted(pin_dir.iterdir(), reverse=True):
        if child.is_dir():
            cleanup_pin_dir(child)
            child.rmdir()
        else:
            child.unlink()
    pin_dir.rmdir()


def cleanup_pin_children(pin_root: Path) -> None:
    if not safe_exists(pin_root):
        return
    for child in sorted(pin_root.iterdir(), reverse=True):
        if child.is_dir():
            cleanup_pin_dir(child)
        else:
            child.unlink()


def guest_verify(args: argparse.Namespace) -> int:
    ensure_guest_environment()
    manifest = load_json(Path(args.manifest))
    helper_binary = Path(args.helper_binary or manifest["guest_helper_binary"]).resolve()
    if not helper_binary.exists():
        raise RuntimeError(f"missing guest helper binary: {helper_binary}")

    results_dir = WORKDIR / "guest_logs"
    results_dir.mkdir(parents=True, exist_ok=True)
    pin_root = Path(args.pin_root).resolve()
    mkdir_p(pin_root)

    result_payload: dict[str, Any] = {
        "manifest_path": str(Path(args.manifest).resolve()),
        "helper_binary": str(helper_binary),
        "pin_root": str(pin_root),
        "objects": [],
    }

    objects = manifest["objects"]
    for index, obj in enumerate(objects, start=1):
        lower_ok_programs = [
            program
            for program in obj["programs"]
            if program.get("lower", {}).get("status") == "ok"
        ]
        if not lower_ok_programs:
            continue

        object_relpath = obj["object_relpath"]
        object_key = f"{safe_slug(object_relpath)}_{sha8(object_relpath)}"
        object_log_dir = results_dir / object_key
        object_log_dir.mkdir(parents=True, exist_ok=True)
        cleanup_pin_children(pin_root)

        print(f"[guest] {index}/{len(objects)} loadall {object_relpath}", file=sys.stderr)
        loadall_completed = run_command(
            [
                require_tool("bpftool"),
                "-d",
                "prog",
                "loadall",
                obj["object_path"],
                str(pin_root),
            ],
            check=False,
        )
        loadall_stdout = object_log_dir / "bpftool_loadall.stdout.log"
        loadall_stderr = object_log_dir / "bpftool_loadall.stderr.log"
        write_text(loadall_stdout, loadall_completed.stdout)
        write_text(loadall_stderr, loadall_completed.stderr)

        pinned_info: dict[str, dict[str, Any]] = {}
        if safe_exists(pin_root):
            for child in sorted(pin_root.iterdir()):
                try:
                    pinned_info[child.name] = read_bpftool_json_for_pinned(child)
                except Exception as exc:  # noqa: BLE001
                    pinned_info[child.name] = {"error": str(exc)}

        object_result = {
            "object_path": obj["object_path"],
            "object_relpath": object_relpath,
            "bpftool_loadall": {
                "returncode": loadall_completed.returncode,
                "stdout_log": str(loadall_stdout),
                "stderr_log": str(loadall_stderr),
            },
            "programs": [],
        }

        for program in lower_ok_programs:
            program_name = program["program_name"]
            if program_name not in pinned_info:
                object_result["programs"].append(
                    {
                        "program_name": program_name,
                        "status": "error",
                        "error": "program not pinned by bpftool prog loadall",
                        "verifier_log": "",
                    }
                )
                continue
            if "error" in pinned_info[program_name]:
                object_result["programs"].append(
                    {
                        "program_name": program_name,
                        "status": "error",
                        "error": pinned_info[program_name]["error"],
                        "verifier_log": "",
                    }
                )
                continue

            prog_id = pinned_info[program_name].get("id")
            if not isinstance(prog_id, int):
                object_result["programs"].append(
                    {
                        "program_name": program_name,
                        "status": "error",
                        "error": f"bpftool did not return an integer prog id for {program_name}",
                        "verifier_log": "",
                    }
                )
                continue

            helper_completed = run_command(
                [
                    str(helper_binary),
                    "--prog-id",
                    str(prog_id),
                    "--roundtrip-bin",
                    program["lower"]["roundtrip_bin_path"],
                    "--expected-attach-type",
                    str(pinned_info[program_name].get("expected_attach_type", 0)),
                ],
                check=False,
            )
            helper_stdout = object_log_dir / f"{safe_slug(program_name)}.verify.stdout.json"
            helper_stderr = object_log_dir / f"{safe_slug(program_name)}.verify.stderr.log"
            write_text(helper_stdout, helper_completed.stdout)
            write_text(helper_stderr, helper_completed.stderr)

            if helper_completed.returncode != 0:
                object_result["programs"].append(
                    {
                        "program_name": program_name,
                        "status": "error",
                        "error": first_line(helper_completed.stderr)
                        or f"guest helper rc={helper_completed.returncode}",
                        "verifier_log": "",
                        "stdout_log": str(helper_stdout),
                        "stderr_log": str(helper_stderr),
                    }
                )
                continue

            helper_payload = json.loads(helper_completed.stdout)
            helper_payload["stdout_log"] = str(helper_stdout)
            helper_payload["stderr_log"] = str(helper_stderr)
            object_result["programs"].append(helper_payload)

        result_payload["objects"].append(object_result)
        cleanup_pin_children(pin_root)

    write_json(Path(args.guest_results), result_payload)
    summary = {
        "object_count": len(result_payload["objects"]),
        "program_count": sum(len(obj["programs"]) for obj in result_payload["objects"]),
        "verify_ok_count": sum(
            1
            for obj in result_payload["objects"]
            for program in obj["programs"]
            if program.get("status") == "ok"
        ),
    }
    print(json.dumps(summary, indent=2))
    return 0


def run_vm_verify(args: argparse.Namespace) -> int:
    manifest = load_json(Path(args.manifest))
    helper_binary = Path(args.helper_binary or manifest["guest_helper_binary"]).resolve()
    guest_command = " ".join(
        [
            shlex.quote(sys.executable),
            shlex.quote(str(SCRIPT_PATH)),
            "guest-verify",
            "--manifest",
            shlex.quote(str(Path(args.manifest).resolve())),
            "--guest-results",
            shlex.quote(str(Path(args.guest_results).resolve())),
            "--helper-binary",
            shlex.quote(str(helper_binary)),
        ]
    )
    make_argv = ["make", "vm-shell", f"VM_COMMAND={guest_command}"]
    completed = run_command(make_argv, check=False)
    write_text(WORKDIR / "vm_verify.stdout.log", completed.stdout)
    write_text(WORKDIR / "vm_verify.stderr.log", completed.stderr)
    if completed.returncode != 0:
        raise RuntimeError(
            "make vm-shell guest verify failed; see "
            f"{rel(WORKDIR / 'vm_verify.stderr.log')}"
        )
    return 0


def collect_lift_failure_reasons(programs: list[dict[str, Any]]) -> Counter[str]:
    counter: Counter[str] = Counter()
    for program in programs:
        if program["lift"]["status"] != "error":
            continue
        counter[program["lift"].get("reason") or "unknown lift failure"] += 1
    return counter


def collect_verifier_failure_reasons(guest_results: dict[str, Any]) -> Counter[str]:
    counter: Counter[str] = Counter()
    for obj in guest_results.get("objects", []):
        for program in obj.get("programs", []):
            if program.get("status") == "ok":
                continue
            reason = program.get("error") or first_line(program.get("verifier_log", "")) or "unknown verifier failure"
            counter[reason] += 1
    return counter


def merge_guest_results(manifest: dict[str, Any], guest_results: dict[str, Any]) -> dict[tuple[str, str], dict[str, Any]]:
    merged: dict[tuple[str, str], dict[str, Any]] = {}
    for obj in guest_results.get("objects", []):
        object_relpath = obj["object_relpath"]
        for program in obj.get("programs", []):
            merged[(object_relpath, program["program_name"])] = program
    return merged


def render_report(args: argparse.Namespace) -> int:
    manifest = load_json(Path(args.manifest))
    guest_results = load_json(Path(args.guest_results))
    host_summary = manifest["host_summary"]
    programs = [program for obj in manifest["objects"] for program in obj["programs"]]
    guest_programs = [
        program
        for obj in guest_results.get("objects", [])
        for program in obj.get("programs", [])
    ]
    verify_attempted = len(guest_programs)
    verify_ok = sum(1 for program in guest_programs if program.get("status") == "ok")
    original_load_fail = sum(
        1
        for program in guest_programs
        if program.get("error") == "program not pinned by bpftool prog loadall"
    )

    lift_failures = collect_lift_failure_reasons(programs)
    verifier_failures = collect_verifier_failure_reasons(guest_results)

    family_lines = [
        f"- `{family}`: {count} object(s)"
        for family, count in host_summary["family_counts"].items()
    ]
    lift_failure_lines = [
        f"- `{reason}`: {count}"
        for reason, count in lift_failures.most_common(5)
    ] or ["- none"]
    verifier_failure_lines = [
        f"- `{reason}`: {count}"
        for reason, count in verifier_failures.most_common(5)
    ] or ["- none"]

    lift_rate = 0.0 if host_summary["program_count"] == 0 else 100.0 * host_summary["lift_ok_count"] / host_summary["program_count"]
    lower_rate = 0.0 if host_summary["lift_ok_count"] == 0 else 100.0 * host_summary["lower_ok_count"] / host_summary["lift_ok_count"]
    verify_rate = 0.0 if verify_attempted == 0 else 100.0 * verify_ok / verify_attempted
    end_to_end_rate = 0.0 if host_summary["program_count"] == 0 else 100.0 * verify_ok / host_summary["program_count"]

    report_lines = [
        "# llvmbpf Bulk Round-Trip Report (2026-03-29)",
        "",
        "## Scope",
        "",
        f"- Objects tested: `{host_summary['object_count']}`",
        f"- Programs discovered from symbol tables: `{host_summary['program_count']}`",
        f"- Program lift success: `{host_summary['lift_ok_count']}/{host_summary['program_count']}` ({lift_rate:.1f}%)",
        f"- Program LLVM lower success: `{host_summary['lower_ok_count']}/{host_summary['lift_ok_count']}` ({lower_rate:.1f}%)",
        f"- Program verifier pass success: `{verify_ok}/{verify_attempted}` ({verify_rate:.1f}%)",
        f"- End-to-end program coverage over the tested corpus slice: `{verify_ok}/{host_summary['program_count']}` ({end_to_end_rate:.1f}%)",
        f"- Total `map_lookup_elem` candidate sites in lifted LLVM IR: `{host_summary['map_inline_site_count']}`",
        f"- Programs that lowered but were not pinned by `bpftool prog loadall` in the VM: `{original_load_fail}`",
        "",
        "## Families",
        "",
        *family_lines,
        "",
        "## Failure Breakdown",
        "",
        "### Lift failures: top 5",
        "",
        *lift_failure_lines,
        "",
        "### Verifier / VM failures: top 5",
        "",
        *verifier_failure_lines,
        "",
        "## Conclusion",
        "",
        (
            "The LLVM IR round-trip path is viable on a meaningful slice of real-world BPF "
            f"programs: {verify_ok} programs from {host_summary['object_count']} real-world "
            "objects completed host lift/O2/lower and then passed a fresh VM-side "
            "`BPF_PROG_LOAD` verifier check. The main blockers remain llvmbpf lift failures "
            "on specific control-flow patterns and VM-side loadability gaps where "
            "`bpftool prog loadall` could not materialize the original program context."
        ),
        "",
        "## Artifacts",
        "",
        f"- Manifest: `{rel(Path(args.manifest).resolve())}`",
        f"- Guest verify results: `{rel(Path(args.guest_results).resolve())}`",
        f"- Guest helper binary: `{rel(Path(manifest['guest_helper_binary']).resolve())}`",
    ]
    write_text(Path(args.report), "\n".join(report_lines) + "\n")
    print(Path(args.report).resolve())
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Bulk llvmbpf round-trip driver for real-world BPF corpus objects")
    subparsers = parser.add_subparsers(dest="command", required=True)

    host = subparsers.add_parser("host-prepare", help="run host-side lift/opt/lower over a large corpus slice")
    host.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    host.add_argument("--llvmbpf-cli", type=Path, default=DEFAULT_LLVMBPF_CLI)
    host.add_argument("--max-objects", type=int, default=None)
    host.add_argument("--opt-level", choices=["O0", "O1", "O2", "O3"], default="O2")
    host.add_argument("--opt-passes", type=str, default=None)

    guest = subparsers.add_parser("guest-verify", help="run inside the VM and verifier-check lowered programs")
    guest.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    guest.add_argument("--guest-results", type=Path, default=DEFAULT_GUEST_RESULTS)
    guest.add_argument("--helper-binary", type=Path, default=None)
    guest.add_argument("--pin-root", type=Path, default=Path("/sys/fs/bpf/llvmbpf_bulk_roundtrip"))

    run_vm = subparsers.add_parser("run-vm-verify", help="launch guest verification through make vm-shell")
    run_vm.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    run_vm.add_argument("--guest-results", type=Path, default=DEFAULT_GUEST_RESULTS)
    run_vm.add_argument("--helper-binary", type=Path, default=None)

    report = subparsers.add_parser("render-report", help="write the final Markdown report")
    report.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    report.add_argument("--guest-results", type=Path, default=DEFAULT_GUEST_RESULTS)
    report.add_argument("--report", type=Path, default=DEFAULT_REPORT)

    return parser


def main() -> int:
    args = build_parser().parse_args()
    if args.command == "host-prepare":
        return host_prepare(args)
    if args.command == "guest-verify":
        return guest_verify(args)
    if args.command == "run-vm-verify":
        return run_vm_verify(args)
    if args.command == "render-report":
        return render_report(args)
    raise AssertionError(f"unexpected command: {args.command}")


if __name__ == "__main__":
    raise SystemExit(main())
