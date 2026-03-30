#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shlex
import shutil
import subprocess
import sys
from dataclasses import dataclass
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


@dataclass(frozen=True)
class PrepareConfig:
    default_opt_level: str
    opt_passes: str | None
    disable_loop_unrolling: bool
    bpf_stack_size: int
    llc_extra_args: tuple[str, ...]
    large_program_threshold: int | None
    large_program_opt_level: str | None


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


def pick_opt_level(program: dict[str, Any], config: PrepareConfig) -> str:
    if (
        config.large_program_threshold is not None
        and config.large_program_opt_level is not None
        and int(program["dump"]["original_insn_count"]) > config.large_program_threshold
    ):
        return config.large_program_opt_level
    return config.default_opt_level


def build_opt_command(raw_ll: Path, opt_bc: Path, opt_level: str, config: PrepareConfig) -> list[str]:
    argv = [require_tool("opt")]
    if config.opt_passes:
        argv.extend([f"-passes={config.opt_passes}", str(raw_ll), "-o", str(opt_bc)])
    else:
        argv.extend([f"-{opt_level}", str(raw_ll), "-o", str(opt_bc)])
    if config.disable_loop_unrolling:
        argv.append("-disable-loop-unrolling")
    return argv


def build_llc_command(opt_bc: Path, raw_obj: Path, config: PrepareConfig) -> list[str]:
    return [
        require_tool("llc"),
        "-march=bpf",
        "-mcpu=v3",
        f"--bpf-stack-size={config.bpf_stack_size}",
        *config.llc_extra_args,
        "-filetype=obj",
        str(opt_bc),
        "-o",
        str(raw_obj),
    ]


def prepare_program(program: dict[str, Any], config: PrepareConfig) -> dict[str, Any]:
    program_dir = Path(program["program_dir"]).resolve()
    original_bin = Path(program["original_bin_path"]).resolve()
    raw_ll = program_dir / "lifted.ll"
    opt_bc = program_dir / "opt.bc"
    raw_obj = program_dir / "roundtrip_raw.bpf.o"
    obj_path = program_dir / "roundtrip.bpf.o"
    bin_path = program_dir / "roundtrip.bin"
    opt_level = pick_opt_level(program, config)

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
        build_opt_command(raw_ll, opt_bc, opt_level, config),
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
        build_llc_command(opt_bc, raw_obj, config),
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
        "effective_opt_level": opt_level,
        "roundtrip_bin_path": str(bin_path),
        "roundtrip_obj_path": str(obj_path),
        "postprocess": postprocess_summary,
    }


def run_prepare(session_dir: Path, config: PrepareConfig) -> None:
    manifest_path = session_dir / "manifest.json"
    if not manifest_path.exists():
        raise RuntimeError(f"missing manifest: {manifest_path}")
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    results = {
        "session_dir": str(session_dir),
        "scenario": manifest["scenario"],
        "prepare_config": {
            "default_opt_level": config.default_opt_level,
            "opt_passes": config.opt_passes,
            "disable_loop_unrolling": config.disable_loop_unrolling,
            "bpf_stack_size": config.bpf_stack_size,
            "llc_extra_args": list(config.llc_extra_args),
            "large_program_threshold": config.large_program_threshold,
            "large_program_opt_level": config.large_program_opt_level,
        },
        "programs": [],
    }
    for program in manifest["programs"]:
        results["programs"].append(prepare_program(program, config))
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
    prepare.add_argument("--opt-passes", default=None)
    prepare.add_argument("--disable-loop-unrolling", action="store_true")
    prepare.add_argument("--bpf-stack-size", type=int, default=512)
    prepare.add_argument("--llc-extra-arg", action="append", default=[])
    prepare.add_argument("--large-program-threshold", type=int, default=None)
    prepare.add_argument("--large-program-opt-level", default=None)
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
        config = PrepareConfig(
            default_opt_level=args.opt_level,
            opt_passes=args.opt_passes,
            disable_loop_unrolling=args.disable_loop_unrolling,
            bpf_stack_size=args.bpf_stack_size,
            llc_extra_args=tuple(args.llc_extra_arg),
            large_program_threshold=args.large_program_threshold,
            large_program_opt_level=args.large_program_opt_level,
        )
        run_prepare(session_dir, config)
        return 0
    raise AssertionError(f"unhandled command: {args.command}")


if __name__ == "__main__":
    raise SystemExit(main())
