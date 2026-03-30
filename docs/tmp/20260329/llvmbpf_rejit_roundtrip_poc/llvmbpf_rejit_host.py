#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shlex
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Any


SCRIPT_PATH = Path(__file__).resolve()
WORKDIR = SCRIPT_PATH.parent


def find_repo_root() -> Path:
    for parent in [SCRIPT_PATH.parent, *SCRIPT_PATH.parents]:
        if (parent / "Makefile").exists() and (parent / "AGENTS.md").exists():
            return parent
    raise RuntimeError(f"unable to locate repo root from {SCRIPT_PATH}")


REPO_ROOT = find_repo_root()
BULK_DIR = REPO_ROOT / "docs" / "tmp" / "20260329" / "llvmbpf_bulk_roundtrip"
sys.path.insert(0, str(BULK_DIR))

from llvmbpf_postprocess import postprocess_roundtrip_object  # noqa: E402


HOST_LIFTER = WORKDIR / "build" / "llvmbpf-raw-lift"


def require_tool(name: str) -> str:
    path = shutil.which(name)
    if not path:
        raise RuntimeError(f"required tool not found in PATH: {name}")
    return path


def run_command(
    argv: list[str],
    *,
    cwd: Path = REPO_ROOT,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        argv,
        cwd=cwd,
        text=True,
        capture_output=True,
        check=False,
    )
    if stdout_path is not None:
        stdout_path.parent.mkdir(parents=True, exist_ok=True)
        stdout_path.write_text(completed.stdout, encoding="utf-8")
    if stderr_path is not None:
        stderr_path.parent.mkdir(parents=True, exist_ok=True)
        stderr_path.write_text(completed.stderr, encoding="utf-8")
    return completed


def write_json(path: Path, payload: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")


def build_tools() -> None:
    completed = run_command(
        ["make", "-C", str(WORKDIR), "host-lifter", "guest-helper"],
        stdout_path=WORKDIR / "build_tools.stdout.log",
        stderr_path=WORKDIR / "build_tools.stderr.log",
    )
    if completed.returncode != 0:
        raise RuntimeError(
            "tool build failed; see "
            f"{WORKDIR / 'build_tools.stdout.log'} and {WORKDIR / 'build_tools.stderr.log'}"
        )


def prepare_program(program: dict[str, Any], opt_level: str, bpf_stack_size: int) -> dict[str, Any]:
    program_dir = Path(program["program_dir"]).resolve()
    original_bin = Path(program["original_bin_path"]).resolve()
    raw_ll = program_dir / "lifted.ll"
    opt_bc = program_dir / "opt.bc"
    raw_obj = program_dir / "roundtrip_raw.bpf.o"
    obj_path = program_dir / "roundtrip.bpf.o"
    bin_path = program_dir / "roundtrip.bin"

    lift = run_command(
        [str(HOST_LIFTER), "emit-llvm", str(original_bin)],
        stdout_path=raw_ll,
        stderr_path=program_dir / "lift.stderr.log",
    )
    if lift.returncode != 0:
        return {
            "program_id": program["program_id"],
            "program_name": program["program_name"],
            "status": "lift_failed",
            "error": (program_dir / "lift.stderr.log").read_text(encoding="utf-8").strip(),
        }

    opt = run_command(
        [require_tool("opt"), f"-{opt_level}", str(raw_ll), "-o", str(opt_bc)],
        stdout_path=program_dir / "opt.stdout.log",
        stderr_path=program_dir / "opt.stderr.log",
    )
    if opt.returncode != 0:
        return {
            "program_id": program["program_id"],
            "program_name": program["program_name"],
            "status": "opt_failed",
            "error": (program_dir / "opt.stderr.log").read_text(encoding="utf-8").strip(),
        }

    llc = run_command(
        [
            require_tool("llc"),
            "-march=bpf",
            "-mcpu=v3",
            f"--bpf-stack-size={bpf_stack_size}",
            "-filetype=obj",
            str(opt_bc),
            "-o",
            str(raw_obj),
        ],
        stdout_path=program_dir / "llc.stdout.log",
        stderr_path=program_dir / "llc.stderr.log",
    )
    if llc.returncode != 0:
        return {
            "program_id": program["program_id"],
            "program_name": program["program_name"],
            "status": "llc_failed",
            "error": (program_dir / "llc.stderr.log").read_text(encoding="utf-8").strip(),
        }

    try:
        postprocess_summary = postprocess_roundtrip_object(
            raw_obj,
            obj_path,
            output_bin_path=bin_path,
            original_bin_path=original_bin,
        )
    except Exception as exc:  # noqa: BLE001
        (program_dir / "postprocess.stderr.log").write_text(f"{exc}\n", encoding="utf-8")
        return {
            "program_id": program["program_id"],
            "program_name": program["program_name"],
            "status": "postprocess_failed",
            "error": str(exc),
        }

    write_json(program_dir / "postprocess.summary.json", postprocess_summary)
    return {
        "program_id": program["program_id"],
        "program_name": program["program_name"],
        "status": "ok",
        "roundtrip_bin_path": str(bin_path),
        "roundtrip_obj_path": str(obj_path),
        "postprocess": postprocess_summary,
    }


def run_prepare(session_dir: Path, opt_level: str) -> None:
    manifest_path = session_dir / "manifest.json"
    if not manifest_path.exists():
        raise RuntimeError(f"missing manifest: {manifest_path}")
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    results = {
        "session_dir": str(session_dir),
        "scenario": manifest["scenario"],
        "programs": [],
    }
    for program in manifest["programs"]:
        results["programs"].append(prepare_program(program, opt_level, manifest["bpf_stack_size"]))
    summary_path = session_dir / "host_prepare_summary.json"
    write_json(summary_path, results)
    print(json.dumps(results, indent=2))


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Host-side llvmbpf GET_ORIGINAL + REJIT preparation")
    sub = parser.add_subparsers(dest="command", required=True)

    sub.add_parser("build-tools")

    prepare = sub.add_parser("prepare")
    prepare.add_argument("--session-dir", type=Path, required=True)
    prepare.add_argument("--opt-level", default="O2")
    prepare.add_argument("--bpf-stack-size", type=int, default=512)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    if args.command == "build-tools":
        build_tools()
        return 0
    if args.command == "prepare":
        session_dir = args.session_dir.resolve()
        manifest_path = session_dir / "manifest.json"
        if not manifest_path.exists():
            raise RuntimeError(f"missing manifest: {manifest_path}")
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        manifest["bpf_stack_size"] = args.bpf_stack_size
        write_json(manifest_path, manifest)
        run_prepare(session_dir, args.opt_level)
        return 0
    raise AssertionError(f"unhandled command: {args.command}")


if __name__ == "__main__":
    raise SystemExit(main())
