from __future__ import annotations

import argparse
import ctypes
import json
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path
from typing import Sequence

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.kop import load_kop_modules
from runner.libs.workspace_layout import (
    inside_runtime_image,
    kop_module_dir,
    micro_program_root,
    runner_binary_path,
    sim_proof_root,
    stage2_program_root,
)
from runner.suites._common import (
    base_suite_runtime_env,
    common_env_args,
    ensure_bpf_stats_enabled,
    env_int,
    env_str,
    env_with_suite_runtime_ld,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    suite_main_setup,
)

_die = partial(fail, "test-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    if argv or (argv is None and sys.argv[1:]):
        _die("test suite takes env only; run through Make")
    args = common_env_args(str(ROOT_DIR), _die)
    args.artifact_dir = env_str("TEST_ARTIFACT_DIR")
    args.run_contract_json = env_str("RUN_CONTRACT_JSON")
    args.run_contract_path = env_str("RUN_CONTRACT_PATH")
    args.test_mode = env_str("TEST_MODE", "test")
    args.fuzz_rounds = env_int("FUZZ_ROUNDS", 1000, _die, positive=True)
    if args.test_mode not in {"selftest", "negative", "test", "fuzz", "native-loader-smoke"}:
        _die(f"unsupported test mode: {args.test_mode}")
    return args


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    return base_suite_runtime_env(workspace, args, "test", _die)


def _run_with_status(
    command: Sequence[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path | None = None,
) -> bool:
    process = subprocess.Popen(
        list(command),
        cwd=cwd,
        env=env,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    assert process.stdout is not None
    log_file = None
    if log_path is not None:
        log_path.parent.mkdir(parents=True, exist_ok=True)
        log_file = log_path.open("a", encoding="utf-8")
    try:
        for line in process.stdout:
            if log_file is not None:
                log_file.write(line)
            sys.stderr.write(line)
    finally:
        if log_file is not None:
            log_file.close()
    return process.wait() == 0


def _expected_kop_modules(workspace: Path, target_arch: str) -> list[str]:
    module_dir = kop_module_dir(workspace, target_arch)
    modules = sorted(
        path.stem
        for path in module_dir.glob("bpf_*.ko")
        if path.is_file()
    )
    if not modules:
        _die(f"no kop modules found under {module_dir}")
    return modules


def _load_kop_modules(workspace: Path, target_arch: str) -> None:
    load_kop_modules(
        _expected_kop_modules(workspace, target_arch),
        module_dir=kop_module_dir(workspace, target_arch),
    )


def _log_test_section(title: str) -> None:
    print(f"\n========================================\n  {title}\n========================================", file=sys.stderr)


class _BpfInsn(ctypes.Structure):
    _fields_ = [
        ("code", ctypes.c_uint8),
        ("regs", ctypes.c_uint8),
        ("off", ctypes.c_int16),
        ("imm", ctypes.c_int32),
    ]


class _BpfProgLoadAttr(ctypes.Structure):
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
        ("core_relo_cnt", ctypes.c_uint32),
        ("fd_array", ctypes.c_uint64),
        ("core_relos", ctypes.c_uint64),
        ("core_relo_rec_size", ctypes.c_uint32),
        ("log_true_size", ctypes.c_uint32),
    ]


def _bpf_syscall_number() -> int:
    machine = os.uname().machine
    if machine == "x86_64":
        return 321
    if machine in {"aarch64", "arm64"}:
        return 280
    _die(f"unsupported architecture for BPF syscall smoke: {machine}")
    raise AssertionError("unreachable")


def _bpf_insn(code: int, *, dst: int = 0, src: int = 0, off: int = 0, imm: int = 0) -> _BpfInsn:
    return _BpfInsn(code, (src << 4) | dst, off, imm)


def _log_negative_line(log_path: Path | None, line: str) -> None:
    print(line, file=sys.stderr)
    if log_path is not None:
        with log_path.open("a", encoding="utf-8") as out:
            out.write(line + "\n")


def _load_xdp_prog(insns: Sequence[_BpfInsn]) -> tuple[int, int, str]:
    bpf_prog_load = 5
    bpf_prog_type_xdp = 6
    libc = ctypes.CDLL(None, use_errno=True)
    insn_array_type = _BpfInsn * len(insns)
    insn_array = insn_array_type(*insns)
    license_buf = ctypes.create_string_buffer(b"GPL")
    log_buf = ctypes.create_string_buffer(65536)
    attr = _BpfProgLoadAttr()
    attr.prog_type = bpf_prog_type_xdp
    attr.insn_cnt = len(insns)
    attr.insns = ctypes.addressof(insn_array)
    attr.license = ctypes.addressof(license_buf)
    attr.log_level = 1
    attr.log_size = ctypes.sizeof(log_buf)
    attr.log_buf = ctypes.addressof(log_buf)
    ret = libc.syscall(
        _bpf_syscall_number(),
        bpf_prog_load,
        ctypes.byref(attr),
        ctypes.sizeof(attr),
    )
    err = ctypes.get_errno() if ret < 0 else 0
    return int(ret), err, log_buf.value.decode("utf-8", errors="replace")


def _expect_bpf_load_ok(name: str, insns: Sequence[_BpfInsn], log_path: Path | None) -> None:
    fd, err, verifier_log = _load_xdp_prog(insns)
    if fd < 0:
        if verifier_log.strip():
            _log_negative_line(log_path, verifier_log.rstrip())
        _die(f"{name}: expected BPF_PROG_LOAD success, got errno={err}")
    os.close(fd)
    _log_negative_line(log_path, f"  PASS  {name}")


def _expect_bpf_load_fail(name: str, insns: Sequence[_BpfInsn], log_path: Path | None) -> None:
    fd, err, _verifier_log = _load_xdp_prog(insns)
    if fd >= 0:
        os.close(fd)
        _die(f"{name}: invalid BPF_PROG_LOAD unexpectedly succeeded")
    if err == 1:
        _die(f"{name}: BPF_PROG_LOAD failed with EPERM; test container lacks BPF privilege")
    _log_negative_line(log_path, f"  PASS  {name} errno={err}")


def _run_bpf_load_negative_suite(
    args: argparse.Namespace,
    *,
    fuzz: bool,
    log_path: Path | None = None,
) -> None:
    _log_test_section("BPF verifier negative smoke")
    xdp_pass = 2
    good_xdp_pass = [
        _bpf_insn(0xb7, dst=0, imm=xdp_pass),
        _bpf_insn(0x95),
    ]
    _expect_bpf_load_ok("valid_xdp_pass", good_xdp_pass, log_path)
    _expect_bpf_load_fail("invalid_opcode", [_bpf_insn(0xff), _bpf_insn(0x95)], log_path)
    _expect_bpf_load_fail("stack_oob_write", [
        _bpf_insn(0xb7, dst=0, imm=0),
        _bpf_insn(0x7b, dst=10, src=0, off=-520),
        _bpf_insn(0xb7, dst=0, imm=xdp_pass),
        _bpf_insn(0x95),
    ], log_path)
    _expect_bpf_load_fail("uninitialized_register", [
        _bpf_insn(0xbf, dst=0, src=5),
        _bpf_insn(0x95),
    ], log_path)
    if fuzz:
        for i in range(args.fuzz_rounds):
            opcode = 0xf0 | ((i * 37 + 11) & 0xf)
            _expect_bpf_load_fail(f"fuzz_invalid_opcode_{i:04d}", [
                _bpf_insn(opcode),
                _bpf_insn(0x95),
            ], log_path)


def _run_kernel_selftest(workspace: Path, env: dict[str, str]) -> None:
    kernel_selftest = workspace / "tests" / "kernel" / "build" / "test_recompile"
    if not kernel_selftest.is_file():
        print(f"SKIP: test_recompile not found at {kernel_selftest}", file=sys.stderr)
        return
    _log_test_section("Kernel selftest (test_recompile)")
    if not _run_with_status([str(kernel_selftest)], cwd=workspace, env=env):
        _die("test_recompile failed")


def _run_native_proof_micro_smoke(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    *,
    log_path: Path | None = None,
) -> None:
    runner_binary = runner_binary_path(workspace, args.target_arch)
    program_dir = micro_program_root(workspace, args.target_arch)
    proof_dir = sim_proof_root(workspace, args.target_arch)
    if not runner_binary.is_file() or not os.access(runner_binary, os.X_OK):
        _die(f"runner artifact is missing or not executable: {runner_binary}")
    if not program_dir.is_dir():
        _die(f"micro program artifact root is missing: {program_dir}")
    if not proof_dir.is_dir():
        _die(f"native proof artifact root is missing: {proof_dir}")

    _log_test_section("native_proof micro smoke")
    proof_env = env.copy()
    proof_env["BPFREJIT_MICRO_PROGRAM_DIR"] = str(program_dir)
    proof_env["BPFREJIT_MICRO_RUNNER_BINARY"] = str(runner_binary)
    proof_env["BPFREJIT_MICRO_PROOF_DIR"] = str(proof_dir)
    command = [
        args.python_bin or sys.executable,
        str(workspace / "micro" / "driver.py"),
        "--suite", str(workspace / "micro" / "config" / "micro_pure_jit.yaml"),
        "--runtime", "native_proof",
        "--samples", "1",
        "--warmups", "0",
        "--inner-repeat", "1",
        "--output", str((_artifact_dir(workspace, args) / "native_proof_micro.json")),
    ]
    if not _run_with_status(command, cwd=workspace, env=proof_env, log_path=log_path):
        _die("native_proof micro smoke failed")


def _run_native_loader_shim_smoke(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    artifact_dir: Path,
) -> None:
    if args.target_arch != "x86_64":
        print("SKIP: native-loader shim smoke is x86-only", file=sys.stderr)
        return

    stage2_root = stage2_program_root(workspace, args.target_arch)
    tool = stage2_root / "multi_prog_tool"
    bpf_object = stage2_root / "multi_prog_smoke.bpf.o"
    native_object = stage2_root / "multi_prog_smoke.native.o"
    shim_so = Path("/usr/local/lib/bpfrejit/libbpfrejit_shim.so")
    native_loader_so = Path("/usr/local/lib/bpfrejit/libnative_loader.so")
    native_link = Path("/usr/local/bin/native-link")
    for path, label in (
        (tool, "multi-prog tool"),
        (bpf_object, "multi-prog BPF object"),
        (native_object, "multi-prog native object"),
        (shim_so, "BPF ReJIT shim"),
        (native_loader_so, "native-loader shared library"),
        (native_link, "native-link binary"),
    ):
        if label in {"multi-prog tool", "BPF ReJIT shim", "native-link binary"}:
            if not path.is_file() or not os.access(path, os.X_OK):
                _die(f"{label} is missing or not executable: {path}")
        elif not path.is_file():
            _die(f"{label} is missing: {path}")

    _log_test_section("native-loader shim multi-prog smoke")
    _load_kop_modules(workspace, args.target_arch)
    shim_dir = artifact_dir / "native-loader-shim"
    shim_dir.mkdir(parents=True, exist_ok=True)
    log_path = artifact_dir / "native-loader-shim.log"
    manifest_path = shim_dir / "manifest.json"
    manifest_path.write_text(json.dumps({
        "version": 1,
        "app": "native-loader-smoke",
        "objects": [
            {
                "program": "multi_prog_firs",
                "symbol": "multi_prog_first",
                "native_object": str(native_object),
            },
            {
                "program": "multi_prog_seco",
                "symbol": "multi_prog_second",
                "native_object": str(native_object),
            },
        ],
    }, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    smoke_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    smoke_env.update({
        "LD_PRELOAD": str(shim_so),
        "BPFREJIT_SHIM_DIR": str(shim_dir),
        "BPFREJIT_SHIM_LOG": str(log_path),
        "BPFREJIT_SHIM_NATIVE_LOADER": "1",
        "BPFREJIT_SHIM_NATIVE_MANIFEST": str(manifest_path),
        "BPFREJIT_NATIVE_LOADER_SO": str(native_loader_so),
        "BPFREJIT_NATIVE_LINK_BINARY": str(native_link),
    })
    completed = subprocess.run(
        [str(tool), str(bpf_object)],
        cwd=workspace,
        env=smoke_env,
        capture_output=True,
        text=True,
        check=False,
    )
    log_path.write_text(
        (log_path.read_text(encoding="utf-8") if log_path.exists() else "") +
        completed.stdout + completed.stderr,
        encoding="utf-8",
    )
    sys.stderr.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        _die(f"native-loader shim smoke failed with exit {completed.returncode}")
    for expected in ("loaded multi_prog_first", "loaded multi_prog_second"):
        if expected not in completed.stdout:
            _die(f"native-loader shim smoke did not report {expected}")
    shim_log = log_path.read_text(encoding="utf-8")
    for expected in (
        "native-loader replaced prog=multi_prog_firs",
        "native-loader replaced prog=multi_prog_seco",
    ):
        if expected not in shim_log:
            _die(f"native-loader shim log missing: {expected}")


def _artifact_dir(workspace: Path, args: argparse.Namespace) -> Path:
    if args.artifact_dir:
        return resolve_workspace_path(workspace, args.artifact_dir)
    token = args.run_token or f"{args.target_name}_test"
    return workspace / "tests" / "results" / token


def _prepare_test_artifacts(workspace: Path, args: argparse.Namespace) -> Path:
    artifact_dir = _artifact_dir(workspace, args)
    artifact_dir.mkdir(parents=True, exist_ok=True)
    contract_path = artifact_dir / "run-contract.json"
    if args.run_contract_path:
        shutil.copy2(resolve_workspace_path(workspace, args.run_contract_path), contract_path)
    elif args.run_contract_json:
        try:
            payload = json.loads(args.run_contract_json)
        except json.JSONDecodeError as exc:
            _die(f"invalid run contract JSON: {exc}")
            raise AssertionError("unreachable")
        contract_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return artifact_dir


def _run_selftest_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "selftest.log"
    _log_test_section("Loading kop modules")
    _load_kop_modules(workspace, args.target_arch)
    _run_native_proof_micro_smoke(workspace, args, env, log_path=log_path)
    _run_bpf_load_negative_suite(args, fuzz=False, log_path=log_path)


def _run_negative_mode(args: argparse.Namespace, artifact_dir: Path) -> None:
    log_path = artifact_dir / "negative.log"
    _run_bpf_load_negative_suite(args, fuzz=False, log_path=log_path)


def _run_fuzz_mode(args: argparse.Namespace, artifact_dir: Path) -> None:
    log_path = artifact_dir / "fuzz.log"
    _run_bpf_load_negative_suite(args, fuzz=True, log_path=log_path)


def _run_test_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str]) -> None:
    _run_kernel_selftest(workspace, env)
    _log_test_section("Loading kop modules")
    _load_kop_modules(workspace, args.target_arch)
    _run_native_proof_micro_smoke(workspace, args, env)
    _run_bpf_load_negative_suite(args, fuzz=False)


def _mode_needs_bpf_stats(mode: str) -> bool:
    return mode in {"selftest", "test"}


def _run_test_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    artifact_dir = _prepare_test_artifacts(workspace, args)
    os.chdir(workspace)
    if inside_runtime_image() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_die)
    if _mode_needs_bpf_stats(args.test_mode):
        ensure_bpf_stats_enabled(workspace, _die)

    if args.test_mode == "selftest":
        _run_selftest_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "negative":
        _run_negative_mode(args, artifact_dir)
    elif args.test_mode == "fuzz":
        _run_fuzz_mode(args, artifact_dir)
    elif args.test_mode == "native-loader-smoke":
        _run_native_loader_shim_smoke(workspace, args, env, artifact_dir)
    elif args.test_mode == "test":
        _run_test_mode(workspace, args, env)
    else:
        _die(f"unsupported test mode: {args.test_mode}")


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    _run_test_suite(workspace, args)


if __name__ == "__main__":
    main()
