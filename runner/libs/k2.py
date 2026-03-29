from __future__ import annotations

import os
import re
import subprocess
import tempfile
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Any

from . import ROOT_DIR, docs_tmp_dir, run_command, tail_text
from .corpus import ResolvedObject, ResolvedProgram
from .object_discovery import ProgramListingEntry, discover_object_programs


_K2_PROG_INPUT_TYPES = {
    "xdp": 2,
    "sched_cls": 3,
}


@dataclass(frozen=True)
class K2Toolchain:
    root: Path
    superopt_dir: Path
    main_binary: Path
    z3_lib_dir: Path
    elf_extract: Path
    patch_script: Path
    artifact_repo: Path

    def as_dict(self) -> dict[str, str]:
        payload = asdict(self)
        return {key: str(value) for key, value in payload.items()}


def resolve_k2_toolchain(root: Path | None = None) -> K2Toolchain:
    resolved_root = (root or (ROOT_DIR / ".cache" / "k2")).resolve()
    toolchain = K2Toolchain(
        root=resolved_root,
        superopt_dir=resolved_root / "superopt",
        main_binary=resolved_root / "superopt" / "main_ebpf.out",
        z3_lib_dir=resolved_root / "z3" / "build",
        elf_extract=resolved_root / "bpf-elf-tools" / "text-extractor" / "elf_extract",
        patch_script=resolved_root / "bpf-elf-tools" / "patch_insns" / "patch_elf.py",
        artifact_repo=resolved_root / "sigcomm21_artifact",
    )
    required = {
        "K2 root": toolchain.root,
        "superopt dir": toolchain.superopt_dir,
        "main_ebpf.out": toolchain.main_binary,
        "Z3 build dir": toolchain.z3_lib_dir,
        "elf_extract": toolchain.elf_extract,
        "patch_elf.py": toolchain.patch_script,
        "artifact repo": toolchain.artifact_repo,
    }
    missing = [f"{label}: {path}" for label, path in required.items() if not path.exists()]
    if missing:
        raise RuntimeError("K2 toolchain is incomplete:\n" + "\n".join(missing))
    return toolchain


def extractor_base_for_section(section_name: str) -> str:
    return str(section_name or "").replace("/", "-")


def k2_program_model(
    obj: ResolvedObject,
    program: ResolvedProgram,
    *,
    max_pkt_sz: int,
) -> dict[str, Any]:
    prog_type_name = str(program.prog_type_name or "").strip()
    pgm_input_type = _K2_PROG_INPUT_TYPES.get(prog_type_name)
    if pgm_input_type is None:
        return {
            "supported": False,
            "reason": (
                "K2 object-file flow in the public artifact is modeled only for "
                f"packet-processing prog types; got {prog_type_name or 'unknown'}"
            ),
        }

    target_base = extractor_base_for_section(program.section_name)
    matches = [
        candidate
        for candidate in obj.programs
        if extractor_base_for_section(candidate.section_name) == target_base
    ]
    if len(matches) != 1:
        return {
            "supported": False,
            "reason": (
                "K2 object-file flow is section-based, but this ELF has "
                f"{len(matches)} programs mapped to extracted section {target_base!r}"
            ),
            "extracted_base": target_base,
            "section_collision_programs": [candidate.canonical_name for candidate in matches],
        }

    return {
        "supported": True,
        "pgm_input_type": pgm_input_type,
        "max_pkt_sz": int(max_pkt_sz),
        "extracted_base": target_base,
    }


def _build_k2_command(
    *,
    toolchain: K2Toolchain,
    desc_path: Path,
    insns_path: Path,
    maps_path: Path,
    output_dir: Path,
    log_path: Path,
    iterations: int,
    logger_level: int,
    window_start: int,
    window_end: int,
) -> list[str]:
    return [
        str(toolchain.main_binary),
        "--bm_from_file",
        "--desc",
        str(desc_path),
        "--bytecode",
        str(insns_path),
        "--map",
        str(maps_path),
        "-k",
        "1",
        "--is_win",
        "--port",
        "8000",
        "--logger_level",
        str(logger_level),
        "--w_e",
        "0.5",
        "--w_p",
        "1.5",
        "--st_ex",
        "0",
        "--st_eq",
        "0",
        "--st_avg",
        "1",
        "--st_perf",
        "0",
        "--st_when_to_restart",
        "0",
        "--st_when_to_restart_niter",
        "0",
        "--st_start_prog",
        "0",
        "--p_inst_operand",
        "0.33333333",
        "--p_inst",
        "0.33333333",
        "--p_inst_as_nop",
        "0.15",
        "--reset_win_niter",
        "5000",
        "--win_s_list",
        str(int(window_start)),
        "--win_e_list",
        str(int(window_end)),
        "--path_res",
        f"{output_dir}/",
        "-n",
        str(int(iterations)),
        str(log_path),
    ]


def _write_desc_file(path: Path, *, pgm_input_type: int, max_pkt_sz: int) -> None:
    path.write_text(
        "{ pgm_input_type = %d, }\n{ max_pkt_sz = %d, }\n" % (pgm_input_type, max_pkt_sz),
        encoding="utf-8",
    )


def _safe_slug(text: str) -> str:
    slug = re.sub(r"[^A-Za-z0-9._-]+", "_", text).strip("._-")
    return slug[:96] or "k2"


def _parse_k2_text(text: str) -> dict[str, Any]:
    warning_lines: list[str] = []
    seen_warnings: set[str] = set()
    for raw_line in text.splitlines():
        line = raw_line.strip()
        lowered = line.lower()
        if not line:
            continue
        if "unknown function id" not in lowered and "illegal input" not in lowered and "error:" not in lowered:
            continue
        if line in seen_warnings:
            continue
        seen_warnings.add(line)
        warning_lines.append(line)

    def parse_int(pattern: str) -> int | None:
        match = re.search(pattern, text)
        return int(match.group(1)) if match else None

    def parse_float(pattern: str) -> float | None:
        match = re.search(pattern, text)
        return float(match.group(1)) if match else None

    return {
        "log_tail": tail_text(text),
        "original_perf_cost": parse_int(r"original program's perf cost:\s*(\d+)"),
        "optimized_perf_cost": parse_int(r"top 1 program's performance cost:\s*(\d+)"),
        "compile_time_seconds": parse_float(r"compiling time:\s*([0-9]+(?:\.[0-9]+)?)"),
        "warnings": warning_lines[:8],
    }


def _parse_k2_log(path: Path) -> dict[str, Any]:
    if not path.exists():
        return {
            "log_tail": "",
            "original_perf_cost": None,
            "optimized_perf_cost": None,
            "compile_time_seconds": None,
            "warnings": [],
        }
    return _parse_k2_text(path.read_text(encoding="utf-8", errors="replace"))


def _merged_ld_library_path(extra_dir: Path) -> str:
    current = os.environ.get("LD_LIBRARY_PATH", "").strip()
    if not current:
        return str(extra_dir)
    return f"{extra_dir}:{current}"


def _count_insns(path: Path) -> int:
    size = path.stat().st_size
    return max(1, size // 8)


def _find_program_listing(
    entries: list[ProgramListingEntry],
    program: ResolvedProgram,
) -> ProgramListingEntry:
    exact_name = [entry for entry in entries if entry.name == program.program_name]
    if len(exact_name) == 1:
        return exact_name[0]

    exact_section = [entry for entry in entries if entry.section_name == program.section_name]
    if len(exact_section) == 1:
        return exact_section[0]

    if len(entries) == 1:
        return entries[0]

    raise RuntimeError(
        "unable to match optimized ELF program to original target "
        f"{program.canonical_name}; entries={[entry.name for entry in entries]}"
    )


def optimize_program_with_k2(
    *,
    toolchain: K2Toolchain,
    runner_binary: Path,
    obj: ResolvedObject,
    program: ResolvedProgram,
    output_root: Path | None = None,
    iterations: int = 5000,
    max_pkt_sz: int = 256,
    timeout_seconds: int = 600,
    logger_level: int = 0,
) -> dict[str, Any]:
    model = k2_program_model(obj, program, max_pkt_sz=max_pkt_sz)
    base_result: dict[str, Any] = {
        "status": "unsupported" if not model.get("supported") else "error",
        "ok": False,
        "canonical_name": program.canonical_name,
        "repo": program.repo,
        "object_path": program.object_path,
        "program_name": program.program_name,
        "section_name": program.section_name,
        "prog_type_name": program.prog_type_name,
        "model": model,
        "iterations": int(iterations),
        "timeout_seconds": int(timeout_seconds),
        "workdir": None,
        "output_object": None,
        "stdout_tail": "",
        "stderr_tail": "",
        "validation_error": None,
        "extract_error": None,
        "patch_error": None,
        "log_path": None,
        "log_tail": "",
        "original_insn_count": None,
        "original_perf_cost": None,
        "optimized_perf_cost": None,
        "compile_time_seconds": None,
        "optimized_insn_count": None,
        "insn_delta": None,
        "warnings": [],
    }
    if not model.get("supported"):
        base_result["reason"] = model.get("reason")
        return base_result

    resolved_output_root = (
        output_root
        or docs_tmp_dir("k2-runs")
    ).resolve()
    resolved_output_root.mkdir(parents=True, exist_ok=True)
    workdir = Path(
        tempfile.mkdtemp(
            prefix=f"{_safe_slug(program.canonical_name)}-",
            dir=resolved_output_root,
        )
    )
    base_result["workdir"] = str(workdir)

    extracted_base = str(model["extracted_base"])
    desc_path = workdir / "k2.desc"
    log_path = workdir / "k2.log"
    output_dir = workdir / "k2-output"
    output_dir.mkdir(parents=True, exist_ok=True)
    output_object = workdir / f"{_safe_slug(program.program_name)}.k2.bpf.o"
    base_result["output_object"] = str(output_object)
    base_result["log_path"] = str(log_path)

    try:
        run_command(
            [str(toolchain.elf_extract), str(Path(obj.object_abs_path).resolve())],
            cwd=workdir,
            timeout=timeout_seconds,
        )
    except Exception as exc:
        base_result["extract_error"] = str(exc)
        base_result["reason"] = "elf_extract failed"
        return base_result

    insns_path = workdir / f"{extracted_base}.insns"
    maps_path = workdir / f"{extracted_base}.maps"
    if not insns_path.exists():
        available = sorted(path.name for path in workdir.glob("*.insns"))
        base_result["reason"] = (
            f"elf_extract did not produce {extracted_base}.insns; available={available}"
        )
        return base_result
    if not maps_path.exists():
        maps_path.write_text("", encoding="utf-8")

    _write_desc_file(
        desc_path,
        pgm_input_type=int(model["pgm_input_type"]),
        max_pkt_sz=int(model["max_pkt_sz"]),
    )
    insn_count = _count_insns(insns_path)
    if insn_count < 3:
        base_result["status"] = "unsupported"
        base_result["reason"] = (
            "K2 public object-file flow is unstable on extremely short programs "
            f"(insn_count={insn_count})"
        )
        return base_result
    window_end = min(8, max(2, insn_count))
    window_start = min(5, max(1, window_end - 1))

    env = dict(os.environ)
    env["LD_LIBRARY_PATH"] = _merged_ld_library_path(toolchain.z3_lib_dir)
    try:
        completed = subprocess.run(
            _build_k2_command(
                toolchain=toolchain,
                desc_path=desc_path,
                insns_path=insns_path,
                maps_path=maps_path,
                output_dir=output_dir,
                log_path=log_path,
                iterations=iterations,
                logger_level=logger_level,
                window_start=window_start,
                window_end=window_end,
            ),
            cwd=toolchain.superopt_dir,
            env=env,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
            check=False,
        )
        base_result["stdout_tail"] = tail_text(completed.stdout or "")
        base_result["stderr_tail"] = tail_text(completed.stderr or "")
    except subprocess.TimeoutExpired:
        base_result["reason"] = f"K2 timed out after {timeout_seconds} seconds"
        base_result["stderr_tail"] = f"K2 timed out after {timeout_seconds} seconds"
        base_result.update(_parse_k2_log(log_path))
        return base_result

    parsed_output = _parse_k2_text(
        "\n".join(
            part
            for part in (
                completed.stdout or "",
                completed.stderr or "",
                log_path.read_text(encoding="utf-8", errors="replace") if log_path.exists() else "",
            )
            if part
        )
    )
    base_result.update(parsed_output)
    optimized_insns_path = output_dir / "output0.insns"
    if completed.returncode != 0:
        base_result["reason"] = f"K2 exited with code {completed.returncode}"
        return base_result
    if not optimized_insns_path.exists():
        base_result["reason"] = (
            f"K2 did not produce {optimized_insns_path.name}; "
            f"stderr={base_result['stderr_tail'] or 'n/a'}"
        )
        return base_result

    try:
        patch_completed = subprocess.run(
            [
                "python3",
                str(toolchain.patch_script),
                str(Path(obj.object_abs_path).resolve()),
                str(optimized_insns_path),
                extracted_base,
                "--remove-reloc",
                "-o",
                str(output_object),
            ],
            cwd=workdir,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
            check=False,
        )
        if patch_completed.returncode != 0:
            base_result["patch_error"] = tail_text(patch_completed.stderr or patch_completed.stdout or "")
            base_result["reason"] = f"patch_elf.py exited with code {patch_completed.returncode}"
            return base_result
    except subprocess.TimeoutExpired:
        base_result["patch_error"] = f"patch_elf.py timed out after {timeout_seconds} seconds"
        base_result["reason"] = "patch_elf.py timed out"
        return base_result

    try:
        original_entries = discover_object_programs(
            runner_binary,
            Path(obj.object_abs_path).resolve(),
            timeout_seconds=max(60, timeout_seconds),
        )
        original_entry = _find_program_listing(original_entries, program)
        optimized_entries = discover_object_programs(
            runner_binary,
            output_object,
            timeout_seconds=max(60, timeout_seconds),
        )
        optimized_entry = _find_program_listing(optimized_entries, program)
    except Exception as exc:
        base_result["validation_error"] = str(exc)
        base_result["reason"] = "optimized ELF validation failed"
        return base_result

    base_result["original_insn_count"] = int(original_entry.insn_count)
    base_result["optimized_insn_count"] = int(optimized_entry.insn_count)
    base_result["insn_delta"] = int(optimized_entry.insn_count) - int(original_entry.insn_count)
    base_result["status"] = "ok"
    base_result["ok"] = True
    return base_result


__all__ = [
    "K2Toolchain",
    "extractor_base_for_section",
    "k2_program_model",
    "optimize_program_with_k2",
    "resolve_k2_toolchain",
]
