#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import json
import os
import resource
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


SCRIPT_PATH = Path(__file__).resolve()
WORKDIR = SCRIPT_PATH.parent


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


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


@dataclass
class CommandResult:
    argv: list[str]
    cwd: str
    returncode: int
    stdout_path: str
    stderr_path: str


def run_cmd(
    name: str,
    argv: list[str],
    *,
    cwd: Path,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    check: bool = True,
) -> CommandResult:
    print(f"$ (cd {cwd} && {' '.join(argv)})")
    completed = subprocess.run(
        argv,
        cwd=cwd,
        capture_output=True,
        text=True,
        check=False,
    )
    if stdout_path is None:
        stdout_path = WORKDIR / f"{name}.stdout.log"
    if stderr_path is None:
        stderr_path = WORKDIR / f"{name}.stderr.log"
    stdout_path.write_text(completed.stdout, encoding="utf-8")
    stderr_path.write_text(completed.stderr, encoding="utf-8")
    if check and completed.returncode != 0:
        raise RuntimeError(
            f"{name} failed with rc={completed.returncode}; "
            f"see {rel(stdout_path)} and {rel(stderr_path)}"
        )
    return CommandResult(
        argv=argv,
        cwd=str(cwd),
        returncode=completed.returncode,
        stdout_path=str(stdout_path),
        stderr_path=str(stderr_path),
    )


def require_tool(name: str) -> str:
    path = shutil.which(name)
    if not path:
        raise RuntimeError(f"required tool not found in PATH: {name}")
    return path


def ensure_llvmbpf_cli() -> Path:
    cli_path = WORKDIR / "llvmbpf_build" / "cli" / "bpftime-vm"
    if cli_path.exists():
        return cli_path
    llvm_config = require_tool("llvm-config")
    llvm_cmakedir = (
        subprocess.check_output([llvm_config, "--cmakedir"], text=True).strip()
    )
    build_dir = WORKDIR / "llvmbpf_build"
    build_dir.mkdir(parents=True, exist_ok=True)
    run_cmd(
        "llvmbpf_cmake",
        [
            require_tool("cmake"),
            "-S",
            str(REPO_ROOT / "vendor/llvmbpf"),
            "-B",
            str(build_dir),
            "-DBUILD_LLVM_AOT_CLI=ON",
            "-DCMAKE_BUILD_TYPE=Release",
            f"-DLLVM_DIR={llvm_cmakedir}",
        ],
        cwd=REPO_ROOT,
    )
    run_cmd(
        "llvmbpf_make",
        ["make", "-C", str(build_dir), "-j4", "bpftime-vm-cli"],
        cwd=REPO_ROOT,
    )
    if not cli_path.exists():
        raise RuntimeError(f"expected llvmbpf CLI at {cli_path}, but build did not produce it")
    return cli_path


def ensure_source_object() -> Path:
    run_cmd(
        "micro_programs_make",
        ["make", "-C", str(REPO_ROOT / "micro"), "programs"],
        cwd=REPO_ROOT,
    )
    source_obj = REPO_ROOT / "micro/programs/simple.bpf.o"
    if not source_obj.exists():
        raise RuntimeError(f"missing source object after build: {source_obj}")
    return source_obj


def extract_section(obj_path: Path, section: str, output_path: Path) -> CommandResult:
    if output_path.exists():
        output_path.unlink()
    return run_cmd(
        f"dump_{output_path.stem}",
        [
            require_tool("llvm-objcopy"),
            f"--dump-section",
            f"{section}={output_path}",
            str(obj_path),
        ],
        cwd=REPO_ROOT,
    )


def file_size(path: Path) -> int:
    return path.stat().st_size


def host_prepare() -> None:
    for tool in ["cmake", "llvm-config", "llvm-as", "opt", "llc", "llvm-objcopy"]:
        require_tool(tool)
    cli_path = ensure_llvmbpf_cli()
    source_obj = ensure_source_object()

    lifted_ll = WORKDIR / "lifted_simple.ll"
    lifted_bc = WORKDIR / "lifted_simple.bc"
    opt_o0_bc = WORKDIR / "optO0_simple.bc"
    opt_o2_bc = WORKDIR / "optO2_simple.bc"
    roundtrip_o2 = WORKDIR / "roundtrip_simple_O2_v3.o"
    original_bin = WORKDIR / "original_simple_xdp.bin"
    roundtrip_bin = WORKDIR / "roundtrip_simple_O2.bin"

    result_lift = run_cmd(
        "lift_simple_emit_llvm",
        [str(cli_path), "build", str(source_obj), "-o", str(WORKDIR), "-emit-llvm"],
        cwd=REPO_ROOT,
        stdout_path=lifted_ll,
    )
    result_llvm_as = run_cmd(
        "lifted_simple_llvm_as",
        [require_tool("llvm-as"), str(lifted_ll), "-o", str(lifted_bc)],
        cwd=REPO_ROOT,
    )
    result_opt_o0 = run_cmd(
        "lifted_simple_opt_o0",
        [require_tool("opt"), "-O0", str(lifted_ll), "-o", str(opt_o0_bc)],
        cwd=REPO_ROOT,
    )
    result_llc_o0 = run_cmd(
        "lifted_simple_llc_o0",
        [
            require_tool("llc"),
            "-march=bpf",
            "-mcpu=v3",
            "-filetype=obj",
            str(opt_o0_bc),
            "-o",
            str(WORKDIR / "roundtrip_simple_O0_v3.o"),
        ],
        cwd=REPO_ROOT,
        check=False,
    )
    result_opt_o2 = run_cmd(
        "lifted_simple_opt_o2",
        [require_tool("opt"), "-O2", str(lifted_ll), "-o", str(opt_o2_bc)],
        cwd=REPO_ROOT,
    )
    result_llc_o2 = run_cmd(
        "lifted_simple_llc_o2",
        [
            require_tool("llc"),
            "-march=bpf",
            "-mcpu=v3",
            "-filetype=obj",
            str(opt_o2_bc),
            "-o",
            str(roundtrip_o2),
        ],
        cwd=REPO_ROOT,
    )
    result_dump_orig = extract_section(source_obj, "xdp", original_bin)
    result_dump_roundtrip = extract_section(roundtrip_o2, ".text", roundtrip_bin)
    result_disasm_orig = run_cmd(
        "original_simple_disasm",
        [require_tool("llvm-objdump"), "-dr", "--no-show-raw-insn", str(source_obj)],
        cwd=REPO_ROOT,
    )
    result_disasm_roundtrip = run_cmd(
        "roundtrip_simple_o2_disasm",
        [require_tool("llvm-objdump"), "-dr", "--no-show-raw-insn", str(roundtrip_o2)],
        cwd=REPO_ROOT,
    )

    summary = {
        "repo_root": str(REPO_ROOT),
        "workdir": str(WORKDIR),
        "source_object": str(source_obj),
        "llvmbpf_cli": str(cli_path),
        "artifacts": {
            "lifted_ll": str(lifted_ll),
            "lifted_bc": str(lifted_bc),
            "opt_o0_bc": str(opt_o0_bc),
            "opt_o2_bc": str(opt_o2_bc),
            "roundtrip_o2_obj": str(roundtrip_o2),
            "original_bin": str(original_bin),
            "roundtrip_bin": str(roundtrip_bin),
        },
        "commands": {
            "lift": result_lift.__dict__,
            "llvm_as": result_llvm_as.__dict__,
            "opt_o0": result_opt_o0.__dict__,
            "llc_o0": result_llc_o0.__dict__,
            "opt_o2": result_opt_o2.__dict__,
            "llc_o2": result_llc_o2.__dict__,
            "dump_original": result_dump_orig.__dict__,
            "dump_roundtrip": result_dump_roundtrip.__dict__,
            "disasm_original": result_disasm_orig.__dict__,
            "disasm_roundtrip": result_disasm_roundtrip.__dict__,
        },
        "bytecode": {
            "original_bytes": file_size(original_bin),
            "original_insns": file_size(original_bin) // 8,
            "roundtrip_bytes": file_size(roundtrip_bin),
            "roundtrip_insns": file_size(roundtrip_bin) // 8,
        },
        "observations": {
            "identity_lowering_rc": result_llc_o0.returncode,
            "optimized_lowering_rc": result_llc_o2.returncode,
            "identity_lowering_stderr_excerpt": read_text(Path(result_llc_o0.stderr_path))[:1200],
        },
        "guest_verify_command": (
            f"make vm-shell VM_COMMAND='python3 {SCRIPT_PATH} guest-verify "
            f"--orig-bin {original_bin} --roundtrip-bin {roundtrip_bin}'"
        ),
    }
    summary_path = WORKDIR / "host_prepare_summary.json"
    summary_path.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    print(json.dumps(summary, indent=2))


class BpfAttrProgLoad(ctypes.Structure):
    _fields_ = [
        ("prog_type", ctypes.c_uint32),
        ("insn_cnt", ctypes.c_uint32),
        ("insns", ctypes.c_uint64),
        ("license", ctypes.c_uint64),
        ("log_level", ctypes.c_uint32),
        ("log_size", ctypes.c_uint32),
        ("log_buf", ctypes.c_uint64),
        ("kern_version", ctypes.c_uint32),
        ("prog_flags", ctypes.c_uint32),
        ("prog_name", ctypes.c_char * 16),
        ("prog_ifindex", ctypes.c_uint32),
        ("expected_attach_type", ctypes.c_uint32),
        ("prog_btf_fd", ctypes.c_uint32),
        ("func_info_rec_size", ctypes.c_uint32),
        ("func_info", ctypes.c_uint64),
        ("func_info_cnt", ctypes.c_uint32),
        ("line_info_rec_size", ctypes.c_uint32),
        ("line_info", ctypes.c_uint64),
        ("line_info_cnt", ctypes.c_uint32),
        ("attach_btf_id", ctypes.c_uint32),
        ("attach_prog_fd", ctypes.c_uint32),
        ("fd_array", ctypes.c_uint64),
    ]


LIBC = ctypes.CDLL(None, use_errno=True)
SYS_BPF = 321
BPF_PROG_LOAD = 5
BPF_PROG_TYPE_XDP = 6


def set_unlimited_memlock() -> None:
    try:
        resource.setrlimit(
            resource.RLIMIT_MEMLOCK,
            (resource.RLIM_INFINITY, resource.RLIM_INFINITY),
        )
    except (ValueError, OSError) as exc:
        raise RuntimeError(f"failed to raise RLIMIT_MEMLOCK: {exc}") from exc


def load_raw_xdp(path: Path, prog_name: str) -> dict[str, object]:
    code = path.read_bytes()
    if len(code) % 8 != 0:
        raise RuntimeError(f"{path} does not contain an integer number of BPF instructions")
    code_buf = ctypes.create_string_buffer(code)
    log_buf = ctypes.create_string_buffer(1 << 20)
    license_buf = ctypes.create_string_buffer(b"GPL")
    attr = BpfAttrProgLoad()
    attr.prog_type = BPF_PROG_TYPE_XDP
    attr.insn_cnt = len(code) // 8
    attr.insns = ctypes.addressof(code_buf)
    attr.license = ctypes.addressof(license_buf)
    attr.log_level = 1
    attr.log_size = ctypes.sizeof(log_buf)
    attr.log_buf = ctypes.addressof(log_buf)
    attr.kern_version = 0
    attr.prog_flags = 0
    encoded_name = prog_name.encode("ascii", errors="strict")[:15]
    attr.prog_name = encoded_name + b"\0" * (16 - len(encoded_name))

    fd = LIBC.syscall(
        ctypes.c_long(SYS_BPF),
        ctypes.c_long(BPF_PROG_LOAD),
        ctypes.byref(attr),
        ctypes.c_uint(ctypes.sizeof(attr)),
    )
    verifier_log = log_buf.value.decode("utf-8", errors="replace")
    result = {
        "path": str(path),
        "prog_name": prog_name,
        "insn_cnt": len(code) // 8,
        "status": "ok" if fd >= 0 else "error",
        "verifier_log": verifier_log,
    }
    if fd < 0:
        err = ctypes.get_errno()
        result["errno"] = err
        result["error"] = os.strerror(err)
    else:
        result["fd"] = fd
        os.close(fd)
    return result


def guest_verify(orig_bin: Path, roundtrip_bin: Path) -> None:
    if os.geteuid() != 0:
        raise RuntimeError("guest-verify must run as root inside the VM")
    set_unlimited_memlock()

    orig_result = load_raw_xdp(orig_bin, "orig_simple")
    roundtrip_result = load_raw_xdp(roundtrip_bin, "rt_simple_o2")

    (WORKDIR / "guest_verify_original.verifier.log").write_text(
        str(orig_result.get("verifier_log", "")),
        encoding="utf-8",
    )
    (WORKDIR / "guest_verify_roundtrip.verifier.log").write_text(
        str(roundtrip_result.get("verifier_log", "")),
        encoding="utf-8",
    )

    summary = {
        "original": orig_result,
        "roundtrip_o2": roundtrip_result,
    }
    summary_path = WORKDIR / "guest_verify_summary.json"
    summary_path.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    print(json.dumps(summary, indent=2))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Minimal llvmbpf -> LLVM -> BPF verifier round-trip POC"
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    subparsers.add_parser("host-prepare", help="build llvmbpf and generate round-trip artifacts")

    guest = subparsers.add_parser("guest-verify", help="load raw BPF bytecode with BPF_PROG_LOAD inside the VM")
    guest.add_argument(
        "--orig-bin",
        type=Path,
        default=WORKDIR / "original_simple_xdp.bin",
        help="path to the original raw xdp bytecode",
    )
    guest.add_argument(
        "--roundtrip-bin",
        type=Path,
        default=WORKDIR / "roundtrip_simple_O2.bin",
        help="path to the round-tripped raw bytecode",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.command == "host-prepare":
        host_prepare()
        return 0
    if args.command == "guest-verify":
        guest_verify(args.orig_bin.resolve(), args.roundtrip_bin.resolve())
        return 0
    raise AssertionError(f"unexpected command: {args.command}")


if __name__ == "__main__":
    sys.exit(main())
